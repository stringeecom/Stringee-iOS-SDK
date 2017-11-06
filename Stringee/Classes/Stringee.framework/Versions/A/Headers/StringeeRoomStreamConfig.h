//
//  StringeeRoomStreamConfig.h
//  Stringee
//
//  Created by Hoang Duoc on 10/20/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum {
    StreamVideoResolution_Normal      = 0, // 480 x 640
    StreamVideoResolution_HD          = 1  // 720 x 1280
} StreamVideoResolution;


@interface StringeeRoomStreamConfig : NSObject

@property(assign, nonatomic) StreamVideoResolution streamVideoResolution;


- (instancetype)init;

@end
