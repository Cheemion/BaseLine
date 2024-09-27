Texture2D gInputA : register(t0);
Texture2D gInputB : register(t1);

RWTexture2D<float4> gOutput : register(u0);

[numthreads(16,16,1)]
void main(uint3 dispatchThreadID : SV_DispatchThreadID, uint3 groupID: SV_GroupID)
{
    gOutput[dispatchThreadID.xy] = float4(sin(groupID.x), cos(groupID.y), cos(groupID.y + groupID.x), 1.0f);
    //gInputA[dispatchThreadID.xy] + gInputB[dispatchThreadID.xy];
}