#include "RedCode.h"



void initMARS(Instruction (*Core)[], int size){
    int i;
    printf("okMARS ");
    FILE* file;
    file = fopen("coretest2.cr" , "w");
    if (file == NULL) printf ("fopen failed");
    printf("savinit ");
    fprintf(file, "%d ", size);
    for (i = 0; i < size; i++){
        (*Core)[i].opcode = DAT;
        (*Core)[i].mod = F;
        (*Core)[i].aA = dol;
        (*Core)[i].A = 1;
        (*Core)[i].aB = dol;
        (*Core)[i].B = 2;
        fprintf(file, "%d %d %d %d %d %d ",(*Core)[i].opcode, (*Core)[i].mod, (*Core)[i].aA, (*Core)[i].A, (*Core)[i].aB, (*Core)[i].B);
    }
    printf("okMARS2 ");
    fclose (file);
    printf("oksave ");
    printf("sizemem(coretest2.cr) : %d instructions", sizemem("coretest2.cr"));
}

void savefile(Instruction (*doc)[], int len, char* filename){
    int i = 0;
    FILE* file;
    file = fopen(filename , "w");
    if (file == NULL) printf ("fopen failed");
    printf("savinit ");
    fprintf(file, "%d ", len);
    for (i = 0; i < len; i++){fprintf(file, "%d %d %d %d %d %d ",(*doc)[i].opcode, (*doc)[i].mod, (*doc)[i].aA, (*doc)[i].A, (*doc)[i].aB, (*doc)[i].B);}
    fclose (file);
    printf("oksave ");

}

int sizemem(char *filename){
    FILE* file;
    int data = 0;
    file = fopen(filename, "w");
    if(file == NULL) {printf ("couldnt open file(sizemem)"); return 0;}
    fscanf(file, "%d", &data);
    printf("%d ", data);
    fclose(file);
    return data;
}

void samplewarrior(){
    FILE* text;
    printf("creating sample warrior");
    Instruction Core[2];
    (Core)[0].opcode = ADD;
    (Core)[0].mod = F;
    (Core)[0].aA = dol;
    (Core)[0].A = 13;
    (Core)[0].aB = dol;
    (Core)[0].B = 15;
    (Core)[1].opcode = MOV;
    (Core)[1].mod = I;
    (Core)[1].aA = sharp;
    (Core)[1].A = 6;
    (Core)[1].aB = aro;
    (Core)[1].B = 2;

}


void loadwarrior(){
    FILE* warrior;
    char data[6];
    int size;
    warrior = fopen("warrior.wr", "w");
    if(warrior == NULL) printf ("couldnt open warrior");
    fscanf (warrior, "%s", data);
    size = atoi(data);
}



void injectwarrior(Instruction (*warrior)[], int len, Instruction (*Core)[], int loc){
    int i;
    for(i=0; i<len; i++){
            (*Core)[loc+i].opcode=(*warrior)[i].opcode;
            (*Core)[loc+i].mod=(*warrior)[i].mod;
            (*Core)[loc+i].aA=(*warrior)[i].aA;
            (*Core)[loc+i].A=(*warrior)[i].A;
            (*Core)[loc+i].aB=(*warrior)[i].aB;
            (*Core)[loc+i].B=(*warrior)[i].B;
    }

}
