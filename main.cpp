#include <iostream>
#include "rbf.h"

using namespace std;



int main(){
    RBF model(5);

    cout<<model.getWeight(4)<<endl;

    model.setNeuronsNumber(2);
    cout<<model.getWeight(4)<<endl;
    return 0;
};
