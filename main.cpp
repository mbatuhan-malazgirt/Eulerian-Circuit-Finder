#include <iostream>
#include <sstream>
#include <fstream>
#include "Graphs.h"

using namespace std;

int main(int argc, char const* argv[]) 
{
    // IO operation.
	ifstream iss;
	iss.open(argv[1]);

	int number_of_vertices, starting_vertex_id;
	iss >> number_of_vertices;
	Graphs big_graph(number_of_vertices);
	big_graph.outputFile.open(argv[2]);
	big_graph.start_degrees();

	for (int i = 0; i < number_of_vertices; i++)
	{
		int vertexID, outdegree_of_vertex, other_vertex;
		iss >> vertexID >> outdegree_of_vertex;
		big_graph.out_degree[vertexID] = outdegree_of_vertex;
		for (int j = 0; j < outdegree_of_vertex; j++)
		{
			iss >> other_vertex;
			big_graph.addEdge(vertexID, other_vertex);
		}
	}
	iss >> starting_vertex_id;
	big_graph.starting_index = starting_vertex_id;
	// IO operation ends.
    big_graph.hierholzer(); // ...algorithm...
 	return 0;
}