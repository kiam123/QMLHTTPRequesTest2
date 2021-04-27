#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QtNetwork/QtNetwork>
#include <QString>
#include <QtQml>
#include "apibase.h"

class HttpRequest : public APIBase
{
    Q_OBJECT
public:
    HttpRequest();

    static void declareQML() {
        qmlRegisterType<HttpRequest>("httpRequest", 1, 0, "HttpRequest");
    }

//    Q_INVOKABLE void getRequest(QUrl url);
    Q_INVOKABLE void patchRequest(QUrl url, const QByteArray &data);
    Q_INVOKABLE void postRequest(QUrl url,const QByteArray &data);
//    Q_INVOKABLE void login(QUrl url,const QByteArray &data);

signals:
    void replyTestRespone(QString reply);
//    void loginRespone(QString reply);

public slots:
    void replyRequestFinished(QNetworkReply *reply);
//    void loginRequestFinished(QNetworkReply *reply);


};

#endif // HTTPREQUEST_H
