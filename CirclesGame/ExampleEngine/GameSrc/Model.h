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
  
  // обновление перед каждым кадром:
  void Update(double timeSinceLastUpdate);
  // вызываем в каждом кадре:
  void Render();
	// вызываем при прикосновениях к экрану:
  void TouchesBegan(GLfloat x, GLfloat y);
  
private:
	std::list<GameObject*> gameObjects_;
  TextBar *textBar_;
  bool shouldUpdateTextBar_;
  
  // случайный период между стартом запущенного круга
  // и стартом следущего запускаемого круга:
  NSTimeInterval periodBetweenStarts_;  
  // сколько времени прошло после старта последнего запущенного круга:
  NSTimeInterval timeSinceLastStart_;

	void AddRandCircle(); // запустить очередной круг
  
  // заработанные и максимально возможные очки
  int totalScore_, maxPossibleTotalScore_;
};
//------------------------------------------------------------------------------
#endif
