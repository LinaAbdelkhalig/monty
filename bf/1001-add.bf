we are now in cell0
,  now the first digit is in cell 0
>, we move to cell1 and accept the input in it
> +++ +++ move to cell 2 and start looping 6 times
[	
	< ---- ---- go to cell 1 and decrease 8
	< ---- ---- go to cell 0 and add 8
	> > - go to cell 2 and decrement by 1
]
< go back to cell 1
[
	< + go to cell 0 and add 1
	> - go back to cell 1 and decrease by 1
]
> +++ +++ go to cell 2 and add 6 to start a loop
[
	< < ++++ ++++ go to cell 0 and subtract 8
	> > - 	      go to cell 2 and decrease by 1
]
< < . go to cell 0 and print
