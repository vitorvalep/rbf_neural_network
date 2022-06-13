#ifndef RBF_H
#define RBF_H

#include <iostream>
#include <string>

using namespace std;


class RBF{
    private:
        const double e = 2.718281828459045;
        unsigned int neurons;
        double* weights = nullptr;
        double* centers = nullptr;
        double* variances = nullptr;
        unsigned int activation_function;
        inline double gaussiana(double center, double variance, double x);
        inline double triangulo(double center, double wideness, double x);
        void clear();



    public:
        void setNeuronsNumber(unsigned int n);

        inline void setActivationFunction(unsigned int n){activation_function = n;}

        //constructor
        inline RBF(){setNeuronsNumber(1);}
        inline RBF(unsigned int n){setNeuronsNumber(n);}
        //Destructor
        inline ~RBF(){clear();}
        //fun��es de consulta
        double getWeight(unsigned int i);
        double getCenter(unsigned int i);
        double getVariance(unsigned int i);
        //
        inline void setWeight(unsigned int i, double value){weights[i] = value;}
        inline void setCenter(unsigned int i, double value){centers[i] = value;}
        inline void setVariance(unsigned int i, double value){variances[i] = value;}
        //void create();
        //void predict();
        //void train();
        //void recreate();

};

#endif
