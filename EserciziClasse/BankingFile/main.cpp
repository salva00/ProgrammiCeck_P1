#include <iostream>
#include <fstream>
#include <iomanip>

int getRequest();
bool shouldDisplay(int,double );
void outputLine(int, const std::string&,double);
int main() {
    //ifstream constructor opens the file
    std::ifstream inClientFile{"clients.txt",std::ios::in};

    //exit program if ifstream could not open file
    if (!inClientFile){
        std::cerr<< "File could not be opened"<<std::endl;
        exit(EXIT_FAILURE);
    }

    //get user's request (e.g., zero, credit or debit balance)
    int request{getRequest()};

    //process user's request
    while (request !=4){
        switch (request) {
            case 1:
                std::cout<<"\nAccounts with zero balances:\n";
                break;
            case 2:
                std::cout<<"\nAccounts with credit balances:\n";
                break;
            case 3:
                std::cout<<"\nAccounts with debit balances:\n";
                break;
        }
        int account; //the account number
        std::string name; //the account owner's name
        double balance; //the account balance

        //read account, name and balance from file

        //display file content (until eof)
        while(!inClientFile.eof()){
            //read accounr, name and balance from file
            inClientFile >> account >> name >> balance;
            //display record
            if(shouldDisplay(request,balance)){
                outputLine(account,name,balance);
            }
        }
        inClientFile.clear();//reset eof for next input
        inClientFile.seekg(0);//reposition to beginning of file
        request=getRequest();
    }

    std::cout << "End of file" << std::endl;
    return 0;
}

int getRequest(){
    //dispay request options
    std::cout << "\nEnter request\n"
        << " 1 - List accounts with zero balances\n"
        << " 2 - List accounts with credit balances\n"
        << " 3 - List accounts with debit balances\n"
        << " 4 - End of run"<<std::fixed<<std::showpoint;
    int type;   //request from user

    do{
        std::cout <<"\n? ";
        std::cin >> type;
    } while (type<1 || type>4);

    return type;
}

bool shouldDisplay(int type, double balance){
    //determine whether to diplay zero balances
    if (type==1 && balance==0){
        return true;
    }
    //determine whether to diplay credit balances
    if (type==2 && balance<0){
        return true;
    }
    //determine whether to diplay debit balances
    if (type==3 && balance>0){
        return true;
    }
    return false;
}
//diplay single record from file
void outputLine(int account, const std::string& name, double balance){
    std::cout <<std::left<< std::setw(10)<<account<<std::setw(13)<<name
        <<std::setw(7)<<std::setprecision(2)<< std::right<<balance<<std::endl;
}