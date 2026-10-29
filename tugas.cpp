#include <iostream>
#include <string>

using namespace std;

const int MAKS = 100;

char kecil(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

bool lebihBesar(const string& a, const string& b) {
    size_t i = 0;
    while (i < a.length() && i < b.length()) {
        char x = kecil(a[i]);
        char y = kecil(b[i]);
        if (x != y) return x > y;
        i++;
    }
    return a.length() > b.length();
}

void tampilkan(string data[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << data[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}
void insertionSort(string data[], int n) {
    cout << "\nKondisi awal      : ";
    tampilkan(data, n);
    cout << "\n\n";

    for (int i = 1; i < n; i++) {
        string kunci = data[i];
        int j = i - 1;

        cout << " Langkah " << i << "\n";
        cout << "Elemen kunci:" << kunci << "\n";

        // Geser elemen yang lebih besar dari kunci satu posisi ke kanan
        while (j >= 0 && lebihBesar(data[j], kunci)) {
            cout << "  Geser \"" << data[j] << "\" dari indeks " << j
                 << " ke indeks " << j + 1 << "\n";
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = kunci;

        if (j + 1 == i) {
            cout << "Tidak ada pergeseran\n";
        } else {
            cout << "Sisipkan \"" << kunci << "\" di indeks " << j + 1 << "\n";
        }

        cout << "Hasil langkah: " << i << " ";
        tampilkan(data, n);
        cout << "\n\n";
    }
}

int main() {
    string kata[MAKS];
    int n = 0;

    cout << "Masukkan jumlah kata: ";
    cin >> n;

    if (n <= 0 || n > MAKS) {
        cout << "Jumlah kata harus antara 1 dan " << MAKS << ".\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> kata[i];
    }

    insertionSort(kata, n);

    cout << "Hasil akhir (A-Z): ";
    tampilkan(kata, n);
    cout << endl;

    return 0;
}
