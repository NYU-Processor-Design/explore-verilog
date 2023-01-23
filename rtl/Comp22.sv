module Comp22 (
    input  [1:0] in,
    output [1:0] out
);
  assign out[0] = ^in;
  assign out[1] = &in;
endmodule
