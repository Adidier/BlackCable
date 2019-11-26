#ifndef MODEL_H
#define MODEL_H
#include "Mesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"
#include<vector>
#include "../Base/Transform.h"
namespace BCE
{
	namespace Graphics
	{
		using namespace BCE::Base;

		class BaseModel
		{
		public:
			BaseModel();
			virtual void Init() = 0;
			virtual void Draw() = 0;
			void SetTransform(Transform* transform);
		protected:
			virtual void LoadMesh() = 0;
			std::vector<Mesh*> meshList;
			Transform *transform;

			void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
				unsigned int vLength, unsigned int normalOffset)
			{
				for (size_t i = 0; i < indiceCount; i += 3)
				{
					unsigned int in0 = indices[i] * vLength;
					unsigned int in1 = indices[i + 1] * vLength;
					unsigned int in2 = indices[i + 2] * vLength;
					glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
					glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
					glm::vec3 normal = glm::cross(v1, v2);
					normal = glm::normalize(normal);

					in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
					vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
					vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
					vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
				}

				for (size_t i = 0; i < verticeCount / vLength; i++)
				{
					unsigned int nOffset = i * vLength + normalOffset;
					glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
					vec = glm::normalize(vec);
					vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
				}
			}
		};
	}
}
#endif