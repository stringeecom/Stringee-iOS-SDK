//
//  StringeeRoomUserInfo.h
//  Stringee
//
//  Created by HoangDuoc on 6/10/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface StringeeRoomUserInfo : NSObject

@property (nonatomic) NSString *userId;
@property (assign, nonatomic) BOOL canCallout;
@property (assign, nonatomic) long long loginTime;
@property (nonatomic) NSArray *attributes;

- (instancetype)initWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
