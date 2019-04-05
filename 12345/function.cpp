#include "function.h"
#include <iostream>
#include <vector>
#define MAX_SIZE 1000
using namespace std;
int color[MAX_SIZE];
int discover[MAX_SIZE];
int finish[MAX_SIZE];
int predecessor[MAX_SIZE];
int kcg=0;
void DFSVisit(vector<Vertex> VertexArr, int vertex, int kcg);

void Implement::addEdge(const int label_1, const int label_2 , const int weight){
    int sign=0, sign_2=0;
    if(label_1==label_2)
        return;
    if (label_1<0 || label_1 > 99)
        return;
    if (label_2<0 || label_2 > 99)
        return;
    Vertex vec;
    Neighbor nei;
    int control=0;
    if(VertexArr.empty()){
        vec.label= label_1;
        VertexArr.push_back(vec);
        nei.label= label_2;
        nei.weight= weight;
        VertexArr[0].neighbors.push_back(nei);

        vec.label= label_2;
        VertexArr.push_back(vec);
        nei.label=label_1;
        nei.weight=weight;
        VertexArr[1].neighbors.push_back(nei);
    }
    else{
        int i, j;
        int one_ne=0, two_ne=0;
        int ope_1, ope_2=0;
        for(i=0; i<VertexArr.size(); i++){
            if(VertexArr[i].label== label_1){
                for(j=0; j<VertexArr.size(); j++){
                    /* label_1存在，label_2存在 */
                    if(VertexArr[j].label== label_2){
                        for(int m=0; m< VertexArr[i].neighbors.size(); m++){
                            if(VertexArr[i].neighbors[m].label==label_2){
                                one_ne=1;
                                ope_1=m;
                            }
                        }
                        for(int m=0; m< VertexArr[j].neighbors.size(); m++){
                            if(VertexArr[j].neighbors[m].label==label_1)
                                two_ne=1;
                                ope_2=m;
                        }
                        if(one_ne==1 && two_ne==1){
                            VertexArr[i].neighbors[ope_1].weight=weight;
                            VertexArr[j].neighbors[ope_2].weight=weight;
                        }
                        if(two_ne==0){
                            nei.label= label_1;
                            nei.weight=weight;
                                if(VertexArr[j].neighbors.empty()){
                                    VertexArr[j].neighbors.push_back(nei);
                                    sign_2=1;
                                }
                            for(int w=0; w<VertexArr[j].neighbors.size(); w++){
                                if(VertexArr[j].neighbors[w].label >label_1 &&sign_2==0){
                                    VertexArr[j].neighbors.insert(VertexArr[j].neighbors.begin()+w, nei);
                                    sign_2=1;
                                }
                                else if(w==VertexArr[j].neighbors.size()-1 && sign_2==0){
                                    VertexArr[j].neighbors.push_back(nei);
                                    w++;
                                    sign_2=1;
                                }
                            }
                        }
                        if(one_ne==0){
                            nei.label= label_2;
                            nei.weight= weight;
                            if(VertexArr[i].neighbors.empty()){
                                    VertexArr[i].neighbors.push_back(nei);
                                    sign=1;
                                }
                            for(int z=0; z<VertexArr[i].neighbors.size(); z++){
                                if(VertexArr[i].neighbors[z].label >label_2 &&sign==0){
                                    VertexArr[i].neighbors.insert(VertexArr[i].neighbors.begin()+z, nei);
                                    sign=1;
                                }
                                else if(z==VertexArr[i].neighbors.size()-1 && sign==0){
                                    VertexArr[i].neighbors.push_back(nei);
                                    z++;
                                    sign=1;
                                }
                            }
                        }
                        control=1;
                    }
                    /* label_1存在，label_2不存在 */
                    if(control==0 && j==VertexArr.size()-1){
                        VertexArr.push_back(label_2);
                        nei.label= label_2;
                        nei.weight= weight;
                        if(VertexArr[i].neighbors.empty()){
                                VertexArr[i].neighbors.push_back(nei);
                                sign=1;
                            }
                        for(int z=0; z<VertexArr[i].neighbors.size(); z++){
                            if(VertexArr[i].neighbors[z].label >label_2 &&sign==0){
                                VertexArr[i].neighbors.insert(VertexArr[i].neighbors.begin()+z, nei);
                                sign=1;
                            }
                            else if(z==VertexArr[i].neighbors.size()-1 && sign==0){
                                VertexArr[i].neighbors.push_back(nei);
                                z++;
                                sign=1;
                            }
                        }

                        nei.label= label_1;
                        nei.weight=weight;
                        VertexArr[j+1].neighbors.push_back(nei);
                        control=2;
                        j++;
                        i++;
                    }
                }
            }
            /* label_1 不存在 */
            if(control==0 && i==VertexArr.size()-1){
                for(j=0; j<VertexArr.size(); j++){
                    /* && label_2 存在 */
                    if(VertexArr[j].label==label_2){
                        VertexArr.push_back(label_1);
                        nei.label= label_2;
                        nei.weight= weight;
                        VertexArr[i+1].neighbors.push_back(nei);

                        nei.label=label_1;
                        nei.weight=weight;
                        if(VertexArr[j].neighbors.empty()){
                                VertexArr[j].neighbors.push_back(nei);
                                sign_2=1;
                            }
                        for(int w=0; w<VertexArr[j].neighbors.size(); w++){
                            if(VertexArr[j].neighbors[w].label >label_1 &&sign_2==0){
                                VertexArr[j].neighbors.insert(VertexArr[j].neighbors.begin()+w, nei);
                                sign_2=1;
                            }
                            else if(w==VertexArr[j].neighbors.size()-1 && sign_2==0){
                                VertexArr[j].neighbors.push_back(nei);
                                w++;
                                sign_2=1;
                            }
                        }
                        control=3;
                        j++;
                        i++;
                    }
                    /* && label_2 不存在 */
                    if(control==0 && j==VertexArr.size()-1){
                        VertexArr.push_back(label_2);
                        nei.label= label_1;
                        nei.weight= weight;
                        VertexArr[j+1].neighbors.push_back(nei);
                        j++;
                        i++;

                        VertexArr.push_back(label_1);
                        nei.label=label_2;
                        nei.weight=weight;
                        VertexArr[i+1].neighbors.push_back(nei);
                        j++;
                        i++;
                    }
                }
            }
        }
    }
    return;
}

