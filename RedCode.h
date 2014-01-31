#include <stdio.h>

/*Setting the RedCode paradigm*/
typedef enum {DAT, MOV, ADD, SUB, MUL, DIV, MOD, JMP, JMZ, JMN, DJM, SPL, SEQ, SNE, SLT, LDP, STP, NOP} Opcode;
typedef enum {sharp, dol, star, aro, BO, BC, LT, GT} AddrMode;
typedef enum {A, B, AB, BA, F, X, I} Modifier;
typedef struct { Opcode opcode; Modifier mod; AddrMode aA; int A; AddrMode aB; int B;} Instruction;

void redcode();
void initMARS();
