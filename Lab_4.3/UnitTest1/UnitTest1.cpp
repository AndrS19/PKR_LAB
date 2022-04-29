#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4.3/Lab_4.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char filename[15] = "file.txt";
			PrintTXT(filename);
		}
	};
}
