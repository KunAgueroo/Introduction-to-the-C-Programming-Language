#include "math.h"


// goal: read equations from a file and write them in a solved state to another
// file
//   NOTE: format details specified in instructions
// param qfile: file with math questions to solve
// param afile: file to write equations with answers in
// example:
//   qfile at start of function:
//     12 + 13
//     24 / 5
//     8 * 234
//     65 - 78
//     239 % 13
//   afile after function:
//      12 +  13 = 25
//      24 /   5 = 4
//       8 * 234 = 1872
//      65 -  78 = -13
//     239 %  13 = 5
//
// TODO: Complete the function
void solve(const char* qfile, const char* afile) {
    FILE *inputFile;
    inputFile = fopen(qfile, "r");
if (inputFile == NULL){
    return;
}
    FILE *outputFile;
    outputFile = fopen(afile, "w");
if (outputFile == NULL){
    fclose (inputFile);
    return;
}
    int lhs;
    int rhs;
    int result;
    int i;
    char op;
    while ((i = fscanf (inputFile, "%d %c %d", &lhs, &op, &rhs)) == 3) {
        switch (op) {
            case '+':
                result = lhs + rhs;
                break;
            case '-':
                result = lhs - rhs;
                break;
            case '*':
                result = lhs * rhs;
                break;
            case '/':
                result = lhs / rhs;
                break;
            case '%':
                result = lhs % rhs;
                break;
            default:
                continue;
        }
        fprintf(outputFile,"%3d %c %3d = %d\n",lhs,op,rhs,result);
    }
    fclose(inputFile);
    fclose(outputFile);
}
