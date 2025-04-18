#include "App.hpp"

#include "Util/Logger.hpp"

#include <iostream>

//#include "InitializeMap.cpp"

void App::Start() {
    LOG_TRACE("Start");
	std::cout << "Start" << std::endl;
    
    /* Phase Resource Manager */
    m_PRM = std::make_shared<PhaseResourceManager>();
    m_Root.AddChildren(m_PRM->GetChildren());

	btn_return = std::make_shared<Character>(RESOURCE_DIR"/Button/btn_return.png");
	m_Root.AddChild(btn_return);
	btn_return->SetZIndex(50);
	btn_return->SetPosition({ -155, 295 });
	btn_return->SetVisible(false);

	btn_reset = std::make_shared<Character>(RESOURCE_DIR"/Button/btn_reset.png");
	m_Root.AddChild(btn_reset);
	btn_reset->SetZIndex(50);
	btn_reset->SetPosition({ 155, 295 });
	btn_reset->SetVisible(false);

    m_CurrentState = State::UPDATE;
}