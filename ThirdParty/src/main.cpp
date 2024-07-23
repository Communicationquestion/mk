#include<ThirdParty/thirdparty.h>
std::string GbkToUtf8(const char* src_str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, src_str, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, src_str, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	std::string strTemp = str;
	if (wstr) delete[] wstr;
	if (str) delete[] str;
	return strTemp;
}

std::string Utf8ToGbk(const char* src_str)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	std::string strTemp(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	return strTemp;
}
std::string stringCharacterReplace(std::string str, char _oldch,
	std::string _newch) {
	std::string res{};
	for (auto ch : str) {
		if (ch == _oldch) {

			res = res + _newch;
		}
		else {
			res = res + ch;
		}
	}
	return res;
}
int run(const char* cmd) {


	int result = system(cmd);

	if (result == 0) {

		std::cout << "CMD命令执行成功." << std::endl;
	}
	else {

		std::cerr << "CMD命令执行失败." << std::endl;
	}

	return 0;
}

std::string exec_cmd(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}
void TextTurnsSound(std::string _txt)
{
	std::string cmd_string = " echo '" + _txt + "' | .\\piper\\piper.exe --model .\\piper\\zh_CN-huayan-medium.onnx -c .\\piper\\zh_zh_CN_huayan_medium_zh_CN-huayan-medium.onnx.json --output_file ./b.wav";
	run(cmd_string.c_str());
}
int create_txt(std::string _txtPath, std::string _nameTxt)
{
	std::ofstream oFile;
	//不存在则新建文件
	oFile.open(_txtPath, std::ios::app);
	if (!oFile)  //true则说明文件打开出错
		std::cout << "error 1" << std::endl;
	else
		oFile << _nameTxt;

	oFile.close();

	return 0;
}
