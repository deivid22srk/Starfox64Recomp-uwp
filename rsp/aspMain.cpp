#include "librecomp/rsp.hpp"
#include "librecomp/rsp_vu_impl.hpp"
RspExitReason aspMain(uint8_t* rdram, [[maybe_unused]] uint32_t ucode_addr) {
    uint32_t           r1 = 0,  r2 = 0,  r3 = 0,  r4 = 0,  r5 = 0,  r6 = 0,  r7 = 0;
    uint32_t  r8 = 0,  r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r15 = 0;
    uint32_t r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0;
    uint32_t r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    uint32_t dma_mem_address = 0, dma_dram_address = 0, jump_target = 0;
    const char * debug_file = NULL; int debug_line = 0;
    RSP rsp{};
    r1 = 0xFC0;
    // addi        $24, $zero, 0x320
    r24 = RSP_ADD32(0, 0X320);
    // addi        $23, $zero, 0xF90
    r23 = RSP_ADD32(0, 0XF90);
    // lw          $28, 0x30($1)
    r28 = RSP_MEM_W_LOAD(0X30, r1);
    // lw          $27, 0x34($1)
    r27 = RSP_MEM_W_LOAD(0X34, r1);
    // mfc0        $5, DPC_STATUS
    r5 = 0;
    // andi        $4, $5, 0x1
    r4 = r5 & 0X1;
    // beq         $4, $zero, L_10B4
    if (r4 == 0) {
        // andi        $4, $5, 0x100
        r4 = r5 & 0X100;
        goto L_10B4;
    }
    // andi        $4, $5, 0x100
    r4 = r5 & 0X100;
    // beq         $4, $zero, L_10B4
    if (r4 == 0) {
        // nop
    
        goto L_10B4;
    }
    // nop

L_10A8:
    // mfc0        $4, DPC_STATUS
    r4 = 0;
    // andi        $4, $4, 0x100
    r4 = r4 & 0X100;
    // bgtz        $4, L_10A8
    if (RSP_SIGNED(r4) > 0) {
        // nop
    
        goto L_10A8;
    }
L_10B4:
    // nop

    // jal         0x113C
    r31 = 0x10C0;
    // nop

    goto L_113C;
    // nop

L_10C0:
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
    // bne         $2, $zero, L_10C0
    if (r2 != 0) {
        // addi        $29, $zero, 0x340
        r29 = RSP_ADD32(0, 0X340);
        goto L_10C0;
    }
    // addi        $29, $zero, 0x340
    r29 = RSP_ADD32(0, 0X340);
    // mtc0        $zero, SP_SEMAPHORE
L_10D0:
    // lw          $26, 0x0($29)
    r26 = RSP_MEM_W_LOAD(0X0, r29);
    // lw          $25, 0x4($29)
    r25 = RSP_MEM_W_LOAD(0X4, r29);
    // srl         $1, $26, 23
    r1 = S32(U32(r26) >> 23);
    // andi        $1, $1, 0xFE
    r1 = r1 & 0XFE;
    // addi        $28, $28, 0x8
    r28 = RSP_ADD32(r28, 0X8);
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
    // addi        $29, $29, 0x8
    r29 = RSP_ADD32(r29, 0X8);
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // add         $2, $zero, $1
    r2 = RSP_ADD32(0, r1);
    // lh          $2, 0x10($2)
    r2 = RSP_MEM_H_LOAD(0X10, r2);
    // jr          $2
    jump_target = r2;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

    // break       0
    return RspExitReason::Broke;
L_1104:
    // bgtz        $30, L_10D0
    if (RSP_SIGNED(r30) > 0) {
        // nop
    
        goto L_10D0;
    }
    // nop

    // blez        $27, L_1124
    if (RSP_SIGNED(r27) <= 0) {
        // nop
    
        goto L_1124;
    }
    // nop

    // jal         0x113C
    r31 = 0x111C;
    // nop

    goto L_113C;
    // nop

L_111C:
    // j           L_10C0
    // nop

    goto L_10C0;
    // nop

L_1124:
    // ori         $1, $zero, 0x4000
    r1 = 0 | 0X4000;
    // mtc0        $1, SP_STATUS
    // break       0
    return RspExitReason::Broke;
    // nop

L_1134:
    // b           L_1134
    // nop

    goto L_1134;
    // nop

L_113C:
    // addi        $5, $ra, 0x0
    r5 = RSP_ADD32(r31, 0X0);
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
    // addi        $3, $27, 0x0
    r3 = RSP_ADD32(r27, 0X0);
    // addi        $4, $3, -0x80
    r4 = RSP_ADD32(r3, -0X80);
    // blez        $4, L_1158
    if (RSP_SIGNED(r4) <= 0) {
        // addi        $1, $zero, 0x340
        r1 = RSP_ADD32(0, 0X340);
        goto L_1158;
    }
    // addi        $1, $zero, 0x340
    r1 = RSP_ADD32(0, 0X340);
    // addi        $3, $zero, 0x80
    r3 = RSP_ADD32(0, 0X80);
L_1158:
    // addi        $30, $3, 0x0
    r30 = RSP_ADD32(r3, 0X0);
    // jal         0x1170
    r31 = 0x1164;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1170;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1164:
    // addi        $29, $zero, 0x340
    r29 = RSP_ADD32(0, 0X340);
    // jr          $5
    jump_target = r5;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

L_1170:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // bne         $4, $zero, L_1170
    if (r4 != 0) {
        // nop
    
        goto L_1170;
    }
    // nop

L_117C:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // bne         $4, $zero, L_117C
    if (r4 != 0) {
        // nop
    
        goto L_117C;
    }
    // nop

    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

L_119C:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // bne         $4, $zero, L_119C
    if (r4 != 0) {
        // nop
    
        goto L_119C;
    }
    // nop

L_11A8:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // bne         $4, $zero, L_11A8
    if (r4 != 0) {
        // nop
    
        goto L_11A8;
    }
    // nop

    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_WR_LEN
    DO_DMA_WRITE(r3);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

L_11C8:
    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
    // beq         $3, $zero, L_1104
    if (r3 == 0) {
        // andi        $2, $26, 0xFFFF
        r2 = r26 & 0XFFFF;
        goto L_1104;
    }
    // andi        $2, $26, 0xFFFF
    r2 = r26 & 0XFFFF;
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
L_11DC:
    // sdv         $v0[0], 0x0($2)
    rsp.SDV<0>(rsp.vpu.r[0], r2, 0X0);
    // sdv         $v0[0], 0x8($2)
    rsp.SDV<0>(rsp.vpu.r[0], r2, 0X1);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // bgtz        $3, L_11DC
    if (RSP_SIGNED(r3) > 0) {
        // addi        $3, $3, -0x10
        r3 = RSP_ADD32(r3, -0X10);
        goto L_11DC;
    }
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_11F8:
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // sh          $26, 0x0($24)
    RSP_MEM_H_STORE(0X0, r24, r26);
    // sh          $2, 0x2($24)
    RSP_MEM_H_STORE(0X2, r24, r2);
    // j           L_1104
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
    goto L_1104;
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
L_120C:
    // lhu         $1, 0x4($24)
    r1 = RSP_MEM_HU_LOAD(0X4, r24);
    // lhu         $4, 0x2($24)
    r4 = RSP_MEM_HU_LOAD(0X2, r24);
    // beq         $1, $zero, L_1104
    if (r1 == 0) {
        // andi        $3, $25, 0xFFFF
        r3 = r25 & 0XFFFF;
        goto L_1104;
    }
    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
L_1220:
    // lqv         $v1[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[1], r2, 0X0);
    // lqv         $v2[0], 0x0($3)
    rsp.LQV<0>(rsp.vpu.r[2], r3, 0X0);
    // ssv         $v1[0], 0x0($4)
    rsp.SSV<0>(rsp.vpu.r[1], r4, 0X0);
    // ssv         $v2[0], 0x2($4)
    rsp.SSV<0>(rsp.vpu.r[2], r4, 0X1);
    // ssv         $v1[2], 0x4($4)
    rsp.SSV<2>(rsp.vpu.r[1], r4, 0X2);
    // ssv         $v2[2], 0x6($4)
    rsp.SSV<2>(rsp.vpu.r[2], r4, 0X3);
    // ssv         $v1[4], 0x8($4)
    rsp.SSV<4>(rsp.vpu.r[1], r4, 0X4);
    // ssv         $v2[4], 0xA($4)
    rsp.SSV<4>(rsp.vpu.r[2], r4, 0X5);
    // ssv         $v1[6], 0xC($4)
    rsp.SSV<6>(rsp.vpu.r[1], r4, 0X6);
    // ssv         $v2[6], 0xE($4)
    rsp.SSV<6>(rsp.vpu.r[2], r4, 0X7);
    // ssv         $v1[8], 0x10($4)
    rsp.SSV<8>(rsp.vpu.r[1], r4, 0X8);
    // ssv         $v2[8], 0x12($4)
    rsp.SSV<8>(rsp.vpu.r[2], r4, 0X9);
    // ssv         $v1[10], 0x14($4)
    rsp.SSV<10>(rsp.vpu.r[1], r4, 0XA);
    // ssv         $v2[10], 0x16($4)
    rsp.SSV<10>(rsp.vpu.r[2], r4, 0XB);
    // ssv         $v1[12], 0x18($4)
    rsp.SSV<12>(rsp.vpu.r[1], r4, 0XC);
    // ssv         $v2[12], 0x1A($4)
    rsp.SSV<12>(rsp.vpu.r[2], r4, 0XD);
    // ssv         $v1[14], 0x1C($4)
    rsp.SSV<14>(rsp.vpu.r[1], r4, 0XE);
    // ssv         $v2[14], 0x1E($4)
    rsp.SSV<14>(rsp.vpu.r[2], r4, 0XF);
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
    // bgtz        $1, L_1220
    if (RSP_SIGNED(r1) > 0) {
        // addi        $4, $4, 0x20
        r4 = RSP_ADD32(r4, 0X20);
        goto L_1220;
    }
    // addi        $4, $4, 0x20
    r4 = RSP_ADD32(r4, 0X20);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_1284:
    // andi        $1, $25, 0xFFFF
    r1 = r25 & 0XFFFF;
    // beq         $1, $zero, L_1104
    if (r1 == 0) {
        // andi        $2, $26, 0xFFFF
        r2 = r26 & 0XFFFF;
        goto L_1104;
    }
    // andi        $2, $26, 0xFFFF
    r2 = r26 & 0XFFFF;
    // srl         $3, $25, 16
    r3 = S32(U32(r25) >> 16);
L_1294:
    // ldv         $v1[0], 0x0($2)
    rsp.LDV<0>(rsp.vpu.r[1], r2, 0X0);
    // ldv         $v2[0], 0x8($2)
    rsp.LDV<0>(rsp.vpu.r[2], r2, 0X1);
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // sdv         $v1[0], 0x0($3)
    rsp.SDV<0>(rsp.vpu.r[1], r3, 0X0);
    // sdv         $v2[0], 0x8($3)
    rsp.SDV<0>(rsp.vpu.r[2], r3, 0X1);
    // bgtz        $1, L_1294
    if (RSP_SIGNED(r1) > 0) {
        // addi        $3, $3, 0x10
        r3 = RSP_ADD32(r3, 0X10);
        goto L_1294;
    }
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_12BC:
    // sll         $1, $25, 8
    r1 = S32(r25) << 8;
    // srl         $1, $1, 8
    r1 = S32(U32(r1) >> 8);
    // j           L_1104
    // sw          $1, 0x10($24)
    RSP_MEM_W_STORE(0X10, r24, r1);
    goto L_1104;
    // sw          $1, 0x10($24)
    RSP_MEM_W_STORE(0X10, r24, r1);
L_12CC:
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
    // lhu         $21, 0x0($24)
    r21 = RSP_MEM_HU_LOAD(0X0, r24);
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // addi        $20, $21, 0x1
    r20 = RSP_ADD32(r21, 0X1);
    // lhu         $19, 0x2($24)
    r19 = RSP_MEM_HU_LOAD(0X2, r24);
    // vxor        $v13, $v13, $v13
    rsp.VXOR<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[13]);
    // vxor        $v14, $v14, $v14
    rsp.VXOR<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[14]);
    // lhu         $18, 0x4($24)
    r18 = RSP_MEM_HU_LOAD(0X4, r24);
    // vxor        $v15, $v15, $v15
    rsp.VXOR<0>(rsp.vpu.r[15], rsp.vpu.r[15], rsp.vpu.r[15]);
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // sll         $17, $25, 8
    r17 = S32(r25) << 8;
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // srl         $17, $17, 8
    r17 = S32(U32(r17) >> 8);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // sqv         $v27[0], 0x10($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X1);
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
    // bgtz        $1, L_1354
    if (RSP_SIGNED(r1) > 0) {
        // srl         $1, $26, 16
        r1 = S32(U32(r26) >> 16);
        goto L_1354;
    }
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x2
    r1 = r1 & 0X2;
    // beq         $zero, $1, L_1338
    if (0 == r1) {
        // addi        $2, $17, 0x0
        r2 = RSP_ADD32(r17, 0X0);
        goto L_1338;
    }
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // lw          $2, 0x10($24)
    r2 = RSP_MEM_W_LOAD(0X10, r24);
