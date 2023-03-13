#pragma once


class GameObject
{
protected://アクセス指定子
	bool m_Destroy = false;

	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;


public:
	GameObject() {}
	virtual ~GameObject() {}

	virtual void Init() = 0; //純粋仮想関数
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetPosition(D3DXVECTOR3 Position)
	{
		m_Position = Position;
	}
	D3DXVECTOR3 GetPosition() { return m_Position; }


	void SetRotation(D3DXVECTOR3 Rotation)
	{
		m_Rotation = Rotation;
	}
	D3DXVECTOR3 GetRotation() { return m_Rotation; }


	void SetScale(D3DXVECTOR3 Scale)
	{
		m_Scale = Scale;
	}
	D3DXVECTOR3 GetScale() { return m_Scale; }



	void SetDestroy() { m_Destroy = true; }

	D3DXVECTOR3 GetForward()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot,
			m_Rotation.y,
			m_Rotation.x,
			m_Rotation.z);

		D3DXVECTOR3 forward;
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;

		return forward;
	}
	D3DXVECTOR3 GetSideway()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot,
			m_Rotation.y,
			m_Rotation.x,
			m_Rotation.z);

		D3DXVECTOR3 sideway;
		sideway.x = rot._11;
		sideway.y = rot._12;
		sideway.z = rot._13;

		return sideway;
	}

	bool Destroy()
	{
		if (m_Destroy)
		{
			Uninit();
			delete this;
			return true;
		}
		else
		{
			return false;
		}
	}
};

