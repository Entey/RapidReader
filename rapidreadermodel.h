#ifndef RAPIDREADERMODEL_H
#define RAPIDREADERMODEL_H

#include <QString>
#include <QObject>
#include <QTimer>
#include <memory>

class RapidReaderStore;

class RapidReaderModel : public QObject
{
    Q_OBJECT
public:
    RapidReaderModel(const std::shared_ptr<RapidReaderStore> & settings);

    // load new file and store in in the settings class
    void loadNewBook(const QString &path);

    void dispatchInfo();
    void startTimer();
    void updateSpeed(int speed);

signals:
    void showMessage(const QString &type, const QString &header, const QString &message);
    void showWord(QString word);

private:
    std::shared_ptr<RapidReaderStore> m_settings;
    QTimer * m_timer;
};

#endif // RAPIDREADERMODEL_H