L_1338:
    // addi        $1, $19, 0x0
    r1 = RSP_ADD32(r19, 0X0);
    // jal         0x1170
    r31 = 0x1344;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_1170;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_1344:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1344
    if (r5 != 0) {
        // nop
    
        goto L_1344;
    }
    // nop

    // mtc0        $zero, SP_SEMAPHORE
L_1354:
    // addi        $16, $zero, 0x50
    r16 = RSP_ADD32(0, 0X50);
    // addi        $15, $zero, 0x3C0
    r15 = RSP_ADD32(0, 0X3C0);
    // ldv         $v25[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[25], r16, 0X0);
    // ldv         $v24[8], 0x0($16)
    rsp.LDV<8>(rsp.vpu.r[24], r16, 0X0);
    // ldv         $v23[0], 0x8($16)
    rsp.LDV<0>(rsp.vpu.r[23], r16, 0X1);
    // ldv         $v23[8], 0x8($16)
    rsp.LDV<8>(rsp.vpu.r[23], r16, 0X1);
    // lqv         $v27[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X1);
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
    // beq         $18, $zero, L_1530
    if (r18 == 0) {
        // ldv         $v1[0], 0x0($20)
        rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
        goto L_1530;
    }
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v16[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[16], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v15[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[15], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v14[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[14], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v13[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[13], r13, 0X2);
L_13FC:
    // addi        $20, $20, 0x9
    r20 = RSP_ADD32(r20, 0X9);
    // vmudn       $v30, $v3, $v23
    rsp.VMUDN<0>(rsp.vpu.r[30], rsp.vpu.r[3], rsp.vpu.r[23]);
    // addi        $21, $21, 0x9
    r21 = RSP_ADD32(r21, 0X9);
    // vmadn       $v30, $v4, $v23
    rsp.VMADN<0>(rsp.vpu.r[30], rsp.vpu.r[4], rsp.vpu.r[23]);
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
    // vmudn       $v29, $v5, $v23
    rsp.VMUDN<0>(rsp.vpu.r[29], rsp.vpu.r[5], rsp.vpu.r[23]);
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
    // vmadn       $v29, $v6, $v23
    rsp.VMADN<0>(rsp.vpu.r[29], rsp.vpu.r[6], rsp.vpu.r[23]);
    // blez        $14, L_142C
    if (RSP_SIGNED(r14) <= 0) {
        // andi        $11, $1, 0xF
        r11 = r1 & 0XF;
        goto L_142C;
    }
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
    // vmudm       $v30, $v30, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[22]);
    // vmudm       $v29, $v29, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[22]);
L_142C:
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
    // vmudh       $v2, $v21, $v27[6]
    rsp.VMUDH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[27]);
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
    // vmadh       $v2, $v20, $v27[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[27]);
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
    // vmadh       $v2, $v19, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[30]);
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
    // vmadh       $v2, $v18, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[30]);
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
    // vmadh       $v2, $v17, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[30]);
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
    // vmadh       $v2, $v16, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[30]);
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
    // vmadh       $v28, $v15, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[15], rsp.vpu.r[30]);
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
    // vmadh       $v2, $v14, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[30]);
    // vmadh       $v2, $v13, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[30]);
    // vmadh       $v2, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[30], rsp.vpu.r[31]);
    // vsar        $v26, $v7, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
    // vsar        $v28, $v7, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[7]);
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
    // vmadh       $v28, $v28, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[31]);
    // vmudh       $v2, $v19, $v29[0]
    rsp.VMUDH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[29]);
    // addi        $12, $13, -0x2
    r12 = RSP_ADD32(r13, -0X2);
    // vmadh       $v2, $v18, $v29[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[29]);
    // lrv         $v19[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[19], r12, 0X2);
    // vmadh       $v2, $v17, $v29[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v16, $v29[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[29]);
    // lrv         $v18[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[18], r12, 0X2);
    // vmadh       $v2, $v15, $v29[4]
    rsp.VMADH<12>(rsp.vpu.r[2], rsp.vpu.r[15], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v14, $v29[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[29]);
    // lrv         $v17[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[17], r12, 0X2);
    // vmadh       $v2, $v13, $v29[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v29, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[29], rsp.vpu.r[31]);
    // lrv         $v16[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[16], r12, 0X2);
    // vmadh       $v2, $v21, $v28[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[28]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v20, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[28]);
    // lrv         $v15[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[15], r12, 0X2);
    // vsar        $v26, $v7, $v27[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vsar        $v27, $v7, $v27[0]
    rsp.VSAR<8>(rsp.vpu.r[27], rsp.vpu.r[7]);
    // lrv         $v14[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[14], r12, 0X2);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // lrv         $v13[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[13], r12, 0X2);
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
    // vmadh       $v27, $v27, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
    // sdv         $v28[0], 0x0($19)
    rsp.SDV<0>(rsp.vpu.r[28], r19, 0X0);
    // sdv         $v28[8], 0x8($19)
    rsp.SDV<8>(rsp.vpu.r[28], r19, 0X1);
    // sdv         $v27[0], 0x10($19)
    rsp.SDV<0>(rsp.vpu.r[27], r19, 0X2);
    // sdv         $v27[8], 0x18($19)
    rsp.SDV<8>(rsp.vpu.r[27], r19, 0X3);
    // bgtz        $18, L_13FC
    if (RSP_SIGNED(r18) > 0) {
        // addi        $19, $19, 0x20
        r19 = RSP_ADD32(r19, 0X20);
        goto L_13FC;
    }
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
L_1530:
    // addi        $1, $19, -0x20
    r1 = RSP_ADD32(r19, -0X20);
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // jal         0x119C
    r31 = 0x1540;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_119C;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_1540:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1540
    if (r5 != 0) {
        // nop
    
        goto L_1540;
    }
    // nop

    // j           L_1104
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1104;
    // mtc0        $zero, SP_SEMAPHORE
L_1554:
    // lh          $8, 0x0($24)
    r8 = RSP_MEM_H_LOAD(0X0, r24);
    // lh          $19, 0x2($24)
    r19 = RSP_MEM_H_LOAD(0X2, r24);
    // lh          $18, 0x4($24)
    r18 = RSP_MEM_H_LOAD(0X4, r24);
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // sw          $2, 0x40($23)
    RSP_MEM_W_STORE(0X40, r23, r2);
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    // srl         $7, $26, 16
    r7 = S32(U32(r26) >> 16);
    // andi        $10, $7, 0x1
    r10 = r7 & 0X1;
    // bgtz        $10, L_15A0
    if (RSP_SIGNED(r10) > 0) {
        // nop
    
        goto L_15A0;
    }
    // nop

    // jal         0x1170
    r31 = 0x158C;
    // nop

    goto L_1170;
    // nop

L_158C:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_158C
    if (r1 != 0) {
        // nop
    
        goto L_158C;
    }
    // nop

    // j           L_15AC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_15AC;
    // mtc0        $zero, SP_SEMAPHORE
L_15A0:
    // sh          $zero, 0x8($23)
    RSP_MEM_H_STORE(0X8, r23, 0);
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
L_15AC:
    // andi        $10, $7, 0x2
    r10 = r7 & 0X2;
    // beq         $10, $zero, L_15CC
    if (r10 == 0) {
        // ldv         $v16[0], 0x0($23)
        rsp.LDV<0>(rsp.vpu.r[16], r23, 0X0);
        goto L_15CC;
    }
    // ldv         $v16[0], 0x0($23)
    rsp.LDV<0>(rsp.vpu.r[16], r23, 0X0);
    // addi        $8, $8, -0x4
    r8 = RSP_ADD32(r8, -0X4);
    // ssv         $v16[0], 0x0($8)
    rsp.SSV<0>(rsp.vpu.r[16], r8, 0X0);
    // ssv         $v16[4], 0x2($8)
    rsp.SSV<4>(rsp.vpu.r[16], r8, 0X1);
    // j           L_160C
    // nop

    goto L_160C;
    // nop

L_15CC:
    // andi        $10, $7, 0x4
    r10 = r7 & 0X4;
    // beq         $10, $zero, L_1604
    if (r10 == 0) {
        // nop
    
        goto L_1604;
    }
    // nop

    // addi        $8, $8, -0x10
    r8 = RSP_ADD32(r8, -0X10);
    // ssv         $v16[0], 0x0($8)
    rsp.SSV<0>(rsp.vpu.r[16], r8, 0X0);
    // ssv         $v16[0], 0x2($8)
    rsp.SSV<0>(rsp.vpu.r[16], r8, 0X1);
    // ssv         $v16[2], 0x4($8)
    rsp.SSV<2>(rsp.vpu.r[16], r8, 0X2);
    // ssv         $v16[2], 0x6($8)
    rsp.SSV<2>(rsp.vpu.r[16], r8, 0X3);
    // ssv         $v16[4], 0x8($8)
    rsp.SSV<4>(rsp.vpu.r[16], r8, 0X4);
    // ssv         $v16[4], 0xA($8)
    rsp.SSV<4>(rsp.vpu.r[16], r8, 0X5);
    // ssv         $v16[6], 0xC($8)
    rsp.SSV<6>(rsp.vpu.r[16], r8, 0X6);
    // ssv         $v16[6], 0xE($8)
    rsp.SSV<6>(rsp.vpu.r[16], r8, 0X7);
    // j           L_160C
    // nop

    goto L_160C;
    // nop

L_1604:
    // addi        $8, $8, -0x8
    r8 = RSP_ADD32(r8, -0X8);
    // sdv         $v16[0], 0x0($8)
    rsp.SDV<0>(rsp.vpu.r[16], r8, 0X0);
L_160C:
    // lsv         $v23[14], 0x8($23)
    rsp.LSV<14>(rsp.vpu.r[23], r23, 0X4);
    // ldv         $v16[0], 0x0($8)
    rsp.LDV<0>(rsp.vpu.r[16], r8, 0X0);
    // mtc2        $8, $v18[4]
    rsp.MTC2<4>(r8, rsp.vpu.r[18]);
    // addi        $10, $zero, 0x100
    r10 = RSP_ADD32(0, 0X100);
    // mtc2        $10, $v18[6]
    rsp.MTC2<6>(r10, rsp.vpu.r[18]);
    // mtc2        $26, $v18[8]
    rsp.MTC2<8>(r26, rsp.vpu.r[18]);
    // addi        $10, $zero, 0x40
    r10 = RSP_ADD32(0, 0X40);
    // mtc2        $10, $v18[10]
    rsp.MTC2<10>(r10, rsp.vpu.r[18]);
    // addi        $9, $zero, 0x60
    r9 = RSP_ADD32(0, 0X60);
    // lqv         $v31[0], 0x10($9)
    rsp.LQV<0>(rsp.vpu.r[31], r9, 0X1);
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v30[0], 0x20($9)
    rsp.LQV<0>(rsp.vpu.r[30], r9, 0X2);
    // lqv         $v29[0], 0x30($9)
    rsp.LQV<0>(rsp.vpu.r[29], r9, 0X3);
    // lqv         $v28[0], 0x40($9)
    rsp.LQV<0>(rsp.vpu.r[28], r9, 0X4);
    // lqv         $v27[0], 0x50($9)
    rsp.LQV<0>(rsp.vpu.r[27], r9, 0X5);
    // lqv         $v26[0], 0x60($9)
    rsp.LQV<0>(rsp.vpu.r[26], r9, 0X6);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v24[0], 0x70($9)
    rsp.LQV<0>(rsp.vpu.r[24], r9, 0X7);
    // addi        $21, $23, 0x20
    r21 = RSP_ADD32(r23, 0X20);
    // addi        $20, $23, 0x30
    r20 = RSP_ADD32(r23, 0X30);
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
    // ssv         $v23[7], 0x8($23)
    rsp.SSV<7>(rsp.vpu.r[23], r23, 0X4);
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
L_16D4:
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
    // ldv         $v15[0], 0x0($9)
    rsp.LDV<0>(rsp.vpu.r[15], r9, 0X0);
    // vmadh       $v23, $v31, $v22[7]
    rsp.VMADH<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[22]);
    // ldv         $v16[8], 0x0($13)
    rsp.LDV<8>(rsp.vpu.r[16], r13, 0X0);
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
    // ldv         $v15[8], 0x0($5)
    rsp.LDV<8>(rsp.vpu.r[15], r5, 0X0);
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
    // ldv         $v14[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[14], r16, 0X0);
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
    // ldv         $v13[0], 0x0($8)
    rsp.LDV<0>(rsp.vpu.r[13], r8, 0X0);
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
    // ldv         $v14[8], 0x0($12)
    rsp.LDV<8>(rsp.vpu.r[14], r12, 0X0);
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
    // ldv         $v13[8], 0x0($4)
    rsp.LDV<8>(rsp.vpu.r[13], r4, 0X0);
    // ldv         $v12[0], 0x0($15)
    rsp.LDV<0>(rsp.vpu.r[12], r15, 0X0);
    // ldv         $v11[0], 0x0($7)
    rsp.LDV<0>(rsp.vpu.r[11], r7, 0X0);
    // ldv         $v12[8], 0x0($11)
    rsp.LDV<8>(rsp.vpu.r[12], r11, 0X0);
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
    // ldv         $v11[8], 0x0($3)
    rsp.LDV<8>(rsp.vpu.r[11], r3, 0X0);
    // ldv         $v10[0], 0x0($14)
    rsp.LDV<0>(rsp.vpu.r[10], r14, 0X0);
    // ldv         $v9[0], 0x0($6)
    rsp.LDV<0>(rsp.vpu.r[9], r6, 0X0);
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
    // ldv         $v10[8], 0x0($10)
    rsp.LDV<8>(rsp.vpu.r[10], r10, 0X0);
    // vmulf       $v8, $v16, $v15
    rsp.VMULF<0>(rsp.vpu.r[8], rsp.vpu.r[16], rsp.vpu.r[15]);
    // ldv         $v9[8], 0x0($2)
    rsp.LDV<8>(rsp.vpu.r[9], r2, 0X0);
    // vmulf       $v7, $v14, $v13
    rsp.VMULF<0>(rsp.vpu.r[7], rsp.vpu.r[14], rsp.vpu.r[13]);
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
    // vmulf       $v6, $v12, $v11
    rsp.VMULF<0>(rsp.vpu.r[6], rsp.vpu.r[12], rsp.vpu.r[11]);
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
    // vmulf       $v5, $v10, $v9
    rsp.VMULF<0>(rsp.vpu.r[5], rsp.vpu.r[10], rsp.vpu.r[9]);
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
    // vadd        $v8, $v8, $v8[1q]
    rsp.VADD<3>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
    // vadd        $v7, $v7, $v7[1q]
    rsp.VADD<3>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
    // vadd        $v6, $v6, $v6[1q]
    rsp.VADD<3>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
    // vadd        $v5, $v5, $v5[1q]
    rsp.VADD<3>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
    // vadd        $v8, $v8, $v8[2h]
    rsp.VADD<6>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
    // vadd        $v7, $v7, $v7[2h]
    rsp.VADD<6>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
    // vadd        $v6, $v6, $v6[2h]
    rsp.VADD<6>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
    // vadd        $v5, $v5, $v5[2h]
    rsp.VADD<6>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
    // vmudn       $v4, $v29, $v8[0h]
    rsp.VMUDN<4>(rsp.vpu.r[4], rsp.vpu.r[29], rsp.vpu.r[8]);
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
    // vmadn       $v4, $v28, $v7[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[28], rsp.vpu.r[7]);
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
    // vmadn       $v4, $v27, $v6[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[27], rsp.vpu.r[6]);
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
    // vmadn       $v4, $v26, $v5[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[26], rsp.vpu.r[5]);
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
    // addi        $18, $18, -0x10
    r18 = RSP_ADD32(r18, -0X10);
    // sqv         $v4[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[4], r19, 0X0);
    // blez        $18, L_17D4
    if (RSP_SIGNED(r18) <= 0) {
        // lh          $2, 0xE($20)
        r2 = RSP_MEM_H_LOAD(0XE, r20);
        goto L_17D4;
    }
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
    // j           L_16D4
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    goto L_16D4;
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
L_17D4:
    // ssv         $v23[0], 0x8($23)
    rsp.SSV<0>(rsp.vpu.r[23], r23, 0X4);
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
    // lw          $2, 0x40($23)
    r2 = RSP_MEM_W_LOAD(0X40, r23);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // jal         0x119C
    r31 = 0x17F0;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_119C;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_17F0:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_17F0
    if (r5 != 0) {
        // nop
    
        goto L_17F0;
    }
    // nop

    // j           L_1104
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1104;
    // mtc0        $zero, SP_SEMAPHORE
L_1804:
    // srl         $15, $26, 16
    r15 = S32(U32(r26) >> 16);
    // andi        $15, $15, 0xFF
    r15 = r15 & 0XFF;
    // andi        $13, $26, 0xFFFF
    r13 = r26 & 0XFFFF;
    // srl         $14, $25, 16
    r14 = S32(U32(r25) >> 16);
L_1814:
    // addi        $15, $15, -0x1
    r15 = RSP_ADD32(r15, -0X1);
    // andi        $12, $25, 0xFFFF
    r12 = r25 & 0XFFFF;
L_181C:
    // lqv         $v1[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[1], r13, 0X0);
    // lqv         $v2[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[2], r13, 0X1);
    // addi        $12, $12, -0x20
    r12 = RSP_ADD32(r12, -0X20);
    // addi        $13, $13, 0x20
    r13 = RSP_ADD32(r13, 0X20);
    // sqv         $v1[0], 0x0($14)
    rsp.SQV<0>(rsp.vpu.r[1], r14, 0X0);
    // sqv         $v2[0], 0x10($14)
    rsp.SQV<0>(rsp.vpu.r[2], r14, 0X1);
    // bgtz        $12, L_181C
    if (RSP_SIGNED(r12) > 0) {
        // addi        $14, $14, 0x20
        r14 = RSP_ADD32(r14, 0X20);
        goto L_181C;
    }
    // addi        $14, $14, 0x20
    r14 = RSP_ADD32(r14, 0X20);
    // bgtz        $15, L_1814
    if (RSP_SIGNED(r15) > 0) {
        // nop
    
        goto L_1814;
    }
    // nop

    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_184C:
    // srl         $15, $26, 16
    r15 = S32(U32(r26) >> 16);
    // andi        $15, $15, 0xFF
    r15 = r15 & 0XFF;
    // andi        $13, $26, 0xFFFF
    r13 = r26 & 0XFFFF;
    // srl         $14, $25, 16
    r14 = S32(U32(r25) >> 16);
    // lqv         $v1[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[1], r13, 0X0);
    // lqv         $v2[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[2], r13, 0X1);
    // lqv         $v3[0], 0x20($13)
    rsp.LQV<0>(rsp.vpu.r[3], r13, 0X2);
    // lqv         $v4[0], 0x30($13)
    rsp.LQV<0>(rsp.vpu.r[4], r13, 0X3);
    // lqv         $v5[0], 0x40($13)
    rsp.LQV<0>(rsp.vpu.r[5], r13, 0X4);
    // lqv         $v6[0], 0x50($13)
    rsp.LQV<0>(rsp.vpu.r[6], r13, 0X5);
    // lqv         $v7[0], 0x60($13)
    rsp.LQV<0>(rsp.vpu.r[7], r13, 0X6);
    // lqv         $v8[0], 0x70($13)
    rsp.LQV<0>(rsp.vpu.r[8], r13, 0X7);
L_187C:
    // addi        $15, $15, -0x1
    r15 = RSP_ADD32(r15, -0X1);
    // sqv         $v1[0], 0x0($14)
    rsp.SQV<0>(rsp.vpu.r[1], r14, 0X0);
    // sqv         $v2[0], 0x10($14)
    rsp.SQV<0>(rsp.vpu.r[2], r14, 0X1);
    // sqv         $v3[0], 0x20($14)
    rsp.SQV<0>(rsp.vpu.r[3], r14, 0X2);
    // sqv         $v4[0], 0x30($14)
    rsp.SQV<0>(rsp.vpu.r[4], r14, 0X3);
    // sqv         $v5[0], 0x40($14)
    rsp.SQV<0>(rsp.vpu.r[5], r14, 0X4);
    // sqv         $v6[0], 0x50($14)
    rsp.SQV<0>(rsp.vpu.r[6], r14, 0X5);
    // sqv         $v7[0], 0x60($14)
    rsp.SQV<0>(rsp.vpu.r[7], r14, 0X6);
    // sqv         $v8[0], 0x70($14)
    rsp.SQV<0>(rsp.vpu.r[8], r14, 0X7);
    // bgtz        $15, L_187C
    if (RSP_SIGNED(r15) > 0) {
        // addi        $14, $14, 0x80
        r14 = RSP_ADD32(r14, 0X80);
        goto L_187C;
    }
    // addi        $14, $14, 0x80
    r14 = RSP_ADD32(r14, 0X80);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_18B0:
    // andi        $12, $26, 0xFFFF
    r12 = r26 & 0XFFFF;
    // andi        $14, $25, 0xFFFF
    r14 = r25 & 0XFFFF;
    // srl         $13, $25, 16
    r13 = S32(U32(r25) >> 16);
L_18BC:
    // lsv         $v1[0], 0x0($13)
    rsp.LSV<0>(rsp.vpu.r[1], r13, 0X0);
    // lsv         $v2[0], 0x8($13)
    rsp.LSV<0>(rsp.vpu.r[2], r13, 0X4);
    // lsv         $v3[0], 0x10($13)
    rsp.LSV<0>(rsp.vpu.r[3], r13, 0X8);
    // lsv         $v4[0], 0x18($13)
    rsp.LSV<0>(rsp.vpu.r[4], r13, 0XC);
    // lsv         $v1[2], 0x4($13)
    rsp.LSV<2>(rsp.vpu.r[1], r13, 0X2);
    // lsv         $v2[2], 0xC($13)
    rsp.LSV<2>(rsp.vpu.r[2], r13, 0X6);
    // lsv         $v3[2], 0x14($13)
    rsp.LSV<2>(rsp.vpu.r[3], r13, 0XA);
    // lsv         $v4[2], 0x1C($13)
    rsp.LSV<2>(rsp.vpu.r[4], r13, 0XE);
    // addi        $13, $13, 0x20
    r13 = RSP_ADD32(r13, 0X20);
    // slv         $v1[0], 0x0($14)
    rsp.SLV<0>(rsp.vpu.r[1], r14, 0X0);
    // slv         $v2[0], 0x4($14)
    rsp.SLV<0>(rsp.vpu.r[2], r14, 0X1);
    // slv         $v3[0], 0x8($14)
    rsp.SLV<0>(rsp.vpu.r[3], r14, 0X2);
    // addi        $12, $12, -0x8
    r12 = RSP_ADD32(r12, -0X8);
    // slv         $v4[0], 0xC($14)
    rsp.SLV<0>(rsp.vpu.r[4], r14, 0X3);
    // bgtz        $12, L_18BC
    if (RSP_SIGNED(r12) > 0) {
        // addi        $14, $14, 0x10
        r14 = RSP_ADD32(r14, 0X10);
        goto L_18BC;
    }
    // addi        $14, $14, 0x10
    r14 = RSP_ADD32(r14, 0X10);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_1904:
    // vxor        $v4, $v4, $v4
    rsp.VXOR<0>(rsp.vpu.r[4], rsp.vpu.r[4], rsp.vpu.r[4]);
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // lqv         $v3[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[3], 0, 0X0);
    // add         $21, $21, $21
    r21 = RSP_ADD32(r21, r21);
    // mtc2        $21, $v4[0]
    rsp.MTC2<0>(r21, rsp.vpu.r[4]);
    // mtc2        $21, $v4[2]
    rsp.MTC2<2>(r21, rsp.vpu.r[4]);
    // srl         $12, $26, 12
    r12 = S32(U32(r26) >> 12);
    // andi        $19, $12, 0xFF0
    r19 = r12 & 0XFF0;
    // add         $22, $22, $22
    r22 = RSP_ADD32(r22, r22);
    // mtc2        $22, $v4[4]
    rsp.MTC2<4>(r22, rsp.vpu.r[4]);
    // mtc2        $22, $v4[6]
    rsp.MTC2<6>(r22, rsp.vpu.r[4]);
    // srl         $12, $25, 20
    r12 = S32(U32(r25) >> 20);
    // andi        $14, $12, 0xFF0
    r14 = r12 & 0XFF0;
    // add         $11, $11, $11
    r11 = RSP_ADD32(r11, r11);
    // mtc2        $11, $v4[8]
    rsp.MTC2<8>(r11, rsp.vpu.r[4]);
    // mtc2        $11, $v4[10]
    rsp.MTC2<10>(r11, rsp.vpu.r[4]);
    // srl         $12, $25, 12
    r12 = S32(U32(r25) >> 12);
    // andi        $15, $12, 0xFF0
    r15 = r12 & 0XFF0;
    // srl         $12, $25, 4
    r12 = S32(U32(r25) >> 4);
    // andi        $16, $12, 0xFF0
    r16 = r12 & 0XFF0;
    // sll         $12, $25, 4
    r12 = S32(r25) << 4;
    // andi        $17, $12, 0xFF0
    r17 = r12 & 0XFF0;
    // andi        $12, $26, 0x2
    r12 = r26 & 0X2;
    // lhu         $12, 0xE0($12)
    r12 = RSP_MEM_HU_LOAD(0XE0, r12);
    // mtc2        $12, $v2[0]
    rsp.MTC2<0>(r12, rsp.vpu.r[2]);
    // andi        $12, $26, 0x1
    r12 = r26 & 0X1;
    // sll         $12, $12, 1
    r12 = S32(r12) << 1;
    // lhu         $12, 0xE0($12)
    r12 = RSP_MEM_HU_LOAD(0XE0, r12);
    // mtc2        $12, $v2[2]
    rsp.MTC2<2>(r12, rsp.vpu.r[2]);
    // srl         $12, $26, 8
    r12 = S32(U32(r26) >> 8);
    // andi        $20, $12, 0xFF
    r20 = r12 & 0XFF;
    // vadd        $v0, $v0, $v0
    rsp.VADD<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // andi        $10, $26, 0x4
    r10 = r26 & 0X4;
    // lqv         $v8[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[8], r19, 0X0);
L_198C:
    // lqv         $v15[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[15], r19, 0X1);
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
    // vmudm       $v9, $v8, $v1[0]
    rsp.VMUDM<8>(rsp.vpu.r[9], rsp.vpu.r[8], rsp.vpu.r[1]);
    // vmudm       $v10, $v8, $v1[2]
    rsp.VMUDM<10>(rsp.vpu.r[10], rsp.vpu.r[8], rsp.vpu.r[1]);
    // addi        $20, $20, -0x10
    r20 = RSP_ADD32(r20, -0X10);
    // lqv         $v11[0], 0x0($14)
    rsp.LQV<0>(rsp.vpu.r[11], r14, 0X0);
    // lqv         $v12[0], 0x0($15)
    rsp.LQV<0>(rsp.vpu.r[12], r15, 0X0);
    // vmudm       $v16, $v15, $v1[1]
    rsp.VMUDM<9>(rsp.vpu.r[16], rsp.vpu.r[15], rsp.vpu.r[1]);
    // vmudm       $v17, $v15, $v1[3]
    rsp.VMUDM<11>(rsp.vpu.r[17], rsp.vpu.r[15], rsp.vpu.r[1]);
    // lqv         $v18[0], 0x10($14)
    rsp.LQV<0>(rsp.vpu.r[18], r14, 0X1);
    // lqv         $v19[0], 0x10($15)
    rsp.LQV<0>(rsp.vpu.r[19], r15, 0X1);
    // vxor        $v9, $v9, $v2[0]
    rsp.VXOR<8>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[2]);
    // vxor        $v10, $v10, $v2[1]
    rsp.VXOR<9>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[2]);
    // lqv         $v13[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[13], r16, 0X0);
    // lqv         $v14[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[14], r17, 0X0);
    // vadd        $v11, $v11, $v9
    rsp.VADD<0>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[9]);
    // vadd        $v12, $v12, $v10
    rsp.VADD<0>(rsp.vpu.r[12], rsp.vpu.r[12], rsp.vpu.r[10]);
    // vmudm       $v9, $v9, $v1[4]
    rsp.VMUDM<12>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[1]);
    // vmudm       $v10, $v10, $v1[4]
    rsp.VMUDM<12>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[1]);
    // vxor        $v16, $v16, $v2[0]
    rsp.VXOR<8>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[2]);
    // vxor        $v17, $v17, $v2[1]
    rsp.VXOR<9>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[2]);
    // lqv         $v20[0], 0x10($16)
    rsp.LQV<0>(rsp.vpu.r[20], r16, 0X1);
    // lqv         $v21[0], 0x10($17)
    rsp.LQV<0>(rsp.vpu.r[21], r17, 0X1);
    // vadd        $v18, $v18, $v16
    rsp.VADD<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[16]);
    // vadd        $v19, $v19, $v17
    rsp.VADD<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[17]);
    // vmudm       $v16, $v16, $v1[5]
    rsp.VMUDM<13>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[1]);
    // vmudm       $v17, $v17, $v1[5]
    rsp.VMUDM<13>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[1]);
    // sqv         $v11[0], 0x0($14)
    rsp.SQV<0>(rsp.vpu.r[11], r14, 0X0);
    // bne         $10, $zero, L_1A54
    if (r10 != 0) {
        // sqv         $v12[0], 0x0($15)
        rsp.SQV<0>(rsp.vpu.r[12], r15, 0X0);
        goto L_1A54;
    }
    // sqv         $v12[0], 0x0($15)
    rsp.SQV<0>(rsp.vpu.r[12], r15, 0X0);
    // vadd        $v13, $v13, $v9
    rsp.VADD<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[9]);
    // vadd        $v14, $v14, $v10
    rsp.VADD<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[10]);
    // sqv         $v18[0], 0x10($14)
    rsp.SQV<0>(rsp.vpu.r[18], r14, 0X1);
    // sqv         $v19[0], 0x10($15)
    rsp.SQV<0>(rsp.vpu.r[19], r15, 0X1);
    // vadd        $v20, $v20, $v16
    rsp.VADD<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[16]);
    // vadd        $v21, $v21, $v17
    rsp.VADD<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[17]);
