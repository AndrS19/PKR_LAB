#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.3(Recursive method)/Lab_6.3(Recursive method).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;
			int i = -10;
			if (i <= 10) {
				Enqueue(first, last, i);
				CreateList(first, last, i + 1);
			}
		}
	};
}