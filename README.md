# Stringee

[![CI Status](http://img.shields.io/travis/duochv@stringee.com/Stringee.svg?style=flat)](https://travis-ci.org/duochv@stringee.com/Stringee)
[![Version](https://img.shields.io/cocoapods/v/Stringee.svg?style=flat)](http://cocoapods.org/pods/Stringee)
[![License](https://img.shields.io/cocoapods/l/Stringee.svg?style=flat)](http://cocoapods.org/pods/Stringee)
[![Platform](https://img.shields.io/cocoapods/p/Stringee.svg?style=flat)](http://cocoapods.org/pods/Stringee)

## Installation

Current version: `2.2.0` (iOS 15.0+, WebRTC `137.0.0` via the `WebRTC-lib` pod).

Stringee is available through [CocoaPods](http://cocoapods.org). Add the following line to your Podfile:

```ruby
pod 'Stringee', '2.2.0'
```

Until `2.2.0` is available on CocoaPods trunk, point to the podspec of the tag:

```ruby
pod 'Stringee', :podspec => 'https://raw.githubusercontent.com/stringeecom/Stringee-iOS-SDK/2.2.0/Stringee.podspec'
```

The pod uses the same `Stringee.xcframework.zip` and the same WebRTC build as the Swift Package
[Stringee-iOS-SDK-SPM](https://github.com/stringeecom/Stringee-iOS-SDK-SPM), so both channels ship one binary per version.

On Xcode versions that require iOS 15.0 or later, raise the deployment target of the pod targets in your Podfile:

```ruby
post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '15.0'
    end
  end
end
```

## Author

info@stringee.com

## License

Stringee is available under the MIT license. See the LICENSE file for more info.

## Release Notes

See the [Changelog](https://developer.stringee.com/file/changelog/platform/ios) for more information.


