#include<iostream>
#include<queue>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class solution{
  public:
  int tour(petrolPump p[], int n){
    int deficit = 0;
    int start = 0;
    int balance = 0;
    for(int i = 0; i<n; i++){
        balance += p[i].petrol-p[i].distance;
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    if(deficit + balance >= 0){
        return start;
    }else{
        return -1;
    }
  }
};
int main() {
    petrolPump arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n = sizeof(arr)/sizeof(arr[0]);

    solution obj;
    int startIndex = obj.tour(arr, n);

    if(startIndex != -1)
        cout << "Start at petrol pump: " << startIndex << endl;
    else
        cout << "No possible tour" << endl;

    return 0;
}