#ifndef GRAPHOPS_H
#define GRAPHOPS_H

#include <string>
#include <iostream>
#include <vector>

class Neighbor{
public:
    int label;
    int weight;

    Neighbor(){};
    Neighbor(const int label)
	{
		this->label = label;
	};
    Neighbor(const int label, const int weight)
	{
		this->label = label;
		this->weight = weight;
	};
	
    ~Neighbor(){};

};

class Vertex {
public:
    //----------------------------------------------------------------------
    // label of the vertex
    //----------------------------------------------------------------------
    int label;

    //----------------------------------------------------------------------
    // record the neighbor vertex
    //----------------------------------------------------------------------
    std::vector<Neighbor> neighbors;

    Vertex(){};
    Vertex(const int label)
	{
		this->label = label;
	};
    ~Vertex(){};
};



class GraphOperations
{
public:
    //----------------------------------------------------------------------
    // a member to create an adjacencyList
    //----------------------------------------------------------------------
    std::vector<Vertex> VertexArr;

    //----------------------------------------------------------------------
    //add an edge between the A and the B with weight
	//if A or B doesn't exist in the graph, 
	//create new A or B in this graph too
    //----------------------------------------------------------------------
    virtual void addEdge(const int label_1, const int label_2 , const int weight)
	{return ;}

    //----------------------------------------------------------------------
    //delete an edge between A and B
	//if this edge doesn't exist, then do nothing
    //----------------------------------------------------------------------
    virtual void deleteEdge(const int label_1, const int label_2)
	{return ;}

    //----------------------------------------------------------------------
    //delete the vertex A and all edges that connect to A, if A doesn't exist, do nothing
    //----------------------------------------------------------------------
    virtual void deleteVertex(const int label)
	{return ;}

    //----------------------------------------------------------------------
    //return the degree of vertex A, return 0 if A doesn't exist 
    //----------------------------------------------------------------------
    virtual int degree(const int label)
	{return 0;}

    //----------------------------------------------------------------------
    //return true(bool) if there is at least one path between A & B, else return false(bool), 
	//if A or B doesn't exist in the graph, return false
    //----------------------------------------------------------------------
    virtual bool isExistPath(const int label_1, const int label_2)
	{return 0;}
	//----------------------------------------------------------------------
    //delete all vertexes and edges in the graph 
    //----------------------------------------------------------------------
    virtual void deleteGraph()
	{return ;}
	//----------------------------------------------------------------------
    //return the numbers of the component, if this graph doesn't have any vertex, then return 0
    //----------------------------------------------------------------------
    virtual int number_of_component()
	{return 0;}
};

class Implement : public GraphOperations
{
public:
    void addEdge(const int label_1, const int label_2 , const int weight);
    void deleteEdge(const int label_1, const int label_2);
    void deleteVertex(const int label);
    int degree(const int label);
    bool isExistPath(const int label_1, const int label_2);
    void deleteGraph();
	int number_of_component();
};

#endif
