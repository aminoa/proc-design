module Exercise3 (
    input clk,
    input nReset,
    input [3:0] a,
    input [15:0] b,
    input [15:0] c,
    output [15:0] out
);

wire [7:0] a_in; 
wire [7:0] b_in;

Mystery1 Alpha(a[1:0], b[7:0], c[7:0], a_in);
Mystery1 Beta(a[3:2], b[15:8], c[15:8], b_in);
Mystery2 Gamma(clk, nReset, a_in, b_in, out);


endmodule
