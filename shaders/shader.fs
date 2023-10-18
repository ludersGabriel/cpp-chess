#version 330 core

uniform bool onlyColor;
uniform vec3 color;

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D texture1;

void main() {
    if(onlyColor) {
        FragColor = vec4(color, 1.0);
        return;
    }

    FragColor = texture(texture1, TexCoord);
}