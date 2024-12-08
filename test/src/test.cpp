#include <abstraction_command/abstraction_command.h>
#include <commands/cmake_command.h>
#include <mk_command_strategy/mk_command_strategy.h>
#include <gtest/gtest.h>
#include <MkGui/imgui.h>
int main_test(std::vector<std::string> cmd_strs) {

	std::vector<std::string> v_commands{};


	for(auto& cmd_str : cmd_strs) {
		v_commands.push_back(cmd_str);
	}

	std::string _cmd = v_commands.at(0);

	MkCommandStrategy::CMKCommandStrategy test(_cmd);

	test.initmap();
	// test.add("cmake", new CmakeCommand);
	test.execute(v_commands);
	return 0;
}
int imgui_test(){
    init();
    return 0;
}
namespace
{

	TEST(AddTest, PositiveNumbers) {
	    EXPECT_EQ(imgui_test(), 0);
		EXPECT_EQ(main_test({"passwd"}), 0);
		EXPECT_EQ(main_test({"enzh","hello"}), 0);
		EXPECT_EQ(main_test({"zhen","你好"}), 0);
	}
}
int main(int argc, char* argv[]) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;
}
