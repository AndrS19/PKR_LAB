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
			L* first = NULL;
			L* last = NULL;
			int N = 5;
			int Min = -5;
			int Max = 5;
			for (int i = 0; i < N; i++)
			{
				int x = Min + rand() % (Max - Min + 1);
				Enqueue(first, last, x);
			}
		}
	};
}
