//
//  StringeeChatRequest.h
//  Stringee
//
//  Created by HoangDuoc on 1/18/19.
//  Copyright © 2019 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class StringeeClient;

NS_ASSUME_NONNULL_BEGIN

@interface StringeeChatRequest : NSObject

@property (strong, nonatomic, readonly) NSString *convId;
@property (strong, nonatomic, readonly) NSString *customerId;
@property (strong, nonatomic, readonly) NSString *customerName;

- (void)answerWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)rejectWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

@end

NS_ASSUME_NONNULL_END
