#ifndef ROBOT_CONNECTION_HPP_
#define ROBOT_CONNECTION_HPP_

#include <iostream>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <array>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <chrono>
#include <vector>
#include <stdint.h>
#include <functional>
#include <cmath>
#include <sstream>

#include "DataFormat.hpp"
#include "helpers.hpp"

class RobotConnection;

struct RobotConnectionArgs {
  RobotConnection * robot;
  std::string ipAddress;
  uint8_t port;
} connectionConfig;

Communication::PcToRobot_t sendToGripper;
Communication::RobotToPc_t recivedFromGripper;

pthread_t threadId_;

class RobotConnection {
private:
  uint8_t messageNumber_ = 0;
  int socketConnection_;

  uint64_t sendTime = 0;
  int bytesSent = 0;
  uint64_t recivedFromGripperTime_;


  bool newMessageRevceived_ = false;
 

public:
  bool cmd_gripper;   // Befehl an Greifer: 0- Greifer öffnen, 1- Greifer schließen



  // Function to read the data recivedFromGripper from the robot.
  bool readData() {
    //std::cout << "readData()" << std::endl;
    //std::cout << "bytesSent = " << bytesSent << std::endl;
    if (bytesSent == 0) return true;  // Return if no recivedFromGripper is expected

    // Read data from the socket
    int bytesReceived = recv(socketConnection_, &recivedFromGripper, sizeof(recivedFromGripper), 0);
    //std::cout << "bytesReceived = " << bytesReceived << std::endl;

    if (bytesReceived == -1) {
        std::cerr << "Fehler beim Empfangen von Daten vom Roboter." << std::endl;
        return false;
    } else if (bytesReceived == 0) {
        std::cerr << "Die Verbindung wurde geschlossen." << std::endl;
        return false;
    }

    recivedFromGripperTime_ = MyUtils::micros() - sendTime;   // Calculate the communication delay

    // Output gripper state
    std::cout << "Antwort Roboter: Gripper State = " << (recivedFromGripper.gripperState ? "Closed" : "Open") << std::endl;

    return true;
}

bool sendData() {
    sendToGripper.messageNumber++;

    // Setze den Greiferzustand im Anfragepaket
    sendToGripper.setGripper = cmd_gripper;

    // Start the communication delay measurement and send the data to the robot:
    sendTime = MyUtils::micros();
    bytesSent = send(socketConnection_, &sendToGripper, sizeof(sendToGripper), 0);


    // Raise an error if no bytes have been sent:
    if (bytesSent == -1) {
        std::cerr << "Error sending Message";
        return false;
    }

    return true;
}


  // Connect to the robot hardware on the given IP Address. 
  bool initialize(std::string ipAddress, std::string ssid, std::string & errorMessage) {
    // If required, check if the hotspot connection is active:
    if (ssid != "" && MyUtils::hotspotIsActive(ssid, errorMessage) == false) return false;

    // Check if the robot can be pinged:
    if (MyUtils::checkConnection(ipAddress, errorMessage) == false) return false;

    // Create a socket handle:
    socketConnection_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socketConnection_ == -1) { std::cerr << "Error creating socket" << std::endl; return false; }   

    // Setup the network connection parameters:
    struct sockaddr_in receiverAddr;
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(80);
    receiverAddr.sin_addr.s_addr = inet_addr(ipAddress.c_str());
    
    sendToGripper.messageNumber = 0;

    // Try to connect to the robot:
    if (connect(socketConnection_, (struct sockaddr*) &receiverAddr, sizeof(receiverAddr)) == -1) {
      std::cerr << "Error connecting to the Robot" << std::endl;
      return false;
    }
    return true;
  };
};

#endif