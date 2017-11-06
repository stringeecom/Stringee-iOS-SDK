//
//  StringeeCall.h
//  Stringee
//
//  Created by Hoang Duoc on 10/12/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeePrivateCall.h"
#import "StringeeConstants.h"
#import "StringeePacketSender.h"

#import <CoreTelephony/CTCall.h>
#import <CoreTelephony/CTCallCenter.h>
#import "StringeeClient.h"

#import "StringeeLocalVideoView.h"
#import "StringeeRemoteVideoView.h"

@class StringeeCall;
@class StringeeClient;


typedef enum {
    STRINGEE_CALLSTATE_INIT           = 0,
    STRINGEE_CALLSTATE_CALLING        = 1,
    STRINGEE_CALLSTATE_RINGING        = 2,
    STRINGEE_CALLSTATE_STARTING       = 3,
    STRINGEE_CALLSTATE_CONNECTED      = 4,
    STRINGEE_CALLSTATE_END            = 5
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

typedef enum {
    VideoResolution_Normal      = 0,
    VideoResolution_HD          = 1
} VideoResolution;

@protocol StringeeCallStateDelegate <NSObject>

@required

-(void) didChangeState:(StringeeCall *) stringeeCall stringeeCallState:(StringeeCallState) state reason:(NSString *) reason;

@end



@protocol StringeeCallMediaDelegate <NSObject>

@required

-(void) didReceiveDtmfDigit:(StringeeCall *) stringeeCall digit:(NSString *) digit;

-(void) didReceiveLocalStream:(StringeeCall *) stringeeCall;

-(void) didReceiveRemoteStream:(StringeeCall *) stringeeCall;

@end


@interface StringeeCall : NSObject<StringeePrivateCallDelegate>

@property(assign, nonatomic) int stringeeCallId;
@property(strong, nonatomic) NSString * callId;
@property(strong, nonatomic) NSString * from;
@property(strong, nonatomic) NSString * to;
@property(strong, nonatomic) NSString * fromAlias;
@property(strong, nonatomic) NSString * toAlias;
@property(strong, nonatomic) NSDictionary * customData;
@property(assign, nonatomic) BOOL isIncomingCall;

@property(weak, nonatomic) id<StringeeCallStateDelegate> callStateDelegate;
@property(weak, nonatomic) id<StringeeCallMediaDelegate> callMediaDelegate;
@property(weak, nonatomic) StringeeClient * stringeeClient;


@property(strong, nonatomic) StringeePrivateCall * call;
@property(assign, nonatomic) BOOL isCaller;
@property(assign, nonatomic) CallType callType;
@property(assign, nonatomic) BOOL isVideoCall;
@property(assign, nonatomic) VideoResolution videoResolution;
@property(assign, nonatomic) BOOL hasAddedCandidate;
@property(assign, nonatomic) BOOL hasSetSDP;
@property(strong, nonatomic) NSMutableArray *  arrayLocalCandidates;

@property(assign, nonatomic) BOOL isAcceptedCall;
@property(assign, nonatomic) BOOL isPeerConnected;

// Remote info
//@property(assign, nonatomic) BOOL * didSetRemoteSDP;

@property (nonatomic, strong) completion makeCallHandler;
@property (nonatomic, strong) NSMutableDictionary * dicDTMFHander;


// Video
@property(strong, nonatomic) StringeeLocalVideoView * localVideoView;
@property(strong, nonatomic) StringeeRemoteVideoView * remoteVideoView;

@property(strong, nonatomic) AVCaptureSession * localCaptionSesstion;
@property(strong, nonatomic) StringeeVideoTrack * remoteVideoTrack;

// MARK: - Init

-(instancetype) initWithStringeeClient:(StringeeClient *) stringeeClient isIncomingCall:(BOOL) isIncomingCall from:(NSString *) from to:(NSString *) to;

-(instancetype) initWithStringeeClient:(StringeeClient *) stringeeClient isIncomingCall:(BOOL) isIncomingCall from:(NSString *) from to:(NSString *) to callId:(NSString *) callId;



// MARK: - Public

-(void) makeCallWithCompletionHandler:(completion) completionHandler;

-(void) initAnswerCall;

-(void) answerCall;

-(void) hangup;

-(void) callDTMF:(CallDTMF) callDTMF completionHandler:(completion) completionHandler;

// Video Call
-(void) switchCamera;

-(void) turnOnCamera:(BOOL) isOn;

-(void) autoOrientationOfLocalVideoViewWithSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator;

// MARK: - Process

-(void) startCallWith:(NSMutableArray<StringeeIceServer*>*) iceServers andCallId: (NSString *) callId isCaller:(BOOL) isCaller;

-(void) setSDPReceiveFromGateWay:(StringeeSDP *) sdp andCallId:(NSString *) callId;

-(void) addCandidate:(StringeeIceCandidate *) candidate;

-(void) addCandidatesFollowOrderWithArray:(NSMutableArray *) arrayCandidates;

-(void) processHangup;

// Option

- (void)mute:(BOOL)isMute;

- (void)statsWithCompletionHandler:
(void (^)( NSDictionary<NSString *, NSString *> *values ))completionHandler;

@end
