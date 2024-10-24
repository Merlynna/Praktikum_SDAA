#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
string loop;

struct Node {
    string data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    
    // Merge Sort dengan opsi ascending atau descending
    void mergeSort(bool ascending = true) {
        int size = getSize();
        string* arr = toArray();
        mergeSortArray(arr, 0, size - 1, ascending);
        fromArray(arr, size);
        delete[] arr;

        if (ascending) {
            cout << "List telah diurutkan secara ascending menggunakan Merge Sort.\n";
        } else {
            cout << "List telah diurutkan secara descending menggunakan Merge Sort.\n";
        }
    }

    void mergeSortArray(string* arr, int left, int right, bool ascending) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortArray(arr, left, mid, ascending);
            mergeSortArray(arr, mid + 1, right, ascending);
            merge(arr, left, mid, right, ascending);
        }
    }

    void merge(string* arr, int left, int mid, int right, bool ascending) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        string* L = new string[n1];
        string* R = new string[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j])) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }
    
    void createNode(string value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Data " << value << " ditambahkan.\n";
    }

    // Fungsi untuk menampilkan data dalam linked list
    void display() {
        if (!head) {
            cout << "List kosong";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Fungsi untuk mencari node dalam linked list
    Node* searchNode(string value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Fungsi untuk mengubah data dalam linked list
    void updateNode(string oldValue, string newValue) {
        Node* node = searchNode(oldValue);
        if (node) {
            node->data = newValue;
            cout << "Data " << oldValue << " diubah menjadi " << newValue << ".\n";
        } else {
            cout << "Data " << oldValue << " tidak ditemukan.\n";
        }
    }

    // Fungsi untuk menghapus data dari linked list
    void deleteNode(string value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Data " << value << " dihapus.\n";
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << "Data " << value << " dihapus.\n";
        } else {
            cout << "Data " << value << " tidak ditemukan.\n";
        }
    }

    // Helper untuk mendapatkan ukuran linked list
    int getSize() {
        int size = 0;
        Node* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    // Konversi linked list ke array untuk sorting
    string* toArray() {
        int size = getSize();
        string* arr = new string[size];
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }
        return arr;
    }

    // Konversi array kembali ke linked list setelah sorting
    void fromArray(string* arr, int size) {
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            temp->data = arr[i];
            temp = temp->next;
        }
    }

    // Quick Sort dengan opsi ascending atau descending
    void quickSort(bool ascending = true) {
        int size = getSize();
        string* arr = toArray();
        quickSortArray(arr, 0, size - 1, ascending);
        fromArray(arr, size);
        delete[] arr;

        if (ascending) {
            cout << "List telah diurutkan secara ascending menggunakan Quick Sort.\n";
        } else {
            cout << "List telah diurutkan secara descending menggunakan Quick Sort.\n";
        }
    }

    void quickSortArray(string* arr, int low, int high, bool ascending) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high, ascending);
            quickSortArray(arr, low, pivotIndex - 1, ascending);
            quickSortArray(arr, pivotIndex + 1, high, ascending);
        }
    }

    int partition(string* arr, int low, int high, bool ascending) {
        string pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if ((ascending && arr[j] <= pivot) || (!ascending && arr[j] >= pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

// Class for managing Linked List (String data)
class LinkedListSearch {
    Node* head;

public:
    LinkedListSearch() : head(nullptr) {}

    // Insert a new string into the linked list
    void insert(string value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Display all elements in the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Boyer-Moore Search for string
    int boyerMooreSearch(string pattern) {
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) {
            if (boyerMoore(temp->data, pattern)) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1; // Not found
    }

    // Boyer-Moore Search Algorithm
    bool boyerMoore(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        vector<int> badChar(256, -1);

        // Preprocess the pattern
        for (int i = 0; i < m; i++) {
            badChar[(int)pattern[i]] = i;
        }

        int s = 0; // s is shift of the pattern with respect to text
        while (s <= (n - m)) {
            int j = m - 1;

            // Keep reducing index j of pattern while characters of pattern and text are matching
            while (j >= 0 && pattern[j] == text[s + j]) {
                j--;
            }

            // If the pattern is present at the current shift, return true
            if (j < 0) {
                return true;
            } else {
                s += max(1, j - badChar[text[s + j]]);
            }
        }

        return false;
    }
};

// Fibonacci Search for integers
int fibonacciSearch(int arr[], int x, int n) {
    int fibMMm2 = 0;   // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if (fibMMm1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    return -1;  // Element not found
}

// Jump Search for integers
int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

int main() {
    LinkedList list;
    LinkedListSearch listsearch;
	int pilihan;
	string data;
	string pattern;
	string newData;
    bool ascending;
    
    // Integer data
    int intArr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(intArr) / sizeof(intArr[0]);
    
    // Linked list of strings
    listsearch.insert("Brush");
    listsearch.insert("Mascara");
    listsearch.insert("Lipstick");
    listsearch.insert("Eyeliner");

    while (true) {
    	system("cls");
    	cout << " " << endl;
		cout << "====================================================== " << endl;
		cout << "||                       CRUD                       || " << endl;
		cout << "====================================================== " << endl;
		cout << "|| 1.  Tambahkan Data                               || " << endl;
		cout << "|| 2.  Tampilkan Data                               || " << endl;
		cout << "|| 3.  Ubahkan Data                                 || " << endl;
        cout << "|| 4.  Hapuskan Data                                || " << endl;
        cout << "====================================================== " << endl;
        cout << "||          Sorting Ascending & Descending          || " << endl;
		cout << "====================================================== " << endl;
        cout << "|| 5.  Merge Sort Ascending                         || " << endl;
        cout << "|| 6.  Merge Sort Descending                        || " << endl;
        cout << "|| 7.  Quick Sort Ascending                         || " << endl;
        cout << "|| 8.  Quick Sort Descending                        || " << endl;
        cout << "====================================================== " << endl;
        cout << "||                    Searching                     || " << endl;
		cout << "====================================================== " << endl;
		cout << "|| 9.  Pilih Data                                   || " << endl;
		cout << "====================================================== " << endl;
		cout << "|| 10. Fibonacci Search (Integer)                   || " << endl;
        cout << "|| 11. Jump Search                                  || " << endl;
        cout << "|| 12. Pilih Data String                            || " << endl;
        cout << "|| 13. Boyer-Moore Search                           || " << endl;
        cout << "====================================================== " << endl;
        cout << "|| 14. Keluar Program                               || " << endl;
		cout << "====================================================== " << endl;
		cout << "Masukkan Pilihan : ";
		cin >> pilihan;
        cin.ignore();
		
		// program pertama Crud
		if(pilihan == 1) {
			// tambah
			system("cls");
	        do {
				cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                  Tambahkan Data                  || " << endl;
				cout << "====================================================== " << endl;
		        cout << "Masukkan string: ";
	            cin >> data;
	            list.createNode(data);
				cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
				cout << "Kembali (Y) : ";
				cin >> loop;
			} while (loop != "Y");		
		} else if(pilihan == 2) {
			// lihat
			system("cls");
	        do {
	            cout << " " << endl;
	            cout << "====================================================== " << endl;
				cout << "||                  Tampilkan Data                  || " << endl;
				cout << "====================================================== " << endl;
	            list.display();
	            cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
				cout << "Kembali (Y) : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 3) {
			// ubah
			system("cls");
	        do {
	            cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                   Ubahkan Data                   || " << endl;
				cout << "====================================================== " << endl;
	            cout << "Masukkan Nama Lama : ";
	            cin >> data;
	            cout << "Masukkan Nama Baru : ";
	            cin >> newData;
                list.updateNode(data, newData);
	            cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
				cout << "Kembali (Y) : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 4) {
			// hapus
			system("cls");
			do {
				cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                   Hapuskan Data                  || " << endl;
				cout << "====================================================== " << endl;
	            cout << "Masukkan string untuk dihapus: ";
	            cin >> data;
                list.deleteNode(data);
	            cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
				cout << "Kembali (Y) : ";
				cin >> loop;
	        } while (loop != "Y");
		} else if(pilihan == 5) {
			// merge ascending
			system("cls");
        	do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||           Urutan Data secara Ascending           || " << endl;
				cout << "====================================================== " << endl;
        		ascending = true;
                list.mergeSort(ascending);
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 6) {
			// merge descending
			system("cls");
			do {
				cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||           Urutan Data secara Descending          || " << endl;
				cout << "====================================================== " << endl;
				ascending = false;
                list.mergeSort(ascending);
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 7) {
			// quick ascending
			system("cls");
        	do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||           Urutan Data secara Ascending           || " << endl;
				cout << "====================================================== " << endl;
        		ascending = true;
                list.quickSort(ascending);
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 8) {
			// quick descending
			system("cls");
			do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||           Urutan Data secara Descending          || " << endl;
				cout << "====================================================== " << endl;
        		ascending = false;
                list.quickSort(ascending);
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 9) {
			// choose
			system("cls");
			do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                    Pilih Data                    || " << endl;
				cout << "====================================================== " << endl;
        		cout << "Integer Data : ";
            	for (int i = 0; i < n; i++) {
                	cout << intArr[i] << " ";
            	}
            	cout << endl;
            	
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 10) {
			// Fibonacci
			system("cls");
			do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                 Fibonacci Search                 || " << endl;
				cout << "====================================================== " << endl;
        		int x;
            	cout << "Masukkan Angka Pencarian Fibonacci : ";
            	cin >> x;
            	int index = fibonacciSearch(intArr, x, n);
            	if (index != -1) {
            		cout << " " << endl;
            		cout << "====================================================== " << endl;
					cout << "||                     Ditemukan                    || " << endl;
					cout << "====================================================== " << endl;
                	cout << x << " ditemukan di indeks " << index << endl;
                	cout << " " << endl;
                } else {
                	cout << " " << endl;
            		cout << "====================================================== " << endl;
					cout << "||                  Tidak Ditemukan                 || " << endl;
					cout << "====================================================== " << endl;
                	cout << x << " tidak ditemukan.";
            	}
            	
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 11) {
			// Jump
			system("cls");
			do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                    Jump Search                   || " << endl;
				cout << "====================================================== " << endl;
        		int x;
            	cout << "Masukkan Angka Jump Search : ";
            	cin >> x;
            	int index = jumpSearch(intArr, x, n);
            	if (index != -1) {
            		cout << " " << endl;
            		cout << "====================================================== " << endl;
					cout << "||                     Ditemukan                    || " << endl;
					cout << "====================================================== " << endl;
                	cout << x << " ditemukan di indeks " << index << endl;
                	cout << " " << endl;
                } else {
                	cout << " " << endl;
            		cout << "====================================================== " << endl;
					cout << "||                  Tidak Ditemukan                 || " << endl;
					cout << "====================================================== " << endl;
                	cout << x << " tidak ditemukan.";
            	}
            	
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 12) {
			// Linked List String
			system("cls");
			do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                     Pilih Data                   || " << endl;
				cout << "====================================================== " << endl;
        		cout << "String Data: ";
            	listsearch.display();
            	
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 13) {
			// Jump
			system("cls");
			do {
        		cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||                    Booye-Moore                   || " << endl;
				cout << "====================================================== " << endl;
            	cout << "Masukkan Pola String Boyer-Moore : ";
            	cin >> pattern;
            	int index = listsearch.boyerMooreSearch(pattern);
            	if (index != -1) {
            		cout << " " << endl;
            		cout << "====================================================== " << endl;
					cout << "||                     Ditemukan                    || " << endl;
					cout << "====================================================== " << endl;
                	cout << pattern << " ditemukan di indeks " << index << endl;
                	cout << " " << endl;
                } else {
                	cout << " " << endl;
            		cout << "====================================================== " << endl;
					cout << "||                  Tidak Ditemukan                 || " << endl;
					cout << "====================================================== " << endl;
                	cout << pattern << " tidak ditemukan.";
            	}
            	
                cout << " " << endl;
				cout << "====================================================== " << endl;
				cout << "||               Kembali ke Menu Utama              || " << endl;
				cout << "====================================================== " << endl;
                cout << "Apakah ingin kembali? [Y] : ";
				cin >> loop;
			} while (loop != "Y");
		} else if(pilihan == 14) {
			// end
			cout << " " << endl;
        	cout << "====================================================== " << endl;
			cout << "||            Terima Kasih Karena Datang!           || " << endl;
            cout << "====================================================== " << endl;
            break;
		}
	}
}
