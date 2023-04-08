#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"
#include "sort.h"

Template *char_array, *int_array;

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
    char_array  = Template_array(CHAR, sizeof(a), a);
    topdown_merge_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

TEST(sort_group, bottomup_merge_sort_test)
{
    char a[] = "MERGESORTEXAMPLE";
    char_array  = Template_array(CHAR, sizeof(a), a);
    bottomup_merge_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);

    int b[] = {1,3,2,3,1};
    int_array = Template_array(INT, 5, b);
    bottomup_merge_sort(int_array);
    CHECK(is_sorted(int_array));
    free(int_array);
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}