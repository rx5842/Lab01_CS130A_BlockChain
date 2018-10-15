//Ryan Xia
#include "blockChain.h"
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>

block::block(int amt, std::string sender, std::string reciever) {
  this->amount = amt;
  this->sender=sender;
  this->reciever=reciever;
  this->nonce="a";
  this->hash="";
}

void block::setHash(std::string newHash){
  this->hash=newHash;
}

std::string block::toString() {
  std::string result;

  result += ("Block Info");
  result+="\n";

  result += ("amount: " + std::to_string(amount));
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
  holdHash="";
}

void blockChain::addTransaction(int amt, std::string sender, std::string reciever) {
  block * temp = new block(amt,sender,reciever);
  temp->setHash(holdHash);
  temp->prev=head;
  head=temp;
}

void blockChain::findTransaction(std::string senderName) {
  block* current = head;
  while(current != NULL) {
    if(current->getSender() == senderName) {
        std::cout<<current->toString();
    }
    current=current->prev;
  }


}
bool blockChain::verifyAndPrint() {
    block* current = head;
    while(current!=NULL)
    {
      std::cout<<current->toString();
      current = current->prev;
    }

  return true;
}
