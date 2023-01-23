module Comp53 (
    input  [4:0] in,
    output [2:0] out
);
  wire [1:0] fa0_out;
  Comp32 fa0 (
      .in (in[2:0]),
      .out(fa0_out)
  );

  wire c;
  Comp32 fa1 (
      .in ({in[4:3], fa0_out[0]}),
      .out({c, out[0]})
  );

  Comp22 ha (
      .in ({c, fa0_out[1]}),
      .out({out[2:1]})
  );

endmodule
