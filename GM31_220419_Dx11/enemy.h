#pragma once

#include "gameObject.h"

class Model;

class Enemy : public GameObject
{
private:
	Model* m_Model;

	ID3D11VertexShader* m_VertexShader = NULL;
	ID3D11PixelShader* m_PixelShader = NULL;
	ID3D11InputLayout* m_VertexLayout = NULL;

	D3DXVECTOR3 m_Velocity;

public:
	void Init()		override;
	void Uninit()	override;
	void Update()	override;
	void Draw()		override;
};