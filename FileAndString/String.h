#ifndef STRING_H_
#define STRING_H_

// This file introduces some tools for string convert

#include <sstream>

namespace TString {

	System::String^ ToDotNetString(const std::string& StdString)
	{
		if (StdString.empty())
			return "";

		// generate a byte-array of sufficient length
		array<System::Byte>^ UTF8Bytes = gcnew array<System::Byte>(StdString.size());

		// convert the char* to a byte-array
		System::Runtime::InteropServices::Marshal::Copy((System::IntPtr)const_cast<char*>(StdString.c_str()), UTF8Bytes, 0, StdString.size());

		//at last do the encoding
		return System::Text::Encoding::UTF8->GetString(UTF8Bytes);
	}

	std::string ToStdString(System::String^ DotNetString)
	{
		if (System::String::IsNullOrEmpty(DotNetString))
			return "";

		// convert the string to UTF8 encoded bytes
		array<System::Byte>^ UTF8Bytes = System::Text::Encoding::UTF8->GetBytes(DotNetString);

		// pin these bytes:
		pin_ptr<System::Byte> PinnedUTF8Bytes = &UTF8Bytes[0];

		// Call the function, typecast from byte* -> char* is required
		return(reinterpret_cast<char*>(PinnedUTF8Bytes));
	}
	
	double ToDouble(System::String^ DotNetString)
	{
		std::stringstream Stream(ToStdString(DotNetString));
		double RetVal = 0;
		Stream >> RetVal;
		return RetVal;
	}
	
	int ToInt(System::String^ DotNetString)
	{
		std::stringstream Stream(ToStdString(DotNetString));
		int RetVal = 0;
		Stream >> RetVal;
		return RetVal;
	}

}  // namespace TString

#endif      // #ifndef STRING_H_