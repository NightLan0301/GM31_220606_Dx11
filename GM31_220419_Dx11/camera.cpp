#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "camera.h"
#include "scene.h"
#include "game.h"

void Camera::Init()
{
	m_Position = D3DXVECTOR3(0.0f, 1.0f, -10.0f);
	m_Target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

void Camera::Uninit()
{
}

void Camera::Update()
{
	Scene* scene = Manager::GetScene();

	//god veiw
	//m_Target = playerPosition;
	//m_Position = playerPosition
	//	+ D3DXVECTOR3(0.0f, 2.0f, -5.0f);

	//tpv
	//m_Target = playerPosition;
	//m_Position = playerPosition
	//		- playerForward * 5.0f
	//		+ D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//fpv
	//m_Target = playerPosition + playerForward;
	//m_Position = playerPosition;
}

void Camera::Draw()
{
	//D3DXMATRIX viewMatrix;
	D3DXVECTOR3  up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&m_ViewMatrix,
		&m_Position, 
		&m_Target,
		&up);

	Renderer::SetViewMatrix(&m_ViewMatrix);

	D3DXMATRIX projectionMatrix;
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, 1.0f,
		(float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);

		Renderer::SetProjectionMatrix(&projectionMatrix);

}
