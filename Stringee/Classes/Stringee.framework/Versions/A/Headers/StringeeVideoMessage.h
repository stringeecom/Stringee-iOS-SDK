//
//  StringeeVideoMessage.h
//  Stringee
//
//  Created by HoangDuoc on 9/25/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"

@interface StringeeVideoMessage : StringeeMessage

/**
 Cho biết địa chỉ file video được lưu trữ trên server.
 */
@property (strong, nonatomic, readonly) NSString *fileUrl;

/**
 Cho biết địa chỉ file video được lưu trữ ở máy nếu đã được tải về hoặc nil nếu chưa.
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
 Tỉ lệ thumbnail của video, sử dụng để căn chỉnh khung hiển thị video.
 */
@property (assign, nonatomic, readonly) float ratio;

/**
 Khoảng thời gian của video được phát.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 Hàm khởi tạo.
 @param url là đường dẫn tới file video.
 @param metadata là dữ liệu bất kì gắn kèm với message này, có thể sử dụng để tuỳ biến thêm.
 @return 1 thể hiện của StringeeVideoMessage.
 */
- (instancetype)initWithPath:(NSURL *)url metadata:(NSDictionary *)metadata;

// Sử dụng cho react-native
- (instancetype)initWithFileUrl:(NSString *)fileUrl thumbnailUrl:(NSString *)thumbnailUrl ratio:(float)ratio duration:(NSTimeInterval)duration metadata:(NSDictionary *)metadata;

@end
