#include <iostream>
#include <stack>
#include <queue>
#include <string>

// CRUDStack : Untuk Stack
// CRUDQueue : Untuk Queue

using namespace std;
string loop;

template <typename T>
class CRUDStack {
private:
    stack<T> dataStack;

public:
    void create(const T& value) {
        dataStack.push(value);
        cout << "Data \"" << value << "\" berhasil ditambahkan ke Stack." << endl;
    }

    void read() {
        if (dataStack.empty()) {
            cout << "Stack kosong." << endl;
            return;
        }
        
        stack<T> tempStack = dataStack;
        cout << "Data dalam Stack: ";
        while (!tempStack.empty()) {
            cout << "\"" << tempStack.top() << "\" ";
            tempStack.pop();
        }
        cout << endl;
    }

    void update(const T& oldValue, const T& newValue) {
        stack<T> tempStack;
        bool found = false;

        while (!dataStack.empty()) {
            if (dataStack.top() == oldValue) {
                tempStack.push(newValue);
                found = true;
            } else {
                tempStack.push(dataStack.top());
            }
            dataStack.pop();
        }

        while (!tempStack.empty()) {
            dataStack.push(tempStack.top());
            tempStack.pop();
        }

        if (found) {
            cout << "Data \"" << oldValue << "\" berhasil diperbarui menjadi \"" << newValue << "\" di Stack." << endl;
        } else {
            cout << "Data \"" << oldValue << "\" tidak ditemukan di Stack." << endl;
        }
    }

    void deleteData(const T& value) {
        stack<T> tempStack;
        bool found = false;

        while (!dataStack.empty()) {
            if (dataStack.top() == value && !found) {
                found = true;
            } else {
                tempStack.push(dataStack.top());
            }
            dataStack.pop();
        }

        while (!tempStack.empty()) {
            dataStack.push(tempStack.top());
            tempStack.pop();
        }

        if (found) {
            cout << "Data \"" << value << "\" berhasil dihapus dari Stack." << endl;
        } else {
            cout << "Data \"" << value << "\" tidak ditemukan di Stack." << endl;
        }
    }
};

template <typename T>
class CRUDQueue {
private:
    queue<T> dataQueue;

public:
    void create(const T& value) {
        dataQueue.push(value);
        cout << "Data " << value << "\" berhasil ditambahkan ke Queue." << endl;
    }

    void read() {
        if (dataQueue.empty()) {
            cout << "Queue kosong." << endl;
            return;
        }

        queue<T> tempQueue = dataQueue;
        cout << "Data dalam Queue: ";
        while (!tempQueue.empty()) {
            cout << " " << tempQueue.front() << "\" ";
            tempQueue.pop();
        }
        cout << endl;
    }

    void update(const T& oldValue, const T& newValue) {
        queue<T> tempQueue;
        bool found = false;

        while (!dataQueue.empty()) {
            if (dataQueue.front() == oldValue) {
                tempQueue.push(newValue);
                found = true;
            } else {
                tempQueue.push(dataQueue.front());
            }
            dataQueue.pop();
        }

        dataQueue = tempQueue;

        if (found) {
            cout << "Data \"" << oldValue << "\" berhasil diperbarui menjadi \"" << newValue << "\" di Queue." << endl;
        } else {
            cout << "Data \"" << oldValue << "\" tidak ditemukan di Queue." << endl;
        }
    }

    void deleteData(const T& value) {
        queue<T> tempQueue;
        bool found = false;

        while (!dataQueue.empty()) {
            if (dataQueue.front() == value && !found) {
                found = true;
            } else {
                tempQueue.push(dataQueue.front());
            }
            dataQueue.pop();
        }

        dataQueue = tempQueue;

        if (found) {
            cout << "Data \"" << value << "\" berhasil dihapus dari Queue." << endl;
        } else {
            cout << "Data \"" << value << "\" tidak ditemukan di Queue." << endl;
        }
    }
};

