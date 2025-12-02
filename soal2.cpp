#include <iostream>
using namespace std;

struct pelanggan{
    string nama;
    string berat;
    int urutan;
    int status;
};

void to_upper(string &s)
{
    for (char &c : s)
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
}

void enq(pelanggan *&queue, int &size, int &capacity, pelanggan data)
{
    if (size == capacity)
    {
        capacity *= 2;
        pelanggan *baru = new pelanggan[capacity];
        for (int j = 0; j < size; ++j)
            baru[j] = queue[j];
        delete[] queue;
        queue = baru;
    }

    queue[size] = data;
    ++size;
}

pelanggan deq(pelanggan *queue, int &size)
{
    if (size == 0)
    {
        pelanggan kosong = {"", "", -1, 0};
        return kosong;
    }

    int prioritas = 0;
    for (int i = 1; i < size; ++i)
    {
        bool vip = queue[i].status > queue[prioritas].status;
        bool duluan = queue[i].status == queue[prioritas].status && queue[i].urutan < queue[prioritas].urutan;

        if (vip || duluan)
            prioritas = i;
    }

    pelanggan dilayani = queue[prioritas];
    
    for (int i = prioritas; i < size - 1; ++i)
        queue[i] = queue[i + 1];
    --size;

    return dilayani;
}

void display(pelanggan *queue, int size)
{
    cout << "\nUrutan: \n";
    pelanggan *tempQueue = new pelanggan[size];
    int tempSize = size;
    int waktu = 0;
    for (int i = 0; i < size; ++i)
        tempQueue[i] = queue[i];

    for (int nomor = 1; tempSize > 0; ++nomor)
    {
        pelanggan dilayani = deq(tempQueue, tempSize);
        
        to_upper(dilayani.nama);
        cout << nomor << ". " << dilayani.nama << " - " << dilayani.berat;
        if (dilayani.status == 1) {
            cout << " Reguler";
            waktu = waktu + 10;
        }
        if (dilayani.status == 2){
            cout << " Express";
            waktu = waktu + 5;
        }
        cout << '\n';
    }

    cout << "Total waktu : " << waktu << " Menit ";
    delete[] tempQueue;
}


int main(){
    int n;
    cout << "Masukkan jumlah pesanan: ";
    cin >> n;
    cin.ignore(); 

    int capacity = max(1, n);
    int size = 0;
    int waktu = 0;
    pelanggan *queue = new pelanggan[capacity];

    for (int i = 0; i < n; ++i)
    {
        pelanggan data;
        cout << "\nPesanan " << i + 1 << ":\n";
        cout << "Masukkan nama pelanggan: ";
        getline(cin, data.nama);
        cout << "Masukkan berat: ";
        getline(cin, data.berat);
        cout << "masukkan jenis layanan (1 = reguler, 2 = express): ";
        cin >> data.status;
        cin.ignore();
        
        data.urutan = i;
        enq(queue, size, capacity, data);
    }


        display(queue, size);
}