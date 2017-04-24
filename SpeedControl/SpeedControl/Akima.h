#ifndef  AKIMA_H_
#define AKIMA_H_

#include <vector>
#include "../../Math/MathBase.h"
#include "../../Geometry/geometry.h"

class TAkima
{
private:
	double P0;
	double P1;
	double P2;
	double P3;
	Geo::TPoint prePoint;
private:
	// rhs - lhs
	double GetSlop(Geo::TPoint pt1, Geo::TPoint pt2)
	{
		return (pt2.Y() - pt1.Y()) / (pt2.X() - pt1.X());
	}

	double GetMSlop(std::vector<double> &VecM, int index, int strategy)
	{
		if (0 == strategy)
		{
			do
			{
				// Strategy 1
				// Ti = (|M(i+1) - M(i)|M(i-1) + |M(i-1) - M(i-2)|M(i)) / (|M(i+1) - M(i)| + |M(i-1) - M(i-2)|)
				index -= 1;
				if (index - 1 < 0 || index + 1 > static_cast<int>(VecM.size()))
					return 1;

				double T = abs(VecM[index + 1] - VecM[index])*VecM[index - 1] + abs(VecM[index - 1] - VecM[index - 2])*VecM[index];

				if (T < TMath::Epsilon)
					break;

				double T2 = abs(VecM[index + 1] - VecM[index]) + abs(VecM[index - 1] - VecM[index - 2]);
				if (T2 < TMath::Epsilon)
					break;

				T = T / T2;

				return T;

			} while (0);

			// if strategy1 is error, then use strategy 2
			return (VecM[index - 1] + VecM[index]) / 2;
		}
		else if (1 == strategy)
		{
			// Strategy 2
			// Ti = (M(i-1) + M(i)) / 2
			return (VecM[index - 1] + VecM[index]) / 2;
		}
		else if (2 == strategy)
		{
			// Strategy 3
			// Ti = Mi
			return VecM[index - 1];
		}
		else {
			return 1.0;
		}
	}
public:
	TAkima() {}
	~TAkima() {}

	void AkimaInit(std::vector<Geo::TPoint> &VecPt, int iAkimaStrategy = 0)
	{
		if (6 != VecPt.size())
			return;

		double M1 = GetSlop(VecPt[0], VecPt[1]);
		double M2 = GetSlop(VecPt[1], VecPt[2]);
		double M3 = GetSlop(VecPt[2], VecPt[3]);
		double M4 = GetSlop(VecPt[3], VecPt[4]);
		double M5 = GetSlop(VecPt[4], VecPt[5]);

		std::vector<double> VecM;
		VecM.push_back(M1);
		VecM.push_back(M2);
		VecM.push_back(M3);
		VecM.push_back(M4);
		VecM.push_back(M5);

		double T3 = GetMSlop(VecM, 3, iAkimaStrategy);
		double T4 = GetMSlop(VecM, 4, iAkimaStrategy);

		P0 = VecPt[2].Y();
		P1 = T3;
		P2 = (3 * (VecPt[3].Y() - VecPt[2].Y()) / (VecPt[3].X() - VecPt[2].X()) - 2 * T3 - T4) / (VecPt[3].X() - VecPt[2].X());
		P3 = (T3 + T4 - 2 * (VecPt[3].Y() - VecPt[2].Y()) / (VecPt[3].X() - VecPt[2].X())) / ((VecPt[3].X() - VecPt[2].X()) * (VecPt[3].X() - VecPt[2].X()));
		prePoint = VecPt[2];
	}
	double GetAkimaCoordY(double CoordX)
	{
		return P0 + P1*(CoordX - prePoint.X()) + P2 * (CoordX - prePoint.X()) * (CoordX - prePoint.X()) + P3 * (CoordX - prePoint.X()) * (CoordX - prePoint.X()) * (CoordX - prePoint.X());
	}
};

#endif			// ifndef AKIMA_H_

