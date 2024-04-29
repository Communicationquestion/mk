#pragma once
#include <ctranslate2/translator.h>
#include<qstring.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>


std::string GbkToUtf8(const char* src_str);
int run(const char* cmd);
void TextTurnsSound(std::string _txt);
