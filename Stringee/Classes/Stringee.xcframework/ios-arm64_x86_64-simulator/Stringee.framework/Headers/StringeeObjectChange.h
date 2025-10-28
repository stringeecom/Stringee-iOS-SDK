//
//  StringeeObjectChange.h
//  Stringee
//
//  Created by Hoang Duoc on 5/24/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, StringeeObjectChangeType) {
    // Object đã đã được tạo.
    StringeeObjectChangeTypeCreate,
    
    // Object đã được cập nhật.
    StringeeObjectChangeTypeUpdate,
    
    // Object đã bị xoá.
    StringeeObjectChangeTypeDelete
};

/**
 Đại diện cho sự thay đổi của một object.
 */
@interface StringeeObjectChange : NSObject

/**
 object mà có sự thay đổi.
 */
@property (nonatomic, readonly) id object;

/**
 Kiểu mà object thay đổi.
 */
@property (nonatomic, readonly) StringeeObjectChangeType type;

@end
