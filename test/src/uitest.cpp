#include "../include/test/uitest.h"
#include <MkGui/customcontrol.h>
#include <memory>
TestApp::TestApp() {}

void TestApp::initui() {
  // CustomControl<InputText, "test"> a();
  //
  // m_testui
}

void TestApp::app_run() {

  lookerr<std::string, true>(m_testui1.run());
  lookerr<std::string, true>(m_testui2.run());
}
