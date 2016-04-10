#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

double curve(double x){
	return 1 + x + sin(2*x);
}

int main()
{
	cout << "Enter the number of intervals	";
	double n;
	cin >> n;
	
	double x1, x2;
	cout << "Enter the X coordinates  ";
	cin >> x1 >> x2;
	
	double dx = (x2-x1)/n;
	double total_area = 0;
	
	for(double x = x1; x <= (x2-dx); x += dx){
		total_area += curve(x)+curve(x + dx);					//modification
	}
	total_area *= dx/2;
	cout << "The approximate Area of the curve is " << total_area << ".\n";

	return 0;
}
