
#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

template<typename moj>
moj NWD(moj a, moj b) 
{
	return (a == 0) ? b : NWD(b % a, a);
}

template<typename moj>
moj tocjent(moj n) {
	double suma = n;
	moj dzielnik = 2;
	while (n != 1) {
		while (n % dzielnik != 0)
			dzielnik++;
		suma *= (1 - 1.0 / dzielnik);
		while (n % dzielnik == 0) {
			n /= dzielnik;
		}
	}
	return moj(suma);
}

template<typename moj>
moj potegowanie_eulera(moj x, moj y, moj m) {
	moj w = x;
	y = y % tocjent(m);

	for (moj i = 1; i < y; i++)
	{
		w = (w * x) % m;
		cout << w << endl;
	}
	return w;
}

int main() {
	string temp_string;
	
	cout << "Podaj podstawę: ";
	getline(cin, temp_string);
	auto x = stoull(temp_string);
	cout << endl;

	cout << "Podaj wykładnik: ";
	getline(cin, temp_string);
	auto y = stoull(temp_string);
	cout << endl;

	cout << "Podaj mod: ";
	getline(cin, temp_string);
	auto z = stoull(temp_string); //m
	cout << endl;

	// x y z o rozmiarze unsigned long long

	if( NWD(x,z) != 1 || z < 1) 
	{
		cout << "Wprowadzone dane nie spelniają założenia twierdzenia eulera !!" << endl;
		system("pause");
		return 0;
	}

	cout << endl << "Wynik to: " << potegowanie_eulera(x,y,z) << endl;
	system("pause");
	return 0;
}

