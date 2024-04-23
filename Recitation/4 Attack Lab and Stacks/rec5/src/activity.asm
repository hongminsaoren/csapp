
activity:     file format elf64-x86-64


Disassembly of section .init:

00000000004004c8 <_init>:
  4004c8:	48 83 ec 08          	sub    $0x8,%rsp
  4004cc:	48 8b 05 25 0b 20 00 	mov    0x200b25(%rip),%rax        # 600ff8 <__gmon_start__>
  4004d3:	48 85 c0             	test   %rax,%rax
  4004d6:	74 05                	je     4004dd <_init+0x15>
  4004d8:	e8 43 00 00 00       	callq  400520 <__gmon_start__@plt>
  4004dd:	48 83 c4 08          	add    $0x8,%rsp
  4004e1:	c3                   	retq   

Disassembly of section .plt:

00000000004004f0 <.plt>:
  4004f0:	ff 35 12 0b 20 00    	pushq  0x200b12(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4004f6:	ff 25 14 0b 20 00    	jmpq   *0x200b14(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4004fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400500 <puts@plt>:
  400500:	ff 25 12 0b 20 00    	jmpq   *0x200b12(%rip)        # 601018 <puts@GLIBC_2.2.5>
  400506:	68 00 00 00 00       	pushq  $0x0
  40050b:	e9 e0 ff ff ff       	jmpq   4004f0 <.plt>

0000000000400510 <__libc_start_main@plt>:
  400510:	ff 25 0a 0b 20 00    	jmpq   *0x200b0a(%rip)        # 601020 <__libc_start_main@GLIBC_2.2.5>
  400516:	68 01 00 00 00       	pushq  $0x1
  40051b:	e9 d0 ff ff ff       	jmpq   4004f0 <.plt>

0000000000400520 <__gmon_start__@plt>:
  400520:	ff 25 02 0b 20 00    	jmpq   *0x200b02(%rip)        # 601028 <__gmon_start__>
  400526:	68 02 00 00 00       	pushq  $0x2
  40052b:	e9 c0 ff ff ff       	jmpq   4004f0 <.plt>

0000000000400530 <gets@plt>:
  400530:	ff 25 fa 0a 20 00    	jmpq   *0x200afa(%rip)        # 601030 <gets@GLIBC_2.2.5>
  400536:	68 03 00 00 00       	pushq  $0x3
  40053b:	e9 b0 ff ff ff       	jmpq   4004f0 <.plt>

0000000000400540 <exit@plt>:
  400540:	ff 25 f2 0a 20 00    	jmpq   *0x200af2(%rip)        # 601038 <exit@GLIBC_2.2.5>
  400546:	68 04 00 00 00       	pushq  $0x4
  40054b:	e9 a0 ff ff ff       	jmpq   4004f0 <.plt>

0000000000400550 <fwrite@plt>:
  400550:	ff 25 ea 0a 20 00    	jmpq   *0x200aea(%rip)        # 601040 <fwrite@GLIBC_2.2.5>
  400556:	68 05 00 00 00       	pushq  $0x5
  40055b:	e9 90 ff ff ff       	jmpq   4004f0 <.plt>

Disassembly of section .text:

0000000000400560 <_start>:
  400560:	31 ed                	xor    %ebp,%ebp
  400562:	49 89 d1             	mov    %rdx,%r9
  400565:	5e                   	pop    %rsi
  400566:	48 89 e2             	mov    %rsp,%rdx
  400569:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40056d:	50                   	push   %rax
  40056e:	54                   	push   %rsp
  40056f:	49 c7 c0 00 08 40 00 	mov    $0x400800,%r8
  400576:	48 c7 c1 90 07 40 00 	mov    $0x400790,%rcx
  40057d:	48 c7 c7 16 07 40 00 	mov    $0x400716,%rdi
  400584:	e8 87 ff ff ff       	callq  400510 <__libc_start_main@plt>
  400589:	f4                   	hlt    
  40058a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400590 <deregister_tm_clones>:
  400590:	b8 5f 10 60 00       	mov    $0x60105f,%eax
  400595:	55                   	push   %rbp
  400596:	48 2d 58 10 60 00    	sub    $0x601058,%rax
  40059c:	48 83 f8 0e          	cmp    $0xe,%rax
  4005a0:	48 89 e5             	mov    %rsp,%rbp
  4005a3:	77 02                	ja     4005a7 <deregister_tm_clones+0x17>
  4005a5:	5d                   	pop    %rbp
  4005a6:	c3                   	retq   
  4005a7:	b8 00 00 00 00       	mov    $0x0,%eax
  4005ac:	48 85 c0             	test   %rax,%rax
  4005af:	74 f4                	je     4005a5 <deregister_tm_clones+0x15>
  4005b1:	5d                   	pop    %rbp
  4005b2:	bf 58 10 60 00       	mov    $0x601058,%edi
  4005b7:	ff e0                	jmpq   *%rax
  4005b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004005c0 <register_tm_clones>:
  4005c0:	b8 58 10 60 00       	mov    $0x601058,%eax
  4005c5:	55                   	push   %rbp
  4005c6:	48 2d 58 10 60 00    	sub    $0x601058,%rax
  4005cc:	48 c1 f8 03          	sar    $0x3,%rax
  4005d0:	48 89 e5             	mov    %rsp,%rbp
  4005d3:	48 89 c2             	mov    %rax,%rdx
  4005d6:	48 c1 ea 3f          	shr    $0x3f,%rdx
  4005da:	48 01 d0             	add    %rdx,%rax
  4005dd:	48 d1 f8             	sar    %rax
  4005e0:	75 02                	jne    4005e4 <register_tm_clones+0x24>
  4005e2:	5d                   	pop    %rbp
  4005e3:	c3                   	retq   
  4005e4:	ba 00 00 00 00       	mov    $0x0,%edx
  4005e9:	48 85 d2             	test   %rdx,%rdx
  4005ec:	74 f4                	je     4005e2 <register_tm_clones+0x22>
  4005ee:	5d                   	pop    %rbp
  4005ef:	48 89 c6             	mov    %rax,%rsi
  4005f2:	bf 58 10 60 00       	mov    $0x601058,%edi
  4005f7:	ff e2                	jmpq   *%rdx
  4005f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400600 <__do_global_dtors_aux>:
  400600:	80 3d 61 0a 20 00 00 	cmpb   $0x0,0x200a61(%rip)        # 601068 <completed.6355>
  400607:	75 11                	jne    40061a <__do_global_dtors_aux+0x1a>
  400609:	55                   	push   %rbp
  40060a:	48 89 e5             	mov    %rsp,%rbp
  40060d:	e8 7e ff ff ff       	callq  400590 <deregister_tm_clones>
  400612:	5d                   	pop    %rbp
  400613:	c6 05 4e 0a 20 00 01 	movb   $0x1,0x200a4e(%rip)        # 601068 <completed.6355>
  40061a:	f3 c3                	repz retq 
  40061c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400620 <frame_dummy>:
  400620:	48 83 3d f8 07 20 00 	cmpq   $0x0,0x2007f8(%rip)        # 600e20 <__JCR_END__>
  400627:	00 
  400628:	74 1e                	je     400648 <frame_dummy+0x28>
  40062a:	b8 00 00 00 00       	mov    $0x0,%eax
  40062f:	48 85 c0             	test   %rax,%rax
  400632:	74 14                	je     400648 <frame_dummy+0x28>
  400634:	55                   	push   %rbp
  400635:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  40063a:	48 89 e5             	mov    %rsp,%rbp
  40063d:	ff d0                	callq  *%rax
  40063f:	5d                   	pop    %rbp
  400640:	e9 7b ff ff ff       	jmpq   4005c0 <register_tm_clones>
  400645:	0f 1f 00             	nopl   (%rax)
  400648:	e9 73 ff ff ff       	jmpq   4005c0 <register_tm_clones>

000000000040064d <win>:
  40064d:	48 83 ec 08          	sub    $0x8,%rsp
  400651:	81 ff 13 52 01 00    	cmp    $0x15213,%edi
  400657:	75 0c                	jne    400665 <win+0x18>
  400659:	bf 20 08 40 00       	mov    $0x400820,%edi
  40065e:	e8 9d fe ff ff       	callq  400500 <puts@plt>
  400663:	eb 4b                	jmp    4006b0 <win+0x63>
  400665:	81 ff 13 82 01 00    	cmp    $0x18213,%edi
  40066b:	75 0c                	jne    400679 <win+0x2c>
  40066d:	bf b0 08 40 00       	mov    $0x4008b0,%edi
  400672:	e8 89 fe ff ff       	callq  400500 <puts@plt>
  400677:	eb 37                	jmp    4006b0 <win+0x63>
  400679:	81 ff 13 86 01 00    	cmp    $0x18613,%edi
  40067f:	75 0c                	jne    40068d <win+0x40>
  400681:	bf 40 08 40 00       	mov    $0x400840,%edi
  400686:	e8 75 fe ff ff       	callq  400500 <puts@plt>
  40068b:	eb 23                	jmp    4006b0 <win+0x63>
  40068d:	8b 05 dd 09 20 00    	mov    0x2009dd(%rip),%eax        # 601070 <mystery>
  400693:	3d 13 55 01 00       	cmp    $0x15513,%eax
  400698:	75 0c                	jne    4006a6 <win+0x59>
  40069a:	bf 68 08 40 00       	mov    $0x400868,%edi
  40069f:	e8 5c fe ff ff       	callq  400500 <puts@plt>
  4006a4:	eb 0a                	jmp    4006b0 <win+0x63>
  4006a6:	bf 88 08 40 00       	mov    $0x400888,%edi
  4006ab:	e8 50 fe ff ff       	callq  400500 <puts@plt>
  4006b0:	48 83 c4 08          	add    $0x8,%rsp
  4006b4:	c3                   	retq   

00000000004006b5 <solve>:
  4006b5:	48 83 ec 38          	sub    $0x38,%rsp
  4006b9:	48 c7 44 24 28 b4 00 	movq   $0xb4,0x28(%rsp)
  4006c0:	00 00 
  4006c2:	48 c7 44 24 08 af 00 	movq   $0xaf,0x8(%rsp)
  4006c9:	00 00 
  4006cb:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4006d0:	e8 6a 00 00 00       	callq  40073f <Gets>
  4006d5:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  4006da:	48 b8 31 35 32 31 33 	movabs $0x3331323531,%rax
  4006e1:	00 00 00 
  4006e4:	48 39 c2             	cmp    %rax,%rdx
  4006e7:	75 0a                	jne    4006f3 <solve+0x3e>
  4006e9:	bf 13 52 01 00       	mov    $0x15213,%edi
  4006ee:	e8 5a ff ff ff       	callq  40064d <win>
  4006f3:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  4006f8:	48 b8 31 38 32 31 33 	movabs $0x3331323831,%rax
  4006ff:	00 00 00 
  400702:	48 39 c2             	cmp    %rax,%rdx
  400705:	75 0a                	jne    400711 <solve+0x5c>
  400707:	bf 13 82 01 00       	mov    $0x18213,%edi
  40070c:	e8 3c ff ff ff       	callq  40064d <win>
  400711:	48 83 c4 38          	add    $0x38,%rsp
  400715:	c3                   	retq   

0000000000400716 <main>:
  400716:	48 83 ec 08          	sub    $0x8,%rsp
  40071a:	48 8b 35 2f 09 20 00 	mov    0x20092f(%rip),%rsi        # 601050 <stack_top>
  400721:	bf b5 06 40 00       	mov    $0x4006b5,%edi
  400726:	e8 4e 00 00 00       	callq  400779 <run_on_stack>
  40072b:	bf cb 08 40 00       	mov    $0x4008cb,%edi
  400730:	e8 cb fd ff ff       	callq  400500 <puts@plt>
  400735:	b8 00 00 00 00       	mov    $0x0,%eax
  40073a:	48 83 c4 08          	add    $0x8,%rsp
  40073e:	c3                   	retq   

000000000040073f <Gets>:
  40073f:	48 83 ec 08          	sub    $0x8,%rsp
  400743:	e8 e8 fd ff ff       	callq  400530 <gets@plt>
  400748:	48 85 c0             	test   %rax,%rax
  40074b:	75 25                	jne    400772 <Gets+0x33>
  40074d:	48 8b 0d 0c 09 20 00 	mov    0x20090c(%rip),%rcx        # 601060 <stderr@@GLIBC_2.2.5>
  400754:	ba 0d 00 00 00       	mov    $0xd,%edx
  400759:	be 01 00 00 00       	mov    $0x1,%esi
  40075e:	bf e8 08 40 00       	mov    $0x4008e8,%edi
  400763:	e8 e8 fd ff ff       	callq  400550 <fwrite@plt>
  400768:	bf 01 00 00 00       	mov    $0x1,%edi
  40076d:	e8 ce fd ff ff       	callq  400540 <exit@plt>
  400772:	48 83 c4 08          	add    $0x8,%rsp
  400776:	c3                   	retq   

0000000000400777 <gadget1>:
  400777:	5f                   	pop    %rdi
  400778:	c3                   	retq   

0000000000400779 <run_on_stack>:
  400779:	48 89 e2             	mov    %rsp,%rdx
  40077c:	48 8d 66 f8          	lea    -0x8(%rsi),%rsp
  400780:	52                   	push   %rdx
  400781:	ff d7                	callq  *%rdi
  400783:	5a                   	pop    %rdx
  400784:	48 89 d4             	mov    %rdx,%rsp
  400787:	c3                   	retq   
  400788:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40078f:	00 

0000000000400790 <__libc_csu_init>:
  400790:	41 57                	push   %r15
  400792:	41 89 ff             	mov    %edi,%r15d
  400795:	41 56                	push   %r14
  400797:	49 89 f6             	mov    %rsi,%r14
  40079a:	41 55                	push   %r13
  40079c:	49 89 d5             	mov    %rdx,%r13
  40079f:	41 54                	push   %r12
  4007a1:	4c 8d 25 68 06 20 00 	lea    0x200668(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  4007a8:	55                   	push   %rbp
  4007a9:	48 8d 2d 68 06 20 00 	lea    0x200668(%rip),%rbp        # 600e18 <__do_global_dtors_aux_fini_array_entry>
  4007b0:	53                   	push   %rbx
  4007b1:	4c 29 e5             	sub    %r12,%rbp
  4007b4:	31 db                	xor    %ebx,%ebx
  4007b6:	48 c1 fd 03          	sar    $0x3,%rbp
  4007ba:	48 83 ec 08          	sub    $0x8,%rsp
  4007be:	e8 05 fd ff ff       	callq  4004c8 <_init>
  4007c3:	48 85 ed             	test   %rbp,%rbp
  4007c6:	74 1e                	je     4007e6 <__libc_csu_init+0x56>
  4007c8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4007cf:	00 
  4007d0:	4c 89 ea             	mov    %r13,%rdx
  4007d3:	4c 89 f6             	mov    %r14,%rsi
  4007d6:	44 89 ff             	mov    %r15d,%edi
  4007d9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4007dd:	48 83 c3 01          	add    $0x1,%rbx
  4007e1:	48 39 eb             	cmp    %rbp,%rbx
  4007e4:	75 ea                	jne    4007d0 <__libc_csu_init+0x40>
  4007e6:	48 83 c4 08          	add    $0x8,%rsp
  4007ea:	5b                   	pop    %rbx
  4007eb:	5d                   	pop    %rbp
  4007ec:	41 5c                	pop    %r12
  4007ee:	41 5d                	pop    %r13
  4007f0:	41 5e                	pop    %r14
  4007f2:	41 5f                	pop    %r15
  4007f4:	c3                   	retq   
  4007f5:	90                   	nop
  4007f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4007fd:	00 00 00 

0000000000400800 <__libc_csu_fini>:
  400800:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400804 <_fini>:
  400804:	48 83 ec 08          	sub    $0x8,%rsp
  400808:	48 83 c4 08          	add    $0x8,%rsp
  40080c:	c3                   	retq   
