#include <stdio.h>
#include <windows.h>
#include <locale.h>

struct Carro
{
    int velocidade;
    int aceleracao;
    int freio;
};

int acelerar(struct Carro x, int y){
    while(x.velocidade < y){
    x.velocidade += x.aceleracao;
    Beep(0,100);
    printf("\r%d ", x.velocidade);
    printf("km/h");
    }
    return x.velocidade;
}

int frear(struct Carro w, int z){
    if(z==0){
        while(w.velocidade != 0){
        w.velocidade -= w.freio;
        Beep(0,200);
        printf("\r%d ", w.velocidade);
        printf("km/h");
        }
    }
    while(w.velocidade > z){
    w.velocidade -= w.freio;
    Beep(0,200);
    printf("\r%d ", w.velocidade);
    printf("km/h");
    }
    return w.velocidade;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    struct Carro c1;
    c1.velocidade = 0;
    c1.aceleracao = 10;
    c1.freio = 5;

    printf("Bem-vindo ao meu carro!!");
    printf("\n\nDê partida no carro pressionando ENTER.");
    getc(stdin);


    printf("Carro iniciando \n[");
    for(int i=0;i<9;i++){
        Beep(0,100);
        printf("=");
    }

    printf("]\n");
    Beep(0,100);

    system("cls");
    
    
    printf("\nCarro Parado e Ligado.");
    printf("\nPressione ENTER para Acelerar para 50km/h");
    getc(stdin);
    
    printf("Carro em movimento...\n");
    printf("Velocidade: \n");
    c1.velocidade = acelerar(c1,50);

    printf("\nPressione ENTER para freiar para 30km/h");
    getc(stdin);
    system("cls"); 
    
    printf("Carro em movimento...\n");
    printf("Velocidade: \n");
    c1.velocidade = frear(c1,30);

    printf("\npressione ENTER para parar o carro");
    getc(stdin);
    system("cls"); 
    
    printf("Carro em movimento...\n");
    printf("Velocidade: \n");
    c1.velocidade = frear(c1,0);
    system("cls");

    printf("\nO carro está parado, pressione ENTER para desligá-lo\n");
    getc(stdin);
    printf("\nCarro desligado.");
    return 0;

}