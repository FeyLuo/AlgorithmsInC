export CPPUTEST_HOME=/usr/local

CPPFLAGS += -I$(CPPUTEST_HOME)/include -I../inc -I../tools/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

#***********************************************************************#
#				  build useful tools like adt, plot, etc.				#
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

sort: elementary_sort merge_sort

export SORT_HOME = ../src/2\:sort
export SORT_2_1 = $(SORT_HOME)/2.1\:elementary_sort
export SORT_2_2 = $(SORT_HOME)/2.2\:merge_sort

test_sort: test_elementary_sort test_merge_sort
	./test_elementary_sort
	./test_merge_sort

export TEST_SORT_HOME = ../test/src/2\:sort
export TEST_2_1 = $(TEST_SORT_HOME)/2.1\:elementary_sort
export TEST_2_2 = $(TEST_SORT_HOME)/2.2\:merge_sort


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

#***********************************************************************#

clean:
	rm -f *.o test*