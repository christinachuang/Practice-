#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "function.h"
#include <time.h>

void tryTestCase(Implement &inst)
{
    std::string op;
    clock_t t1, t2;
	int label_1, label_2, weight, degree, degreePass, numCmp, numCmpPass;
	bool isExistPath, isExistPathPass;
	std::string input;
    while(getline(std::cin, input))
    {
		std::istringstream in(input);
		while(in >> op) {
			if( op == "addEdge" )
			{
				t1 = clock();
				in >> label_1 >> label_2 >> weight;
				inst.addEdge(label_1, label_2, weight);
				t2 = clock();
				std::cout << "time:" << (t2-t1)/(double)(CLOCKS_PER_SEC) << std::endl;
			}
			else if( op == "deleteEdge" )
			{
				t1 = clock();
				in >> label_1 >> label_2;
				inst.deleteEdge(label_1, label_2);
				t2 = clock();
				std::cout << "time:" << (t2-t1)/(double)(CLOCKS_PER_SEC) << std::endl;
			}
			else if( op == "deleteVertex" )
			{
				t1 = clock();
				in >> label_1;
				inst.deleteVertex(label_1);
				t2 = clock();
				std::cout << "time:" << (t2-t1)/(double)(CLOCKS_PER_SEC) << std::endl;
			}
			else if( op == "degree" )
			{
				t1 = clock();
				in >> label_1;
				degree = inst.degree(label_1);
				std::cout << degree << std::endl;
				t2 = clock();
				std::cout << "time:" << (t2-t1)/(double)(CLOCKS_PER_SEC) << std::endl;
			}
			else if( op == "isExistPath")
			{
                t1 = clock();
				in >> label_1 >> label_2;
				isExistPath = inst.isExistPath(label_1, label_2);
				if(isExistPath) std::cout << "true" << std::endl;
				else std::cout << "false" << std::endl;
				t2 = clock();
				std::cout << "time:" << (t2-t1)/(double)(CLOCKS_PER_SEC) << std::endl;
			}
			else if(op == "number_of_component")
			{
			    t1 = clock();
				numCmp = inst.number_of_component();
				std::cout << numCmp << std::endl;
				t2 = clock();
				std::cout << "time:" << (t2-t1)/(double)(CLOCKS_PER_SEC) << std::endl;
			}
			else if(op == "deleteGraph")
			{
				inst.deleteGraph();
			}
		}
    }
}

int main(int argc, char *argv[])
{
    Implement inst;
    tryTestCase(inst);
    return 0;
}
