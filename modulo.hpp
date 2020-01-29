#ifndef MODULO_HPP
#define MODULO_HPP

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

//COLORS
#define ANSI_COLOR_RED "\033[1;31m"
#define ANSI_COLOR_YELLOW "\033[33m"
#define ANSI_COLOR_GREEN "\033[1;32m"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_WRITE "\033[1;97m"
#define ANSI_COLOR_MAGENTA "\033[1;35m"
#define ANSI_COLOR_BLACK "\033[0;0m"

//INITIAL DEFINES
#define CASH 3000000 // MONEY INITIAL
#define RENT 22 // NUMBER OF PROPERTIES WITH RENTS
#define PROP 28 // NUMBER TOTAL OF PROPERTIES
#define CREDIT 1
#define DEBIT 2
#define TRANSFER 3


// PLAYER'S STRUCT
typedef struct players{
    char name[10];
    int id;
    int money;
}players;

// PROPERTIES STRUCT
typedef struct properties{
    char name[35];
    int value;
    int id;
    int rent;
    int player;
}properties;

// RENTS STRUCT
typedef struct rents{
    int ValueRent;
    char name[35];
    int OneHouse;
    int TwoHouse;
    int ThreeHouse;
    int FourHouse;
    int Hotel;
}rents;

void MoneyInitialize(int num, players *jog); // INITIALIZE MONEY IN PLAYERS;
void Preview(int op, int num, players *jog); // MENU DEBIT,CREDIT AND TRANSFER;
void SecondPreview(int op, int num, players *jog, properties *prop); // MENU BUY, SELL AND RENT;
void ThirdPreview(int option, int num, players *jog, properties *prop, rents *rent); // MENU RENTS;
void Credit(int value,players *jog); // CREDIT A VALUE IN ESPECIFIC PLAYER;
void Debit(int value,players *jog); // DEBIT A VALUE IN ESPECIFIC PLAYER;
void Transfer(int value, players *jog1, players *jog2); // TRANSFER A VALUE OF ESPECIFICS PLAYER'S;
char UppercaseLetters(char letter); // Uppercase names;
void PrintScreen(int num, players *jog, properties *prop); // PRINT PLAYERS AND MONEY ON SCREEN;
void SystemClear(); // LINUX OR WINDOWS;
void RegisterPlayers(int num, players *jog); // REGISTER'S NAME OF PLAYERS AND ASSIGN YOUR IDS;
void VerifyProperties(int i, players *jog, properties *prop); // VERIFY IF A PLAYER IS OWNER OF ONE PROPERTY;


// READ ARCHIVES
int ReadProperties(properties *prop); // READ ARCHIVE WITH PROPERTIES;
int ReadRents(rents *rent); // READ ARCHIVE WITH RENTS;

#endif