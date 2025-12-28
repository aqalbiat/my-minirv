
module ram_w32_addr24 (
    input [23:0] sel_addr,
    input [31:0] data_in,
    input [3:0] wbyte_enable,
    input [3:0] rbyte_enable,
    input wen,
    input clk,
    output [31:0] data_out
);

    reg [31:0] data [23:0];

    wire [31:0] mask_in;
    wire [31:0] mask_out;

    assign mask_in = {{8{wbyte_enable[3]}}, {8{wbyte_enable[2]}}, {8{wbyte_enable[1]}}, {8{wbyte_enable[0]}}}
    assign mask_out = {{8{rbyte_enable[3]}}, {8{rbyte_enable[2]}}, {8{rbyte_enable[1]}}, {8{rbyte_enable[0]}}};

    always @(posedge clk) begin
        if (wen) begin
            data[sel_addr] <= (data_in & mask_in);
        end
    end

    assign data_out = (data[sel_addr] & mask_out);

end
