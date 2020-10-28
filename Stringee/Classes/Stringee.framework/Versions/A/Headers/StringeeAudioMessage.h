//
//  StringeeAudioMessage.h
//  Stringee
//
//  Created by HoangDuoc on 10/3/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"

/**
 Đại diện một message kiểu audio
 */
@interface StringeeAudioMessage : StringeeMessage

/**
 Cho biết địa chỉ file audio được lưu trữ trên server.
 */
@property (strong, nonatomic, readonly) NSString *fileUrl;

/**
 Cho biết địa chỉ file audio được lưu trữ ở máy nếu đã được tải về hoặc nil nếu chưa.
 */
@property (strong, nonatomic, readonly) NSString *filePath;

/**
 Khoảng thời gian của audio được phát.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 Hàm khởi tạo.
 @param url là đường dẫn tới file audio.
 @param metadata là dữ liệu bất kì gắn kèm với message này, có thể sử dụng để tuỳ biến thêm.
 @return 1 thể hiện của StringeeAudioMessage.
 */
- (instancetype)initWithPath:(NSURL *)url metadata:(NSDictionary *)metadata;

// Sử dụng cho react-native
- (instancetype)initWithFileUrl:(NSString *)fileUrl duration:(NSTimeInterval)duration metadata:(NSDictionary *)metadata;

@end
