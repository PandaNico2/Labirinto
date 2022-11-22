#include <iostream>
#include <fstream>
#include <conio.h> //getch()
#include <windows.h> ///remover
#include <ctime>
#include <wchar.h>
#include <ctype.h>
#include <string>
using namespace std;


void bubbleSort(int arr[], int n){
    int i, j;
    bool flag;
    // Outer pass
    for(i = 0; i < n; i++)
    {
        flag = false;                                   // Set flag as false
        for(j = 0; j < n-i-1; j++)
        {
            // Compare values
            if( arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        // If no to elements are swapped then
        // array is sorted. Hence Break the loop.
        if(!flag)
        {
            break;
        }
    }
}


void menu();
struct clockt {
    string soma;
};

/// Struct do meu heroi
struct PLAYER {
    int x,y;

    void coord (int li, int co){
        x=li;
        y=co;

    }
};



struct ARQUIVO {
    char* nome;
    int x, y;
    int** m;
    int** mi;


    void tam(int li, int co){
        x=li;
        y=co;
    }


    void carrega (){
        m = new int*[x];
        for (int i=0; i<x; i++){
            m[i]=new int[y];
        }

        ifstream mapa;
        mapa.open(nome);
        char c;

        ///coloca na matriz o mapa
        for(int i=0; i<x;i++){
            for(int j=0; j<y;j++){
                    mapa>>c;
                    m[i][j]=c-48;
            }
        }
    }

};


void mostrarCursor(bool showFlag){


/// função nao utilizada
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void colorir (int cor) {


/// posição do mapa no cmd

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out, cor);
}
void posicaoxy( int column, int line )    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
    }


void mostra_mapa(ARQUIVO a, PLAYER p){
    posicaoxy(0,0);
    for (int i=p.x-5; i<p.x+5; i++){
        for (int j=p.y-5; j<p.y+5; j++){
            if(i<0 || j<0 ){
                        cout << " ";
                        }else {
                            switch(a.m[i][j]){
                            case 0: cout << " ";break;
                            case 1: cout <<char(219); break;
                            case 2: cout << char(1);break;
                            case 5: cout << char(2);break;
                            case 6: cout  <<char(26);break;
                            case 7:cout << char(23);break;
                            }
                        }
                    }cout<<endl;
        }

}

void mostra_mapa1 (ARQUIVO a, PLAYER p) {
    posicaoxy(0,16);
        for (int j=p.y-5; j<p.y+5; j++){
    for (int i=p.x-5; i<p.x+5; i++){
            if(i<0 || j<0 ){
                        cout << " ";
                        }else {
                            switch(a.m[i][j]){
                            case 0: cout << " ";break;
                            case 1: cout <<char(219); break;
                            case 2: cout << char(1);break;
                            case 5: cout << char(2);break;
                            case 6:cout << char(26);break;
                            case 7:cout << char(23);break;
                            }
                        }
                    }cout<<endl;
        }
}


void extrai(int m, string l){

    fstream arq;
    arq.open(l);
    arq<<m;
    arq.close();
}

int expor(int m, string l ){

        fstream aqr;
        aqr.open(l);
        aqr>>m;
        aqr.close();

        return m;
}


char getchnolock(){

     return _kbhit() ? _getch() : -1;
}

void trava(int m,int n ,PLAYER p){
    posicaoxy(0,0);
    p.coord(n,m);
}

int  relogio1(clock_t inicio){
    clock_t soma=33.33;
 ///   cout<<"relogio: "<<( clock() - inicio + soma ) / (double) CLOCKS_PER_SEC;
    return  soma;
}

void mover (PLAYER &p,PLAYER &p1, ARQUIVO &mapa){
    int n,m,i=0;
    clock_t inicio;
    inicio = clock();
    char tecla=getchnolock();
    if(!kbhit())
    switch (tecla){
    clock_t inicio;
    inicio = clock();
    case 'w':
        if(mapa.m[p.x-1][p.y]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x-1][p.y]=2;
            p.x=p.x-1;
        }else if(mapa.m[p.x-1][p.y]==6){
            mapa.m[p.x][p.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p.coord(n,m);

            }while(mapa.m[n][m]!=0);

            mapa.m[p.x][p.y]=2;
        }
        break;
    case 's':
         if(mapa.m[p.x+1][p.y]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x+1][p.y]=2;
            p.x=p.x+1;
        }else if(mapa.m[p.x+1][p.y]==6){
            mapa.m[p.x][p.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p.coord(n,m);

            }while(mapa.m[n][m]!=0);
            mapa.m[p.x][p.y]=2;
        }
        break;
    case 'a':
        if(mapa.m[p.x][p.y-1]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x][p.y-1]=2;
            p.y=p.y-1;
        }else if(mapa.m[p.x][p.y-1]==6){
            mapa.m[p.x][p.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p.coord(n,m);

            }while(mapa.m[n][m]!=0);
            mapa.m[p.x][p.y]=2;
        }
        break;
    case 'd':
        if(mapa.m[p.x][p.y+1]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x][p.y+1]=2;
            p.y=p.y+1;
        }else if(mapa.m[p.x][p.y+1]==6){
            mapa.m[p.x][p.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p.coord(n,m);

            }while(mapa.m[n][m]!=0);
            mapa.m[p.x][p.y]=2;
        }
        break;
    case 72:
        if(mapa.m[p1.x][p1.y-1]==0){
            mapa.m[p1.x][p1.y]=0;
            mapa.m[p1.x][p1.y-1]=5;
            p1.y=p1.y-1;
        }else if(mapa.m[p1.x][p1.y-1]==6){
            mapa.m[p1.x][p1.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p1.coord(n,m);

            }while(mapa.m[n][m]!=0);
            mapa.m[p1.x][p1.y]=5;
        }else if(mapa.m[p1.x][p1.y-1]==7){
             m=p.x;
             n=p.y;
             while(relogio1(inicio)<(float)5000){
                trava(m,n,p);
                relogio1(inicio);

             }
        }
        break;
    case 80:
         if(mapa.m[p1.x][p1.y+1]==0){
            mapa.m[p1.x][p1.y]=0;
            mapa.m[p1.x][p1.y+1]=5;
            p1.y=p1.y+1;
        }else if(mapa.m[p1.x][p1.y+1]==6){
            mapa.m[p1.x][p1.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p1.coord(n,m);

            }while(mapa.m[n][m]!=0);
            mapa.m[p1.x][p1.y]=5;
        }else if(mapa.m[p1.x][p1.y+1]==7){
            m=p.x;
             n=p.y;
             while(relogio1(inicio)<(float)5000){
                trava(m,n,p);
                relogio1(inicio);
             }
        }
        break;
    case 75:
        if(mapa.m[p1.x-1][p1.y]==0){
            mapa.m[p1.x][p1.y]=0;
            mapa.m[p1.x-1][p1.y]=5;
            p1.x=p1.x-1;
        }else if(mapa.m[p1.x-1][p1.y]==6){
            mapa.m[p1.x][p1.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p1.coord(n,m);

            }while(mapa.m[n][m]!=0);
            mapa.m[p1.x][p1.y]=5;
        }else if(mapa.m[p1.x-1][p1.y]==7){
           m=p.x;
             n=p.y;
             while(relogio1(inicio)<(float)5000){
                trava(m,n,p);
                relogio1(inicio);

             }
        }
        break;
    case 77:
        if(mapa.m[p1.x+1][p1.y]==0){
            mapa.m[p1.x][p1.y]=0;
            mapa.m[p1.x+1][p1.y]=5;
            p1.x=p1.x+1;
        }else if(mapa.m[p1.x+1][p1.y]==6){
            mapa.m[p1.x][p1.y]=0;
            do{
                 m=rand()%85;
                 n=rand()%85;
                p1.coord(n,m);

            }while(mapa.m[n][m]!=0);
            mapa.m[p1.x][p1.y]=5;
        }else if(mapa.m[p1.x+1][p1.y]==7){
            m=p.x;
             n=p.y;
             while(relogio1(inicio)<(float)5000){
                trava(m,n,p);
                relogio1(inicio);
             }
        }
        break;
    case 'u':
        int m;
        m = p.x;
        extrai(m,"x.txt");
        m = p.y;
        extrai(m,"y.txt");
        m = p1.x;
        extrai(m,"x1.txt");
        m = p1.y;
        extrai(m,"y1.txt");
        break;
    case 'j':

        system("cls");
        menu();

        break;
    }
}

