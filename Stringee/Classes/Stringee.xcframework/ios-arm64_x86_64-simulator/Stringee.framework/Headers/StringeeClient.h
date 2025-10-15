//
//  StringeeClient.h
//  Stringee
//
//  Created by Hoang Duoc on 10/11/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeConversation.h"
#import "StringeeChatProfile.h"
#import "StringeeChatRequest.h"
#import "StringeeServerAddress.h"

@class StringeeClient;
@class StringeeCall;
@class StringeeRoom;
@class StringeeCall2;

/**
 Notification Name
 */

// StringeeClient đã kết nối tới Server
extern NSString * const StringeeClientDidConnectNotification;

// StringeeClient đã mất kết nối tới Server
extern NSString * const StringeeClientDidDisconnectNotification;

// StringeeClient kết nối thất bại tới Server.
extern NSString * const StringeeClientDidFailNotification;

// Sự kiện Object(conversation, message) thay đổi.
extern NSString * const StringeeClientObjectsDidChangeNotification;

// Có tin nhắn đến.
extern NSString * const StringeeClientNewMessageNotification;


/**
 Notification Key để lấy thông tin
 */

// Lấy thông tin của changedObjects
extern NSString * const StringeeClientObjectChangesUserInfoKey;

// Lấy các thông tin của tin nhắn đến.
extern NSString * const StringeeClientNewMessageConversationIDKey;
extern NSString * const StringeeClientNewMessageConversationNameKey;
extern NSString * const StringeeClientNewMessageSenderUserIdKey;
extern NSString * const StringeeClientNewMessageSenderAvatarUrlKey;
extern NSString * const StringeeClientNewMessageSenderDisplayNameKey;
extern NSString * const StringeeClientNewMessageContentKey;
extern NSString * const StringeeClientNewMessageTypeKey;
extern NSString * const StringeeClientNewMessageSeqKey;

extern NSString * const StringeeChatUserTypingNotification;

@protocol StringeeConnectionDelegate <NSObject>

@required

- (void)requestAccessToken:(StringeeClient *)stringeeClient;

- (void)didConnect:(StringeeClient *)stringeeClient isReconnecting:(BOOL)isReconnecting;

- (void)didDisConnect:(StringeeClient *)stringeeClient isReconnecting:(BOOL)isReconnecting;

- (void)didFailWithError:(StringeeClient *)stringeeClient code:(int)code message:(NSString *)message;

@optional

- (void)didReceiveCustomMessage:(StringeeClient *)stringeeClient message:(NSDictionary *)message fromUserId:(NSString *)userId;

- (void)didReceiveMessageFromTopic:(StringeeClient *)stringeeClient message:(NSDictionary *)message fromUserId:(NSString *)userId;

- (void)didReceiveChatRequest:(StringeeClient *)stringeeClient request:(StringeeChatRequest *)request;

- (void)didReceiveTransferChatRequest:(StringeeClient *)stringeeClient request:(StringeeChatRequest *)request;

- (void)timeoutAnswerChat:(StringeeClient *)stringeeClient request:(StringeeChatRequest *)request;

- (void)timeoutInQueue:(StringeeClient *)stringeeClient info:(NSDictionary *)info;

- (void)conversationEnded:(StringeeClient *)stringeeClient info:(NSDictionary *)info;

@end


@protocol StringeeIncomingCallDelegate <NSObject>

@required

-(void) incomingCallWithStringeeClient:(StringeeClient *)stringeeClient stringeeCall:(StringeeCall *)stringeeCall;

@optional

- (void)incomingCallWithStringeeClient:(StringeeClient *)stringeeClient stringeeCall2:(StringeeCall2 *)stringeeCall2;

@end



@interface StringeeClient : NSObject

@property (weak, nonatomic) id<StringeeConnectionDelegate> connectionDelegate;
@property (weak, nonatomic) id<StringeeIncomingCallDelegate> incomingCallDelegate;
@property (assign, nonatomic, readonly) BOOL hasConnected;
@property (copy, nonatomic, readonly) NSString *userId;
@property (strong, nonatomic, readonly) NSString *projectId;

- (instancetype)initWithConnectionDelegate:(id<StringeeConnectionDelegate>)delegate;

