//By Ryan Xia
#include <iostream>
#include <fstream>
#include <string>
#include"blockChain.h"

using namespace std;

int main(int argv, char** argc){

  blockChain b;
  std::cout<<b.addTransaction(1,"me","her");
  std::cout<<b.addTransaction(2,"brandon","her");
  std::cout<<b.addTransaction(3,"me","tom");
  std::cout<<b.addTransaction(4,"chan","youtube");

  bool c = b.verifyAndPrint();

  std::cout<<"\n";
  b.findTransaction("chan");


  return 0;

}
