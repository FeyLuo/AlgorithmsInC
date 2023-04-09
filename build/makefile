export CPPUTEST_HOME=/usr/local

CPPFLAGS += -I$(CPPUTEST_HOME)/include -I../inc -I../tools/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

#***********************************************************************#
#             build useful tools like template, plot, etc.              #
#***********************************************************************#

tools: template ADT

export TOOL_HOME=../tools

test_tools: test_template test_ADT
	./test_template
	./test_ADT

export TEST_TOOL_HOME = ../test/tools

test_template: test_template.o template.o
	g++ -g -o test_template test_template.o  template.o $(LD_LIBRARIES)
test_template.o: $(TEST_TOOL_HOME)/test_template.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_TOOL_HOME)/test_template.cpp
template.o: $(TOOL_HOME)/template.c
	g++ -g $(CPPFLAGS) -c $(TOOL_HOME)/template.c

test_ADT: test_ADT.o ADT.o template.o
	g++ -g -o test_ADT test_ADT.o  ADT.o template.o $(LD_LIBRARIES)
test_ADT.o: $(TEST_TOOL_HOME)/test_ADT.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_TOOL_HOME)/test_ADT.cpp
ADT.o: $(TOOL_HOME)/ADT.c
	g++ -g $(CPPFLAGS) -c $(TOOL_HOME)/ADT.c

#***********************************************************************#

sort: elementary_sort merge_sort quick_sort priority_queues applications

export SORT_HOME = ../src/2\:sort
export SORT_2_1 = $(SORT_HOME)/2.1\:elementary_sort
export SORT_2_2 = $(SORT_HOME)/2.2\:merge_sort
export SORT_2_3 = $(SORT_HOME)/2.3\:quick_sort
export SORT_2_4 = $(SORT_HOME)/2.4\:priority_queues
export SORT_2_5 = $(SORT_HOME)/2.5\:applications

test_sort: test_elementary_sort test_merge_sort test_quick_sort test_priority_queues test_applications
	./test_elementary_sort -c
	./test_merge_sort -c
	./test_quick_sort -c -v
	./test_priority_queues -c
	./test_applications -c

export TEST_SORT_HOME = ../test/src/2\:sort
export TEST_2_1 = $(TEST_SORT_HOME)/2.1\:elementary_sort
export TEST_2_2 = $(TEST_SORT_HOME)/2.2\:merge_sort
export TEST_2_3 = $(TEST_SORT_HOME)/2.3\:quick_sort
export TEST_2_4 = $(TEST_SORT_HOME)/2.4\:priority_queues
export TEST_2_5 = $(TEST_SORT_HOME)/2.5\:applications


test_elementary_sort: test_elementary_sort.o elementary_sort.o template.o
	g++ -g -o test_elementary_sort test_elementary_sort.o elementary_sort.o template.o $(LD_LIBRARIES)
	./test_elementary_sort
test_elementary_sort.o: $(TEST_2_1)/test_elementary_sort.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_1)/test_elementary_sort.cpp
elementary_sort.o: $(SORT_2_1)/elementary_sort.c
	g++ -g $(CPPFLAGS) -c $(SORT_2_1)/elementary_sort.c

test_merge_sort: test_merge_sort.o merge_sort.o template.o
	g++ -g -o test_merge_sort test_merge_sort.o merge_sort.o template.o $(LD_LIBRARIES)
	./test_merge_sort
test_merge_sort.o: $(TEST_2_2)/test_merge_sort.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_2)/test_merge_sort.cpp
merge_sort.o: $(SORT_2_2)/merge_sort.c
	g++ -g $(CPPFLAGS) -c $(SORT_2_2)/merge_sort.c

test_quick_sort: test_quick_sort.o quick_sort.o template.o
	g++ -g -o test_quick_sort test_quick_sort.o quick_sort.o template.o $(LD_LIBRARIES)
	./test_quick_sort
test_quick_sort.o: $(TEST_2_3)/test_quick_sort.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_3)/test_quick_sort.cpp
quick_sort.o: $(SORT_2_3)/quick_sort.c
	g++ -g $(CPPFLAGS) -c $(SORT_2_3)/quick_sort.c

test_priority_queues: test_priority_queues.o priority_queues.o template.o
	g++ -g -o test_priority_queues test_priority_queues.o priority_queues.o template.o $(LD_LIBRARIES)
	./test_priority_queues
test_priority_queues.o: $(TEST_2_4)/test_priority_queues.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_4)/test_priority_queues.cpp
priority_queues.o: $(SORT_2_4)/priority_queues.c
	g++ -g $(CPPFLAGS) -c $(SORT_2_4)/priority_queues.c

test_applications: test_applications.o applications.o priority_queues.o template.o
	g++ -g -o test_applications test_applications.o applications.o priority_queues.o template.o $(LD_LIBRARIES)
	./test_applications
test_applications.o: $(TEST_2_5)/test_applications.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_2_5)/test_applications.cpp
applications.o: $(SORT_2_5)/applications.c
	g++ -g $(CPPFLAGS) -c $(SORT_2_5)/applications.c

#***********************************************************************#

searching: symbol_tables hash_tables

export SEARCHING_HOME = ../src/3\:searching
export SEARCHING_3_1 = $(SEARCHING_HOME)/3.1\:symbol_tables
export SEARCHING_3_4 = $(SEARCHING_HOME)/3.4\:hash_tables

test_searching: test_symbol_tables test_hash_tables
	./test_symbol_tables -c
	./test_hash_tables -c

export TEST_SEARCHING_HOME = ../test/src/3\:searching
export TEST_3_1 = $(TEST_SEARCHING_HOME)/3.1\:symbol_tables
export TEST_3_4 = $(TEST_SEARCHING_HOME)/3.4\:hash_tables

test_symbol_tables: test_symbol_tables.o symbol_tables.o template.o
	g++ -g -o test_symbol_tables test_symbol_tables.o symbol_tables.o template.o $(LD_LIBRARIES)
	./test_symbol_tables -c
test_symbol_tables.o: $(TEST_3_1)/test_symbol_tables.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_3_1)/test_symbol_tables.cpp
symbol_tables.o: $(SEARCHING_3_1)/symbol_tables.c
	g++ -g $(CPPFLAGS) -c $(SEARCHING_3_1)/symbol_tables.c

test_hash_tables: test_hash_tables.o hash_tables.o template.o
	g++ -g -o test_hash_tables test_hash_tables.o hash_tables.o template.o $(LD_LIBRARIES)
	./test_hash_tables -c
test_hash_tables.o: $(TEST_3_4)/test_hash_tables.cpp
	g++ -g $(CPPFLAGS) -c $(TEST_3_4)/test_hash_tables.cpp
hash_tables.o: $(SEARCHING_3_4)/hash_tables.c
	g++ -g $(CPPFLAGS) -c $(SEARCHING_3_4)/hash_tables.c

#***********************************************************************#

clean:
	rm -f *.o test*