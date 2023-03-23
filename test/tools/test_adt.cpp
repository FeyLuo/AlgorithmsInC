#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "../../tools/include/adt.h"
#include <malloc.h>

TEST_GROUP(int_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST_GROUP(char_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST(int_group, less_test)
{
    struct adt* int_array = adt_array(INT, 100);
    set_value(&int_array[0], 100);
    set_value(&int_array[1], 200);
    CHECK(less(&int_array[0], &int_array[1]));
    free(int_array);
}

TEST(int_group, len_test)
{
    struct adt* int_array = adt_array(INT, 100);
    LONGS_EQUAL(100, len(int_array));
    free(int_array);
}
TEST(int_group, exch_test)
{
    struct adt* int_array = adt_array(INT, 100);
    set_value(&int_array[0], 100);
    set_value(&int_array[1], 200);
    exch(int_array, 0, 1);
    LONGS_EQUAL(200, GET_INT_VALUE(int_array[0]));
    LONGS_EQUAL(100, GET_INT_VALUE(int_array[1]));
    free(int_array);
}

TEST(char_group, less_test)
{
    ;
}

TEST(char_group, exch_test)
{
    ;
}

int main(int argc, char** argv)
{
   return RUN_ALL_TESTS(argc, argv);
}