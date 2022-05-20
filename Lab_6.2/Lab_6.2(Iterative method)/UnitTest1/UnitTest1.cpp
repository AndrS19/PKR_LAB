#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.2(Iterative method)/Lab_6.2(Iterative method).cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			L* tmp;
			tmp = new L;
			tmp->info = 10;
			tmp->link = new L;
			tmp->link->info = 20;
			tmp->link->link = new L;
			tmp->link->link->info = 30;

			L* first = tmp->link->link;

			Enqueue(tmp, first, 50);

			Assert::AreEqual(tmp->link->link->link->info, 50);
		}
	};
}