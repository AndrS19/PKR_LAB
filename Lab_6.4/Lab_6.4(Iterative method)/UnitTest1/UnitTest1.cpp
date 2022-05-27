#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4(Iterative method)/Lab_6.4(Iterative method).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Elem* one;
			one = new Elem;

			one->info = 29;
			one->link = new Elem;

			one->link->info = 60;
			one->link->link = new Elem;

			one->link->link->info = 97;
			one->link->link->link = one;

			Elem* two = NULL;
			Elem* start = one;
			Create(one, 5, 10, 20);

			Assert::AreEqual(two->info, 97);
		};
	}
}