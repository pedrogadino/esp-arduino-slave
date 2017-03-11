# ESP8266- NodeMCU - Slave

Receiveis commands from a Master Board or via requests by endpoints

Master board repository: https://github.com/pedrogadino/esp-arduino-central

This code can control D7 digital pin of the board with HIGH and LOW commands (tipically used for home automation)

# Slave endpoints

This endpoints can be called:
   - GET | http://{MASTER_IP_ON_NETWORK}/cmd?status={STATUS_1_OR_0} 
      - Send a command execute request for the board (1 or 0 = ON or OFF)
