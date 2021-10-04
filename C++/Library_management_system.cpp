#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<string.h>
void frame()
{
 int i,j;
 for(i=3,j=1;i<78;i++,j++)
 {
  gotoxy(i,2);
  cout<<char(205);
  sound(j*10);
  delay(10);
  nosound();
  }
  nosound();

  for(i=3;i<47;i++,j++)
  {
  gotoxy(77,i);
  cout<<char(205);
  sound(j*20);
  delay(10);
  nosound();
  }
  nosound();
  for(i=77;i>2;i--,j--)
  {
  gotoxy(i,47);
  cout<<char(205);
  sound(j*20);
  delay(10);
  nosound();
  }
  nosound();
  for(i=46;i>2;i--,j--)
  {gotoxy(3,i);
  cout<<char(205);
  sound(j*10);
  delay(10);
  nosound();
  }
  nosound();
  }
class library{int accno,admno;
       char author[20],title[20],pub[20],issue;
       float price;
       public:
       void accept()
       {cout<<'\t'<<'\t'<<"Enter the accession no."<<'\n';
        cout<<'\t'<<'\t';
        cin>>accno;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the title"<<'\n';
  cout<<'\t'<<'\t';
        cin>>title;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the author"<<'\n';
  cout<<'\t'<<'\t';
        cin>>author;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the publication"<<'\n';
  cout<<'\t'<<'\t';
        cin>>pub;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the price"<<'\n';
  cout<<'\t'<<'\t';
        cin>>price;
  cout<<'\n';
        admno=0;
        issue='N';
       }
     void display()
     {cout<<'\t'<<'\t'<<"Access no."<<accno<<'\n';
      cout<<'\n';
      cout<<'\t'<<'\t'<<"Title"<<title<<'\n';
       cout<<'\n';
      cout<<'\t'<<'\t'<<"Author"<<author<<'\n';
       cout<<'\n';
      cout<<'\t'<<'\t'<<"Publication"<<pub<<'\n';
      cout<<'\n';
      cout<<'\t'<<'\t'<<"Price"<<price<<'\n';
       cout<<'\n';
      cout<<'\t'<<'\t'<<"Issue status"<<issue<<'\n';
       cout<<'\n';
      if(issue=='Y')
        cout<<'\t'<<'\t'<<"Issued to admission no."<<admno<<'\n';
  cout<<'\n';
     }
     void modify()
     {cout<<'\t'<<'\t'<<"Enter the title"<<'\n';
      cout<<'\t'<<'\t';
      cin>>title;
       cout<<'\n';
      cout<<'\t'<<'\t'<<"Enter the author name"<<'\n';
       cout<<'\t'<<'\t';
      cin>>author;
       cout<<'\n';
      cout<<'\t'<<'\t'<<"Enter the publication"<<'\n';
       cout<<'\t'<<'\t';
      cin>>pub;
       cout<<'\n';
      cout<<'\t'<<'\t'<<"Enter the price"<<'\n';
       cout<<'\t'<<'\t';
      cin>>price;
       cout<<'\n';
     }
     int search(int acc)
     {if(acc==accno)
        return 1;
      else
        return 0;
     }
     void issue1()
     {if(issue=='Y')
        cout<<'\t'<<'\t'<<"Book is already issued"<<'\n';
      else
        {cout<<'\t'<<'\t'<<"Enter the admission no.";
  cin>>admno;
   cout<<'\n';
  issue='Y';
  cout<<'\t'<<'\t'<<"Book is issued"<<'\n';
   cout<<'\n';
        }
      }
     void returnb()
     {admno=0;
      issue='N';
      cout<<'\t'<<'\t'<<"Book is returned"<<'\n';
     }
   };
