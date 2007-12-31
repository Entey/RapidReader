#include "rapidreadermodel.h"
#include "rapidreaderstore.h"

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

RapidReaderModel::RapidReaderModel(const std::shared_ptr<RapidReaderStore> & settings)
    : m_settings(settings)
{
    m_settings->m_speed = 1;
    m_settings->m_lineIter = m_settings->m_currentBook.cbegin();
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &RapidReaderModel::dispatchInfo);
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
        m_settings->m_currentBook.append(line.split(" "));
    }
    m_settings->m_lineIter = m_settings->m_currentBook.cbegin();
    file.flush();
    file.close();
}

void RapidReaderModel::dispatchInfo()
{
    if(m_settings->m_lineIter != m_settings->m_currentBook.end())
    {
        qDebug() << *m_settings->m_lineIter;
        emit showWord(*m_settings->m_lineIter++);
        m_settings->m_lineIter++;
    }
    else
    {
        m_timer->stop();
    }
}

void RapidReaderModel::updateSpeed(int speed)
{
    m_settings->m_speed += speed;
    m_timer->setInterval(1000 * m_settings->m_speed);
}

void RapidReaderModel::startTimer()
{
    m_timer->start(1000 * m_settings->m_speed);
}
