#include <iostream>

using namespace std;

float *Arr, *OutArr;
int M, OutCounter;
float MaxWeight;
float MaxCost = 0;

void enumer(float arr[], float weight, float cost, int counter)
{
    bool isAll = true;
    if((counter<M)&&(weight<MaxWeight))
    {
        for(int i=counter; i<M; i++)
        {
            if (weight+arr[i]<=MaxWeight){
                swap(arr[counter], arr[i]);
                swap(arr[counter+M], arr[i+M]);
                enumer(arr, weight+arr[counter], cost+arr[counter+M], counter+1);
                isAll = false;
            }
        }
    }
    if((weight==MaxWeight)||isAll)
    {
        if ((cost>MaxCost)&&(weight<=MaxWeight)){
            MaxCost=cost;
            OutCounter = counter;
            for(int i=0; i<counter; i++){
                OutArr[i] = arr[i];
                OutArr[i+M] = arr[i+M];
            }
        }
    }    
}


int main()
{
    do{
        cout << "Enter count of objects" << endl;
        cin >> M;
    }while(!(M>0 && M<INT64_MAX));
    Arr = new float[M*2];
    OutArr = new float[M*2];
    do{
        cout << "Enter maximal weight" << endl;
        cin >> MaxWeight;
    }while(!(MaxWeight>0 && MaxWeight<INT64_MAX));
    cout << "Enter objects's weight and cost, for example:10 2" << endl;
    for (int i=0; i<M; i++){
        do{
            cin >> Arr[i] >> Arr[i+M];
            if ((Arr[i]<0)||(Arr[i+M]<0)){
                cout << "Enter the correct number";
            }
        }while(Arr[i]<0 || Arr[i+M]<0);
    }
    enumer(Arr, 0, 0, 0);
    cout << "Maximal cost: " << MaxCost << endl;
    cout << "Objects(weight cost):" << endl;
    for (int i=0; i<OutCounter; i++){
        cout << OutArr[i] << ' ' << OutArr[i+M] << endl;
    }
    delete [] Arr;
    delete [] OutArr;
    return 0;
}