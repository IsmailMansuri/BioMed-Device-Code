
// Biomed Device Server Side Code 
// by: Ismail Mansuri
// Made for Arduino Micro


#include Arduino.h
#include <SPI.h>
#include <RH_NRF24.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

// Radio driver
RH_NRF24 nrf24;

void setup() 
{
  lcd.begin(16, 2);

  Serial.begin(9600);
  while (!Serial) 
    ; // wait for serial port to connect. Needed for Leonardo only
  if (!nrf24.init())
    Serial.println("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    Serial.println("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");    
}

void loop()
{
  if (nrf24.available())
  {
    // Should be a message if the connection is active 
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (nrf24.recv(buf, &len))
    {
      Serial.print("got request: "); //Print the request from the client
      Serial.println((char*)buf);
      lcd.print((char*)buf);
      
      // Send a reply
      uint8_t data[] = "Recieved by server";
      nrf24.send(data, sizeof(data));
      nrf24.waitPacketSent();
      Serial.println("Sent a reply");
    }
    else
    {
      Serial.println("recv failed");
    }
  }
}