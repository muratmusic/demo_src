//
//  GameObject.cpp
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#include "GameObject.h"
//------------------------------------------------------------------------------
GameObject::GameObject(ColorEnum color)
{
	switch (color)
  {
  case COLOR_RED:
  	solidColor_ = GLKVector4Make(1.f, 0.f, 0.f, 1.f);
    break;
  case COLOR_GREEN:
  	solidColor_ = GLKVector4Make(0.f, 1.f, 0.f, 1.f);
    break;
  case COLOR_BLUE:
  	solidColor_ = GLKVector4Make(0.f, 0.f, 1.f, 1.f);
    break;
  case COLOR_YELLOW:
  	solidColor_ = GLKVector4Make(1.f, 1.f, 0.f, 1.f);
    break;
  case COLOR_BROWN:
  	solidColor_ = GLKVector4Make(169.f/255.f, 82.f/255.f, 45.f/255.f, 1.f);
    break;
  case COLOR_VIOLET:
  	solidColor_ = GLKVector4Make(238.f/255.f, 130.f/255.f, 238.f/255.f, 1.f);
    break;
  case COLOR_GRAY:
  	solidColor_ = GLKVector4Make(.67f, .67f, .67f, 1.f);
  	break;
  case COLOR_WHITE:
  default:
  	solidColor_ = GLKVector4Make(1.f, 1.f, 1.f, 1.f);  
    break;
  }
}
//------------------------------------------------------------------------------
bool GameObject::IsOutOfScreen()
{
	for (int i=0; i<vertices_.size(); i += 2)
  {
  	if (vertices_[i+1] > 0)
    	return false;
  }
  
  return true;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------