//
//  StringeeRoomStream.h
//  Stringee
//
//  Created by Hoang Duoc on 10/19/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeRemoteVideoView.h"
#import "StringeeLocalVideoView.h"
#import "ECStream.h"
#import "StringeeRoomStreamConfig.h"

@interface StringeeRoomStream : NSObject

@property (strong, nonatomic) NSString * userId;
@property(strong, nonatomic) NSString * streamId;

@property(strong, nonatomic) ECStream * stringeeLocalStream;
@property(strong, nonatomic) ECStream * stringeeRemoteStream;
@property(strong, nonatomic) StringeeRemoteVideoView * remoteVideoView;
@property(strong, nonatomic) StringeeLocalVideoView * localVideoView;
@property(strong, nonatomic) AVCaptureSession * localCaptionSesstion;

@property(assign, nonatomic, readonly) BOOL isLocal;
@property(assign, nonatomic) BOOL isReconnect;

// Public
- (instancetype)initLocalStreamWithConfig:(StringeeRoomStreamConfig *) config;

-(void)switchCamera;

-(void)mute:(BOOL) mute;

-(void)turnOnCammera:(BOOL) isOn;

-(void) autoOrientationOfLocalVideoViewWithSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator;


// Private
-(void) renderRemoteStream;

-(void) removeRenderRemoteStream;

-(void) cleanStream;
@end

