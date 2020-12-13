#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "funs.h"
#include <iomanip>

using namespace std;

/// <summary>
/// Ќаходит минимально по модулю значение в файле
/// </summary>
/// <param name="file"> Ч исходный файл</param>
/// <returns>min_dbl Ч минимальное по модулю значение</returns>
double find_min_abs(ifstream& file)
{
	double min_dbl = DBL_MAX;
	double dbl_now;

	while (!file.eof()) {
		file >> dbl_now;
		if (abs(dbl_now) < abs(min_dbl)) {
			min_dbl = dbl_now;
		}
	}

	return min_dbl;
}

/// <summary>
/// Ќаходит максимальное и минимальное значение в каждой строке и записывает его в файл MaxsAndMins.txt
/// </summary>
/// <param name="input_file"> Ч исходный файл</param>
void find_maxs_and_mins_in_file(ifstream& input_file)
{
	double max_dbl, min_dbl, dbl_now;
	int k{ 1 };
	ofstream output_file("MaxsAndMins.txt");
	if (output_file.is_open()) {
		while (!input_file.eof()) {
			max_dbl = DBL_MIN;
			min_dbl = DBL_MAX;
			while (input_file.peek() != '\n' && !input_file.eof()) {
				input_file >> dbl_now;
				if (dbl_now < min_dbl)	min_dbl = dbl_now;
				if (dbl_now > max_dbl)	max_dbl = dbl_now;
			}
			input_file.ignore(1);
			output_file << k << "-€ строка: MAX Ч " << max_dbl << "\t | MIN Ч " << min_dbl << '\n';
			++k;
		}


		output_file.close();
	}

	return;
}