using namespace std;

void tomarDecision(char& c){

    do{
        cout<<"\n¿(M)ayor, (m)enor o (I)gual?: ";
        cin>>c;
    }while((c!='M' && c!='m')&&(c!='I' && c!='i'));

}

void comprobarBeneficios(int& dinero, int a, int c1, int c2, char c, int& beneficios){

    if(c1==c2 && (c=='I' || c=='i')){
        dinero += 5*a;
        beneficios += 5*a;
        cout<<"\n¡El numero es igual, "<<green<<"has ganado cinco veces lo apostado"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if(c1<c2 && c=='M'){
        dinero += a;
        beneficios += a;
        cout<<"\n¡El numero es mayor, "<<green<<"has acertado"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if (c1>c2 && c=='m'){
        dinero += a;
        beneficios += a;
        cout<<"\n¡El numero es menor, "<<green<<"has acertado"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if(c=='M'){
        dinero -= a;
        beneficios -= a;
        cout<<"\n¡El numero es menor, "<<red<<"has perdido"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else {
        dinero -= a;
        beneficios -= a;
        cout<<"\n¡El numero es mayor, "<<red<<"has perdido"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    }

}

void mayorMenor(int& d, int& a, char& c){

    int carta1 = 1+numeroAleatorio(13), carta2, beneficios = 0;

    mostrarDinero(d);
    apuesta(a, d);
    sacarCarta(carta1);

    do{
        tomarDecision(c);
        carta2 = 1+numeroAleatorio(13);
        sacarCarta(carta2);
        comprobarBeneficios(d, a, carta1, carta2, c, beneficios);
        carta1 = carta2;
        if(d>=a){
            do{
                cout<<"¿Seguir jugando? (S/N): ";
                cin>>c;
            }while((c!='S' && c!='s')&&(c!='N' && c!='n'));
        }
        cout<<endl;
    }while((c!='N' && c!='n')&&(d>=0 && d>=a));

    if(d<a) cout<<"No puedes seguir porque la apuesta supera tu balance."<<endl;
    if(beneficios>0) cout<<"Beneficios totales: "<<green<<beneficios<<"$"<<white<<endl;
    else cout<<"Beneficios totales: "<<red<<beneficios<<"$"<<white<<endl;

    cout<<"\nContinuar (S/N): ";
    cin>>c;

}