///void relogio();
double relogio(clock_t inicio){
    clock_t soma=33.33;
    posicaoxy(0, 27);
    double timer=( clock() - inicio + soma ) / (double) CLOCKS_PER_SEC;
    cout<<"Timer: "<<timer;
    return ((double)( clock() - inicio + soma ));
}


int main();
int jogosalvo(){

    mostrarCursor(false);
    PLAYER p;
    int m,n;
    m = expor(m,"x.txt");
    n = expor(n,"y.txt");
    p.coord(m,n);
    PLAYER p1;
    int r,t;
    r = expor(r,"x1.txt");
    t = expor(t,"y1.txt");
    p1.coord(r,t);

    ARQUIVO mapa;
    mapa.nome="labirinto.txt";
    mapa.tam(93,90);
    mapa.carrega();


        clock_t inicio;
    inicio = clock(); // tempo inicial

    while (true){
        relogio(inicio);
        mostra_mapa(mapa, p);
        mostra_mapa1(mapa,p1);

        if(abs(p.x-p1.x)>=3||abs(p.y-p1.y)>=3){
            mover(p, p1, mapa);

    }else{
            system("cls");

            int r=(relogio(inicio));
            fstream arq;
            arq.open("ranking.txt",fstream::app);
            arq<<r<<endl;
            int conti=1;
            char  line;
            string m=" ";
            int o;
            while (arq.get(line)) {
                if(line=='\n'){
                    conti++;
                }
            }
            int* vet= new int[conti];
            int i=0;
            while(arq.get(line)){
                if(line=='\n'){
                    int num = stoi(m);
                    vet[i]=num;
                    i++;
                    m="";
                    bubbleSort(vet,conti);
                }else{
                    m+=line;
                }

            }

            /*for (int i=0; i<conti; i++){
                vet[i]=line-48;
            }*/

            /*for (int i=0; i<conti; i++){
                arq<<"time : "<<vet[i];
            }*/
            arq.close();
            int s;
            cout<<"GAME OVER"<<endl;
            cout<<"Deseja \n (2)VOLTAR AO MENU!  (1)SAIR DO JOGO"<<endl;
            cin>>s;
            if(s==2){
                system("cls");
                return main();
            }else if(s==1){
             return 0;
            }


            }

    }

}




