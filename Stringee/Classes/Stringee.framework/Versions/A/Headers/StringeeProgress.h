//
//  StringeeProgress.h
//  Stringee
//
//  Created by HoangDuoc on 9/18/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class StringeeProgress;

/**
 Report quá trình transfer data.
 */
@protocol StringeeProgressDelegate <NSObject>

/**
 Dữ liệu đang được transfer, đọc các thông số của StringeeProgress để biểu diễn quá trình.
 */
- (void)progressDidChange:(StringeeProgress *)progress;

/**
 Dữ liệu đã được transfer hoàn tất.
 */
- (void)transferCompleted:(StringeeProgress *)progress;

/**
 Dữ liệu đã được transfer thất bại, error mô tả lỗi trả về.
 */
- (void)transferFailed:(StringeeProgress *)progress error:(NSError **)error;

@end

/**
 Đại diện một message kiểu audio
 */
@interface StringeeProgress : NSObject

/**
 Tượng trưng tổng số phần công việc cần thực hiện
 */
@property (assign, nonatomic, readonly) NSUInteger totalUnitCount;

/**
 Tượng trưng số phần công việc đã hoàn thành.
 */
@property (assign, nonatomic, readonly) NSUInteger completedUnitCount;

/**
 Tượng trưng tỉ lệ công việc đã hoàn thành.
 */
@property (assign, nonatomic, readonly) double fractionCompleted;

/**
 Implement delegate để biết quá trình transfer.
 */
@property (weak, nonatomic) id<StringeeProgressDelegate> delegate;

@end
