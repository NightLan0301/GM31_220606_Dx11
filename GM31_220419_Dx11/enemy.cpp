#include "main.h"
#include "renderer.h"
#include "model.h"
#include "enemy.h"
#include "manager.h"

bool EisOnAir = false;

void Enemy::Init()
{
	m_Model = new Model();
	m_Model->Load("assert\\torus.obj");

	m_Position = D3DXVECTOR3(0.0f, 1.0f, 5.0f);		//coordinate
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);


	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout, "vertexLightingVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader, "vertexLightingPS.cso");


	m_Velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

}

void Enemy::Uninit()
{
	m_Model->Unload();
	delete m_Model;

	m_VertexLayout->Release();
	m_VertexShader->Release();
	m_PixelShader->Release();

}

void Enemy::Update()
{

	//’ïR
	m_Velocity.x -= m_Velocity.x * 0.1f;
	m_Velocity.y -= m_Velocity.y * 0.01f;
	m_Velocity.z -= m_Velocity.z * 0.1f;

	D3DXVECTOR3 oldPosition = m_Position;

	//ˆÚ“®
	m_Position += m_Velocity;

	//d—Í
	m_Velocity.y -= 0.01f;

	float groundHeight = 0.0f;

}

void Enemy::Draw()
{
	//layout
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//shader
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//world matrix
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.x, m_Rotation.y, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;
	Renderer::SetWorldMatrix(&world);

	m_Model->Draw();

}
