//
//  TouchedGLKView.mm
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//

#import "TouchedGLKView.h"
#include "Model.h"

@implementation TouchedGLKView

- (void)setModel:(Model *)model
{
	model_ = model;
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
	if (!model_)
  	return;
    
  // все касания, используемые в жесте:
	NSSet *allTouches = [event touchesForView:self];
	// мультитач более 2-х пальцев игнорируем:	
	if ([allTouches count] > 2)	return;
	
	int finger = 0; // индекс пальца из множества касаний
	NSEnumerator *enumerator = [allTouches objectEnumerator];
	UITouch *touch;
	// 2 безопасно
	CGPoint location[2];
	NSUInteger tapCounts[2];
	while ((touch = (UITouch*)[enumerator nextObject]) && finger < 2)
	{
		location[finger] = [touch locationInView:self];
		tapCounts[finger] = [touch tapCount];
		++finger; // после цикла finger = количеству пальцев, удерживаемых на экране
	}
	
	if (1 == finger)
	{
  	GLfloat x = location[0].x;
    GLfloat y = 460.f - location[0].y;    
  	model_->TouchesBegan(x, y);		
	}
  // if (2 == finger) // а вообще нужен ли нам мультитач?
}

@end
