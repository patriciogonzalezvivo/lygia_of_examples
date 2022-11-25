#version 120

#ifdef GL_ES
precision mediump float;
#endif

varying vec2 v_texcoord;
varying vec4 v_position;

void main() {
   // get the texture coordinates
    v_texcoord = gl_MultiTexCoord0.xy;

    // get the position of the vertex relative to the modelViewProjectionMatrix
    v_position = ftransform();
    		
    // this is the resulting vertex position
	gl_Position = v_position;
}
