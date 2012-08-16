// Copyright 2012 madvertise Mobile Advertising GmbH
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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface MadvertiseTracker : NSObject {
}

+ (void) reportDownload:(NSURL*) url;

// sends a request on first start to the madvertise server
// !!call setDebugMode and setProductToken before!!
+ (void) reportActionToMadvertise: (NSString*) action_type;

// set debug mode, default is NO
+ (void) setDebugMode: (BOOL) debugMode;

// set product token, that you will geth from madvertise
+ (void) setProductToken: (NSString *) productToken;

+ (void) enable;

@end
