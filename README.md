# Handheld Embedded Calculator

A fully functional handheld calculator designed and engineered from concept to physical prototype. This project integrates custom C++ firmware, embedded electronics, PCB design, and mechanical enclosure design into a compact consumer-style device.

The project progressed through multiple hardware iterations—from an Arduino breadboard prototype to an ESP32-based architecture, perf-board validation, a custom 2-layer PCB, and a 3D-printed enclosure.

## Project Overview

The goal of this project was to design and build a production-oriented handheld electronic device while gaining experience across the complete product development process.

Rather than stopping at a breadboard prototype, the calculator was progressively redesigned to improve wiring complexity, physical size, reliability, manufacturability, and overall integration.

### Tech Stack

- C++
- Arduino
- ESP32
- KiCad
- SOLIDWORKS
- PCB Design
- Embedded Systems
- 3D Printing

## Development Process

### 1. Arduino Breadboard Prototype

The first prototype was constructed using an Arduino Uno to validate the calculator's core computational logic, keypad input, LCD output, and C++ firmware.

![Arduino Breadboard](images/arduino-breadboard.jpg)

### 2. ESP32 Architecture Migration

After validating the initial design, the system was re-engineered around an ESP32 and a 4-pin LCD interface.

This reduced wiring complexity and provided a significantly smaller platform for the final handheld design.

![ESP32 Breadboard](images/esp32-breadboard.jpg)

### 3. Perf-Board Prototype

An intermediate perf-board version was built before committing to a custom PCB.

This stage provided an opportunity to validate the electrical architecture, connections, signal integrity, and power delivery in a more permanent configuration.

![Perf-Board Prototype](images/perfboard.jpg)

### 4. Custom PCB

After hardware validation, a custom 2-layer PCB was designed in KiCad.

The board was designed around the physical constraints of the handheld enclosure while minimizing unnecessary board area and simplifying final assembly.

![PCB](images/pcb.jpg)

#### Schematic

![KiCad Schematic](images/schematic.png)

#### PCB Layout

![KiCad PCB Layout](images/pcb-layout.png)

#### PCB 3D Model

![PCB 3D View](images/pcb-3d-view.png)

### 5. Mechanical Enclosure

A compact enclosure was designed in SOLIDWORKS to integrate the display, keypad, PCB, and supporting electronics into a single handheld device.

The enclosure was designed with a snap-fit architecture and manufactured using 3D printing.

![SOLIDWORKS Enclosure](images/enclosure.png)

## Final Assembly

The final system integrates the custom electronics, C++ firmware, display, keypad, PCB, and 3D-printed enclosure into a complete handheld calculator.

![Final Calculator](images/final-calculator.jpg)

## Engineering Challenges

### Cross-Domain Integration

One of the primary challenges was integrating firmware, electronics, PCB design, and mechanical components into one functional system.

Design decisions in one area frequently affected another, requiring the electrical and mechanical designs to be developed together rather than independently.

### Spatial Constraints

The handheld form factor introduced strict space limitations.

Component placement, PCB geometry, wiring, display positioning, and enclosure dimensions were optimized to reduce the overall footprint while maintaining functionality.

### Design for Manufacturability

The project was developed with manufacturability in mind rather than remaining solely a proof-of-concept prototype.

Design considerations included:

- Component placement
- Assembly efficiency
- Structural durability
- PCB size
- Low-profile component selection
- Cost-effective component sourcing
- Reduced wiring complexity

## Repository Structure

```text
Handheld-Embedded-Calculator/
│
├── firmware/
│   └── Calculator firmware and embedded software
│
├── hardware/
│   ├── kicad/
│   │   └── PCB schematic and layout files
│   ├── gerbers/
│   │   └── PCB manufacturing files
│   └── bom/
│       └── Bill of materials
│
├── mechanical/
│   ├── solidworks/
│   │   └── Enclosure CAD files
│   └── stl/
│       └── 3D-printable enclosure files
│
├── images/
│   └── Project photos, PCB renders, and CAD images
│
├── documentation/
│   └── Engineering project documentation
│
└── README.md
