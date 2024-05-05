unsigned pla(unsigned input, unsigned plamask[][3]) /* and-or nand-nand pla */{
	unsigned i, res = 0;

	for (i = 0; (plamask[i][2] != 0); i++) {
		if (!((~(input) & plamask[i][0]) || (input & plamask[i][1])))
			res |= plamask[i][2];
	}
	return (res);
}