L_1A1C:
    // addi        $14, $14, 0x20
    r14 = RSP_ADD32(r14, 0X20);
    // sqv         $v13[0], 0x0($16)
    rsp.SQV<0>(rsp.vpu.r[13], r16, 0X0);
    // sqv         $v14[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[14], r17, 0X0);
    // addi        $15, $15, 0x20
    r15 = RSP_ADD32(r15, 0X20);
    // lqv         $v8[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[8], r19, 0X0);
    // sqv         $v20[0], 0x10($16)
    rsp.SQV<0>(rsp.vpu.r[20], r16, 0X1);
    // sqv         $v21[0], 0x10($17)
    rsp.SQV<0>(rsp.vpu.r[21], r17, 0X1);
    // addi        $16, $16, 0x20
    r16 = RSP_ADD32(r16, 0X20);
    // vaddc       $v1, $v1, $v4
    rsp.VADDC<0>(rsp.vpu.r[1], rsp.vpu.r[1], rsp.vpu.r[4]);
    // addi        $17, $17, 0x20
    r17 = RSP_ADD32(r17, 0X20);
    // bgtz        $20, L_198C
    if (RSP_SIGNED(r20) > 0) {
        // vadd        $v0, $v0, $v0
        rsp.VADD<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
        goto L_198C;
    }
    // vadd        $v0, $v0, $v0
    rsp.VADD<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // j           L_1104
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    goto L_1104;
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
L_1A54:
    // vadd        $v13, $v13, $v10
    rsp.VADD<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[10]);
    // vadd        $v14, $v14, $v9
    rsp.VADD<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[9]);
    // sqv         $v18[0], 0x10($14)
    rsp.SQV<0>(rsp.vpu.r[18], r14, 0X1);
    // sqv         $v19[0], 0x10($15)
    rsp.SQV<0>(rsp.vpu.r[19], r15, 0X1);
    // vadd        $v20, $v20, $v17
    rsp.VADD<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[17]);
    // j           L_1A1C
    // vadd        $v21, $v21, $v16
    rsp.VADD<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[16]);
    goto L_1A1C;
    // vadd        $v21, $v21, $v16
    rsp.VADD<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[16]);
