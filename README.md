# GPS_track
GPS tracking and location database
This is a demo project for GPS data collection and management system.

It is implemented on two platforms - 1.Raspberry Pi
                                     2. Node MCU with TinyGPS++ library
                                    
                                    
                                    
The program ipfind2.py in Raspberry Pi fetches location data based on the IP address and pushes the locatio co-ordinates to a mySQL database setup on a different
device on the network.


The node_v1.0.ino is an arduino sketch to runon a esp8266 enabled system like Nodemcu.
It serially connects to a GPS module and data thus received is parsed and sent to a local server using "http" protocols.
(Due to unavailability of GPS module the program transmits dummy value at the moment).
