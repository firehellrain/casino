#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "ConsoleColor.h"

#include "auxfunc.h"
#include "blackjack.h"
#include "mayorMenor.h"
#include "coinflip.h"
#include "ruleta.h"

using namespace std;

void iniciarJuego(char& c){

    cout<<".             .        .     .     |--|--|--|--|--|--|  |===|==|   /    i"<<endl;
    cout<<"        .            ______________|__|__|__|__|__|_ |  |===|==|  *  . /=\\"<<endl;
    cout<<"__ *            .   /______________________________|-|  |===|==|       |=|  ."<<endl;
    cout<<"__|  .      .   .  //______________________________| :----------------------."<<endl;
    cout<<"__|   /|\\      _|_|//       "<<yellow<<"ooooooooooooooooooooo"<<white<<"  |-|                      |"<<endl;
    cout<<"__|  |/|\\|__   ||l|/,-------"<<yellow<<"8                   8"<<white<<" -| |   "<<blue<<"Congrugencia Bank"<<white<<"  |"<<endl;
    cout<<"__|._|/|\\|||.l |[=|/,-------"<<yellow<<"8   "<<green<<"Bienvenidos al"<<yellow<<"  8"<<white<<" -|-|    "<<blue<<"Sus 1000 euros"<<white<<"    |"<<endl;
    cout<<"__|[+|-|-||||li|[=|---------"<<yellow<<"8  "<<green<<"Casino de Mariam"<<yellow<<" 8"<<white<<" -| |    "<<blue<<"a buen recaudo"<<white<<"    |"<<endl;
    cout<<"_-----.|/| //:\\_[=|\\`-------"<<yellow<<"8                   8"<<white<<" -|-|  Pr�stamos  Seguros  |"<<endl;
    cout<<" /|  /||//8/ :  8_|\\`------ "<<yellow<<"8ooooooooooooooooooo8"<<white<<" -| | Suspensos     Viajes |"<<endl;
    cout<<"/=| //||/ |  .  | |\\\\_____________  ____  _________|-|                      |"<<endl;
    cout<<"==|//||  /   .   \\ \\\\_____________ |X|  | _________| `---==------------==---'"<<endl;
    cout<<"==| ||  /         \\ \\_____________ |X| \\| _________|     ||            ||  "<<endl;
    cout<<"==| |~ /     .     \\                                                       "<<endl;
    cout<<"LS|/  /             \\______________________________________________________"<<endl;
    cout<<endl;

    do{
        cout<<"¿Deseas entrar? (S/N): ";
        cin>>c;
    }while((c!='S' && c!='s')&&(c!='N' && c!='n'));

}

void elegirModo(char& c){

    cout<<"Los juegos de los que disponemos en el casino son: (B)lackjack, (R)uleta, (C)oinflip, (M)ayor/Menor, (S)alir"<<endl;
    do{
        cout<<"Modo de Juego: ";
        cin>>c;
    }while((((c!='C' && c!='c')&&(c!='B' && c!='b'))&&((c!='R' && c!='r')&&(c!='M' && c!='m')))&&(c!='s' && c!='S'));

}

void modoJuego(char& c, int& d, int& a, bool& t){

    switch(c){
        case 'C':
        case 'c': coinflip(d, a, c); break;
        case 'B':
        case 'b': blackjack(d, a, c); break;
        case 'R':
        case 'r': ruleta(d, a, c); break;
        case 'M':
        case 'm': mayorMenor(d, a, c); break;
        case 'S':
        case 's': t = false; break;
    }
}

int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "spanish");

    int dinero = 1000, apuesta;
    char c;
    bool terminal = true;

    iniciarJuego(c);

    if(c=='N' || c=='n') terminal = false;

    while(terminal){

        mostrarDinero(dinero);
        elegirModo(c);
        modoJuego(c, dinero, apuesta, terminal);

        if(dinero < 1 || (c=='N' || c=='n')) terminal = false;
    }

    cout<<green<<"\n�Gracias por jugar!";

    return 0;
}
