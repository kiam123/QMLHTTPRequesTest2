#ifndef TEST_H
#define TEST_H

#include "apibase.h"

class Test : public APIBase
{
public:
    Test();
    QNetworkReply *getRequest(QUrl url);

private:
    QNetworkAccessManager m_manager;

signals:
//    QString finished(QString reply);

public slots:
    void finished(QNetworkReply *reply);
};

#endif // TEST_H
