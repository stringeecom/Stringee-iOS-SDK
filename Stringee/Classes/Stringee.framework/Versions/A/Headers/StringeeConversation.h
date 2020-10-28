//
//  StringeeConversation.h
//  Stringee
//
//  Created by Hoang Duoc on 5/10/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeMessage.h"
#import "StringeeConversationOption.h"
#import "StringeeIdentity.h"

@class StringeeClient;

/**
 Lớp đại diện một group chat(đơn hoặc nhóm).
 */
@interface StringeeConversation : NSObject

/**
 Định danh Conversation là duy nhất trên hệ thống.
 */
@property (strong, nonatomic, readonly) NSString *identifier;

/**
 Cùng một thiết bị có thể có nhiều user connect đến Stringee server để tạo các cuộc trò chuyện. Trường này để định danh user mà conversation này thuộc về.
 */
@property (copy, nonatomic, readonly) NSString *userId;

/**
 Tên của conversation.
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 Cho biết conversation là dạng group hay không, nếu là dạng group thì mới có thể thêm thành viên.
 */
@property (assign, nonatomic, readonly) BOOL isGroup;

/**
 Tin nhắn cuối cùng của conversation này, sử dụng cho việc hiển thị.
 */
@property (strong, nonatomic, readonly) StringeeMessage *lastMsg;

/**
 Id của tin nhắn được pin
 */
@property (strong, nonatomic, readonly) NSString *pinMsgId;

/**
 Các thành viên của conversation này, có dạng 1 set các StringeeIdentity.
 */
@property (strong, nonatomic, readonly) NSSet *participants;

/**
 Sequence của tin nhắn cuối cùng của conversation.
 */
@property (assign, nonatomic, readonly) NSUInteger convLastSeq;

/**
 Sequence của tin nhắn cuối cùng của conversation mà user nhận được.
 */
@property (assign, nonatomic, readonly) NSUInteger lastMsgSeqReceived;

/**
 Sequence của tin nhắn cuối cùng của conversation mà user đã đọc.
 */
@property (assign, nonatomic, readonly) NSUInteger lastMsgSeqSeen;

/**
 Kiểu của tin nhắn cuối cùng.
 */
@property (assign, nonatomic, readonly) NSUInteger lastMsgType;

/**
 Mốc thời gian gần nhất conversation có tin nhắn mới.
 */
@property (assign, nonatomic, readonly) long long lastTimeNewMsg;

/**
 Mốc thời gian gần nhất conversation được cập nhất(có tin nhắn đến, thêm thành viên...)
 */
@property (assign, nonatomic, readonly) long long lastUpdate;

/**
 Số lượng tin nhắn chưa đọc của user trong conversation.
 */
@property (assign, nonatomic, readonly) NSUInteger unread;

/**
 User đã tạo conversation.
 */
@property (strong, nonatomic, readonly) NSString *creator;

/**
 Thời gian conversation được tạo.
 */
@property (assign, nonatomic, readonly) long long created;

@property (assign, nonatomic) StringeeChannel channelType;

/**
 Gửi tin nhắn
 @param message một thể hiện của StringeeMessage(StringeeTextMessage, StringeeLocationMessage, StringeeContactMessage...).
 @param error lỗi trả về nếu gửi thất bại.
 */
- (void)sendMessage:(StringeeMessage *)message error:(NSError **)error;

/**
 Gửi tin nhắn - Sử dụng cho react-native
 @param message một thể hiện của StringeeMessage(StringeeTextMessage, StringeeLocationMessage, StringeeContactMessage...).
 @param error lỗi trả về nếu gửi thất bại.
 */
- (void)sendMessageWithoutPretreatment:(StringeeMessage *)message error:(NSError **)error;

/**
 Xoá conversation này.
 CompletionHandler trả về kết quả.
 */
- (void)deleteWithCompletionHandler:(void(^)(BOOL status, int code, NSString * message))completionHandler;

/**
 Lấy về thông tin của các message của 1 conversation được lưu ở local.
 @param count số lượng message cần lấy.
 CompletionHandler trả về kết quả.
 */
- (void)getLocalMessagesWithCount:(NSUInteger)count completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeMessage *> *messages))completionHandler;

/**
 Lấy về thông tin của các message mới nhất của 1 conversation trên server.
 @param count số lượng message cần lấy.
 CompletionHandler trả về kết quả.
 */
