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
    char c;
    int i = 0;
q0:
    c = palavra[i++];
    if (c == '-') goto q1;
    else if (c == '$') goto q3;
    else if (c >= '1' && c <= '9') goto q10;
    else if (c == ',' || c == '.') goto q18;
    else if (c == '0') goto q20;
    else return (_REJEITA_);
 
q1:
    c = palavra[i++];
    if (c == '0') goto q2;
    else if (c >= '1' && c <= '9') goto q4;
    else if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q2:
    c = palavra[i++];
    if (c == ',') goto q6;
    else if ((c >= '0' && c <= '9') || c == '$' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q3:
    c = palavra[i++];
    if (c == '0') goto q12;
    else if (c >= '1' && c <= '9') goto q16;
    else if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q4: /* Inteiro com sinal - estado final */
    c = palavra[i++];
    if (c >= '0' && c <= '9') goto q4;
    else if (c == '.') goto q5;
    else if (c == ',') goto q6;
    else if (c == '$' || c == '-') goto q18;
    else if (c == '\0') return (_INTEIRO_COM_SINAL_);
    else return (_REJEITA_);
 
q5:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q26;
    else return (_REJEITA_);
 
q6:
    c = palavra[i++];
    if (c >= '1' && c <= '9') goto q7;
    else if (c == '0') goto q8;
    else if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q7: /* Ponto Flutuante com Sinal - estado final */
    c = palavra[i++];
    if (c >= '0' && c <= '9') goto q9;
    else if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c == '\0') return (_P_FLUTUANTE_COM_SINAL_);
    else return (_REJEITA_);
 
q8:
    c = palavra[i++];
    if (c >= '1' && c <= '9') goto q9;
    else if (c == '0' || c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q9: /* Ponto Flutuante com Sinal - estado final */
    c = palavra[i++];
    if ((c >= '0' && c <= '9') || c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c == '\0') return (_P_FLUTUANTE_COM_SINAL_);
    else return (_REJEITA_);
 
q10: /* Inteiro - estado final */
    c = palavra[i++];
    if (c >= '0' && c <= '9') goto q10;
    else if (c == '.') goto q11;
    else if (c == '$' || c == '-') goto q18;
    else if (c == ',') goto q21;
    else if (c == '\0') return (_INTEIRO_);
    else return (_REJEITA_);
 
q11:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q29;
    else return (_REJEITA_);
 
q12:
    c = palavra[i++];
    if (c == ',') goto q13;
    else if ((c >= '0' && c <= '9') || c == '$' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q13:
    c = palavra[i++];
    if (c >= '0' && c <= '9') goto q14;
    else if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q14:
    c = palavra[i++];
    if (c >= '0' && c <= '9') goto q15;
    else if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else return (_REJEITA_);
 
q15: /* Monetario - estado final */
    c = palavra[i++];
    if ((c >= '0' && c <= '9') || c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c == '\0') return (_VALOR_MONETARIO_);
    else return (_REJEITA_);
 
q16:
    c = palavra[i++];
    if (c == ',') goto q13;
    else if (c >= '0' && c <= '9') goto q16;
    else if (c == '.') goto q17;
    else if (c == '$' || c == '-') goto q18;
    else return (_REJEITA_);
 
q17:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-') goto q18;
    else if (c >= '0' && c <= '9') goto q32;
    else return (_REJEITA_);
 
q18: /* Poco (estado de erro, sem saidas) */
    c = palavra[i++];
    return (_REJEITA_);
 
q20:
    c = palavra[i++];
    if ((c >= '0' && c <= '9') || c == '$' || c == '-' || c == '.') goto q18;
    else if (c == ',') goto q21;
    else return (_REJEITA_);
 
q21:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c == '0') goto q22;
    else if (c >= '1' && c <= '9') goto q25;
    else return (_REJEITA_);
 
q22:
    c = palavra[i++];
    if (c == '0' || c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '1' && c <= '9') goto q23;
    else return (_REJEITA_);
 
q23: /* Ponto Flutuante - estado final */
    c = palavra[i++];
    if ((c >= '0' && c <= '9') || c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c == '\0') return (_P_FLUTUANTE_);
    else return (_REJEITA_);
 
q25: /* Ponto Flutuante - estado final */
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q23;
    else if (c == '\0') return (_P_FLUTUANTE_);
    else return (_REJEITA_);
 
q26:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q27;
    else return (_REJEITA_);
 
q27:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q28;
    else return (_REJEITA_);
 
q28: /* Inteiro com sinal - estado final */
    c = palavra[i++];
    if (c == '.') goto q5;
    else if (c == ',') goto q6;
    else if ((c >= '0' && c <= '9') || c == '$' || c == '-') goto q18;
    else if (c == '\0') return (_INTEIRO_COM_SINAL_);
    else return (_REJEITA_);
 
q29:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q30;
    else return (_REJEITA_);
 
q30:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q31;
    else return (_REJEITA_);
 
q31:
    c = palavra[i++];
    if (c == '.') goto q11;
    else if ((c >= '0' && c <= '9') || c == '$' || c == '-') goto q18;
    else if (c == ',') goto q21;
    else return (_REJEITA_);
 
q32:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q34;
    else return (_REJEITA_);
 
q33:
    c = palavra[i++];
    if (c == ',') goto q13;
    else if (c == '.') goto q16;
    else if ((c >= '0' && c <= '9') || c == '$' || c == '-') goto q18;
    else return (_REJEITA_);
 
q34:
    c = palavra[i++];
    if (c == '$' || c == ',' || c == '-' || c == '.') goto q18;
    else if (c >= '0' && c <= '9') goto q33;
    else return (_REJEITA_);
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
