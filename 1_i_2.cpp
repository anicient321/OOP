#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* prvi i drugi zadatak, bilo je zgodno stavit ih u isti*/

//inputamo br u vektor dok ne unesemo nulu
void inputajvector(vector<int>& v) {
	int num;
	while (true) {
		cin >> num;
		if (num == 0) break;
		v.push_back(num);
	}
}

void printajvector(const vector<int>& v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

vector<int> unikatni(const vector<int>& v) {
	vector<int> unique;
	for (int num : v) {
		if (find(unique.begin(), unique.end(), num) == unique.end()) {
			unique.push_back(num);
		}
	}
	return unique;
}

int main() {
	vector<int> v;
	cout << "unestie brojeve: ";
	cout << "0 za kraj";
	inputajvector(v);

	vector<int> unique = unikatni(v);

	cout << "originalni vektor: ";
	printajvector(v);

	cout << "unikatni tj. jedinstveni elementi: ";
	printajvector(unique);

	sort(unique.begin(), unique.end(), [](int a, int b) {
		return abs(a) < abs(b);
	});

	cout << "sort po apsolutnoj vrijednosti: ";
	printajvector(unique);

	return 0;
}
