#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.4(2)/lab12.4(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestInsertAndIncrease)
        {
            Elem* L = NULL;
            insertRec(L, L, 10);
            insertRec(L, L, 20);

            Assert::AreEqual(10, L->info, L"First element should be 20 right after insertion.");

            increaseListValuesRec(L, 5);

            Assert::AreEqual(15, L->info, L"First element should be 25 after increment.");
            Assert::AreEqual(25, L->link->info, L"Second element should be 15 after increment.");
        }

        TEST_METHOD(TestPrintAndIncrease)
        {
            Elem* L = NULL;
            insertRec(L, L, 1);
            insertRec(L, L, 2);

            increaseListValuesRec(L, 5);

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            printListRec(L);
            std::string output = buffer.str();
            std::cout.rdbuf(old);

            Assert::AreEqual(std::string("6 7 \n"), output, L"Output should match the list contents after increase.");
        }
	};
}