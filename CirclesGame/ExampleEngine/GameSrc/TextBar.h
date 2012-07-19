//
//  TextBar.h
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#ifndef ExampleEngine_ResultsBar_h
#define ExampleEngine_ResultsBar_h
//------------------------------------------------------------------------------
#import <GLKit/GLKit.h>
#include <vector>
//------------------------------------------------------------------------------
class TextBar
{
public:
  TextBar();
  ~TextBar() {}
  
  void SetText(const char *utf8Text);
  void Render();
  
private:
	GLuint textureID_;
  GLKTextureInfo *textureInfo_;
  std::vector<GLfloat> vertices_;
  std::vector<GLfloat> textureVertices_;
};
//------------------------------------------------------------------------------
#endif
