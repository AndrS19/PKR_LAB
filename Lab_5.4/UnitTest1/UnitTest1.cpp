#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.4/Lab_5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char filename[15] = "filename.bat";
			int t = SearchBIN(filename, "Камера");
			Assert::AreEqual(t, -1);
		}
	};
}