# Handheld Embedded Calculator

A fully functional handheld calculator developed from concept to physical prototype. This project combines custom C++ firmware, embedded electronics, PCB design, rechargeable power, and a 3D-printed mechanical enclosure in a compact consumer-style device.

![Final handheld calculator](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/final-calculator.jpg?raw=true)

## Project Overview

The goal of this project was to design and build a production-oriented handheld electronic device while gaining experience across the complete product-development process.

Rather than stopping at a breadboard prototype, the calculator was progressively redesigned to improve wiring complexity, physical size, reliability, manufacturability, and overall integration.

The project progressed through several hardware iterations:

1. Arduino Uno breadboard prototype
2. ESP32 breadboard redesign
3. Perf-board validation prototype
4. Custom two-layer PCB
5. 3D-printed snap-fit enclosure
6. Final integrated handheld device

## Key Features

- Addition, subtraction, multiplication, and division
- 4x4 matrix-keypad input
- 16x2 I2C LCD output
- Result chaining for consecutive calculations
- Divide-by-zero error handling
- ESP32-based embedded control
- Custom two-layer PCB
- Rechargeable 3.7 V battery system
- TP4056 battery-charging module
- MT3608 voltage step-up module
- 3D-printed snap-fit enclosure

## Tech Stack

- C++
- Arduino framework
- ESP32
- KiCad
- SOLIDWORKS
- PCB design
- Embedded systems
- Electronics prototyping
- 3D printing

## Development Process

### 1. Arduino Breadboard Prototype

The first prototype used an Arduino Uno to validate the calculator's computational logic, keypad input, LCD output, and C++ firmware.

![Arduino breadboard prototype](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/arduino-breadboard.png?raw=true)

### 2. ESP32 Architecture Migration

After validating the initial design, the system was redesigned around an ESP32 and a four-pin I2C LCD interface.

This reduced wiring complexity and provided a smaller platform for the final handheld device.

![ESP32 breadboard prototype](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/esp32-breadboard.png?raw=true)

### 3. Perf-Board Prototype

An intermediate perf-board version was built before committing to a custom PCB.

This stage validated the electrical architecture, permanent connections, and power delivery in a more durable configuration.

![Perf-board prototype](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/perf-board.png?raw=true)

### 4. Custom PCB

A custom two-layer PCB was designed in KiCad around the physical constraints of the handheld enclosure.

The PCB reduced unnecessary board area, simplified the wiring, and improved the reliability and organization of the final assembly.

![Manufactured custom PCBs](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/custom-pcbs.jpg?raw=true)

#### KiCad Schematic

![KiCad schematic](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/schematic.png?raw=true)

#### KiCad PCB Layout

![KiCad PCB layout](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/pcb-layout.png?raw=true)

### 5. Mechanical Enclosure

A compact snap-fit enclosure was designed in SOLIDWORKS to integrate the display, keypad, PCB, battery, charging electronics, and supporting hardware into one handheld device.

The enclosure was manufactured using 3D printing. Printable STL files are included in the repository.

![SOLIDWORKS enclosure](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/enclosure.png?raw=true)

## Final Assembly

The finished system integrates the ESP32, custom firmware, display, keypad, custom PCB, rechargeable power system, and 3D-printed enclosure.

