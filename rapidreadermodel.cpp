#include "rapidreadermodel.h"
#include "rapidreaderstore.h"

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

RapidReaderModel::RapidReaderModel(const std::shared_ptr<RapidReaderStore> & settings)
    : m_settings(settings)
{
}

/*********************************************************************
 * DESCRIPTION: Read and save new file in the store
 *********************************************************************/
void RapidReaderModel::loadNewBook(const QString &path)
{
    qDebug() << path;
    QFile file(path);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        //QMessageBox::critical(this, "ERROR!", "Cannot open file!");
        emit showMessage("critical", "ERROR!", "Cannot open file!");
        file.flush();
        file.close();
        return;
    }

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        m_settings->m_current_book.append(line);
    }

    qDebug() << m_settings->m_current_book;

    qDebug() << "end";

    file.flush();
    file.close();
}
