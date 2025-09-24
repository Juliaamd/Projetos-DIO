#include <stdio.h>
#include <stdlib.h>

int main() {
    char operacao;
    double n1, n2, resultado;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
		
        // Limpar a tela após uma operação
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

   
        printf("Digite a operação desejada (+, -, *, /): ");
        scanf(" %c", &operacao);

        printf("Digite o primeiro número: ");
        scanf("%lf", &n1);

        printf("Digite o segundo número: ");
        scanf("%lf", &n2);

        
        switch (operacao) {
            case '+':
                resultado = n1 + n2;
                break;
            case '-':
                resultado = n1 - n2;
                break;
            case '*':
                resultado = n1 * n2;
                break;
            case '/':
                if (n2 != 0)
                    resultado = n1 / n2;
                else {
                    printf("Erro: divisão por zero!\n");
                    continue; 
                }
                break;
            default:
                printf("Operação inválida!\n");
                continue; 
        }

        printf("\n%.2lf %c %.2lf = %.2lf\n", n1, operacao, n2, resultado);

 
        printf("\nDeseja realizar outra operação? (s/n): ");
        scanf(" %c", &continuar);
    }

    return 0;
}
