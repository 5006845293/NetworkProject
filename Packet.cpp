#include "Packet.h"

//Constructors
          Packet::Packet(){}

          Packet::Packet(int ID,int DESTINATION) : ID(ID), DESTINATION(DESTINATION){
                std::cout<<"New Packet Created: "<<ID<<std::endl;
                TOB = count;
          }
    
//Getters
          int Packet::GetId(){return ID;}
          int Packet::GetSource(){return  SOURCE;}
          int Packet::GetDestination(){return DESTINATION;}
          std::string Packet::GetPath(){return PATH;}
          int Packet::GetAge(){return count - TOB;}

//Setters
          void Packet::SetId(int ID){this->ID = ID;}
          void Packet::SetSource(int SOURCE){this->SOURCE = SOURCE;}
          void Packet::SetDestination(int DESTINAITON){this->DESTINATION = DESTINATION;}
          void Packet::SetPath(std::string PATH){this->PATH = PATH;}
