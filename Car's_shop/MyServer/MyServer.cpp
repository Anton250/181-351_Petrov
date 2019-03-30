#include "MyServer.h"
#include "QDebug"




MyServer::MyServer(QObject *parent) 
: QObject(parent)
{
	MyTcpServer = new QTcpServer(this);
	connect(MyTcpServer, &QTcpServer::newConnection, this, &MyServer::slotNewConnection);
	if (MyTcpServer->listen(QHostAddress::Any, 6000)) {
		serverStatus = 1;
		qDebug() << "Server is working";
	}
}

MyServer::~MyServer()
{
	serverStatus = 0;
}

void MyServer::slotReadClient()
{
	QTcpSocket* clientSocket = (QTcpSocket*)sender();
	QByteArray arr;
	while (clientSocket->bytesAvailable() > 0) {
		arr.clear();
		QString str = clientSocket->readAll();
		
		qDebug() << str << '\n';
		
		int pos = str.toStdString().find("login$");

		if (pos != std::string::npos) {
			std::string strStr = str.toStdString();
			strStr.erase(0, pos + 6);
			str = authorize(QString::fromStdString(strStr));
		}

		arr.append(str);
		clientSocket->write(arr);
	}
}

void MyServer::slotClientDisconnected()
{
	QTcpSocket* clientSocket = (QTcpSocket*)sender();
	qDebug() << "User disconected!" << clientSocket->peerAddress();
	int idusersoc = clientSocket->socketDescriptor();
	SClients.remove(idusersoc);
	clientSocket->close();
}

void MyServer::slotNewConnection() {

	if (serverStatus == 1) {
		QTcpSocket* clientSocket = MyTcpServer->nextPendingConnection();
		qDebug() << "New connection!" << clientSocket->peerAddress();
		int idusersocs = clientSocket->socketDescriptor();
		SClients[idusersocs] = clientSocket;
		connect(SClients[idusersocs], &QTcpSocket::readyRead, this, &MyServer::slotReadClient);
		connect(SClients[idusersocs], &QTcpSocket::disconnected, this, &MyServer::slotClientDisconnected);
	}
}