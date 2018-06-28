#include "dialog.h"
#include <QApplication>
#include "rapidreaderpresenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RapidReaderPresenter presenter;

    return a.exec();
}
