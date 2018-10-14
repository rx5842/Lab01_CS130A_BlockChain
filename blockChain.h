//Ryan  Xia

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

class block{
public:
  block(int amt, std::string sender, std::string reciever);
  block * prev;
private:
  int amount;
  std::string sender;
  std::string reciever;
  std::string nonce;
  std::string hash;
};

class blockChain{
public:
  blockChain();
  void addTransaction(int amt, std::string sender, std::string reciever);
  void findTransaction();
  bool verifyAndPrint();
private:
  int size;
  block* head;
};


#endif
