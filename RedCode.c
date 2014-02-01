#include "RedCode.h"



void initMARS(Instruction (*Core)[], int size){ /*creates a blank memory of CORESIZE instructions*/
    int i;
    for (i = 0; i < size; i++){
        (*Core)[i].op = DAT;
        (*Core)[i].mod = F;
        (*Core)[i].aA = dol;
        (*Core)[i].A = 0;
        (*Core)[i].aB = dol;
        (*Core)[i].B = 0;
    }
}

void savefile(Instruction (*doc)[], int len, char* filename){ /*saves an array of instructions to a file*/
    int i = 0;
    FILE* file;
    file = fopen(filename, "w");
    if (file == NULL) printf ("fopen failed");
    fprintf(file, "%d ", len);
    for (i = 0; i < len; i++){
        fprintf(file, "%d %d %d %d %d %d ",(*doc)[i].op, (*doc)[i].mod, (*doc)[i].aA, (*doc)[i].A, (*doc)[i].aB, (*doc)[i].B);
    }
    fclose (file);
}

void loadfile(Instruction (*doc)[], char* filename){ /*loads an array of instructions from a file*/
    int i = 0;
    int len;
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) printf ("fopen failed");
    fscanf(file, "%d ", &len);
    for (i = 0; i < len; i++){
        fscanf(file, "%d", &((*doc)[i].op));
        fscanf(file, "%d", &((*doc)[i].mod));
        fscanf(file, "%d", &((*doc)[i].aA));
        fscanf(file, "%d", &((*doc)[i].A));
        fscanf(file, "%d", &((*doc)[i].aB));
        fscanf(file, "%d", &((*doc)[i].B));
    }
    printf("copied %d inst.", len);
    fclose (file);
}

int sizemem(char *filename){ /*returns the numbers of instructions a file holds*/
    FILE* file;
    int data = 0;
    file = fopen(filename, "r");
    if(file == NULL) {printf ("couldnt open file(sizemem)"); return 0;}
    fscanf(file, "%d", &data);
    fclose(file);
    return data;
}

void samplewarrior(){
    FILE* text;
    printf("creating sample warrior");
    Instruction Core[2];
    (Core)[0].op = ADD;
    (Core)[0].mod = F;
    (Core)[0].aA = dol;
    (Core)[0].A = 13;
    (Core)[0].aB = dol;
    (Core)[0].B = 15;
    (Core)[1].op = MOV;
    (Core)[1].mod = I;
    (Core)[1].aA = sharp;
    (Core)[1].A = 6;
    (Core)[1].aB = aro;
    (Core)[1].B = 2;

}



void injectwarrior(Instruction (*warrior)[], int len, Instruction (*Core)[], int loc){
    int i;
    for(i=0; i<len; i++){
            (*Core)[loc+i].op=(*warrior)[i].op;
            (*Core)[loc+i].mod=(*warrior)[i].mod;
            (*Core)[loc+i].aA=(*warrior)[i].aA;
            (*Core)[loc+i].A=(*warrior)[i].A;
            (*Core)[loc+i].aB=(*warrior)[i].aB;
            (*Core)[loc+i].B=(*warrior)[i].B;
    }
}
