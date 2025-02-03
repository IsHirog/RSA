#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
// Descriptografa
void imprimir_letras(mpz_t array[], int tam) {
    for (int i = 0; i < tam; i++) {
        gmp_printf("%c", (char)mpz_get_ui(array[i]));
    }
}
 
int main() {
    mpz_t p, q, e, n, d, fi_n;
    mpz_inits(p, q, e, n, d, fi_n, NULL);
 
    // Entrada dos valores p, q, e
    printf("Digite o valor de p: ");
    gmp_scanf("%Zd", p);
 
    printf("Digite o valor de q: ");
    gmp_scanf("%Zd", q);
 
    printf("Digite o valor de e: ");
    gmp_scanf("%Zd", e);
 
    // Calculando n = p * q
    mpz_mul(n, p, q);
 
    // Calculando fi_n
    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);
    mpz_mul(fi_n, p, q);
 
    // Calculando o inverso multiplicativo de e mod fi_n
    mpz_invert(d, e, fi_n);
 
    // Declarando a matriz criptografia
    mpz_t criptografia[1000];
    int tamArray = 0;
 
    // Entrada dos valores criptografados
    printf("Digite os valores criptografados (use EOF para terminar): \n");
    while (gmp_scanf("%Zd", criptografia[tamArray]) != EOF) {
        tamArray++;
    }
 
    // Declarando o array descriptografa e alocando memória dinamicamente
    mpz_t *descriptografa = (mpz_t *)malloc((tamArray + 1) * sizeof(mpz_t));
 
    // Descriptografando os valores e armazenando em descriptografa
    for (int i = 0; i < tamArray; i++) {
        mpz_init(descriptografa[i]);
        mpz_powm(descriptografa[i], criptografia[i], d, n);
    }
 
    // Imprimindo a mensagem descriptografada
    printf("Mensagem descriptografada: ");
    imprimir_letras(descriptografa, tamArray);
    printf("\n");
 
    // Liberando memória alocada
    for (int i = 0; i < tamArray; i++) {
        mpz_clear(descriptografa[i]);
    }
    free(descriptografa);
 
    mpz_clears(p, q, e, n, d, fi_n, NULL);
 
    return 0;
}