class student{int rno,admno,cls,mobno;
       char add[20],name[20];
       public:
       void insert()
       {cout<<'\t'<<'\t'<<"Enter the roll no."<<'\n';
        cout<<'\t'<<'\t';
        cin>>rno;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the admission no."<<'\n';
  cout<<'\t'<<'\t';
        cin>>admno;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the class"<<'\n';
  cout<<'\t'<<'\t';
        cin>>cls;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the name"<<'\n';
  cout<<'\t'<<'\t';
        cin>>name;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the mobile no."<<'\n';
  cout<<'\t'<<'\t';
        cin>>mobno;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the address"<<'\n';
  cout<<'\t'<<'\t';
        cin>>add;
  cout<<'\n';
       }
        void show()
       {cout<<'\t'<<'\t'<<"Roll no."<<rno<<'\n';
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Name"<<name<<'\n';
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Admission no."<<admno<<'\n';
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Class"<<cls<<'\n';
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Address"<<add<<'\n';
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Mobile no."<<mobno<<'\n';
  cout<<'\n';
       }
        void modify1()
       {cout<<'\t'<<'\t'<<"Enter the roll no."<<'\n';
        cout<<'\t'<<'\t';
        cin>>rno;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the name"<<'\n';
  cout<<'\t'<<'\t';
        cin>>name;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the admission no."<<'\n';
  cout<<'\t'<<'\t';
        cin>>admno;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the class"<<'\n';
  cout<<'\t'<<'\t';
        cin>>cls;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the address"<<'\n';
  cout<<'\t'<<'\t';
        cin>>add;
  cout<<'\n';
        cout<<'\t'<<'\t'<<"Enter the mobile no."<<'\n';
  cout<<'\t'<<'\t';
        cin>>mobno;
  cout<<'\n';
       }
       int searchr(int r)
       {if(r==rno)
   return 1;
        else
   return 0;
        }
       int searchclass(int z)
       {if(z==cls)
   return 1;
        else
   return 0;
       }
      };
