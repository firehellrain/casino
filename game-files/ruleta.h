using namespace std;

void elegirNumero(int& n, char& c){

    do{
        cout<<"Introduzca un numero del 1 al "<<green<<"14"<<white<<": ";
        cin>>n;
    }while(n<1 && n>14);

    if(n!=14){

        do{
            cout<<"Escoja un color (R/B): ";
            cin>>c;
        }while((c!='R' && c!='r')&&(c!='B' && c!='b'));

        if(c=='r') c='R';
        else if (c=='b') c='B';
    }

}

void escogerNumero(int& n, char& colorn){

    n = 1+numeroAleatorio(14);
    cout<<"\nNumero sacado: "<<n<<endl;

    if(n!=14){
        switch(numeroAleatorio(2)){
            case 0: colorn = 'R'; cout<<"Color sacado: "<<red<<"Rojo"<<white<<endl; break;
            case 1: colorn = 'B'; cout<<"Color sacado: Blanco"<<endl; break;
        }
    } else {
        cout<<"\nNumero sacado: "<<green<<n<<white<<endl;
        colorn = 'V';
    }

}

void resultadosR(int& dinero, int a, int n, char color, int num, char colorn){

    if(n==num && colorn=='V'){
        dinero += a*5;
        cout<<"¡"<<green<<"Has acertado el 14, ganando cinco veces lo apostado"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if (n==num && colorn==color){
        dinero += a*2;
        cout<<"¡"<<green<<"Has acertado el numero y el color, ganando el doble de lo apostado"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if (n==num){
        dinero += a;
        cout<<"¡"<<green<<"Has acertado el numero"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else if (colorn==color){
        dinero += a;
        cout<<"¡"<<green<<"Has acertado el color"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    } else {
        dinero -= a;
        cout<<"¡"<<red<<"Has perdido"<<white<<"!\nTu balance actual es de "<<green<<dinero<<"$"<<white<<endl;
    }

}

void ruleta(int& d, int& a, char& c){

    int n, num;
    char color, colorn;

    do{
        mostrarDinero(d);
        apuesta(a, d);
        elegirNumero(n, color);
        escogerNumero(num, colorn);
        resultadosR(d, a, n, color, num, colorn);
        do{
            cout<<"¿Seguir jugando? (S/N): ";
            cin>>c;
        }while((c!='S' && c!='s')&&(c!='N' && c!='n'));
        if(c=='S' || c=='s') system("cls");
    }while((c!='N' && c!='n') && d>0);

    if(c=='S' || c=='s' && d<=0) {
        cout<<"No puedes seguir porque te has quedado sin dinero."<<endl;
        c = 'n';
    } else {
        cout<<"\nContinuar (S/N): ";
        cin>>c;
    }

}

