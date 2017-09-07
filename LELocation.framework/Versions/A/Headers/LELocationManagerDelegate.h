//
//  LELocationManagerDelegate.h
//  LELocation framework
//
//  Created by Romain Quidet on 28/06/2014.
//  Copyright (c) 2017 xdappfactory. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LELocationManager.h"

/**
 The manager error types returned by the callback
 */
typedef NS_ENUM(NSUInteger, LELocationManagerError) {
    LELocationManagerErrorNone = 0,
    LELocationManagerErrorBluetoothOff,
    LELocationManagerErrorBluetoothUnauthorized,
    LELocationManagerErrorGPSNotFound,
    LELocationManagerErrorGPSConnectionFailed,
    LELocationManagerErrorGPSDidDisconnect
};

NS_ASSUME_NONNULL_BEGIN

@protocol LELocationManagerDelegate <NSObject>

@optional
/**
 Invoked when new locations are available.
 @param manager The LELocationManager caller
 @param locations An array of CLLocation objects in chronological order.
 */
- (void)locationManager:(LELocationManager *)manager
	 didUpdateLocations:(NSArray *)locations __OSX_AVAILABLE_STARTING(__MAC_10_10,__IPHONE_7_0);

/**
 Invoked when an error has occurred.
 @param manager The LELocationManager caller
 @param error The LELocationManagerError error
 */
- (void)locationManager:(LELocationManager *)manager
       didFailWithError:(LELocationManagerError)error;

@end

NS_ASSUME_NONNULL_END
