# Hard decoder based on Opencv 
Directly decoding from video can save much IO time. 

## Requirement
Opencv3.1 with GPU Support and Contrib installed

## Usage
mkdir build\
cd build\
cmake ..\
make

## Result
Decode 50 frames:\
GPU: 20ms\
CPU: 180ms

