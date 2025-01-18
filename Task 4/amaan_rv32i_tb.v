module amaan_rv32i_tb;

reg clk,RN;
wire [31:0]WB_OUT,NPC;

amaan_rv32i rv32(clk,RN,NPC,WB_OUT);


always #3 clk=!clk;

initial begin 
RN  = 1'b1;
clk = 1'b1;

  $dumpfile ("amaan_rv32i.vcd"); //by default vcd
  $dumpvars (0, amaan_rv32i_tb);
  
  #5 RN = 1'b0;
  
  #300 $finish;

end
endmodule
