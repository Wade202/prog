#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include <string.h>
#include<malloc.h>
using namespace std;
int p,m;
#define SIZE 100
int count=0;
int countbk=0;
int countbkc=0;
int scount=0;
class User
{
	private:
		string name;
		string password;
		string birthday;
		string email;
		int number;
		double points;
		double money;
		string bookname;
	public:
	User() {};
		void Registers();								//ע���»�Ա
		void save();									//�洢���ĺ��Ա��Ϣ
		void read();									//
		void read0();									//
		void printDat(int i);							//��Ա������Ϣҳ
		void printinaf();								//����Ա�鿴��Ա������Ϣ
		void caidan();									//�˵� 
		void fname();									//��Ա��¼								
		void deletef();									//����Աɾ���û���Ϣ
}us;
User user[SIZE];

class Books
{
	private:
		string bookname;
		string author;
		double price;
		int inventory;
	public:
	    void book();									//����Ա����鼮��Ϣ
	    void readbook();								//
	    void saves();									//�洢���ĺ��鼮��Ϣ
	    void readbookc();								//
	    void printAll();								//��������鼮��Ϣ
	    string buyBooks(double *M,double *jf);
}books;
Books addbook[SIZE];

void empty()											//����һ���պ��������ڷ��������� 
{
	cout<<"";
}


void User::read0()
{   count =0;
	ifstream readf;
	readf.open("dat0.txt",ios::in);
	
	if(!readf.is_open())
	{
		cout<<"�ļ���ʧ��!"<<endl;
		return;
	}
	
	for(int i=0;!readf.eof();i++)
	{ 
		readf>>user[i].name;	
		readf>>user[i].password;
		readf>>user[i].birthday;
		readf>>user[i].email;
		readf>>user[i].points;
		readf>>user[i].money;
		readf>>user[i].number;
		count++;
	}
    count--;
    readf.close();
}


void User::read()
{   
   	scount=0;
	ifstream readf;
	readf.open("dat0.txt",ios::in);
	
	if(!readf.is_open())
	{
		cout<<"�ļ���ʧ��!"<<endl;
		return;
	}
	
	for(int i=0;!readf.eof();i++)
	{ 
		readf>>user[i].name;	
		readf>>user[i].password;
		readf>>user[i].birthday;
		readf>>user[i].email;
		readf>>user[i].points;
		readf>>user[i].money;
		readf>>user[i].number;
		readf>>user[i].bookname;
		scount++;
}
    readf.close();
}


void User::save()										//�洢���ĺ��Ա��Ϣ 
{
	ofstream openf;
	openf.open("dat0.txt",ios::out);
	for(int i=0;i<count;i++)
	{
		openf<<user[i].name<<endl;
		openf<<user[i].password<<endl;
		openf<<user[i].birthday<<endl;
		openf<<user[i].email<<endl;
		openf<<user[i].points<<endl;
		openf<<user[i].money<<endl;
		openf<<user[i].number<<endl;
		openf<<user[i].bookname<<endl;
	}
	openf.close();
}





void Books::saves()									//�洢���ĺ��鼮��Ϣ
{
	ofstream openf;
	openf.open("books.txt",ios::out);
	for(int i=0;i<countbk;i++)
	{
		openf<<addbook[i].bookname<<endl;
		openf<<addbook[i].author<<endl;
		openf<<addbook[i].price<<endl;
		openf<<addbook[i].inventory<<endl;
	}
	openf.close();
}


void Books::readbook()              //���ڶ�ȡ���� 
{
    countbk=0;
	ifstream readf;
	readf.open("books.txt",ios::in);
	
	if(!readf.is_open())
	{
		cout<<"�ļ���ʧ��!"<<endl;
		return;
	}
	
	for( int i=0;!readf.eof();i++)
	{
		readf>>addbook[i].bookname;
		readf>>addbook[i].author;
		readf>>addbook[i].price;
		readf>>addbook[i].inventory;
		countbk++;
}
    countbk--;
    readf.close();
}

void Books::readbookc()										//���ڼ��� 
{
	countbkc=0;
	ifstream readf;
	readf.open("books.txt",ios::in);
	
	if(!readf.is_open())
	{
		cout<<"�ļ���ʧ��!"<<endl;
		return;
	}
	
	for( int i=0;!readf.eof();i++)
	{
		readf>>addbook[i].bookname;
		readf>>addbook[i].author;
		readf>>addbook[i].price;
		readf>>addbook[i].inventory;
		countbkc++;
}
    readf.close();
}

