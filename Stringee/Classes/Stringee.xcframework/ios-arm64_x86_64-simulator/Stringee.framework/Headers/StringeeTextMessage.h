//
//  StringeeTextMessage.h
//  Stringee
//
//  Created by HoangDuoc on 9/20/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"

/**
 Đại diện một message kiểu text
 */
@interface StringeeTextMessage : StringeeMessage

/**
 Hàm khởi tạo.
 @param text là chuỗi cần gửi.
 @param metadata là dữ liệu bất kì gắn kèm với message này, có thể sử dụng để tuỳ biến thêm.
 @return 1 thể hiện của StringeeTextMessage.
 */
- (instancetype)initWithText:(NSString *)text metadata:(NSDictionary *)metadata;

// Sử dụng cho react-native
- (instancetype)initWithLink:(NSString *)link metadata:(NSDictionary *)metadata;

@end
