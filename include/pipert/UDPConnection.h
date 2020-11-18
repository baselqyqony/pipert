#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h> 
#include<stdlib.h> 
#define PORT 5000
#define MAXLINE 1000

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {


class UDPConnection {


private:
  string Serialize(MeasurementProfileBase profileBase) {
    switch (profileBase.IsOptionalUserProfile) {
      true : return SerializeUserMeasurementProfile(profileBase);
      break;

      false : return SerializeGeneralMeasurementProfile(profileBase);
      break;
    }

    return "";
  }

string SerializeUserMeasurementProfile(MeasurementProfileBase profileBase) {
    MeasurmentProfile profile = (MeasurmentProfile) profileBase;
    //tese serialization
    string serializedMessage = "1,start,";
    serializedMessage.append(profile.add());
    serializedMessage.append("50,");
  serializedMessage.append("end,");

}

string SerializeGeneralMeasurementProfile(
    MeasurementProfileBase profileBase) {
  MeasurmentProfile profile = (MeasurmentProfile)profileBase;
  // tese serialization
  string serializedMessage = "0,start,";
  serializedMessage.append(profile.add());
  serializedMessage.append("50,");
  serializedMessage.append("end,");
}





}

 public:
 


 void send(std::vector<MeasurementProfileBase> measurements) {
    char buffer[100];
    char *message = "";
    int sockfd, n;
    struct sockaddr_in servaddr;

    // clear servaddr
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;

    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
      printf("\n Error : Connect Failed \n");
      exit(0);
    }

    // request to send datagram
    // no need to specify server address in sendto
    // connect stores the peers IP and port

    for (int i = 0; i < measurements.size(); i++) {
    
      message = Serialize(measurements.at(i));
      sendto(sockfd, message, MAXLINE, 0, (struct sockaddr *)NULL,
             sizeof(servaddr));

    }

   

    // close the descriptor
    close(sockfd);  
 }  




  // this class will manage udp connection  

}  // namespace pipert
#endif #pragma once
