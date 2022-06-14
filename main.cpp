#include <iostream>
#include "rbf.h"

using namespace std;



int main(){
    RBF model(3);
    model.setCenter(0,-2);model.setVariance(0,2);
    model.setCenter(1,0); model.setVariance(1,2);
    model.setCenter(2,2); model.setVariance(2,2);
    
    
    model.printWeights();
    cout<<"valor previsto: "<<model.predict(10)<<endl;
    model.train(10,0.1);
    model.printWeights();
    cout<<"valor previsto: "<<model.predict(10)<<endl;
    return 0;
};