int main() {
    CRUDStack<string> stringStack;
    CRUDStack<int> intStack;
    CRUDQueue<string> stringQueue;
    CRUDQueue<int> intQueue;

    int pilihan, tipe;
    string strValue, oldStrValue, newStrValue;
    int intValue, oldIntValue, newIntValue;

    while (true) {
    	system("cls")
    	;cout << " " << endl;
    	cout << "============================================= " << endl;
		cout << "||      Menu CRUD untuk Stack dan Queue    || " << endl;
		cout << "============================================= " << endl;
        cout << "1. Stack String                               " << endl;
        cout << "2. Stack Integer                              " << endl;
        cout << "3. Queue String                               " << endl;
        cout << "4. Queue Integer                              " << endl;
        cout << "============================================= " << endl;
        cout << "5. Keluar" << endl;
        cout << "============================================= " << endl;
        cout << "Pilih tipe struktur data: ";
        cin >> tipe;
        cin.ignore();
		
		// keluar program
        if (tipe == 5) {
            cout << "Keluar dari program" << endl;
            break;
        }

		system("cls");
        cout << " " << endl;
    	cout << "============================================= " << endl;
		cout << "||               Operasi Menu              || " << endl;
		cout << "============================================= " << endl;
        cout << "1. Tambah data                                " << endl;
        cout << "2. Tampilkan data                             " << endl;
        cout << "3. Perbarui data                              " << endl;
        cout << "4. Hapus data                                 " << endl;
    	cout << "============================================= " << endl;
        cout << "Pilih Operasi Data: ";
        cin >> pilihan;
        cin.ignore();

        switch (tipe) {
        	case 1:
        		system("cls");
	        	if (pilihan == 1) {
	        		do {
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tambahkan Data             || " << endl;
						cout << "============================================= " << endl;
	                	cout << "Masukkan string: ";
	                	getline(cin, strValue);
	                	stringStack.create(strValue);
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");		
	            } else if (pilihan == 2) {
	            	system("cls");
	            	do {
	            		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tampilkan Data             || " << endl;
						cout << "============================================= " << endl;
	                	stringStack.read();
	                	cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y")
	            ;} else if (pilihan == 3) {
	            	system("cls");
	            	do {
	            		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||               Ubahkan Data              || " << endl;
						cout << "============================================= " << endl;
	                	cout << "Masukkan string lama : ";
	                	getline(cin, oldStrValue);
	                	cout << "Masukkan string baru : ";
	                	getline(cin, newStrValue);
	                	stringStack.update(oldStrValue, newStrValue);
	                	cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y")
	            ;} else if (pilihan == 4) {
	            	system("cls");
	                cout << " " << endl;
					cout << "============================================= " << endl;
					cout << "||               Hapuskan Data             || " << endl;
					cout << "============================================= " << endl;
	                cout << "Masukkan string untuk dihapus: ";
	                getline(cin, strValue);
	                stringStack.deleteData(strValue);
	                cout << " " << endl;
					cout << "============================================= " << endl;
					cout << "||          Kembali ke Menu Utama          || " << endl;
					cout << "============================================= " << endl;
					cout << "Kembali (Y) : ";
					cin >> loop;
	            } while (loop != "Y");
                break;
                
            case 2:
                if (pilihan == 1) {
                	do {
                		system("cls");
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tambahkan Data             || " << endl;
						cout << "============================================= " << endl;
	                	cout << "Masukkan string : ";
	                	cin >> intValue;
                    	intStack.create(intValue);
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");		
                } else if (pilihan == 2) {
                	system("cls");
                	do {
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tampilkan Data             || " << endl;
						cout << "============================================= " << endl;
                    	intStack.read();
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");		
                } else if (pilihan == 3) {
                	system("cls");
                	do {
	                	cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||               Ubahkan Data              || " << endl;
						cout << "============================================= " << endl;
	                    cout << "Masukkan Harga lama : ";
	                    cin >> oldIntValue;
	                    cout << "Masukkan Harga baru : ";
	                    cin >> newIntValue;
	                    intStack.update(oldIntValue, newIntValue);
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");		
                } else if (pilihan == 4) {
                	system("cls");
                	do {
                		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||               Ubahkan Data              || " << endl;
						cout << "============================================= " << endl;
                    	cout << "Masukkan Harga untuk dihapus: ";
                    	cin >> intValue;
                    	intStack.deleteData(intValue);
                    	cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                }
                break;
            case 3:
                if (pilihan == 1) {
                	system("cls");
                	do {
	                	cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tambahkan Data             || " << endl;
						cout << "============================================= " << endl;
	                    cout << "Masukkan string: ";
	                    getline(cin, strValue);
	                    stringQueue.create(strValue);
	                	cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                } else if (pilihan == 2) {
                	system("cls");
                	do {
                		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tampilkan Data             || " << endl;
						cout << "============================================= " << endl;
	                    stringQueue.read();
	                    cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                } else if (pilihan == 3) {
                	system("cls");
                	do {
                		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||               Ubahkan Data              || " << endl;
						cout << "============================================= " << endl;
	                    cout << "Masukkan string lama: ";
	                    getline(cin, oldStrValue);
	                    cout << "Masukkan string baru: ";
	                    getline(cin, newStrValue);
	                    stringQueue.update(oldStrValue, newStrValue);
	                    cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                } else if (pilihan == 4) {
                	system("cls");
                	do {
                		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||               Hapuskan Data             || " << endl;
						cout << "============================================= " << endl;
	                    cout << "Masukkan string untuk dihapus: ";
	                    getline(cin, strValue);
	                    stringQueue.deleteData(strValue);
	                    cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
				}
                break;
            case 4:
                if (pilihan == 1) {
                	system("cls");
	        		do {
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tambahkan Data             || " << endl;
						cout << "============================================= " << endl;
	                	cout << "Masukkan Harga : ";
	                    cin >> intValue;
	                    intQueue.create(intValue);
						cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                } else if (pilihan == 2) {
                	system("cls");
                	do {
                		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||              Tampilkan Data             || " << endl;
						cout << "============================================= " << endl;
                    	intQueue.read();
	                    cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                } else if (pilihan == 3) {
                	system("cls");
                	do {
                		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||               Ubahkan Data              || " << endl;
						cout << "============================================= " << endl;
	                    cout << "Masukkan Harga lama : ";
	                    cin >> oldIntValue;
	                    cout << "Masukkan Harga baru : ";
	                    cin >> newIntValue;
	                    intQueue.update(oldIntValue, newIntValue);
		                cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                } else if (pilihan == 4) {
                	system("cls");
                	do {
                		cout << " " << endl;
						cout << "============================================= " << endl;
						cout << "||               Hapuskan Data             || " << endl;
						cout << "============================================= " << endl;
	                    cout << "Masukkan Harga untuk dihapus : ";
	                    cin >> intValue;
	                    intQueue.deleteData(intValue);
						cout << "============================================= " << endl;
						cout << "||          Kembali ke Menu Utama          || " << endl;
						cout << "============================================= " << endl;
						cout << "Kembali (Y) : ";
						cin >> loop;
					} while (loop != "Y");
                }
                break;
            default:
                cout << "Maaf, Tipe tidak valid." << endl;
        }
    }

    return 0;
}
