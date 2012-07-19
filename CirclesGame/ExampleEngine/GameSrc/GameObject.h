//
//  GameObject.h
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//  Абстрактный класс любого игрового объекта, отображаемого на экране
//
//------------------------------------------------------------------------------
#ifndef Circles_GameObject_h
#define Circles_GameObject_h
//------------------------------------------------------------------------------
#include <vector>
#include "DataTypes.h"
#ifdef __IPHONE_NA
#import <GLKit/GLKit.h>
#else
#error Add your platform OpenGL headers
#endif
//------------------------------------------------------------------------------
class GameObject
{
public:
	GameObject(ColorEnum color);
  ~GameObject() {}  
  
  virtual void Update(double timeSinceLastUpdate) = 0;
  virtual void Render() = 0;
  virtual bool IsPointInside(GLfloat x, GLfloat y) = 0;
  virtual int Score() = 0;  
  
  // true если все вершины вышли за границы экрана (по Y):
  bool IsOutOfScreen(); 
protected:
	std::vector<GLfloat> vertices_;
  GLKVector4 solidColor_;
};
//------------------------------------------------------------------------------
#endif
