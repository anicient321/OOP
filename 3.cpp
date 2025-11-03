#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void popravirazmake(string& text) {
	//micimo visestruke razmake
	text.erase(unique(text.begin(), text.end(), [](char a, char b) {
		return a == ' ' && b == ' ';
	}), text.end());

	//makni razmake prije zareza pa tocke
	size_t pos;
	while ((pos = text.find(" ,")) != string::npos) text.erase(pos + 1, 1);
	while ((pos = text.find(" .")) != string::npos) text.erase(pos + 1, 1);

	//ako nema razmaka tu stvorit cemo ga
	for (size_t i = 0; i < text.size(); ++i) {
		if (text[i] == ',' && (i + 1 < text.size() && text[i + 1] != ' ')) {
			text.insert(i + 1, " ");
		}
		if (text[i] == '.' && (i + 1 < text.size() && text[i + 1] != ' ')) {
			text.insert(i + 1, " ");
		}
	}
}

int main() {
	string text = "puno   razmaka ,i tocka .";
	cout << "prije: " << text << endl;
	popravirazmake(text);
	cout << "posli: " << text << endl;
	return 0;
}
