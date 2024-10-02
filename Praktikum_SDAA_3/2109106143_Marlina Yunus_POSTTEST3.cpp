#include <iostream>
using namespace std;

// system(cls) : untuk menutup pembukaan yang dilakukan

#define max 10
string barangan[max], loop;
int pos = 0;

// memanggil struct
void struct_data() {
	system("cls");
	
	struct Original {
        string name;
        string located;
        int since;
        int until;
    };

    struct Customer {
    	string name;
        int usia;
        int membeli;
        int score;
        
		// penambahan pointer dari struct lainnya
        Original *from_ori;
    };
    
    Customer player_cust;
    
    // pengisian data nama
    cout << " " << endl;
    cout << "============================================= " << endl;
	cout << "||              Pengisian Data             || " << endl;
	cout << "============================================= " << endl;
    cout << "Nama Pembeli    : "; cin >> player_cust.name;
    cout << "Usia            : "; cin >> player_cust.usia;
    cout << "Pembelian Sejak : "; cin >> player_cust.membeli;
    cout << "Penilaian       : "; cin >> player_cust.score;
    cout << "============================================= " << endl;
	;player_cust.from_ori= new Original;
	
	(*player_cust.from_ori).name = "PT UNMUL INFORMATIKA JAYA";
    (*player_cust.from_ori).located = "Samarinda";
    (*player_cust.from_ori).since = 1990;
    (*player_cust.from_ori).until = 2024;


    // cetak status struct
    cout << " " << endl;
    cout << "============================================= " << endl;
	cout << "||              Pencetakan Data            || " << endl;
	cout << "============================================= " << endl;
    cout << "Nama Pembeli    : " << player_cust.name << endl;
    cout << "Usia            : " << player_cust.usia << endl;
    cout << "Pembelian Sejak : " << player_cust.membeli << endl;
    cout << "Penilaian       : " << player_cust.score << endl;
    cout << "============================================= " << endl;
    
    cout << " " << endl;
    cout << "============================================= " << endl;
	cout << "||           Pencetakan Data Lokasi        || " << endl;
	cout << "============================================= " << endl;
    cout << "Nama Lokasi     : " << (*player_cust.from_ori).name << endl;
    cout << "Lokasi          : " << (*player_cust.from_ori).located << endl;
    cout << "Sejak           : " << (*player_cust.from_ori).since << endl;
    cout << "Sehingga        : " << (*player_cust.from_ori).until << endl;
    cout << "============================================= " << endl;
}

// memanggil DISPLAY
void display_tampil() {
	system("cls");
	
	if (pos > 0) {
		cout << " " << endl;
		cout << "============================================= " << endl;
		cout << "||              Data Tersimpan             || " << endl;
		cout << "============================================= " << endl;
		cout << " " << endl;
		
		for (int i = 0; i < pos; i++) {
			cout << i + 1 << ". " << barangan[i] << endl;
		}
	} else {
		cout << " " << endl;
		cout << "============================================= " << endl;
		cout << "||               Data Kosong               || " << endl;
		cout << "============================================= " << endl;
		cout << "Data Masih Kosong" << endl;
		cout << " " << endl;
	}
}

// memanggil EDIT
void edit_ubah() {
	int y;
	system("cls");
	do {
		display_tampil();
		cout << " " << endl;
		cout << "============================================= " << endl;
		cout << "||           Sebelum Ubahkan Data          || " << endl;
		cout << "============================================= " << endl;
		cout << "Ubahkan data ke : ";
		cin >> y;
		cin.ignore();
		
		cout << " " << endl;
		cout << "============================================= " << endl;
		cout << "||           Setelah Ubahkan Data          || " << endl;
		cout << "============================================= " << endl;
		cout << "Ubahkan menjadi : ";
		getline(cin, barangan[y-1])
		;display_tampil();
		
		cout << " " << endl;
		cout << "============================================= " << endl;
		cout << "||          Kembali ke Menu Utama          || " << endl;
		cout << "============================================= " << endl;
		cout << "Ubahkan Kembali (Y/N) : ";
		cin >> loop;
	} while (loop == "Y");
}


