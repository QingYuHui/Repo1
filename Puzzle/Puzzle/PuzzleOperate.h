#ifndef PUZZLEOPERATE_H_
#define PUZZLEOPERATE_H_

#include <sstream>
#include <ctime>
#include "../../FileAndString/String.h"

namespace Puzzle {

	using namespace System;
	using namespace System::IO;
	using namespace System::Drawing;
	using namespace System::Timers;

	public ref class PuzzleOperate
	{
	private:
		array<Bitmap^>^					blockBitmap;
		array<int>^						blockIndex;
		array<int>^						blockDeg;
		Bitmap^							picBitmap;
		int								blocks;						// the number of block
		int								iBlockWidth;				// block's width
		int								iEmptyBlock;
		//int							iBlockHeigh;				// block's heigh, which is useless for a square block
		bool							bEnable;					// is the PuzzleOperate initialize success ?
		unsigned int					iClickCount;				// totally mouse click count
		System::Timers::Timer^			gameTimer;					// totally time for the puzzle
		String^							sStartTime;					// game start time
		unsigned int					uiTotalTime;				// game totally time, i store it use second

	public:
		PuzzleOperate()
		{
			bEnable = false;
			ClearCount();

			// set timer
			gameTimer = gcnew System::Timers::Timer(1000);
			gameTimer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &PuzzleOperate::gameTimer_Elapsed);
			gameTimer->AutoReset = true;
			gameTimer->Enabled = false;
		}
		~PuzzleOperate() {}
	private:
		void DrawBitmap(System::Drawing::Graphics^ myGraphics_p)
		{
			myGraphics_p->Clear(System::Drawing::Color::White);

			// draw each bitmap to picturebox
			for (int i = 0; i < blocks*blocks; i++)
			{
				int posX, posY;
				posX = i % blocks;
				posY = i / blocks;

				int iIndex = blockIndex[i];
				if (iIndex != iEmptyBlock)
					myGraphics_p->DrawImage(blockBitmap[iIndex], posX * iBlockWidth, posY * iBlockWidth);
			}
		}
		// swap the array
		// lhs and rhs are array's index
		inline void SwapArray(int lhs, int rhs)
		{
			int tmp = blockIndex[lhs];
			blockIndex[lhs] = blockIndex[rhs];
			blockIndex[rhs] = tmp;
		}
		// after shuffle we need clear this variables
		void ClearCount()
		{
			uiTotalTime = 0;
			iClickCount = 0;
		}
		// is win ?
		bool CheckStatus()
		{
			for (int i = 0; i < blocks * blocks; i++)
			{
				if (blockDeg[i] != 0 && (i != iEmptyBlock))
					return false;
			}
			for (int i = 0; i < blocks * blocks; i++)
			{
				if (blockIndex[i] != i)
					return false;
			}
			// the puzzle finish
			// should stop the timer
			gameTimer->Enabled = false;

			// clear empty block, and make empty block can display
			// this step not finish
			iEmptyBlock = -1;

			return true;
		}
		// calculate two time's differ.
		// tm0 is early time, tm1 is later time.
		TimeSpan TimeSub(String^ tm0, String^ tm1) {
			DateTime dtm0 = Convert::ToDateTime(tm0);
			DateTime dtm1 = Convert::ToDateTime(tm1);
			TimeSpan dtmLag = dtm1.Subtract(dtm0);
			return dtmLag;
		}
		void gameTimer_Elapsed(System::Object^ sender, System::Timers::ElapsedEventArgs^ e)
		{
			String^ sCurrentTime = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
			// Day running time
			TimeSpan tDaySpan = TimeSub(sStartTime, sCurrentTime);
			uiTotalTime = (unsigned int)(tDaySpan.TotalSeconds);
		}
		void RotateBlockBack()
		{
			for (int i = 0; i < blocks * blocks; i++)
			{
				System::Drawing::Graphics^ mGraphics = System::Drawing::Graphics::FromImage(blockBitmap[blockIndex[i]]);
				System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();
				
				// rotate back
				matrix->RotateAt(360.0f - blockDeg[blockIndex[i]], System::Drawing::PointF(iBlockWidth / 2.0f, iBlockWidth / 2.0f));
				mGraphics->Transform = matrix;
				mGraphics->DrawImage(blockBitmap[blockIndex[i]], 0, 0);

				// normally blockDeg[i] is 0
				blockDeg[blockIndex[i]] += (360 - blockDeg[blockIndex[i]]);
				blockDeg[blockIndex[i]] %= 360;
			}
		}
	public:
		bool Initialize(String^	sPath, System::Drawing::Graphics^ myGraphics_p, int d, int w, int h)
		{
			if (bEnable)
				return true;

			if (!File::Exists(sPath))
			{
				bEnable = false;
				return false;
			}

			picBitmap = gcnew Bitmap(Image::FromFile(sPath));
			blockBitmap = gcnew array<Bitmap^>(d*d);
			blockIndex = gcnew array<int>(d*d);
			blockDeg = gcnew array<int>(d*d);

			bEnable = true;
			blocks = d;

			iBlockWidth = w / blocks;

			// draw picture to each bitmaps
			for (int i = 0; i < blocks*blocks; i++)
			{
				int posX, posY;
				posX = i % blocks;
				posY = i / blocks;
				blockBitmap[i] = gcnew Bitmap(iBlockWidth, iBlockWidth);
				blockBitmap[i] = picBitmap->Clone(System::Drawing::Rectangle(posX * iBlockWidth, posY * iBlockWidth, iBlockWidth, iBlockWidth), picBitmap->PixelFormat);
			}

			// fill bitmap array by increase number
			for (int i = 0; i < blocks * blocks; i++)
			{
				blockIndex[i] = i;
				blockDeg[i] = 0;
			}

			// we don't have any empty block from the beginning
			iEmptyBlock = -1;

			DrawBitmap(myGraphics_p);

			// initialize totally count
			ClearCount();
			// initialize start time
			sStartTime = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
			// start timer
			if (!gameTimer->Enabled)
			{
				gameTimer->Enabled = true;
			}

			return true;
		}

