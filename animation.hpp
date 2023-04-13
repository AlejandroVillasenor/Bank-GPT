/*  - Villasenor Rivas Alejandro Rodrigo.
    - Ingenieria en Computacion.
    - Codigo: 218414783.
    - Materia: Estructura de Datos.
    - Profesor: Ramiro Lupercio Coronel.
*/
#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;
//Prototipos de funciones
void gotoxy(int,int);
void bancoCarga();
void banco();
void ciudad(int, int);
void pantallaCarga();
void personas(int,int);
void removerPersona(int,int);
void darPaso(int,int,int,int,int);
void imprimirMonos(int,int, int);
void escena2();
void mostrarMonos(int,int);
void escena3();
void borrarMonos(int,int);
void windowInterior(int,int);
void plantita(int,int);
void despedida();
void desactivarCursor();

//Tamaño de la consola 120x80

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void desactivarCursor(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
void titulo(){//Recuadro superior muestra el titulo en un recuadro superior
    string titulo = "BANCO GPT";
    int longitud = titulo.length();//Logitud para centrar el titulo
    //Lado izquierdo y esquinas
    gotoxy(1,1);cout << (char)201;
    gotoxy(1,2);cout << (char)186;
    gotoxy(1,3);cout << (char)200;
    //Lado derecho y esquinas
    gotoxy(120-longitud,1);cout << (char)187;
    gotoxy(120-longitud,2);cout << (char)186;
    gotoxy(120-longitud,3);cout << (char)188;
    //Bordes superior e inferior
    for(int i=2; i<120-longitud; i++){
        gotoxy(i,1);cout << (char)205;
        gotoxy(i,3);cout << (char)205;
    }
    //Centramos el titulo
    gotoxy(60-(longitud/2),2);cout << titulo;
}
void pantallaCarga(){
    system("color 0E");
    bancoCarga();
    //Barra de carga
    gotoxy(50,23);cout << "Cargando...";
    gotoxy(50,20);
    for (int i=0; i<60; i++){
        gotoxy(i+21,21);cout << (char)219;
        Sleep(30);
    }
}
void despedida(){
    /*
    Lo imprimimos en el centro de la pantalla
       ___|                   _)
      |       __|  _` |   __|  |   _` |   __|
     |   |  |    (   |  (     |  (   | \__ \
   \____| _|   \__,_| \___| _| \__,_| ____/
     */
    gotoxy(35,10);cout << "       ___|                   _)"<<endl;
    gotoxy(35,11);cout << "      |       __|  _` |   __|  |   _` |   __|"<<endl;
    gotoxy(35,12);cout << "     |   |  |    (   |  (     |  (   | \\__ \\"<<endl;
    gotoxy(35,13);cout << "   \\____| _|   \\__,_| \\___| _| \\__,_| ____/"<<endl;
    gotoxy(35,15);cout << "   Gracias por usar mi programa  "<<endl;
    /*gotoxy(35,16);cout << " Villasenor Rivas Alejandro Rodrigo"<<endl;
    gotoxy(35,17);cout << "             218414783             "<<endl;*/
    gotoxy(35,19);cout << " <Presione cualquier tecla para salir>"<<endl;
}

//Banco para la pantalla de carga
void bancoCarga(){
    //Dibujo del banco en el centro de la pantalla
    //Techo
    gotoxy(48,10);cout << (char)201<<string(20,(char)205)<<(char)187<<endl;
    //Lados
    gotoxy(48,11);cout << (char)186<<string(20,' ')<<(char)186<<endl;
    gotoxy(48,12);cout << (char)186<<"      BANCO GPT     "<<(char)186<<endl;
    gotoxy(48,13);cout << (char)186<<"      *********     "<<(char)186<<endl;
    gotoxy(48,14);cout << (char)186<<string(20,' ')<<(char)186<<endl;
    //Puerta
    //Puerta arriba
    gotoxy(48,15);cout << (char)186<<string(8,' ')<<(char)201<<string(2,char(205)) <<(char)187<<string(8,' ')<<(char)186<<endl;
    //Puerta laterales
    gotoxy(48,16);cout << (char)186<<string(8,' ')<<(char)186<<string(2,' ')<<(char)186<<string(8,' ')<<(char)186<<endl;
    //Parte de abajo
    gotoxy(48,17);cout << (char)200<<string(8,char(205))<<(char)200<<string(2,char(205)) <<(char)188<<string(8,char(205))<<(char)188<<endl;
}

void banco(){//Funcion para dibujar el banco en la animacion
    //22x8
    //Techo
    gotoxy(85,10);cout << (char)201<<string(20,(char)205)<<(char)187<<endl;
    //Lados
    gotoxy(85,11);cout << (char)186<<string(20,' ')<<(char)186<<endl;
    gotoxy(85,12);cout << (char)186<<"      BANCO GPT     "<<(char)186<<endl;
    gotoxy(85,13);cout << (char)186<<"      *********     "<<(char)186<<endl;
    gotoxy(85,14);cout << (char)186<<string(20,' ')<<(char)186<<endl;
    //Puerta
    //Puerta arriba
    gotoxy(85,15);cout << (char)186<<string(8,' ')<<(char)201<<string(2,char(205)) <<(char)187<<string(8,' ')<<(char)186<<endl;
    //Puerta laterales
    gotoxy(85,16);cout << (char)186<<string(8,' ')<<(char)186<<string(2,' ')<<(char)186<<string(8,' ')<<(char)186<<endl;
    //Parte de abajo
    gotoxy(85,17);cout << (char)200<<string(8,char(205))<<(char)200<<string(2,char(205)) <<(char)188<<string(8,char(205))<<(char)188<<endl;
    gotoxy(0,18);cout << string(117,(char)223)<<endl;
    ciudad(6,6);
}

void ciudad(int x, int y){
    gotoxy(x,y);cout <<"####              ##                +              #####"<<endl;
    gotoxy(x,y+1);cout <<"                                   / \\"<<endl;
    gotoxy(x,y+2);cout <<" _____        _____     __________/ o \\/\\_________      _________"<<endl;
    gotoxy(x,y+3);cout <<"|o o o|_______|    |___|               | | # # #  |____|o o o o  | /\\"<<endl;
    gotoxy(x,y+4);cout <<"|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |//\\\\"<<endl;
    gotoxy(x,y+5);cout <<"|o o o|  * * *|: ::|. .|               | | # # #  |. . |o o o o  |\\/\\/"<<endl;
    gotoxy(x,y+6);cout <<"|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |((|))"<<endl;
    gotoxy(x,y+7);cout <<"|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |((|))"<<endl;
    gotoxy(x,y+8);cout <<"|_[]__|__[]___|_||_|__<|____________;;_|_|___/\\___|_.|_|____[]___|  |"<<endl;
}

void windowInterior(int x, int y){
    gotoxy(x,y); cout << "_____________"<<endl;
    gotoxy(x,y+1);cout << "|     |     |"<<endl;
    gotoxy(x,y+2);cout << "|_____|_____|"<<endl;
    gotoxy(x,y+3);cout << "|     |     |"<<endl;
    gotoxy(x,y+4);cout << "|_____|_____|"<<endl;
}
void plantita(int x, int y){
    gotoxy(x,y);cout << "  _";
    gotoxy(x,y+1);cout << " ( )";
    gotoxy(x,y+2);cout << "(_X_)";
    gotoxy(x,y+3);cout << "  |";
    gotoxy(x,y+4);cout << " [ ] ";

}

void personas(int num,int h){
    int ban = 0;
    int limite = 82;
    int reduce;
    if(num % 2 != 0){
        reduce = num * 3 - 1;
    }else{
        reduce = num * 3 - 2;
    }
    int x = (num * 3), t = (num * 3);
     for(int j=0;j<num;j++){
        t -= 3; x-=3;
        for(int i=0;i<limite- reduce;i++){
            if(ban == 0){
                gotoxy(i + t, h);cout << "   " << endl;
                gotoxy(i + t, h+1);cout << "   " << endl;
                gotoxy(i + t, h+2);cout << "   " << endl;
                gotoxy(i + x,h);cout<<"   o " <<endl;
                gotoxy(i + x,h+1);cout<<"  |" <<endl;
                gotoxy(i + x,h+2);cout<<"  \\\n" <<endl;
                ban = 1;
            }else{
                gotoxy(i + t, h);cout << "   " << endl;
                gotoxy(i + t, h+1);cout << "   " << endl;
                gotoxy(i + t, h+2);cout << "   " << endl;
                gotoxy(i + x,h);cout<<"   o " <<endl;
                gotoxy(i + x,h+1);cout<<"  /|\\\n" <<endl;
                gotoxy(i + x,h+2);cout<<"  / \\\n" <<endl;
                ban = 0;
            }
            Sleep(50);
        }
    }
}

void escena2(){
    //Letrero de atencion a clientes
    gotoxy(85,2);cout <<' ' <<"  ATENCION A CLIENTES  "<< ' ' <<endl;
    //Marco de atencion a clientes
    gotoxy(85,3);cout << (char)201<<string(20,(char)205)<<(char)187<<endl;
    //Relleno con cabeza de una persona en el centro
    gotoxy(85,4);cout << (char)186<<"    _       o       "<<(char)186<<endl;
    gotoxy(85,5);cout << (char)186<<" []| |_    /|\\      "<<(char)186<<endl;
    //linea de abajo
    gotoxy(85,6);cout << (char)204<<string(20,(char)205)<<(char)185<<endl;
    //Cerrar el recuadro
    gotoxy(85,7);cout << (char)200<<string(20,(char)205)<<(char)188<<endl;
    //Linea de separacion que abarca el largo de la pantalla
    gotoxy(0,8);cout << string(117,(char)223)<<endl;
    //Caja
    //Letrero de caja
    gotoxy(85,9);cout <<' ' <<"          CAJA        "<< ' ' <<endl;
    //Marco de caja
    gotoxy(85,10);cout << (char)201<<string(20,(char)205)<<(char)187<<endl;
    //Relleno con cabeza de una persona en el centro
    gotoxy(85,11);cout << (char)186<<"   o          o     "<<(char)186<<endl;
    gotoxy(85,12);cout << (char)186<<"  /|\\        /|\\    "<<(char)186<<endl;
    //linea de abajo
    gotoxy(85,13);cout << (char)204<<string(20,(char)205)<<(char)185<<endl;
    //Cerrar el recuadro
    gotoxy(85,14);cout << (char)200<<string(20,(char)205)<<(char)188<<endl;
    //Linea de separacion que abarca el largo de la pantalla
    gotoxy(0,15);cout << string(117,(char)223)<<endl;
    //Gerente
    //Letrero de gerente
    gotoxy(85,16);cout <<' ' <<"        GERENTE       "<< ' ' <<endl;
    //Marco de gerente
    gotoxy(85,17);cout << (char)201<<string(20,(char)205)<<(char)187<<endl;
    //Relleno con cabeza de una persona en el centro
    gotoxy(85,18);cout << (char)186<<"    _       o       "<<(char)186<<endl;
    gotoxy(85,19);cout << (char)186<<" []| |_    /|\\      "<<(char)186<<endl;
    //linea de abajo
    gotoxy(85,20);cout << (char)204<<string(20,(char)205)<<(char)185<<endl;
    //Cerrar el recuadro
    gotoxy(85,21);cout << (char)200<<string(20,(char)205)<<(char)188<<endl;
    //Linea de separacion que abarca el largo de la pantalla
    gotoxy(0,22);cout << string(117,(char)223)<<endl;
    //Plantitas
    plantita(29,24);
    plantita(80,24);
}

void escena3(){
    windowInterior(3,6);windowInterior(17,6);windowInterior(31,6);windowInterior(45,6);windowInterior(59,6);windowInterior(73,6);
   //LETRERO DE ATM
    gotoxy(85,11);cout <<"   ATM  "<<endl;
    //Marco de ATM
    gotoxy(85,12);cout << (char)201<<string(6,(char)205)<< (char)187<<endl;
    gotoxy(85,13);cout << (char)186<<string(1,' ')<<(char)201<<string(2,(char)205)<<(char)187<<string(1,' ')<<(char)186<<endl;
    gotoxy(85,14);cout << (char)204<<(char)205<<(char)202<<string(2,char(205))<<(char)202<<(char)205<<(char)185<<endl;
    gotoxy(85,15);cout << (char)186<<string(6,' ')<<(char)186<<endl;
    gotoxy(85,16);cout << (char)186<<string(6,' ')<<(char)186<<endl;
    //Cerramos
    gotoxy(85,17);cout << (char)200<<string(6,(char)205)<<(char)188<<endl;
    //Linea de separacion que abarca el largo de la pantalla
    gotoxy(0,18);cout << string(117,(char)223)<<endl;
    //ATM 2
    //LETRERO DE ATM
    gotoxy(94,9);cout <<"   ATM  "<<endl;
    gotoxy(94,10);cout <<"Fuera de "<<endl;
    gotoxy(94,11);cout <<"servicio"<<endl;
    //Marco de ATM
    gotoxy(94,12);cout << (char)201<<string(6,(char)205)<< (char)187<<endl;
    gotoxy(94,13);cout << (char)186<<string(1,' ')<<(char)201<<string(2,(char)205)<<(char)187<<string(1,' ')<<(char)186<<endl;
    gotoxy(94,14);cout << (char)204<<(char)205<<(char)202<<string(2,char(205))<<(char)202<<(char)205<<(char)185<<endl;
    gotoxy(94,15);cout << (char)186<<string(6,' ')<<(char)186<<endl;
    gotoxy(94,16);cout << (char)186<<string(6,' ')<<(char)186<<endl;
    //Cerramos
    gotoxy(94,17);cout << (char)200<<string(6,(char)205)<<(char)188<<endl;
}

void removerPersona(int fulanos,int h){
        int coor = h;
        int fulanosCopia = fulanos;
        //Recibimos un mono menos
        int ban = 0;
        int limite = 80; //80 es el limite maximo a donde llegaran los monos
        int inicio = limite - 3;
        int fincola = inicio;
        //Borramos el primero
        gotoxy(limite-2,h);cout<<"       ";
        gotoxy(limite-1,h+1);cout<< "      ";
        gotoxy(limite-1,h+2);cout<< "      ";
        //Dibujamos los monos
        for(int i=0; i<fulanos; i++){
            gotoxy(inicio,h);cout<<"   o ";
            gotoxy(inicio,h+1);cout<< " /|\\";
            if(ban == 0){
                gotoxy(inicio,h+2);cout<< " / \\";
                ban = 1;
            }else{
                gotoxy(inicio,h+2);cout<< " / \\";
                ban = 0;
            }
            inicio -= 3;
        }
        //Movemos el primer fulano hacia la derecha y lo eliminamos
        fincola +=1;
        Sleep(500);
        darPaso(fulanosCopia,inicio,fincola,68,coor);
        //Borramos el ultimo fulano
        gotoxy(fincola,coor);cout<<"       ";
        gotoxy(fincola,coor+1);cout<< "      ";
        gotoxy(fincola,coor+2);cout<< "      ";

}
void darPaso(int numP,int inicio, int fin, int limit, int h){
    int ban = 0;
    int limite = limit;
    for(int i = inicio; i < limite; i++){
        if(ban == 0){
            gotoxy(fin,h);cout<<"   o " <<endl;
            gotoxy(fin,h+1);cout<<"  |" <<endl;
            gotoxy(fin,h+2);cout<<"  \\\n" <<endl;
            ban = 1;
        }else{
            gotoxy(fin,h);cout<<"   o " <<endl;
            gotoxy(fin,h+1);cout<<"  /|\\\n" <<endl;
            gotoxy(fin,h+2);cout<<"  / \\\n" <<endl;
            ban = 0;
        }
        fin++;
        //Sleep de dos segundos
        Sleep(500);
    }
    //Funcion que borra los monos
    borrarMonos(numP,h);
    mostrarMonos(numP,h);
}
void borrarMonos(int numP, int h){
    int limite = 80;
    for (int i = 0; i < numP+1; i++){
        gotoxy(limite,h);cout<<"     ";
        gotoxy(limite,h+1);cout<<"     ";
        gotoxy(limite,h+2);cout<<"     ";
        limite -= 3;
    }
}

void mostrarMonos(int numP,int h){
    int ban = 0;
    int limite = 80;
    for (int i = 0; i < numP; i++){
        gotoxy(limite,h);cout<<"   o ";
        gotoxy(limite,h+1);cout<< " /|\\";
        if(ban == 0){
            gotoxy(limite,h+2);cout<< " / \\";
            ban = 1;
        }else{
            gotoxy(limite,h+2);cout<< " / \\";
            ban = 0;
        }
        limite -= 3;
    }
}
