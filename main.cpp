/*  - Villasenor Rivas Alejandro Rodrigo.
    - Ingenieria en Computacion.
    - Codigo: 218414783.
    - Materia: Estructura de Datos.
    - Profesor: Ramiro Lupercio Coronel.
*/
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "validation.hpp"
#include "animation.hpp"
using namespace std;
int cont = 0, AC = 0, CA = 0, GE = 0, AT = 0;

//Prototipos de funciones
void gotoxy(int,int);
void titulo();
void menuServicios();
void idGenerator(string &,int);

//Funciones
void menuServicios(){
    system("cls");
    titulo();
    gotoxy(1,5);
    cout << "Seleccione tipo de servicio" << endl;
    cout << "1. Atencion a clientes" << endl;
    cout << "2. Caja" << endl;
    cout << "3. Gerencia" << endl;
    cout << "4. ATM" << endl;
    cout << "Opcion: ";
}
void idGenerator(string &id,int servicio){
    //Generamos ID en base al tipo de servicio y un numero aleatorio
    int opcion = servicio;
    switch(opcion){
        case 1:{id = "AC";AC++;}break;
        case 2:{id = "CA";CA++;}break;
        case 3:{id = "GE";GE++;}break;
        case 4:{id = "AT";AT++;}break;}
    srand(time(NULL));
    int num = rand() % 100;
    id += to_string(num);
}

//Cola
class General{
    private:
        int value;
        General *next;
        string id;
        string name;
        int service;
        int time;
    public:
        void encolar(General *&,General *&,string,string,int,int);
        void descolar(General *&,General *&, General *&,General *&);
        bool cola_vacia(General *);
        void imprimir(General *&);
        int get_time(General *&);
        int get_timeATM(General *&);
        int get_service(General *&);
        string get_id(General *&);
        void descolarATM(General *&,General *&);
        void turnos(string, General *&, int);
};
bool General::cola_vacia(General *frente){
    return (frente == NULL)? true : false;
}
int General::get_time(General *&frente){
    General *aux = frente;
    return aux->time;
}
int General::get_timeATM(General *&frente){
    General *aux = frente;
    //Obtenemos el timepo de espera del frente de la cola para ATM
    if(cola_vacia(frente)){
        return 0;
    }else{
        return aux->time;
    }
}
int General::get_service(General *&frente){
    General *aux = frente;
    return aux->service;
}
string General::get_id(General *&frente){
    General *aux = frente;
    return aux->id;
}
void General::encolar(General *&frente,General *&fin,string id,string name,int service,int time){
    General *nuevo_nodo = new General();
    nuevo_nodo->id = id;
    nuevo_nodo->name = name;
    nuevo_nodo->service = service;
    nuevo_nodo->time = time;
    nuevo_nodo->next = NULL;
    (cola_vacia(frente))? frente = nuevo_nodo:fin->next = nuevo_nodo;
    fin = nuevo_nodo;

}
void General::descolar(General *&frente,General *&fin,General *&frente2,General *&fin2){
    General *aux = frente;
    if(frente->service == 4){//Se rescata el servicio ATM
        encolar(frente2,fin2,frente->id,frente->name,frente->service,frente->time);
    }
    (frente == fin)? frente = fin = NULL : frente = frente->next;
    delete aux;
}
void General::descolarATM(General *&frente2,General *&fin2){
    General *aux = frente2;
    (frente2 == fin2)? frente2 = fin2 = NULL : frente2 = frente2->next;
    delete aux;
}
void General::imprimir(General *&frente){
    //Imprimimos la cola general
    General *aux = frente;
    int i = 0;
    while(aux != NULL){
        cout << "-ID: " << aux->id << endl;
        cout << "-Nombre: " << aux->name << endl;
        cout << "-Servicio: " << aux->service << endl;
        cout << "-Tiempo de espera(ms): " << aux->time << endl;
        cout << endl;
        aux = aux->next;
        i++;
    }
}
void General::turnos(string turnoAC, General *&frente,int personas){
    General *temp = frente;
    //Parte de arriba
    gotoxy(35,24);cout << (char)201<<string(42,(char)205)<<(char)187<<endl;
    //Parte de Banco GPT
    gotoxy(35,25);cout << (char)186<<"BANCO GPT"<<string(33,' ')<<(char)186<<endl;
    gotoxy(35,26);cout << (char)186<<"Turnos   "<<string(33,' ')<<(char)186<<endl;
    //Parte de turno actual y proximos turnos
    int i = 0;
    gotoxy(35,27);cout << (char)186<<"Turno actual"<<"\t"<<"    Proximos turnos "<<string(2,' ')<<(char)186<<endl;
    gotoxy(36,28);cout << turnoAC;
    if(personas > 1){
        temp = temp->next;
        while(temp != NULL){
            Sleep(100);
            gotoxy(35,28+i);cout << (char)186;gotoxy(78,28+i);cout<<(char)186<<endl;
            if(temp -> service != 4){
                cout<<"\t";gotoxy(60,28+i);cout <<"-: " << temp->id;
                cout<<"\t";gotoxy(60,29+i);cout <<"-: "<< "      ";
            }else{i--;}
            i++;
            temp = temp->next;
        }
    }else if(personas == 1){
        Sleep(200);
        cout<<"\t";gotoxy(60,28);cout <<"-: " << "No hay turnos";
        i = 1;
        gotoxy(35,28);cout << (char)186;gotoxy(78,28);cout<<(char)186<<endl;
    }
    //Parte de abajo
    gotoxy(35,28+i);cout << (char)200<<string(42,(char)205)<<(char)188<<endl;
    gotoxy(35,28+i+1);cout << ' '<<string(42,' ')<< ' '<<endl;
}

