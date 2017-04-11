
#ifndef __BCD_UTIL_H_
#define __BCD_UTIL_H_

#include <string>

struct BcdUtil{
    static int bcdDecoder(char * src, int len);
    static std::string bcdDecode2Str(char * src, int len);
    static long long bcdDecode2ll(char * src, int len);
};

#endif
