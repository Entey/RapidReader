#include "filesystem.h"
#include "ui_filesystemdialog.h"
#include "rapidreaderstore.h"
#include "rapidreaderpresenter.h"
#include <QDebug>

FileSystem::FileSystem(const std::shared_ptr<RapidReaderStore> &settings,
                       RapidReaderPresenter *presenter, QWidget* parent) :
    QDialog(parent),
    m_ui(new Ui::FileSystemDialog),
    m_settings(settings),
    m_presenter(presenter)
{
    m_ui->setupUi(this);

    m_DirModel = new QFileSystemModel(this);
    m_DirModel->setRootPath("C:/Users/Smooth/");
    m_DirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    m_ui->treeView->setModel(m_DirModel);

    m_FileModel = new QFileSystemModel(this);
    m_FileModel->setRootPath("C:/");
    m_FileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    m_ui->listView->setModel(m_FileModel);

}

void FileSystem::on_treeView_clicked(const QModelIndex &index)
{
    QString path = m_DirModel->fileInfo(index).filePath();
    m_ui->listView->setRootIndex(m_FileModel->setRootPath(path));
}

void FileSystem::on_listView_doubleClicked(const QModelIndex &index)
{
    QString path = m_DirModel->fileInfo(index).filePath();

    m_presenter->readFile(path);
    this->hide();
}
