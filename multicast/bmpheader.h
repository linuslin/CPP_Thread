
#ifndef __BMP_HEADER_H_
#define __BMP_HEADER_H_

struct BMPHeader
{
    int msgLen; 	//2 Byte BCDPACK
    int bizType;	//1 Byte BCDPACK
    int fmtNo;  	//1 Byte BCDPACK  
    int fmtVer; 	//1 Byte BCDPACK
    int seqNum; 	//4 Byte BCDPACK

    const static int msgLen_len=2;
    const static int bizType_len=1;
    const static int fmtNo_len=1;
    const static int fmtVer_len=1;
    const static int seqNum_len=4;

    enum INDEX{ MSG_LEN=0, BIZ_TYPE=2, FMT_NO=3, FMT_VER=4, SEQ_NUM=5};
    BMPHeader(char * src);
    void setHeader(char * src);
    void dump();
    
};

#endif
