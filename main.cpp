#include <QtWidgets/QApplication>
#include "UI.h"
#include "Testing.h"
int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    //const Testing teste;
    //teste.toate_testele();
    //qDebug( "teste rulate cu succes!\n");
    FileRepository repo{ "activitati.txt" };
    Service serv{ repo };
    UserInterface ui{ serv };

    ui.show();
    //return 0;
    return app.exec();
}
