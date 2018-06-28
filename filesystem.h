#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QDialog>
#include <QFileSystemModel>

namespace Ui
{
 class FileSystemDialog;
}

class FileSystem : public QDialog
{
    Q_OBJECT
public:
    explicit FileSystem(QWidget* parent = nullptr);

public slots:
    void onLaunch(const QString& path);

protected:
    QFileSystemModel * m_DirModel;
    QFileSystemModel * m_FileModel;
    Ui::FileSystemDialog * m_ui;
private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_listView_doubleClicked(const QModelIndex &index);
};

#endif // FILESYSTEM_H
