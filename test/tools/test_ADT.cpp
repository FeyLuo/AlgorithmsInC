#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"
#include "ADT.h"

TEST_GROUP(bags_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST_GROUP(queues_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST_GROUP(stack_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST_GROUP(heap_group)
{
   void setup()
   {

   }

   void teardown()
   {

   }
};

TEST(queues_group, init_test)
{
   Queue* Q = queue();
   CHECK(NULL!=Q);
   CHECK(Q->n == 0);
   POINTERS_EQUAL(NULL, Q->first);
   POINTERS_EQUAL(NULL, Q->last);
   free(Q);
}

TEST(queues_group, enqueue_test)
{
   Queue* Q = queue();
   Template* T = Template_array(INT, 1);
   enqueue(Q, T);
   CHECK(size_queue(Q) == 1);
   CHECK(!is_empty_queue(Q));
   POINTERS_EQUAL(Q->first->value, T);
   POINTERS_EQUAL(Q->first, Q->last);
   free(Q);
   free(T);
}

TEST(queues_group, dequeue_test)
{
   Queue* Q = queue();
   Template* T = Template_array(INT, 2);
   enqueue(Q, &T[0]);
   enqueue(Q, &T[1]);
   LONGS_EQUAL(2, size_queue(Q));
   POINTERS_EQUAL(dequeue(Q), &T[0]);
   LONGS_EQUAL(1, size_queue(Q));
   POINTERS_EQUAL(dequeue(Q), &T[1]);
   CHECK(is_empty_queue(Q));
   free(Q);
   free(T);
}

int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}