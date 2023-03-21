#include<iostream>;
using namespace std;
int main()
{
	double y, x, u, v, w;
	cout << "Enter x ";
	cin >> x;
	cout << "Enter v ";
	cin >> v;
	cout << "Enter w ";
	cin >> w;

	//y=x^59
	/*y = x * x; //x^2
	y *= y * y * x; //x^7
	y *= y; //x^14
	y *= y * x; //x^29
	y *= y * x; //x^59*/


	/*y = x * x; //x^2
	y *= y * x; //x^5
	y *= y; //x^10
	y *= y; //x^20
	y *= y * y; //x^60
	y = y * (1 / x);*/

    
	y = x * x * x; //3
	y *= y * x; //7
	y *= y; //14
	y *= y; //28
	y *= y; //56
	y *= x * x * x; //59

	cout << "y=" << y << endl;


	//u=v^71*w^103
	u = v * v * w * w; //v^2*w^2
	u = v * v * w * w; //v^4*w^4


	cout << "u=" <<u;
    return 0;
}
