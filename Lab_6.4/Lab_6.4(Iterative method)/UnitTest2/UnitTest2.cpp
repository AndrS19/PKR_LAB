#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4(Iterative method)/Lab_6.4(Iterative method).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* T = NULL;
			Insert(T, 5);
			Print(T);
			Assert::AreEqual(T->info, 5);
		}
	};
}
