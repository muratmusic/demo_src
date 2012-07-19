//
//  DataTypes.h
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//  Общие простые типы данных (структуры)
//  пока сюда же помещаем и макроопределения
//
//------------------------------------------------------------------------------
#ifndef Circles_DataTypes_h
#define Circles_DataTypes_h

#define DEGREES_TO_RADIANS(x) (3.14159265358979323846 * x / 180.0)
//------------------------------------------------------------------------------
#import <GLKit/GLKit.h>
//------------------------------------------------------------------------------
enum ColorEnum
{
	COLOR_RED,
  COLOR_GREEN,
  COLOR_BLUE,
  COLOR_YELLOW,
  COLOR_BROWN,
  COLOR_VIOLET,
  COLOR_GRAY,
  COLOR_WHITE,
  COLORS_COUNT
};
//------------------------------------------------------------------------------
#endif
