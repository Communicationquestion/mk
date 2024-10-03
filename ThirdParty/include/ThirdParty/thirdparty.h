#pragma once
#include <ctranslate2/translator.h>
#include <qstring.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <array>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/base64.h>
#include <cryptopp/files.h>
#include <cryptopp/aes.h> 
#include <cryptopp/hex.h> 
#include <cryptopp/modes.h> 
#include <cryptopp/salsa.h>
#include <cryptopp/osrng.h>
#include <cryptopp/secblock.h>

std::string GbkToUtf8(const char* src_str);
int run(const char* cmd);
void TextTurnsSound(std::string _txt);
int create_txt(std::string _txtPath, std::string _nameTxt);
std::string Utf8ToGbk(const char* src_str);
std::string stringCharacterReplace(std::string str, char _oldch, std::string _newch);
std::string exec_cmd(const char* cmd);
inline std::string getcwd() {
   
	wchar_t buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);

	QString s = QString::fromWCharArray(buffer).remove(s.length() - 6, 6).replace("\\", "/");

	return s.toStdString();
    
}