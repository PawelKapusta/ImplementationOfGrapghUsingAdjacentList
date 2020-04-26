//
// Created by sony on 21.04.2020.
//

#ifndef ZADANIE7A_GRAPHLINKED_H
#define ZADANIE7A_GRAPHLINKED_H

#include <fstream>
#include "Vertex.h"
#include "Edge.h"

#define MAX 1000

class GraphLinked{

public:
    struct Node{
        int id;
        Node * next;
        int valueOfVertex;
        int valueOfConnectedEdge;
    };

    Node* tabOfLists[MAX]{};
    int numberOfVertexes = 0;
    int numberOfEdges = 0;

    string tabOfColors[15]={"red","cyan","grey","aquamarine","pink","green", "yellow",
                            "aquamarine4","purple","brown","white","gold","violet","tomato","blue"};
    string tabOfShapes[15]={"box"," doubleoctagon","ellipse","circle","triangle","egg","diamond","trapezium"
            ,"parallelogram","house","hexagon","octagon","doublecircle","invhouse","tripleoctagon"};


    GraphLinked(){
        for (auto  & i : tabOfLists) {
                i = nullptr;
        }
    }

    void addVertex(Vertex vertex0){

        Node * newNode = new Node();
        newNode -> valueOfVertex = vertex0.getVertexValue();
        newNode -> id = numberOfVertexes;
        newNode ->next = nullptr;
        if(vertex0.getVertexValue() == 0){
            cout << "You do not set vertex any value! " << endl;
            return;
        }
        tabOfLists[numberOfVertexes] = newNode;
        numberOfVertexes++;

    }

    void addEdge(Vertex vertex0, Vertex vertex1, Edge edge){

        int idOfVertex0 = vertex0.getId();
        int idOfVertex1 = vertex1.getId();

        if(idOfVertex0 == idOfVertex1){
            Node * theSame = new Node();
            theSame -> valueOfVertex = vertex0.getVertexValue();
            theSame -> valueOfConnectedEdge = edge.getEdgeValue();
            theSame -> id = idOfVertex0;

            Node * temp0 = tabOfLists[idOfVertex0];
            while(temp0 -> next != nullptr){
                temp0 = temp0 -> next;
            }
            temp0 -> next = theSame;
        }else {
            Node * first = new Node();
            first -> valueOfVertex = vertex0.getVertexValue();
            first -> valueOfConnectedEdge = edge.getEdgeValue();
            first -> id = idOfVertex0;

            Node * second = new Node();
            second -> valueOfVertex = vertex1.getVertexValue();
            second -> valueOfConnectedEdge = edge.getEdgeValue();
            second -> id = idOfVertex1;


            Node * temp0 = tabOfLists[idOfVertex0];
            while(temp0 -> next != nullptr){
                temp0 = temp0 -> next;
            }
            temp0 -> next = second;

            Node * temp1 = tabOfLists[idOfVertex1];
            while(temp1 -> next != nullptr){
                temp1 = temp1 -> next;
            }
            temp1 -> next = first;

        }
        numberOfEdges ++;

    }


    bool adjacent(Vertex vertex0, Vertex vertex1){

        int index0 = vertex0.getId();
        int index1 = vertex1.getId();

        Node * temp = tabOfLists[index0];
        if (tabOfLists[index0] -> next == nullptr || tabOfLists[index1] == nullptr){
            return false;
        }else{
            temp = temp -> next;
            while(temp != nullptr){
                if(temp -> id == index1){
                    return true;
                }
                temp = temp -> next;
            }
            return false;
        }
    }

    void neighbours(Vertex vertex){
        int counter = 0;
        int id = vertex.getId();
        Node * temp = tabOfLists[id];
            while(temp -> next != nullptr){
                temp = temp ->next;
                cout << counter + 1 << ". Neighbour: " << temp -> valueOfVertex
                                    << " connected with edge with value equals: " << temp -> valueOfConnectedEdge << endl;
                counter ++;

            }
    }

