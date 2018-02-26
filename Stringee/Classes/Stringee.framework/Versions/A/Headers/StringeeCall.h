//
//  StringeeCall.h
//  Stringee
//
//  Created by Hoang Duoc on 10/12/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CTCall.h>
#import <CoreTelephony/CTCallCenter.h>
#import "StringeeClient.h"
#import "StringeeLocalVideoView.h"
#import "StringeeRemoteVideoView.h"
#import "StringeeRoomStreamConfig.h"

@class StringeeCall;

typedef enum {
    STRINGEE_CALLSTATE_INIT           = 0,
    STRINGEE_CALLSTATE_CALLING        = 1,
    STRINGEE_CALLSTATE_RINGING        = 2,
    STRINGEE_CALLSTATE_STARTING       = 3,
    STRINGEE_CALLSTATE_CONNECTED      = 4,
    STRINGEE_CALLSTATE_BUSY           = 5,
    STRINGEE_CALLSTATE_END            = 6
} StringeeCallState;

typedef enum {
    CallType_CallIn                     = 0,
    CallType_CallOut                    = 1,
    CallType_Internal_Incoming_Call     = 2,
    CallType_Internal_Call_Away         = 3
} CallType;

typedef enum {
    CallDTMF_Zero           = 0,
    CallDTMF_One            = 1,
    CallDTMF_Two            = 2,
    CallDTMF_Three          = 3,
    CallDTMF_Four           = 4,
    CallDTMF_Five           = 5,
    CallDTMF_Six            = 6,
    CallDTMF_Seven          = 7,
    CallDTMF_Eight          = 8,
    CallDTMF_Nine           = 9,
    CallDTMF_Star           = 10,
    CallDTMF_Pound          = 11
} CallDTMF;


@protocol StringeeCallStateDelegate <NSObject>

@required

- (void)didChangeState:(StringeeCall *)stringeeCall stringeeCallState:(StringeeCallState)state reason:(NSString *)reason;

@end


@protocol StringeeCallMediaDelegate <NSObject>

@required

- (void)didReceiveDtmfDigit:(StringeeCall *)stringeeCall digit:(NSString *)digit;

- (void)didReceiveCallInfo:(StringeeCall *)stringeeCall info:(NSDictionary *)info;

- (void)didAnsweredOnOtherDevice:(StringeeCall *)stringeeCall state:(StringeeCallState)state;

- (void)didReceiveLocalStream:(StringeeCall *)stringeeCall;

- (void)didReceiveRemoteStream:(StringeeCall *)stringeeCall;

@end


@interface StringeeCall : NSObject

@property (strong, nonatomic, readonly) NSString *callId;
@property (strong, nonatomic, readonly) NSString *from;
@property (strong, nonatomic, readonly) NSString *to;
@property (strong, nonatomic, readonly) NSString *fromAlias;
@property (strong, nonatomic, readonly) NSString *toAlias;
@property (weak, nonatomic) id<StringeeCallStateDelegate> callStateDelegate;
@property (weak, nonatomic) id<StringeeCallMediaDelegate> callMediaDelegate;
@property (assign, nonatomic, readonly) BOOL isIncomingCall;
@property (assign, nonatomic, readonly) BOOL answeredOnAnotherDevice;
@property (assign, nonatomic, readonly) CallType callType;
@property (assign, nonatomic) BOOL isVideoCall;
@property (assign, nonatomic) VideoResolution videoResolution;
@property (strong, nonatomic, readonly) StringeeLocalVideoView *localVideoView;
@property (strong, nonatomic, readonly) StringeeRemoteVideoView *remoteVideoView;


// MARK: - Init

- (instancetype)initWithStringeeClient:(StringeeClient *) stringeeClient from:(NSString *) from to:(NSString *) to;

// MARK: - Public

- (void)makeCallWithCompletionHandler:(void(^)(BOOL status, int code, NSString * message)) completionHandler;

- (void)initAnswerCall;

- (void)answerCallWithCompletionHandler:(void(^)(BOOL status, int code, NSString * message)) completionHandler;

- (void)hangupWithCompletionHandler:(void(^)(BOOL status, int code, NSString * message)) completionHandler;

- (void)rejectWithCompletionHandler:(void(^)(BOOL status, int code, NSString * message)) completionHandler;

- (void)sendDTMF:(CallDTMF)callDTMF completionHandler:(void(^)(BOOL status, int code, NSString * message))completionHandler;

- (void)sendCallInfo:(NSDictionary *)info;

- (void)switchCamera;

- (BOOL)enableLocalVideo:(BOOL)isEnable;

- (void)autoOrientationOfLocalVideoViewWithSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator;

- (void)mute:(BOOL)isMute;

- (void)statsWithCompletionHandler:
(void (^)( NSDictionary<NSString *, NSString *> *values ))completionHandler;

@end
