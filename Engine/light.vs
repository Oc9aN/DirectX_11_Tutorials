/////////////
// DEFINES //
/////////////
#define NUM_LIGHTS 4

/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};

cbuffer CameraBuffer
{
    float3 cameraPosition;
    float padding;
};

cbuffer LightPositionBuffer
{
    float4 lightPosition[NUM_LIGHTS];
};

//////////////
// TYPEDEFS //
//////////////
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
    float3 normal : NORMAL;
    float3 viewDirection : TEXCOORD1;
    float3 lightPos[NUM_LIGHTS] : TEXCOORD2;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType LightVertexShader(VertexInputType input)
{
    PixelInputType output;
    float4 worldPosition;
    int i;

    // Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;

    // Calculate the position of the vertex against the world, view, and projection matrices.
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
    
    // Store the texture coordinates for the pixel shader.
    output.tex = input.tex;
    // Calculate the normal vector against the world matrix only.
    // �븻 ���͸� ���� ��İ� ���
    output.normal = mul(input.normal, (float3x3)worldMatrix);
	
    // Normalize the normal vector.
    // ��� �� Ȥ�� ũ�Ⱑ ������ ���� �ֱ⶧���� �븻������ 
    output.normal = normalize(output.normal);

    // Calculate the position of the vertex in the world.
    // ������ ���� ��ġ�� ����
    worldPosition = mul(input.position, worldMatrix);

    // Determine the viewing direction based on the position of the camera and the position of the vertex in the world.
    // ������ ��ġ�� ī�޶��� ��ġ�� ���� ��� ���͸� ����
    output.viewDirection = cameraPosition.xyz - worldPosition.xyz;
	
    // Normalize the viewing direction vector.
    // ����� ������ ����ȭ
    output.viewDirection = normalize(output.viewDirection);

    for(i=0; i<NUM_LIGHTS; i++)
    {
        // ������� ���� ��ġ�� ���� ��ġ�� ���ؼ� ���������� ���� ��ġ�� ���� -> ���� ps���� lightDir����
        output.lightPos[i] = lightPosition[i].xyz - worldPosition.xyz;

        // ���� ��ġ ���͸� �ʱ�ȭ
        // output.lightPos[i] = normalize(output.lightPos[i]);
    }

    return output;
}