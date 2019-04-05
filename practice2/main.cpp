#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        istringstream iss(str);
        int count=0;
        int ivalue;
        while(iss >> ivalue){
            count+=1;
        }
        cout << count << endl;
    }
    return 0;
}
