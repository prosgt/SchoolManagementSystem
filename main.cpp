#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

#define sys "Library Management System"
using namespace std;

class GuidLine
{
private:
    char conditionValue[10];
    void showGuideLineMessage()
    {
        SetConsoleTitle(sys": Guide Lines");
         logo();
        cout <<"\n\n\n"<< setw(65)<< "Hello Friends,\n";
        cout << setw(99)<<"We welcome to you here our system. Please select only correct option from  "<<endl;
        cout << setw(99)<<"the menu. If you press wrong option 3 times then the software goes down.\n\n\n";
        cout << setw(51)<< "1. Show this message again."<<endl;
        cout << setw(57)<< "2. Never show this message again."<<endl;
        cout << setw(28)<< ">>> ";
        char g1;
        cin >> g1;
        switch(g1)
        {
        case '1':
            {
                system("cls");
                ofstream WriteGuideLineValue("GuideLines.txt");
                WriteGuideLineValue << "again";
                WriteGuideLineValue.close();
                break;
            }
        case '2':
            {
                system("cls");
                ofstream WriteGuideLineValue("GuideLines.txt");
                WriteGuideLineValue << "never";
                WriteGuideLineValue.close();
                break;
            }
        }
    }
public:
    void logo()
    {
        cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t|"<<setw(69)<<"LIBRARY MANAGEMENT SYSTEM"<<setw(48)<<"|\n";
        cout<<"\t|"<<setw(66)<<"Genius Public school"<<setw(51)<<"|\n";
        cout<<"\t|"<<setw(64)<<"Birtamode, Jhapa"<<setw(53)<<"|\n";
         cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    }
    void GuidLineCondition()
    {
        ifstream OpenGuidLineFile("GuideLines.txt");
        if(OpenGuidLineFile.is_open())
        {
            OpenGuidLineFile >> conditionValue;
            if(strcmp(conditionValue,"again")==0)
            {
                showGuideLineMessage();
            }
            else if(strcmp(conditionValue,"never")==0)
            {
                system("cls");
                SetConsoleTitle(sys": Guide Lines");
                cout << "You have been blocked the guide line message.\nIf you want to see...\ngoto Setting option."<<endl;
                cout << ">>> ";
                getch();
            }
            else
            {
                system("cls");
                showGuideLineMessage();
            }
        }
        else
        {
            system("cls");
            showGuideLineMessage();
        }
        OpenGuidLineFile.close();
    }
};//    end of guideline class

