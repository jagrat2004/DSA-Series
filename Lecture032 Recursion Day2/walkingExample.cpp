#include<iostream> 
using namespace std;

void reachHome(int src, int dest) {
    
    cout << "source " << src  << " destination " << dest << endl;
    //base case
    if(src == dest) {
        cout << " pahuch gya " << endl;
        return ;
    }

    //processing - ek step aage badhjao
    src++;

    //recursive call
    reachHome(src, dest);

}

void reach(int src, int dest){
    cout << "source " << src  << " destination " << dest << endl;

    //base case
    if(src == dest){
        cout << "reached" << endl;
        return;
    }
    
    //processing - move one step 
    src++;
    
    //recursive call
    reach(src,dest);
}



int main() {

    int dest = 5;
    int src = 1;

    cout << endl;

    reach(src, dest);


    return 0;
}