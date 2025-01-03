#pragma once
#include <MkGui/MkGui.h>
#include <iostream>
#include <optional>
#include <MkGui/customcontrol.h>
class ui1 {
	public:
		std::optional<std::string> run() {
			return	m_testwin1.run();
		}
	private:
	windowui<> m_testwin1;
};


class ui2 {
public:
	std::optional<std::string> run() {
		return m_testwin2.run();
	}
private:
	windowui<> m_testwin2;
};

class TestApp {
public:
	TestApp();
	void initui();
	void app_run();
private:
	ui1 m_testui1;
	ui2 m_testui2;
};