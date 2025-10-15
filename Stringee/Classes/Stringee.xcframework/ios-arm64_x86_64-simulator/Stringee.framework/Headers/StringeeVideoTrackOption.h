//
//  StringeeVideoTrackOption.h
//  Stringee
//
//  Created by HoangDuoc on 6/10/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, StringeeVideoDimension) {
    StringeeVideoDimension1080p,
    StringeeVideoDimension720p,
    StringeeVideoDimension480p,
    StringeeVideoDimension288p
};

@interface StringeeVideoTrackOption : NSObject

@property (assign, nonatomic) BOOL audio;
@property (assign, nonatomic) BOOL video;
@property (assign, nonatomic) BOOL screen;
@property (assign, nonatomic) StringeeVideoDimension videoDimension;

@end

NS_ASSUME_NONNULL_END
