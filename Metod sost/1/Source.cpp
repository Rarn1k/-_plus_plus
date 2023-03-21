#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
	fstream in("sint.txt");
	ofstream out("result.txt");
	char x;
	int q = 0;
	if (!in)
	{
		cout << "Can't open file" << endl;
		exit(-1);
	}
	while (in >> x && q != 7)
	{
		out << x;
		switch (q)
		{
		case 0:if (x == 'A') q = 1; else q = 7; break;
		case 1:if (x == 'A') q = 4;
			   else if (x == 'B') q = 2;
			   else if (x == 'C') q = 3;
			   else q = 7; break;
		case 2:if (x == 'A') q = 4; else q = 7; break;
		case 3:if (x == 'D') q = 4; else q = 7; break;
		case 4:if (x == 'D') q = 5; else q = 7; break;
		case 5:if (x == 'B') q = 2;
			   else if (x == 'C') q = 3;
			   else if (x == 'A') q = 4;
			   else if (x == 'E') q = 6;
			   else q = 7; break;
		default: q = 7; break;
		}
		out << setw(2) << q << endl;
	}
	out << endl;
	if (q == 6) out << "sequense is element of L" << endl;
	else out << "sequense is not element of L" << endl;
	in.close();
	out.close();
	return 0;
}