void main()
{clrscr();
 char pass[]="8682";
 char password[30];
 do{
 gotoxy(24,2);
 cout<<"Enter the password";
 int i=0;
 char tp;
 while((tp=getch())!='\r')
 {cout<<"*";
  password[i]=tp;
  i++;
 }
 password[i]='\0';
 if(strcmpi(password,pass)==0)
   break;
 else
   cout<<'\n'<<"Wrong Password";
  }while(1);
 fstream obj,obj2;
 library l;
 student s;
 int ch,acc,r,c=0,roll,z;

  do{  main:
    textmode(3);
    textmode(C4350);
    textbackground(BLACK);
    textcolor(GREEN);
    frame();
  gotoxy(1,3);
     cout<<"             *****************ST MARY'S INTER COLLEGE******************";
     gotoxy(24,5);
     cout<<"****WELCOME TO THE PROJECT OF C++****";
     gotoxy(22,8);
     cout<<" ON SCHOOL LIBRARY MANAGEMENT SYSTEM";
     gotoxy(10,17);
     cout<<"UNDER THE GUIDANCE OF-" ;
     gotoxy(10,20);
     cout<<   "MR ANIL KUMAR" ;
     gotoxy(50,17);
     cout<<"Submitted by-";
     gotoxy(51,19);
     cout<<"SATVIK KUMAR"<<endl;
     gotoxy(4,21);
     cout<<'\t'<<'\t'<<'\t'<<"WELCOME TO LIBRARY MANAGEMENT SYSTEM"<< '\t'<<'\t'<<'\t'<<endl;
     delay(2400);
      clrscr();
     }while(0);
 do{
 clrscr();
 cout<<'\t'<<'\t'<<'\t'<<"****ST.  MARY'S  LIBRARY****"<<'\n';
 gotoxy(20,2);
 cout<<'\t'<<"****MAIN MENU****"<<'\n';
 gotoxy(20,4);
    cout<<"01-Add records"<<'\n';

 gotoxy(20,6);
    cout<<"02-Issue a book"<<'\n';

 gotoxy(20,8);
    cout<<"03-Return a book"<<'\n';

 gotoxy(20,10);
    cout<<"04-Display all book details"<<'\n';

 gotoxy(20,12);
    cout<<"05-Display single book details"<<'\n';

 gotoxy(20,14);
    cout<<"06-Modify a book detail"<<'\n';

 gotoxy(20,16);
    cout<<"07-Delete a book record"<<'\n';

 gotoxy(20,18);
    cout<<"08-Add student details"<<'\n';

 gotoxy(20,20);
    cout<<"09-Display all student details"<<'\n';

 gotoxy(20,22);
    cout<<"10-Modify student details"<<'\n';

 gotoxy(20,24);
    cout<<"11-Delete a student details"<<'\n';

 gotoxy(20,26);
    cout<<"12-Display single student details"<<'\n';

 gotoxy(20,28);
    cout<<"13-Display student details classwise"<<'\n';

 gotoxy(20,30);
    cout<<"14-Exit"<<'\n';

 gotoxy(20,32);
    cout<<"Enter your choice";
    cin>>ch;
switch(ch)
{case 1:
       obj.open("lib.dat",ios::binary|ios::app);
       l.accept();
       obj.write((char*)&l,sizeof(l));
       obj.close();
       cout<<'\t'<<'\t'<<"Press any key....";
       getch();
       break;
 case 2:
       obj.open("lib.dat",ios::binary|ios::in|ios::out);
       c=0;
       cout<<'\t'<<'\t'<<"Enter the access no."<<'\n';
 cout<<'\t'<<'\t';
       cin>>acc;
       cout<<'\n';
       while(!obj.eof())
       {obj.read((char*)&l,sizeof(l));
 c++;
 r=l.search(acc);
 if(r==1)
   {l.issue1();
    obj.seekp((c-1)*sizeof(l),ios::beg);
    obj.write((char*)&l,sizeof(l));
    break;
   }
       }
       if(r==0)
  cout<<'\t'<<'\t'<<"The given book is not found"<<'\n';
  cout<<'\n';
  obj.close();
  cout<<'\t'<<'\t'<<"Press any key....";
  getch();
  break;
 case 3:
       obj.open("lib.dat",ios::binary|ios::in|ios::app);
       c=0;
       cout<<'\t'<<'\t'<<"Enter the access no."<<'\n';
 cout<<'\t'<<'\t';
       cin>>acc;
       cout<<'\n';
       while(!obj.eof())
       {obj.read((char*)&l,sizeof(l));
 c++;
 r=l.search(acc);
 if(r==1)
   {l.returnb();
    obj.seekp((c-1)*sizeof(l),ios::beg);
    obj.write((char*)&l,sizeof(l));
    break;
   }
 }
 if(r==0)
   cout<<'\t'<<'\t'<<"The given book is not found"<<'\n';
    cout<<'\n';
   obj.close();
   cout<<'\t'<<'\t'<<"Press any key....";
   getch();
   break;
 case 4:
       obj.open("lib.dat",ios::binary|ios::in);
       int d=0;
       while(!obj.eof())
       {obj.read((char*)&l,sizeof(l));
 if(obj.eof())
   break;
  d++;
 l.display();
       }
       if(d==0)
  cout<<'\t'<<'\t'<<"No records are found"<<'\n';
  cout<<'\n';
       obj.close();
       cout<<'\t'<<'\t'<<"Press any key....";
       getch();
       break;
 case 5:
       obj.open("lib.dat",ios::binary|ios::in);
       cout<<'\t'<<'\t'<<"Enter the access no."<<'\n';
 cout<<'\t'<<'\t';
       cin>>acc;
 cout<<'\n';
       while(!obj.eof())
       {obj.read((char*)&l,sizeof(l));
 r=l.search(acc);
 if(r==1)
   {l.display();
    break;
   }
 }
 if(r==0)
   cout<<'\t'<<'\t'<<"The given book is not found"<<'\n';
   cout<<'\n';
   obj.close();
   cout<<'\t'<<'\t'<<"Press any key....";
   getch();
   break;
 case 6:
       obj.open("lib.dat",ios::binary|ios::in|ios::out);
       c=0;
       cout<<'\t'<<'\t'<<"Enter the accession no."<<'\n';
 cout<<'\t'<<'\t';
       cin>>acc;
       cout<<'\n';
       while(!obj.eof())
 {obj.read((char*)&l,sizeof(l));
  c++;
  r=l.search(acc);
  if(r==1)
    {l.modify();
     obj.seekp((c-1)*sizeof(l),ios::beg);
     obj.write((char*)&l,sizeof(l));
     cout<<'\t'<<'\t'<<"Book details are modified"<<'\n';
     cout<<'\n';
     break;
    }
   }
  if(r==0)
    cout<<'\t'<<'\t'<<"The given book is not found"<<'\n';
    cout<<'\n';
    obj.close();
    cout<<'\t'<<'\t'<<"Press any key....";
    getch();
    break;
 case 7:
 obj.open("lib.dat",ios::binary|ios::in);
 fstream obj1("temp.dat",ios::binary|ios::out);
  int ano;
  char found='f',confirm='n';
  cout<<'\t'<<'\t'<<"Enter accession no.of book whose details is to be deleted"<<'\n';
   cout<<'\t'<<'\t';
  cin>>ano;
  while(!obj.eof())
  {obj.read((char*)&l,sizeof(l));
   if(l.search(ano)==1)
   {l.display();
    found='t';
    cout<<'\t'<<'\t'<<"Are you sure you want to delete the details of this book?(Y/N)";
     cout<<'\t'<<'\t';
    cin>>confirm;
    if(toupper(confirm)=='N')
      obj1.write((char*)&l,sizeof(l));
    }
   else
      obj1.write((char*)&l,sizeof(l));
     }
   if(found=='f')
     cout<<'\t'<<'\t'<<"Record not found"<<'\n';
  obj.close();
  obj1.close();
  remove("lib.dat");
  rename("temp.dat","lib.dat");
  cout<<'\t'<<'\t'<<"The required book detalis are deleted"<<'\n';
  cout<<'\t'<<'\t'<<"Press any key....";
  getch();
  break;
 case 8:
 obj2.open("stud.dat",ios::binary|ios::app);
 s.insert();
 obj2.write((char*)&s,sizeof(s));
 obj2.close();
 cout<<'\t'<<'\t'<<"Press any key....";
 getch();
 break;
 case 9:
       obj2.open("stud.dat",ios::binary|ios::in);
       d=0;
       while(!obj2.eof())
       {obj2.read((char*)&s,sizeof(s));
 if(obj2.eof())
   break;
 d++;
 s.show();
       }
       if(d==0)
  cout<<'\t'<<'\t'<<"No records are found"<<'\n';
  cout<<'\n';
       obj2.close();
       cout<<'\t'<<'\t'<<"Press any key....";
       getch();
       break;
 case 10:
       obj2.open("stud.dat",ios::binary|ios::in|ios::out);
       c=0;
       cout<<'\t'<<'\t'<<"Enter the roll no to be modified"<<'\n';
 cout<<'\t'<<'\t';
       cin>>roll;
       cout<<'\n';
       while(!obj2.eof())
 {obj2.read((char*)&s,sizeof(s));
  c++;
  r=s.searchr(roll);
  if(r==1)
    {s.modify1();
     obj2.seekp((c-1)*sizeof(s),ios::beg);
     obj2.write((char*)&s,sizeof(s));
     cout<<'\t'<<'\t'<<"student details are modified"<<'\n';
     break;
    }
   }
  if(r==0)
    cout<<'\t'<<'\t'<<"The given record is not found"<<'\n';
    cout<<'\n';
    obj2.close();
    cout<<'\t'<<'\t'<<"Press any key....";
    getch();
    break;
 case 11:
 obj2.open("stud.dat",ios::binary|ios::in);
 fstream obj3("tem.dat",ios::binary|ios::out);
  int roll;
  found='f',confirm='n';
  cout<<'\t'<<'\t'<<"Enter roll no. whose details is to be deleted"<<'\n';
   cout<<'\t'<<'\t';
  cin>>roll;
  cout<<'\n';
  while(!obj2.eof())
  {obj2.read((char*)&s,sizeof(s));
   if(s.searchr(roll)==1)
   {s.show();
    found='t';
    cout<<'\t'<<'\t'<<"Are you sure you want to delete the details of this student?(Y/N)";
     cout<<'\t'<<'\t';
    cin>>confirm;
    cout<<'\n';
    if(toupper(confirm)=='N')
      obj3.write((char*)&s,sizeof(s));
    }
   else
      obj3.write((char*)&s,sizeof(s));
     }
   if(found=='f')
     cout<<'\t'<<'\t'<<"Record not found"<<'\n';
     cout<<'\n';
  obj2.close();
  obj3.close();
  remove("stud.dat");
  rename("tem.dat","stud.dat");
  cout<<'\t'<<'\t'<<"The required student detalis are deleted"<<'\n';
  cout<<'\n';
  cout<<'\t'<<'\t'<<"Press any key....";
  getch();
  break;
 case 12:
 obj2.open("stud.dat",ios::binary|ios::in);
 cout<<'\t'<<'\t'<<"Enter the roll no."<<'\n';
  cout<<'\t'<<'\t';
 cin>>roll;
 cout<<'\n';
 while(!obj2.eof())
 {obj2.read((char*)&s,sizeof(s));
 r=s.searchr(roll);
  if(r==1)
   {s.show();
    break;
   }
 }
 if(r==0)
   cout<<'\t'<<'\t'<<"The given student details is not found"<<'\n';
   obj2.close();
   cout<<'\t'<<'\t'<<"Press any key....";
   getch();
   break;
 case 13:
 obj2.open("stud.dat",ios::binary|ios::in);
 cout<<'\t'<<'\t'<<"Enter the class"<<'\n';
  cout<<'\t'<<'\t';
 cin>>z;
 while(!obj2.eof())
 {obj2.read((char*)&s,sizeof(s));
  r=s.searchclass(z);
  if(r==1)
   s.show();
 }
 if(r==0)
   cout<<'\t'<<'\t'<<"The given student details is not found"<<'\n';
   obj2.close();
   cout<<'\t'<<'\t'<<"Press any key....";
   getch();
   break;
 case 14:
  exit(0);
  break;
 default:
       cout<<'\t'<<'\t'<<"Wrong choice"<<'\n';
       cout<<'\t'<<'\t'<<"Press any key...";
       getch();
   }
 }while(1);
}
