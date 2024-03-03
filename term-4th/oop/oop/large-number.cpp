#include "large-number.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isSmaller(string num1, string num2) {
	int n1 = num1.size(), n2 = num2.size();

	if (n1 < n2) return true;
	if (n2 < n1) return false;

	for (int i = 0; i < n1; i++) {
		if (num1[i] < num2[i]) return true;
		else if (num1[i] > num2[i]) return false;
	}
	return false;
}

string addLargeNumbers(string num1, string num2) {
	if (num1.size() > num2.size()) swap(num1, num2);

	string res = "";
	int n1 = num1.size(), n2 = num2.size();
	int carry = 0;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	
	for (int i = 0; i < n1; i++) {
		int sum = ((num1[i] - '0') + (num2[i] - '0') + carry);
		res += (sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = n1; i < n2; i++) {
		int sum = ((num2[i]) - '0' + carry);
		res += (sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry) res += (carry + '0');
	reverse(res.begin(), res.end());
	cout << res << endl;
	return res;
}

string diffLargeNumbers(string num1, string num2) {
	if (isSmaller(num1, num2)) swap(num1, num2);
	string res = "";
	int n1 = num1.size(), n2 = num2.size();
	int carry = 0;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	for (int i = 0; i < n2; i++) {
		int sub = ((num1[i] - '0') - (num2[i] - '0') - carry);
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else carry = 0;
		res.push_back(sub + '0');
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
	return res;
}

string multiplyLargeNumbers(string num1, string num2) {
	int n1 = num1.size(), n2 = num2.size();

	if (n1 == 0 || n2 == 0) return "0";

	vector<int> res(n1 + n2, 0);

	int i_n1 = 0, i_n2 = 0;

	for (int i = n1 - 1; i >= 0; i--) {
		int carry = 0;
		int cur1 = num1[i] - '0';
		i_n2 = 0;

		for (int j = n2 - 1; j >= 0; j--) {
			int cur2 = num2[j] - '0';
			int sum = cur1 * cur2 + res[i_n1 + i_n2] + carry;
			carry = sum / 10;
			res[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}

		if (carry > 0) res[i_n1 + i_n2] += carry;
		i_n1++;
	}

	int i = res.size() - 1;
	while (i >= 0 && res[i] == 0) i--;
	if (i == -1) return "0";

	string s = "";
	while (i >= 0) {
		s += to_string(res[i--]);
	}
	cout << s << endl;
	return s;
}