module s_51011(clk,clr,x,z);
input clk,clr,x;
output reg z;
reg[2:0]c_s,n_s;
parameter s0=3'b000,s1=3'b001,s2=3'b010,s3=3'b011,s4=3'b100;
always @(posedge clk or posedge clr)begin
    if(clr)c_s<=0;
    else c_s<=n_s;
end
always @(c_s or x)begin
   case(c_s)
        s0:begin if(x==1)n_s<=s1;
            else n_s<=s0; end
        s1:begin if(x==0)n_s<=s2;
            else n_s<=s1; end
        s2:begin if(x==1)n_s<=s3;
            else n_s<=s0; end
        s3:begin if(x==1)n_s<=s4;
            else n_s<=s2; end
        s4:begin if(x==1)n_s<=s1;
            else n_s<=s2; end
    endcase
end
always @(c_s)begin
    case(c_s)
        s4:z=1'b1;
        default:z=1'b0;
    endcase
end
endmodule