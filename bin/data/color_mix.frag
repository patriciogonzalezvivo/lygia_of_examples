
#version 120
#ifdef GL_ES
precision mediump float;
#endif

uniform vec2        u_resolution;
uniform vec2        u_mouse;
uniform float       u_time;

#include "lygia/math/saturate.glsl"
#include "lygia/color/mixOklab.glsl"

void main(void) {
    vec3 color = vec3(0.0);
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    
    vec3 A = vec3(0.9333, 0.9451, 0.0588);
    vec3 B = vec3(0.0824, 0.1686, 0.5529);
    float pct = st.x;

    if (st.y > 0.5) 
        color = mix(A, B, pct);
    else
        color = mixOklab(A, B, pct);

    gl_FragColor = vec4(color, 1.0);
}
