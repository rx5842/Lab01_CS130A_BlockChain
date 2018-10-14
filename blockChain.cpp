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

blockChain::blockChain(){
  head=NULL;
  size=0;
}

void blockChain::addTransaction(int amt, std::string sender, std::string reciever) {
  block * temp = new block(amt,sender,reciever);
  //temp->nonce="a";
  temp->prev=head;
  head=temp;
}

void blockChain::findTransaction() {
  
}
bool blockChain::verifyAndPrint() {
  return true;
}
