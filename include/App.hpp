#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
//#include "Util/Text.hpp"

#include "Character.hpp"
#include "PhaseResourceManager.hpp"
#include "AnimatedCharacter.hpp"

//#include "InitializeMap.cpp"

class App {
public:
	//App();

    enum class State {
        START,
        UPDATE,
        END,
    };
    State GetCurrentState() const { return m_CurrentState; }

    void Start();
    void Update();
    void End();

private:
    void ValidTask();
	void InitializeMap(const std::vector<std::vector<int>>& GameMap);
    //void CheckPoint();

private:
    enum class Phase {
        MENU,
        LEVEL,
        LEVEL1,
        LEVEL2,
    };

    State m_CurrentState = State::START;
	Phase m_Phase = Phase::MENU;

    bool m_PhaseChanged = false;

    std::shared_ptr<PhaseResourceManager> m_PRM;

    std::shared_ptr<Character> m_Player;
    std::shared_ptr<Character> m_Box;
    std::vector<std::shared_ptr<Character>> m_Wall;
	std::vector<std::shared_ptr<Character>> m_Floor;
    std::shared_ptr<Character> m_Point;
    std::shared_ptr<Character> m_Check;
    
    /* 讀人的位置 */
    bool isPlayerOnCheck = false;
    int m_PlayerPosition_i = 0;
    int m_PlayerPosition_j = 0;

    /* 讀箱子的位置 */
    bool isBoxOnCheck = false;
	int m_BoxPosition_i = 0;
	int m_BoxPosition_j = 0;

    Util::Renderer m_Root;

    std::vector<std::vector<int>> m_GameMap;

    /* 地圖 */
    /* 0:草地 1:牆壁 2:空地 3:箱子 4:人物 5:目標點*/
    std::vector<std::vector<int>> GameMap1 = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 5, 2, 2, 1},
        {1, 2, 3, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 4, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    std::vector<std::vector<int>> GameMap2 = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 4, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 5, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 3, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
};

#endif