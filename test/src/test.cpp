#include "../include/test/test.h"
#include <MkGui/MkGui.h>
#include <abstraction_command/abstraction_command.h>
#include <commands/cmake_command.h>
#include <gtest/gtest.h>
#include <iostream>
#include <mk_command_strategy/mk_command_strategy.h>
#include <optional>

int main_test(std::vector<std::string> cmd_strs) {
  std::vector<std::string> v_commands{};
  for (auto &cmd_str : cmd_strs) {
    v_commands.push_back(cmd_str);
  }
  std::string _cmd = v_commands.at(0);
  MkCommandStrategy::CMKCommandStrategy test(_cmd);
  test.initmap();
  test.execute(v_commands);
  return 0;
}
int imgui_test() {

  TestApp tapp;

  tapp.app_run();

  return 0;
}
namespace {
TEST(Imgui, PositiveNumbers) { EXPECT_EQ(imgui_test(), 0); }
TEST(Transltate, PositiveNumbers) {
  EXPECT_EQ(main_test({"enzh", "hello"}), 0);
  EXPECT_EQ(main_test({"zhen", "你好"}), 0);
}
} // namespace
int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}
