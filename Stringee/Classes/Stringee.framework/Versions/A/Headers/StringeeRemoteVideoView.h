//
//  StringeeRemoteVideoView.h
//  Stringee
//
//  Created by Hoang Duoc on 10/18/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeVideoView.h"

@class StringeeRemoteVideoView;

@protocol StringeeRemoteViewDelegate<StringeeVideoViewDelegate>

- (void)videoView:(StringeeRemoteVideoView *)videoView didChangeVideoSize:(CGSize)size;

@end


@interface StringeeRemoteVideoView : StringeeVideoView

@property(nonatomic, weak) id<StringeeRemoteViewDelegate> delegate;

@end
