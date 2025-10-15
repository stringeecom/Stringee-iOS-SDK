//
//  StringeeVideoView.h
//  Stringee
//
//  Created by HoangDuoc on 6/16/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, StringeeVideoContentMode) {
    StringeeVideoContentModeScaleAspectFill,
    StringeeVideoContentModeScaleAspectFit
};

typedef NS_ENUM(NSInteger, StringeeScannerType) {
    StringeeScannerTypeRectangle,
    StringeeScannerTypeOval
};

@interface StringeeVideoView : UIView

@property (nonatomic) AVCaptureSession *captureSession;

@property (nonatomic, assign) StringeeVideoContentMode contentMode;

- (void)addScanLayer;

- (void)removeScanLayer;

- (void)snapshotWithCompletion:(void(^)(UIImage *snapshot))completion;

- (void)setupScanView:(CGFloat)boderRadius maskWidth:(CGFloat)maskWidth ratio:(CGFloat)ratio color:(UIColor*)color cornerColor:(UIColor *)cornerColor type:(StringeeScannerType)type;
@end

