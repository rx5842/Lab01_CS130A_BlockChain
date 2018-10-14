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
  std::string result="";
  
  result += ("amount: " + amount);
  result+="/n";
  result += ("sender: " + sender);
  result+="/n";
  result += ("reciever: " + reciever);
  result+="/n";
  result += ("nonce: " + nonce);
  result+="/n";
  result += ("hash: " + hash);
  result+="/n";
  
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

void blockChain::findTransaction() {
  
}
bool blockChain::verifyAndPrint() {

  return true;
}
