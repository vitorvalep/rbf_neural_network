#include "rbf.h"
#include <math.h>

inline double RBF::gaussiana(double center, double variance, double x){
    return pow(e,(-( ( pow((x-center),2) )/2*pow(variance,2))));
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

void RBF::setNeuronsNumber(unsigned int number){
    if(number == 0){
        if(debugger_flag)
            cout <<"O modelo deve ter uma quantidade maior que "<<number<<" de neuronios"<<endl;      
    }
        
    else{
        if(weights==nullptr && centers==nullptr && variances==nullptr){
            clear();
        }
        neurons = number;
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

void RBF::setLearningRate(double learningRate){
    if(learningRate > 0)
        neta = learningRate;
    else{
        if(debugger_flag)
            cout<<"valor de neta deve ser maior que zero"<<endl;
    }
}

double RBF::predict(double input){
    double output = 0;
    
    for(int i = 0; i < neurons; i++){
        output += gaussiana(centers[i],variances[i],input)*weights[i];
    }
     
    return output;
 }

void RBF::train(double input, double h){
    for(int i = 0; i < neurons; i++){
        weights[i] += neta*gaussiana(centers[i],variances[i],input)*input*h;
    }
 }

inline void RBF::setDebugger(bool flag){
    debugger_flag = flag;
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
            if(debugger_flag)
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
            if(debugger_flag)
                cout << "O valor do centro da fun��o de ativa��o deve ter um indice menor que " << n << endl;
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
            if(debugger_flag)
                cout << "O valor da variancia da fun��o de ativa��o deve ter um indice menor que " << n << endl;
            return -1;
        }
}

void RBF::printWeights(){
    cout<<"[";
    for (int i = 0; i < neurons - 1; i++)
    {
        cout<<weights[i]<<", ";
    }
    cout<<weights[neurons-1]<<"]"<<endl;
}

void RBF::setWeight(unsigned int i, double value){
    if(i < neurons)
        weights[i] = value;
    else{
        if(debugger_flag)
            cout<<"indice invalido"<<endl;
    }
}

void RBF::setCenter(unsigned int i, double value){
    if(i < neurons)
        centers[i] = value;
    else{
        if(debugger_flag)
            cout<<"indice invalido"<<endl;
        }
        
}
void RBF::setVariance(unsigned int i, double value){
    if(i < neurons)
        variances[i] = value;
    else{
        if(debugger_flag)
            cout<<"indice invalido"<<endl;
    }
}

