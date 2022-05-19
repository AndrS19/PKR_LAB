#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.1/Lab_6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* p = new Elem;
			p->info = 4;
			Assert::AreEqual(4, p->info);
			delete p;
		}
	};
}