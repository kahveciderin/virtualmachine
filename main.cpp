
#include "functions.h"


int main(int argc, char* argv[]){

    srand (time(NULL));
    string data;
    virtualmachine machinestate;
    ifstream file(argv[1]);
    
    string line ;
    while( getline( file, line ) )
    {
        data += line;
        data += "\n";
    }


    uint16_t* a = compile(data + "\n");

    /*for(int i = 0; i < 65535; i++){
        printf("0x%x\n", a[i]);
    }*/
    //initscr();
    machinestate.push = false;
    machinestate.halt = false;
    machinestate.addrspace = a;
    #ifdef DEBUG
    unsigned long tinstrun = 0;
    #endif
    while(true){
        run(&machinestate);
        check(&machinestate);
        if(machinestate.halt)   break;
        #ifdef DEBUG
        tinstrun++;
        #endif
    }
    #ifdef DEBUG
    printf("\n\nTotal instructions ran: %lu\n", tinstrun);
    #else
    printf("\n");
    #endif

    
    //endwin();
    return 0;
}