#include <stdio.h>

#define _REJEITA_ 0
#define _INTEIRO_ 1
#define _INTEIRO_COM_SINAL_ 2
#define _P_FLUTUANTE_ 3
#define _P_FLUTUANTE_COM_SINAL_ 4
#define _VALOR_MONETARIO_ 5

int confereErro(char palavra[])
{
    int i = 0;
    int sinal = 0;
    int monetario = 0;

    if (palavra[i] == '-') {
        sinal = 1;
        i++;
    } else if (palavra[i] == '$') {
        monetario = 1;
        i++;
    }

    if (palavra[i] != '0') return 0;       /* nao comeca com zero */
    i++;

    if (palavra[i] >= '0' && palavra[i] <= '9')
        return 1;                          /* zero a esquerda */

    if (palavra[i] == '\0')
        return sinal;                      /* "0" certo, "-0" errado */

    if (monetario) return 0;               /* "$0,00" e valido */

    if (palavra[i] == ',' || palavra[i] == '.') {
        i++;
        while (palavra[i] == '0') i++;
        if (palavra[i] == '\0') return 1;   /* 0,0 / 0,00 / -0,000 ... */
    }

    return 0;
}

int scanner(char palavra[])
{
    return _REJEITA_;
}

void imprimeResultado(char palavra[], int resultado)
{
    printf("para \"%s\" eh ", palavra);
    if (resultado == _INTEIRO_) printf("<INTEIRO>\n");
    else if (resultado == _INTEIRO_COM_SINAL_) printf("<INTEIRO COM SINAL>\n");
    else if (resultado == _P_FLUTUANTE_) printf("<P.FLUTUANTE>\n");
    else if (resultado == _P_FLUTUANTE_COM_SINAL_) printf("<P.FLUTUANTE COM SINAL>\n");
    else if (resultado == _VALOR_MONETARIO_) printf("<VALOR MONETARIO>\n");
    else printf("<ERRO>\n");
}

int main(){

    char palavra1 [] = "21";
    char palavra2 [] = "-21";
    char palavra3 [] = "021";
    char palavra4 [] = "2.1";
    char palavra5 [] = "2,1";
    char palavra6 [] = "-0,34";
    char palavra7 [] = "05,567";
    char palavra8 [] = "$5.567,78";
    char palavra9 [] = "-2.1";
    int resultado;
    
    /* chama confere erro [0; -0.0;zeros a esquerda(000143)] */

    /* chama scanner */

    /* printa resultado */
    
    resultado = scanner(palavra1);
    if (confereErro(palavra1)) resultado = _REJEITA_;
    imprimeResultado(palavra1, resultado);
 
    resultado = scanner(palavra2);
    if (confereErro(palavra2)) resultado = _REJEITA_;
    imprimeResultado(palavra2, resultado);
 
    resultado = scanner(palavra3);
    if (confereErro(palavra3)) resultado = _REJEITA_;
    imprimeResultado(palavra3, resultado);
 
    resultado = scanner(palavra4);
    if (confereErro(palavra4)) resultado = _REJEITA_;
    imprimeResultado(palavra4, resultado);
 
    resultado = scanner(palavra5);
    if (confereErro(palavra5)) resultado = _REJEITA_;
    imprimeResultado(palavra5, resultado);
 
    resultado = scanner(palavra6);
    if (confereErro(palavra6)) resultado = _REJEITA_;
    imprimeResultado(palavra6, resultado);
 
    resultado = scanner(palavra7);
    if (confereErro(palavra7)) resultado = _REJEITA_;
    imprimeResultado(palavra7, resultado);
 
    resultado = scanner(palavra8);
    if (confereErro(palavra8)) resultado = _REJEITA_;
    imprimeResultado(palavra8, resultado);
 
    resultado = scanner(palavra9);
    if (confereErro(palavra9)) resultado = _REJEITA_;
    imprimeResultado(palavra9, resultado);
 
    return 0;
}
