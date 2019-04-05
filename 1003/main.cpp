#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        istringstream iss(str);
        string value;
        int count=0;
        while(iss >> value){
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
