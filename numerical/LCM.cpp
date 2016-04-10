#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int euclid_gcd(int a, int b){
	while(b !=0){
		int p = (a>b) ? a :b;
		int d = (a>b) ? b :a;
		int rem = p%d;
		return euclid_gcd(d, rem);
	}
}

int lcm(int a, int b){
	return (a/euclid_gcd(a,b))*b;
}

int main()
{
	cout << lcm(45, 9);	

	return 0;
}
