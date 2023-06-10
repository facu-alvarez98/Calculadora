#include <iostream>

using namespace std;

class interpolation{
    private:
        int nCantCoordinates;
        float xWanted;
    public:
        interpolation(int,float);
        float calculo();
};

class bisection{

    private:
        float errorRate;
        int funct;
    public:
        bisection(int,float);
        float bisectionCalculation();
};
