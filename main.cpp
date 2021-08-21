#include <iostream>
#include<fstream>
#include<cmath>

using namespace std;

int main()
{
    int cash,cash1,cash2,cash3;
    string line,line4;
    int line2;
    string pin,pass1,pass2;
    int c;
    cout<<endl;
    cout<<"              *******************************************"<<endl;
    cout<<"              *  WELCOME TO BANK OF INDIA ATM SERVICEs  *"<<endl;
    cout<<"              *******************************************"<<endl<<endl;
    ifstream p;
    p.open("PIN.txt");
cout<<"   Enter 4 digit pin   ";
cin>>pin;
    if(p.is_open()){
        while(!p.eof()){
            p>>line;
            if(pin==line){
                p.close();
                do{
                    cout<<endl;
                    cout<<"   ***********************************"<<endl;
                    cout<<"   * 1. Balance Inquiry              *"<<endl;
                    cout<<"   * 2. Withdrawal                   *"<<endl;
                    cout<<"   * 3. Deposit                      *"<<endl;
                    cout<<"   * 4. Transaction list             *"<<endl;
                    cout<<"   * 5. Deposition list              *"<<endl;
                    cout<<"   * 6. Change PIN                   *"<<endl;
                    cout<<"   * 7. EXIT                         *"<<endl<<endl;
                    cout<<"    Please Enter your Choice    "<<endl;
                    cin>>c;
                    switch(c){
                    case 1:
                        {
                            ifstream b;
                            b.open("Balance.txt");
                            if(b.is_open()){
                                while(!b.eof()){
                                    b>>line2;
                                    cout<<endl<<"Your current balance is: "<<line2<<endl;
                                }
                            }
                            b.close();
                            break;
                        }
                    case 2:
                        {
                            ifstream wd;
                            wd.open("Balance.txt");
                            if(wd.is_open()){
                                while(!wd.eof()){
                                    wd>>line2;
                                    cout<<"Enter the amount to withdraw: ";
                                    cin>>cash;
                                    if(cash>line2){
                                        cout<<"Transaction failed"<<endl<<"Please enter valid amount";
                                    }else{
                                        cash1=line2-cash;
                                        cout<<endl<<"Your remaining balance is: "<<cash1<<endl;
                                        cout<<endl<<"Thank you for using our ATM service"<<endl;
                                        wd.close();
                                        ofstream iwd;
                                        iwd.open("Balance.txt");
                                        if(iwd.is_open()){
                                            iwd<<cash1;
                                        }
                                        iwd.close();
                                        fstream itl;
                                        itl.open("Transition list.txt",ios::app);
                                        if(itl.is_open()){
                                            itl<<endl<<"Rs."<<cash<<endl;
                                        }
                                        itl.close();
                                    }
                                }
                            }
                            break;
                        }
                    case 3:
                        {
                            ifstream d;
                            d.open("Balance.txt");
                            if(d.is_open()){
                                while(!d.eof()){
                                    d>>line2;
                                    cout<<"Enter the amount to deposit: ";
                                    cin>>cash2;
                                    cash3=line2+cash2;
                                    cout<<endl<<"Your remaining balance is: "<<cash3<<endl;
                                    cout<<endl<<"Thank you for using our ATM service"<<endl;
                                    d.close();
                                    ofstream id;
                                    id.open("Balance.txt");
                                    if(id.is_open()){
                                        id<<cash3;
                                    }
                                    id.close();
                                    fstream idl;
                                    idl.open("Deposition list.txt",ios::app);
                                    if(idl.is_open()){
                                        idl<<endl<<"Rs."<<cash2<<endl;
                                    }
                                    idl.close();
                                }
                            }
                            break;
                        }
                    case 4:
                        {
                            ifstream f("Transition list.txt");
                            if(f.is_open()){
                                cout<<endl<<f.rdbuf();
                            }
                            f.close();
                            break;
                        }
                    case 5:
                        {
                            ifstream f2("Deposition list.txt");
                            if(f2.is_open()){
                                cout<<endl<<f2.rdbuf();
                            }
                            f2.close();
                            break;
                        }
                    case 6:
                        {
                            ofstream pn;
                            pn.open("PIN.txt");
                            if(pn.is_open()){
                                cout<<"Enter new PIN: ";
                                cin>>pass1;
                                cout<<"Re-enter new PIN: ";
                                cin>>pass2;
                                if(pass1==pass2){
                                    pn<<pass1;
                                    cout<<"PIN changed successfully";
                                }
                            }else{
                                cout<<"Please enter a valid PIN";
                            }
                            pn.close();
                            break;
                        }
                    case 7:
                        {
                            break;
                        }
                    default:
                        {
                            cout<<"Please enter valid choice";
                        }
                    }
                }
                while(c!=7);
            }else{
                cout<<endl<<"    PLEASE ENTER VALID PIN";
            }
        }
    }
    return 0;
}
