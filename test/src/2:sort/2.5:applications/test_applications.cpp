#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "template.h"
#include "sort.h"
#include "priority_queues.h"
#include "applications.h"
#include <stdlib.h>

Template *char_array, *int_array, *int_array2;

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


TEST(sort_group, Kendall_tau_test) //肯德尔秩：按数组B的排列顺序定义索引
{                                    //a'[a[i]] = i            c[i] = a'[b[i]] -> c
    int a[]  = {0, 3, 1, 6, 2, 5, 4}; //0 2 4 1 6 5 3    --\    2 0 1 3 6 4 5   =  4
    int b[]  = {1, 0, 3, 6, 4, 2, 5}; //1 0 5 2 4 6 3    --/    0 1 2 3 4 5 6
    LONGS_EQUAL(4, Kendall_tau(a, b, 7));
    int a1[] = {9, 3, 1, 6, 2, 5, 4}; //2 4 1 6 5 3 0    --\    2 0 1 3 6 4 5   =  4
    int b1[] = {1, 9, 3, 6, 4, 2, 5}; //0 5 2 4 6 3 1    --/    0 1 2 3 4 5 6
    LONGS_EQUAL(4, Kendall_tau(a1, b1, 7));
}

TEST(sort_group, inversions_test) //如果数组A无序，数组B有序，转化成求数组A的逆序对（剑指 Offer 51）
{                                    //a'[a[i]] = i   -> a' (b[i] = i -> c[i] = a'[b[i]] = a'[i] = a')
    int a[] = {0, 3, 1, 6, 2, 5, 4}; //0 2 4 1 6 5 3  =  6
    int b[] = {0, 1, 2, 3, 4, 5, 6}; //0 1 2 3 4 5 6
    LONGS_EQUAL(6, inversions(a, 7)); 
}

TEST(sort_group, median_test)
{
    int a[] = {1, 3, 2, 8, 6, 7, 7, 9, 4, 5};
    int_array = Template_array(INT, 10, a);
    DOUBLES_EQUAL(5.5, meadian(int_array), 1e-5);
}


int main(int argc, char** argv)
{
    RUN_ALL_TESTS(argc, argv);
    return 0;
}