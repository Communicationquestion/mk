#pragma once
#include<PasswordManagement/PasswordManagement.h>

Qmlmod::Passwd::Passwd(QObject* parent) : QObject(parent)
{
}
Qmlmod::Passwd::~Passwd()
{
}
void Qmlmod::Passwd::getInPutTextName(QString _Name)
{
	account_item.name = _Name;
	
}

void Qmlmod::Passwd::getInPutTextUser(QString _User)
{
	account_item.user = _User;
	
}

void Qmlmod::Passwd::getInPutTextpassWd(QString _passWd)
{
	account_item.passwd = _passWd;
	
	
}

void Qmlmod::Passwd::addAccount(QString name, QString user, QString passwd)
{
	getInPutTextName(name);
	getInPutTextUser(user);
	getInPutTextpassWd(passwd);
	qDebug() << account_item.name << account_item.user << account_item.passwd;
	account.push_back(account_item);
	
}

void Qmlmod::Passwd::saveAccount()
{
	creatpasswd.MkDir("./mkconfig");
	
	for (auto &t : account)
	{
		pwContents = pwContents+" "+ t.name + " " + t.user + " " + t.passwd + "\n";
	
		qDebug() << t.name << t.user << t.passwd;
	}

	creatpasswd.create_txt("./mkconfig/config.txt", pwContents.toStdString());
}

void Qmlmod::Passwd::foo()
{
	std::string message = "我我我我我我我我我我我";
	CryptoPP::StringSource Base64String(message, true, new CryptoPP::Base64Encoder(new CryptoPP::FileSink(std::cout)));

	std::string base64Message = "ztLO0s7SztLO0s7SztLO0s7SztLO0g==";
	CryptoPP::StringSource Base64String2(base64Message, true, new CryptoPP::Base64Decoder(new CryptoPP::FileSink(std::cout)));
}