![Internal electronics assembly](https://github.com/azagar06/Handheld-Embedded-Calculator/blob/main/Handheld-Embedded-Calculator-Browser-Safe/images/internal-electronics.jpg?raw=true)

## Firmware

The calculator firmware is located here:

[`handheld_calculator.ino`](./Handheld-Embedded-Calculator-Browser-Safe/firmware/handheld_calculator/handheld_calculator.ino)

The firmware uses the following Arduino libraries:

- `Wire`
- `LiquidCrystal_I2C`
- `Keypad`

### ESP32 Pin Assignments

| Function | ESP32 Pins |
| --- | --- |
| I2C SDA | GPIO 21 |
| I2C SCL | GPIO 22 |
| Keypad rows | GPIO 13, 12, 14, and 27 |
| Keypad columns | GPIO 26, 25, 33, and 32 |

The LCD is configured as a 16x2 display using I2C address `0x27`.

## Hardware Design Files

### KiCad

The KiCad project includes:

- `Calc.kicad_pro`
- `Calc.kicad_sch`
- `Calc.kicad_pcb`

[Open the KiCad project folder](./Handheld-Embedded-Calculator-Browser-Safe/hardware/kicad/calculator)

### Gerber Files

PCB manufacturing files are provided as:

[`calculator-gerbers.zip`](./Handheld-Embedded-Calculator-Browser-Safe/hardware/gerbers/calculator-gerbers.zip)

## Mechanical Design Files

### SOLIDWORKS

The repository contains:

- `Calculator.SLDASM`
- `calcbase.SLDPRT`

[Open the SOLIDWORKS folder](./Handheld-Embedded-Calculator-Browser-Safe/mechanical/solidworks)

The larger `calctop.SLDPRT` source file is available in the repository's [Releases](https://github.com/azagar06/Handheld-Embedded-Calculator/releases) section.

### 3D-Printable Files

The following STL files are included:

- `calcbase.STL`
- `calctop.STL`

[Open the STL folder](./Handheld-Embedded-Calculator-Browser-Safe/mechanical/stl)

## Engineering Challenges

### Cross-Domain Integration

One of the primary challenges was integrating firmware, custom electronics, PCB design, power electronics, and mechanical components into one functional system.

Electrical and mechanical decisions had to be developed together because changes in one area frequently affected the final assembly.

### Spatial Constraints

The handheld form factor introduced strict space limitations.

Component placement, PCB geometry, wiring, display positioning, battery placement, and enclosure dimensions were optimized to reduce the overall footprint while maintaining functionality.

### Rechargeable Power System

An MT3608 step-up module, 3.7 V rechargeable battery, and TP4056 charger module were integrated to create a rechargeable power system for the calculator.

### Design for Manufacturability

The project was developed beyond a breadboard proof of concept.

Design considerations included:

- Component placement
- Assembly efficiency
- Structural durability
- PCB size
- Low-profile component selection
- Cost-effective component sourcing
- Reduced wiring complexity
- Ease of final assembly

## Repository Structure

```text
Handheld-Embedded-Calculator/
├── README.md
└── Handheld-Embedded-Calculator-Browser-Safe/
    ├── firmware/
    │   └── handheld_calculator/
    │       └── handheld_calculator.ino
    ├── hardware/
    │   ├── kicad/
    │   │   └── calculator/
    │   │       ├── Calc.kicad_pcb
    │   │       ├── Calc.kicad_pro
    │   │       └── Calc.kicad_sch
    │   └── gerbers/
    │       └── calculator-gerbers.zip
    ├── mechanical/
    │   ├── solidworks/
    │   │   ├── Calculator.SLDASM
    │   │   ├── calcbase.SLDPRT
    │   │   └── README.md
    │   └── stl/
    │       ├── calcbase.STL
    │       └── calctop.STL
    ├── images/
    │   ├── arduino-breadboard.png
    │   ├── custom-pcbs.jpg
    │   ├── enclosure.png
    │   ├── esp32-breadboard.png
    │   ├── final-calculator.jpg
    │   ├── internal-electronics.jpg
    │   ├── pcb-layout.png
    │   ├── perf-board.png
    │   └── schematic.png
    └── docs/
        ├── calculator-project-one-page.pdf
        └── calculator-project-portfolio.pdf
```

## Opening the Project Files

- Open `handheld_calculator.ino` using the Arduino IDE.
- Install the `LiquidCrystal_I2C` and `Keypad` libraries if needed.
- Open `Calc.kicad_pro` in KiCad to view the schematic and PCB layout.
- Use `calculator-gerbers.zip` when viewing or ordering the custom PCB.
- Open the `.SLDASM` and `.SLDPRT` files using SOLIDWORKS.
- Download `calctop.SLDPRT` from the Releases section before opening the complete SOLIDWORKS assembly.
- Open the STL files in a compatible 3D-printing slicer.

## Documentation

Printable project summaries are available in the [`docs`](./Handheld-Embedded-Calculator-Browser-Safe/docs) folder.

## Author

Adriano Zagar
