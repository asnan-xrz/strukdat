#include <iostream>
#include <map>

using namespace std;

map<string, map<string, string> > dataAkun;

// Hash Function
int hashFunction(string password)
{
  int hashValue = 0;

  for (char c : password) //loop yang akan berjalan melalui setiap karakter (c) dalam string password
  {
    hashValue = (hashValue * 31) + int(c) - 17; //mengalikan hashValue dengan 31 untuk memastikan variasi yang cukup besar dalam hasil hash (31 adalah angka prima sehingga meminimalisir koilisi). int(c) mengonversi karakter c ke nilai ASCII. Misalnya, jika c adalah huruf 'a', maka nilai ASCII-nya adalah 97. (- 17): Kita kemudian mengurangi 17 dari hasilnya. Ini adalah operasi pengurangan konstan. Operasi ini dapat memberikan variasi tambahan pada hash.
  }

  return hashValue;
}


void registerAkun()
{
  string username, password, fullname;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;
  cout << "Masukkan Nama Lengkap: " << endl;
  cin >> fullname;

  string hash_key = to_string(hashFunction(password));

  map<string, string> dataDetail;
  dataDetail["username"] = username;
  dataDetail["fullname"] = fullname;

  // masukkan ke map
  dataAkun[hash_key] = dataDetail;
}

void loginAkun()
{
  string username, password;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;

  string hash_key = to_string(hashFunction(password));

  cout << endl;
  if (dataAkun.find(hash_key) != dataAkun.end())
  {
    cout << "Login berhasil!" << endl
         << endl;
    cout << "==== Account Details ====" << endl;
    cout << "Username: " << dataAkun[hash_key]["username"] << endl;
    cout << "Fullname: " << dataAkun[hash_key]["username"] << endl;
  } else {
    cout << "Login gagal!" << endl
         << endl;
  }
}

void printAkun()
{
  cout << endl;
  for (auto i = dataAkun.begin(); i != dataAkun.end(); i++)
  {
    cout << "Key: " << i->first << "\t"
         << " Username: " << i->second["username"] << " Fullname: " << i->second["fullname"] << endl;
  }
}

// Menu
void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << endl;
    cout << "Pilih Menu: " << endl;
    cin >> input_user;

    if (input_user == 1)
    {
      registerAkun();
    }
    else if (input_user == 2)
    {
      loginAkun();
    }
    else if (input_user == 3)
    {
      printAkun();
      break;
    }
    else
    {
      cout << "Invalid!" << endl;
    }
  }
}

int main()
{
  menu();
}
