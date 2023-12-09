#include <iostream>

using namespace std;

void super_write_vertical(int);

int main() {
	int n = 0;

	
		cout << "input num: ";
		cin >> n;
		super_write_vertical(n);
	

	return 0;
}

void super_write_vertical(int n) {
	if (n < 0) {
		cout << "-" << endl;
		super_write_vertical(abs(n));
		return;
	}
	else if (n < 10) {
		cout << n << endl;
		return;
	}
	else {
		super_write_vertical(n / 10);
		cout << n % 10 << endl;
		return;
	}
}