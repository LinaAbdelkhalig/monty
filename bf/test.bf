,	a is in cell 0
>,	b is in cell 1
<
[
	>	go to cell 1
	[
		- 	subtract 1 from cell#1
		< +	go to cell#0 and add 1
		> +	go to cell#3 and add 1
		< < go back to cell#0
	] by the end of this loop, both cell#2 and cell #3 hold the value of cell#1
	>	go to cell#1
	[
		-	subtract 1 from cell#2
		< +	go to cell#1 and add 1
		>	go to cell#2
	] by the end of this loop cell#1 is back to its original value and cell#2 is0
	< < - go back to cell#0 and subtract 1
] by the end of this loop, cell#3 is incremented by b a times and cell#1 is equal to the value of b
>>> .
