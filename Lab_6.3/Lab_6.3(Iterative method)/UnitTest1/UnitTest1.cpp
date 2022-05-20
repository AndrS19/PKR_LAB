#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.3(Iterative method)/Lab_6.3(Iterative method).cpp"

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

			Enqueue(first, last, 50);

			Assert::AreEqual(first->info, 50);
		}
	};
}