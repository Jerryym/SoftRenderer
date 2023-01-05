#include "Vertex.h"

///////////////////////////////////////////////////////////////////
// Vertex
pipeline::Vertex::Vertex()
{
}

pipeline::Vertex::Vertex(const Math::Vector4D& pos,
	const Math::Vector4D& color,
	const Math::Vector2D& texture,
	const Math::Vector3D& normal)
	: position(pos), color(color), texcoord(texture), normal(normal)
{
}

pipeline::Vertex::Vertex(const Vertex& RefObj)
	: position(RefObj.position), color(RefObj.color), texcoord(RefObj.texcoord), normal(RefObj.normal)
{
}

void pipeline::Vertex::operator=(const Vertex& RefObj)
{
	position = RefObj.position;
	color = RefObj.color;
	texcoord = RefObj.texcoord;
	normal = RefObj.normal;
}

pipeline::Vertex::~Vertex()
{
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// Fragment
pipeline::Fragment::Fragment()
{

}

pipeline::Fragment::Fragment(const Math::Vector4D& PMW,
							 const Math::Vector4D& PVP,
							 const Math::Vector4D& color, 
							 const Math::Vector2D& texture, 
							 const Math::Vector3D& normal, 
							 const double rOneDivZ)
	: posMToW(PMW), posVToP(PVP), color(color), textcoord(texture), normal(normal), oneDivZ(rOneDivZ)
{
}

pipeline::Fragment::Fragment(const Fragment& RefObj)
	: posMToW(RefObj.posMToW), 
	  posVToP(RefObj.posVToP),
	  color(RefObj.color),
	  textcoord(RefObj.textcoord),
	  normal(RefObj.normal),
	  oneDivZ(RefObj.oneDivZ)
{
}

void pipeline::Fragment::operator=(const Fragment& RefObj)
{
	posMToW = RefObj.posMToW;
	posVToP = RefObj.posVToP;
	color = RefObj.color;
	textcoord = RefObj.textcoord;
	normal = RefObj.normal;
	oneDivZ = RefObj.oneDivZ;
}

pipeline::Fragment::~Fragment()
{
}
///////////////////////////////////////////////////////////////////