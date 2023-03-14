module count7(res,clk,cout);
input clk,res;
output wire cout;
reg[2:0] m,n;reg counter1,counter2;
assign cout=counter1|counter2;
always @(posedge clk)begin
    if(!res)begin counter1<=0;m<=0;end
    else begin
        if(m==6) m<=0;else m<=m+1;
        if(n<3) counter1<=1;else counter1<=0;
    end
end
always @(negedge clk)begin
    if(!res)begin counter2<=0;n<=0;end
    else begin
        if(n==6) n<=0;else n<=n+1;
        if(n<3) counter2<=1;else counter2<=0;
    end
end
endmodule