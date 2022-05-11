#include <iostream>
#include "ConsoleColor.h"
#include "asciicards.h"

using namespace std;

int numeroAleatorio(int n){
    return rand()%n;
}

void sacarCarta(int car){

    int palo = 1+rand()%4;

    switch(car){
        case 1 ... 10: cout<<"\nHas sacado un "<<car; break;
        case 11:       cout<<"\nHas sacado una J"; break;
        case 12:       cout<<"\nHas sacado una Q"; break;
        case 13:       cout<<"\nHas sacado una K"; break;
    }

    switch(palo){
        case 1: cout<<" de picas"<<endl; break;
        case 2: cout<<" de treboles"<<endl; break;
        case 3: cout<<" de corazones"<<endl; break;
        case 4: cout<<" de diamantes"<<endl; break;
    }

    asciicard(car, palo);

}

void mostrarDinero(int dinero){

    system("cls");
    cout<<"Balance Actual: "<<green<<dinero<<"$"<<white<<endl;

}

void apuesta(int& a, int d){
    do{
        cout<<"Introduzca la cantidad a apostar (minimo 100): ";
        cin>>a;
    }while(a<100 || a>d);
}


