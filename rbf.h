#ifndef RBF_H
#define RBF_H

#include <iostream>
#include <string>

using namespace std;


class RBF{
    private:
        const double e = 2.718281828459045;
        bool debugger_flag = 0;
        
        unsigned int neurons;
        double neta = 1; 
        double* weights = nullptr;
        double* centers = nullptr;
        double* variances = nullptr;
        //unsigned int activation_function;
        //metodos privados
        inline double gaussiana(double center, double variance, double x);
        void clear();



    public:
        
        //constructor
        inline RBF(){setNeuronsNumber(1);}
        inline RBF(unsigned int n){setNeuronsNumber(n);}
        //Destructor
        inline ~RBF(){clear();}
        
        //metodos principais
        void setNeuronsNumber(unsigned int number);
        void setLearningRate(double learningRate);
        double predict(double input);
        void train(double input, double h);
        inline void setDebugger(bool flag);
        

        //metodos de consulta
        double getWeight(unsigned int i);
        double getCenter(unsigned int i);
        double getVariance(unsigned int i);
        void printWeights();
        //metodos de escrita
        void setWeight(unsigned int i, double value);
        void setCenter(unsigned int i, double value);
        void setVariance(unsigned int i, double value);
};

#endif
