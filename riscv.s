.data
returnSize:
        .zero   4
LC0:
        .string "25016247489"
LC1:
        .string "12539220"
LC2:
        .string "524816033"
testCases:
        .word   LC0
        .word   LC1
        .word   LC2
result:
        .zero   1600
LC3:
        .string "Input: "
LC4:
        .string "No valid IP addresses found."
LC5:
        .string "Valid IP addresses:"
.text
main:
        addi    sp,sp,-112
        sw      ra,108(sp)
        sw      s0,104(sp)
        addi    s0,sp,112
        sw      zero,-20(s0)
        j       L2
L45:
        lui     a5,%hi(testCases)
        addi    a4,a5,%lo(testCases)
        lw      a5,-20(s0)
        slli    a5,a5,2
        add     a5,a4,a5
        lw      a5,0(a5)
        sw      a5,-96(s0)
        lw      a1,-96(s0)
        lui     a5,%hi(LC3)
        addi    a0,a5,%lo(LC3)
        la      a0,LC3
        li      a7,4
        ecall
        lw      a0,-96(s0)
        li      a7,4
        ecall
        la      a0,\n
        li      a7,4
        ecall
        lui     a5,%hi(returnSize)
        sw      zero,%lo(returnSize)(a5)
        sw      zero,-24(s0)
        j       L3
L4:
        lw      a5,-24(s0)
        addi    a5,a5,1
        sw      a5,-24(s0)
