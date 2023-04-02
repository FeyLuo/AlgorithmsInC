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

TEST(sort_group, selection_sort_test)
{
    char a[] = "SORTEXAMPLE";
    Template *char_array  = Template_array(CHAR, sizeof(a), a);
    selection_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

TEST(sort_group, insertion_sort_test)
{
    char a[] = "SORTEXAMPLE";
    Template *char_array  = Template_array(CHAR, sizeof(a), a);
    insertion_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

TEST(sort_group, shell_sort_test)
{
    char a[] = "SHELLSORTEXAMPLE";
    Template *char_array  = Template_array(CHAR, sizeof(a), a);
    shell_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);

    char b[] = "EASYSHELLSORTQUESTION";
    char_array  = Template_array(CHAR, sizeof(b), b);
    shell_sort(char_array);
    CHECK(is_sorted(char_array));
    free(char_array);
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);

    return 0;
}