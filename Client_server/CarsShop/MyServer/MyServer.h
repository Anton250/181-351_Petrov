#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <crypto.h>
#include "workWithDB.h"

class MyServer : public QObject, public workWithDB, public crypto
{
	Q_OBJECT

public:
	MyServer(QObject *parent = 0);
	~MyServer();
public slots:
	void slotNewConnection();
	void slotReadClient();
	void slotClientDisconnected();
private:
	QTcpServer * MyTcpServer;
	//QTcpSocket * MyTcpSocket;
	int serverStatus;
	QMap<int, QTcpSocket *> SClients;


};
