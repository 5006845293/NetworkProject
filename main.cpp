#include <iostream>
#include "Node.h"
#include "Packet.h"
#include "MeshNetwork.h"
#include "Counter.h"

#define MAXIMUM 10
int main(){

        DisplayMenu();
        return 0;
}

void DisplayMenu(){
        int Nodes,Iterations,duration, i;
        
	std::cout<<"\nWelcome to Jasmine's Network Simulation!\n"<<std::endl;
        std::cout<<"How many Nodes would you like in your network?"<<std::endl;

        std::cin >> Nodes;
        while(Nodes<3 || Nodes>MAXIMUM){             
                std::cout<<"The amount of Nodes you entered is invalid.\nPlease enter a number between 2 and "<<MAXIMUM<<std::endl;
                std::cin >> Nodes;
        }

        std::cout<<"\nHow many Trials would you like to do?"<<std::endl;
        std::cin >> Iterations;
        std::cout<<"\nHow long would you like to run the test for in iterations?\n Please enter at least 20."<<std::endl;
        std::cin >> duration;
        for(int i=0;i<Iterations;i++){
                MeshNetwork Network(Nodes);
                Network.MakeAdjMatrix();
                count = 0;
                while(count<duration){
                      for(i = 0;i<Nodes;i++){
                            Network.GetNode(i).CheckNode();
                      }
                      NetWork.UpdateMatrix();
                      increment();
                }
        }
        std::cout<<"\nFinished"<<std::endl;


}
