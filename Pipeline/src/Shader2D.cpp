#include "Shader2D.h"

pipeline::Shader2D::Shader2D()
{
}

pipeline::Shader2D::~Shader2D()
{
}

pipeline::Fragment pipeline::Shader2D::vertexShader(const Vertex& vertexObj)
{
    Fragment fragment;

    fragment.posMToW = vertexObj.position;
    fragment.posVToP = vertexObj.position;
    fragment.color = vertexObj.color;
    fragment.textcoord = vertexObj.texcoord;
    fragment.normal = vertexObj.normal;
    fragment.oneDivZ = 1.0;

    return fragment;
    
}

Math::Vector4D pipeline::Shader2D::fragmentShader(const Fragment& fragmentObj)
{
    Math::Vector4D resultColor(fragmentObj.color);

    return resultColor;
}
