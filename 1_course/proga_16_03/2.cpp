#include<iostream>
#include<fstream>
using namespace std;
struct gold
{
	char surname[50];
	int age;
	int edu;
	int a[4];
	int stazh;
	int exp;
	int place;
	int fired;
};

void Sort(gold* a, int n)
{
	gold g;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= (i + 1); j--)
			if (a[j].stazh > a[j - 1].stazh)
			{
				g = a[j];
				a[j] = a[j - 1];
				a[j - 1] = g;
			}
	}
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (!fin)
	{
		cout << "File not found" << endl;
		system("pause");
		exit(-1);
	}
	gold x;
	int i = 0, n;
	gold arr[8];
	while (fin >> x.surname >> x.age >> x.edu >> x.a[0] >> x.a[1] >> x.a[2] >> x.a[3] >> x.stazh >> x.exp >> x.place >> x.fired)
	{
		if (x.age < 50 && (x.edu == 1 || x.edu == 2) && (x.a[0] == 1 || x.a[1] == 1) && x.stazh >= 5 && (x.exp>=(double)x.stazh/2) && x.fired <= 1 && x.place <= 5)
		{
			arr[i] = x;
			i++;
		}
	}
	fin.close();
	Sort(arr, i);
	cout << "Enter the number of vacant seats " << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		fout << arr[i].surname << " " << arr[i].age << " " << arr[i].edu << " " << arr[i].a[0] << " " << arr[i].a[1] << " " << arr[i].a[2] << " " << arr[i].a[3]
			<< " " << arr[i].stazh << " " << arr[i].exp << " " << arr[i].place << " " << arr[i].fired << endl;
	}
	fout.close();
	i = 0;

	ifstream oni("output.txt");
	ofstream aga("Sheff.txt");
	if (!oni)
	{
		cout << "File 'oni' not found" << endl;
		system("pause");
		exit(-1);
	}

	for (i = 0; (oni >> x.surname >> x.age >> x.edu >> x.a[0] >> x.a[1] >> x.a[2] >> x.a[3] >> x.stazh >> x.exp >> x.place >> x.fired) && i < n; i++)
	{
		if (x.age <= 45 && x.edu == 2  && x.stazh >= 15 && x.fired == 0 && x.place <= 2)
		{
			aga << x.surname << " " << x.age << " " << x.edu << " " << x.a[0] << " " << x.a[1] << " " << x.a[2] << " " << x.a[3]
				<< " " << x.stazh << " " << x.exp << " " << x.place << " " << x.fired << endl;
		}
	}
	if (i == 0) 
	 aga << "Net takovyh!"; 
	oni.close();
	aga.close();
	return 0;
}

