#include <iostream>
using namespace std;

int giaiThuaCalculation(int n) {
    long giaiThua = 1;
    for (int i = 1; i <= n ; i++)
    {
        giaiThua *= i;
    }
    return giaiThua;
}

int asteriskNumber(int n) {
    int number = 1;
    for (int i = 1; i < n; i++)
    {
        number += 2;
    }
    return number;
}

void toHopCalculation() {
    int k;
    do {
        cout << "Nhap so nguyen duong k trong to hop C(n, k): ";
        cin >> k;
    } while (k <= 0);

    int n;
    do {
        cout << "Nhap so nguyen duong n trong to hop C(n-k): ";
        cin >> n;
    } while (n <= 0 || n < k);

    int res;
    res = giaiThuaCalculation(n) / (giaiThuaCalculation(k) * giaiThuaCalculation(n - k));
    
    cout << "Gia tri cua to hop C (" << n << "-" << k << ") la: " << res << endl;
    
}

void getKaraokeMoney() {
    int startTime, endTime = 0;
    do {
        cout << "Nhap gio bat dau: ";
        cin >> startTime;
    } while ((startTime < 8) || (startTime >= 24));

    do {
        cout << "Nhap gio ket thuc: ";
        cin >> endTime;
    } while ((endTime < 9) || (endTime > 24) || (endTime < startTime));

    double sum = 0;
    int curTime = endTime - startTime;
    if (curTime <= 3) {
        sum += curTime * 30;
        if (endTime <= 17) {
            sum = sum - sum * 0.1;
        }
        else {
            if (17 - startTime > 0) {
                sum -= ((17 - startTime) * 30 * 0.1);
            }
        }
    }
    else {
        sum += 90 + (curTime - 3) * 21;
        if (endTime < 17) {
            sum -= sum * 0.1;
        }
        else {
            if (17 - startTime > 0) {
                if (17 - startTime >= 4) {
                    sum -= ((17 - startTime - 3) * 21 + 90) * 0.1;
                }
                else {
                    sum -= ((17 - startTime) * 30 * 0.1);
                }
            }
        }
    }
    cout << "So tien khach hang phai tra la: " << sum << endl;
    
}

void getTripleSum() {
    int n;
    do {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
    } while (n <= 0);

    long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (i * i * i);
    }
    cout << "Tong lap phuong cac so tu 1 den " << n << " la: " << sum << endl;

}

void triangleDrawing() {
    int height;
    do {
        cout << "Nhap chieu cao cua tam giac" << endl;
        cin >> height;
    } while (height <= 0);
    int asteriskHeight = asteriskNumber(height);
    for (int i = 1; i <= asteriskHeight; i+= 2)
    {
        for (int k = 0; k < height - 1; k++)
        {
            cout << " ";
        }
        height -= 1;
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int options = 99;
    int exit = 5;
    while (exit > 0) {
        cout << "***    Thi Giua Ki     ***" << endl;;
        cout << "MSSV: 22120128" << endl;
        cout << "Ho va Ten: Bui Quoc Huy" << endl;
        cout << "He dao tao: Chinh quy" << endl;
        cout << "Chon so tuong ung voi ham can nhap: " << endl;
        cout << "1: Tinh tien quan Karaoke." << endl;
        cout << "2: Tinh tong lap phuong tu 1 den so n." << endl;
        cout << "3: Tinh to hop Ck-n." << endl;
        cout << "4: Ve tam giac" << endl;
        cin >> options;
        
        switch (options){
            case 1:
                getKaraokeMoney();
                break;
            case 2:
                getTripleSum();
                break;
            case 3:
                toHopCalculation();
                break;
            case 4:
                triangleDrawing();
                break;
            default:
                break;
        }
        cout << "Ban co muon tiep tuc ? (Nhap 0 de tat chuong trinh/ So khac de tiep tuc)" << endl;
        cin >> exit;
        system("cls");
    }
    return 0;
}
