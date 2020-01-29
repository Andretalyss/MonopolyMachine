#include "modulo.hpp"
using namespace std;

void MoneyInitialize(int num, players *jog){
    for(int i=0;i<num;i++){
        jog[i].money = CASH;
    }
}

// MENU OF DEBIT, CREDIT AND TRANSFER
void Preview(int op, int num, players *jog){
    int OneId, TwoId;
    char name[10];
    char name2[10];
    if(op==CREDIT || op==DEBIT){
        printf("Player operating: ");
        fgets(name,10,stdin);

         if(name[strlen(name)-1] == '\n')
            name[strlen(name)-1] = '\0';

        for(int i=0;i<strlen(name);i++){
            name[i] = UppercaseLetters(name[i]);
        }

    }else if(op==TRANSFER){
        printf("Payer: ");
        fgets(name, 10, stdin);

        if(name[strlen(name)-1] == '\n')
            name[strlen(name)-1] = '\0';

        for(int i=0;i<strlen(name);i++){
            name[i] = UppercaseLetters(name[i]);
        }

        printf("Receptor: ");
        fgets(name2, 10, stdin);

        if(name2[strlen(name2)-1] == '\n')
            name2[strlen(name2)-1] = '\0';

        for(int i=0;i<strlen(name2);i++){
            name2[i] = UppercaseLetters(name2[i]);
        }

        for(int i=0;i<num;i++){
            if(!strcmp(name,jog[i].name))
                OneId = jog[i].id;
            if(!strcmp(name2,jog[i].name))
                TwoId = jog[i].id;
        }

    }

    for(int i=0;i<num;i++){
        if(!strcmp(name,jog[i].name)){
            int value;
            if(op==CREDIT){
                printf("Credit value: ");
                scanf("%d", &value);
                cin.ignore();
                SystemClear();
                Credit(value, &jog[i]);
                break;
            }
            else if(op==DEBIT){
                printf("Debit value: ");
                scanf("%d", &value);
                cin.ignore();
                SystemClear();
                Debit(value, &jog[i]);
                break;
            }
            else if(op==TRANSFER){
                printf("Value of transference: ");
                scanf("%d", &value);
                cin.ignore();
                SystemClear();
                Transfer(value, &jog[OneId], &jog[TwoId]);
                break;
            }
        }
    }
} 

// MENU OF BUY PROPERTY, SELL PROPERTY;
void SecondPreview(int op, int num, players *jog, properties *prop){
    char name[10];
    int cont =0;
    printf("Player operating: ");
    fgets(name,10,stdin);
    if(name[strlen(name)-1] == '\n')
        name[strlen(name)-1] = '\0';

    for(int i=0;i<strlen(name);i++){
        name[i] = UppercaseLetters(name[i]);
    }

    for(int i=0;i<num;i++){
        if(!strcmp(name,jog[i].name)){
            char propy[35];
            printf("Property name: ");
            fgets(propy,35,stdin);
            if(propy[strlen(propy)-1] == '\n')
                propy[strlen(propy)-1] = '\0';
            
            for(int j=0;j<strlen(propy);j++){
                propy[j] = UppercaseLetters(propy[j]);
            }

            for(int j=0;j<PROP;j++){
                    if(!strcmp(propy,prop[j].name)){
                        cont++;
                        if(op == 4){
                            if(prop[j].player == 80){
                                prop[j].player = jog[i].id;
                                Debit(prop[j].value, &jog[i]);
                                SystemClear();
                                break;
                            }else{
                                puts(ANSI_COLOR_RED"This property has a owner");
                            }
                        }
                        else if(op == 5){
                            if(prop[j].player == jog[i].id){
                                prop[j].player = 80;
                                Credit(prop[j].value, &jog[i]);
                                SystemClear();
                                break;
                            }else{
                                puts(ANSI_COLOR_RED"You not owner of this property");
                            }
                        }    
                }
            
            }

            if(cont == 0){
                SystemClear();
                puts(ANSI_COLOR_RED"Property not found");
            }
            
            break;
        }
    }
}

void ThirdPreview(int option ,int num, players *jog, properties *prop, rents *rent){
    if(option == 1){
        char name[10];
        char name2[10];
        int OneId, TwoId, cont = 0, cont2 = 0;
        printf("Operating Player: ");
        fgets(name, 10, stdin);
        if(name[strlen(name)-1] == '\n')
            name[strlen(name)-1] = '\0';
        
        printf("Receptor: ");
        fgets(name2, 10, stdin);
        if(name2[strlen(name2)-1] == '\n')
            name2[strlen(name2)-1] = '\0';
        
        for(int i=0;i<strlen(name);i++){
            name[i] = UppercaseLetters(name[i]);
        }
        for(int i=0;i<strlen(name2);i++){
            name2[i] = UppercaseLetters(name2[i]);
        }

        for(int i=0;i<num;i++){
            if(!strcmp(name,jog[i].name)){
                OneId = jog[i].id;
                cont++;
                break;
            }
        }
        for(int i=0;i<num;i++){
            if(!strcmp(name2,jog[i].name)){
                TwoId = jog[i].id;
                cont++;
                break;
            }
        }

        if(cont == 2){
            char pro[35];
            printf("Property name: ");
            fgets(pro,35,stdin);
            if(pro[strlen(pro)-1] == '\n')
                pro[strlen(pro)-1] = '\0';

            for(int i=0;i<strlen(pro);i++){
                pro[i] = UppercaseLetters(pro[i]);
            }   

            for(int i=0;i<RENT;i++){
                if(!strcmp(pro,prop[i].name)){
                    cont2++;
                    SystemClear();
                    if(prop[i].player == jog[TwoId].id)
                        Transfer(prop[i].rent, &jog[OneId], &jog[TwoId]);
                    else
                        printf(ANSI_COLOR_RED "The Player %s don't has the property\n", jog[TwoId].name);
                         
                    break;

                }
            }
            SystemClear();
            if(cont2==0)
                puts(ANSI_COLOR_RED"Property not found");

        }else{
            SystemClear();
            puts(ANSI_COLOR_RED"Player not found");
        }
    }

}


