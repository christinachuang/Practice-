#include <iostream>
#include <string>

using namespace std;
char letter[27];
int number[27];
char let_rig[27];
int num_rig[27];
int a;
int n;
int control;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swapcha(char *a, char *b){
    char temp= *a;
    *a=*b;
    *b=temp;
}
void QuickSort(char *letter, int *number, const int left, const int right){
    int temp_cha, temp_num;
    if(left<right){
        int i=left+1, j=right, pivot=number[left];
        while(1){
            while(i<=right){
                if(number[i]>pivot){
                    break;
                }
                i=i+1;
            }
            while(j>left){
                if(number[j]<pivot){
                    break;
                }
                j=j-1;
            }
            if(i>j)
                break;
            swap(&number[i], &number[j]);
            swapcha(&letter[i], &letter[j]);
        }
        swap(&number[left], &number[j]);
        swapcha(&letter[left], &letter[j]);
        QuickSort(letter, number, left, j-1);
        QuickSort(letter, number, j+1, right);
    }
}

void QuickSortcha(char *let_rig, int *num_rig, const int left, const int right){
    int temp_cha, temp_num;
    if(left<right){
        int i=left+1, j=right, pivot=let_rig[left], aa, bb;
        while(1){
            while(i<=right){
                aa=let_rig[i];
                if(aa>pivot){
                    break;
                }
                i=i+1;
            }
            while(j>left){
                bb=let_rig[j];
                if(bb<pivot){
                    break;
                }
                j=j-1;
            }
            if(i>j)
                break;
            swap(&num_rig[i], &num_rig[j]);
            swapcha(&let_rig[i], &let_rig[j]);
        }
        swap(&num_rig[left], &num_rig[j]);
        swapcha(&let_rig[left], &let_rig[j]);
        QuickSortcha(let_rig, num_rig, left, j-1);
        QuickSortcha(let_rig, num_rig, j+1, right);
    }
}

int main()
{
    for(int j=0; j<27; j++){
        letter[j]='\0';
        number[j]=0;
        let_rig[j]='\0';
        num_rig[j]=0;
    }
    cin >> n;
    int record;
    string text[10000];
    getline(cin, text[0]);
    for(int i=0; i<n; i++){
        getline(cin, text[i]);
    }
    for(int i=0; i<n; i++){
        for(int x=0; text[i][x] ; x++){
            text[i][x]=toupper(text[i][x]);
        }
        a=0;
        while(text[i][a]!='\0'){
            if(text[i][a]<=90 && text[i][a]>=65){
            control=0;
            for(int j=0; j<27; j++){
                if(letter[0]=='\0'){
                    letter[0]=text[i][a];
                    number[0]++;
                    control=1;
                    break;
                }
                else if(letter[j]==text[i][a]){
                    number[j]++;
                    control=1;
                    break;
                }
                else if(letter[j+1]=='\0' && letter[j]!='\0' && control==0){
                    letter[j+1]=text[i][a];
                    number[j+1]++;
                    break;
                }
            }
        }
        a++;
        }
    }
    for(int k=0; k<27; k++){
        if(letter[k]=='\0' && letter[k-1]!='\0'){
            record=k-1;
        }
    }
    QuickSort(letter, number, 0, record);
    for(int b=record; b>=0; b--){
            let_rig[record-b]=letter[b];
            num_rig[record-b]=number[b];
    }
    int sta[10000];
    for(int y=0; y<10000; y++){
        sta[y]=0;
    }
    for(int y=0; y<=record; y++){
        sta[num_rig[y]]+=1;
    }
    int fron=0;
    for(int y=9999; y>=0; y--){
        if(sta[y]>1){
            QuickSortcha(let_rig, num_rig, fron, fron+sta[y]-1);
        }
        fron+=sta[y];
    }
        /* print the array */
    for(int b=0; b<=record; b++){
            if(let_rig[b]!='\0')
                cout << let_rig[b] << " " << num_rig[b] << endl;
    }
}
