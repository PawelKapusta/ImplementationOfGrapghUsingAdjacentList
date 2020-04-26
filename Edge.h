//
// Created by sony on 24.04.2020.
//

#ifndef ZADANIE7A_EDGE_H
#define ZADANIE7A_EDGE_H
#include <iostream>

using namespace std;
class Edge{
public:
    int edgeValue = 0;


    void setEdgeValue(int value){
        edgeValue = value;
    }
    int getEdgeValue(){
        if (edgeValue == 0){
            cout << "This edge has no value!!! " << endl;
            return -1;
        }
        return edgeValue;
    }

};
#endif //ZADANIE7A_EDGE_H
