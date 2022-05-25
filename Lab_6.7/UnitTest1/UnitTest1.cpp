#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.7/Lab_6.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* first = NULL,
				* last = NULL;

			Enqueue(first, last, "One", 5, 1);
			Enqueue(first, last, "Two", 4.5, 1);
			Enqueue(first, last, "Three", 3, 0);
			Enqueue(first, last, "Four", 3.5, 0);
			Enqueue(first, last, "Five", 4.6, 1);

			int k = Find(first, 0, 3);

			Assert::AreEqual(k, 1);
		}
	};
}