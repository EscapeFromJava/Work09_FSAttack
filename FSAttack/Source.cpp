#include <iostream>
#include <vector>

using namespace std;

struct Plate {
	float x, y, r;
};

struct Gun {
	float x1, y1, x2, y2;
	float k, b;
};

Plate inputPlate(int i)
{
	Plate plate;
	cout << "Введите координаты " << i + 1 << " тарелки по оси \"x\" и \"у\" и радиус \"r\": ";
	cin >> plate.x >> plate.y >> plate.r;
	while (abs(plate.x + plate.y + plate.r) > 10000 && plate.r <= 0) {
		cin >> plate.x >> plate.y >> plate.r;
	}
	return plate;
}

Gun inputGun()
{
	Gun gun;
	cout << "Введите координаты точек \"x1\", \"у1\", \"x2\" и \"у2\" через которые проходит лазерный луч: ";
	cin >> gun.x1 >> gun.y1 >> gun.x2 >> gun.y2;
	while (abs(gun.x1 + gun.y1 + gun.x2 + gun.y2) > 10000) {
		cin >> gun.x1 >> gun.y1 >> gun.x2 >> gun.y2;
	}
	gun.k = (gun.y2 - gun.y1) / (gun.x2 - gun.x1);
	gun.b = (gun.x2 * gun.y1 - gun.x1 * gun.y2) / (gun.x2 - gun.x1);
	return gun;
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector<Plate> vecPlate;
	int n;
	cout << "Введите количество тарелок: ";
	cin >> n;
	while (n < 1 || n > 30000) {
		cin >> n;
	}
	Gun gun = inputGun();

	for (int i = 0; i < n; i++) {
		vecPlate.push_back(inputPlate(i));
	}

	for (int i = 0; i < vecPlate.size(); i++) {
		int count = 0;
		if ((vecPlate[i].y <= ((gun.k * vecPlate[i].x) + gun.b)) && (vecPlate[i].x >= (vecPlate[i].y-gun.b)/gun.k)) {
			if (((vecPlate[i].y + vecPlate[i].r) >= ((gun.k * vecPlate[i].x) + gun.b)) || ((vecPlate[i].x - vecPlate[i].r) <= ((vecPlate[i].y - gun.b) / gun.k))) {
				count++;
				if (count == 1) {
					cout << i + 1 << " ";
				}
			}
		}
		if ((vecPlate[i].y >= ((gun.k * vecPlate[i].x) + gun.b)) && (vecPlate[i].x <= (vecPlate[i].y - gun.b) / gun.k)) {
			if (((vecPlate[i].y - vecPlate[i].r) <= ((gun.k * vecPlate[i].x) + gun.b)) || ((vecPlate[i].x + vecPlate[i].r) >= ((vecPlate[i].y - gun.b) / gun.k))) {
				count++;
				if (count == 1) {
					cout << i + 1 << " ";
				}
			}
		}
	}
	return 0;
}