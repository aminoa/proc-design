# Week 3 Lab: Verification

Exercise 2:

- My strategy was to try randomized different initial states and run the model for 1000 cycles. Since the LFSR can take a 16 bit number, it's not reasonable to simply bruteforce all values. Therefore, I chose the strategy of trying a sample of values that can fit into a 16 bit number. The 1000 cycles was to verify the behavior of the module over time without taking too much time.