L_1A70:
    // vxor        $v1, $v1, $v1
    rsp.VXOR<0>(rsp.vpu.r[1], rsp.vpu.r[1], rsp.vpu.r[1]);
    // andi        $11, $26, 0xFFFF
    r11 = r26 & 0XFFFF;
    // srl         $12, $26, 8
    r12 = S32(U32(r26) >> 8);
    // andi        $12, $12, 0xFF00
    r12 = r12 & 0XFF00;
    // mtc2        $12, $v1[8]
    rsp.MTC2<8>(r12, rsp.vpu.r[1]);
    // add         $12, $12, $11
    r12 = RSP_ADD32(r12, r11);
    // mtc2        $12, $v1[10]
    rsp.MTC2<10>(r12, rsp.vpu.r[1]);
    // srl         $21, $25, 16
    r21 = S32(U32(r25) >> 16);
    // j           L_1104
    // andi        $22, $25, 0xFFFF
    r22 = r25 & 0XFFFF;
    goto L_1104;
    // andi        $22, $25, 0xFFFF
    r22 = r25 & 0XFFFF;
L_1A98:
    // srl         $12, $25, 16
    r12 = S32(U32(r25) >> 16);
    // mtc2        $12, $v1[0]
    rsp.MTC2<0>(r12, rsp.vpu.r[1]);
    // add         $12, $12, $21
    r12 = RSP_ADD32(r12, r21);
    // mtc2        $12, $v1[2]
    rsp.MTC2<2>(r12, rsp.vpu.r[1]);
    // andi        $12, $25, 0xFFFF
    r12 = r25 & 0XFFFF;
    // mtc2        $12, $v1[4]
    rsp.MTC2<4>(r12, rsp.vpu.r[1]);
    // add         $12, $12, $22
    r12 = RSP_ADD32(r12, r22);
    // j           L_1104
    // mtc2        $12, $v1[6]
    rsp.MTC2<6>(r12, rsp.vpu.r[1]);
    goto L_1104;
    // mtc2        $12, $v1[6]
    rsp.MTC2<6>(r12, rsp.vpu.r[1]);
