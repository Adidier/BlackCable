#include "Mesh.h"
namespace BCE
{
	namespace Graphics
	{
		Mesh::Mesh()
		{
			VAO = 0;
			VBO = 0;
			IBO = 0;
			indexCount = 0;
		}

		void Mesh::CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices, unsigned int vSize)
		{
			indexCount = numOfIndices;

			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			glGenBuffers(1, &IBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numOfIndices, indices, GL_STATIC_DRAW);

			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * vSize, 0);
			glEnableVertexAttribArray(0);
			if (vSize > 3) {
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * vSize, (void*)(sizeof(vertices[0]) * 3));
				glEnableVertexAttribArray(1);
			}
			if (vSize > 5) {
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * vSize, (void*)(sizeof(vertices[0]) * 5));
				glEnableVertexAttribArray(2);
			}
			if (vSize > 8) {
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * vSize, (void*)(sizeof(vertices[0]) * 8));
				glEnableVertexAttribArray(3);
			}

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			glBindVertexArray(0);
		}

		void Mesh::RenderMesh()
		{
			glBindVertexArray(VAO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
			glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}

		void Mesh::ClearMesh()
		{
			if (IBO != 0)
			{
				glDeleteBuffers(1, &IBO);
				IBO = 0;
			}

			if (VBO != 0)
			{
				glDeleteBuffers(1, &VBO);
				VBO = 0;
			}

			if (VAO != 0)
			{
				glDeleteVertexArrays(1, &VAO);
				VAO = 0;
			}

			indexCount = 0;
		}


		Mesh::~Mesh()
		{
			ClearMesh();
		}
	}
}