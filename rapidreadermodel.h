#ifndef RAPIDREADERMODEL_H
#define RAPIDREADERMODEL_H

#include <QString>
#include <QObject>
#include <memory>

class RapidReaderStore;

class RapidReaderModel : public QObject
{
    Q_OBJECT
public:
    RapidReaderModel(const std::shared_ptr<RapidReaderStore> & settings);

    // load new file and store in in the settings class
    void loadNewBook(const QString &path);
signals:
    void showMessage(const QString &type, const QString &header, const QString &message);

private:
    std::shared_ptr<RapidReaderStore> m_settings;
};

#endif // RAPIDREADERMODEL_H
