#include "test.h"

Test::Test()
{
    connect(this, SIGNAL(finished), SLOT(replyFinished));
}

void Test::finished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "APIBase::replyFinished" << reply->error() << reply->errorString();
        emit replyError(reply, reply->error(), reply->errorString());
    }

    QString data = reply->readAll();
//    emit finished(data);
}
