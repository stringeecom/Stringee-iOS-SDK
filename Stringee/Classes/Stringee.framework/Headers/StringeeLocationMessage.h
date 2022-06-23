//
//  StringeeLocationMessage.h
//  Stringee
//
//  Created by HoangDuoc on 9/20/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"

@interface StringeeLocationMessage : StringeeMessage

@property (assign, nonatomic, readonly) double latitude;

@property (assign, nonatomic, readonly) double longitude;

- (instancetype)initWithlatitude:(double)latitude longitude:(double)longitude metadata:(NSDictionary *)metadata;

@end
