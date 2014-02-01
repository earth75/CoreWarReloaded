#include "mars.h"
#include "Redcode.h"

int exec(Instruction (*inst)[], int addr){
    switch ((*inst)[addr].op){
    case DAT : return -1;
    case MOV : break;
    case ADD : break;
    case SUB : break;
    case MUL : break;
    case DIV : break;
    case MOD : break;
    case JMP : break;
    case JMZ : break;
    case JMN : break;
    case DJM : break;
    case SPL : break;
    case SEQ : break;
    case SNE : break;
    case SLT : break;
    case LDP : break;
    case STP : break;
    case NOP : break;
    default : break;
    }

}
