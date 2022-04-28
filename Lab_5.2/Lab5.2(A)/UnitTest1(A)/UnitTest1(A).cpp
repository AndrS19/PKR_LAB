#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2(A)/Lab5.2(A).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1A
{
	TEST_CLASS(UnitTest1A)
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
