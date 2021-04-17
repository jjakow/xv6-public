#include "types.h"
#include "stat.h"
#include "user.h"
//#include <stdlib.h>


int
main(int argc, char *argv[])
{


  //int * i = 0;

  int* test_pointer = (int*) 0x1000;


  printf(1,"Here is the initial value %d\n", *test_pointer);

  //by default 2 not seeming to be working
  //printf(1,"Trying to change it to the value %d\n", 2); 
  printf(1,"Now changing\n");
  *test_pointer =  2;  
  
  printf(1,"pointer has been set to %d\n", test_pointer);

  mprotect((void*)test_pointer, sizeof(*test_pointer)); 


  munprotect((void*)test_pointer, sizeof(*test_pointer)); 
  *test_pointer = 1;

  printf(1,"Here is no problem changing %d\n", *test_pointer);

  printf(1,"Now an error will become generated due to permissions to modify memory not allowed\n");


  mprotect((void*)test_pointer, sizeof(*test_pointer));
 
  *test_pointer = 36443;


  printf(1,"This will not print\n");
//  int * test = malloc(sizeof(int));
//  *test = 167;
  
//  mprotect(test, sizeof(test));
//  munprotect(test, sizeof(test)); 


 
  //printf(1,"%lu\n", *i);
  //return 0;
  exit();
}
