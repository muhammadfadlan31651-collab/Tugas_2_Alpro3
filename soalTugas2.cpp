#include <iostream>
#include <string>
using namespace std;

// Mengecek apakah angka termasuk "alfa"
// Caranya: lihat apakah digit-digitnya selalu naik (misalnya 1234)
// atau selalu turun (misalnya 9876). Kalau salah satu pola terpenuhi, berarti alfa.
bool isAlfa(const string &num) {
    bool naik = true, turun = true;
    for (int i = 0; i < 3; i++) {
        if (!(num[i] < num[i+1])) naik = false;   // kalau ada yang tidak naik, gagal pola naik
        if (!(num[i] > num[i+1])) turun = false;  // kalau ada yang tidak turun, gagal pola turun
    }
    return naik || turun;
}

// Mengecek apakah angka termasuk "beta"
// Aturannya: ambil dua digit pertama dan dua digit terakhir,
// lalu hitung selisihnya. Kalau selisih ≥ 30, maka masuk kategori beta.
bool isBeta(const string &num) {
    int depan = stoi(num.substr(0,2));    // dua digit pertama
    int belakang = stoi(num.substr(2,2)); // dua digit terakhir
    return abs(depan - belakang) >= 30;
}

int main() {
    string num;
    cout << "Masukkan bilangan 4 digit: ";
    cin >> num;

    // Pastikan input benar-benar 4 digit angka
    if (num.size() != 4 || !isdigit(num[0]) || !isdigit(num[1]) || !isdigit(num[2]) || !isdigit(num[3])) {
        cout << "Input harus berupa bilangan 4 digit." << endl;
        return 0;
    }

    // Cek apakah angka memenuhi syarat alfa dan beta
    bool alfa = isAlfa(num);
    bool beta = isBeta(num);

    // Tentukan kategori:
    // - Gamma: kalau alfa dan beta sekaligus
    // - Alfa: hanya pola digit naik/turun
    // - Beta: hanya selisih digit ≥ 30
    // - Delta: tidak masuk ketiganya
    if (alfa && beta) {
        cout << "Bilangan gamma" << endl;
    } else if (alfa) {
        cout << "Bilangan alfa" << endl;
    } else if (beta) {
        cout << "Bilangan beta" << endl;
    } else {
        cout << "Bilangan delta" << endl;
    }

    return 0;
}
