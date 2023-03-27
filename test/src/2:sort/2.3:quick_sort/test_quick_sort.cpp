#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "adt.h"
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

TEST(sort_group, quick_sort_test)
{
    char a[] = "MERGESORTEXAMPLE";
    struct adt *char_array  = adt_array(CHAR, sizeof(a), a);
    quick_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

TEST(sort_group, quick_3way_sort_test)
{
    char a[] = "MERGESORTEXAMPLE";
    struct adt *char_array  = adt_array(CHAR, sizeof(a), a);
    quick_3way_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}