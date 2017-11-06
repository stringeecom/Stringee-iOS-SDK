//
//  StringeeLocalVideoView.h
//  Stringee
//
//  Created by Hoang Duoc on 10/18/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>
#import "StringeeCameraPreviewView.h"
#import <UIKit/UIKit.h>
#import "StringeeVideoRenderer.h"

@interface StringeeLocalVideoView: StringeeCameraPreviewView<StringeeVideoRenderer>

@property(nonatomic, strong) AVCaptureSession * captureSession;

@end
