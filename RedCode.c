#include "RedCode.h"

#define CORESIZE 800


void redcode(){

}

void initMARS(){
    FILE* corefile;
    Instruction Core[CORESIZE];
    int i = 0;
    for (i = 0; i < CORESIZE; i++){
        Core[i].opcode = DAT;
        Core[i].mod = F;
        Core[i].aA = dol;
        Core[i].A = 0;
        Core[i].aB = dol;
        Core[i].B = 0;
    }
    corefile = fopen("Core.wr" , "wb");
    if (corefile == NULL) printf ("fopen failed");
    fwrite(&(Core[0]), sizeof(Instruction), CORESIZE, corefile);
}
