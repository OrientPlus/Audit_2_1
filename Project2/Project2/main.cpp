#include <iostream>
#include <fstream>
#include <random>
#include <locale>
#include <vector>

using namespace std;

void gistogram(const vector<int> &n, fstream *out)
{
	int mass[8] = {0,0,0,0,0,0,0,0};
	for (int i = 0; i < 1000000; i++)
	{

		if (n[i] % 2 == 0)
		{
			mass[0]++;
		}
		if (n[i] % 3 == 0)
		{
			mass[1]++;
		}
		if (n[i] % 4 == 0)
		{
			mass[2]++;
		}
		if (n[i] % 5 == 0)
		{
			mass[3]++;
		}
		if (n[i] % 6 == 0)
		{
			mass[4]++;
		}
		if (n[i] % 7 == 0)
		{
			mass[5]++;
		}
		if (n[i] % 8 == 0)
		{
			mass[6]++;
		}
		if (n[i] % 9 == 0)
		{
			mass[7]++;
		}
	}
	for (int i = 0; i < 8; i++)
	{			
		mass[i] = mass[i] / 10000;
		*out << i+2<<" |";
		for (mass[i]; mass[i] >= 0; mass[i]--)
		{
			*out << "*";
		}
		*out << endl;
	}
}

int main()
{
	setlocale(0, "ru");
	fstream out;
	out.open("output.txt", ios::out);
	int tmp=0;
	if (!out.is_open())
	{
		cout << "���� �� ������!" << endl;
	}
	clock_t start, end;

	random_device rd;
	uniform_int_distribution<> dist(0, 1000000);
	cout << "��������� �����... " << endl;
	vector<int> v1, v2, v3;

	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		tmp = rd();
		v1.push_back(tmp);
	}
	end = clock();
	cout << endl << "��������� ���������. �������� �����������..." << endl;
	out << "����������� random_device :" << endl;
	gistogram(v1, &out);
	out << "����� ��������� 1 000 000 �����: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << endl;


	mt19937 gen(rd());
	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		tmp = dist(gen);
		v2.push_back(tmp);
	}
	end = clock();
	cout << endl << "��������� ���������. �������� �����������..." << endl;
	out << endl << "����������� mt19937 :" << endl;
	gistogram(v2, &out);
	out << endl << "����� ��������� 1 000 000 �����: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << endl;

	cout << endl;
	system("pause");
	return 0;
}