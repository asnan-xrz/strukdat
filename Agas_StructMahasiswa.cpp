#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string judul;
    string penulis;
    string editor;
    string desainerIsi;
    string desainerSampul;
    string penerbit;
    int tahunTerbit;
    int jumlahHalaman;
    float lebarBuku;
    float tinggiBuku;
    string ISBN;
};

void tampilMenu() {
    cout << "Menu Data Buku\n\n";
    cout << "1. Tambah Data Buku\n";
    cout << "2. Tampilkan Data Buku\n";
    cout << "3. Ubah Data Buku\n";
    cout << "4. Hapus Data Buku\n";
    cout << "5. Keluar\n\n";
    cout << "Pilih Menu: ";
}

int main() {
    //declare variabel
    int pilihan;
    Buku *buku; //pointer ke struct Buku
    int jumlahBuku = 0;

    //inisialisasi pointer buku
    buku = new Buku[10];

    //loop
    while (true) {
        tampilMenu();
        cin >> pilihan;
    


    switch (pilihan) {
        case 1:
            //tambah data
            if (jumlahBuku < 10) {
                cout << "Masukkan Judul Buku: ";
                cin.ignore(); //ngebersihin buffer
                getline(cin, buku[jumlahBuku].judul);

                cout << "Masukkan Penulis Buku: ";
                getline(cin,buku[jumlahBuku].penulis);

                cout << "Masukkan Editor Buku: ";
                getline(cin, buku[jumlahBuku].editor);

                cout << "Masukkan Desainer isi Buku: ";
                getline(cin, buku[jumlahBuku].desainerIsi);

                cout << "Masukkan Desainer Sampul Buku: ";
                getline(cin, buku[jumlahBuku].desainerSampul);

                cout << "Masukkan Penerbit Buku: ";
                getline(cin, buku[jumlahBuku].penerbit);

                cout << "Masukkan Tahun Terbit: ";
                cin >> buku[jumlahBuku].tahunTerbit;

                cout << "Masukkan Jumlah Halaman: ";
                cin >> buku[jumlahBuku].jumlahHalaman;

                cout << "Masukkan Lebar Buku (cm): ";
                cin >> buku[jumlahBuku].lebarBuku;

                cout << "Masukkan Tinggi Buku (cm): ";
                cin >> buku[jumlahBuku].tinggiBuku;

                cin.ignore(); //ngebersihin buffer

                cout << "Masukkan ISBN: ";
                getline(cin, buku[jumlahBuku].ISBN);
                
                jumlahBuku++;

                cout << "Data buku berhasil ditambahkan.\n\n";
            } else {
                cout << "sudah mencapai batas maksimal data buku (10).\n\n";
            }
            break;
        
        case 2:
            //nampilin data
            if (jumlahBuku > 0) {
                cout << "Data Buku\n\n";
                for (int i=0 ; i < jumlahBuku ; i++) {
                    cout << "Nomor: " << i + 1 << "\n";

                    cout << "Judul Buku: " << buku[i].judul << "\n";

                    cout << "Editor Buku: " << buku[i].editor << "\n";

                    cout << "Desainer Isi Buku: " << buku[i].desainerIsi << "\n";

                    cout << "Desainer Sampul Buku: " << buku[i].desainerSampul << "\n";

                    cout << "Penerbit Buku: " << buku[i].penerbit << "\n";

                    cout << "Tahun Terbit: " << buku[i].tahunTerbit << "\n";

                    cout << "Jumlah Halaman: " << buku[i].jumlahHalaman << "\n";

                    cout << "Lebar Buku (cm): " << buku[i].lebarBuku << "\n";

                    cout << "Tinggi Buku (cm): " << buku[i].tinggiBuku << "\n";

                    cout << "ISBN: " << buku[i].ISBN << "\n\n";
                }
            } else {
                cout << "Belum ada data buku. \n\n";
            }
            break;

        case 3:
            // ubah data
            if (jumlahBuku > 0) {
                int nomor;
                cout << "Masukkan nomor data yang ingin diubah: ";
                cin >> nomor;

                if (nomor >= 1 && nomor <= jumlahBuku) {
                    cout << "Masukkan Judul Buku: ";
                    cin.ignore();
                    getline(cin, buku[nomor - 1].judul);

                    cout << "Masukkan Penulis Buku: ";
                    getline(cin, buku[nomor - 1].penulis);

                    cout << "Masukkan Editor Buku: ";
                    getline(cin, buku[nomor - 1].editor);

                    cout << "Masukkan Desainer Isi Buku: ";
                    getline(cin, buku[nomor - 1].desainerIsi);

                    cout << "Masukkan Desainer Sampul Buku: ";
                    getline(cin, buku[nomor - 1].desainerSampul);

                    cout << "Masukkan Penerbit Buku: ";
                    getline(cin, buku[nomor - 1].penerbit);

                    cout << "Masukkan Tahun Terbit: ";
                    cin >> buku[nomor - 1].tahunTerbit;

                    cout << "Masukkan Jumlah Halaman: ";
                    cin >> buku[nomor - 1].jumlahHalaman;

                    cout << "Masukkan Lebar Buku (cm): ";
                    cin >> buku[nomor - 1].lebarBuku;

                    cout << "Masukkan Tinggi Buku (cm): ";
                    cin >> buku[nomor - 1].tinggiBuku;
                    cin.ignore();

                    cout << "Masukkan ISBN: ";
                    getline(cin, buku[nomor - 1].ISBN);
                    cout << "Data buku berhasil diubah\n\n";
                } else {
                    cout << "Nomor Tidak Valid. \n\n";
                }
            } else {
                cout << "Belum ada data buku. \n\n";
            }
            break;

        case 4:
            //hapus data
            if (jumlahBuku > 0) {
                int nomor;
                cout << "Masukkan nomor data yang ingin dihapus: ";
                cin >> nomor;

                if (nomor >= 1 && nomor <= jumlahBuku) {
                    for (int i = nomor - 1; i < jumlahBuku - 1; i++) {
                        buku[i] = buku[i+1];
                    }
                    jumlahBuku--;
                    cout << "Data buku berhasil dihapus.\n\n";
                } else {
                    cout << "Nomor tidak valid.\n\n";
                }
            } else {
                cout << "Belum ada data buku.\n\n";
            }
            break;

        case 5:
            //exit program
            cout << "Terimakasih sudah menggunakan program ini. \n";
            delete[] buku; //bebaskan memori yang telah dialokasikan untuk pointer buku
            return 0;

        default:
            cout << "Pilihan tidak valid. Silahkan coba lagi dari angka 1-5\n\n";
    }
    
}
	return 0;
}
