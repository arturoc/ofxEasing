# ofxEasing

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

