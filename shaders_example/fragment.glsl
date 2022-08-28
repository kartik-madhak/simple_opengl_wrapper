#version 430 core
out vec4 FragColor;
in vec3 pColor;
in vec2 pTexCoord;

uniform vec4 uColor;
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main() {
    FragColor = mix(texture(ourTexture1, pTexCoord), texture(ourTexture2, pTexCoord), 0.4);
}