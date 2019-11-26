#include "Texture.h"

#include "stb_image.h"
namespace BCE
{
	namespace Graphics
	{

		Texture::Texture()
		{
			textureID = 0;
			width = 0;
			height = 0;
			bitDepth = 0;
			fileLocation = "";
		}

		Texture::Texture(std::string fileLoc)
		{
			textureID = 0;
			width = 0;
			height = 0;
			bitDepth = 0;
			fileLocation = fileLoc;
		}

		bool Texture::LoadTexture()
		{
			unsigned char* texData = stbi_load(fileLocation.c_str(), &width, &height, &bitDepth, 0);
			if (!texData)
			{
				printf("Failed to find: %s\n", fileLocation.c_str());
				return false;
			}

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
			glGenerateMipmap(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, 0);

			stbi_image_free(texData);
			return true;
		}

		bool Texture::LoadTextureA()
		{
			unsigned char* texData = stbi_load(fileLocation.c_str(), &width, &height, &bitDepth, 0);
			if (!texData)
			{
				printf("Failed to find: %s\n", fileLocation.c_str());
				return false;
			}

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
			glGenerateMipmap(GL_TEXTURE_2D);


			stbi_image_free(texData);
			return true;
		}

		void Texture::UseTexture(unsigned int i)
		{
			glActiveTexture(i);
			glBindTexture(GL_TEXTURE_2D, textureID);
		}

		void Texture::ClearTexture()
		{
			glDeleteTextures(1, &textureID);
			textureID = 0;
			width = 0;
			height = 0;
			bitDepth = 0;
			fileLocation = "";
		}


		Texture::~Texture()
		{
			ClearTexture();
		}
	}
}