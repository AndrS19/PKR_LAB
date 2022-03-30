#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.1/Lab3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* p = new Student[5];
			p[0] = { "Ярмола", 1, KOMP_NAYK, 4, 4, 5 };
			p[1] = { "Худенко", 3, INFORMATUKA, 3, 4, 4 };
			p[2] = { "Кандиба", 4, MATEM_EKONOM, 5, 3, 5 };
			p[3] = { "Пустова", 2, FIZ_MATEM, 3, 3, 4 };
			p[4] = { "Майстренко", 1, TRUD_NAVCH, 5, 5, 5 };
			Assert::AreEqual(2, Maths_4(p,5));
		}
		TEST_METHOD(TestMethod2)
		{
			Student* p = new Student[5];
			p[0] = { "Ярмола", 1, KOMP_NAYK, 4, 4, 5 };
			p[1] = { "Худенко", 3, INFORMATUKA, 3, 4, 4 };
			p[2] = { "Кандиба", 4, MATEM_EKONOM, 5, 3, 5 };
			p[3] = { "Пустова", 2, FIZ_MATEM, 3, 3, 4 };
			p[4] = { "Майстренко", 1, TRUD_NAVCH, 5, 5, 5 };
			Assert::AreEqual(1, Pedagogy_4(p, 5));
		}
		TEST_METHOD(TestMethod3)
		{
			Student* p = new Student[5];
			p[0] = { "Ярмола", 1, KOMP_NAYK, 4, 4, 5 };
			p[1] = { "Худенко", 3, INFORMATUKA, 3, 4, 4 };
			p[2] = { "Кандиба", 4, MATEM_EKONOM, 5, 3, 5 };
			p[3] = { "Пустова", 2, FIZ_MATEM, 3, 3, 4 };
			p[4] = { "Майстренко", 1, TRUD_NAVCH, 5, 5, 5 };
			Assert::AreEqual((3.3333333333333333), LowMark(p, 5));
		}
	};
}