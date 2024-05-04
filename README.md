# Persistence-of-Vision-Globe

This project was completed as a deliverable for an Independent Study Module on Rapid Prototyping and Experimentation (CS-IS-4053-1), focusing on developing a Persistence of Vision (PoV) Display with dimensionality to represent the globe. The first prototype was a simple PoV LED Fan Display which incorporated on an Arduino Nano being placed on soldered mounts onto a zero PCB, connected to a battery, 5 LEDs, 330 ohms resistor, and a switch, all mounted on a Stepper Motor controlled by an Arduino Uno. This works to display simple patterns with circles as a 'first-attempt' prototype.

[Images of Prototype 1]

The final build is a circular base with an 8mm rod going through it, mounted onto a DC motor, rotating along with the motor while the addressable RGB LED Strips are controlled by an ESP32. There are 8 magnets attached below the circle, with a hall effect sensor present on the circle to detect the positional angle of the circle while in rotation to modify the pattern. The link to the demo run for the same is here.

Parts Used:
1. 8mm Aluminium Rod
2. High-Densite RGB Strip Light (Addressable)
3. 8 Neodym Magnets (10mm x 2mm)
4. 12V DC Motor (2000 RPM)
5. Ball Bearing
6. Wood for Base and Stand
7. 3D Prints (Link to CAD and STL Files)
  a. 2 x Semi Circles
  b. 1 Rotor Clasp
  c. 1 x Motor Mount
  d. 2 x Power Transmission
  e. 1 x Shaft Coupler (3.2mm to 8mm)
8. LM2596 DC-DC Buck Converter
9. 12V 4500mAh LiPo Battery
10. Hall Effect Sensor

Important Points about the Build:
1. Radius of Circle = 15 cm
2. 64 LEDs on each side

[Images of Final Build]
