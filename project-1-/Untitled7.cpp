# This file will prevent temp files from apearing to git
*.dcz
*.cpz
*#
*~
*.class
*.pyc
*.py~
*.o
*.swp
cache_sim
# This file will prevent temp files from apearing to git
*.dcz
*.cpz
*#
*~
*.class
*.pyc
*.py~
*.o
*.swp
*.exe
 92  
Makefile
@@ -1,46 +1,46 @@
# Adding new Files to the Makefile
# If u have different filenames or want to add any more sources add
# them to this list of SRCS
SRCS = main.cc funcs.cc

CC = /usr/bin/g++
LD = /usr/bin/g++

# Compiler options
# IF u want to add any other compiler options add them to CPPFLAGS
# Debug information
# The -g option in CPPFLAGS will generate debug information,
# this is required if u want to use a debugger like gdb
# Hint if you are used to VC style of debugging a visual debugger 'ddd'
# is available on linux which should be very much like VC and make life simpler
# while debugging. It actually uses the gdb but you dont have to know the
# commands of gdb to use it.
CPPFLAGS = -g

IFLAGS = 
LDFLAGS =

# Using extra libraries
# If u are using any extra libraries u will have to update the LIBS =
LIBS = 

# Output of the make
# The Makefile produces your final binary as cache_sim,
# Changing output filename
# If u want to change this just modify the PROGRAM = 
PROGRAM = cache_sim

OBJS = $(SRCS:.cc=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)


# Recompiling all sources
# If u want to recompile all your sourses run 
# 	make clean
# and then make
clean:
	rm -f $(OBJS) $(PROGRAM)
# Adding new Files to the Makefile
# If u have different filenames or want to add any more sources add
# them to this list of SRCS
SRCS = main.cc funcs.cc main_memory.cc

CC = /usr/bin/g++
LD = /usr/bin/g++

# Compiler options
# IF u want to add any other compiler options add them to CPPFLAGS
# Debug information
# The -g option in CPPFLAGS will generate debug information,
# this is required if u want to use a debugger like gdb
# Hint if you are used to VC style of debugging a visual debugger 'ddd'
# is available on linux which should be very much like VC and make life simpler
# while debugging. It actually uses the gdb but you dont have to know the
# commands of gdb to use it.
CPPFLAGS = -g

IFLAGS = 
LDFLAGS =

# Using extra libraries
# If u are using any extra libraries u will have to update the LIBS =
LIBS = 

# Output of the make
# The Makefile produces your final binary as cache_sim,
# Changing output filename
# If u want to change this just modify the PROGRAM = 
PROGRAM = cache_sim

OBJS = $(SRCS:.cc=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)


# Recompiling all sources
# If u want to recompile all your sourses run 
# 	make clean
# and then make
clean:
	rm -f $(OBJS) $(PROGRAM)
 123  
main.cc
@@ -1,56 +1,67 @@
/*
Ian Buitrago
Miguel Diaz
*/

#include "main_memory.cc"
#include <cassert>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "funcs.h"

using namespace std;

void test(){
	MainMemory mem(1024);
	mem.print_contents(13, 24, DEC);
}

int main (int argc, char *argv[ ])
{
  //the values that we get from the 
  //command line will be put into these
  //variables. we can use them later in the program
  //like for checking if they have valid values

  int cache_capacity = 0;
  int cache_blocksize = 0;
  int cache_associativity = 0;

  if(!parseParams(argc, argv, cache_capacity, cache_blocksize, cache_associativity)) {
	exit (2);
  }

  // -c <capacity> with <capacity> in KB: 4, 8, 16, 32, or 64. 
  assert(cache_capacity == 4 || cache_capacity == 8 || cache_capacity == 16
         || cache_capacity == 32 || cache_capacity == 64); 
  // -b <blocksize> with <blocksize> in bytes:
  //  4, 8, 16, 32, 64, 128, 256, or 512. 
  assert(cache_blocksize == 4 || cache_blocksize == 8 || cache_blocksize == 16
         || cache_blocksize == 32 || cache_blocksize == 64 
         || cache_blocksize == 128 || cache_blocksize == 256
         || cache_blocksize == 512); 
  // -a <associativity> where <associativity> is integer size of set:
  // 1, 2, 4, 8, 16. 
  assert(cache_associativity == 1 || cache_associativity == 2
         || cache_associativity == 4 || cache_associativity == 8
         || cache_associativity == 16);

  cout << "Cache Capacity: " << cache_capacity << endl;
  cout << "Cache BlockSize: " << cache_blocksize << endl;
  cout << "Cache Associativity: " << cache_associativity << endl;
test();
return 0;
}
/*
Ian Buitrago
Miguel Diaz
notes:
run with
make
./cache_sim -c8 -b16 -a4
*/

//#include "main_memory.cc"
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <vector>
#include "funcs.h"
#include "main_memory.h"


using namespace std;

void test();

