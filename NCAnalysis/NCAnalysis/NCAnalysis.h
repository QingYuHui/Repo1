#pragma once

#include <string>
#include "../../FileAndString/FileAndDirs.h"
#include "../../FileAndString/String.h"

namespace NCAnalysis {

	typedef enum {
		FastMove,				// G00
		LinearMove,				// G01
		KnifePlunge,			// M14
		KnifeLeft,				// M15
		SetSpeed				// OVERRIDE FEED_FACT
	} TActionType;

	struct node {
		TActionType TAction;
		double		dParameter1;
		double		dParameter2;
		double		dParameter3;
		double		dParameter4;
		struct node *next;
		struct node *pre;
	};

	class NCAnalysis
	{
	public:
		NCAnalysis()
		{
			head = nullptr;
		};

		~NCAnalysis() {};
		
		bool LoadFile(std::string str)
		{
			return ReadFile(str);
		}
	private:
		struct node ** head;

		bool ReadFile(std::string str)
		{
			return false;
		}
	};	// class NCAnalysis
}	// namespace NCAnalysis