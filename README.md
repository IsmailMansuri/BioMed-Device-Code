# Ambulance Alert
This device allows ambulances or other emergency vehicles to communicate with traffic ahead of them, allowing the traffic more time to exit the emergency vehicle's path, awarding quicker arrival times for the emergency vehicle.

This device is almost like a radar dector for police cars. Our device is aimed for automakers to put these in vehicles.

# Motivation
Our group noticed that tracking technologies used by ambulances dated back to the 1980's, and we wanted to improve upon that and somehow allow ambulances an easier journey to get to their patients and to the hospital.

# Build Status
Working Prototype

# Code Style
Code Style: Standard

# Code Example

    if (Mirf.dataReady()){                               
        Mirf.getData(&value);
        Serial.print("Got data: ");
        Serial.println(value);
        if (value == 255){
          display(); 
        }
    }
    else{
        clearLCD();
    }
  
# Built With
   - Arduino
   - Arduino C
   - Keywish RF-Nano
   - I2C Serial Display Module

# Features
Our project features two radios: one transmitting (for the emergency vehicle) and one receiving the message (for the other vehicles on the road). The message is a simple delcaration of the incoming emergency vehicle, flashing on and off the screen to attract the drivers' attention. Our device is small and light and uses a very small amount of power (7-12 volts).
