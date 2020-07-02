//
//  StringeeServerAddress.h
//  Stringee
//
//  Created by HoangDuoc on 6/15/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface StringeeServerAddress : NSObject

@property (nonatomic) NSString *host;
@property (assign, nonatomic) int port;

- (instancetype)initWithHost:(NSString *)host port:(int)port;

@end

NS_ASSUME_NONNULL_END