int jogoinicial(){

    system("cls");

    cout << endl << endl << endl << endl << endl;
    cout << "\n\n\n\n\n\n\n Pause: press [n]";

    mostrarCursor(false);
    PLAYER p;
    p.coord(10,10);
    PLAYER p1;
    p1.coord(1,1);

    ARQUIVO mapa;
    mapa.nome="labirinto.txt";
    mapa.tam(93,90);
    mapa.carrega();

    clock_t inicio;
    inicio = clock(); // tempo inicial
    while (true){
        relogio(inicio);
        mostra_mapa(mapa, p);
        mostra_mapa1(mapa,p1);

        if(abs(p.x-p1.x)>=3||abs(p.y-p1.y)>=3){
            mover(p, p1, mapa);
    }else{

            system("cls");
            int r=(relogio(inicio));
            fstream arq;
            arq.open("ranking.txt",fstream::app);
            arq<<r<<endl;
            int conti=1;
            char  line;
            string m=" ";
            int o;
            while (arq.get(line)) {
                if(line=='\n'){
                    conti++;
                }
            }
            int* vet= new int[conti];
            int i=0;
            while(arq.get(line)){
                if(line=='\n'){
                    int num = stoi(m);
                    vet[i]=num;
                    i++;
                    m="";
                    bubbleSort(vet,conti);
                }else{
                    m+=line;
                }

            }
            /*for (int i=0; i<conti; i++){
                vet[i]=line-48;
            }*/

            /*for (int i=0; i<conti; i++){
                arq<<"time : "<<vet[i];
            }*/
            arq.close();
            int s;
            cout<<"GAME OVER"<<endl;
            cout<<"Deseja \n (2)VOLTAR AO MENU!  (1)SAIR DO JOGO"<<endl;
            cin>>s;
            if(s==2){
                    system("cls");
                return main();
            }else if(s==1){
             return 0;
            }


            }
    }

}


void rankin(){
  fstream arq;
  arq.open("ranking.txt");
  char line;
  while (arq.get(line)) {

        cout<<line;

   }
}




void menu (){
    ifstream pause;
        pause.open("pause.txt");
        string linha;
        if(pause.is_open()){
                while(getline(pause, linha)){
                    cout << linha << endl;
                }
        }else {
            cout << "Não foi possível carregar o Menu...";
        }
        char tec=getch();
        switch (tec){
        case 'a':

        system("cls");
    break;

        case 'b':
            system("cls");
            jogoinicial();

    break;

        case 'p':
            system("cls");
            cout << "---- FIM DE JOGO ----" << endl;
            system("pause");
            system("cls");
         main();
        break;
    }
}


int main(){

    ifstream Menu;
        Menu.open("Menu.txt");
        string linha;
        if(Menu.is_open()){
                while(getline(Menu, linha)){
                    cout << linha << endl;
                }
        }else {
            cout<< "Não foi possível carregar o Menu...";
        }
        cout<< "Select: ";
        int opcao=getch();
        switch (opcao){
        case 'v':
            Menu.close();
            system("cls");
            jogoinicial();
            break;
        case 'c' :
            Menu.close();
            system("cls");
            jogosalvo();
            break;
        case 'r':
            Menu.close();
            system("cls");
            rankin();
            system("pause");
            system("cls");
            main();
            break;

}


    return 0;
}
