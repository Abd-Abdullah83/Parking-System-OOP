# 🅿 Smart Parking System

![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue?style=flat-square&logo=cplusplus)
![OOP](https://img.shields.io/badge/Paradigm-OOP-blueviolet?style=flat-square)
![Rule of Five](https://img.shields.io/badge/Rule%20of%20Five-Implemented-green?style=flat-square)
![Assignment](https://img.shields.io/badge/Assignment-2-orange?style=flat-square)
![University](https://img.shields.io/badge/FAST-NUCES-red?style=flat-square)

> A complete Object-Oriented C++ implementation of a dynamic smart parking lot management system — built for FAST University OOP Assignment 2.

---

## 📋 Overview

This project redesigns the Smart Parking System from Assignment 1 using proper **Object-Oriented Programming** principles. All dynamic memory is encapsulated inside a single class — `ParkingBlock` — which manages a 2D grid of parking slots with full **Rule of Five** compliance.

> [!NOTE]
> STL containers (`vector`, `list`, etc.) and static arrays are **not permitted**. All memory is manually managed with raw pointers.

---

## 🏗 Project Structure

```
SmartParkingSystem/
├── ParkingClass.cpp        # Full class implementation
├── parking_block.txt      # Sample layout input file
└── coordinates.txt         # Block (x, y) coordinates file
```

---

## 🔧 Class Design

### `ParkingBlock` — Private Data Members

| Member         | Type       | Description                                              |
|----------------|------------|----------------------------------------------------------|
| `slots`        | `char***` | 2D dynamic array; stores vehicle number or `"EMPTY"`     |
| `slotsPerRow`  | `int*`     | Dynamic array; number of slots in each row               |
| `totalRows`    | `int`      | Total rows currently allocated in this block             |
| `x_coordinate` | `float`    | Block X position on the 2D plane (feet)                  |
| `y_coordinate` | `float`    | Block Y position on the 2D plane (feet)                  |

---

### Special Member Functions — Rule of Five

```cpp
class ParkingBlock {
public:
    ParkingBlock();                               // Default constructor — no allocation
    ParkingBlock(int numRows);                    // Parameterized constructor
    ~ParkingBlock();                              // Destructor — frees all memory
    ParkingBlock(const ParkingBlock& other);      // Copy constructor — deep copy
    ParkingBlock(ParkingBlock&& other) noexcept;  // Move constructor — transfer ownership
    ParkingBlock& operator=(const ParkingBlock& other);      // Copy assignment
    ParkingBlock& operator=(ParkingBlock&& other) noexcept;  // Move assignment
};
```

---

## 📦 Memory Management Functions

```cpp
// Increases row count by n — reallocates slotsPerRow and row pointer arrays
void addRows(int n);

// Allocates n slots for the given row and initializes each to "EMPTY"
void addSlots(int row, int n);
```

> These two functions are the primary memory allocation path post-construction. Used by `loadParkingLot()` to build the layout from a file.

---

## ⚙️ Functional Methods

| Method | Description |
|--------|-------------|
| `parkCar(row, slot, vehicleNum)` | Parks a vehicle; validates bounds and empty state |
| `removeCar(row, slot)` | Removes a vehicle; validates occupied state |
| `displayBlock()` | Prints block (x, y) and full slot layout |
| `resizeSlots(row, newSize)` | Grows or shrinks a row; aborts shrink if slots occupied |
| `searchVehicle(vehicleNum)` | Returns `int[2]` `{row, slot}` or `nullptr` — caller frees memory |
| `emptyRow(row)` | Sets all slots in a row to `"EMPTY"` |
| `emptyBlock()` | Calls `emptyRow()` on every row |
| `transferVehicles(source)` | Deep-copies source layout + data into this block |
| `mergeVehicles(source)` | **[Bonus]** Merges source vehicles without clearing destination |

### `searchVehicle()` — Usage in `main()`

```cpp
for (int b = 0; b < totalBlocks; b++) {
    int* result = blocks[b].searchVehicle(vehicleNumber);
    if (result != nullptr) {
        cout << "Found at Block " << b
             << ", Row " << result[0]
             << ", Slot " << result[1] << endl;
        delete[] result;   // caller is responsible for deallocation
        break;
    }
}
```

---

## 📁 Input File Formats

### `parking_layout.txt`

```
2           ← number of blocks
3 3 4 2     ← block 1: 3 rows with 3, 4, and 2 slots
2 5 9       ← block 2: 2 rows with 5 and 9 slots
```

### `coordinates.txt`

```
0.0   0.0    ← block 1 (x, y)
100.0 0.0    ← block 2 (x, y)
```

---

## 🗺 Smart Allocation — Coordinate Formula

Each block is anchored at `(x, y)`. Slot top-left corners are calculated as:

```cpp
float slotX = blockX + col * 8.0f;   // 8 ft per slot width
float slotY = blockY + row * 16.0f;  // 16 ft per row depth

float dist = sqrt(pow(slotX - targetX, 2) + pow(slotY - targetY, 2));
```

`smartAllocate(vehicleNum, desiredBlockIndex)` scans **all blocks** and parks the vehicle in the empty slot with minimum Euclidean distance from the target block's origin.

---

## 📟 Program Menu
| `0` | Initialize — load from file |
| `1` | enter layout manually |

| Option | Action |
|--------|--------|
| `1` | Park a vehicle |
| `2` | Remove a vehicle |
| `3` | Display full parking system |
| `4` | Increase slots in a row |
| `5` | Decrease slots in a row |
| `6` | Search for a vehicle |
| `7` | Empty a row |
| `8` | Empty a block |
| `9` | Transfer vehicles between blocks |
| `10` | Smart allocate a vehicle |
| `11` | Load block coordinates from file |
| `12` | Merge vehicles into a block *(Bonus)* |
| `13` | Exit |

---

## 🚀 How to Build & Run

### Linux / macOS

```bash
# Clone the repository
git clone https://github.com/Abd-Abdullah83/Parking-System-OOP.git
cd SmartParkingSystem

# Compile
g++ -std=c++17 -Wall -o parking ParkingClass.cpp

# Run
./parking
```

### Windows (MinGW)

```bash
g++ -std=c++17 -Wall -o parking.exe  ParkingClass.cpp
parking.exe
```

### Check for memory leaks (Linux)

```bash
valgrind --leak-check=full ./parking
```

---

## ✅ OOP Constraints & Rules

- All data members of `ParkingBlock` are `private` — strict encapsulation
- Full **Rule of Five** implemented
- No global variables anywhere in the project
- No STL containers (`vector`, `list`, `map`, etc.)
- No static arrays — all dynamic allocation only
- All user input validated with `cin.clear()` + `cin.ignore()` loop guards
- No memory leaks — ownership clearly tracked throughout

---

## 💬 Constructor Justifications (Evaluation Notes)

Comments are placed in the following functions identifying implicit constructor usage:

| Function | Constructor Comment |
|----------|---------------------|
| `emptyRow()` | Notes whether copy/move occurs internally |
| `emptyBlock()` | Notes which constructor would be implicitly invoked |
| `transferVehicles()` | Notes most appropriate constructor for this operation |

> You may be asked to verbally justify these during oral evaluation.

---

## 📝 Input Validation

- Non-integer input where integer expected → `cin.clear()` + `cin.ignore()` + re-prompt loop
- Out-of-range row/slot indices → descriptive error, re-prompt
- Empty or occupied slot conflicts → descriptive error
- File not found → graceful error message, falls back to manual input

---

## 👤 Author
### Built by **Abd-Abdullah83**
Submitted for **Object-Oriented Programming — Assignment 2**  
FAST National University of Computer & Emerging Sciences (NUCES)

---

<p align="center"><sub>Built with manual memory management and zero leaks.</sub></p>
