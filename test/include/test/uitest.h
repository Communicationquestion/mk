#pragma once
#include <MkGui/MkGui.h>
#include <iostream>
#include <optional>
#include <MkGui/customcontrol.h>

class ui1 {

	public:
		std::optional<std::string> run() {
			return	m_testwin.run();
		}
	private:
	windowui<> m_testwin;
};

class TestApp {
	public:
	TestApp();
	void initui();
	void app_run();
	private:
	ui1 m_testui;

};