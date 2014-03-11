//**********************************************
//     PROJECT   RAILWAY  ENQUIRY  SYSTEM
//**********************************************

//*********************************************
//     INCLUDED  HEADER  FILES
//**********************************************

#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<process.h>
//**********************************************
//     CLASS  NAME  :  TRAIN
//**********************************************

class train
      {
		 int tno ;
		 char tname[40],ttype[20];
		 float atime , dtime ;
 public:
		void getdata();
		void displaydata();
		char*returntname()
		 {
            return tname  ;
         }
      };

//******************************************
//    FUNCTIONS TO GET  AND SHOW DATA
//*****************************************

void train::getdata()
{
cout <<"\n\nEnter  train number :  ";
cin >>tno;
cout << "\nEnter train name : ";
gets(tname);
cout << "\nEnter train type : ";
cin >> ttype;
cout << "\nEnter arrival time of train where hours and minutes are separated by a'.': ";
cin >> atime;
cout << "\nEnter the departure time of the train: ";
cin>>dtime;
}

void train::displaydata()
{

  cout <<"\n********************************"<<endl;
  cout <<"\nTrain number: "<<tno<<"\nTrain name : “;
  cout<<tname<<"\nTrain type:  "<<ttype;
  cout <<"\nEnter  the arrival time of the train:  "<<atime;
  cout <<"\nEnter  the departure time of the train:  "<<dtime;
}

//*******************************************
//   TO CREATE FILES  , DISPLAY  FILES
//              & FILES MODIFICATIONS
//*******************************************
void creater();
void display();
void add();
void modify();
void deletet();
void main()
{
		  int choice;
		  char ch;

          do
            {

                cout<<"\n\t~~~~~~~~~~~~~~~~~~~~WELCOME TO INDIAN RAILWAY ~~~~~~~~~"<<endl;
				cout<<"\n\t\tEnter 1: To create a record";
				cout<<"\n\t\tEnter 2: To display a record";
				cout<<"\n\t\tEnter 3: To add a record";
				cout<<"\n\t\tEnter  4: To modify a record";
				cout<<"\n\t\tEnter 5: To delete a record";
				cout<<"\n\t\tEnter 6: To exit  "<<endl<<endl;
				cout<<"\n ENTER YOUR CHOICE: ";
				cin>>choice;

				switch(choice)
				 {
//*******************************************************
//              CASE      :  1
//              DETAIL    :  TO CREATE A TRAIN'S RECORD
// ******************************************************

			 case 1: creater();
			         getch();
                     break;

//*********************************************************
//                CASE     :  2
//              DETAILS    :  TO DISPLAY A TRAIN'S RECORD
//*********************************************************

            case 2: display();
                    getch();
                    break;


 //***************************************************
 //            CASE   :   3
//          DETAILS   :   TO ADD A TRAIN'S RECORD
//***************************************************

			 case 3: add();
                     getch();
                    break;

//**********************************************************
//                 CASE      :      4
//                 DETAILS   :   TO MODIFY A TRAIN'S RECORD
//**********************************************************

			case 4: modify();
                    getch();
                    break;

 //********************************************************
//                CASE     :   5
//               DETAILS   :   TO DELETE  A TRAIN'S RECORD
//*********************************************************

			 case 5: deletet();
                     getch();
                     break;

//***************************************************
//                CASE       :   6
//                DETAILS    :   TO EXIT
//***************************************************

			 case 6 : exit(0) ;
                      getch();
                    break;
                 }


              cout<<"\n\nDo you wish to continue(y/n)";
              cin>>ch;

              }while((ch=='y')||(ch=='Y'));

}
void creater()
{
   train s;
   char ch;

   fstream file;
   file.open("INDIAN RAILWAYS.dat",ios::in|ios::binary|ios::app);

   do
    {
       s.getdata();
       file.write((char*)&s,sizeof(s));
       cout<<"\n\n do you want to enter another record of a train(y/n) : ";
       cin>>ch;
       getch();

    }while((ch=='y')||(ch=='Y'));

    getch();
    file.close();

}

void display()
{
	train s;
    fstream file1;
    file1.open("INDIAN RAILWAYS.dat",ios::binary|ios::out|ios::in);
    while(!file1.eof())
     {
         file1.read((char*)&s,sizeof(s));
	     s.displaydata();
     }

    file1.close();
}

void add()
{
   train s;

   fstream  file3;
   file3.open("INDIAN RAILWAYS.dat",ios::app|ios::binary);

   s.getdata();
   file3.write((char*)&s,sizeof(s));
   file3.close();
}

void modify()
{
   int flag=0;
   train s;
   char n[20];
   cout<<"\n\nenter the train name whose data you want to modify: ";
   gets(n);

   fstream  file2;
   file2.open("INDIAN RAILWAYS.dat",ios::binary|ios::in|ios::out);

   while(file2.read((char*)&s,sizeof (s)))
    {
       if(strcmp(n,s.returntname())==0)
        {
           s.displaydata();
           cout<<"\nenter new enteries";
           s.getdata();
           int pos = -1*sizeof (s);
           file2.seekp(pos,ios::cur);
           file2.write((char*)&s,sizeof (s));
           flag=1;
           cout<<"\n record updated";
           break;
        }
     }

   file2.close();

   if(flag==0)
   cout<<"train not found"<<endl;
}

void deletet()
{
   fstream file4,file5;
   int flag =0;
   train s;
   char n[20];
   cout<<"\n\n enter the train name you want to delete: ";
   gets(n);

   file4.open("INDIAN RAILWAYS.dat",ios::in);
   file5.open("temp.dat",ios::out);
   while(!file4.eof())
    {
         file4.read((char*)&s,sizeof (s));
		 if((n,s.returntname())!=0)
			file5.write((char*)&s,sizeof(s));
		  else
             flag=1;
    }

   file4.close();
   file5.close();
   remove("INDIAN RAILWAYS.dat");
   rename("temp.dat","INDIAN RAILWAYS.dat");

   getch();

   if(flag==1)
      cout<<"\n record deleted";

   else if(flag==0)
      cout<<"\n  train not found ";
}





