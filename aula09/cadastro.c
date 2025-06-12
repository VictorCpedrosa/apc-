#include <stdio.h>
#include <string.h>
int main()
{
    struct endereco_t
    {
        char logradouro[61];
        int numero;
        int cep;
        char complemento[61];
        char cidade[41];
        char uf[3];
    };

    struct cliente_t
    {
        char nome[61];
        long long int telefone;
        char email[61];
        struct endereco_t endereco;
    };

    struct cliente_t cliente;
    strcpy(cliente.nome, "JOSE");
    cliente.telefone = 61111111111L;
    strcpy(cliente.email, "jose@iesb.br");
    strcpy(cliente.endereco.logradouro, "sqs");
    cliente.endereco.numero = 612;
    cliente.endereco.cep = 70000000;
    strcpy(cliente.endereco.complemento, "iesb");
    strcpy(cliente.endereco.cidade, "Brasilia");
    strcpy(cliente.endereco.uf, "DF");

    printf("Dados do cliente\n");
    printf("Nome: %s\n", cliente.nome);
    printf("Telefone: %lli\n", cliente.telefone);
    printf("E-mail: %s\n", cliente.email);
    printf("Endereco: %s, %i - %s - %s/%s\n", cliente.endereco.logradouro, cliente.endereco.numero, cliente.endereco.complemento, cliente.endereco.cidade, cliente.endereco.uf);
    printf("CEP: %i", cliente.endereco.cep);

    struct cliente_t clientes[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Cliente %i\n", i + 1);
        printf("Entre com o nome do cliente: ");
        scanf("%s", clientes[i].nome);

        printf("Entre com o telefone do cliente: ");
        scanf("%lli", &clientes[i].telefone);

        printf("Entre com o email do cliente: ");
        scanf("%s", clientes[i].email);

        printf("Entre com o endereco do cliente: ");
        printf("Logradouro: ");
        scanf("%s", clientes[i].endereco.logradouro);
        printf("Numero: ");
        scanf("%i", &clientes[i].endereco.numero);
        printf("Complemento: ");
        scanf("%s", clientes[i].endereco.complemento);
        printf("Cidade: ");
        scanf("%s", clientes[i].endereco.cidade);
        printf("UF: ");
        scanf("%s", clientes[i].endereco.uf);
        printf("CEP: ");
        scanf("%i", &clientes[i].endereco.cep);
    }

    return 0;
}