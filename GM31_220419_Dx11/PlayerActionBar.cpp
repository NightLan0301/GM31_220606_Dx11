#include "main.h"
#include"renderer.h"
#include "PlayerActionBar.h"
#include "player2D.h"
#include "input.h"


void PAB::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(0.0, 350.0f, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(100, 350.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(100.0f, SCREEN_HEIGHT, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = vertex;

	Renderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	D3DX11CreateShaderResourceViewFromFile(Renderer::GetDevice(),
		"assert\\command.png",
		NULL,
		NULL,
		&m_Texture,
		NULL);
	assert(m_Texture);

	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout, "unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader, "unlitTexturePS.cso");
}

void PAB::Uninit()
{
	m_VertexBuffer->Release();
	m_Texture->Release();

	m_VertexLayout->Release();
	m_VertexShader->Release();
	m_PixelShader->Release();

}

void PAB::Update()
{
}

void PAB::Draw()
{
	//layout
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//shader
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//matrix
	Renderer::SetWorldViewProjection2D();

	// vertex buffer
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	Renderer::GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

	//texture buffer
	Renderer::GetDeviceContext()->PSSetShaderResources(0, 1, &m_Texture);


	Renderer::GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//draw polygon
	Renderer::GetDeviceContext()->Draw(4, 0);


}

VERTEX_3D arrow[4];
D3DXVECTOR3 arrowPos(10.0, 360.0f, 0.0f);

void PAB_ARROW::Init()
{

	arrow[0].Position = D3DXVECTOR3(0.0 + arrowPos.x, 0.0f + arrowPos.y, 0.0f);
	arrow[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	arrow[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	arrow[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	arrow[1].Position = D3DXVECTOR3(25.0f + arrowPos.x, 0.0f + arrowPos.y, 0.0f);
	arrow[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	arrow[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	arrow[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	arrow[2].Position = D3DXVECTOR3(0.0f + arrowPos.x, 25.0f + arrowPos.y, 0.0f);
	arrow[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	arrow[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	arrow[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	arrow[3].Position = D3DXVECTOR3(25.0f + arrowPos.x, 25.0f + arrowPos.y, 0.0f);
	arrow[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	arrow[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	arrow[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);


	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = arrow;

	Renderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	D3DX11CreateShaderResourceViewFromFile(Renderer::GetDevice(),
		"assert\\command arrow.png",
		NULL,
		NULL,
		&m_Texture,
		NULL);
	assert(m_Texture);

	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout, "unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader, "unlitTexturePS.cso");


}

void PAB_ARROW::Uninit()
{

	m_VertexBuffer->Release();
	m_Texture->Release();

	m_VertexLayout->Release();
	m_VertexShader->Release();
	m_PixelShader->Release();


}

void PAB_ARROW::Update()
{

	if (Input::GetKeyTrigger(VK_UP))
	{
		for (int i = 0; i < 4; i++)
		{
			arrow[i].Position.y -= 50.0f;
		}
	}
	else if (Input::GetKeyTrigger(VK_DOWN))
	{
		for (int i = 0; i < 4; i++)
		{
			arrow[i].Position.y += 50.0f;
		}

	}
}

void PAB_ARROW::Draw()
{

	arrow[0].Position = D3DXVECTOR3(0.0 + arrowPos.x, 0.0f + arrowPos.y, 0.0f);
	arrow[1].Position = D3DXVECTOR3(25.0f + arrowPos.x, 0.0f + arrowPos.y, 0.0f);
	arrow[2].Position = D3DXVECTOR3(0.0f + arrowPos.x, 25.0f + arrowPos.y + 100.0f, 0.0f);
	arrow[3].Position = D3DXVECTOR3(25.0f + arrowPos.x, 25.0f + arrowPos.y + 100.0f, 0.0f);

	//layout
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//shader
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//matrix
	Renderer::SetWorldViewProjection2D();

	// vertex buffer
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	Renderer::GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

	//texture buffer
	Renderer::GetDeviceContext()->PSSetShaderResources(0, 1, &m_Texture);


	Renderer::GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//draw polygon
	Renderer::GetDeviceContext()->Draw(4, 0);


}
