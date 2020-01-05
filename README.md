# ArduinoLightSystem

**I used an Arduino Uno Rev3 to build a light system that, using servos, flips a light switch on or off everytime someone trips the motion detectors.**

An additional feature of the motion detection system was that because it used modulated Infrared rays, the motion sensors could be trigerred through a TV remote and some RC car controllers. Meaning that if you angle the motion sensors just right, you could turn lights on and off from your living room. 

Material used: Arduino Uno Rev3 microcontroller, IRED, IR Detector, 2 servos, LED, 12 jumper wires, 3 x 3 cardboard cutout.

Builiding Detail: There are really two major components to building this: the motion detection and the servo set up. 

1. Motion detection: I segmented my shield into two parts using a cardboard cutout. This was required because I wanted the left part of my shield to emitt Infrared light and the right half to detect it. However, without the cardboard segement the IRED continously emitts rays and the IR Detector continuously detects rays. Using the segment solves this problem as the ray will now be focused upward and the detector would not needlessly detect rays unless it bounces off an object and back toward the Arduino shield- which is exactly the kind of detection we want. 

2. Servo setup: I found it best to attach the arduino shield with it's IRED and IR Detection sensor perpendicular to the wall, only a few inches away from the light switch; with one servo above and one servo below the light switch. Feel free to connect servos to the light switch as you see fit, I used rubber bands because they were readily available and reasonably stable. 