class Security
{
public:
    void Check()
    {
        cout<<setw(50)<< "Checking";
        for(int i=1;i<=10;i++){
            cout << ".";
            Sleep(40);
        }
        for(int i=1;i<=10;i++){
            cout << ".";
            Sleep(60);
        }
        for(int i=1;i<=10;i++){
            cout << ".";
            Sleep(30);
        }
    }
    void Login();
    void ChangeSecuritySystem();
};
void Security::Login()
{
    SetConsoleTitle(sys": Login");
    char username[20];
    char password[20];
    int ErrorCount;
    ifstream OpenSecurityFile("SecuritySystem.txt");
    if(OpenSecurityFile.is_open())
    {
        char checkUsername[20];
        char checkPassword[20];
        ifstream CheckSecurity;
        CheckSecurity.open("SecuritySystem.txt");
        CheckSecurity>>checkUsername>>checkPassword;
        CheckSecurity.close();
        ErrorCount=0;
        _checkUser:
        system("cls");
        cout<<"\n\n\n\n\n\n"<< setw(65)<<"Username: ";
        cin>>username;
        if(strcmp(username,checkUsername)==0)
        {
            Check();
            cout <<setw(10)<< "Ok !";
            Sleep(1000);
            cout<<endl<<endl;
            goto _checkPass;
        }
        else
        {
            Check();
            cout <<setw(10)<< "Error !";
            ErrorCount++;
            Sleep(1000);
            if(ErrorCount>=3)
            {
                system("cls");
                cout<<"\n\n\n"<< setw(75) << "Oops, Server is going to die.";
                Sleep(2000);
                exit(0);
            }
            goto _checkUser;
        }
        ErrorCount=0;
        _checkPass:
        system("cls");
        cout <<"\n\n\n\n\n\n"<<setw(65)<< "Password : ";
        cin>>password;
        if(strcmp(password,checkPassword)==0)
        {
            Check();
            cout <<setw(10)<< "Ok !";
            Sleep(1000);
            goto _SecurityAccess;
        }
        else
        {
            Check();
            cout <<setw(10)<< "Error !";
            ErrorCount++;
            Sleep(1000);
            if(ErrorCount>=3)
            {
                system("cls");
                cout<<"\n\n\n"<< setw(75) << "Oops, Server is going to die.";
                Sleep(2000);
                exit(0);
            }
            goto _checkPass;
        }
        _SecurityAccess:
        system("cls");
        cout <<"\n\n\n\n"<< setw(65)<< "Security Authorized.";
        Sleep(1000);
        system("cls");
    }
    else
    {
        //unable to open the file
        ErrorCount = 0;
        user:
        system("cls");
        cout <<"\n\n\n\n\n\n"<< setw(65)<<"Username : ";
        cin>>username;
        if(strcmp(username,"admin")==0)
        {
            Check();
            cout <<setw(10)<< "Ok !";
            Sleep(1000);
            cout<<endl<<endl;
//            goto pass;
        }
        else
        {
            Check();
            cout <<setw(10)<< "Error !";
            ErrorCount++;
            Sleep(1000);
            if(ErrorCount>=3)
            {
                system("cls");
                cout <<"\n\n\n"<< setw(75)<< "Oops, Server is going to die.";
                Sleep(2000);
                exit(0);
            }
            goto user;
        }
        ErrorCount=0;
        pass:
        system("cls");
        cout<<"\n\n\n\n\n\n"<< setw(65) << "Password : ";cin>>password;
        if(strcmp(password,"admin")==0)
        {
            Check();
            cout <<setw(10)<< "Ok !";
            Sleep(1000);
            goto SecurityAccess;
        }
        else
        {
            Check();
            cout <<setw(10)<< "Error !";
            ErrorCount++;
            Sleep(1000);
            if(ErrorCount>=3)
            {
                system("cls");
                cout<<"\n\n\n"<< setw(75) << "Oops, Server is going to die.";
                Sleep(2000);
                exit(0);
            }
            goto pass;
        }
        SecurityAccess:
        system("cls");
        cout << "\n\n\n\t\t\t\t\t\t\tSecurity Authorized.";
        Sleep(1000);
        system("cls");
        cout <<"\n\n\n\n\n\t\t"<<"This is your first Login  So you need to change default username and password for better Security Mechanism."<<endl;
        cout<< "\n\t\t\t\t\t\tPress any key to continue...";
        getch();
        ChangeSecuritySystem();
        //getch();
    }
}// login function end here
void Security::ChangeSecuritySystem()
{
    //Login();
    SetConsoleTitle(sys": Authentication Configure");
    char username[20];
    char password[20];
    system("cls");
    cout<<"\n\n\n\n\n\n"<< setw(65) << "Username : ";
    cin>>username;
    cout << setw(65)<< "Password : ";
    cin>>password;
    ofstream SecurityChange;
    SecurityChange.open("SecuritySystem.txt");
    SecurityChange<<username<<endl<<password;
    SecurityChange.close();
}//     change security system close here