void Implement::deleteEdge(const int label_1, const int label_2){
    int i, j;
    if(label_1==label_2)
        return;
    if(VertexArr.empty())
        return;
    for(i=0; i<VertexArr.size(); i++){
        for(j=0; j<VertexArr.size(); j++){
            /* Edge 存在 */
            if(VertexArr[i].label== label_1 && VertexArr[j].label== label_2){
                    for(int a=0; a< VertexArr[i].neighbors.size(); a++){
                            if(VertexArr[i].neighbors[a].label==label_2)
                                VertexArr[i].neighbors.erase(VertexArr[i].neighbors.begin()+a);
                    }
                    for(int a=0; a< VertexArr[j].neighbors.size(); a++){
                            if(VertexArr[j].neighbors[a].label==label_1)
                                VertexArr[j].neighbors.erase(VertexArr[j].neighbors.begin()+a);
                    }
            }
        }
    }
    return;
}

void Implement::deleteVertex(const int label){
    int i, j=0;
    int record=0, aa=0;
    if(VertexArr.empty())
        return;
    for(i=0; i<VertexArr.size(); i++){
        if(VertexArr[i].label== label){
            record=i;
            aa=1;
        }
    }
            /* 從VextexArr[i]裡依序刪除edges */
    if(aa==1){
        for(j=0; j<VertexArr[record].neighbors.size(); j++){
            for(int k=0; k<VertexArr.size(); k++){
                if(VertexArr[record].neighbors[j].label== VertexArr[k].label){
                    for(int y=0; y<VertexArr[k].neighbors.size();y++ ){
                        if(VertexArr[k].neighbors[y].label==label){
                            VertexArr[k].neighbors.erase(VertexArr[k].neighbors.begin()+y);
                            y--;
                        }
                    }
                }
            }
        }
        int r=0, len=VertexArr[record].neighbors.size();
        for(r=0;r<len;r++){
            VertexArr[record].neighbors.erase(VertexArr[record].neighbors.begin()+r);
        }
        VertexArr.erase(VertexArr.begin()+record);
    }
    return;
}

