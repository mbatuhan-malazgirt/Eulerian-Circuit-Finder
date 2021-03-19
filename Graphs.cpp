#include "Graphs.h"

Graphs::Graphs(int number_of_vertices)
{
	this->number_of_vertices = number_of_vertices;
	this->index_of_current_vertice = 0;
	this->is_eulerian = -1;
	this->outputFile;
	this->starting_index = 0;
	this->total_edges = 0;
	this->graph = new queue <int>[number_of_vertices];
	vector <int> out_degree();
	vector <int> eulerian();
}

Graphs::~Graphs()
{
	delete[] graph;
}

void Graphs::addEdge(int u, int v)
{
	graph[u].push(v);
	eulerian[u]++;
	eulerian[v]--;
	this->total_edges++;
	
}

void Graphs::start_degrees()
{
	for (int i = 0; i < this->number_of_vertices; i++)
	{
		out_degree.push_back(0);
		eulerian.push_back(0);
	}
}

bool Graphs::is_Eulerian()
{
	for (int i = 0; i < this->eulerian.size(); i++)
	{
		if (eulerian[i] != 0)
		{
			return false;
		}
	}
	return true;
}

int Graphs::getFirstNonUsedEdge(int v)
{
	int ret = graph[v].front();
	graph[v].pop();
	return ret;
}

void Graphs::merge(list <int>  & a, vector <int> & b)
{
    int replace_id =this->index_of_current_vertice;
    list <int>::iterator it;
    it = a.begin();
    advance(it, replace_id);
    a.erase(it);
    it = a.begin();
    advance(it, replace_id);
    for (int i = 0; i < b.size(); i++)
    {
        a.insert(it, b[i]);
    }
}

int Graphs::findFirstVertexinTheCircuitWithAnUnusedEdge(list <int>&  a)
{
    int i = 0 ;
	for (list<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		if (this->out_degree[*it] != 0)
		{
			this->index_of_current_vertice = i;
			return *it;
		}
		i++;
	}
	return -1;
}

list <int> Graphs::hierholzer()
{
	list <int> eulerianCircuit;
	
	if (!this->is_Eulerian())
	{
		this->outputFile << "no path";
		return eulerianCircuit;
	}
	vector<int> tour;
	eulerianCircuit.push_back(this->starting_index);
	
	int v = *eulerianCircuit.begin();
	
	while (eulerianCircuit.size() <= total_edges)
	{	
		
		tour.clear();
		tour.push_back(v);
		while (out_degree[v]>0)
		{	
			int u = this->getFirstNonUsedEdge(v);
			out_degree[v]--;
			v = u;
			tour.push_back(v);

		}
		
		this->merge(eulerianCircuit, tour);
		v = this->findFirstVertexinTheCircuitWithAnUnusedEdge(eulerianCircuit);
	}

	for(list<int>::iterator it = eulerianCircuit.begin(); it != eulerianCircuit.end(); it++)
    {
	    this->outputFile << *it << " ";
    }
	return eulerianCircuit;
}
