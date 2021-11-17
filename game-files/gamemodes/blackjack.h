using namespace std;

void nuevaCarta(char& c, int& cont, int& cartasj, bool& terminal){
    
    cout<<"\nTu numero de cartas es: "<<cartasj<<endl;
    cout<<"¿Qué deseas hacer?"<<endl;

    int car = 1+numeroAleatorio(13);

    do{
        cout<<"(R)obar carta, (P)lantarse: "; cin>>c;
    }while((c!='R' && c!='r') && (c!='P' && c!='p'));

    if(c=='R' || c=='r') {
        sacarCarta(car);
        if(car>10) cartasj += 10; else cartasj += car;
        cont++;
    } else terminal = true;
}

void misCartas(int d, int& a, char& c, int& cartasj, int& cont){

    int car = 1+numeroAleatorio(13);
    bool terminal = false;

    if(car>10) cartasj += 10; else cartasj += car;

    sacarCarta(cartasj);

    cout<<"\nBalance Actual: "<<green<<d<<"$"<<white<<endl;
    apuesta(a, d);

    do nuevaCarta(c, cont, cartasj, terminal); while(cartasj<21 && !terminal);

    cout<<"\nCartas del Jugador: "<<cartasj<<endl;
}

void cartasBot(int& cartasb){

    int carta = 1+numeroAleatorio(13);

    do{
        if(carta>10) cartasb += 10; else cartasb += carta;
        carta = 1+numeroAleatorio(13);
    }while(cartasb<17);

    cout<<"Cartas de la Máquina: "<<cartasb<<endl;

}

void resultadosB(int& dinero, int a, int cartasj, int cartasb, int cont){

    if(cartasj > 21){
        dinero -= a;
        cout<<"\n¡Te has pasado de 21, "<<red<<"has perdido"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if (cartasb > 21){
        dinero += a;
        cout<<"\n¡La máquina se ha pasado de 21, "<<green<<"has ganado"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if(cartasj > cartasb && cont==2){
        dinero += 2*a;
        cout<<"\n¡Has superado a la máquina en la primera tirada, "<<green<<"has ganado el triple"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if(cartasj > cartasb){
        dinero += a;
        cout<<"\n¡Has superado a la máquina, "<<green<<"has ganado"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if(cartasj < cartasb){
        dinero -= a;
        cout<<"\n¡La máquina te ha superado, "<<red<<"has perdido"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else cout<<"\n¡La máquina te ha "<<yellow<<"empatado"<<white<<"!\nRecuperas el dinero apostado."<<endl;

}

void blackjack(int& d, int& a, char& c){

    system("cls");

    int cartasj= 0, cartasb = 0, cont = 1;

    do{
        misCartas(d, a, c, cartasj, cont);
        cartasBot(cartasb);
        resultadosB(d, a, cartasj, cartasb, cont);

        do{
            cout<<"¿Seguir jugando? (S/N): ";
            cin>>c;
        }while(((c!='S' && c!='s')&&(c!='N' && c!='n')) && d>0);
        if((c=='S' || c=='s') && d>0) {
            cartasj = 0;
            cartasb = 0;
            cont = 0;
            system("cls");
        }
    }while((c!='N' && c!='n') && d>0);

    if(c=='S' || c=='s' && d<=0) {
        cout<<"No puedes seguir porque te has quedado sin dinero."<<endl;
        c = 'n';
    } else {
        cout<<"\nContinuar (S/N): ";
        cin>>c;
    }

}
