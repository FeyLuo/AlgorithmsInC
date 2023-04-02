#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"

static Template *int_array, *char_array;

TEST_GROUP(int_group)
{
   void setup()
   {
        int_array = Template_array(INT, 10);
   }

   void teardown()
   {
        free(int_array);
   }
};

TEST_GROUP(char_group)
{
   void setup()
   {
        char_array = Template_array(CHAR, 10);
   }

   void teardown()
   {
        free(char_array);
   }
};

TEST(int_group, less_test)
{
    set_value(&int_array[0], 100);
    set_value(&int_array[1], 200);
    CHECK(less(int_array[0], int_array[1]));
}

TEST(int_group, len_test)
{
    LONGS_EQUAL(10, len(int_array));
}
TEST(int_group, exch_test)
{
    set_value(&int_array[0], 100);
    set_value(&int_array[1], 200);
    exch(int_array, 0, 1);
    LONGS_EQUAL(200, GET_INT_VALUE(int_array[0]));
    LONGS_EQUAL(100, GET_INT_VALUE(int_array[1]));
}

TEST(int_group, show_test)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Template* Template = Template_array(INT, 10, a);
    show(Template);
    free(Template);
}

TEST(int_group, is_sorted_test)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Template* Template = Template_array(INT, 10, a);
    CHECK(!is_sorted(Template));
    set_value(&Template[9], 10);
    CHECK(is_sorted(Template));
}

TEST(int_group, copy_test)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Template* Template1 = Template_array(INT, 10, a);
    Template* Template2 = Template_array(INT, 10);
    copy(Template1, Template2, 0, 5);
    for(int i = 0; i < 5; i++)
        LONGS_EQUAL(GET_INT_VALUE(Template1[i]), GET_INT_VALUE(Template2[i]));
}


TEST(char_group, less_test)
{
    set_value(&char_array[0], 'a');
    set_value(&char_array[1], 'b');
    CHECK(less(char_array[0], char_array[1]));
}

TEST(char_group, len_test)
{
    LONGS_EQUAL(10, len(char_array));
}

TEST(char_group, exch_test)
{
    set_value(&char_array[0], 'a');
    set_value(&char_array[1], 'b');
    exch(char_array, 0, 1);
    LONGS_EQUAL('b', GET_INT_VALUE(char_array[0]));
    LONGS_EQUAL('a', GET_INT_VALUE(char_array[1]));
}

TEST(char_group, show_test)
{
    char a[] = "abcdefgha";
    Template* Template = Template_array(CHAR, sizeof(a), a);
    show(Template);
    free(Template);
}

TEST(char_group, is_sorted_test)
{
    char a[] = "abcdefgha";
    Template* Template = Template_array(CHAR, sizeof(a), a);
    CHECK(!is_sorted(Template));
    set_value(&Template[8], 'i');
    CHECK(is_sorted(Template));
}

TEST(char_group, copy_test)
{
    char a[] = "abcdefgha";
    Template* Template1 = Template_array(CHAR, 10, a);
    Template* Template2 = Template_array(CHAR, 10);
    copy(Template1, Template2, 0, 5);
    for(int i = 0; i < 5; i++)
        LONGS_EQUAL(GET_INT_VALUE(Template1[i]), GET_INT_VALUE(Template2[i]));
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}