L_1ABC:
    // srl         $3, $26, 12
    r3 = S32(U32(r26) >> 12);
    // andi        $3, $3, 0xFF0
    r3 = r3 & 0XFF0;
    // andi        $1, $26, 0xFFFF
    r1 = r26 & 0XFFFF;
L_1AC8:
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    goto do_indirect_jump;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
L_1AD4:
    // jal         0x1ABC
    r31 = 0x1ADC;
    // nop

    goto L_1ABC;
    // nop

L_1ADC:
    // jal         0x1170
    r31 = 0x1AE4;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1170;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1AE4:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_1AE4
    if (r1 != 0) {
        // nop
    
        goto L_1AE4;
    }
    // nop

    // j           L_1104
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1104;
    // mtc0        $zero, SP_SEMAPHORE
L_1AF8:
    // jal         0x1ABC
    r31 = 0x1B00;
    // nop

    goto L_1ABC;
    // nop

L_1B00:
    // jal         0x119C
    r31 = 0x1B08;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_119C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1B08:
    // j           L_1AE4
    // nop

    goto L_1AE4;
    // nop

L_1B10:
    // jal         0x1AC8
    r31 = 0x1B18;
    // addi        $1, $zero, 0x3C0
    r1 = RSP_ADD32(0, 0X3C0);
    goto L_1AC8;
    // addi        $1, $zero, 0x3C0
    r1 = RSP_ADD32(0, 0X3C0);
