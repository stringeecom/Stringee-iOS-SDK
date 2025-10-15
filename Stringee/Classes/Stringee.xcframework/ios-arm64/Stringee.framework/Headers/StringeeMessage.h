//
//  StringeeMessage.h
//  Stringee
//
//  Created by Hoang Duoc on 5/5/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeProgress.h"

@class StringeeConversation;
@class StringeeClient;

typedef NS_ENUM(NSInteger, StringeeChannel) {
    StringeeChannelNormal       = 0,
    StringeeChannelLiveChat     = 1,
    StringeeChannelFacebook     = 2,
    StringeeChannelZalo         = 3,
};

typedef NS_ENUM(NSInteger, StringeeMessageType) {
    // Message kiểu text
    StringeeMessageTypeText             = 1,
    
    // Message kiểu ảnh
    StringeeMessageTypePhoto            = 2,
    
    // Message kiểu video
    StringeeMessageTypeVideo            = 3,
    
    // Message kiểu audio
    StringeeMessageTypeAudio            = 4,
    
    // Message kiểu File
    StringeeMessageTypeFile             = 5,
    
    // Message kiểu Link
    StringeeMessageTypeLink             = 6,
    
    // Message dạng text có nội dung khi group được tạo
    StringeeMessageTypeCreateGroup      = 7,
    
    // Message dạng text có nội dung khi group đổi tên.
    StringeeMessageTypeRenameGroup      = 8,
    
    // Message kiểu Localtion.
    StringeeMessageTypeLocation         = 9,
    
    // Message kiểu Contact.
    StringeeMessageTypeContact          = 10,
    
    // Message kiểu Sticker.
    StringeeMessageTypeSticker          = 11,

    // Message kiểu thông báo (thêm thành viên, xoá thành viên).
    StringeeMessageTypeNotify           = 100
};

typedef NS_ENUM(NSInteger, StringeeMessageStatus) {
    // Tin nhắn đang được xử lý và chờ để gửi đi.
    StringeeMessageStatusPending,
    
    // Tin nhắn đang được gửi đi.
    StringeeMessageStatusSending,
    
    // Tin nhắn đã được gửi đi.
    StringeeMessageStatusSent,
    
    // Người nhận đã nhận được tin nhắn.
    StringeeMessageStatusDelivered,
    
    // Tin nhắn đã được người nhận đọc.
    StringeeMessageStatusRead
};

typedef NS_ENUM(NSInteger, StringeeContentTransferStatus) {
    // Content có sẵn ở local, đang chờ để upload
    StringeeContentTransferAwaitingUpload,
    
    // Content có sẵn ở local, đang được upload
    StringeeContentTransferUploading,
    
    // Content không có ở local nhưng có thể download
    StringeeContentTransferReadyForDownload,
    
    // Content đang được download
    StringeeContentTransferDownloading,
    
    // Content đã được download hoặc upload thành công, có sẵn ở local
    StringeeContentTransferComplete,
};

/**
 Đại diện một tin nhắn trong hệ thống, là lớp cha cho các lớp tin nhắn với kiểu cụ thể(StringeeAudioMessage, StringeeContactMessage...)
 */
@interface StringeeMessage : NSObject

/**
 Định danh Message trong local database, chỉ có ý nghĩa phân biệt ở 1 thiết bị.
 */
@property (strong, nonatomic, readonly) NSString *localIdentifier;

/**
 Định danh Message là duy nhất trên hệ thống.
 */
@property (strong, nonatomic, readonly) NSString *identifier;

/**
 Conversation's localIdentifier mà tin nhắn thuộc về.
 */
@property (strong, nonatomic, readonly) NSString *convLocalId;

/**
 Conversation's identifier mà tin nhắn thuộc về.
 */
@property (strong, nonatomic, readonly) NSString *convId;

/**
 Kiểu tin nhắn.
 */
@property (assign, nonatomic, readonly) StringeeMessageType type;

/**
 Nội dung dạng text của tin nhắn.
 */
@property (strong, nonatomic, readonly) NSString *content;

/**
 Mốc thời gian mà message được tạo.
 */
@property (assign, nonatomic, readonly) long long created;

/**
 Sequence của message.
 */
@property (assign, nonatomic, readonly) NSUInteger seq;

/**
 UserId của người gửi tin nhắn.
 */
@property (strong, nonatomic, readonly) NSString *sender;

@property(assign, nonatomic, readonly) BOOL deleted;

@property (assign, nonatomic, readonly) StringeeChannel channelType;

/**
 Trạng thái của tin nhắn.
 */
@property (assign, nonatomic, readonly) StringeeMessageStatus status;

/**
 Một dạng custom data của tin nhắn mà người dùng có thể tuỳ biến. Người dùng truyền vào giá trị này khi tạo tin nhắn, người nhận sẽ đọc được.
 */
@property (strong, nonatomic, readonly) NSDictionary *metadata;

/**
 Trạng thái quá trình transfer data. Ex: upload image, video...
 */
@property (assign, nonatomic, readonly) StringeeContentTransferStatus transferStatus;

/**
 Một thể hiện của StringeeProgress, làm việc với object này để lấy report về quá trình transfer data.
 */
@property (strong, nonatomic, readonly) StringeeProgress *progress;

/**
 Thực hiện upload data của message. Ex: video, image...
 completion trả về kết quả.
 */
- (void)uploadContentWithCompletion:(void (^)(BOOL status))completion;

/**
 Tải xuống data của message được lưu ở fileUrl, sau qúa trình này sẽ có filePath.
 */
- (void)downloadContent;

/**
 Xoá tin nhắn.
 @completionHandler trả về kết quả.
 */
- (void)deleteWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

@end
