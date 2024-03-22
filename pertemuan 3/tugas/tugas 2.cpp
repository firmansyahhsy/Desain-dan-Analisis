#include <iostream>
#include <string>

using namespace std;

class Pelajar {
private:
    string nama;
    int umur;
    string sekolah;
    bool statusPinjam;

public:
    // Constructor
    Pelajar() : nama(" "), umur(0), sekolah(" "), statusPinjam(false) {}

    // Setter
    void setNama(string _nama) {
        nama = _nama;
    }

    void setUmur(int _umur) {
        umur = _umur;
    }

    void setsekolah(string _sekolah) {
        sekolah = _sekolah;
    }

    void setStatusPinjam(bool pinjam) {
        statusPinjam = pinjam;
    }

    // Getter
    string getNama() const {
        return nama;
    }

    int getUmur() const {
        return umur;
    }

    string getsekolah() const {
        return sekolah;
    }

    bool getStatusPinjam() const {
        return statusPinjam;
    }

    void pinjamuang(string JumlahUang) {
        if (!statusPinjam) {
            cout << endl<< nama << " (" << sekolah << ") Meminjam Uang \"" << JumlahUang << "\" dari Arya." << endl;
            statusPinjam = true;
        } else {
            cout << "Maaf, " << nama << " (" << sekolah << ") sudah meminjam Uang." << endl;
        }
    }

    void kembalikanuang(string JumlahUang) {
        if (statusPinjam) {
            cout <<endl<<endl<< nama << " (" << sekolah << ") mengembalikan uang \"" << JumlahUang << "\" ke Arya." << endl;
            statusPinjam = false;
        } else {
            cout << "Maaf, " << nama << " (" << sekolah << ") tidak meminjam uang." << endl;
        }
    }
};

int main() {
    Pelajar pelajar;

    // Input data pelajar
    string nama, sekolah;
    int umur;
    cout << "Masukkan nama pelajar\t: ";
    getline(cin, nama);
    cout << "Masukkan umur pelajar\t: ";
    cin >> umur;
    cin.ignore(); // Membuang karakter newline di buffer
    cout << "Masukkan tempat sekolah pelajar\t: ";
    getline(cin, sekolah);

    // Set data pelajar
    pelajar.setNama(nama);
    pelajar.setUmur(umur);
    pelajar.setsekolah(sekolah);

    // Meminjam dan mengembalikan uang
    string JumlahUang;
    cout << "Masukkan jumlah uang yang ingin di pinjam : ";
    getline(cin, JumlahUang);
    pelajar.pinjamuang(JumlahUang);

    cout << "\nMasukkan jumlah uang yang ingin dikembalikan : ";
    getline(cin, JumlahUang);
    pelajar.kembalikanuang(JumlahUang);

    return 0;
}






