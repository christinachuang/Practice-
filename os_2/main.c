#include<windows.h>
#include<stdio.h>

int main(int argc, LPTSTR argv[]){
    DWORD nin, nout;
    CHAR buffer[8192];
    if(argc!=3){
        printf("Usage:cpfile1file2\n");
        return 1;
    }
    HANDLE hin=CreateFile(argv[1],
                          GENERIC_READ,
                          FILE_SHARE_READ,
                          NULL,
                          OPEN_EXISTING,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    if(hin== INVALID_HANDLE_VALUE){
        printf("Cannotopeninputfile.Error\n");
        return 2;
    }
    HANDLE hout=CreateFile(argv[2],
                           GENERIC_WRITE,
                           0,
                           NULL,
                           CREATE_ALWAYS,
                           FILE_ATTRIBUTE_NORMAL,
                           NULL);
    if(hout== INVALID_HANDLE_VALUE){
        printf("Cannotopenoutputfile.Error\n");
        CloseHandle(hin);
        return 3;
    }
    while(ReadFile(hin, buffer, 8192, &nin, NULL)& nin>0){
        WriteFile(hout, buffer, nin, &nout, NULL);
        if(nin!=nout){
            printf("Fatalwriteerror\n");
            CloseHandle(hin);
            CloseHandle(hout);
            return 4;
        }
    }
    CloseHandle(hin);
    CloseHandle(hout);
return 0;

}
