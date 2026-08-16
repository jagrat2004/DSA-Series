#include<iostream>
using namespace std;



void reverseString(string& str, int i, int j){
    cout << "call recieved for " << str << endl;

    //base case
    if(i>j)
     return;

    swap(str[i], str[j]);
    i++;
    j--;

    //recursive call
    reverseString(str,i,j);
}

int main() {

    string name = "abcdef";
    cout << endl;
    reverseString(name, 0 , name.length()-1 );
    cout << endl;
    cout << name << endl;

    return 0;
}