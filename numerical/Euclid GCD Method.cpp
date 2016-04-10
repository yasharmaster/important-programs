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

int main()
{
	cout << euclid_gcd(27, 81);	

	return 0;
}
