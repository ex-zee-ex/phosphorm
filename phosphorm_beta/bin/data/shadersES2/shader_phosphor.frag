precision highp float;


uniform sampler2D tex0;


varying vec2 texCoordVarying;


uniform float test;

void main()
{
	float x=.0016;
	float y=.0022;
	
	vec4 color=texture2D(tex0, texCoordVarying)
				+texture2D(tex0, texCoordVarying+vec2(x,y))
				+texture2D(tex0, texCoordVarying+vec2(x,-y))
				+texture2D(tex0, texCoordVarying+vec2(-x,y))
				+texture2D(tex0, texCoordVarying+vec2(-x,-y));
	color.rgb=color.rgb*.18;
	
	if(color.r<.01){color=vec4(0.0);}
	
	gl_FragColor = color;
}
