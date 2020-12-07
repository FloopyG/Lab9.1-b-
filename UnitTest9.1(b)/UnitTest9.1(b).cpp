#include "pch.h"
#include <string>
#include <iomanip>
#include <Windows.h>
#include "CppUnitTest.h"
#include "../Lab9.1(b).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91b
{
	TEST_CLASS(UnitTest91b)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 1;
			Student* s = new Student[k];
			s->gradeMath = 0;
			s->gradePhys = 0;
			int t = goodMathPhys(s, k);
			Assert::AreEqual(t, 0);

		}
	};
}
