#include "Grafo.h"
#include "Grafo_matriz_adyacencia.h"
#include "Grafo_lista_adyacencia.h"
#include "Grafo_lista_aristas.h"
#include <bits/stdc++.h>

void busquedaProfundidad();
void busquedaAnchura();
void algoritmoDijkstra();
void algoritmoBellmanFord();
void algoritmoPrimm();

int main()
{
  //#Punto1
  cout<<"Busqueda en Profundidad (DFS): "<<endl;
  //busquedaProfundidad();

  //#Punto2
  cout<<"Busqueda en Anchura (BFS): "<<endl;
  //busquedaAnchura();

  //#Punto3
  cout<<"Algoritmo Dijkstra: "<<endl;
  //algoritmoDijkstra();

  //#Punto4
  cout<<"Algoritmo BellmanFord: "<<endl;
  algoritmoBellmanFord();
  
  //#Punto5
  cout<<"Algoritmo PrimmKruskal: "<<endl;
  //algoritmoPrimm();
    
  return 0;

}

void busquedaProfundidad(){
  
  Graph *grafo = new Grafo_Lista_Adyacencia();
  //#Graph  *grafo = new Grafo_Matriz_Adyacencia();
  //Graph *grafo = new Grafo_Lista_Aristas();

  Vertice *v1 = new Vertice("0");
  Vertice *v2 = new Vertice("1");
  Vertice *v3 = new Vertice("2");
  Vertice *v4 = new Vertice("3");
  Vertice *v5 = new Vertice("4");

  grafo->anadirVertice(v1);
  grafo->anadirVertice(v2);
  grafo->anadirVertice(v3);
  grafo->anadirVertice(v4);
  grafo->anadirArista(*v1,*v2, 20);
  grafo->anadirArista(*v1,*v3, 10);
  grafo->anadirArista(*v2,*v3, 30);
  grafo->anadirArista(*v3,*v4, 40);
  grafo->anadirArista(*v3,*v1, 30);
  grafo->anadirArista(*v4,*v4, 50);
  grafo->anadirArista(*v5,*v2, 40);
  grafo->anadirArista(*v5,*v3, 20);

  list<Vertice> x;
  x = grafo->DFS(*v2);
  for (std::list<Vertice>::iterator it=x.begin(); it != x.end(); ++it){
    cout << ' ' << it->contenido;
  }
}

void busquedaAnchura(){

  Graph *grafo = new Grafo_Lista_Adyacencia();
  //Graph  *grafo = new Grafo_Matriz_Adyacencia();
  //Graph *grafo = new Grafo_Lista_Aristas();

  Vertice *v1 = new Vertice("0");
  Vertice *v2 = new Vertice("1");
  Vertice *v3 = new Vertice("2");
  Vertice *v4 = new Vertice("3");

  grafo->anadirVertice(v1);
  grafo->anadirVertice(v2);
  grafo->anadirVertice(v3);
  grafo->anadirVertice(v4);
  grafo->anadirArista(*v1,*v2, 10);
  grafo->anadirArista(*v1,*v3, 20);
  grafo->anadirArista(*v2,*v3, 30);
  grafo->anadirArista(*v3,*v4, 40);
  grafo->anadirArista(*v3,*v1, 30);
  grafo->anadirArista(*v4,*v4, 50);

  map<int, int> x;
  x = grafo->BFS(*v2);
  for (std::map<int,int>::iterator it=x.begin(); it!=x.end(); ++it){
    cout<<it->first<<"   ,   "<<it->second<<endl;
  }
}

void algoritmoDijkstra(){

  Graph *grafo = new Grafo_Lista_Adyacencia();
  //#Graph  *grafo = new Grafo_Matriz_Adyacencia();
  //Graph *grafo = new Grafo_Lista_Aristas();

  Vertice *v1 = new Vertice("0");
  Vertice *v2 = new Vertice("1");
  Vertice *v3 = new Vertice("2");
  Vertice *v4 = new Vertice("3");
  
  grafo->anadirVertice(v1);
  grafo->anadirVertice(v2);
  grafo->anadirVertice(v3);
  grafo->anadirVertice(v4);
  grafo->anadirArista(*v1,*v2, 10);
  grafo->anadirArista(*v1,*v3, 20);
  grafo->anadirArista(*v2,*v3, 30);
  grafo->anadirArista(*v3,*v4, 40);
  grafo->anadirArista(*v3,*v1, 30);
  grafo->anadirArista(*v4,*v4, 50);

  map<int, int> x;
  x = grafo->Dijkstras(*v3);
  for (std::map<int,int>::iterator it=x.begin(); it!=x.end(); ++it){
    cout<<it->first<<"   ,   "<<it->second<<endl;
  }
    
}

