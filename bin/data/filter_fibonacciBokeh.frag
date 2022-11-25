#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2        u_resolution;
uniform float       u_time;

uniform sampler2D   u_tex0;
uniform vec2        u_tex0Resolution;

#include "lygia/filter/fibonacciBokeh.glsl"

#include "lygia/draw/digits.glsl"

void main (void) {
    vec3 color = vec3(0.0);
    vec2 pixel = 1.0/u_resolution;
    vec2 st = gl_FragCoord.xy * pixel;
    vec2 uv = st;
    st.y = 1.0 - st.y;

    float ix = floor(st.x * 5.0);
    float radius = (ix/4.0) * 0.5;
    color += fibonacciBokeh(u_tex0, st, pixel, radius).rgb;

    color -= digits(uv - vec2(ix/5.0 + 0.01, 0.01), radius, 2.);
    color -= step(.99, fract(uv.x * 5.0));

    gl_FragColor = vec4(color,1.0);
}
