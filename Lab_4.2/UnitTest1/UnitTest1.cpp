#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4.2/Lab_4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char fname[10] = "t.txt";
			ProcessTXT(fname);
		}
	};
}