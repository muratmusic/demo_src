//
//  EEAppDelegate.h
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#include <memory>
//------------------------------------------------------------------------------
class Model;
//------------------------------------------------------------------------------
@interface EEAppDelegate : UIResponder <UIApplicationDelegate, GLKViewDelegate, GLKViewControllerDelegate>
{
	std::auto_ptr<Model> model_;
}
//------------------------------------------------------------------------------
@property (strong, nonatomic) UIWindow *window;
//------------------------------------------------------------------------------
@end
