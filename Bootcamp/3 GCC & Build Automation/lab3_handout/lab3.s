	.file	"lab3.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"You are taking this class: %d %d \n"
	.text
	.globl	fibonacci
	.type	fibonacci, @function
fibonacci:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -36(%rbp)
	movl	$40, -20(%rbp)
	movl	$0, %eax
	call	helper_func@PLT
	movl	%eax, %ecx
	movl	-36(%rbp), %eax
	movl	%eax, %edx
	movl	%ecx, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$1, -36(%rbp)
	jg	.L2
	movl	-36(%rbp), %eax
	jmp	.L3
.L2:
	movl	-36(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fibonacci
	movl	%eax, %ebx
	movl	-36(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fibonacci
	addl	%ebx, %eax
.L3:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fibonacci, .-fibonacci
	.section	.rodata
.LC1:
	.string	"fib(%d) = %d\n"
	.align 8
.LC3:
	.string	"clocks ticks: %f \nTime in seconds taken by CPU: %f \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	call	clock@PLT
	movq	%rax, -16(%rbp)
	movl	$25, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edi
	call	fibonacci
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2, -24(%rbp)
	call	clock@PLT
	subq	-16(%rbp), %rax
	movq	%rax, -16(%rbp)
	cvtsi2sdq	-16(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	cvtsi2sdq	-16(%rbp), %xmm0
	movsd	-8(%rbp), %xmm1
	leaq	.LC3(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1093567616
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
