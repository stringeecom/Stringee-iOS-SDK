//
//  StringeePhotoMessage.h
//  Stringee
//
//  Created by HoangDuoc on 9/20/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"

/**
 Lớp đại diện cho một tin nhắn dạng ảnh
 */
@interface StringeePhotoMessage : StringeeMessage

/**
 Cho biết địa chỉ file ảnh được lưu trữ trên server.
 */
@property (strong, nonatomic, readonly) NSString *fileUrl;

/**
 Cho biết địa chỉ file ảnh được lưu trữ ở máy nếu đã được tải về hoặc nil nếu chưa.
 */
@property (strong, nonatomic, readonly) NSString *filePath;

/**
 Cho biết địa chỉ file thumbnail được lưu trữ trên server
 */
@property (strong, nonatomic, readonly) NSString *thumbnailUrl;

/**
 Cho biết địa chỉ file thumbnail được lưu trữ ở máy nếu đã được tải về hoặc nil nếu chưa.
 */
@property (strong, nonatomic, readonly) NSString *thumbnailPath;

/**
 Tỉ lệ ảnh
 */
@property (assign, nonatomic, readonly) float ratio;

/**
 Hàm khởi tạo.
 @param image là ảnh cần gửi
 @param metadata là dữ liệu bất kì gắn kèm với message này, có thể sử dụng để tuỳ biến thêm.
 @return 1 thể hiện của StringeePhotoMessage.
 */
- (instancetype)initWithImage:(UIImage *)image metadata:(NSDictionary *)metadata;

// Sử dụng cho react-native
- (instancetype)initWithFileUrl:(NSString *)fileUrl thumbnailUrl:(NSString *)thumbnailUrl ratio:(float)ratio metadata:(NSDictionary *)metadata;

@end
