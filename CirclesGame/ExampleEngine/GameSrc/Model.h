//
//  Model.h
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
// 
//  Класс, хранящий все игровые объекты и данные для вывода на экран очков
//  и обеспечивающий взаимодействие между ними.
//  В случае возрастания сложности игры придётся применить декомпозицию 
//
//------------------------------------------------------------------------------
#ifndef Circles_Model_h
#define Circles_Model_h
//------------------------------------------------------------------------------
#include <list>
//------------------------------------------------------------------------------
class GameObject;
class TextBar;
//------------------------------------------------------------------------------
class Model
{
public:
	Model();
  ~Model();
  
  void TearDownGL();
  
  // обновление перед каждым кадром:
  void Update(double timeSinceLastUpdate);
  // вызываем Render() каждого объекта на экране:
  void Render();
  
  void TouchesBegan(GLfloat x, GLfloat y);
  
private:
	std::list<GameObject*> gameObjects_;
  TextBar *textBar_;
  bool shouldUpdateTextBar_;
  
  // случайный период между стартами кругов (и их рождениями):
  NSTimeInterval periodBetweenStarts_;  
  // сколько времени прошло после старта последнего круга:
  NSTimeInterval timeSinceLastStart_;

	void AddRandCircle();
  
  int totalScore_, maxPossibleTotalScore_;
};
//------------------------------------------------------------------------------
#endif
