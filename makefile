all: Network

Network: main.cpp Node.o Packet.o MeshNetwork.o Counter.o
	g++ -o Network main.cpp Node.cpp Packet.cpp MeshNetwork.cpp Counter.cpp

directory.o: Node.cpp Node.h
	g++ -c Node.cpp

Packet.o: Packet.cpp Packet.h
	g++ -c Packet.cpp

MeshNetwork.o: MeshNetwork.cpp MeshNetwork.h
	g++ -c MeshNetwork.cpp

Counter.o: Counter.cpp Counter.h
	g++ -c Counter.cpp

clean:
	rm *.o Network
