//
//  Circle.h
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//  Просто неподвижный круг (использовался для тестирования, остался базовым)
//------------------------------------------------------------------------------
#ifndef Circles_Circle_h
#define Circles_Circle_h
//------------------------------------------------------------------------------
#include "GameObject.h"
#include "DataTypes.h"
//------------------------------------------------------------------------------
class Circle : public GameObject
{
public:
  Circle(GLfloat radius, GLfloat centerX, GLfloat centerY, ColorEnum color = COLOR_WHITE);
  ~Circle() {}
  
  virtual void Update(double timeSinceLastUpdate);
  virtual void Render();
  virtual bool IsPointInside(GLfloat x, GLfloat y);
  virtual int Score() { return 0; }
  
protected:
	void UpdateVertices();
  
  GLfloat radius_;
  GLfloat centerX_;
  GLfloat centerY_;
};
//------------------------------------------------------------------------------
#endif
