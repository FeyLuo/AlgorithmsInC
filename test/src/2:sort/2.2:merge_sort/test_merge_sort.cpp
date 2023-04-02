#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"
#include "sort.h"

TEST_GROUP(sort_group)
{
   void setup()
   {
   }

   void teardown()
   {

   }
};

TEST_GROUP(qa_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST(sort_group, topdown_merge_sort_test)
{
    char a[] = "MERGESORTEXAMPLE";
    Template *char_array  = Template_array(CHAR, sizeof(a), a);
    topdown_merge_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

TEST(sort_group, bottomup_merge_sort_test)
{
    char a[] = "MERGESORTEXAMPLE";
    Template *char_array  = Template_array(CHAR, sizeof(a), a);
    bottomup_merge_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}