#ifndef RAPIDREADERPRESENTER_H
#define RAPIDREADERPRESENTER_H

#include "rapidreaderstore.h"
#include "rapidreaderpresenter.h"
#include "rapidreadermodel.h"
#include "filesystem.h"
#include "dialog.h"

#include <QObject>

#include <memory>

class RapidReaderPresenter : public QObject
{
    Q_OBJECT
public:
    explicit RapidReaderPresenter(QObject* object = nullptr);

    // call this function to launch the app
    void exec();

    // call read file from model and apply it to display
    void readFile(const QString &path);
    // exec filesystem dialog
    void showFileReader();
public slots:
    // callback to show message from model
    void onShowMessage(const QString &type, const QString &header, const QString &message);

    void onStartTimer();
    void onSpeedUpdate(int i);
private:
    std::shared_ptr<RapidReaderStore> m_store;

    std::unique_ptr<FileSystem> m_filesystem;
    std::unique_ptr<MainDialog> m_dialog;
    std::unique_ptr<RapidReaderModel> m_model;
};


#endif // RAPIDREADERPRESENTER_H