L3:
        lw      a5,-24(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a5,0(a5)
        bne     a5,zero,L4
        lw      a4,-24(s0)
        li      a5,3
        ble     a4,a5,L5
        lw      a4,-24(s0)
        li      a5,12
        ble     a4,a5,L6
L5:
        lui     a5,%hi(LC4)
        addi    a0,a5,%lo(LC4)
        la      a0,LC4
        li      a7,4
        ecall
        j       L7
L6:
        li      a5,1
        sw      a5,-28(s0)
        j       L8
L41:
        lw      a5,-96(s0)
        lbu     a4,0(a5)
        li      a5,48
        bne     a4,a5,L9
        lw      a4,-28(s0)
        li      a5,1
        bgt     a4,a5,L47
L9:
        sw      zero,-32(s0)
        sw      zero,-36(s0)
        j       L11
L12:
        lw      a4,-32(s0)
        mv      a5,a4
        slli    a5,a5,2
        add     a5,a5,a4
        slli    a5,a5,1
        mv      a3,a5
        lw      a5,-36(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a5,0(a5)
        addi    a5,a5,-48
        add     a5,a3,a5
        sw      a5,-32(s0)
        lw      a5,-36(s0)
        addi    a5,a5,1
        sw      a5,-36(s0)
L11:
        lw      a4,-36(s0)
        lw      a5,-28(s0)
        blt     a4,a5,L12
        lw      a4,-32(s0)
        li      a5,255
        bgt     a4,a5,L48
        lw      a5,-28(s0)
        sw      a5,-100(s0)
        lw      a5,-100(s0)
        addi    a5,a5,1
        sw      a5,-40(s0)
        j       L14
L39:
        lw      a5,-100(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a4,0(a5)
        li      a5,48
        bne     a4,a5,L15
        lw      a5,-100(s0)
        addi    a5,a5,1
        lw      a4,-40(s0)
        bgt     a4,a5,L49
L15:
        sw      zero,-44(s0)
        lw      a5,-100(s0)
        sw      a5,-48(s0)
        j       L17
L18:
        lw      a4,-44(s0)
        mv      a5,a4
        slli    a5,a5,2
        add     a5,a5,a4
        slli    a5,a5,1
        mv      a3,a5
        lw      a5,-48(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a5,0(a5)
        addi    a5,a5,-48
        add     a5,a3,a5
        sw      a5,-44(s0)
        lw      a5,-48(s0)
        addi    a5,a5,1
        sw      a5,-48(s0)
L17:
        lw      a4,-48(s0)
        lw      a5,-40(s0)
        blt     a4,a5,L18
        lw      a4,-44(s0)
        li      a5,255
        bgt     a4,a5,L50
        lw      a5,-40(s0)
        sw      a5,-104(s0)
        lw      a5,-104(s0)
        addi    a5,a5,1
        sw      a5,-52(s0)
        j       L20
L38:
        lw      a5,-104(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a4,0(a5)
        li      a5,48
        bne     a4,a5,L21
        lw      a5,-104(s0)
        addi    a5,a5,1
        lw      a4,-52(s0)
        bgt     a4,a5,L51
L21:
        sw      zero,-56(s0)
        lw      a5,-104(s0)
        sw      a5,-60(s0)
        j       L23
L24:
        lw      a4,-56(s0)
        mv      a5,a4
        slli    a5,a5,2
        add     a5,a5,a4
        slli    a5,a5,1
        mv      a3,a5
        lw      a5,-60(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a5,0(a5)
        addi    a5,a5,-48
        add     a5,a3,a5
        sw      a5,-56(s0)
        lw      a5,-60(s0)
        addi    a5,a5,1
        sw      a5,-60(s0)
L23:
        lw      a4,-60(s0)
        lw      a5,-52(s0)
        blt     a4,a5,L24
        lw      a4,-56(s0)
        li      a5,255
        bgt     a4,a5,L52
        lw      a5,-52(s0)
        sw      a5,-108(s0)
        lw      a4,-108(s0)
        lw      a5,-24(s0)
        bge     a4,a5,L22
        lw      a5,-108(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a4,0(a5)
        li      a5,48
        bne     a4,a5,L26
        lw      a5,-108(s0)
        addi    a5,a5,1
        lw      a4,-24(s0)
        bgt     a4,a5,L53
L26:
        sw      zero,-64(s0)
        lw      a5,-108(s0)
        sw      a5,-68(s0)
        j       L27
L28:
        lw      a4,-64(s0)
        mv      a5,a4
        slli    a5,a5,2
        add     a5,a5,a4
        slli    a5,a5,1
        mv      a3,a5
        lw      a5,-68(s0)
        lw      a4,-96(s0)
        add     a5,a4,a5
        lbu     a5,0(a5)
        addi    a5,a5,-48
        add     a5,a3,a5
        sw      a5,-64(s0)
        lw      a5,-68(s0)
        addi    a5,a5,1
        sw      a5,-68(s0)
L27:
        lw      a4,-68(s0)
        lw      a5,-24(s0)
        blt     a4,a5,L28
        lw      a4,-64(s0)
        li      a5,255
        bgt     a4,a5,L54
        lui     a5,%hi(returnSize)
        lw      a5,%lo(returnSize)(a5)
        slli    a4,a5,4
        lui     a5,%hi(result)
        addi    a5,a5,%lo(result)
        add     a5,a4,a5
        sw      a5,-112(s0)
        sw      zero,-72(s0)
        sw      zero,-76(s0)
        j       L30
L31:
        lw      a5,-76(s0)
        lw      a4,-96(s0)
        add     a4,a4,a5
        lw      a5,-72(s0)
        addi    a3,a5,1
        sw      a3,-72(s0)
        mv      a3,a5
        lw      a5,-112(s0)
        add     a5,a5,a3
        lbu     a4,0(a4)
        sb      a4,0(a5)
        lw      a5,-76(s0)
        addi    a5,a5,1
        sw      a5,-76(s0)
L30:
        lw      a4,-76(s0)
        lw      a5,-100(s0)
        blt     a4,a5,L31
        lw      a5,-72(s0)
        addi    a4,a5,1
        sw      a4,-72(s0)
        mv      a4,a5
        lw      a5,-112(s0)
        add     a5,a5,a4
        li      a4,46
        sb      a4,0(a5)
        lw      a5,-100(s0)
        sw      a5,-80(s0)
        j       L32
L33:
        lw      a5,-80(s0)
        lw      a4,-96(s0)
        add     a4,a4,a5
        lw      a5,-72(s0)
        addi    a3,a5,1
        sw      a3,-72(s0)
        mv      a3,a5
        lw      a5,-112(s0)
        add     a5,a5,a3
        lbu     a4,0(a4)
        sb      a4,0(a5)
        lw      a5,-80(s0)
        addi    a5,a5,1
        sw      a5,-80(s0)
L32:
        lw      a4,-80(s0)
        lw      a5,-104(s0)
        blt     a4,a5,L33
        lw      a5,-72(s0)
        addi    a4,a5,1
        sw      a4,-72(s0)
        mv      a4,a5
        lw      a5,-112(s0)
        add     a5,a5,a4
        li      a4,46
        sb      a4,0(a5)
        lw      a5,-104(s0)
        sw      a5,-84(s0)
        j       L34
L35:
        lw      a5,-84(s0)
        lw      a4,-96(s0)
        add     a4,a4,a5
        lw      a5,-72(s0)
        addi    a3,a5,1
        sw      a3,-72(s0)
        mv      a3,a5
        lw      a5,-112(s0)
        add     a5,a5,a3
        lbu     a4,0(a4)
        sb      a4,0(a5)
        lw      a5,-84(s0)
        addi    a5,a5,1
        sw      a5,-84(s0)
L34:
        lw      a4,-84(s0)
        lw      a5,-108(s0)
        blt     a4,a5,L35
        lw      a5,-72(s0)
        addi    a4,a5,1
        sw      a4,-72(s0)
        mv      a4,a5
        lw      a5,-112(s0)
        add     a5,a5,a4
        li      a4,46
        sb      a4,0(a5)
        lw      a5,-108(s0)
        sw      a5,-88(s0)
        j       L36
L37:
        lw      a5,-88(s0)
        lw      a4,-96(s0)
        add     a4,a4,a5
        lw      a5,-72(s0)
        addi    a3,a5,1
        sw      a3,-72(s0)
        mv      a3,a5
        lw      a5,-112(s0)
        add     a5,a5,a3
        lbu     a4,0(a4)
        sb      a4,0(a5)
        lw      a5,-88(s0)
        addi    a5,a5,1
        sw      a5,-88(s0)
L36:
        lw      a4,-88(s0)
        lw      a5,-24(s0)
        blt     a4,a5,L37
        lw      a5,-72(s0)
        lw      a4,-112(s0)
        add     a5,a4,a5
        sb      zero,0(a5)
        lui     a5,%hi(returnSize)
        lw      a5,%lo(returnSize)(a5)
        addi    a4,a5,1
        lui     a5,%hi(returnSize)
        sw      a4,%lo(returnSize)(a5)
        j       L22
L51:
        nop
        j       L22
L52:
        nop
        j       L22
L53:
        nop
        j       L22
L54:
        nop
L22:
        lw      a5,-52(s0)
        addi    a5,a5,1
        sw      a5,-52(s0)
L20:
        lw      a4,-52(s0)
        lw      a5,-24(s0)
        bge     a4,a5,L16
        lw      a5,-104(s0)
        addi    a5,a5,3
        lw      a4,-52(s0)
        ble     a4,a5,L38
        j       L16
L49:
        nop
        j       L16
L50:
        nop
L16:
        lw      a5,-40(s0)
        addi    a5,a5,1
        sw      a5,-40(s0)
L14:
        lw      a4,-40(s0)
        lw      a5,-24(s0)
        bge     a4,a5,L10
        lw      a5,-100(s0)
        addi    a5,a5,3
        lw      a4,-40(s0)
        ble     a4,a5,L39
        j       L10
L47:
        nop
        j       L10
L48:
        nop
L10:
        lw      a5,-28(s0)
        addi    a5,a5,1
        sw      a5,-28(s0)
L8:
        lw      a4,-28(s0)
        lw      a5,-24(s0)
        bge     a4,a5,L40
        lw      a4,-28(s0)
        li      a5,3
        ble     a4,a5,L41
L40:
        lui     a5,%hi(returnSize)
        lw      a5,%lo(returnSize)(a5)
        bne     a5,zero,L42
        lui     a5,%hi(LC4)
        addi    a0,a5,%lo(LC4)
        la      a0,LC4
        li      a7,4
        ecall
        j       L7
L42:
        lui     a5,%hi(LC5)
        addi    a0,a5,%lo(LC5)
        la      a0,LC5
        li      a7,4
        ecall
        sw      zero,-92(s0)
        j       L43
L44:
        lw      a5,-92(s0)
        slli    a4,a5,4
        lui     a5,%hi(result)
        addi    a5,a5,%lo(result)
        add     a5,a4,a5
        mv      a0,a5
        li      a7,4         
        ecall
        la      a0,\n
        li      a7,4
        ecall    
        lw      a5,-92(s0)
        addi    a5,a5,1
        sw      a5,-92(s0)
L43:
        lui     a5,%hi(returnSize)
        lw      a5,%lo(returnSize)(a5)
        lw      a4,-92(s0)
        blt     a4,a5,L44
        la      a0,\n
        li      a7,4
        ecall
L7:
        lw      a5,-20(s0)
        addi    a5,a5,1
        sw      a5,-20(s0)
L2:
        lw      a4,-20(s0)
        li      a5,2
        ble     a4,a5,L45
        li      a5,0
        mv      a0,a5
        lw      ra,108(sp)
        lw      s0,104(sp)
        addi    sp,sp,112
        
        li      a7, 10
        ecall