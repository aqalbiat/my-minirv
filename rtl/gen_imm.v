module gen_imm (
    in [11:0] data_imm_w12,
    in [19:0] data_imm_w20,
    in [4:0] data_imm_w5,
    in [6:0] data_imm_w7,
    out [31:0] type_I_imm,
    out [31:0] type_S_imm,
    out [31:0] type_U_imm
);

    assign type_I_imm = {{20{data_imm_w12[11]}}, data_imm_w12};
    assign type_S_imm = {{20{data_imm_w7[6]}}, {data_imm_w7}, {data_imm_w5}};
    assign type_U_imm = {{12{data_imm_w20[19]}}, data_imm_w20};

end