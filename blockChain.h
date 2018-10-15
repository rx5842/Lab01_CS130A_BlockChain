//Ryan  Xia

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include<string>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

class block{
public:
  block(int amt, std::string sender, std::string reciever);
  block * prev;
  void setHash(std::string newHash);
  std::string getHash() {return hash;};
  std::string getSender() {return sender;};
  std::string getReceiver() {return reciever;};
  std::string getNonce() {return nonce;};
  std::string getAmount() {return std::to_string(amount);};
  std::string toHashString();
  std::string toPrint();
  void generateSetNonce();

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
  std::string addTransaction(int amt, std::string sender, std::string reciever);
  void findTransaction(std::string senderName);
  bool verifyAndPrint();
  block* getHead() {return head;};
private:
  int size;
  block* head;
  std::string holdHash;
};


#endif
