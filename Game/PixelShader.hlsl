
//Pong
//float4 main(float3 color : Color) : SV_Target
//{
//	return float4(color, 1.0f);
//}

// End pong

cbuffer CBuf
{
	float4 face_colors[6];
};

float4 main(uint tid : SV_PrimitiveID) : SV_Target
{
	return face_colors[tid / 2];
}