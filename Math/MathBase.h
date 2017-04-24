#ifndef MATHBASE_H_
#define MATHBASE_H_

// This file introduces some mathematical basic stuff(namespace TMath)

#include <math.h>

namespace TMath {

	// Epsilon is sometimes needed for numerical calcluations as a "replacement for zero"
	const double Epsilon = 1e-10;
	// Use MaxValue, if you want something as "biggest value, ever"
	const double MaxValue = std::numeric_limits<double>::max();

	// numerical comparison, if zero
	inline bool IsZero(double Value)
	{
		return fabs(Value) <= Epsilon;
	}

	// numerical comparison, if less
	inline bool IsLessOrEqual(double Left, double Right)
	{
		double Diff = Left - Right;
		return Diff<0 || IsZero(Diff);
	}

	// numerical comparison, if greater
	inline bool IsGreaterOrEqual(double Left, double Right)
	{
		double Diff = Left - Right;
		return Diff>0 || IsZero(Diff);
	}

	inline double Cos(double Value)
	{
		return ::cos(Value);
	}
	inline double Sin(double Value)
	{
		return ::sin(Value);
	}
	inline double Tan(double Value)
	{
		return ::tan(Value);
	}

	inline void CalcSinCos(double Value, double &RetValSin, double &RetValCos)
	{
		RetValSin = Sin(Value);
		RetValCos = Cos(Value);
	}

	// return asin(x); values:[-PI/2;PI/2]
	inline double ArcSin(double x)
	{
		return ::asin(x);
	}

	// return atan(y/x);
	inline double Atan2(double y, double x)
	{
		return ::atan2(y, x);
	}

	// return atan(x); values: (-PI;PI)
	inline double ArcTan(double x)
	{
		return ::atan(x);
	}

	template< class Type >
	inline Type Sqr(Type Value)
	{
		return Value*Value;
	}

	template< class Type >
	inline Type Sqrt(Type Value)
	{
		return sqrt(Value);
	}

	template< class Type>
	inline Type Abs(Type Value)
	{
		return abs(Value);
	}

	template<>
	inline float Abs(float Value)
	{
		return static_cast<float>(fabs(Value));
	}

	template<>
	inline double Abs(double Value)
	{
		return fabs(Value);
	}

	template<>
	inline long double Abs(long double Value)
	{
		return static_cast<long double>(fabsl(Value));
	}

	template< class T >
	inline T Accumulate(T& Result, T Increment)
	{
		return (Result += Increment);
	}

	inline double Round(double Value, int Digits = 0)
	{
		double M = std::pow(10.0, Digits);
		Value *= M;
		Value = (Value > 0.0) ? floor(Value + 0.5) : ceil(Value - 0.5);
		return Value / M;
	}

}  // namespace TMath

#endif      // #ifndef MATHBASE_H_