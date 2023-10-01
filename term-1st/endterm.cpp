#include <iostream>
#include <string>
using namespace std;

bool PrimeNumberChecker(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    for (int i = 2; i < n/2 + 1; i++)
    {
        if (n % i == 0) {
            return false;
        }
    }
    return true;

}

void Cau1() {
    // Initialize Array's Value
    int n;
    int arr[100];
    cout << "Nhap vao so phan tu cua mang: ";
    cin >> n;
    
    // Check if n is negative
    if (n < 0) 
    {
        cout << "Ban vua nhap vao so am" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao phan tu thu " << i + 1 << " :";
        cin >> arr[i];
    }

    // Prin the array
    cout << "In ra mang: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print the array on reverse
    cout << "In ra mang theo thu tu nguoc lai: ";
    for (int i = n - 1; i >= 0 ; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print array's even value > 50
    cout << "In ra cac so chan lon hon 50 trong mang: ";
    for (int i = n - 1; i >= 0; i--)
    {
        if ((arr[i] % 2 == 0) && (arr[i] > 50)) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void Cau2() {
    // Initialize Array's Value
    int n;
    int arr[100][100] = {0};
    cout << "Nhap vao so phan tu cua mang NxN: ";
    cin >> n;

    // Check if n is negative
    if (n < 0)
    {
        cout << "Ban vua nhap vao so am" << endl;
        return;
    }

    cout << "Nhap vao cac phan tu cua mang " << n << " x " << n << " lan luot theo thu tu tu phai qua trai, tu tren xuong duoi" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            cin >> arr[i][j];
        }
    }

    // Print the array
    cout << "In ra mang 2D:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Print the first column min number of that array
    int minPrime = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ( PrimeNumberChecker(arr[i][0]) && (arr[i][0] < minPrime)){
            minPrime = arr[i][0];
        }
    }
    
    if (minPrime != INT_MAX) {
        cout << "So nguyen to be nhat tren cot dau tinh tu trai sang la: " << minPrime << endl;
    }
    else {
        cout << "Khong ton tai so nguyen to tren cot dau tinh tu trai sang" << endl;
    }

    // Diagonal Sum
    int sum = 0;
    int curC = n - 1;
    int curR = 0;
    while (curC >= 0 && curR < n) 
    {
        if (arr[curR][curC] % 2 == 1) {
            sum += arr[curR][curC];
        }
        curR += 1;
        curC -= 1;
    }
    cout << "Tong cac so le tren duong cheo nguoc la: " << sum << endl;
}

double CalculateYn(double n);

double CalculateXn(double n) {
    if (n != 0) {
        return (3 * CalculateYn(n) + CalculateXn(n - 1));
    }
    return 1;
}

double CalculateYn(double n){
    if (n != 0) {
        return ((CalculateXn(n) / 3) + CalculateYn(n - 1));
    }
    return (-0.3333333);
}

void Cau3() {
    cout << "Em run code bi bug duoc" << endl;
    return;
    double n;
    cout << "Nhap vao so nguyen duong n: ";
    cin >> n;

    // Check if n is negative
    if (n < 0)
    {
        cout << "Ban vua nhap vao so am" << endl;
        return;
    }

    cout << "Gia tri cua Xn la: " << CalculateXn(n) << endl;
    cout << "Gia tri cua Yn la: " << CalculateYn(n) << endl;

}

int main()
{
    // Initialize menu's values
    int options = -1;
    int again = 1;
    string answer = "";

    while (again) 
    {
        system("cls");
        // Introduction
        cout << "*** THI CUOI KI ***" << endl;
        cout << "MSSV: 22120128" << endl;
        cout << "Ho va ten: Bui Quoc Huy" << endl;
        cout << "He dao tao: Chinh quy" << endl;
        // Menu
        cout << "0: Ket thuc chuong trinh" << endl;
        cout << "1: Cau 1" << endl;
        cout << "2: Cau 2" << endl;
        cout << "3: Cau 3" << endl;
        do 
        {
            cout << "Nhap vao so tuong ung voi cau muon chon: " << endl;
            cin >> options;
        } while (options < 0 || options > 3);

        switch (options)
        {
        case 1:
        {
            Cau1();
            break;
        }
        case 2: 
        {
            Cau2();
            break;
        }
        case 3:
        {
            Cau3();
            break;
        }
        default:
            break;
        }

        do 
        {
            cout << "Ban co muon tiep tuc? (Nhan 'y' de tiep tuc, 'n' de ket thuc)" << endl;
            cin >> answer;

        } while (answer != "y" && answer != "n");

        if (answer == "n") {
            again = 0;
        }
    }
    return 0;
}

