#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.2(B)/Lab3.2(B).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestB
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
			Assert::AreEqual(2, BinSearch(p, 5, "Кандиба", 4, MATEM_EKONOM));
		}

		TEST_METHOD(TestMethod2)
		{
			Student* p = new Student[7];
			p[0] = { "Кандиба", 4, MATEM_EKONOM, 5, 3, 5 };
			p[1] = { "Майстренко", 1, TRUD_NAVCH, 5, 5, 5 };
			p[2] = { "Ярмола", 1, KOMP_NAYK, 4, 4, 5 };
			p[3] = { "Худенко", 3, INFORMATUKA, 3, 4, 4 };
			p[4] = { "Пустова", 2, FIZ_MATEM, 3, 3, 4 };
			p[5] = { "Кандиба", 1, MATEM_EKONOM, 4, 4, 4 };
			p[6] = { "Мироненко", 4, KOMP_NAYK, 4, 3, 4 };
			Sort(p, 7);
			Assert::AreEqual(5, BinSearch(p, 7, "Пустова", 2, FIZ_MATEM));
		}
	};
}