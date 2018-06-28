#include "filesystem.h"
#include "ui_filesystemdialog.h"
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QMessageBox>

FileSystem::FileSystem(QWidget* parent) :
    QDialog(parent),
    m_ui(new Ui::FileSystemDialog)
{
    m_ui->setupUi(this);

    m_DirModel = new QFileSystemModel(this);
    m_DirModel->setRootPath("C:/");
    m_DirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    m_ui->treeView->setModel(m_DirModel);

    m_FileModel = new QFileSystemModel(this);
    m_FileModel->setRootPath("C:/");
    m_FileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    m_ui->listView->setModel(m_FileModel);

}

void FileSystem::onLaunch(const QString &path)
{

}

void FileSystem::on_treeView_clicked(const QModelIndex &index)
{
    QString path = m_DirModel->fileInfo(index).absolutePath();
    m_ui->listView->setRootIndex(m_FileModel->setRootPath(path));
}

void FileSystem::on_listView_doubleClicked(const QModelIndex &index)
{
    QString path = m_DirModel->fileInfo(index).absolutePath();

    QFile file(path);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, "ERROR!", "Cannot open file!");
        file.flush();
        file.close();
        return;
    }



    file.flush();
    file.close();
}
