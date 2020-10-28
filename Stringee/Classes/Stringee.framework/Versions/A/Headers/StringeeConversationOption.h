//
//  StringeeConversationOption.h
//  Stringee
//
//  Created by Hoang Duoc on 5/10/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Sử dụng để thêm tuỳ chọn khi tạo conversation.
 */
@interface StringeeConversationOption : NSObject

/**
 Cho biết khi tạo conversation thì có nên tạo conversation mới hay không với một tập hợp user mà đã có conversation.
 Nếu YES thì nếu đã có conversation của các user đang muốn tạo thì hệ thống sẽ trả về conversation đó chứ không tạo mới.
 Nếu NO thì hệ thống sẽ tạo một conversation mới mặc dù conversation giữa các user này đã được tạo.
 */
@property (assign, nonatomic) BOOL distinctByParticipants;

/**
 Cho biết conversation được tạo sẽ là kiểu group hay không, kiểu group thì mới có thể thêm thành, xoá thành viên.
 isGroup = YES nếu là kiểu group và ngược lại.
 */
@property (assign, nonatomic) BOOL isGroup;

@end
