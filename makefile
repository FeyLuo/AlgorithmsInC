all: test
export CPPUTEST_HOME=/usr/local
CPPFLAGS += -I$(CPPUTEST_HOME)/include 
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt
mytest: test.o
	g++ -g -o test test.o  $(LD_LIBRARIES)
	./test
test.o: test.cpp 
	g++ -g $(CPPFLAGS) -c test.cpp
clean:
	rm -f *.o test