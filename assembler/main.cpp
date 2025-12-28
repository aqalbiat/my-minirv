#include "assembler.h"
#include "arguments.cpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

string help_message;

void init_help() {
    help_message += "Expected format of arguments:\n";
    help_message += "./asm --fin=$input_file.txt$ --fout=$output_file.txt$ --mode\n";
    help_message += " - $input_file.txt$ is the file from which is tool should read the data\n";
    help_message += " - $output_file.txt$ is the file to which the tool should write the result of work\n";
    help_message += " - mode could be of two types: --asm (for assembling) or --dis (for disassembling)\n";
}

int main(int argc, char **argv) {
    init_help();
    pair < map <string, bool>, map <string, string> > parsed;
    parsed = parse_arguments(argc, argv);
    map <string, bool> exists = parsed.first;
    map <string, string> values = parsed.second;
    if (!exists["fin"] || !exists["fout"] || (!exists["asm"] && !exists["dis"])) {
        cout << "Some of the arguments are missing\n";
        cout << help_message;
        exit(-1);
    }
    if (exists["asm"] && exists["dis"]) {
        cout << "Only one of the mod arguments must be used: --asm or --dis (not both)\n";
        cout << help_message;
        exit(-1);
    }
    assembler machine = assembler(values["fin"], values["fout"]);
    if (exists["asm"]) {
        machine.read_asm_file();
        machine.assemble();
        machine.write_hex_file();
    } else {
        machine.read_hex_file();
        machine.disassemble();
        machine.write_asm_file();
    }
    return 0;
}
