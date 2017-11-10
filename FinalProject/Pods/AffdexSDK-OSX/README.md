![Affectiva Logo](http://developer.affectiva.com/images/logo.png)

##Affdex SDK for macOS v3.2.0

####Copyright (c) 2017 Affectiva Inc.<br/>See our [SDK License Agreement](http://developer.affectiva.com/sdklicense) for copying permission.

Welcome to the Affdex SDK for macOS.

We are surrounded by highly-connected smart devices, interactive digital experiences and artificial intelligence. Yet, technology is not able to sense, analyze and adapt to human emotions. At Affectiva, we have made it our mission to bring emotional intelligence to the digital world. To make this mission a reality, we have created the Affdex SDK so that others can bring emotion sensing and analytics to their own offerings, be it digital experiences, apps, games, devices, or other technologies.

Using our SDK, developers can now enrich digital experiences and apps by detecting emotion. Devices can now instantly respond to a user’s unfiltered emotions, and apps can adjust their interfaces and flow to better suit moods. This makes for a more authentic, interactive, and unique experience.

For developer documentation, sample code, and other information, please visit our website:
http://developer.affectiva.com

The SDK License Agreement is available at:
http://developer.affectiva.com/sdklicense

## Getting started

__The Affdex SDK for macOS is distributed as a [CocoaPod](https://cocoapods.org/pods/AffdexSDK-OSX). If you do not have CocoaPods installed on your Mac, please install it using the instructions in the [CocoaPods Getting Started Guide](https://guides.cocoapods.org/using/getting-started.html).__

#### 1. Create a Podfile

After you have installed CocoaPods on your Mac, create a file named "Podfile" in your project directory.  This is the directory which contains the .xcodeproj and/or .xcworkspace files for your project.  The Podfile is a plain-text file which describes the framework and library dependencies that your project contains.  Installing the pod file will load and configure the Affdex SDK framework for use with your project.

Place the following text into your Podfile, substituting your app name for the 'MyApp' target:

```
source 'https://github.com/CocoaPods/Specs.git'
use_frameworks!

target 'MyApp' do
    pod 'AffdexSDK-OSX'
end
```

#### 2. Install the Affdex SDK CocoaPod

With the Podfile created, run the following commands from the Terminal application:

```
pod repo update
pod install
```

This will install the SDK and support pods into the Pods folder, and will create or update the Xcode workspace file to support building from the pods.  Make sure to open the .xcworkspace file in Xcode instead of the .xcodeproj file from this point onwards.  You can now build and run the project on your Mac from Xcode.

After you run `pod install` your app will be linked to the most recent release of the Affdex SDK, although you can also configure your Podfile to install a specific version of the SDK if you choose.  Your project will continue to use this version even if newer versions of the SDK are released.  Use the `pod update` command to update to newer SDK releases as they become available.