// memanggil ADD
void add_tambah() {
	system("cls");
	do {
		display_tampil();
		if (pos < max) {
			cin.ignore();
			cout << " " << endl;
			cout << "============================================= " << endl;
			cout << "||         Tambahkan Data Barangan         || " << endl;
			cout << "============================================= " << endl;
			cout << "Tambahkan Data : ";
			getline(cin, barangan[pos]);
			pos++;
			display_tampil();
			
			cout << " " << endl;
			cout << "============================================= " << endl;
			cout << "||       Pengulangan Untuk Awal Loop       || " << endl;
			cout << "============================================= " << endl;
			cout << "Apakah ingin diulangi? [Y/N] : ";
			cin >> loop;
		} else {
			cout << " " << endl;
			cout << "============================================= " << endl;
			cout << "||        Sudah mencapai batasannya        || " << endl;
			cout << "============================================= " << endl;
			
			cout << " " << endl;
			cout << "============================================= " << endl;
			cout << "||           Kembali ke Menu Awal          || " << endl;
			cout << "============================================= " << endl;
			cout << "Tekan [Y] untuk kembali : " << endl;
			cin >> loop;
			
		}
	} while (loop == "Y");
}

// memanggil DELETE
void delete_hapus() {
	int x;
	system("cls");
	do {
		display_tampil();
		if(pos > 0) {
			cout << " " << endl;
			cout << "============================================= " << endl;
			cout << "||          Hapuskan Data Barangan         || " << endl;
			cout << "============================================= " << endl;
			cout << "Hapus data ke : ";
			cin >> x;
			for (int b = x; b < pos; b++) {
				barangan[b-1] = barangan[b];
			}
			pos--;
			display_tampil();
			cout << " " << endl;
			cout << "============================================= " << endl;
			cout << "||       Apakah kamu ingin Hapus Lagi      || " << endl;
			cout << "============================================= " << endl;
			cout << "Apakah kamu ingin hapus lagi? [Y/N] : ";
			cin >> loop;
		} else {
			cout << " " << endl;
			cout << "============================================= " << endl;
			cout << "||          Kembali ke Menu Utama          || " << endl;
			cout << "============================================= " << endl;
			cout << "Isikan [T] untuk Tidak : ";
			cin >> loop;
		}
	} while(loop == "Y");
}

int main() {
	int pilSwitch;
	
	do {
		// membuat daftar menu
		system("cls");
		cout << " " << endl;
		cout << "============================================= " << endl;
		cout << "||              Program Saya               || " << endl;
		cout << "============================================= " << endl;
		cout << "1. Tambahkan Data                             " << endl;
		cout << "2. Tampilkan Data                             " << endl;
		cout << "3. Ubahkan Data                               " << endl;
		cout << "4. Hapuskan Data                              " << endl;
		cout << "============================================= " << endl;
		cout << "5. Struct                                     " << endl;
		cout << "6. Selesai dan Keluar                         " << endl;
		cout << "============================================= " << endl;
		cout << "Pilih Angka 1 - 6 : ";
		cin >> pilSwitch;
	
		// membuat pilihan menu dengan Switch
		switch(pilSwitch) {
			case 1:
				system("cls");
				do {
					add_tambah();
					cout << " " << endl;
					cout << "============================================= " << endl;
					cout << "||          Kembali ke Menu Utama          || " << endl;
					cout << "============================================= " << endl;
					cout << "Kembali (Y) : ";
					cin >> loop;
				} while (loop != "Y");
				break;
			case 2:
				do {
					display_tampil();
					cout << " " << endl;
					cout << "============================================= " << endl;
					cout << "||          Kembali ke Menu Utama          || " << endl;
					cout << "============================================= " << endl;
					cout << "Kembali (Y) : ";
					cin >> loop;
				} while (loop != "Y");
				break;
			case 3:
				do {
					edit_ubah();
					cout << " " << endl;
					cout << "============================================= " << endl;
					cout << "||          Kembali ke Menu Utama          || " << endl;
					cout << "============================================= " << endl;
					cout << "Kembali (Y) : ";
					cin >> loop;
				} while (loop != "Y");
				break;
			case 4:
				do {
					delete_hapus();
					cout << " " << endl;
					cout << "============================================= " << endl;
					cout << "||          Kembali ke Menu Utama          || " << endl;
					cout << "============================================= " << endl;
					cout << "Kembali (Y) : ";
					cin >> loop;
				} while (loop != "Y");
				break;
			case 5:
				do {
					
					struct_data();
					cout << " " << endl;
					cout << "============================================= " << endl;
					cout << "||          Kembali ke Menu Utama          || " << endl;
					cout << "============================================= " << endl;
					cout << "Kembali (Y) : ";
					cin >> loop;
				} while (loop != "Y");
				break;
			case 6:
				cout << " " << endl;
				cout << "..." << endl;
				cout << " " << endl;
				break;
			default:
				cout << " " << endl;
				cout << "Pilihan antara angka 1 sampai 6" << endl;
				cout << " " << endl;
				break;
		}
	} while (pilSwitch != 6);
	
	cout << "Program Selesai" << endl;
}
