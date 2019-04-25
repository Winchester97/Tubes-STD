#include "head.h"

using namespace std;

int main() {
    int pil,kembali;
    infotype mobil,montir;
    mList Lcar;
    kList Lmech;
    k_adr sMax,k_hapus;
    m_adr m_hapus;
    createkList(Lmech);
    createmList(Lcar);
    do {
        system("CLS");
        Menu();
        cout<<"     pilihan: ";
        cin>>pil;
        switch(pil) {
        case 1:
            system("CLS");
            Header();
            cout<<"Nama Montir: ";
            cin>>montir;
            k_insert(Lmech,k_Allocation(montir));
            break;
        case 2:
            system("CLS");
            Header();
            cout<<"Merk Mobil: ";
            cin>>mobil;
            m_insert(Lcar,m_Allocation(mobil));
            break;
        case 3:
            system("CLS");
            Header();
            if (ismEmpty(Lcar) && iskEmpty(Lmech)) {
                cout<<"List Empty \n";
            } else {
                showData(Lcar,Lmech);
                menuKerusakan (Lcar, Lmech);
            }
            cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        case 4:
            system("CLS");
            Header();
            if (iskEmpty(Lmech)) {
                cout<<"List Mechanic Empty \n";
            } else {
                showData(Lcar,Lmech);
                cout<<"Pilih montir yang akan dihapus: ";
                cin>>montir;
                del_Montir(Lcar,Lmech,montir,k_hapus);
            } cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        case 5:
            system("CLS");
            Header();
            if (ismEmpty(Lcar)) {
                cout<<"List Mechanic Empty \n";
            } else {
                showData (Lcar,Lmech);
                cout<<"Pilih mobil yang akan dihapus: ";
                cin>>mobil;
                del_Mobil(Lcar,mobil,m_hapus);
            } cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        case 6:
            system("CLS");
            Header();
            printInfo(Lcar,Lmech);
            cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        case 7:
            system("CLS");
            Header();
            k_MostFix (Lcar, Lmech,sMax);
            cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        case 8:
            system("CLS");
            Header();
            showData(Lcar,Lmech);
            cout<<"Montir : ";
            cin>>montir;
            printCarofMech(Lcar,Lmech,montir);
            cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        case 9:
            system("CLS");
            Header();
            printCarof2Mech(Lcar,Lmech);
            cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        case 10:
            system("CLS");
            Header();
            showData(Lcar,Lmech);
            cout<<"\n\n(insert 0 to back)\n";
            cin>>kembali;
            break;
        }
    }while (pil != 0);
return 0;
}
