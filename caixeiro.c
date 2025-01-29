#include <stdio.h>
#include <limits.h>

//Resolução utilizando o algoritmo do vizinho mais proximo.
void cidadeMaisProxima(int Ncidades, int distancias[Ncidades][Ncidades]){
    int cidadesVisitadas[Ncidades];
    int caminho[Ncidades];
    int distanciaTotal=0;
    int cidade_natal = 0;
    //inicializa array
    for(int i=0; i<Ncidades; i++){
        cidadesVisitadas[i]=0;
    }

    int atualCidade = cidade_natal;     // Começa pela cidade 0 (cidade natal)
    cidadesVisitadas[atualCidade] = 1; // Marca a cidade inicial como visitada
    caminho[0] = atualCidade;   // Adiciona a cidade inicial ao caminho

    // Itera para encontrar o caminho
    for (int passo = 1; passo < Ncidades; passo++) {
        int cidadeProx = -1;
        int menorDistancia= INT_MAX;

        // Encontra a cidade não visitada mais próxima
        for (int i = 0; i < Ncidades; i++) {
            if (!cidadesVisitadas[i] && distancias[atualCidade][i] < menorDistancia && atualCidade != i) {
                cidadeProx = i;
                menorDistancia = distancias[atualCidade][i];
            }
        }

        // Vai para a cidade mais próxima
        atualCidade = cidadeProx;
        cidadesVisitadas[atualCidade] = 1;
        caminho[passo] = atualCidade;
        distanciaTotal += menorDistancia;
    }


    // Imprime o caminho e a distância total
    printf("Caminho: ");
    for (int i = 0; i < Ncidades; i++) {
        printf("%d ", caminho[i]);
    }
    printf("%i",cidade_natal);//Volta diretamente para a cidade Natal
    distanciaTotal += distancias[atualCidade][caminho[0]];//soma a distancia entre a cidade final e a cidade natal
    printf("\nDistancia total: %d\n", distanciaTotal);
}

int main() {
    int Ncidades;

    printf("Número de cidades: ");
    scanf("%d", &Ncidades);
    int formato_matriz;
    printf("digite 0 para diagonal inferior e 1 para diagonal superior");
    scanf("%i",&formato_matriz);
    int distancias[Ncidades][Ncidades];
    int lixo;
    printf("Enter the distance matrix:\n");
    if(formato_matriz == 1){ 
        for (int i = 0; i < Ncidades - 1 ; i++){
            scanf("%i",&lixo);
            for (int j = i+1; j < Ncidades; j++){
                scanf("%d", &distancias[i][j]);
                distancias[j][i] = distancias[i][j];
            }
        }
    }
    else if (formato_matriz == 0){
        scanf("%i",&lixo);
        for (int i = 1; i < Ncidades; i++){
            for (int j = 0; j < i; j++){
                scanf("%d", &distancias[i][j]);
                distancias[j][i] = distancias[i][j];
            }
            scanf("%i",&lixo);
        }
    }
    else
        printf("Valor inválido para formato da matriz");

    

    cidadeMaisProxima(Ncidades, distancias);

}