#include <stdio.h>

#define _ACEITA_ 1
#define _REJEITA_ 0

int confereErro(){

}

int scanner(){

}

int main(){

    char palavra [] = "21";
    char palavra [] = "-21";
    char palavra [] = "021";
    char palavra [] = "2.1";
    char palavra [] = "2,1";
    char palavra [] = "-0,34";
    char palavra [] = "05,567";
    char palavra [] = "$5.567,78";
    char palavra [] = "2.1";


    //chama confere erro [0; -0.0;zeros a esquerda(000143)]

    //chama scanner

    //printa resultado

    return 0;
}