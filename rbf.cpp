#include "rbf.h"
#include <math.h>

inline double RBF::gaussiana(double center, double variance, double x){
    return pow(e,(-( ( pow((x-center),2) )/2*pow(variance,2))));
}

inline double RBF::triangulo(double center, double variance, double x){
    return 2;
}

void RBF::setNeuronsNumber(unsigned int n){
    if(n == 0){
        try{
            throw 0;
        }
        catch(int n){
            cout <<"O modelo deve ter uma quantidade maior que "<<n<<" de neuronios"<<endl;
        }
    }
    else{
        if(weights==nullptr && centers==nullptr && variances==nullptr){
            clear();
        }
        neurons = n;
        weights = new double[neurons];
        centers = new double[neurons];
        variances = new double[neurons];

        for(unsigned int i = 0; i < neurons ; i++){
            weights[i] = 0.0;
            centers[i] = 0.0;
            variances[i] = 0.0;
        }

    }
}

double RBF::getWeight(unsigned int i){
    try{
        if(i>=neurons){
            throw neurons;
        }else{
            return weights[i];
        }
    }
        catch(unsigned int n){
             cout << "O valor dos pesos do neuronio deve ter um indice menor que " << n << endl;
             return -1;
        }

}



double RBF::getCenter(unsigned int i){
    try{
        if(i>=neurons){
            throw neurons;
        }else{
            return centers[i];
        }
    }
        catch(unsigned int n){
             cout << "O valor do centro da função de ativação deve ter um indice menor que " << n << endl;
             return -1;
        }
}

double RBF::getVariance(unsigned int i){
    try{
        if(i>=neurons){
            throw neurons;
        }else{
            return variances[i];
        }
    }
        catch(unsigned int n){
             cout << "O valor da variancia da função de ativação deve ter um indice menor que " << n << endl;
             return -1;
        }
}


void RBF::clear(){
    if(weights!=nullptr && centers!=nullptr && variances!=nullptr)
        {
            delete[] weights;
            weights = nullptr;

            delete[] centers;
            centers = nullptr;

            delete[] variances;
            variances = nullptr;

            neurons = 0;
        }
}
