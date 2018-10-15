//Ryan Xia
#include "blockChain.h"
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include<cstring>

block::block(int amt, std::string sender, std::string reciever) {
  this->amount = amt;
  this->sender=sender;
  this->reciever=reciever;
  this->nonce="";
  this->hash="";
}

void block::setHash(std::string newHash){
  this->hash=newHash;
}
std::string block::toHashString(){
  std::string result;
  result=(getAmount()+sender+reciever+nonce);
  return result;
}

std::string block::toPrint() {
  std::string result;

  result += ("Block Info");
  result+="\n";

  result += ("amount: " + getAmount());
  result+="\n";
  result += ("sender: " + sender);
  result+="\n";
  result += ("reciever: " + reciever);
  result+="\n";
  result += ("nonce: " + nonce);
  result+="\n";
  result += ("hash: " + hash);
  result+="\n";
  result+="\n";

  return result;
}

void block::generateSetNonce() {
  //std::srand(time(0));
  char c = (char(rand()%26+97));
  std::string s(1,c);
  this->nonce=s;
}

blockChain::blockChain(){
  head=NULL;
  size=0;
  holdHash="Null";
}

std::string sha256Hash(std::string input){
  
   unsigned char digest[SHA256_DIGEST_LENGTH];
    char string[input.size()+1];
    std::strcpy(string , input.c_str());
    SHA256((unsigned char*)&string, strlen(string), (unsigned char*)&digest);    
    char mdString[SHA256_DIGEST_LENGTH*2+1];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {	
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }
    return mdString;
}

std::string blockChain::addTransaction(int amt, std::string sender, std::string reciever) {

  std::string result;
  result=holdHash;

// generating the new block
  block * temp = new block(amt,sender,reciever);
  temp->setHash(holdHash);
  temp->prev=head;
  


  //creates the thenexthash and stores it
  std::string tHash;
  bool goodDigit=false;
  while(!goodDigit) {
    temp->generateSetNonce();
    tHash= sha256Hash(temp->toHashString());
    if(tHash[tHash.size()-1]>='0'&&tHash[tHash.size()-1]<='4') {
      goodDigit=true;
    }
  }
  temp->setHash(holdHash);
  holdHash=tHash;

  head=temp;
 
  return result+"\n";
}

void blockChain::findTransaction(std::string senderName) {
  block* current = head;
  while(current != NULL) {
    if(current->getSender() == senderName) {
        std::cout<<current->toPrint();
    }
    current=current->prev;
  }


}
bool blockChain::verifyAndPrint() {
    block* current = head;
    while(current!=NULL)
    {
      std::string tHash=current->getHash();
      if(current->prev!=NULL) {
        if(tHash!= sha256Hash(current->prev->toHashString())) {
          std::cout<<"\n"<<"There is a mismatched hash"<<"\n";
          std::cout<<"The stored hash: "<<tHash<<"\n";
          std::cout<<"The calculated hash: "<<sha256Hash(current->prev->toHashString())<<"\n\n";
          return false;
        }
      }
      std::cout<<current->toPrint();
      current = current->prev;
    }

  return true;
}
