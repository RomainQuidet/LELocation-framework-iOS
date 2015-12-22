LELocation-framework-iOS
========================

Bluetooth 4.0 LE framework for easy integration of Location and
Navigation Service stream reception. Get standard CoreLocation data
in your app.

1 - Summary
-----------

On one hand, you need a GPS aware device like an iPhone. On the other hand 
you have a device which needs GPS ccordinates but does not have any GPS 
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
*	min iOS on device: 7.0
*	min iOS SDK on Xcode: 7.0

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

4 - Framework usage
-------------------

Once the framework added, you can start using it.
Import the files "LELocationManager.h" to get access to the API.
You'll have access to the LELocationManager singleton. It will handle the Bluetooth
stuff for you. 
You basically just need to call the startUpdatingLocation and stopUpdatingLocation
methods start and stop getting location.
A delegate protocol is available with "LELocationManagerDelegate.h" to get callbacks
once a location data is available.

Enjoy !!

Romain