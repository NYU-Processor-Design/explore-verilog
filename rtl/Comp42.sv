module Comp42 (
    input [3:0] in,
    input cin,
    output [1:0] out,
    output cout
);
  wire s;
  Comp32 fa0 (
      .in (in[2:0]),
      .out({cout, s})
  );

  Comp32 fa1 (
      .in ({s, in[3], cin}),
      .out(out)
  );

endmodule
