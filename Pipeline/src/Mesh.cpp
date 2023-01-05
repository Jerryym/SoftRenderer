#include "Mesh.h"

pipeline::Mesh::Mesh()
{
	vertices.clear();
	indices.clear();
}

pipeline::Mesh::Mesh(const Mesh& RefObj)
	: vertices(RefObj.vertices),
	  indices(RefObj.indices)
{
}

pipeline::Mesh::~Mesh()
{
}

pipeline::Mesh& pipeline::Mesh::operator=(const Mesh& RefObj)
{
	// TODO: 在此处插入 return 语句
	if (this == &RefObj)	return *this;

	vertices = RefObj.vertices;
	indices = RefObj.indices;
	return *this;
}


void pipeline::Mesh::setVertices(Vertex* VO, int Count)
{
	vertices.resize(Count);
	new(&vertices[0])std::vector<Vertex>(VO, VO + Count);
}


void pipeline::Mesh::setIndices(unsigned int* IO, int Count)
{
	indices.resize(Count);
	new(&indices[0])std::vector<unsigned int>(IO, IO + Count);
}

void pipeline::Mesh::triangle(const Math::Vector4D& pos1, const Math::Vector4D& pos2, const Math::Vector4D& pos3)
{
	vertices.resize(3);
	indices.resize(3);

	vertices[0].position = pos1;
	vertices[0].normal = Math::Vector3D(0.0f, 0.0f, 1.0f);
	vertices[0].color = Math::Vector4D(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[0].texcoord = Math::Vector2D(0.0f, 0.0f);

	vertices[1].position = pos2;
	vertices[1].normal = Math::Vector3D(0.0f, 0.0f, 1.0f);
	vertices[1].color = Math::Vector4D(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[1].texcoord = Math::Vector2D(1.0f, 0.0f);

	vertices[2].position = pos3;
	vertices[2].normal = Math::Vector3D(0.0f, 0.0f, 1.0f);
	vertices[2].color = Math::Vector4D(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[2].texcoord = Math::Vector2D(0.5f, 1.0f);

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
}
