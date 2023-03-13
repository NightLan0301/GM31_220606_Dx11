#pragma once
#include"main.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

#include "scene.h"

class Result : public Scene
{
private:
	class Transition* m_Transition;

public:
	void Init();
	void Uninit();
	void Update();

};