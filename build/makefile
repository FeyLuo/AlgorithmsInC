export CPPUTEST_HOME=/usr/local
export TOOL_HOME=../tools
CPPFLAGS += -I$(CPPUTEST_HOME)/include -I../inc -I../tools/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

adt.o: $(TOOL_HOME)/adt.cpp
	g++ -g $(CPPFLAGS) -c $(TOOL_HOME)/adt.cpp

sort: elementary_sort

export SORT_HOME = ../src/2\:sort
export SORT_2_1 = $(SORT_HOME)/2.1\:elementary_sort

export TEST_SORT_HOME = ../test/src/2\:sort
export TEST_2_1 = $(TEST_SORT_HOME)/2.1\:elementary_sort


test_elementary_sort: test_elementary_sort.o elementary_sort.o adt.o
	g++ -g -o test_elementary_sort test_elementary_sort.o elementary_sort.o adt.o $(LD_LIBRARIES)
test_elementary_sort.o: $(TEST_2_1)/test_elementary_sort.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_1)/test_elementary_sort.cpp
elementary_sort.o: $(SORT_2_1)/elementary_sort.cpp 
	g++ -g $(CPPFLAGS) -c $(SORT_2_1)/elementary_sort.cpp

clean:
	rm -f *.o