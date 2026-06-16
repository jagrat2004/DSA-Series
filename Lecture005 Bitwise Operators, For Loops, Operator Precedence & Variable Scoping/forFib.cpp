// #include<iostream>
// using namespace std;

// int main() {

//     int n ;
//     cin >> n;

//     int a = 0;
//     int b = 1;
//     cout<<a <<" " <<b<<" ";
//     for(int i = 1; i<=n; i++ ) {
        
//         int nextNumber = a+b;
//         cout<<nextNumber<<" ";

//         a = b;
//         b = nextNumber;
//     }
//     return 0;
// }

#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a = 0;
    int b = 1;
     cout<<a <<" " <<b<<" ";
     for(int i = 0; i < n; i++){
        int newNumber = a+b;
        cout<< newNumber<<" ";
        a = b;
        b = newNumber;
     }
     return 0;

}