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

	// ������ ��� ����� ���ؼ� w ���� 1�� ���� -> ��ġ��ǥ
	input.position.w = 1.0f;

	// ����, ��, ���� ��Ŀ� ���ؼ� ����Ѵ�.
	output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);

	// �ؽ�Ʈ ������ ����
	output.tex = input.tex;

	return output;
}