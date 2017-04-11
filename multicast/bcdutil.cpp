#include "bcdutil.h"
#include <cmath>
int BcdUtil::bcdDecoder(char * src, int len)
{
    return (int)(bcdDecode2ll(src,len));
}

std::string BcdUtil::bcdDecode2Str(char * src, int len)
{
    return std::to_string(bcdDecode2ll(src,len));
}

long long BcdUtil::bcdDecode2ll(char * src, int len){
    long long result=0;
    for (int i=0 ; i<len ; i++){
        result+=(((int)*(src+i)>>4)*10+((int)(*(src+i))&15))*pow(100,len-i-1);
    }
    return result;
}


