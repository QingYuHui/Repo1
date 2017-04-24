#ifndef VIEWWINDOW_H_
#define VIEWWINDOW_H_

#include "../Geometry/geometry.h"

namespace HGUI {

	using namespace Geo;

	enum class eCoordinate {
		BottomLeft = 0,
		BottomRight = 1,
		TopLeft = 2,
		TopRight = 3
	};

	class ViewWindow{

	public:
		ViewWindow() : CTM(1, 0, 0, 0, 1, 0)
		{}
		~ViewWindow()
		{}

	private:
		Geo::TCTM CTM;
	public:
		void SetCoordinateSystem(System::Drawing::Rectangle rec, const eCoordinate eSetCoordinateSystem = eCoordinate::BottomLeft)
		{
			switch (eSetCoordinateSystem)
			{
			case eCoordinate::BottomLeft:
				CTM = Geo::TCTM(1, 0, 0, 0, -1, rec.Height);
				break;
			case eCoordinate::BottomRight:
				CTM = Geo::TCTM(-1, 0, rec.Width, 0, -1, rec.Height);
				break;
			case eCoordinate::TopLeft:
				CTM = Geo::TCTM(1, 0, 0, 0, 1, 0);
				break;
			case eCoordinate::TopRight:
				CTM = Geo::TCTM(-1, 0, rec.Width, 0, 1, 0);
				break;
			}
		}
		
		Geo::TPoint ConvertToWorldCoords(const TPoint& refPoint)
		{
			Geo::TPoint Pt(refPoint);
			Pt.Transform(CTM);
			return Pt;
		}

		// fill rectangle with default brush
		void FillRectangle(System::Drawing::Graphics^ myGraphics_p, Geo::TRectangle rec)
		{
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Black);
			System::Drawing::Rectangle Rect( static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).X()), static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).Y()), static_cast<int>(rec.Width()), static_cast<int>(rec.Height()));
			myGraphics_p->FillRectangle(brush, Rect);
		}
		// fill rectangle with special brush and without gcnew
		void FillRectangle(System::Drawing::Graphics^ myGraphics_p, System::Drawing::Brush^  brush, Geo::TRectangle rec)
		{
			System::Drawing::Rectangle Rect(static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).X()), static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).Y()), static_cast<int>(rec.Width()), static_cast<int>(rec.Height()));
			myGraphics_p->FillRectangle(brush, Rect);
		}

		// paint rectangle with default pen
		void PaintRectangle( System::Drawing::Graphics^ myGraphics_p, Geo::TRectangle rec )
		{
			System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);
			System::Drawing::Rectangle Rect(static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).X()), static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).Y()), static_cast<int>(rec.Width()), static_cast<int>(rec.Height()));
			myGraphics_p->DrawRectangle(pen, Rect);
		}
		// paint rectangle with special pen and without gcnew
		void PaintRectangle(System::Drawing::Graphics^ myGraphics_p, System::Drawing::Pen^ pen, Geo::TRectangle rec)
		{
			System::Drawing::Rectangle Rect(static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).X()), static_cast<int>(ConvertToWorldCoords(rec.TopLeft()).Y()), static_cast<int>(rec.Width()), static_cast<int>(rec.Height()));
			myGraphics_p->DrawRectangle(pen, Rect);
		}

		// paint point with default pen and brush
		void PaintPoint( System::Drawing::Graphics^ myGraphics_p, const Geo::TPoint& pt, float size = 3.0)
		{
			Geo::TPoint PtDraw(pt);
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Black);
			PtDraw.Transform(CTM);
			myGraphics_p->FillEllipse(brush, (float)PtDraw.X(), (float)PtDraw.Y(), (float)size, (float)size);
		}
		// paint point with special brush and without gcnew
		void PaintPoint(System::Drawing::Graphics^ myGraphics_p, System::Drawing::Brush^  brush, const Geo::TPoint& pt, float size = 3.0)
		{
			Geo::TPoint PtDraw(pt);
			PtDraw.Transform(CTM);
			myGraphics_p->FillEllipse(brush, (float)PtDraw.X(), (float)PtDraw.Y(), (float)size, (float)size);
		}

		// paint line with default pan
		void PaintLine(System::Drawing::Graphics^ myGraphics_p, const Geo::TPoint& pt1, const Geo::TPoint& pt2, const float iSize = 1)
		{
			Geo::TPoint PtDraw1(pt1);
			Geo::TPoint PtDraw2(pt2);
			PtDraw1.Transform(CTM);
			PtDraw2.Transform(CTM);
			System::Drawing::Pen^  pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, iSize);
			myGraphics_p->DrawLine(pen, (float)PtDraw1.X(), (float)PtDraw1.Y(), (float)PtDraw2.X(), (float)PtDraw2.Y());
		}
		// paint line with special pen and without gcnew
		void PaintLine(System::Drawing::Graphics^ myGraphics_p, System::Drawing::Pen^  pen, const Geo::TPoint& pt1, const Geo::TPoint& pt2, const float iSize = 1)
		{
			Geo::TPoint PtDraw1(pt1);
			Geo::TPoint PtDraw2(pt2);
			PtDraw1.Transform(CTM);
			PtDraw2.Transform(CTM);
			myGraphics_p->DrawLine(pen, (float)PtDraw1.X(), (float)PtDraw1.Y(), (float)PtDraw2.X(), (float)PtDraw2.Y());
		}

		void PaintText(System::Drawing::Graphics^ myGraphics_p, System::String^ targetStr, const Geo::TPoint& pt, System::Drawing::Color color, float size = 12.0)
		{
			Geo::TPoint PtDraw(pt);
			PtDraw.Transform(CTM);
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(color);
			System::Drawing::Font^ font = gcnew System::Drawing::Font("ËÎÌו", size);
			myGraphics_p->DrawString(targetStr, font, brush, (float)PtDraw.X(), (float)PtDraw.Y());
		}
	};			// end class ViewWindow
}			// end namespace

#endif			// VIEWWINDOW_H_