void Books::printAll()									//��������鼮��Ϣ 
{
	books.readbookc();
	for(int i=0;i<countbkc-1;i++)
	{
		cout << endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��"<<"����:"<<addbook[i].bookname<<"��\t\n"<<endl;
		cout << "\t\t\t��"<<"����:"<<addbook[i].author<<"��\t\n"<<endl;
		cout << "\t\t\t��"<<"�۸�:"<<addbook[i].price<<"��\t\n"<<endl;
	    cout << "\t\t\t��"<<"���:"<<addbook[i].inventory<<"��\t\n"<<endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
	}
	
}

string Books::buyBooks(double *M,double *jf1)
{
	int choice0;
	double m1,m2;
	string b1,b2,b3;
	b3="-----";
	books.readbook();
	book:
	string bn;
	cout<<"������Ҫ���������:"<<endl;
	cin>>bn;
	cout<<"��ѡ����Ҫ����ķ�ʽ:"<<endl;
	cout<<"------------1--------��Ǯ����"<<endl;
	cout<<"------------2---------�û��ֹ���"<<endl;
	cin>>choice0;
	if(choice0==1)
	{
	
	for(int j=0;j<countbk;j++) 
	{
		if(bn==addbook[j].bookname)
		{
			if(addbook[j].inventory==0)
			{
				for (int m=j;m<countbk;m++)
			        {
			        	addbook[m] = addbook[m+1];
			        	books.saves();
					}
					countbk--;
				
			}
			else 
			{
			addbook[j].inventory=addbook[j].inventory-1;
			books.saves();
			cout<<"����ɹ�!"<<endl;
			b1=addbook[j].bookname;
			if(*M<addbook[j].price)
			{
				cout<<"Ǯ���������ֵ!"<<endl;
			}
			else
			{
			m1=*M-addbook[j].price;
			*M=m1;
			*jf1=*jf1+addbook[j].price/10;
			}
			cout<<"b1="<<b1;
			books.printAll();
			cout<<"�Ƿ�Ҫ���������鼮(Y/N)"<<endl;
			char choice;
	        while(1)
     {
		cin>>choice;
		if(choice=='y'||choice=='Y'||choice=='n'||choice=='N')
		  break;
		  else
		  cout<<"�����ʽ��������������";
	 }
	 if (choice=='n'||choice=='N')
	 {
     	b2=b1+b3+b2;
	    return b2;
	 }
	 else if(choice=='y'||choice=='Y')
	 {
	 	b2=b1+b3+b2;
	 	goto book;
	 }
	 
		    }
		}
	}
}

else if(choice0==2)
{
		for(int k=0;k<countbk;k++) 
	{
		if(bn==addbook[k].bookname)
		{
			if(addbook[k].inventory==0)
			{
				for (int l=k;l<countbk;l++)
			        {
			        	addbook[l] = addbook[l+1];
			        	books.saves();
					}
					countbk--;
				
			}
			else 
			{
			addbook[k].inventory=addbook[k].inventory-1;
			books.saves();
			cout<<"����ɹ�!"<<endl;
			b1=addbook[k].bookname;
			if(*jf1<addbook[k].price)
			{
				cout<<"���ֲ��������ֵ!"<<endl;
				exit(0);
			}
			else
			{
			m1=*jf1-addbook[k].price;
			*jf1=m1;
			*jf1=m1+addbook[k].price/10;
			}
			books.printAll();
			cout<<"�Ƿ�Ҫ���������鼮(Y/N)"<<endl;
			char choice1;
	        while(1)
     {
		cin>>choice1;
		if(choice1=='y'||choice1=='Y'||choice1=='n'||choice1=='N')
		  break;
		  else
		  cout<<"�����ʽ��������������";
	 }
	 if (choice1=='n'||choice1=='N')
	 {
     	b2=b1+b3+b2;
	    return b2;
	 }
	 else if(choice1=='y'||choice1=='Y')
	 {
	 	b2=b1+b3+b2;
	 	goto book;
	 }
		    }
		}
	}
}
	
	cout<<"û�и��鼮!"<<endl; 
	cout<<"����������!"<<endl;
	goto book;
}


