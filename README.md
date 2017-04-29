# ofxEasing

[![Build status](https://travis-ci.org/arturoc/ofxEasing.svg?branch=master)](https://travis-ci.org/arturoc/ofxEasing)

[![Build status](https://ci.appveyor.com/api/projects/status/r1u88c06u8jo8e8p/branch/master?svg=true)](https://ci.appveyor.com/project/arturoc/ofxeasing/branch/master)


Replaces ofxTween with a simpler API and no external dependencies.

Usage:

```cpp
using namespace ofxeasing;
map(value, minIn, maxIn, minOut, maxOut, linear::easeIn);
```

Some easing functions might have more parameters than the usual 4. Right now only the \_s version of the back functions which indicate which proportion of the distance is done in the back trajectory. In those cases you can pass the extra parameter at the end of the map function like:

```cpp
using namespace ofxeasing;
map(value, minIn, maxIn, minOut, maxOut, back::easeIn_s, 0.8);
```