- (instancetype)initWithConnectionDelegate:(id<StringeeConnectionDelegate>)delegate serverAddress:(NSArray<StringeeServerAddress *> *)serverAddresses;

- (instancetype)initWithServerAddress:(NSArray<StringeeServerAddress *> *)serverAddresses;

- (void)setServerAddress:(NSArray<StringeeServerAddress *> *)serverAddresses;

- (void)enableSSLPinningWithCerts:(NSArray<NSString *> *)certs;
- (void)enableSSLPinningWithCerts:(NSArray<NSString *> *)certs bundle:(NSBundle *)bundle;
- (void)enableSSLPinningWithPublicKeys:(NSArray<NSString *> *)publicKeys;

- (void)connectWithAccessToken:(NSString *)accessToken;

- (void)registerPushForDeviceToken:(NSString *)deviceToken isProduction:(BOOL)isProduction isVoip:(BOOL)isVoip completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)registerPushForDeviceToken:(NSString *)deviceToken isProduction:(BOOL)isProduction isVoip:(BOOL)isVoip deleteOthers:(BOOL)deleteOthers packageNames:(NSArray<NSString *> *)packageNames completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)unregisterPushForDeviceToken:(NSString *)deviceToken completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)existIncomingCallWithCallId:(NSString *)callId completion:(void(^)(BOOL status, int code, NSString *message, BOOL exist))completion;

- (void)existCall:(NSString *)callId completion:(void(^)(BOOL status, int code, NSString *message, BOOL exist))completion;

- (void)sendCustomMessage:(NSDictionary *)message toUserId:(NSString *)userId completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)setRestBaseUrl:(NSString *)baseUrl completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

- (void)setStringeeXBaseUrl:(NSString *)baseUrl completionHandler:(void(^)(BOOL status, int code, NSString *message))completionHandler;

/**
 Tạo một conversation.
 @param name tên conversation.
 @param participants danh sách các thành viên. Chú ý: không cần bao gồm chính user đang tạo conversation trong danh sách, user này sẽ được tự động thêm vào.
 @param options: các lựa chọn khi tạo conversations, Xem StringeeConversationOption.
 CompletionHandler trả về kết quả.
 */
- (void)createConversationWithName:(NSString *)name participants:(NSSet<StringeeIdentity *> *)participants options:(StringeeConversationOption *)options completionHandler:(void(^)(BOOL status, int code, NSString *message, StringeeConversation *conversation))completionHandler;

/**
 Lấy về thông tin của 1 conversation.
 @param convId identifier của conversation.
 Trả về conversation cần lấy hoặc nil nếu thất bại.
 */
- (void)getConversationWithConversationId:(NSString *)convId completionHandler:(void(^)(BOOL status, int code, NSString *message, StringeeConversation *conversation))completionHandler;

/**
 Lấy thông tin các conversation được lưu ở local database.
 @param count số lượng conversation muốn lấy.
 @param userId lấy các conversation thuộc về user này.
 Trả về conversations hoặc nil nếu thất bại.
 */
- (void)getLocalConversationsWithCount:(NSUInteger)count userId:(NSString *)userId completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getLocalConversationsWithCount:(NSUInteger)count userId:(NSString *)userId oaId:(NSString *)oaId completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;


/**
 Lấy thông tin các conversation mà được update mới nhất trên server(Ex: có tin nhắn đến, thêm thành viên...). Trong đó:
 @param count số lượng conversation muốn lấy.
 Trả về conversations hoặc nil nếu thất bại.
 */
- (void)getLastConversationsWithCount:(NSUInteger)count completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getLastConversationsWithCount:(NSUInteger)count loadAllConversations:(BOOL)loadAllConversations completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getLastConversationsWithCount:(NSUInteger)count oaId:(NSString *)oaId completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getLastConversationsWithCount:(NSUInteger)count loadAllConversations:(BOOL)loadAllConversations oaId:(NSString *)oaId completionHandler:(void(^)(BOOL status, int code, NSString *message,
                                                                                                                                   NSArray<StringeeConversation *> *conversations))completionHandler;
