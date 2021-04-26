

#include "mainwindow.h"
#include "apibase.h"
#include "test.h"
#include <QApplication>
#include <QtNetwork/QtNetwork>
#include <QDebug>

void replyFinished(QNetworkReply *reply);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    APIBase *apibase = new APIBase();
//    apibase->getRequest(QUrl("https://google.com"));
//    QObject::connect(apibase, &Test::finished, &a, replyFinished);

    return a.exec();
}

void replyFinished(QString reply){
//    QString data = reply->readAll();
    qDebug()<< "data: "<<reply;

}
