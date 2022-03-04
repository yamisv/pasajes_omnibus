#ifndef LIBRERIAPASAJES_H
#define LIBRERIAPASAJES_H
#include <iostream>
#define MAX 1000
using namespace std;



struct Reserva{
    string destino, fecha, nombre, carnet;
};

struct Planificacion{
    int placa;
    string chofer, salida, llegada, fecha;
};


Reserva Reservado[MAX];
int cantReserva = 0;

Planificacion Listado[MAX];
int canPlanificacion=0;

string Destino[]={"La habana", "Santiago", "Granma", "Holguin", "Las Tunas"};
float DestinoP[]={50, 200, 250, 150, 70};
int cantDestino = 5;

float precio(string d){

    for (int i=0;i<cantDestino;i++) {
        if(Destino[i]==d)
            return DestinoP[i];
    }

    return 0;
}

// MENU PRINCIPAL
void menu (){
    //    system("cls");
    cout<<"AGENCIA DE ASTRO "<<endl;
    cout<<"-----------------------------------"<<endl<<endl;
    cout<<" (1) Reservar un pasaje"<<endl;
    cout<<" (2) Listado de reservaciones"<<endl;
    cout<<" (3) Reitegrar un pasaje"<<endl;
    cout<<" (4) Planificacion de los viajes"<<endl;
    cout<<" (5) Listado de viajes Planificados"<<endl;
    cout<<" (0) Salir "<<endl;
    cout<<" Escoja una opcion: ";
}


// RESERVAR UN PASAJE
void Reserva(){
    cout<<"Nombre la persona: "<<endl;
    cin>>Reservado[cantReserva].nombre;
    cout<<"Numero de carnet: "<<endl;
    cin>>Reservado[cantReserva].carnet;
    int pos;
    do{
        cout<<"Escoja un destino: \n";
        for(int i=0;i<cantDestino;i++)
            cout<<i+1<<"\t"<<Destino[i]<<endl;
        cin>>pos;
    }while(pos<=0 || pos>cantDestino);
    Reservado[cantReserva].destino=Destino[pos-1];
    cout<<"Fecha de salida: "<<endl;
    cin>>Reservado[cantReserva].fecha;
    cantReserva++;
}



// LISTADO DE RESERVACIONES
void ListadoReserva(){
    cout<<"\nPASAJES RESERVADOS: \n";
    cout<<"NOMBRES\t\t CARNET \t\t DESTINO \t\t FECHA \n";
    for (int i=0; i<cantReserva; i++){
        cout<<Reservado[i].nombre<<"\t\t\t "<<Reservado[i].carnet<<
              "\t\t "<<Reservado[i].destino<<"\t\t "<<Reservado[i].fecha<<endl;
    }
}


// REINTEGRAR UN PASAJE
void Reintegro(){
    string ci;
    int obc;
    cout<<"Introduzca el numero de carnet: "<<endl;
    cin>>ci;
    int pos;
    for(int i=0; i<cantReserva; i++){

        if (Reservado[i].carnet == ci){
            cout<<Reservado[i].nombre<<"\t\t\t "<<Reservado[i].carnet<<
                  "\t\t "<<Reservado[i].destino<<"\t\t "<<Reservado[i].fecha<<endl;
            pos =i;
        }
    }
    cout<<"ESCOJA EL PORCIENTO A DESCONTAR"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"(1) 10% de descuento "<<endl;
    cout<<"(2) 25% de descuento "<<endl;
    cout<<"(0) Salir "<<endl;
    cin>>obc;
    switch (obc) {
    case 1:
      cout<<"Se le desconto: "<< precio(Reservado[pos].destino)*0.1<<endl;
      cout<<"Se le devuelve: "<<precio(Reservado[pos].destino)-(precio(Reservado[pos].destino)*0.1)<<endl;
        break;
    case 2:
        cout<<"Se le desconto: "<<precio(Reservado[pos].destino)*0.25<<endl;
        cout<<"Se le devuelve: "<<precio(Reservado[pos].destino)-(precio(Reservado[pos].destino)*0.25)<<endl;
        break;
    case 3:
        cout<<"Adios"<<endl;
        break;
    }
}


// PLANIFICACION DE LOS VIAJES
void PlanificacionMensual(){
    cout<<"Introduzca el omnibus: "<<endl;
    cin>>Listado[cantReserva].placa;
    cout<<"Fecha: "<<endl;
    cin>>Listado[cantReserva].fecha;
    cout<<"Hora de salida: "<<endl;
    cin>>Listado[cantReserva].salida;
    cout<<"Hora de llegada: "<<endl;
    cin>>Listado[cantReserva].llegada;
    cout<<"Nombre del chofer: "<<endl;
    cin>>Listado[cantReserva].chofer;
   canPlanificacion++;
}

// LISTADO DE VIAJES PLANIFICADOS
void ListadoPlanificado(){
    cout<<"#\t OMNIBUS\t\t FECHA \t\t HORA SALIDA \t\t HORA LLEGADA \t\t CHOFER \n";
    for (int i=0; i<canPlanificacion; i++){
        cout<<i+1<<"\t"<<Listado[i].placa<<"\t\t\t "<<Listado[i].fecha<<
              "\t\t "<<Listado[i].salida<<"\t\t "<<Listado[i].llegada<<"\t\t "<<Listado[i].chofer<<endl;
    }
    cout<<"ESCOJA EL VIAJE A MODIFICAR"<<endl;
    cout<<"(0) Ir Atras"<<endl;
    cout<<"--------------------------------"<<endl;
    int pos;
    cin>>pos;
    if(pos>canPlanificacion || pos<1)
        return;

    pos-=1;



    cout<<"Introduzca la nueva placa ("<<Listado[pos].placa<<"):"<<endl;
    cin>>Listado[pos].placa;
    cout<<"Nueva Fecha ("<<Listado[pos].fecha<<"):"<<endl;
    cin>>Listado[pos].fecha;
    cout<<"Nueva Hora de salida ("<<Listado[pos].salida<<"):"<<endl;
    cin>>Listado[pos].salida;
    cout<<"Nueva Hora de llegada ("<<Listado[pos].llegada<<"):"<<endl;
    cin>>Listado[pos].llegada;
    cout<<"Nuevo nombre del chofer ("<<Listado[pos].chofer<<"):"<<endl;
    cin>>Listado[pos].chofer;
}








//            6.Planificación de los viajes.
//            7.Modificar Planificación.








#endif // LIBRERIAPASAJES_H
