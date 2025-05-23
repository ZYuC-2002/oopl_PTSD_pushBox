#ifndef TASKTEXT_HPP
#define TASKTEXT_HPP

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"

class TaskText : public Util::GameObject {
public:
    TaskText() : GameObject(
        std::make_unique<Util::Text>(
            RESOURCE_DIR"/Font/BodoniFLF-Bold.ttf", 
            50,
            append_string_views(s_PhaseTasks[0], s_Validation),
            Util::Color::FromName(Util::Colors::WHITE)),
            100){
            m_Transform.translation = { 15.F, 200.F };
    }

    TaskText(const std::string& fontPath, int fontSize, const std::string& text, const Util::Color& color)
        : GameObject(
            std::make_unique<Util::Text>(fontPath, fontSize, text, color),
            100) {
        m_Transform.translation = { 0.F, -270.F }; // 預設位置
    }

    void NextPhase(const int phase) {
        //std::cout << "NextPhase" << std::endl;
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(append_string_views(s_PhaseTasks[phase], s_Validation));
    }

    void SetText(const std::string& text) {
        //std::cout << "SetText" << std::endl;
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(text);
    }

    void UpdatePosition(float x, float y) { // 更新位置
        //std::cout << "UpdatePosition" << std::endl;
        m_Transform.translation = { x, y }; 
    }

private:
    inline static std::string append_string_views(std::string_view sv1, std::string_view sv2) {
        return std::string(sv1) + "\n" + std::string(sv2);
    }

    static constexpr std::string_view s_PhaseTasks[32] = {
        "", "",
        "LEVEL1",  "LEVEL2",  "LEVEL3",  "LEVEL4",  "LEVEL5",
        "LEVEL6",  "LEVEL7",  "LEVEL8",  "LEVEL9",  "LEVEL10",
        "LEVEL11", "LEVEL12", "LEVEL13", "LEVEL14", "LEVEL15",
        "LEVEL16", "LEVEL17", "LEVEL18", "LEVEL19", "LEVEL20",
        "LEVEL21", "LEVEL22", "LEVEL23", "LEVEL24", "LEVEL25",
        "LEVEL26", "LEVEL27", "LEVEL28", "LEVEL29", "LEVEL30"
    };
    static constexpr std::string_view s_Validation = "";
};


#endif //TASKTEXT_HPP