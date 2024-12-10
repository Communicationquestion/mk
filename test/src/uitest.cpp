#include "../include/test/uitest.h"
#include <MkGui/customcontrol.h>
#include <memory>
TestApp::TestApp() {

}

void TestApp::initui() {
	//CustomControl<InputText, "test"> a();
	//
	
	auto company_inputTxt = std::make_unique<CustomControl<InputText, std::string>>("company", &std::string("company"));
	auto account_inputTxt = std::make_unique<CustomControl<InputText, std::string>>("account", &std::string("account"));
	auto passwd_inputTxt = std::make_unique<CustomControl<InputText, std::string>>("passwd", &std::string("passwd"));
	auto key_inputTxt = std::make_unique<CustomControl<InputText, std::string>>("key", &std::string("key"));



}

void TestApp::app_run() {
	lookerr(m_testui.run());

}