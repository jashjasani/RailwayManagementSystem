//author: Jash Jasani , Dharmik Malaviya , Falgun Gohel , Jainam Doshi


#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<iostream>
using namespace std;
void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void add_train();
void delete_train();
void awrite();
void aread();
void bookticket_write();
void viewpassengers_read();

int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];

class adddata
{  public:
	char si[10];
	char train_number[10];
	char train_name[100];
	char start[100];
	char destination[100];
	char price[10];
	int seat;
	char time[10];
}add[1000];

class bookticket
{  public:
	char train_number[20];
	char name[100];
	char phone[20];
	char date[20];
	int seat;
}book_ticket[1000];


int main()
{
	aread();
	viewpassengers_read();
	system("COLOR 4f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	cout<<"\n\t\t\t     "<<ctime(&currentTime)<<"\n";

	cout<<"\n\t\t\t*********************************\n";
	cout<<"\t\t\t---RAILWAY RESERVATION SYSTEM----\n";
	cout<<"\t\t\t*********************************\n";
	cout<<"\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
	cout<<"\n\n\t\t\t\t      MENU\n";
	cout<<"\t\t\t             ******";
	cout<<"\n\t\t\t[1] VIEW INFORMATION\n";
	cout<<"\n\t\t\t[2] BOOK TICKET\n";
	cout<<"\n\t\t\t[3] CANCEL TICKET\n";
	cout<<"\n\t\t\t[4] ADMIN";
	cout<<"\n\n\t\t\t[5] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";

	cin>>ch;
	switch(ch)
	{
		case 1:
		    system("COLOR 2f");
			viewinfo();
			break;
        case 2:
            system("COLOR 6f");
            bookticket();
            break;
        case 3:
            system("COLOR 9f");
            cancelticket();
            break;
        case 4:
            system("COLOR 1f");
            password();
            break;
        case 5:
            system("cls");
            cout<<"\n\t\t\t =========================================\n";
            cout<<"\t\t\t -------RAILWAY RESERVATION SYSTEM--------\n";
            cout<<"\t\t\t -----------------------------------------\n";
            cout<<"\t\t\t -----------THANKS FOR VISITING-----------\n";
            cout<<"\t\t\t =========================================\n";
            getch();
            exit(0);
            break;
        default:
            system("cls");
            cout<<"\n\t\t\t==============================================\n";
            cout<<"\t\t\t   ----------RAILWAY RESERVATION SYSTEM----------\n";
            cout<<"\t\t\t   ==============================================\n";
            cout<<"\n\n\t\t\t!!!!!!!!YOU ENTERED WRONG CHOICE!!!!!!!!\n";
            cout<<"\n\n\t\t\t===========START AGAIN PLEASE===========\n";
            system("cls");
            exit(0);
	}
	return 0;
}
void bookticket()
{
	int c,j,n,i,found=-1;
	char v,train_number[10];
	system("cls");
	aread();
	cout<<"\n\n\t\t\t==============================================";
	cout<<"\n\t\t\t----------RAILWAY RESERVATION SYSTEM----------\n";
	cout<<"\t\t\t==============================================";
	cout<<"\n\n\t\t\t how many ticket do you want to buy: ";
	cin>>n;
	for(j=u;j<u+n;j++)
	{
        cout<<"\n\n\t\t\tEnter train number: ";
        cin>>book_ticket[j].train_number;
        cout<<k;
        for(i=0;i<k;i++)
        {
        if(strcmp(book_ticket[j].train_number,add[i].train_number)==0)
        {
            if(add[i].seat==0)
            {
                cout<<"\n\n\t\t\tno seats available seat";

                getch();
                system("cls");
                main();
            }
        else
         {
            found=1;
            cout<<"\n\t\t\tenter book "<<j+1<<" no ticket: ";
            cout<<"\n\t\t\tenter date: ";
            cin>>book_ticket[j].date;
            cout<<"\n\t\t\tenter your name: ";
            cin>>book_ticket[j].name;
            cout<<"\n\t\t\tenter your phone number: ";
            cin>>book_ticket[j].phone;
            cout<<"\n\t\t\tseat number : "<<add[i].seat;
            system("cls");
            cout<<"\n\n\t\t\t==============================================";
            cout<<"\n\t\t\t----------RAILWAY RESERVATION SYSTEM----------\n";
            cout<<"\t\t\t==============================================";
            cout<<"\t\t\t --------------TICKET BOOKED--------------\n";
            cout<<"\t\t\t -----------------------------------------\n";
            cout<<"\t\t\t --------------Happy Journey--------------\n";
            book_ticket[j].seat=add[i].seat;
            bookticket_write();
            add[i].seat--;
            awrite();
         }
        }
        }
        if(found==-1)
        {
            cout<<"\n\n\t\t\ttrain not found!!!";
            getch();
            system("cls");
            main();
        }

        }
            u=j;
            bookticket_write();
            system("cls");
            cout<<"\n\n\t\t\tenter '1' for main menu & press any key to exit: ";
            cin>>c;
                if(c==1)
                {
                    system("cls");
                    main();
                }
                if(c!=1)
                {
                    exit;
                }
}
void cancelticket()
{
	viewpassengers_read();
    char pnnmbr[100];
    int location = -1,e;
    cout<<"\n\n\t\t\tenter phone number: ";
    cin>>pnnmbr;
    for (e=0;e<u;e++)
    {
        if (strcmp(pnnmbr,book_ticket[e].phone)==0)
        {
            location=e;
            break;
        }
    }
    if (location==-1)
    {
        cout<< ("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        main();
    }
    else
    {
        for (e=location;e<u;e++)
        {   strcpy(book_ticket[e].date,book_ticket[e+1].date);
            strcpy(book_ticket[e].train_number,book_ticket[e+1].train_number);
            strcpy(book_ticket[e].name,book_ticket[e+1].name);
            strcpy(book_ticket[e].phone,book_ticket[e+1].phone);
            bookticket_write();
        }
        u--;
        bookticket_write();
        cout<<"\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>";
        getch();
        system("cls");
        main();
    }
}
void admin()
{
	int choice;
	system("cls");
	cout<<"\n     =================================================================";
cout<<"\n     ********************RAILWAY RESERVATION SYSTEM*******************";
cout<<"\n     =================================================================";
cout<<"\n\n";
	cout<<"               <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n";
	cout<<"\n\n";
	cout<<"                 ************************************\n";
	cout<<"                 ||      CHOOSE YOUR OPERATION     ||\n";
	cout<<"                 ||--------------------------------||\n";
	cout<<"                 ||      [1] VIEW PASSENGERS       ||\n";
	cout<<"                 ||      [2] ADD TRAIN             ||\n";
	cout<<"                 ||      [3] DELETE TRAIN          ||\n";
	cout<<"                 ||      [4] BACK                  ||\n";
	cout<<"                 ||                                ||\n";
	cout<<"                 ************************************\n\n";
	cout<<"       **********************************************************\n";
	cout<<"\n\t\tENTER YOUR CHOICE: ";
	cin>>choice;

	switch(choice)
	{
		case 1:
                viewpassenger();
                break;
        case 2:
                add_train();
                break;
        case 3:
                delete_train();
                break;
        case 4:
                system("cls");
                getch();
                main();
                break;
        default:
                getch();
                cout<<"\n\t\t\tyou entered wrong KEY!!!!";
                getch();
                system("cls");
                main();
	}
	getch();
}
void password()
{
	int number=12345;
	int pass;
	cout<<"\n\t\t\tenter password: ";
	cin>>pass;
	if(pass==number)
	{
		cout<<"\n\n\t\t\t<<<<<login successfully>>>>>";
		getch();
		system("cls");
		admin();
	}
	else
	{
		cout<<"\n\n\t\t\t\t   ERROR!!!!!";
		cout<<"\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>";
		getch();
		system("cls");
		main();
	}
}
void delete_train()
{
	aread();
    char train[100];
    int location = -1,f;
    cout<<"\n\n\tenter train number: ";
    cin>>train;
    for (f=0;f<k;f++)
    {
        if (strcmp(train,add[f].train_number)==0)
        {
            location=f;
            break;
        }
    }
    if (location==-1)
    {
        cout<<"\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        getch();
        system("cls");
        admin();
    }
    else
    {
        for (f=location;f<k;f++)
        {
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].train_number,add[f+1].train_number);
            strcpy(add[f].train_name,add[f+1].train_name);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].destination,add[f+1].destination);
            strcpy(add[f].price,add[f+1].price);
            strcpy(add[f].time,add[f+1].time);
            awrite();
        }
        k--;
        awrite();
		cout<<"\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>";
		getch();
		system("cls");
		admin();
    }
}
void viewpassenger()
{
	int a,j;
	system("cls");
	viewpassengers_read();
	cout<<"\n\t\t\t       **********************************************************";
	cout<<"\n\t\t\t       ****************RAILWAY RESERVATION SYSTEM****************";
	cout<<"\n\t\t\t       **********************************************************";
	cout<<"\n\n\t\t\ttrain number\t\tname\t\tphone number\t\tdate\t\tseat\n";
	cout<<"\n\t\t\t**********************************************************************************\n";
	for(j=0;j<u;j++)
	{
		cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<<book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t"<<book_ticket[j].seat;
		book_ticket[j].seat++;
	}
	cout<<"\n\t\t\t**********************************************************************************\n";
	cout<<"\n\n\t\t\tenter '1' for main menu & enter '0' for back: ";
	cin>>a;
	if(a==1)
	{
		system("cls");
		main();
	}
	if(a==0)
	{
		system("cls");
		admin();
	}
}
void add_train()
{
	system("cls");
	int ch;
	aread();
	int i,a;
cout<<"\n\t\t     **********************************************************";
cout<<"\n\t\t     ****************RAILWAY RESERVATION SYSTEM****************";
	cout<<"\n\t\t     **********************************************************";
	cout<<"\n\n\t\t\thow many trains do you want to add: ";
	cin>>a;
	for(i=k;i<k+a;i++)
	{
		cout<<"\n\t\t\tenter "<<i+1<<" train details: ";
		cout<<"\n\n\t\t\tenter serial number: ";
		cin>>add[i].si;
		cout<<"\n\t\t\tenter train number: ";
		cin>>add[i].train_number;
		cout<<"\n\t\t\tenter train name: ";
		cin>>add[i].train_name;
		cout<<"\n\t\t\tenter start place: ";
		cin>>add[i].start;
		cout<<"\n\t\t\tenter destination place: ";
		cin>>add[i].destination;
		cout<<"\n\t\t\t enter price: ";
		cin>>add[i].price;
		cout<<"\n\t\t\t enter seat: ";
		cin>>add[i].seat;
		cout<<"\n\t\t\t enter time: ";
		cin>>add[i].time;
	}

		cout<<"\n\n\t\t\tconfirm train: (y=1/n=0):- ";
		cin>>ch;
		if(ch==1)
		{
			awrite();
			k=i;
			awrite();
			system("cls");
			cout<<"\n\n\t\t\t**********************************************************";
cout<<"\n\t\t\t****************RAILWAY RESERVATION SYSTEM****************";
cout<<"\n\t\t\t**********************************************************";
			cout<<"\n\n";
			cout<<"\n\t\t\t\t   **********************************";
			cout<<"\n\t\t\t\t   *<<<<<train add successfully>>>>>*";
			cout<<"\n\t\t\t\t   **********************************";
			getch();
			system("cls");
			main();
		}
			if(ch==0)
			{
				system("cls");
				admin();
			}
			if((ch!=1)&&(ch!=0))
			{
				system("cls");
				main();
			}
}
void viewinfo()
{
int ch,i;
system("cls");
aread();
cout<<"\n\t\t     **********************************************************";
cout<<"\n\t\t     ****************RAILWAY RESERVATION SYSTEM****************";
cout<<"\n\t\t     **********************************************************";
cout<<"\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tprice\tseat\ttime\n\n";
	for(i=0;i<k;i++)
	{
		cout<<"    "<<add[i].si<<"\t"<<add[i].train_number <<"\t\t"<< add[i].train_name<<"\t"<<add[i].start <<"\t\t"<< add[i].destination<<"\t\t\t"<<add[i].price <<"\t"<<add[i].seat <<"\t"<<add[i].time <<"\n";
	}
	cout<<"    ***********************************************************************************************\n";
	cout<<"\n\t\t\tpress '1' for main menu & press any key for exit:  ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			system("cls");
			main();
			break;
        default:
            exit(0);
	}
}

//-----------------------------------------book ticket file start----------------------------------

void bookticket_write()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
	fwrite(&book_ticket,sizeof(book_ticket),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
void viewpassengers_read()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","r");
	fread(&book_ticket,sizeof(book_ticket),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","r");
	fread(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}

//---------------------------------------add train file start-----------------------------------------
void awrite()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","w");
	fwrite(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","w");
	fwrite(&k,sizeof(k),1,train_report);
	fclose(train_report);
}
void aread()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","r");
	fread(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","r");
	fread(&k,sizeof(k),1,train_report);
	fclose(train_report);
}
//--------------------------------------------program close----------------------------------------
