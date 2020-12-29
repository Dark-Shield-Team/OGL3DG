#version 450 core
//dont fogot delete posbuild shader path

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

uniform mat4 matVP;

out vec2 fragTextureCoord;
out vec3 fragNormal;
out vec3 fragPos;



void main()
{
    gl_Position = matVP * vec4(VertexPosition, 1.0f);
    fragPos = VertexPosition;
    fragTextureCoord = texCoord;
    fragNormal = normalize(normal); // if was scaled
}