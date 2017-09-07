//
//  LELocationManager.h
//  LELocation framework
//
//  Created by Romain Quidet on 27/04/2014.
//  Copyright (c) 2017 xdappfactory. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The possible manager states.
 */
typedef NS_ENUM(NSUInteger, LELocationManagerState) {
    LELocationManagerStateUnknown = 0,
    LELocationManagerStateIdle,
    LELocationManagerStateSearchingForGPS,
    LELocationManagerStateUpdatingLocation
};

@protocol LELocationManagerDelegate;

/**
 'LELocationManager' is a class that mimic the official CoreLocation class
 by providing a source of GPS positions as CLLocation objects.
 The source of GPS positions is not the internal GPS (Wifi iPad do not have
 internal GPS for example) but a standard Bluetooth Smart (Low Energy) GPS
 transmitter. An example of such a transmitter is the app 'LE GPS' installed
 on in iPhone. 
 More information about the transmitters here: 
 http://www.xdappfactory.com/wp/?page_id=181
 */
@interface LELocationManager : NSObject

/**
 Use this singleton as entry point for LELocation framework.
 @return The Low Energy Location manager singleton. First call
 returns the singleton initialized, ready to use in idle state.
 */
+ (LELocationManager *)sharedManager;

/**
 Start the bluetooth GPS search and pairing process. Once done updates location
 by callbacks.
 GPS search will timeout after 10s if LE GPS transmitter is not found for battery
 saving.
 @see LELocationManagerDelegate
 */
- (void)startUpdatingLocation;

/**
 Stop updating location and disconnect the bluetooth GPS link.
 */
- (void)stopUpdatingLocation;

/**
 The last known location sent by the GPS.
 The value of this property is nil if no location data has ever been retrieved.
 */
@property(readonly, nonatomic) CLLocation *location;

/**
 The delegate will receive callback messages from the LELocationManagerDelegate protocol.
 */
@property(weak, nonatomic) id<LELocationManagerDelegate> delegate;

/**
 Describes the current manager state
 */
@property (readonly) LELocationManagerState state;

/**
 Try to perform a wider BT scan for non standard devices like the GL-770 GPS
 GPS search will timeout after 20s
 NO by default.
 */
@property (nonatomic, assign) BOOL wideScan;

/**
 The current version of the framework as @"1.0"
 */
@property (readonly) NSString *version;

@end

NS_ASSUME_NONNULL_END
