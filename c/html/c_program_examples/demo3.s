	.file	"demo3.c"
	.section	.rodata
.LC2:
	.string	"%d\n"
.LC4:
	.string	"%f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$3, -24(%rbp)
	movb	$37, -25(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -20(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	-24(%rbp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	pxor	%xmm0, %xmm0
	cvtsi2sd	-24(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	pxor	%xmm0, %xmm0
	cvtsi2sd	-24(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	movsbl	-25(%rbp), %esi
	movl	-24(%rbp), %eax
	cltd
	idivl	%esi
	pxor	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	-24(%rbp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, -40(%rbp)
	movsd	-40(%rbp), %xmm0
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	pxor	%xmm0, %xmm0
	cvtsi2ss	-24(%rbp), %xmm0
	divss	-20(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1078523331
	.align 8
.LC1:
	.long	1996669136
	.long	1048413988
	.align 8
.LC3:
	.long	0
	.long	1075052544
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
