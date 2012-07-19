//
//  Circle.cpp
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#include "Circle.h"
//------------------------------------------------------------------------------
#ifndef DEGREES_TO_RADIANS
#define DEGREES_TO_RADIANS(x) (3.14159265358979323846 * x / 180.0)
#endif
//------------------------------------------------------------------------------
Circle::Circle(GLfloat radius, GLfloat centerX, GLfloat centerY, ColorEnum color) :
	GameObject(color), radius_(radius), centerX_(centerX), centerY_(centerY)
{
  UpdateVertices();
}
//------------------------------------------------------------------------------
void Circle::UpdateVertices()
{
	vertices_.clear();
	for (int i = 0; i < 360; ++i)
  {
    // x value
    vertices_.push_back(centerX_ + cos(DEGREES_TO_RADIANS(i)) * radius_);
    // y value
    vertices_.push_back(centerY_ + sin(DEGREES_TO_RADIANS(i)) * radius_);
  }
}
//------------------------------------------------------------------------------
void Circle::Update(double timeSinceLastUpdate)
{
	// у неподвижного круга нечего менять
}
//------------------------------------------------------------------------------
void Circle::Render()
{
	if (!vertices_.size())
  	return;
 
  GLKBaseEffect *effect = [[GLKBaseEffect alloc] init];
  effect.useConstantColor = YES;
  effect.constantColor = solidColor_;
  effect.transform.projectionMatrix = GLKMatrix4MakeOrtho(0, 320, 0, 460, 1, -1);
  //GLKMatrix4MakeOrtho(-2, 2, -3, 3, 1, -1);
  [effect prepareToDraw];

	glEnableVertexAttribArray(GLKVertexAttribPosition);
  glVertexAttribPointer(GLKVertexAttribPosition, 2, GL_FLOAT, GL_FALSE, 0, &vertices_[0]);
  glDrawArrays(GL_TRIANGLE_FAN, 0, vertices_.size()/2);
  glDisableVertexAttribArray(GLKVertexAttribPosition);
}
//------------------------------------------------------------------------------
bool Circle::IsPointInside(GLfloat x, GLfloat y)
{
	// сравнение радиуса и расстояния между центром круга и точкой
  GLfloat xDistanceFromCenter = x - centerX_;
  GLfloat yDistanceFromCenter = y - centerY_;
  GLfloat distanceFromCenter = sqrtf(xDistanceFromCenter*xDistanceFromCenter +
  	yDistanceFromCenter*yDistanceFromCenter);
    
  return (distanceFromCenter <= radius_);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------