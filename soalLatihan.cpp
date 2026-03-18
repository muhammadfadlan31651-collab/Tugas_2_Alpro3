#include <iostream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string ekspedisi, tujuan;
    double berat, biaya = 0;

    // input data dari user
    cout << "Pilih ekspedisi (JNE/SiCepat/Gojek): ";
    cin >> ekspedisi;
    cout << "Tujuan (dalam/luar): ";
    cin >> tujuan;
    cout << "Berat barang (kg): ";
    cin >> berat;

    // cek ekspedisi yang dipilih
    if (ekspedisi == "JNE") {
        // biaya dasar JNE
        if (tujuan == "dalam") biaya = 10000 * berat;
        else biaya = 20000 * berat;

        // diskon 50% kalau berat > 10 kg
        if (berat > 10) biaya *= 0.5;
    }
    else if (ekspedisi == "SiCepat") {
        // biaya dasar SiCepat
        if (tujuan == "dalam") biaya = 8000 * berat;
        else biaya = 18000 * berat;

        // gratis ongkir kalau berat > 15 kg
        if (berat > 15) biaya = 0;
    }
    else if (ekspedisi == "Gojek") {
        // Gojek hanya untuk dalam kota
        if (tujuan == "dalam") {
            biaya = 12000 * berat;
            // potongan Rp10.000 kalau berat > 5 kg
            if (berat > 5) biaya -= 10000;
            // jangan sampai minus
            if (biaya < 0) biaya = 0;
        } else {
            cout << "Gojek hanya bisa dalam kota.\n";
            return 0;
        }
    }
    else {
        // kalau nama ekspedisi tidak dikenali
        cout << "Ekspedisi tidak tersedia.\n";
        return 0;
    }

    // tampilkan hasil
    cout << "Total biaya pengiriman: Rp" << biaya << endl;
    return 0;
}

