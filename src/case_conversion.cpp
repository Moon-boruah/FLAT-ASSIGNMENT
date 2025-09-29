#include "case_conversion.h"
#include <fst/fstlib.h>
#include <string>

using namespace fst;

void BuildCaseConversionFST(const std::string &input) {
    StdVectorFst fst;
    auto s0 = fst.AddState();
    fst.SetStart(s0);
    fst.SetFinal(s0, TropicalWeight::One());

    int current_state = s0;
    for (char c : input) {
        int in_sym = c;
        int out_sym;
        if (c >= 'A' && c <= 'Z')
            out_sym = c + 32;  // Upper → lower
        else if (c >= 'a' && c <= 'z')
            out_sym = c - 32;  // Lower → upper
        else
            out_sym = c;       // Other chars unchanged

        auto next_state = fst.AddState();
        fst.AddArc(current_state, StdArc(in_sym, out_sym, TropicalWeight::One(), next_state));
        current_state = next_state;
    }
    fst.SetFinal(current_state, TropicalWeight::One());

    // Save FST
    fst.Write("outputs/case_conversion.fst");
}



