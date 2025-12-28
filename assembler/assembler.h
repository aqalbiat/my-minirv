

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <vector>
#include <string>
#include <cstdint>

using namespace std;

class assembler {

	public:

        assembler() {}

        assembler(string fname_r, string fname_w) {
            this->read_fname = fname_r;
            this->write_fname = fname_w;
        }

        // Methods to pipeline the disassembling process:
        //      read_hex_file, disassemble, write_asm_file

        void read_hex_file();

        void disassemble();

        void write_asm_file();
        
        // Methods to pipeline the assembling process:
        //      read_asm_file, assemble, write_hex_file

        void read_asm_file();

        void assemble();

        void write_hex_file();

    private:
        string read_fname, write_fname;
        vector <uint32_t> input_data, output_data;
    
        // Functions to help with disassembling:
        //      check_hex, hex_str_to_int, inst_to_asm

        bool check_hex(string w);

        uint32_t hex_str_to_nbr(string w);

        string inst_to_asm(uint32_t);

        // Functions to help with assembling:
        //      check_asm, asm_to_inst, nbr_to_hex_str

        bool check_asm(string w);

        uint32_t asm_to_inst(string w);

        string nbr_to_hex_str(uint32_t);

};

#include "assembler.cpp"

#endif
