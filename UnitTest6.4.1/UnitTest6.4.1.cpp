#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab6.4.1\lab6.4.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest641
{
	TEST_CLASS(UnitTest641)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1,2,3,4 };
			int s = Sum(a, 4, 0);
			Assert::AreEqual(10, s, 0);
		}
	};
}
