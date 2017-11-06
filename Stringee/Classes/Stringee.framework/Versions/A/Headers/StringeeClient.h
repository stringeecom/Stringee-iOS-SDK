//
//  StringeeClient.h
//  Stringee
//
//  Created by Hoang Duoc on 10/11/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TcpClient.h"
#import "StringeeNetworkHandler.h"
//#import "StringeeCall.h"

@class StringeeClient;
@class StringeeCall;
@class StringeeRoom;

typedef void(^completion)(BOOL status, int code, NSString * message);

@protocol StringeeConnectionDelegate <NSObject>

@required

-(void) requestAccessToken: (StringeeClient *) stringeeClient;

-(void) didConnect:(StringeeClient *) stringeeClient isReconnecting:(BOOL) isReconnecting;

-(void) didDisConnect:(StringeeClient *) stringeeClient isReconnecting:(BOOL) isReconnecting;

-(void) didFailWithError:(StringeeClient *) stringeeClient code:(int) code message:(NSString *) message;

@end


@protocol StringeeIncomingCallDelegate <NSObject>

@required

-(void) incomingCallWithStringeeClient:(StringeeClient *) stringeeClient isVideoCall:(BOOL) isVideoCall callId:(NSString *) callId from:(NSString *) from to:(NSString *) to fromAlias:(NSString *) fromAlias toAlias:(NSString *) toAlias;

@end



@interface StringeeClient : NSObject

@property(weak, nonatomic) id<StringeeConnectionDelegate> connectionDelegate;
@property(weak, nonatomic) id<StringeeIncomingCallDelegate> incomingCallDelegate;

@property(strong, nonatomic) TcpClient * tcpClient;
@property(strong, nonatomic) NSString * host;
@property(assign, nonatomic) int port;
@property(strong, nonatomic) StringeeNetworkHandler * handler;
@property(assign, nonatomic) BOOL hasConnected;
@property(strong, nonatomic) NSString * accessToken;
@property(assign, nonatomic) long long connectionId;
@property(strong, nonatomic) NSString * userId;
@property(assign, nonatomic) BOOL isReconnecting;

@property(strong, nonatomic) NSMutableArray<StringeeCall *> * calls;
@property(strong, nonatomic) NSMutableArray<StringeeRoom *> * rooms;
@property(strong, nonatomic) NSMutableDictionary * incomingCallDatas;


//-(NSString *) getNewAccessToken;

-(instancetype) initWithConnectionDelegate:(id<StringeeConnectionDelegate>) delegate;
-(void) connectWithAccessToken:(NSString *) accessToken;


-(void) checkConnectionOfTCPClient:(TcpClient *) tcpClient;

-(void) clientDisConnect;

@end