		// re-initialize, it is use for restart a new puzzle with new picture
		void ReInitialize(System::Drawing::Graphics^ myGraphics_p, String^	sPath)
		{
			delete picBitmap;
			delete blockBitmap;
			delete blockIndex;
			delete blockDeg;

			// must delete the useless memory
			GC::Collect();

			bEnable = false;

			Initialize(sPath, myGraphics_p, blocks, iBlockWidth * blocks, iBlockWidth * blocks);
		}

		// re-initialize, it is use for restart a new puzzle with old picture
		void ReInitialize(System::Drawing::Graphics^ myGraphics_p)
		{
			// if has not initialize, then return
			if (!bEnable)
				return;

			// fill bitmap array by increase number
			for (int i = 0; i < blocks * blocks; i++)
			{
				blockIndex[i] = i;
			}
			// retate the block to 0 degrees
			RotateBlockBack();
			// we don't have any empty block from the beginning
			iEmptyBlock = -1;
			// initialize totally count
			ClearCount();
			// initialize start time
			sStartTime = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");

			// draw picture
			DrawBitmap(myGraphics_p);

			// start timer
			if (!gameTimer->Enabled)
			{
				gameTimer->Enabled = true;
			}
		}

		// new picture's order
		void ShuffleBitmapOrd(System::Drawing::Graphics^ myGraphics_p)
		{
			if (!bEnable)
				return;

			srand(static_cast<unsigned int>(time(nullptr)));

			// shuffle the array
			// the follow mothods is wrong
			// simply swap number will make matrix can not revert

			// for (int i = 0; i < blocks * blocks; i++)
			// {
			// 	int r = rand() % (blocks * blocks);
			//	SwapArray(i, r);
			// }

			// choose a empty block
			// we can not use random
			// use the last one is a simple solution
			// iEmptyBlock = rand() % (blocks * blocks);

			iEmptyBlock = (blocks * blocks) - 1;

			int empty = blockIndex[iEmptyBlock];

			for (int i = 0; i < 200; i++)
			{
				// 0 move empty block up
				// 1 move empty block left
				// 2 move empty block down
				// 3 move empty block right
				int direction = rand() % 4;
				int NewIndex = -1;

				switch (direction)
				{
				case 0:
					NewIndex = empty - blocks;		// the block's index which on the top of the empty block
					if (NewIndex > 0)
					{
						SwapArray(empty, NewIndex);
						empty = NewIndex;
					}
					break;
				case 1:
					NewIndex = empty - 1;		// the block's index which on the left of the empty block
					if (NewIndex >= 0 && empty%blocks != 0)
					{
						SwapArray(empty, NewIndex);
						empty = NewIndex;
					}
					break;
				case 2:
					NewIndex = empty + blocks;		// the block's index which on the bottom of the empty block
					if (NewIndex < blocks * blocks)
					{
						SwapArray(empty, NewIndex);
						empty = NewIndex;
					}
					break;
				case 3:
					NewIndex = empty + 1;		// the block's index which on the right of the empty block
					if (NewIndex < blocks * blocks && NewIndex%blocks != 0)
					{
						SwapArray(empty, NewIndex);
						empty = NewIndex;
					}
					break;
				default:
					break;
				}
			}
			
			// initialize totally count
			ClearCount();

			// draw bitmap
			DrawBitmap(myGraphics_p);
		}
		// new picture's angle
		void ShuffleBitmapAng(System::Drawing::Graphics^ myGraphics_p)
		{
			if (!bEnable)
				return;

			srand(static_cast<unsigned int>(time(nullptr)));

			// shuffle the array
			// we need not shuffle the empty block
			for (int i = 0; i < blocks * blocks - 1; i++)
			{
				int r = rand() % 4;

				System::Drawing::Graphics^ mGraphics = System::Drawing::Graphics::FromImage(blockBitmap[i]);
				System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();
				matrix->RotateAt(90.0f * r, System::Drawing::PointF(iBlockWidth / 2.0f, iBlockWidth / 2.0f));
				mGraphics->Transform = matrix;
				mGraphics->DrawImage(blockBitmap[i], 0, 0);
				blockDeg[i] = 90 * r;
			}

			// initialize totally count
			ClearCount();

			// draw bitmap
			DrawBitmap(myGraphics_p);
		}

