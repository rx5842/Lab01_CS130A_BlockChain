//Ryan Xia
#include "blockChain.h"
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>

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

  return result;
}

blockChain::blockChain(){
  head=NULL;
  size=0;
  holdHash="Null";
}

std::string blockChain::addTransaction(int amt, std::string sender, std::string reciever) {

  std::string result;
  result=holdHash;

  block * temp = new block(amt,sender,reciever);
  temp->setHash(holdHash);
  temp->prev=head;
  head=temp;

  holdHash=temp->toHashString();

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
      std::cout<<current->toPrint();
      current = current->prev;
    }

  return true;
}
