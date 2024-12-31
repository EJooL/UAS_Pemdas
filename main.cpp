#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Struktur data pasien dengan prioritas
struct Patient {
    int priority; // 1: Darurat, 2: Tinggi, 3: Biasa
    string name;
    string illness;

    // Operator untuk menentukan prioritas di priority queue
    bool operator<(const Patient &other) const {
        return priority > other.priority; // Prioritas lebih kecil diutamakan
    }
};

// Priority queue untuk antrean pasien
priority_queue<Patient> patientQueue;

// Fungsi untuk menambahkan pasien ke antrean
void addPatient() {
    Patient newPatient;
    cout << "Masukkan nama pasien: ";
    cin.ignore();
    getline(cin, newPatient.name);
    cout << "Masukkan keluhan pasien: ";
    getline(cin, newPatient.illness);

    cout << "Masukkan prioritas pasien (1: Darurat, 2: Tinggi, 3: Biasa): ";
    cin >> newPatient.priority;

    if (newPatient.priority < 1 || newPatient.priority > 3) {
        cout << "Prioritas tidak valid. Pasien tidak ditambahkan.\n";
        return;
    }

    patientQueue.push(newPatient);
    cout << "Pasien berhasil ditambahkan ke antrean!\n";
}

// Fungsi untuk melayani pasien dengan prioritas tertinggi
void servePatient() {
    if (patientQueue.empty()) {
        cout << "Tidak ada pasien dalam antrean.\n";
        return;
    }

    Patient nextPatient = patientQueue.top();
    patientQueue.pop();

    cout << "\nPasien berikutnya yang akan dilayani:\n";
    cout << "Nama: " << nextPatient.name 
         << "\nKeluhan: " << nextPatient.illness 
         << "\nPrioritas: " << nextPatient.priority << "\n";
}

// Fungsi untuk menampilkan semua pasien dalam antrean
void listPatients() {
    if (patientQueue.empty()) {
        cout << "Tidak ada pasien dalam antrean.\n";
        return;
    }

    cout << "\nDaftar Pasien dalam Antrean:\n";
    priority_queue<Patient> tempQueue = patientQueue;
    while (!tempQueue.empty()) {
        Patient patient = tempQueue.top();
        tempQueue.pop();
        cout << "Nama: " << patient.name 
             << ", Keluhan: " << patient.illness 
             << ", Prioritas: " << patient.priority << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n=== Sistem Layanan Rumah Sakit ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Layani Pasien\n";
        cout << "3. Lihat Antrean Pasien\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: servePatient(); break;
            case 3: listPatients(); break;
            case 4: cout << "Terima kasih telah menggunakan layanan.\n"; break;
            default: cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}