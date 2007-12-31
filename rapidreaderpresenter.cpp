#include "rapidreaderpresenter.h"
#include <QMessageBox>

RapidReaderPresenter::RapidReaderPresenter(QObject* parent)
    : QObject(parent)
{
    m_store.reset(new RapidReaderStore);

    m_filesystem.reset(new FileSystem(m_store, this));
    m_dialog.reset(new MainDialog(m_store, this));
    m_model.reset(new RapidReaderModel(m_store));

    connect(m_model.get(), &RapidReaderModel::showMessage, this, &RapidReaderPresenter::onShowMessage);
    connect(m_model.get(), &RapidReaderModel::showWord,  m_dialog.get(), &MainDialog::updateWordLine);

    m_dialog->show();
}

void RapidReaderPresenter::readFile(const QString &path)
{
    m_model->loadNewBook(path);
    m_dialog->updateDataFromStore();
}

void RapidReaderPresenter::onShowMessage(const QString &type, const QString &header, const QString &message)
{
    QMessageBox::critical(nullptr, header, message);
    Q_UNUSED(type)
}

void RapidReaderPresenter::onStartTimer()
{
    m_model->startTimer();
}

void RapidReaderPresenter::onSpeedUpdate(int i)
{
    m_model->updateSpeed(i);
}

void RapidReaderPresenter::showFileReader()
{
    m_filesystem->show();
}
