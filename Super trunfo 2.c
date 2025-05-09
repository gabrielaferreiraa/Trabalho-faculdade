#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.

float calculoDensidade (int populacao, float area) {
    return populacao/area;
}

int calculoPibpercapita (float PIB, int populacao) {
    return PIB/populacao;
}

float calculoDensidadeinvertida (float calculoDensidade) {
    return 1/calculoDensidade;

}
typedef struct {
    unsigned long int populacao;
    float area;
    float PIB;
    int numeroPt;
    float calculoPibpercapita;
    float calculoDensidade
} Cidade;

float calculoSomaatributos (Cidade cidade[], int indice){
    return cidade[indice].populacao + cidade[indice].area + cidade[indice].PIB + cidade[indice].numeroPt + calculoDensidade(cidade[indice].populacao, cidade[indice].area) + calculoPibpercapita(cidade[indice].PIB, cidade[indice].populacao) + calculoDensidadeinvertida(cidade[indice].calculoDensidade);

}

int main() {
    int codigoCidade[2];
    char nomeCidade[2][100] = {'d', 'd'};
    int populacao[2];
    float area[2];
    float PIB[2];
    int numeroPt[2];
    float densidadeInvertida[2];
    int escolha;
    float soma0;
    float soma1;

    // Cadastro das Cartas:
    printf ("Atributos das cidades\n Digite o código da cidade 1:");
    scanf ("%d", &codigoCidade[0]);
    printf ("Digite o código da cidade 2:");
    scanf ("%d", &codigoCidade[1]);

    printf ("Digite o nome da cidade da cidade 1:");
    scanf ("%99s", &nomeCidade[0]);
    printf ("Digite o nome da cidade 2:");
    scanf ("%99s", &nomeCidade[1]);

    printf ("Digite a população da cidade 1:");
    scanf ("%d", &populacao[0]);
    printf ("Digite a população da cidade 2:");
    scanf ("%d", &populacao[1]);

    printf ("Digite a área da cidade 1:");
    scanf ("%f", &area[0]);
    printf ("Digite a área da cidade 2:");
    scanf ("%f", &area[1]);

    printf ("Digite o PIB da cidade 1:");
    scanf ("%f", &PIB[0]);
    printf ("Digite a PIB da cidade 2:");
    scanf ("%f", &PIB[1]);

    printf ("Digite o número de pontos turísticos da cidade 1:");
    scanf ("%d", &numeroPt[0]);
    printf ("Digite o número dos pontos turísticos da cidade 2:");
    scanf ("%d", &numeroPt[1]);

    Cidade cidade[2] = {
        {populacao[0], area[0], PIB[0], numeroPt[0], calculoPibpercapita(PIB[0], populacao[0])},  
        {populacao[1], area[1], PIB[1], numeroPt[1], calculoPibpercapita(PIB[0], populacao[0])}
    };

    //Opções de escolha de atributo
    printf ("Atributos: \n");
    printf ("1 - Atributo POPULAÇÃO\n");
    printf ("2 - Atributo ÁREA\n");
    printf ("3 - Atributo PIB\n");
    printf ("4 - Atributo PONTOS TURÍSTICOS\n");
    printf ("5 - Atributo DENSIDADE POPULACIONAL\n");
    printf ("6 - Atributo PIB PER CAPITA\n");
    printf ("7 - Atributo SUPER PODER\n");
    printf ("Digite o número do atributo que você quer para determinar o vencedor: \n");
    scanf ("%d", &escolha);  

    switch (escolha){
        case 1: //População
            if (cidade[0].populacao > cidade[1].populacao) {
                printf("População: Carta 1 venceu!\n");
            } else if (cidade[0].populacao < cidade[1].populacao) {
                printf("População: Carta 2 venceu!\n");
            } else {
                printf("População: Empate!\n");
            }
            break;
        case 2: //Área
            if (cidade[0].area > cidade[1].area) {
            printf("Área: Carta 1 venceu!\n");
            } else if (cidade[0].area < cidade[1].area) {
            printf("Área: Carta 2 venceu!\n");
            } else {
            printf("Área: Empate!\n");
            }
            break;
        case 3: //PIB
            if (cidade[0].PIB > cidade[1].PIB) {
                printf("PIB: Carta 1 venceu!\n");
            } else if (cidade[0].PIB < cidade[1].PIB) {
                printf("PIB: Carta 2 venceu!\n");
            } else {
                printf("PIB: Empate!\n");
            }
            break;
        case 4: //Pontos turísticos
            if (cidade[0].numeroPt > cidade[1].numeroPt) {
                printf("Pontos turísticos: Carta 1 venceu!\n");
            } else if (cidade[0].numeroPt < cidade[1].numeroPt) {
                printf("Pontos turísticos: Carta 2 venceu!\n");
            } else {
                printf("Pontos turísticos: Empate!\n");
            }
            break;
        case 5: //Densidade Populacional
            if (cidade[0].calculoDensidade > cidade[1].calculoDensidade){
                printf("Densidade populacional: Carta 2 venceu!\n");
            } else if (cidade[0].calculoDensidade < cidade[1].calculoDensidade){
                printf("Densidade populacional: Carta 1 venceu!\n");
            } else {
                printf("Densidade populacional: Empate!\n");
            }
            break;
        case 6: //PIB per capita
            if (cidade[0].calculoPibpercapita > cidade[1].calculoPibpercapita) {
                printf("PIB per capita: Carta 1 venceu!\n");
            } else if (cidade[0].calculoPibpercapita < cidade[1].calculoPibpercapita) {
                printf("PIB per capita: Carta 2 venceu!\n");
            } else {
                printf("PIB per capita: Empate!\n");
            }
            break;
        case 7: // Super poder
            soma0 = calculoSomaatributos(cidade, 1);
            soma1 = calculoSomaatributos(cidade, 1);

            if (soma0 > soma1){
                printf("Super Trunfo: Carta 1 venceu!\n");
            } else if (soma0 < soma1) {
                printf("Super Trunfo: Carta 2 venceu!\n");
            } else {
                printf("Super Trunfo: Empate!\n");
            }
            break;
    }
   
    // Exibição dos Dados das Cartas:
    printf ("\n============== Dados cidade 1 ================\n");
    printf ("Código Cidade: %d\n", codigoCidade[0]);
    printf ("Nome da Cidade: %s\n", nomeCidade[0]);
    printf ("Número da população: %d\n", populacao[0]);
    printf ("Área: %f\n", area[0]);
    printf ("PIB da cidade: %f\n", PIB[0]);
    printf ("Número de pontos turísticos: %d\n", numeroPt[0]);
    printf ("Densidade Populacional: %f\n", calculoDensidade(populacao[0],area[0]));
    printf ("PIB per capita: %d\n", calculoPibpercapita(PIB[0],populacao[0]));

    printf ("\n============== Dados cidade 2 ================\n");
    printf ("Código Cidade: %d\n", codigoCidade[1]);
    printf ("Nome da Cidade: %s\n", nomeCidade[1]);
    printf ("Número da população: %d\n", populacao[1]);
    printf ("Área: %f\n", area[1]);
    printf ("PIB da cidade: %f\n", PIB[1]);
    printf ("Número de pontos turísticos: %d\n", numeroPt[1]);
    printf ("Densidade Populacional: %f\n", calculoDensidade(populacao[1],area[1]));
    printf ("PIB per capita: %d\n", calculoPibpercapita(PIB[1],populacao[1]));

    return 0;
}


