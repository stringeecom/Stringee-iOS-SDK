//
//  SXCustomerInfo.h
//  Stringee
//
//  Created by HoangDuoc on 2/28/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SXCustomerInfo : NSObject

@property (nonatomic, readonly) NSString *as;
@property (nonatomic, readonly) NSString *city;
@property (nonatomic, readonly) NSString *country;
@property (nonatomic, readonly) NSString *countryCode;
@property (nonatomic, readonly) NSString *isp;
@property (nonatomic, assign, readonly) double lat;
@property (nonatomic, assign, readonly) double lon;
@property (nonatomic, readonly) NSString *org;
@property (nonatomic, readonly) NSString *query;
@property (nonatomic, readonly) NSString *region;
@property (nonatomic, readonly) NSString *regionName;
@property (nonatomic, readonly) NSString *status;
@property (nonatomic, readonly) NSString *timezone;
@property (nonatomic, readonly) NSString *zip;

- (instancetype)initWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