void Credit(int value, players *jog){
    jog->money += value;
}

void Debit(int value, players *jog){
    if(jog->money > value){
        jog->money -= value;
    }else{
        printf(ANSI_COLOR_RED"Insuficient Money of Player: %s\n", jog->name);
    }
}

void Transfer(int value, players *jog1, players *jog2){
    if(jog1->money > value){
        jog1->money -= value;
        jog2->money += value;
    }else{
        printf(ANSI_COLOR_RED"Insuficient Money of Player: %s\n", jog1->name);
    }
}

char UppercaseLetters(char letter){
    char ret;
    ret = toupper(letter);

    return ret;
}

void VerifyProperties(int i, players *jog, properties *prop){
    int VerifyProp = 0;
    printf("Properties: ");
    for(int j=0;j<PROP;j++){
        if(jog->id == prop[j].player){
            VerifyProp++;
            printf(", %s", prop[j].name);
    }}

    if(VerifyProp == 0)
        printf("Nothing");
    
    printf(".");
}

void PrintScreen(int num, players *jog, properties *prop){
    for(int i=0;i<num;i++){
        if(i==0){
            printf( ANSI_COLOR_BLUE "\n Player 1: %s\n", jog[i].name);
            printf(" Money: $ %d\n", jog[i].money);
            VerifyProperties(i,&jog[i], &prop[0]);
            printf("\n------------------------\n\n");
        }
        if(i==1){
            printf( ANSI_COLOR_YELLOW "\n Player 2: %s\n", jog[i].name);
            printf(" Money: $ %d\n", jog[i].money);
            VerifyProperties(i,&jog[i], &prop[0]);
            printf("\n------------------------\n\n");
        }
        if(i==2){
            printf( ANSI_COLOR_BLACK "\n Player 3: %s\n", jog[i].name);
            printf(" Money: $ %d\n", jog[i].money);
            VerifyProperties(i,&jog[i], &prop[0]);
            printf("\n------------------------\n\n");
        }
        if(i==3){
            printf( ANSI_COLOR_RED "\n Player 4: %s\n", jog[i].name);
            printf(" Money: $ %d\n", jog[i].money);
            VerifyProperties(i,&jog[i], &prop[0]);
            printf("\n------------------------\n\n");
        }
        if(i==4){
            printf( ANSI_COLOR_GREEN "\n Player 5: %s\n", jog[i].name);
            printf(" Money: $ %d\n", jog[i].money);
            VerifyProperties(i,&jog[i], &prop[0]);
            printf("\n------------------------\n\n");
        }
    }
}

void SystemClear(){
    #ifdef linux
        system("tput reset");
    #elif defined WIN32
        system("cls");
    #else   
        printf("\e[H\e[2J");
        printf("Didn't identify\n");
    #endif
}

void RegisterPlayers(int num, players *jog){
    for(int i=0;i<num;i++){
        printf("Player %d: ", i+1);
        fgets(jog[i].name,10,stdin);

        if(jog[i].name[strlen(jog[i].name)-1] == '\n')
            jog[i].name[strlen(jog[i].name)-1] = '\0';
        
        jog[i].id = i;
    }
}

int ReadProperties(properties *prop){
    FILE *arq;
    arq = fopen("Archives/properties.txt", "r");
    if(!arq){
        puts("Don't open");
        return 0;
    }

    int i=0;
    while(1){
        if(feof(arq))
            break;
        
        fscanf(arq, "%d\n", &prop[i].id);
        fgets(prop[i].name,35,arq);
        if(prop[i].name[strlen(prop[i].name)-1] == '\n')
            prop[i].name[strlen(prop[i].name)-1] = '\0';
        
        fscanf(arq, "%d\n", &prop[i].value);
       
        if(prop[i].id < 23){
            fscanf(arq, "%d\n", &prop[i].rent);
        }


        fscanf(arq, "%d\n", &prop[i].player);

        i++;   
     }
     
    fclose(arq);
    return 1;
}

int ReadRents(rents *rent){
    FILE *arq;
    arq = fopen("Archives/rents.txt", "r");
    if(!arq)
        return 0;

    int i=0;
    while(1){
        if(feof(arq))
            break;

        fscanf(arq, "%d\n", &rent[i].ValueRent);
        fgets(rent[i].name,35,arq);
        if(rent[i].name[strlen(rent[i].name)-1] == '\n')
            rent[i].name[strlen(rent[i].name)-1] = '\0';

        fscanf(arq, "%d\n", &rent[i].OneHouse);
        fscanf(arq, "%d\n", &rent[i].TwoHouse);
        fscanf(arq, "%d\n", &rent[i].ThreeHouse);
        fscanf(arq, "%d\n", &rent[i].FourHouse);
        fscanf(arq, "%d\n", &rent[i].Hotel);
    
        i++;
    }

    fclose(arq);
    return 1;
}