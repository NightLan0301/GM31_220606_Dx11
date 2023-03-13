#include"main.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

#include "camera.h"
#include"field.h"
#include"model.h"
#include"enemy.h"
#include"polygon2D.h"

#include "game.h"
#include "result.h"
#include "audio.h"
#include "Shadow.h"
#include "Score.h"

#include "transition.h"



#include "BackGround2D.h"
#include "Player2D.h"
#include "Enemy2D.h"
#include "PlayerStatusBar.h"
#include "PlayerActionBar.h"

PAB_ARROW* PAB_Arrow;

void Game::Init()
{	

	//AddGameObject <Camera>(0);
	AddGameObject <BackGround2D>(0);
	AddGameObject <Player2D>(1);

	Enemy2D* enemy1 = AddGameObject <Enemy2D>(1);
	
	PSB* PlayerStatusBar = AddGameObject <PSB>(2);
	PSB_AvataIcon* AvataIcon = AddGameObject <PSB_AvataIcon>(2);

	PSB_AvataMAXHP* AvataMAXHP = AddGameObject <PSB_AvataMAXHP>(2);
	PSB_AvataHP* AvataHP = AddGameObject <PSB_AvataHP>(2);

	PSB_AvataMAXMP* AvataMAXMP = AddGameObject <PSB_AvataMAXMP>(2);
	PSB_AvataMP* AvataMP = AddGameObject <PSB_AvataMP>(2);


	PAB* PlayerActionBar = AddGameObject <PAB>(2);
	PAB_Arrow = AddGameObject <PAB_ARROW>(2);

	//Enemy2D* enemy2 = AddGameObject <Enemy2D>(1);

	//Enemy2D* enemy3 = AddGameObject <Enemy2D>(1);


	Audio* bgm = AddGameObject<Audio>(2);
	bgm->Load("assert\\bgm.wav");
	bgm->Play(true);


	m_Transition = AddGameObject<Transition>(2);

	m_Transition->Start(true);


}

void Game::Uninit()
{
	Scene::Uninit();


}

void Game::Update()
{
	Scene::Update();



	if (Input::GetKeyTrigger(VK_SPACE))
	{
		m_Transition->Start(false);
	}

	if (m_Transition->GetFinish())
	{
		Manager::SetScene<Result>();
	}



}
