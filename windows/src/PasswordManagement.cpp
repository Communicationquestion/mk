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
	for (auto &t : account)
	{
		qDebug() << t.name << t.user << t.passwd;
	}
	
}
