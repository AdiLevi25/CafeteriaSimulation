# CafeteriaSimulation

This project simulates a cafeteria queue system using Object-Oriented Programming principles in C++.  
The simulation handles student arrivals, service processing, and queue management using custom data structures.

---

## 📁 File Overview

| File Name             | Description |
|-----------------------|-------------|
| `Main.cpp`            | Entry point of the program. Runs the simulation. |
| `Simulation.h/cpp`    | Contains the main simulation logic and time control. |
| `Student.h/cpp`       | Defines the Student class and its properties (ID, arrival time, etc.). |
| `StudentQueue.h/cpp`  | Implements a queue to manage students waiting to be served. |
| `CafeteriaQueue.h/cpp`| Coordinates the simulation between student logic and queue logic. |
| `VectorInt.h/cpp`     | A simple dynamic array class used internally (e.g., for queue storage). |

---

## ⚙️ How to Compile

You can compile the project using `g++` with the following command:

```bash
g++ Main.cpp Simulation.cpp Student.cpp StudentQueue.cpp CafeteriaQueue.cpp VectorInt.cpp -o CafeteriaSim
