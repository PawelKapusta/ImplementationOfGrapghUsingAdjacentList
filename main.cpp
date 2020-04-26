#include <iostream>
#include <chrono>
#include "GraphLinked.h"
#include "Vertex.h"

#define MAX 1000
int main() {

    Vertex vertex0;
    vertex0.setVertexValue(2);
    Vertex vertex1;
    vertex1.setVertexValue(45);
    Vertex vertex2;
    vertex2.setVertexValue(21);
    Vertex vertex3;
    vertex3.setVertexValue(5);
    Vertex vertex4;
    vertex4.setVertexValue(120);
    Vertex vertex5;
    vertex5.setVertexValue(65);
    Vertex vertex6;
    vertex6.setVertexValue(78);
    Vertex vertex7;
    vertex7.setVertexValue(88);
    Vertex vertex8;
    vertex8.setVertexValue(99);

    GraphLinked graphLinked;

    graphLinked.addVertex(vertex0);
    graphLinked.addVertex(vertex1);
    graphLinked.addVertex(vertex2);
    graphLinked.addVertex(vertex3);
    graphLinked.addVertex(vertex4);
    graphLinked.addVertex(vertex5);
    graphLinked.addVertex(vertex6);
    graphLinked.addVertex(vertex7);
    graphLinked.addVertex(vertex8);

    Edge edge0;
    edge0.setEdgeValue(13);
    Edge edge1;
    edge1.setEdgeValue(3);
    Edge edge2;
    edge2.setEdgeValue(5);
    Edge edge3;
    edge3.setEdgeValue(7);
    Edge edge4;
    edge4.setEdgeValue(12);
    Edge edge5;
    edge5.setEdgeValue(20);
    Edge edge6;
    edge6.setEdgeValue(30);
    Edge edge7;
    edge7.setEdgeValue(2);
    Edge edge8;
    edge8.setEdgeValue(4);
    Edge edge9;
    edge9.setEdgeValue(23);


    graphLinked.addEdge(vertex0, vertex1,edge0);
    graphLinked.addEdge(vertex0, vertex2,edge1);
    graphLinked.addEdge(vertex0, vertex4,edge2);
    graphLinked.addEdge(vertex1,vertex2,edge3);
    graphLinked.addEdge(vertex2,vertex4,edge4);
    graphLinked.addEdge(vertex2,vertex5,edge5);
    graphLinked.addEdge(vertex3,vertex4,edge6);
    graphLinked.addEdge(vertex4,vertex5,edge7);
    graphLinked.addEdge(vertex5,vertex5,edge8);

    cout << "---------------------------------" << endl;
    graphLinked.neighbours(vertex4);

    graphLinked.print();
    graphLinked.display();



    GraphLinked graph;
    Vertex tab[MAX];
    for (int i =0; i < MAX; i++) {
        Vertex newVertex;
        newVertex.setVertexValue(rand()%10000);
       tab[i] = newVertex;
    }
    srand(time(NULL));
    ofstream zapis;
    zapis.open("/home/sony/CLionProjects/AISD2/Zadanie7A/daneInsertVertex.txt",ios::out | ios::app);
    double totalTime = 0;
    if (zapis.good()) {

            auto start = chrono::high_resolution_clock::now();
            for (int i =0; i< MAX; i++) {
                graph.addVertex(tab[i]);
            }
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;
            totalTime = elapsed.count();

    }
    zapis << MAX  << " " << totalTime << endl;

    zapis.flush();
    zapis.close();

    return 0;
}