int Implement::degree(const int label){
    if(VertexArr.empty())
        return 0;
    for(int i=0; i<VertexArr.size(); i++){
        if(VertexArr[i].label==label){
            return VertexArr[i].neighbors.size();
        }
    }
    return 0;
}

bool Implement::isExistPath(const int label_1, const int label_2){
    int la_1=0, la_2=0;
    if(label_1==label_2)
        return false;
    if(VertexArr.empty())
        return false;
    for(int i=0; i<VertexArr.size(); i++){
        if(VertexArr[i].label==label_1){
            la_1=1;
        }
        if(VertexArr[i].label==label_2){
            la_2=1;
        }
        if(i==VertexArr.size()-1 && la_1==0){
            return false;
        }
        if(i==VertexArr.size()-1 && la_2==0){
            return false;
        }
    }

    for(int i=0; i<VertexArr.size(); i++){
        color[i]=0;
        discover[i]=0;
        finish[i]=0;
        predecessor[i]=-1;
    }
    int i=0;
    for(int j=0; j<VertexArr.size(); j++){
        if(color[i]==0){
            DFSVisit(VertexArr, i, kcg);
        }
        i=j;
    }
        int check_1=0, check_2=0;
        for(int i=0; i<VertexArr.size(); i++){
            if(VertexArr[i].label==label_1)
                check_1=i;
            if(VertexArr[i].label==label_2)
                check_2=i;
        }
        /*SetCollapsing*/
        int current=check_1;
        int root=0;
        for(root=current; predecessor[root]>=0; root=predecessor[root]);
        while(current!= root){
            int parent= predecessor[current];
            predecessor[current]=root;
            current=parent;
        }

        int current_2=check_2;
        root=0;
        for(root=current_2; predecessor[root]>=0; root=predecessor[root]);
        while(current_2!= root){
            int parent= predecessor[current_2];
            predecessor[current_2]=root;
            current_2=parent;
        }
        if(current==current_2)
            return true;
        else
            return false;
}

void Implement::deleteGraph(){
    if (VertexArr.empty())
        return;
    VertexArr.clear();
    return;
}

void DFSVisit(vector<Vertex> VertexArr, int vertex, int kcg){
    color[vertex]=1;
    discover[vertex]= ++kcg;
    for(int a=0; a<VertexArr.size(); a++){
        for(int c=0; c<VertexArr[a].neighbors.size(); c++){
            if(color[a]==0 && VertexArr[vertex].label== VertexArr[a].neighbors[c].label){
                predecessor[a]=vertex;
                DFSVisit(VertexArr, a, kcg);
            }
        }
    }
    color[vertex]=2;
    finish[vertex]= ++kcg;
}

int Implement::number_of_component(){
    if(VertexArr.empty())
        return 0;
    /* DFS */
    for(int i=0; i<VertexArr.size(); i++){
        color[i]=0;
        discover[i]=0;
        finish[i]=0;
        predecessor[i]=-1;
    }
    int i=0;
    for(int j=0; j<VertexArr.size(); j++){
        if(color[i]==0){
            DFSVisit(VertexArr, i, kcg);
        }
        i=j;
    }
    for(int k=0; k<VertexArr.size(); k++){
        /* SetCollapsing */
        int current=k;
        int root=0;
        for(root=current; predecessor[root]>=0; root=predecessor[root]);
        while(current!= root){
            int parent= predecessor[current];
            predecessor[current]=root;
            current=parent;
        }
 /*       for(int i=0; i<VertexArr.size(); i++){
            cout << predecessor[i] << " ";
        }
*/
    }

    int total=0;
    for(int i=0; i<VertexArr.size(); i++){
        if(predecessor[i]<0){
            total++;
        }
    }
    return total;
}
