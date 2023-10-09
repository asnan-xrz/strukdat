#include <iostream>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
    Contact* next;
};

class ContactList {
private:
    Contact* head;

public:
    ContactList() : head(nullptr) {}

    void tambahKontak(string nama, string telepon, string email) {
        Contact* kontakBaru = new Contact;
        kontakBaru->name = nama;
        kontakBaru->phone = telepon;
        kontakBaru->email = email;
        kontakBaru->next = nullptr;

        if (!head) {
            head = kontakBaru;
            return;
        }

        Contact* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = kontakBaru;
    }

    void tampilkanKontak() {
        Contact* temp = head;
        while (temp) {
            cout << "Nama: " << temp->name << ", Telepon: " << temp->phone << ", Email: " << temp->email << endl;
            temp = temp->next;
        }
    }

    ~ContactList() {
        while (head) {
            Contact* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ContactList daftarKontak;

    daftarKontak.tambahKontak("Agas Ananta", "0819-4322-9052", "agasananta04@gmail.com");
    daftarKontak.tambahKontak("Agus Anantum", "0822-3834-4829", "agusanantum@gmail.com");
    daftarKontak.tambahKontak("Saga Atnana", "0891-3837-4759", "sagaatnana@gmail.com");

    cout << "Daftar Kontak:" << endl;
    daftarKontak.tampilkanKontak();

    return 0;
}


