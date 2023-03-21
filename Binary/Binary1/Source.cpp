/*��� ���� f, ���������� �������� �� ��������:
����������� �������� ������� (��������, �����, ������,
���, ����������� � �. �.), �� ���� � ������ � ���������� ������� �����, ��� ������� ������� ������������� (��������, ��� ����� �� ���� �� ���� ���). ��������
��������� ��������:
�) �������� �������, ���� ������� �� ���������
100 ���. � ������� �������� ����� 5 ���, �������� �� � �������� ����;
�) �������� �������, ������� �������� ��� ����� 4 ���, ��� � ����� 10 ���, �������� �� � ������ �������� ����;
������������ ��������� ����, ���������� ��������������� �� ����������� ���� ��� �������� �� ��������, ������� �������� ��� ������� �)
� ������� � ������� �������� �������, ������� �������� ��� ������� �).*/

#include <iostream>
#include <fstream>
using namespace std;

struct toys
{
	char toy[25];
	int price;
	int bottom_line;
	int upper_bound;
};

int main()
{
	ifstream in("toys.txt");
	ofstream out1("5years.bin", ios::binary);
	ofstream out2("other.bin", ios::binary);
	if (!in)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		exit(-1);
	}
	int i = 0, j = 0, k = 0, num1 = 0, num2 = 0;
	toys x, sw;
	while (in)
	{
		in >> x.toy;
		in >> x.price;
		in >> x.bottom_line;
		in >> x.upper_bound;
		if (x.price <= 100 && x.bottom_line <= 5 && x.upper_bound >= 5 && in)
		{
			out1.write((char*)&x, sizeof(toys));
			num1++;
		}
		if (x.bottom_line <= 4 && x.upper_bound >= 10 && in)
		{
			out2.write((char*)&x, sizeof(toys));
			num2++;
		}
	}
	in.close();
	out1.close();
	out2.close();
	ifstream in1("5years.bin", ios::binary);
	toys* arr1 = new toys[num1];
	toys* arr2 = new toys[num2];
	i = 0;
	while (i < num1 && in1.read((char*)& arr1[i], sizeof(toys)))
	{
		i++;
	}
	in1.close();
	for (i = 0; i < num1; i++)
	{
		for (j = num1 - 1; j > i; j--)
			if (arr1[j].price < arr1[j-1].price)
			{
				sw = arr1[j];
				arr1[j] = arr1[j - 1];
				arr1[j - 1] = sw;
		    }
	}
	ofstream fout("5years_toys.txt");
	for (i = 0; i < num1; i++)
	{
		fout << arr1[i].toy << " " << arr1[i].price << " " << arr1[i].bottom_line << " " << arr1[i].upper_bound << endl;
	}
	fout.close();
	ifstream in2("other.bin", ios::binary);
	i = 0;
	while (i < num2 && in2.read((char*)& arr2[i], sizeof(toys)))
	{
		i++;
	}
	in2.close();
	for (i = 0; i < num2; i++)
	{
		cout << arr2[i].toy << endl;
	}
	system("pause");
	return 0;
}