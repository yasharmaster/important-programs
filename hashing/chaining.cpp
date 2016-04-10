#include <iostream>
#include <cstring>
#include <conio.h>

#define ll long long

using namespace std;
class bucket{
	public:
		ll data;
		bucket* next;
		bucket(ll phn){
			data = phn;
			next = NULL;
		}
};
class hash_table{
	public:
		bucket* link;
		hash_table(){
			link = NULL;
		}
		bool find_phone(ll phn){
			bucket* ptr = link;
			while(ptr != NULL){
				if(ptr->data == phn)
					return true;
				ptr = ptr->next;
			}
			return false;
		}
		void add_bucket(ll phn){
			if(!find_phone(phn)){
				bucket *temp = new bucket(phn);
				if (link == NULL)
					link = temp;
				else {
					bucket* ptr = link;
					while(ptr->next != NULL)
						ptr = ptr->next;
					ptr->next = temp;
				}
			}
		}
};
int main()
{
	hash_table phone[10];
	
	cout << "Enter the number of entries  ";
	ll n;
	cin >> n;
	
	while(n--){
		cout << "Enter a phone number  ";
		ll phn;
		cin >> phn;
		phone[phn%10].add_bucket(phn);
	}
	
	for(int i=0; i<10; i++){
		cout << i << "\t";
		bucket* ptr = phone[i].link;
		while(ptr != NULL){
			cout << ptr->data << "  ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	
	
	return 0;
}
