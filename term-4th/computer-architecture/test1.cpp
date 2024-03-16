#include <iostream>
#include <math.h>
using namespace std;

bool* GetUsignedBinary(int num) {
    const int n = 8;
    static bool num_binary[n];
    int temp = abs(num);
    int j =  n - 1;

    // Initialize to zeros
    for (int i = 0; i < n; i++) {
        num_binary[i] = 0;
    }
    
    // Get unsigned binary representation
    while (temp != 0 && j >= 0) {
        num_binary[j--] = temp % 2;
        temp /= 2;
    }
    return num_binary;
}

bool *DTBSignMagnitude(int num) {
    const int n = 8;

    // Edge Case
    if (num > pow(2, n - 1) - 1 || num < - pow(2, n - 1) + 1) {
        cout << "overflow" << endl;
        return {};
    }

    bool *num_binary = GetUsignedBinary(num);
    
    // Handle num < 0
    if (num < 0) {
        num_binary[0] = 1;
    }

    for (int i = 0; i < 8; i++) {
        cout << num_binary[i];
    }
    if (num == 0) {
        num_binary[0] = 1;
        cout << " and ";
        for (int i = 0; i < 8; i++) {
            cout << num_binary[i];
        }
        cout << endl;
    } else {
        cout << endl;
    }
    return num_binary;
}

bool *DTBOneComplement(int num) {
    const int n = 8;

    // Edge Case
    if (num > pow(2, n - 1) - 1 || num < - pow(2, n - 1) + 1) {
        cout << "overflow" << endl;
        return {};
    }

    bool *num_binary = GetUsignedBinary(num);

    // Handle num < 0
    if (num < 0) {
        // Flip bits
        for (int i = 0; i < n; i++) {
            num_binary[i] = !num_binary[i];
        }
    }

    for (int i = 0; i < 8; i++) {
        cout << num_binary[i];
    }
    if (num == 0) {
        cout << " and ";
        for (int i = 0; i < 8; i++) {
            cout << !num_binary[i];
        }
        cout << endl;
    } else {
        cout << endl;
    }
    return num_binary;
}

bool *DTBTwoComplement(int num) {
    const int n = 8;

    // Edge Case
    if (num > pow(2, n - 1) - 1 || num < - pow(2, n - 1)) {
        cout << "overflow" << endl;
        return {};
    }

    bool *num_binary = GetUsignedBinary(num);

    // Handle num < 0
    if (num < 0) {
        // Flip bits
        for (int i = 0; i < n; i++) {
            num_binary[i] = !num_binary[i];
        }

        // Add one
        for (int i = n - 1; i >= 0; i--) {
            if (num_binary[i] == 0) {
                num_binary[i] = 1;
                break;
            }
            num_binary[i] = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        cout << num_binary[i];
    }
    cout << endl;
    return num_binary;
}

char* Hexa(bool *num) {
    const int n = 8;
    char dict[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    static char res[2];

    for (int i = 7; i >= 0;) {
        int tmp = 0;

        for (int j = 0; j <= 3; j++) {
            tmp += num[i-j] * pow(2, j);
        }
        if (i > 4) res[1] = dict[tmp];
        else res[0] = dict[tmp];
        i -= 4;
    }
    cout << res[0] << res[1] << endl;
    return res;
}

int main() {
    int num;
    cout << "Input: ";
    cin >> num;
    cout << "Ouput a: ";
    bool* num_binary_1 = DTBSignMagnitude(num);
    cout << "Ouput b: ";
    bool* num_binary_2 = DTBOneComplement(num);
    cout << "Ouput c: ";
    bool* num_binary_3 = DTBTwoComplement(num);
    cout << "Hexadecimal: ";
    char* hex = Hexa(num_binary_3);
}

