# Pressure Detection
First Term Project 
||||
| :- | :- | :- |
|Abdulrahman Hassanin Ali |12/31/22 |Learn-in-depth |
||||

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.001.jpeg)






# Content 

1. [Problem Statement](#ProblemStatement)
1. [Goal](#Goal)
1. [Specification](#Specification) 
1. [Method](#Method) 
1. [Requirement Diagram](#RequirementDiagram) 
1. [Space Exploration](#SpaceExploration)
1. [System Analysis](#SystemAnalysis) 
   1. [Use Case Diagram](#UseCase)
   1. [Activity Diagram](#activity)
   1. [Sequence Diagram](#seq)
1. [System Design](#sysdesign)
   1. [Block (Instance) DiagramPressure Sensor Driver](#block) 
   1. [Pressure Driver](#pressure)
   1. [Pressure Detection](#pressureDetect)
   1. [Alarm Monitor](#AlarmMonitor)
   1. [Alarm Actuator Driver](#AlarmAct)
   1. [System Design Simulation](#Sim)
1. [System Simulation](#prot)
1. [Software Analysis](#analysis)
    1. [Memory Map](#mem)

##  1. Problem Statement <a name="ProblemStatement"></a>

The more we travel up in the air, pressure decreases. Airplane travels up and down causes the air pressure changing. This problem is dangerous for passengers. 

## 2  Goal <a name="Goal"></a>

Develop a device to control and manage the air pressure in the crew cabin. 

## 3  Specification <a name="Specification"></a>

Pressure Detection informs the crew of a cabin with an alarm, when the pressure exceeds 20 bars in the cabin. 

- The alarm duration equal 60 seconds. 
- Optional: Keep track of the measured value. 

## 4  Method <a name="Method"></a>

The V-model is the used method for developing and testing. 

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.002.png)

## 5  Requirement Diagram <a name="RequirementDiagram"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.003.jpeg)

## 6  Space Exploration <a name="SpaceExploration"></a>

STM32 Microcontroller will be used. 
![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.004.png)

## 7  System Analysis <a name="SystemAnalysis"></a>

### 7.1 Use Case Diagram <a name="UseCase"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.005.jpeg)

### 7.2 Activity Diagram <a name="activity"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.006.jpeg)

### 7.3 Sequence Diagram <a name="seq"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.007.jpeg)

## 8  System Design <a name="sysdesign"></a>

### 8.1 Block (Instance) Diagram <a name="block"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.008.jpeg)

### 8.2 Pressure Sensor Driver <a name="pressure"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.009.jpeg)

### 8.3 Pressure Detection <a name="pressureDetect"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.010.jpeg)

### 8.4 Alarm Monitor <a name="AlarmMonitor"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.011.jpeg)

### 8.5 Alarm Actuator Driver <a name="AlarmAct"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.012.png)

### 8.6 System Design Simulation <a name="Sim"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.013.jpeg)

## 9  System Simulation <a name="prot"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.014.jpeg)

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.015.jpeg)

## 10 Software Analysis <a name="analysis"></a>

### 10.1  Object files section <a name="mem"></a>

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.016.jpeg)

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.017.jpeg)

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.018.jpeg)

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.019.jpeg)

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.020.jpeg)

![](assets/Aspose.Words.c4ec6389-c714-476c-9beb-4683ff07a17c.021.jpeg)