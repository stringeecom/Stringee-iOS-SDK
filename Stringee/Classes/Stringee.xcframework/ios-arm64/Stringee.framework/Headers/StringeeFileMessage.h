//
//  StringeeFileMessage.h
//  Stringee
//
//  Created by HoangDuoc on 10/8/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"

/**
 Đại diện một message kiểu file
 */

@interface StringeeFileMessage : StringeeMessage

/**
 Cho biết địa chỉ file audio được lưu trữ trên server.
 */
@property (strong, nonatomic, readonly) NSString *fileUrl;

/**
 Cho biết địa chỉ file audio được lưu trữ ở máy nếu đã được tải về hoặc nil nếu chưa.
 */
@property (strong, nonatomic, readonly) NSString *filePath;

/**
 Tên file
 */
@property (strong, nonatomic, readonly) NSString *filename;

/**
 Dung lượng của file
 */
@property (assign, nonatomic, readonly) NSUInteger length;

/**
 Hàm khởi tạo.
 @param url là đường dẫn tới file.
 @param metadata là dữ liệu bất kì gắn kèm với message này, có thể sử dụng để tuỳ biến thêm.
 @return 1 thể hiện của StringeeFileMessage.
 */
- (instancetype)initWithPath:(NSURL *)url metadata:(NSDictionary *)metadata;

// Sử dụng cho react-native
- (instancetype)initWithFileUrl:(NSString *)fileUrl fileName:(NSString *)fileName length:(NSUInteger)length metadata:(NSDictionary *)metadata;

@end
