#include "modulo.hpp"
using namespace std;

int main(){
    int NumberOfPlayers, Options;
    properties prop[PROP];
    rents rent[RENT];

    if(!ReadProperties(&prop[0])){
        puts("Don't open properties");
        return 0;
    }
    if(!ReadRents(&rent[0])){
        puts("Don't open rents");
        return 0;
    }

    printf(" NÚMERO DE JOGADORES NA PARTIDA: ");
    scanf("%d", &NumberOfPlayers);
    cin.ignore();

    players jog[NumberOfPlayers];
    RegisterPlayers(NumberOfPlayers, &jog[0]);
    MoneyInitialize(NumberOfPlayers, &jog[0]);
    SystemClear();

    PrintScreen(NumberOfPlayers, &jog[0], &prop[0]);

    while(1){
        printf(ANSI_COLOR_BLACK "-- MENU MONOPOLY --\n\n");
        printf(" [1] RECEBER\n [2] PAGAMENTO\n [3] TRANSFERÊNCIA\n [4] COMPRAR PROPRIEDADE\n [5] VENDER PROPRIEDADE\n [6] ALUGUÉIS\n-> ");
        scanf("%d", &Options);
        cin.ignore();

        if(Options > 0 && Options < 4){
            SystemClear();
            Preview(Options,NumberOfPlayers, &jog[0]);
        }
        else if(Options > 3 && Options < 6){
            SystemClear();
            SecondPreview(Options,NumberOfPlayers,&jog[0],&prop[0]);
        }
        else if(Options == 6){
            SystemClear();
            int option;
            printf("--- MENU RENTS ---\n");
            printf("[1] PAY \n[2] ENLARGE\n");
            scanf("%d", &option);
            cin.ignore();
            SystemClear();
            ThirdPreview(option, NumberOfPlayers, &jog[0], &prop[0], &rent[0]);
        }

        PrintScreen(NumberOfPlayers, &jog[0], &prop[0]);
    }




    return 0;
}