L_1B18:
    // andi        $3, $26, 0xFFFF
    r3 = r26 & 0XFFFF;
    // jal         0x1170
    r31 = 0x1B24;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1170;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1B24:
    // j           L_1AE4
    // nop

    goto L_1AE4;
    // nop

L_1B2C:
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
    // srl         $18, $26, 12
    r18 = S32(U32(r26) >> 12);
    // andi        $18, $18, 0xFF0
    r18 = r18 & 0XFF0;
    // andi        $19, $25, 0xFFFF
    r19 = r25 & 0XFFFF;
    // srl         $20, $25, 16
    r20 = S32(U32(r25) >> 16);
    // andi        $17, $26, 0xFFFF
    r17 = r26 & 0XFFFF;
    // mtc2        $17, $v30[0]
    rsp.MTC2<0>(r17, rsp.vpu.r[30]);
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
    // lqv         $v29[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[29], r20, 0X0);
    // lqv         $v26[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[26], r19, 0X1);
    // lqv         $v28[0], 0x10($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X1);
L_1B58:
    // vmulf       $v27, $v27, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
    // vmacf       $v27, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[27], rsp.vpu.r[29], rsp.vpu.r[30]);
    // addi        $20, $20, 0x20
    r20 = RSP_ADD32(r20, 0X20);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // vmulf       $v26, $v26, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[31]);
    // lqv         $v29[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[29], r20, 0X0);
    // vmacf       $v26, $v28, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[26], rsp.vpu.r[28], rsp.vpu.r[30]);
    // lqv         $v28[0], 0x10($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X1);
    // sqv         $v26[0], 0x10($19)
    rsp.SQV<0>(rsp.vpu.r[26], r19, 0X1);
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
    // bgtz        $18, L_1B58
    if (RSP_SIGNED(r18) > 0) {
        // lqv         $v26[0], 0x10($19)
        rsp.LQV<0>(rsp.vpu.r[26], r19, 0X1);
        goto L_1B58;
    }
    // lqv         $v26[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[26], r19, 0X1);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_1B98:
    // lhu         $13, 0x0($24)
    r13 = RSP_MEM_HU_LOAD(0X0, r24);
    // vxor        $v2, $v2, $v2
    rsp.VXOR<0>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[2]);
    // lhu         $14, 0x2($24)
    r14 = RSP_MEM_HU_LOAD(0X2, r24);
    // vxor        $v3, $v3, $v3
    rsp.VXOR<0>(rsp.vpu.r[3], rsp.vpu.r[3], rsp.vpu.r[3]);
    // lhu         $12, 0x4($24)
    r12 = RSP_MEM_HU_LOAD(0X4, r24);
    // sll         $17, $25, 8
    r17 = S32(r25) << 8;
    // srl         $17, $17, 8
    r17 = S32(U32(r17) >> 8);
    // sqv         $v2[0], 0x0($14)
    rsp.SQV<0>(rsp.vpu.r[2], r14, 0X0);
    // sqv         $v3[0], 0x10($14)
    rsp.SQV<0>(rsp.vpu.r[3], r14, 0X1);
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
    // bgtz        $1, L_1BF8
    if (RSP_SIGNED(r1) > 0) {
        // srl         $1, $26, 16
        r1 = S32(U32(r26) >> 16);
        goto L_1BF8;
    }
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x2
    r1 = r1 & 0X2;
    // beq         $zero, $1, L_1BDC
    if (0 == r1) {
        // addi        $2, $17, 0x0
        r2 = RSP_ADD32(r17, 0X0);
        goto L_1BDC;
    }
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // lw          $2, 0x10($24)
    r2 = RSP_MEM_W_LOAD(0X10, r24);
L_1BDC:
    // addi        $1, $14, 0x0
    r1 = RSP_ADD32(r14, 0X0);
    // jal         0x1170
    r31 = 0x1BE8;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_1170;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_1BE8:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1BE8
    if (r5 != 0) {
        // nop
    
        goto L_1BE8;
    }
    // nop

    // mtc0        $zero, SP_SEMAPHORE
L_1BF8:
    // addi        $14, $14, 0x20
    r14 = RSP_ADD32(r14, 0X20);
    // beq         $12, $zero, L_1C24
    if (r12 == 0) {
        // nop
    
        goto L_1C24;
    }
    // nop

L_1C04:
    // lpv         $v2[0], 0x0($13)
    rsp.LPV<0>(rsp.vpu.r[2], r13, 0X0);
    // lpv         $v3[0], 0x8($13)
    rsp.LPV<0>(rsp.vpu.r[3], r13, 0X1);
    // addi        $13, $13, 0x10
    r13 = RSP_ADD32(r13, 0X10);
    // addi        $12, $12, -0x20
    r12 = RSP_ADD32(r12, -0X20);
    // sqv         $v2[0], 0x0($14)
    rsp.SQV<0>(rsp.vpu.r[2], r14, 0X0);
    // sqv         $v3[0], 0x10($14)
    rsp.SQV<0>(rsp.vpu.r[3], r14, 0X1);
    // bgtz        $12, L_1C04
    if (RSP_SIGNED(r12) > 0) {
        // addi        $14, $14, 0x20
        r14 = RSP_ADD32(r14, 0X20);
        goto L_1C04;
    }
    // addi        $14, $14, 0x20
    r14 = RSP_ADD32(r14, 0X20);
L_1C24:
    // addi        $1, $14, -0x20
    r1 = RSP_ADD32(r14, -0X20);
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // jal         0x119C
    r31 = 0x1C34;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_119C;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_1C34:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1C34
    if (r5 != 0) {
        // nop
    
        goto L_1C34;
    }
    // nop

    // j           L_1104
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1104;
    // mtc0        $zero, SP_SEMAPHORE
L_1C48:
    // andi        $12, $26, 0xFFFF
    r12 = r26 & 0XFFFF;
    // srl         $13, $25, 16
    r13 = S32(U32(r25) >> 16);
    // srl         $15, $26, 4
    r15 = S32(U32(r26) >> 4);
    // andi        $15, $15, 0xF000
    r15 = r15 & 0XF000;
    // mtc2        $15, $v3[2]
    rsp.MTC2<2>(r15, rsp.vpu.r[3]);
    // srl         $15, $26, 20
    r15 = S32(U32(r26) >> 20);
    // andi        $15, $15, 0xF
    r15 = r15 & 0XF;
    // mtc2        $15, $v3[0]
    rsp.MTC2<0>(r15, rsp.vpu.r[3]);
