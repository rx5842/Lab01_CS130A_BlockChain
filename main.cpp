
#include <iostream>
#include <fstream>
#include <string>
#include"blockChain.h"

using namespace std;

int main(int argv, char** argc){

  blockChain b;
  b.addTransaction(1,"me","her");
  b.addTransaction(2,"brandon","her");
  b.addTransaction(3,"me","tom");
  b.addTransaction(4,"chan","youtube");

  bool c = b.verifyAndPrint();

  std::cout<<"\n";
  b.findTransaction("chan");


  return 0;

}
