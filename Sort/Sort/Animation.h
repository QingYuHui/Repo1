#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace Sort {

	public class TDataQueue
	{
	public:
		TDataQueue() {}

		~TDataQueue() {}
		enum TAction
		{
			NUL = 0,
			LOH = 1,
			SWP = 2,
			ENDL = 3
		};
		struct TItem
		{
			int A;
			int B;
			int C;
			int D;
			unsigned int Step;
			TAction	act;
			int actpar1;
			int actpar2;
		};
		std::vector<TItem>		Queue;					// all my items
		int						data[10];					// sort data in demo
		std::string				paraA;
		std::string				paraB;
		std::string				paraC;
		std::string				paraD;
		unsigned int			TotalStep;
	
	private:
		void ClearQueue()
		{
			std::vector<TItem> t;
			t.swap(Queue);
		}
		bool GetTotoal(std::string str)
		{
			int begin = 0;
			begin = str.find("len=");
			if (begin == std::string::npos)
				return false;

			std::string lenStr = str.substr(4);
			if (10 != atoi(lenStr.c_str()))
				return false;

			return true;
		}
		bool FillData(std::string str)
		{
			try
			{
				std::istringstream is(str);

				is >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] >> data[5] >> data[6] >> data[7] >> data[8] >> data[9];
			}
			catch (const std::exception&)
			{
				return false;
			}
			return true;
		}
	public:
		bool LoadAnimation(std::string path)
		{
			std::ifstream in(path);
			if (!in.is_open())
				return false;

			std::string str;

			// read one line
			if (!std::getline(in, str))
				return false;
			// get total length
			if (!GetTotoal(str))
				return false;

			// read one line
			if (!std::getline(in, str))
				return false;
			// fill data
			if (!FillData(str))
				return false;

			// clear vectore
			ClearQueue();

			// temp parameter
			int count = 1;
			int a = 0;
			int b = 0;
			int c = 0;
			int d = 0;

			while (std::getline(in, str))
			{
				int begin = 0;

				TItem item;

				item.A = a;
				item.B = b;
				item.C = c;
				item.D = d;
				item.Step = count;
				item.act = TAction::NUL;

				// set default parameter
				begin = str.find("==");
				if (begin != std::string::npos)
				{
					std::string para = str.substr(0, 1);
					if (para == "a")
						paraA = str.substr(3);
					else if (para == "b")
						paraB = str.substr(3);
					else if (para == "c")
						paraC = str.substr(3);
					else if (para == "d")
						paraD = str.substr(3);
					continue;
				}

				// set integer
				begin = str.find("=");
				if (begin != std::string::npos)
				{
					std::string para = str.substr(0, 1);
					if (para == "a")
						a = atoi((str.substr(2)).c_str());
					else if (para == "b")
						b = atoi((str.substr(2)).c_str());
					else if (para == "c")
						c = atoi((str.substr(2)).c_str());
					else if (para == "d")
						d = atoi((str.substr(2)).c_str());

					item.A = a;
					item.B = b;
					item.C = c;
					item.D = d;
					// item.Step = count++;
					item.act = TAction::NUL;
					item.actpar1 = -1;
					item.actpar2 = -1;
				}

				// set action low or heigh
				begin = str.find("LOH");
				if (begin != std::string::npos)
				{
					int pos = str.find(",");
					item.actpar1 = atoi((str.substr(3, pos)).c_str());
					item.actpar2 = atoi((str.substr(pos + 1)).c_str());
					item.act = TAction::LOH;
					// item.Step = count++;
				}

				// set action swap
				begin = str.find("SWP");
				if (begin != std::string::npos)
				{
					int pos = str.find(",");
					item.actpar1 = atoi((str.substr(3, pos)).c_str());
					item.actpar2 = atoi((str.substr(pos + 1)).c_str());
					item.act = TAction::SWP;
					// item.Step = count++;
				}

				// set new step
				begin = str.find("STEP");
				if (begin != std::string::npos)
				{
					item.act = TAction::NUL;
					item.Step = ++count;
				}

				begin = str.find("ENDL");
				if (begin != std::string::npos)
				{
					item.act = TAction::ENDL;
					item.Step = ++count;
				}

				Queue.push_back(item);
			}

			// save total step
			TotalStep = count;

			in.close();

			return true;
		}
		bool Reset()
		{

		}
	};
}		// namespace Sort