#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"
#include "sort.h"

Template *char_array;

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
    char a[] = "QUICKSORTEXAMPLE";
    
    char_array  = Template_array(CHAR, sizeof(a), a);
    
    quick_sort(char_array);
    CHECK(is_sorted(char_array));
}

TEST(sort_group, quick_sort_equal_test)
{
    char b[100000];
    for(int i = 0; i < sizeof(b); i++)
        b[i] = 'A';
    char_array  = Template_array(CHAR, sizeof(b), b);
    
    quick_sort(char_array);
}

TEST(sort_group, quick_3way_sort_test)
{
    char a[] = "QUICKSORTEXAMPLE";
    char_array  = Template_array(CHAR, sizeof(a), a);
    quick_3way_sort(char_array);
    CHECK(is_sorted(char_array));
}

TEST(sort_group, quick_3way_sort_equal_test)
{
    char b[100000];
    for(int i = 0; i < sizeof(b); i++)
        b[i] = 'A';
    char_array  = Template_array(CHAR, sizeof(b), b);
    
    quick_3way_sort(char_array);
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}