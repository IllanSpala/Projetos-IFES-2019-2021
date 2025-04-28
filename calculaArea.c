#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    float basemenor, basemaior, altura, area;

    printf("\nDigite o valor da base maior: ");
    scanf("%f", &basemaior);
    while (basemaior <= 0) {
        printf("\nO valor informado nao e valido. Digite novamente o valor da base maior: ");
        scanf("%f", &basemaior);
    }

    printf("\nDigite o valor da base menor: ");
    scanf("%f", &basemenor);
    while (basemenor <= 0) {
        printf("\nO valor informado nao e valido. Digite novamente o valor da base menor: ");
        scanf("%f", &basemenor);
    }
  
    while (basemenor > basemaior) {
        printf("\nO valor da base menor nao pode ser maior que a base maior");
        printf("\nDigite o valor da base menor novamente: ");
        scanf("%f", &basemenor);
        printf("\nDigite o valor da base maior novamente: ");
        scanf("%f", &basemaior);
    }

    printf("\nDigite a altura: ");
    scanf("%f", &altura);
    while (altura <= 0) {
        printf("\nO valor informado nao e valido. Digite novamente o valor da altura: ");
        scanf("%f", &altura);  // Corrigido de "&f" para "%f"
    }

    area = ((basemenor + basemaior) * altura) / 2;
    printf("\nA area do trapezio == %.2f\n", area);  
    
    return 0;
}