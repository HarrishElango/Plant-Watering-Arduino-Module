# Plant-Watering-Arduino-Module

## Description
C++ code that allows using an Arduino grove board with external moisture sensor, MOSFET and water pump for a standalone plant watering system that detects soil moisture and waters the soil accordingly.
There is also accompanying code used in development, that allowed for visualization of the moisture value via a graph, as well as auxilary operation functions such as being able to control the system using a slider and a button. 


## Dependencies
For this code to work, you need an Arduino grove board, Arduino IDE, MOSFET, moisture sensor and water pump. 

## Usage Instructions
1. Download code file 
2. Open code file in Arduino IDE
3. Plug Arduino board into computer.
4. Verify and upload code file to Arduino board using corresponding port - Will likely need to be changed in depending on computer. 
5. Place moisture sensor into plant pot of choice
6. Ensure that water pump is placed in an adequate source of water
7. Place hose from water pump into plant of choice
8. Keep board powered for use

## Identifying correct port for system
When plugging in Arduino board, at the bottom right corner of the application, it will state which port the board is connected to. This will need to be changed in the code where you initialize the location of the board to ensure code is uploaded properly to the board. 
