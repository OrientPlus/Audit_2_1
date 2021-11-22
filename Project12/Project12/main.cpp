#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <cmath>

using namespace std;


int main()
{
	vector<int> v;
	fstream in_file, out_file;
	in_file.open("input.txt");
	out_file.open("output.txt", ios::out);
	out_file.clear();

	int tmp, it=0;
	cout << "Read values:";
	while (!in_file.eof())
	{
		in_file >> tmp;
		tmp = abs(tmp);
		v.push_back(tmp);
		cout << " " << v[it];
		it++;
	}
	sort(v.begin(), v.end());

	cout << endl << "Sorted vector: " ;
	out_file << "Sorted vector: " << endl;
	it = v.size() - 1;
	while (it >= 0)
	{
		cout << " " << v[it];
		out_file << " " << v[it];
		it--;
	}

	//------------bitset--------------------------
	out_file << endl << "----------------BITSET----------------" << endl;
	bool t;
	string bin;
	for (int i = 0; i < v.size(); i++)
	{
		bitset<32> b = v[i];
		for (int j = 31; j >=0; j--)
		{
			t = b.test(j);
			if (t)
			{
				bin = b.to_string();
				out_file << bin.substr(31 - j) << endl;
				break;
			}
		}
	}
	//----------stack----------------------------
	out_file << endl << "----------------STACK----------------" << endl;
	stack <int> s;
	tmp = v.size() - 1;
	for (int i = v.size()-1; i>=0; i--)
	{
		while (v[i] != 0) //запись в стек кода числа
		{
			tmp = v[i] % 2;
			s.push(tmp);
			v[i] /= 2;
		}

		it = s.size();
		while (it > 0)
		{
			tmp = s.top();
			out_file << tmp;
			s.pop();
			it--;
		}
		out_file << endl;
	}

	in_file.close();
	out_file.close();
	cout << endl;
	system("pause");
	return 0;
}