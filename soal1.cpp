#include <iostream>
using namespace std;

int main(){
    int n;
    int x;
    int hasil;
    cout << "masukkan jumlah deret : "; cin >> n;

    for (int i = 0; i < n; i++){
        cout << "masukkan angka : "; cin >> x;

        if ( i % 2 == 0){
            cout << x << " " << ++n << endl;
        } else {
            cout << -x << " " << ++n << endl;
        }
    }
}