#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <vector>
#include <assert.h>
#include "../Math/MathBase.h"

namespace Geo {

	using namespace TMath;

	// A class for a Current Transformation TMatrix (CTM)
	// A CTM is a homogeneous matrix consisting of 9 entries; 3 of them are always the same: \n
	// / a b t1 \  abcd are a 2x2 matrix doing scaling, shearing, mirroring and turning \n
	// | c d t2 |  t1 and t2 do the translation \n
	// \ 0 0 1  /
	class TCTM
	{
	private:
		double x[6];	// the entries in the matrix

	public:
		// ctor from scratch (preset the entries in the matrix with zero)
		TCTM()
		{
			std::fill(x, x + 6, 0);
		}

		// ctor from six values to preset the entries in the matrix
		TCTM(double x00, double x01, double x02, double x10, double x11, double x12)
		{
			x[0] = x00; x[1] = x01; x[2] = x02;
			x[3] = x10; x[4] = x11; x[5] = x12;
		}

		// ctor from a scale
		TCTM(double Skal)
		{
			x[0] = Skal; x[1] = 0; x[2] = 0;
			x[3] = 0; x[4] = Skal; x[5] = 0;
		}

		// access the entries in the matrix
		double& operator() (unsigned int iRow, unsigned int iCol)
		{
			assert(iRow<2);
			assert(iCol<3);
			return x[iRow * 3 + iCol];
		}

		// access the entries in the matrix
		const double& operator() (unsigned int iRow, unsigned int iCol) const
		{
			assert(iRow<2);
			assert(iCol<3);
			return x[iRow * 3 + iCol];
		}
		// multiplication of two CTMs
		TCTM operator *(const TCTM &rhs) const
		{
			return TCTM(x[0] * rhs.x[0] + x[1] * rhs.x[3],
				x[0] * rhs.x[1] + x[1] * rhs.x[4],
				x[0] * rhs.x[2] + x[1] * rhs.x[5] + x[2],
				x[3] * rhs.x[0] + x[4] * rhs.x[3],
				x[3] * rhs.x[1] + x[4] * rhs.x[4],
				x[3] * rhs.x[2] + x[4] * rhs.x[5] + x[5]
			);
		}
		//! the transformation of a "point"
		void Transform(double &dX, double &dY) const
		{
			double dH = x[0] * dX + x[1] * dY + x[2];
			dY = x[3] * dX + x[4] * dY + x[5];
			dX = dH;
		}
	}; // end class CTM

	// A class for point
	class TPoint {
		double PtX;
		double PtY;
	public:
		TPoint( double x, double y)
		{
			PtX = x;
			PtY = y;
		}
		TPoint()
		{
			PtX = 0;
			PtY = 0;
		}
		TPoint(const TPoint& pt)
		{
			PtX = pt.X();
			PtY = pt.Y();
		}

		TPoint *Clone() const
		{
			return new TPoint(*this);
		}

		const double &X() const { return PtX; }
		const double &Y() const { return PtY; }

		double &X() { return PtX; }
		double &Y() { return PtY; }

		void Transform(const TCTM &CTM)
		{
			CTM.Transform(X(), Y());
		}

		unsigned int size() const { return 1; }

		const TPoint operator-() const
		{
			return TPoint(-X(), -Y());
		}
		const TPoint operator+(double rhs) const
		{
			return TPoint(X() + rhs, Y());
		}
		const TPoint operator+(const TPoint& rhs) const
		{
			return TPoint(X() + rhs.X(), Y() + rhs.Y());
		}
		TPoint& operator+=(const TPoint& rhs)
		{
			PtX += rhs.X();
			PtY += rhs.Y();
			return *this;
		}
		const TPoint operator-(const TPoint& rhs) const
		{
			return TPoint(X() - rhs.X(), Y() - rhs.Y());
		}
		TPoint& operator-=(const TPoint& rhs)
		{
			PtX -= rhs.X();
			PtY -= rhs.Y();
			return *this;
		}
		const TPoint operator*(const double& rhs) const
		{
			return TPoint(X()*rhs, Y()*rhs);
		}
		const TPoint& operator*=(const double& rhs)
		{
			X() *= rhs;
			Y() *= rhs;
			return *this;
		}
		const TPoint operator/(const double& rhs) const
		{
			return TPoint(X() / rhs, Y() / rhs);
		}
		const TPoint& operator/=(const double& rhs)
		{
			X() /= rhs;
			Y() /= rhs;
			return *this;
		}
		bool operator==(const TPoint& rhs) const
		{
			return (*this - rhs).Norm() < Geo::Epsilon;
		}
		bool operator!=(const TPoint& rhs) const
		{
			return !operator==(rhs);
		}
		// length from origin point to point
		double Norm() const
		{
			return TMath::Sqrt(PtX*PtX + PtY*PtY);
		}
		// normalize the TPoint (same direction from origin, but with length 1
		Geo::TPoint& Normalize()
		{
			assert(Norm()>Geo::Epsilon);
			*this = *this / Norm();
			return *this;
		}

