#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2    u_resolution;
uniform vec2    u_mouse;
uniform float   u_time;

#include "lygia/space/fisheye2xyz.glsl"
#include "lygia/lighting/atmosphere.glsl"

#ifndef TONEMAP_FNC
#define TONEMAP_FNC tonemapLinear
// #define TONEMAP_FNC tonemapDebug
// #define TONEMAP_FNC tonemapAces
// #define TONEMAP_FNC tonemapFilmic
// #define TONEMAP_FNC tonemapReinhard
// #define TONEMAP_FNC tonemapReinhardJodie
// #define TONEMAP_FNC tonemapUncharted
// #define TONEMAP_FNC tonemapUncharted2
// #define TONEMAP_FNC tonemapUnreal
#endif
#include "lygia/color/tonemap.glsl"


void main(void) {
    vec3 color = vec3(0.0);
    vec2 pixel = 1.0/u_resolution.xy;
    vec2 st = gl_FragCoord.xy * pixel;

    vec2 mouse = u_mouse * pixel;
    mouse.y = 1.0-mouse.y;

    if (mouse.x <= 0.0 || mouse.y <= 0.0 || mouse.x >= 1.0 || mouse.y >= 1.0)
        mouse = vec2(fract(0.5+u_time*0.5), 0.6);
        
    vec3 eye_dir = fisheye2xyz(st);
    vec3 sun_dir = fisheye2xyz(mouse);

    color = atmosphere(eye_dir, sun_dir);

    color = tonemap(color);

    gl_FragColor = vec4(color, 1.0);
}
