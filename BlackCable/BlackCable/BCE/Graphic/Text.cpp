#include "Text.h"

namespace BCE
{
	namespace Graphics
	{

		Text::Text()
		{
			// Shader Setup
			shaderManager = ShaderManager::getPtr();
			shaderManager->LoadShaders("Text", "Assets/Shaders/Default/Text-Shader.vert", "Assets/Shaders/Default/Text-Shader.frag");
		}

		Text::~Text()
		{

		}

		void Text::LoadFont(string path)
		{
			if (FT_Init_FreeType(&_library))
				std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

			if (FT_New_Face(_library, "Assets/Fonts/arial.ttf", 0, &_face))
				std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

			FT_Set_Pixel_Sizes(_face, 0, 48);

			if (FT_Load_Char(_face, 'X', FT_LOAD_RENDER))
				std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;

			glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction

			for (GLubyte c = 0; c < 128; c++)
			{
				// Load character glyph 
				if (FT_Load_Char(_face, c, FT_LOAD_RENDER))
				{
					std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
					continue;
				}
				// Generate texture
				GLuint texture;
				glGenTextures(1, &texture);
				glBindTexture(GL_TEXTURE_2D, texture);
				glTexImage2D(GL_TEXTURE_2D,0,GL_RED,_face->glyph->bitmap.width,_face->glyph->bitmap.rows,0,GL_RED,GL_UNSIGNED_BYTE,_face->glyph->bitmap.buffer);
				// Set texture options
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				// Now store character for later use
				Character character = { texture, glm::ivec2(_face->glyph->bitmap.width, _face->glyph->bitmap.rows), glm::ivec2(_face->glyph->bitmap_left, _face->glyph->bitmap_top),_face->glyph->advance.x };
				Characters.insert(std::pair<GLchar, Character>(c, character));
			}

			FT_Done_Face(_face);
			FT_Done_FreeType(_library);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}

		void Text::RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color)
		{
			// Activate corresponding render state	
			shaderManager->Activate("text");
			shaderManager->draw();
			//glUniform3f(glGetUniformLocation(s.Program, "textColor"), color.x, color.y, color.z);
			glActiveTexture(GL_TEXTURE0);
			glBindVertexArray(VAO);

			// Iterate through all characters
			std::string::const_iterator c;
			for (c = text.begin(); c != text.end(); c++)
			{
				Character ch = Characters[*c];

				GLfloat xpos = x + ch.Bearing.x * scale;
				GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

				GLfloat w = ch.Size.x * scale;
				GLfloat h = ch.Size.y * scale;
				// Update VBO for each character
				GLfloat vertices[6][4] = {
					{ xpos,     ypos + h,   0.0, 0.0 },
					{ xpos,     ypos,       0.0, 1.0 },
					{ xpos + w, ypos,       1.0, 1.0 },

					{ xpos,     ypos + h,   0.0, 0.0 },
					{ xpos + w, ypos,       1.0, 1.0 },
					{ xpos + w, ypos + h,   1.0, 0.0 }
				};
				// Render glyph texture over quad
				glBindTexture(GL_TEXTURE_2D, ch._TextureID);
				// Update content of VBO memory
				glBindBuffer(GL_ARRAY_BUFFER, VBO);
				glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
				glBindBuffer(GL_ARRAY_BUFFER, 0);
				// Render quad
				glDrawArrays(GL_TRIANGLES, 0, 6);
				// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
				x += (ch.Advance >> 6)* scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
			}
			glBindVertexArray(0);
			glBindTexture(GL_TEXTURE_2D, 0);


			glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
			
			glDepthMask(GL_FALSE);
			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(projection));
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
			skyMesh->RenderMesh();
			glDepthMask(GL_TRUE);
		}

	}
}