class Students
{
public:
    int S_Id;
    char S_Name[30],S_Address[20],S_Gender[6],S_Email[30],S_Contact[15],S_Faculty[20];
    void AddStudents(int);
    void StudentsLists();
    void SearchStudents();
    void UpdateStudents();
    void DeleteStudents();
    void getStudentsData();
    int S_IdChecker();
};
void Students::AddStudents(int si)
{
    /*cout << "Student ID : ";
    cin >> S_Id;*/
    cout <<"\n" << setw(80) <<"Adding New Student:\n\n";
    S_Id = si;
    cout << setw(75)<< "Student Name : ";
    cin.ignore();
    cin.getline(S_Name,sizeof(S_Name));
    cout << setw(75)<< "Faculty      : ";
    cin.getline(S_Faculty,sizeof(S_Faculty));
    cout << setw(75)<< "Address      : ";
    //cin.ignore();
    cin.getline(S_Address,sizeof(S_Address));
    cout << setw(75)<< "Gender       : ";
    cin >> S_Gender;
    cout << setw(74) << "Email        : ";
    cin >> S_Email;
    cout << setw(74) << "Contact      : ";
    cin >> S_Contact;
}
void Students::getStudentsData()
{
    cout<<setw(5)<<S_Id<<setw(25)<<S_Name<<setw(25)<<S_Faculty<<setw(20)<<S_Address<<setw(15)<<S_Gender<<setw(25)<<S_Email<<setw(20)<<S_Contact<<endl;
}
int Students::S_IdChecker()
{
    return S_Id;
}



