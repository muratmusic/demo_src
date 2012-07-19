//
//  MovingCircle.cpp
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#include "MovingCircle.h"
//------------------------------------------------------------------------------
MovingCircle::MovingCircle(GLfloat radius, GLfloat centerX, GLfloat centerY,
ColorEnum color, GLfloat velY) :
	Circle(radius, centerX, centerY, color),
  velY_(velY)
{
}
//------------------------------------------------------------------------------
void MovingCircle::Update(double timeSinceLastUpdate)
{
	centerY_ -= velY_*timeSinceLastUpdate;
  UpdateVertices();
}
//------------------------------------------------------------------------------
void MovingCircle::Render()
{
	Circle::Render();
}
//------------------------------------------------------------------------------