void algoritmoBellmanFord(){

  Graph *grafo = new Grafo_Lista_Adyacencia();
  //#Graph  *grafo = new Grafo_Matriz_Adyacencia();
  //Graph *grafo = new Grafo_Lista_Aristas();
  
  Vertice *v1 = new Vertice("a");
  Vertice *v2 = new Vertice("b");
  Vertice *v3 = new Vertice("c");
  Vertice *v4 = new Vertice("d");
  Vertice *v5 = new Vertice("e");

  grafo->anadirVertice(v1);
  grafo->anadirVertice(v2);
  grafo->anadirVertice(v3);
  grafo->anadirVertice(v4);
  grafo->anadirVertice(v5);

  grafo->anadirArista(*v1,*v2, -1); //A-B
  grafo->anadirArista(*v1,*v3, 4); //A-C
  grafo->anadirArista(*v2,*v3, 3); //B-C
  grafo->anadirArista(*v2,*v4, 2); //B-D
  grafo->anadirArista(*v2,*v5, 2); //B-E
  grafo->anadirArista(*v4,*v2, 1); //D-B
  grafo->anadirArista(*v4,*v3, 5); //D-C
  grafo->anadirArista(*v5,*v4, -3); //E-D
  grafo->anadirArista(*v4,*v4, 50);
  
  map<int, long> x = grafo->BELLMAN_FORDS(*v1);
  for (std::map<int,long>::iterator it=x.begin(); it!=x.end(); ++it){
    cout<<it->first<<"  ,   "<<it->second<<endl;
  }
      
}

void algoritmoPrimm(){

  Graph *grafo = new Grafo_Lista_Adyacencia();
  //#Graph  *grafo = new Grafo_Matriz_Adyacencia();
  //Graph *grafo = new Grafo_Lista_Aristas();
  
  Vertice *v1 = new Vertice("0");
  Vertice *v2 = new Vertice("1");
  Vertice *v3 = new Vertice("2");
  Vertice *v4 = new Vertice("3");
  Vertice *v5 = new Vertice("4");
  Vertice *v6 = new Vertice("5");
  Vertice *v7 = new Vertice("6");
  Vertice *v8 = new Vertice("7");
  Vertice *v9 = new Vertice("8");

  grafo->anadirVertice(v1);
  grafo->anadirVertice(v2);
  grafo->anadirVertice(v3);
  grafo->anadirVertice(v4);
  grafo->anadirVertice(v5);
  grafo->anadirVertice(v6);
  grafo->anadirVertice(v7);
  grafo->anadirVertice(v8);
  grafo->anadirVertice(v9);

  grafo->anadirArista(*v1,*v2,4);
  grafo->anadirArista(*v1,*v8,8);
  grafo->anadirArista(*v2,*v3,8);
  grafo->anadirArista(*v2,*v8,11);
  grafo->anadirArista(*v3,*v4,7);
  grafo->anadirArista(*v3,*v9,2);
  grafo->anadirArista(*v3,*v6,4);
  grafo->anadirArista(*v4,*v5,9);
  grafo->anadirArista(*v4,*v6,14);
  grafo->anadirArista(*v5,*v6,10);
  grafo->anadirArista(*v6,*v7,2);
  grafo->anadirArista(*v7,*v8,1);
  grafo->anadirArista(*v7,*v9,6);
  grafo->anadirArista(*v8,*v9,7);
  grafo->anadirArista(*v2,*v1,4);
  grafo->anadirArista(*v8,*v1,8);
  grafo->anadirArista(*v3,*v2,8);
  grafo->anadirArista(*v8,*v2,11);
  grafo->anadirArista(*v4,*v3,7);
  grafo->anadirArista(*v9,*v3,2);
  grafo->anadirArista(*v6,*v3,4);
  grafo->anadirArista(*v5,*v4,9);
  grafo->anadirArista(*v6,*v4,14);
  grafo->anadirArista(*v6,*v5,10);
  grafo->anadirArista(*v7,*v6,2);
  grafo->anadirArista(*v8,*v7,1);
  grafo->anadirArista(*v9,*v7,6);
  grafo->anadirArista(*v9,*v8,7);

  cout<<"KRUSKAL'S "<<endl;
  cout<<"valor: "<<grafo->kruskals()<<endl;
  cout<<"PRIM'S "<<endl;
  grafo->Prim();

}