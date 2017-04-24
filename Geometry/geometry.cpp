#include "geometry.h"

namespace Geo {

	double TRectangle::Distance(const TPoint& Point) const
	{
		// check where the point is (compared to the rectangle)
		// then it is easy to calc the distance!
		int WhereIsTag = WhereIs(Point);
		int WhereIsTagX = WhereIsTag & eXMask;
		int WhereIsTagY = (WhereIsTag & eYMask) << 5;
		switch (WhereIsTagX + WhereIsTagY)
		{
		case eXMiddle + eXMiddle:         // inside the rectangle
		case eXMiddle + eXFirstLine:      // or on one of the boundary lines
		case eXMiddle + eXSecondLine:
		case eXFirstLine + eXFirstLine:   // or on both of the boundary lines (corner)
		case eXFirstLine + eXSecondLine:
		case eXSecondLine + eXSecondLine:
			return 0;
		case eXNeg + eXNeg:               // this is left bottom
		case eXNeg + eXFirstLine:
			return Geo::Distance(Point, LowerLeft);
		case eXPos + eXPos:               // this is right top
		case eXPos + eXSecondLine:
			return Geo::Distance(Point, UpperRight);
		case eXNeg + eXPos:               //this is left top and right bottom
		case eXNeg + eXSecondLine:
		case eXPos + eXFirstLine:
			if (WhereIsTagY>WhereIsTagX)
				return Geo::Distance(Point, TPoint(Left(), Top()));
			else
				return Geo::Distance(Point, TPoint(Right(), Bottom()));
		}
		// now only the "sides" are left:
		if (WhereIsTagY == eXNeg)
			return Bottom() - Point.Y();
		else if (WhereIsTagY == eXPos)
			return Point.Y() - Top();
		else if (WhereIsTagX == eXNeg)
			return Left() - Point.X();
		return Point.X() - Right();
	}

	// calculate, where the point is (relative to this)
	// param[in] Pt The point to check
	// return A Bitset with 4 bits for X and 4 for Y, for the meaning see enum \see ePosition
	inline int TRectangle::WhereIs(const TPoint Pt) const
	{
		int RetVal(0);
		if (Geo::IsZero(Pt.X() - Left()))
			RetVal += eXFirstLine;
		else if (Geo::IsZero(Pt.X() - Right()))
			RetVal += eXSecondLine;
		else if (Pt.X() < Left())
			RetVal += eXNeg;
		else if (Pt.X() > Right())
			RetVal += eXPos;
		else
			RetVal += eXMiddle;

		if (Geo::IsZero(Pt.Y() - Bottom()))
			RetVal += eYFirstLine;
		else if (Geo::IsZero(Pt.Y() - Top()))
			RetVal += eYSecondLine;
		else if (Pt.Y() < Bottom())
			RetVal += eYNeg;
		else if (Pt.Y() > Top())
			RetVal += eYPos;
		else
			RetVal += eYMiddle;

		return RetVal;
	}
} // end Geo