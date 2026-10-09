Pod::Spec.new do |s|
  s.name             = 'Stringee'
  s.version          = '2.2.0'
  s.summary          = 'Developed by Stringee'

  s.description      = <<-DESC
The Stringee platform, developed by Stringee, makes it easy to embed high-quality interactive video, voice, messaging, and screen sharing into web and mobile apps.
                       DESC

  s.homepage         = 'https://github.com/stringeecom/Stringee-iOS-SDK'
  s.license          = { :type => 'MIT', :text => <<-LICENSE
Copyright (c) 2017 duochv@stringee.com <hoangduoc20121540@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
    LICENSE
  }
  s.author           = { 'HoangDuoc' => 'duochv@stringee.com' }

  # Same zip as the Swift Package release, so SPM and CocoaPods ship one binary per version.
  s.source           = {
    :http => "https://github.com/stringeecom/Stringee-iOS-SDK-SPM/releases/download/#{s.version}/Stringee.xcframework.zip",
    :sha256 => 'cb5cde217632cd2653e610399520f15835fd1be41afe754e89d6bed752c8fcfa'
  }

  s.ios.deployment_target = '15.0'
  s.vendored_frameworks = 'Stringee.xcframework'

  # Same WebRTC build as the Swift Package: stasel/WebRTC 137.0.0.
  s.dependency 'WebRTC-lib', '137.0.0'
end
