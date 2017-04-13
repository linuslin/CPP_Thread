#include "l_multicast_util.h"

int L_Multicast_Util::connect(const char * group, const int port, struct sockaddr_in &addr, std::string & errorMsg){
    int fd;
    struct ip_mreq mreq;
    u_int modify=1;

    //Create socket
    if ((fd=socket(AF_INET,SOCK_DGRAM,0)) < 0) {
	errorMsg="socket() failed";
        //std::cerr<<"socket() failed"<<std::endl;
        //exit(EXIT_FAILURE);
        return -1;
    }


    // MODIFICATION TO ORIGINAL
    // Allow multiple sockets to use the same port number
    if (setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&modify,sizeof(modify)) < 0) {
        errorMsg="setsockopt() reusing ADDR failed";
        //std::cerr<<"setsockopt() reusing ADDR failed"<<std::endl;
        //exit(EXIT_FAILURE);
        return -1;
    }

    // Setup destination address
    memset(&addr,0,sizeof(addr));
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=htonl(INADDR_ANY); /* N.B.: differs from sender */
    addr.sin_port=htons(port);

    // Bind to receive address
    if (bind(fd,(struct sockaddr *) &addr,sizeof(addr)) < 0) {
        errorMsg="bind() failed";
        //std::cerr<<"bind() failed"<<std::endl;
        //exit(EXIT_FAILURE);
        return -1;
    }

    // Request to join multicast group
    mreq.imr_multiaddr.s_addr=inet_addr(group);
    mreq.imr_interface.s_addr=htonl(INADDR_ANY);
    if (setsockopt(fd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq)) < 0) {
        errorMsg="setsockopt() join multicast group failed";
        //std::cerr<<"setsockopt() join multicast group failed"<<std::endl;
        //exit(EXIT_FAILURE);
        return -1;
    }

    return 0;   
}

ssize_t L_Multicast_Util::receive(int & fd, char * msgbuf,const size_t size,struct sockaddr_in& addr){
    ssize_t nbytes;
    int flags=0;
    socklen_t addrlen=sizeof(addr);
    nbytes=recvfrom(fd,msgbuf,size,flags,(struct sockaddr *) &addr,&addrlen);
    return nbytes;
}