//  library class start
class Library
{
public:
    char BookTitle[20],BookAuthor[20],BookPublisher[20],BookPublishedDate[15],BookPurchaseDate[15],BookCat[30];
    int BookCodeNo;
    float BookRate;
    void AddNewBook(int);
    void BookList();
    void BookSearch();
    void BookUpdate();
    void BookDelete();
    int getBookCodeNo();
    char getBookFaculty();
    void getMinBookInfo();
    void getFullBookInfo();
};
//  library class end
//  library functions start
void Library::AddNewBook(int x)
{
    BookCodeNo = x;
    cout << "Book Category : ";
    cin.ignore();
    cin.getline(BookCat,sizeof(BookCat));
    cout << "Book Title : ";
    cin.getline(BookTitle,sizeof(BookTitle));
    cout << "Book Published Date : ";
    cin.getline(BookPublishedDate,sizeof(BookPublishedDate));
    cout << "Book Purchased Date : ";
    cin.getline(BookPurchaseDate,sizeof(BookPurchaseDate));
    cout << "Book Author : ";
    cin.getline(BookAuthor,sizeof(BookAuthor));
    cout << "Book Publisher : ";
    cin.getline(BookPublisher,sizeof(BookPublisher));
    cout << "Book Price : ";
    cin>>BookRate;
}
void Library::getMinBookInfo()
{
    cout<<setw(5)<<BookCodeNo<<setw(25)<<BookTitle<<setw(25)<<BookCat<<endl;
}
int Library::getBookCodeNo()
{
    return BookCodeNo;
}
void Library::getFullBookInfo()
{
    cout<<endl<<"Book Code\t\t:\t"<<BookCodeNo<<endl<<"Book Title\t\t:\t"<<BookTitle<<endl<<"Book Category\t\t:\t"<<BookCat<<endl<<"Book Published Date\t:\t"<<BookPublishedDate<<endl<<"Book Purchased Date\t:\t"<<BookPurchaseDate<<endl<<"Book Author\t\t:\t"<<BookAuthor<<endl<<"Book Publisher\t\t:\t"<<BookPublisher<<endl<<"Book Price\t\t:\t"<<BookRate<<endl<<endl;
}/*
char Library::getBookFaculty()
{
    return BookCat;
}*/
//  library functions end
int main()
{
    Restart:

    GuidLine G;
    Security S;
    Students STU,STUREAD;
    Library BooksWrite,BooksRead,BooksIssue,BooksRecepit;

    S.Login();

    G.GuidLineCondition();

    //  menu items
    SetConsoleTitle(sys": Main Menus");
    char input;
    MainMenu:
    system("cls");
    G.logo();
    cout <<"\n"<< setw(80)<<"Select any option from below:\n"<<endl;
    cout << setw(63)<< "1. Students."<<endl;
    cout << setw(62)<< "2. Library."<<endl;
    cout << setw(66)<< "3. Books Issue."<<endl;
    cout << setw(63)<< "4. Settings."<<endl;
    cout << setw(60)<< "5. Helps."<<endl;
    cout << setw(61)<< "6. About ?"<<endl;
    cout << setw(60)<< "7. Exits."<<endl;
    cout << setw(74) << "8. Restart The Machine."<<endl;
    cout << setw(55)<< ">>> ";
    input = getch();
    switch(input)
    {
    case '1'://     Students
        {
            StudentsMenu:
            system("cls");
            G.logo();
            SetConsoleTitle(sys": Main Menus: Students Menus");
            cout <<"\n" << setw(80)<<"Select any option from below:\n"<<endl;
            cout << setw(70)<< "1. Add Students."<<endl;
            cout << setw(72)<< "2. Students Lists."<<endl;
            cout << setw(72)<< "3. Search Student."<<endl;
            cout << setw(72)<< "4. Update Student."<<endl;
            cout << setw(72)<< "5. Delete Student."<<endl;
            cout << setw(62)<< "6. Back."<<endl;
            cout << setw(58)<< ">>> ";
            input = getch();
            switch(input)
            {
            case '1'://     Add Student
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Students Menus: Student Reregistration");
                    int sid,idR;
                    int isFound=0;
                    IDTaken_TryAgain:
                    system("cls");
                    G.logo();
                    cout <<setw(72)<< "Student ID : ";
                    cin >> sid;
                    ifstream FILE001;
                    FILE001.open("student.txt", ios::in);
                    if(FILE001.is_open())
                    {
                        FILE001.seekg(0,ios::beg);
                        while(!FILE001.eof()){
                            idR = STUREAD.S_IdChecker();
                            if(idR==sid)
                            {
                                isFound=1;
                                break;
                            }
                            else
                            {
                                isFound=2;
                            }
                            FILE001.read((char *)&STUREAD,sizeof(STUREAD));
                        }
                    }
                    else
                    {
                        goto idNthMatch;
                    }
                    FILE001.close();
                    if(isFound==1)
                    {
                        cout << setw(65)<< "Student ID "<<sid<<" is taken.";
                        Sleep(1000);
                        system("cls");
                        goto IDTaken_TryAgain;
                    }
                    else if(isFound>1)
                    {
                        idNthMatch:
                        system("cls");
                        G.logo();
                        STU.AddStudents(sid);
                        ofstream FILE002;
                        FILE002.open("student.txt", ios::out | ios::app);
                        FILE002.write((char *)&STU,sizeof(STU));
                        FILE002.close();
                        cout<<endl<<setw(80)<<"Inserted Successfully !\n";
                        char confirm;
                        cout<<setw(82)<<"Want to record more(Y/N)?\n";
                         cout <<setw(60) <<">>> ";
                        cin>>confirm;
                        if(confirm =='Y'|| confirm== 'y')
                        {
                            goto IDTaken_TryAgain;
                        }
                    }
                    goto StudentsMenu;
                }
            case '2': //    Students Lists
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Students Menus: Student List");
                    ifstream FILE003;
                    FILE003.open("student.txt", ios::in);
                    if(FILE003.is_open())
                    {
                        G.logo();
                        cout << setw(72) << "Students List:"<<endl<<endl ;
                        cout <<setw(5)<<"id"<<setw(15)<<"Name"<<setw(15)<<"Faculty"<<setw(20)<<"Address"<<setw(20)<<"Gender"<<setw(25)<<"Email"<<setw(20)<<"Contact"<<endl <<" ";
                        for(int i=1;i<=130;i++){cout<<"-";}cout<<endl;
                        FILE003.seekg(0,ios::beg);
                        FILE003.read((char *)&STUREAD,sizeof(STUREAD));
                        while(!FILE003.eof()){
                            STUREAD.getStudentsData();
                            FILE003.read((char *)&STUREAD,sizeof(STUREAD));
                        }
                        FILE003.close();
                    }
                    else
                    {
                        system("cls");
                        cout << "\nThe file is not exists here."<<endl<<"Please Add some new records.";
                    }
                    cout << ">>> ";
                    getch();
                    goto StudentsMenu;
                }
            case '3'://     Search Students
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Students Menus: Student Search");
                    int S_IDCheck,idR,idMatchs;
                    cout << "Student Search :"<<endl;
                    cout << "Enter Student ID (for search): ";
                    cin>>S_IDCheck;
                    ifstream FILE004;
                    FILE004.open("student.txt");
                    if(FILE004.is_open())
                    {
                        FILE004.seekg(0,ios::beg);
                        while(!FILE004.eof()){
                            idR = STUREAD.S_IdChecker();
                            if(idR==S_IDCheck)
                            {
                                idMatchs=1;
                                goto LEVEL001;
                                //break;
                            }
                            else
                            {
                                idMatchs=0;
                            }
                            FILE004.read((char *)&STUREAD,sizeof(STUREAD));
                        }
                        LEVEL001:
                        if(idMatchs==1)
                        {
                            cout <<setw(5)<<"id"<<setw(25)<<"Name"<<setw(25)<<"Faculty"<<setw(20)<<"Address"<<setw(15)<<"Gender"<<setw(25)<<"Email"<<setw(20)<<"Contact"<<endl;
                            for(int i=1;i<=130;i++){cout<<"-";}cout<<endl;
                            STUREAD.getStudentsData();
                            FILE004.read((char *)&STUREAD,sizeof(STUREAD));
                        }
                        else
                        {
                            cout <<endl<< "Student ID "<<S_IDCheck<<" is not match.";
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\nThe file is not exists here."<<endl<<"Please Add some new records.";
                    }
                    FILE004.close();
                    cout << ">>> ";
                    getch();
                    goto StudentsMenu;
                }
            case '4'://     Student Update
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Students Menus: Student Update");
                    int UpdateIDChecker,UpdateID,UpdateIDMatch;
                    cout << "Enter Student ID (for update): ";
                    cin>>UpdateID;
                    ifstream FILE005;
                    FILE005.open("student.txt",ios::in);
                    if(FILE005.is_open())
                    {
                        FILE005.seekg(0,ios::beg);
                        while(!FILE005.eof()){
                            UpdateIDChecker = STUREAD.S_IdChecker();
                            if(UpdateIDChecker==UpdateID)
                            {
                                UpdateIDMatch=1;
                                break;
                            }
                            else
                            {
                                UpdateIDMatch=0;
                            }
                            FILE005.read((char *)&STUREAD,sizeof(STUREAD));
                        }
                        if(UpdateIDMatch==1)
                        {
                            LEVEL000001:
                            system("cls");
                            char input1;
                            cout <<endl<<endl<<setw(5)<<"id"<<setw(25)<<"Name"<<setw(25)<<"Faculty"<<setw(20)<<"Address"<<setw(15)<<"Gender"<<setw(25)<<"Email"<<setw(20)<<"Contact"<<endl;
                            for(int i=1;i<=130;i++){cout<<"-";}cout<<endl;
                            STUREAD.getStudentsData();
                            FILE005.read((char *)&STUREAD,sizeof(STUREAD));
                            /*
                            cout<<endl<<"1. Update."<<endl<<"2. Back."<<endl;
                            cout << ">>> ";
                            input1 = getch();
                            switch(input1)
                            {
                            case '1':
                                {*/
                                    ofstream SFILETEMP("STEMP.txt", ios::out);
                                    ifstream FILE006;
                                    FILE005.seekg(0,ios::beg);
                                    FILE005.read((char*)&STU,sizeof(STUREAD));
                                    while(!FILE005.eof())
                                    {
                                        UpdateIDChecker = STUREAD.S_IdChecker();
                                        if(UpdateIDChecker==UpdateID)
                                        {
                                            SFILETEMP.write((char*)&STUREAD, sizeof(STUREAD));
                                        }
                                        FILE005.read((char*)&STU,sizeof(STUREAD));
                                    }
                                    FILE005.close();
                                    STU.AddStudents(UpdateID);
                                    SFILETEMP.write((char*)&STU, sizeof(STU));
                                    SFILETEMP.close();
                                    remove("student.txt");
                                    rename("STEMP.txt","student.txt");
                                    getch();
                                    goto StudentsMenu;/*
                                }
                            case '2':
                                {
                                    system("cls");
                                    goto StudentsMenu;
                                }
                            default:
                                {
                                    system("cls");
                                    goto LEVEL000001;
                                }
                            }*/
                        }
                        else
                        {
                            cout <<endl<< "Student ID "<<UpdateIDMatch<<" is not match.";
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\nThe file is not exists here."<<endl<<"Please Add some new records.";
                    }
                    FILE005.close();
                    cout << ">>> ";
                    getch();
                    goto StudentsMenu;
                }
            case '5'://     Delete Student
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Students Menus: Student Delete");
                    cout << "I am Student Delete Section."<<endl;
                    cout << ">>> ";
                    getch();
                    goto StudentsMenu;
                }
            case '6'://     Back
                {
                    system("cls");
                    goto MainMenu;
                }
            default:
                {
                    system("cls");
                    goto StudentsMenu;
                }
            }
            goto MainMenu;
        }
    case '2'://     Library
        {
            LibMenu:
            system("cls");
            SetConsoleTitle(sys": Main Menus: Library Menus");
            G.logo();
            cout <<"\n\n\n" << setw(80)<<"Select any option from below:\n\n"<<endl;
            cout << "1. Add New Book."<<endl;
            cout << "2. Books List."<<endl;
            cout << "3. Search Book."<<endl;
            cout << "4. Update Book Information."<<endl;
            cout << "5. Delete Book."<<endl;
            cout << "6. Back."<<endl;
            cout << ">>> ";
            input = getch();
            switch(input)
            {
            case '1':// Add New Books
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Library Menus: Add New Book");
                    int BookCodeChecker,BookCode,BookCodeMatch,isFound;
                    BookCodeTaken_TryAgain:
                    cout << "Book Code No. : ";
                    cin >> BookCode;
                    ifstream BOOK01;
                    BOOK01.open("Books.txt", ios::in);
                    if(BOOK01.is_open())
                    {
                        BOOK01.seekg(0,ios::beg);
                        while(!BOOK01.eof()){
                            BookCodeChecker = BooksRead.getBookCodeNo();
                            if(BookCodeChecker==BookCode)
                            {
                                isFound=1;
                                break;
                            }
                            else
                            {
                                isFound=2;
                            }
                            BOOK01.read((char *)&BooksRead,sizeof(BooksRead));
                        }
                    }
                    else
                    {
                        goto BookCodeNoMatch;
                    }
                    BOOK01.close();
                    if(isFound==1)
                    {
                        cout << "Student ID "<<BookCode<<" is taken.";
                        Sleep(2000);
                        system("cls");
                        goto BookCodeTaken_TryAgain;
                    }
                    else if(isFound>1)
                    {
                        BookCodeNoMatch:
                        BooksWrite.AddNewBook(BookCode);
                        ofstream BOOK02;
                        BOOK02.open("Books.txt", ios::out | ios::app);
                        BOOK02.write((char *)&BooksWrite,sizeof(BooksWrite));
                        BOOK02.close();
                        cout<<endl<<"Inserted Successfully !"<<endl;
                    }
                    cout << ">>> ";
                    getch();
                    goto LibMenu;
                }
            case '2':// books list
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Library Menus: Book List");
                    ifstream BOOK03;
                    BOOK03.open("Books.txt", ios::in);
                    if(BOOK03.is_open())
                    {
                        cout << "Books List."<<endl<<endl;
                        cout <<setw(5)<<"id"<<setw(25)<<"Book Title"<<setw(25)<<"Book Category"<<endl;
                        for(int i=1;i<=60;i++){cout<<"-";}cout<<endl;
                        BOOK03.seekg(0,ios::beg);
                        BOOK03.read((char *)&BooksRead,sizeof(BooksRead));
                        while(!BOOK03.eof()){
                            BooksRead.getMinBookInfo();
                            BOOK03.read((char *)&BooksRead,sizeof(BooksRead));
                        }
                        BOOK03.close();
                    }
                    else
                    {
                        system("cls");
                        cout << "\nThe file is not exists here."<<endl<<"Please Add some new records."<<endl;
                    }
                    cout << ">>> ";
                    getch();
                    goto LibMenu;
                }
            case '3':// books search
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Library Menus: Book Search");
                    int BookCodeChecker,BCode,BCodeM;
                    ifstream BOOK04;
                    BOOK04.open("Books.txt");
                    if(BOOK04.is_open())
                    {
                        cout << "Book Search :"<<endl;
                        cout << "Enter Book Code No. (for search): ";
                        cin>>BCode;
                        BOOK04.seekg(0,ios::beg);
                        while(!BOOK04.eof()){
                            BookCodeChecker = BooksRead.getBookCodeNo();
                            if(BookCodeChecker==BCode)
                            {
                                BCodeM=1;
                                goto LEVELB01;
                            }
                            else
                            {
                                BCodeM=0;
                            }
                            BOOK04.read((char *)&BooksRead,sizeof(BooksRead));
                        }
                        LEVELB01:
                        if(BCodeM==1)
                        {
                            BooksRead.getFullBookInfo();
                            BOOK04.read((char *)&BooksRead,sizeof(BooksRead));
                        }
                        else
                        {
                            cout <<endl<< "Book Code "<<BCode<<" is not match."<<endl;
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\nThe file is not exists here."<<endl<<"Please Add some new records."<<endl;
                    }
                    BOOK04.close();
                    cout << ">>> ";
                    getch();
                    goto LibMenu;
                }
            case '4':// books info update
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Library Menus: Book Info Update");
                    cout << ">>> ";
                    getch();
                    goto LibMenu;
                }
            case '5':// books delete
                {
                    system("cls");
                    SetConsoleTitle(sys": Main Menus: Library Menus: Delete Book");
                    cout << ">>> ";
                    getch();
                    goto LibMenu;
                }
            case '6':// back to library menu
                {
                    system("cls");
                    goto MainMenu;
                }
            default:
                {
                    system("cls");
                    goto LibMenu;
                }
            }
            goto MainMenu;
        }
    case '3'://     Books Issue
        {
            system("cls");
            cout << "I am Books Issue Menu."<<endl;
            cout << ">>> ";
            getch();
            goto MainMenu;
        }
    case '4'://     Settings
        {
            system("cls");
            cout << "I am Settings Menu."<<endl;
            cout << ">>> ";
            getch();
            goto MainMenu;
        }
    case '5'://     Help
        {
            system("cls");
            cout << "I am Helps Menu."<<endl;
            cout << ">>> ";
            getch();
            goto MainMenu;
        }
    case '6'://     About
        {
            system("cls");
            cout << "I am About Menu."<<endl;
            cout << ">>> ";
            getch();
            goto MainMenu;
        }
    case '7'://     Exits
        {
            system("cls");
            cout << "The Server is Turning Off."<<endl;
            Sleep(2000);
            exit(0);
        }
    case '8'://     Restart
        {
            system("cls");
            cout << "System is Restarting";
            for(int i=1;i<=20;i++){
                cout << " .";
                Sleep(50);
            }
            Sleep(1000);
            goto Restart;
        }
    default:
        {
            system("cls");
            goto MainMenu;
        }
    }


    return 0;
}
