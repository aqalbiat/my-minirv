module instruction_decode (
    in [31:0] instruction,
    out [6:0] opcode,
    out [4:0] rd,
    out [2:0] funct3,
    out [4:0] rs1,
    out [11:0] imm_31_20,
    out [4:0] rs2,
    out [6:0] funct7,
    out [19:0] imm_31_12,
    out [4:0] imm_11_7,
    out [6:0] imm_31_25 
);

    assign opcode       = instruction[6:0];
    assign rd           = instruction[11:7];
    assign funct3       = instruction[14:12];
    assign rs1          = instruction[19:15];
    assign rs2          = instruction[24:20];
    assign funct7       = instruction[31:25];
    assign imm_31_20    = instruction[31:20];
    assign imm_31_12    = instruction[31:12];
    assign imm_11_7     = instruction[11:7];
    assign imm_31_25    = instruction[31:25];

end