//Funcion principal
int main(){
    system("tittle Proyecto MOD2 - Banco GPT");
    system("mode con: cols=120 lines=37");
    COORD size = {120,80};//Tamaño de la consola
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(h,size);
    srand(time(NULL));
    General *frente = NULL;
    General *frente2 = NULL;
    General *fin = NULL;
    General *fin2 = NULL;
    General nodo;//General
    General nodo2;//ATM
    system("cls");
    //Variables
    string nombre,id,finish;
    int servicio;
    desactivarCursor();
    titulo();
    pantallaCarga();//Llamamos a la pantalla de carga
    system("cls");
    titulo();
    system("color 0A");
    string validinput;
    bool ban2 = false;
    do{
        system("cls");
        titulo();
        gotoxy(1,5);
        cout << "Bienvenido al Banco GPT" << endl;
        cout << "Por favor ingrese numero de clientes: ";
        cin >> validinput;
        if(validintP(&validinput)){
            cont = stoi(validinput);
            if(cont >= 1 && cont <= 20){
                ban2 = true;
            }else{
                cout << "Numero de clientes invalido" << endl;
                system("pause");
            }
        }else{
            cout << "Dato invalido" << endl;
            system("pause");
        }
    }while(!ban2);
    system("pause");
    int counter = cont;
    while(counter > 0){
        counter--;
        system("cls");
        titulo();
        system("color 0D");
        gotoxy(1,5);
        bool ban = false;
        string validinput;
        cout <<"Bienvenido al Banco GPT" << endl;
        cout <<"\nCliente " << cont - counter << " de " << cont << " en cola" << endl;
        cout <<" \nPor favor ingrese sus datos"<< endl;
        do{
            cout << "Nombre: ";
            cin >> validinput;
            if(validname(&validinput)){
                nombre = validinput;
                ban = true;
            }else{
                cout << "Nombre invalido\n" << endl;
            }
        }while(!ban);
        ban = false;
        do{
            menuServicios();
            cin >> validinput;
            if(validintP(&validinput)){
                servicio = stoi(validinput);
                if(servicio >= 1 && servicio <= 4){
                    ban = true;
                }else{
                    cout << "Opcion invalida" << endl;
                    system("pause");
                }
            }else{
                cout << "Opcion invalida" << endl;
                system("pause");
            }
        }while(!ban);
        idGenerator(id,servicio);
        int time = 500 + rand() % (1200 + 1 - 500);//Generamos el tiempo de espera por persona
        nodo.encolar(frente,fin,id,nombre,servicio,time);
    };
    gotoxy(1,32);
    system("pause");
    system("cls");
    titulo();
    gotoxy(1,5);
    system("color 0B");
    cout << "<< Registro de general de clientes >>\n" << endl;//Mostramos los registros
    nodo.imprimir(frente);
    system("pause");
    system("cls");
    //Llamamos a la pantalla de carga
    titulo();
    pantallaCarga();
    system("cls");
    //INICIO PRIMERA ANIMACION
    system("color 0C");
    titulo();
    banco();
    personas(cont,15);
    gotoxy(1,32);
    system("pause");
    int numPersonas = cont;
    int espera = 100;
    //Eliminamos un mono segun el tiempo de espera
     while(numPersonas > 0){
        titulo();
        banco();
        numPersonas--;
        Sleep(espera);
        removerPersona(numPersonas,15);
    }
    gotoxy(1,32);
    system("pause");
    system("cls");
    // INICIO DE LA SEGUNDA ANIMACION
    titulo();
    pantallaCarga();
    system("cls");
    system("color 0F");
    escena2();
    int numPersonas2 = cont - AT;
    //Mostramos como llegan a las ventanillas por grupos
    personas(AC,5);//Atencion de los clientes
    personas(CA,12);//Cajas
    personas(GE,19);//Gestiones
    Sleep(800);
    bool ban3 = false;
    while(numPersonas2 > 0){
        //Comenzamos a decolar segun el tiempo de espera y el servicio
        int tiposervicio = nodo.get_service(frente);
        string idAct;//Valores para el cuadro
        if(tiposervicio != 4){
            idAct = nodo.get_id(frente);
        }
        if((AC > 0) || (CA > 0) || (GE > 0)){nodo.turnos(idAct,frente,numPersonas2);ban3 = true;}
        switch(tiposervicio){
            case 1:{
                int tiempo = nodo.get_time(frente);
                Sleep(tiempo);
                AC--;
                removerPersona(AC,5);
            }break;
            case 2:{
                int tiempo = nodo.get_time(frente);
                Sleep(tiempo);
                CA--;
                removerPersona(CA,12);
            }break;
            case 3:{
                int tiempo = nodo.get_time(frente);
                Sleep(tiempo);
                GE--;
                removerPersona(GE,19);
            }break;
        }
        nodo.descolar(frente,fin,frente2,fin2);
        numPersonas2--;
    }
    if(ban3){
        gotoxy(35,28);cout << (char)186;gotoxy(78,28);cout<<(char)186<<endl;
        gotoxy(36,28);cout << "           ";
        cout<<"\t";gotoxy(60,28);cout << "                ";
    }
    gotoxy(1,32);
    system("pause");
    //INICIO DE LA TERCERA ANIMACION
    system("cls");
    system("color 0A");
    titulo();
    pantallaCarga();
    system("cls");
    system("color 0A");
    titulo();
    escena3();
    personas(AT,15);
    gotoxy(1,34);
    system("pause");
    while(AT > 0){
        int esperaAT = nodo2.get_timeATM(frente2);
        Sleep(esperaAT);
        AT--;
        removerPersona(AT, 15);
        nodo2.descolarATM(frente2,fin2);
    }
    //Acomodamos el cursor al final de la pantalla
    gotoxy(1,34);
    system("pause");
    system("cls");
    system("color 0E");
    titulo();
    despedida();
    gotoxy(1,32);
    system("pause>>cls");
    system("color 0F");
    fflush(stdin);
    return 0;
}
