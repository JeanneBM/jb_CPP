#ifndef SMARTPOINTANALIZERTHREAD_H
#define SMARTPOINTANALIZERTHREAD_H

#include <QObject>
#include <QRgb>
#include <QMap>

#include "smartpointitem.h"

class SmartPointAnalizerThreadPrivate;
class SmartPointAnalizerThread : public QObject
{
    Q_OBJECT
public:
    SmartPointAnalizerThread(QObject *parent = 0);
    ~SmartPointAnalizerThread();

public slots:
    void start(const QString &src, int maxPointSize, int minPointSize);
    void terminate();
    void unterminate();

signals:
    void result( const QList<SmartPointItem> &list, const QSize &size );
    void terminated();

private:
    SmartPointItem analizePoint( int x, int y, int max, int min, const QList< QList<QRgb> > *data, QMap<int, QMap<int, bool> > *index);

private:
    SmartPointAnalizerThreadPrivate *p;
};

Q_DECLARE_METATYPE( QList<SmartPointItem> )

#endif // SMARTPOINTANALIZERTHREAD_H

