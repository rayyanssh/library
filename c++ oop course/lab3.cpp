#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue; 
        }
        cout << i << '\n';
    }
    for(int i = 1; i <= 20; i++){
        if(i==3 || i==4 || i==8){
            continue;
        } 
        cout<< i * 0.5f << endl; 
    }
    int i=0;
    do {
        cout << i << ":HELLO\n";
        i++;
    } while(i < 10);
    int a=10;
    string b="john";
    if (a>1)
    cout<<"more than one\n";
    if (a<10)
    cout<<"less than 10\n";
    if (a>=10)
    cout<<"more than or equal to 10\n";
    if (a<=10)
    cout<<"less than or equal to 10\n";
    if (a==10)
    cout<<"equal to 10\n";
    if(a!=7)
    cout<<"is not equal to 7";
    if (b=="john")
    cout<<"\nb is..."<<b;

    return 0;
}