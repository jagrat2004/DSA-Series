#include<iostream>
using namespace std;



bool checkPalindromeWord(string str, int i, int j){

    //base case
    if(i>j)
     return true;

    if(str[i] != str[j])
     return false;
    else{
        //recursive call
        return checkPalindromeWord(str,i+1,j-1);
    }
}

int main() {

    string name = "BookkooBa";
    cout << endl;

    bool isPalindrome = checkPalindromeWord(name, 0, name.length()-1 );

    if(isPalindrome) {
        cout << "Its a Palindrome " << endl; 
    }
    else {
        cout << "Its not a Palindrome " << endl;
    }


    return 0;
}