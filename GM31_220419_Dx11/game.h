#pragma once

#include "scene.h"

class Game : public Scene
{
private:
	class Transition* m_Transition;


public:
	void Init();
	void Uninit();
	void Update();

};