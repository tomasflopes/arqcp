.section .data
	.global byte1	# char byte1;
	.global byte2	# char byte2;


.section .text
	.global concatBytes	# short concatBytes(void);

concatBytes:
	movb	byte1(%rip), %al	# 8 bit copy of variable byte1 to register
	movb	byte2(%rip), %ah	# 8 bit copy of variable byte2 to register
	ret

