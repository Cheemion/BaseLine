    struct VSIn                            
    {                                      
     float2 tex : TEXCOORD;                
     float  lod : LOD;                     
     float3 pos : POSITION;                
    };                                     
                                           
    struct VSOut                           
    {                                      
     float2 tex : TEXCOORD;                
     float  lod : LOD;                     
     float4 pos : SV_Position;             
    };                                     
                                           
    VSOut main( in VSIn input )            
    {                                      
     VSOut output;                         
	 output.pos = float4(input.pos, 1.0);     
     output.tex = input.tex;               
     output.lod = input.lod;               
     return output;                        
    }                                      
                                           