#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "adt.h"

static struct adt *int_array, *char_array;

TEST_GROUP(int_group)
{
   void setup()
   {
        int_array = adt_array(INT, 10);
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
        char_array = adt_array(CHAR, 10);
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
    CHECK(less(&int_array[0], &int_array[1]));
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
    struct adt* adt = adt_array(INT, 10, a);
    show(adt);
    free(adt);
}

TEST(int_group, is_sorted_test)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    struct adt* adt = adt_array(INT, 10, a);
    CHECK(!is_sorted(adt));
    set_value(&adt[9], 10);
    CHECK(is_sorted(adt));
}

TEST(int_group, copy_test)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    struct adt* adt1 = adt_array(INT, 10, a);
    struct adt* adt2 = adt_array(INT, 10);
    copy(adt1, adt2, 0, 5);
    for(int i = 0; i < 5; i++)
        LONGS_EQUAL(GET_INT_VALUE(adt1[i]), GET_INT_VALUE(adt2[i]));
}


TEST(char_group, less_test)
{
    set_value(&char_array[0], 'a');
    set_value(&char_array[1], 'b');
    CHECK(less(&char_array[0], &char_array[1]));
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
    struct adt* adt = adt_array(CHAR, sizeof(a), a);
    show(adt);
    free(adt);
}

TEST(char_group, is_sorted_test)
{
    char a[] = "abcdefgha";
    struct adt* adt = adt_array(CHAR, sizeof(a), a);
    CHECK(!is_sorted(adt));
    set_value(&adt[8], 'i');
    CHECK(is_sorted(adt));
}

TEST(char_group, copy_test)
{
    char a[] = "abcdefgha";
    struct adt* adt1 = adt_array(CHAR, 10, a);
    struct adt* adt2 = adt_array(CHAR, 10);
    copy(adt1, adt2, 0, 5);
    for(int i = 0; i < 5; i++)
        LONGS_EQUAL(GET_INT_VALUE(adt1[i]), GET_INT_VALUE(adt2[i]));
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}