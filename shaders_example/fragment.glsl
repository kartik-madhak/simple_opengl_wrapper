#version 430 core
out vec4 FragColor;
in vec3 pColor;

void main() {
    FragColor = vec4(pColor.xyz, 1.0f);
}