//
//  StringeeIdentity.h
//  Stringee
//
//  Created by Hoang Duoc on 6/1/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, StringeeRole) {
    StringeeRoleMember,
    StringeeRoleAdmin
};

/**
 Đại diện một user trong hệ thống với các thông tin định danh người dùng, thông tin của người dùng trong conversation.
 */
@interface StringeeIdentity : NSObject

/**
 Thông tin định danh người dùng là duy nhất trong hệ thống.
 */
@property (strong, nonatomic) NSString *userId;

/**
 Link avatar image của người dùng nếu có.
 */
@property (strong, nonatomic) NSString *avatarUrl;

/**
 Tên hiển thị của người dùng nếu có
 */
@property (strong, nonatomic) NSString *displayName;

/**
 Sequence của tin nhắn cuối cùng mà user nhận được trong conversation, trường này sử dụng khi đọc thông của Participants trong conversation.
 */
@property (assign, nonatomic, readonly) NSUInteger lastMsgSeqReceived;

/**
 Sequence của tin nhắn cuối cùng mà user đã xem trong conversation, trường này sử dụng khi đọc thông của Participants trong conversation.
 */
@property (assign, nonatomic, readonly) NSUInteger lastMsgSeqSeen;

@property (assign, nonatomic, readonly) StringeeRole role;


@end