void User::deletef()									//����Աɾ���û���Ϣ 
{
	string name;
	int n,x;
	here1:
	cout<<"��������ɾ�����û�����"<<endl; 
	cin>>name;
	for(int i=0;i<scount;i++)							//�ҵ�����Ա��ɾ���û���λ�� 
	{
		if(name == user[i].name)
		{
			n=i;
			break;
		}
	}
	for(;n<scount;n++)									//�ú������Ϣ����ǰ�����Ϣ 
	{
	    user[n]=user[n+1];	
		us.save();
	}
	count--;
	scount--;
	cout<<"ɾ���ɹ�!"<<endl;
	here2:
	cout<<"�Ƿ�Ҫ����ɾ��"<<endl;
	cout<<"----1----����ɾ��"<<endl; 
	cout<<"----2----����"<<endl; 
	cin>>x;
	if(x==1)
		goto here1;
	if(x==2)
		empty();
	else if(x!=2&&x!=1)
	{
		cout<<"�������"<<endl;
		goto here2; 
	}
	
	
	
	
}

void User::printinaf()									//����Ա�鿴��Ա������Ϣ 
{
	us.read();
	int  i;
	for(int i=0;i<scount-1;i++)
	{
		cout<<"��"<<i+1<<"���û�"<<endl;
		cout<<"\t\t\t\t�û���:\t\t\t\t"<<user[i].name<<endl;
		cout<<"\t\t\t\t����:\t\t\t\t"<<user[i].password<<endl;
		cout<<"\t\t\t\t����:\t\t\t\t"<<user[i].birthday<<endl;
		cout<<"\t\t\t\t����:\t\t\t\t"<<user[i].email<<endl;
		cout<<"\t\t\t\tʣ�����\t\t\t\t"<<user[i].points<<endl;
		cout<<"\t\t\t\t��ʣ��Ǯ\t\t\t\t"<<user[i].money<<endl;
		cout<<"\t\t\t\t��Ա���:\t\t\t\t\t"<<user[i].number<<endl;
		cout<<"\t\t\t\t�����¼:\t\t\t\t\t"<<user[i].bookname<<endl;
	}
	cout<<"----1----ɾ����Ա"<<endl;
	cout<<"----2----����"<<endl;
	cin>>i;	
	while(1)
	{
		if(i==1)
		{
			us.deletef();
			break;
		}
		if(i==2)
		{
			break;
		}
		if(i!=1&&i!=2)
		{
			cout<<"�������"<<endl;
			break;
		}
	}
}


void User::fname()												//��Ա��¼ 
{
	int x=0;
	us.read();
	string name;
	string pass;
	here1:
		cout<<"�������û���:";
		cin>>name;
		for(int i=0;i<scount;i++)
		{
		 	if(name == user[i].name)
		  	{
				agpass:	  	
				cout<<"����������:"<<endl;
				cin>>pass;
				if(pass.compare(user[i].password)==0)
					{
						cout<<"��¼�ɹ�!"<<endl;
						us.printDat(i);							//��Ա������Ϣҳ
					}
   				else 
					{
						cout<<"�������!���ٴ�����!";
						goto agpass;
					}
				x=1;
		  	}
		}
		if(x==0)
		{
			cout<<"û�и��û���!"<<endl;
			goto here1;
		}
		
}



void Books::book()									//����Ա����鼮��Ϣ 
{   
	books.readbook();
	string bm1;
	string bm;
	string at;
	int x; 
	double pr;
	int inv;
	cout<<"----1.����鼮----"<<endl;
	cout<<"----2.��ӿ��----"<<endl; 
	cin>>x;
	if(x==1)
	{
		for(int i = countbk;i<SIZE;i++)
		{   
			here: 
				cout<<"������Ҫ��ӵ�����:";
				cin>>bm;
				for(int i=0;i<countbk;i++)
				{
					if(bm == addbook[i].bookname)
		  			{
						cout<<"�����Ѵ���!"<<endl;
						goto here;
			 		 }
				}
			int j=countbk;
			addbook[j].bookname = bm;
			cout<<"�������������ߣ�";
			cin>>at;
			addbook[j].author =at;
			cout<<"���������ļ۸�(��λ����)��";
			cin>>pr;
			addbook[j].price = pr;
			cout<<"���������Ŀ�棺";
			cin>>inv;
			addbook[j].inventory = inv;
			countbk++;
			books.saves();
			cout<<"��ӳɹ�!";
			char choice;
			cout<<"�Ƿ������ӣ�Y/N��?"; 
			while(1)
			{
				cin>>choice;
				if(choice=='y'||choice=='Y'||choice=='n'||choice=='N')
				    break;
				else
			  		cout<<"�����ʽ��������������";
			}
			if (choice=='n'||choice=='N')
			{
			 	break;
			} 
		}	
	}
	if(x==2)
	{
		cout<<"�������鼮���֣�"<<endl;
		cin>>bm1;
		for(int j = countbk;j<SIZE;j++)
		{
			if(bm == addbook[j].bookname)
			{
		 		cout<<"��������:"<<endl;
		 		cin>>inv;
		 		addbook[j].inventory=inv;
				break;		
			}	
		}
	}
}


