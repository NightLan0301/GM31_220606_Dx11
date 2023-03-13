#pragma once

#include <list>
#include <vector>
#include <typeinfo>
#include "gameObject.h"
#include "gameObject2D.h"

class Scene
{
protected:
	std::list<GameObject*> m_GameObject[3];

public:
	Scene() {}
	virtual ~Scene() {}

	virtual void Init() = 0;

	template <typename T>
	T* AddGameObject(int Layer)
	{
		T* gameObject = new T();
		m_GameObject[Layer].push_back(gameObject);
		gameObject->Init();

		return gameObject;
	}

	//for 1 object
	template <typename T>
	T* GetGameObject(int Layer)
	{
		for (GameObject* object : m_GameObject[Layer]) {
			if (typeid(*object) == typeid(T)) //Œ^‚ğ’²‚×‚é(RTTI“®“IŒ^î•ñ)
			{
				return(T*) object;
			}
		}
		return NULL;
	}

	//for multiple same object(like bullet)
	template <typename T>
	std::vector<T*> GetGameObjects(int Layer)
	{
		std::vector<T*> objects;
		for (GameObject* object : m_GameObject[Layer]) {
			if (typeid(*object) == typeid(T)) //Œ^‚ğ’²‚×‚é(RTTI“®“IŒ^î•ñ)
			{
				objects.push_back((T*)object);
			}
		}
		return objects;
	}

	virtual void Uninit()
	{
		for (int i = 0; i < 3; i++)
		{
			for (GameObject* object : m_GameObject[i])
			{
				object->Uninit();
				delete object;
			}
			m_GameObject[i].clear();
		}

	}

	virtual void Update()
	{
		for (int i = 0; i < 3; i++)
		{
			for (GameObject* object : m_GameObject[i])
			{
				object->Update();
			}
			m_GameObject[i].remove_if([](GameObject* object)
				{return object->Destroy(); });
		}
	}

	virtual void Draw()
	{
		for (int i = 0; i < 3; i++)
		{
			for (GameObject* object : m_GameObject[i])
			{
				object->Draw();
			}
		}
	}
};
