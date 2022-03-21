#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1.2/Account.cpp"
#include "../OOP_Lab_1.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Account a;
			double x, y, z;
			x = a.setSumma(4300.23);
			y = a.setPercent(5.7);
			z = a.setNo(224343);
			bool t = true;
			t = a.Init(z, y, x);
			Assert::IsTrue(t);
		}
	};
}
