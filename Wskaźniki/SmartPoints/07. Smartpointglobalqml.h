#ifndef SMARTPOINTGLOBALQML_H
#define SMARTPOINTGLOBALQML_H

#include <QObject>
#include <QUrl>
#include <QStringList>

class SmartPointGlobalQml : public QObject
{
    Q_OBJECT
public:
    SmartPointGlobalQml(QObject *parent = 0);
    ~SmartPointGlobalQml();

public slots:
    QStringList readFileData(const QString &url);
    QStringList filesEntryList(const QString &url, const QStringList &filters = QStringList());
    QString applicationDirPath() const;
};

#endif // SMARTPOINTGLOBALQML_H

