//
//  TextBar.cpp
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#include "TextBar.h"
#import <QuartzCore/QuartzCore.h>
//------------------------------------------------------------------------------
TextBar::TextBar()
{
	// правый нижний угол:
	vertices_.push_back(320.f);
  vertices_.push_back(430.f);
  // правый верхний угол:
  vertices_.push_back(320.f);
  vertices_.push_back(460.f);
  // левый верхний угол:
  vertices_.push_back(0.f);
  vertices_.push_back(460.f);
  // левый нижний угол:
  vertices_.push_back(0.f);
  vertices_.push_back(430.f);

  textureVertices_.push_back(1.f);
  textureVertices_.push_back(0.f);
  textureVertices_.push_back(1.f);
  textureVertices_.push_back(1.f);
  textureVertices_.push_back(0.f);
  textureVertices_.push_back(1.f);
  textureVertices_.push_back(0.f);
  textureVertices_.push_back(0.f);
  
  textureInfo_ = nil;
}
//------------------------------------------------------------------------------
void TextBar::SetText(const char *utf8Text)
{
	if (textureInfo_ != nil)
  {
  	GLuint name = textureInfo_.name;
    glDeleteTextures(1, &name);  	
  }

	UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0.f, 0.f, 320.f, 30.f)];
  label.font = [UIFont systemFontOfSize:17.f];
  label.textColor = [UIColor blackColor];
  label.textAlignment = UITextAlignmentCenter;
  label.text = [NSString stringWithUTF8String:utf8Text];
  UIGraphicsBeginImageContext(label.frame.size);
  [label.layer renderInContext:UIGraphicsGetCurrentContext()];
  UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
  UIGraphicsEndImageContext();
    
  NSError *error;
  textureInfo_ = [GLKTextureLoader textureWithCGImage:image.CGImage
  	options:[NSDictionary dictionaryWithObject:[NSNumber numberWithBool:YES]
    forKey:GLKTextureLoaderOriginBottomLeft]
    error:&error];
  if (error)
  {
    NSLog(@"Error loading texture from image: %@",error);
    return;
  }
  
  NSLog(@"Texture loaded successfully: name = %d size = (%d x %d)",
    textureInfo_.name, textureInfo_.width, textureInfo_.height);
}
//------------------------------------------------------------------------------
void TextBar::Render()
{
	/*UIImage *image = [UIImage imageNamed:@"testTexture.png"];
    
  NSError *error;
  textureInfo_ = [GLKTextureLoader textureWithCGImage:image.CGImage
  	options://nil
    [NSDictionary dictionaryWithObject:[NSNumber numberWithBool:YES] forKey:GLKTextureLoaderOriginBottomLeft]    
    error:&error];
  if (error)
  {
    NSLog(@"Error loading texture from image: %@",error);
    return;
  }
  
  NSLog(@"Texture loaded successfully: name = %d size = (%d x %d)",
    textureInfo_.name, textureInfo_.width, textureInfo_.height);*/

  GLKBaseEffect *effect = [[GLKBaseEffect alloc] init];
  //effect.useConstantColor = YES;
  //effect.constantColor = GLKVector4Make(.67f, .67f, .67f, 1.f);  
  if (textureInfo_ != nil) 
  {
    effect.texture2d0.enabled = GL_TRUE;
    effect.texture2d0.envMode = GLKTextureEnvModeReplace;
    effect.texture2d0.target = GLKTextureTarget2D;
    effect.texture2d0.name = textureInfo_.name;
  }
  
  // Set up the projection matrix to fit the scene's boundaries
  effect.transform.projectionMatrix = GLKMatrix4MakeOrtho(0, 320, 0, 460, 1, -1);
  
  // Tell OpenGL that we're going to use this effect for our upcoming drawing
  [effect prepareToDraw];
  
  // Enable transparency
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  // Tell OpenGL that we'll be using vertex position data
  glEnableVertexAttribArray(GLKVertexAttribPosition);
  glVertexAttribPointer(GLKVertexAttribPosition, 2, GL_FLOAT, GL_FALSE, 0, &vertices_[0]);
  
  // If we have a texture, tell OpenGL that we'll be using texture coordinate data
  if (textureInfo_ != nil)
  {
    glEnableVertexAttribArray(GLKVertexAttribTexCoord0);
    glVertexAttribPointer(GLKVertexAttribTexCoord0, 2, GL_FLOAT, GL_FALSE, 0, &textureVertices_[0]);
  }

  // Draw our primitives!
  glDrawArrays(GL_TRIANGLE_FAN, 0, vertices_.size()/2);

  // Cleanup: Done with position data
  glDisableVertexAttribArray(GLKVertexAttribPosition);

  // Cleanup: Done with texture data (only if we used it)
  if (textureInfo_ != nil)
    glDisableVertexAttribArray(GLKVertexAttribTexCoord0);
  
  // Cleanup: Done with the current blend function
  glDisable(GL_BLEND);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
