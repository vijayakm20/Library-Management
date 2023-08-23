#include <bits/stdc++.h>
using namespace std;

void loginadmin()
{
    cout<<"Type your username"<<endl;
    
    string u_name;
    cin>>u_name;
    string u_password;
    cout<<"Type your password"<<endl;
    cin>>u_password;

    ifstream hin("username.xlsx");
    ifstream pin("password.xlsx");
 
    // creating a content string variable and filling it with string present there in the text file
    string user_name;
    hin>>user_name;
    string user_password;
    pin>>user_password;
    if(u_name==user_name && u_password==user_password)
    {
        cout<<"Login successful"<<endl;
    }

    else 
    {
         cout<<"Entered wrong username or password"<<endl;
         cout<<"1. Retry" <<endl;
         cout<<"2. Exit"<<endl;
         int p;
         cin>>p;
         if(p==1)
         {loginadmin();}
         else 
         {
            exit;
         }
         
    }

}
void createadmin()
{
    ifstream checkus("username.xlsx");
    string checkusername;
    checkus>>checkusername;
    if(checkusername.length()>1)
    {
        cout<<"Already admin exists you can't create a new admin"<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Exit"<<endl;
        int z;
        cin>>z;
        if(z==1)
        {
            loginadmin();
        }
        else
        {
            exit;
        }
    }
    else
   { cout<<"Type your username"<<endl;
    
    string name;
    cin>>name;
    ofstream hout("username.xlsx");
    hout<<name<<endl;
    cout<<"Type your password"<<endl;

    ofstream pout("password.xlsx");
    string password;
    cin>>password;
    pout<<password<<endl;
    cout<<"You have created account Please log in "<<endl;
    loginadmin();
}

}

void admin()
{
    cout<<"Choose 1,2"<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Create a admin"<<endl;
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"You Have entered 1"<<endl;
        loginadmin();
    }
     else if(n==2)
    {
        cout<<"You Have entered 2"<<endl;
        createadmin();
    }
    else{
        cout<<"You have entered wrong choice"<<endl;
        admin();
    }
}
int main()
{
    cout<<"Choose your postion(1,2)"<<endl;
    cout<<"1. Admin"<<endl;
    cout<<"2. User"<<endl;
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"You Have entered 1"<<endl;
        admin();
    }
    else if(n==2)
    {
        cout<<"You Have entered 2"<<endl;
    }
    else{
        cout<<"You have entered wrong position"<<endl;
        main();
    }
    return 0;

}