//header yang digunakan untuk mengimport pustaka iostream yang mencakup konten file header standar C++ seperti cin dan cout
#include <iostream>
//header yang digunakan untuk mengimport pustaka yang digunakan untuk mengakses file eksternal
#include <fstream>
//file Header yang berfungsi untuk menampilkan hasil antarmuka kepada pengguna seperti getch
#include <conio.h>

//modul yang digunakan untuk mengimport keseluruhan namespace std ke namespace program saat ini
using namespace std;

//deklarasi struct data_warung yang digunakan untuk menyimpan data warung
struct data_warung{
    string nama_warung;
    string alamat;
    string username;
    string password;
};

//deklarasi struct saldo yang digunakan untuk menyimpan data pengeluaran dan pemasukan
struct saldo{
    int hari;
    int bulan;
    int tahun;
    int uang;
};

//deklarasi array of struct yang digunakan untuk menyimpan 100 struct
struct data_warung warung[100];
struct saldo klr[100];
struct saldo msk[100];

//deklarasi variabel global untuk menghitung panjang dari array of struct
int panjang = sizeof (warung) / sizeof (warung[0]);
int banyak_keluar, banyak_masuk, banyak_warung, sum_masuk, sum_keluar;

//deklarasi prosedur dan fungsi prototype
void hitung_keluar();
void hitung_masuk();
void hitung_warung();
void clear_keluar();
void clear_masuk();
void clear_warung();
void read_warung();
void read_keluar(string nama_warung);
void read_masuk(string nama_warung);
void replace_keluar(string nama_warung);
void replace_masuk(string nama_warung);
void replace_warung();
void create_pengeluaran(string nama_warung, int banyak_tambah);
void create_pemasukan(string nama_warung, int banyak_tambah);
void create_warung();
int total_pemasukan();
int total_pengeluaran();
void swap(saldo *a, saldo *b);
void sort_tanggal_keluar(string nama_warung, char pilih_sort);
void sort_tanggal_masuk(string nama_warung, char pilih_sort);
void sort_saldo_keluar(string nama_warung, char pilih_sort);
void sort_saldo_masuk(string nama_warung, char pilih_sort);
void swap_warung(data_warung *a, data_warung *b);
int partition(int low, int high);
void sort_warung(int low, int high);
void display_keluar();
void display_masuk();
void display_warung();
void display_saldo();
void update_keluar(string nama_warung);
void update_masuk(string nama_warung);
void update_warung();
void hapus_keluar(string nama_warung);
void hapus_masuk(string nama_warung);
void hapus_warung();
void search_keluar(string nama_warung);
void search_masuk(string nama_warung);
void search_warung();
void display_keluar_manager(string nama_warung);
void display_masuk_manager(string nama_warung);
void display_saldo_manager(string nama_warung, string alamat);
void display_warung_for();
void display_keluar_for(string nama_warumg);
void display_masuk_for(string nama_warung);

