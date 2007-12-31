#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <memory>

class RapidReaderStore;
class RapidReaderPresenter;

namespace Ui
{
class Dialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(const std::shared_ptr<RapidReaderStore> &store,
                    RapidReaderPresenter* presenter, QWidget *parent = nullptr);
    ~MainDialog();

    void updateDataFromStore();
    void updateWordLine(QString word);

private slots:
    void on_speedUpButton_clicked();
    void on_speedDownButton_clicked();
    void on_newBook_clicked();
    void on_buttonBack_clicked();
    void on_buttonForward_clicked();
    void on_buttonStart_clicked();

private:
    Ui::Dialog *m_ui;

    std::shared_ptr<RapidReaderStore> m_store;
    RapidReaderPresenter* m_presenter;
};

#endif // DIALOG_H
