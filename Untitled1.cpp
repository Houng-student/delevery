#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
void gotoy(){
	cout<<"\n\n\n\n\n";
}
void loadingBar(){
	char a=219;
	gotoy;
	cout<<"\t\t\t\t\tWelocome....."<<endl;
	cout<<"\t\t\t\t\t";
	for(int i;i<26;i++){
		Sleep(80);
		cout<<a;
	}
}
class Register{
	private:
		char username[20];
		char email[20];
		char pass[20];
	public:
		void Input(){
			Regis:
				gotoy();
			cout<<"\t\t\t\t  --------------- Register form ---------------------"<<endl<<endl;
			cout<<"\t\t\t\t\t   Enter Username :";gets(username);
			cout<<"\t\t\t\t\t   Enter Email    :";gets(email);
			cout<<"\t\t\t\t\t   Enter Password     :";gets(pass);
			cout<<"\t\t\t\t  ---------------------------------------------------"<<endl<<endl;
			if(strlen(pass)<8){
				cout<<"\t\t\t\t Your password must be 8 charactors...";
				getch();
				system("cls");
				goto Regis;
			}
		}
		char *getUsername(){
			return username;
		}
		char *getEmail(){
			return email;
		}
		char *getPass(){
			return pass;
		}
};
void Login(){
	Register arr[100],re;
	fstream file;
	char nameoremail[20],password[20];
	int count=0;
	file.open("UserRecord.bin",ios::app | ios::binary);
	while(file.read((char*)&re,sizeof(re))){
		arr[count]=re;
		count++;
	}
	again:
	gotoy();
	cout<<"\t\t\t\t  --------------- Login form ---------------------"<<endl<<endl;
	cout<<"\t\t\t\t\t   Enter nameoremail    :";gets(nameoremail);
	cout<<"\t\t\t\t\t   Enter Password       :";gets(password);
	cout<<"\t\t\t\t  ---------------------------------------------------"<<endl;
	for(int i=0;i<count;i++){
		if(((strcmp(nameoremail,arr[i].getUsername())==0)||(strcmp(nameoremail,arr[i].getEmail())==0) ) 
		&& (strcmp(password,arr[i].getPass())==0)){
			system("cls");
			loadingBar();
			break;
		}
		else{
			cout<<"\t\t\t\t\t    Invalid username email or password.";
			getch();
			system("cls");
			goto again;
		}
	}
	file.close();
}
void Regis(){
	Register re;
	fstream file;
	
	file.open("UserRecord.bin",ios::app | ios::binary);
	re.Input();
	file.write((char*)&re,sizeof(re))<<endl;
	
	file.close();
}
int main (){
	int op;
	sys:
	gotoy();
	cout<<"\t\t\t\t\t------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t|                                                                 "<<endl;
	cout<<"\t\t\t\t\t|                          DELIEVERY SYSTEM                       "<<endl;
	cout<<"\t\t\t\t\t|                                                                 "<<endl;
	cout<<"\t\t\t\t\t------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t|[1.sign in]                                           [2.Sign up]"<<endl;
	cout<<"\t\t\t\t\t------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t chose one option";cin>>op;
	if(op==1){
		system("cls");
		cin.ignore();
		Login();
	}else if(op==2){
		system("cls");
		cin.ignore();
		Regis();
		goto sys;
	}else{ 
	system("cls");
	goto sys;
    }
}
void Menu(){
	gotoy();
	cout<<"\t\t\t\t     --------------- Input form ------------------------"<<endl;
	cout<<"\t\t\t\t\t   |1.Write Data                                     |:"<<endl;
	cout<<"\t\t\t\t     ---------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t   |2.Read Data                                      |:"<<endl;
	cout<<"\t\t\t\t     ---------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t   |3.Update Data                                    |:"<<endl;
	cout<<"\t\t\t\t     ---------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t   |4.Delete Data                                    |:"<<endl;
}
class customer{
	private:
		int id;
		char name[20];
		char telephone[20];
		char time[20];
		char location[20];
	public:
		customer(){
			id=0;
			strcmp(name,"undifine");
			strcmp(telephone,"undifine");
			strcmp(location,"undifine");
			strcmp(time,"undifine");
		}
		void Input(){
			cout<<"Enter ID";cin>>id;
			cout<<"Enter Name";cin.ignore();gets(name);
			cout<<"Enter Tel";gets(telephone);
			cout<<"Enter time";gets(time);
			cout<<"Enter location";gets(location);
		}
};
int main(){
	Customer cus;
	fstream file;
	system ("cls");
	int op;
	do{
		Menu()[
		cout<<"\t\t\t\t   Enter one option";cin>>op;
		switch(op){
			case 1{
				system("cls");
				gotoy();
				file.open("customerRecord.bin",ios::app|ios::binary);
				cus.Input();
				file.write((char*)&cus,sizeof(cus));
				cout<<"\t\t\t\t   Data was recorded...";
				file.close();
				break;
			}
			case 2{
				file.read("customerRecord.bin",ios::in|ios::binary);
				while(file.read((char*))&cus,sizeof(cus));
				cus.Output();
				file.close();
				break;
			}
			case 3{
				int sid;
				fstream tmp;
				system("cls");
				file.open("customerRecord.bin";ios::in|ios::binary);
				tmp.open("tmp.bin";ios::out|ios::binary);
				updateagain;
				gotoy();
				int check;
				cout<<"\t\t\t\t  --------------- Login form ---------------------"<<endl<<endl;
				cout<<"\t\t\t\t\t   Enter Your ID you want to update    :";cin>>sid;cout<<endl;
				cout<<"\t\t\t\t  ---------------------------------------------------"<<endl;
				
				while(file.read(char*)&cus,sizeof(cus)){
					if(sid == cus.getID()){
						system("cls");
						gotoy();
						cus.Input(sid);
						tmp.write((char*)cus,sizeof(cus));
						check=1;
						cout<<"\t\t\t\t\t  Update succes...!"<<endl;
					}else{
						tmp.write((char*)cus,sizeof(cus));
					}
				}
				if(check==0){
					cout<<"\t\t\t\t\t  404 not found pleas try again.."<<endl;
					getch();
					system("cls");
					goto updateagain;
				}
				file.close();
				tmp.close();
				remove("customerRecord.bin");
				rename("Tmp.bin","customerRecord.bin");
				break;
			}
			case 4{
				int sid;
				fstream tmp;
				system("cls");
				file.open("customerRecord.bin";ios::in|ios::binary);
				tmp.open("tmp.bin";ios::out|ios::binary);
				updateagain;
				gotoy();
				int check;
				cout<<"\t\t\t\t  --------------- Login form ---------------------"<<endl<<endl;
				cout<<"\t\t\t\t\t   Enter Your ID you want to update    :";cin>>sid;cout<<endl;
				cout<<"\t\t\t\t  ---------------------------------------------------"<<endl;
				
				while(file.read(char*)&cus,sizeof(cus)){
					if(sid == cus.getID()){
						system("cls");
						gotoy();
						cout<<"haha"<<endl;
						tmp.write((char*)cus,sizeof(cus));
						check=1;
						cout<<"\t\t\t\t\t  Delete succes...!"<<endl;
					}else{
						tmp.write((char*)cus,sizeof(cus));
					}
				}
				if(check==0){
					cout<<"\t\t\t\t\t  404 not found pleas try again.."<<endl;
					getch();
					system("cls");
//					goto updateagain;
				}
				file.close();
				tmp.close();
				remove("customerRecord.bin");
				rename("Tmp.bin","customerRecord.bin");
				break;
			}
		}getch();
		system("cls");
	}while(op<5);
}

