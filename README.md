FLAT Assignment: C++ Finite State Transducer Project

This project is a C++ application built for the Formal Languages and Automata Theory (FLAT) course. It demonstrates how Finite State Transducers (FSTs) can be used to perform simple string manipulations such as binary complement and case conversion, along with visual representations of these FSTs.

The program provides an interactive command-line interface to enter input strings and see the corresponding FST outputs both in .fst and graphical .png formats.

🔹 Features

Binary Complement: Flips bits in a binary string (0 → 1, 1 → 0).

Case Conversion: Converts lowercase letters to uppercase and uppercase letters to lowercase.

Note: Additional modules like string reversal or tokenization could be added in the future.

⚙️ Prerequisites

Make sure your system has the following installed:

Linux/Ubuntu (tested on Ubuntu 24.04)

g++ compiler for C++

Anaconda/Miniconda for managing packages

Graphviz to generate visual diagrams of FSTs

Git to clone the project

🛠️ Setup Instructions
1. Clone the Repository
git clone [your-repo-link]
cd FLAT-Assignment

2. Create Conda Environment
conda create -n flat_fst_cpp
conda activate flat_fst_cpp

3. Install Dependencies
conda install -c conda-forge openfst -y
sudo apt update
sudo apt install graphviz -y

📁 Project Structure
FLAT-Assignment/
│
├── include/       # Header files (.h)
├── src/           # Source files (.cpp)
├── outputs/       # Generated .fst files
├── diagram/       # Graphical .dot and .png files
└── syms.txt       # Symbol table for FSTs

💻 Compilation & Execution
Compile the Program
g++ src/main.cpp src/binary_complement.cpp src/case_conversion.cpp \
-I include -I $CONDA_PREFIX/include -L $CONDA_PREFIX/lib -lfst -o fst_program

Set Library Path
export LD_LIBRARY_PATH=$CONDA_PREFIX/lib:$LD_LIBRARY_PATH

Run the Program
./fst_program


Follow prompts to enter binary or text strings.

The program automatically generates the corresponding FST files and diagram files.

🖼️ Generating Diagrams

To visualize the FSTs:

fstdraw --isymbols=syms.txt --osymbols=syms.txt outputs/binary_complement.fst diagram/binary_complement.dot
fstdraw --isymbols=syms.txt --osymbols=syms.txt outputs/case_conversion.fst diagram/case_conversion.dot

$CONDA_PREFIX/bin/dot -Tpng diagram/binary_complement.dot -o diagram/binary_complement.png
$CONDA_PREFIX/bin/dot -Tpng diagram/case_conversion.dot -o diagram/case_conversion.png


.dot files are text-based graphs of FSTs

.png files are rendered images of the FSTs

🔍 How It Works

Input Handling: The program reads the user input string.

FST Construction:

Each module creates a StdVectorFst object.

States and arcs are added dynamically based on the input.

File Output:

.fst files are saved in outputs/.

.dot files are generated using OpenFST's fstdraw.

.png diagrams are created using Graphviz's dot tool.

Visualization: The diagrams reflect the exact structure of the FST for the input string.

The system is designed modularly so each input generates a unique FST diagram automatically.

📝 Notes

Keep .fst and .png files organized in outputs/ and diagram/.

The program is interactive; each run produces fresh FSTs depending on input.

syms.txt provides the symbol table necessary for FST visualization.