	.file	"lab3_helper.c"
	.text
	.globl	helper_func
	.type	helper_func, @function
helper_func:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$45, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	$213, -24(%rbp)
	movl	$0, -28(%rbp)
	jmp	.L2
.L3:
	movl	$24, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, -12(%rbp)
	movl	-24(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	negl	%eax
	movl	-12(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	imull	$45, %eax, %eax
	movslq	%eax, %rdx
	imulq	$2078471887, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$8, %edx
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$100900090, %eax, %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	subl	-4(%rbp), %eax
	movl	%eax, -20(%rbp)
	addl	$1, -28(%rbp)
.L2:
	movl	-24(%rbp), %eax
	imull	$100, %eax, %eax
	cmpl	%eax, -28(%rbp)
	jl	.L3
	movl	-24(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	helper_func, .-helper_func
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
