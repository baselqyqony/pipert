#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#define PORT 5000
#define MAXLINE 1000

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {


class MonitoringProfileServer {


private:
  std::thread RecievingJob(recievingJobCallBack);
 std::ofstream outfile;
 public:
  bool enableRecieving;
  uint16_t Timeinterval;
  std::ofstream outfile;


  MonitoringProfileServer() { enableRecieving = true;
    RecievingJob.join();
  }



  void recievingJobCallBack() {
    while (enableRecieving) {

      char buffer[1000];
      int listenfd, len;
      struct sockaddr_in servaddr, cliaddr;
      bzero(&servaddr, sizeof(servaddr));

      // Create a UDP Socket
      listenfd = socket(AF_INET, SOCK_DGRAM, 0);
      servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
      servaddr.sin_port = htons(PORT);
      servaddr.sin_family = AF_INET;

      // bind server address to socket descriptor
      bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

      // receive the datagram
      len = sizeof(cliaddr);
      int n = recvfrom(listenfd, buffer, sizeof(buffer), 0,
                       (struct sockaddr *)&cliaddr,
                       &len);  // receive message from server
      outfile.open("logFile.txt",
                   std::ios_base::app);  

      outfile << buffer; 
      outfile << "\n";
      myfile.close();

      std::this_thread::sleep_for(std::chrono::milliseconds(Timeinterval));
    }
  }
    
  }

 
}


}  // namespace pipert
#endif #pragma once
