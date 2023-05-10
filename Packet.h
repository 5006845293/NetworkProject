#ifndef Packet_h
#define Packet_h

#include <string>
#include <iostream>

#include "Counter.h"

class Packet{

protected:
    //Attributes
          int ID;
          int SOURCE;
          int DESTINATION;
          std::string PATH;
          int TOB;

public:
    //Constructors
          Packet();
          Packet(int ID, int DESTINATION);

    
    //Getters
          int GetId();
          int GetSource();
          int GetDestination();
          std::string GetPath();
          int GetAge();

    //Setters
          void SetId(int ID);
          void SetSource(int SOURCE);
          void SetDestination(int DESTINAITON);
          void SetPath(std::string PATH);
};
#endif