		// param [in]: pt is mouse click point
		bool MoveBlock(System::Drawing::Graphics^ myGraphics_p, const Geo::TPoint& pt)
		{
			if (!bEnable)
				return false;

			int iX = static_cast<int>(pt.X() / iBlockWidth);
			int iY = static_cast<int>(pt.Y() / iBlockWidth);

			// index is the picture's index which are clicked
			int Index = iY * blocks + iX;

			// click on the empty block
			// return false
			if (blockIndex[Index] == iEmptyBlock)
				return false;

			do {
				// the empty block on the top ?
				int IndexUp = ((iY - 1) * blocks) + iX;
				if (IndexUp >= 0)
				{
					// if this block is empty block
					// swap click block with empty blcok
					if (blockIndex[IndexUp] == iEmptyBlock)
					{
						SwapArray(IndexUp, Index);
						iClickCount++;
						break;
					}
				}

				// the empty block on the left ?
				int IndexLeft = (iY * blocks) + iX - 1;
				if (IndexLeft >= 0 && iX != 0 )
				{
					// if this block is empty block
					// swap click block with empty blcok
					if (blockIndex[IndexLeft] == iEmptyBlock)
					{
						SwapArray(IndexLeft, Index);
						iClickCount++;
						break;
					}
				}

				// the empty block on the right ?
				int IndexRight = (iY * blocks) + iX + 1;
				if (IndexRight >= 0 && iX != (blocks - 1))
				{
					// if this block is empty block
					// swap click block with empty blcok
					if (blockIndex[IndexRight] == iEmptyBlock)
					{
						SwapArray(IndexRight, Index);
						iClickCount++;
						break;
					}
				}

				// the empty block on the bottom ?
				int IndexBottom = ((iY + 1) * blocks) + iX;
				if (IndexBottom < (blocks * blocks))
				{
					// if this block is empty block
					// swap click block with empty blcok
					if (blockIndex[IndexBottom] == iEmptyBlock)
					{
						SwapArray(IndexBottom, Index);
						iClickCount++;
						break;
					}
				}
			} while (0);

			// draw bitmap
			DrawBitmap(myGraphics_p);

			return CheckStatus();
		}

		// param [in]: pt is mouse click point
		bool RotateBlock(System::Drawing::Graphics^ myGraphics_p, const Geo::TPoint& pt)
		{
			if (!bEnable)
				return false;

			int iX = static_cast<int>(pt.X() / iBlockWidth);
			int iY = static_cast<int>(pt.Y() / iBlockWidth);

			int Index = iY * blocks + iX;
			// click on the empty block
			if (blockIndex[Index] == iEmptyBlock)
				return false;

			System::Drawing::Graphics^ mGraphics = System::Drawing::Graphics::FromImage(blockBitmap[blockIndex[Index]]);
			System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();
			matrix->RotateAt(90, System::Drawing::PointF(iBlockWidth / 2.0f, iBlockWidth / 2.0f));
			mGraphics->Transform = matrix;
			mGraphics->DrawImage(blockBitmap[blockIndex[Index]], 0, 0);

			blockDeg[blockIndex[Index]] += 90;
			blockDeg[blockIndex[Index]] %= 360;

			iClickCount++;

			// draw bitmap
			DrawBitmap(myGraphics_p);

			return CheckStatus();
		}

