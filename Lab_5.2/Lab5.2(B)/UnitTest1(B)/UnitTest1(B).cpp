#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2(B)/Lab5.2(B).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1B
{
	TEST_CLASS(UnitTest1B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char filename[15] = "file.bat";
			int t = Maths_4(filename);
			Assert::AreEqual(t, 0);
		}
	};
}
