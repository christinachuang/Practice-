#include<windows.h>
#include<stdio.h>
#define BUF_SIZE 256
int main(int argc,LPTSTR argv[]){
     HANDLE hIn,hOut;
     DWORD nIn,nOut;
     CHAR Buffer[BUF_SIZE];
     if(argc!=3){
            printf("Usage:cpfile1file2\n");
            return 1;
     }
     hIn=CreateFile(argv[1],GENERIC_READ,FILE_SHARE_READ,NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
     if(hIn==INVALID_HANDLE_VALUE){
            printf("Cannotopeninputfile.Error:%x\n",GetLastError());
            return 2;
     }
     hOut=CreateFile(argv[2],GENERIC_WRITE,0,NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
     if(hOut==INVALID_HANDLE_VALUE){
            printf("Cannotopenoutputfile.Error:%x\n",GetLastError());
            return 3;
     }
     while(ReadFile(hIn,Buffer,BUF_SIZE,&nIn,NULL)&&nIn>0){
            WriteFile(hOut,Buffer,nIn,&nOut,NULL);
            if(nIn!=nOut){
                    printf("Fatalwriteerror:%x\n",GetLastError());
                    return 4;
            }
    }
    CloseHandle(hIn);
    CloseHandle(hOut);
    return 0;
    }
