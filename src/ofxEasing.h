#ifndef EASING_H_
#define EASING_H_

#include <cmath>
#include <functional>

namespace ofxeasing{
	constexpr float pi = 3.14159265358979323846f;

class back{
public:
	inline static float easeIn_s(float t,float b , float c, float d, float s) {
		float postFix = t/=d;
		return c*(postFix)*t*((s+1)*t - s) + b;
	}

	inline static float easeIn (float t,float b , float c, float d) {
		return easeIn_s(t, b, c, d, 1.70158f);
	}

	inline static float easeOut_s(float t,float b , float c, float d, float s) {
		t=t/d-1;
		return c*(t*t*((s+1)*t + s) + 1) + b;
	}

	inline static float easeOut(float t,float b , float c, float d) {
		return easeOut_s(t, b, c, d, 1.70158f);
	}

	inline static float easeInOut_s(float t,float b , float c, float d, float s) {
		s*=(1.525f);
		if ((t/=d/2) < 1){
			return c/2*(t*t*((s+1)*t - s)) + b;
		}
		float postFix = t-=2;
		return c/2*((postFix)*t*((s+1)*t + s) + 2) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		return easeInOut_s(t, b, c, d, 1.70158f);
	}
};

class bounce{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		return c - easeOut (d-t, 0, c, d) + b;
	}

	inline static float easeOut(float t,float b , float c, float d) {
		if ((t/=d) < (1/2.75f)) {
			return c*(7.5625f*t*t) + b;
		} else if (t < (2/2.75f)) {
			float postFix = t-=(1.5f/2.75f);
			return c*(7.5625f*(postFix)*t + .75f) + b;
		} else if (t < (2.5/2.75)) {
				float postFix = t-=(2.25f/2.75f);
			return c*(7.5625f*(postFix)*t + .9375f) + b;
		} else {
			float postFix = t-=(2.625f/2.75f);
			return c*(7.5625f*(postFix)*t + .984375f) + b;
		}
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if (t < d/2) return easeIn (t*2, 0, c, d) * .5f + b;
		else return easeOut (t*2-d, 0, c, d) * .5f + c*.5f + b;
	}
};

class circ{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return c * sqrt(1 - (t=t/d-1)*t) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if ((t/=d/2) < 1) return c/2 * (1 - sqrt(1 - t*t)) + b;
		return c/2 * (sqrt(1 - (t-=2)*t) + 1) + b;
	}
};

class cubic{
	public:

	inline static float easeIn (float t,float b , float c, float d) {
		return c*(t/=d)*t*t + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return c*((t=t/d-1)*t*t + 1) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if ((t/=d/2) < 1) return c/2*t*t*t + b;
		return c/2*((t-=2)*t*t + 2) + b;
	}
};

class elastic{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		if (t==0) return b;  if ((t/=d)==1) return b+c;
		float p=d*.3f;
		float a=c;
		float s=p/4;
		float postFix =a*pow(2,10*(t-=1)); // this is a fix, again, with post-increment operators
		return -(postFix * sin((t*d-s)*(2*float(pi))/p )) + b;
	}

	inline static float easeOut(float t,float b , float c, float d) {
		if (t==0) return b;  if ((t/=d)==1) return b+c;
		float p=d*.3f;
		float a=c;
		float s=p/4;
		return (a*pow(2,-10*t) * sin( (t*d-s)*(2*pi)/p ) + c + b);
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if (t==0) return b;  if ((t/=d/2)==2) return b+c;
		float p=d*(.3f*1.5f);
		float a=c;
		float s=p/4;

		if (t < 1) {
			float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
			return -.5f*(postFix* sin( (t*d-s)*(2*pi)/p )) + b;
		}
		float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
		return postFix * sin( (t*d-s)*(2*pi)/p )*.5f + c + b;
	}
};


class exp{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if (t==0) return b;
		if (t==d) return b+c;
		if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
		return c/2 * (-pow(2, -10 * --t) + 2) + b;
	}
};

class linear{
	public:
	inline static float easeNone (float t,float b , float c, float d) {
		return c*t/d + b;
	}
	inline static float easeIn (float t,float b , float c, float d) {
		return c*t/d + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return c*t/d + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		return c*t/d + b;
	}
};

class quad{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		return c*(t/=d)*t + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return -c *(t/=d)*(t-2) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if ((t/=d/2) < 1) return c/2*t*t + b;
		return -c/2 * ((--t)*(t-2) - 1) + b;

		/*

		originally return -c/2 * (((t-2)*(--t)) - 1) + b;

		I've had to swap (--t)*(t-2) due to diffence in behaviour in
		pre-increment operators between java and c++, after hours
		of joy

		 James George:: The fix refered to above actually broke the equation,
		 it would land at 50% all the time at the end
		 copying back the original equation from online fixed it...

		 potentially compiler dependent.
		*/

	}
};

class quart{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		return c*(t/=d)*t*t*t + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return -c * ((t=t/d-1)*t*t*t - 1) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
		return -c/2 * ((t-=2)*t*t*t - 2) + b;
	}
};

class quint{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		return c*(t/=d)*t*t*t*t + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return c*((t=t/d-1)*t*t*t*t + 1) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
		return c/2*((t-=2)*t*t*t*t + 2) + b;
	}
};

class sine{
	public:
	inline static float easeIn (float t,float b , float c, float d) {
		return -c * cos(t/d * (float(pi)/2)) + c + b;
	}
	inline static float easeOut(float t,float b , float c, float d) {
		return c * sin(t/d * (float(pi)/2)) + b;
	}

	inline static float easeInOut(float t,float b , float c, float d) {
		return -c/2 * (cos(float(pi)*t/d) - 1) + b;
	}
};

template<typename Function, typename ...Args>
std::function<float(float,float,float,float)> bind(Function f, Args... parameters){
	return std::bind(f, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, parameters...);
}

inline float map(float v, float minIn, float maxIn, float minOut, float maxOut, std::function<float(float,float,float,float)> easing){
	float t = v - minIn;
	float c = maxOut - minOut;
	float d = maxIn - minIn;
	float b = minOut;
	return easing(t,b,c,d);
}

template<typename Function, typename ...Args>
inline float map(float v, float minIn, float maxIn, float minOut, float maxOut, Function easing, Args... parameters){
	return map(v, minIn, maxIn, minOut, maxOut, bind(easing, parameters...));
}

inline float map_clamp(float v, float minIn, float maxIn, float minOut, float maxOut, std::function<float(float,float,float,float)> easing){
	v = std::min(std::max(v, minIn), maxIn);
	return map(v,minIn,maxIn,minOut,maxOut,easing);
}

template<typename Function, typename ...Args>
inline float map_clamp(float v, float minIn, float maxIn, float minOut, float maxOut, Function easing, Args... parameters){
	return map_clamp(v, minIn, maxIn, minOut, maxOut, bind(easing, parameters...));
}

typedef std::function<float(float, float, float, float)> function;
}

#endif /* EASING_H_ */
