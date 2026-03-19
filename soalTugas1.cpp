#include <iostream>

using namespace std;

int main() {
    int jamBerangkat, jamPulang;
    int biayaTotal = 0;

    // input jam keberangkatan dan kepulangan user 
    cout << "Jam Berangkat (1-24): ";
    cin >> jamBerangkat;
    cout << "Jam Pulang (1-24): ";
    cin >> jamPulang;

    cout << "\n--- Rencana Perjalanan ---" << endl;

    /*logika pemilihan transportasi 
    kita harus mengecek bus linus karena biayanya gratis, jika tidak masuk jadwal linus baru cek bus hijau
    jika keduanya tidak tersedia otomatis menggunakan angkot*/
    cout << "Berangkat: ";
    // cek apakah jam berangkat masuk jadwal bus linus
    if ((jamBerangkat >= 6 && jamBerangkat <= 8) || (jamBerangkat >= 15 && jamBerangkat <= 17)) {
        cout << "Bus Linus (Gratis)" << endl;
        biayaTotal += 0;
    // jika bukan linus, cek apakah masuk jadwal bus hijau
    } else if (jamBerangkat >= 7 && jamBerangkat <= 18) {
        cout << "Bus Hijau (Rp5.000)" << endl;
        biayaTotal += 5000;

    // jika diluar jadwal kedua bus diatas, maka naik angkot
    } else {
        cout << "Angkot (Rp10.000)" << endl;
        biayaTotal += 10000;
    }

    cout << "Pulang: ";
    // logika yang sama di terapkan untuk jam pulang
    if ((jamPulang >= 6 && jamPulang <= 8) || (jamPulang >= 15 && jamPulang <= 17)) {
        cout << "Bus Linus (Gratis)" << endl;
        biayaTotal += 0;
    } else if (jamPulang >= 7 && jamPulang <= 18) {
        cout << "Bus Hijau (Rp5.000)" << endl;
        biayaTotal += 5000;
    } else {
        cout << "Angkot (Rp10.000)" << endl;
        biayaTotal += 10000;
    }

    cout << "--------------------------" << endl;
    cout << "Total Biaya: Rp" << biayaTotal << endl;

    return 0;
}