		// return the "length" of the Point (distance from origin)
		double Length() const
		{
			return Norm();
		}
	}; // end class TPoint

	   // A class for rectangle (axis aligned!)
	class TRectangle
	{
	private:
		TPoint LowerLeft;			// LowerLeft and UpperRight determine the rectangle
		TPoint UpperRight;			// LowerLeft and UpperRight determine the rectangle

		TPoint UpperLeft;           // UpperLeft and LowerRight are helper variables
		TPoint LowerRight;          // UpperLeft and LowerRight are helper variables

		// Make UpperLeft and LowerRight valid
		void Validate() const
		{
			TRectangle *This = const_cast< TRectangle* >(this);
			This->LowerRight.X() = UpperRight.X();
			This->LowerRight.Y() = LowerLeft.Y();
			This->UpperLeft.X() = LowerLeft.X();
			This->UpperLeft.Y() = UpperRight.Y();
		}

	public:
		// a type defining the position of a point relative to a rectangle
		enum ePosition
		{
			eXNeg = 1,							// left of  left border
			eXFirstLine = 2,					// on  the  left border
			eXMiddle = 4,						// between  left and right border
			eXSecondLine = 8,					// on  the  right border
			eXPos = 16,							// right of right border
			eXMask = 31,						// all bits belonging to x-direction

			eYNeg = 32,							// below     lower border
			eYFirstLine = 64,					// on  the   lower border
			eYMiddle = 128,						// between   lower and upper border
			eYSecondLine = 256,					// on  the   upper border
			eYPos = 512,						// above the upper border
			eYMask = 992						// all bits belonging to y-direction
		};

		// calculate, where the point is (relative to this)
		// param[in] Pt The point to check
		// return A Bitset with 4 bits for X and 4 for Y, for the meaning see enum ePosition
		int WhereIs(const TPoint Pt) const;

		//! ctor from two points (or one or default)
		TRectangle(const TPoint& Point = TPoint(0, 0))
			: LowerLeft(Point),
			UpperRight(Point)
		{}

		// ctor from two points (or one or default)
		TRectangle(const TPoint& lowerLeft, const TPoint& upperRight)
			: LowerLeft(lowerLeft),
			UpperRight(upperRight)
		{
			if (LowerLeft.X()>UpperRight.X())
				std::swap(LowerLeft.X(), UpperRight.X());
			if (LowerLeft.Y()>UpperRight.Y())
				std::swap(LowerLeft.Y(), UpperRight.Y());
		}

		// ctor from four values
		TRectangle(const double& left, const double& lower,
			const double& right, const double& upper)
			: LowerLeft(left, lower),
			UpperRight(right, upper)
		{
			if (LowerLeft.X()>UpperRight.X())
				std::swap(LowerLeft.X(), UpperRight.X());
			if (LowerLeft.Y()>UpperRight.Y())
				std::swap(LowerLeft.Y(), UpperRight.Y());
		}

		// alloc a copy of yours and return it:
		TRectangle *Clone() const
		{
			return new TRectangle(*this);
		}

		// Set the rectangle by two points
		void Set(const TPoint& lowerLeft, const TPoint& upperRight)
		{
			LowerLeft = lowerLeft;
			UpperRight = upperRight;

			if (LowerLeft.X()>UpperRight.X())
				std::swap(LowerLeft.X(), UpperRight.X());
			if (LowerLeft.Y()>UpperRight.Y())
				std::swap(LowerLeft.Y(), UpperRight.Y());
		}

		// Extend the rectangle, so that Pt is included
		// param[in] Pt The point to include
		void Include(const TPoint& Pt)
		{
			if (LowerLeft.X()>Pt.X())
				LowerLeft.X() = Pt.X();
			if (LowerLeft.Y()>Pt.Y())
				LowerLeft.Y() = Pt.Y();
			if (UpperRight.X()<Pt.X())
				UpperRight.X() = Pt.X();
			if (UpperRight.Y()<Pt.Y())
				UpperRight.Y() = Pt.Y();
		}

