#include <iostream>
using namespace std;
void main()
{
	cout << "Begin " << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "i = " << i << endl;
		if (i == 5)
		{
			break;
		}

	}
	cout << "End" << endl;

}