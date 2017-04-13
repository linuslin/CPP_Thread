#include "bmpheader.h"
#include "bcdutil.h"
#include <iostream>

BMPHeader::BMPHeader(char * src){
    this->setHeader(src);
}

void BMPHeader::setHeader(char * src){
    this->msgLen = BcdUtil::BcdUtil::bcdDecoder((src+MSG_LEN),msgLen_len);
    this->bizType = BcdUtil::BcdUtil::bcdDecoder((src+BIZ_TYPE),bizType_len);
    this->fmtNo = BcdUtil::BcdUtil::bcdDecoder((src+FMT_NO),fmtNo_len);
    this->fmtVer = BcdUtil::BcdUtil::bcdDecoder((src+FMT_VER),fmtVer_len);
    this->seqNum = BcdUtil::BcdUtil::bcdDecoder((src+SEQ_NUM),seqNum_len);
}

void BMPHeader::dump()
{
   std::clog<<"{msgLen="<<this->msgLen
	<<" bizType="<<this->bizType
	<<" fmtNo="<<this->fmtNo
        <<" fmtVer="<<this->fmtVer
        <<" seqNum="<<this->seqNum<<std::endl;
}
