//
//  Model.cpp
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#include "Model.h"
#include "DataTypes.h"
#include "MovingCircle.h"
#include "TextBar.h"
#import <GLKit/GLKit.h>
//------------------------------------------------------------------------------
#ifndef BUFFER_OFFSET
#define BUFFER_OFFSET(i) ((char *)NULL + (i))
#endif
//------------------------------------------------------------------------------
Model::Model() : timeSinceLastStart_(0.0), totalScore_(0),
	maxPossibleTotalScore_(0), shouldUpdateTextBar_(false)
{
  srand (time(NULL)); // initialize random seed
	AddRandCircle();
  textBar_ = new TextBar();
}
//------------------------------------------------------------------------------
Model::~Model()
{
	for (std::list<GameObject*>::iterator iter = gameObjects_.begin();
  	iter != gameObjects_.end(); ++iter)
  {
  	delete *iter;
  }
  
  delete textBar_;
}
//------------------------------------------------------------------------------
void Model::AddRandCircle()
{
	timeSinceLastStart_ = 0.0;
	// from 0.3 sec to 1.3 sec
  periodBetweenStarts_ = (double)(rand() % 1000)/1000.0 + 0.3;
  // from 10.f to 60.f
  GLfloat radius = (GLfloat)(rand() % 50) + 10.f;
  // границы в зависимости от радиуса
  GLfloat centerX = radius + rand()%(320 - (int)(2*radius));
  // скорость (поинтов в секунду) обратно радиусу
  GLfloat velY = 500.f - radius*5.f;
  
  MovingCircle *circle = new MovingCircle(radius, centerX, 460.f + radius/2.f,
  	(ColorEnum)(rand()%COLORS_COUNT), velY);
  gameObjects_.push_back(circle);
  maxPossibleTotalScore_ += circle->Score();
  shouldUpdateTextBar_ = true;
}
//------------------------------------------------------------------------------
void Model::Update(double timeSinceLastUpdate)
{
	timeSinceLastStart_ += timeSinceLastUpdate;
  if (timeSinceLastStart_ >= periodBetweenStarts_)
  	AddRandCircle();

	for (std::list<GameObject*>::iterator iter = gameObjects_.begin();
  	iter != gameObjects_.end(); ++iter)
  {
  	if (*iter == gameObjects_.front())
    {
    	if ((*iter)->IsOutOfScreen())
      {
      	delete *iter;
      	gameObjects_.pop_front();
        break;
      }
    }
        
  	(*iter)->Update(timeSinceLastUpdate);
  }
  
  if (shouldUpdateTextBar_)
  {
  	NSString *scoreText =
    	[NSString stringWithFormat:@"%d / %d", totalScore_, maxPossibleTotalScore_];
  	textBar_->SetText([scoreText UTF8String]);
    shouldUpdateTextBar_ = false;    
  }
}
//------------------------------------------------------------------------------
void Model::Render()
{
	for (std::list<GameObject*>::iterator iter = gameObjects_.begin();
  	iter != gameObjects_.end(); ++iter)
  {
  	(*iter)->Render();
  }
  
  textBar_->Render();
}
//------------------------------------------------------------------------------
void Model::TouchesBegan(GLfloat x, GLfloat y)
{
	if (y > 430.f)
  	return;
 
  std::list<GameObject*>::iterator iter = gameObjects_.end();
  iter--; // позже добавленные объекты приоритетнее,
  	// так как могут перекрывать более ранние 
  while (true)
  {
    if ((*iter)->IsPointInside(x, y))
    {
    	totalScore_ += (*iter)->Score();
      gameObjects_.erase(iter);
      break;
    }
      
  	if (iter == gameObjects_.begin())
    	break;
            
    --iter;
  }
  
  NSLog(@"totalScore_ = %d", (int)totalScore_);
  shouldUpdateTextBar_ = true;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
