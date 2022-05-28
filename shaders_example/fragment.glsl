#version 430 core
out vec4 FragColor;
in vec3 pColor;

uniform vec4 uColor;

void main() {
    FragColor = uColor + vec4(pColor.xyz, 1.0f);
}