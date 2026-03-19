#include <iostream>

using namespace std;

int main() {
    float ip, gaji;

    // Input data mahasiswa
    cout << "Masukkan IP Mahasiswa: ";
    cin >> ip;
    cout << "Masukkan Gaji Orang Tua (dalam juta): ";
    cin >> gaji;

    cout << "Hasil: ";

    // 1. Cek kondisi utama: IP >= 3.5
    if (ip >= 3.5) {
        cout << "Beasiswa Kategori 4" << endl;
    } 
    // 2. Jika IP < 3.5, cek berdasarkan gaji
    else {
        if (gaji < 1.0) {
            // Gaji < 1 juta dan IP < 3.5
            cout << "Beasiswa Kategori 1" << endl;
        } 
        else if (gaji >= 1.0 && gaji <= 5.0) {
            // Gaji rentang 1 - 5 juta, ada pengecekan IP lagi (Nested If)
            if (ip >= 2.0) {
                cout << "Beasiswa Kategori 3" << endl;
            } else {
                cout << "Beasiswa Kategori 2" << endl;
            }
        } 
        else {
            // Jika gaji > 5 juta dan IP < 3.5
            cout << "Tidak mendapat beasiswa" << endl;
        }
    }

    return 0;
}
