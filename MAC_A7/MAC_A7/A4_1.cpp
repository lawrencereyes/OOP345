#include <iostream>

using namespace std;

int main(void) {
	double m1[4][4];
	double m2[4][4];
	double m3[4][4];

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << "matrix 1[" << r << "] [" << c << "] = ";
			cin >> m1[r][c];
		}
	}

	cout << endl;

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			m2[r][c] = m1[c][r];
			cout << "matrix 2[" << r << "] [" << c << "] = " << m2[r][c] << endl;
		}
	}

	cout << endl;

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			m3[r][c] = m1[r][c] + m2[r][c];
			cout << "matrix 3[" << r << "] [" << c << "] = " << m3[r][c] << endl;
		}
	}

	cout << endl;
	cout << "Matrices in tubular form" << endl;
	cout << "------------------------" << endl;


	cout << endl;
	cout << "Matrix 1" << endl;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << m1[r][c] << " ";
			if (c == 3) {
				cout << endl;
			}
		}
	}

	cout << endl;
	cout << "Matrix 2" << endl;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << m2[r][c] << " ";
			if (c == 3) {
				cout << endl;
			}
		}
	}

	cout << endl;
	cout << "Matrix 3" << endl;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << m3[r][c] << " ";
			if (c == 3) {
				cout << endl;
			}
		}
	}
	system("pause");
	return 0;
}