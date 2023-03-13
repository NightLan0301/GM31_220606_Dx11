#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "input.h"
#include "game.h"
#include "title.h"
#include "result.h"
#include "audio.h"
#include "Shadow.h"
#include "BackGround2D.h"
#include "Player2D.h"

Scene* Manager::m_Scene = NULL;

void Manager::Init()
{
	Renderer::Init();
	Input::Init();
	Audio::InitMaster();

	//m_Scene = new Game/*Title*/();
	//m_Scene->Init();

	SetScene<Game>();
}


void Manager::Uninit()
{
	m_Scene->Uninit();
	delete m_Scene;

	Audio::UninitMaster();
	Input::Uninit();
	Renderer::Uninit();
}

void Manager::Update()
{
	Input::Update();
	m_Scene->Update();
}

void Manager::Draw()
{
	Renderer::Begin();

	m_Scene->Draw();

	Renderer::End();
}
