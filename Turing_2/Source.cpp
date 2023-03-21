#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int  main()
{
	const int n = 100, kol_sost = 19; 
	const int number_comand = 36;
	char a[n];
	struct zap
	{
		char sym;
		int sost;
		char move;
	};

	zap** tabl = new zap * [kol_sost];
	for (int i = 0; i < kol_sost; i++)
	{
		tabl[i] = new zap[n];
	}

	int i, count = 0;
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
	out << setw(10) << 1;
	for (i = 2; i < kol_sost; i++)
		out << setw(9) << i;
	out << endl << '1';
	for (sost_in = 1; sost_in < kol_sost; sost_in++)
	{
		if (sost_in < 10)
			out << setw(7) << tabl[sost_in]['1'].sym << tabl[sost_in]['1'].sost << tabl[sost_in]['1'].move;
		else
			out << setw(6) << tabl[sost_in]['1'].sym << tabl[sost_in]['1'].sost << tabl[sost_in]['1'].move;
	}
	out << endl;

	out << '_';
	for (sost_in = 1; sost_in < kol_sost; sost_in++)
	{
		if (sost_in < 9)
			out << setw(7) << tabl[sost_in]['_'].sym << tabl[sost_in]['_'].sost << tabl[sost_in]['_'].move;
		else
			out << setw(6) << tabl[sost_in]['_'].sym << tabl[sost_in]['_'].sost << tabl[sost_in]['_'].move;
	}
	out << endl;

	cout << endl << "Enter input word; number of symbols{1} <=21;  symbol '_' is a last symbol  " << endl;

	cout << endl << "input word " << endl;

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == '_') break;
	}
	out << endl << "input word" << endl;
	for (i = 0; i < n; i++)
	{
		if (a[i] == '1')
			count++;
		out << a[i];
	}
	out << endl;
	out << "x = " << count;
	out << endl;

	i = 0; int t = 0, f = 0;
	if (count >= 5)
	{
		while (sost != 10 && t<1500)
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
	}
	else
	{
		sost = 10;
		while (sost && t<1500)
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
	}

	out << endl << "output word" << endl;
	for (i = 0; i < n; i++)
	{
		if (a[i] == '1')
			f++;
		out << a[i];
	}
	out << endl;
	out << "f(x) = " << f;
	out << endl;
	out.close();
	return 0;
}