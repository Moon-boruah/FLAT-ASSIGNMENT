#include "binary_complement.h"
#include "case_conversion.h"
#include <iostream>
#include <string>

int main() {
    std::string bin_input;
    std::cout << "Enter binary string: ";
    std::cin >> bin_input;
    BuildBinaryComplementFST(bin_input);
    std::cout << "Binary complement FST saved in outputs/binary_complement.fst\n";

    std::string text_input;
    std::cout << "Enter text string for case conversion: ";
    std::cin >> text_input;
    BuildCaseConversionFST(text_input);
    std::cout << "Case conversion FST saved in outputs/case_conversion.fst\n";

    std::cout << "Done!\n";
    return 0;
}


