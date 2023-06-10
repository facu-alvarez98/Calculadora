#include <iostream>
#include "class.h"
#include <math.h>

using namespace std;

interpolation :: interpolation(int numCoordinates, float xWanted_){

    nCantCoordinates=numCoordinates;
    xWanted=xWanted_;
};


float interpolation :: calculo(){

    float x[100],y[100];
    float yInterpolada=0;
    float p1=1;
    float p2=1;


    cout<<"x a interpolar "<<xWanted<<" /cantidad de coordenadas "<<nCantCoordinates;

    for(int i=0;i<nCantCoordinates;i++)
    {
        cout<<"\ningrese las coordenadas x"<<i<<" e y"<<i<<" separadas por el espacio\n";
        cin>>x[i]>>y[i];

    }

    for(int i=0;i<nCantCoordinates;i++)
    {
    p1=1;
    p2=1;
        for(int j=0;j<nCantCoordinates;j++)
            {
                if(i!=j)
                {
                    p1=(xWanted - x[j])*p1;
                    p2=(x[i] - x[j])*p2;

                }
            }
        yInterpolada= yInterpolada +(p1/p2)*y[i];
    }

    return yInterpolada;

};


bisection :: bisection( int funct_,float errorRate_){

    funct=funct_;
    errorRate=errorRate_;
}


float bisection :: bisectionCalculation(){

    switch(funct){
    case 1:
        {
            float aInterval=0;
            float bInterval=1;
            float m;
            float fA=0;
            float fB=0;
            float fM=0;

            float error=((bInterval-aInterval)/2)*100;

            while(errorRate<error){

                m= (aInterval+bInterval)/2;

                fA= (exp(3*aInterval))-4;

                fB= (exp(3*bInterval))-4;

                fM= (exp(3*m))-4;

                if ((fA<0 && fM>0) || (fA>0 && fM<0)){
                    bInterval=m;
                }else if((fB<0 && fM>0) || (fB>0 && fM<0)){
                    aInterval=m;
                }
                error=((bInterval-aInterval)/2)*100;

            }

            return m;
            break;
        }
    case 2:
        {
            float aInterval=-5;
            float bInterval=5;
            float m;
            float fA=0;
            float fB=0;
            float fM=0;

            float error=((bInterval-aInterval)/2)*100;

            while(errorRate<error){


                m= (aInterval+bInterval)/2;
                fA= (pow(aInterval,5))-(pow(aInterval,2))+1;
                fB= (pow(bInterval,5))-(pow(bInterval,2))+1;
                fM= (pow(m,5))-(pow(m,2))+1;

                if ((fA<0 && fM>0) || (fA>0 && fM<0)){
                    bInterval=m;
                }else if((fB<0 && fM>0) || (fB>0 && fM<0)){
                    aInterval=m;
                }
                error=((bInterval-aInterval)/2)*100;

            }

            return m;
            break;
        }
    default:
        cout<<"Numero ingresado es incorrecto, por favor elija una de las funciones antes presentadas ";
        break;

                    }





}
