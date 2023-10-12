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
		void Registers();								//注册新会员
		void save();									//存储更改后会员信息
		void read();									//
		void read0();									//
		void printDat(int i);							//会员个人信息页
		void printinaf();								//管理员查看会员个人信息
		void caidan();									//菜单 
		void fname();									//会员登录								
		void deletef();									//管理员删除用户信息
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
	    void book();									//管理员添加书籍信息
	    void readbook();								//
	    void saves();									//存储更改后书籍信息
	    void readbookc();								//
	    void printAll();								//输出所有书籍信息
	    string buyBooks(double *M,double *jf);
}books;
Books addbook[SIZE];

void empty()											//这是一个空函数，用于返回主函数 
{
	cout<<"";
}


void User::read0()
{   count =0;
	ifstream readf;
	readf.open("dat0.txt",ios::in);
	
	if(!readf.is_open())
	{
		cout<<"文件打开失败!"<<endl;
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
		cout<<"文件打开失败!"<<endl;
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


void User::save()										//存储更改后会员信息 
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





void Books::saves()									//存储更改后书籍信息
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


void Books::readbook()              //用于读取数据 
{
    countbk=0;
	ifstream readf;
	readf.open("books.txt",ios::in);
	
	if(!readf.is_open())
	{
		cout<<"文件打开失败!"<<endl;
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

void Books::readbookc()										//用于计数 
{
	countbkc=0;
	ifstream readf;
	readf.open("books.txt",ios::in);
	
	if(!readf.is_open())
	{
		cout<<"文件打开失败!"<<endl;
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

void Books::printAll()									//输出所有书籍信息 
{
	books.readbookc();
	for(int i=0;i<countbkc-1;i++)
	{
		cout << endl;
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃"<<"书名:"<<addbook[i].bookname<<"┃\t\n"<<endl;
		cout << "\t\t\t┃"<<"作者:"<<addbook[i].author<<"┃\t\n"<<endl;
		cout << "\t\t\t┃"<<"价格:"<<addbook[i].price<<"┃\t\n"<<endl;
	    cout << "\t\t\t┃"<<"库存:"<<addbook[i].inventory<<"┃\t\n"<<endl;
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
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
	cout<<"输入你要购买的书名:"<<endl;
	cin>>bn;
	cout<<"请选择你要购买的方式:"<<endl;
	cout<<"------------1--------用钱购买"<<endl;
	cout<<"------------2---------用积分购买"<<endl;
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
			cout<<"购买成功!"<<endl;
			b1=addbook[j].bookname;
			if(*M<addbook[j].price)
			{
				cout<<"钱不够，请充值!"<<endl;
			}
			else
			{
			m1=*M-addbook[j].price;
			*M=m1;
			*jf1=*jf1+addbook[j].price/10;
			}
			cout<<"b1="<<b1;
			books.printAll();
			cout<<"是否要继续购买书籍(Y/N)"<<endl;
			char choice;
	        while(1)
     {
		cin>>choice;
		if(choice=='y'||choice=='Y'||choice=='n'||choice=='N')
		  break;
		  else
		  cout<<"输入格式错误，请重新输入";
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
			cout<<"购买成功!"<<endl;
			b1=addbook[k].bookname;
			if(*jf1<addbook[k].price)
			{
				cout<<"积分不够，请充值!"<<endl;
				exit(0);
			}
			else
			{
			m1=*jf1-addbook[k].price;
			*jf1=m1;
			*jf1=m1+addbook[k].price/10;
			}
			books.printAll();
			cout<<"是否要继续购买书籍(Y/N)"<<endl;
			char choice1;
	        while(1)
     {
		cin>>choice1;
		if(choice1=='y'||choice1=='Y'||choice1=='n'||choice1=='N')
		  break;
		  else
		  cout<<"输入格式错误，请重新输入";
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
	
	cout<<"没有该书籍!"<<endl; 
	cout<<"请重新输入!"<<endl;
	goto book;
}


void User::deletef()									//管理员删除用户信息 
{
	string name;
	int n,x;
	here1:
	cout<<"请输入想删除的用户名："<<endl; 
	cin>>name;
	for(int i=0;i<scount;i++)							//找到管理员想删除用户的位置 
	{
		if(name == user[i].name)
		{
			n=i;
			break;
		}
	}
	for(;n<scount;n++)									//用后面的信息覆盖前面的信息 
	{
	    user[n]=user[n+1];	
		us.save();
	}
	count--;
	scount--;
	cout<<"删除成功!"<<endl;
	here2:
	cout<<"是否要继续删除"<<endl;
	cout<<"----1----继续删除"<<endl; 
	cout<<"----2----返回"<<endl; 
	cin>>x;
	if(x==1)
		goto here1;
	if(x==2)
		empty();
	else if(x!=2&&x!=1)
	{
		cout<<"输入错误！"<<endl;
		goto here2; 
	}
	
	
	
	
}

void User::printinaf()									//管理员查看会员个人信息 
{
	us.read();
	int  i;
	for(int i=0;i<scount-1;i++)
	{
		cout<<"第"<<i+1<<"个用户"<<endl;
		cout<<"\t\t\t\t用户名:\t\t\t\t"<<user[i].name<<endl;
		cout<<"\t\t\t\t密码:\t\t\t\t"<<user[i].password<<endl;
		cout<<"\t\t\t\t生日:\t\t\t\t"<<user[i].birthday<<endl;
		cout<<"\t\t\t\t邮箱:\t\t\t\t"<<user[i].email<<endl;
		cout<<"\t\t\t\t剩余积分\t\t\t\t"<<user[i].points<<endl;
		cout<<"\t\t\t\t所剩金钱\t\t\t\t"<<user[i].money<<endl;
		cout<<"\t\t\t\t会员编号:\t\t\t\t\t"<<user[i].number<<endl;
		cout<<"\t\t\t\t购买记录:\t\t\t\t\t"<<user[i].bookname<<endl;
	}
	cout<<"----1----删除会员"<<endl;
	cout<<"----2----返回"<<endl;
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
			cout<<"输入错误！"<<endl;
			break;
		}
	}
}


void User::fname()												//会员登录 
{
	int x=0;
	us.read();
	string name;
	string pass;
	here1:
		cout<<"请输入用户名:";
		cin>>name;
		for(int i=0;i<scount;i++)
		{
		 	if(name == user[i].name)
		  	{
				agpass:	  	
				cout<<"请输入密码:"<<endl;
				cin>>pass;
				if(pass.compare(user[i].password)==0)
					{
						cout<<"登录成功!"<<endl;
						us.printDat(i);							//会员个人信息页
					}
   				else 
					{
						cout<<"密码错误!请再次输入!";
						goto agpass;
					}
				x=1;
		  	}
		}
		if(x==0)
		{
			cout<<"没有该用户名!"<<endl;
			goto here1;
		}
		
}



void Books::book()									//管理员添加书籍信息 
{   
	books.readbook();
	string bm1;
	string bm;
	string at;
	int x; 
	double pr;
	int inv;
	cout<<"----1.添加书籍----"<<endl;
	cout<<"----2.添加库存----"<<endl; 
	cin>>x;
	if(x==1)
	{
		for(int i = countbk;i<SIZE;i++)
		{   
			here: 
				cout<<"请输入要添加的书名:";
				cin>>bm;
				for(int i=0;i<countbk;i++)
				{
					if(bm == addbook[i].bookname)
		  			{
						cout<<"该书已存在!"<<endl;
						goto here;
			 		 }
				}
			int j=countbk;
			addbook[j].bookname = bm;
			cout<<"请输入该书的作者：";
			cin>>at;
			addbook[j].author =at;
			cout<<"请输入该书的价格(单位：￥)：";
			cin>>pr;
			addbook[j].price = pr;
			cout<<"请输入该书的库存：";
			cin>>inv;
			addbook[j].inventory = inv;
			countbk++;
			books.saves();
			cout<<"添加成功!";
			char choice;
			cout<<"是否继续添加（Y/N）?"; 
			while(1)
			{
				cin>>choice;
				if(choice=='y'||choice=='Y'||choice=='n'||choice=='N')
				    break;
				else
			  		cout<<"输入格式错误，请重新输入";
			}
			if (choice=='n'||choice=='N')
			{
			 	break;
			} 
		}	
	}
	if(x==2)
	{
		cout<<"请输入书籍名字："<<endl;
		cin>>bm1;
		for(int j = countbk;j<SIZE;j++)
		{
			if(bm == addbook[j].bookname)
			{
		 		cout<<"请输入库存:"<<endl;
		 		cin>>inv;
		 		addbook[j].inventory=inv;
				break;		
			}	
		}
	}
}


void manage()											//管理员登录入口 
{
	char name[20]; 
	int c;
	char pass[20];
	int cho;
	here1:
	cout<<"请输入管理员账户名:"<<endl;
	cin>>name;
	if(strcmp(name,"wade0")==0||(name,"xizai"))
	{	
		cout<<"请输入密码:"<<endl;
		cin>>pass;
		if(strcmp(pass,"7410")==0)
		{	
 			cout<<"登陆成功!"<<endl;
 			cout<<"----1----查看所有的会员"<<endl;
 			cout<<"----2----添加新书或添加库存"<<endl;
 			cin>>cho;
 			if(cho==1)
 				us.printinaf();
  			else if(cho==2)
   				books.book();
		}
	}
	else 
	{
		cout<<"没有该管理员!"<<endl;
		cout<<"继续登录---1---"<<endl;
		cout<<"返回主菜单---2---"<<endl;
		cin>>c;
		if(c==1)
		goto here1;
		else if(c==2)
			us.caidan();
		else 
			cout<<"格式错误!";
	}
}


void User::printDat(int i)								//会员个人信息页 
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
	cout<<"————————个人信息页——————————"<<endl;
	cout<<"————您的用户名:————"<<user[i].name<<endl;
	cout<<"————您的密码:—————"<<user[i].password<<endl;
	cout<<"————您的生日:—————"<<user[i].birthday<<endl;
	cout<<"————您的邮箱:—————"<<user[i].email<<endl;
	cout<<"————积分:——————"<<user[i].points<<endl;
	cout<<"————所剩金钱:————"<<user[i].money<<endl; 
	cout<<"————您的会员编号:———"<<user[i].number<<endl;
	cout<<"————购买记录:———"<<user[i].bookname<<endl;
	cout<<"修改个人信息请按Y:"<<endl;
	cout<<"充值请按Q"<<endl;
	cout<<"兑换积分请按C"<<endl; 
	cout<<"购买图书请按M"<<endl;
	cout<<"按0退出"<<endl; 
	cin>>chioce2;
	if(chioce2=='y'||chioce2=='Y')
	{
  		cout<<"请选择您要修改的内容:"<<endl;
  		cout<<"---1---密码"<<endl;
  		cout<<"---2---邮箱"<<endl;
  		cout<<"---3---生日"<<endl;
  		cout<<"---0---返回"<<endl;
  		cin>>chioce;
	  	if(chioce==1)
	    {
	    	cout<<"请输入修改后密码："<<endl;
	    	cin>>psw;
			user[i].password =psw;
			us.save();
		}
		else if(chioce==2)
		{
			cout<<"请输入修改后邮箱："<<endl; 
			user[i].email = Em;
			us.save();	
		}
		else if(chioce==3)
		{
			cout<<"请输入修改后生日："<<endl;
			cin>>Bd;
			user[i].birthday = Bd;
			us.save();
		}
		else if(chioce==0)
		{
		goto loop1;
		}
	    else cout<<"格式错误";
	}
	else if (chioce2=='Q'||chioce2=='q')
	{
		cout<<"请输入您要充值的数目"<<endl;
		cin>>my;
		user[i].money=my+user[i].money;
		us.save();
		cout<<"————充值成功!————" ; 
		cout<<"————按0————返回"<<endl;
		int chioce2;
		cin>>chioce2;
		if (chioce2==0)
		us.printDat(i);
	}
	else if (chioce2=='C' || chioce2=='c')
	{
		cout<<"你的金钱:"<<endl;
		cout<<user[i].money<<endl;
		cout<<"你的积分:"<<endl;
		cout<<user[i].points<<endl;
		if(user[i].money<1)
		{
			cout<<"1元兑换一个积分"<<endl;
			cout<<"金钱不够,请充值!"<<endl;
		}
		else
		{
		  duih:
		  cout<<"请选择兑换的积分数目:"<<endl;
		  cout<<"------1----兑换1积分"<<endl;
		  cout<<"------2----兑换10积分"<<endl;
		  cout<<"------3----兑换100积分"<<endl;
		  cin>>chioce4;
		  if(chioce4==1)
		  {
		  user[i].money=user[i].money-1;
		  user[i].points=user[i].points+1;
		  cout<<"兑换成功!"<<endl;
		  us.save();
		  empty();
	      }
	      else if(chioce4==2)
	      {
	      	user[i].money=user[i].money-10;
	      	user[i].points=user[i].points+10;
	      	cout<<"兑换成功!"<<endl;
	      	us.save();
	      	empty();
		  }
		  else if(chioce4==3)
		  {
		    user[i].money=user[i].money-100;
	      	user[i].points=user[i].points+100;
	      	cout<<"兑换成功!"<<endl;
	      	us.save();
	      	empty();
		  }
		  else
		  {
		  	cout<<"格式错误!"<<endl;
			goto duih; 
		  }
		}
	}	
	else if (chioce2=='M' || chioce2=='m')
	{
	double *jf;        //指向积分的指针 
	double *moneyj; //指向钱的指针 
	moneyj=&user[i].money;
	jf=&user[i].points;
	books.printAll();
	user[i].bookname=books.buyBooks(*&moneyj,*&jf)+user[i].bookname;				//购买记录储存 
	us.save();
}
	else if(chioce==0)
		empty();
}

void User::Registers()									//注册新会员 
{
	us.read0();
	string nm;
	string psw;
	string Em;
	string Bd;
	for(int i = count;i<SIZE;i++)
	{   
		here: 
			cout<<"请输入用户名:";
			cin>>nm;
		for(int i=0;i<count;i++)
		{if(nm == user[i].name)
		    {
				cout<<"该用户已存在!"<<endl;
				goto here;
		  	}
		}
		int j=count;
		user[j].name = nm;
		cout<<"请输入密码：";
		cin>>psw;
		user[j].password =psw;
		cout<<"请输入你的生日：";
		cin>>Bd;
		user[j].birthday = Bd;
		cout<<"请输入你的邮箱：";
		cin>>Em;
		user[j].email = Em;
		int num=1000+count;
		user[j].points=0;
		user[j].money=0;
		user[j].number=num;
		user[j].bookname="暂无";
		count++;
		cout<<"注册成功!";
		us.save();
		char choice;
		cout<<"是否继续注册（Y/N）?"; 
		while(1)
		{
			cin>>choice;
			if(choice=='y'||choice=='Y'||choice=='n'||choice=='N')
				break;
			else
		    	cout<<"输入格式错误，请重新输入";
		}
	 		if (choice=='n'||choice=='N')
	 		{
	 			break;
			} 
	}
}




void User::caidan()									//菜单 
{ 
	cout<<"\t\t\t\t---1---会员登录入口\t\t\t\t"<<endl;
  	cout<<"\t\t\t\t---2---管理员入口\t\t\t\t"<<endl;
 	 cout<<"\t\t\t\t---3---注册\t\t\t\t"<<endl;
 	 cout<<"\t\t\t\t---0---退出系统\t\t\t\t"<<endl;
}


int main()
{
	User user;
	cout<<"\t\t\t\t\t-----****图书销售系统****------\t\t\t\t\t"<<endl;
	while(1)
	{
     	int i;
     	empty();						  //这是一个空函数，用于返回主函数
     	us.caidan();					  //菜单 
     	cout<<"请输入：";
     	cin>>i;
     	if(i==1) us.fname();              //会员登录入口 
     	else if(i==2) manage();           //管理员入口 
     	else if(i==3) us.Registers();     //注册新会员 
     	else if(i==0) exit(0);			  //退出 系统 
     }
}
