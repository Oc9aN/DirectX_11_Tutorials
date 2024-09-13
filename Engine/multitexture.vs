cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

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

PixelInputType MultiTextureVertexShader(VertexInputType input)
{
	PixelInputType output;

	// 적절한 행렬 계산을 위해서 w 값을 1로 설정 -> 위치좌표
	input.position.w = 1.0f;

	// 월드, 뷰, 투영 행렬에 대해서 계산한다.
	output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);

	// 텍스트 정보를 저장
	output.tex = input.tex;

	return output;
}