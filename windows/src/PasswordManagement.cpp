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

	std::string plaintext = pwContents.toStdString();
	std::string key{};
	std::cin >> key;
	
	memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
	CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption encryption((byte*)key.c_str(), key.length(), iv);
	std::string ciphertext{};
	CryptoPP::StringSource(plaintext, true, new CryptoPP::StreamTransformationFilter(encryption, new CryptoPP::StringSink(ciphertext)));


	std::string encoded{};

	CryptoPP::StringSource Base64String(ciphertext, true, new CryptoPP::Base64Encoder(new CryptoPP::StringSink(encoded)));


	creatpasswd.create_txt("./mkconfig/config.txt", encoded);

	
	encipherfile("./mkconfig/config.txt");

}

void Qmlmod::Passwd::encipherfile(std::string _path)
{
	std::string key;
	std::cin >> key;
	std::string content1;
	std::string read_cipher_text;
	std::ifstream readfile(_path);
	std::stringstream buffer;
	buffer << readfile.rdbuf();
	read_cipher_text = buffer.str();
	readfile.close();
	content1 = read_cipher_text;
	std::cout << content1 << std::endl;
	std::string uncoded;
	CryptoPP::StringSource Base64String2(content1, true, new CryptoPP::Base64Decoder(new CryptoPP::StringSink(uncoded)));

	std::string ciphertext= uncoded;
	// 解密过程
	CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption decryption((byte*)key.c_str(), key.length(), iv);
	std::string decryptedtext;
	CryptoPP::StringSource(ciphertext, true, new CryptoPP::StreamTransformationFilter(decryption, new CryptoPP::StringSink(decryptedtext)));

	// 打印解密后的明文
	std::cout << "res------:" << decryptedtext << std::endl;



}


