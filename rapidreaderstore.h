#ifndef RAPIDREADERSTORE_H
#define RAPIDREADERSTORE_H
#include <QObject>
#include <QStringList>

class RapidReaderStore : public QObject
{
    Q_OBJECT
public:
    QStringList m_current_book;
};

#endif // RAPIDREADERSTORE_H
