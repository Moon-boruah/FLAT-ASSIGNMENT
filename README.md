# FLAT Assignment: C++ Finite State Transducer Toolkit

This project is a C++ application developed for the Formal Languages and Automata Theory (FLAT) course. It demonstrates **Binary Complement** and **Case Conversion** Finite State Transducers (FSTs) using the OpenFST library.

The program allows the user to enter input strings interactively and generates both `.fst` files and visual diagrams for the FSTs.

## ✨ Features

- **Binary Complement**: Flips bits in a binary string (0 → 1, 1 → 0).  
- **Case Conversion**: Converts lowercase letters to uppercase and vice versa.

## 🔧 Prerequisites

Make sure you have the following installed:

- Ubuntu-based Linux distribution  
- g++ compiler  
- [Anaconda or Miniconda](https://www.anaconda.com/)  
- OpenFST (via conda)  
- Graphviz (for visualizing FSTs)

## 🚀 Setup Instructions

1. **Clone the Repository**  
```bash
git clone <your-repository-link>
cd <repository-folder>
```

2. **Create Conda Environment and Install Dependencies**  
```bash
conda create -n flat_fst_cpp
conda activate flat_fst_cpp
conda install -c conda-forge openfst -y
sudo apt update
sudo apt install graphviz -y
```

3. **Compile the Project**  
```bash
g++ src/main.cpp src/binary_complement.cpp src/case_conversion.cpp \
-I include -I $CONDA_PREFIX/include -L $CONDA_PREFIX/lib -lfst -o fst_program
```

4. **Set Library Path**  
```bash
export LD_LIBRARY_PATH=$CONDA_PREFIX/lib:$LD_LIBRARY_PATH
```

5. **Run the Program**  
```bash
./fst_program
```

## 🕹️ Usage Example

**Binary Complement**
```
Enter binary string: 1011
Binary complement FST saved in outputs/binary_complement.fst
```

**Case Conversion**
```
Enter text string for case conversion: AbC
Case conversion FST saved in outputs/case_conversion.fst
```

The corresponding `.dot` diagrams are generated in `diagram/` and can be converted to `.png` using:
```bash
$CONDA_PREFIX/bin/dot -Tpng diagram/binary_complement.dot -o diagram/binary_complement.png
$CONDA_PREFIX/bin/dot -Tpng diagram/case_conversion.dot -o diagram/case_conversion.png
```

## 📁 Directory Structure

```
FLAT-Assignment/
│
├── include/      # Header files (.h)
├── src/          # C++ source files (.cpp)
├── outputs/      # Generated .fst files
├── diagram/      # Generated .dot and .png diagrams
└── syms.txt      # Symbol table for FSTs
```

## 🔬 Project Overview

- **main.cpp**: Command-line interface, handles user input and dispatches tasks.  
- **binary_complement.cpp/h**: Builds FST for binary complement.  
- **case_conversion.cpp/h**: Builds FST for case conversion.  
- Generates `.fst` files and `.dot` diagrams dynamically for each input.  

The program demonstrates the fundamentals of FST construction and visualization with OpenFST.
