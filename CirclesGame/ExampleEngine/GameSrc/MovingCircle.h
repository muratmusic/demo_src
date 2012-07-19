//
//  MovingCircle.h
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//  Класс движущегося круга
//
//------------------------------------------------------------------------------
#ifndef Circles_MovingCircle_h
#define Circles_MovingCircle_h
//------------------------------------------------------------------------------
#include "Circle.h"
#include "DataTypes.h"
//------------------------------------------------------------------------------
class MovingCircle : public Circle
{
public:
  MovingCircle(GLfloat radius, GLfloat centerX, GLfloat centerY,
  	ColorEnum color, GLfloat velY);
  ~MovingCircle() {}
  
  virtual void Update(double timeSinceLastUpdate);
  virtual void Render();
  virtual int Score() { return (int)velY_; }
  
private:
	GLfloat velY_; // y-скорость
};
//------------------------------------------------------------------------------
#endif
