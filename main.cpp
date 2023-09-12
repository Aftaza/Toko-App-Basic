#include <iostream>
#include <string>


using namespace std;


#define gudang 10


class Toko{
    private:
        int total;
        int uang;
        int menuIn;
        int kresek;
        int hargabaru;
        int order[gudang] = {};
        int harga[gudang] = {10000, 50000, 70000, 100000, 85000};
        string barangBaru;
        string barang[gudang] = {"Kaos kaki", "Kaos branded", "Kemeja biasa", "Celana", "Rok"};
    public:
        Toko(){
            do
            {
                cout << "=============================" << endl;
                cout << "Selamat datang di Toko berkah" << endl;
                cout << "=============================" << endl;
                cout << endl;
                menuToko();
            } while (menuIn != 4);
            
        }
        void menuToko(){
            cout << "Daftar menu yang bisa dieksekusi:" << endl;
            cout << "[1] Tampilkan stok barang" << endl;
            cout << "[2] Input barang" << endl;
            cout << "[3] Jual Beli" << endl;
            cout << "[4] Keluar" << endl;
            cout << "Silahkaan masukkan angka: "; cin >>menuIn;
            if (menuIn == 1)
            {
                tampil();
            }else if (menuIn == 2)
            {
                input();
            }else if (menuIn == 3)
            {
                transaksi();
            }else{
                cout << "Maaf input salah" << endl;
            }
        }
        void tampil(){
            cout << endl << "Daftar barang yang tersedia adalah:" << endl;
            for (int i = 0; i < gudang; i++)
            {
                if (barang[i] == "")
                {
                    continue;
                }
                
                cout << "[" << i+1 << "] " << barang[i] << "(" << harga[i] << ")" << endl;
            }
            cout << endl;
        }
        void input(){
            cout << "Masukkan nama barang: "; cin >> barangBaru;
            cout << "Masukkan harga barang: "; cin >> hargabaru;
            for (int i = 0; i < gudang; i++)
            {
                if (barang[i] == "")
                {
                    barang[i] = barangBaru;
                    harga[i] = hargabaru;
                    cout << "Barang berhasil ditambhakn di index " << i << endl;
                    break;
                }else if (i == gudang){
                    cout << "Gudang sudah penuh barang tidak dapat ditambahkan" << endl;
                }
                
            }
            
        }
        void transaksi(){
            cout << endl << "Selamat berbelanja" << endl;
            cout << "Tentukan kapasistas kresek anda: "; cin >> kresek;
            if (kresek >= gudang)
            {
                cout << "Maaf kresek kamu terlalu besar bagi gudang kami" << endl;
            }else{
                tampil();
                cout << endl;
                cout << "Masukkan list belanja anda dengan angka dipisah spasi" << endl;
                for (int i = 0; i < kresek; i++)
                {
                    int temp;
                    cout << "Masukkan barang " << i+1 << " anda: "; cin >> temp;
                    order[i] = temp-1;
                    total += harga[temp-1];
                }
                bayar();
            }
        }
        void bayar(){
            cout << endl;
            cout << "Jumlah belanja kamu adalah: " << total << endl;
            cout << "Silahkan masukkan uang anda: "; cin >> uang; 
            cout << endl;
            if (uang < total)
            {
                cout << "Maaf uang kamu gk cukup nih" << endl;
            }else if (uang > total){
                cout << "Nih kemablian kamu sebanyak " << uang - total << endl;
                nota();
            }else{
                nota();
            }
            
        }
        void nota(){
            cout << endl;
            cout << "Ini nota belanja kamu" << endl;
            for (int i = 0; i < kresek; i++)
            {
                cout << "[" << i+1 << "] " << barang[order[i]] << endl; 
            }
            cout << "Terima Kasih sudah berbelanja" << endl << endl;
            
        }


};


int main()
{
    Toko dibuka;
    
    
    return 0;
}
