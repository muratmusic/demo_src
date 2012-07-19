//
//  EEAppDelegate.mm
//  Circles
//
//  Created by Murat Dzhusupov on 19.07.12.
//
//------------------------------------------------------------------------------
#import "EEAppDelegate.h"
#import "TouchedGLKView.h"
#include "Model.h"
//------------------------------------------------------------------------------
@implementation EEAppDelegate
//------------------------------------------------------------------------------
@synthesize window = _window;
//------------------------------------------------------------------------------
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	model_.reset(new Model());

  EAGLContext *context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
  [EAGLContext setCurrentContext:context];
  
  TouchedGLKView *view = [[TouchedGLKView alloc] initWithFrame:[[UIScreen mainScreen] bounds] context:context];
  [view setModel:model_.get()];
  view.delegate = self;
  
  GLKViewController *controller = [[GLKViewController alloc] init];
  controller.delegate = self;
  controller.view = view;
  
  self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
  self.window.rootViewController = controller;
  [self.window makeKeyAndVisible];
  
  return YES;
}
//------------------------------------------------------------------------------
- (void)glkViewControllerUpdate:(GLKViewController *)controller
{
  //NSLog(@"in glkViewControllerUpdate");
  model_->Update(controller.timeSinceLastUpdate);
}
//------------------------------------------------------------------------------
- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
  //NSLog(@"in glkView:drawInRect:");
  glClearColor(0.f, 0.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT);
  
  model_->Render();
}
//------------------------------------------------------------------------------
- (void)applicationWillResignActive:(UIApplication *)application
{
  /*
   Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
   Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
   */
}
//------------------------------------------------------------------------------
- (void)applicationDidEnterBackground:(UIApplication *)application
{
  /*
   Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
   If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
   */
}
//------------------------------------------------------------------------------
- (void)applicationWillEnterForeground:(UIApplication *)application
{
  /*
   Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
   */
}
//------------------------------------------------------------------------------
- (void)applicationDidBecomeActive:(UIApplication *)application
{
  /*
   Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
   */
}
//------------------------------------------------------------------------------
- (void)applicationWillTerminate:(UIApplication *)application
{
  /*
   Called when the application is about to terminate.
   Save data if appropriate.
   See also applicationDidEnterBackground:.
   */
}
//------------------------------------------------------------------------------
@end
