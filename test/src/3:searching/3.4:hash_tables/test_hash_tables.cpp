#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"
#include <stdlib.h>

TEST_GROUP(search_group)
{
   void setup()
   {
   }

   void teardown()
   {
   }
};

TEST(search_group, hash_tables_test)
{
}


int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}