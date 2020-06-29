#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>  
using namespace std;
bool register_student(struct student *stud,struct list *ls);
double calculate_aggregiate(struct student *);
long int calculate_scholarship(struct student *stdu);
void addToList(struct student *stud, struct list *l);
void showList(struct student *stud, struct list *l);
void fee(struct student *stud, struct list *l);
struct student
{
    char name[20];
    int tenth_marks,inter_marks,entryTest_marks,hos;
    student *next;
    double aggr;
};
struct list
{
    char name[20];
    double aggr;
    int host;
    long int anual;
    list *next;
};
int main()
{   
    student *s;     
    s = (struct student *) malloc(sizeof(struct student));
    struct list *ls;
    ls = (struct list *) malloc(sizeof(struct list));
    ls->name[0] = '\0';
    ls->aggr = 0;
    ls->next= NULL;
    do
    {
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t|-------------------------------------------------------------|\n";
    cout<<"\t\t\t\t\t\t\t|   *******Enter 1 to register a new student*******           |\n";
    cout<<"\t\t\t\t\t\t\t|*******Enter 2 to display lists of students registered*******|\n";
    cout<<"\t\t\t\t\t\t\t|        *******Enter 3 to display fee detalis*******         |\n";
    cout<<"\t\t\t\t\t\t\t|            *******Enter 4 to quit*******                    |\n";
    cout<<"\t\t\t\t\t\t\t|-------------------------------------------------------------|\n\n\n\n";
    int input;
    cout<<"\nEnter your option:  ";
    cin>>input;
    if (input == 1)
    {
        register_student(s, ls);
    }
    else if (input == 2)
    {
        showList(s, ls);
    }
    else if(input==3)
    {
    	fee(s,ls);
	}
    else if (input == 4)
        exit(0);
    cout<<"\n";
    } while(1);
    getch();
}
bool register_student(struct student *stud,struct list *ls)
{   
    student *s = stud;
    cout<<"\nEnter name of student: ";
    cin>>s->name;
    cout<<"\nEnter 10th percentage: ";
    cin>>s->tenth_marks;
    cout<<"\nEnter 12th percentage: ";
    cin>>s->inter_marks;
    cout<<"\nEnter entry test percentage: ";
    cin>>s->entryTest_marks;
    cout<<"\nEnter 1 if student is hostler else 0: ";
    cin>>s->hos;
    double aggregiate;
    aggregiate = calculate_aggregiate(s);   
    cout<<"----------------------------------\n";
    cout<<"aggregiate percentage is "<< aggregiate<<"\n";
    if (aggregiate >= 70)
    {
        cout<<"\nStudent registered in Merit level\n";
        cout<<"----------------------------------\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >= 60)
    {
        cout<<"\nStudent registered in O level\n";
        cout<<"----------------------------------\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >=50)
    {
        cout<<"\nStudent registered in A level\n";
        cout<<"----------------------------------\n";
        addToList(s,ls);
        return true;
    }
    else
    {
        cout<<"Sorry, the student can't be registered in engineering\n";
        return false;
    }
}
double calculate_aggregiate(struct student *stud)
{   
    student *s = stud;
    double aggr;
    aggr = s->tenth_marks * 10/100  + s->inter_marks * 50/100 + s->entryTest_marks * 40/100;
    //---> 10 % weightage to 10th, 50% to 12th, 40% to entry test...
    return aggr;
}
long int calculate_scholarship(struct student *stud)
{
	double aggr;
	student *s=stud;
	int scholar;
	s->aggr=calculate_aggregiate(stud);
	scholar=(s->aggr * 1000)/2;
	return scholar;
}
void addToList(struct student *stud, struct list *l)
{   
    list *pointer = l;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    } 
    pointer->next = (struct list *) malloc(sizeof(struct list));
    pointer = pointer->next;
    strcpy(pointer->name , stud->name);
    pointer->aggr = calculate_aggregiate(stud);
    pointer->host=stud->hos;
    pointer->next = NULL;
}
void showList(struct student *stud, struct list *l)
{
    list *pointer = l;
    if(pointer->next == NULL)
    {
		cout<<"_________________________________________________________\n\n";
        cout<<"No student registered yet!\n\n";
    }
    else
    {
    	cout<<"________________________________________________________\n\n";
        cout<<"Students statistics are: \n";
        cout<<"-----------------------\n\n";
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
            cout<<"Name of student is: "<<pointer->name<<"\n";
            cout<<"Aggregiate of student is: "<<pointer->aggr<<"\n";
            if (pointer->aggr >= 70)
            {
                cout<<"Student registered in Merit level\n\n";
            }
            else if(pointer->aggr >=60)
            {
                cout<<"Student registered in O level\n\n";
        	}
            else
            {
                cout<<"Student registered in A level\n\n";
        	}
            }
        }
        cout<<"_________________________________________________________\n";
    }
void fee(struct student *stud, struct list *l)
{
	long int sch;
    list *pointer = l;
    sch=calculate_scholarship(stud);
    long int tf,th;
    if(pointer->next == NULL)
    {
		cout<<"_________________________________________________________\n\n";
        cout<<"No student registered yet!\n\n";
    }
    else
    {
    	cout<<"________________________________________________________\n\n";
        cout<<"Fee details of students registered are: \n";
        cout<<"---------------------------------------\n\n";
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
            cout<<"Name of student is: "<<pointer->name<<"\n\n";
            if (pointer->aggr >= 70)
            {
            	cout<<"Enter aunal income of parent: \n";
            	cin>>pointer->anual;
            	if(pointer->anual<=100000)
            	{
            		cout<<"Merit level--->Tution Fee=100000\n";
            		cout<<"               Scholarship amount="<<sch<<"\n";
            		tf=100000-sch;
            		cout<<"               ----------------------\n";
            		if(pointer->host==1)
            		cout<<"               Balance fee="<<tf<<"\n";
            		else
            		cout<<"               Total fee="<<tf<<"\n\n\n";
            	}
            	else
            	{
                	cout<<"Merit level--->Tution Fee=100000\n";
                }
                if(pointer->host==1)
                {
                	if(pointer->anual<=100000)
                	{
                	th=tf+70000;
                	cout<<"\t\tHostel fee=50000\n";
                	cout<<"\t\tMess fee=20000\n";
                	cout<<"\t\t-------------------\n";
                	cout<<"\t\tTotal fee="<<th<<"\n\n\n";
                	}
                	else
                	{
                		cout<<"\t      Hostel fee=50000\n";
                		cout<<"\t       Mess fee=20000\n";
                		cout<<"\t      -------------------\n";
                		cout<<"\t       Total fee=170000\n\n\n";
                	}
				}
				else
				{
					cout<<"\n";
				}
            }
            else if(pointer->aggr >=60)
            {
                cout<<"O level--->Tution Fee=200000\n";
                if(pointer->host==1)
                {
                	cout<<"\t   Hostel fee=50000\n";
                	cout<<"\t    Mess fee=20000\n";
                	cout<<"\t   -------------------\n";
                	cout<<"\t    Total fee=270000\n\n\n";
				}
				else
				{
					cout<<"\n";
				}
        	}
            else
            {
                cout<<"A level--->Tution Fee=300000\n";
               if(pointer->host==1)
                {
                	cout<<"\t   Hostel fee=50000\n";
                	cout<<"\t    Mess fee=20000\n";
                	cout<<"\t   -------------------\n";
                	cout<<"\t    Total fee=370000\n\n\n";
				}
				else
				{
					cout<<"\n";
				}
        	}
            }
        }
        cout<<"_________________________________________________________\n";
    }
