#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef GRAPHS_CPP
#define GRAPHS_CPP

class Graphs
{
public: // Graph class .h
	int starting_index;
	int number_of_vertices;
	int index_of_current_vertice;
	int is_eulerian;

	queue  <int>* graph; // graph table.
	vector <int> out_degree;
	vector <int> eulerian; // eularian checker.
	int total_edges;

	ofstream outputFile;

	Graphs(int number_of_vercite);  // graph constructor.
	~Graphs(); // graph destructor.
	void addEdge(int u, int v); // add edge
	void start_degrees(); // constructor.
	bool is_Eulerian(); // eularian checker.
	int getFirstNonUsedEdge(int v);  // getfirst non used edge.
	void merge(list <int>  & a, vector <int>  & b); // merge.
	int findFirstVertexinTheCircuitWithAnUnusedEdge(list <int>&  a); // first vertex unused.
	list<int> hierholzer(); // algorithm in order to find eularian circuit.
};
#endif