		// Combine two rectangles
		// param[in] rhs The other rectangle
		TRectangle& operator+=(const TRectangle& rhs)
		{
			if (rhs.Left() < Left())
				LowerLeft.X() = rhs.Left();
			if (rhs.Bottom() < Bottom())
				LowerLeft.Y() = rhs.Bottom();
			if (rhs.Right() > Right())
				UpperRight.X() = rhs.Right();
			if (rhs.Top() > Top())
				UpperRight.Y() = rhs.Top();
			return *this;
		}

		// Check for equality
		// param[in] rhs The other rectangle
		bool operator==(const TRectangle& rhs)
		{
			return (LowerLeft == rhs.LowerLeft) && (UpperRight == rhs.UpperRight);
		}

		// Check for inequality
		// param[in] rhs The other rectangle
		bool operator!=(const TRectangle& rhs)
		{
			return !(*this == rhs);
		}

		// Scale the size of the rectangle (but leave LowerLeft, where it is)
		// param[in] dX the factor to use for scaling in x-direction
		// param[in] dY the factor to use for scaling in y-direction
		void ScaleSize(double dX, double dY)
		{
			double NewRight = dX * Width();
			double NewUpper = dY * Height();
			UpperRight = LowerLeft + TPoint(NewRight, NewUpper);
		}
		// Scale the size of the rectangle (but leave LowerLeft, where it is)
		// param[in] dX the factor to use for scaling in x- and y-direction
		void ScaleSize(double dX)
		{
			ScaleSize(dX, dX);
		}

		// offset (extend by some amount) the rectangle by OffsetLength
		// param[in] OffsetLength The distance between the original lines and the resulting lines (positive->bigger)
		void OffsetBy(double OffsetLength)
		{
			Set(LowerLeft - Geo::TPoint(OffsetLength, OffsetLength), UpperRight + Geo::TPoint(OffsetLength, OffsetLength));
		}

		// name to access some features/points of the rectangle (everything read-only)
		const double Width()  const { return UpperRight.X() - LowerLeft.X(); }
		const double Height() const { return UpperRight.Y() - LowerLeft.Y(); }

		const double Left()   const { return LowerLeft.X(); }
		const double Top()    const { return UpperRight.Y(); }
		const double Right()  const { return UpperRight.X(); }
		const double Bottom() const { return LowerLeft.Y(); }

		TPoint BottomLeft()      const { return LowerLeft; }
		TPoint BottomRight()     const { return TPoint(Right(), Bottom()); }
		TPoint TopRight()        const { return UpperRight; }
		TPoint TopLeft()         const { return TPoint(Left(), Top()); }
		TPoint Center()          const { return (LowerLeft + UpperRight) / 2; }

		// name the heritage
		const TPoint& operator[](unsigned int Index) const
		{
			assert(Index<5);
			Validate();
			switch (Index)
			{
			case 0: return LowerLeft;
			case 1: return LowerRight;
			case 2: return UpperRight;
			case 3: return UpperLeft;
			}
			return LowerLeft;
		}

		Geo::TRectangle GetAABB() const
		{
			return *this;
		}

		bool IsAABBValid() const { return true; }

		unsigned int size() const { return 4; }

		// check, if the point is inside
		// param[in] Pt The point to check
		// return true  The point is inside or on edges
		// Otherwise return false
		bool IsInside(const TPoint& Pt) const
		{
			return (IsLessOrEqual(LowerLeft.X(), Pt.X()) && IsLessOrEqual(LowerLeft.Y(), Pt.Y())
				&& IsGreaterOrEqual(UpperRight.X(), Pt.X()) && IsGreaterOrEqual(UpperRight.Y(), Pt.Y()));
		}

		// The distance of this to a point
		// param[in] Point The point to calculate the distance to
		// return The distance to the Point
		double Distance(const TPoint& Point) const;

	}; // end class TRectangle


	   // Distances between geometrical objects

	   // Calculate the distance between two points
	   // return The distance between the two points
	inline double Distance(const TPoint& Pt1, const TPoint& Pt2)
	{
		return (Pt1 - Pt2).Norm();
	}

}			// namespace Geo
#endif			// ifndef GEOMETRY_H_