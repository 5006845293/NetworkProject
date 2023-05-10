#include "MeshNetwork.h"

MeshNetwork::MeshNetwork(){}

MeshNetwork::MeshNetwork(int NODES): NODES(NODES){


}

    Node& MeshNetwork::GetNode(int index) {
        return Nodes[index];
    }



 std::vector<Node*> MeshNetwork::createLinks(int NODES){
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int> dis(1,NODES);

      int randomNumber1 = dis(gen);
      int randomNumber2 = dis(gen);

      while(randomNumber1 == randomNumber2){
          randomNumber2 = dis(gen);
      }

      int randomNumber3 = dis(gen);

      while(randomNumber1 == randomNumber3 || randomNumber3 == randomNumber2){
          randomNumber3 = dis(gen);
      }
      std::vector<Node*> nums(3);
      nums[0] = &Nodes[randomNumber1-1];
      nums[1] = &Nodes[randomNumber2-1];
      nums[2] = &Nodes[randomNumber3-1];
      return nums;
}

void MeshNetwork::MakeAdjMatrix(){
  AdjMatrix.resize(NODES, std::vector<int>(NODES));

  std::cout<<"Network created"<<NODES<<std::endl; 
  for(int i =0;i<NODES; i++){
          for(int j=0; j<NODES;j++){
                        AdjMatrix[i][j] = 0;
          }
          std::cout<<std::endl;
  }
  int i,j;
  for(i=0;i<NODES;i++){
      Node node(i,NODES);
      Nodes[i] = node;
  }
  for(j =0;j<NODES;j++){
      Nodes[j].SetLinks(createLinks(NODES));
  }

  for(i = 0;i<NODES;i++){
      AdjMatrix[i][Nodes[i].GetLink1()->GetId()] = Nodes[i].GetLinkLength1();
      AdjMatrix[i][Nodes[i].GetLink2()->GetId()] = Nodes[i].GetLinkLength2();
      AdjMatrix[i][Nodes[i].GetLink3()->GetId()] = Nodes[i].GetLinkLength3();
  }
  
  std::cout<<"PRINT TABLE"<<std::endl;
  for(i =0;i<NODES; i++){
          for(j=0; j<NODES;j++){
                  std::cout<<AdjMatrix[i][j]<< " ";
      
          }
          std::cout<<std::endl;
  }
  std::cout<<"END TABLE"<<std::endl;
}


void MeshNetwork::UpdateMatrix(){

        for(int i=0;i<NODES;i++){
              if(Nodes[i].GetStatus() == 0){
                      for(int j=0;j<NODES;j++){
                              AdjMatrix[i][j] = 0;
                      }
              }
        }


}


