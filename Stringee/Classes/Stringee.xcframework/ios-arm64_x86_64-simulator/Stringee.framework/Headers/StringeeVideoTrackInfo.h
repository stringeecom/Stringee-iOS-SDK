//
//  StringeeVideoTrackInfo.h
//  Stringee
//
//  Created by HoangDuoc on 6/10/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeRoomUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface StringeeVideoTrackInfo : NSObject

@property (nonatomic) StringeeRoomUserInfo *publisher;
@property (nonatomic) NSString *serverId;
@property (assign, nonatomic) BOOL audio;
@property (assign, nonatomic) BOOL video;
@property (assign, nonatomic) BOOL screen;

// Private
@property (nonatomic) NSString *userPublish;

- (instancetype)initWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
