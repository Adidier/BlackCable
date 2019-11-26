#version 330
out vec4 colour;

in vec4 vCol;
in vec2 TexCoord;

uniform sampler2D tex;

void main()
{
	colour =  texture(tex, TexCoord) * vCol;
}
