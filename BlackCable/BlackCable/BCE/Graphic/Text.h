#pragma once
#include <ft2build.h>
#include FT_FREETYPE_H  
#include "Shader.h"
#include "../Base/ShaderManager.h"
#include "Mesh.h"
#include <string>

//Tutorial https://learnopengl.com/In-Practice/Text-Rendering

using namespace BCE::Base;
using std::string;

namespace BCE
{
	namespace Graphics
	{

		struct Character {
			GLuint     _TextureID;  // ID handle of the glyph texture
			glm::ivec2 Size;       // Size of glyph
			glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
			GLuint     Advance;    // Offset to advance to next glyph
		};

		class Text
		{
		public:
			Text();
			~Text();
			void LoadFont(string path);
			void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
		private:
			string Message;
			Mesh* skyMesh;
			GLuint textureId;
			GLuint uniformProjection;
			GLuint uniformView;
			ShaderManager* shaderManager;
			FT_Library  _library;   /* handle to library     */
			FT_Face     _face;      /* handle to face object */
			GLuint VAO, VBO;
			std::map<GLchar, Character> Characters;
		};
	}
}