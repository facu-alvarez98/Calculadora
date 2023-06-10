#include <iostream>
#include "funciones.h"
#include "class.h"

using namespace std;


int optionMain(){

    int optionMain;
    int optionBisection;
    float rest=-1;
    float error=0;
    do{

    cout<<"\t\tIngrese que metodo quiere aplicar\n\t1-Interpolacion\n\t2-Metodo biseccion\n\t0-Para finalizar programa\n\tMetodo:";
    cin>>optionMain;

    switch (optionMain)
    {

        case 1:{
                int numCoordinates;
                float xWanted;
                cout<<"Ingrese la cantidad de coordenadas: ";
                cin>>numCoordinates;
                cout<<"Ingrese valor que quiere interpolar: ";
                cin>>xWanted;

                interpolation prueba(numCoordinates,xWanted);
                rest=prueba.calculo();

                cout<<"\n\t\tResultado: "<<rest;
                break;
                }
        case 2:{

                cout<<"Funcion 1: (e^3x)+4\n\nFuncion 2: (x^5)-(x^2)+1\n\nFuncion:";
                cin>>optionBisection;
                if(optionBisection <1 || optionBisection > 2){
                    cout<<"La opcion no existe";
                    break;
                }
                cout<<"Escribir el error: ";
                cin>>error;

                bisection prueba(optionBisection,error);
                rest=prueba.bisectionCalculation();
                if(rest!=0)
                {cout<<"\n\t"<<rest;};
                break;                }
        case 0:
            cout<<"\n\n\t\t\tNos vemos :)";
            break;
        default:
            cout<<"\n\tERRO\nOpcion ingresada incorrecta, por favor elija una de las opciones antes mencionadas";
            break;


    }
    cout<<"\n\n\n";
    system("pause");
    system("cls");

    }while(optionMain!=0);


}



