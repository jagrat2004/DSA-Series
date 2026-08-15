#include<iostream> 
using namespace std;

int power(int n) {

    //base case 
    if(n == 0)
        return 1;

    //recursive relation
    return 2 * power(n-1);    
}

int pow(int n){
    if(n==0)
     return 1;

    return 2*pow(n-1);
}
int main() {

    int n;
    cin >> n;

    int ans = pow(n);

    cout << ans << endl;

    return 0;
}