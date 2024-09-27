struct PSIn                                                                 
{                                                                          
    float2 tex : TEXCOORD;                                                    
    float  lod : LOD;      
    float4 pos : SV_Position;
};                                                                         

struct PSOut                                                                
{                                                                          
    float4 color : SV_Target;                                                
};                                                                         
                                                                              
sampler sampler1 : register(s0);

Texture2D<float4> srvC : register(t0);
                                                                               
PSOut main( in PSIn input )                                                
{                                                                         
    PSOut output;                                                            
    output.color = float4(input.pos.xyz, 1.0f);
    //srvC.Sample(sampler1, input.pos.xy);
    return output;                                                           
}                                                                          
        
