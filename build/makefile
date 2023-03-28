export CPPUTEST_HOME=/usr/local

CPPFLAGS += -I$(CPPUTEST_HOME)/include -I../inc -I../tools/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

#***********************************************************************#
#                build useful tools like adt, plot, etc.                #
#***********************************************************************#

tools: adt

export TOOL_HOME=../tools

test_tools: test_adt
	./test_adt

export TEST_TOOL_HOME = ../test/tools

test_adt: test_adt.o adt.o
	g++ -g -o test_adt test_adt.o  adt.o $(LD_LIBRARIES)
test_adt.o: $(TEST_TOOL_HOME)/test_adt.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_TOOL_HOME)/test_adt.cpp
adt.o: $(TOOL_HOME)/adt.cpp
	g++ -g $(CPPFLAGS) -c $(TOOL_HOME)/adt.cpp

#***********************************************************************#

sort: elementary_sort merge_sort quick_sort priority_queues

export SORT_HOME = ../src/2\:sort
export SORT_2_1 = $(SORT_HOME)/2.1\:elementary_sort
export SORT_2_2 = $(SORT_HOME)/2.2\:merge_sort
export SORT_2_3 = $(SORT_HOME)/2.3\:quick_sort
export SORT_2_4 = $(SORT_HOME)/2.4\:priority_queues
export SORT_2_5 = $(SORT_HOME)/2.5\:applications

test_sort: test_elementary_sort test_merge_sort test_quick_sort test_priority_queues
	./test_elementary_sort -c
	./test_merge_sort -c
	./test_quick_sort -c -v
	./test_priority_queues -c

export TEST_SORT_HOME = ../test/src/2\:sort
export TEST_2_1 = $(TEST_SORT_HOME)/2.1\:elementary_sort
export TEST_2_2 = $(TEST_SORT_HOME)/2.2\:merge_sort
export TEST_2_3 = $(TEST_SORT_HOME)/2.3\:quick_sort
export TEST_2_4 = $(TEST_SORT_HOME)/2.4\:priority_queues
export TEST_2_5 = $(TEST_SORT_HOME)/2.5\:applications


test_elementary_sort: test_elementary_sort.o elementary_sort.o adt.o
	g++ -g -o test_elementary_sort test_elementary_sort.o elementary_sort.o adt.o $(LD_LIBRARIES)
	./test_elementary_sort
test_elementary_sort.o: $(TEST_2_1)/test_elementary_sort.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_1)/test_elementary_sort.cpp
elementary_sort.o: $(SORT_2_1)/elementary_sort.cpp 
	g++ -g $(CPPFLAGS) -c $(SORT_2_1)/elementary_sort.cpp

test_merge_sort: test_merge_sort.o merge_sort.o adt.o
	g++ -g -o test_merge_sort test_merge_sort.o merge_sort.o adt.o $(LD_LIBRARIES)
	./test_merge_sort
test_merge_sort.o: $(TEST_2_2)/test_merge_sort.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_2)/test_merge_sort.cpp
merge_sort.o: $(SORT_2_2)/merge_sort.cpp 
	g++ -g $(CPPFLAGS) -c $(SORT_2_2)/merge_sort.cpp

test_quick_sort: test_quick_sort.o quick_sort.o adt.o
	g++ -g -o test_quick_sort test_quick_sort.o quick_sort.o adt.o $(LD_LIBRARIES)
	./test_quick_sort
test_quick_sort.o: $(TEST_2_3)/test_quick_sort.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_3)/test_quick_sort.cpp
quick_sort.o: $(SORT_2_3)/quick_sort.cpp 
	g++ -g $(CPPFLAGS) -c $(SORT_2_3)/quick_sort.cpp

test_priority_queues: test_priority_queues.o priority_queues.o adt.o
	g++ -g -o test_priority_queues test_priority_queues.o priority_queues.o adt.o $(LD_LIBRARIES)
	./test_priority_queues
test_priority_queues.o: $(TEST_2_4)/test_priority_queues.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_4)/test_priority_queues.cpp
priority_queues.o: $(SORT_2_4)/priority_queues.cpp 
	g++ -g $(CPPFLAGS) -c $(SORT_2_4)/priority_queues.cpp

#***********************************************************************#

clean:
	rm -f *.o test*