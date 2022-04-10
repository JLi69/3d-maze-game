#include "VertexBuffer.h"

int VertexBuffer::VertexCount()
{
	return bufferSize / vertSize;
}

void VertexBuffer::Bind()
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, begin, GL_STATIC_DRAW);
	glVertexAttribPointer(0, vertSize, GL_FLOAT, false, vertSize * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

VertexBuffer::VertexBuffer(float* bufferBegin, int sz, int vertexSize, bool bind)
{
	begin = bufferBegin;
	bufferSize = sz;
	vertSize = vertexSize;

	//Bind the buffer if told to
	if(bind) Bind();
}

VertexBuffer::VertexBuffer()
{
	begin = nullptr;
	bufferSize = 0;
	vertSize = 0;
}