#include <stdio.h>
#include <math.h>
#include <string.h>

void calculadora();
void calcularNovamente();


int main() {
    printf("$$$$$$ CALCULADORA DE JUROS $$$$$$$\n");
    calculadora();
    return 0;
}



void calcularJurosSimples(float C, float i, float t) {
    float J = C * i * t;
    float M = C + J;
    printf("\n\nCapital inicial: R$ %.2f \n\nJuros: R$ %.2f\n\nMontante: R$ %.2f", C, J, M);
    calcularNovamente();
}

void calcularJurosCompostos(float C, float i, float n) {
    float M = C * pow((1 + i), n);
    float J = M - C;

    printf("\n\nCapital inicial: R$ %.2f \n\nJuros: R$ %.2f\n\nMontante: R$ %.2f", C, J, M);
    calcularNovamente();
}

void calcularJuros(float C, float i, float t, char tipo[2]) {
    i *= 0.01;

    if (strstr(tipo, "c") != NULL) {
        printf("\n| CALCULANDO A JUROS COMPOSTOS: |\n");
        calcularJurosCompostos(C, i, t);
    } else if (strstr(tipo, "s") != NULL ) {
        printf("\n| CALCULANDO A JUROS SIMPLES: |\n");
        calcularJurosSimples(C, i, t);
    } else {
        printf("\nTipo de juros inválido! Tente novamente.\n");
        calculadora();
    }
}


void calcularNovamente() {
    char resposta[2];
   
    printf("\n\n\nDeseja fazer outro cálculo? s/n\n");
    scanf("%1s", resposta);

    if (strstr(resposta, "s") != NULL) {
        calculadora();
    } else {
        printf("Ok, tudo bem!\n");
    }
}


void calculadora() {
    float capital, taxa, periodo;
    char  tipoDeJuros[2];

    printf("\nCapital inicial: ");
    scanf("%f", &capital);

    printf("\nTaxa(%%): ");
    scanf("%f", &taxa);

    printf("\nPeríodo: ");
    scanf("%f", &periodo);

    printf("\n\nJuros simples ou compostos? s/c \n");
    scanf("%1s", tipoDeJuros);

    calcularJuros(capital, taxa, periodo, tipoDeJuros);
}
    
