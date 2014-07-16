//
//  LELocationManager.h
//  LELocation framework
//
//  Created by Romain Quidet on 27/04/2014.
//  Copyright (c) 2014 xdappfactory. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>

/*
 *  LELocationManagerState
 *
 *  Discussion:
 *      Represents the current state of the manager.
 *
 */
typedef NS_ENUM(NSUInteger, LELocationManagerState) {
    LELocationManagerStateUnknown = 0,
    LELocationManagerStateIdle,
    LELocationManagerStateSearchingForGPS,
    LELocationManagerStateUpdatingLocation
};

@protocol LELocationManagerDelegate;
@interface LELocationManager : NSObject

/*
 *  sharedManager
 *
 *  Discussion:
 *      Returns the Low Energy Location manager singleton
 */
+ (LELocationManager *)sharedManager;

/*
 *  startUpdatingLocation
 *
 *  Discussion:
 *      Start bluetooth connection with the GPS and once done updates location.
 */
- (void)startUpdatingLocation;

/*
 *  stopUpdatingLocation
 *
 *  Discussion:
 *      Stop updating location and disconnect bluetooth links.
 */
- (void)stopUpdatingLocation;

/*
 * location
 *
 * Discussion:
 *      The value of this property is nil if no location data has ever been retrieved.
 */
@property(readonly, nonatomic) CLLocation *location;

/*
 * delegate
 *
 * Discussion:
 *      The delegate will receive callback messages from the LELocationManagerDelegate protocol
 */
@property(weak, nonatomic) id<LELocationManagerDelegate> delegate;

/*
 * state
 *
 * Discussion:
 *      Describes the current manager state
 */
@property (readonly) LELocationManagerState state;

/*
 * version
 *
 * Discussion:
 *      Returns the current version of the framework as @"1.0"
 */
@property (readonly) NSString *version;

@end
