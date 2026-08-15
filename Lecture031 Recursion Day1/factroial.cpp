#include<iostream> 
using namespace std;

int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;

    // int smallerProblem = factorial(n-1);   
    // int biggerProblem = n * smallerProblem;

    return n * factorial(n-1);
}

int fact(int n){
    if(n==0)
      return 1;

    return n * fact(n-1);
}

int main() {

    int n;
    cin >> n;

    int ans = fact(n);

    cout << ans << endl;

    return 0;
}