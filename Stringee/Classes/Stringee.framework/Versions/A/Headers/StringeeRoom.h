//
//  StringeeRoom.h
//  Stringee
//
//  Created by Hoang Duoc on 10/19/17.
//  Copyright © 2017 Hoang Duoc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StringeeClient.h"
#import "StringeeRoomStream.h"
#import "ECRoom.h"

@class StringeeClient;

@protocol StringeeRoomDelegate <NSObject>

@required

-(void) didRoomConnect:(StringeeRoom *) stringeeRoom streams:(NSArray<StringeeRoomStream *>*) streams;

-(void) didRoomDisConnect:(StringeeRoom *) stringeeRoom;

-(void) didRoomError:(StringeeRoom *) stringeeRoom code:(int) code message:(NSString *) message;



-(void) didStreamAdd:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream;

-(void) didStreamRemove:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream;




-(void) didStreamSubscribe:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream;
-(void) didStreamSubscribeError:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream error:(NSString *) error;



-(void) didStreamPublish:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream;
-(void) didStreamPublishError:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream error:(NSString *) error;



-(void) didStreamUnPublish:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream;
-(void) didStreamUnPublishError:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream error:(NSString *) error;



-(void) didStreamUnSubscribe:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream;
-(void) didStreamUnSubscribeError:(StringeeRoom *) stringeeRoom stream:(StringeeRoomStream *) stream error:(NSString *) error;

@end


@interface StringeeRoom : NSObject<ECRoomDelegate>


// MARK: - Variable
@property(weak, nonatomic) StringeeClient * stringeeClient;

@property(weak, nonatomic) id<StringeeRoomDelegate> roomDelegate;


@property(strong, nonatomic) ECRoom * room;
@property(assign, nonatomic) long long roomId;
@property(assign, nonatomic) int stringeeRoomId;
@property(strong, nonatomic) NSString * roomToken;

@property (nonatomic, strong) completion makeRoomHandler;
@property (nonatomic, strong) completion joinRoomHandler;

@property (nonatomic, strong) StringeeRoomStream * localStream;
@property (nonatomic, strong) NSMutableDictionary * remoteStreams;
@property (nonatomic, strong) NSMutableDictionary * currentStreamInRooms;

// Check reconnect
@property(assign, nonatomic) BOOL hasConnectToRoom;
@property(assign, nonatomic) BOOL hasPublishLocal;
@property(assign, nonatomic) BOOL isReconnecting;



// MARK: - Init
-(instancetype) initWithStringeeClient:(StringeeClient *) stringeeClient;


// MARK: - Public method
-(void) makeRoomWithCompletionHandler:(completion)completionHandler;

-(void) joinRoomWithRoomId:(long long) roomId completionHandler:(completion)completionHandler;

-(void) subscribe:(StringeeRoomStream *) stream;

-(void) unSubscribe:(StringeeRoomStream *) stream;

-(void) publish:(StringeeRoomStream *) stream;

-(void) unPublish:(StringeeRoomStream *) stream;

-(void) destroy;

-(void) statsReportForStream:(StringeeRoomStream *) stream useVideoTrack:(BOOL) useVideoTrack withCompletionHandler: (nullable void (^)( NSDictionary<NSString *, NSString *> *stats ))completionHandler;

// MARK: - Private method
-(void) connectToRoom;

@end
