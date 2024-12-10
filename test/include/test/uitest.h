#pragma once
#include <MkGui/MkGui.h>
#include <iostream>
#include <optional>

class TestApp {
	public:
	TestApp();
	void initui();
	void app_run();

	private:
	windowui<> m_testui;
};