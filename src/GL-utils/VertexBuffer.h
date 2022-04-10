#include <glad/glad.h>

class VertexBuffer
{
	//Store the id of the vertex buffer here
	unsigned int bufferId;

	float* begin; //Store the pointer to the beginning of the buffer here
	int bufferSize, vertSize; //Store the size of the vertex buffer and the size of a vertex here
public:
	int VertexCount(); //Returns the number of vertices in the buffer

	void Bind(); //Bind the vertex

	//Constructor
	VertexBuffer(float* bufferBegin, int sz, int vertexSize, bool bind);

	//Default constructor
	VertexBuffer();
};