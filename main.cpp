#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
char un[20];
class Admin
{
    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[15],mail[50],fname[20];
    char passwd[20],rpasswd[20];
public:
    char rollno[15];
    void getstdata()
    {
        cout<<"\nEnter the student name : ";
        cin>>name;//gets(name);
        cout<<"\nEnter the student ID/Roll No. : ";
        cin>>rollno;
        cout<<"\nEnter the student Father's name : ";
        cin>>fname;//gets(fname);
        cout<<"\nEnter the student Mobile Number : ";
        cin>>mobile;//gets(mobile);
        cout<<"\nEnter the student E-mail ID : ";
        cin>>mail;//gets(mail);
        cout<<"\nEnter the Total Subject : ";
        cin>>totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"\nEnter the subject "<<i+1<<" name : ";
            cin>>subject[i];
        }
        cout<<"\nCreate Your Login Passwword : ";
        cin>>passwd;
        cout<<"\nEnter the Unique Keyword to Recover Password : ";
        cin>>rpasswd;
        cout<<"\n\nPlease note your Username is ID/Roll No.\n";
    }
    int login()
    {
        if ((strcmp(::un,rollno))==0)
        {
            cout<<"\nEnter the Login Password : ";
            int i,len=0;
            len=strlen(passwd);
            char inputpasswd[20];
            for(i=0;i<len;i++)
            {
                inputpasswd[i]=getch();
                cout<<"*";
            }
            inputpasswd[i]='\0'; //inputpaswd[8]=null/'\0' because i increament to 8 and 8 index contain null value or termination of string
            cout<<"\nThe Enter Password is "<<inputpasswd;
            if((strcmp(::un,rollno)==0)&&(strcmp(passwd,inputpasswd)==0))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    int recover()
    {
        //cout<<"\nThe Input Username is "<<::un;
        char key[20];
        if (strcmp(::un,rollno)==0)
        {
            cout<<"\nEnter the Unique keyword (provided by Admin) : ";
            cin>>key;
            if((strcmp(key,rpasswd)==0))
            {
                cout<<"\nYou are a valid user." ;
                cout<<"\nYour password is "<<rpasswd;
                cout<<"\nPlease Exit To Login Again ";
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    int faprofile()
    {
        if(strcmp(::un,rollno)==0)
        {
            cout<<"\nFaculty Name          : "<<name;
            cout<<"\nFaculty Father's Name : "<<fname;
            cout<<"\nFaculty mobile No.    : "<<mobile;
            cout<<"\nFaculty E-mail ID     : "<<mail;
            return 1;
        }
        else
            return 0;
    }
    int knowfasub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nFaculty Total Subject : "<<totsub;
            for(int i=0;i<totsub;i++)
            {
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }
        else
            return 0;
    }
    void addfasub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\n\nNew Subject Added successfully... ";
        }
    }
    void delfasub()
    {
        knowfasub();
        int de=0;
        if((strcmp(::un,rollno)==0))
        {
            if(totsub==0 || totsub<0)
            {
                totsub=0;
                cout<<"\nNone Subject Exist..";
                getch();
                exit(0);
            }
            cout<<"\nEnter the subject No. to be deleted : ";
            cin>>de;
            if(de==totsub)
            {
                totsub--;
                strcpy(subject[totsub]," ");
            }
            else if(totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub]," ");
            }
            else
            {
                de--;
                strcpy(subject[totsub]," ");
                for (int p=de;p<totsub;p++)
                {
                    strcpy(subject[p],subject[p+1]);
                }
                totsub--;
            }
            cout<<"\n Records Updated Successfully..";
        }
    }
    void modfaprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nThe Profile Details are : ";
            cout<<"\n 1. Faculty E-mail : "<<mail;
            cout<<"\n 2. Faculty Mobile : "<<mobile;
            int g=-1;
            cout<<"\n\nEnter the Detail No. to be Modified : ";
            cin>>g;
            if(g==1)
            {
                char nmail[50];
                cout<<"\nEnter the New Mail Address : ";
                strcpy(mail,nmail);
                cout<<"\nRecords Updated Successfully..";
            }
            else if(g==2)
            {
                char nmobile[15];
                cout<<"\nEnter the New Mobile No. : ";
                gets(nmobile);
                strcpy(mobile,nmobile);
                cout<<"\nRecords Updated Successfully..";
            }
            else
                cout<<"\nInvalid Input Provided...";
        }
    }
    int stprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nStudent Name          : "<<name;
            cout<<"\nStudent Father's Name : "<<fname;
            cout<<"\nStudent mobile No.    : "<<mobile;
            cout<<"\nStudent E-mail ID     : "<<mail;
            return 1;
        }
        else
            return 0;
    }
    int knowstsub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nStudent Total Subjects : "<<totsub;
            for(int i=0;i<totsub;i++)
            {
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }
        else
            return 0;
    }
    void addstsub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\n\nNew Subject Added successfully... ";
        }
    }
    void delstsub()
    {
        knowstsub();
        int de=0;
        if((strcmp(::un,rollno)==0))
        {
            if(totsub==0 || totsub<0)
            {
                totsub=0;
                cout<<"\nNone Subject Exist..";
                getch();
                exit(0);
            }
            cout<<"\nEnter the subject No. to be deleted : ";
            cin>>de;
            if(de==totsub)
            {
                totsub--;
                strcpy(subject[totsub]," ");
            }
            else if(totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub]," ");
            }
            else
            {
                de--;
                strcpy(subject[totsub]," ");
                for (int p=de;p<totsub;p++)
                {
                    strcpy(subject[p],subject[p+1]);
                }
                totsub--;
            }
            cout<<"\n Records Updated Successfully..";
        }
    }
    void modstprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nThe Profile Details are : ";
            cout<<"\n 1. Student E-mail : "<<mail;
            cout<<"\n 2. Student Mobile : "<<mobile;
            int g=-1;
            cout<<"\n\nEnter the Detail No. to be Modified : ";
            cin>>g;
            if(g==1)
            {
                char nmail[50];
                cout<<"\nEnter the New Mail Address : ";
                strcpy(mail,nmail);
                cout<<"\nRecords Updated Successfully..";
            }
            else if(g==2)
            {
                char nmobile[15];
                cout<<"\nEnter the New Mobile No. : ";
                gets(nmobile);
                strcpy(mobile,nmobile);
                cout<<"\nRecords Updated Successfully..";
            }
            else
                cout<<"\nInvalid Input Provided...";
        }
    }
    void getfadata()
    {
        cout<<"\nEnter the Faculty name : ";
        cin>>gets(name);
        cout<<"\nEnter the Faculty ID/Roll No. : ";
        cin>>rollno;
        cout<<"\nEnter the Faculty Father's name : ";
        cin>>fname;//gets(fname);
        cout<<"\nEnter the Faculty Mobile Number : ";
        cin>>mobile;//gets(mobile);
        cout<<"\nEnter the Faculty E-mail ID : ";
        cin>>mail;//gets(mail);
        cout<<"\nEnter the Total Subject : ";
        cin>>totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"\nEnter the subject "<<i+1<<" name : ";
            cin>>subject[i];
        }
        cout<<"\nCreate Your Login Passwword : ";
        cin>>passwd;
        cout<<"\nEnter the Unique Keyword to Recover Password : ";
        cin>>rpasswd;
        cout<<"\n\nPlease note Your UserName is ID/Roll No.\n";
    }
    void stdisplay()
    {
        cout<<"\nStudent Name          : "<<name;
        cout<<"\nStudent ID/Roll No.   : "<<rollno;
        cout<<"\nStudent Father's Name : "<<fname;
        cout<<"\nStudent mobile No.    : "<<mobile;
        cout<<"\nStudent E-mail ID     : "<<mail;
        cout<<"\nStudent subjects      : "<<totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"\n   subjects  "<<i+1<<". "<<subject[i];
        }
        if(totsub==0)
            cout<<"\n\t\tNone Subjects Specified.. ";
    }
    void fadisplay()
    {
        cout<<"\nFaculty Name          : "<<name;
        cout<<"\nFaculty ID/Roll No.   : "<<rollno;
        cout<<"\nFaculty Father's Name : "<<fname;
        cout<<"\nFaculty mobile No.    : "<<mobile;
        cout<<"\nFaculty E-mail ID     : "<<mail;
        cout<<"\nFaculty subjects      : "<<totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"\n   subject "<<i+1<<". "<<subject[i];
        }
        if(totsub==0)
            cout<<"\n\t\tNone Subjects Specified.. ";

    }
}a;
Admin f;

