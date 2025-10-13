#include <iostream>

int& at(int* niz, int i) {
	return niz[i];  //vraca referencu na element niza
}

int main() {
	int niz[] = { 1, 2, 3, 4, 5 };
	int i = 2;

	at(niz, i)++;  //uvecavamo 3. element (indeks 2) za 1

	for (int j = 0; j < 5; j++) {
		std::cout << niz[j] << " ";
	}

	return 0;
}
/*Funkcija at uzima pokazivač na niz (int* niz) i indeks (int i), te vraća referencu na element na tom indeksu.
U funkciji main pozivamo at(niz, i)++, što povećava 3. element niza za 1.*/