#pragma once

#include <vector>
#include <ctime>
#include <Windows.h>
#include <process.h>
#include <fstream>

namespace Sort {

	using namespace System::Threading;

	// select sort methods
	enum ESort
	{
		Select = 0,
		Insertion = 1,
		Shell = 2,
		Merge = 3
	};

	public class SortOperate
	{
	private:				
		static unsigned int			pLen;				// the *p's length
		static ESort				SortMethod;			// use for single step, which sore is selected
		static int					p[200];				// store sort data
		HANDLE						SortThread;			// sort thread
	public:
		static HANDLE				PMutex;				// mutex lock
	public:
		SortOperate() {}

		~SortOperate() {}

		// get thread status
		// if the status is WAIT_OBJECT_0, then thread (sort) is finish
		bool GetThreadStatus()
		{
			DWORD dwRet = WaitForSingleObject(SortThread, 1);
			if (WAIT_OBJECT_0 == dwRet)
				return true;
			return false;
		}
		// get the data
		const int * GetSortData()
		{
			if (p != nullptr)
				return p;
			return nullptr;
		}
		int	GetSortData(unsigned int index)
		{
			if (0 <= index && index <= pLen)
				return p[index];
			return 0;
		}

		// fill data to array (vector),
		// count: how many datas £¿ £¨from 0 to 200£©
		void FillSortData(unsigned int count, double MaxFact = 500.0)
		{
			if (count < 1)
				return;
			
			// dFact will make values in vectore fit with picturebox's height
			double dFact = MaxFact / count;

			pLen = count;

			for (size_t i = 1; i < count; i++)
			{
				p[i] = static_cast<int>(dFact * i);
			}
			p[0] = (p[1] / 2 == 0) ? 1 : p[1] / 2;
		}

		// shuffle the data
		void ShuffleSortData()
		{
			srand(static_cast<unsigned int>(time(nullptr)));

			for (unsigned int i = 0; i < pLen; i++)
			{
				std::swap(p[i], p[rand() % pLen]);
			}
		}

		// sort
		void DoSortInChildThraed(int sortType)
		{
			// set method
			switch (sortType)
			{
			case ESort::Select:
				SortMethod = ESort::Select;
				break;
			case ESort::Insertion:
				SortMethod = ESort::Insertion;
				break;
			case ESort::Shell:
				SortMethod = ESort::Shell;
				break;
			case ESort::Merge:
				SortMethod = ESort::Merge;
				break;
			default:
				break;
			}

			// create a mutex
			PMutex = CreateMutex(NULL, FALSE, LPCWSTR("SortThread"));
			// create a child thread
			SortThread = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, NULL, 0, NULL);

			return;
		}
		
		// child thread, use for sort operate
		static unsigned int _stdcall ThreadProc(LPVOID pM)
		{
			switch (SortMethod)
			{
			case ESort::Select:
				SelectMethod();
				break;
			case ESort::Insertion:
				InsertionMethod();
				break;
			case ESort::Shell:
				ShellMethod();
				break;
			case ESort::Merge:
				MergeMethod();
				break;
			default:
				break;
			}
			return 0;
		}

