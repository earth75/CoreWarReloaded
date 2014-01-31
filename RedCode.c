#include "RedCode.h"



void initMARS(Instruction (*Core)[CORESIZE+1]){
    FILE* corefile;
    int i;
    corefile = fopen("core.cr" , "w");
    if (corefile == NULL) printf ("fopen failed");
    printf("okMARS ");
    for (i = 0; i < CORESIZE; i++){
        (*Core)[i].opcode = DAT;
        (*Core)[i].mod = F;
        (*Core)[i].aA = dol;
        (*Core)[i].A = 0;
        (*Core)[i].aB = dol;
        (*Core)[i].B = 0;
        printf("%d!", i);
        fprintf(corefile, "%d %d %d %d %d %d ",(*Core)[i].opcode, (*Core)[i].mod, (*Core)[i].aA, (*Core)[i].A, (*Core)[i].aB, (*Core)[i].B);

        printf("%d ", i);
    }
    printf("okMARS2");
    (*Core)[CORESIZE].opcode = END;
    (*Core)[CORESIZE].mod = F;
    (*Core)[CORESIZE].aA = dol;
    (*Core)[CORESIZE].A = 0;
    (*Core)[CORESIZE].aB = dol;
    (*Core)[CORESIZE].B = 0;
    fprintf(corefile, "%d %d %d %d %d %d\n",(*Core)[CORESIZE].opcode, (*Core)[CORESIZE].mod, (*Core)[CORESIZE].aA, (*Core)[CORESIZE].A, (*Core)[CORESIZE].aB, (*Core)[CORESIZE].B);
    fclose(corefile);
    printf("ok close corefile");
}


void loadwarrior(){
    FILE* warrior;
    warrior = fopen("warrior.wr", "wb");
    if(warrior == NULL) printf ("couldnt open warrior");


}

void injectwarrior(Instruction* warrior, int len, Instruction* Core, int loc){
    int i;
    for(i=0; i<len; i++){
            Core[loc+i]=warrior[i];
    }

}
