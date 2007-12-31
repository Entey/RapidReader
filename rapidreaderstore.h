#ifndef RAPIDREADERSTORE_H
#define RAPIDREADERSTORE_H
#include <QObject>
#include <QStringList>
#include <QVector>

class RapidReaderStore : public QObject
{
    Q_OBJECT
public:
    QStringList m_currentBook;
    QStringList::const_iterator m_lineIter;
    int m_speed;
};

#endif // RAPIDREADERSTORE_H
