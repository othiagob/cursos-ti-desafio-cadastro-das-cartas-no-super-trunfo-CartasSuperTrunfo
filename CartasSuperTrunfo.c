#include <stdio.h>
#include <string.h>
//Criando um struct para armazenar dados das cidades
//Assim poderei reutilizar o mesmo bloco de código quantas cartas eu quiser.
typedef struct {
    char estado;
    char codigo[3];
    char cidade[30];
    unsigned int populacao;
    float area;
    float pib;
    int pontoTuristico;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta; //Nomiei a struct com Carta, agora vou só adicionar o numero no fim do nome para representar a carta que desejo.

//Agora e a funcao para registrar as informacoes digitadas pelo usuario.
void cadastroCartas(Carta *c, int num){
  printf("\nDigite os dados da carta %d:\n", num);
  printf("_____________________________________\n");

  printf("Digite a letra do estado de A até H: ");
  scanf(" %c", &c->estado);

  printf("Digite o código da carta: ");
  scanf("%s", c->codigo);

  getchar(); //Limpando o buffer e não dar prego no programa
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

    c->densidadePopulacional = (float)c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1e9) / c->populacao;
    c->superPoder = c->populacao + c->area + (c->pib * 1e9) + c->pontoTuristico + (1.0 / c->densidadePopulacional);


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
    printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB PER CAPITA: %.2f reais\n", c.pibPerCapita);
    printf("SUPER PODER: %.2f\n", c.superPoder);

}   //OBS: esse trecho do PIB PER CAPITA: (c.pib * 1e9) serve para colocar o valor digitado pelo usuario em bilhoes.
    //Por exemplo: Se digitar 699.28 no console, o PIB PER CAPITA sai zerado no fim do programa.
    //Mas como eu pego este valor 699.28 * 1bilhão isso faz com que o calculo de PIB/POPULACAO tenha a saída correta.
    //Foi necessário pesquisa no google e ajuda do chatgpt para entender como poderia aplicar uma solução viavel e pratica pra este problema.

//Criando uma função para comparar as duas cartas que vou digitar.
typedef enum {FALSO, VERDADEIRO} Bool;
void compararCartas(Carta c1, Carta c2) {
    printf("\n-----COMPARANDO AS CARTAS-----\n");
    printf("POPULAÇÃO: Carta %d venceu(%d)\n!", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao ? VERDADEIRO : FALSO);
    printf("AREA: Carta %d venceu! (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area ? VERDADEIRO : FALSO);
    printf("PIB: Carta %d venceu! (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib ? VERDADEIRO : FALSO);
    printf("PONTOS TURISTICOS: Carta %d venceu! (%d)\n", c1.pontoTuristico > c2.pontoTuristico ? 1 : 2, c1.pontoTuristico > c2.pontoTuristico ? VERDADEIRO : FALSO);
    printf("DENSIDADE POPULACIONAL: Carta %d venceu! (%d)\n", c1.densidadePopulacional > c2.densidadePopulacional ? 1 : 2, c1.densidadePopulacional > c2.densidadePopulacional ? VERDADEIRO : FALSO);
    printf("PIB PER CAPITA: Carta %d venceu! (%d)\n", c1.pibPerCapita > c2.pibPerCapita ? 1 : 2, c1.pibPerCapita > c2.pibPerCapita ? VERDADEIRO : FALSO);
    printf("SUPER PODER: Carta %d venceu! (%d)\n", c1.superPoder > c2.superPoder ? 1 : 2, c1.superPoder > c2.superPoder ? VERDADEIRO : FALSO);

}


//Agora vamos iniciar o programa, chamando a função main e adicionando as funcoes que criamos dentro do corpo dela.
int main(){
  Carta carta1, carta2;

  cadastroCartas(&carta1, 1);
  cadastroCartas(&carta2, 2);

  exibirCarta(carta1, 1);
  exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);
}