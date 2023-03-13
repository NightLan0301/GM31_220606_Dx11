#include"main.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"


#include "result.h"
#include "title.h"
#include "ResultLogo.h"
#include "transition.h"



void Result::Init()
{
	AddGameObject<ResultLogo>(2);

	m_Transition = AddGameObject<Transition>(2);

	m_Transition->Start(true);

}

void Result::Uninit()
{
	Scene::Uninit();
}

void Result::Update()
{
	Scene::Update();

	if (Input::GetKeyTrigger(VK_SPACE))
	{
		m_Transition->Start(false);
	}
	if (m_Transition->GetFinish())
	{
		Manager::SetScene<Title>();
	}

	//if (Input::GetKeyTrigger(VK_SPACE))
	//{
	//	Manager::SetScene<Title>();
	//}
}
