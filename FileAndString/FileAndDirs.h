#ifndef FILEANDDIRS_H_
#define FILEANDDIRS_H_


namespace TFileAndDirs {

	using namespace System;
	using namespace System::IO;

	// return true: directory is esists.
	// return false: directory does not esists.
	bool AssertDirectory(System::String^ Path)
	{
		bool RetVal = System::IO::Directory::Exists(Path);

		return RetVal;
	}

	// return true: create directory successful.
	// return false: create directory failed.
	bool MakeDirectory(System::String^ Path, System::String^ *message)
	{
		try
		{
			System::IO::Directory::CreateDirectory(Path);
		}
		catch (Exception^ e)
		{
			*message = e->Message;
			return false;
		}

		return true;
	}

	// source and dest must be file name
	bool CopyFile(System::String^ source, System::String^ dest, System::String^ *message)
	{
		try
		{
			System::IO::File::Copy(source, dest, true);
		}
		catch (Exception^ e)
		{
			*message = e->Message;
			return false;
		}

		return true;
	}

	// source and dest must be folder name
	// CopyCount[0]: how many dirs are copy ?
	// CopyCount[1]: how many files are copy ?
	bool CopyDirectory(System::String^ source, System::String^ dest, System::String^ *message, int CopyCount[])
	{
		try
		{
			// copy directory
			array<System::String^>^ dirs = System::IO::Directory::GetDirectories(source);
			for (int i = 0; i < dirs->Length; ++i)
			{
				String^ foldername = "\\" + dirs[i]->Substring(dirs[i]->LastIndexOf("\\") + 1);
				if (!AssertDirectory(dest + foldername))
				{
					// folder does not exists
					if (!MakeDirectory(dest + foldername, message))
						return false;
				}
				if (!CopyDirectory(dirs[i], dest + foldername, message, CopyCount))
				{
					return false;
				}
				++CopyCount[0];
			}

			// copy file
			array<System::String^>^ files = System::IO::Directory::GetFiles(source);
			for (int i = 0; i < files->Length; ++i)
			{
				String^ filename = "\\" + files[i]->Substring(files[i]->LastIndexOf("\\") + 1);
				if (!CopyFile(files[i], dest + filename, message))
				{
					return false;
				}
				++CopyCount[1];
			}
		}
		catch (Exception^ e)
		{
			*message = e->Message;
			return false;
		}

		return true;
	}

	// brief Function: Read file
	// param[in] path; file path
	static String^ ReadFile(String^ path)
	{
		if (!File::Exists(path))
			return "";
		StreamReader^ sr = gcnew StreamReader(path, System::Text::Encoding::GetEncoding("gb2312"));
		String^ str = "";
		try
		{
			str = sr->ReadToEnd();
		}
		finally
		{
			if (sr)
				delete (IDisposable^)sr;
		}
		return str;
	}
	static void WriteFile(String^ path, String^ strFile) {
		StreamWriter^ sw = gcnew StreamWriter(path, false, System::Text::Encoding::UTF8);
		try
		{
			sw->Write(strFile);
		}
		finally
		{
			if (sw)
				delete (IDisposable^)sw;
		}
	}
	// brief Write data to file. If have existed,then add the data in the end
	// param[in] path; file path
	// param[in] strFile: file content
	static void AddStringToFile(String^ path, String^ strFile)
	{
		StreamWriter^ sw = File::AppendText(path);
		try
		{
			sw->WriteLine(strFile);
		}
		finally
		{
			if (sw)
				delete (IDisposable^)sw;
		}
	}
#if 0
	//! \brief read file content.
	//! \param[in] sFilePath: 
	//! @return type is std::string.
	static std::string ReadFile(const std::string& sFilePath)
	{
		std::fstream fs;
		std::string str;
		std::string sTemp;
		fs.open(sFilePath.c_str());
		str.clear();
		while (getline(fs, sTemp))
		{
			str = str + sTemp + "\r\n";
		}
		fs.close();

		return str;
	}
#endif

}  // namespace TFileAndDirs

#endif      // #ifndef FILEANDDIRS_H_