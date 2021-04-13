//#include "types.h"
//need types.h for pde pointer defintions

int mprotect(void * addr,int len,pde_t* pgdir);
int munprotect(void * addr,int len,pde_t* pgdir);

