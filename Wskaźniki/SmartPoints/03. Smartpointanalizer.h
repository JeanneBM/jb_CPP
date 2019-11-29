#ifndef SMARTPOINTANALIZER_H
#define SMARTPOINTANALIZER_H

#include <QObject>
#include <QUrl>
#include <QColor>
#include <QSize>
#include <QVariant>

#include "smartpointitem.h"

class SmartPointAnalizerPrivate;
class SmartPointAnalizer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int maxPointSize READ maxPointSize WRITE setMaxPointSize NOTIFY maxPointSizeChanged)
    Q_PROPERTY(int minPointSize READ minPointSize WRITE setMinPointSize NOTIFY minPointSizeChanged)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QSize sourceSize READ sourceSize NOTIFY sourceSizeChanged)

public:
    SmartPointAnalizer(QObject *parent = 0);
    ~SmartPointAnalizer();

    void setMaxPointSize(int sz);
    int maxPointSize() const;

    void setMinPointSize(int sz);
    int minPointSize() const;

    void setSource(const QUrl &url);
    QUrl source() const;

    QSize sourceSize() const;

public slots:
    void start();
    void start(const QUrl &url);
    void stop();

signals:
    void maxPointSizeChanged();
    void minPointSizeChanged();
    void sourceChanged();
    void sourceSizeChanged();

    void resultBegin();
    void resultFound(int x, int y, int radius, const QColor &color);
    void resultEnd();

    void resultList( const QList<SmartPointItem> &list, const QSize &size );
    void result( const QVariantList &list, const QSize &size );

private slots:
    void result_priv( const QList<SmartPointItem> &list, const QSize &size );

private:
    SmartPointAnalizerPrivate *p;
};

#endif // SMARTPOINTANALIZER_H
