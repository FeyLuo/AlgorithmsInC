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

TEST_GROUP(qa_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST(sort_group, swim_test)
{
    char a[] = "SPRGTOAEIHG";
    
    char_array  = Template_array(CHAR, sizeof(a), a);

    swim(char_array, 5);
    CHECK(!is_heaped(char_array));
    swim(char_array, 9);
    CHECK(is_heaped(char_array));
}

TEST(sort_group, sink_test)
{
    char a[] = "THRPSOAEING";
    
    char_array  = Template_array(CHAR, sizeof(a), a);

    sink(char_array, 2);
    CHECK(is_heaped(char_array));
}

TEST(sort_group, heap_sort_sink_test)
{
    char a[] = "SORTEXAMPLE";
    
    char_array  = Template_array(CHAR, sizeof(a), a);
    
    heap_sort_sink(char_array);
    
    CHECK(is_sorted(char_array));
}

TEST(sort_group, heap_sort_swim_test)
{
    char a[] = "SORTEXAMPLE";
    
    char_array  = Template_array(CHAR, sizeof(a), a);
    
    heap_sort_sink(char_array);
    
    CHECK(is_sorted(char_array));
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}