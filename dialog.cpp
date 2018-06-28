#include "dialog.h"
#include "ui_dialog.h"
#include "rapidreaderpresenter.h"
#include "rapidreaderstore.h"

MainDialog::MainDialog(const std::shared_ptr<RapidReaderStore> &store,
    RapidReaderPresenter* presenter, QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::Dialog),
        m_presenter(presenter),
        m_store(store)
{
   m_ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete m_ui;
}

void MainDialog::updateDataFromStore()
{

}

void MainDialog::on_speedUpButton_clicked()
{

}

void MainDialog::on_speedDownButton_clicked()
{

}

void MainDialog::on_newBook_clicked()
{
    m_presenter->showFileReader();
}

void MainDialog::on_buttonBack_clicked()
{

}

void MainDialog::on_buttonForward_clicked()
{

}

void MainDialog::on_buttonStart_clicked()
{

}
