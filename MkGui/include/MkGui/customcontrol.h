#pragma once
#include <functional>
#include <imgui/imgui.h>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>

struct SliderFloat {};
struct Checkbox {};
struct InputText {};

template <typename ControlType, typename... DataTypes>
struct Control {};

template <typename... T>
struct Control<SliderFloat, T...> {
    static void Draw(const std::string label, T*... values) {
        float sum = 3;
        if constexpr (sizeof...(T) > 0) {
            std::string title = label + std::to_string(sum);
            // ImGui::SliderFloat(title.c_str(),
            //				   &sum,
            //				   0.0f,
            //				   1.0f);
        }
    }
    static void set_data(T*... values) {

        if constexpr (sizeof...(T) > 0) {
        }
    }
};

template <typename... T>
struct Control<Checkbox, T...> {
    static void Draw(const std::string& label, T*... values) {
        double sum = 0;
        ((sum += (*values ? 1.0 : 0.0)), ...);
        std::cout << "Sum of values for " << label << ":" << sum << std::endl;

        if constexpr (sizeof...(T) > 0) {
        }
    }
};

template <typename... T>
struct Control<InputText, T...> {
    static void Draw(const std::string& label, T*... values) {
        double sum = 0;
        ((sum += static_cast<double>(values->length())), ...);
        std::cout << "Sum of values for " << label << ":" << sum << std::endl;
        if constexpr (sizeof...(T) > 0) {
        }
    }
};

template <typename ControlType, typename... DataTypes>
class CustomControl {
public:
    explicit CustomControl(const std::string& label, DataTypes*... data) : label_(label), data_(data...) {}
    void Draw() {
        std::apply([this](auto&&... args) { Control<ControlType, DataTypes...>::Draw(label_, args...); }, data_);
    }
    void set_data() {
        std::apply([this](auto&&... args) { Control<ControlType, DataTypes...>::set_data(args...); }, data_);
    }

private:
    std::string label_;
    std::tuple<DataTypes*...> data_;
};
