#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

TEST_GROUP(FirstTestGroup)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST(FirstTestGroup, FirstTest)
{
   FAIL("Fail me!");
}

int main(int argc, char** argv)
{
   return RUN_ALL_TESTS(argc, argv);
}