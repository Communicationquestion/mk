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
void TextTurnsSound(std::string _txt)
{
	std::string cmd_string = " echo '" + _txt + "' | .\\piper\\piper.exe --model .\\piper\\zh_CN-huayan-medium.onnx -c .\\piper\\zh_zh_CN_huayan_medium_zh_CN-huayan-medium.onnx.json --output_file ./b.wav";
	run(cmd_string.c_str());
}