		// save puzzle data
		bool WriteTo(String^ sFilePath)
		{
			if (!bEnable)
				return false;

			try
			{
				if (File::Exists(sFilePath))
				{
					System::IO::FileInfo^ DelFile = gcnew System::IO::FileInfo(sFilePath);
					DelFile->Delete();
				}
				
				FileStream^ file = gcnew FileStream(sFilePath, FileMode::CreateNew);
				StreamWriter^ sw = gcnew StreamWriter(file);
				
				std::ostringstream os;

				// out put blockIndex[i]
				for (int i = 0; i < blockIndex->Length; i++)
				{
					os << blockIndex[i];
				}
				sw->WriteLine(TString::ToDotNetString(os.str()));

				os.str("");			// clear();

				// out put blockDeg[i];
				for (int i = 0; i < blockDeg->Length; i++)
				{
					os << (blockDeg[i] / 90);
				}
				sw->WriteLine(TString::ToDotNetString(os.str()));

				os.str("");			// clear();

				// blocks
				os << blocks;
				sw->WriteLine(TString::ToDotNetString(os.str()));

				os.str("");			// clear();

				// iEmptyBlock
				os << iEmptyBlock;
				sw->WriteLine(TString::ToDotNetString(os.str()));

				os.str("");			// clear();

				// iClickCount
				os << iClickCount;
				sw->WriteLine(TString::ToDotNetString(os.str()));

				os.str("");			// clear();

				// uiTotalTime
				os << uiTotalTime;
				sw->WriteLine(TString::ToDotNetString(os.str()));

				sw->Flush();
				sw->Close();
				file->Close();
			}
			catch (Exception^ e)
			{
				e->ToString();
				return false;
			}
			return true;
		}


		bool ReadFrom(String^ sFilePath, System::Drawing::Graphics^ myGraphics_p)
		{
			try
			{
				if (!File::Exists(sFilePath))
					return false;

				FileStream^ file = gcnew FileStream(sFilePath, FileMode::Open, FileAccess::Read);
				StreamReader^ rw = gcnew StreamReader(file);
				std::string line1 = TString::ToStdString(rw->ReadLine());			// blockIndex[i]
				std::string line2 = TString::ToStdString(rw->ReadLine());			// blockDeg[i]
				String^ line3 = rw->ReadLine();			// blocks
				String^ line4 = rw->ReadLine();			// iEmptyBlock
				String^ line5 = rw->ReadLine();			// iClickCount
				String^ line6 = rw->ReadLine();			// uiTotalTime

				if (bEnable)
				{
					if (Convert::ToInt32(line3) != blocks)
						return false;
					iEmptyBlock = Convert::ToInt32(line4);
					iClickCount = Convert::ToInt32(line5);
					uiTotalTime = Convert::ToInt32(line6);

					if (line1.length() == blockIndex->Length)
					{
						for (size_t i = 0; i < line1.length(); i++)
						{
							char ch = line1[i];
							blockIndex[i] = ch - '0';
						}
					}
					else {
						return false;
					}

					if (line2.length() == blockDeg->Length)
					{
						for (size_t i = 0; i < line2.length(); i++)
						{
							char ch = line2[i];
							if (0 == ch - '0')
								blockDeg[i] = 0;
							else if (1 == ch - '0')
								blockDeg[i] = 90;
							else if (2 == ch - '0')
								blockDeg[i] = 180;
							else if (3 == ch - '0')
								blockDeg[i] = 270;
							else
								return false;
						}
					}
					else {
						return false;
					}
				}

				DrawBitmap(myGraphics_p);
			}
			catch (Exception^ e)
			{
				e->ToString();
				return false;
			}
			return true;
		}

		// get totally time
		unsigned int GetTotalTime()
		{
			return uiTotalTime;
		}

		unsigned int GetTotalClick()
		{
			return iClickCount;
		}
		// get puzzleOperate enable or not
		bool GetEnable()
		{
			return bEnable;
		}
		
	}; // end class PuzzleOperate
}			// namespace Puzzle
#endif // #ifndef PUZZLEOPERATE_H_