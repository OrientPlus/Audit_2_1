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

	for (auto& p : directory_iterator(way)) //Получаем список файлов в директории и их размер.
	{
		way = p.path();
		FName.push_back(way.string());
		FSize.push_back(p.file_size());
		way.remove_filename();
		n++;
	}

	for (int i = 0; i < n; ++i) //Выводим найденные файлы.
	{
		cout << FName[i] << " || SIZE ==> "<< FSize[i] /1024 << "Kb" << endl;
	}

	way.clear();

	for (int i = 0; i < n; i++)
	{
		if (FSize[i]/1024 > 100)
		{
			way.remove_filename();
			way = _way;
			way /= "DIR";
			create_directory(way.string());
			fileWay.remove_filename();
			fileWay = _way;
			fileWay /= FName[i];
			copy(fileWay.string(), way.string());
		}
		else if (tmp < 100)
		{
			if (file_point == 0)
			{
				way.remove_filename();
				way = _way;
				way /= "DIR2";
				create_directory(way.string());
				file_point = 1;
			}
			fileWay.remove_filename();
			fileWay = _way;
			fileWay /= FName[i];
			copy(fileWay.string(), way.string());
			tmp = tmp + FSize[i]/1024;
		}
	}


	//for (int j = 0; j < i; ++j) //Пробегаем по всем найденным файлам в директории
	//{
	//	if (FSize[j] >= 100) //Если файл больше 100Кб, создаем директорию и копируем в нее файл
	//	{
	//		way /= "DIRECTORY";
	//		if (!create_directory(way.string())) //Вывести сообщение об ошибке, если не удалось создать директорию
	//		{
	//			cout << endl << "ERROR! DIRECTORY WAS NOT CREATED!" << endl;
	//			system("pause");
	//			exit(0);
	//		}
	//		for (auto& q : directory_iterator(way))//Получаем имя созданной директории и копируем в нее файл
	//		{                                      //т.к директории скорее всего создаются с одинаковым именем, они будут расположены 
	//			way = q.path();                    //последовательно по мере создания (Дир1, Дир2, ...) соответсвенно можем получать их имена в цикле
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