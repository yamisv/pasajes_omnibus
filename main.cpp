#include <libreriapasajes.h>


int main()
{

    int opc;
    do{
        menu();
        cin>>opc;

        switch (opc) {
        case 1:
            Reserva();

            break;
        case 2:
            ListadoReserva();
            break;
        case 3:
            Reintegro();
            break;
        case 4:
            PlanificacionMensual();
            break;
        case 5:
            ListadoPlanificado();
            break;
        case 0:
            cout<<"Adios \n";
            break;
        default:
            cout<<"Ha esocgido una opcion invalida \n";
            break;
        }

        system("pause");
    }while(opc!=0);








//            3.Listado de reservaciones.
//            4.Reintegrar pasaje.
//            5.Recogida de un bulto.
//            6.Planificación de los viajes.
//            7.Modificar Planificación.

    return 0;
}
