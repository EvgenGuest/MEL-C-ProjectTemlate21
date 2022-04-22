//Персональный шаблон проекта С++
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define chui(s) (unsigned int)s

// Задача 1. Возвращает двоичный код числа
string tobinary(char num) {
	string res;
	for (int i = 7; i >= 0; i--)
		res += to_string(num >> i & 1);
	return res;
}
string tobinary(short num) {
	string res;
	for (int i = 15; i >= 0; i--)
		res += to_string(num >> i & 1);
	return res;
}
string tobinary(int num) {
	string res;
	for (int i = 31; i >= 0; i--)
		res += to_string(num >> i & 1);
	return res;
}

//Задача 2. Переводит двоичное число в десятичное
int tohex(string bin) {
	int size = bin.length();
	for (int i = 0; i < size; i++)
		if (bin[i] != '0' && bin[i] != '1')
			throw invalid_argument("not binary");
	int res = 0;
	for (int i = size - 1, j = 0; i >= 0; i--, j++)
		res += pow(2, i) * (bin[j] - '0');
	return res;
}

//Задача 3.
void fillArr(int arr[], int length, int min, int max) {
	if (min >= max)
		throw out_of_range("range error");
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 3.
	cout << "Задача 3.\nИзначальный массив:\n[";
	int z3[10];
	try{
	fillArr(z3, 10, 10, 31);
	for (int i = 0; i < 10; i++)
		cout << z3[i] << ", ";
	cout << "\b\b]\n";
	}
	catch (const out_of_range& ex) {
		cout << "Ошибка: " << ex.what() << endl;
	}


	//Задача 2.
	/*cout << "Задача 2.\nВВедите двоичный код:\n";
	string binStr;
	cin >> binStr;
	try {
		cout << "Введено число " << tohex(binStr) << endl;
	}
	catch (const invalid_argument &ex) {
		cout << "Ошибка: " << ex.what() << endl;

	}*/
	//Задача 1
	/*cout << "Задача 1.\n";
	char z1c = 77;     // 1001101
	short z1s = 15000; // 11101010011000
	int z1i = 123000;  // 11110000001111000
	cout << "z1c = " << tobinary(z1c) << endl;
	cout << "z1s = " << tobinary(z1s) << endl;
	cout << "z1i = " << tobinary(z1i) << endl;*/
	// Битовые операции
	/*unsigned char n = 5;                              // 00000101
	cout << chui(n) << " << 3 = " << (n << 3) << endl;// 00101000

	n = 35 >> 3;                             // 00100011 = 35
	cout << "35 >> 3 = " << chui(n) << endl; // 00000100 = 4

	n = ~100;                             // 01100100
	cout << "~100 = " << chui(n) << endl; // 10011011 = 155

	n = 154;               // 10011010
	unsigned char m = 171; // 10101011
	                       // 10001010 = 138;
	cout << chui(n) << " & " << chui(m) << " = " << (n & m) << endl;

	n = 152; // 10011000
	m = 43;  // 00101011
	         // 10111011 = 187
	cout << chui(n) << " | " << chui(m) << " = " << (n | m) << endl;

	n = 154; // 10011010
	m = 43;  // 00101011
	         // 10110001 = 177
	cout << chui(n) << " ^ " << chui(m) << " = " << (n ^ m) << endl;*/
	
	return 0;
}
