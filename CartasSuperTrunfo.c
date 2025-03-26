#include <stdio.h>
#include <string.h>
//Criando um struct para armazenar dados das cidades
//Assim poderei reutilizar o mesmo bloco de código quantas cartas eu quiser.
typedef struct {
    char estado;
    char codigo[3];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontoTuristico;
} Carta; //Nomiei a struct com Carta, agora vou só adicionar o numero no fim do nome para representar a carta que desejo.

//Agora e a funcao para registrar as informacoes digitadas pelo usuario.
void cadastroCartas(Carta *c, int num){
  getchar();
  printf("\nDigite os dados da carta %d:\n", num);
  printf("_____________________________________\n");

  printf("Digite a letra do estado de A até H: ");
  scanf("%c", &c->estado);

  printf("Digite o código da carta: ");
  scanf("%s", c->codigo);

  getchar(); //Limpando o buffer
  printf("Digite o nome da cidade: ");
  fgets(c->cidade, sizeof(c->cidade), stdin);
  c->cidade[strcspn(c->cidade,"\n")] = '\0';

  printf("Digite a quantidade da população: ");
  scanf("%d", &c->populacao);

  printf("Digite a area em Km²: ");
  scanf("%f", &c->area);

  printf("Digite o PIB da cidade: ");
  scanf("%f", &c->pib);

  printf("Digite a quantidade de pontos turisticos: ");
  scanf("%d", &c->pontoTuristico);
}
//Funcao para exibir as informacoes registradas
void exibirCarta(Carta c, int num){
    printf("\n=========== CARTA %d ===========\n", num);
    printf("ESTADO: %c\n", c.estado);
    printf("CODIGO: %s\n", c.codigo);
    printf("NOME DA CIDADE: %s\n", c.cidade);
    printf("POPULACAO: %d\n", c.populacao);
    printf("AREA:  %.2f Km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("PONTOS TURISTICOS: %d\n", c.pontoTuristico);

}

//Agora vamos iniciar o programa, chamando a função main e adicionando as funcoes que criamos dentro do corpo dela.
int main(){
  Carta carta1, carta2;

  cadastroCartas(&carta1, 1);
  cadastroCartas(&carta2, 2);

  exibirCarta(carta1, 1);
  exibirCarta(carta2, 2);
}