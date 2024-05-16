# Persistence-of-Vision-Globe

This project was completed as a deliverable for an Independent Study Module on Rapid Prototyping and Experimentation (CS-IS-4053-1), focusing on developing a Persistence of Vision (PoV) Display with dimensionality to represent the globe. The first prototype was a simple PoV LED Fan Display which incorporated on an Arduino Nano being placed on soldered mounts onto a zero PCB, connected to a battery, 5 LEDs, 330 ohms resistor, and a switch, all mounted on a Stepper Motor controlled by an Arduino Uno. This works to display simple patterns with circles as a 'first-attempt' prototype. The reference for this was the [Instructables Tutorial] by GreatScottLab. <br>

[Instructables Tutorial]: https://www.instructables.com/How-to-Make-a-Fan-POV-Display/

<p align="center"> 
  <img src="First Prototype/Prototype 1 - Image 1.jpg" width=350>
  <img src="First Prototype/Prototype 1 - Image 3.jpg" width=400> 
</p>

The final build is a circular base with an 8mm rod going through it, mounted onto a DC motor, rotating along with the motor while the addressable RGB LED Strips are controlled by an ESP32. There are 8 magnets attached below the circle, with a hall effect sensor present on the circle to detect the positional angle of the circle while in rotation to modify the pattern. To build this, I have referred to two existing projects, one by Andreas Rottach ([Youtube] and [Github]) and the other by the [GreatScottLab], capitalizing on the strengths of both to modify for further efficiency in my final build. The link to the demo run for the same is here. <br>

[Youtube]: https://www.youtube.com/watch?v=E4yqSw38R_Q
[Github]: https://github.com/rottaca/PovGlobe/tree/master
[GreatScottLab]: https://www.instructables.com/Make-Your-Own-POV-LED-Globe/

### Parts Used:
1. 8mm Aluminium Rod
2. High-Densite RGB Strip Light (Addressable)
3. 8 Neodym Magnets (10mm x 2mm)
4. 12V DC Motor (2000 RPM)
5. Ball Bearing
6. Wood for Base and Stand
7. 3D Prints (Link to CAD and [STL Files]) <br>
  a. 2 x Semi Circles <br>
  b. 1 Rotor Clasp <br>
  c. 1 x Motor Mount <br>
  d. 2 x Power Transmission <br>
  e. 1 x Shaft Coupler (3.2mm to 8mm)
8. LM2596 DC-DC Buck Converter
9. 12V 4500mAh LiPo Battery
10. Hall Effect Sensor

[STL Files]: https://drive.google.com/drive/folders/1sWfZnWFb5knWOkBUvoM1cNdkBBITKUgz?usp=drive_link

### Important Points about the Build:
1. Radius of Circle = 15 cm
2. 64 LEDs on each side

There were several issues encountered along the way due to motor failure and resultantly, the motor was replaced with a NEMA17 Stepper Motor connected to a breadboard circuit with a A4988 Stepper Driver, connected to an Arduino UNO and a power supply. Video for the first demo can be found [here].

[here]: https://www.youtube.com/watch?v=s0MQgqX_jck

<p align="center"> 
  <img src="Final Build/Image 1.jpg" width=350>
  <img src="Final Build/Image 2.jpg" width=200> 
  <img src="Final Build/Image 3.jpg" width=350>
  <img src="Final Build/Image 4.jpg" width=200> 
</p>
