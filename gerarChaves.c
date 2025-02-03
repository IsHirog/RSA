#include <stdio.h>
#include <gmp.h>
 
int main() {
    mpz_t p, q, e, n, d,fi_n, mdc;  // eu acrescentei o "d"
    mpz_inits(p, q, e, n, d,fi_n, mdc, NULL); //Acrescentei o "d"
 
    // Entrada
    printf("Digite o p: ");
    gmp_scanf("%Zd", p);
 
    // Verifica se p é primo
    if (mpz_probab_prime_p(p, 50) == 0) {
        printf("p nao e primo\n");
        return 0;
    }
 
    printf("Digite o q: ");
    gmp_scanf("%Zd", q);
 
    // Verifica se q é primo
    if (mpz_probab_prime_p(q, 50) == 0) {
        printf("q nao e primo\n");
        return 0;
    }
 
    // Calculando o valor de n
    mpz_mul(n, p, q);
 
    // Calculando o totiente fi_n
    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);
    mpz_mul(fi_n, p, q);
 
    // Entrada de e
    printf("Digite o e: ");
    gmp_scanf("%Zd", e);
    mpz_invert(d,e,fi_n);  //ACrescentei essa funcao para calcular o "d"
 
    // Verificando se e é coprimo com fi_n
    mpz_gcd(mdc, e, fi_n);
    if (mpz_cmp_ui(mdc, 1) != 0) {
        printf("e nao e coprimo com fi(n)\n");
        return 0;
    }
 
    // Saída
    printf("Chave publica (n, e): ");
    gmp_printf("%Zd %Zd\n", n, e);
    printf("Chave privada (d, fi_n): ");  //ACrescentei esses dois ultimos printf para mostrar a chave privada
    gmp_printf("%Zd %Zd",d,fi_n);
 
    mpz_clears(p, q, e, n, fi_n, mdc, NULL);
 
    return 0;
}