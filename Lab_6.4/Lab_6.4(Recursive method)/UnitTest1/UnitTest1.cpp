#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4(Recursive method)/Lab_6.4(Recursive method).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* T = NULL;
			Insert(T, 5);
			Assert::AreEqual(T->info, 5);
		}
	};
}