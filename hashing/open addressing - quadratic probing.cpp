#include <iostream>


using namespace std;

const int MAX = 10;
int hashed(int k){
	return k%MAX;
}
int main()
{
	int hash_table[MAX];
	for(int i=0; i<MAX; i++)
		hash_table[i] = -1;

	for(int i=0; i<MAX; i++){
		int n;
		cin >> n;
		
		int j=0;
		while(hash_table[(hashed(n) + j*j)%10] != -1)
			j++;
		hash_table[(hashed(n) + j*j)%10] = n;
		
	}
	for(int i=0; i<MAX; i++)
		cout << hash_table[i] << "\t";
	return 0;
}
