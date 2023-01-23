module Comp73 (
    input  [6:0] in,
    output [2:0] out
);
  wire [1:0] fa0_out;
  Comp32 fa0 (
      .in (in[2:0]),
      .out(fa0_out)
  );

  wire [1:0] fa1_out;
  Comp32 fa1 (
      .in (in[5:3]),
      .out(fa1_out)
  );

  wire c;
  Comp32 fa2 (
      .in ({fa0_out[0], fa1_out[0], in[6]}),
      .out({c, out[0]})
  );

  Comp32 fa3 (
      .in ({fa0_out[1], fa1_out[1], c}),
      .out(out[2:1])
  );

endmodule
