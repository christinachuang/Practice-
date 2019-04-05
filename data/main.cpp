#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
    char filename[]="xxx.txt";
    fstream fp;
    fstream fp2;
    fstream fp3;
    char line[2000];
    char line2[2000];
    char line3[2000];
    char line4[2000];
    char number[111];
    char number2[111];
    char number3[111];
    char number4[111];
    float output[111];
    float output2[111];
    float output3[111];
    float output4[111];
    float val=0;
    int b=0;
    int j=0;
    int a=0;

    for(int y=0; y<2000; y++){
        line[y]='\0';
        line2[y]='\0';
        line3[y]='\0';
        line4[y]='\0';
    }
    fp.open("data.txt", ios::in);//開啟檔案
    if(!fp){//如果開啟檔案失敗，fp為0；成功，fp為非0
        cout<<"Fail to open file: "<<filename<<endl;
    }
    cout<<"File Descriptor: "<<fp<<endl;
    while(fp.getline(line, sizeof(line), '\n')){
        cout<<line<<endl;
    }
    fp.close();//關閉檔案
    b=0;
    for(int i=2; line[i] ; i++){
        j=0;
        for(int m=0; m<20; m++){
            number[m]='\n';
        }
        while(line[i]!=','&& line[i]){
            number[j]=line[i];
            j++;
            i++;
            a=i;
            cout << "I: " << i<<endl;
        }
        val=atof(number);
        cout<<val<< endl;
        output[b]=val;
        b++;
        i=a;
    }
    //DATA2
    fp2.open("data2.txt", ios::in);//開啟檔案
    if(!fp2){//如果開啟檔案失敗，fp為0；成功，fp為非0
        cout<<"Fail to open file: "<<filename<<endl;
    }
    cout<<"File Descriptor: "<<fp2<<endl;
    while(fp2.getline(line2, sizeof(line2), '\n')){
        cout<<line2<<endl;
    }
    fp2.close();//關閉檔案
    b=0;
    for(int i=2; line2[i] ; i++){
        j=0;
        cout <<"i: "<<i << endl;
        for(int m=0; m<20; m++){
            number2[m]='\n';
        }
        while(line2[i]!=','&& line2[i]){
            number2[j]=line2[i];
            j++;
            i++;
            a=i;
        }
        val=atof(number2);
        cout<<val<< endl;
        output2[b]=val;
        b++;
        i=a;
    }
//DATA3
    fp3.open("data3.txt", ios::in);//開啟檔案
    if(!fp3){//如果開啟檔案失敗，fp為0；成功，fp為非0
        cout<<"Fail to open file: "<<filename<<endl;
    }
  //  cout<<"File Descriptor: "<<fp<<endl;
    while(fp3.getline(line3, sizeof(line3), '\n')){
        cout<<line3<<endl;
    }
    fp3.close();//關閉檔案
    b=0;
    for(int i=2; line3[i] ; i++){
        j=0;
        for(int m=0; m<20; m++){
            number3[m]='\n';
        }
        while(line3[i]!=','&& line3[i]){
            number3[j]=line3[i];
            j++;
            i++;
            a=i;
        }
        val=atof(number3);
        cout<<val<< endl;
        output3[b]=val;
        b++;
        i=a;
    }
    //DATA4
    fp.open("data4.txt", ios::in);//開啟檔案
    if(!fp){//如果開啟檔案失敗，fp為0；成功，fp為非0
        cout<<"Fail to open file: "<<filename<<endl;
    }
    cout<<"File Descriptor: "<<fp<<endl;
    while(fp.getline(line4, sizeof(line4), '\n')){
        cout<<line4<<endl;
    }
    fp.close();//關閉檔案
    b=0;
    for(int i=2; line4[i] ; i++){
        j=0;
        for(int m=0; m<20; m++){
            number4[m]='\n';
        }
        while(line4[i]!=','&& line4[i]){
            number4[j]=line4[i];
            j++;
            i++;
            a=i;
        }
        val=atof(number4);
        cout<<val<< endl;
        output4[b]=val;
        b++;
        i=a;
    }
    //印出結果(從第一個開始讀，所以index要減1)
    for(int k=0; k<42; k++){
        cout<<" 1:"<<output[k]<<" 2:"<<output2[k]<<" 3:"<<output3[k]<<" 4:"<<output4[k]<<endl;
    }

    return EXIT_SUCCESS;
}
