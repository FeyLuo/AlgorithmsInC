#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"
#include "sort.h"
#include "priority_queues.h"

Template *char_array;

TEST_GROUP(sort_group)
{
   void setup()
   {
   }

   void teardown()
   {
        free(char_array);
   }
};


TEST(sort_group, Kendall_tau_test)
{

}

TEST(sort_group, median_test)
{

}


int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}