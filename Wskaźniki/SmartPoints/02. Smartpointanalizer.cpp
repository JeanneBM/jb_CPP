#include "smartpointanalizer.h"
#include "smartpointanalizerthread.h"

#include <QThread>
#include <QImageReader>
#include <QDebug>

class SmartPointAnalizerPrivate
{
public:
    QThread *thread;
    SmartPointAnalizerThread *analizer;

    int maxPointSize;
    int minPointSize;
    QUrl source;
    QSize sourceSize;
};

SmartPointAnalizer::SmartPointAnalizer(QObject *parent) :
    QObject(parent)
{
    p = new SmartPointAnalizerPrivate;
    p->maxPointSize = 100;
    p->minPointSize = 3;

    p->thread = new QThread(this);
    p->thread->start();

    p->analizer = new SmartPointAnalizerThread();
    p->analizer->moveToThread(p->thread);

    connect(p->analizer, SIGNAL(result(QList<SmartPointItem>,QSize)), SLOT(result_priv(QList<SmartPointItem>,QSize)) );
}

void SmartPointAnalizer::setMaxPointSize(int sz)
{
    if(p->maxPointSize == sz)
        return;

    p->maxPointSize = sz;
    emit maxPointSizeChanged();
}

int SmartPointAnalizer::maxPointSize() const
{
    return p->maxPointSize;
}

void SmartPointAnalizer::setMinPointSize(int sz)
{
    if(p->minPointSize == sz)
        return;

    p->minPointSize = sz;
    emit minPointSizeChanged();
}

int SmartPointAnalizer::minPointSize() const
{
    return p->minPointSize;
}

void SmartPointAnalizer::setSource(const QUrl &url)
{
    if(p->source == url)
        return;

    p->source = url;
    emit sourceChanged();

    QImageReader reader(url.toLocalFile());
    p->sourceSize = reader.size();
    emit sourceSizeChanged();
}

QUrl SmartPointAnalizer::source() const
{
    return p->source;
}

QSize SmartPointAnalizer::sourceSize() const
{
    return p->sourceSize;
}

void SmartPointAnalizer::start()
{
    start(p->source);
}

void SmartPointAnalizer::start(const QUrl &url)
{
    p->analizer->unterminate();
    QString source = url.toLocalFile();
    QMetaObject::invokeMethod(p->analizer, "start", Qt::QueuedConnection, Q_ARG(QString,source),
                              Q_ARG(int,p->maxPointSize), Q_ARG(int,p->minPointSize));
}

void SmartPointAnalizer::stop()
{
    p->analizer->terminate();
}

void SmartPointAnalizer::result_priv(const QList<SmartPointItem> &list, const QSize &size)
{
    QVariantList result;

    emit resultBegin();
    foreach(const SmartPointItem &item, list)
    {
        QVariantMap map;
        map["x"] = item.x;
        map["y"] = item.y;
        map["radius"] = item.radius;
        map["color"] = QColor(item.rgb);

        result << QVariant::fromValue<QVariantMap>(map);

        emit resultFound(item.x, item.y, item.radius, QColor(item.rgb));
    }

    emit resultEnd();
    emit SmartPointAnalizer::result(result, size);
    emit resultList(list, size);
}

SmartPointAnalizer::~SmartPointAnalizer()
{
    stop();

    p->thread->quit();
    p->thread->wait();
    p->thread->deleteLater();
    p->analizer->deleteLater();

    delete p;
}
