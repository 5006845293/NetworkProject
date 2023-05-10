#ifndef MeshNetwork_h
#define MeshNetwork_h

#include <string>
#include <iostream>
#include <random>
#include <vector>
#include "Node.h"

#define MAXIMUM 10
class MeshNetwork{

protected:
    //Attributes
          Node Nodes[MAXIMUM];
          int NODES;
          std::vector<std::vector<int>> AdjMatrix;

public:
    //Constructors
          MeshNetwork();
          MeshNetwork(int NODES);

    
    //Getters
          Node& GetNode(int index);
    //Setters

    //Helper Function
          std::vector<Node*> createLinks(int NODES);
          void MakeAdjMatrix();
          void UpdateMatrix();
};
#endif
