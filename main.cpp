#include <iostream>

using namespace std;

void mnominal()
{
    string menunominal[4]={"50.000","100.000","250.000","500.000"};
    cout << "\n\t1. " << menunominal[0]<<"\n";
    cout << "\n\t2. " << menunominal[1]<<"\n";
    cout << "\n\t3. " << menunominal[2]<<"\n";
    cout << "\n\t4. " << menunominal[3]<<"";
    cout << endl;
}

void header()
{
    cout <<"\t================================================\n";
    cout <<"\t===========  BANK Central Banyumas  ============\n";
    cout <<"\t================================================\n\n";
}
void hmenu()
{
    cout <<"\t==================================================\n";
    cout <<"\t=========  Silahkan Pilih Transaksi, =============\n";
    cout <<"\t========= Untuk Membatalkan Transaksi ============\n";
    cout <<"\t=========         Tekan Keluar        ============\n";
    cout <<"\t==================================================\n\n";
}
void hpnominal()
{
    cout <<"\t================================================\n";
    cout <<"\t===============  Pilih Nominal  ================\n";
    cout <<"\t================================================\n\n";
}
void htransfer()
{
    cout <<"\t================================================\n";
    cout <<"\t===========  BANK Central Banyumas  ============\n";
    cout <<"\t============== Transfer Rekening  ==============\n";
    cout <<"\t================================================\n\n";
}
void hsetortunai()
{
    cout <<"\t================================================\n";
    cout <<"\t===========  BANK Central Banyumas  ============\n";
    cout <<"\t================= Setor Tunai  =================\n";
    cout <<"\t================================================\n\n";
}
void hceksaldo()
{
    cout <<"\t================================================\n";
    cout <<"\t===========  BANK Central Banyumas  ============\n";
    cout <<"\t================== Cek Saldo  ==================\n";
    cout <<"\t================================================\n\n";
}

