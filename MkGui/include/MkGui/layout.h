#pragma once
#include <MkGui/customcontrol.h>
#include <iostream>
#include <memory>
#include <type_traits>
#include <variant>
#include <vector>


// class LayoutManager {
//
//
//	public:
//	void add(std::shared_ptr<std::variant> item) {
//		items.push_back(item);
//	}
//
//	void draw() const {
//		for (const auto& item : items) {
//				item->draw();
//		}
//	}
//	protected:
//	std::vector < std::shared_ptr < std::variant<CustomControl<>>>> items;
// };


// int main() {
//	// 创建一些控件
//	auto button1 = std::make_shared<Button>();
//	auto button2 = std::make_shared<Button>();
//
//	// 创建一个普通的 LayoutManager 来管理控件
//	auto layout1 = std::make_shared<LayoutManager<Button>>();
//	layout1->add(button1);
//	layout1->add(button2);
//
//	// 创建一个嵌套的 LayoutManager 来管理其他 LayoutManager
//	auto nestedLayout = std::make_shared<LayoutManager<LayoutManager<Button>>>();
//	nestedLayout->add(layout1);
//
//	// 绘制嵌套布局
//	nestedLayout->draw();
//
//	return 0;
// }
