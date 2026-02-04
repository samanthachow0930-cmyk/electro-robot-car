# electro-robot-car

## Project Overview
* The objective was to develop a robot car that could autonomously track a white line on a dark mat, execute precise turns, navigate a loop section, and respond to a bumper sensor trigger—all within a constrained timeframe. This project demonstrated the integration of embedded systems, sensor-based control, and hardware-software co-design.

## System Architecture
### Hardware Components
* Microcontroller: Arduino Nano
* Sensors: Infrared (IR) sensors for line tracking and a bumper sensor for initiation and obstacle detection
* Motor Control: L293D H-Bridge motor driver
* Power Management: LM7805 voltage regulator for stable 5V supply
* Signal Conditioning: 74HC14 inverter for sensor signal processing
* Actuators: Two DC gear motors for differential drive

### Software Implementation
* Language: Arduino (C++)
* Core Logic: Combinational and sequential digital logic implemented in firmware

### Key Features
* State-based navigation using a counter system (count00)
* Custom go_straight() function for fine-tuned path correction
* Dynamic PWM control for motor speed and directional adjustment

### Development Process
(The project followed an iterative engineering design process)
* Circuit Assembly: Built and tested the full electro-robotic system on a breadboard.
* Sensor Integration: Calibrated IR sensors for reliable white/black surface detection.
* Control Logic Development: Programmed the Arduino to interpret sensor inputs and control motors via the L293D H-Bridge.

### Testing & Refinement
* Conducted repeated track trials to optimize PWM values and delay timings.
* Adjusted sensor placement and sensitivity to improve detection accuracy.
* Debugged logic flow and timing issues to ensure consistent navigation through junctions and turns.

### Key Challenges & Solutions
* Sensor Synchronization: Fine-tuned sensor alignment and sensitivity to prevent miscounting at junctions.
* Motor Control Tuning: Balanced PWM outputs and directional logic to execute sharp and smooth turns.
* System Reliability: Ensured stable power delivery and signal integrity across all components.

### Learning Outcomes
* Gained hands-on experience in embedded system design, from schematic to functional prototype.
* Developed skills in Arduino programming, sensor interfacing, and motor control.
* Practiced systematic debugging and iterative testing in a hardware-software integrated project.
* Strengthened collaborative engineering through team-based problem-solving and project documentation.

### How to Use
* Assemble the circuit as per the hardware design.
* Upload the provided Arduino sketch to the Nano board.
* Calibrate the IR sensors using the adjustable potentiometers.
* Place the car on a white-line track and trigger the bumper sensor to begin autonomous operation.
