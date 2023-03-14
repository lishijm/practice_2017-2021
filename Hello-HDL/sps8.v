module sps8(clk,start,clr,datai,wr,datao);
input clr,start,clk,datai;
output wr;
output reg [7:0] datao;
reg wr;
reg [3:0] count;
always @(posedge clk)begin
   if(clr==1)begin wr<=0;datao<=8'b0;count<=4'b0; end
end 
always@(start or posedge clk or negedge clk)begin
    if(clr==0&&count==7) begin
        wr<=1;
	datao[count]<=datai;
	count<=count+1;
    end
    else if(clr==0&&count==8)begin
        count<=1;
        datao=8'b0;
	wr=0;
    end
    else if(clr==0) begin
        wr=0;
        datao[count]<=datai;
        count<=count+1;
    end
end
endmodule