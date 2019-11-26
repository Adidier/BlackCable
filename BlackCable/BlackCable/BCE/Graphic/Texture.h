
#ifndef  TEXTURE_H
#define  TEXTURE_H


#define STB_IMAGE_IMPLEMENTATION
#include <GL\glew.h>
#include <string>

namespace BCE
{
	namespace Graphics
	{

		class Texture
		{
		public:
			Texture();
			Texture(std::string fileLoc);
			bool LoadTexture();
			bool LoadTextureA();
			void UseTexture(unsigned int i = 0);
			void ClearTexture();
			~Texture();
		private:
			GLuint textureID;
			int width, height, bitDepth;
			std::string fileLocation;
		};

	}
}

#endif // ! TEXTURE_H