		// select
		static void SelectMethod()
		{
			for (size_t i = 0; i < pLen; i++)
			{
				// lock data
				WaitForSingleObject(PMutex, INFINITE);
				
				unsigned int min = i;
				for (size_t j = i+1; j < pLen; j++)
				{
					if (p[j] < p[min])
						min = j;
				}
				std::swap(p[i], p[min]);
				
				// unlock data
				ReleaseMutex(PMutex);

				// sleep thread
				Sleep(50);
			}

			return;
		}
		// select
		void SelectMethodForOutput(int *q, std::string path)
		{
			std::ofstream outfile(path);
			if (!outfile)
				return;

			outfile << "len=10" << std::endl;
			for (int i = 0; i < 10; i++)
				outfile << q[i] << " ";
			outfile << std::endl;
			outfile << "a==i" << std::endl;
			outfile << "b==j" << std::endl;
			outfile << "c==min" << std::endl;
			
			
			outfile << "c=0" << std::endl;
			for (size_t i = 0; i < 10; i++)
			{
				unsigned int min = i;

				outfile << "a=" << i << std::endl;
				outfile << "c=" << min << std::endl;

				for (size_t j = i + 1; j < 10; j++)
				{
					outfile << "b=" << j << std::endl;
					outfile << "LOH" << j << "," << min << std::endl;
					if (q[j] < q[min])
					{
						min = j;
						outfile << "c=" << min << std::endl;
					}
					outfile << "STEP" << std::endl;
				}
				std::swap(q[i], q[min]);
				outfile << "SWP" << i << "," << min << std::endl;
				outfile << "STEP" << std::endl;
				outfile << "ENDL" << std::endl;
			}

			outfile.close();

			return;
		}
		static void InsertionMethod()
		{
			for (size_t i = 1; i < pLen; i++)
			{
				// lock data
				WaitForSingleObject(PMutex, INFINITE);

				for (int j = i; j > 0 && (p[j] < p[j - 1]); j--)
				{
					std::swap(p[j], p[j - 1]);
				}

				// unlock data
				ReleaseMutex(PMutex);

				// sleep thread
				Sleep(50);
			}

			return;
		}
		void InsertionMethodForOutput(int *q, std::string path)
		{
			std::ofstream outfile(path);
			if (!outfile)
				return;

			// the data length is 10
			outfile << "len=10" << std::endl;
			for (int i = 0; i < 10; i++)
				outfile << q[i] << " ";		// output data
			outfile << std::endl;
			outfile << "a==i" << std::endl;	// need parameter a to display i
			outfile << "b==j" << std::endl; // need parameter b to display j

			for (size_t i = 1; i < 10; i++)
			{
				outfile << "a=" << i << std::endl;
				for (int j = i; j > 0; j--)
				{
					outfile << "b=" << j << std::endl;
					outfile << "LOH" << j << "," << j - 1 << std::endl;
					outfile << "STEP" << std::endl;
					if (q[j] >= q[j - 1])
					{
						outfile << "STEP" << std::endl;
						break;
					}
					
					std::swap(q[j], q[j - 1]);
					outfile << "SWP" << j << "," << j - 1 << std::endl;
					outfile << "STEP" << std::endl;
				}
			}

			outfile.close();

			return;
		}
		static void ShellMethod()
		{
			int N = pLen;
			int h = 1;
			while (h < N / 3)
				h = 3 * h + 1;	//  h = 1, 4, 13, 40, 121, 364, 1093, ...
			while (h >= 1)
			{
				for (int i = h; i < N; i++)
				{
					// lock data
					WaitForSingleObject(PMutex, INFINITE);

					for (int j = i; j >= h && p[j] <= p[j-h]; j -= h)
						std::swap(p[j], p[j - h]);

					// unlock data
					ReleaseMutex(PMutex);

					// sleep thread
					Sleep(50);
				}
				h = h / 3;
			}

			return;
		}

		static void MergeMethod()
		{
			int lo = 0;
			// the hi is count from 0
			// so make sure: hi = length - 1
			int hi = pLen - 1;

			int *aux = new int[pLen];
			DoSort(p, aux, lo, hi);

			delete [] aux;

			return;
		}
		//void mysort(int a[], int aux[], int lo, int hi)
		static void DoSort(int *a, int *aux, int lo, int hi)
		{
			if (hi <= lo) return;

			int mid = lo + (hi - lo) / 2;
			DoSort(a, aux, lo, mid);
			DoSort(a, aux, mid + 1, hi);
			DoMerge(a, aux, lo, mid, hi);		
		}

		static void DoMerge(int *a, int *aux, int lo, int mid, int hi)
		{
			int i = lo;
			int j = mid + 1;

			for (int k = lo; k <= hi; k++)
				aux[k] = a[k];

			for (int k = lo; k <= hi; k++)
			{
				// lock data
				WaitForSingleObject(PMutex, INFINITE);

				if (i > mid)		a[k] = aux[j++];
				else if (j > hi)	a[k] = aux[i++];
				else if (aux[j] < aux[i])	a[k] = aux[j++];
				else						a[k] = aux[i++];

				// unlock data
				ReleaseMutex(PMutex);

				// sleep thread
				Sleep(25);
			}
		}

	}; // end class Sort

}			// namespace Sort
