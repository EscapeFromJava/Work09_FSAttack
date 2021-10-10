#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, Lx1, Ly1, Lx2, Ly2;
	int arrX[30000] = {};//массив с координатой X
	int arrY[30000] = {};//массив с координатой Y
	int arrR[30000] = {};//массив с величиной радиуса
	cout << "Введите количество тарелок" << endl;
	cin >> n;
	if (n < 1 || n >30000) {
		cout << "Введено неверное количество тарелок" << endl;
		return 0;
	}
	cin >> Lx1 >> Ly1 >> Lx2 >> Ly2;
	if (Lx1 < 1 || Lx1 > 10000 || Ly1 < 1 || Ly1 > 10000 || Lx2 < 1 || Lx2 > 10000 || Ly2 < 1 || Ly2 > 10000 || ) {
		cout << "Введены неверные параметры" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> arrX[i] >> arrY[i] >> arrR[i];
		if (arrX[i] < 1 || arrX[i] > 10000 || arrY[i] < 1 || arrY[i] > 10000 || arrR[i] < 1 || arrR[i] > 10000 ) {
			cout << "Введены неверные параметры" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arrX[i] == arrY[i]) {
				cout << i + 1 <<" тарелка уничтожена!" << endl;
			}
		else cout << i + 1 << " тарелка уцелела!" << endl;
		}
	return 0;
}