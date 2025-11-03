#include <iostream>
#include <string>

using namespace std;

string ric_u_piglatin(const string& word) {
	string vowels = "aeiouAEIOU";
	if (vowels.find(word[0]) != string::npos) {
		return word + "hay";
	}
	else {
		return word.substr(1) + word[0] + "ay";
	}
}

int main() {
	string ric1 = "objektno";
	string ric2 = "hellooo";

	cout << ric1 << " -> " << ric_u_piglatin(ric1) << endl;
	cout << ric2 << " -> " << ric_u_piglatin(ric2) << endl;

	return 0;
}
