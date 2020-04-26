//
// Created by sony on 23.04.2020.
//

#ifndef ZADANIE7A_VERTEX_H
#define ZADANIE7A_VERTEX_H
#include <iostream>

using namespace std;
#define MAX 1000

int size = 0;

class Vertex  {

public:
    int valueTab[MAX] = {};
    int valueOfVertex = 0;
    int id = 0 ;

public:
    void setVertexValue(int value){

        for (int i : valueTab) {
            if (i == value) {
                cout << "Vertex with this value is already exist in this graph " << endl;
                return;
            }
        }
        id = size;
        valueOfVertex = value;
        valueTab[size] = value;
        size ++;
    }

    int getVertexValue(){
        if (valueOfVertex == 0){
            cout << "This vertex has no special value, only default equals: ";
        }
        return valueOfVertex;
    }
    int getId(){
        return id;
    }
    void setId(int value){
        id = value;
    }
};

#endif //ZADANIE7A_VERTEX_H