L_1C68:
    // lqv         $v1[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[1], r13, 0X0);
    // lqv         $v2[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[2], r13, 0X1);
    // vmudm       $v4, $v1, $v3[1]
    rsp.VMUDM<9>(rsp.vpu.r[4], rsp.vpu.r[1], rsp.vpu.r[3]);
    // vmadh       $v4, $v1, $v3[0]
    rsp.VMADH<8>(rsp.vpu.r[4], rsp.vpu.r[1], rsp.vpu.r[3]);
    // vmudm       $v5, $v2, $v3[1]
    rsp.VMUDM<9>(rsp.vpu.r[5], rsp.vpu.r[2], rsp.vpu.r[3]);
    // vmadh       $v5, $v2, $v3[0]
    rsp.VMADH<8>(rsp.vpu.r[5], rsp.vpu.r[2], rsp.vpu.r[3]);
    // sqv         $v4[0], 0x0($13)
    rsp.SQV<0>(rsp.vpu.r[4], r13, 0X0);
    // sqv         $v5[0], 0x10($13)
    rsp.SQV<0>(rsp.vpu.r[5], r13, 0X1);
    // addi        $12, $12, -0x20
    r12 = RSP_ADD32(r12, -0X20);
    // bgtz        $12, L_1C68
    if (RSP_SIGNED(r12) > 0) {
        // addi        $13, $13, 0x20
        r13 = RSP_ADD32(r13, 0X20);
        goto L_1C68;
    }
    // addi        $13, $13, 0x20
    r13 = RSP_ADD32(r13, 0X20);
    // j           L_1104
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    goto L_1104;
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
L_1C9C:
    // andi        $12, $26, 0xFFFF
    r12 = r26 & 0XFFFF;
    // srl         $13, $25, 16
    r13 = S32(U32(r25) >> 16);
    // addi        $14, $13, 0x0
    r14 = RSP_ADD32(r13, 0X0);
    // andi        $15, $25, 0xFFFF
    r15 = r25 & 0XFFFF;
    // srl         $11, $26, 16
    r11 = S32(U32(r26) >> 16);
    // andi        $11, $11, 0xFF
    r11 = r11 & 0XFF;
    // add         $15, $15, $11
    r15 = RSP_ADD32(r15, r11);
    // ldv         $v11[0], 0x0($15)
    rsp.LDV<0>(rsp.vpu.r[11], r15, 0X0);
    // ldv         $v12[0], 0x10($15)
    rsp.LDV<0>(rsp.vpu.r[12], r15, 0X2);
    // ldv         $v13[0], 0x20($15)
    rsp.LDV<0>(rsp.vpu.r[13], r15, 0X4);
    // ldv         $v14[0], 0x30($15)
    rsp.LDV<0>(rsp.vpu.r[14], r15, 0X6);
    // ldv         $v11[8], 0x8($15)
    rsp.LDV<8>(rsp.vpu.r[11], r15, 0X1);
    // ldv         $v12[8], 0x18($15)
    rsp.LDV<8>(rsp.vpu.r[12], r15, 0X3);
    // ldv         $v13[8], 0x28($15)
    rsp.LDV<8>(rsp.vpu.r[13], r15, 0X5);
    // ldv         $v14[8], 0x38($15)
    rsp.LDV<8>(rsp.vpu.r[14], r15, 0X7);
L_1CD8:
    // lqv         $v3[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[3], r13, 0X0);
    // lqv         $v4[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[4], r13, 0X1);
    // lqv         $v5[0], 0x20($13)
    rsp.LQV<0>(rsp.vpu.r[5], r13, 0X2);
    // lqv         $v6[0], 0x30($13)
    rsp.LQV<0>(rsp.vpu.r[6], r13, 0X3);
    // vmudh       $v3, $v3, $v11
    rsp.VMUDH<0>(rsp.vpu.r[3], rsp.vpu.r[3], rsp.vpu.r[11]);
    // vmudh       $v4, $v4, $v12
    rsp.VMUDH<0>(rsp.vpu.r[4], rsp.vpu.r[4], rsp.vpu.r[12]);
    // vmudh       $v5, $v5, $v13
    rsp.VMUDH<0>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[13]);
    // vmudh       $v6, $v6, $v14
    rsp.VMUDH<0>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[14]);
    // sqv         $v3[0], 0x0($13)
    rsp.SQV<0>(rsp.vpu.r[3], r13, 0X0);
    // sqv         $v4[0], 0x10($13)
    rsp.SQV<0>(rsp.vpu.r[4], r13, 0X1);
    // sqv         $v5[0], 0x20($13)
    rsp.SQV<0>(rsp.vpu.r[5], r13, 0X2);
    // sqv         $v6[0], 0x30($13)
    rsp.SQV<0>(rsp.vpu.r[6], r13, 0X3);
    // addi        $12, $12, -0x40
    r12 = RSP_ADD32(r12, -0X40);
    // bgtz        $12, L_1CD8
    if (RSP_SIGNED(r12) > 0) {
        // addi        $13, $13, 0x40
        r13 = RSP_ADD32(r13, 0X40);
        goto L_1CD8;
    }
    // addi        $13, $13, 0x40
    r13 = RSP_ADD32(r13, 0X40);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_1D1C:
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
    // vxor        $v28, $v28, $v28
    rsp.VXOR<0>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[28]);
    // lhu         $21, 0x0($24)
    r21 = RSP_MEM_HU_LOAD(0X0, r24);
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // lhu         $20, 0x2($24)
    r20 = RSP_MEM_HU_LOAD(0X2, r24);
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // lhu         $19, 0x4($24)
    r19 = RSP_MEM_HU_LOAD(0X4, r24);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // beq         $19, $zero, L_1E70
    if (r19 == 0) {
        // andi        $14, $26, 0xFFFF
        r14 = r26 & 0XFFFF;
        goto L_1E70;
    }
    // andi        $14, $26, 0xFFFF
    r14 = r26 & 0XFFFF;
    // mtc2        $14, $v31[10]
    rsp.MTC2<10>(r14, rsp.vpu.r[31]);
    // sll         $14, $14, 2
    r14 = S32(r14) << 2;
    // mtc2        $14, $v16[0]
    rsp.MTC2<0>(r14, rsp.vpu.r[16]);
    // vxor        $v20, $v20, $v20
    rsp.VXOR<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[20]);
    // sll         $18, $25, 8
    r18 = S32(r25) << 8;
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
    // srl         $18, $18, 8
    r18 = S32(U32(r18) >> 8);
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
    // slv         $v28[0], 0x0($23)
    rsp.SLV<0>(rsp.vpu.r[28], r23, 0X0);
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
    // bgtz        $1, L_1D9C
    if (RSP_SIGNED(r1) > 0) {
        // nop
    
        goto L_1D9C;
    }
    // nop

    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
    // jal         0x1170
    r31 = 0x1D8C;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_1170;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_1D8C:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1D8C
    if (r5 != 0) {
        // nop
    
        goto L_1D8C;
    }
    // nop

    // mtc0        $zero, SP_SEMAPHORE
L_1D9C:
    // addi        $13, $zero, 0x3C0
    r13 = RSP_ADD32(0, 0X3C0);
    // addi        $1, $zero, 0x4
    r1 = RSP_ADD32(0, 0X4);
    // mtc2        $1, $v14[0]
    rsp.MTC2<0>(r1, rsp.vpu.r[14]);
    // lqv         $v24[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[24], r13, 0X1);
    // vmudm       $v16, $v24, $v16[0]
    rsp.VMUDM<8>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[16]);
    // ldv         $v28[8], 0x0($23)
    rsp.LDV<8>(rsp.vpu.r[28], r23, 0X0);
    // sqv         $v16[0], 0x10($13)
    rsp.SQV<0>(rsp.vpu.r[16], r13, 0X1);
    // lqv         $v25[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[25], r13, 0X0);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v23[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[23], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v22[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[22], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v21[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[21], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v20[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[20], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
L_1DFC:
    // vmudh       $v16, $v25, $v28[6]
    rsp.VMUDH<14>(rsp.vpu.r[16], rsp.vpu.r[25], rsp.vpu.r[28]);
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
    // vmadh       $v16, $v24, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[28]);
    // addi        $19, $19, -0x10
    r19 = RSP_ADD32(r19, -0X10);
    // vmadh       $v16, $v23, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[16], rsp.vpu.r[23], rsp.vpu.r[30]);
    // vmadh       $v16, $v22, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[16], rsp.vpu.r[22], rsp.vpu.r[30]);
    // vmadh       $v16, $v21, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[16], rsp.vpu.r[21], rsp.vpu.r[30]);
    // vmadh       $v16, $v20, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[30]);
    // vmadh       $v28, $v19, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[19], rsp.vpu.r[30]);
    // vmadh       $v16, $v18, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[30]);
    // vmadh       $v16, $v17, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[16], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadh       $v16, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[30], rsp.vpu.r[31]);
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
    // vsar        $v26, $v15, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[15]);
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
    // vsar        $v28, $v15, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[15]);
    // vmudn       $v16, $v26, $v14[0]
    rsp.VMUDN<8>(rsp.vpu.r[16], rsp.vpu.r[26], rsp.vpu.r[14]);
    // vmadh       $v28, $v28, $v14[0]
    rsp.VMADH<8>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[14]);
    // sdv         $v28[0], 0x0($20)
    rsp.SDV<0>(rsp.vpu.r[28], r20, 0X0);
    // sdv         $v28[8], 0x8($20)
    rsp.SDV<8>(rsp.vpu.r[28], r20, 0X1);
    // bgtz        $19, L_1DFC
    if (RSP_SIGNED(r19) > 0) {
        // addi        $20, $20, 0x10
        r20 = RSP_ADD32(r20, 0X10);
        goto L_1DFC;
    }
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
    // addi        $1, $20, -0x8
    r1 = RSP_ADD32(r20, -0X8);
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
    // jal         0x119C
    r31 = 0x1E64;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_119C;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_1E64:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1E64
    if (r5 != 0) {
        // nop
    
        goto L_1E64;
    }
    // nop

