#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

//Поиск символа в массиве
int find_ch(char* a, char ch) {
	for (int i = 0; i < 255; i++)
		if (ch == a[i])
			return i;
	return -1;
}

//Кол-во слов в кодовом блокноте
int AmountCodeWords() {
	string buffer;
	int n = 0;
	ifstream code_pad("../CodePad.txt");
	while (!code_pad.eof()) {
		code_pad >> buffer;

		n++;
	}
	code_pad.seekg(0);
	code_pad.close();
	return n;
}

//Считывание кодового блокнота
int* ReadCodePad() {
	ifstream file("../CodePad.txt");
	string buffer;
	int shift, n;
	n = AmountCodeWords();
	int* arr = new int[n];

	for (int i = 0; !file.eof(); i++) {
		shift = 0;
		file >> buffer;
		for (int j = 0; j < buffer.length(); j++)
			shift += abs((int)buffer[j]);
		arr[i] = shift;
	}

	file.close();
	return arr;
}

//Кодирование исходного текста 
void TextRusCode() {
	char ch; int n, counter = 0, k = 0;

	n = AmountCodeWords();
	int* arrcode = new int[n];
	arrcode = ReadCodePad();
	char arr[255];
	int arr1[255];

	for (int i = 0; i < 255; i++) {
		arr[i] = '<';
		arr1[i] = 0;
	}

	//Посимвольное считывание исходного текста
	ifstream file("../TextRus.txt");
	ofstream code("../TextCode.txt");
	ofstream ch_code("../Ch.txt");

	while (!file.eof()) {
		if (counter > n) 
			counter -= n;

		file.get(ch);

		if (file.eof()) 
			break;

		cout << ch;
		if (find_ch(arr, ch) == -1) {
			arr[k] = ch;
			arr1[k] = 1;
			k++;
		}
		else {
			arr[find_ch(arr, ch)] = ch;
			arr1[find_ch(arr, ch)] += 1;
		}

		//Посимвольное кодирование и запись в новый файл
		code << (char)((int)ch + arrcode[counter]);
		counter++;

	};
	
	for (int i = 0; i < 255; i++) {
		if (arr[i] == '<') break;
		ch_code << arr[i] << " - " << arr1[i] << endl;
	}

	file.close();
	code.close();
	ch_code.close();
	delete []arrcode;
}

//Поиск кодирования символа
void Symbol(char CheckChar) {
	char ch; int n, counter = 1;

	n = AmountCodeWords();
	int* arrcode = new int[n];
	arrcode = ReadCodePad();

	//Посимвольное считывание исходного текста
	ifstream file("../TextRus.txt");

	while (!file.eof()) {
		if (counter > n)
			counter -= n;

		file.get(ch);

		if (file.eof())
			break;

		//Вывод кодов для символа
		if (ch == CheckChar) {
			cout << (char)((int)ch + arrcode[counter]) << " ";
			counter++;
		}

	};

	file.close();
	delete []arrcode;
}

//Чтение закодированного текста из файла
void ReadCodeText() {
	ifstream file("../TextCode.txt");
	char ch;
	while (!file.eof()) {
		file.get(ch);
		cout << ch;
	}
	file.close();
	cout << endl;
}

//Декодирование текста
void DecodeText() {
	int n, counter = 0;
	char ch;
	n = AmountCodeWords();
	int* arr = new int[n];
	arr = ReadCodePad();
	ifstream file("../TextCode.txt");
	while (!file.eof()) {
		if (counter > n) counter -= n;
		file.get(ch);
		if (file.eof()) break;
		cout << char((int)(ch)-arr[counter]);
		counter++;
	}
	delete []arr;
}

//Данные о символе
void CheckSymbol() {
	char MyChar, YesNo = 'y';

	cout << "Хотите ли вы получить отчет по конкретному символу?(y or n): ";
	cin >> YesNo;
	while (YesNo == 'y' || YesNo == 'Y') {
		cout << "Введите нужный символ: ";
		cin >> MyChar;
		cout << endl << "Символ " << MyChar << " кодируется следующими символами: " << endl;
		Symbol(MyChar);

		cout << endl << endl << "Проверить символ еще раз?(y or n): ";
		cin >> YesNo;
	}
}

//Частота повторяемости символов
void PrintTable() {
	char ch;
	ifstream ch_code("../Ch.txt");

	while (!ch_code.eof()) {
		ch_code.get(ch);
		cout << ch;
		ch_code.get(ch);
		cout << ch;
		ch_code.get(ch);
		cout << ch;
	}

	ch_code.close();
}

//Основное тело программы
void solve() {

	cout << endl << "Количество слов в словаре: ";
	cout << AmountCodeWords() << endl;
	cout << endl << "Исходный текст: " << endl;
/*    TextRusCode();
		cout << endl << endl << "Закодированный текст: " << endl;
	ReadCodeText();
	cout << endl << endl << "Декодированный текст: " << endl;
	DecodeText();
	cout << endl << endl << "Таблица символов: " << endl;
	PrintTable();
	CheckSymbol();*/
}

int main()
{
	//system("chcp 1251");
    CheckSymbol();
	solve();

	//system("pause");
	return 0;
}