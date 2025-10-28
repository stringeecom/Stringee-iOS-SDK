//
//  StringeeVideo.h
//  Stringee
//
//  Created by HoangDuoc on 6/9/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeClient.h"
#import "StringeeVideoTrackOption.h"
#import "StringeeVideoTrack.h"
#import "StringeeVideoRoom.h"

NS_ASSUME_NONNULL_BEGIN

@interface StringeeVideo : NSObject

+ (void)addRoom:(StringeeVideoRoom *)room;

+ (StringeeVideoRoom *)getRoom:(NSString *)roomId;

+ (void)removeRoom:(StringeeVideoRoom *)room;

+ (void)joinRoom:(StringeeClient *)client roomToken:(NSString *)roomToken completion:(void(^)(BOOL status, int code, NSString * message, StringeeVideoRoom *room, NSArray<StringeeVideoTrackInfo *> *tracks, NSArray<StringeeRoomUserInfo *> *users))completion;

+ (StringeeVideoTrack *)createLocalVideoTrack:(StringeeClient *)client options:(StringeeVideoTrackOption *)options delegate:(id<StringeeVideoTrackDelegate>)delegate;


@end

NS_ASSUME_NONNULL_END
