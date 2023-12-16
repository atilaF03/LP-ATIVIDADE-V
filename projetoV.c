#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 10

struct Produto {
    int codigo, quantidade;
    char nome[500];
    float preco;
};

struct Produto estoque[MAX_PRODUTOS];
int numProdutos = 0;

void adicionarProduto() {
        struct Produto novoProduto;

        printf("\nDigite o c�digo do produto: ");
        scanf("%d", &novoProduto.codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &novoProduto.quantidade);
        printf("Digite o pre�o do produto: ");
        scanf("%f", &novoProduto.preco);

        estoque[numProdutos] = novoProduto;
        numProdutos++;
        printf("\nProduto adicionado com sucesso!\n");
}

void listarProdutos() {
    int i;
    printf("Lista de Produtos no Estoque:\n");
    for (i = 0; i < numProdutos; i++) {
        printf("\nC�digo: %d \n", estoque[i].codigo);
        printf("Mercadoria: %s \n", estoque[i].nome);
        printf("Pre�o: R$%.2f \n", estoque[i].preco);
        printf("Quantidade: %d \n", estoque[i].quantidade);
    }
}

void buscarProdutoPorCodigo() {
    int codigo;
    printf("\nInforme o c�digo do produto a ser buscado: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\nProduto encontrado!\n");
            printf("C�digo: %d \n", estoque[i].codigo);
            printf("Mercadoria: %s \n", estoque[i].nome);
            printf("Pre�o: R$%.2f \n", estoque[i].preco);
            printf("Quantidade: %d \n", estoque[i].quantidade);
            return;
        }
    }
    printf("\nProduto n�o encontrado!\n");
    printf("Por favor! Informe um c�digo existente!");
}

void atualizarQuantidade() {
    int codigo, quantidade;
    printf("\nInforme o c�digo do produto para atualizar a quantidade: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Digite a quantidade a ser adicionada: ");
            scanf("%d", &quantidade);
            estoque[i].quantidade += quantidade;
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }
    printf("Produto n�o encontrado!\n");
    printf("Por favor! Informe um c�digo existente!");
}

int main() {

    setlocale(LC_ALL, "portuguese");

    int opcao;

    do {
        printf("\nGest�o de Estoque Casas Bahia\n");
        printf("\nEscolha uma das op��es abaixo\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Exibir estoque\n");
        printf("3 - Buscar produto por c�digo\n");
        printf("4 - Atualizar quantidade\n");
        printf("5 - Encerrar programa\n");
        printf("Escolha a op��o desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                buscarProdutoPorCodigo();
                break;
            case 4:
                atualizarQuantidade();   
                break; 
            case 5:
                printf("\nPrograma encerrado...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }

    } while (opcao != 5);

    return 0;

}