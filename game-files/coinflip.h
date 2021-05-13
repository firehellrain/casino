using namespace std;

void elegirMoneda(int& a, char& c, int d){

    apuesta(a, d);

    do{
        cout<<"\nCara o Cruz (c/x): ";
        cin>>c;
    }while((c!='C' && c!='c')&&(c!='x' && c!='X'));

}

int traducirMoneda(char c){

    switch(c){
        case 'c':
        case 'C': return 0; break;
        case 'x':
        case 'X': return 1; break;
    }
}

void giro(int& dinero, int apuesta, char& c){

    int giro = numeroAleatorio(2);

    switch (giro){
        case 0: cout<<"\nHa salido Cara"<<endl; break;
        case 1: cout<<"\nHa salido Cruz"<<endl; break;
    }

    if (traducirMoneda(c)==giro){
        dinero += apuesta;
        cout<<green<<"¡Has ganado!"<<white<<" Tu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else {
        dinero -= apuesta;
        cout<<red<<"¡Has perdido!"<<white<<" Tu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    }
}

void coinflip(int& dinero, int& apuesta, char& c){

    do{
        mostrarDinero(dinero);
        elegirMoneda(apuesta, c, dinero);
        giro(dinero, apuesta, c);
        do{
            cout<<"¿Seguir jugando? (S/N): ";
            cin>>c;
        }while(((c!='S' && c!='s')&&(c!='N' && c!='n')));
    }while(c!='N' && c!='n' && dinero>0);

    if(c=='S' || c=='s' && dinero<=0) {
        cout<<"No puedes seguir porque te has quedado sin dinero."<<endl;
        c = 'n';
    } else {
        cout<<"\nContinuar (S/N): ";
        cin>>c;
    }
}
