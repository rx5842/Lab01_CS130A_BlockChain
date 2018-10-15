//By Ryan Xia
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include<cstring>
#include <string.h>
#include <openssl/sha.h>
#include "blockChain.h"

using namespace std;

int getUserInput () {
  int userSelection;
  cout<<"1) Add A Transaction \n";
  cout<<"2) Find A Transaction with the name of Sender\n";
  cout<<"3) Verify and Print \n";
  cout<<"4) Exit the Program \n";
  cin>>userSelection;
  return userSelection;
}

int main(int argv, char** argc){

srand(time(NULL));

  int userSelection;
  
  blockChain b;

  cout<<"Welcome to the BlockChain Tester \nPlease Select an option from below\n";
  userSelection=getUserInput();
  
  while(userSelection!=4) {
    if(userSelection<1||userSelection>4) {
      cout<<"Your input is not one of the options try again. \n";
      userSelection=getUserInput();
    }
    else if (userSelection==1){
      
      cout<<"Add A Transaction \n";
      cout<<"Input the amount: ";
      int amt;
      cin>>amt;
      cout<<"Input the Sender ";
      string sender;
      cin>>sender;
      cout<<"Input the Receiver: ";
      string receiver;
      cin>>receiver;
      
      cout<<"The previous hash is: "<< b.addTransaction(amt, sender,receiver);
      cout<<"\n";
      
      userSelection=getUserInput();
    }
    else if(userSelection==2) {
      cout<<"Find Transactions \n";
      cout<<"Input the Sender: ";
      string sender;
      cin>>sender;
      cout<<"\n";
      b.findTransaction(sender);
      
      userSelection=getUserInput();
    }
    else if(userSelection==3) {
      cout<<"Verify and print\n";
      if(b.getHead()==NULL){
        cout<<"Empty Chain\n"; }
      else if(b.verifyAndPrint()) {
        cout<<"The Chain is Verified\n";
      }
      userSelection= getUserInput();
    }
    
    
  }
  
  /*srand(time(NULL));

  blockChain b;
  std::cout<<b.addTransaction(1,"me","her");
  std::cout<<b.addTransaction(2,"brandon","her");
  std::cout<<b.addTransaction(3,"me","tom");
  std::cout<<b.addTransaction(4,"chan","youtube");

  bool c = b.verifyAndPrint();

  std::cout<<"\n";
  //b.findTransaction("chan");
  */
  
  cout<<"Thank You For Using \n";
  return 0;

}
