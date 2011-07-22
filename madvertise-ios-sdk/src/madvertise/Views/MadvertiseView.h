// Copyright 2011 madvertise Mobile Advertising GmbH
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import "Ad.h"
#import "MadDebug.h"
#import "MadLocation.h"
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "InAppLandingPageController.h"
#import "MadvertiseDelegationProtocol.h"
#import "MadAdWhirlProtocol.h"


////////////////////////////////////
/// Enum of available banner formats
////////////////////////////////////
typedef enum tagMadvertiseAdClass {
  IABAd,MMAAd,leaderboard,full_screen,portrait,landscape,all 
} MadvertiseAdClass;


@interface MadvertiseView : UIView<UIWebViewDelegate> {
  
  //////////////
  // Attributes
  //////////////
  
  
  InAppLandingPageController* inAppLandingPageController;
  id<MadvertiseDelegationProtocol> madDelegate;           // the delegate which receives ad related events like: adLoaded or adLoadFailed
  NSMutableDictionary* post_params;
  NSMutableData* receivedData;                            // data received thorugh the connection to the ad server
  NSMutableURLRequest* request;  
  NSURLConnection *conn;                                  // current request object
  
  Ad* currentAd;                                          // current ad
  MadvertiseAdClass currentAdClass;                       // ad type
  
  NSInteger responseCode;                                 // flag that indicates if http response from ad server is ok
  bool isBannerMode;                                      // flag that indicates if the view shows a banner or a popup
  
  UIView* animationView;
  UIView* currentView;                                    // one of the two views above, depending on user action
  UIView* oldView;           
  
  int visibleHolder;
  UIWebView* placeholder_1;
  UIWebView* placeholder_2;
  NSLock* lock;                                           // lock which is used to avoid race conditions while requesting an ad

  NSTimer* timer;                                         // the ad rotation timer
  double interval;                                        // interval of ad refresh
  int x, y;                                               // Position
  
  double animationDuration;
}


/////////////////
/// constructor
////////////////

+ (MadvertiseView*)loadAdWithDelegate:(id<MadvertiseDelegationProtocol>)delegate withClass:(MadvertiseAdClass)adClassValue secondsToRefresh:(int)seconds;
+ (void) adLoadedHandlerWithObserver:(id) addObserver AndSelector:(SEL) sel;
+ (void) adLoadFailedHandlerWithObserver:(id) addObserver AndSelector:(SEL) sel;
- (void)place_at_x:(int)x_pos y:(int)y_pos;               // position the frame for the view


@end
