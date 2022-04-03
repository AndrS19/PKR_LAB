#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.3/Lab3.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int N = 5;
			Price* p = new Price[N];
			p[0] = { "Монітор", "Фокстрот", 3000 };
			p[1] = { "Мобільний телефон", "Розетка", 7500 };
			p[2] = { "Електросамокат", "Епіцентр", 15000 };
			p[3] = { "Колонки", "Комфі", 350 };
			p[4] = { "Навушники", "Мобіманія", 255 };

			Price* r = new Price[N];
			r[0] = { "Електросамокат", "Епіцентр", 15000 };
			r[1] = { "Колонки", "Комфі", 350 };
			r[2] = { "Навушники", "Мобіманія", 255 };
			r[3] = { "Мобільний телефон", "Розетка", 7500 };
			r[4] = { "Монітор", "Фокстрот", 3000 };

			Sort(p, N);

			for (int i = 0; i < N; i++)
			{
				Assert::AreEqual(p[i].product_name, r[i].product_name);
				Assert::AreEqual(p[i].store_name, r[i].store_name);
				Assert::AreEqual(p[i].money, r[i].money);
			}
		}
	};
}