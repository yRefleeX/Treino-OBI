#include <stdio.h>
#include <stdlib.h>

void verificaCartas(int cartas[]){
    int cont = 0, cartasRestantes;

    for(int i = 0; i < 13; i++){
        if(cartas[i] > 1){
            printf("erro\n");
            return;
        }
        if(cartas[i] == 1){
            cont++;
        }
    }

    cartasRestantes = 13 - cont;
    printf("%i\n",cartasRestantes);
}

int main(){
    char baralho[157];
    int tamanho;

    //Lendo a cadeia de caracteres que descreve as cartas do baralho
    do{
        scanf("%s",baralho);
        tamanho = strlen(baralho);
    }
    while(tamanho < 3);

    int valor_str[2], valor, copas[13] = {0}, espadas[13] = {0}, ouros[13] = {0}, paus[13] = {0};
    char naipe;

    for(int i = 0; i<tamanho; i+=3){
        valor_str[0] = baralho[i] - 48;
        valor_str[1] = baralho[i+1] - 48;

        valor = ((valor_str[0]*10) + valor_str[1]) - 1;

        naipe = baralho[i+2];
    
        switch(naipe){
            case 'C':
                copas[valor]++;
                break;
            case 'E':
                espadas[valor]++;
                break;
            case 'U':
                ouros[valor]++;
                break;
            case 'P':
                paus[valor]++;
                break;
        }
    }

    verificaCartas(copas);
    verificaCartas(espadas);
    verificaCartas(ouros);
    verificaCartas(paus);
    return 0;
}