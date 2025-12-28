module register_file (
    in [4:0] sel_rs1,
    in [4:0] sel_rs2,
    in [4:0] sel_rd,
    in [31:0] data_in,
    in write_enable,
    in rst,
    in clk,
    out [31:0] data_rs1,
    out [31:0] data_rs2
);

    reg [31:0] gpr[31:0];

    always @(posedge clk) begin
        if (rst) begin 
            genvar i1;
            generate
                for (i1 = 0; i1 < 32; i1++) begin : gen_gprs_resets
                    gpr[i1] <= 32'b0;
                end
            endgenerate
        end else if (write_enable && sel_rd > 5'b0) begin
            gpr[sel_rd] <= data_in;
        end
    end

    assign gpr[0] = 32'b0;
    assign data_rs1 = gpr[sel_rs1];
    assign data_rs2 = gpr[sel_rs2];

end