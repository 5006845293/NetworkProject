#include "Node.h"
#include "MeshNetwork.h"

//Constructors
          Node::Node(){}
          
          Node::Node(int ID, int NodeNum): ID(ID), NodeNum(NodeNum){
                std::cout<<"New Node Created: "<<ID<<std::endl;
                STATUS = 1;
                SetLinkLengths();
                SetDelays();
          }

    
//Getters
          int Node::GetId(){return ID;}
          int Node::GetLifetime(){return LIFETIME;}
          int Node::GetNewPacketDelay(){return NEWPACKETDELAY;}
          int Node::GetProcessingDelay(){return PROCESSINGDELAY;}
          int Node::GetAcknowledgeDelay(){return ACKNOWLEDGEDELAY;}
          int Node::GetStatus(){return STATUS;}
          Node* Node::GetLink1(){return Link1;}
          Node* Node::GetLink2(){return Link2;}
          Node* Node::GetLink3(){return Link3;}
          int Node::GetLinkLength1(){return LinkLength1;}
          int Node::GetLinkLength2(){return LinkLength2;}
          int Node::GetLinkLength3(){return LinkLength3;}

//Setters
          void Node::SetId(int ID){this->ID = ID;}
          void Node::SetLifetime(int LIFETIME){this->LIFETIME = LIFETIME;}
          void Node::SetNewPacketDelay(int NEWPACKETDELAY){this->NEWPACKETDELAY = NEWPACKETDELAY;}
          void Node::SetProcessingDelay(int PROCESSINGDELAY){this->PROCESSINGDELAY = PROCESSINGDELAY;}
          void Node::SetAcknowledgeDelay(int ACKNOWLEDGEDELAY){this->ACKNOWLEDGEDELAY = ACKNOWLEDGEDELAY;}
          void Node::SetStatus(int STATUS){this->STATUS = STATUS;}
          void Node::SetLinkLengths(){
                std::random_device RD;
                std::mt19937 gen(RD());
                std::uniform_int_distribution<int> Dis(1,MAXLINK);
                
                LinkLength1 = Dis(gen);
                LinkLength2 = Dis(gen);
                LinkLength3 = Dis(gen);
          }
          void Node::SetLinks(std::vector<Node*> links){
                Link1 = links[0];
                Link2 = links[1];
                Link3 = links[2];
          }
          void Node::SetDelays(){
                std::random_device Rd;
                std::mt19937 gen(Rd());
                std::uniform_int_distribution<int> DIS(1,SIZE);

                NEWPACKETDELAY = DIS(gen);
                PROCESSINGDELAY = DIS(gen);
                ACKNOWLEDGEDELAY = NodeNum*2;
                LIFETIME = DIS(gen);
                
          }

          
//Helper Functions
          void Node::ProcessPacket(Packet p){
                  if(p.GetDestination()== ID){
                        //processing delay  
                        //send ack     
                  }
                  else if(p.GetPath() ==""){
                        CalculateShortest(p);
                  }
                  else{
                        //send to node of last header digit
                  }

          }
          void Node::AddPacket(int id){
                  std::random_device rd;
                  std::mt19937 gen(rd());
                  std::uniform_int_distribution<int> dis(1,NodeNum);
                  int dest = dis(gen);

                  Packet packet(id,dest);
                  packets++;
                  if(QUEUE.size() < SIZE){
                          QUEUE.push(packet);
                  }
                  else{
                          AckQueue.push(packet);
                  }
                    
          }
          void Node::CalculateShortest(Packet p){
              int n = NodeNum; // Number of nodes
              std::vector<int> dist(n, INT_MAX); // Initialize all distances to infinity
              std::vector<int> prev(n, -1); // Initialize all previous nodes to -1
              dist[ID] = 0; // Set the distance of the starting node to 0

              std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; // Priority queue to store nodes with their distances
              pq.push(std::make_pair(0, ID)); // Add the starting node to the queue

              while (!pq.empty()) {
                  int u = pq.top().second; // Get the node with the smallest distance
                  pq.pop();

                  /*for (int v = 0; v < n; v++) { // Iterate over all neighbors of u
                      if (AdjMatrix[u][v] != 0) { // If there is an edge from u to v
                          int alt = dist[u] + AdjMatrix[u][v]; // Calculate the new distance to v
                          if (alt < dist[v]) { // If the new distance is smaller than the current distance to v
                              dist[v] = alt; // Update the distance to v
                              prev[v] = u; // Set the previous node of v to u
                              pq.push(std::make_pair(dist[v], v)); // Add v to the queue with its new distance
                          }
                      }
                  }*/
              }

              // Construct the path string by iterating from the end node to the start node
              std::string path = std::to_string(p.GetDestination());
              int node = p.GetDestination();
              while (prev[node] != -1) {
                  path = std::to_string(prev[node]) + path;
                  node = prev[node];
              }

              p.SetPath(path);
          }
          void Node::SendACK(){}
          void Node::CheckNode(){
                if(count == LIFETIME){
                          STATUS = 0;
                }
                if(count%NEWPACKETDELAY == 0){
                          AddPacket(packets+1);
                }
                if(QUEUE.front().GetAge() == ACKNOWLEDGEDELAY){
                          Packet p = QUEUE.front();
                          QUEUE.pop();
                          if(QUEUE.size()< SIZE){
                                QUEUE.push(p);
                          }
                          else{
                                AckQueue.push(p);
                          }
                }
                if(!QUEUE.empty()){
                          ProcessPacket(QUEUE.front());

                }
                

          }
        
          bool Node::CheckQueue(std::queue<Packet> myQueue){
                    std::queue<Packet> tempQueue = myQueue;
                    while (!tempQueue.empty()) {
                          Packet element = tempQueue.front();
                          if (element.GetAge() == ACKNOWLEDGEDELAY) {
                              return true;
                              break;
                          }
                          tempQueue.pop();
                    }
                    return false;
        }

