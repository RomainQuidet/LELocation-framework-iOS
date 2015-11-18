//
//  LELocationManagerDelegate.h
//  LELocation framework
//
//  Created by Romain Quidet on 28/06/2014.
//  Copyright (c) 2014 xdappfactory. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LELocationManager.h"

typedef NS_ENUM(NSUInteger, LELocationManagerError) {
    LELocationManagerErrorNone = 0,
    LELocationManagerErrorBluetoothOff,
    LELocationManagerErrorBluetoothUnauthorized,
    LELocationManagerErrorGPSNotFound,
    LELocationManagerErrorGPSConnectionFailed,
    LELocationManagerErrorGPSDidDisconnect
};

@protocol LELocationManagerDelegate <NSObject>

@optional
/*
 *  locationManager:didUpdateLocations:
 *
 *  Discussion:
 *    Invoked when new locations are available.  Required for delivery of
 *    deferred locations.  If implemented, updates will
 *    not be delivered to locationManager:didUpdateToLocation:fromLocation:
 *
 *    locations is an array of CLLocation objects in chronological order.
 */
- (void)locationManager:(LELocationManager *)manager
	 didUpdateLocations:(NSArray *)locations __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/*
 *  locationManager:didFailWithError:
 *
 *  Discussion:
 *    Invoked when an error has occurred.
 */
- (void)locationManager:(LELocationManager *)manager
       didFailWithError:(LELocationManagerError)error;

@end
