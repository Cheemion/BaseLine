   struct PSIn                                                                 
   {                                                                          
     float2 tex : TEXCOORD;                                                    
     float  lod : LOD;                                                        
    };                                                                         
                                                                               
   struct PSOut                                                                
    {                                                                          
     float4 color : SV_Target;                                                
    };                                                                         
                                                                              
    sampler    theSampler;                                                    
    texture2D  theTexture;                                                    
                                                                               
    PSOut main( in PSIn input )                                                
    {                                                                         
     PSOut output;                                                            
     output.color = theTexture.SampleLevel(theSampler, input.tex, input.lod);  
     return output;                                                           
    }                                                                          
        
