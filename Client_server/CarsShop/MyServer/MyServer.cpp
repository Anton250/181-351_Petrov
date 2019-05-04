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
	
		arr.clear();
		arr = clientSocket->readAll();
		qDebug() << arr << '\n';
		arr = decrypt(arr);

		qDebug() << arr << '\n';
		


		int pos = find("login$", arr);

		if (pos != -1) {
			arr = erase(arr, 0, pos + 6);
			arr = authorize(arr);
		}
		
		pos = find("addCars$", arr);
		

		if (pos != -1) {
			arr = erase(arr, 0, pos + 8);
			arr = addCar(arr);
		}

		pos = find("editCars$", arr);

		if (pos != -1) {
			arr = erase(arr, 0, pos + 9);
			arr = editCar(arr);
		}

		pos = find("deleteCars$", arr);

		if (pos != -1) {
			arr = erase(arr, 0, pos + 11);
			arr = deleteCar(arr);
		}

		pos = find("addUsers$", arr);

		if (pos != -1) {
			arr = erase(arr, 0, pos + 9);
			arr = addUser(arr);
		}

		pos = find("editUsers$", arr);

		if (pos != -1) {
			arr = erase(arr, 0, pos + 10);
			arr = editUser(arr);
		}

		pos = find("deleteUsers$", arr);

		if (pos != -1) {
			arr = erase(arr, 0, pos + 12);
			arr = deleteUser(arr);
		}

		pos = find("editUser$", arr);

		if (pos != -1) {
			arr = erase(arr, 0, pos + 9);
			arr = editUser(arr);
			arr.append("updateCorrect");
			
		}
		
		
		if (arr.toStdString().find("error$") != std::string::npos || arr.toStdString().find("true$") != std::string::npos || 
			arr.toStdString().find("false$") != std::string::npos) {
			arr = encrypt(arr);
			clientSocket->write(arr);

		}
		else {
			if (arr.toStdString().find("updateCorrect") != std::string::npos) {
				arr = encrypt(arr);
				clientSocket->write(arr);
				arr = decrypt(arr);
				arr.remove(arr.toStdString().find("updateCorrect"), 13);
			}
			else {
				arr = encrypt(arr);
				clientSocket->write(arr);
				arr = decrypt(arr);
			}
			arr = encrypt(arr);
			for each (QTcpSocket * var in SClients)
			{
				if (var == clientSocket) {

					continue;
				}
				var->write(arr);

			}
			
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