#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int  main()
{
	const int n = 100, kol_sost = 8;
	const int number_comand = 14;
	char a[n];
	struct zap
	{
		char sym;
		int sost;
		char move;
	};

	zap tabl[kol_sost][100];
	int i;
	int sost = 1;
	for (i = 0; i < n; i++)
		a[i] = '_';

	ifstream in("machine.txt");
	ofstream out("out.txt");
	char sym_in, sym_out;
	int sost_in, sost_out;
	char mv;
	if (!in)
	{
		cout << "Can't open file " << endl;
		system("pause");
		exit(-1);
	}
	for (i = 0; i < number_comand; i++)
	{
		in >> sym_in >> sym_out >> mv >> sost_in >> sost_out;
		tabl[sost_in][sym_in].sost = sost_out;
		tabl[sost_in][sym_in].sym = sym_out;
		tabl[sost_in][sym_in].move = mv;
	}
	in.close();

	out << setw(8) << 1 << setw(7) << 2 << setw(7) << 3 << setw(7) << 4 << setw(7) << 5 << setw(7) << 6 << setw(7) << 7 << endl;
	out << '1';
	for (sost_in = 1; sost_in < kol_sost; sost_in++)
		out << setw(5) << tabl[sost_in]['1'].sym << tabl[sost_in]['1'].sost << tabl[sost_in]['1'].move;
	out << endl;

	out << '_';
	for (sost_in = 1; sost_in < kol_sost; sost_in++)
		out << setw(5) << tabl[sost_in]['_'].sym << tabl[sost_in]['_'].sost << tabl[sost_in]['_'].move;
	out << endl;

	cout << endl << "Enter input word; number of symbols{1} <=19;  symbol '_' is a last symbol  " << endl;

	cout << endl << "input word " << endl;

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == '_') break;
	}
	int count = 0;
	out << "input word" << endl;
	for (i = 0; i < n; i++)
	{
		out << a[i];
		if (a[i] == '1')
			count++;
	}
	out << endl;
	out << "x = " << count;
	out << endl;

	i = 0; int t = 0, f = 0;
	while (sost && (t < 1500))
	{ 
		char r = tabl[sost][a[i]].sym;
		int s = tabl[sost][a[i]].sost;
		mv = tabl[sost][a[i]].move;
		sost = s;
		a[i] = r;
		if (mv == 'R') i++; else
			if (mv == 'L') i--;
		t++;
	}

	out << endl << "output word" << endl;
	for (i = 0; i < n; i++)
	{
		out << a[i];
		if (a[i] == '1')
			f++;
	}
	out << endl;
	out << "f(x) = " << f;
	out << endl;
	out.close();
	return 0;
}