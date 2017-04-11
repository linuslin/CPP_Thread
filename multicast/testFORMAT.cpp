#include<iostream>
#include<fstream>
#include<cmath>
#include "bmpheader.h"


long bcdDecoder(char * src, int len)
{
    long result=0;
    for (int i=0 ; i<len ; i++){
        result+=(((int)*(src+i)>>4)*10+((int)(*(src+i))&15))*pow(100,len-i-1);
    }
    return result;
}

int main(){

  std::ifstream is("format3.dat");     // open file

  char c;
  char tmpBuf[10];
  char buffer[256];
  std::string::size_type sz;
  int count=0;
  while (is.get(c)){          // loop getting single characters
    std::cout << c;
    if(c==27){
       is.get(tmpBuf,10);
       BMPHeader header(tmpBuf);
       header.dump();
    }
    
    if(c==0x0d && is.peek() == 0x0a){
       exit(1);
    }
  }
  is.close();                // close file

  return 0;
}
