#define TERMINATE_CHECK if(p->terminate){ emit terminated(); return; }
#define TERMINATE_CHECK_2 if(p->terminate){ emit terminated(); return result; }

#include "smartpointanalizerthread.h"

#include <QImage>
#include <QDebug>
#include <QMap>

#include <math.h>
#include <qmath.h>

class SmartPointAnalizerThreadPrivate
{
public:
    bool terminate;
};

SmartPointAnalizerThread::SmartPointAnalizerThread(QObject *parent) :
    QObject(parent)
{
    p = new SmartPointAnalizerThreadPrivate;
    p->terminate = false;

    qRegisterMetaType< QList<SmartPointItem> >("QList<SmartPointItem>");
}

void SmartPointAnalizerThread::start(const QString &src, int maxPointSize, int minPointSize)
{
    QImage img(src);

    QList< QList<QRgb> > data;
    QMap<int, QMap<int, bool> > index;

    QList<SmartPointItem> list;

    int count = 0;
    for(int i=0; i<img.height(); i++)
    {
        data << QList<QRgb>();
        for(int j=0; j<img.width(); j++)
        {
            const QRgb rgb = img.pixel(j, i);
            data[i] << rgb;
            if( (qRed(rgb)+qGreen(rgb)+qBlue(rgb))/3 < 250 && qAlpha(rgb) >= 230 )
            {
                count++;
                index[i][j] = true;
            }

            TERMINATE_CHECK;
        }

        TERMINATE_CHECK;
    }

    QMapIterator<int, QMap<int, bool> > ii(index);
    while(ii.hasNext())
    {
        ii.next();
        QMapIterator<int, bool> ij(ii.value());
        while(ij.hasNext())
        {
            ij.next();
            const int x = ij.key();
            const int y = ii.key();

            const SmartPointItem &res = analizePoint(x, y, maxPointSize, minPointSize, &data, &index);
            if(res.radius == 0)
                continue;

            list << res;

            TERMINATE_CHECK;
        }

        TERMINATE_CHECK;
    }

    emit result(list, img.size());
}

SmartPointItem SmartPointAnalizerThread::analizePoint(int x, int y, int max, int min, const QList<QList<QRgb> > *_data, QMap<int, QMap<int, bool> > *_index)
{
    QMap<int, QMap<int, bool> > & index = *_index;
    const QList<QList<QRgb> > & data = *_data;

    SmartPointItem result;
    if(data.isEmpty())
        return result;

    const int height = data.length();
    const int width = data.first().length();

    qint32 length = 0;
    qint32 rx = 0;
    qint32 ry = 0;

    for(int i=0; i<20; i++)
    {
        int angle = i*(M_PI/10);
        int lx = x, ly = y;

        int diagonal = length?length:min;
        for(int j=0; j<=max; j++)
        {
            lx = x + j*qCos(angle);
            ly = y + j*qSin(angle);
            diagonal = j;
            if(!index[ly][lx])
                break;
        }
        if(diagonal > max)
            continue;

        int mx = (lx+x)/2;
        int my = (ly+y)/2;
        int radius = diagonal/2;

        bool accept = true;
        for(int k=0; k<8; k++)
        {
            int xangle = k*(M_PI/4);
            int tx = mx + radius*qCos(xangle);
            int ty = my + radius*qSin(xangle);
            if(!index[ty][tx])
            {
                accept = false;
                break;
            }
        }
        if(!accept)
            continue;

        length = radius;
        rx = mx;
        ry = my;

        TERMINATE_CHECK_2;
    }

    if(length < min)
        return result;

    result.radius = length;
    result.x = rx;
    result.y = ry;

    int rcolor = 0, gcolor = 0, bcolor = 0;
    int colorsCount = 0;

    for(int i=-result.radius; i<=result.radius; i++)
    {
        int xlen = qPow( result.radius*result.radius - i*i, 0.5 );
        for(int j=-xlen; j<=xlen; j++)
        {
            TERMINATE_CHECK_2;

            int mX = result.x + j;
            int mY = result.y + i;
            if(mX < 0 || mY < 0)
                continue;
            if(mY >= height || mX >= width )
                continue;

            index[mY].remove(mX);

            QRgb rgb = data[mY][mX];
            if(qAlpha(rgb)<240)
                continue;

            rcolor += qRed(rgb);
            gcolor += qGreen(rgb);
            bcolor += qBlue(rgb);
            colorsCount++;
        }
        TERMINATE_CHECK_2;
    }

    if(!colorsCount) colorsCount = 1;

    rcolor /= colorsCount;
    gcolor /= colorsCount;
    bcolor /= colorsCount;
    result.rgb = qRgb(rcolor, gcolor, bcolor);

    return result;
}

void SmartPointAnalizerThread::terminate()
{
    p->terminate = true;
}

void SmartPointAnalizerThread::unterminate()
{
    p->terminate = false;
}

SmartPointAnalizerThread::~SmartPointAnalizerThread()
{
    delete p;
}
