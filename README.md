# Resistor Ratio Calculator

  A simple calculator that returns a combination of resistors from E12 or E24 series, based on the user-specified ratio and tolerance.

  Combinations of 2 resistors are tested first -> R2/R1

  If none found, combinations of 3 resistors are tested -> R2/(R1+R3)

  This calculator can aid in the design of specific OpAmp gain.

  The output of the calculator is saved to a .txt file.

  `.replit` is included for easy integration into Repl.it web based IDE.
  
  Things to implement:
      add calculation mode for voltage divider combinations
