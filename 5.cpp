#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void okrenistringove(vector<string>& words) {
	//okricemo svaki string u vektoru
	for (auto& word : words) {
		reverse(word.begin(), word.end());
	}
}

int main() {
	//init vektora stringova
	vector<string> words = { "hello", "world", "c++" };

	cout << "prije: ";
	for (const auto& word : words) {
		cout << word << " ";
	}
	cout << endl;

	okrenistringove(words);

	cout << "posli: ";
	for (const auto& word : words) {
		cout << word << " ";  //tocan ispis
	}
	cout << endl;

	return 0;
}
