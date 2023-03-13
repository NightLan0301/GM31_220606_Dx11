#pragma once
#include "gameObject.h"
class Score :
    public GameObject
{
private:
	ID3D11Buffer* m_VertexBuffer = NULL;
	ID3D11ShaderResourceView* m_Texture = NULL;

	ID3D11VertexShader* m_VertexShader = NULL;
	ID3D11PixelShader* m_PixelShader = NULL;
	ID3D11InputLayout* m_VertexLayout = NULL;

	int s_Count;

	class Audio* m_ExploSE;


public:
	void Init()		override;
	void Uninit()	override;
	void Update()	override;
	void Draw()		override;

	void AddCount(float count)
	{
		s_Count += count;
	};

};

