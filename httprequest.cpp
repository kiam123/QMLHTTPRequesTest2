#include "httprequest.h"

HttpRequest::HttpRequest()
{
    connect(&m_nam, &QNetworkAccessManager::finished, this, &HttpRequest::replyRequestFinished);
}


void HttpRequest::replyRequestFinished(QNetworkReply *reply){

    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "APIBase::replyFinished" << reply->error() << reply->errorString();
        emit replyError(reply, reply->error(), reply->errorString());
    }
    QString data = reply->readAll();
    qDebug() << "data123: " << data;

    emit replyTestRespone(data);
}

void HttpRequest::patchRequest(QUrl url, const QByteArray &data) {
    patch(url, data);
}


void HttpRequest::postRequest(QUrl url,const QByteArray &data) {
    post(url, data);
}
