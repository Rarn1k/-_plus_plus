/*������� �� ������� � ������������. ���������� ��������� ����� ������:
�)���;
�)�������;
�)���������� ������;
�)��� ������;
�)�������(1) ��� ����������(0) �������;
�)����� ������-������(1) ��� ������(0);
�� ��� ������� � �������� ����.
���� �������� ����� ������ �����, �� �������� �����:
�)������� - �� 14 �� 60 ���;
�)�� ����� 3;
�)�� ����� 25��;
�)���������� �������;
���� �������� ����� ����� ������-������, �� �������� �����:
�)�� 6 �� 70 ���;
�) �� ����� 5;
�) �� ����� 40��;
������������ ���� � ��� ����������, � ����, �������� �� ��� �� ���� ��������� ��� ���.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct pass
{
	char fio[25];
	int age;
	int amounte;
	int weight;
	int pet;
	int ticket;
};

int main()
{
	ifstream in("numbers.txt");
	ofstream out("passengers.bin", ios::binary);
	if (!in)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		exit(-1);
	}
	int i = 0, n = 0;
	pass x;
	while (in)
	{
		in >> x.fio;
		in >> x.age;
		in >> x.amounte;
		in >> x.weight;
		in >> x.pet;
		in >> x.ticket;
		if (in)
		{
			out.write((char*)& x, sizeof(pass));
			n++;
		}
	}
	out.close();
	in.close();
	pass* arr = new pass[n];
	ifstream in1("passengers.bin", ios::binary);
	i = 0;
	while (i < n && in1.read((char*)& arr[i], sizeof(pass)))
	{
		i++;
	}
	in1.close();
	ofstream fout("flying.txt");
	for (i = 0; i < n; i++)
	{
		if ((arr[i].ticket == 0 && arr[i].age >= 14 && arr[i].age <= 60 && arr[i].amounte <= 3 && arr[i].weight <= 25 && arr[i].pet == 0) ||
			(arr[i].ticket == 1 && arr[i].age >= 6 && arr[i].age <= 70 && arr[i].amounte <= 5 && arr[i].weight <= 40))
			fout << arr[i].fio << " Yes" << endl;
		else
			fout << arr[i].fio << " No" << endl;

	}
	fout.close();
	return 0;
}