/**
 Lấy thông tin các conversation mà được update sau một mốc thời gian, dùng để lấy về các conversation mới được update.
 @param datetime mốc thời gian, sử dụng trường lastUpdate của Conversation.
 @param count số lượng conversation muốn lấy.
 Trả về conversations hoặc nil nếu thất bại.
 */
- (void)getConversationsAfter:(long long)datetime withCount:(NSUInteger)count completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getConversationsAfter:(long long)datetime withCount:(NSUInteger)count loadAllConversations:(BOOL)loadAllConversations completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getConversationsAfter:(long long)datetime withCount:(NSUInteger)count oaId:(NSString *)oaId completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getConversationsAfter:(long long)datetime withCount:(NSUInteger)count loadAllConversations:(BOOL)loadAllConversations oaId:(NSString *)oaId completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

/**
 Lấy thông tin các conversation mà được update trước một mốc thời gian. Ex: lấy về các conversation khi người dùng loadmore.
 @param datetime mốc thời gian, sử dụng trường lastUpdate của Conversation.
 @param count số lượng conversation muốn lấy.
 Trả về conversations hoặc nil nếu thất bại.
 */
- (void)getConversationsBefore:(long long)datetime withCount:(NSUInteger)count completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getConversationsBefore:(long long)datetime withCount:(NSUInteger)count loadAllConversations:(BOOL)loadAllConversations completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getConversationsBefore:(long long)datetime withCount:(NSUInteger)count oaId:(NSString *)oaId completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getConversationsBefore:(long long)datetime withCount:(NSUInteger)count loadAllConversations:(BOOL)loadAllConversations oaId:(NSString *)oaId completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;


- (void)getConversationForUsers:(NSSet<StringeeIdentity *> *)users completionHandler:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completionHandler;

- (void)getUnreadConversationCountWithCompletionHandler:(void(^)(BOOL status, int code, NSString *message, int count))completionHandler;

- (void)getLastUnreadConversationsWithCount:(NSUInteger)count completion:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completion;

- (void)getUnreadConversationsAfter:(long long)datetime withCount:(NSUInteger)count completion:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completion;

- (void)getUnreadConversationsBefore:(long long)datetime withCount:(NSUInteger)count completion:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeConversation *> *conversations))completion;

- (void)joinOAConversationWithConvId:(NSString *)convId completion:(void(^)(BOOL status, int code, NSString *message))completion;

/**
 Xoá dữ liệu chat của user ở local. Cần thực hiện trước khi connect tới stringee server với user mới.
 */
- (void)clearData;

- (void)disconnect;

- (void)getChatProfileWithKey:(NSString *)key completion:(void(^)(BOOL status, int code, NSString *message, StringeeChatProfile *chatProfile))completion;

- (void)generateTokenForCustomerWithKey:(NSString *)key username:(NSString *)username email:(NSString *)email completion:(void(^)(BOOL status, int code, NSString *message, NSString *token))completion;

- (void)createLiveChatConversationWithQueueId:(NSString *)queueId completion:(void(^)(BOOL status, int code, NSString *message, StringeeConversation *conversation))completion;

- (void)createTicketForMissChatWithKey:(NSString *)key username:(NSString *)username email:(NSString *)email note:(NSString *)note completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)createTicketForMissChatWithKey:(NSString *)key username:(NSString *)username email:(NSString *)email phone:(NSString *)phone note:(NSString *)note completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)updateUserInfoWithUsername:(NSString *)username email:(NSString *)email avatar:(NSString *)avatar completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)updateUserInfoWithUsername:(NSString *)username email:(NSString *)email avatar:(NSString *)avatar phone:(NSString *)phone completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)updateUserInfo:(StringeeIdentity *)userInfo completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)getUserInfosByUserIds:(NSArray<NSString *> *)userIds completion:(void(^)(BOOL status, int code, NSString *message, NSArray<StringeeIdentity *> *users))completion;

- (void)sendChatTranscriptTo:(NSString *)email convId:(NSString *)convId domain:(NSString *)domain completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (void)endChatSupportWithConvId:(NSString *)convId completion:(void(^)(BOOL status, int code, NSString *message))completion;

- (StringeeChatRequest *)getChatRequestWithConvId:(NSString *)convId;

@end
