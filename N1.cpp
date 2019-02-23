#include <iostream>
#include "string.h"
#include <fstream>

using namespace std;

#define symbols 20

    int arr[symbols];
    char Ex_Arr[symbols][2] = {{'b', 'B'}, {'c', 'C'}, {'d', 'D'}, {'f', 'F'}, {'g', 'G'}, {'h', 'H'}, {'j', 'J'}, {'l', 'L'}, {'k', 'K'}, {'m', 'M'}, {'n', 'N'}, {'p', 'P'}, {'q', 'Q'}, {'r', 'R'}, {'s', 'S'}, {'t', 'T'}, {'v', 'V'}, {'w', 'W'}, {'x', 'X'}, {'z', 'Z'}};

void QSort(int first, int last)
{
    if (first<last){
        int l = first;
        int r = last;
        int middle = arr[(l+r)/2];
        do{
            while(arr[l]>middle) {l++;}
            while(arr[r]<middle){r--;}
            if(l<=r){
                swap(arr[l], arr[r]);
                swap(Ex_Arr[l][0], Ex_Arr[r][0]);
                l++;
                r--;
            }
        }while(l<=r);
        QSort(first, r);
        QSort(l, last);
    }
}


int main()
{
    string s;
    string path;
    string j;
    ifstream fin;
    do{
        cout << "Choose file or console input thread(1 - file; 2 - console)" << endl;
        getline(cin, j);
        if (j=="1"){
            cout << "Enter file's path" << endl;
            do{
                getline(cin, path);
                fin.open(path);
                if (!fin.is_open()){
                    cout << "path are incorrect, please enter correct path" << endl;
                }
            }while(!fin.is_open());
            getline(fin, s);
            fin.close();
        }
        else if(j=="2"){
            cout << "Enter text" << endl;
            getline(cin, s);
        }
        else{
            cout << "Enter the correct number( 1 or 2 )" << endl;
        }
    }while(j!="1" && j!="2");
    for (int i=0; i<symbols; i++)
    {
        arr[i]=0;
    }
    for (int i=0; i<s.size(); i++)
    {
        for (int j=0; j<symbols; j++){
            if ((s[i]==Ex_Arr[j][0])||(s[i]==Ex_Arr[j][1])){
                arr[j]++;
            }
        }
    }
    QSort(0, symbols);
    for (int i=0; (i<symbols)&&(arr[i]>0); i++){
        cout << Ex_Arr[i][0] << ' ';
    }
    cout << endl;
    return 0;
}