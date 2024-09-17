#include<iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "Pindahkan Cakram " << from_rod << " ke paksi " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Pindahkan Cakram " << n << " dari paksi " << from_rod << " ke paksi " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    cout << "Masukkan Cakram : ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C merupakan nama paksi atau batangan
    return 0;
}
