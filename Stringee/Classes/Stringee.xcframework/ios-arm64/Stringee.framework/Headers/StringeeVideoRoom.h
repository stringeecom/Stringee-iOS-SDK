//
//  StringeeVideoRoom.h
//  Stringee
//
//  Created by HoangDuoc on 6/9/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeVideoTrack.h"
#import "StringeeVideoTrackInfo.h"

@class StringeeClient;
@class StringeeVideoRoom;

@protocol StringeeVideoRoomDelegate <NSObject>

@required

- (void)joinRoom:(StringeeVideoRoom *)room userInfo:(StringeeRoomUserInfo *)userInfo;

- (void)leaveRoom:(StringeeVideoRoom *)room userInfo:(StringeeRoomUserInfo *)userInfo;

- (void)addTrack:(StringeeVideoRoom *)room trackInfo:(StringeeVideoTrackInfo *)trackInfo;

- (void)removeTrack:(StringeeVideoRoom *)room trackInfo:(StringeeVideoTrackInfo *)trackInfo;

- (void)newMessage:(StringeeVideoRoom *)room msg:(NSDictionary *)msg fromUser:(StringeeRoomUserInfo *)fromUser;

@end

@interface StringeeVideoRoom : NSObject

@property (nonatomic) NSString *roomId;
@property (assign, nonatomic) BOOL permissionControlRoom;
@property (assign, nonatomic) BOOL permissionPublish;
@property (assign, nonatomic) BOOL permissionSubscribe;
@property (assign, nonatomic) BOOL record;
@property (weak, nonatomic) id<StringeeVideoRoomDelegate> delegate;


@property (nonatomic) StringeeClient *client;

- (instancetype)initWithClient:(StringeeClient *)client joinData:(NSDictionary *)data;

- (void)publish:(StringeeVideoTrack *)localTrack completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)unpublish:(StringeeVideoTrack *)localTrack completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)subscribe:(StringeeVideoTrackInfo *)trackInfo options:(StringeeVideoTrackOption *)options delegate:(id<StringeeVideoTrackDelegate>)delegate completion:(void(^)(BOOL status, int code, NSString *message, StringeeVideoTrack *videoTrack))completion;

- (void)unsubscribe:(StringeeVideoTrack *)subscribedTrack completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)sendMessage:(NSDictionary *)message completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)save:(StringeeVideoTrack *)track;

- (void)remove:(StringeeVideoTrack *)track;

- (void)leave:(BOOL)allStringeeClient completion:(void(^)(BOOL status, int code, NSString *message))completion;

@end

