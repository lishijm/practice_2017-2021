module counter(clk,clr,out,num);
input clk;
input clr;

output[7:0]num;
output out;

reg[7:0] num;
reg out;

always @(posedge clk or negedge clr)
begin
	if(!clr) begin out<=1'b0;num<=8'b0;end
	else begin
 		if(num==8'b01101111) begin out<=1'b1;num<=8'b0;end
		else begin num<=num+1'b1;end
	end
end
endmodule