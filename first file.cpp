#include <iostream>
#include <fstream>
using namespace std;
class delievery{
	protected:
		int id;
		char name,location;
		float price[20];
	public:
		delievery(){
			id = 0;
			name = 'null';
			price = 'qmpy';
			location ='where';
		}
		void Input(){
			cout<<"Enter Id :";cin>>id;
			cout<<"Enter name :";cin>>name;
			cout<<"Enter price :";cin>>price;
			cout<<"Enter location :";cin>>location;
		}
		void Output(){
			cout<<id<<" "<<name<<" "<<price<<" "<<location<<endl;
		}
};
int main(){
	Delievery del;
	int op,size,check,search;
	fstream file;
	do{
		cout<<"1. appent"<<endl;
		cout<<"2. Update"<<endl;
		cout<<"3. read"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. search"<<endl;
		cout<<" chose one option :";cin>>op;
		switch(op){
			case 1{
				file.open("text.bin",ios::app|ios::binary);
				cout<<"Enter size: ";cin>>size;
				for(int i = 0 ; i<size;i++){
					cout<<"================["<<i<<"]================"<<endl;
					test.Input();
					file.write((char*)&del,sizeof(del));
				}
				break;
			}
			case 2{
				cout<<"chose one option you want to update...";cin>>search;
				for(int i =0;i<size;i++){
					cout<<"==============["<<i+1<<"]==================="<<endl;
				}
				break;
			}
			case 3{
				file.open("text.bin",ios::in|ios::binary);
				while(file.read((char*)&del,sizeof(del))){
				del.Output();
				}
				break;
			}
		}
	}
}
