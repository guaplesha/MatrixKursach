#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include <locale>

void summary(const vector <vector <float>>&matrix1, const vector <vector <float>>&matrix2) {
	ofstream result("Result.txt");
	if ((matrix1.size() == matrix2.size()) && (matrix1[0].size() == matrix2[0].size())) {
		for (int i = 0; i < matrix1.size(); i++) {
			for (int j = 0; j < matrix1[0].size(); j++) {
				cout << matrix1[i][j] + matrix2[i][j] << "\t";
				result << matrix1[i][j] + matrix2[i][j] << "\t";
			}
			result << endl;
			cout << endl;
		}
		cout << "Результа сложения двух матриц находится в файле Result.txt" << endl;
	}
	else {
		cout << "По правилам сложения матриц, можно складывать лишь матрицы одного порядка." << endl;
		cout << "Матрица 1 имеет размерность " << matrix1.size() << " на " << matrix1[0].size() << endl;
		cout << "Матрица 2 имеет размерность " << matrix2.size() << " на " << matrix2[0].size() << endl;
		cout << "Рекомендация - изменить исходные матрицы в обоих файлах." << endl;
	}
}

void difference(const vector <vector <float>>&matrix1, const vector <vector <float>>&matrix2) {
	ofstream result("Result.txt");
	if ((matrix1.size() == matrix2.size()) && (matrix1[0].size() == matrix2[0].size())) {
		for (int i = 0; i < matrix1.size(); i++) {
			for (int j = 0; j < matrix1[0].size(); j++) {
				cout << matrix1[i][j] - matrix2[i][j] << "\t";
				result << matrix1[i][j] - matrix2[i][j] << "\t";
			}
			result << endl;
			cout << endl;
		}
		cout << "Результа разности двух матриц находится в файле Result.txt" << endl;
	}
	else {
		cout << "По правилам разности матриц, можно производить вычитаниелишь между матрицами одного порядка." << endl;
		cout << "Матрица 1 имеет размерность " << matrix1.size() << " на " << matrix1[0].size() << endl;
		cout << "Матрица 2 имеет размерность " << matrix2.size() << " на " << matrix2[0].size() << endl;
		cout << "Рекомендация - изменить исходные матрицы в обоих файлах." << endl;
	}
}

void multiplication(const vector <vector <float>>&matrix1, const vector <vector <float>>&matrix2) {
	ofstream result("Result.txt");
	float result2 = 0;
	if (matrix1[0].size() == matrix2.size()) { //n=n
		for (int i = 0; i < matrix1.size(); i++) { //m
			for (int j = 0; j < matrix2[0].size(); j++) { //n
				for (int p = 0; p < matrix1[0].size(); p++) {//0..p
					result2 += matrix1[i][p] * matrix2[p][j];
				}
				result << result2 << "\t";
				cout << result2 << "\t";
				result2 = 0;
			}
			result << endl;
			cout << endl;
		}
		cout << "Результа разности двух матриц находится в файле Result.txt" << endl;
	}
	else {
		cout << "Произведение матриц(С = АВ) — операция только для согласованных матриц А и В, у которых число столбцов матрицы А равно числу строк матрицы В"<< endl;
		cout << "Матрица 1 имеет размерность " << matrix1.size() << " на " << matrix1[0].size() << endl;
		cout << "Матрица 2 имеет размерность " << matrix2.size() << " на " << matrix2[0].size() << endl;
		cout << "Рекомендация - изменить исходные матрицы в обоих файлах." << endl;
	}
}


void main(void) {
	setlocale(LC_ALL, "Russian");
	try {
		ifstream input1("Input1.txt");
		ifstream input2("Input2.txt");

		if (!input1.is_open()) {
			throw - 1;
		}
		if (input1.peek() == EOF) {
			throw - 2;
		}
		if (!input2.is_open()) {
			throw - 1;
		}
		if (input2.peek() == EOF) {
			throw - 2;
		}
		float temp;
		int number_of_lines1 = 0;
		int number_of_columns1 = 0;
		int number_of_numbers1 = 0;
		string str;
		while (getline(input1, str, '\n')) {
			number_of_lines1++;
		}
		input1.close();
		ifstream input11("Input1.txt");
		while (input11 >> temp) {
			number_of_numbers1++;
		}
		number_of_columns1 = number_of_numbers1 / number_of_lines1;
		input11.close();
		int number_of_lines2 = 0;
		int number_of_columns2 = 0;
		int number_of_numbers2 = 0;
		while (getline(input2, str, '\n')) {
			number_of_lines2++;
		}
		input2.close();
		ifstream input22("Input2.txt");
		while (input22 >> temp) {
			number_of_numbers2++;
		}
		number_of_columns2 = number_of_numbers2 / number_of_lines2;
		input22.close();


		vector <vector <float>> matrix1(number_of_lines1, vector<float>(number_of_columns1));
		vector <vector <float>> matrix2(number_of_lines2, vector<float>(number_of_columns2));

		ifstream input111("Input1.txt");
		ifstream input222("Input2.txt");
		for (int i = 0; i < number_of_lines1; i++) {
			for (int j = 0; j < number_of_columns1; j++) {
				input111 >> matrix1[i][j];
			}
		}
		input111.close();
		for (int i = 0; i < number_of_lines2; i++) {
			for (int j = 0; j < number_of_columns2; j++) {
				input222 >> matrix2[i][j];
			}
		}
		input111.close();
		input222.close();
		int flag = 1;
		int choice = 0;
		while (flag == 1) {
			cout << "Меню \n1)Сложение матриц\n2)Вычитание матриц\n3)Умножение матриц\n4)Выход из программы\n";
			cin >> choice; 
			if ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4)) {
				throw 2;
			}
			switch (choice) {
			case 1:
				summary(matrix1, matrix2);
				break;
			case 2:
				difference(matrix1, matrix2);
				break;
			case 3:
				multiplication(matrix1, matrix2);
				break;
			case 4:
				return;
				break;
			}
			system("pause");
			system("cls");
		}
	}
	catch (int a) {
		switch (a) {
		case 2:
			cout << "Неверный ввод выбора. Ошибка номер " << a << endl;
			break;
		case -1:
			cout << "Входной файл Input1.txt не существует в директории программы. Ошибка номер " << a << endl;
			break;
		case -2:
			cout << "Входной файл Input2.txt пустой. Ошибка номер " << a << endl;
			break;
		}
	}
}