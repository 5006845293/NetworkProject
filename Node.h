#ifndef Node_h
#define Node_h

#define SIZE 10
#define MAXLINK 15

#include "Packet.h"
#include "Counter.h"
#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <climits>
class Node{

protected:
    //Attributes
          int ID;
          int LIFETIME;
          int NEWPACKETDELAY;
          int PROCESSINGDELAY;
          int ACKNOWLEDGEDELAY;
          std::queue<Packet> QUEUE;
          std::queue<Packet> AckQueue;
          int STATUS;
          Node* Link1;
          Node* Link2;
          Node* Link3;
          int LinkLength1;
          int LinkLength2;
          int LinkLength3;
          int NodeNum;
          int (*Adjmatrix)[1000];
          

public:
    //Constructors
          Node();
          Node(int ID, int NodeNum, int (*arr)[1000]);

    
    //Getters
          int GetId();
          int GetLifetime();
          int GetNewPacketDelay();
          int GetProcessingDelay();
          int GetAcknowledgeDelay();
          int GetStatus();
          Node* GetLink1();
          Node* GetLink2();
          Node* GetLink3();
          int GetLinkLength1();
          int GetLinkLength2();
          int GetLinkLength3();

    //Setters
          void SetId(int ID);
          void SetLifetime(int LIFETIME);
          void SetNewPacketDelay(int NEWPACKETDELAY);
          void SetProcessingDelay(int PROCESSINGDELAY);
          void SetAcknowledgeDelay(int ACKNOWLEDGEDELAY);
          void SetStatus(int STATUS);
          void SetLinkLengths();
          void SetLinks(std::vector<Node*> links);
          void SetDelays();
          
    //Helper Functions
          void ProcessPacket(Packet p);
          void AddPacket(int id);
          void CalculateShortest(Packet p);
          void SendACK();
          void CheckNode();
          bool CheckQueue(std::queue<Packet> myQueue);
};
#endif
