#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int row = 1;
    while(row <= n) {

        int col = 1;
        while(col <= row) {
            cout<< row;
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}


#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int row = 1;

    while(row<=n) {

        int col = 1;
        int value = row;
        while(col <= row) {
            cout<<value;
            value = value + 1;
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int i = 1;
    
    while(i <= n) {

        int j = 1;
        while(j <= i) {
            cout<<(i-j+1)<<" ";
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;
    }
    return 0;
}

#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    int row = 1;
    while(row <= n) {

        int col = 1;

        while(col <= n) {
            char ch = 'A' + row - 1;
            cout<< ch;
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}


#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    int row = 1;

    while(row <= n) {

        int col = 1;

        while(col <= row) {
            char ch = ('A' + row + col - 2);
            cout<<ch;
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;

    }
    return 0;
}


#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    int row = 1;

    while(row <= n) {

        int col = 1;
        char start = 'A' + n - row;
        while(col <= row) {
            cout<< start;
            start = start + 1;
            col = col + 1;
        }
        cout<< endl;
        row = row + 1;
    }
    return 0;
}


#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    int row = 1;

    while(row <= n) {

        //space print karlo
        int space = n - row;
        while(space) {
            cout<<" ";
            space = space - 1;
        }

        //stars print karlo
        int col = 1;
        while( col <= row ) {
            cout<<"*";
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}

#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    int row = 1;

    while(row <= n) {

        //Print karo space (1st triangle)
        int space = n - row ;
        while(space) {
            cout<<" ";
            space = space -1;
        }

        //print 2nd triangle 
        int j = 1;
        while(j <= row ) {
            cout<<j;
            j = j + 1;
        }

        //print 3rd triangle

        int start = row - 1;
        while(start) {
            cout<<start;
            start = start - 1;
        }

        cout<<endl;
        row = row + 1;
    }
    return 0;
}