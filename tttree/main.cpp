#include <iostream>
#include <stdlib.h>
using namespace std;
int tree[100];
string input;
char mid[100];
int num;
int place=1;
void Weight(int* arr, int a, int sum,int maxi){
    if(sum>maxi){
        maxi=sum;
    }
    if(arr[a*2]){
        sum+=arr[a*2];
        Weight(arr,2*a,sum, maxi);
    }
    if(arr[a*2+1]){
        sum+=arr[a*2+1];
        Weight(arr,a*2+1,sum, maxi);

    }
}
int main()
{
    while(cin>> input){
            int i=0;
        while(input[i]){
            int j=0;
            int con=1;
            while(input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0')
            {
                mid[j]=input[i];
                j++;
                i++;
                con=0;
            }
            num=atoi(mid);
            tree[place]=num;
            place++;
            if(con==1)
                i++;
        }
        Weight(tree, 1,tree[1], 0);
//        cout << maxi << endl;
    }
    return 0;
}