    void removeEdge(Vertex vertex0, Vertex vertex1){

        int idFirst = vertex0.getId();
        int idSecond = vertex1.getId();

        Node * temp = tabOfLists[idFirst];
        Node * toDelete;
        while(temp -> next != nullptr){

            if(temp -> next -> id == idSecond){
                toDelete = temp -> next;
                temp -> next = temp -> next -> next;
                delete(toDelete);
            }else{
                temp = temp -> next;
            }

        }
        Node * temp2 = tabOfLists[idSecond];
        while(temp2 -> next != nullptr){
            if(temp2 -> next -> id == idFirst){
                toDelete = temp2 -> next;
                temp2 -> next = temp2 -> next -> next;
                delete(toDelete);
            }else{
                temp2 = temp2 ->next;
            }

        }
    }

    void removeVertex(Vertex vertex){

        int idVertexToDelete = vertex.getId();

        if(idVertexToDelete == numberOfVertexes){
            Node * temp = tabOfLists[numberOfVertexes - 1];
            Node * next;
            while(temp != nullptr){
                next = temp -> next;
                delete(temp);
                temp = next;
            }
            tabOfLists[numberOfVertexes - 1] = nullptr;
        }else{

           // Node * temp = tabOfLists[idVertexToDelete];
//            Node * next;
//            while(temp != nullptr){
//                next = temp -> next;
//                delete(temp);
//                temp = next;
//            }
//            tabOfLists[idVertexToDelete] = nullptr;
            for (int i = idVertexToDelete; i < numberOfVertexes - 1; ++i) {
                tabOfLists[i] = tabOfLists[i+1];
            }
            Node * toDelete;
            for (int j = 0; j < numberOfVertexes ; ++j) {
                Node * temp = tabOfLists[j];
                while (temp -> next != nullptr){
                    if (temp -> next -> id == idVertexToDelete){
                        toDelete = temp -> next;
                        temp -> next = temp -> next -> next;
                        delete(toDelete);
                    } else if(temp -> next -> id > idVertexToDelete){
                        temp -> next -> id --;
                        temp = temp -> next;
                    } else{
                        temp = temp -> next;
                    }
                }
            }

        }
    }

    void print(){

        for (int i = 0; i < numberOfVertexes; ++i) {
            cout << "Vertex: " << i << ": ";
            Node * temp = tabOfLists[i] -> next;
            while(temp != nullptr){
                cout << temp -> valueOfVertex << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
    }
    void display(){
        ofstream zapis;
        zapis.open("/home/sony/CLionProjects/AISD2/Zadanie7A/draw_graph.dot",ios::out );
        zapis << "graph draw_graph{" << endl;

        for (int i = 0; i < numberOfVertexes; ++i) {
            zapis << "   " << tabOfLists[i] -> valueOfVertex << "[ color = " << tabOfColors[i % 15]
                  << ", shape = " << tabOfShapes[i] << ", distortion = 2, style = \" filled\", label = " << " \" "
                  << tabOfLists[i] -> valueOfVertex << "\" ];" << endl;
        }

       int tab[numberOfVertexes];

        for (int l = 0; l < numberOfVertexes; ++l) {
            Node * temp = tabOfLists[l];
            Node * temp2 = tabOfLists[l] -> next;
            while(temp2 != nullptr){
                if(isExist(temp2,tab)){
                    temp2 = temp2 -> next;
                }else{
                    zapis <<"   " << temp -> valueOfVertex  << " -- " << temp2 -> valueOfVertex
                          << "[ color = " << tabOfColors[l]
                          << ", label = \" " << temp2 -> valueOfConnectedEdge <<" \" " << " ];" << endl;
                    temp2 = temp2 -> next;
                }
            }
            tab[l] = temp -> valueOfVertex;

        }

        zapis << "}" << endl;
        zapis.flush();
        zapis.close();
    }
   bool isExist(Node * temp, const int tab[]){
        for (int i = 0; i < numberOfVertexes; ++i) {
            if(temp -> valueOfVertex == tab[i]){
                return true;
            }
        }
        return false;
    }



};



#endif //ZADANIE7A_GRAPHLINKED_H
