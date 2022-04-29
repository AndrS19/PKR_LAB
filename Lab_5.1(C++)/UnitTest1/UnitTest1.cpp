#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1(C++)/Lab_5.1(C++).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[15] = "file.dat";
			char newfile[15] = "newfile.dat";
			ProcessBIN(filename, newfile);
		}
	};
}