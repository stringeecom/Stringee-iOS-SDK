
Pod::Spec.new do |s|
  s.name             = 'Stringee'
  s.version          = '2.0.1'
  s.summary          = 'Developed by Stringee'

  s.description      = <<-DESC
The Stringee platform, developed by Stringee, makes it easy to embed high-quality interactive video, voice, messaging, and screen sharing into web and mobile apps.
                       DESC

  s.homepage         = 'https://github.com/stringeecom/Stringee-iOS-SDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'HoangDuoc' => 'duochv@stringee.com' }
  s.source           = { :git => 'https://github.com/stringeecom/Stringee-iOS-SDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  

  s.ios.deployment_target = '13.0'
  s.pod_target_xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}

  s.source_files = 'Stringee/Classes/**/Stringee.xcframework/**/Stringee.framework/Headers/*.h'
  s.public_header_files = 'Stringee/Classes/**/Stringee.xcframework/**/Stringee.framework/Headers/*.h'

  s.frameworks = 'CoreFoundation', 'VideoToolbox', 'AudioToolbox', 'AVFoundation', 'GLKit'
  s.libraries = 'icucore', 'stdc++'

  s.vendored_frameworks = 'Stringee/Classes/**/Stringee.xcframework'
  s.dependency "WebRTC-SDK", '137.7151.09'

end
