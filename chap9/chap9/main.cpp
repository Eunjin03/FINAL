#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void super_write_vertical(int);
void random_frantal(int,int,int,int);
void display(int);

int main() {
	int n = 0;

	
	random_frantal(-10,10,10,1);
	cout << endl;
	Sleep(1000);
	random_frantal(-10, 10, 10, 1);
	cout << endl;
	Sleep(1000);
	random_frantal(-10, 10, 10, 1);
	cout << endl;
	Sleep(1000);
	random_frantal(-10, 10, 10, 1);
	cout << endl;
	Sleep(1000);
	random_frantal(-10, 10, 10, 1);

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

void random_frantal(int left_hight, int right_hight, int width, int epslion) {
	double mid_hight = 0;
	double rand_num = (rand() % (width * 2)) - width;

	assert(width > 0);
	assert(epslion > 0);

	srand((unsigned int)time(NULL));

	if (width <= epslion)
		display(right_hight);
	else {
		mid_hight = (left_hight + right_hight) / 2;
		mid_hight += rand_num;
		random_frantal(right_hight, mid_hight, width / 2, epslion);
		random_frantal(mid_hight, left_hight, width / 2, epslion);
	}
}

void display(int n) {
	if (n > 0) {
		cout << "           |";
		for (int i = 0; i < n; i++)
			cout << "*";
		cout << endl;
	}
	else if (n < 0) {
		for (int i = 0; i < 11 + n; i++)
			cout << " ";
		for (int j = 0; j < abs(n); j++)
			cout << "*";

		cout << "|"<<endl;
	}
}