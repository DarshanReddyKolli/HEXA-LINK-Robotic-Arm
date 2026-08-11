# HEXA-LINK-Robotic-Arm
Bluetooth-controlled 6-DOF robotic arm based on ATmega328P, PCA9685 and HC-05.
# HEXA-LINK Robotic Arm 🤖

**A Bluetooth-controlled 6-DOF robotic arm developed as a diploma project in Automation & Robotics Engineering.**

HEXA-LINK is a compact robotic arm designed for wireless control through a custom Android application. The system uses an **ATmega328P microcontroller**, **HC-05 Bluetooth module**, **PCA9685 16-channel PWM servo driver**, and **six servo motors** to control the different joints of the robotic arm.

The mechanical structure was designed as a **3D-printed assembly**, while the control electronics were developed using a custom PCB.

---

## 📌 Project Overview

The objective of HEXA-LINK is to develop a low-cost, educational robotic arm capable of performing controlled multi-axis movements through a wireless Android interface.

The project combines:

* Embedded systems
* Robotics and automation
* Servo motor control
* Bluetooth communication
* PCB design and fabrication
* 3D mechanical design
* Android-based control

The robotic arm receives commands from the Android application through Bluetooth. The **HC-05** module transfers these commands to the **ATmega328P**, which processes them and controls the servo motors through the **PCA9685 PWM driver**.

---

## ✨ Key Features

* 🤖 6-axis / 6-DOF robotic arm
* 📱 Custom Android control application
* 📡 Wireless Bluetooth communication
* 🎛️ PCA9685 16-channel PWM servo driver
* 🧠 ATmega328P-based control system
* ⚙️ Six servo motors for robotic movement
* 🖨️ 3D-designed and fabricated mechanical structure
* 🔌 Custom PCB design
* 🛠️ PCB etching and fabrication
* 🔄 Multi-joint coordinated movement
* 💰 Designed as a low-cost educational robotics platform

---

## 🧩 System Architecture

```text
             ┌──────────────────────┐
             │    Android App       │
             │  Wireless Controller │
             └──────────┬───────────┘
                        │
                     Bluetooth
                        │
                        ▼
             ┌──────────────────────┐
             │       HC-05          │
             │  Bluetooth Module    │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │      ATmega328P      │
             │  Main Controller     │
             └──────────┬───────────┘
                        │ I²C
                        ▼
             ┌──────────────────────┐
             │      PCA9685         │
             │   PWM Servo Driver   │
             └──────────┬───────────┘
                        │
          ┌─────────────┼─────────────┐
          ▼             ▼             ▼
       Servo 1       Servo 2       Servo 3
       
          ┌─────────────┼─────────────┐
          ▼             ▼             ▼
       Servo 4       Servo 5       Servo 6
```

---

## 🔧 Hardware

| Component              | Purpose                      |
| ---------------------- | ---------------------------- |
| ATmega328P             | Main microcontroller         |
| HC-05                  | Bluetooth communication      |
| PCA9685                | 16-channel PWM servo control |
| Servo Motors ×6        | Robotic arm actuation        |
| 7805 Voltage Regulator | Voltage regulation           |
| 12 MHz Crystal         | Microcontroller clock        |
| Custom PCB             | Control electronics          |
| 3D-Printed Parts       | Robotic arm structure        |
| Power Supply           | System power                 |

---

## 💻 Software & Tools

* **Arduino IDE** — Microcontroller programming
* **Embedded C/C++** — Control firmware
* **EasyEDA** — PCB and circuit design
* **Android Application** — Wireless robotic arm control
* **3D CAD Software** — Mechanical structure design

---

## ⚙️ Working Principle

1. The user operates the robotic arm through the Android application.
2. Movement commands are transmitted wirelessly using Bluetooth.
3. The **HC-05 Bluetooth module** receives the commands.
4. The **ATmega328P** interprets the received commands.
5. The controller communicates with the **PCA9685** using I²C.
6. The PCA9685 generates the required PWM signals.
7. The six servo motors move according to the received commands.
8. The combined movement of the servos produces the required robotic arm motion.

---

## 🔌 Electronics & PCB

The project includes a custom control PCB designed for integrating the microcontroller, Bluetooth communication, servo control, and supporting electronic components.

The repository contains:

* Circuit diagram
* Schematic
* PCB design
* PCB 3D view
* PCB etching tracks
* Fabricated PCB
* Soldered PCB
* Connection diagram

---

## 🖨️ Mechanical Design

The robotic arm structure was designed as a modular 3D-printed assembly.

The repository includes various stages of the mechanical design, including:

* 3D structure designs
* Individual component designs
* Assembly views
* Final assembled robotic arm

---

## 📱 Android Control

A custom Android application was developed to provide a wireless interface for controlling the robotic arm.

The application communicates with the robotic arm through the HC-05 Bluetooth module and sends movement commands to the ATmega328P.

> The Android APK included in this repository is provided for demonstration and educational purposes.

---

## 📂 Repository Structure

```text
HEXA-LINK-Robotic-Arm/
│
├── Arduino/
│   └── HEXA-LINK-Robotic-Arm.ino
│
├── PCB/
│   ├── Circuit-Diagram/
│   ├── Schematic/
│   ├── PCB-Design/
│   └── Fabrication/
│
├── 3D-Design/
│   └── Structure-Diagrams/
│
├── Android-App/
│   └── roboticARM.apk
│
├── Images/
│   ├── Assembly/
│   ├── Electronics/
│   └── Components/
│
├── Documentation/
│
├── README.md
└── LICENSE
```

---

## 🎯 Project Objectives

* Develop a functional multi-axis robotic arm.
* Implement wireless robotic control using Bluetooth.
* Learn practical servo motor control.
* Develop an ATmega328P-based embedded control system.
* Design and fabricate a custom PCB.
* Develop a 3D-printed robotic structure.
* Integrate hardware, software, electronics, and mechanical systems into a single working prototype.

---

## 📚 Learning Outcomes

Through this project, the following practical skills were developed:

* Microcontroller programming
* Arduino-based embedded systems
* Servo motor control
* I²C communication
* Bluetooth communication
* PCB schematic and layout design
* PCB fabrication and soldering
* 3D mechanical design
* Robotics system integration
* Hardware troubleshooting
* Android-based hardware control

---

## 🚀 Future Improvements

Possible improvements for future versions include:

* Inverse kinematics-based control
* Automatic trajectory generation
* Improved precision and repeatability
* End-effector/tool attachment system
* Position feedback using sensors
* Computer vision integration
* Wi-Fi-based remote control
* Gesture-based control
* Improved mechanical strength
* Closed-loop servo control

---

## 👨‍💻 Project Team

**HEXA-LINK Robotic Arm**
Diploma Project — Automation & Robotics Engineering

Developed as an academic robotics project focused on practical implementation of embedded systems, electronics, mechanical design, and robotic control.

---

## 📜 License

This project is intended primarily for educational and demonstration purposes.

Please refer to the repository license before using, modifying, or redistributing the project.

---

## ⭐ Acknowledgements

This project was developed as part of an academic diploma project in **Automation & Robotics Engineering**.

Special thanks to the faculty, institution, and project team members who supported the development, fabrication, testing, and documentation of the project.
