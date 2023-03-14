`timescale 1ns/1ns

module count7t;
reg clk;
reg res;
wire cout;
count7 u1(
    .res(res),
    .clk(clk),
    .cout(cout)
);
always #10 clk=~clk;
initial
    begin
	clk=1'b0;
        res=1'b0;
        #50 res=1'b1;
        $stop;
    end
endmodule