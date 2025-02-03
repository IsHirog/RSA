#include <stdio.h>
#include <string.h>
#include <gmp.h>
 
void imprimir ( mpz_t array[], int tam)
{
    for( int i = 0; i < tam; i++)
    {
        gmp_printf("%Zd ",array[i]);
    }
}
 
int main()
{
 
    //Declarando as variaveis
    mpz_t p,q,e,n;
    mpz_inits(p,q,e,n,NULL);
 
    char mensagem[1000];
    int tamArray = 0;
 
 
    
    //Pega a mensagem
    printf("Digite a mensagem: ");
    fgets(mensagem, 1000, stdin);
 
 
    mensagem[strcspn(mensagem, "\n")] = 0;
 
    //Digite as chaves publicas
    printf("Digite a chave pública 'e': ");
    gmp_scanf("%Zd",e);
    printf("Digite a chave pública 'n': ");
    gmp_scanf("%Zd",n);
 
     //Array que armazenarah a mensagem criptografada
    mpz_t criptografar [strlen(mensagem)];
 
    for ( int i = 0; i < strlen(mensagem); i++)
    {
        mpz_init(criptografar[i]);
 
        //converter caracter para numero inteiro
        mpz_set_ui(criptografar[i],mensagem[i]);
 
        //Criptografar o caracter
        mpz_powm(criptografar[i], criptografar[i],e,n);
    }
 
    //Mensagem
    imprimir(criptografar,strlen(mensagem));
    printf("\n");
 
    //Liberar memória alocada
    for ( int i = 0; i < strlen(mensagem); i++)
    {
        mpz_clear(criptografar[i]);
    }
 
    mpz_clears( p,q,e,n,NULL);
 
    return 0;
}