int main()
{
    int saldo = 1000000, pin, rekening, keluar, transfer, rekeningTuju, setor, nominal, pilih,selesai,cetak;
    system("cls");
    header();
    cout <<"\tMasukan No Rekening : ";
    cin>>rekening;
    cout << "\n";
pin:
    cout <<"\tMasukan Pin : ";
    cin >>pin;
    if (pin == 12345)
    {
    menu:
        system("cls");
        hmenu();
        cout << "\t1. PENARIKAN TUNAI " << "\t4. CEK SALDO ";
        cout << "\n\n\t2. TRANSFER " << "\t\t5. KELUAR " ;
        cout << "\n\n\t3. SETOR TUNAI \n";

        cout <<"\n\tPilih Transaksi : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            system("cls");
            hpnominal();
        casemenu:
           cout <<"\tPilih nominal yang ingin anda ambil,\n";
           mnominal();
           cout <<"\n\t5. Nominal Lain\n";
           cout <<"\n\tPilih : ";
           cin >>nominal;
            if (nominal == 1)
                keluar = 50000;
            else if (nominal == 2)
                keluar = 100000;
            else if (nominal == 3)
                keluar = 250000;
            else if (nominal == 4)
                 keluar = 500000;
            else if (nominal == 5)
            {
                system("cls");
                hpnominal();
            inputKeluar:
                cout <<"\tMasukan nominal yang ingin anda ambil (kelipatan 50.000) : ";
                cin >>keluar;
                if (keluar % 50000 !=0)
                {
                    system("cls");
                    hpnominal();
                    cout <<"\tNominal yang anda masukan bukan kelipatan 50.000\n\n";
                    goto inputKeluar;
                }
                else if(keluar == 0){
                    system("cls");
                    hpnominal();
                    cout <<"\tNominal yang anda masukkan bukan kelipatan 50.000\n\n";
                    goto inputKeluar;
                }
            }
            else
            {
                system("cls");
                hpnominal();
                cout <<"\tPilihan salah\n\tSilahkan Pilih kembali\n\n";
                goto casemenu;
            }
            if (keluar > saldo)
            {
                system("cls");
                hpnominal();
                cout <<"\tTransaksi Gagal\n";
                cout <<"\tSaldo anda tidak mencukupi\n\n";
                goto konfirmasi;
            }
            else
            {
                system("cls");
                header();
                cout <<"\tTransaksi Berhasil !!\n";
                saldo = saldo - keluar;
                cout <<"\n\tSisa saldo anda = " << saldo <<" ,-\n";
                cout <<"\n\tSilahkan Ambil uang anda sebesar = "<< keluar<<" ,-";
                cout <<"\n\t________________________________________\n";
                goto konfirmasi;
            }
            break;
        case 2: //transfer
            system("cls");
            htransfer();
            cout <<"\tMasukan nomor rekening yang dituju = ";
            cin >> rekeningTuju;
            cout <<"\n\tMasukan nominal yang ingin anda transfer = ";
            cin >> transfer;
            if (transfer > saldo)
            {
                system("cls");
                htransfer();
                cout <<"Transaksi Gagal\n";
                cout <<"Saldo anda tidak mencukupi ";
                goto konfirmasi;
            }
            else
            {
                system("cls");
                htransfer();
                cout <<"\n\tTransaksi Berhasil!\n";
                saldo = saldo - transfer;
                cout <<"\n\tSisa saldo anda = " << saldo <<",-";
                cout <<"\n\t________________________________________\n";
                goto konfirmasi;
            }
            break;
        case 3://setor tunai
            system("cls");
            hsetortunai();
            cout <<"\tMinimal nominal 50.000,-\n\tDan merupakan kelipatan 50.000\n\n";
        inputSetor:
           cout <<"\tMasukan nominal yang ingin anda setor = ";
           cin >>setor;
            if (setor % 50000 != 0)
            {
                system("cls");
                hsetortunai();
                cout <<"\tNominal yang anda masukan bukan kelipatan 50000\n\n";
                goto inputSetor;
            }
            system("cls");
            hsetortunai();
            cout <<"\tTransaksi Berhasil!\n";
            saldo = saldo + setor;
            cout <<"\tTotal saldo anda menjadi = " << saldo <<",-";
            cout <<"\n\t________________________________________\n";
            goto konfirmasi;
            break;
        case 4://cek saldo
            system("cls");
            hceksaldo();
            cout <<"\tSaldo Anda = " << saldo << " ,-";
            cout <<"\n\t_________________________________\n";
            cout <<"\n\tApakah anda ingin Mencetak Saldo ?\n";
            cout <<"\n\t1. Ya\n";
            cout <<"\n\t2. Tidak\n";
            cout <<"\n\tPilih : ";
            cin >> cetak;
            if (cetak == 1){
                goto cetaksaldo;
            }
            else if(cetak == 2){
                goto end;
            }
            break;
        case 5: // keluar
            system("cls");
            header();
            goto selesai;
            break;

        default:
            system("cls");
            goto menu;
        }
    }
    else
    {
        system("cls");
        header();
        cout <<"\tPin Anda Salah\n\n";
        goto pin;
    }
konfirmasi:
    cout <<"\n\tApakah anda ingin melakukan transaksi lain ?\n";
    cout <<"\n\t1. Ya\n";
    cout <<"\n\t2. Tidak\n";
    cout <<"\n\tPilih : ";
    cin  >>pilih;
    if (pilih == 1)
        goto menu;
    else if (pilih == 2)
        goto end;
    else
    {
        system("cls");
        header();
        cout <<"Pilihan Salah\nSilahkan pilih kembali\n\n";
        goto konfirmasi;
    }

cetaksaldo:
    system("cls");
    hceksaldo();
    cout <<"\tCetak Saldo Berhasil !!! " << endl;
    cout <<"\n\tSaldo Awal Anda = " << saldo;
    cout <<"\n\t____________________________\n" << endl;

    cout <<"\tApakah anda ingin melakukan transaksi ? \n ";
    cout <<"\n\t1. Ya\n";
    cout <<"\n\t2. Tidak\n";
    cout <<"\n\tPilih : ";
    cin >> cetak;
    if(cetak == 1)
        goto menu;
    else if (cetak == 2)
        goto end;

selesai:
    system("cls");
    header();
    cout << "\tMaaf, tidak ada Transaksi yang dilakukan !!\n";
    cout << "\t_________________________________________\n\n";
    cout <<"\tApakah anda ingin melakukan transaksi ?\n";
    cout <<"\n\t1. Ya\n";
    cout <<"\n\t2. Tidak\n";
    cout <<"\n\tPilih : ";
    cin >> cetak;
    if(cetak == 1)
        goto menu;
    else if (cetak == 2)
        goto end;

end:
    system("cls");
    header();
    cout <<"\tTerimakasih Telah Percaya Melakukan Transaksi\n\tDi Bank Central Banyumas\n\n";
    return 0;
}


