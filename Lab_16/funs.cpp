#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "funs.h"
#include <iomanip>

using namespace std;

/// <summary>
/// ������� ���������� �� ������ �������� � �����
/// </summary>
/// <param name="file"> � �������� ����</param>
/// <returns>min_dbl � ����������� �� ������ ��������</returns>
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
/// ������� ������������ � ����������� �������� � ������ ������ � ���������� ��� � ���� MaxsAndMins.txt
/// </summary>
/// <param name="input_file"> � �������� ����</param>
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
			output_file << k << "-� ������: MAX � " << max_dbl << "\t | MIN � " << min_dbl << '\n';
			++k;
		}


		output_file.close();
	}

	return;
}