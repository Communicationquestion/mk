#include<abstraction_create/abstraction_create.h>
#include <fstream>

project_path::project_path abstraction_create::Abs_create::set_project_path(std::string _file)
{

	ProjectPath.set_path(_file, "CMakeLists.txt");



	ProjectPath.print_path();

	return ProjectPath;
}


module_path::ModulePath abstraction_create::Abs_create::set_module_Path(std::string _file_path)
{

	ModulePath.set_path(_file_path, "CMakeLists.txt");

	ModulePath.print_path();

	return ModulePath;
}

project_path::project_path abstraction_create::Abs_create::get_project_path()
{
	return ProjectPath;
}

module_path::ModulePath abstraction_create::Abs_create::get_module_Path()
{
	return ModulePath;
}


bool abstraction_create::Abs_create::MkDir(const std::string& strPath)
{
	int i = 0;
	int nDirLen = strPath.length();
	if (nDirLen <= 0)
		return false;
	char* pDirTemp = new char[nDirLen + 4];
	strPath.copy(pDirTemp, nDirLen + 1, 0);// +1 to copy '\0'
	pDirTemp[nDirLen] = '\0';
	//在末尾加'/'
	if (pDirTemp[nDirLen - 1] != '\\' && pDirTemp[nDirLen - 1] != '/')
	{
		pDirTemp[nDirLen] = '/';
		pDirTemp[nDirLen + 1] = '\0';
		nDirLen++;
	}
	// 创建目录
	for (i = 0; i < nDirLen; i++)
	{
		if (pDirTemp[i] == '\\' || pDirTemp[i] == '/')
		{
			pDirTemp[i] = '\0';//截断后面的子目录，逐级查看目录是否存在，若不存在则创建
			//如果不存在,创建
			int statu;
			statu = ACCESS(pDirTemp, 0);
			if (statu != 0)//可能存在同名文件导致没有创建
			{
				statu = MKDIR(pDirTemp);
				if (statu != 0)//可能上级不是文件夹而是同名文件导致创建失败
				{
					return false;
				}
			}
			//支持linux,将所有\换成/
			pDirTemp[i] = '/';
		}
	}
	delete[] pDirTemp;
	return true;
}
int abstraction_create::Abs_create::create_cmaketxt(std::string _cmakePath, std::string _txt)
{
	std::ofstream oFile;
	//不存在则新建文件
	oFile.open(_cmakePath, std::ios::app);
	if (!oFile)  //true则说明文件打开出错
		std::cout << "error 1" << std::endl;
	else
		oFile << _txt;

	oFile.close();

	return 0;

}

int abstraction_create::Abs_create::create_txt(std::string _txtPath, std::string _nameTxt)
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
int abstraction_create::Abs_create::create_txt(std::string _txtPath)
{
	std::ofstream oFile;
	//不存在则新建文件
	oFile.open(_txtPath, std::ios::app);
	if (!oFile)  //true则说明文件打开出错
		std::cout << "error 1" << std::endl;
	else
		oFile;

	oFile.close();

	return 0;
}