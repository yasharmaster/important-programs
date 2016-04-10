#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int is_prime(int p){
	
	for(int i=2; i<sqrt(p); i++){
		if(p%i == 0)
			return 0;
	}
	return 1;
	
}
void print_factors(int x){
	cout << x << " = ";
	
	int f = 2;
	while(f <= sqrt(x)){
		if(is_prime(f)){
			while(x%f == 0){
				cout << f;
				x /= f;
				cout << "*";
			}
		}
		f++;
	}
	if(x  > 1)
		cout << x;
	else
		cout <<"1";
}

int main()
{
	cout << "Enter a number		";
	int x;
	cin >> x;
	
	print_factors(x);

	return 0;
}