- (void)getLastMessagesWithCount:(NSUInteger)count loadDeletedMessage:(BOOL)loadDeletedMessage loadDeletedMessageContent:(BOOL)loadDeletedMessageContent completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeMessage *> *messages))completionHandler;

- (void)getLastMessagesWithCount:(NSUInteger)count loadDeletedMessage:(BOOL)loadDeletedMessage loadDeletedMessageContent:(BOOL)loadDeletedMessageContent loadHistory:(BOOL)loadHistory completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeMessage *> *messages))completionHandler;

/**
 Lấy về thông tin của các message được gửi đến conversations trước một message nào đó. Ex: sử dụng khi người dùng thực hiện load more.
 @param index sequence của message mốc, sử dụng trường seq của Message.
 @param count số lượng message cần lấy.
 CompletionHandler trả về kết quả.
 */
- (void)getMessagesBefore:(NSUInteger)index withCount:(NSUInteger)count loadDeletedMessage:(BOOL)loadDeletedMessage loadDeletedMessageContent:(BOOL)loadDeletedMessageContent completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeMessage *> *messages))completionHandler;

- (void)getMessagesBefore:(NSUInteger)index withCount:(NSUInteger)count loadDeletedMessage:(BOOL)loadDeletedMessage loadDeletedMessageContent:(BOOL)loadDeletedMessageContent loadHistory:(BOOL)loadHistory completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeMessage *> *messages))completionHandler;

/**
 Lấy về thông tin của các message được gửi đến conversations sau một message nào đó. Ex: thực hiện khi load các message mới hơn.
 @param index sequence của message mốc, sử dụng trường seq của Message.
 @param count số lượng message cần lấy.
 CompletionHandler trả về kết quả.
 */
- (void)getMessagesAfter:(NSUInteger)index withCount:(NSUInteger)count loadDeletedMessage:(BOOL)loadDeletedMessage loadDeletedMessageContent:(BOOL)loadDeletedMessageContent completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeMessage *> *messages))completionHandler;

- (void)getMessagesAfter:(NSUInteger)index withCount:(NSUInteger)count loadDeletedMessage:(BOOL)loadDeletedMessage loadDeletedMessageContent:(BOOL)loadDeletedMessageContent loadHistory:(BOOL)loadHistory completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeMessage *> *messages))completionHandler;

/**
 Đánh dấu tất cả message của conversation như đã đọc.
 CompletionHandler trả về kết quả.
 */
- (void)markAllMessagesAsSeenWithCompletionHandler:(void(^)(BOOL status, int code, NSString * message))completionHandler;

/**
 Thêm thành viên đến conversation, chỉ có người tạo conversation mới có thể thao tác.
 @param parts mảng user cần thêm đến conversation.
 CompletionHandler trả về kết quả.
 */
- (void)addParticipants:(NSSet<StringeeIdentity *> *)parts completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeIdentity *> *addedUsers))completionHandler;

/**
 Xoá thành viên khỏi conversation , chỉ có người tạo conversation mới có thể thao tác.
 @param parts mảng user cần xoá khỏi conversation.
 CompletionHandler trả về kết quả.
 */
- (void)removeParticipants:(NSSet<StringeeIdentity *> *)parts completionHandler:(void(^)(BOOL status, int code, NSString * message, NSArray<StringeeIdentity *> *removedUsers))completionHandler;

/**
 Xoá các message với message's identifier
 @param messageIds mảng identifier của các message muốn xoá, sử dụng Message's identifier.
 CompletionHandler trả về kết quả.
 */
- (void)deleteMessageWithMessageIds:(NSArray *)messageIds withCompletionHandler:(void(^)(BOOL status, int code, NSString * message))completionHandler;

/**
 Cập nhật thông tin cho conversation
 @param name tên cần update cho conversation
 CompletionHandler trả về kết quả.
 */

- (void)updateWithName:(NSString *)name strAvatarUrl:(NSString *)strAvatarUrl completionHandler:(void(^)(BOOL status, int code, NSString * message))completionHandler;

- (void)getMessageWithId:(NSString *)msgId completion:(void(^)(BOOL status, int code, NSString *message, StringeeMessage *msg))completion;

- (void)pinMessage:(StringeeMessage *)msg isPin:(BOOL)isPin completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)editMessage:(StringeeMessage *)msg newContent:(NSString *)newContent completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)revokeMessage:(StringeeMessage *)msg deleted:(BOOL)deleted completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)setRole:(StringeeRole)role forPart:(StringeeIdentity *)part completion:(void(^)(BOOL status, int code, NSString *message))completion;

@end
