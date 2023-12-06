//
//  StringeeVideoTrack.h
//  Stringee
//
//  Created by HoangDuoc on 6/9/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeClient.h"
#import "StringeeVideoTrackOption.h"
#import "StringeeVideoView.h"
#import "StringeeRoomUserInfo.h"

@class StringeeVideoTrack;
@class StringeeVideoRoom;

typedef NS_ENUM(NSInteger, StringeeTrackMediaType) {
    StringeeTrackMediaTypeAudio = 1,
    StringeeTrackMediaTypeVideo = 2
};

typedef NS_ENUM(NSInteger, StringeeTrackType) {
    StringeeTrackTypeCamera,
    StringeeTrackTypeScreen,
    StringeeTrackTypePlayer
};


@protocol StringeeVideoTrackDelegate <NSObject>

@required
- (void)ready:(StringeeVideoTrack *)track;

@end

@interface StringeeVideoTrack : NSObject

@property (assign, nonatomic) BOOL isLocal;
@property (assign, nonatomic) BOOL audio;
@property (assign, nonatomic) BOOL video;
@property (assign, nonatomic) BOOL screen;
@property (assign, nonatomic) BOOL player;

@property (assign, nonatomic) StringeeTrackType trackType;

@property (nonatomic) NSString *localId; // local track id, server se ghi nhan la peerConnectionID, moi track se co 1 peer
@property (nonatomic) NSString *serverId;
@property (nonatomic) NSString *serverPcId;
@property (nonatomic) StringeeRoomUserInfo *publisher;

@property (weak, nonatomic) id<StringeeVideoTrackDelegate> delegate;
@property (nonatomic) AVCaptureSession *captureSession; // video cua local
@property (weak, nonatomic) StringeeVideoRoom *room;
@property (assign, nonatomic) BOOL autoSendTrackMediaState;

- (instancetype)initWithClient:(StringeeClient *)client options:(StringeeVideoTrackOption *)options isLocal:(BOOL)isLocal delegate:(id<StringeeVideoTrackDelegate>)delegate;

- (StringeeVideoView *)attach;

- (StringeeVideoView *)attachWithVideoContentMode:(StringeeVideoContentMode)contentMode;

- (NSArray<StringeeVideoView *> *)detach;

- (void)detachAndRemove;

- (void)close;

- (BOOL)switchCamera;

- (BOOL)mute:(BOOL)mute;

- (BOOL)enableLocalVideo:(BOOL)enable;

- (void)stats:(BOOL)useVideoTrack completionHandler:(void (^)( NSDictionary<NSString *, NSString *> *values))completionHandler;

@end

