we are now in cell0
,  now the first digit is in cell 0
>, we move to cell1 and accept the input in it
> +++ +++ move to cell 2 and start looping 6 times
[	
	< ---- ---- go to cell 1 and decrease 8
	< ---- ---- go to cell 0 and add 8
	> > - go to cell 2 and decrement by 1
]
< < go back to cell 0
[
	> go to cell 1
	[
		- decrease cell#1
		> + go to cell 2 and add 1
		> + go to cell 3 and add 1
	]
	> go to cell 2
	[
		- decrease cell 2 by 1
		< + go to cell 1 and increase by 1
	]
	< < - decrease cell 0 by 1
]
> > > go to cell 3
> +++ +++ go to cell 4 and add 6 to start a loop
[
        < ++++ ++++   go to cell 3 and add 8
        > -           go to cell 4 and decrease by 1
]
<< .
