// cbuffer
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

// types
struct VertexInputType
{
	float4 position : POSITION;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 tex : TEXCOORD0;
};

PixelInputType AlphaMapVertexShader(VertexInputType input)
{
	PixelInputType output;

	// 좌표 계산을 위해서
	input.position.w = 1.0f;

	// 매트릭스 계산
	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

	// 텍스쳐 저장
	output.tex = input.tex;

	return output;
}