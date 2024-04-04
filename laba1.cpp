#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter Number: " ;
    cin >> n;


    for (int i = 0; i < n; ++i) {

        for (int j = n - 1; j > i; j--){
            cout <<" ";
        }
       
        for (int j = 0; j <= i; ++j) {
            cout << "*";
        }
       
       
       
        for (int k = 0; k < i; ++k) {
             cout << k;
        }
        cout << endl;
    }
    
    return 0;
}