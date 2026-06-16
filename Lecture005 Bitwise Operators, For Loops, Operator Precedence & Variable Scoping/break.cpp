#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i < 5; i++) {
        if(i == 2)
            continue;  // skip printing 2
        if(i == 4)
            break;     // stop loop at 4
        cout << i << " ";
    }
    return 0;
}