L_1E70:
    // j           L_1104
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1104;
    // mtc0        $zero, SP_SEMAPHORE
L_1E78:
    // vaddc       $v31, $v31, $v31
    rsp.VADDC<0>(rsp.vpu.r[31], rsp.vpu.r[31], rsp.vpu.r[31]);
    // srl         $18, $26, 12
    r18 = S32(U32(r26) >> 12);
    // andi        $18, $18, 0xFF0
    r18 = r18 & 0XFF0;
    // andi        $19, $25, 0xFFFF
    r19 = r25 & 0XFFFF;
    // srl         $20, $25, 16
    r20 = S32(U32(r25) >> 16);
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
L_1E90:
    // lqv         $v29[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[29], r20, 0X0);
    // lqv         $v26[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[26], r19, 0X1);
    // lqv         $v28[0], 0x10($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X1);
    // lqv         $v25[0], 0x20($19)
    rsp.LQV<0>(rsp.vpu.r[25], r19, 0X2);
    // lqv         $v23[0], 0x20($20)
    rsp.LQV<0>(rsp.vpu.r[23], r20, 0X2);
    // lqv         $v24[0], 0x30($19)
    rsp.LQV<0>(rsp.vpu.r[24], r19, 0X3);
    // lqv         $v22[0], 0x30($20)
    rsp.LQV<0>(rsp.vpu.r[22], r20, 0X3);
    // addi        $20, $20, 0x40
    r20 = RSP_ADD32(r20, 0X40);
    // vadd        $v27, $v27, $v29
    rsp.VADD<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[29]);
    // vadd        $v26, $v26, $v28
    rsp.VADD<0>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[28]);
    // vadd        $v25, $v25, $v23
    rsp.VADD<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[23]);
    // vadd        $v24, $v24, $v22
    rsp.VADD<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[22]);
    // addi        $18, $18, -0x40
    r18 = RSP_ADD32(r18, -0X40);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // sqv         $v26[0], 0x10($19)
    rsp.SQV<0>(rsp.vpu.r[26], r19, 0X1);
    // sqv         $v25[0], 0x20($19)
    rsp.SQV<0>(rsp.vpu.r[25], r19, 0X2);
    // sqv         $v24[0], 0x30($19)
    rsp.SQV<0>(rsp.vpu.r[24], r19, 0X3);
    // addi        $19, $19, 0x40
    r19 = RSP_ADD32(r19, 0X40);
    // bgtz        $18, L_1E90
    if (RSP_SIGNED(r18) > 0) {
        // lqv         $v27[0], 0x0($19)
        rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
        goto L_1E90;
    }
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
    // j           L_1104
    // nop

    goto L_1104;
    // nop

L_1EE8:
    // lh          $14, 0x0($24)
    r14 = RSP_MEM_H_LOAD(0X0, r24);
    // lh          $15, 0x2($24)
    r15 = RSP_MEM_H_LOAD(0X2, r24);
    // lh          $13, 0x4($24)
    r13 = RSP_MEM_H_LOAD(0X4, r24);
    // andi        $12, $26, 0xFFFF
    r12 = r26 & 0XFFFF;
    // sll         $12, $12, 2
    r12 = S32(r12) << 2;
    // andi        $10, $25, 0xFFFF
    r10 = r25 & 0XFFFF;
    // sll         $14, $14, 16
    r14 = S32(r14) << 16;
    // or          $10, $10, $14
    r10 = r10 | r14;
L_1F08:
    // srl         $11, $10, 16
    r11 = S32(U32(r10) >> 16);
    // andi        $11, $11, 0xFFFE
    r11 = r11 & 0XFFFE;
    // lsv         $v1[0], 0x0($11)
    rsp.LSV<0>(rsp.vpu.r[1], r11, 0X0);
    // add         $10, $10, $12
    r10 = RSP_ADD32(r10, r12);
    // srl         $11, $10, 16
    r11 = S32(U32(r10) >> 16);
    // andi        $11, $11, 0xFFFE
    r11 = r11 & 0XFFFE;
    // lsv         $v1[2], 0x0($11)
    rsp.LSV<2>(rsp.vpu.r[1], r11, 0X0);
    // add         $10, $10, $12
    r10 = RSP_ADD32(r10, r12);
    // srl         $11, $10, 16
    r11 = S32(U32(r10) >> 16);
    // andi        $11, $11, 0xFFFE
    r11 = r11 & 0XFFFE;
    // lsv         $v1[4], 0x0($11)
    rsp.LSV<4>(rsp.vpu.r[1], r11, 0X0);
    // add         $10, $10, $12
    r10 = RSP_ADD32(r10, r12);
    // srl         $11, $10, 16
    r11 = S32(U32(r10) >> 16);
    // andi        $11, $11, 0xFFFE
    r11 = r11 & 0XFFFE;
    // lsv         $v1[6], 0x0($11)
    rsp.LSV<6>(rsp.vpu.r[1], r11, 0X0);
    // add         $10, $10, $12
    r10 = RSP_ADD32(r10, r12);
    // addi        $13, $13, -0x8
    r13 = RSP_ADD32(r13, -0X8);
    // sdv         $v1[0], 0x0($15)
    rsp.SDV<0>(rsp.vpu.r[1], r15, 0X0);
    // addi        $15, $15, 0x8
    r15 = RSP_ADD32(r15, 0X8);
    // bgtz        $13, L_1F08
    if (RSP_SIGNED(r13) > 0) {
        // nop
    
        goto L_1F08;
    }
    // nop

    // jal         0x1104
    r31 = 0x1F64;
    // nop

    goto L_1104;
    // nop

L_1F64:
    // nop

    // nop

    // nop

    return RspExitReason::ImemOverrun;
do_indirect_jump:
    switch ((jump_target | 0x1000) & 0X1FFF) { 
        case 0x1C9C: goto L_1C9C;
        case 0x1B98: goto L_1B98;
        case 0x1A98: goto L_1A98;
        case 0x1AF8: goto L_1AF8;
        case 0x1AD4: goto L_1AD4;
        case 0x1C48: goto L_1C48;
        case 0x1A70: goto L_1A70;
        case 0x18B0: goto L_18B0;
        case 0x1BE8: goto L_1BE8;
        case 0x12BC: goto L_12BC;
        case 0x1B08: goto L_1B08;
        case 0x11F8: goto L_11F8;
        case 0x158C: goto L_158C;
        case 0x1104: goto L_1104;
        case 0x1D1C: goto L_1D1C;
        case 0x120C: goto L_120C;
        case 0x1344: goto L_1344;
        case 0x1B24: goto L_1B24;
        case 0x1164: goto L_1164;
        case 0x111C: goto L_111C;
        case 0x1AE4: goto L_1AE4;
        case 0x10C0: goto L_10C0;
        case 0x1B2C: goto L_1B2C;
        case 0x1C34: goto L_1C34;
        case 0x1B00: goto L_1B00;
        case 0x11C8: goto L_11C8;
        case 0x1804: goto L_1804;
        case 0x1540: goto L_1540;
        case 0x1F64: goto L_1F64;
        case 0x1E78: goto L_1E78;
        case 0x1D8C: goto L_1D8C;
        case 0x1EE8: goto L_1EE8;
        case 0x17F0: goto L_17F0;
        case 0x1E64: goto L_1E64;
        case 0x1904: goto L_1904;
        case 0x1ADC: goto L_1ADC;
        case 0x1554: goto L_1554;
        case 0x1B18: goto L_1B18;
        case 0x12CC: goto L_12CC;
        case 0x1284: goto L_1284;
        case 0x184C: goto L_184C;
        case 0x1B10: goto L_1B10;
    }
    printf("Unhandled jump target 0x%04X in microcode aspMain, coming from [%s:%d]\n", jump_target, debug_file, debug_line);
    printf("Register dump: r0  = %08X r1  = %08X r2  = %08X r3  = %08X r4  = %08X r5  = %08X r6  = %08X r7  = %08X\n"
           "               r8  = %08X r9  = %08X r10 = %08X r11 = %08X r12 = %08X r13 = %08X r14 = %08X r15 = %08X\n"
           "               r16 = %08X r17 = %08X r18 = %08X r19 = %08X r20 = %08X r21 = %08X r22 = %08X r23 = %08X\n"
           "               r24 = %08X r25 = %08X r26 = %08X r27 = %08X r28 = %08X r29 = %08X r30 = %08X r31 = %08X\n",
           0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16,
           r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31);
    return RspExitReason::UnhandledJumpTarget;
}
