#ifndef RAPEADREADERSETTINGS_H
#define RAPEADREADERSETTINGS_H
#include <QObject>

class RapidReaderSettings : public QObject
{
    Q_OBJECT
public:
    QString m_current_book;
};

#endif // RAPEADREADERSETTINGS_H
