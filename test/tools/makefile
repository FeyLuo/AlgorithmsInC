all: test
export CPPUTEST_HOME=/usr/local
export TOOL_HOME=../../tools
CPPFLAGS += -I$(CPPUTEST_HOME)/include -I../../tools/include 
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

test_adt: test_adt.o $(TOOL_HOME)/adt.o
	g++ -g -o test_adt test_adt.o  $(TOOL_HOME)/adt.o $(LD_LIBRARIES)
test_adt.o: test_adt.cpp
	g++ -g $(CPPFLAGS) -c test_adt.cpp
adt.o: $(TOOL_HOME)/adt.cpp
	g++ -g $(CPPFLAGS) -c $(TOOL_HOME)/adt.cpp
clean:
	rm -f *.o $(TOOL_HOME)/*.o test_adt