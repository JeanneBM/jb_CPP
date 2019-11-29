#include "smartpointglobalqml.h"

#include <QDir>
#include <QCoreApplication>
#include <QDebug>

SmartPointGlobalQml::SmartPointGlobalQml(QObject *parent) :
    QObject(parent)
{

}

QStringList SmartPointGlobalQml::readFileData(const QString &url)
{
    QStringList result;
    QFile file(url);
    if(!file.open(QFile::ReadOnly))
        return result;

    result = QString(file.readAll()).split("\n");
    file.close();
    return result;
}

QStringList SmartPointGlobalQml::filesEntryList(const QString &url, const QStringList & filters)
{
    QStringList result = QDir(url).entryList(filters, QDir::Files, QDir::Name);
    for(int i=0; i<result.count(); i++)
        result[i] = url + "/" + result[i];

    return result;
}

QString SmartPointGlobalQml::applicationDirPath() const
{
    return QCoreApplication::applicationDirPath();
}

SmartPointGlobalQml::~SmartPointGlobalQml()
{

}