//deklarasi prosedur admin untuk menampilkan semua menu pada admin
void admin(){
    string nama_warung, pilih, pilih_tambah, pilih_lihat, pilih_ubah, pilih_hapus, pilih_cari, pilih_logout, back;
    int banyak_tambah;
    //exception untuk error handling
    cin.exceptions(ios_base::failbit);
    while (true){
        bool cari_warung = true;
        bool logout = true;
        //membaca file data warung
        clear_warung();
        read_warung();
        hitung_warung();
        system("cls");
        //tampilan menu utama admin/owner
        cout << "=================================================================" << endl;
        cout << "          ~~~~~>>>>>  Selamat Datang Owner  <<<<<~~~~~~          " << endl;
        cout << "=================================================================" << endl;
        cout << "|                 Daftar Menu Pada Program Ini                  |" << endl;
        cout << "|                                                               |" << endl;
        cout << "|  [1]\tTambah Data                                             |" << endl;
        cout << "|  [2]\tLihat Data                                              |" << endl;
        cout << "|  [3]\tUbah Data                                               |" << endl;
        cout << "|  [4]\tHapus Data                                              |" << endl; 
        cout << "|  [5]\tCari Data                                               |" << endl;
        cout << "|  [0]\tLogout                                                  |" << endl; 
        cout << "=================================================================" << endl;
        cout << "   Masukkan Pilihan Menu >> " ; cin >> pilih;
        if (pilih == "1"){
            while (true){
                //tampilan menu tambah data
                system("cls");
                cout << "=================================================================" << endl;
                cout << "|                      Ingin Menambah Data                      |" << endl;
                cout << "|                                                               |" << endl;
                cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                cout << "|  [2]\tData Pemasukan                                          |" << endl;
                cout << "|  [3]\tData Warung Cabang                                      |" << endl;
                cout << "|  [4]\tKembali Ke Menu Utama                                   |" << endl;
                cout << "=================================================================" << endl;
                cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_tambah;
                if (pilih_tambah == "1"){
                    //cek jumlah data warung
                    if (banyak_warung > 0){
                        while (cari_warung){
                            //menampilkan data warung agar memudahkan pengguna
                            system("cls");
                            display_warung_for();
                            cout << "  Ingin Tambah Data Pada Warung >> " ; fflush(stdin) ; getline (cin, nama_warung);
                            //proses mencarui warung
                            for (int i = 0 ; i < panjang ; i++){
                                //apabila ditemukan
                                if (warung[i].nama_warung == nama_warung){
                                    //lakukan
                                    do{
                                        //coba
                                        try {
                                            cout << "=================================================================" << endl;
                                            cout << "  Mohon Untuk Input Angka Mulai Dari 1 \n" << endl;
                                            cout << "  Ingin Tambah Berapa Banyak Data >> " ; cin >> banyak_tambah;
                                        }
                                        //apabila input gagal 
                                        catch (const ios_base::failure &) {
                                            cout << "  Mohon Untuk Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                            system("cls");
                                            //membersihkan kesalahan pada cin
                                            cin.clear();
                                            //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                            cin.ignore();
                                        }
                                    //perulangan while mencegah input kurang dari 0
                                    } while (banyak_tambah <= 0);
                                    //memanggil prosedur create_pengeluaran sesuai nama warung dan banyak yang diinginkan
                                    create_pengeluaran(nama_warung, banyak_tambah);
                                    cari_warung = false;
                                    break;
                                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                                    //apabila tidak ditemukan, dapat kembali atau melanjutkan pencarian
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }
                                }
                            }
                        }
                    }else{
                        cout << "\n  Tidak Ada Data Warung, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                    break;
                }else if (pilih_tambah == "2"){
                    //cek jumlah data warung
                    if (banyak_warung > 0){
                        while (cari_warung){
                            //menampilkan data warung agar memudahkan pengguna
                            system("cls");
                            display_warung_for();
                            cout << "  Ingin Tambah Data Pada Warung >> " ; fflush(stdin) ; getline (cin, nama_warung);
                            //proses mencari data warung
                            for (int i = 0 ; i < panjang ; i++){
                                if (warung[i].nama_warung == nama_warung){
                                    //lakukan
                                    do{
                                        //coba
                                        try {
                                            cout << "=================================================================" << endl;
                                            cout << "  Mohon Untuk Input Angka Mulai Dari 1 \n" << endl;
                                            cout << "  Ingin Tambah Berapa Banyak Data >> " ; cin >> banyak_tambah;
                                        }
                                        //apabila input gagal 
                                        catch (const ios_base::failure &) {
                                            cout << "  Mohon Untuk Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                            system("cls");
                                            //membersihkan kesalahan pada cin
                                            cin.clear();
                                            //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                            cin.ignore();
                                        }
                                    //perulangan while mencegah input kurang dari 0
                                    } while (banyak_tambah <= 0);
                                    //memanggil prosedur create_pemasukan sesuai nama warung dan banyak yang diinginkan
                                    create_pemasukan(nama_warung, banyak_tambah);
                                    cari_warung = false;
                                    break;
                                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                                    //apabila data tidak ditemukan, dapat kembali atau melanjutkan pencarian
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }
                                }
                            }
                        }
                    }else{
                        //apabila tidak ada data warung
                        cout << "\n  Tidak Ada Data Warung, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                    break;
                }else if (pilih_tambah == "3"){
                    //memnaggil prosedur create_warung untuk menambah data warung
                    create_warung();
                    break;
                }else if (pilih_tambah == "4"){
                    break;
                }else{
                    cout << "  \nPilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
        }else if (pilih == "2"){
            while (true){
                //cek jumlah data warung
                if (banyak_warung > 0){
                    //menu tampilkan data
                    system("cls");
                    cout << "=================================================================" << endl;
                    cout << "|                      Ingin Melihat Data                       |" << endl;
                    cout << "|                                                               |" << endl;
                    cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                    cout << "|  [2]\tData Pemasukan                                          |" << endl;
                    cout << "|  [3]\tData Warung Cabang                                      |" << endl;
                    cout << "|  [4]\tSaldo Seluruh Warung                                    |" << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_lihat;
                    if (pilih_lihat == "1"){
                        //menampilkan data pengeluaran
                        display_keluar();
                        break;
                    }else if (pilih_lihat == "2"){
                        //menampilkan data pemasukan
                        display_masuk();
                        break;
                    }else if (pilih_lihat == "3"){
                        //menampilkan data seluruh warung 
                        display_warung();
                        break;
                    }else if (pilih_lihat == "4"){
                        //menampilkan total saldo yang dimiliki seluruh warung
                        display_saldo();
                        break;
                    }else{
                        cout << "  \nPilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                }else{
                    //apabila tidak ada data warung
                    cout << "\n  Tidak Ada Data Warung, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    break;
                }
            }
        }else if (pilih == "3"){
            //cek jumlah data warung
            if (banyak_warung > 0){
                while (true){
                    //tampilan menu ubah data
                    system("cls");
                    cout << "=================================================================" << endl;
                    cout << "|                        Ingin Mengubah                         |" << endl;
                    cout << "|                                                               |" << endl;
                    cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                    cout << "|  [2]\tData Pemasukan                                          |" << endl;
                    cout << "|  [3]\tData Warung                                             |" << endl;
                    cout << "|  [4]\tKembali Ke Menu Utama                                   |" << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_ubah;
                    if (pilih_ubah == "1"){
                        while (cari_warung){
                            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                            display_warung_for();
                            cout << "  Ingin Mengubah Data Pengeluaran Pada Warung >> " ; fflush(stdin) ; getline(cin, nama_warung);
                            //proses mencari data warung
                            for (int i = 0 ; i < panjang ; i++){
                                if (warung[i].nama_warung == nama_warung){
                                    //membaca file pengeluaran
                                    system("cls");
                                    clear_keluar();
                                    read_keluar(nama_warung);
                                    //menampilkan data pengeluaran secara singkat memudahkan pengguna mencari data pengeluaran
                                    display_keluar_for(nama_warung);
                                    //memanggil prosedur untuk mengupdate data pengeluaran
                                    update_keluar(nama_warung);
                                    cari_warung = false;
                                    break;
                                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                                    //apabila data warung tidak ditemukan
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }else{
                                        system("cls");
                                    } 
                                }
                            }
                        }
                        break;
                    }else if (pilih_ubah == "2"){
                        while (cari_warung){
                            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                            display_warung_for();
                            cout << "  Ingin Mengubah Data Pemasukan Pada Warung >> " ; fflush(stdin) ; getline(cin, nama_warung);
                            //proses mencari data warung
                            for (int i = 0 ; i < panjang ; i++){
                                if (warung[i].nama_warung == nama_warung){
                                    //membaca file pemasukan
                                    system("cls");
                                    clear_masuk();
                                    read_masuk(nama_warung);
                                    //menampilkan data pemasukan secara singkat memudahkan pengguna mencari data pemasukan
                                    display_masuk_for(nama_warung);
                                    //memanggil prosedur untuk mengupdate data pemasukan
                                    update_masuk(nama_warung);
                                    cari_warung = false;
                                    break;
                                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                                    //apabila data warung tidak ditemukan
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }else{
                                        system("cls");
                                    } 
                                }
                            }
                        }
                        break;
                    }else if (pilih_ubah == "3"){
                        //memanggil prosedur untuk mengupdate data warung
                        update_warung();
                        break;
                    }else if (pilih_ubah == "4"){
                        break;
                    }else{
                        cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                }
            }else{
                //apabila tidak ada data warung
                cout << "\n  Tidak Ada Data Warung, Tekan ENTER Untuk Melanjutkan..." ; getch();
            }
        }else if (pilih == "4"){
            //cek jumlah data warung
            if (banyak_warung > 0){
                while (true){
                    system("cls");
                    cout << "=================================================================" << endl;
                    cout << "|                        Ingin Menghapus                        |" << endl;
                    cout << "|                                                               |" << endl;
                    cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                    cout << "|  [2]\tData Pemasukan                                          |" << endl;
                    cout << "|  [3]\tData Warung                                             |" << endl;
                    cout << "|  [4]\tKembali Ke Menu Utama                                   |" << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_hapus;
                    if (pilih_hapus == "1"){
                        while (cari_warung){
                            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                            display_warung_for();
                            cout << "  Ingin Menghapus Data Pengeluaran Pada Warung >> " ; fflush(stdin) ; getline(cin, nama_warung);
                            //proses mencari data warung
                            for (int i = 0 ; i < panjang ; i++){
                                if (warung[i].nama_warung == nama_warung){
                                    //membaca file pemasukan
                                    clear_keluar();
                                    read_keluar(nama_warung);
                                    //menampilkan data pengeluaran secara singkat memudahkan pengguna mencari data pengeluaran
                                    display_keluar_for(nama_warung);
                                    //memanggil prosedur untuk hapus data
                                    hapus_keluar(nama_warung);
                                    cari_warung = false;
                                    break;
                                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                                    //apabila data tidak ditemukan
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }else{
                                        system("cls");
                                    } 
                                }
                            }
                        }
                        break;
                    }else if (pilih_hapus == "2"){
                        while (cari_warung){
                            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                            display_warung_for();
                            cout << "  Ingin Menghapus Data Pemasukan Pada Warung : " ; fflush(stdin) ; getline(cin, nama_warung);
                            //proses mencari data warung
                            for (int i = 0 ; i < panjang ; i++){
                                if (warung[i].nama_warung == nama_warung){
                                    //membaca file pemasukan
                                    clear_keluar();
                                    read_masuk(nama_warung);
                                    //menampilkan data pemasukan secara singkat memudahkan pengguna mencari data pemasukan
                                    display_masuk_for(nama_warung);
                                    //memanggil prosedur untuk hapus data   
                                    hapus_masuk(nama_warung);
                                    cari_warung = false;
                                    break;
                                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                                    //apabila data tidak ditemukan
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }else{
                                        system("cls");
                                    } 
                                }
                            }
                        }
                        break;
                    }else if (pilih_hapus == "3"){
                        //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                        display_warung_for();
                        //memanggil prosedur untuk hapus data 
                        hapus_warung();
                        break;
                    }else if (pilih_hapus == "4"){
                        break;
                    }else{
                        cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                }
            }else{
                cout << "\n  Tidak Ada Data Warung, Tekan ENTER Untuk Melanjutkan..." ; getch();
            }
        }else if (pilih == "5"){
            int awal = 0;
            int akhir = banyak_warung;
            if (banyak_warung > 0){
                sort_warung(0, banyak_warung - 1);
                while (true){
                    system("cls");
                    cout << "=================================================================" << endl;
                    cout << "|                         Ingin Mencari                         |" << endl;
                    cout << "|                                                               |" << endl;
                    cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                    cout << "|  [2]\tData Pemasukan                                          |" << endl;
                    cout << "|  [3]\tData Warung                                             |" << endl;
                    cout << "|  [4]\tKembali Ke Menu Utama                                   |" << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_cari;
                    if (pilih_cari == "1"){
                        while (cari_warung){;
                            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                            display_warung_for();
                            cout << "  Ingin Mencari Data Pengeluaran Pada Warung : " ; fflush(stdin) ; getline(cin, nama_warung);
                            int loop = 0;
                            while (true){
                                //proses mencari data warung dengan metode binary search
                                int tengah = (awal + akhir) / 2;
                                if (warung[tengah].nama_warung == nama_warung){
                                    //memanggil prosedur untuk mencari data pengeluaran
                                    search_keluar(nama_warung);
                                    cari_warung = false;
                                    break;
                                }else if (warung[tengah].nama_warung < nama_warung){
                                    awal = tengah + 1;
                                }else{
                                    akhir = tengah - 1;
                                }
                                if (loop == 99 and warung[tengah].nama_warung != nama_warung){
                                    //apabila looping melewati 99 maka dianggap tidak ditemukan menghindari infinite loop
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }else{
                                        system("cls");
                                    }
                                    break;
                                }
                                loop += 1;
                            }
                        }
                        break;
                    }else if (pilih_cari == "2"){
                        while (cari_warung){
                            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                            display_warung_for();
                            cout << "  Ingin Mencari Data Pemasukan Pada Warung : " ; fflush(stdin) ; getline(cin, nama_warung);
                            int loop = 0;
                            while (true){
                                //proses mencari data warung dengan metode binary search
                                int tengah = (awal + akhir) / 2;
                                if (warung[tengah].nama_warung == nama_warung){
                                    //memanggil prosedur untuk mencari data pemasukan
                                    search_masuk(nama_warung);
                                    cari_warung = false;
                                    break;
                                }else if (warung[tengah].nama_warung < nama_warung){
                                    awal = tengah + 1;
                                }else{
                                    akhir = tengah - 1;
                                }
                                if (loop == 99 and warung[tengah].nama_warung != nama_warung){
                                    //apabila looping melewati 99 maka dianggap tidak ditemukan menghindari infinite loop
                                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                                    if (back == "b" or back == "B"){
                                        cari_warung = false;
                                    }else{
                                        system("cls");
                                    }
                                    break;
                                }
                                loop += 1;
                            }
                        }
                        break;
                    }else if (pilih_cari == "3"){
                        //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
                        display_warung_for();
                        //prosedur mencari data warung
                        search_warung();
                        break;
                    }else if (pilih_cari == "4"){
                        break;
                    }else{
                        cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                }
            }else{
                //apabila tidak ada data warung
                cout << "\n  Tidak Ada Data Warung, Tekan ENTER Untuk Melanjutkan..." ; getch();
            }
        }else if (pilih == "0"){
            while (logout){
                //konfirmasi saat ingin logout dari akun
                cout << "\n=================================================================" << endl;
                cout << "   Yakin Ingin Logout (Y/N) ? " ; cin >> pilih_logout;
                if (pilih_logout == "y" or pilih_logout == "Y" or pilih_logout == "n" or pilih_logout == "N"){
                    logout = false;
                }else{
                    cout << "\n  Masukkan Huruf Y Atau N, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
            if (pilih_logout == "y" or pilih_logout == "Y"){
                cout << "\n    ~~~~~~~~~~~~    Berhasil Logout Dari Akun    ~~~~~~~~~~~~    " ; getch();
                break;
            }else {
                cout << "\n    ~~~~~~~~~~~~~    Batal Logout Dari Akun    ~~~~~~~~~~~~~     " ; getch();
                system("cls");
            }
        }else{
            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
        }
    }
}

//deklarasi prosedur user untuk menampilkan semua menu pada user
void user(string nama_warung, string alamat){  
    string pilih, pilih_tambah, pilih_lihat, pilih_ubah, pilih_hapus, pilih_cari, pilih_logout;
    int banyak_tambah;
    //exception error handling mencegah error saat menginput
    cin.exceptions(ios_base::failbit);
    while (true){
        bool logout = true;
        //membaca seluruh data pengeluran dan pemasukan pada file
        clear_keluar();
        clear_masuk();
        read_keluar(nama_warung);
        read_masuk(nama_warung);
        hitung_keluar();
        hitung_masuk();
        //tampilan menu manager cabang
        system("cls");
        cout << "=================================================================" << endl;
        cout << "  ~~~~~>>>>> Selamat Datang Manager " << nama_warung << " <<<<<~~~~~  " << endl;
        cout << "=================================================================" << endl;
        cout << "|                 Daftar Menu Pada Program Ini                  |" << endl;
        cout << "|                                                               |" << endl;
        cout << "|  [1]\tTambah Data Keuangan                                    |" << endl;
        cout << "|  [2]\tLihat Data Keuangan                                     |" << endl;
        cout << "|  [3]\tUbah Data Keuangan                                      |" << endl;
        cout << "|  [4]\tHapus Data Keuangan                                     |" << endl; 
        cout << "|  [5]\tCari Data Keuangan                                      |" << endl;
        cout << "|  [0]\tLogout                                                  |" << endl; 
        cout << "=================================================================" << endl;
        cout << "   Masukkan Pilihan Menu >> " ; cin >> pilih;
        if (pilih == "1"){
            while (true){
                //tampilan menu tambah data
                system("cls");
                cout << "=================================================================" << endl;
                cout << "|                      Ingin Menambah Data                      |" << endl;
                cout << "|                                                               |" << endl;
                cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                cout << "|  [2]\tData Pemasukan                                          |" << endl;
                cout << "|  [3]\tKembali Ke Menu Utama                                   |" << endl;
                cout << "=================================================================" << endl;
                cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_tambah;
                if (pilih_tambah == "1"){
                    //lakukan
                    do{
                        //coba
                        try {
                            cout << "=================================================================" << endl;
                            cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl; 
                            cout << "  Ingin Tambah Berapa Banyak Data >> " ; cin >> banyak_tambah;
                        }
                        //apabila input gagal 
                        catch (const ios_base::failure &) {
                            cout << "  Mohon Untuk Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                            system("cls");
                            //membersihkan kesalahan pada cin
                            cin.clear();
                            //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                            cin.ignore();
                        }
                    //perulangan while mencegah input kurang dari 0
                    } while (banyak_tambah <= 0);
                    //memanggil prosedur untuk menambah data sesuai dengan nama warung dan banyak yang diinginkan
                    create_pengeluaran(nama_warung, banyak_tambah);
                    break;
                }else if (pilih_tambah == "2"){
                    //lakukan
                    do{
                        //coba
                        try {
                            cout << "=================================================================" << endl;
                            cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl; 
                            cout << "  Ingin Tambah Berapa Banyak Data >> " ; cin >> banyak_tambah;
                        }
                        //apabila input gagal 
                        catch (const ios_base::failure &) {
                            cout << "  Mohon Untuk Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                            system("cls");
                            //membersihkan kesalahan pada cin
                            cin.clear();
                            //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                            cin.ignore();
                        }
                    //perulangan while mencegah input kurang dari 0
                    } while (banyak_tambah <= 0);
                    //memanggil prosedur untuk menambah data sesuai dengan nama warung dan banyak yang diinginkan
                    create_pemasukan(nama_warung, banyak_tambah);
                    break;
                }else if (pilih_tambah == "3"){
                    break;
                }else{
                    cout << "  \nPilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
        }else if (pilih == "2"){
            while (true){
                //tampilan menu lihat data
                system("cls");
                cout << "=================================================================" << endl;
                cout << "|                      Ingin Melihat Data                       |" << endl;
                cout << "|                                                               |" << endl;
                cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                cout << "|  [2]\tData Pemasukan                                          |" << endl;
                cout << "|  [3]\tSaldo Warung                                            |" << endl;
                cout << "=================================================================" << endl;
                cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_lihat;
                if (pilih_lihat == "1"){
                    //memanggil prosedur untuk melihat data pengeluaran berdasarkan nama warung
                    system("cls");
                    display_keluar_manager(nama_warung);
                    break;
                }else if (pilih_lihat == "2"){
                    //memanggil prosedur untuk melihat data pemasukan berdasarkan nama warung
                    system("cls");
                    display_masuk_manager(nama_warung);
                    break;
                }else if (pilih_lihat == "3"){
                    //memanggil prosedur untuk melihat data saldo dari sebuah warung
                    system("cls");
                    display_saldo_manager(nama_warung, alamat);
                    break;
                }else{
                    cout << "  \nPilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
        }else if (pilih == "3"){
            while (true){
                //tampilan ubah data
                system("cls");
                cout << "=================================================================" << endl;
                cout << "|                        Ingin Mengubah                         |" << endl;
                cout << "|                                                               |" << endl;
                cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                cout << "|  [2]\tData Pemasukan                                          |" << endl;
                cout << "|  [3]\tKembali Ke Menu Utama                                   |" << endl;
                cout << "=================================================================" << endl;
                cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_ubah;
                if (pilih_ubah == "1"){
                    //menampilkan data pengeluaran secara singkat untuk memudahkan pengguna mencari data
                    system("cls");
                    display_keluar_for(nama_warung);
                    //memanggil prosedur untuk mengupdate data pengeluaran
                    update_keluar(nama_warung);
                    break;
                }else if (pilih_ubah == "2"){
                    //menampilkan data pemasukan secara singkat untuk memudahkan pengguna mencari data
                    system("cls");
                    display_masuk_for(nama_warung);
                    //memanggil prosedur untuk mengupdate data pemasukan
                    update_masuk(nama_warung);
                    break;
                }else if (pilih_ubah == "3"){
                    break;
                }else{
                    cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
        }else if (pilih == "4"){
            while (true){
                //tampilan menu hapus data
                system("cls");
                cout << "=================================================================" << endl;
                cout << "|                        Ingin Menghapus                        |" << endl;
                cout << "|                                                               |" << endl;
                cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                cout << "|  [2]\tData Pemasukan                                          |" << endl;
                cout << "|  [3]\tKembali Ke Menu Utama                                   |" << endl;
                cout << "=================================================================" << endl;
                cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_hapus;
                if (pilih_hapus == "1"){
                    //menampilkan data pengeluaran secara singkat untuk memudahkan pengguna mencari data
                    system("cls");
                    display_keluar_for(nama_warung);
                    //memanggil prosedur untuk menghapus data pengeluaran  
                    hapus_keluar(nama_warung);
                    break;
                }else if (pilih_hapus == "2"){
                    //menampilkan data pemasukan secara singkat untuk memudahkan pengguna mencari data
                    system("cls");
                    display_masuk_for(nama_warung);
                    //memanggil prosedur untuk menghapus data pemasukan  
                    hapus_masuk(nama_warung);
                    break;
                }else if (pilih_hapus == "3"){
                    break;
                }else{
                    cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
        }else if (pilih == "5"){
            while (true){
                //tampilan menu searching
                system("cls");
                cout << "=================================================================" << endl;
                cout << "|                         Ingin Mencari                         |" << endl;
                cout << "|                                                               |" << endl;
                cout << "|  [1]\tData Pengeluaran                                        |" << endl;
                cout << "|  [2]\tData Pemasukan                                          |" << endl;
                cout << "|  [3]\tKembali Ke Menu Utama                                   |" << endl;
                cout << "=================================================================" << endl;
                cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_cari;
                if (pilih_cari == "1"){
                    system("cls");
                    //memanggil prosedur untuk mencari data pengeluaran 
                    search_keluar(nama_warung);
                    break;
                }else if (pilih_cari == "2"){
                    //memanggil prosedur untuk mencari data pemasukan
                    search_masuk(nama_warung);
                    break;
                }else if (pilih_cari == "3"){
                    break;
                }else{
                    cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
            system("cls");
        }else if (pilih == "0"){
            while (logout){
                //konfirmasi logout
                cout << "\n=================================================================" << endl;
                cout << "   Yakin Ingin Logout (Y/N) ? " ; cin >> pilih_logout;
                if (pilih_logout == "y" or pilih_logout == "Y" or pilih_logout == "n" or pilih_logout == "N"){
                    logout = false;
                }else{
                    cout << "\n  Masukkan Huruf Y Atau N, Tekan ENTER Untuk Melanjutkan..." ; getch();
                }
            }
            if (pilih_logout == "y" or pilih_logout == "Y"){
                cout << "\n    ~~~~~~~~~~~~    Berhasil Logout Dari Akun    ~~~~~~~~~~~~    " ; getch();
                break;
            }else {
                cout << "\n    ~~~~~~~~~~~~~    Batal Logout Dari Akun    ~~~~~~~~~~~~~     " ; getch();
            }
            system("cls");
        }else{
            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
            system("cls");
        }
    }
}

//deklarasi login untuk proses login ke program
void login(){
    bool loop = true;
    int batas = 0;
    string username, password;
    while (loop) {
        //inputkan username dan password
        system("cls");
        cout << "=================================================================" << endl;
        cout << "|          Silahkan Login Untuk Melanjutkan Ke Program          |" << endl;
        cout << "=================================================================" << endl;
        cout << "  Username >> " ; fflush(stdin) ; getline (cin, username);
        cout << "  Password >> " ; fflush(stdin) ; getline (cin, password);
        //apabila login sebagai admin atau owner
        if (username == "owner" and password == "admin"){
            //akan masuk ke menu admin atau owner
            admin();
            break;;
        }
        //membaca data warung
        clear_warung();
        read_warung();
        //mencari apakah data login sesuai dengan data akun manager
        for (int i = 0 ; i < panjang ; i++){
            if (username == warung[i].username and password == warung[i].password){
                //apabila ditemukan, akan masuk ke menu user atau manager
                user(warung[i].nama_warung, warung[i].alamat);
                loop = false;
                break;
            } else if (i == 99 and username != warung[i].username and password != warung[i].password){
                //apabila data tidak sesuai
                cout << "  Username Atau Password Salah, Tekan ENTER Untuk Melanjutkan..." ; getch();
                batas += 1;
            }
        }
        //batas dari kesalahan saat input login adalah 3 kali
        if (batas >= 3){
            cout << "\n  Mohon Maaf Kesempatan Login Telah Habis..." ; getch();
            loop = false;
        }
    }
}

int main(){
    string pilih, exit;
    while (true){
        //tampilan menu awal
        //system("cls") digunakan untuk clear screen
        system("cls");
        cout << "=================================================================" << endl;
        cout << "|            ~~~~~>>>>>  Selamat Datang  <<<<<~~~~~             |" << endl;
        cout << "|    >>>  Di Program Manajemen Keuangan Warung Kalasan  <<<     |" << endl;
        cout << "=================================================================" << endl;
        cout << "|  [1]\tLogin                                                   |" << endl;
        cout << "|  [2]\tEXIT                                                    |" << endl;
        cout << "=================================================================" << endl;
        cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih;
        if (pilih == "1"){
            //beralih ke prosedur login
            login(); 
        }else if (pilih == "2"){
            //konfirmasi exit
            cout << "\n  Yakin Ingin Keluar Dari Program? Masukkan 'y' Jika Anda Yakin : " ; cin >> exit;
            if (exit == "Y" or exit == "y"){
                //input y untuk benar benar keluar dari program
                cout << "\n  ~~~~~~~  Terimakasih Telah Menggunakan Program Kami  ~~~~~~~   " << endl;
                break;
            }
        }else {
            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
        }
    }

    //mengembalikan nilai ke 0 atau mengakhiri program
    return 0;
}

//prosedur hitung_keluar untuk menghitung jumlah pengeluaran
void hitung_keluar(){
	banyak_keluar = 0;
	for (int i = 0 ; i < panjang ; i++){
		if (klr[i].hari != 0){
			banyak_keluar += 1;
		}
	}
}

//prosedur hitung_masuk untuk menghitung jumlah pemasukan
void hitung_masuk(){
	banyak_masuk = 0;
	for (int i = 0 ; i < panjang ; i++){
		if (msk[i].hari != 0){
			banyak_masuk += 1;
		}
	}
}

//prosedur hitung_warung untuk menghitung jumlah warung
void hitung_warung(){
    banyak_warung = 0;
	for (int i = 0 ; i < panjang ; i++){
		if (warung[i].nama_warung != ""){
			banyak_warung += 1;
		}
	}
}

//prosedur clear_keluar untuk menghapus seluruh struct data pengeluaran
void clear_keluar(){
	for (int i = 0 ; i < panjang ; i++){
		klr[i].hari = 0;
		klr[i].bulan = 0;
		klr[i].tahun = 0;
		klr[i].uang = 0;
	}
}

//prosedur clear_masuk untuk menghapus seluruh struct data pemasukan
void clear_masuk(){
	for (int i = 0 ; i < panjang ; i++){
		msk[i].hari = 0;
		msk[i].bulan = 0;
		msk[i].tahun = 0;
		msk[i].uang = 0;
	}
}

//prosedur clear_warung untuk menghapus seluruh struct data warung
void clear_warung(){
    for (int i = 0 ; i < panjang ; i++){
		warung[i].nama_warung = "";
        warung[i].alamat = "";
        warung[i].username = "";
        warung[i].password = "";
	}
}

//prosedur read_warung untuk membaca file eksternal data warung ke dalam program
void read_warung(){
    //membuka file dengan fungsi in untuk membaca file
    ifstream data;
    data.open("Data Warung.txt", ios::in);
    if (data.is_open()){
        while (!data.eof()){
            for (int i = 0 ; i < panjang ; i++){
                if (warung[i].nama_warung == ""){
                    //membaca file ke program
                    getline (data, warung[i].nama_warung);
                    getline (data, warung[i].alamat);
                    getline (data, warung[i].username);
                    getline (data, warung[i].password);
                    break;
                }
            }
        }
    }
    //menutup file
    data.close();
}

//prosedur read_keluar untuk membaca file eksternal data pengeluaran ke dalam program
void read_keluar(string nama_warung){
    //membuka file dengan fungsi in untuk membaca file
    ifstream data;
    data.open("Pengeluaran "+nama_warung+".txt", ios::in);
    if (data.is_open()){
        while (!data.eof()){
            for (int i = 0 ; i < panjang ; i++){
                if (klr[i].hari == 0){
                    //membaca file ke program
                    data >> klr[i].hari;
                    data >> klr[i].bulan;
                    data >> klr[i].tahun;
                    data >> klr[i].uang;
                    break;
                }
            }
        }
    }
    //menutup file
    data.close();
}

//prosedur read_masuk untuk membaca file eksternal data pemasukan ke dalam program
void read_masuk(string nama_warung){
    //membuka file dengan fungsi in untuk membaca file
    ifstream data;
    data.open("pemasukan "+nama_warung+".txt", ios::in);
    if (data.is_open()){
        while (!data.eof()){
            for (int i = 0 ; i < panjang ; i++){
                if (msk[i].hari == 0){
                    //membaca file ke program
                    data >> msk[i].hari;
                    data >> msk[i].bulan;
                    data >> msk[i].tahun;
                    data >> msk[i].uang;
                    break;
                }
            }
        }
    }
    //menutup file
    data.close();
}

//prosedur replace_keluar untuk menulis ulang file eksternal data pengeluaran
void replace_keluar(string nama_warung){
    //membuka file dengan ios::trunc untuk menulis ulang file database
    fstream data;
    data.open("Pengeluaran "+nama_warung+".txt", ios::trunc | ios::out | ios::in);
    if (data.is_open()){
        for (int i = 0 ; i < panjang ; i++){
            if (klr[i].hari != 0){
                data << klr[i].hari << " ";
                data << klr[i].bulan << " ";
                data << klr[i].tahun << " ";
                data << klr[i].uang << " " << endl;
            }
        }
    }
    //menutup file
    data.close();
}

//prosedur replace_masuk untuk menulis ulang file eksternal data pemasukan
void replace_masuk(string nama_warung){
    //membuka file dengan ios::trunc untuk menulis ulang file database
    fstream data;
    data.open("Pemasukan "+nama_warung+".txt", ios::trunc | ios::out | ios::in);
    if (data.is_open()){
        for (int i = 0 ; i < panjang ; i++){
            if (msk[i].hari != 0){
                data << msk[i].hari << " ";
                data << msk[i].bulan << " ";
                data << msk[i].tahun << " ";
                data << msk[i].uang << " " << endl;
            }
        }
    }
    //menutup file
    data.close();
}

//prosedur replace_warung untuk menulis ulang file eksternal data warung
void replace_warung(){
    //membuka file dengan ios::trunc untuk menulis ulang file database
    fstream data;
    data.open("Data Warung.txt", ios::trunc | ios::out | ios::in);
    if (data.is_open()){
        for (int j = 0 ; j < panjang ; j++){
            if (warung[j].nama_warung != ""){
                data << warung[j].nama_warung << endl;
                data << warung[j].alamat << endl;
                data << warung[j].username << endl;
                data << warung[j].password << endl;
            }
        }
    }
    //menutup file
    data.close();
}

//prosedur create_pengeluaran untuk menambah pengeluaran
void create_pengeluaran(string nama_warung, int banyak_tambah){
    ofstream data;
    saldo tulis;
    clear_keluar();
    read_keluar(nama_warung);
    hitung_keluar();
    if (banyak_keluar < 100){
        //exception merupakan error handling mencegah error saat menginput integer
        cin.exceptions(ios_base::failbit);
        //membuka file dengan ios::out dan app untuk menulis file dari baris terakhir
        data.open("Pengeluaran "+nama_warung+".txt", ios::out | ios::app);
        if (data.is_open()){
            for (int i = 0 ; i < banyak_tambah ; i++){
                //lakukan
                do{
                    //coba
                    try {
                        system("cls");
                        cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                        cout << "=================================================================" << endl;
                        cout << "  Masukkan Tanggal Pengeluaran " << endl;
                        cout << "  Masukkan Hari : " ; cin >> tulis.hari;
                        cout << "  Masukkan Bulan: " ; cin >> tulis.bulan;
                        cout << "  Masukkan Tahun: " ; cin >> tulis.tahun;
                        cout << "=================================================================" << endl;
                        cout << "  Masukkan Jumlah Pengeluaran : Rp" ; cin >> tulis.uang;
                    }
                    //apabila input gagal 
                    catch (const ios_base::failure &) {
                        cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                        //membersihkan kesalahan pada cin
                        cin.clear();
                        //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                        cin.ignore();
                    }
                //perulangan while mencegah input kurang dari 0
                } while (tulis.hari <= 0 or tulis.bulan <= 0 or tulis.tahun <= 0 or tulis.uang < 0);
                //menulis file
                data << tulis.hari << " ";
                data << tulis.bulan << " ";
                data << tulis.tahun << " ";
                data << tulis.uang << endl;
                cout << "   ~~~~~~~~~  Berhasil Menambahkan Data Pengeluaran  ~~~~~~~~~   " << endl;
            }
        }else{
            cout << "  File ERROR!" << endl;
        }
        //menutup file
        data.close();
    }else{
        cout << "  Data Pengeluaran Telah Penuh, Mohon Untuk Hapus Data Sebelum Menambah Data " << endl;
    }
    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();  
    clear_keluar();
    read_keluar(nama_warung);
}

//prosedur create_masuk untuk menambah pemasukan
void create_pemasukan(string nama_warung, int banyak_tambah){
    ofstream data;
    saldo tulis;
    clear_masuk();
    read_masuk(nama_warung);
    hitung_masuk();
    if (banyak_masuk < 100){
        //exception merupakan error handling mencegah error saat menginput integer
        cin.exceptions(ios_base::failbit);
        //membuka file dengan ios::out dan app untuk menulis file dari baris terakhir
        data.open("Pemasukan "+nama_warung+".txt", ios::out | ios::app);
        if (data.is_open()){
            for (int i = 0 ; i < banyak_tambah ; i++){
                //lakukan
                do{
                    //coba
                    try {
                        system("cls");
                        cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                        cout << "=================================================================" << endl;
                        cout << "  Masukkan Tanggal Pemasukan " << endl;
                        cout << "  Masukkan Hari : " ; cin >> tulis.hari;
                        cout << "  Masukkan Bulan: " ; cin >> tulis.bulan;
                        cout << "  Masukkan Tahun: " ; cin >> tulis.tahun;
                        cout << "=================================================================" << endl;
                        cout << "  Masukkan Jumlah Pemasukan : Rp" ; cin >> tulis.uang;
                    }
                    //apabila input gagal 
                    catch (const ios_base::failure &) {
                        cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    //membersihkan kesalahan pada cin
                        cin.clear();
                    //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                        cin.ignore();
                    }
                //perulangan while mencegah input kurang dari 0
                } while (tulis.hari <= 0 or tulis.bulan <= 0 or tulis.tahun <= 0 or tulis.uang < 0);
                //menulis file
                data << tulis.hari << " ";
                data << tulis.bulan << " ";
                data << tulis.tahun << " ";
                data << tulis.uang << endl;
                cout << "   ~~~~~~~~~~  Berhasil Menambahkan Data Pemasukan  ~~~~~~~~~~   " << endl;
            }
        }else{
            cout << "  File ERROR!" << endl;
        }
        //menutup file
        data.close();
    }else{
        cout << "  Data Pemasukan Telah Penuh, Mohon Untuk Hapus Data Sebelum Menambah Data " << endl;
    }
    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    clear_masuk();
    read_masuk(nama_warung);
}

//prosedur create_warung untuk menambah data warung
void create_warung(){
    data_warung tulis;
    ofstream data;
    if (banyak_warung < 100){
        //membuka file dengan fungsi out dan app untuk menulis file dari baris terakhir
        data.open("Data Warung.txt", ios::out | ios::app);
        if (data.is_open()){
            system("cls");
            cout << "=================================================================" << endl;
            cout << "  Masukkan Nama Warung Cabang    : " ; fflush(stdin) ; getline (cin, tulis.nama_warung);
            cout << "  Masukkan Alamat Warung Cabang  : " ; fflush(stdin) ; getline (cin, tulis.alamat);
            cout << "  Masukkan Username Akun Manager : " ; fflush(stdin) ; getline (cin, tulis.username);
            cout << "  Masukkan Password Akun Manager : " ; fflush(stdin) ; getline (cin, tulis.password);
            //menulis file
            data << tulis.nama_warung << endl;
            data << tulis.alamat << endl;
            data << tulis.username << endl;
            data << tulis.password << endl;
            cout << "  ~~~~~~~~~~~~  Berhasil Menambahkan Data Warung  ~~~~~~~~~~~~   " << endl;
        }else{
            cout << "  File ERROR!" << endl;
        }
        //menutup file
        data.close();   
    }else{
        cout << "  Data Warung Telah Penuh, Mohon Untuk Hapus Data Sebelum Menambah Data " << endl;
    }
    clear_warung();
    read_warung();
    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
}

//fungsi total_pemasukan untuk menghitung total pemasukan
int total_pemasukan(){
    sum_masuk = 0;
    for (int i = 0 ; i < panjang ; i++){
        sum_masuk += msk[i].uang;
    }
    return sum_masuk;
}

//fungsi total_pemasukan untuk menghitung total pemasukan
int total_pengeluaran(){
    sum_keluar = 0;
    for (int i = 0 ; i < panjang ; i++){
        sum_keluar += klr[i].uang;
    }
    return sum_keluar;
}

//prosedur swap untuk menukar posisi saat proses sorting
void swap(saldo *a, saldo *b){
    //proses swap mengambil alamat dari struct yang ingin ditukar posisinya
    saldo swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

//prosedur sort_tanggal_keluar untuk sorting data pengeluaran berdasarkan tanggal
void sort_tanggal_keluar(string nama_warung, string pilih_sort){
    //sorting dilakukan dengan metode bubble sort
    //mengurutkan mulai dari hari-bulan-tahun
    hitung_keluar();
    if (pilih_sort == "1"){
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].hari != 0){
                    if (klr[j].hari > klr[j+1].hari){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].hari != 0){
                    if (klr[j].bulan > klr[j+1].bulan){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].hari != 0){
                    if (klr[j].tahun > klr[j+1].tahun){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
    }else{
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].hari != 0){
                    if (klr[j].hari < klr[j+1].hari){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].hari != 0){
                    if (klr[j].bulan < klr[j+1].bulan){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].hari != 0){
                    if (klr[j].tahun < klr[j+1].tahun){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
    }
    //menulis kembali file yang telah disorting dan membacanya kembali
    replace_keluar(nama_warung);
    clear_keluar();
    read_keluar(nama_warung);
}

//prosedur sort_tanggal_masuk untuk sorting data pemasukan berdasarkan tanggal
void sort_tanggal_masuk(string nama_warung, string pilih_sort){
    //sorting dilakukan dengan metode bubble sort
    //mengurutkan mulai dari hari-bulan-tahun
    hitung_masuk();
    if (pilih_sort == "1"){
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].hari != 0){
                    if (msk[j].hari > msk[j+1].hari){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].hari != 0){
                    if (msk[j].bulan > msk[j+1].bulan){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].hari != 0){
                    if (msk[j].tahun > msk[j+1].tahun){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
    }else{
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].hari != 0){
                    if (msk[j].hari < msk[j+1].hari){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].hari != 0){
                    if (msk[j].bulan < msk[j+1].bulan){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].hari != 0){
                    if (msk[j].tahun < msk[j+1].tahun){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
    }
    //menulis kembali file yang telah disorting dan membacanya kembali
    replace_masuk(nama_warung);
    clear_masuk();
    read_masuk(nama_warung);
}

//prosedur sort_saldo_keluar untuk sorting data pengeluaran berdasarkan saldo
void sort_saldo_keluar(string nama_warung, string pilih_sort){
    //sorting dilakukan dengan metode bubble sort
    if (pilih_sort == "1"){
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].uang != 0){
                    if (klr[j].uang > klr[j+1].uang){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
    }else{
        for (int i = 0 ; i < banyak_keluar ; i ++){
            for (int j = 0 ; j < banyak_keluar - 1 ; j++){
                if (klr[j].uang != 0){
                    if (klr[j].uang < klr[j+1].uang){
                        swap(&klr[j], &klr[j+1]);
                    }
                }
            }
        }
    }
    //menulis kembali file yang telah disorting dan membacanya kembali
    replace_keluar(nama_warung);
    clear_keluar();
    read_keluar(nama_warung);
}

//prosedur sort_saldo_masuk untuk sorting data pemasukan berdasarkan saldo
void sort_saldo_masuk(string nama_warung, string pilih_sort){
    //sorting dilakukan dengan metode bubble sort
    if (pilih_sort == "1"){
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].uang != 0){
                    if (msk[j].uang > msk[j+1].uang){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
    }else{
        for (int i = 0 ; i < banyak_masuk ; i ++){
            for (int j = 0 ; j < banyak_masuk - 1 ; j++){
                if (msk[j].uang != 0){
                    if (msk[j].uang < msk[j+1].uang){
                        swap(&msk[j], &msk[j+1]);
                    }
                }
            }
        }
    }
    //menulis kembali file yang telah disorting dan membacanya kembali
    replace_masuk(nama_warung);
    clear_masuk();
    read_masuk(nama_warung);
}

//prosedur swap_warung untuk menukar posisi saat proses sorting
void swap_warung(data_warung *a, data_warung *b){
    //proses swap mengambil nilai dari alamat yang telah ditentukan
    data_warung swap = *a;
    *a = *b;
    *b = swap;
}

//fungsi partition untuk membagi dan memproses sorting data warung
int partition(int low, int high){
    //proses ini membagi data menjadi 2 bagian yang kemudian akan disorting
    //dan selanjutnya apabila memungkinkan akan dibagi lagi dan akan terus berulang sampai tersorting
    data_warung pivot = warung[high];
    int i = (low - 1);
    for (int j = low ; j <= high - 1; j++){
        if (warung[j].nama_warung <= pivot.nama_warung){
            i++;
            swap_warung(&warung[i], &warung[j]);
        }
    }
    swap_warung(&warung[i+1], &warung[high]);
    return (i + 1);
}

//prosedur sort_warung untuk sorting data warung dengan metode quick sort
void sort_warung(int low, int high){
    if (low < high){
        int pi = partition(low, high);
        //fungsi rekursif memanggil dirinya sendiri dengan parameter berbeda
        sort_warung(low, pi - 1);
        sort_warung(pi + 1, high);
    }
    //menulis ulang file dan membacanya kembali
    replace_warung();
    clear_warung();
    read_warung();
}

//prosedur display_keluar untuk menampilkan data pengeluaran untuk owner
void display_keluar(){
    bool cari_warung = true;
    string nama_warung, back, pilih_lihat, pilih_sort;
    //menghitung jumlah data warung
    clear_warung();
    read_warung();
    hitung_warung();
    if (banyak_warung > 0){
        while (cari_warung){
            system("cls");
            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
            display_warung_for();
            //mencari data warung
            cout << "  Ingin Melihat Data Pengeluaran Pada Warung >> " ; fflush(stdin) ; getline(cin, nama_warung);
            for (int i = 0 ; i < panjang ; i++){
                if (warung[i].nama_warung == nama_warung){
                    //menghitung jumlah data pengeluaran
                    clear_keluar();
                    read_keluar(nama_warung);
                    hitung_keluar();
                    if (banyak_keluar > 0){
                        while (true){
                            cout << "=================================================================" << endl;
                            cout << "|                   Ingin Melihat Berdasarkan                   |" << endl;
                            cout << "|                                                               |" << endl;
                            cout << "|  [1]\tTanggal Pengeluaran                                     |" << endl;
                            cout << "|  [2]\tJumlah Pengeluaran                                      |" << endl;
                            cout << "=================================================================" << endl;
                            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_lihat;
                            //mencegah input diluar menu
                            if (pilih_lihat == "1" or pilih_lihat == "2"){
                                break;
                            }else{
                                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." << endl ; getch();
                                system("cls");
                            }
                        }
                        while (true){
                            system("cls");
                            cout << "=================================================================" << endl;
                            cout << "|                     Ingin Sorting Secara                      |" << endl;
                            cout << "|                                                               |" << endl;
                            cout << "|  [1]\tAscending                                               |" << endl;
                            cout << "|  [2]\tDescending                                              |" << endl;
                            cout << "=================================================================" << endl;
                            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_sort;
                            //mencegah input diluar menu
                            if (pilih_lihat == "1" or pilih_lihat == "2"){
                                break;
                            }else{
                                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                            }
                        }
                        //memanggil prosedur sorting sesuai keinginan pengguna
                        if (pilih_lihat == "1"){
                            sort_tanggal_keluar(nama_warung, pilih_sort);
                        }else{
                            sort_saldo_keluar(nama_warung, pilih_sort);
                        }
                        //menampilkan data pengeluaran
                        system("cls");
                        cout << "---------------------------------"<<endl;
                        cout << "|    Tanggal\t| Pengeluaran\t|"<<endl;
                        cout << "---------------------------------"<<endl;
                        for (int i = 0 ; i < panjang ; i++){
                            if (klr[i].hari != 0){
                                cout << "| " << klr[i].hari << "-" << klr[i].bulan << "-" << klr[i].tahun << "\t| Rp" << klr[i].uang << "\t|" << endl;
                            }
                        }
                        cout << "---------------------------------"<<endl;
                        cout << "| Total Pengeluaran Rp" << total_pengeluaran() << "\t|"<<endl;
                        cout << "---------------------------------"<<endl;
                    }else{
                        //apabila tidak ada data pengeluaran
                        cout << "   ~~~~~~~~~~~~    Tidak Ada Data Pengeluaran    ~~~~~~~~~~~~    " << endl;
                    }
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_warung = false;
                    break;
                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                    //diberikan kesempatan untuk mencari kembali atau kembali ke menu utama
                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_warung = false;
                    }
                }
            }
        }
    }else{
        cout << "\n   ~~~~~~~~~~~~   Tidak Ada Data Warung Cabang   ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
}

//prosedur display_masuk untuk menampilkan data pemasukan
void display_masuk(){
    bool cari_warung = true;
    string nama_warung, back, pilih_lihat, pilih_sort;
    //menghitung jumlah data warung
    clear_warung();
    read_warung();
    hitung_warung();
    if (banyak_warung > 0){
        while (cari_warung){
            system("cls");
            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
            display_warung_for();
            //mencari data warung
            cout << "  Ingin Melihat Data Pemasukan Pada Warung >> " ; fflush(stdin) ; getline(cin, nama_warung);
            for (int i = 0 ; i < panjang ; i++){
                if (warung[i].nama_warung == nama_warung){
                    //menghitung jumlah data pemasukan
                    clear_masuk();
                    read_masuk(nama_warung);
                    hitung_masuk();
                    if (banyak_masuk > 0){
                        while (true){
                            cout << "=================================================================" << endl;
                            cout << "|                   Ingin Melihat Berdasarkan                   |" << endl;
                            cout << "|                                                               |" << endl;
                            cout << "|  [1]\tTanggal Pemasukan                                       |" << endl;
                            cout << "|  [2]\tJumlah Pemasukan                                        |" << endl;
                            cout << "=================================================================" << endl;
                            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_lihat;
                            //mencegah input diluar menu
                            if (pilih_lihat == "1" or pilih_lihat == "2"){
                                break;
                            }else{
                                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                system("cls");
                            }
                        }
                        while (true){
                            system("cls");
                            cout << "=================================================================" << endl;
                            cout << "|                     Ingin Sorting Secara                      |" << endl;
                            cout << "|                                                               |" << endl;
                            cout << "|  [1]\tAscending                                               |" << endl;
                            cout << "|  [2]\tDescending                                              |" << endl;
                            cout << "=================================================================" << endl;
                            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_sort;
                            //mencegah input diluar menu
                            if (pilih_lihat == "1" or pilih_lihat == "2"){
                                break;
                            }else{
                                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                            }
                        }
                        //memanggil prosedur sorting sesuai dengan keinginan pengguna
                        if (pilih_lihat == "1"){
                            sort_tanggal_masuk(nama_warung, pilih_sort);
                        }else{
                            sort_saldo_masuk(nama_warung, pilih_sort);
                        }
                        //menampilkan data pemasukan
                        system("cls");
                        cout << "---------------------------------"<<endl;
                        cout << "|    Tanggal\t| Pemasukan  \t|"<<endl;
                        cout << "---------------------------------"<<endl;
                        for (int i = 0 ; i < panjang ; i++){
                            if (msk[i].hari != 0){
                                cout << "| " << msk[i].hari << "-" << msk[i].bulan << "-" << msk[i].tahun << "\t| Rp" << msk[i].uang << "\t|" << endl;
                            }
                        }
                        cout << "---------------------------------"<<endl;
                        cout << "| Total Pemasukan Rp" << total_pemasukan() << "\t|"<<endl;
                        cout << "---------------------------------"<<endl;
                    }else{
                        //apabila tidak ada data
                        cout << "   ~~~~~~~~~~~~~    Tidak Ada Data Pemasukan    ~~~~~~~~~~~~~~   " << endl;
                    }
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_warung = false;
                    break;
                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                    //diberikan kesempatan untuk mencari kembali atau kembali ke menu utama
                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_warung = false;
                    }
                }
            }
        }
    }else{
        cout << "\n   ~~~~~~~~~~~~   Tidak Ada Data Warung Cabang   ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
}

//prosedur display_warung untuk menampilkan data warung
void display_warung(){
    //mengecek jumlah data warung
    if (banyak_warung > 0){
        //sorting warung berdasarkan nama warung
        sort_warung(0, banyak_warung - 1);
        system("cls");
        cout << "=================================================================" << endl;
        //menampilkan data warung
        for (int i = 0 ; i < panjang ; i++){
            if (warung[i].nama_warung != ""){
                cout << "  Nama Warung      : " << warung[i].nama_warung << endl;
                cout << "  Alamat Warung    : " << warung[i].alamat << endl;
                cout << "  Username Manager : " << warung[i].username << endl;
                cout << "  Password Manager : " << warung[i].password << endl;
                cout << "=================================================================" << endl;
            }
        }
    }else{
        //apabila tidak ada data
        cout << "\n   ~~~~~~~~~~~~   Tidak Ada Data Warung Cabang   ~~~~~~~~~~~~    " << endl;
    }
    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
}

//prosedur display_saldo untuk menampilkan data saldo seluruh warung
void display_saldo(){
    int total_saldo = 0;
    //cek jumlah data warung
    if (banyak_warung > 0){
        //sorting data warung berdasarkan nama warung
        sort_warung(0, banyak_warung - 1);
        system("cls");
        //menampilkan data keuangan tiap warung serta saldonya
        for (int i = 0 ; i < panjang ; i++){
            if (warung[i].nama_warung != ""){
                int saldo = 0;
                cout << "=================================" << endl;
                cout << "|\t" << warung[i].nama_warung << "\t\t|" << endl;
                cout << "=================================" << endl;
                cout << "|\t" << warung[i].alamat << "\t|" << endl;
                clear_masuk();
                read_masuk(warung[i].nama_warung);
                total_pemasukan();
                clear_keluar();
                read_keluar(warung[i].nama_warung);
                total_pengeluaran();
                hitung_keluar();
                hitung_masuk();
                if (banyak_keluar > 0 and banyak_masuk > 0){
                    cout << "=================================" << endl;
                    cout << "| Pengeluaran\t| Rp" << sum_keluar << "\t|" << endl;
                    cout << "| Pemasukan\t| Rp" << sum_masuk << "\t|" << endl;
                    cout << "=================================" << endl;
                    saldo = sum_masuk - sum_keluar;
                    cout << "| Total Saldo\t| Rp" << saldo << "\t|" << endl;
                    cout << "=================================\n" << endl;
                }else if (banyak_keluar > 0 and banyak_masuk <= 0) {
                    cout << "=================================" << endl;
                    cout << "| Pengeluaran\t| Rp" << sum_keluar << "\t|" << endl;
                    cout << "| Pemasukan\t| Rp0\t\t|" << endl;
                    cout << "=================================" << endl;
                    saldo -= sum_keluar;
                    cout << "| Total Saldo\t| Rp" << saldo << "\t|" << endl;
                    cout << "=================================\n" << endl;
                }else if (banyak_keluar <= 0 and banyak_masuk > 0){
                    cout << "=================================" << endl;
                    cout << "| Pengeluaran\t| Rp0\t\t|" << endl;
                    cout << "| Pemasukan\t| Rp" << sum_masuk << "\t|" << endl;
                    cout << "=================================" << endl;
                    saldo = sum_masuk;
                    cout << "| Total Saldo\t| Rp" << saldo << "\t|" << endl;
                    cout << "=================================\n" << endl;
                }else{
                    cout << "=================================" << endl;
                    cout << "| Pengeluaran\t| Rp0\t\t|" << endl;
                    cout << "| Pemasukan\t| Rp0\t\t|" << endl;
                    cout << "=================================" << endl;
                    cout << "| Total Saldo\t| Rp0\t\t|" << endl;
                    cout << "=================================\n" << endl;
                }
                total_saldo += saldo;
            }
        }
        //menampilkan total saldo seluruh warung
        cout << "=================================" << endl;
        cout << "|  Total Saldo Seluruh Warung   |" << endl;
        cout << "=================================" << endl;
        cout << "|         Rp" << total_saldo << "\t\t|" << endl;
        cout << "=================================" << endl; 
    }else{
        //apabila tidak ada data
        cout << "   ~~~~~~~~~~~~   Tidak Ada Data Warung Cabang   ~~~~~~~~~~~~    " << endl;
    }
    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
}

//prosedur update_keluar untuk mengupdate data pengeluaran
void update_keluar(string nama_warung){
    string pilih_update, back;
    int hari, bulan, tahun;
    bool cari_tanggal = true;
    //exception untuk error handling
    cin.exceptions(ios_base::failbit);
    //read file dan hitung jumlah data
    clear_keluar();
    read_keluar(nama_warung);
    hitung_keluar();
    if (banyak_keluar > 0){
        while (cari_tanggal){
            //lakukan
            do{
                //coba
                try {
                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Tanggal Pengeluaran Yang Ingin Diubah " << endl;
                    cout << "  Hari  : " ; cin >> hari;
                    cout << "  Bulan : " ; cin >> bulan;
                    cout << "  Tahun : " ; cin >> tahun;
                }
                //apabila input gagal 
                catch (const ios_base::failure &) {
                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cout << "\n" << endl;
                //membersihkan kesalahan pada cin
                    cin.clear();
                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                    cin.ignore();
                }
            //perulangan while mencegah input kurang dari 0
            } while (hari <= 0 or bulan <= 0 or tahun <= 0);
            //proses mencari tanggal sesuai inputan
            for (int j = 0 ; j < panjang ; j++){
                if (klr[j].hari == hari and klr[j].bulan == bulan and klr[j].tahun == tahun){
                    //menampilkan data
                    system("cls");
                    cout << "---------------------------------"<<endl;
                    cout << "|    Tanggal\t| Pengeluaran\t|"<<endl;
                    cout << "---------------------------------"<<endl;
                    cout << "| " << klr[j].hari << "-" << klr[j].bulan << "-" << klr[j].tahun << "\t| Rp" << klr[j].uang << "\t|" << endl;
                    cout << "---------------------------------\n"<<endl;
                    while (true){
                        //menu update
                        cout << "=================================================================" << endl;
                        cout << "|                        Ingin Mengubah                         |" << endl;
                        cout << "|                                                               |" << endl;
                        cout << "|  [1]\tTanggal                                                 |" << endl;
                        cout << "|  [2]\tJumlah Pengeluaran                                      |" << endl;
                        cout << "|  [3]\tSemua                                                   |" << endl;
                        cout << "|  [4]\tKembali Ke Menu Utama                                   |" << endl;
                        cout << "=================================================================" << endl;
                        cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_update;
                        //proses update data
                        if (pilih_update == "1"){
                            //lakukan
                            do{
                                //coba
                                try {
                                    system("cls");
                                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Tanggal Pengeluaran Yang Baru " << endl;
                                    cout << "  hari  : " ; cin >> klr[j].hari;
                                    cout << "  Bulan : " ; cin >> klr[j].bulan;
                                    cout << "  Tahun : " ; cin >> klr[j].tahun;
                                }
                                //apabila input gagal 
                                catch (const ios_base::failure &) {
                                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                    //membersihkan kesalahan pada cin
                                    cin.clear();
                                    //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                    cin.ignore();
                                }
                            //perulangan while mencegah input kurang dari 0
                            } while (klr[j].hari <= 0 or klr[j].bulan <= 0 or klr[j].tahun <= 0);
                            break;
                        }else if (pilih_update == "2"){
                            //lakukan
                            do{
                                //coba
                                try {
                                    system("cls");
                                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Jumlah Pengeluaran Yang Baru : Rp" ; cin >> klr[j].uang;
                                }
                                //apabila input gagal 
                                catch (const ios_base::failure &) {
                                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                //membersihkan kesalahan pada cin
                                    cin.clear();
                                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                    cin.ignore();
                                }
                            //perulangan while mencegah input kurang dari 0
                            } while (klr[j].uang <= 0);
                            break;
                        }else if (pilih_update == "3"){
                            //lakukan
                            do{
                                //coba
                                try {
                                    system("cls");
                                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Tanggal Pengeluaran Yang Baru " << endl;
                                    cout << "  hari  : " ; cin >> klr[j].hari;
                                    cout << "  Bulan : " ; cin >> klr[j].bulan;
                                    cout << "  Tahun : " ; cin >> klr[j].tahun;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Jumlah Pengeluaran Yang Baru : Rp" ; cin >> klr[j].uang;
                                }
                                //apabila input gagal 
                                catch (const ios_base::failure &) {
                                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                //membersihkan kesalahan pada cin
                                    cin.clear();
                                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                    cin.ignore();
                                }
                            //perulangan while mencegah input kurang dari 0
                            } while (klr[j].hari <= 0 or klr[j].bulan <= 0 or klr[j].tahun <= 0 or klr[j].uang <= 0);
                            break;
                        }else if (pilih_update == "4"){
                            break;
                        }else{
                            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                            system("cls");
                        }
                    }
                    //menuli ulang data yang telah diubah
                    if (pilih_update != "4"){
                        replace_keluar(nama_warung);
                        cout << "   ~~~~~~~~~   Berhasil Mengubah Data Pengeluaran   ~~~~~~~~~~   " << endl;
                        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                    cari_tanggal = false;
                    break;
                }else if (j == 99 and klr[j].hari != hari and klr[j].bulan != bulan and klr[j].tahun != tahun){
                    //apabila data tidak ketemu, diberikan kesempatan untuk mencari kembali atau kembali ke menu utama
                    cout << "\n  Data Pengeluaran Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_tanggal = false;
                    }
                }
            }
        }
    }else{
        //apabila tidak ada data
        cout << "\n   ~~~~~~~~~~~~    Tidak Ada Data Pengeluaran    ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
}

//prosedur update_masuk untuk mengupdate data pemasukan
void update_masuk(string nama_warung){
    string pilih_update, back;
    int hari, bulan, tahun;
    bool cari_tanggal = true;
    //exception untuk error handling
    cin.exceptions(ios_base::failbit);
    //read file dan hitung jumlah data
    clear_masuk();
    read_masuk(nama_warung);
    hitung_masuk();
    if (banyak_masuk > 0){
        while (cari_tanggal){
            //lakukan
            do{
                //coba
                try {
                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Tanggal Pemasukan Yang Ingin Diubah " << endl;
                    cout << "  Hari  : " ; cin >> hari;
                    cout << "  Bulan : " ; cin >> bulan;
                    cout << "  Tahun : " ; cin >> tahun;
                }
                //apabila input gagal 
                catch (const ios_base::failure &) {
                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cout << "\n" << endl;
                //membersihkan kesalahan pada cin
                    cin.clear();
                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                    cin.ignore();
                }
            //perulangan while mencegah input kurang dari 0
            } while (hari <= 0 or bulan <= 0 or tahun <= 0);
            //mencari tanggal pada file
            for (int j = 0 ; j < panjang ; j++){
                if (msk[j].hari == hari and msk[j].bulan == bulan and msk[j].tahun == tahun){
                    //menampilkan data
                    system("cls");
                    cout << "---------------------------------"<<endl;
                    cout << "|    Tanggal\t| Pemasukan  \t|"<<endl;
                    cout << "---------------------------------"<<endl;
                    cout << "| " << msk[j].hari << "-" << msk[j].bulan << "-" << msk[j].tahun << "\t| Rp" << msk[j].uang << "\t|" << endl;
                    cout << "---------------------------------"<<endl;
                    while (true){
                        //menu ubah
                        cout << "=================================================================" << endl;
                        cout << "|                        Ingin Mengubah                         |" << endl;
                        cout << "|                                                               |" << endl;
                        cout << "|  [1]\tTanggal                                                 |" << endl;
                        cout << "|  [2]\tJumlah Pemasukan                                        |" << endl;
                        cout << "|  [3]\tSemua                                                   |" << endl;
                        cout << "|  [4]\tKembali Ke Menu Utama                                   |" << endl;
                        cout << "=================================================================" << endl;
                        cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_update;
                        //proses update
                        if (pilih_update == "1"){
                            //lakukan
                            do{
                                //coba
                                try {
                                    system("cls");
                                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Tanggal Pemasukan Yang Baru " << endl;
                                    cout << "  hari  : " ; cin >> msk[j].hari;
                                    cout << "  Bulan : " ; cin >> msk[j].bulan;
                                    cout << "  Tahun : " ; cin >> msk[j].tahun;
                                }
                                //apabila input gagal 
                                catch (const ios_base::failure &) {
                                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                //membersihkan kesalahan pada cin
                                    cin.clear();
                                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                    cin.ignore();
                                }
                            //perulangan while mencegah input kurang dari 0
                            } while (msk[j].hari <= 0 or msk[j].bulan <= 0 or msk[j].tahun <= 0);
                            break;
                        }else if (pilih_update == "2"){
                            //lakukan
                            do{
                                //coba
                                try {
                                    system("cls");
                                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Jumlah Pemasukan Yang Baru : Rp" ; cin >> msk[j].uang;
                                }
                                //apabila input gagal 
                                catch (const ios_base::failure &) {
                                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                //membersihkan kesalahan pada cin
                                    cin.clear();
                                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                    cin.ignore();
                                }
                            //perulangan while mencegah input kurang dari 0
                            } while (msk[j].uang <= 0);
                            break;
                        }else if (pilih_update == "3"){
                            //lakukan
                            do{
                                //coba
                                try {
                                    system("cls");
                                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Tanggal Pemasukan Yang Baru " << endl;
                                    cout << "  hari  : " ; cin >> msk[j].hari;
                                    cout << "  Bulan : " ; cin >> msk[j].bulan;
                                    cout << "  Tahun : " ; cin >> msk[j].tahun;
                                    cout << "=================================================================" << endl;
                                    cout << "  Masukkan Jumlah Pemasukan Yang Baru : Rp" ; cin >> msk[j].uang;
                                }
                                //apabila input gagal 
                                catch (const ios_base::failure &) {
                                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                                //membersihkan kesalahan pada cin
                                    cin.clear();
                                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                                    cin.ignore();
                                }
                            //perulangan while mencegah input kurang dari 0
                            } while (msk[j].hari <= 0 or msk[j].bulan <= 0 or msk[j].tahun <= 0 or msk[j].uang <= 0) ;
                            break;
                        }else if (pilih_update == "4"){
                            break;
                        }else{
                            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                            system("cls");
                        }
                    }
                    //menulis kembali data
                    if (pilih_update != "4"){
                        replace_masuk(nama_warung);
                        cout << "   ~~~~~~~~~~   Berhasil Mengubah Data Pemasukan   ~~~~~~~~~~~   " << endl;
                        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                    cari_tanggal = false;
                    break;
                }else if (j == 99 and msk[j].hari != hari and msk[j].bulan != bulan and msk[j].tahun != tahun){
                    //apabila data tidak ditemukan
                    cout << "\n  Data Pemasukan Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_tanggal = false;
                    }
                }
            }
        }
    }else{
        cout << "\n   ~~~~~~~~~~~~~    Tidak Ada Data Pemasukan    ~~~~~~~~~~~~~    " << endl;
    }
}

//prosedur update_warung untuk mengupdate data warung
void update_warung(){
    string nama_warung, pilih_update, back;
    bool cari_warung = true;
    //menghitung data warung
    clear_warung();
    read_warung();
    hitung_warung();
    if (banyak_warung > 0){
        while (cari_warung){
            //menampilkan data warung secara singkat untuk memudahkan pengguna mencari data warung
            display_warung_for();
            cout << "  Ingin Mengubah Data Pada Warung : " ; fflush(stdin) ; getline(cin, nama_warung);
            //mencari data warung
            for (int i = 0 ; i < panjang ; i++){
                if (warung[i].nama_warung == nama_warung){
                    cout << "=================================================================" << endl;
                    cout << "  Nama Warung      : " << warung[i].nama_warung << endl;
                    cout << "  Alamat Warung    : " << warung[i].alamat << endl;
                    cout << "  Username Manager : " << warung[i].username << endl;
                    cout << "  Password Manager : " << warung[i].password << endl;
                    while (true){
                        //menu ubah
                        cout << "\n=================================================================" << endl;
                        cout << "|                        Ingin Mengubah                         |" << endl;
                        cout << "|                                                               |" << endl;
                        cout << "|  [1]\tNama Warung                                             |" << endl;
                        cout << "|  [2]\tAlamat Warung                                           |" << endl;
                        cout << "|  [3]\tUsername Akun Manager Cabang                            |" << endl;
                        cout << "|  [4]\tPassword Akun Manager Cabang                            |" << endl;
                        cout << "|  [5]\tSemua                                                   |" << endl;
                        cout << "|  [6]\tKembali Ke Menu Utama                                   |" << endl;
                        cout << "=================================================================" << endl;
                        cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_update;
                        cout << "=================================================================" << endl;
                        if (pilih_update == "1"){
                            cout << "  Masukkan Nama Warung Yang Baru : " ; fflush(stdin) ;  getline (cin, warung[i].nama_warung);
                            break;
                        }else if (pilih_update == "2"){
                            cout << "  Masukkan Alamat Warung Yang Baru : " ; fflush(stdin) ;  getline (cin, warung[i].alamat);
                            break;
                        }else if (pilih_update == "3"){
                            cout << "  Masukkan Username Yang Baru : " ; fflush(stdin) ;  getline (cin, warung[i].username);
                            break;
                        }else if (pilih_update == "4"){
                            cout << "  Masukkan Password Yang Baru : " ; fflush(stdin) ;  getline (cin, warung[i].password);
                            break;
                        }else if (pilih_update == "5"){
                            cout << "  Masukkan Nama Warung Yang Baru   : " ; fflush(stdin) ;  getline (cin, warung[i].nama_warung);
                            cout << "  Masukkan Alamat Warung Yang Baru : " ; fflush(stdin) ;  getline (cin, warung[i].alamat);
                            cout << "  Masukkan Username Yang Baru      : " ; fflush(stdin) ;  getline (cin, warung[i].username);
                            cout << "  Masukkan Password Yang Baru      : " ; fflush(stdin) ;  getline (cin, warung[i].password);
                            break;
                        }else if (pilih_update == "6"){
                            break;
                        }else{
                            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                        }
                    }
                    //menulis kembali data
                    if (pilih_update != "6"){
                        replace_warung();
                        cout << "   ~~~~~~~~~~~~   Berhasil Mengubah Data Warung   ~~~~~~~~~~~~   " << endl;
                        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    }
                    cari_warung = false;
                    break;
                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                    //apabila data tidak ditemukan
                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_warung = false;
                    }
                }
            }
        }
    }else{
        cout << "\n   ~~~~~~~~~~~~   Tidak Ada Data Warung Cabang   ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
    system("cls");
}

//prosedur hapus_keluar untuk menghapus data pengeluaran
void hapus_keluar(string nama_warung){
    int hari, bulan, tahun;
    string konfirmasi, back;
    bool cari_tanggal = true;
    //exception untuk error handling
    cin.exceptions(ios_base::failbit);
    //read file dan hitung jumlah data
    clear_keluar();
    read_keluar(nama_warung);
    hitung_keluar();
    if (banyak_keluar > 0){
        while (cari_tanggal){
            //lakukan
            do{
                //coba
                try {
                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Tanggal Pengeluaran Yang Ingin Dihapus " << endl;
                    cout << "  Hari  : " ; cin >> hari;
                    cout << "  Bulan : " ; cin >> bulan;
                    cout << "  Tahun : " ; cin >> tahun;
                }
                //apabila input gagal 
                catch (const ios_base::failure &) {
                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cout << "\n" << endl;
                //membersihkan kesalahan pada cin
                    cin.clear();
                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                    cin.ignore();
                }
            //perulangan while mencegah input kurang dari 0
            } while (hari <= 0 or bulan <= 0 or tahun <= 0);
            //mencari tanggal pada data
            for (int j = 0 ; j < panjang ; j++){
                if (klr[j].hari == hari and klr[j].bulan == bulan and klr[j].tahun == tahun){
                    while (true){
                        //tampilkan data
                        system("cls");
                        cout << "---------------------------------"<<endl;
                        cout << "|    Tanggal\t| Pengeluaran\t|"<<endl;
                        cout << "---------------------------------"<<endl;
                        cout << "| " << klr[j].hari << "-" << klr[j].bulan << "-" << klr[j].tahun << "\t| Rp" << klr[j].uang << "\t|" << endl;
                        cout << "---------------------------------\n"<<endl;
                        //konfirmasi hapus data
                        cout << "\n  Yakin Ingin Menghapus Data Pengeluaran (Y/N) ? " ; cin >> konfirmasi;
                        if (konfirmasi == "y" or konfirmasi == "Y"){
                            klr[j].hari = 0;
                            klr[j].bulan = 0;
                            klr[j].tahun = 0;
                            klr[j].uang = 0;
                            //menulis kembali file
                            replace_keluar(nama_warung);
                            cout << "   ~~~~~~~~~~~~~~    Berhasil Menghapus Data    ~~~~~~~~~~~~~~   " << endl;
                            break;
                        }else if (konfirmasi == "n" or konfirmasi == "N"){
                            cout << "    ~~~~~~~~~~~~~~    Batal Menghapus Data    ~~~~~~~~~~~~~~~    " << endl;
                            break;
                        }else{
                            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                        }
                    }
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_tanggal = false;
                    break;
                }else if (j == 99 and klr[j].hari != hari and klr[j].bulan != bulan and klr[j].tahun != tahun){
                    //apabila data tidak ditemukan
                    cout << "\n  Data Pengeluaran Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_tanggal = false;
                    }
                }
            }
        }
    }else{
        cout << "   ~~~~~~~~~~~~    Tidak Ada Data Pengeluaran    ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
}

//prosedur hapus_masuk untuk menghapus data pemasukan
void hapus_masuk(string nama_warung){
    int hari, bulan, tahun;
    string konfirmasi, back;
    bool cari_tanggal = true;
    //exception untuk error handling
    cin.exceptions(ios_base::failbit);
    //read file dan hitung jumlah data
    clear_masuk();
    read_masuk(nama_warung);
    hitung_masuk();
    if (banyak_masuk > 0){
        while (cari_tanggal){
            //lakukan
            do{
                //coba
                try {
                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Tanggal Pemasukan Yang Ingin Dihapus " << endl;
                    cout << "  Hari  : " ; cin >> hari;
                    cout << "  Bulan : " ; cin >> bulan;
                    cout << "  Tahun : " ; cin >> tahun;
                }
                //apabila input gagal 
                catch (const ios_base::failure &) {
                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cout << "\n" << endl;
                //membersihkan kesalahan pada cin
                    cin.clear();
                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                    cin.ignore();
                }
            //perulangan while mencegah input kurang dari 0
            } while (hari <= 0 or bulan <= 0 or tahun <= 0);
            //mencari tanggal pada data
            for (int j = 0 ; j < panjang ; j++){
                if (msk[j].hari == hari and msk[j].bulan == bulan and msk[j].tahun == tahun){
                    while (true){
                        //menampilkan data
                        system("cls");
                        cout << "---------------------------------"<<endl;
                        cout << "|    Tanggal\t| Pengeluaran\t|"<<endl;
                        cout << "---------------------------------"<<endl;
                        cout << "| " << msk[j].hari << "-" << msk[j].bulan << "-" << msk[j].tahun << "\t| Rp" << msk[j].uang << "\t|" << endl;
                        cout << "---------------------------------\n"<<endl;
                        //konfirmasi hapus data
                        cout << "\n  Yakin Ingin Menghapus Data Pemasukan (Y/N) ? " ; cin >> konfirmasi;
                        if (konfirmasi == "y" or konfirmasi == "Y"){
                            msk[j].hari = 0;
                            msk[j].bulan = 0;
                            msk[j].tahun = 0;
                            msk[j].uang = 0;
                            //menulis ulang data
                            replace_masuk(nama_warung);
                            cout << "   ~~~~~~~~~~~~~~    Berhasil Menghapus Data    ~~~~~~~~~~~~~~   " << endl;
                            break;
                        }else if (konfirmasi == "n" or konfirmasi == "N"){
                            cout << "    ~~~~~~~~~~~~~~    Batal Menghapus Data    ~~~~~~~~~~~~~~~    " << endl;
                            break;
                        }else{
                            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                        }
                    }
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_tanggal = false;
                    break;
                }else if (j == 99 and msk[j].hari != hari and msk[j].bulan != bulan and msk[j].tahun != tahun){
                    //apabila data tidak ditemukan
                    cout << "\n  Data Pemasukan Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_tanggal = false;
                    }
                }
            }
        }
    }else{
        cout << "   ~~~~~~~~~~~~~    Tidak Ada Data Pemasukan    ~~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
}

//prosedur hapus_warung untuk menghapus data warung
void hapus_warung(){
    string nama_warung, konfirmasi, back;
    bool cari_warung = true;
    //membaca data warung
    clear_warung();
    read_warung();
    hitung_warung();
    if (banyak_warung > 0){
        while (cari_warung){
            cout << "  Ingin Menghapus Data Pada Warung : " ; fflush(stdin) ; getline(cin, nama_warung);
            //mencari data warung
            for (int i = 0 ; i < panjang ; i++){
                if (warung[i].nama_warung == nama_warung){
                    while (true){
                        //menampilkan data warung
                        cout << "=================================================================" << endl;
                        cout << "  Nama Warung      : " << warung[i].nama_warung << endl;
                        cout << "  Alamat Warung    : " << warung[i].alamat << endl;
                        cout << "  Username Manager : " << warung[i].username << endl;
                        cout << "  Password Manager : " << warung[i].password << endl;
                        cout << "=================================================================" << endl;
                        //konfirmasi hapus
                        cout << "\n  Yakin Ingin Menghapus Data Warung (Y/N) ? " ; cin >> konfirmasi;
                        if (konfirmasi == "Y" or konfirmasi == "y"){
                            warung[i].nama_warung = "";
                            warung[i].alamat = "";
                            warung[i].username = "";
                            warung[i].password = "";
                            //menulis ulang data
                            replace_warung();
                            cout << "   ~~~~~~~~~~~~   Berhasil Menghapus Data Warung   ~~~~~~~~~~~~   " << endl;
                            break;
                        }else if (konfirmasi == "n" or konfirmasi == "N"){
                            cout << "    ~~~~~~~~~~~~~~    Batal Menghapus Data    ~~~~~~~~~~~~~~~    " << endl;
                            break;
                        }else{
                            cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                        }
                    }
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_warung = false;
                    break;
                }else if (i == 99 and warung[i].nama_warung != nama_warung){
                    //apabila data tidak ditemukan
                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_warung = false;
                    }
                }
            }
        }
    }else{
        cout << "   ~~~~~~~~~~~~   Tidak Ada Data Warung Cabang   ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
    system("cls");
}

//prosedur search_keluar untuk searching data pengeluaran
void search_keluar(string nama_warung){
    //searching ini menggunakan metode squential search
    string back;
    //exception untuk error handling
    cin.exceptions(ios_base::failbit);
    //read file dan hitung jumlah data
    clear_keluar();
    read_keluar(nama_warung);
    hitung_keluar();
    int hari, bulan, tahun;
    bool cari_tanggal = true;
    if (banyak_keluar > 0){
        while (cari_tanggal){
            //lakukan
            do{
                //coba
                try {
                    system("cls");
                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Tanggal Pengeluaran Yang Ingin Dicari " << endl;
                    cout << "  Hari  : " ; cin >> hari;
                    cout << "  Bulan : " ; cin >> bulan;
                    cout << "  Tahun : " ; cin >> tahun;
                }
                //apabila input gagal 
                catch (const ios_base::failure &) {
                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cout << "\n" << endl;
                //membersihkan kesalahan pada cin
                    cin.clear();
                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                    cin.ignore();
                }
            //perulangan while mencegah input kurang dari 0
            } while (hari <= 0 or bulan <= 0 or tahun <= 0);
            //mencari tanggal pada data
            for (int i = 0 ; i < panjang ; i++){
                if (klr[i].hari == hari and klr[i].bulan == bulan and klr[i].tahun == tahun){
                    //tampilkan data
                    system("cls");
                    cout << "---------------------------------"<<endl;
                    cout << "|    Tanggal\t| Pengeluaran\t|"<<endl;
                    cout << "---------------------------------"<<endl;
                    cout << "| " << klr[i].hari << "-" << klr[i].bulan << "-" << klr[i].tahun << "\t| Rp" << klr[i].uang << "\t|" << endl;
                    cout << "---------------------------------"<<endl;
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_tanggal = false;
                    break;
                }else if (i == 99 and klr[i].hari != hari and klr[i].bulan != bulan and klr[i].tahun != tahun){
                    //apabila data tidak ditemukan
                    cout << "\n  Data Pengeluaran Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_tanggal = false;
                    }
                    break;
                }
            }
        }
    }else{
        cout << "   ~~~~~~~~~~~~    Tidak Ada Data Pengeluaran    ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
}

//prosedur search_masuk untuk searching data pemasukan
void search_masuk(string nama_warung){
    //searching ini menggunakan metode squential search
    //read file dan hitung jumlah data
    clear_masuk();
    read_masuk(nama_warung);
    hitung_masuk();
    //exception untuk error handling
    cin.exceptions(ios_base::failbit);
    int hari, bulan, tahun;
    string back;
    bool cari_tanggal = true;
    if (banyak_masuk > 0){
        while (cari_tanggal){
            //lakukan
            do{
                //coba
                try {
                    system("cls");
                    cout << "  Mohon Untuk Input Angka Mulai Dari 1 " << endl;
                    cout << "=================================================================" << endl;
                    cout << "  Masukkan Tanggal Pemasukan Yang Ingin Dicari " << endl;
                    cout << "  Hari  : " ; cin >> hari;
                    cout << "  Bulan : " ; cin >> bulan;
                    cout << "  Tahun : " ; cin >> tahun;
                }
                //apabila input gagal 
                catch (const ios_base::failure &) {
                    cout << "  Mohon Input Angka Mulai Dari 1, Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cout << "\n" << endl;
                //membersihkan kesalahan pada cin
                    cin.clear();
                //melompat ke baris baru berikutnya untuk mengabaikan hal lain pada baris yang sama sehingga tidak menyebabkan kegagalan lain
                    cin.ignore();
                }
            //perulangan while mencegah input kurang dari 0
            } while (hari <= 0 or bulan <= 0 or tahun <= 0);
            //mencari tanggal pada data
            for (int i = 0 ; i < panjang ; i++){
                if (msk[i].hari == hari and msk[i].bulan == bulan and msk[i].tahun == tahun){
                    //menampilkan data
                    system("cls");
                    cout << "---------------------------------"<<endl;
                    cout << "|    Tanggal\t| Pemasukan  \t|"<<endl;
                    cout << "---------------------------------"<<endl;
                    cout << "| " << msk[i].hari << "-" << msk[i].bulan << "-" << msk[i].tahun << "\t| Rp" << msk[i].uang << "\t|" << endl;
                    cout << "---------------------------------"<<endl;
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_tanggal = false;
                    break;
                }else if (i == 99 and msk[i].hari != hari and msk[i].bulan != bulan and msk[i].tahun != tahun){
                    //apabila data tidak ditemukan
                    cout << "\n  Data Pengeluaran Tidak Ditemukan, Masukkan 'B' Jika Ingin Kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "b" or back == "B"){
                        cari_tanggal = false;
                    }
                    break;
                }
            }
        }
    }else{
        cout << "   ~~~~~~~~~~~~~    Tidak Ada Data Pemasukan    ~~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
}

//prosedur search_warung untuk searching data warung
void search_warung(){
    //proses searching ini menggunakan metode binary search
    clear_warung();
    read_warung();
    //sorting data secara ascending sesuai dengan tanggal
    sort_warung(0, banyak_warung - 1);
    string nama_warung, back;
    bool cari_warung = true;
    if (banyak_warung > 0){
        while (cari_warung){
            cout << "  Masukkan Nama Warung Yang Ingin Dicari : " ; fflush(stdin) ; getline(cin, nama_warung);
            int awal = 0;
            int akhir = banyak_warung;
            int loop = 0;
            cout << akhir;
            while (true){
                //proses mencari data
                int tengah = (awal + akhir) / 2;
                if (warung[tengah].nama_warung == nama_warung){
                    cout << "=================================================================" << endl;
                    cout << "  Nama Warung      : " << warung[tengah].nama_warung << endl;
                    cout << "  Alamat Warung    : " << warung[tengah].alamat << endl;
                    cout << "  Username Manager : " << warung[tengah].username << endl;
                    cout << "  Password Manager : " << warung[tengah].password << endl;
                    cout << "=================================================================" << endl;
                    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
                    cari_warung = false;
                    break;
                }else if (warung[tengah].nama_warung < nama_warung){
                    awal = tengah + 1;
                }else if (warung[tengah].nama_warung > nama_warung){
                    akhir = tengah - 1;
                }
                //apabila jumlah loop melewati batas, maka data dianggap tidak ditemukan
                if (loop == 99 and warung[tengah].nama_warung != nama_warung){
                    cout << "\n  Data Warung Tidak Ditemukan, Masukkan 'B' Jika Ingin kembali Ke Menu Utama..." ; cin >> back;
                    if (back == "B" or back == "b"){
                        cari_warung = false;
                    }
                    break;
                }
                loop += 1;
            }
        }
    }else{
        //apabila tidak ada data
        cout << "   ~~~~~~~~~~~~   Tidak Ada Data Warung Cabang   ~~~~~~~~~~~~    " << endl;
        cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
    }
    system("cls");
}

//prosedur display_keluar_manager untuk menampilkan data pengeluaran pada menu manager
void display_keluar_manager(string nama_warung){
    string pilih_lihat, pilih_sort;
    if (banyak_keluar > 0){
        while (true){
            cout << "=================================================================" << endl;
            cout << "|                   Ingin Melihat Berdasarkan                   |" << endl;
            cout << "|                                                               |" << endl;
            cout << "|  [1]\tTanggal Pengeluaran                                     |" << endl;
            cout << "|  [2]\tJumlah Pengeluaran                                      |" << endl;
            cout << "=================================================================" << endl;
            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_lihat;
            //mencegah input diluar menu
            if (pilih_lihat == "1" or pilih_lihat == "2"){
                break;
            }else{
                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                system("cls");
            }
        }
        while (true){
            system("cls");
            cout << "=================================================================" << endl;
            cout << "|                     Ingin Sorting Secara                      |" << endl;
            cout << "|                                                               |" << endl;
            cout << "|  [1]\tAscending                                               |" << endl;
            cout << "|  [2]\tDescending                                              |" << endl;
            cout << "=================================================================" << endl;
            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_sort;
            //mencegah input diluar menu
            if (pilih_lihat == "1" or pilih_lihat == "2"){
                break;
            }else{
                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
            }
        }
        //sorting data sesuai keinginan user
        if (pilih_lihat == "1"){
            sort_tanggal_keluar(nama_warung, pilih_sort);
        }else{
            sort_saldo_keluar(nama_warung, pilih_sort);
        }
        //tampilkan data
        system("cls");
        cout << "---------------------------------"<<endl;
        cout << "|    Tanggal\t| Pengeluaran\t|"<<endl;
        cout << "---------------------------------"<<endl;
        for (int i = 0 ; i < panjang ; i++){
            if (klr[i].hari != 0){
                cout << "| " << klr[i].hari << "-" << klr[i].bulan << "-" << klr[i].tahun << "\t| Rp" << klr[i].uang << "\t|" << endl;
            }
        }
        cout << "---------------------------------"<<endl;
        cout << "| Total Pengeluaran Rp" << total_pengeluaran() << "\t|"<<endl;
        cout << "---------------------------------"<<endl;
    }else{
        //apabila tidak ada data
        cout << "\n   ~~~~~~~~~~~~    Tidak Ada Data Pengeluaran    ~~~~~~~~~~~~    " << endl;
    }
    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
}

//prosedur display_masuk_manager untuk menampilkan data pemasukan pada menu manager
void display_masuk_manager(string nama_warung){
    string pilih_lihat, pilih_sort;
    if (banyak_masuk > 0){
        while (true){
            cout << "=================================================================" << endl;
            cout << "|                   Ingin Melihat Berdasarkan                   |" << endl;
            cout << "|                                                               |" << endl;
            cout << "|  [1]\tTanggal Pemasukan                                       |" << endl;
            cout << "|  [2]\tJumlah Pemasukan                                        |" << endl;
            cout << "=================================================================" << endl;
            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_lihat;
            //mencegah input diluar menu
            if (pilih_lihat == "1" or pilih_lihat == "2"){
                break;
            }else{
                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
                system("cls");
            }
        }
        while (true){
            system("cls");
            cout << "=================================================================" << endl;
            cout << "|                     Ingin Sorting Secara                      |" << endl;
            cout << "|                                                               |" << endl;
            cout << "|  [1]\tAscending                                               |" << endl;
            cout << "|  [2]\tDescending                                              |" << endl;
            cout << "=================================================================" << endl;
            cout << "  Masukkan Pilihan Menu >> " ; cin >> pilih_sort;
            //mencegah input diluar menu
            if (pilih_lihat == "1" or pilih_lihat == "2"){
                break;
            }else{
                cout << "\n  Pilihan Menu Tidak Ditemukan, Tekan ENTER Untuk Melanjutkan..." ; getch();
            }
        }
        //sorting data sesuai dengan keinginan pengguna
        if (pilih_lihat == "1"){
            sort_tanggal_masuk(nama_warung, pilih_sort);
        }else{
            sort_saldo_masuk(nama_warung, pilih_sort);
        }
        //tampilkan data
        system("cls");
        cout << "---------------------------------"<<endl;
        cout << "|    Tanggal\t| Pemasukan  \t|"<<endl;
        cout << "---------------------------------"<<endl;
        for (int i = 0 ; i < panjang ; i++){
            if (msk[i].hari != 0){
                cout << "| " << msk[i].hari << "-" << msk[i].bulan << "-" << msk[i].tahun << "\t| Rp" << msk[i].uang << "\t|" << endl;
            }
        }
        cout << "---------------------------------"<<endl;
        cout << "| Total Pemasukan Rp" << total_pemasukan() << "\t|"<<endl;
        cout << "---------------------------------"<<endl;
    }else{
        //apabila data tidak ada
        cout << "\n   ~~~~~~~~~~~~~    Tidak Ada Data Pemasukan    ~~~~~~~~~~~~~~   " << endl;
    }
    cout << "\n  Tekan ENTER Untuk Melanjutkan..." ; getch();
}

//prosedur display_saldo_manager untuk menampilkan data saldo pada manager
void display_saldo_manager(string nama_warung, string alamat){
    int saldo;
    cout << "=================================" << endl;
    cout << "|\t" << nama_warung << "\t\t|" << endl;
    cout << "=================================" << endl;
    cout << "|\t" << alamat << "\t|" << endl;
    //menghitung total pengeluaran dan pemasukan
    total_pemasukan();
    total_pengeluaran();
    //tampilkan data pengeluaran, pemasukan, beserta saldonya
    if (banyak_keluar > 0 and banyak_masuk > 0){
        cout << "=================================" << endl;
        cout << "| Pengeluaran\t| Rp" << sum_keluar << "\t|" << endl;
        cout << "| Pemasukan\t| Rp" << sum_masuk << "\t|" << endl;
        cout << "=================================" << endl;
        saldo = sum_masuk - sum_keluar;
        cout << "| Total Saldo\t| Rp" << saldo << "\t|" << endl;
        cout << "=================================\n" << endl;
    }else if (banyak_keluar > 0 and banyak_masuk <= 0) {
        cout << "=================================" << endl;
        cout << "| Pengeluaran\t| Rp" << sum_keluar << "\t|" << endl;
        cout << "| Pemasukan\t| Rp0\t\t|" << endl;
        cout << "=================================" << endl;
        saldo = 0 - sum_keluar;
        cout << "| Total Saldo\t| Rp" << saldo << "\t|" << endl;
        cout << "=================================\n" << endl;
    }else if (banyak_keluar <= 0 and banyak_masuk > 0){
        cout << "=================================" << endl;
        cout << "| Pengeluaran\t| Rp0\t\t|" << endl;
        cout << "| Pemasukan\t| Rp" << sum_masuk << "\t|" << endl;
        cout << "=================================" << endl;
        saldo = sum_masuk;
        cout << "| Total Saldo\t| Rp" << saldo << "\t|" << endl;
        cout << "=================================\n" << endl;
    }else{
        cout << "=================================" << endl;
        cout << "| Pengeluaran\t| Rp0\t\t|" << endl;
        cout << "| Pemasukan\t| Rp0\t\t|" << endl;
        cout << "=================================" << endl;
        cout << "| Total Saldo\t| Rp0\t\t|" << endl;
        cout << "=================================\n" << endl;
    }
    cout << "  Tekan ENTER Untuk Melanjutkan..." ; getch();
}

//prosedur display_warung_for untuk menampilkan data nama warung dan alamat
void display_warung_for(){
    //prosedur ini berfungsi untuk menampilkan nama dan alamat warung saat ingin mencari data warung, mengupdate, dan hapus data
    system("cls");
    //sorting data warung berdsarkan nama
    sort_warung(0, banyak_warung - 1);
    cout << "=================================================================" << endl;
    for (int i = 0 ; i < panjang ; i++){
        if (warung[i].nama_warung != ""){
            cout << "   Nama Warung   : " << warung[i].nama_warung << endl;
            cout << "   Alamat Warung : " << warung[i].alamat << endl;
            cout << "=================================================================" << endl;
        }
    }
    cout << "\n";
}

//prosedur display_keluar_for untuk menampilkan pengeluaran saat ingin mengedit dan hapus
void display_keluar_for(string nama_warung){
    //prosedur ini berfungsi untuk menampilkan tanggal dan pengeluaran warung saat ingin mencari, mengupdate, dan hapus data
    //sorting tanggal pengeluaran secara ascending
    sort_tanggal_keluar(nama_warung, "1");
    hitung_keluar();
    if (banyak_keluar > 0){
        //tampilkan data
        system("cls");
        cout << "---------------------------------"<<endl;
        cout << "|    Tanggal\t| Pengeluaran\t|"<<endl;
        cout << "---------------------------------"<<endl;
        for (int i = 0 ; i < panjang ; i++){
            if (klr[i].hari != 0){
                cout << "| " << klr[i].hari << "-" << klr[i].bulan << "-" << klr[i].tahun << "\t| Rp" << klr[i].uang << "\t|" << endl;
            }
        }
        cout << "---------------------------------\n"<<endl;
    }
}

//prosedur display_masuk_for untuk menampilkan pemasukan saat ingin mengedit dan hapus
void display_masuk_for(string nama_warung){
    //prosedur ini berfungsi untuk menampilkan tanggal dan pemasukan warung saat ingin mencari, mengupdate, dan hapus data
    //sorting tanggal pemasukan secara ascending
    sort_tanggal_masuk(nama_warung, "1");
    hitung_masuk();
    if (banyak_masuk > 0){
        //tampilkan data
        system("cls");
        cout << "---------------------------------"<<endl;
        cout << "|    Tanggal\t| Pemasukan  \t|"<<endl;
        cout << "---------------------------------"<<endl;
        for (int i = 0 ; i < panjang ; i++){
            if (msk[i].hari != 0){
                cout << "| " << msk[i].hari << "-" << msk[i].bulan << "-" << msk[i].tahun << "\t| Rp" << msk[i].uang << "\t|" << endl;
            }
        }
        cout << "---------------------------------\n"<<endl;
    }
}