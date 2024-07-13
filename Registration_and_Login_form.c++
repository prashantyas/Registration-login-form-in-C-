#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>

using namespace std;

class Login{
private:
string LoginId, Password, Name;
public:
Login():LoginId(""), Password(""), Name(""){}

void setID(string id){
    LoginId=id;
}
void setPW(string pw){
    Password=pw;
}
void setNM(string nm){
    Name=nm;
}

string getNM(){
    return Name;
}
string getID(){
    return LoginId;
}
string getPW(){
    return Password;
}
};

void registration(Login log){
    system("cls");
    string id, pw, nm;
    cout<<"\t Enter your Name: ";
    cin>>nm;
    log.setNM(nm);

    cout<<"\t Enter Login ID: ";
    cin>>id;
    log.setID(id);
    
    start:
    cout<<"\t Enter A strong Password: ";
    cin>>pw;
    if(pw.length()>=8){
    log.setPW(pw);
}
    else{
        cout<<"\t Enter Minimum 8 Characters"<<endl;
        goto start;
}
    ofstream outfile("C:/Users/prash/projects/Project 3/Login.txt", ios::app);
    if(!outfile){
        cout<<"\t Error: File Can't open"<<endl;
    }
    else{
        outfile<<"\t"<<log.getNM()<<" : "<<log.getID()<<" : "<<log.getPW()<<endl<<endl<<endl;
        cout<<"\t User registred Successfully!"<<endl;
    }
    outfile.close();
    Sleep(3000);
}

void login(){
    system("cls");
    string nm, id, pw;
    cout<<"\t Enter Your Name: ";
    cin>>nm;

    cout<<"\t Enter Login Id: ";
    cin>>id;

    cout<<"\t Enter Password: ";
    cin>>pw;

    ifstream infile("C:/Users/prash/projects/Project 3/Login.txt");
    if(!infile){
        cout<<"\t Error : File Can't open"<< endl;    
    }
    else{
        string line;
        bool found = false;
        while (getline(infile, line)){
            stringstream ss;
            ss<<line;
            string userNM, userID, userPW; 
            char delimiter;
            ss>>userNM>>delimiter>>userID>>delimiter>>userPW;

            if(nm==userNM && id==userID && pw==userPW){
                found == true;

                cout<<"\t Please wait";
                for (int i = 0; i < 3; i++)
                {
                    cout<<".";
                    Sleep(800);
                }
                system("cls");
                cout<<"\t Welcome to This Page!"<<endl;
            }
           }
                if(found=false){
            cout<<"\t Error : Incorrect Name, ID OR Password"<<endl;
        }
    }
        infile.close();
        Sleep(5000);
}

int main()
{
    Login log;

    bool exit = false;

    while (!exit)
    {
        system("cls");
        int val;
        cout<<"\t Welcome To Registration And Login Form"<<endl;
        cout<<"\t*****************************************"<<endl;
        cout<<"\t1. Register."<<endl;
        cout<<"\t2. Login."<<endl;
        cout<<"\t3. Exit"<<endl;
        cout<<"\t Enter Choice:  ";
        cin>>val;

        if(val==1){
            registration(log);
        }
        else if(val==2){
            login();
        }
        else if(val==3){
            system("cls");
            exit = true;
            cout<<"\t Good luck!"<<endl;
            Sleep(3000);
        }
    }
    return 0;    
}