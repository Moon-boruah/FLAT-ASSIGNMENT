#include "binary_complement.h"
#include <fst/fstlib.h>
#include <string>

using namespace fst;

void BuildBinaryComplementFST(const std::string &input) {
    StdVectorFst fst;
    auto s0 = fst.AddState();
    fst.SetStart(s0);
    auto s1 = fst.AddState();
    fst.SetFinal(s1, TropicalWeight::One());

    int current_state = s0;
    for (char c : input) {
        int in_sym = c;
        int out_sym = (c == '0') ? '1' : '0';
        auto next_state = fst.AddState();
        fst.AddArc(current_state, StdArc(in_sym, out_sym, TropicalWeight::One(), next_state));
        current_state = next_state;
    }
    fst.SetFinal(current_state, TropicalWeight::One());

    // Save FST
    fst.Write("outputs/binary_complement.fst");
}


