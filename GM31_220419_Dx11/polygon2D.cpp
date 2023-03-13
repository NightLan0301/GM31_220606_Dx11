#include "main.h"
#include"renderer.h"
#include "polygon2D.h"

void Polygon2D::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position	 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Normal	 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse	 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord	 = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position	 = D3DXVECTOR3(200.0f, 0.0f, 0.0f);
	vertex[1].Normal	 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse	 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord	 = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position	 = D3DXVECTOR3(0.0f, 200.0f, 0.0f);
	vertex[2].Normal	 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse	 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord	 = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position	 = D3DXVECTOR3(200.0f, 200.0f, 0.0f);
	vertex[3].Normal	 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[3].Diffuse	 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord	 = D3DXVECTOR2(1.0f, 1.0f);

	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = vertex;

	Renderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	D3DX11CreateShaderResourceViewFromFile(	Renderer::GetDevice(), 
											"assert\\brick.jpg", 
											NULL,
											NULL,
											&m_Texture, 
											NULL);
	assert(m_Texture);

	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout, "unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader, "unlitTexturePS.cso");
}

void Polygon2D::Uninit()
{
	m_VertexBuffer->Release();
	m_Texture->Release();

	m_VertexLayout->Release();
	m_VertexShader->Release();
	m_PixelShader->Release();

}

void Polygon2D::Update()
{
}

void Polygon2D::Draw()
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
