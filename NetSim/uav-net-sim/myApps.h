#ifndef MYAPPS_H_
#define MYAPPS_H_
#include <stdio.h>
#include <stdlib.h>
#include "ns3/applications-module.h"

extern pthread_mutex_t tNext_mutex;
extern pthread_mutex_t mob_mutex;
extern long last_schedule_time;
extern int cong_new_rate;

using namespace ns3;

class MyApp : public Application
{
public:

  MyApp ();
  virtual ~MyApp();

  // Init from the ns3 code
  void Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate, uint32_t appId, uint32_t appType);
  // !!! Not use this function. Not found.
  void ChangeRate(DataRate newrate);
  // The `SendMsg` function is responsible for sending a message over a socket.
  void SendMsg (Ptr<Socket>, char *);
  // Print the Parameters of the network
  void PrintParameters ();
  // The `StartApplication` function is responsible for starting the application. It sets the `m_running` flag to true, initializes the `m_packetsSent` counter to 0, binds the socket, connects to the peer address, and stores the current simulation time in `m_elapse`. Additionally, it prints the socket and peer address information for debugging purposes.
  virtual void StartApplication (void);
  // The `StopApplication` function is used to stop the application from sending any more packets.
  virtual void StopApplication (void);
  // The `SendPacket` function is responsible for sending a packet over a socket.
  void SendPacket (void);
  // The `ScheduleTx` function is responsible for scheduling the next packet transmission.
  void ScheduleTx (void);

  Ptr<Socket>     m_socket;
  Address         m_peer;
  int             m_rate;
  double          m_elapse;
  int             m_congId;

private:

  uint32_t        m_packetSize;
  uint32_t        m_nPackets;
  DataRate        m_dataRate;
  EventId         m_sendEvent;
  bool            m_running;
  uint32_t        m_packetsSent;
  uint32_t        m_appId;   //Odd: LTE App , Even: Wifi App
  uint32_t        m_appType;   //Command: 0 , Telemetry: 1
};

#endif
