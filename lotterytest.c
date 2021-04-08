#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{


  int i;
  //int counter;
  for(i = 1; i < 4; i++){
    int pid = fork();
    if(pid == 0){
	
	printf(1,"this is the child %d. Should do something\n", getpid());
	settickets(i*10);
	int j = 0;

		
	while(1){
	  j++;
          if( j == 100000 && getpid() == 5){
	    j = 0;
	    struct pstat p;
            getpinfo(&p);
	    int k;
	    for( k = 0; k < NPROC; k++){
		if( (p.tickets[k] == 10) || (p.tickets[k] == 20) || (p.tickets[k] == 30) ){
			printf(1,"this work with pid %d and ticks %d\n", p.pid[k], p.ticks[k]);
			
		}
	    }
	  }
	}
	
	
	/*
	for(j = 0; j < 2000000000; j++){
		counter = (j%50 + j);
	}*/
    } 
    else{
	printf(1,"this is the parent. Should do nothing\n");
    }
   }
   wait(); //this is for the children
   wait();
   wait();
   //printf(1,"this is the value of counter %d\n", counter);
   //printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");
  exit();
}
