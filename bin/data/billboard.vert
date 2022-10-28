uniform mat4    modelViewProjectionMatrix;

uniform vec2    u_resolution;

attribute vec4  position;
attribute vec2  texcoord;

varying vec4    v_position;
varying vec2    v_texcoord;

void main() {
    v_position  = position;
    // v_position.xy *= u_resolution;
    v_texcoord  = texcoord;

    gl_Position = v_position;
}