#include <iostream>
#include <fstream>
using namespace std;
class product
{
	public:
	char name[25];
	float price;
	string product_code;
	void display(){
    cout<<name<<endl;
    cout<<price<<endl;
  }
  
	void input(){
		cin>>name;
		cin>>price>>product_code;
	}
};
int main(){
	fstream f1; product p;
	// char ch='y';
	f1.open("Products.txt",ios::out|ios::app);
	// f1.seekp(sizeof(p));
	for (int i = 0; i < 4; ++i)
	{
		p.input();
		f1<<p.name<<" "<<p.price<<""
		cout<<"entered"<<endl;
		// cin>>ch;  
	}
	
	f1.close();
}