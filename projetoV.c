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

        printf("\nDigite o código do produto: ");
        scanf("%d", &novoProduto.codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &novoProduto.quantidade);
        printf("Digite o preço do produto: ");
        scanf("%f", &novoProduto.preco);

        estoque[numProdutos] = novoProduto;
        numProdutos++;
        printf("\nProduto adicionado com sucesso!\n");
}

void listarProdutos() {
    int i;
    printf("Lista de Produtos no Estoque:\n");
    for (i = 0; i < numProdutos; i++) {
        printf("\nCódigo: %d \n", estoque[i].codigo);
        printf("Mercadoria: %s \n", estoque[i].nome);
        printf("Preço: R$%.2f \n", estoque[i].preco);
        printf("Quantidade: %d \n", estoque[i].quantidade);
    }
}

void buscarProdutoPorCodigo() {
    int codigo;
    printf("\nInforme o código do produto a ser buscado: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\nProduto encontrado!\n");
            printf("Código: %d \n", estoque[i].codigo);
            printf("Mercadoria: %s \n", estoque[i].nome);
            printf("Preço: R$%.2f \n", estoque[i].preco);
            printf("Quantidade: %d \n", estoque[i].quantidade);
            return;
        }
    }
    printf("\nProduto não encontrado!\n");
    printf("Por favor! Informe um código existente!");
}

void atualizarQuantidade() {
    int codigo, quantidade;
    printf("\nInforme o código do produto para atualizar a quantidade: ");
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
    printf("Produto não encontrado!\n");
    printf("Por favor! Informe um código existente!");
}

int main() {

    setlocale(LC_ALL, "portuguese");

    int opcao;

    do {
        printf("\nGestão de Estoque Casas Bahia\n");
        printf("\nEscolha uma das opções abaixo\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Exibir estoque\n");
        printf("3 - Buscar produto por código\n");
        printf("4 - Atualizar quantidade\n");
        printf("5 - Encerrar programa\n");
        printf("Escolha a opção desejada: ");
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
                printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    return 0;

}