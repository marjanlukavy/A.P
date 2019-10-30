#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct queue{

    int storage[10000];
    int start;
    int finish;
    queue() {
        start = 0;
        end = 0;
    }

    void push(int n){
        
        storage[end] = n;
        end++;
    }

    int pop(){
        int a = storage[start];
        start++;
        return a;
    }

    int front(){
        return storage[start];
    }
   int size(){
       return end - start;
   }
    
    string clear() {
        start = 0;
        end = 0;
        return "cleared";
    }
};

int main() {
    string a;
    queue x;
    cout << "push/pop/front" << endl;

    while(cin >> a){
        if(a == "push"){
            cout << "number:" << endl;
            int n;
            cin >> n;
            x.push(n);
            cout << "size " << endl;
        }
        if(a == "pop"){
            cout << x.pop()<< endl;
        }
        if(a == "front"){
            cout << x.front() << endl;
        }
    }
    return 0;
}


