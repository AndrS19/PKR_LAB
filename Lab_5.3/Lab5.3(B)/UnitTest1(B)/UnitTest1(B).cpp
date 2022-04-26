#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.3(B)/Lab5.3(B).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1B
{
	TEST_CLASS(UnitTest1B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char newfile[15] = "newfile.bat";
			int t = BinSearch(newfile, "One", 4, KOMP_NAYK);
			Assert::AreEqual(t, -1);
		}
	};
}