int main (int argc, char *argv[ ])
{
	//the values that we get from the 
	//command line will be put into these
	//variables. we can use them later in the program
	//like for checking if they have valid values

	int cache_capacity = 0;
	int cache_blocksize = 0;
	int cache_associativity = 0;

	if(!parseParams(argc, argv, cache_capacity, cache_blocksize, cache_associativity)) {
		exit (2);
	}

	// -c <capacity> with <capacity> in KB: 4, 8, 16, 32, or 64. 
	assert(cache_capacity == 4 || cache_capacity == 8 || cache_capacity == 16
		|| cache_capacity == 32 || cache_capacity == 64); 
	// -b <blocksize> with <blocksize> in bytes:
	//  4, 8, 16, 32, 64, 128, 256, or 512. 
	assert(cache_blocksize == 4 || cache_blocksize == 8 || cache_blocksize == 16
		|| cache_blocksize == 32 || cache_blocksize == 64 
		|| cache_blocksize == 128 || cache_blocksize == 256
		|| cache_blocksize == 512); 
	// -a <associativity> where <associativity> is integer size of set:
	// 1, 2, 4, 8, 16. 
	assert(cache_associativity == 1 || cache_associativity == 2
		|| cache_associativity == 4 || cache_associativity == 8
		|| cache_associativity == 16);

	cout << "Cache Capacity: " << cache_capacity << endl;
	cout << "Cache BlockSize: " << cache_blocksize << endl;
	cout << "Cache Associativity: " << cache_associativity << endl;
	test();

	return 0;
}

void test(){
	MainMemory mem(1024);
	mem.print_contents(13, 24, HEX);
}
 151  
main_memory.cc
@@ -1,66 +1,85 @@
#include <iostream>
#include <iomanip>
#include <new>

//*** the .cc file of a class should include its .h 
#include "main_memory.h"

#define STARTING_ADDRESS 4161280 // 0x003f7f00

using namespace std;

//*** constructor
MainMemory::MainMemory(int capacity){
     size = capacity;
     memory = new (nothrow) int [1024];
     if (memory==0){
	cout << "Failed to allocate memory!\n";
     }

     for(int set = 0; set < 1024; set++)
     {
       memory[set] = STARTING_ADDRESS + set;
     }

}

//*** destructor
MainMemory::~MainMemory(){
     if(memory != NULL){
	delete [] memory;	
     } 
}

void MainMemory::print_contents(int from, int to, int format){
	//assert -1 < format < 3
	cout << "Address    Data" << endl;
	while(from <= to)
	  {
		if(format == 0)
		{
		  cout << setw(8) << setfill('0') << hex << STARTING_ADDRESS + from << "   " << hex << memory[from] << endl;
		}
		if(format == 1)
		{
		  cout << setw(8) << setfill('0') << hex << STARTING_ADDRESS + from << "   " << hex << memory[from] << endl;
		}
		if(format == 2)
		{
		  cout << setw(8) << setfill('0') << hex << STARTING_ADDRESS + from << "   " << hex << memory[from] << endl;
		}
		if(format < 0 || format > 2)
		{
		  cout << "Invalid format";
		  from = to + 1; // exit loop early
		}
		from++;
	  }
}

void MainMemory::set_content(int location, int value){
	//More code
}

void MainMemory::reset_content(void){
	//More code
}
#include <iostream>
#include <iomanip>
#include <new>

//*** the .cc file of a class should include its .h 
#include "main_memory.h"

#define STARTING_ADDRESS 4161280 // 0x003f7f00

using namespace std;

//*** constructor
MainMemory::MainMemory(int capacity){
     size = capacity;
     memory = new (nothrow) int [1024];
     if (memory==0){
		cout << "Failed to allocate memory!\n";
     }

     for(int set = 0; set < 1024; set++)
     {
       memory[set] = STARTING_ADDRESS + set;
     }

}

//*** destructor
MainMemory::~MainMemory(){
     if(memory != NULL){
	delete [] memory;	
     } 
}

void MainMemory::print_contents(int from, int to, int format){
	struct {int total, reads, writes;} misses, missrate;	//temp
	int evicted = 0;

	cout << "STATISTICS:" << endl;
	cout << "Misses:" << endl;
	cout << "Total: " << misses.total;
	cout << " DataReads: " << misses.reads;
	cout << " DataWrites: " << misses.writes << endl;
	cout << "Miss rate: " << endl;
	cout << "Total: " << missrate.total;
	cout << " DataReads: " << missrate.reads;
	cout << " DataWrites: " << missrate.writes << endl;
	cout << "Number of Dirty Blocks Evicted From the Cache: " << evicted << endl;

	cout << "MAIN MEMORY:" << endl;
	//assert -1 < format < 3
	cout << "Address    Words" << endl;
	int i = from;
	while(i <= to){

	  cout  << setw(8) << setfill('0') << hex << i << "   ";		//print address first

	  for(int j = 0; j < 8; j++, i++){

		  switch(format){
		  case HEX:
		    cout << setw(8) << setfill('0') << hex << memory[i] << "   ";
		    break;
		  case DEC:
		    cout << setw(8) << setfill('0') << dec << memory[i] << "   ";
		    break;
		  case OCT:
		    cout << setw(8) << setfill('0') << oct << memory[i] << "   ";
		    break;
		  default:
		    cout << "Invalid format";
		    i = to + 1;		//break loop
		  }
	  }
	  cout  << endl;

	}
}

void MainMemory::set_content(int location, int value){
	//More code
}

void MainMemory::reset_content(void){
	//More code
}
