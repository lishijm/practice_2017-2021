`timescale 1ns/1ns

module countert;
reg clk;
reg clr;
wire out ;
wire[7:0] num ;
counter u1(
	.clk(clk),
	.clr(clr),
	.num(num),
	.out(out)
	
);

always #50 clk=~clk;


initial 
	begin
        clk=1'b0;
        clr=1'b0;
        #10 clr =1'b1;
		$stop;
	end
endmodule