void manage()											//����Ա��¼��� 
{
	char name[20]; 
	int c;
	char pass[20];
	int cho;
	here1:
	cout<<"���������Ա�˻���:"<<endl;
	cin>>name;
	if(strcmp(name,"wade0")==0||(name,"xizai"))
	{	
		cout<<"����������:"<<endl;
		cin>>pass;
		if(strcmp(pass,"7410")==0)
		{	
 			cout<<"��½�ɹ�!"<<endl;
 			cout<<"----1----�鿴���еĻ�Ա"<<endl;
 			cout<<"----2----����������ӿ��"<<endl;
 			cin>>cho;
 			if(cho==1)
 				us.printinaf();
  			else if(cho==2)
   				books.book();
		}
	}
	else 
	{
		cout<<"û�иù���Ա!"<<endl;
		cout<<"������¼---1---"<<endl;
		cout<<"�������˵�---2---"<<endl;
		cin>>c;
		if(c==1)
		goto here1;
		else if(c==2)
			us.caidan();
		else 
			cout<<"��ʽ����!";
	}
}


void User::printDat(int i)								//��Ա������Ϣҳ 
{	
    us.read();
	double jf;
    string nm;
	string psw;
	string Em;
	string Bd;
	string bookname;
	double my;
    int chioce;
    int chioce3;
    int chioce4;
    int n;
    char chioce2;
    loop1:
	cout<<"����������������������Ϣҳ��������������������"<<endl;
	cout<<"�������������û���:��������"<<user[i].name<<endl;
	cout<<"����������������:����������"<<user[i].password<<endl;
	cout<<"����������������:����������"<<user[i].birthday<<endl;
	cout<<"����������������:����������"<<user[i].email<<endl;
	cout<<"������������:������������"<<user[i].points<<endl;
	cout<<"����������ʣ��Ǯ:��������"<<user[i].money<<endl; 
	cout<<"�����������Ļ�Ա���:������"<<user[i].number<<endl;
	cout<<"�������������¼:������"<<user[i].bookname<<endl;
	cout<<"�޸ĸ�����Ϣ�밴Y:"<<endl;
	cout<<"��ֵ�밴Q"<<endl;
	cout<<"�һ������밴C"<<endl; 
	cout<<"����ͼ���밴M"<<endl;
	cout<<"��0�˳�"<<endl; 
	cin>>chioce2;
	if(chioce2=='y'||chioce2=='Y')
	{
  		cout<<"��ѡ����Ҫ�޸ĵ�����:"<<endl;
  		cout<<"---1---����"<<endl;
  		cout<<"---2---����"<<endl;
  		cout<<"---3---����"<<endl;
  		cout<<"---0---����"<<endl;
  		cin>>chioce;
	  	if(chioce==1)
	    {
	    	cout<<"�������޸ĺ����룺"<<endl;
	    	cin>>psw;
			user[i].password =psw;
			us.save();
		}
		else if(chioce==2)
		{
			cout<<"�������޸ĺ����䣺"<<endl; 
			user[i].email = Em;
			us.save();	
		}
		else if(chioce==3)
		{
			cout<<"�������޸ĺ����գ�"<<endl;
			cin>>Bd;
			user[i].birthday = Bd;
			us.save();
		}
		else if(chioce==0)
		{
		goto loop1;
		}
	    else cout<<"��ʽ����";
	}
	else if (chioce2=='Q'||chioce2=='q')
	{
		cout<<"��������Ҫ��ֵ����Ŀ"<<endl;
		cin>>my;
		user[i].money=my+user[i].money;
		us.save();
		cout<<"����������ֵ�ɹ�!��������" ; 
		cout<<"����������0������������"<<endl;
		int chioce2;
		cin>>chioce2;
		if (chioce2==0)
		us.printDat(i);
	}
	else if (chioce2=='C' || chioce2=='c')
	{
		cout<<"��Ľ�Ǯ:"<<endl;
		cout<<user[i].money<<endl;
		cout<<"��Ļ���:"<<endl;
		cout<<user[i].points<<endl;
		if(user[i].money<1)
		{
			cout<<"1Ԫ�һ�һ������"<<endl;
			cout<<"��Ǯ����,���ֵ!"<<endl;
		}
		else
		{
		  duih:
		  cout<<"��ѡ��һ��Ļ�����Ŀ:"<<endl;
		  cout<<"------1----�һ�1����"<<endl;
		  cout<<"------2----�һ�10����"<<endl;
		  cout<<"------3----�һ�100����"<<endl;
		  cin>>chioce4;
		  if(chioce4==1)
		  {
		  user[i].money=user[i].money-1;
		  user[i].points=user[i].points+1;
		  cout<<"�һ��ɹ�!"<<endl;
		  us.save();
		  empty();
	      }
	      else if(chioce4==2)
	      {
	      	user[i].money=user[i].money-10;
	      	user[i].points=user[i].points+10;
	      	cout<<"�һ��ɹ�!"<<endl;
	      	us.save();
	      	empty();
		  }
		  else if(chioce4==3)
		  {
		    user[i].money=user[i].money-100;
	      	user[i].points=user[i].points+100;
	      	cout<<"�һ��ɹ�!"<<endl;
	      	us.save();
	      	empty();
		  }
		  else
		  {
		  	cout<<"��ʽ����!"<<endl;
			goto duih; 
		  }
		}
	}	
	else if (chioce2=='M' || chioce2=='m')
	{
	double *jf;        //ָ����ֵ�ָ�� 
	double *moneyj; //ָ��Ǯ��ָ�� 
	moneyj=&user[i].money;
	jf=&user[i].points;
	books.printAll();
	user[i].bookname=books.buyBooks(*&moneyj,*&jf)+user[i].bookname;				//�����¼���� 
	us.save();
}
	else if(chioce==0)
		empty();
}

