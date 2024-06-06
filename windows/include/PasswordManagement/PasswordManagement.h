#pragma once
#include<QObject>
#include<QString>
#include<QDebug>
namespace Qmlmod  {
	struct Account
	{
		QString name;
		QString user;
		QString passwd;
	};
	class Passwd : public QObject
	{
		Q_OBJECT
	public:
		explicit Passwd(QObject* parent = nullptr);
		
		~Passwd();
		Q_INVOKABLE void getInPutTextName(QString text);
		Q_INVOKABLE void getInPutTextUser(QString text);
		Q_INVOKABLE void getInPutTextpassWd(QString text);
	
		Q_INVOKABLE void addAccount(QString name,QString user,QString passwd);

		Q_INVOKABLE void saveAccount();
	private:
		Account account_item;
		std::vector<Account> account;
	};

}