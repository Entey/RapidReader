#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QDialog>
#include <QFileSystemModel>
#include <memory>

namespace Ui
{
 class FileSystemDialog;
}

class RapidReaderStore;
class RapidReaderPresenter;

class FileSystem : public QDialog
{
    Q_OBJECT
public:
    explicit FileSystem(const std::shared_ptr<RapidReaderStore> &settings,
                        RapidReaderPresenter *presenter, QWidget* parent = nullptr);

protected:
    QFileSystemModel * m_DirModel;
    QFileSystemModel * m_FileModel;
    Ui::FileSystemDialog * m_ui;
    std::shared_ptr<RapidReaderStore> m_settings;
    RapidReaderPresenter * m_presenter;

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_listView_doubleClicked(const QModelIndex &index);
};

#endif // FILESYSTEM_H