int main()
{
    int ch;
    system("CLS");
    cout<<"\n\n\n\t\t\tWelcome to MIMIT Database Portal ";
    cout<<"\n\n\n\t\t\t\tEnter to Continue.. ";
    getch();
    mainportal:
    system("CLS");
    cout<<"\n\n\n\t\t\tPress 1 for Admin Portal";
    cout<<"\n\t\t\tPress 2 for Faculty Portal";
    cout<<"\n\t\t\tPress 3 for Student Portal";
    cout<<"\n\t\t\tPress 4 for Exit";
    cout<<"\n\n\t\t\tEnter your Choice : ";
    cin>>ch;
    system("CLS");
    if(ch==4)
    {
                cout<<"\n\n\n\n\n\n\t\t\t\tThank You!!! ";
                cout<<"\n\n\t\t\t\tHave A Good Day ";
                getch();
                exit(0);
    }
    if(ch==1)
    {
        char adminuser[20],adminpass[20];
        cout<<"\n\t\t\tWelcome To Admin Portal";
        cout<<"\n\nEnter the UserName : ";
        cin>>adminuser;
        cout<<"\nEnter the Password : ";
        int k;
        for(k=0;k<8;k++)
        {
            adminpass[k]=getch();
            cout<<"*";
        }
        getch();
        adminpass[k]='\0';
        if((strcmp(adminuser,"admin")==0)&&(strcmp(adminpass,"password")==0))
        {
            system("CLS");
        }
        else
        {

            cout<<"\n\n\t\t\t  Invalid Access To Portal ";
            cout<<"\n\n\t\t\t\tThank You!!!";
            getch();
            exit(0);
        }
        char opera='y';
        do
        {
            int tmp;
            cout<<"\n\t\t\t\tWelcome To Admin Portal";
            cout<<"\n\nPress 1 to Add a Faculty Record";
            cout<<"\nPress 2 to Add Multiple Records of Faculty";
            cout<<"\nPress 3 to View All Records of Faculty";
            cout<<"\nPress 4 to Delete a Faculty Record";
            cout<<"\nPress 5 to Add a Student Record";
            cout<<"\nPress 6 to Add Multiple Records of Students";
            cout<<"\nPress 7 to View All Records of Students";
            cout<<"\nPress 8 to to Delete a Student Record";
            cout<<"\nPress 9 to Exist.";
            cout<<"\nPress 0 to LogOut.";
            cout<<"\n\n\tEnter your choice : ";
            cin>>tmp;
            system("CLS");
            if(tmp==1)
            {
                cout<<"\nEnter The Details : ";
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::app);
                a.getfadata();
                fs.write((char *)&a,sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully.. ";
            }
            if(tmp==2)
            {
                int m=0;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::app);
                do
                {
                    cout<<"\nEnter the Details :- ";
                    a.getfadata();
                    fs.write((char *)&a,sizeof(Admin));
                    cout<<"\nPress 0 If You Want To Enter More Records : ";
                    cin>>m;
                }
                while(m==0);
                fs.close();
                cout<<"\nRecord Entered Successfully..";
            }
            if(tmp==3)
            {
                ifstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                fs.read((char *)&a,sizeof(Admin));
                while(!fs.eof())
                {
                    a.fadisplay();
                    fs.read((char *)&a,sizeof(Admin));
                    cout<<"\n\n";
                }
                fs.close();
            }
            if(tmp==4)
            {
                char tmpfaid[15];
                int de=0,result=-1;
                cout<<"\nEnter the Faculty ID/Roll No. :- ";
                cin>>tmpfaid;
                ifstream fs;
                fs.open("fainfo.txt",ios::in);
                fstream fs1;
                fs1.open("fanewinfo.txt",ios::out|ios::binary);
                while(!fs.eof())
                {
                    fs.read((char *)&a,sizeof(Admin));
                    result=strcmp(tmpfaid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                        fs1.write((char *)&a,sizeof(Admin));
                }
                if(de==1)
                {
                    cout<<"\nReocrd deleted Successfully !!!";
                }
                else
                {
                    cout<<"\nRecord Not Found.. ";
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("fanewinfo.txt","fainfo.txt");
            }
            if(tmp==5)
              {
                cout<<"\nEnter The Details : ";
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::app);
                a.getstdata();
                fs.write((char *)&a,sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully.. ";
            }
            if(tmp==6)
            {
                int m=0;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::app);
                do
                {
                    cout<<"\nEnter the Details :- ";
                    a.getstdata();
                    fs.write((char *)&a,sizeof(Admin));
                    cout<<"\nPress 0 If You Want To Enter More Records : ";
                    cin>>m;
                }
                while(m==0);
                fs.close();
                cout<<"\nRecord Entered Successfully..";
            }
            if(tmp==7)
            {
                ifstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                fs.read((char *)&a,sizeof(Admin));
                while(!fs.eof())
                {
                    a.stdisplay();
                    fs.read((char *)&a,sizeof(Admin));
                    cout<<"\n\n";
                }
                fs.close();
            }
            if(tmp==8)
            {
                char tmpstid[15];
                int de=0,result=-1;
                cout<<"\nEnter the Faculty ID/Roll No. :- ";
                cin>>tmpstid;
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char *)&a,sizeof(Admin));
                    result=strcmp(tmpstid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                        fs1.write((char *)&a,sizeof(Admin));
                }
                if(de==1)
                {
                    cout<<"\nRecord Deleted Successfully.. ";
                }
                else
                {
                    cout<<"\nRecord Not Found.. ";
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt","stinfo.txt");
            }
            if(tmp==9)
            {
                cout<<"\n\n\n\n\t\t\t\tThank You!!! ";
                cout<<"\n\n\t\t\t\tHave A Good Day ";
                getch();
                exit(0);
            }
            if(tmp==0)
            {
                system("CLS");
                cout<<"\n\n\t\tYou are Logout Now..";
                cout<<"\n\t\tPress to Continue..";
                getch();
                goto mainportal;
            }
            if(tmp<0||tmp>9)
            {
                system("CLS");
                cout<<"\n\n\n\t\t\t\tInvalid Input... ";
            }

            getch();
            cout<<"\n\nPress y , For More Operations Otherwise n : ";
            cin>>opera;
            if(opera!='y')
            {
                getch();
                system("CLS");
                cout<<"\n\n\n\n\n\t\t\t\t\tThank You!!! ";
                getch();
            }
        }
        while(opera=='y'||opera=='Y');
    }

    if(ch==2)
    {
        system("CLS");
        char un[20];
        int val,s=0;
        cout<<"\n\t\t\tWelcome TO Faculty Login Page";
        cout<<"\n\nEneter the UserName :";
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(!fs.eof())
        {
            val=-1;
            fs.read((char *)&f,sizeof(Admin));
            val=f.login();
            if(val==1)
            {
                s=1;
                break;
            }
        }
        fs.close();
        if(s==1)
        {
            system("CLS");
        } //if first login is valid
        if(s!=1) //if first login is invalid then
        {
            system("CLS");
            int ho=0;
            cout<<"\n\n\t\tYour Login Credential are In-Correct";
            cout<<"\nThe UserName is Your ID/Rollno.";
            cout<<"\nThe Password is Case-Sensitive.";
            cout<<"\n\tPress 1. Re-Cover Password \n\t2. Re-Attempt Login \n\t3. Main Portal ";
            cout<<"\nEnter the Choice : ";
            cin>>ho;
            if(ho==1) //recover password
            {
                cout<<"Enter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(!fs.eof())
                {
                    re=-1;
                    fs.read((char *)&f,sizeof(Admin));
                    re=f.recover();
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1)
                {
                    getch();
                    system("CLS");
                    cout<<"\n\n\n\n\t\t\tThank You!!! ";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are a Invalid User.";
                    getch();
                    exit(0);
                }
            } //recover password
            if(ho==2)   //re-attempt of login
            {
                cout<<"Enter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1,valu; //valu for storing login() returned value...suc for success login
                while(!fs.eof())
                {
                    valu=-1;
                    fs.read((char *)&f,sizeof(Admin));
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                if(suc==1)
                {
                    system("CLS");
                }
                else
                {
                    getch();
                    cout<<"\nYou are an Invalid User...";
                    cout<<"\nThank You!!!";
                    getch();
                    exit(0);
                    exit(0);
                }
            }
             if(ho==3)
            {
                getch();
                goto mainportal;
            }
            if(ho!=1&&ho!=2&&ho!=3)
            {
                cout<<"\n\nInvalid Input Provided. ";
                cout<<"\n\n\t\t\tThank You!!!";
                getch();
                exit(0);
            }
        } //CLOSING of first invalid login ( forget password & recover password )
        //begin of faculty
        char con='y';
        do
        {
            system("CLS");
            cout<<"\n\n\t\t\tWelcome To Faculty Portal ";
            cout<<"\n\n\t\t\t\t\t\t    your UserID is : "<<::un;
            cout<<"\n\nPress 1 to View Your Profile.";
            cout<<"\nPress 2 to Know Your Subjects.";
            cout<<"\nPress 3 to Add a Subject.";
            cout<<"\nPress 4 to Delete a Subject.";
            cout<<"\nPress 5 to Modify Your Profile.";
            cout<<"\nPress 0 to LogOut ";
            int choice;
            cout<<"\n\nEnter Your Choice : ";
            cin>>choice;
            if(choice==1)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int x;
                while(!fs.eof())
                {
                    x=0;
                    fs.read((char *)&f,sizeof(Admin));
                    x=f.faprofile();
                    if(x==1)
                    {
                        getch();
                        break;
                    }
                }
                fs.close();
            }  //closing of choice=1
            if(choice==2)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int y;
                while(!fs.eof())
                {
                    y=0;
                    fs.read((char *)&f,sizeof(Admin));
                    int y=f.knowfasub();
                    if(y==1)
                    {
                        getch();
                        break;
                    }
                }
                fs.close();
            } //closing of choice=2
            if(choice==3)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs1.open("tmpfainfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&f,sizeof(Admin));
                    f.addfasub();
                    fs1.write((char *)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("tmpfainfo.txt","fainfo.txt");
            } //closing of choice=3
            if(choice==4)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fstream fs1;
                fs1.open("delfainfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&f,sizeof(Admin));
                    f.delfasub();
                    fs1.write((char *)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("delfainfo.txt","fainfo.txt");
            }
            if(choice==5)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                fs1.open("modfainfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char *)&f,sizeof(Admin));
                    f.modfaprofile();
                    fs1.write((char *)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("modfainfo.txt","fainfo.txt");
            }
            if(choice==0)
            {
                system("CLS");
                cout<<"\n\n\t\t\t\tYou are Logout Now..";
                cout<<"\n\t\t\t\tThank You!!";
                cout<<"\n\t\t\t\tPress to Continue..";
                getch();
                goto mainportal;
            }
            if(choice<0||choice>5)
            {
                cout<<"\nInvalid Input Provided!!!";
                cout<<"\n\n\t\t\t\tEnter To Continue..";
                getch();
                cout<<"\n\nPress y to Continue, otherwise n : ";
                cin>>con;
                if(con!='y'&&con!='Y')
                {
                    system("CLS");
                    cout<<"\n\n\n\n\n\t\t\t\tThank You!!! ";
                    getch();
                    exit(0);
                }
            }
        }
        while(con=='y'||con=='Y');
    } //close of faculty view
    //begin of student view
    if(ch==3)
    {
        system("CLS");
        char un[20];
        int value,s1=0;
        student:
        cout<<"\n\t\t\tWelcome TO Student Login Page";
        cout<<"\n\nEneter the UserName :";
        cin>>::un;
        fstream fs;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(!fs.eof())
        {
            value=-1;
            fs.read((char *)&f,sizeof(Admin));
            value=f.login();
            if(value==1)
            {
                s1=1;
                break;
            }
        }
        fs.close();
        if(s1==1)
        {
            system("CLS");
        } //if first login is valid
        if(s1!=1) //if first login is invalid then
        {
            system("CLS");
            int sho=0;
            cout<<"\n\n\t\tYour Login Credential are In-Correct";
            cout<<"\nThe UserName is Your ID/Rollno.";
            cout<<"\nThe Password is Case-Sensitive.";
            cout<<"\n\tPress 1. Re-Cover Password \n\t2. Re-Attempt Login \n\t3. Main Portal ";
            cout<<"\nEnter the Choice : ";
            cin>>sho;
            if(sho==1) //recover password
            {
                cout<<"Enter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(!fs.eof())
                {
                    re=-1;
                    fs.read((char *)&f,sizeof(Admin));
                    re=f.recover();
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1)
                {
                    getch();
                    system("CLS");
                    cout<<"\n\n\n\n\t\t\tThank You!!! ";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are a Invalid User.";
                    cout<<"\nThank You!!!";
                    getch();
                    exit(0);
                }
            } //recover password
            if(sho==2)   //re-attempt of login
            {
                cout<<"Enter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1,valu; //valu for storing login() returned value...suc for success login
                while(!fs.eof())
                {
                    valu=-1;
                    fs.read((char *)&f,sizeof(Admin));
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                if(suc==1)
                {
                    system("CLS");
                }
                else
                {
                    getch();
                    cout<<"\nYou are an Invalid User...";
                    cout<<"\nThank You!!!";
                    getch();
                    goto student;
                }
            }
            if(sho==3)
            {
                getch();
                goto mainportal;
            }
            if(sho!=1&&sho!=2&&sho!=3)
            {
                cout<<"\n\nInvalid Input Provided. ";
                cout<<"\n\n\t\t\tThank You!!!";
                getch();
                exit(0);
            }
        } //CLOSING of first invalid login ( forget password & recover password )
        //begin of student panel
        char moreop='y';
        do
        {
            system("CLS");
            cout<<"\n\n\t\t\tWelcome To Student Portal ";
            cout<<"\n\n\t\t\t\t\t\t    your UserID is : "<<::un;
            cout<<"\n\nPress 1 to View Your Profile.";
            cout<<"\nPress 2 to Know Your Subjects.";
            cout<<"\nPress 3 to Add a Subject.";
            cout<<"\nPress 4 to Delete a Subject.";
            cout<<"\nPress 5 to Modify Your Profile.";
            cout<<"\nPress 0 to LogOut ";
            int inchoice;
            cout<<"\n\nEnter Your Choice : ";
            cin>>inchoice;
            if(inchoice==1)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                int x;
                while(!fs.eof())
                {
                    x=0;
                    fs.read((char *)&f,sizeof(Admin));
                    x=f.stprofile();
                    if(x==1)
                    {
                        getch();
                        break;
                    }
                }
                fs.close();
            }  //closing of inchoice=1
            if(inchoice==2)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                int y;
                while(!fs.eof())
                {
                    y=0;
                    fs.read((char *)&f,sizeof(Admin));
                    int y=f.knowstsub();
                    if(y==1)
                    {
                        getch();
                        break;
                    }
                }
                fs.close();
            } //closing of inchoice=2
            if(inchoice==3)
            {
                fstream fs;
                fstream fs1;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs1.open("tmpstinfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&f,sizeof(Admin));
                    f.addstsub();
                    fs1.write((char *)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("tmpstinfo.txt","stinfo.txt");
            } //closing of inchoice=3
            if(inchoice==4)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fstream fs1;
                fs1.open("delstinfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&f,sizeof(Admin));
                    f.delstsub();
                    fs1.write((char *)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("delstinfo.txt","stinfo.txt");
            }
            if(inchoice==5)
            {
                fstream fs;
                fstream fs1;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                fs1.open("modstinfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char *)&f,sizeof(Admin));
                    f.modstprofile();
                    fs1.write((char *)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("modstinfo.txt","stinfo.txt");
            }
            if(inchoice==0)
            {
                system("CLS");
                cout<<"\n\n\t\tYou are Logout Now..";
                cout<<"\n\t\t\t\tThank You!!";
                cout<<"\n\t\tPress to Continue..";
                getch();
                goto mainportal;
            }
            if(inchoice<0||inchoice>5)
            {
                cout<<"\nInvalid Input Provided!!!";
                cout<<"\n\n\t\t\t\tEnter To Continue..";
                getch();
                cout<<"\n\nPress y to Continue, otherwise n to perform More Operations : ";
                cin>>moreop;
                if(moreop!='y'&&moreop!='Y')
                {
                    system("CLS");
                    cout<<"\n\n\n\n\n\t\t\t\tThank You!!! ";
                    getch();
                    exit(0);
                }
            }

        }
        while(moreop=='y'||moreop=='Y');
        getch();
    } //closing of student panel ch=3

    if(ch<1||ch>4)
    {
        cout<<"\nInvalid Input Proviided!!! ";
        getch();
        system("CLS");
        cout<<"\n\n\n\t\t\tThank You!!! ";
    }
    return 0;
}
