# Resistor Ratio Calculator

  A simple calculator that returns a combination of resistors from E12 or E24 series, based on the user-specified ratio and tolerance.

  Combinations of 2 resistors are tested first -> $\frac{R2}{R1}$ <img src="https://latex.codecogs.com/gif.latex?\frac{R2}{R1}" title="\frac{R2}{R1}" /></a>

  If none found, combinations of 3 resistors are tested -> $\frac{R2}{(R1+R3)}$ <img src="https://latex.codecogs.com/gif.latex?\frac{R2}{(R1&plus;R3)}" title="\frac{R2}{(R1+R3)}" /></a>

  This calculator can aid in the design of voltage dividers or specific OpAmp gain.

  The output of the calculator is saved to a .txt file.

  `.replit` and `Makefile` are included for easy integration into Repl.it web based IDE.
