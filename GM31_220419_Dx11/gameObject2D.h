#pragma once


class GameObject2D
{
protected://アクセス指定子
	bool m_Destroy = false;

	D3DXVECTOR3 m_Position2D;
	D3DXVECTOR3 m_Normal2D;
	D3DXVECTOR4 m_Diffuse2D;
	D3DXVECTOR2 m_TexCoord2D;

	D3DXVECTOR2 m_Scale2D;


public:
	GameObject2D() {}
	virtual ~GameObject2D() {}

	virtual void Init() = 0; //純粋仮想関数
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetPosition2D(D3DXVECTOR3 Position)
	{
		m_Position2D = Position;
	}
	D3DXVECTOR3 GetPosition2D() { return m_Position2D; }


	void SetNormal2D(D3DXVECTOR3 Position)
	{
		m_Normal2D = Position;
	}
	D3DXVECTOR3 GetNormal2D() { return m_Normal2D; }


	void SetDiffuse2D(D3DXVECTOR4 Position)
	{
		m_Diffuse2D = Position;
	}
	D3DXVECTOR4 GetDiffuse2D() { return m_Diffuse2D; }


	void SetTexCoord2D(D3DXVECTOR2 Position)
	{
		m_TexCoord2D = Position;
	}
	D3DXVECTOR2 GetTexCoord2D() { return m_TexCoord2D; }




	void SetScale(D3DXVECTOR2 Scale)
	{
		m_Scale2D = Scale;
	}
	D3DXVECTOR2 GetScale() { return m_Scale2D; }



	void SetDestroy() { m_Destroy = true; }




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

#pragma once
