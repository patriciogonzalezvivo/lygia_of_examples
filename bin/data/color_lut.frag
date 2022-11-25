#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D   u_tex0;
uniform sampler2D   u_lut;

uniform vec2        u_resolution;
uniform vec2        u_mouse;
uniform float       u_time;

#define LUT_SQUARE
#define LUT_FLIP_Y
#include "lygia/color/lut.glsl"

void main(void) {
    vec4 color = vec4(0.0);
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st.y = 1.0-st.y;
    
    color = texture2D(u_tex0, st);

    color = lut(u_lut, color);

    gl_FragColor = color;
}