void User::Registers()									//ע���»�Ա 
{
	us.read0();
	string nm;
	string psw;
	string Em;
	string Bd;
	for(int i = count;i<SIZE;i++)
	{   
		here: 
			cout<<"�������û���:";
			cin>>nm;
		for(int i=0;i<count;i++)
		{if(nm == user[i].name)
		    {
				cout<<"���û��Ѵ���!"<<endl;
				goto here;
		  	}
		}
		int j=count;
		user[j].name = nm;
		cout<<"���������룺";
		cin>>psw;
		user[j].password =psw;
		cout<<"������������գ�";
		cin>>Bd;
		user[j].birthday = Bd;
		cout<<"������������䣺";
		cin>>Em;
		user[j].email = Em;
		int num=1000+count;
		user[j].points=0;
		user[j].money=0;
		user[j].number=num;
		user[j].bookname="����";
		count++;
		cout<<"ע��ɹ�!";
		us.save();
		char choice;
		cout<<"�Ƿ����ע�ᣨY/N��?"; 
		while(1)
		{
			cin>>choice;
			if(choice=='y'||choice=='Y'||choice=='n'||choice=='N')
				break;
			else
		    	cout<<"�����ʽ��������������";
		}
	 		if (choice=='n'||choice=='N')
	 		{
	 			break;
			} 
	}
}




void User::caidan()									//�˵� 
{ 
	cout<<"\t\t\t\t---1---��Ա��¼���\t\t\t\t"<<endl;
  	cout<<"\t\t\t\t---2---����Ա���\t\t\t\t"<<endl;
 	 cout<<"\t\t\t\t---3---ע��\t\t\t\t"<<endl;
 	 cout<<"\t\t\t\t---0---�˳�ϵͳ\t\t\t\t"<<endl;
}


int main()
{
	User user;
	cout<<"\t\t\t\t\t-----****ͼ������ϵͳ****------\t\t\t\t\t"<<endl;
	while(1)
	{
     	int i;
     	empty();						  //����һ���պ��������ڷ���������
     	us.caidan();					  //�˵� 
     	cout<<"�����룺";
     	cin>>i;
     	if(i==1) us.fname();              //��Ա��¼��� 
     	else if(i==2) manage();           //����Ա��� 
     	else if(i==3) us.Registers();     //ע���»�Ա 
     	else if(i==0) exit(0);			  //�˳� ϵͳ 
     }
}
