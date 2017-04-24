#ifndef SPEEDCONTROL_H_
#define SPEEDCONTROL_H_

#include <vector>
#include <ctime>
#include "../../Geometry/geometry.h"
#include "../../Math/MathBase.h"

class TSpeedControl
{
private:
	std::vector<Geo::TPoint> VecPt;
	int iBlockWidth = 100;
	int iBlockHeigh = 100;
public:
	TSpeedControl() {}
	~TSpeedControl() {}
	void GeneratePath()
	{
		VecPt.clear();
		srand(static_cast<unsigned int>(time(nullptr)));
		for (int w = 0; w < (int)(750 / iBlockWidth); w++)
		{
			for (int h = 0; h < (int)(600 / iBlockHeigh); h++)
			{
				double dCoordX = rand() % (iBlockWidth * 10) / 10.0 + w * iBlockWidth;
				if (0 == w % 2)
				{
					double dCoordY = rand() % (iBlockHeigh * 10) / 10.0 + h * iBlockHeigh;
					VecPt.push_back(Geo::TPoint(dCoordX, dCoordY));
				}
				else {
					double dCoordY = rand() % (iBlockHeigh * 10) / 10.0 + (600 - h * iBlockHeigh - iBlockHeigh);
					VecPt.push_back(Geo::TPoint(dCoordX, dCoordY));
				}
			}
		}
	}

	const std::vector<Geo::TPoint>& GetPathVec()
	{
		return VecPt;
	}
};

#endif			// ifndef SPEEDCONTROL_H_

