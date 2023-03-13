#include"main.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"



#include "title.h"
#include "game.h"
#include "TitleLogo.h"
#include "transition.h"


void Title::Init()
{
	AddGameObject<TitleLogo>(2);

	m_Transition = AddGameObject<Transition>(2);

	m_Transition->Start(true);
}

void Title::Uninit()
{
	Scene::Uninit();
}

void Title::Update()
{
	Scene::Update();

	if (Input::GetKeyTrigger(VK_SPACE))
	{
		m_Transition->Start(false);
	}

	if (m_Transition->GetFinish())
	{
		Manager::SetScene<Game>();
	}

}
