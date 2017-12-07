LELocation-framework-iOS
========================

Bluetooth 4.0 LE framework for easy integration of Location and
Navigation Service stream reception. Get standard CoreLocation data
in your app.

1 - Summary
-----------

On one hand, you need a GPS aware device like an iPhone. On the other hand 
you have a device which needs GPS coordinates but does not have any GPS 
embedded, like an iPad.

Bluetooth Consortium offers a standard interface to share location data over 
bluetooth 4.0 (Location and Navigation Service, LNS). It is designed to be 
very efficent regarding power usage (so called Low Energy, LE). But 
CoreBluetooth on iOS can be difficult to handle.

This framework simplifies the developpers work for reading GPS stream by 
abstracting the bluetooth work behind a standard API using CoreLocation 
data on iOS.

2 - GPS transmitter
---------------

Before receiving GPS data you'll need a GPS location streamer. I 
designed an app for this purpose.  
It's called **LE GPS**, available here: 
*	iOS - [App Store](http://appstore.com/legps)
*	Android - coming soon

Other devices can be used to stream location data over BT4.0, such
as Arduino or Rapsberry Pi embedded systems.

3 - Framework integration
-------------------------

Now that you have a GPS data streamer, you'll need to include this framework on
you iOS app to receive the data.

You can get LELocation framework as a Pod from CocoaPods or install it manually:

Versions requirements:  
*	min iOS on device: 8.0
*	min iOS SDK on Xcode: 8.0

Just download this framework, copy it on your project repository.
Once done, drag and drop this framework over your Xcode interface Frameworks.
Or click on File, add existing file and select the framework.

Check it is added to frameworks linked to your project:
Select your target, go to general tab and check 'linked Frameworks and libraries'. If
LELocation is not there, click on + to add it.

Other mandatory frameworks:
You'll need to link your project with standard framework:  
*	CoreLocation
*	CoreBluetooth

>Please note that this framework will only work on Bluetooth 4.0 capable devices. You can 
still use it on devices without Bluetooth 4.0 capabilities (like iPad 2), it will only
fail trying to start GPS pairing.

4 - Framework usage
-------------------

Once the framework added to your project, using it is very simple.

Import the file "LELocationManager.h" to get access to the API.

You'll have access to the LELocationManager singleton. It will handle the Bluetooth
stuff for you. 

### Getting locations

You basically just need to set a delegate object and then call the startUpdatingLocation 
method:

```
// start pairing with LE GPS and get locations
[LELocationManager sharedManager].delegate = self;
[[LELocationManager sharedManager] startUpdatingLocation];
```
The startUpdatingLocation method will check the Bluetooth state, start LE GPS scan and
pairing, then handle the stream to create standard CoreLocation locations.

The delegate protocol is available with "LELocationManagerDelegate.h" to get callbacks
for locations data and error handling.

If the GPS is not found after 6 seconds, the manager will go back to idle state.

### Getting manager state

Check the manager state property when you need to know the current state, if the
manager is idle, searching for the GPS or paired and streaming locations.

### Stopping 

Call the stopUpdatingLocation method to close the bluetooth stream and stop getting
locations.

```
// stop getting locations
[[LELocationManager sharedManager] stopUpdatingLocation];
```

>The Bluetooth on iOS has to be turned on by the user, it's not possible to toggle 
the power programmatically. A typical callback error is LELocationManagerErrorBluetoothOff.
You need to ask the user to turn on Bluetooth.

Enjoy !!


Romain