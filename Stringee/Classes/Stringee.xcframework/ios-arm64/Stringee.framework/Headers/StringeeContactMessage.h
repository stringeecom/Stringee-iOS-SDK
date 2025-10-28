//
//  StringeeContactMessage.h
//  Stringee
//
//  Created by HoangDuoc on 10/2/18.
//  Copyright © 2018 Hoang Duoc. All rights reserved.
//

#import "StringeeMessage.h"
#import <Contacts/Contacts.h>
#import <AddressBook/AddressBook.h>

/**
 Đại diện một message kiểu contact, được sử dụng để chia sẻ thông tin liên hẹ
 */
@interface StringeeContactMessage : StringeeMessage

/**
 Thông tin contact được mô tả dưới dạng CNContact object, có sẵn nếu iOS >= 9.0
 */
@property (nonatomic, readonly) CNContact *cnContact;

/**
 Thông tin contact được mô tả dưới dạng ABRecordRef object, có sẵn nếu iOS < 9.0
 */
@property (nonatomic, readonly) ABRecordRef abRecordRef;

/**
 Cho biết tên đầy đủ của liên hệ, sử dụng để hiển thị.
 */
@property (nonatomic, readonly) NSString *fullname;

/**
 Cho biết ảnh đại diện liên hệ nếu có, sử dụng để hiển thị.
 */
@property (nonatomic, readonly) UIImage *contactImage;

/**
 Các thông tin của liên hệ được trả về dưới dạng mảng(phones, emails), mỗi object là một Dictionary lưu trữ thông tin(phones, emails) dưới dạng key/value.
 */
@property (nonatomic, readonly) NSArray *infos;

@property (nonatomic, strong, readonly) NSString *vcard;

/**
 Hàm khởi tạo.
 @param contact thông tin liên hệ dạng CNContact object.
 @param metadata là dữ liệu bất kì gắn kèm với message này, có thể sử dụng để tuỳ biến thêm.
 @return 1 thể hiện của StringeeContactMessage.
 */
- (instancetype)initWithCNContact:(CNContact *)contact metadata:(NSDictionary *)metadata;

/**
 Hàm khởi tạo.
 @param abRecordRef thông tin liên hệ dạng ABRecordRef object.
 @param metadata là dữ liệu bất kì gắn kèm với message này, có thể sử dụng để tuỳ biến thêm.
 @return 1 thể hiện của StringeeContactMessage.
 */
- (instancetype)initWithABRecordRef:(ABRecordRef)abRecordRef metadata:(NSDictionary *)metadata;

// Sử dụng cho react-native
- (instancetype)initWithVcard:(NSString *)vcard metadata:(NSDictionary *)metadata;

@end
