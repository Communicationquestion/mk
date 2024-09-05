#pragma once
#include<PasswordManagement/passwdTxt.h>
#include<QObject>
#include<QDebug>
#include<ThirdParty/thirdparty.h>
#include<abstraction_create/abstraction_create.h>
#include <QFileDialog>
#include <QString>

namespace Qmlmod {
	struct Account
	{
		QString name;
		QString user;
		QString passwd;
	};

	class Create : public abstraction_create::Abs_create
	{
	public:
		int creta_files(std::string _file_name, std::string _type) {

			return 0;
		}

	private:

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

		Q_INVOKABLE void addAccount(QString name, QString user, QString passwd);

		Q_INVOKABLE void saveAccount();
		Q_INVOKABLE void setKey(QString _key);
		std::string encipherfile(const std::string&& _path);

	private:
		byte iv[CryptoPP::AES::BLOCKSIZE]{0};
		Account account_item;
		CryptoPP::XSalsa20::Encryption en;
		CryptoPP::XSalsa20::Decryption de;
		std::vector<Account> account;
		QString txtFileKey;
		Create creatpasswd;
		QString pwContents{};
		
	};

	class TxtTable : public QObject
	{
		Q_OBJECT
	public:
		
		explicit TxtTable(QObject* parent = nullptr);
		Q_INVOKABLE std::string getfilepath(QString _filePath);
		Q_INVOKABLE void ensrctxt();
	private:
		std::vector<Account> env{};
		Passwd pwdtools;
		QString srcfilepath{};
		edtxt::edtxtfile<Account> edf{};
	};

}