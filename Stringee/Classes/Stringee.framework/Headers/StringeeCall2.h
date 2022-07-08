//
//  StringeeCall2.h
//  Stringee
//
//  Created by HoangDuoc on 8/29/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeCall.h"
#import "StringeeVideo.h"

@class StringeeCall2;

@protocol StringeeCall2Delegate <NSObject>

@required

- (void)didChangeSignalingState2:(StringeeCall2 *)stringeeCall2 signalingState:(SignalingState)signalingState reason:(NSString *)reason sipCode:(int)sipCode sipReason:(NSString *)sipReason;

- (void)didChangeMediaState2:(StringeeCall2 *)stringeeCall2 mediaState:(MediaState)mediaState;

@optional

- (void)didReceiveLocalStream2:(StringeeCall2 *)stringeeCall2;

- (void)didReceiveRemoteStream2:(StringeeCall2 *)stringeeCall2;

- (void)didAddTrack2:(StringeeCall2 *)stringeeCall2 track:(StringeeVideoTrack *)track;

- (void)didHandleOnAnotherDevice2:(StringeeCall2 *)stringeeCall2 signalingState:(SignalingState)signalingState reason:(NSString *)reason sipCode:(int)sipCode sipReason:(NSString *)sipReason;

- (void)didReceiveCallInfo2:(StringeeCall2 *)stringeeCall2 info:(NSDictionary *)info;

- (void)trackMediaStateChange:(StringeeCall2 *)stringeeCall2 mediaType:(StringeeTrackMediaType)mediaType enable:(BOOL)enable from:(NSString *)from;

@end

@interface StringeeCall2 : NSObject

@property (strong, nonatomic, readonly) NSString *callId;
@property (assign, nonatomic, readonly) int serial;
@property (strong, nonatomic, readonly) NSString *from;
@property (strong, nonatomic, readonly) NSString *to;
@property (strong, nonatomic, readonly) NSString *fromAlias;
@property (strong, nonatomic, readonly) NSString *toAlias;
@property (weak, nonatomic) id<StringeeCall2Delegate> delegate;
@property (assign, nonatomic, readonly) BOOL isIncomingCall;
@property (assign, nonatomic, readonly) SignalingState signalingState;
@property (assign, nonatomic, readonly) BOOL answeredOnAnotherDevice;
@property (assign, nonatomic, readonly) CallType callType;
@property (strong, nonatomic) NSString *customData;
@property (strong, nonatomic, readonly) NSString *customDataFromYourServer;
@property (assign, nonatomic) BOOL isVideoCall;
@property (assign, nonatomic) VideoResolution videoResolution;
@property (assign, nonatomic) StringeeVideoContentMode videoContentMode;
@property (strong, nonatomic, readonly) StringeeVideoView *localVideoView;
@property (strong, nonatomic, readonly) StringeeVideoView *remoteVideoView;
@property (assign, nonatomic) BOOL autoSendTrackMediaState;

- (instancetype)initWithStringeeClient:(StringeeClient *)stringeeClient from:(NSString *)from to:(NSString *)to;

- (void)makeCallWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message, NSString *data))completionHandler;

- (void)initAnswerCall;

- (void)answerCallWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)hangupWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)rejectWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)switchCamera;

- (BOOL)enableLocalVideo:(BOOL)isEnable;

- (void)mute:(BOOL)isMute;

- (void)sendCallInfo:(NSDictionary *)info completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)stats:(BOOL)useVideoTrack completionHandler:(void (^)( NSDictionary<NSString *, NSString *> *values))completionHandler;

- (void)sendDTMF:(CallDTMF)callDTMF completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

@end

