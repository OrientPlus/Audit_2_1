#include <iostream>
#include <fstream>
#include <random>
#include <locale>
#include <vector>
#include <ctime>

using namespace std;

void gistogram(const vector<int>& n, fstream* out)
{
	int mass[8] = { 0,0,0,0,0,0,0,0 };
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
	*out << "Пример генерируемых значений:" << endl;
	for (int i = 0; i < 7; ++i)
	{
		*out << n[i] << "  ";
	}
	*out << endl;
	for (int i = 0; i < 8; i++)
	{
		mass[i] = mass[i] / 5000;
		*out << i+2<<" |";
		for (mass[i]; mass[i] >= 0; mass[i]--)
		{
			*out << "*";
		}
		*out << endl;
	}
}

void generate_RD(fstream *out)
{
	int tmp = 0;
	clock_t start, end;
	random_device rd;
	vector<int> v;

	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		tmp = rd();
		v.push_back(tmp);
	}
	end = clock();
	cout << endl << "Генерация завершена.";
	*out << "Гистограмма random_device :" << endl;
	gistogram(v, out);
	*out << "Время генерации 1 000 000 чисел: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << endl;
}

void generate_mt19937(fstream *out)
{
	int tmp = 0;
	clock_t start, end;
	random_device rd;
	mt19937 gen(rd());
	vector<int> v;
	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		tmp = gen();
		v.push_back(tmp);
	}
	end = clock();
	cout << endl << "Генерация завершена.";
	*out << endl << "Гистограмма mt19937 :" << endl;
	gistogram(v, out);
	*out << endl << "Время генерации 1 000 000 чисел: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << endl;
}

void generate_uniform(fstream* out)
{
	int a, b, tmp=0;
	cout << "Введите значение для нижней границы распределения:";
	cin >> a;
	cout << endl << "Введите значение для верхней границы распределения:";
	cin >> b;
	mt19937 gen(1729);
	uniform_int_distribution <> distr(a, b);
	
	clock_t start, end;
	vector<int> v;
	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		tmp = distr(gen);
		v.push_back(tmp);
	}
	end = clock();
	cout << endl << "Генерация завершена.";
	*out << endl << "Гистограмма uniform_int_distribution:" << endl;
	gistogram(v, out);
	*out << endl << "Время генерации 1 000 000 чисел: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << endl;
}

void generate_srand(fstream* out)
{
	srand(time(NULL));
	int tmp = 0;
	clock_t start, end;
	vector<int> v;
	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		tmp = rand() % 1000000;
		v.push_back(tmp);
	}
	end = clock();
	cout << endl << "Генерация завершена.";
	*out << endl << "Гистограмма srand + rand:" << endl;
	gistogram(v, out);
	*out << endl << "Время генерации 1 000 000 чисел: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << endl;
}

int main()
{
	setlocale(0, "ru");
	fstream out;
	out.open("output.txt", ios::out);
	int choise;
	if (!out.is_open())
	{
		cout << "ФАЙЛ НЕ ОТКРЫТ!" << endl;
	}
	
	cout << "1)random_device" << endl << "2)mt19937" << endl << "3)uniform_int_distribution" << endl <<"4) srand + rand" << endl << "5) EXIT";
	cout << endl << ":";
	cin >> choise;
	while (1)
	{
		if (choise == 5)
			break;
		if (choise == 1)
			generate_RD(&out);
		if (choise == 2)
			generate_mt19937(&out);
		if (choise == 3)
			generate_uniform(&out);
		if (choise == 4)
			generate_srand(&out);
		cout << endl << ":";
		cin >> choise;
	}

	cout << endl;
	out.close();
	system("pause");
	return 0;
}