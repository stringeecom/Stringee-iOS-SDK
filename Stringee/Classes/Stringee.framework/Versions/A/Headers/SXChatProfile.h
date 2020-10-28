//
//  SXChatProfile.h
//  Stringee
//
//  Created by HoangDuoc on 2/27/20.
//  Copyright © 2020 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SXQueue.h"

NS_ASSUME_NONNULL_BEGIN

@interface SXChatProfile : NSObject

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, assign, readonly) BOOL auto_create_ticket;
@property (nonatomic, readonly) NSString *background;
@property (nonatomic, assign, readonly) BOOL enabled;
@property (nonatomic, assign, readonly) BOOL facebook_as_livechat;
@property (nonatomic, readonly) NSString *hour;
@property (nonatomic, readonly) NSString *language;
@property (nonatomic, readonly) NSString *logo_url;
@property (nonatomic, readonly) NSString *popup_answer_url;
@property (nonatomic, readonly) NSString *portal;
@property (nonatomic, assign, readonly) int project_id;
@property (nonatomic, assign, readonly) BOOL zalo_as_livechat;
@property (nonatomic, strong, readonly) NSArray<SXQueue *> *queues;

- (instancetype)initWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
