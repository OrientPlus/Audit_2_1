#include <iostream>
#include <filesystem>
#include <vector>
#include <string>


using namespace std;
using namespace filesystem;

int main()
{
	vector<string> FName;
	vector<int> FSize;
	path way = "C:\\Users\\gutro\\Desktop\\GIT\\audit\\Project3\\Project3\\dir";
	path _way = "C:\\Users\\gutro\\Desktop\\GIT\\audit\\Project3\\Project3\\dir";
	path fileWay;
	int n = 0, file_point = 0, tmp = 0, tmpI=0;

	for (auto& p : directory_iterator(way)) //�������� ������ ������ � ���������� � �� ������.
	{
		way = p.path();
		FName.push_back(way.string());
		FSize.push_back(p.file_size());
		way.remove_filename();
		n++;
	}

	for (int i = 0; i < n; ++i) //������� ��������� �����.
	{
		cout << FName[i] << " || SIZE ==> "<< FSize[i] /1024 << "Kb" << endl;
	}

	way.clear();

	for (int i = 0; i < n; i++)
	{
		if (FSize[i] > 100)
		{
			way.remove_filename();
			way = _way;
			way /= "DIR" + i;
			create_directory(way.string());
			fileWay.remove_filename();
			fileWay = _way;
			fileWay /= FName[i];
			copy_file(fileWay.string(), way.string());
		}
		else if (tmp < 100)
		{
			if (file_point == 0)
			{
				way.remove_filename();
				way = _way;
				way /= "DIR2";
				create_directory(way.string());
			}
			fileWay.remove_filename();
			fileWay = _way;
			fileWay /= FName[i];
			//copy_file(fileWay.string(), way.string());
			tmp = tmp + FSize[i];
		}
	}


	//for (int j = 0; j < i; ++j) //��������� �� ���� ��������� ������ � ����������
	//{
	//	if (FSize[j] >= 100) //���� ���� ������ 100��, ������� ���������� � �������� � ��� ����
	//	{
	//		way /= "DIRECTORY";
	//		if (!create_directory(way.string())) //������� ��������� �� ������, ���� �� ������� ������� ����������
	//		{
	//			cout << endl << "ERROR! DIRECTORY WAS NOT CREATED!" << endl;
	//			system("pause");
	//			exit(0);
	//		}
	//		for (auto& q : directory_iterator(way))//�������� ��� ��������� ���������� � �������� � ��� ����
	//		{                                      //�.� ���������� ������ ����� ��������� � ���������� ������, ��� ����� ����������� 
	//			way = q.path();                    //��������������� �� ���� �������� (���1, ���2, ...) ������������� ����� �������� �� ����� � �����
	//			if (point == j)
	//				break;
	//			point++;
	//			way.remove_filename();
	//		}
	//		point = 0;
	//		copy_file(FName[j], way);
	//	}
	//	else {
	//		tmp = tmp + FSize[j];
	//		tmpI++;
	//	}
	//	if (tmp >= 100)
	//	{
	//		way /= "DIREC";
	//		create_directory(way.string());
	//	}
	//}

	system("pause");
	return 0;
}