//
//  StringeeStickerMessage.h
//  Stringee
//
//  Created by HoangDuoc on 5/17/19.
//  Copyright © 2019 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"


@interface StringeeStickerMessage : StringeeMessage

@property (strong, nonatomic) NSString *category;

@property (strong, nonatomic) NSString *name;

- (instancetype)initWithCategory:(NSString *)category name:(NSString *)name metadata:(NSDictionary *)metadata;

@end

