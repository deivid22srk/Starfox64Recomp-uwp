#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Lib_Texture_Scroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099A30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80099A34: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80099A38: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80099A3C: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80099A40: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80099A44: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80099A48: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80099A4C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80099A50: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80099A54: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80099A58: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80099A5C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80099A60: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80099A64: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80099A68: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x80099A6C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80099A70: and         $t7, $a0, $at
    ctx->r15 = ctx->r4 & ctx->r1;
    // 0x80099A74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80099A78: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x80099A7C: beq         $a3, $zero, L_80099AA8
    if (ctx->r7 == 0) {
        // 0x80099A80: addu        $t0, $t0, $at
        ctx->r8 = ADD32(ctx->r8, ctx->r1);
            goto L_80099AA8;
    }
    // 0x80099A80: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x80099A84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099A88: beq         $a3, $at, L_80099C28
    if (ctx->r7 == ctx->r1) {
        // 0x80099A8C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80099C28;
    }
    // 0x80099A8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80099A90: beq         $a3, $at, L_80099CD4
    if (ctx->r7 == ctx->r1) {
        // 0x80099A94: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80099CD4;
    }
    // 0x80099A94: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80099A98: beq         $a3, $at, L_80099D50
    if (ctx->r7 == ctx->r1) {
        // 0x80099A9C: nop
    
            goto L_80099D50;
    }
    // 0x80099A9C: nop

    // 0x80099AA0: b           L_80099E10
    // 0x80099AA4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
        goto L_80099E10;
    // 0x80099AA4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80099AA8:
    // 0x80099AA8: blez        $a1, L_80099E0C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80099AAC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80099E0C;
    }
    // 0x80099AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80099AB0: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x80099AB4: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099AB8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80099ABC: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80099AC0: mflo        $t9
    ctx->r25 = lo;
    // 0x80099AC4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80099AC8: addu        $t5, $t0, $t6
    ctx->r13 = ADD32(ctx->r8, ctx->r14);
L_80099ACC:
    // 0x80099ACC: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80099AD0: lhu         $a3, 0x0($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X0);
    // 0x80099AD4: bne         $at, $zero, L_80099C08
    if (ctx->r1 != 0) {
        // 0x80099AD8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80099C08;
    }
    // 0x80099AD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80099ADC: addiu       $s1, $a2, -0x1
    ctx->r17 = ADD32(ctx->r6, -0X1);
    // 0x80099AE0: andi        $t7, $s1, 0x3
    ctx->r15 = ctx->r17 & 0X3;
    // 0x80099AE4: beq         $t7, $zero, L_80099B44
    if (ctx->r15 == 0) {
        // 0x80099AE8: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80099B44;
    }
    // 0x80099AE8: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80099AEC: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099AF0: addiu       $s0, $t7, 0x1
    ctx->r16 = ADD32(ctx->r15, 0X1);
    // 0x80099AF4: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80099AF8: mflo        $t9
    ctx->r25 = lo;
    // 0x80099AFC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80099B00: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80099B04: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099B08: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x80099B0C: mflo        $t8
    ctx->r24 = lo;
    // 0x80099B10: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80099B14: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x80099B18: addu        $v0, $t6, $t1
    ctx->r2 = ADD32(ctx->r14, ctx->r9);
L_80099B1C:
    // 0x80099B1C: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80099B20: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80099B24: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x80099B28: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80099B2C: sh          $t7, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r15;
    // 0x80099B30: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x80099B34: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80099B38: bne         $s0, $t4, L_80099B1C
    if (ctx->r16 != ctx->r12) {
        // 0x80099B3C: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80099B1C;
    }
    // 0x80099B3C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80099B40: beq         $v1, $a2, L_80099C08
    if (ctx->r3 == ctx->r6) {
        // 0x80099B44: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80099C08;
    }
L_80099B44:
    // 0x80099B44: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80099B48: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099B4C: sll         $s2, $a1, 3
    ctx->r18 = S32(ctx->r5 << 3);
    // 0x80099B50: sll         $s3, $a1, 3
    ctx->r19 = S32(ctx->r5 << 3);
    // 0x80099B54: sll         $s4, $a1, 3
    ctx->r20 = S32(ctx->r5 << 3);
    // 0x80099B58: mflo        $t7
    ctx->r15 = lo;
    // 0x80099B5C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80099B60: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x80099B64: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099B68: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x80099B6C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80099B70: mflo        $t6
    ctx->r14 = lo;
    // 0x80099B74: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80099B78: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80099B7C: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099B80: addiu       $t9, $v1, 0x2
    ctx->r25 = ADD32(ctx->r3, 0X2);
    // 0x80099B84: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x80099B88: mflo        $t6
    ctx->r14 = lo;
    // 0x80099B8C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80099B90: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80099B94: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099B98: addiu       $t9, $v1, 0x3
    ctx->r25 = ADD32(ctx->r3, 0X3);
    // 0x80099B9C: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
    // 0x80099BA0: mflo        $t6
    ctx->r14 = lo;
    // 0x80099BA4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80099BA8: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80099BAC: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099BB0: addu        $s0, $t8, $t1
    ctx->r16 = ADD32(ctx->r24, ctx->r9);
    // 0x80099BB4: mflo        $t6
    ctx->r14 = lo;
    // 0x80099BB8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80099BBC: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80099BC0: addu        $s1, $t8, $t1
    ctx->r17 = ADD32(ctx->r24, ctx->r9);
L_80099BC4:
    // 0x80099BC4: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x80099BC8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80099BCC: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x80099BD0: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x80099BD4: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80099BD8: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
    // 0x80099BDC: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80099BE0: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x80099BE4: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80099BE8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80099BEC: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x80099BF0: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x80099BF4: addu        $s1, $s1, $s4
    ctx->r17 = ADD32(ctx->r17, ctx->r20);
    // 0x80099BF8: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80099BFC: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80099C00: bne         $v1, $a2, L_80099BC4
    if (ctx->r3 != ctx->r6) {
        // 0x80099C04: addu        $s0, $s0, $s3
        ctx->r16 = ADD32(ctx->r16, ctx->r19);
            goto L_80099BC4;
    }
    // 0x80099C04: addu        $s0, $s0, $s3
    ctx->r16 = ADD32(ctx->r16, ctx->r19);
L_80099C08:
    // 0x80099C08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80099C0C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80099C10: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80099C14: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // 0x80099C18: bne         $a0, $a1, L_80099ACC
    if (ctx->r4 != ctx->r5) {
        // 0x80099C1C: sh          $a3, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r7;
            goto L_80099ACC;
    }
    // 0x80099C1C: sh          $a3, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r7;
    // 0x80099C20: b           L_80099E10
    // 0x80099C24: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
        goto L_80099E10;
    // 0x80099C24: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80099C28:
    // 0x80099C28: blez        $a1, L_80099E0C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80099C2C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80099E0C;
    }
    // 0x80099C2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80099C30: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x80099C34: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099C38: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80099C3C: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80099C40: addiu       $t3, $a2, -0x2
    ctx->r11 = ADD32(ctx->r6, -0X2);
    // 0x80099C44: mflo        $t8
    ctx->r24 = lo;
    // 0x80099C48: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80099C4C: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
L_80099C50:
    // 0x80099C50: lhu         $a3, 0x0($t5)
    ctx->r7 = MEM_HU(ctx->r13, 0X0);
    // 0x80099C54: bltz        $t3, L_80099CB4
    if (SIGNED(ctx->r11) < 0) {
        // 0x80099C58: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80099CB4;
    }
    // 0x80099C58: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80099C5C: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099C60: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80099C64: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    // 0x80099C68: mflo        $t6
    ctx->r14 = lo;
    // 0x80099C6C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80099C70: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80099C74: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099C78: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x80099C7C: mflo        $t6
    ctx->r14 = lo;
    // 0x80099C80: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80099C84: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80099C88: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
L_80099C8C:
    // 0x80099C8C: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x80099C90: negu        $at, $a1
    ctx->r1 = SUB32(0, ctx->r5);
    // 0x80099C94: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80099C98: sll         $t6, $at, 1
    ctx->r14 = S32(ctx->r1 << 1);
    // 0x80099C9C: sll         $t7, $at, 1
    ctx->r15 = S32(ctx->r1 << 1);
    // 0x80099CA0: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
    // 0x80099CA4: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x80099CA8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80099CAC: bgez        $a2, L_80099C8C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80099CB0: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80099C8C;
    }
    // 0x80099CB0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80099CB4:
    // 0x80099CB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80099CB8: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80099CBC: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80099CC0: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // 0x80099CC4: bne         $a0, $a1, L_80099C50
    if (ctx->r4 != ctx->r5) {
        // 0x80099CC8: sh          $a3, -0x2($t2)
        MEM_H(-0X2, ctx->r10) = ctx->r7;
            goto L_80099C50;
    }
    // 0x80099CC8: sh          $a3, -0x2($t2)
    MEM_H(-0X2, ctx->r10) = ctx->r7;
    // 0x80099CCC: b           L_80099E10
    // 0x80099CD0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
        goto L_80099E10;
    // 0x80099CD0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80099CD4:
    // 0x80099CD4: blez        $a2, L_80099E0C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80099CD8: sll         $t8, $zero, 1
        ctx->r24 = S32(0 << 1);
            goto L_80099E0C;
    }
    // 0x80099CD8: sll         $t8, $zero, 1
    ctx->r24 = S32(0 << 1);
    // 0x80099CDC: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x80099CE0: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80099CE4: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x80099CE8: addu        $t5, $t0, $t6
    ctx->r13 = ADD32(ctx->r8, ctx->r14);
    // 0x80099CEC: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x80099CF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80099CF4: addiu       $t3, $a1, -0x2
    ctx->r11 = ADD32(ctx->r5, -0X2);
L_80099CF8:
    // 0x80099CF8: lhu         $a3, -0x2($t2)
    ctx->r7 = MEM_HU(ctx->r10, -0X2);
    // 0x80099CFC: bltz        $t3, L_80099D20
    if (SIGNED(ctx->r11) < 0) {
        // 0x80099D00: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80099D20;
    }
    // 0x80099D00: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80099D04: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80099D08: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
L_80099D0C:
    // 0x80099D0C: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80099D10: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80099D14: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80099D18: bgez        $a0, L_80099D0C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80099D1C: sh          $t8, 0x4($v0)
        MEM_H(0X4, ctx->r2) = ctx->r24;
            goto L_80099D0C;
    }
    // 0x80099D1C: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
L_80099D20:
    // 0x80099D20: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80099D24: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80099D28: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80099D2C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80099D30: sh          $a3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r7;
    // 0x80099D34: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80099D38: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x80099D3C: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80099D40: bne         $t4, $a2, L_80099CF8
    if (ctx->r12 != ctx->r6) {
        // 0x80099D44: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80099CF8;
    }
    // 0x80099D44: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80099D48: b           L_80099E10
    // 0x80099D4C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
        goto L_80099E10;
    // 0x80099D4C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80099D50:
    // 0x80099D50: blez        $a2, L_80099E0C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80099D54: sll         $t8, $zero, 1
        ctx->r24 = S32(0 << 1);
            goto L_80099E0C;
    }
    // 0x80099D54: sll         $t8, $zero, 1
    ctx->r24 = S32(0 << 1);
    // 0x80099D58: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x80099D5C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80099D60: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x80099D64: addu        $t5, $t0, $t6
    ctx->r13 = ADD32(ctx->r8, ctx->r14);
    // 0x80099D68: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x80099D6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80099D70:
    // 0x80099D70: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80099D74: lhu         $a3, 0x0($t5)
    ctx->r7 = MEM_HU(ctx->r13, 0X0);
    // 0x80099D78: bne         $at, $zero, L_80099DE4
    if (ctx->r1 != 0) {
        // 0x80099D7C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80099DE4;
    }
    // 0x80099D7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80099D80: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    // 0x80099D84: andi        $t7, $t0, 0x3
    ctx->r15 = ctx->r8 & 0X3;
    // 0x80099D88: beq         $t7, $zero, L_80099DB0
    if (ctx->r15 == 0) {
        // 0x80099D8C: addiu       $v1, $t7, 0x1
        ctx->r3 = ADD32(ctx->r15, 0X1);
            goto L_80099DB0;
    }
    // 0x80099D8C: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x80099D90: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80099D94: addu        $v0, $t1, $t8
    ctx->r2 = ADD32(ctx->r9, ctx->r24);
L_80099D98:
    // 0x80099D98: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x80099D9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80099DA0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80099DA4: bne         $v1, $a0, L_80099D98
    if (ctx->r3 != ctx->r4) {
        // 0x80099DA8: sh          $t9, -0x4($v0)
        MEM_H(-0X4, ctx->r2) = ctx->r25;
            goto L_80099D98;
    }
    // 0x80099DA8: sh          $t9, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r25;
    // 0x80099DAC: beq         $a0, $a1, L_80099DE4
    if (ctx->r4 == ctx->r5) {
        // 0x80099DB0: sll         $t6, $a0, 1
        ctx->r14 = S32(ctx->r4 << 1);
            goto L_80099DE4;
    }
L_80099DB0:
    // 0x80099DB0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80099DB4: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
L_80099DB8:
    // 0x80099DB8: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x80099DBC: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x80099DC0: lhu         $t6, 0x6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6);
    // 0x80099DC4: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80099DC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80099DCC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80099DD0: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x80099DD4: sh          $t9, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r25;
    // 0x80099DD8: sh          $t6, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r14;
    // 0x80099DDC: bne         $a0, $a1, L_80099DB8
    if (ctx->r4 != ctx->r5) {
        // 0x80099DE0: sh          $t7, -0xA($v0)
        MEM_H(-0XA, ctx->r2) = ctx->r15;
            goto L_80099DB8;
    }
    // 0x80099DE0: sh          $t7, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r15;
L_80099DE4:
    // 0x80099DE4: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80099DE8: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80099DEC: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x80099DF0: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80099DF4: sh          $a3, -0x2($t2)
    MEM_H(-0X2, ctx->r10) = ctx->r7;
    // 0x80099DF8: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x80099DFC: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x80099E00: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80099E04: bne         $t4, $a2, L_80099D70
    if (ctx->r12 != ctx->r6) {
        // 0x80099E08: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80099D70;
    }
    // 0x80099E08: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_80099E0C:
    // 0x80099E0C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80099E10:
    // 0x80099E10: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80099E14: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80099E18: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x80099E1C: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x80099E20: jr          $ra
    // 0x80099E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80099E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Versus_InitMatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1368: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800C136C: addiu       $a3, $a3, -0x784C
    ctx->r7 = ADD32(ctx->r7, -0X784C);
    // 0x800C1370: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800C1374: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1378: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C137C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C1380: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800C1384: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C1388: addiu       $a2, $a2, -0x7808
    ctx->r6 = ADD32(ctx->r6, -0X7808);
    // 0x800C138C: addiu       $a1, $a1, -0x7818
    ctx->r5 = ADD32(ctx->r5, -0X7818);
    // 0x800C1390: addiu       $a0, $a0, -0x7828
    ctx->r4 = ADD32(ctx->r4, -0X7828);
    // 0x800C1394: addiu       $v1, $v1, -0x7880
    ctx->r3 = ADD32(ctx->r3, -0X7880);
    // 0x800C1398: addiu       $v0, $v0, 0x1A18
    ctx->r2 = ADD32(ctx->r2, 0X1A18);
    // 0x800C139C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_800C13A0:
    // 0x800C13A0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C13A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C13A8: bnel        $t6, $zero, L_800C13C0
    if (ctx->r14 != 0) {
        // 0x800C13AC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800C13C0;
    }
    goto skip_0;
    // 0x800C13AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_0:
    // 0x800C13B0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800C13B4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C13B8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800C13BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800C13C0:
    // 0x800C13C0: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x800C13C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C13C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C13CC: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800C13D0: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800C13D4: bne         $at, $zero, L_800C13A0
    if (ctx->r1 != 0) {
        // 0x800C13D8: swc1        $f0, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = ctx->f0.u32l;
            goto L_800C13A0;
    }
    // 0x800C13D8: swc1        $f0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800C13DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C13E0: swc1        $f0, -0x7834($at)
    MEM_W(-0X7834, ctx->r1) = ctx->f0.u32l;
    // 0x800C13E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C13E8: swc1        $f0, -0x7830($at)
    MEM_W(-0X7830, ctx->r1) = ctx->f0.u32l;
    // 0x800C13EC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C13F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C13F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C13F8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C13FC: swc1        $f4, -0x7854($at)
    MEM_W(-0X7854, ctx->r1) = ctx->f4.u32l;
    // 0x800C1400: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1404: swc1        $f0, -0x7850($at)
    MEM_W(-0X7850, ctx->r1) = ctx->f0.u32l;
    // 0x800C1408: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C140C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1410: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1414: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C1418: swc1        $f6, 0x1A10($at)
    MEM_W(0X1A10, ctx->r1) = ctx->f6.u32l;
    // 0x800C141C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1420: sw          $zero, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = 0;
    // 0x800C1424: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1428: sw          $t9, -0x7870($at)
    MEM_W(-0X7870, ctx->r1) = ctx->r25;
    // 0x800C142C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1430: sw          $a3, -0x786C($at)
    MEM_W(-0X786C, ctx->r1) = ctx->r7;
    // 0x800C1434: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1438: sw          $zero, -0x7864($at)
    MEM_W(-0X7864, ctx->r1) = 0;
    // 0x800C143C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1440: sw          $zero, -0x7860($at)
    MEM_W(-0X7860, ctx->r1) = 0;
    // 0x800C1444: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1448: sw          $zero, -0x785C($at)
    MEM_W(-0X785C, ctx->r1) = 0;
    // 0x800C144C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1450: addiu       $t1, $zero, 0x63
    ctx->r9 = ADD32(0, 0X63);
    // 0x800C1454: sw          $t1, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r9;
    // 0x800C1458: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C145C: sw          $zero, -0x7848($at)
    MEM_W(-0X7848, ctx->r1) = 0;
    // 0x800C1460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1464: sw          $zero, -0x78B0($at)
    MEM_W(-0X78B0, ctx->r1) = 0;
    // 0x800C1468: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C146C: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x800C1470: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1474: sw          $zero, -0x77D0($at)
    MEM_W(-0X77D0, ctx->r1) = 0;
    // 0x800C1478: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C147C: sw          $zero, 0x4A90($at)
    MEM_W(0X4A90, ctx->r1) = 0;
    // 0x800C1480: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C1484: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800C1488: sw          $zero, 0x4A98($at)
    MEM_W(0X4A98, ctx->r1) = 0;
    // 0x800C148C: addiu       $t0, $t0, 0x4AA0
    ctx->r8 = ADD32(ctx->r8, 0X4AA0);
    // 0x800C1490: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800C1494: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C1498: sw          $zero, 0x4A9C($at)
    MEM_W(0X4A9C, ctx->r1) = 0;
    // 0x800C149C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C14A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800C14A4: sw          $t3, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r11;
    // 0x800C14A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C14AC: sw          $zero, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = 0;
    // 0x800C14B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C14B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800C14B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C14BC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C14C0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C14C4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800C14C8: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x800C14CC: addiu       $a2, $a2, -0x77D0
    ctx->r6 = ADD32(ctx->r6, -0X77D0);
    // 0x800C14D0: addiu       $v0, $v0, -0x77E0
    ctx->r2 = ADD32(ctx->r2, -0X77E0);
    // 0x800C14D4: addiu       $a1, $a1, -0x77F0
    ctx->r5 = ADD32(ctx->r5, -0X77F0);
    // 0x800C14D8: addiu       $a0, $a0, -0x77F8
    ctx->r4 = ADD32(ctx->r4, -0X77F8);
    // 0x800C14DC: addiu       $v1, $v1, 0x7C30
    ctx->r3 = ADD32(ctx->r3, 0X7C30);
L_800C14E0:
    // 0x800C14E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C14E4: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800C14E8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800C14EC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800C14F0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800C14F4: sh          $zero, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = 0;
    // 0x800C14F8: sh          $zero, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = 0;
    // 0x800C14FC: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x800C1500: bne         $at, $zero, L_800C14E0
    if (ctx->r1 != 0) {
        // 0x800C1504: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800C14E0;
    }
    // 0x800C1504: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800C1508: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C150C: lbu         $v0, -0x7781($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7781);
    // 0x800C1510: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1514: addiu       $t4, $zero, 0x96
    ctx->r12 = ADD32(0, 0X96);
    // 0x800C1518: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x800C151C: sw          $t5, -0x7804($at)
    MEM_W(-0X7804, ctx->r1) = ctx->r13;
    // 0x800C1520: sw          $t4, -0x7808($at)
    MEM_W(-0X7808, ctx->r1) = ctx->r12;
    // 0x800C1524: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1528: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x800C152C: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x800C1530: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800C1534: sw          $t7, -0x77FC($at)
    MEM_W(-0X77FC, ctx->r1) = ctx->r15;
    // 0x800C1538: bne         $a3, $t8, L_800C1550
    if (ctx->r7 != ctx->r24) {
        // 0x800C153C: sw          $t6, -0x7800($at)
        MEM_W(-0X7800, ctx->r1) = ctx->r14;
            goto L_800C1550;
    }
    // 0x800C153C: sw          $t6, -0x7800($at)
    MEM_W(-0X7800, ctx->r1) = ctx->r14;
    // 0x800C1540: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1544: addiu       $v1, $v1, -0x78A4
    ctx->r3 = ADD32(ctx->r3, -0X78A4);
    // 0x800C1548: b           L_800C155C
    // 0x800C154C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
        goto L_800C155C;
    // 0x800C154C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_800C1550:
    // 0x800C1550: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1554: addiu       $v1, $v1, -0x78A4
    ctx->r3 = ADD32(ctx->r3, -0X78A4);
    // 0x800C1558: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800C155C:
    // 0x800C155C: sll         $t9, $v0, 28
    ctx->r25 = S32(ctx->r2 << 28);
    // 0x800C1560: srl         $t1, $t9, 31
    ctx->r9 = S32(U32(ctx->r25) >> 31);
    // 0x800C1564: bne         $a3, $t1, L_800C157C
    if (ctx->r7 != ctx->r9) {
        // 0x800C1568: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_800C157C;
    }
    // 0x800C1568: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800C156C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C1570: addiu       $v0, $v0, -0x78A0
    ctx->r2 = ADD32(ctx->r2, -0X78A0);
    // 0x800C1574: b           L_800C1588
    // 0x800C1578: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
        goto L_800C1588;
    // 0x800C1578: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
L_800C157C:
    // 0x800C157C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C1580: addiu       $v0, $v0, -0x78A0
    ctx->r2 = ADD32(ctx->r2, -0X78A0);
    // 0x800C1584: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800C1588:
    // 0x800C1588: lw          $t2, 0x78AC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78AC);
    // 0x800C158C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1590: addiu       $t3, $zero, 0x2710
    ctx->r11 = ADD32(0, 0X2710);
    // 0x800C1594: bne         $t2, $at, L_800C15A4
    if (ctx->r10 != ctx->r1) {
        // 0x800C1598: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_800C15A4;
    }
    // 0x800C1598: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800C159C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C15A0: sw          $t3, 0x78A4($at)
    MEM_W(0X78A4, ctx->r1) = ctx->r11;
L_800C15A4:
    // 0x800C15A4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C15A8: bne         $t4, $zero, L_800C15B4
    if (ctx->r12 != 0) {
        // 0x800C15AC: nop
    
            goto L_800C15B4;
    }
    // 0x800C15AC: nop

    // 0x800C15B0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800C15B4:
    // 0x800C15B4: lw          $t5, 0x78C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78C8);
    // 0x800C15B8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C15BC: addiu       $v0, $v0, -0x7898
    ctx->r2 = ADD32(ctx->r2, -0X7898);
    // 0x800C15C0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800C15C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C15C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C15CC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800C15D0: jr          $ra
    // 0x800C15D4: nop

    return;
    // 0x800C15D4: nop

;}
RECOMP_FUNC void Math_RoundF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FBC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FBCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FBD0: jal         0x8001FF08
    // 0x8001FBD4: nop

    __roundf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001FBD4: nop

    after_0:
    // 0x8001FBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FBDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FBE0: jr          $ra
    // 0x8001FBE4: nop

    return;
    // 0x8001FBE4: nop

;}
RECOMP_FUNC void ActorEvent_Effect394_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F1F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F1F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006F1F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006F1FC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006F200: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006F204: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8006F208: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8006F20C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8006F210:
    // 0x8006F210: bnel        $t6, $zero, L_8006F23C
    if (ctx->r14 != 0) {
        // 0x8006F214: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8006F23C;
    }
    goto skip_0;
    // 0x8006F214: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8006F218: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006F21C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006F220: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006F224: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006F228: jal         0x8006F140
    // 0x8006F22C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    ActorEvent_Effect394_Setup(rdram, ctx);
        goto after_0;
    // 0x8006F22C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8006F230: b           L_8006F248
    // 0x8006F234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006F248;
    // 0x8006F234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F238: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8006F23C:
    // 0x8006F23C: bnel        $a0, $v0, L_8006F210
    if (ctx->r4 != ctx->r2) {
        // 0x8006F240: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8006F210;
    }
    goto skip_1;
    // 0x8006F240: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006F244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F248:
    // 0x8006F248: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F24C: jr          $ra
    // 0x8006F250: nop

    return;
    // 0x8006F250: nop

;}
RECOMP_FUNC void Game_InitViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1FB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A1FB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A1FBC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800A1FC0: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x800A1FC4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800A1FC8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800A1FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1FD0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A1FD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A1FD8: beq         $v1, $a1, L_800A2490
    if (ctx->r3 == ctx->r5) {
        // 0x800A1FDC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A2490;
    }
    // 0x800A1FDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A1FE0: bne         $a1, $at, L_800A2490
    if (ctx->r5 != ctx->r1) {
        // 0x800A1FE4: nop
    
            goto L_800A2490;
    }
    // 0x800A1FE4: nop

    // 0x800A1FE8: beq         $a2, $zero, L_800A2018
    if (ctx->r6 == 0) {
        // 0x800A1FEC: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_800A2018;
    }
    // 0x800A1FEC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A1FF0: beq         $a2, $v1, L_800A2138
    if (ctx->r6 == ctx->r3) {
        // 0x800A1FF4: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_800A2138;
    }
    // 0x800A1FF4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A1FF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1FFC: beq         $a2, $at, L_800A2250
    if (ctx->r6 == ctx->r1) {
        // 0x800A2000: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_800A2250;
    }
    // 0x800A2000: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A2004: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A2008: beq         $a2, $at, L_800A236C
    if (ctx->r6 == ctx->r1) {
        // 0x800A200C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_800A236C;
    }
    // 0x800A200C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A2010: b           L_800A2478
    // 0x800A2014: nop

        goto L_800A2478;
    // 0x800A2014: nop

L_800A2018:
    // 0x800A2018: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A201C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2020: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2024: addiu       $a0, $a0, 0x1A14
    ctx->r4 = ADD32(ctx->r4, 0X1A14);
    // 0x800A2028: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A202C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2030: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A2034: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A2038: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A203C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A2040: addiu       $v0, $v0, 0x7E58
    ctx->r2 = ADD32(ctx->r2, 0X7E58);
    // 0x800A2044: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800A2048: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A204C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2050: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A2054: addiu       $a2, $zero, 0x1FF
    ctx->r6 = ADD32(0, 0X1FF);
    // 0x800A2058: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A205C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2060: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A2064: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A2068: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800A206C: nop

    // 0x800A2070: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800A2074: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2078: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800A207C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A2080: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A2084: nop

    // 0x800A2088: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A208C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A2090: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800A2094: nop

    // 0x800A2098: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x800A209C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800A20A0: sh          $a2, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r6;
    // 0x800A20A4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800A20A8: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800A20AC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A20B0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A20B4: lui         $t5, 0xED02
    ctx->r13 = S32(0XED02 << 16);
    // 0x800A20B8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A20BC: ori         $t5, $t5, 0x20
    ctx->r13 = ctx->r13 | 0X20;
    // 0x800A20C0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A20C4: nop

    // 0x800A20C8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A20CC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A20D0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800A20D4: nop

    // 0x800A20D8: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x800A20DC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A20E0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800A20E4: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A20E8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A20EC: nop

    // 0x800A20F0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A20F4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A20F8: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800A20FC: nop

    // 0x800A2100: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    // 0x800A2104: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800A2108: sh          $a2, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r6;
    // 0x800A210C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800A2110: sh          $zero, 0xE($t3)
    MEM_H(0XE, ctx->r11) = 0;
    // 0x800A2114: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800A2118: lui         $t6, 0x28
    ctx->r14 = S32(0X28 << 16);
    // 0x800A211C: ori         $t6, $t6, 0x1E0
    ctx->r14 = ctx->r14 | 0X1E0;
    // 0x800A2120: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A2124: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x800A2128: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A212C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A2130: b           L_800A24A8
    // 0x800A2134: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
        goto L_800A24A8;
    // 0x800A2134: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_800A2138:
    // 0x800A2138: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A213C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2140: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2144: addiu       $a0, $a0, 0x1A14
    ctx->r4 = ADD32(ctx->r4, 0X1A14);
    // 0x800A2148: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A214C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2150: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A2154: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A2158: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A215C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A2160: addiu       $v0, $v0, 0x7E58
    ctx->r2 = ADD32(ctx->r2, 0X7E58);
    // 0x800A2164: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800A2168: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A216C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2170: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A2174: addiu       $a2, $zero, 0x1FF
    ctx->r6 = ADD32(0, 0X1FF);
    // 0x800A2178: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A217C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2180: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A2184: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A2188: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800A218C: nop

    // 0x800A2190: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x800A2194: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2198: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800A219C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A21A0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A21A4: nop

    // 0x800A21A8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A21AC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A21B0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800A21B4: nop

    // 0x800A21B8: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x800A21BC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800A21C0: sh          $a2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r6;
    // 0x800A21C4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800A21C8: sh          $zero, 0x6($t4)
    MEM_H(0X6, ctx->r12) = 0;
    // 0x800A21CC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A21D0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800A21D4: lui         $t4, 0xED28
    ctx->r12 = S32(0XED28 << 16);
    // 0x800A21D8: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800A21DC: ori         $t4, $t4, 0x20
    ctx->r12 = ctx->r12 | 0X20;
    // 0x800A21E0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A21E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A21E8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800A21EC: nop

    // 0x800A21F0: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x800A21F4: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A21F8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800A21FC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800A2200: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800A2204: nop

    // 0x800A2208: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A220C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A2210: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800A2214: nop

    // 0x800A2218: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
    // 0x800A221C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800A2220: sh          $a2, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r6;
    // 0x800A2224: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800A2228: sh          $zero, 0xE($t2)
    MEM_H(0XE, ctx->r10) = 0;
    // 0x800A222C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800A2230: lui         $t5, 0x4E
    ctx->r13 = S32(0X4E << 16);
    // 0x800A2234: ori         $t5, $t5, 0x1E0
    ctx->r13 = ctx->r13 | 0X1E0;
    // 0x800A2238: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800A223C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800A2240: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A2244: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800A2248: b           L_800A24A8
    // 0x800A224C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
        goto L_800A24A8;
    // 0x800A224C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_800A2250:
    // 0x800A2250: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A2254: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2258: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A225C: addiu       $a0, $a0, 0x1A14
    ctx->r4 = ADD32(ctx->r4, 0X1A14);
    // 0x800A2260: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A2264: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2268: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A226C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A2270: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A2274: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A2278: addiu       $v0, $v0, 0x7E58
    ctx->r2 = ADD32(ctx->r2, 0X7E58);
    // 0x800A227C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A2280: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A2284: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2288: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A228C: addiu       $a2, $zero, 0x1FF
    ctx->r6 = ADD32(0, 0X1FF);
    // 0x800A2290: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A2294: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2298: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A229C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A22A0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A22A4: nop

    // 0x800A22A8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800A22AC: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A22B0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800A22B4: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A22B8: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800A22BC: nop

    // 0x800A22C0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A22C4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A22C8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800A22CC: nop

    // 0x800A22D0: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
    // 0x800A22D4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800A22D8: sh          $a2, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r6;
    // 0x800A22DC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800A22E0: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x800A22E4: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A22E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800A22EC: lui         $t3, 0xED02
    ctx->r11 = S32(0XED02 << 16);
    // 0x800A22F0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800A22F4: ori         $t3, $t3, 0x1E0
    ctx->r11 = ctx->r11 | 0X1E0;
    // 0x800A22F8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A22FC: nop

    // 0x800A2300: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A2304: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A2308: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800A230C: nop

    // 0x800A2310: sh          $t5, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r13;
    // 0x800A2314: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2318: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800A231C: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800A2320: nop

    // 0x800A2324: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A2328: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A232C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A2330: nop

    // 0x800A2334: sh          $t8, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r24;
    // 0x800A2338: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800A233C: sh          $a2, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r6;
    // 0x800A2340: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800A2344: sh          $zero, 0xE($t1)
    MEM_H(0XE, ctx->r9) = 0;
    // 0x800A2348: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800A234C: lui         $t4, 0x28
    ctx->r12 = S32(0X28 << 16);
    // 0x800A2350: ori         $t4, $t4, 0x3A0
    ctx->r12 = ctx->r12 | 0X3A0;
    // 0x800A2354: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A2358: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800A235C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800A2360: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A2364: b           L_800A24A8
    // 0x800A2368: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
        goto L_800A24A8;
    // 0x800A2368: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_800A236C:
    // 0x800A236C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A2370: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2378: addiu       $a0, $a0, 0x1A14
    ctx->r4 = ADD32(ctx->r4, 0X1A14);
    // 0x800A237C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A2380: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2384: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A2388: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A238C: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A2390: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A2394: addiu       $v0, $v0, 0x7E58
    ctx->r2 = ADD32(ctx->r2, 0X7E58);
    // 0x800A2398: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800A239C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800A23A0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A23A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A23A8: addiu       $a2, $zero, 0x1FF
    ctx->r6 = ADD32(0, 0X1FF);
    // 0x800A23AC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A23B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A23B4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800A23B8: nop

    // 0x800A23BC: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800A23C0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A23C4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800A23C8: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A23CC: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800A23D0: nop

    // 0x800A23D4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A23D8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A23DC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800A23E0: nop

    // 0x800A23E4: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x800A23E8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800A23EC: sh          $a2, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r6;
    // 0x800A23F0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800A23F4: sh          $zero, 0x6($t2)
    MEM_H(0X6, ctx->r10) = 0;
    // 0x800A23F8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A23FC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800A2400: lui         $t2, 0xED28
    ctx->r10 = S32(0XED28 << 16);
    // 0x800A2404: mul.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800A2408: ori         $t2, $t2, 0x1E0
    ctx->r10 = ctx->r10 | 0X1E0;
    // 0x800A240C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A2410: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A2414: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A2418: nop

    // 0x800A241C: sh          $t4, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r12;
    // 0x800A2420: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A2424: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A2428: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800A242C: nop

    // 0x800A2430: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A2434: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A2438: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800A243C: nop

    // 0x800A2440: sh          $t7, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r15;
    // 0x800A2444: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800A2448: sh          $a2, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r6;
    // 0x800A244C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800A2450: sh          $zero, 0xE($t0)
    MEM_H(0XE, ctx->r8) = 0;
    // 0x800A2454: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800A2458: lui         $t3, 0x4E
    ctx->r11 = S32(0X4E << 16);
    // 0x800A245C: ori         $t3, $t3, 0x3A0
    ctx->r11 = ctx->r11 | 0X3A0;
    // 0x800A2460: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800A2464: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x800A2468: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800A246C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800A2470: b           L_800A24A8
    // 0x800A2474: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
        goto L_800A24A8;
    // 0x800A2474: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_800A2478:
    // 0x800A2478: jal         0x800A1F44
    // 0x800A247C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Game_InitFullViewport(rdram, ctx);
        goto after_0;
    // 0x800A247C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A2480: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A2484: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A2488: b           L_800A24A4
    // 0x800A248C: addiu       $v0, $v0, 0x7E58
    ctx->r2 = ADD32(ctx->r2, 0X7E58);
        goto L_800A24A4;
    // 0x800A248C: addiu       $v0, $v0, 0x7E58
    ctx->r2 = ADD32(ctx->r2, 0X7E58);
L_800A2490:
    // 0x800A2490: jal         0x800A1F44
    // 0x800A2494: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Game_InitFullViewport(rdram, ctx);
        goto after_1;
    // 0x800A2494: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x800A2498: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A249C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A24A0: addiu       $v0, $v0, 0x7E58
    ctx->r2 = ADD32(ctx->r2, 0X7E58);
L_800A24A4:
    // 0x800A24A4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_800A24A8:
    // 0x800A24A8: lui         $t5, 0x380
    ctx->r13 = S32(0X380 << 16);
    // 0x800A24AC: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A24B0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A24B4: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x800A24B8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A24BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800A24C0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A24C4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800A24C8: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800A24CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A24D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A24D4: jr          $ra
    // 0x800A24D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A24D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Audio_ProcessSeqCmd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800177C8: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x800177CC: and         $t2, $a0, $at
    ctx->r10 = ctx->r4 & ctx->r1;
    // 0x800177D0: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x800177D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800177D8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800177DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800177E0: srl         $t6, $t2, 24
    ctx->r14 = S32(U32(ctx->r10) >> 24);
    // 0x800177E4: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x800177E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800177EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800177F0: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x800177F4: beq         $at, $zero, L_800182E0
    if (ctx->r1 == 0) {
        // 0x800177F8: andi        $a1, $t6, 0xFF
        ctx->r5 = ctx->r14 & 0XFF;
            goto L_800182E0;
    }
    // 0x800177F8: andi        $a1, $t6, 0xFF
    ctx->r5 = ctx->r14 & 0XFF;
    // 0x800177FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80017800: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017804: addu        $at, $at, $t8
    gpr jr_addend_8001780C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80017808: lw          $t8, -0x6FC8($at)
    ctx->r24 = ADD32(ctx->r1, -0X6FC8);
    // 0x8001780C: jr          $t8
    // 0x80017810: nop

    switch (jr_addend_8001780C >> 2) {
        case 0: goto L_80017814; break;
        case 1: goto L_80017954; break;
        case 2: goto L_80017974; break;
        case 3: goto L_80017B78; break;
        case 4: goto L_80017CD8; break;
        case 5: goto L_80017D9C; break;
        case 6: goto L_80017EA0; break;
        case 7: goto L_80017FB0; break;
        case 8: goto L_80017FEC; break;
        case 9: goto L_8001807C; break;
        case 10: goto L_800180B0; break;
        case 11: goto L_80018150; break;
        case 12: goto L_80018184; break;
        case 13: goto L_800182E0; break;
        case 14: goto L_80018228; break;
        case 15: goto L_80018278; break;
        default: switch_error(__func__, 0x8001780C, 0x800C9038);
    }
    // 0x80017810: nop

L_80017814:
    // 0x80017814: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    // 0x80017818: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001781C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80017820: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017824: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80017828: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001782C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80017830: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80017834: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x80017838: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8001783C: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x80017840: lbu         $t6, 0x254($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X254);
    // 0x80017844: andi        $a2, $s0, 0xFF00
    ctx->r6 = ctx->r16 & 0XFF00;
    // 0x80017848: srl         $t7, $a2, 8
    ctx->r15 = S32(U32(ctx->r6) >> 8);
    // 0x8001784C: bne         $t6, $zero, L_800182E0
    if (ctx->r14 != 0) {
        // 0x80017850: andi        $a2, $t7, 0xFF
        ctx->r6 = ctx->r15 & 0XFF;
            goto L_800182E0;
    }
    // 0x80017850: andi        $a2, $t7, 0xFF
    ctx->r6 = ctx->r15 & 0XFF;
    // 0x80017854: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x80017858: beq         $at, $zero, L_80017888
    if (ctx->r1 == 0) {
        // 0x8001785C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80017888;
    }
    // 0x8001785C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80017860: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017864: and         $a3, $s0, $at
    ctx->r7 = ctx->r16 & ctx->r1;
    // 0x80017868: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001786C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80017870: srl         $t6, $a3, 13
    ctx->r14 = S32(U32(ctx->r7) >> 13);
    // 0x80017874: andi        $a3, $t6, 0xFFFF
    ctx->r7 = ctx->r14 & 0XFFFF;
    // 0x80017878: jal         0x80017600
    // 0x8001787C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    Audio_StartSequence(rdram, ctx);
        goto after_0;
    // 0x8001787C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_0:
    // 0x80017880: b           L_800182E4
    // 0x80017884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80017884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017888:
    // 0x80017888: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001788C: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80017890: and         $t8, $s0, $at
    ctx->r24 = ctx->r16 & ctx->r1;
    // 0x80017894: sw          $t8, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->r24;
    // 0x80017898: sb          $t9, 0x254($v1)
    MEM_B(0X254, ctx->r3) = ctx->r25;
    // 0x8001789C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800178A0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800178A4: jal         0x80017760
    // 0x800178A8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    Audio_StopSequence(rdram, ctx);
        goto after_1;
    // 0x800178A8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x800178AC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800178B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800178B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800178B8: lhu         $t6, 0x24A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24A);
    // 0x800178BC: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x800178C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800178C4: beq         $t6, $at, L_80017920
    if (ctx->r14 == ctx->r1) {
        // 0x800178C8: addiu       $a1, $sp, 0x4C
        ctx->r5 = ADD32(ctx->r29, 0X4C);
            goto L_80017920;
    }
    // 0x800178C8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800178CC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800178D0: jal         0x8001ED14
    // 0x800178D4: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    AudioThread_GetFontsForSequence(rdram, ctx);
        goto after_2;
    // 0x800178D4: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    after_2:
    // 0x800178D8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800178DC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800178E0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800178E4: lhu         $a0, 0x24A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X24A);
    // 0x800178E8: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800178EC: jal         0x8001ED14
    // 0x800178F0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    AudioThread_GetFontsForSequence(rdram, ctx);
        goto after_3;
    // 0x800178F0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x800178F4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800178F8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800178FC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80017900: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80017904: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x80017908: sll         $t8, $a0, 8
    ctx->r24 = S32(ctx->r4 << 8);
    // 0x8001790C: beq         $t6, $t7, L_80017920
    if (ctx->r14 == ctx->r15) {
        // 0x80017910: lui         $at, 0xF600
        ctx->r1 = S32(0XF600 << 16);
            goto L_80017920;
    }
    // 0x80017910: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80017914: or          $a0, $t8, $at
    ctx->r4 = ctx->r24 | ctx->r1;
    // 0x80017918: jal         0x8001E8CC
    // 0x8001791C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_4;
    // 0x8001791C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80017920:
    // 0x80017920: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x80017924: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80017928: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8001792C: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x80017930: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80017934: ori         $t7, $t6, 0x1400
    ctx->r15 = ctx->r14 | 0X1400;
    // 0x80017938: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8001793C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80017940: or          $a0, $t7, $t9
    ctx->r4 = ctx->r15 | ctx->r25;
    // 0x80017944: jal         0x8001E8F0
    // 0x80017948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_5;
    // 0x80017948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8001794C: b           L_800182E4
    // 0x80017950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80017950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017954:
    // 0x80017954: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017958: and         $a1, $s0, $at
    ctx->r5 = ctx->r16 & ctx->r1;
    // 0x8001795C: srl         $t6, $a1, 13
    ctx->r14 = S32(U32(ctx->r5) >> 13);
    // 0x80017960: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    // 0x80017964: jal         0x80017760
    // 0x80017968: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    Audio_StopSequence(rdram, ctx);
        goto after_6;
    // 0x80017968: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    after_6:
    // 0x8001796C: b           L_800182E4
    // 0x80017970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80017970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017974:
    // 0x80017974: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80017978: addiu       $v0, $v0, -0x5660
    ctx->r2 = ADD32(ctx->r2, -0X5660);
    // 0x8001797C: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x80017980: addu        $t4, $v0, $t7
    ctx->r12 = ADD32(ctx->r2, ctx->r15);
    // 0x80017984: lbu         $t1, 0x0($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0X0);
    // 0x80017988: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8001798C: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x80017990: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80017994: blez        $t1, L_80017A24
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80017998: or          $t3, $t1, $zero
        ctx->r11 = ctx->r9 | 0;
            goto L_80017A24;
    }
    // 0x80017998: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x8001799C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800179A0: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800179A4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800179A8: addiu       $t6, $t6, -0x5688
    ctx->r14 = ADD32(ctx->r14, -0X5688);
    // 0x800179AC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800179B0: andi        $a3, $s0, 0xFF
    ctx->r7 = ctx->r16 & 0XFF;
    // 0x800179B4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800179B8: addu        $a2, $t7, $t6
    ctx->r6 = ADD32(ctx->r15, ctx->r14);
L_800179BC:
    // 0x800179BC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800179C0: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x800179C4: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x800179C8: addu        $t8, $v0, $a1
    ctx->r24 = ADD32(ctx->r2, ctx->r5);
    // 0x800179CC: bnel        $a3, $t7, L_80017A0C
    if (ctx->r7 != ctx->r15) {
        // 0x800179D0: lbu         $t9, 0x0($t8)
        ctx->r25 = MEM_BU(ctx->r24, 0X0);
            goto L_80017A0C;
    }
    goto skip_0;
    // 0x800179D0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    skip_0:
    // 0x800179D4: bne         $v1, $zero, L_800182E0
    if (ctx->r3 != 0) {
        // 0x800179D8: lbu         $a0, 0x37($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X37);
            goto L_800182E0;
    }
    // 0x800179D8: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x800179DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800179E0: and         $a3, $s0, $at
    ctx->r7 = ctx->r16 & ctx->r1;
    // 0x800179E4: andi        $a2, $s0, 0xFF00
    ctx->r6 = ctx->r16 & 0XFF00;
    // 0x800179E8: srl         $t6, $a2, 8
    ctx->r14 = S32(U32(ctx->r6) >> 8);
    // 0x800179EC: srl         $t9, $a3, 13
    ctx->r25 = S32(U32(ctx->r7) >> 13);
    // 0x800179F0: andi        $a3, $t9, 0xFFFF
    ctx->r7 = ctx->r25 & 0XFFFF;
    // 0x800179F4: andi        $a2, $t6, 0xFF
    ctx->r6 = ctx->r14 & 0XFF;
    // 0x800179F8: jal         0x80017600
    // 0x800179FC: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    Audio_StartSequence(rdram, ctx);
        goto after_7;
    // 0x800179FC: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    after_7:
    // 0x80017A00: b           L_800182E4
    // 0x80017A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80017A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A08: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
L_80017A0C:
    // 0x80017A0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80017A10: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x80017A14: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80017A18: bne         $at, $zero, L_800179BC
    if (ctx->r1 != 0) {
        // 0x80017A1C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800179BC;
    }
    // 0x80017A1C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80017A20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80017A24:
    // 0x80017A24: blez        $t3, L_80017A94
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017A28: andi        $t0, $t1, 0xFF
        ctx->r8 = ctx->r9 & 0XFF;
            goto L_80017A94;
    }
    // 0x80017A28: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x80017A2C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80017A30: andi        $a0, $s0, 0xFF00
    ctx->r4 = ctx->r16 & 0XFF00;
    // 0x80017A34: srl         $t7, $a0, 8
    ctx->r15 = S32(U32(ctx->r4) >> 8);
    // 0x80017A38: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    // 0x80017A3C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80017A40: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80017A44: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80017A48: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80017A4C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80017A50: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80017A54: addiu       $t7, $t7, -0x5688
    ctx->r15 = ADD32(ctx->r15, -0X5688);
    // 0x80017A58: addu        $a2, $t9, $t7
    ctx->r6 = ADD32(ctx->r25, ctx->r15);
    // 0x80017A5C: lbu         $v0, -0x5660($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5660);
L_80017A60:
    // 0x80017A60: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80017A64: addu        $t8, $a2, $t6
    ctx->r24 = ADD32(ctx->r6, ctx->r14);
    // 0x80017A68: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80017A6C: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80017A70: bnel        $at, $zero, L_80017A84
    if (ctx->r1 != 0) {
        // 0x80017A74: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80017A84;
    }
    goto skip_1;
    // 0x80017A74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80017A78: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80017A7C: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x80017A80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80017A84:
    // 0x80017A84: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x80017A88: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80017A8C: bne         $at, $zero, L_80017A60
    if (ctx->r1 != 0) {
        // 0x80017A90: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80017A60;
    }
    // 0x80017A90: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80017A94:
    // 0x80017A94: bne         $t0, $t3, L_80017AA4
    if (ctx->r8 != ctx->r11) {
        // 0x80017A98: or          $t2, $t0, $zero
        ctx->r10 = ctx->r8 | 0;
            goto L_80017AA4;
    }
    // 0x80017A98: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80017A9C: bne         $t2, $zero, L_80017B3C
    if (ctx->r10 != 0) {
        // 0x80017AA0: nop
    
            goto L_80017B3C;
    }
    // 0x80017AA0: nop

L_80017AA4:
    // 0x80017AA4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80017AA8: andi        $a3, $s0, 0xFF00
    ctx->r7 = ctx->r16 & 0XFF00;
    // 0x80017AAC: srl         $t6, $a3, 8
    ctx->r14 = S32(U32(ctx->r7) >> 8);
    // 0x80017AB0: andi        $a3, $t6, 0xFF
    ctx->r7 = ctx->r14 & 0XFF;
    // 0x80017AB4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80017AB8: or          $t5, $s0, $zero
    ctx->r13 = ctx->r16 | 0;
    // 0x80017ABC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80017AC0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80017AC4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80017AC8: addiu       $t8, $t8, -0x5688
    ctx->r24 = ADD32(ctx->r24, -0X5688);
    // 0x80017ACC: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x80017AD0: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80017AD4: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x80017AD8: beq         $at, $zero, L_80017AEC
    if (ctx->r1 == 0) {
        // 0x80017ADC: addu        $a2, $t6, $t8
        ctx->r6 = ADD32(ctx->r14, ctx->r24);
            goto L_80017AEC;
    }
    // 0x80017ADC: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x80017AE0: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x80017AE4: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x80017AE8: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
L_80017AEC:
    // 0x80017AEC: addiu       $v1, $t3, -0x1
    ctx->r3 = ADD32(ctx->r11, -0X1);
    // 0x80017AF0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80017AF4: beq         $t2, $v0, L_80017B2C
    if (ctx->r10 == ctx->r2) {
        // 0x80017AF8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80017B2C;
    }
    // 0x80017AF8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80017AFC:
    // 0x80017AFC: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80017B00: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    // 0x80017B04: lbu         $t9, -0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, -0X1);
    // 0x80017B08: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80017B0C: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x80017B10: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
    // 0x80017B14: lbu         $t7, -0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, -0X2);
    // 0x80017B18: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80017B1C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80017B20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80017B24: bne         $t2, $v0, L_80017AFC
    if (ctx->r10 != ctx->r2) {
        // 0x80017B28: sb          $t7, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r15;
            goto L_80017AFC;
    }
    // 0x80017B28: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_80017B2C:
    // 0x80017B2C: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x80017B30: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x80017B34: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x80017B38: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
L_80017B3C:
    // 0x80017B3C: bne         $t2, $zero, L_800182E0
    if (ctx->r10 != 0) {
        // 0x80017B40: lbu         $a0, 0x37($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X37);
            goto L_800182E0;
    }
    // 0x80017B40: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x80017B44: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017B48: and         $a3, $s0, $at
    ctx->r7 = ctx->r16 & ctx->r1;
    // 0x80017B4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017B50: andi        $a2, $s0, 0xFF00
    ctx->r6 = ctx->r16 & 0XFF00;
    // 0x80017B54: srl         $t7, $a2, 8
    ctx->r15 = S32(U32(ctx->r6) >> 8);
    // 0x80017B58: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80017B5C: srl         $t8, $a3, 13
    ctx->r24 = S32(U32(ctx->r7) >> 13);
    // 0x80017B60: andi        $a3, $t8, 0xFFFF
    ctx->r7 = ctx->r24 & 0XFFFF;
    // 0x80017B64: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80017B68: jal         0x80017600
    // 0x80017B6C: andi        $a2, $t7, 0xFF
    ctx->r6 = ctx->r15 & 0XFF;
    Audio_StartSequence(rdram, ctx);
        goto after_8;
    // 0x80017B6C: andi        $a2, $t7, 0xFF
    ctx->r6 = ctx->r15 & 0XFF;
    after_8:
    // 0x80017B70: b           L_800182E4
    // 0x80017B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80017B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017B78:
    // 0x80017B78: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80017B7C: addiu       $t7, $t7, -0x5660
    ctx->r15 = ADD32(ctx->r15, -0X5660);
    // 0x80017B80: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x80017B84: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x80017B88: lbu         $t1, 0x0($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0X0);
    // 0x80017B8C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80017B90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80017B94: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80017B98: blez        $t1, L_80017BFC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80017B9C: or          $t3, $t1, $zero
        ctx->r11 = ctx->r9 | 0;
            goto L_80017BFC;
    }
    // 0x80017B9C: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x80017BA0: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x80017BA4: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x80017BA8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80017BAC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80017BB0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80017BB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80017BB8: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80017BBC: addiu       $t9, $t9, -0x5688
    ctx->r25 = ADD32(ctx->r25, -0X5688);
    // 0x80017BC0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80017BC4: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    // 0x80017BC8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_80017BCC:
    // 0x80017BCC: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80017BD0: addu        $t8, $a2, $t6
    ctx->r24 = ADD32(ctx->r6, ctx->r14);
    // 0x80017BD4: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x80017BD8: bnel        $a3, $t7, L_80017BEC
    if (ctx->r7 != ctx->r15) {
        // 0x80017BDC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80017BEC;
    }
    goto skip_2;
    // 0x80017BDC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80017BE0: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80017BE4: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x80017BE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80017BEC:
    // 0x80017BEC: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80017BF0: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80017BF4: bne         $at, $zero, L_80017BCC
    if (ctx->r1 != 0) {
        // 0x80017BF8: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_80017BCC;
    }
    // 0x80017BF8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80017BFC:
    // 0x80017BFC: beq         $t0, $t3, L_80017C70
    if (ctx->r8 == ctx->r11) {
        // 0x80017C00: or          $t2, $t0, $zero
        ctx->r10 = ctx->r8 | 0;
            goto L_80017C70;
    }
    // 0x80017C00: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80017C04: addiu       $a3, $t3, -0x1
    ctx->r7 = ADD32(ctx->r11, -0X1);
    // 0x80017C08: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80017C0C: beq         $at, $zero, L_80017C68
    if (ctx->r1 == 0) {
        // 0x80017C10: andi        $v1, $t0, 0xFF
        ctx->r3 = ctx->r8 & 0XFF;
            goto L_80017C68;
    }
    // 0x80017C10: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x80017C14: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80017C18: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80017C1C: addiu       $t7, $t7, -0x5688
    ctx->r15 = ADD32(ctx->r15, -0X5688);
    // 0x80017C20: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80017C24: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80017C28: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80017C2C: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x80017C30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80017C34:
    // 0x80017C34: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80017C38: addu        $a1, $a2, $t6
    ctx->r5 = ADD32(ctx->r6, ctx->r14);
    // 0x80017C3C: lbu         $t8, 0x3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X3);
    // 0x80017C40: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80017C44: addu        $a0, $a2, $t9
    ctx->r4 = ADD32(ctx->r6, ctx->r25);
    // 0x80017C48: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80017C4C: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
    // 0x80017C50: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x80017C54: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80017C58: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80017C5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80017C60: bne         $at, $zero, L_80017C34
    if (ctx->r1 != 0) {
        // 0x80017C64: sb          $t7, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r15;
            goto L_80017C34;
    }
    // 0x80017C64: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_80017C68:
    // 0x80017C68: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x80017C6C: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
L_80017C70:
    // 0x80017C70: bne         $t2, $zero, L_800182E0
    if (ctx->r10 != 0) {
        // 0x80017C74: lbu         $a0, 0x37($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X37);
            goto L_800182E0;
    }
    // 0x80017C74: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x80017C78: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017C7C: and         $a3, $s0, $at
    ctx->r7 = ctx->r16 & ctx->r1;
    // 0x80017C80: srl         $t8, $a3, 13
    ctx->r24 = S32(U32(ctx->r7) >> 13);
    // 0x80017C84: andi        $a3, $t8, 0xFFFF
    ctx->r7 = ctx->r24 & 0XFFFF;
    // 0x80017C88: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x80017C8C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80017C90: jal         0x80017760
    // 0x80017C94: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    Audio_StopSequence(rdram, ctx);
        goto after_9;
    // 0x80017C94: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_9:
    // 0x80017C98: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80017C9C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80017CA0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80017CA4: lbu         $t9, 0x0($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X0);
    // 0x80017CA8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80017CAC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80017CB0: beq         $t9, $zero, L_800182E0
    if (ctx->r25 == 0) {
        // 0x80017CB4: sll         $t6, $t6, 1
        ctx->r14 = S32(ctx->r14 << 1);
            goto L_800182E0;
    }
    // 0x80017CB4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80017CB8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80017CBC: addiu       $t8, $t8, -0x5688
    ctx->r24 = ADD32(ctx->r24, -0X5688);
    // 0x80017CC0: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80017CC4: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80017CC8: jal         0x80017600
    // 0x80017CCC: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    Audio_StartSequence(rdram, ctx);
        goto after_10;
    // 0x80017CCC: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    after_10:
    // 0x80017CD0: b           L_800182E4
    // 0x80017CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80017CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017CD8:
    // 0x80017CD8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017CDC: and         $v0, $s0, $at
    ctx->r2 = ctx->r16 & ctx->r1;
    // 0x80017CE0: srl         $t7, $v0, 15
    ctx->r15 = S32(U32(ctx->r2) >> 15);
    // 0x80017CE4: andi        $v1, $t7, 0xFF
    ctx->r3 = ctx->r15 & 0XFF;
    // 0x80017CE8: bne         $v1, $zero, L_80017CFC
    if (ctx->r3 != 0) {
        // 0x80017CEC: andi        $a1, $t7, 0xFF
        ctx->r5 = ctx->r15 & 0XFF;
            goto L_80017CFC;
    }
    // 0x80017CEC: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    // 0x80017CF0: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80017CF4: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80017CF8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_80017CFC:
    // 0x80017CFC: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80017D00: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80017D04: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80017D08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80017D0C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80017D10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80017D14: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x80017D18: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80017D1C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80017D20: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80017D24: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x80017D28: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80017D2C: addu        $v1, $t1, $t8
    ctx->r3 = ADD32(ctx->r9, ctx->r24);
    // 0x80017D30: bgez        $t9, L_80017D48
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80017D34: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80017D48;
    }
    // 0x80017D34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80017D38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80017D3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017D40: nop

    // 0x80017D44: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80017D48:
    // 0x80017D48: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80017D4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017D50: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017D54: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80017D58: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80017D5C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80017D60: bc1tl       L_800182E4
    if (c1cs) {
        // 0x80017D64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800182E4;
    }
    goto skip_3;
    // 0x80017D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80017D68: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80017D6C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80017D70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80017D74: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80017D78: bgez        $a1, L_80017D8C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80017D7C: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80017D8C;
    }
    // 0x80017D7C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80017D80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017D84: nop

    // 0x80017D88: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80017D8C:
    // 0x80017D8C: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80017D90: sh          $a1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r5;
    // 0x80017D94: b           L_800182E0
    // 0x80017D98: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
        goto L_800182E0;
    // 0x80017D98: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
L_80017D9C:
    // 0x80017D9C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017DA0: and         $v0, $s0, $at
    ctx->r2 = ctx->r16 & ctx->r1;
    // 0x80017DA4: srl         $t6, $v0, 15
    ctx->r14 = S32(U32(ctx->r2) >> 15);
    // 0x80017DA8: andi        $v1, $t6, 0xFF
    ctx->r3 = ctx->r14 & 0XFF;
    // 0x80017DAC: bne         $v1, $zero, L_80017DC0
    if (ctx->r3 != 0) {
        // 0x80017DB0: andi        $a1, $t6, 0xFF
        ctx->r5 = ctx->r14 & 0XFF;
            goto L_80017DC0;
    }
    // 0x80017DB0: andi        $a1, $t6, 0xFF
    ctx->r5 = ctx->r14 & 0XFF;
    // 0x80017DB4: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80017DB8: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80017DBC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_80017DC0:
    // 0x80017DC0: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x80017DC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80017DC8: bgez        $a1, L_80017DE0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80017DCC: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80017DE0;
    }
    // 0x80017DCC: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80017DD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80017DD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017DD8: nop

    // 0x80017DDC: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
L_80017DE0:
    // 0x80017DE0: andi        $a2, $t2, 0xFF
    ctx->r6 = ctx->r10 & 0XFF;
    // 0x80017DE4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80017DE8: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x80017DEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017DF0: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80017DF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017DF8: andi        $t8, $s0, 0xFFFF
    ctx->r24 = ctx->r16 & 0XFFFF;
    // 0x80017DFC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80017E00: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80017E04: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80017E08: addiu       $t9, $t9, -0x5258
    ctx->r25 = ADD32(ctx->r25, -0X5258);
    // 0x80017E0C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80017E10: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80017E14: bgez        $t8, L_80017E2C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80017E18: cvt.s.w     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80017E2C;
    }
    // 0x80017E18: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80017E1C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80017E20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017E24: nop

    // 0x80017E28: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80017E2C:
    // 0x80017E2C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80017E30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017E34: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80017E38: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x80017E3C: div.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
L_80017E40:
    // 0x80017E40: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x80017E44: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x80017E48: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80017E4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80017E50: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80017E54: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80017E58: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x80017E5C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80017E60: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80017E64: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80017E68: sh          $a1, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r5;
    // 0x80017E6C: bne         $at, $zero, L_80017E40
    if (ctx->r1 != 0) {
        // 0x80017E70: swc1        $f6, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
            goto L_80017E40;
    }
    // 0x80017E70: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80017E74: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80017E78: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80017E7C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80017E80: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80017E84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80017E88: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80017E8C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80017E90: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x80017E94: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80017E98: b           L_800182E0
    // 0x80017E9C: sh          $t6, 0x244($t7)
    MEM_H(0X244, ctx->r15) = ctx->r14;
        goto L_800182E0;
    // 0x80017E9C: sh          $t6, 0x244($t7)
    MEM_H(0X244, ctx->r15) = ctx->r14;
L_80017EA0:
    // 0x80017EA0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017EA4: and         $v0, $s0, $at
    ctx->r2 = ctx->r16 & ctx->r1;
    // 0x80017EA8: srl         $t9, $v0, 15
    ctx->r25 = S32(U32(ctx->r2) >> 15);
    // 0x80017EAC: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
    // 0x80017EB0: bne         $v1, $zero, L_80017EC4
    if (ctx->r3 != 0) {
        // 0x80017EB4: andi        $a1, $t9, 0xFF
        ctx->r5 = ctx->r25 & 0XFF;
            goto L_80017EC4;
    }
    // 0x80017EB4: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x80017EB8: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80017EBC: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80017EC0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_80017EC4:
    // 0x80017EC4: andi        $a3, $t2, 0xFF
    ctx->r7 = ctx->r10 & 0XFF;
    // 0x80017EC8: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80017ECC: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x80017ED0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017ED4: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x80017ED8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017EDC: andi        $a2, $s0, 0xF00
    ctx->r6 = ctx->r16 & 0XF00;
    // 0x80017EE0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80017EE4: srl         $t6, $a2, 8
    ctx->r14 = S32(U32(ctx->r6) >> 8);
    // 0x80017EE8: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x80017EEC: andi        $t7, $s0, 0xFF
    ctx->r15 = ctx->r16 & 0XFF;
    // 0x80017EF0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80017EF4: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x80017EF8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80017EFC: andi        $a2, $t6, 0xFF
    ctx->r6 = ctx->r14 & 0XFF;
    // 0x80017F00: sll         $a0, $a2, 5
    ctx->r4 = S32(ctx->r6 << 5);
    // 0x80017F04: addu        $t8, $t1, $t9
    ctx->r24 = ADD32(ctx->r9, ctx->r25);
    // 0x80017F08: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x80017F0C: bgez        $t7, L_80017F24
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80017F10: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80017F24;
    }
    // 0x80017F10: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80017F14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80017F18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017F1C: nop

    // 0x80017F20: add.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f10.fl;
L_80017F24:
    // 0x80017F24: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80017F28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017F2C: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80017F30: div.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80017F34: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80017F38: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80017F3C: bc1t        L_800182E0
    if (c1cs) {
        // 0x80017F40: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_800182E0;
    }
    // 0x80017F40: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80017F44: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x80017F48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017F4C: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x80017F50: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017F54: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x80017F58: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80017F5C: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x80017F60: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x80017F64: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80017F68: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80017F6C: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80017F70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80017F74: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80017F78: bgez        $a1, L_80017F8C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80017F7C: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80017F8C;
    }
    // 0x80017F7C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80017F80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017F84: nop

    // 0x80017F88: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80017F8C:
    // 0x80017F8C: div.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80017F90: sh          $a1, 0x50($v0)
    MEM_H(0X50, ctx->r2) = ctx->r5;
    // 0x80017F94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80017F98: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x80017F9C: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    // 0x80017FA0: lhu         $t8, 0x244($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X244);
    // 0x80017FA4: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80017FA8: b           L_800182E0
    // 0x80017FAC: sh          $t9, 0x244($v1)
    MEM_H(0X244, ctx->r3) = ctx->r25;
        goto L_800182E0;
    // 0x80017FAC: sh          $t9, 0x244($v1)
    MEM_H(0X244, ctx->r3) = ctx->r25;
L_80017FB0:
    // 0x80017FB0: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x80017FB4: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80017FB8: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80017FBC: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80017FC0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80017FC4: and         $t6, $s0, $at
    ctx->r14 = ctx->r16 & ctx->r1;
    // 0x80017FC8: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80017FCC: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x80017FD0: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x80017FD4: sll         $t6, $s0, 24
    ctx->r14 = S32(ctx->r16 << 24);
    // 0x80017FD8: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80017FDC: jal         0x8001E8F0
    // 0x80017FE0: or          $a0, $t9, $t8
    ctx->r4 = ctx->r25 | ctx->r24;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_11;
    // 0x80017FE0: or          $a0, $t9, $t8
    ctx->r4 = ctx->r25 | ctx->r24;
    after_11:
    // 0x80017FE4: b           L_800182E4
    // 0x80017FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80017FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017FEC:
    // 0x80017FEC: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // 0x80017FF0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80017FF4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80017FF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80017FFC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80018000: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80018004: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80018008: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8001800C: andi        $a2, $s0, 0xF00
    ctx->r6 = ctx->r16 & 0XF00;
    // 0x80018010: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x80018014: srl         $t8, $a2, 8
    ctx->r24 = S32(U32(ctx->r6) >> 8);
    // 0x80018018: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001801C: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x80018020: andi        $a2, $t8, 0xFF
    ctx->r6 = ctx->r24 & 0XFF;
    // 0x80018024: lhu         $t8, 0x24C($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X24C);
    // 0x80018028: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001802C: sllv        $t6, $t7, $a2
    ctx->r14 = S32(ctx->r15 << (ctx->r6 & 31));
    // 0x80018030: and         $t9, $t8, $t6
    ctx->r25 = ctx->r24 & ctx->r14;
    // 0x80018034: bne         $t9, $zero, L_800182E0
    if (ctx->r25 != 0) {
        // 0x80018038: andi        $t7, $v0, 0xFF
        ctx->r15 = ctx->r2 & 0XFF;
            goto L_800182E0;
    }
    // 0x80018038: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x8001803C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80018040: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x80018044: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80018048: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8001804C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80018050: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80018054: and         $t9, $s0, $at
    ctx->r25 = ctx->r16 & ctx->r1;
    // 0x80018058: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8001805C: srl         $t7, $t9, 16
    ctx->r15 = S32(U32(ctx->r25) >> 16);
    // 0x80018060: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80018064: sll         $t7, $s0, 24
    ctx->r15 = S32(ctx->r16 << 24);
    // 0x80018068: sra         $a1, $t7, 24
    ctx->r5 = S32(SIGNED(ctx->r15) >> 24);
    // 0x8001806C: jal         0x8001E8F0
    // 0x80018070: or          $a0, $t8, $t9
    ctx->r4 = ctx->r24 | ctx->r25;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_12;
    // 0x80018070: or          $a0, $t8, $t9
    ctx->r4 = ctx->r24 | ctx->r25;
    after_12:
    // 0x80018074: b           L_800182E4
    // 0x80018078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80018078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001807C:
    // 0x8001807C: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80018080: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80018084: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80018088: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001808C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018090: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018094: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80018098: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001809C: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x800180A0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800180A4: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x800180A8: b           L_800182E0
    // 0x800180AC: sh          $s0, 0x24C($t8)
    MEM_H(0X24C, ctx->r24) = ctx->r16;
        goto L_800182E0;
    // 0x800180AC: sh          $s0, 0x24C($t8)
    MEM_H(0X24C, ctx->r24) = ctx->r16;
L_800180B0:
    // 0x800180B0: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x800180B4: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800180B8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800180BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800180C0: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x800180C4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800180C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800180CC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800180D0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800180D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800180D8:
    // 0x800180D8: and         $t7, $a3, $a0
    ctx->r15 = ctx->r7 & ctx->r4;
    // 0x800180DC: beq         $t7, $zero, L_800180EC
    if (ctx->r15 == 0) {
        // 0x800180E0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800180EC;
    }
    // 0x800180E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800180E4: b           L_800180F0
    // 0x800180E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800180F0;
    // 0x800180E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800180EC:
    // 0x800180EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800180F0:
    // 0x800180F0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800180F4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800180F8: sll         $a1, $a2, 24
    ctx->r5 = S32(ctx->r6 << 24);
    // 0x800180FC: sra         $t7, $a1, 24
    ctx->r15 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80018100: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x80018104: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80018108: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8001810C: sb          $v1, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r3;
    // 0x80018110: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80018114: jal         0x8001E8F0
    // 0x80018118: or          $a0, $t9, $t6
    ctx->r4 = ctx->r25 | ctx->r14;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_13;
    // 0x80018118: or          $a0, $t9, $t6
    ctx->r4 = ctx->r25 | ctx->r14;
    after_13:
    // 0x8001811C: lbu         $v1, 0x63($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X63);
    // 0x80018120: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80018124: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80018128: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001812C: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80018130: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80018134: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x80018138: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x8001813C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80018140: bne         $at, $zero, L_800180D8
    if (ctx->r1 != 0) {
        // 0x80018144: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800180D8;
    }
    // 0x80018144: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80018148: b           L_800182E4
    // 0x8001814C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x8001814C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80018150:
    // 0x80018150: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80018154: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80018158: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001815C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018160: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018164: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018168: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001816C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018170: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x80018174: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80018178: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8001817C: b           L_800182E0
    // 0x80018180: sw          $s0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r16;
        goto L_800182E0;
    // 0x80018180: sw          $s0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r16;
L_80018184:
    // 0x80018184: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80018188: and         $t9, $s0, $at
    ctx->r25 = ctx->r16 & ctx->r1;
    // 0x8001818C: srl         $t6, $t9, 20
    ctx->r14 = S32(U32(ctx->r25) >> 20);
    // 0x80018190: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80018194: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80018198: beq         $t7, $at, L_800181F4
    if (ctx->r15 == ctx->r1) {
        // 0x8001819C: andi        $t8, $t2, 0xFF
        ctx->r24 = ctx->r10 & 0XFF;
            goto L_800181F4;
    }
    // 0x8001819C: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x800181A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800181A4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800181A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800181AC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800181B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800181B4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800181B8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800181BC: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x800181C0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800181C4: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800181C8: lbu         $t0, 0x41($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X41);
    // 0x800181CC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800181D0: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x800181D4: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800181D8: beq         $at, $zero, L_800182E0
    if (ctx->r1 == 0) {
        // 0x800181DC: sb          $t6, 0x41($v1)
        MEM_B(0X41, ctx->r3) = ctx->r14;
            goto L_800182E0;
    }
    // 0x800181DC: sb          $t6, 0x41($v1)
    MEM_B(0X41, ctx->r3) = ctx->r14;
    // 0x800181E0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800181E4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800181E8: sw          $s0, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r16;
    // 0x800181EC: b           L_800182E0
    // 0x800181F0: sb          $t9, 0x40($v1)
    MEM_B(0X40, ctx->r3) = ctx->r25;
        goto L_800182E0;
    // 0x800181F0: sb          $t9, 0x40($v1)
    MEM_B(0X40, ctx->r3) = ctx->r25;
L_800181F4:
    // 0x800181F4: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x800181F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800181FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80018200: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018204: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018208: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001820C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80018210: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018214: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x80018218: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001821C: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80018220: b           L_800182E0
    // 0x80018224: sb          $zero, 0x41($t8)
    MEM_B(0X41, ctx->r24) = 0;
        goto L_800182E0;
    // 0x80018224: sb          $zero, 0x41($t8)
    MEM_B(0X41, ctx->r24) = 0;
L_80018228:
    // 0x80018228: andi        $v0, $s0, 0xF00
    ctx->r2 = ctx->r16 & 0XF00;
    // 0x8001822C: srl         $t9, $v0, 8
    ctx->r25 = S32(U32(ctx->r2) >> 8);
    // 0x80018230: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80018234: beq         $t6, $zero, L_80018250
    if (ctx->r14 == 0) {
        // 0x80018238: lui         $a0, 0xF000
        ctx->r4 = S32(0XF000 << 16);
            goto L_80018250;
    }
    // 0x80018238: lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // 0x8001823C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018240: beq         $t6, $at, L_8001826C
    if (ctx->r14 == ctx->r1) {
        // 0x80018244: andi        $t7, $s0, 0x1
        ctx->r15 = ctx->r16 & 0X1;
            goto L_8001826C;
    }
    // 0x80018244: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
    // 0x80018248: b           L_800182E4
    // 0x8001824C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x8001824C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80018250:
    // 0x80018250: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x80018254: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80018258: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8001825C: jal         0x8001E8CC
    // 0x80018260: lbu         $a1, 0x5D50($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X5D50);
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_14;
    // 0x80018260: lbu         $a1, 0x5D50($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X5D50);
    after_14:
    // 0x80018264: b           L_800182E4
    // 0x80018268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x80018268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001826C:
    // 0x8001826C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80018270: b           L_800182E0
    // 0x80018274: sb          $t7, 0x5D4C($at)
    MEM_B(0X5D4C, ctx->r1) = ctx->r15;
        goto L_800182E0;
    // 0x80018274: sb          $t7, 0x5D4C($at)
    MEM_B(0X5D4C, ctx->r1) = ctx->r15;
L_80018278:
    // 0x80018278: andi        $t8, $s0, 0xFF00
    ctx->r24 = ctx->r16 & 0XFF00;
    // 0x8001827C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80018280: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x80018284: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80018288: addiu       $v1, $v1, 0x5D54
    ctx->r3 = ADD32(ctx->r3, 0X5D54);
    // 0x8001828C: sb          $t9, 0x5D20($at)
    MEM_B(0X5D20, ctx->r1) = ctx->r25;
    // 0x80018290: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80018294: andi        $a3, $s0, 0xFF
    ctx->r7 = ctx->r16 & 0XFF;
    // 0x80018298: sb          $s0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r16;
    // 0x8001829C: beq         $a3, $a1, L_800182CC
    if (ctx->r7 == ctx->r5) {
        // 0x800182A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800182CC;
    }
    // 0x800182A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800182A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800182A8: jal         0x8001ED8C
    // 0x800182AC: sb          $a1, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r5;
    AudioThread_ResetAudioHeap(rdram, ctx);
        goto after_15;
    // 0x800182AC: sb          $a1, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r5;
    after_15:
    // 0x800182B0: jal         0x8001DE1C
    // 0x800182B4: lbu         $a0, 0x61($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X61);
    Audio_StartReset(rdram, ctx);
        goto after_16;
    // 0x800182B4: lbu         $a0, 0x61($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X61);
    after_16:
    // 0x800182B8: lui         $a0, 0xF800
    ctx->r4 = S32(0XF800 << 16);
    // 0x800182BC: jal         0x8001E8CC
    // 0x800182C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_17;
    // 0x800182C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x800182C4: b           L_800182E4
    // 0x800182C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800182E4;
    // 0x800182C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800182CC:
    // 0x800182CC: jal         0x80017760
    // 0x800182D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Audio_StopSequence(rdram, ctx);
        goto after_18;
    // 0x800182D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x800182D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800182D8: jal         0x80017760
    // 0x800182DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Audio_StopSequence(rdram, ctx);
        goto after_19;
    // 0x800182DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
L_800182E0:
    // 0x800182E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800182E4:
    // 0x800182E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800182E8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800182EC: jr          $ra
    // 0x800182F0: nop

    return;
    // 0x800182F0: nop

;}
RECOMP_FUNC void Effect_Effect398_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008092C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80080930: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80080934: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80080938: lh          $v0, 0x44($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X44);
    // 0x8008093C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80080940: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80080944: beq         $v0, $zero, L_80080960
    if (ctx->r2 == 0) {
        // 0x80080948: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80080960;
    }
    // 0x80080948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008094C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080950: beq         $v0, $at, L_80080A00
    if (ctx->r2 == ctx->r1) {
        // 0x80080954: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_80080A00;
    }
    // 0x80080954: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80080958: b           L_80080ABC
    // 0x8008095C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80080ABC;
    // 0x8008095C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80080960:
    // 0x80080960: jal         0x800B8DD0
    // 0x80080964: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80080964: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_0:
    // 0x80080968: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008096C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80080970: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80080974: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80080978: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x8008097C: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x80080980: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080984: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80080988: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8008098C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080990: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80080994: lui         $t2, 0xFF00
    ctx->r10 = S32(0XFF00 << 16);
    // 0x80080998: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x8008099C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800809A0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800809A4: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x800809A8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800809AC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800809B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800809B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800809B8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800809BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800809C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800809C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800809C8: jal         0x80005C34
    // 0x800809CC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x800809CC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_1:
    // 0x800809D0: jal         0x80006EB8
    // 0x800809D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x800809D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800809D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800809DC: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x800809E0: addiu       $t6, $t6, -0x7510
    ctx->r14 = ADD32(ctx->r14, -0X7510);
    // 0x800809E4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800809E8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800809EC: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800809F0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800809F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800809F8: b           L_80080ABC
    // 0x800809FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80080ABC;
    // 0x800809FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80080A00:
    // 0x80080A00: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80080A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80080A08: jal         0x800B8DD0
    // 0x80080A0C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80080A0C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_3:
    // 0x80080A10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80080A14: lui         $t9, 0xFFFF
    ctx->r25 = S32(0XFFFF << 16);
    // 0x80080A18: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x80080A1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080A20: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80080A24: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80080A28: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80080A2C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80080A30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80080A34: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x80080A38: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x80080A3C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80080A40: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80080A44: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80080A48: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80080A4C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80080A50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80080A54: lui         $a1, 0x3F06
    ctx->r5 = S32(0X3F06 << 16);
    // 0x80080A58: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x80080A5C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80080A60: jal         0x80005FE0
    // 0x80080A64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x80080A64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80080A68: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80080A6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80080A70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80080A74: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80080A78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080A7C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80080A80: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80080A84: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80080A88: jal         0x80005C34
    // 0x80080A8C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80080A8C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_5:
    // 0x80080A90: jal         0x80006EB8
    // 0x80080A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80080A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80080A98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80080A9C: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x80080AA0: addiu       $t7, $t7, 0x4AC0
    ctx->r15 = ADD32(ctx->r15, 0X4AC0);
    // 0x80080AA4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80080AA8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80080AAC: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80080AB0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080AB4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80080AB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80080ABC:
    // 0x80080ABC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80080AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80080AC4: jr          $ra
    // 0x80080AC8: nop

    return;
    // 0x80080AC8: nop

;}
RECOMP_FUNC void Graphics_ClearPrintBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099980: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80099984: blez        $a2, L_800999CC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80099988: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800999CC;
    }
    // 0x80099988: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8009998C: andi        $t0, $a2, 0x3
    ctx->r8 = ctx->r6 & 0X3;
    // 0x80099990: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x80099994: beq         $t0, $zero, L_800999B0
    if (ctx->r8 == 0) {
        // 0x80099998: addu        $a3, $t0, $a2
        ctx->r7 = ADD32(ctx->r8, ctx->r6);
            goto L_800999B0;
    }
    // 0x80099998: addu        $a3, $t0, $a2
    ctx->r7 = ADD32(ctx->r8, ctx->r6);
L_8009999C:
    // 0x8009999C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800999A0: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800999A4: bne         $a3, $v1, L_8009999C
    if (ctx->r7 != ctx->r3) {
        // 0x800999A8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8009999C;
    }
    // 0x800999A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800999AC: beq         $v1, $zero, L_800999CC
    if (ctx->r3 == 0) {
        // 0x800999B0: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800999CC;
    }
L_800999B0:
    // 0x800999B0: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800999B4: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x800999B8: sb          $a1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r5;
    // 0x800999BC: sb          $a1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r5;
    // 0x800999C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800999C4: bne         $v1, $zero, L_800999B0
    if (ctx->r3 != 0) {
        // 0x800999C8: sb          $a1, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = ctx->r5;
            goto L_800999B0;
    }
    // 0x800999C8: sb          $a1, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r5;
L_800999CC:
    // 0x800999CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800999D0: jr          $ra
    // 0x800999D4: nop

    return;
    // 0x800999D4: nop

;}
RECOMP_FUNC void Display_ArwingWingTrail_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055E98: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80055E9C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80055EA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80055EA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80055EA8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80055EAC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80055EB0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80055EB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80055EB8: lw          $t6, 0x204($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X204);
    // 0x80055EBC: lui         $at, 0xC190
    ctx->r1 = S32(0XC190 << 16);
    // 0x80055EC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80055EC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055EC8: bne         $t6, $at, L_80055EE4
    if (ctx->r14 != ctx->r1) {
        // 0x80055ECC: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_80055EE4;
    }
    // 0x80055ECC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80055ED0: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80055ED4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80055ED8: lui         $at, 0xC1B0
    ctx->r1 = S32(0XC1B0 << 16);
    // 0x80055EDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80055EE0: nop

L_80055EE4:
    // 0x80055EE4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80055EE8: lwc1        $f4, 0x25C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X25C);
    // 0x80055EEC: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x80055EF0: nop

    // 0x80055EF4: bc1tl       L_8005621C
    if (c1cs) {
        // 0x80055EF8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005621C;
    }
    goto skip_0;
    // 0x80055EF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80055EFC: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x80055F00: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80055F04: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80055F08: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80055F0C: beql        $t8, $zero, L_80055F20
    if (ctx->r24 == 0) {
        // 0x80055F10: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80055F20;
    }
    goto skip_1;
    // 0x80055F10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_1:
    // 0x80055F14: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80055F18: nop

    // 0x80055F1C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80055F20:
    // 0x80055F20: lwc1        $f20, 0xE8($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80055F24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80055F28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80055F2C: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x80055F30: nop

    // 0x80055F34: bc1fl       L_80055F4C
    if (!c1cs) {
        // 0x80055F38: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80055F4C;
    }
    goto skip_2;
    // 0x80055F38: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_2:
    // 0x80055F3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80055F40: nop

    // 0x80055F44: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x80055F48: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80055F4C:
    // 0x80055F4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055F50: lwc1        $f10, 0xE4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x80055F54: lw          $t9, 0x1C8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C8);
    // 0x80055F58: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80055F5C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80055F60: mul.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80055F64: bnel        $t9, $at, L_80055F78
    if (ctx->r25 != ctx->r1) {
        // 0x80055F68: swc1        $f12, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
            goto L_80055F78;
    }
    goto skip_3;
    // 0x80055F68: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    skip_3:
    // 0x80055F6C: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x80055F70: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80055F74: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
L_80055F78:
    // 0x80055F78: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x80055F7C: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x80055F80: jal         0x800BA140
    // 0x80055F84: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    RCP_SetupDL_64(rdram, ctx);
        goto after_0;
    // 0x80055F84: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80055F88: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80055F8C: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x80055F90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80055F94: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80055F98: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80055F9C: sw          $t0, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r8;
    // 0x80055FA0: addiu       $t2, $zero, -0x9C
    ctx->r10 = ADD32(0, -0X9C);
    // 0x80055FA4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80055FA8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80055FAC: lbu         $t3, 0x49D($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X49D);
    // 0x80055FB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055FB4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80055FB8: bne         $t3, $at, L_800560DC
    if (ctx->r11 != ctx->r1) {
        // 0x80055FBC: addiu       $s0, $s0, -0x4C40
        ctx->r16 = ADD32(ctx->r16, -0X4C40);
            goto L_800560DC;
    }
    // 0x80055FBC: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80055FC0: jal         0x80005708
    // 0x80055FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80055FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80055FC8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80055FCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80055FD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80055FD4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80055FD8: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80055FDC: jal         0x80005B00
    // 0x80055FE0: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80055FE0: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_2:
    // 0x80055FE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055FE8: lwc1        $f4, 0x5EE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EE8);
    // 0x80055FEC: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80055FF0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80055FF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055FF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80055FFC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80056000: jal         0x80005D44
    // 0x80056004: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x80056004: nop

    after_3:
    // 0x80056008: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005600C: lwc1        $f10, 0x5EEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5EEC);
    // 0x80056010: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056014: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056018: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8005601C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80056020: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80056024: jal         0x80005E90
    // 0x80056028: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80056028: nop

    after_4:
    // 0x8005602C: lw          $a1, 0x25C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X25C);
    // 0x80056030: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80056034: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80056038: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005603C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80056040: jal         0x80005C34
    // 0x80056044: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80056044: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_5:
    // 0x80056048: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005604C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80056050: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80056054: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80056058: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005605C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056060: jal         0x80005B00
    // 0x80056064: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x80056064: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    after_6:
    // 0x80056068: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005606C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80056070: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056074: jal         0x80005D44
    // 0x80056078: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x80056078: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8005607C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056080: lwc1        $f8, 0x5EF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5EF0);
    // 0x80056084: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80056088: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005608C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056090: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80056094: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80056098: jal         0x80005E90
    // 0x8005609C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x8005609C: nop

    after_8:
    // 0x800560A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800560A4: jal         0x80006EB8
    // 0x800560A8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x800560A8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_9:
    // 0x800560AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800560B0: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x800560B4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800560B8: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x800560BC: addiu       $t9, $t9, -0x5760
    ctx->r25 = ADD32(ctx->r25, -0X5760);
    // 0x800560C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800560C4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800560C8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800560CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800560D0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800560D4: jal         0x80005740
    // 0x800560D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x800560D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_800560DC:
    // 0x800560DC: lbu         $t0, 0x49C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X49C);
    // 0x800560E0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800560E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800560E8: bne         $t0, $at, L_80056218
    if (ctx->r8 != ctx->r1) {
        // 0x800560EC: addiu       $s0, $s0, -0x4C40
        ctx->r16 = ADD32(ctx->r16, -0X4C40);
            goto L_80056218;
    }
    // 0x800560EC: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800560F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800560F4: lwc1        $f6, 0x5EF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EF4);
    // 0x800560F8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800560FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056100: lwc1        $f4, 0x5EF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EF8);
    // 0x80056104: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80056108: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005610C: lui         $t1, 0x103
    ctx->r9 = S32(0X103 << 16);
    // 0x80056110: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80056114: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80056118: addiu       $t1, $t1, -0x5760
    ctx->r9 = ADD32(ctx->r9, -0X5760);
    // 0x8005611C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80056120: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80056124: lwc1        $f10, 0x5EFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5EFC);
    // 0x80056128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005612C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80056130: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80056134: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80056138: jal         0x80005708
    // 0x8005613C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x8005613C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80056140: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80056144: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80056148: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005614C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80056150: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056154: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80056158: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8005615C: jal         0x80005B00
    // 0x80056160: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x80056160: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_12:
    // 0x80056164: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056168: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005616C: jal         0x80005D44
    // 0x80056170: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x80056170: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80056174: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056178: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005617C: jal         0x80005E90
    // 0x80056180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_14;
    // 0x80056180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80056184: lw          $a1, 0x25C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X25C);
    // 0x80056188: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005618C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80056190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056194: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80056198: jal         0x80005C34
    // 0x8005619C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_15;
    // 0x8005619C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_15:
    // 0x800561A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800561A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800561A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800561AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800561B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800561B4: jal         0x80005B00
    // 0x800561B8: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x800561B8: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    after_16:
    // 0x800561BC: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x800561C0: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x800561C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800561C8: jal         0x80005D44
    // 0x800561CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x800561CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x800561D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800561D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800561D8: jal         0x80005E90
    // 0x800561DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x800561DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x800561E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800561E4: jal         0x80006EB8
    // 0x800561E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x800561E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_19:
    // 0x800561EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800561F0: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x800561F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800561F8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800561FC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80056200: sw          $t5, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r13;
    // 0x80056204: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80056208: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005620C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80056210: jal         0x80005740
    // 0x80056214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x80056214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_80056218:
    // 0x80056218: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005621C:
    // 0x8005621C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80056220: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80056224: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80056228: jr          $ra
    // 0x8005622C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005622C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_tank_800441C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800441C8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800441CC: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x800441D0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800441D4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800441D8: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800441DC: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800441E0: mtc1        $a2, $f30
    ctx->f30.u32l = ctx->r6;
    // 0x800441E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800441E8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800441EC: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800441F0: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x800441F4: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x800441F8: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x800441FC: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80044200: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80044204: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80044208: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8004420C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80044210: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80044214: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80044218: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004421C: lwc1        $f8, 0x5638($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5638);
    // 0x80044220: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80044224: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80044228: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004422C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80044230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80044234: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80044238: jal         0x80005E90
    // 0x8004423C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8004423C: nop

    after_0:
    // 0x80044240: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80044244: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80044248: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004424C: mfc1        $s4, $f18
    ctx->r20 = (int32_t)ctx->f18.u32l;
    // 0x80044250: nop

    // 0x80044254: beql        $s4, $zero, L_800443A0
    if (ctx->r20 == 0) {
        // 0x80044258: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_800443A0;
    }
    goto skip_0;
    // 0x80044258: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x8004425C: blez        $s4, L_8004439C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80044260: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8004439C;
    }
    // 0x80044260: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80044264: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80044268: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8004426C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044270: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80044274: lwc1        $f26, 0x563C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X563C);
    // 0x80044278: lwc1        $f24, 0x88($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004427C: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
    // 0x80044280: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80044284:
    // 0x80044284: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80044288: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004428C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80044290: c.le.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl <= ctx->f20.fl;
    // 0x80044294: nop

    // 0x80044298: bc1fl       L_8004434C
    if (!c1cs) {
        // 0x8004429C: lwc1        $f4, 0x78($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
            goto L_8004434C;
    }
    goto skip_1;
    // 0x8004429C: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    skip_1:
    // 0x800442A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800442A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800442A8: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800442AC: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800442B0: lwc1        $f12, 0x138($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800442B4: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800442B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800442BC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800442C0: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x800442C4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800442C8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800442CC: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x800442D0: jal         0x80044120
    // 0x800442D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_tank_80044120(rdram, ctx);
        goto after_1;
    // 0x800442D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800442D8: beq         $v0, $zero, L_80044390
    if (ctx->r2 == 0) {
        // 0x800442DC: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80044390;
    }
    // 0x800442DC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800442E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800442E4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800442E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800442EC: lwc1        $f16, 0xC4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800442F0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800442F4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800442F8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800442FC: sw          $s5, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->r21;
    // 0x80044300: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80044304: addiu       $s1, $s0, 0xEC
    ctx->r17 = ADD32(ctx->r16, 0XEC);
    // 0x80044308: bc1f        L_80044314
    if (!c1cs) {
        // 0x8004430C: add.s       $f0, $f22, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f22.fl + ctx->f10.fl;
            goto L_80044314;
    }
    // 0x8004430C: add.s       $f0, $f22, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x80044310: sw          $s6, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r22;
L_80044314:
    // 0x80044314: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x80044318: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x8004431C: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80044320: jal         0x8009BC2C
    // 0x80044324: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80044324: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x80044328: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004432C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80044330: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80044334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80044338: jal         0x8009BC2C
    // 0x8004433C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8004433C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80044340: b           L_80044394
    // 0x80044344: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80044394;
    // 0x80044344: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80044348: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
L_8004434C:
    // 0x8004434C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80044350: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044354: lwc1        $f12, 0x138($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80044358: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004435C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80044360: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80044364: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80044368: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8004436C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80044370: jal         0x80044120
    // 0x80044374: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    func_tank_80044120(rdram, ctx);
        goto after_4;
    // 0x80044374: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_4:
    // 0x80044378: beq         $v0, $zero, L_80044390
    if (ctx->r2 == 0) {
        // 0x8004437C: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_80044390;
    }
    // 0x8004437C: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80044380: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044384: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x80044388: sub.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x8004438C: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
L_80044390:
    // 0x80044390: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80044394:
    // 0x80044394: bne         $s3, $s4, L_80044284
    if (ctx->r19 != ctx->r20) {
        // 0x80044398: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_80044284;
    }
    // 0x80044398: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_8004439C:
    // 0x8004439C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_800443A0:
    // 0x800443A0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800443A4: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800443A8: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800443AC: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800443B0: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800443B4: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x800443B8: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800443BC: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800443C0: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x800443C4: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800443C8: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x800443CC: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x800443D0: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x800443D4: jr          $ra
    // 0x800443D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800443D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Timer_Wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800070C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800070CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800070D0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800070D4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800070D8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800070DC: addiu       $t8, $t8, 0x2390
    ctx->r24 = ADD32(ctx->r24, 0X2390);
    // 0x800070E0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800070E4: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x800070E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800070EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800070F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800070F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800070F8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800070FC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80007100: jal         0x800233D0
    // 0x80007104: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    osSetTimer_recomp(rdram, ctx);
        goto after_0;
    // 0x80007104: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80007108: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000710C: addiu       $a0, $a0, 0x2390
    ctx->r4 = ADD32(ctx->r4, 0X2390);
    // 0x80007110: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80007114: jal         0x800205E0
    // 0x80007118: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80007118: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8000711C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80007120: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80007124: jr          $ra
    // 0x80007128: nop

    return;
    // 0x80007128: nop

;}
RECOMP_FUNC void AudioThread_GetFontsForSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ED14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ED18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ED1C: jal         0x8000F010
    // 0x8001ED20: nop

    AudioLoad_GetFontsForSequence(rdram, ctx);
        goto after_0;
    // 0x8001ED20: nop

    after_0:
    // 0x8001ED24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ED28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001ED2C: jr          $ra
    // 0x8001ED30: nop

    return;
    // 0x8001ED30: nop

;}
RECOMP_FUNC void Play_Setup360_CO(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A533C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A5340: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800A5344: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x800A5348: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A534C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800A5350: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800A5354: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A5358: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A535C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A5360: lui         $v0, 0x604
    ctx->r2 = S32(0X604 << 16);
    // 0x800A5364: addiu       $v0, $v0, -0x4F8C
    ctx->r2 = ADD32(ctx->r2, -0X4F8C);
    // 0x800A5368: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A536C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800A5370: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A5374: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A5378: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A537C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A5380: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x800A5384: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5388: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x800A538C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5390: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800A5394: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800A5398: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800A539C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800A53A0: lui         $s5, 0x602
    ctx->r21 = S32(0X602 << 16);
    // 0x800A53A4: addiu       $s5, $s5, 0x760
    ctx->r21 = ADD32(ctx->r21, 0X760);
    // 0x800A53A8: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x800A53AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A53B0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800A53B4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800A53B8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
L_800A53BC:
    // 0x800A53BC: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800A53C0: lh          $v0, 0x10($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X10);
    // 0x800A53C4: bgez        $v0, L_800A53D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A53C8: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_800A53D4;
    }
    // 0x800A53C8: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x800A53CC: b           L_800A548C
    // 0x800A53D0: nop

        goto L_800A548C;
    // 0x800A53D0: nop

L_800A53D4:
    // 0x800A53D4: beql        $at, $zero, L_800A5480
    if (ctx->r1 == 0) {
        // 0x800A53D8: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_800A5480;
    }
    goto skip_0;
    // 0x800A53D8: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x800A53DC: jal         0x800A4F4C
    // 0x800A53E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A53E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A53E4: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x800A53E8: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800A53EC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800A53F0: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A53F4: lh          $t7, 0x10($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10);
    // 0x800A53F8: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x800A53FC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A5400: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800A5404: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800A5408: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x800A540C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A5410: nop

    // 0x800A5414: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5418: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800A541C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800A5420: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800A5424: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800A5428: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800A542C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A5430: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800A5434: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x800A5438: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A543C: nop

    // 0x800A5440: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5444: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x800A5448: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A544C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800A5450: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x800A5454: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A5458: nop

    // 0x800A545C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A5460: jal         0x800612B8
    // 0x800A5464: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800A5464: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x800A5468: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x800A546C: bnel        $s4, $t9, L_800A547C
    if (ctx->r20 != ctx->r25) {
        // 0x800A5470: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_800A547C;
    }
    goto skip_1;
    // 0x800A5470: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_1:
    // 0x800A5474: sw          $s5, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r21;
    // 0x800A5478: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_800A547C:
    // 0x800A547C: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_800A5480:
    // 0x800A5480: slti        $at, $s1, 0xFA0
    ctx->r1 = SIGNED(ctx->r17) < 0XFA0 ? 1 : 0;
    // 0x800A5484: bnel        $at, $zero, L_800A53BC
    if (ctx->r1 != 0) {
        // 0x800A5488: lw          $t3, 0x0($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X0);
            goto L_800A53BC;
    }
    goto skip_2;
    // 0x800A5488: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    skip_2:
L_800A548C:
    // 0x800A548C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800A5490: addiu       $s0, $s0, 0x3400
    ctx->r16 = ADD32(ctx->r16, 0X3400);
    // 0x800A5494: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A5498: addiu       $s5, $zero, 0x320
    ctx->r21 = ADD32(0, 0X320);
    // 0x800A549C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800A54A0: addiu       $s3, $zero, 0xA2
    ctx->r19 = ADD32(0, 0XA2);
    // 0x800A54A4: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
L_800A54A8:
    // 0x800A54A8: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800A54AC: lh          $v0, 0x10($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X10);
    // 0x800A54B0: bltz        $v0, L_800A5540
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A54B4: nop
    
            goto L_800A5540;
    }
    // 0x800A54B4: nop

    // 0x800A54B8: bnel        $s3, $v0, L_800A5538
    if (ctx->r19 != ctx->r2) {
        // 0x800A54BC: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_800A5538;
    }
    goto skip_3;
    // 0x800A54BC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_3:
    // 0x800A54C0: jal         0x80061394
    // 0x800A54C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sprite_Initialize(rdram, ctx);
        goto after_2;
    // 0x800A54C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A54C8: sb          $s4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r20;
    // 0x800A54CC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A54D0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800A54D4: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A54D8: lh          $t4, 0x10($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X10);
    // 0x800A54DC: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
    // 0x800A54E0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800A54E4: andi        $a1, $t4, 0xFFFF
    ctx->r5 = ctx->r12 & 0XFFFF;
    // 0x800A54E8: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A54EC: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800A54F0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A54F4: nop

    // 0x800A54F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A54FC: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800A5500: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A5504: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800A5508: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800A550C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800A5510: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800A5514: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800A5518: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x800A551C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800A5520: nop

    // 0x800A5524: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5528: jal         0x800612B8
    // 0x800A552C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x800A552C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x800A5530: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
    // 0x800A5534: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_800A5538:
    // 0x800A5538: bnel        $s1, $s5, L_800A54A8
    if (ctx->r17 != ctx->r21) {
        // 0x800A553C: lw          $t0, 0x0($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X0);
            goto L_800A54A8;
    }
    goto skip_4;
    // 0x800A553C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    skip_4:
L_800A5540:
    // 0x800A5540: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5544: jal         0x80061404
    // 0x800A5548: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_4;
    // 0x800A5548: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_4:
    // 0x800A554C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A5550: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A5554: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5558: sb          $t3, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r11;
    // 0x800A555C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5560: swc1        $f0, -0xEEC($at)
    MEM_W(-0XEEC, ctx->r1) = ctx->f0.u32l;
    // 0x800A5564: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5568: swc1        $f0, -0xEE8($at)
    MEM_W(-0XEE8, ctx->r1) = ctx->f0.u32l;
    // 0x800A556C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5570: swc1        $f0, -0xEE4($at)
    MEM_W(-0XEE4, ctx->r1) = ctx->f0.u32l;
    // 0x800A5574: addiu       $a1, $zero, 0x124
    ctx->r5 = ADD32(0, 0X124);
    // 0x800A5578: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A557C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5580: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x800A5584: jal         0x800612B8
    // 0x800A5588: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x800A5588: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_5:
    // 0x800A558C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5590: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A5594: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A5598: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A559C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A55A0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800A55A4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800A55A8: jr          $ra
    // 0x800A55AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A55AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_edisplay_8005A088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A088: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005A08C: jr          $ra
    // 0x8005A090: nop

    return;
    // 0x8005A090: nop

;}
RECOMP_FUNC void RCP_SetupDL_81(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA520: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA524: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA528: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA52C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA530: addiu       $t8, $t8, 0x4878
    ctx->r24 = ADD32(ctx->r24, 0X4878);
    // 0x800BA534: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA538: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA53C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA540: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA544: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA548: jr          $ra
    // 0x800BA54C: nop

    return;
    // 0x800BA54C: nop

;}
RECOMP_FUNC void RCP_SetupDL_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B99F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B99F4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B99F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B99FC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9A00: addiu       $t8, $t8, 0x3D80
    ctx->r24 = ADD32(ctx->r24, 0X3D80);
    // 0x800B9A04: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9A08: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B9A0C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9A10: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B9A14: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9A18: jr          $ra
    // 0x800B9A1C: nop

    return;
    // 0x800B9A1C: nop

;}
RECOMP_FUNC void HUD_IncomingMsg_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B1B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008B1BC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008B1C0: jal         0x800B8DD0
    // 0x8008B1C4: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008B1C4: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x8008B1C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8008B1CC: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8008B1D0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008B1D4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008B1D8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8008B1DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008B1E0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8008B1E4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008B1E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008B1EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B1F0: lw          $a0, 0x1790($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1790);
    // 0x8008B1F4: bgez        $a0, L_8008B204
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008B1F8: sra         $t9, $a0, 1
        ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8008B204;
    }
    // 0x8008B1F8: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8008B1FC: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x8008B200: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8008B204:
    // 0x8008B204: beq         $t9, $zero, L_8008B27C
    if (ctx->r25 == 0) {
        // 0x8008B208: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008B27C;
    }
    // 0x8008B208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B20C: beq         $t9, $at, L_8008B260
    if (ctx->r25 == ctx->r1) {
        // 0x8008B210: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008B260;
    }
    // 0x8008B210: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008B214: beq         $t9, $at, L_8008B240
    if (ctx->r25 == ctx->r1) {
        // 0x8008B218: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008B240;
    }
    // 0x8008B218: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008B21C: bne         $t9, $at, L_8008B294
    if (ctx->r25 != ctx->r1) {
        // 0x8008B220: lui         $at, 0x430E
        ctx->r1 = S32(0X430E << 16);
            goto L_8008B294;
    }
    // 0x8008B220: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x8008B224: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008B228: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x8008B22C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008B230: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008B234: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008B238: jal         0x8008556C
    // 0x8008B23C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    HUD_IncomingMsgSignal3_Draw(rdram, ctx);
        goto after_1;
    // 0x8008B23C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
L_8008B240:
    // 0x8008B240: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x8008B244: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008B248: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8008B24C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B250: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008B254: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008B258: jal         0x80085514
    // 0x8008B25C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    HUD_IncomingMsgSignal2_Draw(rdram, ctx);
        goto after_2;
    // 0x8008B25C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
L_8008B260:
    // 0x8008B260: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x8008B264: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008B268: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008B26C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008B270: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008B274: jal         0x800854BC
    // 0x8008B278: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    HUD_IncomingMsgSignal1_Draw(rdram, ctx);
        goto after_3;
    // 0x8008B278: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_3:
L_8008B27C:
    // 0x8008B27C: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x8008B280: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008B284: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008B288: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008B28C: jal         0x80085464
    // 0x8008B290: nop

    HUD_IncomingMsgButton_Draw(rdram, ctx);
        goto after_4;
    // 0x8008B290: nop

    after_4:
L_8008B294:
    // 0x8008B294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B29C: jr          $ra
    // 0x8008B2A0: nop

    return;
    // 0x8008B2A0: nop

;}
RECOMP_FUNC void PlayerShot_UpdateShot7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BACC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003BAD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003BAD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003BAD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BAE0: jal         0x8003B55C
    // 0x8003BAE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    PlayerShot_UpdateBeam(rdram, ctx);
        goto after_0;
    // 0x8003BAE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8003BAE8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003BAEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003BAF0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8003BAF4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8003BAF8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003BAFC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8003BB00: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8003BB04: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8003BB08: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003BB0C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8003BB10: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003BB14: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8003BB18: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8003BB1C: jal         0x800A3690
    // 0x8003BB20: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_col2_800A3690(rdram, ctx);
        goto after_1;
    // 0x8003BB20: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003BB24: bnel        $v0, $zero, L_8003BB38
    if (ctx->r2 != 0) {
        // 0x8003BB28: sw          $zero, 0x58($s0)
        MEM_W(0X58, ctx->r16) = 0;
            goto L_8003BB38;
    }
    goto skip_0;
    // 0x8003BB28: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    skip_0:
    // 0x8003BB2C: jal         0x80036318
    // 0x8003BB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_2;
    // 0x8003BB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003BB34: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
L_8003BB38:
    // 0x8003BB38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BB3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8003BB44: jr          $ra
    // 0x8003BB48: nop

    return;
    // 0x8003BB48: nop

;}
RECOMP_FUNC void AudioSeq_SeqLayerFree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001410C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80014110: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80014114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014118: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8001411C: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x80014120: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80014124: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, 0X30B0);
    // 0x80014128: beq         $a2, $zero, L_8001414C
    if (ctx->r6 == 0) {
        // 0x8001412C: addiu       $a1, $a2, 0x6C
        ctx->r5 = ADD32(ctx->r6, 0X6C);
            goto L_8001414C;
    }
    // 0x8001412C: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    // 0x80014130: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80014134: jal         0x800145BC
    // 0x80014138: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_0;
    // 0x80014138: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001413C: jal         0x800140D0
    // 0x80014140: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    AudioSeq_SeqLayerDisable(rdram, ctx);
        goto after_1;
    // 0x80014140: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80014144: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80014148: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
L_8001414C:
    // 0x8001414C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80014154: jr          $ra
    // 0x80014158: nop

    return;
    // 0x80014158: nop

;}
RECOMP_FUNC void CoSkibot_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B9A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005B9A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005B9AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005B9B0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005B9B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005B9B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005B9BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005B9C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005B9C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005B9C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005B9CC: jal         0x80005B00
    // 0x8005B9D0: lui         $a2, 0xC2F8
    ctx->r6 = S32(0XC2F8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005B9D0: lui         $a2, 0xC2F8
    ctx->r6 = S32(0XC2F8 << 16);
    after_0:
    // 0x8005B9D4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8005B9D8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8005B9DC: addiu       $a0, $a0, -0x6AD8
    ctx->r4 = ADD32(ctx->r4, -0X6AD8);
    // 0x8005B9E0: lh          $a1, 0xB6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XB6);
    // 0x8005B9E4: addiu       $a2, $v0, 0x18C
    ctx->r6 = ADD32(ctx->r2, 0X18C);
    // 0x8005B9E8: jal         0x8009AA20
    // 0x8005B9EC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x8005B9EC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005B9F0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005B9F4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8005B9F8: addiu       $t8, $t8, 0x4660
    ctx->r24 = ADD32(ctx->r24, 0X4660);
    // 0x8005B9FC: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8005BA00: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8005BA04: addiu       $a1, $a1, -0x698C
    ctx->r5 = ADD32(ctx->r5, -0X698C);
    // 0x8005BA08: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8005BA0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005BA10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005BA14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005BA18: jal         0x8009A72C
    // 0x8005BA1C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x8005BA1C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x8005BA20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005BA24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005BA28: jr          $ra
    // 0x8005BA2C: nop

    return;
    // 0x8005BA2C: nop

;}
RECOMP_FUNC void Wipe_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008468C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084690: beql        $a1, $zero, L_800846E4
    if (ctx->r5 == 0) {
        // 0x80084694: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800846E4;
    }
    goto skip_0;
    // 0x80084694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80084698: beq         $a0, $zero, L_800846B8
    if (ctx->r4 == 0) {
        // 0x8008469C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800846B8;
    }
    // 0x8008469C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800846A0: beq         $a0, $at, L_800846C8
    if (ctx->r4 == ctx->r1) {
        // 0x800846A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800846C8;
    }
    // 0x800846A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800846A8: beq         $a0, $at, L_800846D8
    if (ctx->r4 == ctx->r1) {
        // 0x800846AC: nop
    
            goto L_800846D8;
    }
    // 0x800846AC: nop

    // 0x800846B0: b           L_800846E4
    // 0x800846B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800846E4;
    // 0x800846B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800846B8:
    // 0x800846B8: jal         0x80084488
    // 0x800846BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Wipe_Circular(rdram, ctx);
        goto after_0;
    // 0x800846BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800846C0: b           L_800846E4
    // 0x800846C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800846E4;
    // 0x800846C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800846C8:
    // 0x800846C8: jal         0x80084370
    // 0x800846CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Wipe_Horizontal(rdram, ctx);
        goto after_1;
    // 0x800846CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800846D0: b           L_800846E4
    // 0x800846D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800846E4;
    // 0x800846D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800846D8:
    // 0x800846D8: jal         0x800843FC
    // 0x800846DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Wipe_Vertical(rdram, ctx);
        goto after_2;
    // 0x800846DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800846E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800846E4:
    // 0x800846E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800846E8: jr          $ra
    // 0x800846EC: nop

    return;
    // 0x800846EC: nop

;}
RECOMP_FUNC void PlayerShot_CheckObjectHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036874: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80036878: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x8003687C: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80036880: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80036884: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80036888: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8003688C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80036890: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80036894: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x80036898: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x8003689C: sdc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X60, ctx->r29);
    // 0x800368A0: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x800368A4: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800368A8: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800368AC: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800368B0: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800368B4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800368B8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800368BC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800368C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800368C4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800368C8: beq         $v0, $at, L_800368D4
    if (ctx->r2 == ctx->r1) {
        // 0x800368CC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800368D4;
    }
    // 0x800368CC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800368D0: bne         $v0, $at, L_800368E0
    if (ctx->r2 != ctx->r1) {
        // 0x800368D4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800368E0;
    }
L_800368D4:
    // 0x800368D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800368D8: b           L_800368F0
    // 0x800368DC: lwc1        $f2, 0x5100($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5100);
        goto L_800368F0;
    // 0x800368DC: lwc1        $f2, 0x5100($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5100);
L_800368E0:
    // 0x800368E0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800368E4: bne         $v0, $at, L_800368F0
    if (ctx->r2 != ctx->r1) {
        // 0x800368E8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800368F0;
    }
    // 0x800368E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800368EC: lwc1        $f2, 0x5104($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5104);
L_800368F0:
    // 0x800368F0: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800368F4: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800368F8: sub.s       $f0, $f4, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x800368FC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036900: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80036904: nop

    // 0x80036908: bc1fl       L_80036F50
    if (!c1cs) {
        // 0x8003690C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036F50;
    }
    goto skip_0;
    // 0x8003690C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80036910: lwc1        $f28, 0x4($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80036914: lwc1        $f6, 0x4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80036918: sub.s       $f0, $f6, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f28.fl;
    // 0x8003691C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036920: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80036924: nop

    // 0x80036928: bc1fl       L_80036F50
    if (!c1cs) {
        // 0x8003692C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036F50;
    }
    goto skip_1;
    // 0x8003692C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80036930: lwc1        $f26, 0x8($s2)
    ctx->f26.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80036934: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036938: sub.s       $f0, $f8, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8003693C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036940: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80036944: nop

    // 0x80036948: bc1fl       L_80036F50
    if (!c1cs) {
        // 0x8003694C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036F50;
    }
    goto skip_2;
    // 0x8003694C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80036950: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80036954: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80036958: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8003695C: nop

    // 0x80036960: beq         $t7, $zero, L_80036F4C
    if (ctx->r15 == 0) {
        // 0x80036964: sw          $t7, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r15;
            goto L_80036F4C;
    }
    // 0x80036964: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80036968: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x8003696C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036970: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80036974: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80036978: beq         $at, $zero, L_800369B4
    if (ctx->r1 == 0) {
        // 0x8003697C: mov.s       $f30, $f0
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
            goto L_800369B4;
    }
    // 0x8003697C: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x80036980: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80036984: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80036988: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003698C: lw          $t0, 0x1AA8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1AA8);
    // 0x80036990: bnel        $t0, $zero, L_800369A8
    if (ctx->r8 != 0) {
        // 0x80036994: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_800369A8;
    }
    goto skip_3;
    // 0x80036994: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_3:
    // 0x80036998: lhu         $t1, 0x2($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X2);
    // 0x8003699C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800369A0: bne         $t1, $at, L_800369B4
    if (ctx->r9 != ctx->r1) {
        // 0x800369A4: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_800369B4;
    }
    // 0x800369A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800369A8:
    // 0x800369A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800369AC: nop

    // 0x800369B0: add.s       $f30, $f0, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f0.fl + ctx->f6.fl;
L_800369B4:
    // 0x800369B4: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x800369B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800369BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800369C0: blez        $t2, L_80036F4C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800369C4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80036F4C;
    }
    // 0x800369C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800369C8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800369CC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800369D0: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x800369D4: lwc1        $f20, 0x5108($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5108);
L_800369D8:
    // 0x800369D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800369DC: lwc1        $f8, 0x510C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X510C);
    // 0x800369E0: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800369E4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800369E8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x800369EC: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x800369F0: mov.s       $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    ctx->f18.fl = ctx->f22.fl;
    // 0x800369F4: mov.s       $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    ctx->f16.fl = ctx->f22.fl;
    // 0x800369F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800369FC: bc1f        L_80036A0C
    if (!c1cs) {
        // 0x80036A00: nop
    
            goto L_80036A0C;
    }
    // 0x80036A00: nop

    // 0x80036A04: b           L_80036F50
    // 0x80036A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036F50;
    // 0x80036A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036A0C:
    // 0x80036A0C: lwc1        $f10, 0x5110($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5110);
    // 0x80036A10: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80036A14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80036A18: c.eq.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl == ctx->f2.fl;
    // 0x80036A1C: nop

    // 0x80036A20: bc1fl       L_80036A40
    if (!c1cs) {
        // 0x80036A24: c.eq.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
            goto L_80036A40;
    }
    goto skip_4;
    // 0x80036A24: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    skip_4:
    // 0x80036A28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80036A2C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036A30: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80036A34: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80036A38: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80036A3C: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
L_80036A40:
    // 0x80036A40: nop

    // 0x80036A44: bc1fl       L_80036A9C
    if (!c1cs) {
        // 0x80036A48: neg.s       $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
            goto L_80036A9C;
    }
    goto skip_5;
    // 0x80036A48: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    skip_5:
    // 0x80036A4C: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80036A50: c.eq.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl == ctx->f4.fl;
    // 0x80036A54: nop

    // 0x80036A58: bc1fl       L_80036A9C
    if (!c1cs) {
        // 0x80036A5C: neg.s       $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
            goto L_80036A9C;
    }
    goto skip_6;
    // 0x80036A5C: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    skip_6:
    // 0x80036A60: lwc1        $f6, 0x10($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80036A64: c.eq.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl == ctx->f6.fl;
    // 0x80036A68: nop

    // 0x80036A6C: bc1fl       L_80036A9C
    if (!c1cs) {
        // 0x80036A70: neg.s       $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
            goto L_80036A9C;
    }
    goto skip_7;
    // 0x80036A70: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    skip_7:
    // 0x80036A74: c.eq.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl == ctx->f22.fl;
    // 0x80036A78: nop

    // 0x80036A7C: bc1fl       L_80036A9C
    if (!c1cs) {
        // 0x80036A80: neg.s       $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
            goto L_80036A9C;
    }
    goto skip_8;
    // 0x80036A80: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    skip_8:
    // 0x80036A84: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80036A88: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036A8C: lwc1        $f16, 0xC($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80036A90: b           L_80036BC4
    // 0x80036A94: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
        goto L_80036BC4;
    // 0x80036A94: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80036A98: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
L_80036A9C:
    // 0x80036A9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80036AA0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80036AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80036AA8: swc1        $f16, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f16.u32l;
    // 0x80036AAC: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x80036AB0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80036AB4: jal         0x80005FE0
    // 0x80036AB8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x80036AB8: nop

    after_0:
    // 0x80036ABC: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80036AC0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80036AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80036AC8: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x80036ACC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80036AD0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80036AD4: jal         0x80005D44
    // 0x80036AD8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80036AD8: nop

    after_1:
    // 0x80036ADC: lwc1        $f18, 0xC4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80036AE0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80036AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80036AE8: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80036AEC: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80036AF0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80036AF4: jal         0x80005E90
    // 0x80036AF8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80036AF8: nop

    after_2:
    // 0x80036AFC: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80036B00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80036B04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80036B08: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80036B0C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80036B10: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80036B14: jal         0x80005FE0
    // 0x80036B18: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80036B18: nop

    after_3:
    // 0x80036B1C: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80036B20: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80036B24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80036B28: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80036B2C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80036B30: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80036B34: jal         0x80005D44
    // 0x80036B38: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80036B38: nop

    after_4:
    // 0x80036B3C: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80036B40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80036B44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80036B48: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80036B4C: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80036B50: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80036B54: jal         0x80005E90
    // 0x80036B58: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80036B58: nop

    after_5:
    // 0x80036B5C: lwc1        $f6, 0x4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80036B60: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80036B64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80036B68: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80036B6C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80036B70: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x80036B74: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80036B78: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80036B7C: lwc1        $f4, 0x8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036B80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80036B84: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x80036B88: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036B8C: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80036B90: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80036B94: jal         0x80006A20
    // 0x80036B98: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x80036B98: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80036B9C: lwc1        $f28, 0x4($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80036BA0: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80036BA4: lwc1        $f26, 0x8($s2)
    ctx->f26.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80036BA8: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80036BAC: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036BB0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80036BB4: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80036BB8: add.s       $f12, $f28, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f28.fl + ctx->f8.fl;
    // 0x80036BBC: add.s       $f14, $f26, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f26.fl + ctx->f10.fl;
    // 0x80036BC0: add.s       $f16, $f24, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f24.fl + ctx->f4.fl;
L_80036BC4:
    // 0x80036BC4: add.s       $f6, $f2, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80036BC8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80036BCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80036BD0: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036BD4: sub.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80036BD8: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x80036BDC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80036BE0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036BE4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80036BE8: nop

    // 0x80036BEC: bc1fl       L_80036F44
    if (!c1cs) {
        // 0x80036BF0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80036F44;
    }
    goto skip_9;
    // 0x80036BF0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_9:
    // 0x80036BF4: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80036BF8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036BFC: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x80036C00: add.s       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80036C04: sub.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80036C08: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036C0C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80036C10: nop

    // 0x80036C14: bc1fl       L_80036F44
    if (!c1cs) {
        // 0x80036C18: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80036F44;
    }
    goto skip_10;
    // 0x80036C18: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_10:
    // 0x80036C1C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80036C20: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80036C24: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x80036C28: add.s       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80036C2C: sub.s       $f0, $f8, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80036C30: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036C34: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80036C38: nop

    // 0x80036C3C: bc1fl       L_80036F44
    if (!c1cs) {
        // 0x80036C40: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80036F44;
    }
    goto skip_11;
    // 0x80036C40: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_11:
    // 0x80036C44: lhu         $t3, 0x2($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X2);
    // 0x80036C48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036C4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036C50: bnel        $t3, $at, L_80036C6C
    if (ctx->r11 != ctx->r1) {
        // 0x80036C54: lhu         $v0, 0x2($s2)
        ctx->r2 = MEM_HU(ctx->r18, 0X2);
            goto L_80036C6C;
    }
    goto skip_12;
    // 0x80036C54: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    skip_12:
    // 0x80036C58: jal         0x80060FBC
    // 0x80036C5C: addiu       $a1, $s3, 0x38
    ctx->r5 = ADD32(ctx->r19, 0X38);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x80036C5C: addiu       $a1, $s3, 0x38
    ctx->r5 = ADD32(ctx->r19, 0X38);
    after_7:
    // 0x80036C60: b           L_80036F50
    // 0x80036C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036F50;
    // 0x80036C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036C68: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
L_80036C6C:
    // 0x80036C6C: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x80036C70: bne         $at, $zero, L_80036C80
    if (ctx->r1 != 0) {
        // 0x80036C74: slti        $at, $v0, 0x124
        ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
            goto L_80036C80;
    }
    // 0x80036C74: slti        $at, $v0, 0x124
    ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
    // 0x80036C78: bnel        $at, $zero, L_80036C90
    if (ctx->r1 != 0) {
        // 0x80036C7C: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80036C90;
    }
    goto skip_13;
    // 0x80036C7C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    skip_13:
L_80036C80:
    // 0x80036C80: jal         0x80036318
    // 0x80036C84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_8;
    // 0x80036C84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x80036C88: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x80036C8C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
L_80036C90:
    // 0x80036C90: beq         $v0, $at, L_80036CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80036C94: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80036CE8;
    }
    // 0x80036C94: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80036C98: bnel        $v0, $at, L_80036CA8
    if (ctx->r2 != ctx->r1) {
        // 0x80036C9C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80036CA8;
    }
    goto skip_14;
    // 0x80036C9C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_14:
    // 0x80036CA0: beq         $s4, $zero, L_80036CE8
    if (ctx->r20 == 0) {
        // 0x80036CA4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80036CE8;
    }
    // 0x80036CA4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80036CA8:
    // 0x80036CA8: bnel        $v0, $at, L_80036CB8
    if (ctx->r2 != ctx->r1) {
        // 0x80036CAC: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80036CB8;
    }
    goto skip_15;
    // 0x80036CAC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_15:
    // 0x80036CB0: beq         $s4, $zero, L_80036CE8
    if (ctx->r20 == 0) {
        // 0x80036CB4: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80036CE8;
    }
    // 0x80036CB4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
L_80036CB8:
    // 0x80036CB8: bnel        $v0, $at, L_80036CC8
    if (ctx->r2 != ctx->r1) {
        // 0x80036CBC: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80036CC8;
    }
    goto skip_16;
    // 0x80036CBC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_16:
    // 0x80036CC0: beq         $s4, $zero, L_80036CE8
    if (ctx->r20 == 0) {
        // 0x80036CC4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80036CE8;
    }
    // 0x80036CC4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_80036CC8:
    // 0x80036CC8: bne         $v0, $at, L_80036CD4
    if (ctx->r2 != ctx->r1) {
        // 0x80036CCC: slti        $at, $s4, 0x3
        ctx->r1 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
            goto L_80036CD4;
    }
    // 0x80036CCC: slti        $at, $s4, 0x3
    ctx->r1 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x80036CD0: bne         $at, $zero, L_80036CE8
    if (ctx->r1 != 0) {
        // 0x80036CD4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80036CE8;
    }
L_80036CD4:
    // 0x80036CD4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80036CD8: beq         $v0, $at, L_80036CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80036CDC: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80036CE8;
    }
    // 0x80036CDC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80036CE0: bnel        $v0, $at, L_80036F24
    if (ctx->r2 != ctx->r1) {
        // 0x80036CE4: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_80036F24;
    }
    goto skip_17;
    // 0x80036CE4: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    skip_17:
L_80036CE8:
    // 0x80036CE8: lwc1        $f28, 0x4($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80036CEC: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80036CF0: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80036CF4: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036CF8: add.s       $f18, $f28, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f28.fl + ctx->f6.fl;
    // 0x80036CFC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80036D00: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80036D04: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x80036D08: sub.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80036D0C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80036D10: nop

    // 0x80036D14: bc1fl       L_80036DC8
    if (!c1cs) {
        // 0x80036D18: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_80036DC8;
    }
    goto skip_18;
    // 0x80036D18: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_18:
    // 0x80036D1C: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036D20: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80036D24: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036D28: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80036D2C: add.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f24.fl + ctx->f4.fl;
    // 0x80036D30: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80036D34: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80036D38: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80036D3C: nop

    // 0x80036D40: bc1fl       L_80036D74
    if (!c1cs) {
        // 0x80036D44: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80036D74;
    }
    goto skip_19;
    // 0x80036D44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_19:
    // 0x80036D48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036D4C: nop

    // 0x80036D50: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80036D54: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
    // 0x80036D58: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80036D5C: lwc1        $f28, 0x4($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80036D60: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036D64: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036D68: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80036D6C: add.s       $f18, $f10, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x80036D70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80036D74:
    // 0x80036D74: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80036D78: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036D7C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80036D80: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80036D84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036D88: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80036D8C: add.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80036D90: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80036D94: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80036D98: add.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80036D9C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80036DA0: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80036DA4: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80036DA8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80036DAC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80036DB0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x80036DB4: jal         0x800365E4
    // 0x80036DB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    PlayerShot_Effect344_Spawn(rdram, ctx);
        goto after_9;
    // 0x80036DB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80036DBC: b           L_80036F50
    // 0x80036DC0: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_80036F50;
    // 0x80036DC0: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // 0x80036DC4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
L_80036DC8:
    // 0x80036DC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80036DCC: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80036DD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80036DD4: bc1f        L_80036E84
    if (!c1cs) {
        // 0x80036DD8: addiu       $t9, $zero, 0x14
        ctx->r25 = ADD32(0, 0X14);
            goto L_80036E84;
    }
    // 0x80036DD8: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80036DDC: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036DE0: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80036DE4: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036DE8: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80036DEC: add.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x80036DF0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80036DF4: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80036DF8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80036DFC: nop

    // 0x80036E00: bc1fl       L_80036E34
    if (!c1cs) {
        // 0x80036E04: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80036E34;
    }
    goto skip_20;
    // 0x80036E04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_20:
    // 0x80036E08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036E0C: nop

    // 0x80036E10: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80036E14: swc1        $f6, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f6.u32l;
    // 0x80036E18: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80036E1C: lwc1        $f28, 0x4($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80036E20: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036E24: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036E28: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80036E2C: add.s       $f18, $f10, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x80036E30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80036E34:
    // 0x80036E34: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80036E38: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036E3C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80036E40: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80036E44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036E48: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80036E4C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80036E50: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80036E54: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80036E58: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80036E5C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80036E60: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80036E64: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80036E68: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80036E6C: add.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80036E70: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x80036E74: jal         0x800365E4
    // 0x80036E78: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    PlayerShot_Effect344_Spawn(rdram, ctx);
        goto after_10;
    // 0x80036E78: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80036E7C: b           L_80036F50
    // 0x80036E80: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_80036F50;
    // 0x80036E80: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
L_80036E84:
    // 0x80036E84: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80036E88: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80036E8C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80036E90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036E94: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80036E98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036E9C: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036EA0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036EA4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80036EA8: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80036EAC: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x80036EB0: nop

    // 0x80036EB4: bc1fl       L_80036ED0
    if (!c1cs) {
        // 0x80036EB8: lwc1        $f24, 0xC($s2)
        ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
            goto L_80036ED0;
    }
    goto skip_21;
    // 0x80036EB8: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    skip_21:
    // 0x80036EBC: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x80036EC0: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036EC4: lwc1        $f28, 0x4($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80036EC8: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80036ECC: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
L_80036ED0:
    // 0x80036ED0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80036ED4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036ED8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80036EDC: add.s       $f10, $f24, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f4.fl;
    // 0x80036EE0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80036EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036EE8: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80036EEC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80036EF0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80036EF4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80036EF8: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80036EFC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80036F00: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80036F04: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80036F08: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80036F0C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80036F10: jal         0x800365E4
    // 0x80036F14: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    PlayerShot_Effect344_Spawn(rdram, ctx);
        goto after_11;
    // 0x80036F14: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x80036F18: b           L_80036F50
    // 0x80036F1C: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_80036F50;
    // 0x80036F1C: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // 0x80036F20: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
L_80036F24:
    // 0x80036F24: beq         $at, $zero, L_80036F38
    if (ctx->r1 == 0) {
        // 0x80036F28: addiu       $a0, $s3, 0x4
        ctx->r4 = ADD32(ctx->r19, 0X4);
            goto L_80036F38;
    }
    // 0x80036F28: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    // 0x80036F2C: lui         $a1, 0x2912
    ctx->r5 = S32(0X2912 << 16);
    // 0x80036F30: jal         0x8007A6F0
    // 0x80036F34: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_12;
    // 0x80036F34: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    after_12:
L_80036F38:
    // 0x80036F38: b           L_80036F50
    // 0x80036F3C: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_80036F50;
    // 0x80036F3C: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // 0x80036F40: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80036F44:
    // 0x80036F44: bne         $s4, $t0, L_800369D8
    if (ctx->r20 != ctx->r8) {
        // 0x80036F48: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_800369D8;
    }
    // 0x80036F48: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_80036F4C:
    // 0x80036F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036F50:
    // 0x80036F50: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x80036F54: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80036F58: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80036F5C: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80036F60: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x80036F64: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x80036F68: ldc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X60);
    // 0x80036F6C: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80036F70: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80036F74: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80036F78: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80036F7C: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x80036F80: jr          $ra
    // 0x80036F84: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80036F84: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void ActorTeamBoss_DmgEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800922F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800922F8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800922FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092300: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80092304: lh          $t6, 0xE4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE4);
    // 0x80092308: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8009230C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80092310: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80092314: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80092318: lw          $v0, 0x78B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B0);
    // 0x8009231C: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80092320: beql        $at, $zero, L_800924D0
    if (ctx->r1 == 0) {
        // 0x80092324: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800924D0;
    }
    goto skip_0;
    // 0x80092324: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80092328: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8009232C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80092330: lw          $t9, 0x1C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C8);
    // 0x80092334: beq         $t9, $at, L_800924CC
    if (ctx->r25 == ctx->r1) {
        // 0x80092338: slti        $at, $v0, 0x11
        ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
            goto L_800924CC;
    }
    // 0x80092338: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8009233C: bne         $at, $zero, L_80092348
    if (ctx->r1 != 0) {
        // 0x80092340: addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
            goto L_80092348;
    }
    // 0x80092340: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80092344: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_80092348:
    // 0x80092348: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x8009234C: bnel        $at, $zero, L_8009235C
    if (ctx->r1 != 0) {
        // 0x80092350: slti        $at, $v0, 0x31
        ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
            goto L_8009235C;
    }
    goto skip_1;
    // 0x80092350: slti        $at, $v0, 0x31
    ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
    skip_1:
    // 0x80092354: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x80092358: slti        $at, $v0, 0x31
    ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
L_8009235C:
    // 0x8009235C: bne         $at, $zero, L_80092368
    if (ctx->r1 != 0) {
        // 0x80092360: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80092368;
    }
    // 0x80092360: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80092364: addiu       $v1, $zero, 0x3F
    ctx->r3 = ADD32(0, 0X3F);
L_80092368:
    // 0x80092368: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8009236C: and         $t0, $v0, $v1
    ctx->r8 = ctx->r2 & ctx->r3;
    // 0x80092370: bnel        $t0, $zero, L_800923F8
    if (ctx->r8 != 0) {
        // 0x80092374: sra         $t1, $v1, 2
        ctx->r9 = S32(SIGNED(ctx->r3) >> 2);
            goto L_800923F8;
    }
    goto skip_2;
    // 0x80092374: sra         $t1, $v1, 2
    ctx->r9 = S32(SIGNED(ctx->r3) >> 2);
    skip_2:
    // 0x80092378: jal         0x80004EB0
    // 0x8009237C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8009237C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80092380: jal         0x80004EB0
    // 0x80092384: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80092384: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80092388: jal         0x80004EB0
    // 0x8009238C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8009238C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80092390: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80092394: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80092398: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009239C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800923A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800923A4: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800923A8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800923AC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800923B0: lui         $a3, 0x400C
    ctx->r7 = S32(0X400C << 16);
    // 0x800923B4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800923B8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800923BC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800923C0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800923C4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800923C8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800923CC: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800923D0: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800923D4: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800923D8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800923DC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800923E0: jal         0x8007D10C
    // 0x800923E4: nop

    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_3;
    // 0x800923E4: nop

    after_3:
    // 0x800923E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800923EC: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x800923F0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800923F4: sra         $t1, $v1, 2
    ctx->r9 = S32(SIGNED(ctx->r3) >> 2);
L_800923F8:
    // 0x800923F8: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x800923FC: bnel        $t2, $zero, L_800924D0
    if (ctx->r10 != 0) {
        // 0x80092400: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800924D0;
    }
    goto skip_3;
    // 0x80092400: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80092404: jal         0x80004EB0
    // 0x80092408: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80092408: nop

    after_4:
    // 0x8009240C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80092410: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092414: nop

    // 0x80092418: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8009241C: nop

    // 0x80092420: bc1fl       L_800924D0
    if (!c1cs) {
        // 0x80092424: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800924D0;
    }
    goto skip_4;
    // 0x80092424: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80092428: jal         0x80004EB0
    // 0x8009242C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8009242C: nop

    after_5:
    // 0x80092430: jal         0x80004EB0
    // 0x80092434: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x80092434: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80092438: jal         0x80004EB0
    // 0x8009243C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8009243C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80092440: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80092444: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80092448: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009244C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092450: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80092454: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80092458: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8009245C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80092460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092464: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80092468: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009246C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80092470: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x80092474: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80092478: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8009247C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80092480: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092484: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80092488: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8009248C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80092490: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80092494: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80092498: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8009249C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800924A0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800924A4: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800924A8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800924AC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800924B0: lwc1        $f18, 0x7FA8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7FA8);
    // 0x800924B4: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800924B8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800924BC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800924C0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800924C4: jal         0x8007C120
    // 0x800924C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_8;
    // 0x800924C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_8:
L_800924CC:
    // 0x800924CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800924D0:
    // 0x800924D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800924D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800924D8: jr          $ra
    // 0x800924DC: nop

    return;
    // 0x800924DC: nop

;}
RECOMP_FUNC void __ceil_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEA4: ceil.w.d    $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(ceil(ctx->f12.d));
    // 0x8001FEA8: jr          $ra
    // 0x8001FEAC: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x8001FEAC: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void ItemLasers_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067F70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80067F74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80067F78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80067F7C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80067F80: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x80067F84: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80067F88: bne         $t6, $zero, L_80068004
    if (ctx->r14 != 0) {
        // 0x80067F8C: nop
    
            goto L_80068004;
    }
    // 0x80067F8C: nop

    // 0x80067F90: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80067F94: addiu       $t9, $zero, 0x151
    ctx->r25 = ADD32(0, 0X151);
    // 0x80067F98: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x80067F9C: lbu         $t7, 0x49D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49D);
    // 0x80067FA0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80067FA4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80067FA8: bne         $at, $zero, L_80067FC0
    if (ctx->r1 != 0) {
        // 0x80067FAC: nop
    
            goto L_80067FC0;
    }
    // 0x80067FAC: nop

    // 0x80067FB0: lbu         $t8, 0x49C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49C);
    // 0x80067FB4: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80067FB8: beq         $at, $zero, L_80068004
    if (ctx->r1 == 0) {
        // 0x80067FBC: nop
    
            goto L_80068004;
    }
    // 0x80067FBC: nop

L_80067FC0:
    // 0x80067FC0: jal         0x800612B8
    // 0x80067FC4: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    Object_SetInfo(rdram, ctx);
        goto after_0;
    // 0x80067FC4: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    after_0:
    // 0x80067FC8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80067FCC: addiu       $t0, $zero, 0x7D0
    ctx->r8 = ADD32(0, 0X7D0);
    // 0x80067FD0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80067FD4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80067FD8: sh          $t0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r8;
    // 0x80067FDC: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80067FE0: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x80067FE4: ori         $a0, $a0, 0x302B
    ctx->r4 = ctx->r4 | 0X302B;
    // 0x80067FE8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80067FEC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80067FF0: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    // 0x80067FF4: jal         0x80019218
    // 0x80067FF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80067FF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80067FFC: b           L_80068010
    // 0x80068000: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80068010;
    // 0x80068000: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80068004:
    // 0x80068004: jal         0x80067BEC
    // 0x80068008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ItemPickup_Update(rdram, ctx);
        goto after_2;
    // 0x80068008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006800C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80068010:
    // 0x80068010: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068014: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80068018: jr          $ra
    // 0x8006801C: nop

    return;
    // 0x8006801C: nop

;}
RECOMP_FUNC void Play_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B86CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B86D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B86D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B86D8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B86DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B86E0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B86E4: lw          $a0, 0x7C70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C70);
    // 0x800B86E8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B86EC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B86F0: beq         $a0, $zero, L_800B8714
    if (ctx->r4 == 0) {
        // 0x800B86F4: lui         $a3, 0x40A0
        ctx->r7 = S32(0X40A0 << 16);
            goto L_800B8714;
    }
    // 0x800B86F4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B86F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B86FC: beq         $a0, $at, L_800B8724
    if (ctx->r4 == ctx->r1) {
        // 0x800B8700: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B8724;
    }
    // 0x800B8700: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8704: beql        $a0, $at, L_800B8738
    if (ctx->r4 == ctx->r1) {
        // 0x800B8708: lui         $at, 0x425C
        ctx->r1 = S32(0X425C << 16);
            goto L_800B8738;
    }
    goto skip_0;
    // 0x800B8708: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    skip_0:
    // 0x800B870C: b           L_800B8748
    // 0x800B8710: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
        goto L_800B8748;
    // 0x800B8710: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800B8714:
    // 0x800B8714: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800B8718: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B871C: b           L_800B8744
    // 0x800B8720: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
        goto L_800B8744;
    // 0x800B8720: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
L_800B8724:
    // 0x800B8724: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800B8728: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B872C: b           L_800B8744
    // 0x800B8730: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
        goto L_800B8744;
    // 0x800B8730: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x800B8734: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
L_800B8738:
    // 0x800B8738: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B873C: nop

    // 0x800B8740: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_800B8744:
    // 0x800B8744: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800B8748:
    // 0x800B8748: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B874C: addiu       $a0, $a0, 0x1A3C
    ctx->r4 = ADD32(ctx->r4, 0X1A3C);
    // 0x800B8750: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800B8754: jal         0x8009BC2C
    // 0x800B8758: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B8758: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800B875C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B8760: addiu       $v0, $v0, 0x7E84
    ctx->r2 = ADD32(ctx->r2, 0X7E84);
    // 0x800B8764: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8768: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x800B876C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B8770: beq         $t6, $zero, L_800B88D4
    if (ctx->r14 == 0) {
        // 0x800B8774: nop
    
            goto L_800B88D4;
    }
    // 0x800B8774: nop

    // 0x800B8778: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B877C: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x800B8780: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B8784: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8788: beq         $s1, $t8, L_800B87A4
    if (ctx->r17 == ctx->r24) {
        // 0x800B878C: sw          $t7, 0x7880($at)
        MEM_W(0X7880, ctx->r1) = ctx->r15;
            goto L_800B87A4;
    }
    // 0x800B878C: sw          $t7, 0x7880($at)
    MEM_W(0X7880, ctx->r1) = ctx->r15;
    // 0x800B8790: jal         0x80006F38
    // 0x800B8794: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
    Memory_Allocate(rdram, ctx);
        goto after_1;
    // 0x800B8794: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
    after_1:
    // 0x800B8798: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B879C: addiu       $v1, $v1, -0x7D58
    ctx->r3 = ADD32(ctx->r3, -0X7D58);
    // 0x800B87A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800B87A4:
    // 0x800B87A4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B87A8: addiu       $v1, $v1, -0x7D58
    ctx->r3 = ADD32(ctx->r3, -0X7D58);
    // 0x800B87AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B87B0: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
L_800B87B4:
    // 0x800B87B4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800B87B8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800B87BC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x800B87C0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800B87C4: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800B87C8: sb          $zero, 0x58($t2)
    MEM_B(0X58, ctx->r10) = 0;
    // 0x800B87CC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800B87D0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800B87D4: sb          $zero, 0xB0($t4)
    MEM_B(0XB0, ctx->r12) = 0;
    // 0x800B87D8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800B87DC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800B87E0: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, 0X160);
    // 0x800B87E4: bne         $v0, $a0, L_800B87B4
    if (ctx->r2 != ctx->r4) {
        // 0x800B87E8: sb          $zero, 0x108($t6)
        MEM_B(0X108, ctx->r14) = 0;
            goto L_800B87B4;
    }
    // 0x800B87E8: sb          $zero, 0x108($t6)
    MEM_B(0X108, ctx->r14) = 0;
    // 0x800B87EC: jal         0x800A6148
    // 0x800B87F0: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_2;
    // 0x800B87F0: nop

    after_2:
    // 0x800B87F4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B87F8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800B87FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B8800: bne         $v0, $zero, L_800B8818
    if (ctx->r2 != 0) {
        // 0x800B8804: nop
    
            goto L_800B8818;
    }
    // 0x800B8804: nop

    // 0x800B8808: jal         0x800A5338
    // 0x800B880C: nop

    Play_Setup360_CO(rdram, ctx);
        goto after_3;
    // 0x800B880C: nop

    after_3:
    // 0x800B8810: b           L_800B8858
    // 0x800B8814: nop

        goto L_800B8858;
    // 0x800B8814: nop

L_800B8818:
    // 0x800B8818: bne         $v0, $at, L_800B8830
    if (ctx->r2 != ctx->r1) {
        // 0x800B881C: nop
    
            goto L_800B8830;
    }
    // 0x800B881C: nop

    // 0x800B8820: jal         0x800A55B0
    // 0x800B8824: nop

    Play_Setup360_SY(rdram, ctx);
        goto after_4;
    // 0x800B8824: nop

    after_4:
    // 0x800B8828: b           L_800B8858
    // 0x800B882C: nop

        goto L_800B8858;
    // 0x800B882C: nop

L_800B8830:
    // 0x800B8830: bne         $s1, $v0, L_800B8848
    if (ctx->r17 != ctx->r2) {
        // 0x800B8834: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800B8848;
    }
    // 0x800B8834: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B8838: jal         0x800A57E0
    // 0x800B883C: nop

    Play_Setup360_AND(rdram, ctx);
        goto after_5;
    // 0x800B883C: nop

    after_5:
    // 0x800B8840: b           L_800B8858
    // 0x800B8844: nop

        goto L_800B8858;
    // 0x800B8844: nop

L_800B8848:
    // 0x800B8848: bne         $v0, $at, L_800B8858
    if (ctx->r2 != ctx->r1) {
        // 0x800B884C: nop
    
            goto L_800B8858;
    }
    // 0x800B884C: nop

    // 0x800B8850: jal         0x80198C50
    // 0x800B8854: nop

    Training_Setup360(rdram, ctx);
        goto after_6;
    // 0x800B8854: nop

    after_6:
L_800B8858:
    // 0x800B8858: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800B885C: addiu       $s2, $s2, -0x7D80
    ctx->r18 = ADD32(ctx->r18, -0X7D80);
    // 0x800B8860: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800B8864: jal         0x800B86A4
    // 0x800B8868: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Play_SetupZPos360(rdram, ctx);
        goto after_7;
    // 0x800B8868: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_7:
    // 0x800B886C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800B8870: jal         0x800B86A4
    // 0x800B8874: addiu       $a0, $a0, 0x138
    ctx->r4 = ADD32(ctx->r4, 0X138);
    Play_SetupZPos360(rdram, ctx);
        goto after_8;
    // 0x800B8874: addiu       $a0, $a0, 0x138
    ctx->r4 = ADD32(ctx->r4, 0X138);
    after_8:
    // 0x800B8878: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B887C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8880: lwc1        $f2, -0x7418($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7418);
    // 0x800B8884: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800B8888: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B888C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B8890: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800B8894: addiu       $v1, $v1, 0x7D20
    ctx->r3 = ADD32(ctx->r3, 0X7D20);
    // 0x800B8898: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B889C: addiu       $a0, $a0, 0x7D08
    ctx->r4 = ADD32(ctx->r4, 0X7D08);
    // 0x800B88A0: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x800B88A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B88A8: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800B88AC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800B88B0: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
    // 0x800B88B4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800B88B8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B88BC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800B88C0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800B88C4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B88C8: swc1        $f0, 0x140($t7)
    MEM_W(0X140, ctx->r15) = ctx->f0.u32l;
    // 0x800B88CC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800B88D0: swc1        $f0, 0x144($t8)
    MEM_W(0X144, ctx->r24) = ctx->f0.u32l;
L_800B88D4:
    // 0x800B88D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B88D8: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
    // 0x800B88DC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800B88E0: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800B88E4: beq         $a1, $v0, L_800B8900
    if (ctx->r5 == ctx->r2) {
        // 0x800B88E8: addiu       $s2, $s2, -0x7D80
        ctx->r18 = ADD32(ctx->r18, -0X7D80);
            goto L_800B8900;
    }
    // 0x800B88E8: addiu       $s2, $s2, -0x7D80
    ctx->r18 = ADD32(ctx->r18, -0X7D80);
    // 0x800B88EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B88F0: addiu       $v1, $v1, 0x7DB0
    ctx->r3 = ADD32(ctx->r3, 0X7DB0);
    // 0x800B88F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800B88F8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B88FC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800B8900:
    // 0x800B8900: beq         $v0, $zero, L_800B892C
    if (ctx->r2 == 0) {
        // 0x800B8904: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_800B892C;
    }
    // 0x800B8904: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B8908: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B890C: beq         $v0, $a3, L_800B8948
    if (ctx->r2 == ctx->r7) {
        // 0x800B8910: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B8948;
    }
    // 0x800B8910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8914: beq         $v0, $at, L_800B89B0
    if (ctx->r2 == ctx->r1) {
        // 0x800B8918: nop
    
            goto L_800B89B0;
    }
    // 0x800B8918: nop

    // 0x800B891C: beq         $v0, $a1, L_800B8BB4
    if (ctx->r2 == ctx->r5) {
        // 0x800B8920: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800B8BB4;
    }
    // 0x800B8920: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B8924: b           L_800B8DB8
    // 0x800B8928: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B8DB8;
    // 0x800B8928: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B892C:
    // 0x800B892C: lw          $t1, 0x783C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X783C);
    // 0x800B8930: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B8934: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8938: bnel        $t1, $zero, L_800B8DB8
    if (ctx->r9 != 0) {
        // 0x800B893C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B8DB8;
    }
    goto skip_1;
    // 0x800B893C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x800B8940: b           L_800B8DB4
    // 0x800B8944: sw          $t2, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r10;
        goto L_800B8DB4;
    // 0x800B8944: sw          $t2, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r10;
L_800B8948:
    // 0x800B8948: jal         0x800ABAB4
    // 0x800B894C: nop

    Play_Init(rdram, ctx);
        goto after_9;
    // 0x800B894C: nop

    after_9:
    // 0x800B8950: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B8954: addiu       $v0, $v0, 0x7C80
    ctx->r2 = ADD32(ctx->r2, 0X7C80);
    // 0x800B8958: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800B895C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B8960: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800B8964: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800B8968: nop

    // 0x800B896C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B8970: swc1        $f18, 0x2F5C($at)
    MEM_W(0X2F5C, ctx->r1) = ctx->f18.u32l;
    // 0x800B8974: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800B8978: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B897C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B8980: nop

    // 0x800B8984: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8988: swc1        $f6, 0x2F60($at)
    MEM_W(0X2F60, ctx->r1) = ctx->f6.u32l;
    // 0x800B898C: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800B8990: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B8994: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B8998: nop

    // 0x800B899C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B89A0: swc1        $f10, 0x2F64($at)
    MEM_W(0X2F64, ctx->r1) = ctx->f10.u32l;
    // 0x800B89A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B89A8: b           L_800B8DB4
    // 0x800B89AC: sw          $t6, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r14;
        goto L_800B8DB4;
    // 0x800B89AC: sw          $t6, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r14;
L_800B89B0:
    // 0x800B89B0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B89B4: lw          $t7, 0x7838($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7838);
    // 0x800B89B8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800B89BC: bne         $t7, $zero, L_800B89D8
    if (ctx->r15 != 0) {
        // 0x800B89C0: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_800B89D8;
    }
    // 0x800B89C0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B89C4: lw          $t8, 0x7840($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7840);
    // 0x800B89C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B89CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B89D0: beq         $t8, $zero, L_800B89E4
    if (ctx->r24 == 0) {
        // 0x800B89D4: nop
    
            goto L_800B89E4;
    }
    // 0x800B89D4: nop

L_800B89D8:
    // 0x800B89D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B89DC: b           L_800B89E8
    // 0x800B89E0: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
        goto L_800B89E8;
    // 0x800B89E0: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
L_800B89E4:
    // 0x800B89E4: sb          $t9, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = ctx->r25;
L_800B89E8:
    // 0x800B89E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B89EC: jal         0x800B832C
    // 0x800B89F0: sw          $t0, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r8;
    Play_Update(rdram, ctx);
        goto after_10;
    // 0x800B89F0: sw          $t0, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r8;
    after_10:
    // 0x800B89F4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B89F8: lw          $t1, 0x7AF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF8);
    // 0x800B89FC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B8A00: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B8A04: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800B8A08: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800B8A0C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800B8A10: lhu         $t3, -0x2768($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2768);
    // 0x800B8A14: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B8A18: beq         $t4, $zero, L_800B8B2C
    if (ctx->r12 == 0) {
        // 0x800B8A1C: nop
    
            goto L_800B8B2C;
    }
    // 0x800B8A1C: nop

    // 0x800B8A20: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800B8A24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8A28: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B8A2C: lw          $t6, 0x1C8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C8);
    // 0x800B8A30: bne         $t6, $at, L_800B8B2C
    if (ctx->r14 != ctx->r1) {
        // 0x800B8A34: nop
    
            goto L_800B8B2C;
    }
    // 0x800B8A34: nop

    // 0x800B8A38: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x800B8A3C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B8A40: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B8A44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B8A48: lbu         $t8, 0x2F6C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2F6C);
    // 0x800B8A4C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B8A50: lbu         $t9, -0x7790($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X7790);
    // 0x800B8A54: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800B8A58: beq         $t0, $zero, L_800B8B2C
    if (ctx->r8 == 0) {
        // 0x800B8A5C: nop
    
            goto L_800B8B2C;
    }
    // 0x800B8A5C: nop

    // 0x800B8A60: jal         0x8001AE58
    // 0x800B8A64: nop

    Audio_ClearVoice(rdram, ctx);
        goto after_11;
    // 0x800B8A64: nop

    after_11:
    // 0x800B8A68: jal         0x8001D400
    // 0x800B8A6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_12;
    // 0x800B8A6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800B8A70: jal         0x800A6148
    // 0x800B8A74: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_13;
    // 0x800B8A74: nop

    after_13:
    // 0x800B8A78: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B8A7C: lw          $t1, 0x78A8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A8);
    // 0x800B8A80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B8A84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B8A88: blezl       $t1, L_800B8AC8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B8A8C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800B8AC8;
    }
    goto skip_2;
    // 0x800B8A8C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_2:
    // 0x800B8A90: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
L_800B8A94:
    // 0x800B8A94: addu        $a0, $t2, $s1
    ctx->r4 = ADD32(ctx->r10, ctx->r17);
    // 0x800B8A98: jal         0x8001A500
    // 0x800B8A9C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_14;
    // 0x800B8A9C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_14:
    // 0x800B8AA0: jal         0x8001CA24
    // 0x800B8AA4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_15;
    // 0x800B8AA4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_15:
    // 0x800B8AA8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B8AAC: lw          $t3, 0x78A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A8);
    // 0x800B8AB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8AB4: addiu       $s1, $s1, 0x4E0
    ctx->r17 = ADD32(ctx->r17, 0X4E0);
    // 0x800B8AB8: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B8ABC: bnel        $at, $zero, L_800B8A94
    if (ctx->r1 != 0) {
        // 0x800B8AC0: lw          $t2, 0x0($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X0);
            goto L_800B8A94;
    }
    goto skip_3;
    // 0x800B8AC0: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    skip_3:
    // 0x800B8AC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_800B8AC8:
    // 0x800B8AC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8ACC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B8AD0: sw          $t4, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r12;
    // 0x800B8AD4: addiu       $v1, $v1, 0x78E8
    ctx->r3 = ADD32(ctx->r3, 0X78E8);
    // 0x800B8AD8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B8ADC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8AE0: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x800B8AE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8AE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B8AEC: sw          $t6, 0x78A8($at)
    MEM_W(0X78A8, ctx->r1) = ctx->r14;
    // 0x800B8AF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B8AF4: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x800B8AF8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B8AFC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B8B00: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B8B04: addiu       $a1, $a1, 0x7840
    ctx->r5 = ADD32(ctx->r5, 0X7840);
    // 0x800B8B08: addiu       $a0, $a0, 0x7838
    ctx->r4 = ADD32(ctx->r4, 0X7838);
    // 0x800B8B0C: addiu       $v0, $v0, -0x7D64
    ctx->r2 = ADD32(ctx->r2, -0X7D64);
    // 0x800B8B10: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B8B14: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800B8B18: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800B8B1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8B20: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x800B8B24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8B28: sw          $zero, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = 0;
L_800B8B2C:
    // 0x800B8B2C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B8B30: addiu       $v1, $v1, 0x78E8
    ctx->r3 = ADD32(ctx->r3, 0X78E8);
    // 0x800B8B34: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800B8B38: beq         $t0, $zero, L_800B8B48
    if (ctx->r8 == 0) {
        // 0x800B8B3C: nop
    
            goto L_800B8B48;
    }
    // 0x800B8B3C: nop

    // 0x800B8B40: jal         0x800C1E9C
    // 0x800B8B44: nop

    Versus_Main(rdram, ctx);
        goto after_16;
    // 0x800B8B44: nop

    after_16:
L_800B8B48:
    // 0x800B8B48: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B8B4C: lw          $t1, 0x7AF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF8);
    // 0x800B8B50: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B8B54: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B8B58: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800B8B5C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800B8B60: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800B8B64: lhu         $t3, -0x2768($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2768);
    // 0x800B8B68: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B8B6C: beq         $t4, $zero, L_800B8DB4
    if (ctx->r12 == 0) {
        // 0x800B8B70: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_800B8DB4;
    }
    // 0x800B8B70: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B8B74: lbu         $t5, 0x79BC($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X79BC);
    // 0x800B8B78: beql        $t5, $zero, L_800B8DB8
    if (ctx->r13 == 0) {
        // 0x800B8B7C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B8DB8;
    }
    goto skip_4;
    // 0x800B8B7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x800B8B80: jal         0x8001D638
    // 0x800B8B84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_PlayPauseSfx(rdram, ctx);
        goto after_17;
    // 0x800B8B84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x800B8B88: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x800B8B8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8B90: sw          $t6, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r14;
    // 0x800B8B94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8B98: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800B8B9C: sw          $t7, 0x7868($at)
    MEM_W(0X7868, ctx->r1) = ctx->r15;
    // 0x800B8BA0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800B8BA4: ori         $t8, $t8, 0x86A0
    ctx->r24 = ctx->r24 | 0X86A0;
    // 0x800B8BA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B8BAC: b           L_800B8DB4
    // 0x800B8BB0: sw          $t8, -0x7B7C($at)
    MEM_W(-0X7B7C, ctx->r1) = ctx->r24;
        goto L_800B8DB4;
    // 0x800B8BB0: sw          $t8, -0x7B7C($at)
    MEM_W(-0X7B7C, ctx->r1) = ctx->r24;
L_800B8BB4:
    // 0x800B8BB4: addiu       $v1, $v1, 0x78E8
    ctx->r3 = ADD32(ctx->r3, 0X78E8);
    // 0x800B8BB8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800B8BBC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800B8BC0: addiu       $s1, $s1, -0x2768
    ctx->r17 = ADD32(ctx->r17, -0X2768);
    // 0x800B8BC4: bne         $t9, $zero, L_800B8CA0
    if (ctx->r25 != 0) {
        // 0x800B8BC8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8CA0;
    }
    // 0x800B8BC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B8BCC: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B8BD0: lw          $t0, 0x7AF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF8);
    // 0x800B8BD4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B8BD8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B8BDC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B8BE0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800B8BE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B8BE8: lhu         $t2, -0x2768($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2768);
    // 0x800B8BEC: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x800B8BF0: beq         $t3, $zero, L_800B8D38
    if (ctx->r11 == 0) {
        // 0x800B8BF4: nop
    
            goto L_800B8D38;
    }
    // 0x800B8BF4: nop

    // 0x800B8BF8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B8BFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8C00: lw          $t4, 0x1CC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1CC);
    // 0x800B8C04: beq         $t4, $at, L_800B8D38
    if (ctx->r12 == ctx->r1) {
        // 0x800B8C08: nop
    
            goto L_800B8D38;
    }
    // 0x800B8C08: nop

    // 0x800B8C0C: lw          $t5, 0x1C8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C8);
    // 0x800B8C10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B8C14: addiu       $v0, $v0, 0x2860
    ctx->r2 = ADD32(ctx->r2, 0X2860);
    // 0x800B8C18: beq         $t5, $zero, L_800B8D38
    if (ctx->r13 == 0) {
        // 0x800B8C1C: nop
    
            goto L_800B8D38;
    }
    // 0x800B8C1C: nop

    // 0x800B8C20: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8C24: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800B8C28: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800B8C2C: subu        $a0, $a3, $t6
    ctx->r4 = SUB32(ctx->r7, ctx->r14);
    // 0x800B8C30: beq         $a0, $zero, L_800B8C70
    if (ctx->r4 == 0) {
        // 0x800B8C34: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_800B8C70;
    }
    // 0x800B8C34: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800B8C38: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800B8C3C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800B8C40: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800B8C44: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x800B8C48: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800B8C4C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800B8C50: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800B8C54: ori         $a0, $a0, 0x19
    ctx->r4 = ctx->r4 | 0X19;
    // 0x800B8C58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B8C5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800B8C60: jal         0x80019218
    // 0x800B8C64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x800B8C64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
    // 0x800B8C68: b           L_800B8D38
    // 0x800B8C6C: nop

        goto L_800B8D38;
    // 0x800B8C6C: nop

L_800B8C70:
    // 0x800B8C70: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800B8C74: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800B8C78: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800B8C7C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x800B8C80: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800B8C84: ori         $a0, $a0, 0x101A
    ctx->r4 = ctx->r4 | 0X101A;
    // 0x800B8C88: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800B8C8C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800B8C90: jal         0x80019218
    // 0x800B8C94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x800B8C94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_19:
    // 0x800B8C98: b           L_800B8D38
    // 0x800B8C9C: nop

        goto L_800B8D38;
    // 0x800B8C9C: nop

L_800B8CA0:
    // 0x800B8CA0: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x800B8CA4: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800B8CA8: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x800B8CAC: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x800B8CB0: beq         $t0, $zero, L_800B8D28
    if (ctx->r8 == 0) {
        // 0x800B8CB4: sll         $t2, $t2, 3
        ctx->r10 = S32(ctx->r10 << 3);
            goto L_800B8D28;
    }
    // 0x800B8CB4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800B8CB8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800B8CBC: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800B8CC0: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800B8CC4: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x800B8CC8: lw          $t3, 0x1CC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1CC);
    // 0x800B8CCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B8CD0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800B8CD4: beq         $t3, $at, L_800B8D28
    if (ctx->r11 == ctx->r1) {
        // 0x800B8CD8: lui         $t5, 0x800D
        ctx->r13 = S32(0X800D << 16);
            goto L_800B8D28;
    }
    // 0x800B8CD8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800B8CDC: addiu       $t5, $t5, 0x2860
    ctx->r13 = ADD32(ctx->r13, 0X2860);
    // 0x800B8CE0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800B8CE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8CE8: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x800B8CEC: ori         $a1, $a1, 0x101A
    ctx->r5 = ctx->r5 | 0X101A;
    // 0x800B8CF0: subu        $a0, $a3, $t6
    ctx->r4 = SUB32(ctx->r7, ctx->r14);
    // 0x800B8CF4: beq         $a0, $zero, L_800B8D18
    if (ctx->r4 == 0) {
        // 0x800B8CF8: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_800B8D18;
    }
    // 0x800B8CF8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800B8CFC: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x800B8D00: ori         $a1, $a1, 0x19
    ctx->r5 = ctx->r5 | 0X19;
    // 0x800B8D04: addiu       $a0, $v1, 0x460
    ctx->r4 = ADD32(ctx->r3, 0X460);
    // 0x800B8D08: jal         0x80060F30
    // 0x800B8D0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    Object_PlayerSfx(rdram, ctx);
        goto after_20;
    // 0x800B8D0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_20:
    // 0x800B8D10: b           L_800B8D28
    // 0x800B8D14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800B8D28;
    // 0x800B8D14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B8D18:
    // 0x800B8D18: addiu       $a0, $v1, 0x460
    ctx->r4 = ADD32(ctx->r3, 0X460);
    // 0x800B8D1C: jal         0x80060F30
    // 0x800B8D20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    Object_PlayerSfx(rdram, ctx);
        goto after_21;
    // 0x800B8D20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_21:
    // 0x800B8D24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B8D28:
    // 0x800B8D28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8D2C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B8D30: bne         $s0, $at, L_800B8CA0
    if (ctx->r16 != ctx->r1) {
        // 0x800B8D34: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_800B8CA0;
    }
    // 0x800B8D34: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
L_800B8D38:
    // 0x800B8D38: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B8D3C: lw          $t7, 0x7868($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7868);
    // 0x800B8D40: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B8D44: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B8D48: bnel        $t7, $at, L_800B8DAC
    if (ctx->r15 != ctx->r1) {
        // 0x800B8D4C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800B8DAC;
    }
    goto skip_5;
    // 0x800B8D4C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_5:
    // 0x800B8D50: lw          $t8, 0x7AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AF8);
    // 0x800B8D54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B8D58: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B8D5C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B8D60: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B8D64: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800B8D68: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B8D6C: lhu         $t0, -0x2768($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2768);
    // 0x800B8D70: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x800B8D74: beql        $t1, $zero, L_800B8DAC
    if (ctx->r9 == 0) {
        // 0x800B8D78: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800B8DAC;
    }
    goto skip_6;
    // 0x800B8D78: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_6:
    // 0x800B8D7C: lbu         $t2, 0x79BC($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X79BC);
    // 0x800B8D80: beql        $t2, $zero, L_800B8DAC
    if (ctx->r10 == 0) {
        // 0x800B8D84: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800B8DAC;
    }
    goto skip_7;
    // 0x800B8D84: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_7:
    // 0x800B8D88: jal         0x8001D638
    // 0x800B8D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayPauseSfx(rdram, ctx);
        goto after_22;
    // 0x800B8D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x800B8D90: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800B8D94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8D98: sw          $t3, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r11;
    // 0x800B8D9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8DA0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800B8DA4: sw          $t4, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r12;
    // 0x800B8DA8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_800B8DAC:
    // 0x800B8DAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8DB0: sb          $t5, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = ctx->r13;
L_800B8DB4:
    // 0x800B8DB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B8DB8:
    // 0x800B8DB8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B8DBC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DC0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B8DC4: jr          $ra
    // 0x800B8DC8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B8DC8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Play_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABAB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ABAB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABABC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800ABAC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ABAC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABAC8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800ABACC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ABAD0: addiu       $v1, $v1, -0x2744
    ctx->r3 = ADD32(ctx->r3, -0X2744);
    // 0x800ABAD4: addiu       $v0, $v0, -0x2748
    ctx->r2 = ADD32(ctx->r2, -0X2748);
    // 0x800ABAD8: swc1        $f4, 0x1A54($at)
    MEM_W(0X1A54, ctx->r1) = ctx->f4.u32l;
L_800ABADC:
    // 0x800ABADC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800ABAE0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800ABAE4: bne         $at, $zero, L_800ABADC
    if (ctx->r1 != 0) {
        // 0x800ABAE8: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_800ABADC;
    }
    // 0x800ABAE8: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x800ABAEC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800ABAF0: lw          $t6, 0x79F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X79F8);
    // 0x800ABAF4: lui         $a0, 0x1140
    ctx->r4 = S32(0X1140 << 16);
    // 0x800ABAF8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800ABAFC: beq         $t6, $zero, L_800ABB14
    if (ctx->r14 == 0) {
        // 0x800ABB00: ori         $a0, $a0, 0x3076
        ctx->r4 = ctx->r4 | 0X3076;
            goto L_800ABB14;
    }
    // 0x800ABB00: ori         $a0, $a0, 0x3076
    ctx->r4 = ctx->r4 | 0X3076;
    // 0x800ABB04: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x800ABB08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABB0C: b           L_800ABB20
    // 0x800ABB10: sh          $t7, 0x7828($at)
    MEM_H(0X7828, ctx->r1) = ctx->r15;
        goto L_800ABB20;
    // 0x800ABB10: sh          $t7, 0x7828($at)
    MEM_H(0X7828, ctx->r1) = ctx->r15;
L_800ABB14:
    // 0x800ABB14: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800ABB18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABB1C: sh          $t8, 0x7828($at)
    MEM_H(0X7828, ctx->r1) = ctx->r24;
L_800ABB20:
    // 0x800ABB20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABB24: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x800ABB28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ABB2C: sb          $t9, 0x7E78($at)
    MEM_B(0X7E78, ctx->r1) = ctx->r25;
    // 0x800ABB30: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABB34: sw          $zero, 0x7C70($at)
    MEM_W(0X7C70, ctx->r1) = 0;
    // 0x800ABB38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800ABB3C: sw          $zero, -0x5DCC($at)
    MEM_W(-0X5DCC, ctx->r1) = 0;
    // 0x800ABB40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800ABB44: jal         0x8001A838
    // 0x800ABB48: sw          $zero, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = 0;
    Audio_KillSfxById(rdram, ctx);
        goto after_0;
    // 0x800ABB48: sw          $zero, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = 0;
    after_0:
    // 0x800ABB4C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800ABB50: jal         0x8001A838
    // 0x800ABB54: ori         $a0, $a0, 0x14
    ctx->r4 = ctx->r4 | 0X14;
    Audio_KillSfxById(rdram, ctx);
        goto after_1;
    // 0x800ABB54: ori         $a0, $a0, 0x14
    ctx->r4 = ctx->r4 | 0X14;
    after_1:
    // 0x800ABB58: jal         0x80006F20
    // 0x800ABB5C: nop

    Memory_FreeAll(rdram, ctx);
        goto after_2;
    // 0x800ABB5C: nop

    after_2:
    // 0x800ABB60: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800ABB64: addiu       $a1, $a1, -0x6F8
    ctx->r5 = ADD32(ctx->r5, -0X6F8);
    // 0x800ABB68: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x800ABB6C: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x800ABB70: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800ABB74: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800ABB78: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800ABB7C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800ABB80: addiu       $a3, $a3, 0x7C8C
    ctx->r7 = ADD32(ctx->r7, 0X7C8C);
    // 0x800ABB84: addiu       $a2, $a2, 0x1734
    ctx->r6 = ADD32(ctx->r6, 0X1734);
    // 0x800ABB88: addiu       $a0, $a0, -0x6F4
    ctx->r4 = ADD32(ctx->r4, -0X6F4);
    // 0x800ABB8C: addiu       $v1, $v1, -0x6F0
    ctx->r3 = ADD32(ctx->r3, -0X6F0);
    // 0x800ABB90: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800ABB94: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800ABB98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABB9C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800ABBA0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800ABBA4: sw          $t8, 0x7C78($at)
    MEM_W(0X7C78, ctx->r1) = ctx->r24;
    // 0x800ABBA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800ABBAC: sw          $zero, -0x5DE0($at)
    MEM_W(-0X5DE0, ctx->r1) = 0;
    // 0x800ABBB0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800ABBB4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800ABBB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABBBC: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
    // 0x800ABBC0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800ABBC4: beq         $v0, $at, L_800ABBD4
    if (ctx->r2 == ctx->r1) {
        // 0x800ABBC8: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800ABBD4;
    }
    // 0x800ABBC8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800ABBCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABBD0: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
L_800ABBD4:
    // 0x800ABBD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ABBD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBDC: sb          $t7, 0x1A2C($at)
    MEM_B(0X1A2C, ctx->r1) = ctx->r15;
    // 0x800ABBE0: addiu       $v1, $v1, 0x7AB0
    ctx->r3 = ADD32(ctx->r3, 0X7AB0);
    // 0x800ABBE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ABBE8: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x800ABBEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABBF0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800ABBF4: sb          $t9, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = ctx->r25;
    // 0x800ABBF8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800ABBFC: addiu       $a0, $a0, 0x2F54
    ctx->r4 = ADD32(ctx->r4, 0X2F54);
    // 0x800ABC00: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800ABC04: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800ABC08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABC0C: addiu       $a1, $a1, 0x2F58
    ctx->r5 = ADD32(ctx->r5, 0X2F58);
    // 0x800ABC10: sb          $zero, 0x7AC8($at)
    MEM_B(0X7AC8, ctx->r1) = 0;
    // 0x800ABC14: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x800ABC18: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ABC1C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800ABC20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800ABC24: addiu       $a2, $a2, -0x698
    ctx->r6 = ADD32(ctx->r6, -0X698);
    // 0x800ABC28: swc1        $f6, -0x5DD0($at)
    MEM_W(-0X5DD0, ctx->r1) = ctx->f6.u32l;
    // 0x800ABC2C: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x800ABC30: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ABC34: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800ABC38: addiu       $t3, $t3, 0x7880
    ctx->r11 = ADD32(ctx->r11, 0X7880);
    // 0x800ABC3C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x800ABC40: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABC44: swc1        $f8, 0x7CE8($at)
    MEM_W(0X7CE8, ctx->r1) = ctx->f8.u32l;
    // 0x800ABC48: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800ABC4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800ABC50: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800ABC54: addiu       $t1, $t1, 0x78E8
    ctx->r9 = ADD32(ctx->r9, 0X78E8);
    // 0x800ABC58: addiu       $t0, $t0, -0x7D00
    ctx->r8 = ADD32(ctx->r8, -0X7D00);
    // 0x800ABC5C: addiu       $a3, $a3, 0x7E84
    ctx->r7 = ADD32(ctx->r7, 0X7E84);
    // 0x800ABC60: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800ABC64: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800ABC68: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800ABC6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800ABC70: sh          $zero, 0x1970($at)
    MEM_H(0X1970, ctx->r1) = 0;
    // 0x800ABC74: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x800ABC78: bne         $at, $zero, L_800ABCA4
    if (ctx->r1 != 0) {
        // 0x800ABC7C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800ABCA4;
    }
    // 0x800ABC7C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ABC80: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800ABC84: bne         $v0, $at, L_800ABCA4
    if (ctx->r2 != ctx->r1) {
        // 0x800ABC88: sw          $t2, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r10;
            goto L_800ABCA4;
    }
    // 0x800ABC88: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800ABC8C: jal         0x800AB964
    // 0x800ABC90: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    Player_ResetVsData(rdram, ctx);
        goto after_3;
    // 0x800ABC90: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    after_3:
    // 0x800ABC94: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800ABC98: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800ABC9C: addiu       $t3, $t3, 0x7880
    ctx->r11 = ADD32(ctx->r11, 0X7880);
    // 0x800ABCA0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_800ABCA4:
    // 0x800ABCA4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800ABCA8: bne         $v0, $at, L_800ABCC4
    if (ctx->r2 != ctx->r1) {
        // 0x800ABCAC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800ABCC4;
    }
    // 0x800ABCAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ABCB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800ABCB4: lw          $t6, -0x7D84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D84);
    // 0x800ABCB8: bne         $t2, $t6, L_800ABCC4
    if (ctx->r10 != ctx->r14) {
        // 0x800ABCBC: nop
    
            goto L_800ABCC4;
    }
    // 0x800ABCBC: nop

    // 0x800ABCC0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_800ABCC4:
    // 0x800ABCC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABCC8: jal         0x800A594C
    // 0x800ABCCC: sw          $zero, 0x7E7C($at)
    MEM_W(0X7E7C, ctx->r1) = 0;
    Play_InitEnvironment(rdram, ctx);
        goto after_4;
    // 0x800ABCCC: sw          $zero, 0x7E7C($at)
    MEM_W(0X7E7C, ctx->r1) = 0;
    after_4:
    // 0x800ABCD0: andi        $t9, $zero, 0xFF
    ctx->r25 = 0 & 0XFF;
    // 0x800ABCD4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800ABCD8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800ABCDC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800ABCE0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800ABCE4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800ABCE8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800ABCEC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800ABCF0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800ABCF4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800ABCF8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800ABCFC: lui         $ra, 0x8017
    ctx->r31 = S32(0X8017 << 16);
    // 0x800ABD00: addiu       $ra, $ra, 0x7B4C
    ctx->r31 = ADD32(ctx->r31, 0X7B4C);
    // 0x800ABD04: addiu       $t5, $t5, -0x6D8
    ctx->r13 = ADD32(ctx->r13, -0X6D8);
    // 0x800ABD08: addiu       $t4, $t4, -0x6C0
    ctx->r12 = ADD32(ctx->r12, -0X6C0);
    // 0x800ABD0C: addiu       $t3, $t3, -0x7D7C
    ctx->r11 = ADD32(ctx->r11, -0X7D7C);
    // 0x800ABD10: addiu       $t1, $t1, 0x7DB0
    ctx->r9 = ADD32(ctx->r9, 0X7DB0);
    // 0x800ABD14: addiu       $t0, $t0, -0x7B80
    ctx->r8 = ADD32(ctx->r8, -0X7B80);
    // 0x800ABD18: addiu       $a3, $a3, -0x7D04
    ctx->r7 = ADD32(ctx->r7, -0X7D04);
    // 0x800ABD1C: addiu       $a2, $a2, 0x13A0
    ctx->r6 = ADD32(ctx->r6, 0X13A0);
    // 0x800ABD20: addiu       $a1, $a1, 0x1690
    ctx->r5 = ADD32(ctx->r5, 0X1690);
    // 0x800ABD24: addiu       $a0, $a0, -0x700
    ctx->r4 = ADD32(ctx->r4, -0X700);
    // 0x800ABD28: addiu       $v1, $v1, 0x7930
    ctx->r3 = ADD32(ctx->r3, 0X7930);
    // 0x800ABD2C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800ABD30: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800ABD34: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800ABD38: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800ABD3C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800ABD40: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800ABD44: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800ABD48: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800ABD4C: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800ABD50: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800ABD54: sb          $t9, 0x0($ra)
    MEM_B(0X0, ctx->r31) = ctx->r25;
    // 0x800ABD58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABD5C: sb          $t9, 0x7B44($at)
    MEM_B(0X7B44, ctx->r1) = ctx->r25;
    // 0x800ABD60: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800ABD64: lbu         $t6, 0x7B44($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7B44);
    // 0x800ABD68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABD6C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800ABD70: sw          $t6, 0x796C($at)
    MEM_W(0X796C, ctx->r1) = ctx->r14;
    // 0x800ABD74: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800ABD78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABD7C: sh          $t6, 0x1A62($at)
    MEM_H(0X1A62, ctx->r1) = ctx->r14;
    // 0x800ABD80: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800ABD84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ABD88: bne         $v0, $at, L_800ABD98
    if (ctx->r2 != ctx->r1) {
        // 0x800ABD8C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800ABD98;
    }
    // 0x800ABD8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ABD90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ABD94: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_800ABD98:
    // 0x800ABD98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ABD9C: lwc1        $f10, -0x7A18($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A18);
    // 0x800ABDA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABDA4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800ABDA8: swc1        $f10, 0x7CC0($at)
    MEM_W(0X7CC0, ctx->r1) = ctx->f10.u32l;
    // 0x800ABDAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ABDB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ABDB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABDB8: addiu       $a1, $a1, -0x6C4
    ctx->r5 = ADD32(ctx->r5, -0X6C4);
    // 0x800ABDBC: swc1        $f16, 0x7950($at)
    MEM_W(0X7950, ctx->r1) = ctx->f16.u32l;
    // 0x800ABDC0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800ABDC4: bne         $v0, $at, L_800ABE04
    if (ctx->r2 != ctx->r1) {
        // 0x800ABDC8: lui         $a2, 0x8017
        ctx->r6 = S32(0X8017 << 16);
            goto L_800ABE04;
    }
    // 0x800ABDC8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800ABDCC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800ABDD0: lw          $t8, -0x7D84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D84);
    // 0x800ABDD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ABDD8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800ABDDC: bne         $t8, $at, L_800ABE04
    if (ctx->r24 != ctx->r1) {
        // 0x800ABDE0: addiu       $v1, $v1, -0x7CAC
        ctx->r3 = ADD32(ctx->r3, -0X7CAC);
            goto L_800ABE04;
    }
    // 0x800ABDE0: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800ABDE4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800ABDE8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800ABDEC: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x800ABDF0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800ABDF4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800ABDF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABDFC: b           L_800ABE24
    // 0x800ABE00: sw          $t9, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r25;
        goto L_800ABE24;
    // 0x800ABE00: sw          $t9, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r25;
L_800ABE04:
    // 0x800ABE04: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800ABE08: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800ABE0C: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x800ABE10: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800ABE14: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800ABE18: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800ABE1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABE20: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
L_800ABE24:
    // 0x800ABE24: andi        $t6, $zero, 0xFF
    ctx->r14 = 0 & 0XFF;
    // 0x800ABE28: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800ABE2C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800ABE30: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800ABE34: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800ABE38: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800ABE3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800ABE40: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ABE44: addiu       $t4, $t4, -0x7CA0
    ctx->r12 = ADD32(ctx->r12, -0X7CA0);
    // 0x800ABE48: addiu       $t3, $t3, -0x7C9C
    ctx->r11 = ADD32(ctx->r11, -0X7C9C);
    // 0x800ABE4C: addiu       $t1, $t1, -0x7C98
    ctx->r9 = ADD32(ctx->r9, -0X7C98);
    // 0x800ABE50: addiu       $t0, $t0, 0x1704
    ctx->r8 = ADD32(ctx->r8, 0X1704);
    // 0x800ABE54: addiu       $a3, $a3, 0x1708
    ctx->r7 = ADD32(ctx->r7, 0X1708);
    // 0x800ABE58: addiu       $a0, $a0, 0x7B6C
    ctx->r4 = ADD32(ctx->r4, 0X7B6C);
    // 0x800ABE5C: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x800ABE60: addiu       $a2, $a2, 0x7C50
    ctx->r6 = ADD32(ctx->r6, 0X7C50);
    // 0x800ABE64: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800ABE68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800ABE6C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800ABE70: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800ABE74: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800ABE78: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800ABE7C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800ABE80: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800ABE84: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800ABE88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABE8C: sh          $t6, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r14;
    // 0x800ABE90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABE94: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x800ABE98: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800ABE9C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800ABEA0: addiu       $t5, $t5, -0x7CA8
    ctx->r13 = ADD32(ctx->r13, -0X7CA8);
    // 0x800ABEA4: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800ABEA8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ABEAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABEB0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800ABEB4: sw          $t9, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
    // 0x800ABEB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABEBC: swc1        $f12, -0x7C94($at)
    MEM_W(-0X7C94, ctx->r1) = ctx->f12.u32l;
    // 0x800ABEC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABEC4: swc1        $f12, -0x6A0($at)
    MEM_W(-0X6A0, ctx->r1) = ctx->f12.u32l;
    // 0x800ABEC8: lui         $ra, 0x8018
    ctx->r31 = S32(0X8018 << 16);
    // 0x800ABECC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABED0: addiu       $ra, $ra, -0x7BD0
    ctx->r31 = ADD32(ctx->r31, -0X7BD0);
    // 0x800ABED4: swc1        $f12, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->f12.u32l;
    // 0x800ABED8: swc1        $f12, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f12.u32l;
    // 0x800ABEDC: lwc1        $f18, 0x0($ra)
    ctx->f18.u32l = MEM_W(ctx->r31, 0X0);
    // 0x800ABEE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABEE4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800ABEE8: swc1        $f18, -0x7BD4($at)
    MEM_W(-0X7BD4, ctx->r1) = ctx->f18.u32l;
    // 0x800ABEEC: lwc1        $f4, -0x7BD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7BD4);
    // 0x800ABEF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABEF4: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x800ABEF8: swc1        $f4, -0x7BD8($at)
    MEM_W(-0X7BD8, ctx->r1) = ctx->f4.u32l;
    // 0x800ABEFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF00: swc1        $f4, -0x7BDC($at)
    MEM_W(-0X7BDC, ctx->r1) = ctx->f4.u32l;
    // 0x800ABF04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF08: swc1        $f4, -0x7BE0($at)
    MEM_W(-0X7BE0, ctx->r1) = ctx->f4.u32l;
    // 0x800ABF0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF10: beq         $t2, $t6, L_800ABF24
    if (ctx->r10 == ctx->r14) {
        // 0x800ABF14: swc1        $f4, -0x7BEC($at)
        MEM_W(-0X7BEC, ctx->r1) = ctx->f4.u32l;
            goto L_800ABF24;
    }
    // 0x800ABF14: swc1        $f4, -0x7BEC($at)
    MEM_W(-0X7BEC, ctx->r1) = ctx->f4.u32l;
    // 0x800ABF18: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800ABF1C: bne         $v0, $at, L_800ABF48
    if (ctx->r2 != ctx->r1) {
        // 0x800ABF20: nop
    
            goto L_800ABF48;
    }
    // 0x800ABF20: nop

L_800ABF24:
    // 0x800ABF24: jal         0x800A5EBC
    // 0x800ABF28: nop

    Play_SetupStarfield(rdram, ctx);
        goto after_5;
    // 0x800ABF28: nop

    after_5:
    // 0x800ABF2C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800ABF30: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x800ABF34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800ABF38: beq         $t7, $at, L_800ABF50
    if (ctx->r15 == ctx->r1) {
        // 0x800ABF3C: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800ABF50;
    }
    // 0x800ABF3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABF40: b           L_800ABF50
    // 0x800ABF44: sb          $zero, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = 0;
        goto L_800ABF50;
    // 0x800ABF44: sb          $zero, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = 0;
L_800ABF48:
    // 0x800ABF48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF4C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
L_800ABF50:
    // 0x800ABF50: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800ABF54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800ABF58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF5C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800ABF60: sw          $t8, -0x7CC8($at)
    MEM_W(-0X7CC8, ctx->r1) = ctx->r24;
    // 0x800ABF64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF68: swc1        $f0, -0x7B18($at)
    MEM_W(-0X7B18, ctx->r1) = ctx->f0.u32l;
    // 0x800ABF6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF70: swc1        $f0, -0x7AF0($at)
    MEM_W(-0X7AF0, ctx->r1) = ctx->f0.u32l;
    // 0x800ABF74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF78: jal         0x800A6148
    // 0x800ABF7C: swc1        $f0, -0x7AC8($at)
    MEM_W(-0X7AC8, ctx->r1) = ctx->f0.u32l;
    Play_ClearObjectData(rdram, ctx);
        goto after_6;
    // 0x800ABF7C: swc1        $f0, -0x7AC8($at)
    MEM_W(-0X7AC8, ctx->r1) = ctx->f0.u32l;
    after_6:
    // 0x800ABF80: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800ABF84: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800ABF88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABF8C: sw          $zero, -0x7D38($at)
    MEM_W(-0X7D38, ctx->r1) = 0;
    // 0x800ABF90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800ABF94: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800ABF98: bne         $v0, $at, L_800ABFB8
    if (ctx->r2 != ctx->r1) {
        // 0x800ABF9C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800ABFB8;
    }
    // 0x800ABF9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ABFA0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800ABFA4: jal         0x801B5110
    // 0x800ABFA8: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    Ground_801B5110(rdram, ctx);
        goto after_7;
    // 0x800ABFA8: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_7:
    // 0x800ABFAC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800ABFB0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800ABFB4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800ABFB8:
    // 0x800ABFB8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800ABFBC: bne         $v0, $at, L_800ABFD4
    if (ctx->r2 != ctx->r1) {
        // 0x800ABFC0: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_800ABFD4;
    }
    // 0x800ABFC0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800ABFC4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800ABFC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ABFCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ABFD0: swc1        $f6, 0x7CC0($at)
    MEM_W(0X7CC0, ctx->r1) = ctx->f6.u32l;
L_800ABFD4:
    // 0x800ABFD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ABFD8: sw          $zero, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = 0;
    // 0x800ABFDC: addiu       $t1, $t1, 0x78A8
    ctx->r9 = ADD32(ctx->r9, 0X78A8);
    // 0x800ABFE0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800ABFE4: bne         $v0, $at, L_800ABFF4
    if (ctx->r2 != ctx->r1) {
        // 0x800ABFE8: sw          $t2, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r10;
            goto L_800ABFF4;
    }
    // 0x800ABFE8: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800ABFEC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800ABFF0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_800ABFF4:
    // 0x800ABFF4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800ABFF8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800ABFFC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800AC000: addiu       $a0, $a0, 0x78E8
    ctx->r4 = ADD32(ctx->r4, 0X78E8);
    // 0x800AC004: addiu       $v0, $v0, 0x78D4
    ctx->r2 = ADD32(ctx->r2, 0X78D4);
    // 0x800AC008: addiu       $v1, $v1, 0x78B4
    ctx->r3 = ADD32(ctx->r3, 0X78B4);
L_800AC00C:
    // 0x800AC00C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AC010: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AC014: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800AC018: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AC01C: bne         $at, $zero, L_800AC00C
    if (ctx->r1 != 0) {
        // 0x800AC020: sw          $t6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r14;
            goto L_800AC00C;
    }
    // 0x800AC020: sw          $t6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r14;
    // 0x800AC024: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800AC028: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800AC02C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC030: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800AC034: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800AC038: jal         0x80006F38
    // 0x800AC03C: sll         $a0, $t7, 5
    ctx->r4 = S32(ctx->r15 << 5);
    Memory_Allocate(rdram, ctx);
        goto after_8;
    // 0x800AC03C: sll         $a0, $t7, 5
    ctx->r4 = S32(ctx->r15 << 5);
    after_8:
    // 0x800AC040: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AC044: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x800AC048: jal         0x800AB2AC
    // 0x800AC04C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    Player_InitializeAll(rdram, ctx);
        goto after_9;
    // 0x800AC04C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    after_9:
    // 0x800AC050: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800AC054: addiu       $t1, $t1, 0x78A8
    ctx->r9 = ADD32(ctx->r9, 0X78A8);
    // 0x800AC058: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AC05C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AC060: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x800AC064: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AC068: blez        $t8, L_800AC0D4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AC06C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800AC0D4;
    }
    // 0x800AC06C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AC070: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800AC074: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AC078: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AC07C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800AC080: addiu       $a2, $a2, 0x7C30
    ctx->r6 = ADD32(ctx->r6, 0X7C30);
    // 0x800AC084: addiu       $a1, $a1, 0x7BD0
    ctx->r5 = ADD32(ctx->r5, 0X7BD0);
    // 0x800AC088: addiu       $a0, $a0, -0x7C80
    ctx->r4 = ADD32(ctx->r4, -0X7C80);
    // 0x800AC08C: addiu       $v1, $v1, -0x7C40
    ctx->r3 = ADD32(ctx->r3, -0X7C40);
    // 0x800AC090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AC094:
    // 0x800AC094: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800AC098: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AC09C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AC0A0: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800AC0A4: sw          $t2, 0x1C8($t6)
    MEM_W(0X1C8, ctx->r14) = ctx->r10;
    // 0x800AC0A8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AC0AC: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x800AC0B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AC0B4: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AC0B8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800AC0BC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800AC0C0: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x800AC0C4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800AC0C8: sh          $zero, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = 0;
    // 0x800AC0CC: bne         $at, $zero, L_800AC094
    if (ctx->r1 != 0) {
        // 0x800AC0D0: sh          $zero, -0x2($a2)
        MEM_H(-0X2, ctx->r6) = 0;
            goto L_800AC094;
    }
    // 0x800AC0D0: sh          $zero, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = 0;
L_800AC0D4:
    // 0x800AC0D4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800AC0D8: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x800AC0DC: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
    // 0x800AC0E0: bne         $t2, $t8, L_800AC278
    if (ctx->r10 != ctx->r24) {
        // 0x800AC0E4: nop
    
            goto L_800AC278;
    }
    // 0x800AC0E4: nop

    // 0x800AC0E8: jal         0x80006F38
    // 0x800AC0EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Memory_Allocate(rdram, ctx);
        goto after_10;
    // 0x800AC0EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x800AC0F0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AC0F4: addiu       $a0, $a0, -0x7D58
    ctx->r4 = ADD32(ctx->r4, -0X7D58);
    // 0x800AC0F8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800AC0FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AC100: addiu       $v0, $zero, 0x44C0
    ctx->r2 = ADD32(0, 0X44C0);
    // 0x800AC104: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AC108:
    // 0x800AC108: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800AC10C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800AC110: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x800AC114: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800AC118: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800AC11C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    // 0x800AC120: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800AC124: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800AC128: sb          $zero, 0xB0($t6)
    MEM_B(0XB0, ctx->r14) = 0;
    // 0x800AC12C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800AC130: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800AC134: addiu       $v1, $v1, 0x160
    ctx->r3 = ADD32(ctx->r3, 0X160);
    // 0x800AC138: bne         $v1, $v0, L_800AC108
    if (ctx->r3 != ctx->r2) {
        // 0x800AC13C: sb          $zero, 0x108($t8)
        MEM_B(0X108, ctx->r24) = 0;
            goto L_800AC108;
    }
    // 0x800AC13C: sb          $zero, 0x108($t8)
    MEM_B(0X108, ctx->r24) = 0;
    // 0x800AC140: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800AC144: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800AC148: addiu       $t6, $t9, -0x9
    ctx->r14 = ADD32(ctx->r25, -0X9);
    // 0x800AC14C: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x800AC150: beq         $at, $zero, L_800AC278
    if (ctx->r1 == 0) {
        // 0x800AC154: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800AC278;
    }
    // 0x800AC154: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AC158: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC15C: addu        $at, $at, $t6
    gpr jr_addend_800AC164 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AC160: lw          $t6, -0x7A14($at)
    ctx->r14 = ADD32(ctx->r1, -0X7A14);
    // 0x800AC164: jr          $t6
    // 0x800AC168: nop

    switch (jr_addend_800AC164 >> 2) {
        case 0: goto L_800AC224; break;
        case 1: goto L_800AC278; break;
        case 2: goto L_800AC278; break;
        case 3: goto L_800AC278; break;
        case 4: goto L_800AC278; break;
        case 5: goto L_800AC194; break;
        case 6: goto L_800AC278; break;
        case 7: goto L_800AC1AC; break;
        case 8: goto L_800AC1D4; break;
        case 9: goto L_800AC16C; break;
        case 10: goto L_800AC1FC; break;
        case 11: goto L_800AC264; break;
        default: switch_error(__func__, 0x800AC164, 0x800D85EC);
    }
    // 0x800AC168: nop

L_800AC16C:
    // 0x800AC16C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800AC170: lw          $t7, 0x782C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X782C);
    // 0x800AC174: bne         $t7, $zero, L_800AC278
    if (ctx->r15 != 0) {
        // 0x800AC178: nop
    
            goto L_800AC278;
    }
    // 0x800AC178: nop

    // 0x800AC17C: jal         0x8019EA68
    // 0x800AC180: nop

    SectorZ_LoadLevelObjects(rdram, ctx);
        goto after_11;
    // 0x800AC180: nop

    after_11:
    // 0x800AC184: jal         0x8002F180
    // 0x800AC188: nop

    ActorAllRange_SpawnTeam(rdram, ctx);
        goto after_12;
    // 0x800AC188: nop

    after_12:
    // 0x800AC18C: b           L_800AC278
    // 0x800AC190: nop

        goto L_800AC278;
    // 0x800AC190: nop

L_800AC194:
    // 0x800AC194: jal         0x8018BA2C
    // 0x800AC198: nop

    Fortuna_LoadLevelObjects(rdram, ctx);
        goto after_13;
    // 0x800AC198: nop

    after_13:
    // 0x800AC19C: jal         0x8002F180
    // 0x800AC1A0: nop

    ActorAllRange_SpawnTeam(rdram, ctx);
        goto after_14;
    // 0x800AC1A0: nop

    after_14:
    // 0x800AC1A4: b           L_800AC278
    // 0x800AC1A8: nop

        goto L_800AC278;
    // 0x800AC1A8: nop

L_800AC1AC:
    // 0x800AC1AC: jal         0x80198930
    // 0x800AC1B0: nop

    Katina_Init(rdram, ctx);
        goto after_15;
    // 0x800AC1B0: nop

    after_15:
    // 0x800AC1B4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800AC1B8: lw          $t8, 0x782C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X782C);
    // 0x800AC1BC: bne         $t8, $zero, L_800AC278
    if (ctx->r24 != 0) {
        // 0x800AC1C0: nop
    
            goto L_800AC278;
    }
    // 0x800AC1C0: nop

    // 0x800AC1C4: jal         0x8002F180
    // 0x800AC1C8: nop

    ActorAllRange_SpawnTeam(rdram, ctx);
        goto after_16;
    // 0x800AC1C8: nop

    after_16:
    // 0x800AC1CC: b           L_800AC278
    // 0x800AC1D0: nop

        goto L_800AC278;
    // 0x800AC1D0: nop

L_800AC1D4:
    // 0x800AC1D4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800AC1D8: lw          $t9, 0x782C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X782C);
    // 0x800AC1DC: bne         $t9, $zero, L_800AC278
    if (ctx->r25 != 0) {
        // 0x800AC1E0: nop
    
            goto L_800AC278;
    }
    // 0x800AC1E0: nop

    // 0x800AC1E4: jal         0x80191ED8
    // 0x800AC1E8: nop

    Bolse_LoadLevelObjects(rdram, ctx);
        goto after_17;
    // 0x800AC1E8: nop

    after_17:
    // 0x800AC1EC: jal         0x8002F180
    // 0x800AC1F0: nop

    ActorAllRange_SpawnTeam(rdram, ctx);
        goto after_18;
    // 0x800AC1F0: nop

    after_18:
    // 0x800AC1F4: b           L_800AC278
    // 0x800AC1F8: nop

        goto L_800AC278;
    // 0x800AC1F8: nop

L_800AC1FC:
    // 0x800AC1FC: jal         0x80196968
    // 0x800AC200: nop

    Venom2_LoadLevelObjects(rdram, ctx);
        goto after_19;
    // 0x800AC200: nop

    after_19:
    // 0x800AC204: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AC208: lw          $t6, -0x7D84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D84);
    // 0x800AC20C: bne         $t6, $zero, L_800AC278
    if (ctx->r14 != 0) {
        // 0x800AC210: nop
    
            goto L_800AC278;
    }
    // 0x800AC210: nop

    // 0x800AC214: jal         0x8002F180
    // 0x800AC218: nop

    ActorAllRange_SpawnTeam(rdram, ctx);
        goto after_20;
    // 0x800AC218: nop

    after_20:
    // 0x800AC21C: b           L_800AC278
    // 0x800AC220: nop

        goto L_800AC278;
    // 0x800AC220: nop

L_800AC224:
    // 0x800AC224: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800AC228: lw          $t7, -0x7D84($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D84);
    // 0x800AC22C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800AC230: bne         $t2, $t7, L_800AC278
    if (ctx->r10 != ctx->r15) {
        // 0x800AC234: nop
    
            goto L_800AC278;
    }
    // 0x800AC234: nop

    // 0x800AC238: lw          $t8, -0x6DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6DC);
    // 0x800AC23C: bne         $t8, $zero, L_800AC254
    if (ctx->r24 != 0) {
        // 0x800AC240: nop
    
            goto L_800AC254;
    }
    // 0x800AC240: nop

    // 0x800AC244: jal         0x801878A8
    // 0x800AC248: nop

    Andross_Ve2LoadLevelObjects(rdram, ctx);
        goto after_21;
    // 0x800AC248: nop

    after_21:
    // 0x800AC24C: b           L_800AC278
    // 0x800AC250: nop

        goto L_800AC278;
    // 0x800AC250: nop

L_800AC254:
    // 0x800AC254: jal         0x801961AC
    // 0x800AC258: nop

    Andross_EscapePhase_Setup(rdram, ctx);
        goto after_22;
    // 0x800AC258: nop

    after_22:
    // 0x800AC25C: b           L_800AC278
    // 0x800AC260: nop

        goto L_800AC278;
    // 0x800AC260: nop

L_800AC264:
    // 0x800AC264: jal         0x800A4F7C
    // 0x800AC268: nop

    Play_InitVsStage(rdram, ctx);
        goto after_23;
    // 0x800AC268: nop

    after_23:
    // 0x800AC26C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800AC270: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AC274: sw          $t9, 0x796C($at)
    MEM_W(0X796C, ctx->r1) = ctx->r25;
L_800AC278:
    // 0x800AC278: jal         0x800AB334
    // 0x800AC27C: nop

    Play_InitLevel(rdram, ctx);
        goto after_24;
    // 0x800AC27C: nop

    after_24:
    // 0x800AC280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AC288: jr          $ra
    // 0x800AC28C: nop

    return;
    // 0x800AC28C: nop

;}
RECOMP_FUNC void BonusText_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A60B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A60BC: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x800A60C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A60C4:
    // 0x800A60C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A60C8: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800A60CC: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800A60D0: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A60D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A60D8: bne         $v1, $a0, L_800A60C4
    if (ctx->r3 != ctx->r4) {
        // 0x800A60DC: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800A60C4;
    }
    // 0x800A60DC: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800A60E0: jr          $ra
    // 0x800A60E4: nop

    return;
    // 0x800A60E4: nop

;}
RECOMP_FUNC void Load_RomFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058B88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80058B8C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80058B90: lw          $t6, -0x7588($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7588);
    // 0x80058B94: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80058B98: addiu       $v0, $v0, -0x7590
    ctx->r2 = ADD32(ctx->r2, -0X7590);
    // 0x80058B9C: beql        $t6, $zero, L_80058C3C
    if (ctx->r14 == 0) {
        // 0x80058BA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80058C3C;
    }
    goto skip_0;
    // 0x80058BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80058BA4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_80058BA8:
    // 0x80058BA8: bnel        $a0, $t7, L_80058C2C
    if (ctx->r4 != ctx->r15) {
        // 0x80058BAC: lw          $t2, 0x18($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X18);
            goto L_80058C2C;
    }
    goto skip_1;
    // 0x80058BAC: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    skip_1:
    // 0x80058BB0: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80058BB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80058BB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80058BBC: bne         $t8, $zero, L_80058BD4
    if (ctx->r24 != 0) {
        // 0x80058BC0: nop
    
            goto L_80058BD4;
    }
    // 0x80058BC0: nop

    // 0x80058BC4: jal         0x800033E0
    // 0x80058BC8: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    Lib_DmaRead(rdram, ctx);
        goto after_0;
    // 0x80058BC8: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_0:
    // 0x80058BCC: b           L_80058C3C
    // 0x80058BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80058C3C;
    // 0x80058BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058BD4:
    // 0x80058BD4: jal         0x800034E8
    // 0x80058BD8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    Lib_FillScreen(rdram, ctx);
        goto after_1;
    // 0x80058BD8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80058BDC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80058BE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058BE4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80058BE8: sb          $t9, -0x5C50($at)
    MEM_B(-0X5C50, ctx->r1) = ctx->r25;
    // 0x80058BEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80058BF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80058BF4: sb          $t0, 0x1A39($at)
    MEM_B(0X1A39, ctx->r1) = ctx->r8;
    // 0x80058BF8: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80058BFC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80058C00: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80058C04: addiu       $a1, $a1, -0x800
    ctx->r5 = ADD32(ctx->r5, -0X800);
    // 0x80058C08: jal         0x800033E0
    // 0x80058C0C: subu        $a2, $t1, $a0
    ctx->r6 = SUB32(ctx->r9, ctx->r4);
    Lib_DmaRead(rdram, ctx);
        goto after_2;
    // 0x80058C0C: subu        $a2, $t1, $a0
    ctx->r6 = SUB32(ctx->r9, ctx->r4);
    after_2:
    // 0x80058C10: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80058C14: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x80058C18: jal         0x8001EE70
    // 0x80058C1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    Mio0_Decompress(rdram, ctx);
        goto after_3;
    // 0x80058C1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80058C20: b           L_80058C3C
    // 0x80058C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80058C3C;
    // 0x80058C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058C28: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
L_80058C2C:
    // 0x80058C2C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80058C30: bnel        $t2, $zero, L_80058BA8
    if (ctx->r10 != 0) {
        // 0x80058C34: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_80058BA8;
    }
    goto skip_2;
    // 0x80058C34: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x80058C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058C3C:
    // 0x80058C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058C40: jr          $ra
    // 0x80058C44: nop

    return;
    // 0x80058C44: nop

;}
RECOMP_FUNC void Versus_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C176C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1774: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1778: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
    // 0x800C177C: sltiu       $at, $a0, 0x15
    ctx->r1 = ctx->r4 < 0X15 ? 1 : 0;
    // 0x800C1780: beq         $at, $zero, L_800C1E4C
    if (ctx->r1 == 0) {
        // 0x800C1784: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C1E4C;
    }
    // 0x800C1784: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C1788: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C178C: addu        $at, $at, $t6
    gpr jr_addend_800C1794 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C1790: lw          $t6, -0x6D5C($at)
    ctx->r14 = ADD32(ctx->r1, -0X6D5C);
    // 0x800C1794: jr          $t6
    // 0x800C1798: nop

    switch (jr_addend_800C1794 >> 2) {
        case 0: goto L_800C179C; break;
        case 1: goto L_800C17C0; break;
        case 2: goto L_800C1818; break;
        case 3: goto L_800C1878; break;
        case 4: goto L_800C18D0; break;
        case 5: goto L_800C19C4; break;
        case 6: goto L_800C1A5C; break;
        case 7: goto L_800C1AB4; break;
        case 8: goto L_800C1B28; break;
        case 9: goto L_800C1BA0; break;
        case 10: goto L_800C1BF0; break;
        case 11: goto L_800C1C98; break;
        case 12: goto L_800C1D04; break;
        case 13: goto L_800C1D80; break;
        case 14: goto L_800C1E4C; break;
        case 15: goto L_800C1E4C; break;
        case 16: goto L_800C1E4C; break;
        case 17: goto L_800C1E4C; break;
        case 18: goto L_800C1E4C; break;
        case 19: goto L_800C1E4C; break;
        case 20: goto L_800C1E08; break;
        default: switch_error(__func__, 0x800C1794, 0x800D92A4);
    }
    // 0x800C1798: nop

L_800C179C:
    // 0x800C179C: jal         0x800C1368
    // 0x800C17A0: nop

    Versus_InitMatch(rdram, ctx);
        goto after_0;
    // 0x800C17A0: nop

    after_0:
    // 0x800C17A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C17A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C17AC: jal         0x800C1690
    // 0x800C17B0: sw          $t7, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r15;
    Versus_ClearFrameCounter(rdram, ctx);
        goto after_1;
    // 0x800C17B0: sw          $t7, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r15;
    after_1:
    // 0x800C17B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C17B8: b           L_800C1E4C
    // 0x800C17BC: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C17BC: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C17C0:
    // 0x800C17C0: jal         0x800C15D8
    // 0x800C17C4: nop

    Versus_InitViewports(rdram, ctx);
        goto after_2;
    // 0x800C17C4: nop

    after_2:
    // 0x800C17C8: bne         $v0, $zero, L_800C17D8
    if (ctx->r2 != 0) {
        // 0x800C17CC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C17D8;
    }
    // 0x800C17CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C17D0: b           L_800C1E4C
    // 0x800C17D4: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C17D4: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C17D8:
    // 0x800C17D8: jal         0x800C16A0
    // 0x800C17DC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    Versus_WaitFrames(rdram, ctx);
        goto after_3;
    // 0x800C17DC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_3:
    // 0x800C17E0: beq         $v0, $zero, L_800C180C
    if (ctx->r2 == 0) {
        // 0x800C17E4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800C180C;
    }
    // 0x800C17E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C17E8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800C17EC: lhu         $a1, 0x7C90($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7C90);
    // 0x800C17F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C17F4: jal         0x8001D444
    // 0x800C17F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_4;
    // 0x800C17F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x800C17FC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800C1800: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1804: jal         0x800C1690
    // 0x800C1808: sw          $t8, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r24;
    Versus_ClearFrameCounter(rdram, ctx);
        goto after_5;
    // 0x800C1808: sw          $t8, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r24;
    after_5:
L_800C180C:
    // 0x800C180C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1810: b           L_800C1E4C
    // 0x800C1814: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1814: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1818:
    // 0x800C1818: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C181C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1820: jal         0x800BE564
    // 0x800C1824: sw          $t9, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r25;
    Versus_SelectStartingForm(rdram, ctx);
        goto after_6;
    // 0x800C1824: sw          $t9, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r25;
    after_6:
    // 0x800C1828: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C182C: lw          $t0, -0x784C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X784C);
    // 0x800C1830: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1834: beq         $v0, $t0, L_800C1844
    if (ctx->r2 == ctx->r8) {
        // 0x800C1838: nop
    
            goto L_800C1844;
    }
    // 0x800C1838: nop

    // 0x800C183C: b           L_800C1E4C
    // 0x800C1840: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1840: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1844:
    // 0x800C1844: jal         0x800C16A0
    // 0x800C1848: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    Versus_WaitFrames(rdram, ctx);
        goto after_7;
    // 0x800C1848: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_7:
    // 0x800C184C: beq         $v0, $zero, L_800C186C
    if (ctx->r2 == 0) {
        // 0x800C1850: nop
    
            goto L_800C186C;
    }
    // 0x800C1850: nop

    // 0x800C1854: jal         0x800ABA08
    // 0x800C1858: nop

    Player_InitVersus(rdram, ctx);
        goto after_8;
    // 0x800C1858: nop

    after_8:
    // 0x800C185C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800C1860: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1864: jal         0x800C1690
    // 0x800C1868: sw          $t1, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r9;
    Versus_ClearFrameCounter(rdram, ctx);
        goto after_9;
    // 0x800C1868: sw          $t1, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r9;
    after_9:
L_800C186C:
    // 0x800C186C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1870: b           L_800C1E4C
    // 0x800C1874: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1874: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1878:
    // 0x800C1878: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800C187C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1880: jal         0x800BEF00
    // 0x800C1884: sw          $t2, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r10;
    Versus_UpdateStartCountdown(rdram, ctx);
        goto after_10;
    // 0x800C1884: sw          $t2, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r10;
    after_10:
    // 0x800C1888: bne         $v0, $zero, L_800C189C
    if (ctx->r2 != 0) {
        // 0x800C188C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C189C;
    }
    // 0x800C188C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1890: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1894: b           L_800C1E4C
    // 0x800C1898: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1898: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C189C:
    // 0x800C189C: bne         $v0, $at, L_800C18AC
    if (ctx->r2 != ctx->r1) {
        // 0x800C18A0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800C18AC;
    }
    // 0x800C18A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C18A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C18A8: sw          $t3, 0x7E7C($at)
    MEM_W(0X7E7C, ctx->r1) = ctx->r11;
L_800C18AC:
    // 0x800C18AC: jal         0x800C16A0
    // 0x800C18B0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    Versus_WaitFrames(rdram, ctx);
        goto after_11;
    // 0x800C18B0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_11:
    // 0x800C18B4: beq         $v0, $zero, L_800C18C8
    if (ctx->r2 == 0) {
        // 0x800C18B8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C18C8;
    }
    // 0x800C18B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C18BC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C18C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C18C4: sw          $t4, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r12;
L_800C18C8:
    // 0x800C18C8: b           L_800C1E4C
    // 0x800C18CC: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C18CC: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C18D0:
    // 0x800C18D0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800C18D4: lw          $t5, 0x4A9C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4A9C);
    // 0x800C18D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C18DC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800C18E0: bne         $t5, $at, L_800C1910
    if (ctx->r13 != ctx->r1) {
        // 0x800C18E4: nop
    
            goto L_800C1910;
    }
    // 0x800C18E4: nop

    // 0x800C18E8: lw          $t6, 0x4AA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4AA0);
    // 0x800C18EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C18F0: ori         $a1, $zero, 0x802F
    ctx->r5 = 0 | 0X802F;
    // 0x800C18F4: bne         $t6, $zero, L_800C1910
    if (ctx->r14 != 0) {
        // 0x800C18F8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800C1910;
    }
    // 0x800C18F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C18FC: jal         0x8001D444
    // 0x800C1900: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_12;
    // 0x800C1900: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_12:
    // 0x800C1904: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C1908: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C190C: sw          $t7, 0x4AA0($at)
    MEM_W(0X4AA0, ctx->r1) = ctx->r15;
L_800C1910:
    // 0x800C1910: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800C1914: lw          $t8, 0x78AC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78AC);
    // 0x800C1918: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C191C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800C1920: bne         $t8, $at, L_800C1944
    if (ctx->r24 != ctx->r1) {
        // 0x800C1924: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_800C1944;
    }
    // 0x800C1924: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x800C1928: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C192C: jal         0x800BE078
    // 0x800C1930: sw          $t9, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r25;
    Versus_UpdateTimer(rdram, ctx);
        goto after_13;
    // 0x800C1930: sw          $t9, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r25;
    after_13:
    // 0x800C1934: jal         0x800BDE3C
    // 0x800C1938: nop

    Versus_dummy_800BDE3C(rdram, ctx);
        goto after_14;
    // 0x800C1938: nop

    after_14:
    // 0x800C193C: b           L_800C194C
    // 0x800C1940: nop

        goto L_800C194C;
    // 0x800C1940: nop

L_800C1944:
    // 0x800C1944: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1948: sw          $t0, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r8;
L_800C194C:
    // 0x800C194C: jal         0x800BF9AC
    // 0x800C1950: nop

    Versus_CheckForWinner(rdram, ctx);
        goto after_15;
    // 0x800C1950: nop

    after_15:
    // 0x800C1954: beq         $v0, $zero, L_800C19B0
    if (ctx->r2 == 0) {
        // 0x800C1958: lui         $a0, 0x1001
        ctx->r4 = S32(0X1001 << 16);
            goto L_800C19B0;
    }
    // 0x800C1958: lui         $a0, 0x1001
    ctx->r4 = S32(0X1001 << 16);
    // 0x800C195C: jal         0x800182F4
    // 0x800C1960: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_16;
    // 0x800C1960: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_16:
    // 0x800C1964: lui         $a0, 0x1101
    ctx->r4 = S32(0X1101 << 16);
    // 0x800C1968: jal         0x800182F4
    // 0x800C196C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_17;
    // 0x800C196C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_17:
    // 0x800C1970: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800C1974: lw          $t1, 0x78AC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78AC);
    // 0x800C1978: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C197C: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x800C1980: bne         $t1, $at, L_800C1994
    if (ctx->r9 != ctx->r1) {
        // 0x800C1984: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_800C1994;
    }
    // 0x800C1984: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800C1988: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C198C: b           L_800C199C
    // 0x800C1990: sw          $t2, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r10;
        goto L_800C199C;
    // 0x800C1990: sw          $t2, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r10;
L_800C1994:
    // 0x800C1994: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1998: sw          $zero, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = 0;
L_800C199C:
    // 0x800C199C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C19A0: jal         0x800C1690
    // 0x800C19A4: sw          $t3, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r11;
    Versus_ClearFrameCounter(rdram, ctx);
        goto after_18;
    // 0x800C19A4: sw          $t3, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r11;
    after_18:
    // 0x800C19A8: b           L_800C19B8
    // 0x800C19AC: nop

        goto L_800C19B8;
    // 0x800C19AC: nop

L_800C19B0:
    // 0x800C19B0: jal         0x800BF17C
    // 0x800C19B4: nop

    Versus_UpdatePlayerStatus(rdram, ctx);
        goto after_19;
    // 0x800C19B4: nop

    after_19:
L_800C19B8:
    // 0x800C19B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C19BC: b           L_800C1E4C
    // 0x800C19C0: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C19C0: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C19C4:
    // 0x800C19C4: jal         0x800C16A0
    // 0x800C19C8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    Versus_WaitFrames(rdram, ctx);
        goto after_20;
    // 0x800C19C8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_20:
    // 0x800C19CC: beq         $v0, $zero, L_800C1A50
    if (ctx->r2 == 0) {
        // 0x800C19D0: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800C1A50;
    }
    // 0x800C19D0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C19D4: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800C19D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C19DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C19E0: beq         $v0, $zero, L_800C1A10
    if (ctx->r2 == 0) {
        // 0x800C19E4: addiu       $a1, $zero, 0x26
        ctx->r5 = ADD32(0, 0X26);
            goto L_800C1A10;
    }
    // 0x800C19E4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x800C19E8: beq         $v0, $at, L_800C1A10
    if (ctx->r2 == ctx->r1) {
        // 0x800C19EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C1A10;
    }
    // 0x800C19EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C19F0: beq         $v0, $at, L_800C1A10
    if (ctx->r2 == ctx->r1) {
        // 0x800C19F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C1A10;
    }
    // 0x800C19F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C19F8: beq         $v0, $at, L_800C1A10
    if (ctx->r2 == ctx->r1) {
        // 0x800C19FC: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_800C1A10;
    }
    // 0x800C19FC: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800C1A00: beq         $v0, $at, L_800C1A24
    if (ctx->r2 == ctx->r1) {
        // 0x800C1A04: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800C1A24;
    }
    // 0x800C1A04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C1A08: b           L_800C1A38
    // 0x800C1A0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_800C1A38;
    // 0x800C1A0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_800C1A10:
    // 0x800C1A10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C1A14: jal         0x8001D444
    // 0x800C1A18: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_21;
    // 0x800C1A18: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_21:
    // 0x800C1A1C: b           L_800C1A38
    // 0x800C1A20: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_800C1A38;
    // 0x800C1A20: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_800C1A24:
    // 0x800C1A24: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x800C1A28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C1A2C: jal         0x8001D444
    // 0x800C1A30: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_22;
    // 0x800C1A30: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_22:
    // 0x800C1A34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_800C1A38:
    // 0x800C1A38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1A3C: sw          $t4, -0x78B0($at)
    MEM_W(-0X78B0, ctx->r1) = ctx->r12;
    // 0x800C1A40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1A44: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800C1A48: jal         0x800C024C
    // 0x800C1A4C: sw          $t5, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r13;
    func_versus_800C024C(rdram, ctx);
        goto after_23;
    // 0x800C1A4C: sw          $t5, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r13;
    after_23:
L_800C1A50:
    // 0x800C1A50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1A54: b           L_800C1E4C
    // 0x800C1A58: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1A58: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1A5C:
    // 0x800C1A5C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800C1A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1A64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1A68: sw          $t6, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r14;
    // 0x800C1A6C: jal         0x800C0294
    // 0x800C1A70: lw          $a0, -0x7858($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7858);
    func_versus_800C0294(rdram, ctx);
        goto after_24;
    // 0x800C1A70: lw          $a0, -0x7858($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7858);
    after_24:
    // 0x800C1A74: bne         $v0, $zero, L_800C1A84
    if (ctx->r2 != 0) {
        // 0x800C1A78: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C1A84;
    }
    // 0x800C1A78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1A7C: b           L_800C1E4C
    // 0x800C1A80: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1A80: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1A84:
    // 0x800C1A84: jal         0x800C16A0
    // 0x800C1A88: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    Versus_WaitFrames(rdram, ctx);
        goto after_25;
    // 0x800C1A88: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_25:
    // 0x800C1A8C: beq         $v0, $zero, L_800C1AA8
    if (ctx->r2 == 0) {
        // 0x800C1A90: nop
    
            goto L_800C1AA8;
    }
    // 0x800C1A90: nop

    // 0x800C1A94: jal         0x800C1690
    // 0x800C1A98: nop

    Versus_ClearFrameCounter(rdram, ctx);
        goto after_26;
    // 0x800C1A98: nop

    after_26:
    // 0x800C1A9C: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800C1AA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1AA4: sw          $t7, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r15;
L_800C1AA8:
    // 0x800C1AA8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1AAC: b           L_800C1E4C
    // 0x800C1AB0: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1AB0: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1AB4:
    // 0x800C1AB4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800C1AB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1ABC: sw          $t8, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r24;
    // 0x800C1AC0: jal         0x800C16A0
    // 0x800C1AC4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    Versus_WaitFrames(rdram, ctx);
        goto after_27;
    // 0x800C1AC4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_27:
    // 0x800C1AC8: beq         $v0, $zero, L_800C1B1C
    if (ctx->r2 == 0) {
        // 0x800C1ACC: nop
    
            goto L_800C1B1C;
    }
    // 0x800C1ACC: nop

    // 0x800C1AD0: jal         0x800C1690
    // 0x800C1AD4: nop

    Versus_ClearFrameCounter(rdram, ctx);
        goto after_28;
    // 0x800C1AD4: nop

    after_28:
    // 0x800C1AD8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800C1ADC: lw          $v1, 0x78AC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78AC);
    // 0x800C1AE0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C1AE4: bnel        $v1, $zero, L_800C1AFC
    if (ctx->r3 != 0) {
        // 0x800C1AE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C1AFC;
    }
    goto skip_0;
    // 0x800C1AE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x800C1AEC: lw          $t9, -0x784C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X784C);
    // 0x800C1AF0: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x800C1AF4: beq         $at, $zero, L_800C1B04
    if (ctx->r1 == 0) {
        // 0x800C1AF8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C1B04;
    }
    // 0x800C1AF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800C1AFC:
    // 0x800C1AFC: bne         $v1, $at, L_800C1B14
    if (ctx->r3 != ctx->r1) {
        // 0x800C1B00: addiu       $t1, $zero, 0x9
        ctx->r9 = ADD32(0, 0X9);
            goto L_800C1B14;
    }
    // 0x800C1B00: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
L_800C1B04:
    // 0x800C1B04: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x800C1B08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1B0C: b           L_800C1B1C
    // 0x800C1B10: sw          $t0, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r8;
        goto L_800C1B1C;
    // 0x800C1B10: sw          $t0, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r8;
L_800C1B14:
    // 0x800C1B14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1B18: sw          $t1, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r9;
L_800C1B1C:
    // 0x800C1B1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1B20: b           L_800C1E4C
    // 0x800C1B24: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1B24: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1B28:
    // 0x800C1B28: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800C1B2C: lw          $v0, 0x78AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78AC);
    // 0x800C1B30: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800C1B34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1B38: beq         $v0, $zero, L_800C1B54
    if (ctx->r2 == 0) {
        // 0x800C1B3C: sw          $t2, -0x7888($at)
        MEM_W(-0X7888, ctx->r1) = ctx->r10;
            goto L_800C1B54;
    }
    // 0x800C1B3C: sw          $t2, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r10;
    // 0x800C1B40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1B44: beq         $v0, $at, L_800C1B7C
    if (ctx->r2 == ctx->r1) {
        // 0x800C1B48: nop
    
            goto L_800C1B7C;
    }
    // 0x800C1B48: nop

    // 0x800C1B4C: b           L_800C1E50
    // 0x800C1B50: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
        goto L_800C1E50;
    // 0x800C1B50: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_800C1B54:
    // 0x800C1B54: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1B58: jal         0x800C107C
    // 0x800C1B5C: lw          $a0, -0x7858($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7858);
    func_versus_800C107C(rdram, ctx);
        goto after_29;
    // 0x800C1B5C: lw          $a0, -0x7858($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7858);
    after_29:
    // 0x800C1B60: beq         $v0, $zero, L_800C1B74
    if (ctx->r2 == 0) {
        // 0x800C1B64: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C1B74;
    }
    // 0x800C1B64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1B68: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800C1B6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1B70: sw          $t3, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r11;
L_800C1B74:
    // 0x800C1B74: b           L_800C1E4C
    // 0x800C1B78: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1B78: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1B7C:
    // 0x800C1B7C: jal         0x800C0D10
    // 0x800C1B80: nop

    func_versus_800C0D10(rdram, ctx);
        goto after_30;
    // 0x800C1B80: nop

    after_30:
    // 0x800C1B84: beq         $v0, $zero, L_800C1B98
    if (ctx->r2 == 0) {
        // 0x800C1B88: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C1B98;
    }
    // 0x800C1B88: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1B8C: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x800C1B90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1B94: sw          $t4, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r12;
L_800C1B98:
    // 0x800C1B98: b           L_800C1E4C
    // 0x800C1B9C: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1B9C: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1BA0:
    // 0x800C1BA0: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800C1BA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1BA8: jal         0x800C08D0
    // 0x800C1BAC: sw          $t5, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r13;
    func_versus_800C08D0(rdram, ctx);
        goto after_31;
    // 0x800C1BAC: sw          $t5, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r13;
    after_31:
    // 0x800C1BB0: beq         $v0, $zero, L_800C1BE4
    if (ctx->r2 == 0) {
        // 0x800C1BB4: nop
    
            goto L_800C1BE4;
    }
    // 0x800C1BB4: nop

    // 0x800C1BB8: jal         0x800C1690
    // 0x800C1BBC: nop

    Versus_ClearFrameCounter(rdram, ctx);
        goto after_32;
    // 0x800C1BBC: nop

    after_32:
    // 0x800C1BC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C1BC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1BC8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1BCC: swc1        $f4, -0x7854($at)
    MEM_W(-0X7854, ctx->r1) = ctx->f4.u32l;
    // 0x800C1BD0: addiu       $v1, $v1, -0x77D0
    ctx->r3 = ADD32(ctx->r3, -0X77D0);
    // 0x800C1BD4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C1BD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1BDC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800C1BE0: sw          $t6, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r14;
L_800C1BE4:
    // 0x800C1BE4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1BE8: b           L_800C1E4C
    // 0x800C1BEC: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1BEC: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1BF0:
    // 0x800C1BF0: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800C1BF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1BF8: sw          $t7, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r15;
    // 0x800C1BFC: jal         0x800C16A0
    // 0x800C1C00: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    Versus_WaitFrames(rdram, ctx);
        goto after_33;
    // 0x800C1C00: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_33:
    // 0x800C1C04: beq         $v0, $zero, L_800C1C8C
    if (ctx->r2 == 0) {
        // 0x800C1C08: nop
    
            goto L_800C1C8C;
    }
    // 0x800C1C08: nop

    // 0x800C1C0C: jal         0x800C0C84
    // 0x800C1C10: nop

    Versus_UpdateMenu(rdram, ctx);
        goto after_34;
    // 0x800C1C10: nop

    after_34:
    // 0x800C1C14: beq         $v0, $zero, L_800C1C8C
    if (ctx->r2 == 0) {
        // 0x800C1C18: lui         $a0, 0x1032
        ctx->r4 = S32(0X1032 << 16);
            goto L_800C1C8C;
    }
    // 0x800C1C18: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x800C1C1C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C1C20: lw          $v0, -0x785C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X785C);
    // 0x800C1C24: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x800C1C28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1C2C: beq         $v0, $zero, L_800C1C5C
    if (ctx->r2 == 0) {
        // 0x800C1C30: nop
    
            goto L_800C1C5C;
    }
    // 0x800C1C30: nop

    // 0x800C1C34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1C38: beq         $v0, $at, L_800C1C64
    if (ctx->r2 == ctx->r1) {
        // 0x800C1C3C: addiu       $t0, $zero, 0xC
        ctx->r8 = ADD32(0, 0XC);
            goto L_800C1C64;
    }
    // 0x800C1C3C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x800C1C40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1C44: beq         $v0, $at, L_800C1C70
    if (ctx->r2 == ctx->r1) {
        // 0x800C1C48: addiu       $t1, $zero, 0xD
        ctx->r9 = ADD32(0, 0XD);
            goto L_800C1C70;
    }
    // 0x800C1C48: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x800C1C4C: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x800C1C50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1C54: b           L_800C1C78
    // 0x800C1C58: sw          $t8, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r24;
        goto L_800C1C78;
    // 0x800C1C58: sw          $t8, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r24;
L_800C1C5C:
    // 0x800C1C5C: b           L_800C1C78
    // 0x800C1C60: sw          $t9, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r25;
        goto L_800C1C78;
    // 0x800C1C60: sw          $t9, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r25;
L_800C1C64:
    // 0x800C1C64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1C68: b           L_800C1C78
    // 0x800C1C6C: sw          $t0, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r8;
        goto L_800C1C78;
    // 0x800C1C6C: sw          $t0, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r8;
L_800C1C70:
    // 0x800C1C70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1C74: sw          $t1, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r9;
L_800C1C78:
    // 0x800C1C78: jal         0x800182F4
    // 0x800C1C7C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_35;
    // 0x800C1C7C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_35:
    // 0x800C1C80: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x800C1C84: jal         0x800182F4
    // 0x800C1C88: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_36;
    // 0x800C1C88: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_36:
L_800C1C8C:
    // 0x800C1C8C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1C90: b           L_800C1E4C
    // 0x800C1C94: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1C94: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1C98:
    // 0x800C1C98: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1C9C: addiu       $v1, $v1, -0x77D0
    ctx->r3 = ADD32(ctx->r3, -0X77D0);
    // 0x800C1CA0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CA4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C1CA8: addiu       $v0, $v0, -0x7CA8
    ctx->r2 = ADD32(ctx->r2, -0X7CA8);
    // 0x800C1CAC: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800C1CB0: slti        $at, $t3, 0x1E1
    ctx->r1 = SIGNED(ctx->r11) < 0X1E1 ? 1 : 0;
    // 0x800C1CB4: bne         $at, $zero, L_800C1E4C
    if (ctx->r1 != 0) {
        // 0x800C1CB8: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_800C1E4C;
    }
    // 0x800C1CB8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800C1CBC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1CC0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C1CC4: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x800C1CC8: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800C1CCC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C1CD0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C1CD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1CD8: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x800C1CDC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C1CE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C1CE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1CE8: sw          $t7, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r15;
    // 0x800C1CEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1CF0: jal         0x800C16D0
    // 0x800C1CF4: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    Versus_PlayAgain(rdram, ctx);
        goto after_37;
    // 0x800C1CF4: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    after_37:
    // 0x800C1CF8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1CFC: b           L_800C1E4C
    // 0x800C1D00: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1D00: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1D04:
    // 0x800C1D04: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1D08: addiu       $v1, $v1, -0x77D0
    ctx->r3 = ADD32(ctx->r3, -0X77D0);
    // 0x800C1D0C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D10: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C1D14: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x800C1D18: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800C1D1C: slti        $at, $t0, 0xA1
    ctx->r1 = SIGNED(ctx->r8) < 0XA1 ? 1 : 0;
    // 0x800C1D20: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800C1D24: bne         $at, $zero, L_800C1E4C
    if (ctx->r1 != 0) {
        // 0x800C1D28: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800C1E4C;
    }
    // 0x800C1D28: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800C1D2C: slti        $at, $t0, 0xB1
    ctx->r1 = SIGNED(ctx->r8) < 0XB1 ? 1 : 0;
    // 0x800C1D30: bne         $at, $zero, L_800C1D44
    if (ctx->r1 != 0) {
        // 0x800C1D34: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800C1D44;
    }
    // 0x800C1D34: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1D38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C1D3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C1D40: sw          $t1, 0x78A8($at)
    MEM_W(0X78A8, ctx->r1) = ctx->r9;
L_800C1D44:
    // 0x800C1D44: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800C1D48: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C1D4C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C1D50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1D54: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x800C1D58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1D5C: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x800C1D60: slti        $at, $v0, 0xE1
    ctx->r1 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x800C1D64: bnel        $at, $zero, L_800C1E50
    if (ctx->r1 != 0) {
        // 0x800C1D68: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800C1E50;
    }
    goto skip_1;
    // 0x800C1D68: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_1:
    // 0x800C1D6C: jal         0x800C1700
    // 0x800C1D70: nop

    Versus_ReturnToMenu(rdram, ctx);
        goto after_38;
    // 0x800C1D70: nop

    after_38:
    // 0x800C1D74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1D78: b           L_800C1E4C
    // 0x800C1D7C: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
        goto L_800C1E4C;
    // 0x800C1D7C: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1D80:
    // 0x800C1D80: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1D84: addiu       $v1, $v1, -0x77D0
    ctx->r3 = ADD32(ctx->r3, -0X77D0);
    // 0x800C1D88: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D8C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C1D90: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x800C1D94: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x800C1D98: slti        $at, $t5, 0xA1
    ctx->r1 = SIGNED(ctx->r13) < 0XA1 ? 1 : 0;
    // 0x800C1D9C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800C1DA0: bne         $at, $zero, L_800C1E4C
    if (ctx->r1 != 0) {
        // 0x800C1DA4: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_800C1E4C;
    }
    // 0x800C1DA4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800C1DA8: slti        $at, $t5, 0xB1
    ctx->r1 = SIGNED(ctx->r13) < 0XB1 ? 1 : 0;
    // 0x800C1DAC: bne         $at, $zero, L_800C1DC0
    if (ctx->r1 != 0) {
        // 0x800C1DB0: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800C1DC0;
    }
    // 0x800C1DB0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C1DB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C1DB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C1DBC: sw          $t6, 0x78A8($at)
    MEM_W(0X78A8, ctx->r1) = ctx->r14;
L_800C1DC0:
    // 0x800C1DC0: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800C1DC4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C1DC8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C1DCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1DD0: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x800C1DD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1DD8: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x800C1DDC: slti        $at, $v0, 0xE1
    ctx->r1 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x800C1DE0: bnel        $at, $zero, L_800C1E50
    if (ctx->r1 != 0) {
        // 0x800C1DE4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800C1E50;
    }
    goto skip_2;
    // 0x800C1DE4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_2:
    // 0x800C1DE8: jal         0x800BC760
    // 0x800C1DEC: nop

    Versus_Exit(rdram, ctx);
        goto after_39;
    // 0x800C1DEC: nop

    after_39:
    // 0x800C1DF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C1DF4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x800C1DF8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1DFC: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
    // 0x800C1E00: b           L_800C1E4C
    // 0x800C1E04: sw          $t9, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r25;
        goto L_800C1E4C;
    // 0x800C1E04: sw          $t9, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r25;
L_800C1E08:
    // 0x800C1E08: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800C1E0C: lw          $t1, 0x797C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X797C);
    // 0x800C1E10: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800C1E14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1E18: sw          $t0, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = ctx->r8;
    // 0x800C1E1C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800C1E20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1E24: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x800C1E28: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800C1E2C: beq         $t3, $zero, L_800C1E3C
    if (ctx->r11 == 0) {
        // 0x800C1E30: nop
    
            goto L_800C1E3C;
    }
    // 0x800C1E30: nop

    // 0x800C1E34: b           L_800C1E44
    // 0x800C1E38: sw          $t4, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r12;
        goto L_800C1E44;
    // 0x800C1E38: sw          $t4, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = ctx->r12;
L_800C1E3C:
    // 0x800C1E3C: jal         0x800C175C
    // 0x800C1E40: nop

    Versus_dummy_800C175C(rdram, ctx);
        goto after_40;
    // 0x800C1E40: nop

    after_40:
L_800C1E44:
    // 0x800C1E44: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1E48: lw          $a0, -0x78AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78AC);
L_800C1E4C:
    // 0x800C1E4C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_800C1E50:
    // 0x800C1E50: beq         $a0, $at, L_800C1E68
    if (ctx->r4 == ctx->r1) {
        // 0x800C1E54: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800C1E68;
    }
    // 0x800C1E54: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C1E58: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800C1E5C: beq         $a0, $at, L_800C1E68
    if (ctx->r4 == ctx->r1) {
        // 0x800C1E60: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800C1E68;
    }
    // 0x800C1E60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800C1E64: bne         $a0, $at, L_800C1E78
    if (ctx->r4 != ctx->r1) {
        // 0x800C1E68: addiu       $v0, $v0, 0x4A98
        ctx->r2 = ADD32(ctx->r2, 0X4A98);
            goto L_800C1E78;
    }
L_800C1E68:
    // 0x800C1E68: addiu       $v0, $v0, 0x4A98
    ctx->r2 = ADD32(ctx->r2, 0X4A98);
    // 0x800C1E6C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800C1E70: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800C1E74: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800C1E78:
    // 0x800C1E78: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x800C1E7C: bne         $at, $zero, L_800C1E8C
    if (ctx->r1 != 0) {
        // 0x800C1E80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C1E8C;
    }
    // 0x800C1E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1E84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C1E88: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
L_800C1E8C:
    // 0x800C1E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1E94: jr          $ra
    // 0x800C1E98: nop

    return;
    // 0x800C1E98: nop

;}
RECOMP_FUNC void Object_LoadLevelObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062664: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80062668: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8006266C: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80062670: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80062674: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80062678: addiu       $s3, $s3, -0x7DCC
    ctx->r19 = ADD32(ctx->r19, -0X7DCC);
    // 0x8006267C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80062680: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80062684: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80062688: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8006268C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80062690: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80062694: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80062698: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8006269C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800626A0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800626A4: addiu       $v0, $v0, -0x7D84
    ctx->r2 = ADD32(ctx->r2, -0X7D84);
    // 0x800626A8: bne         $s2, $v1, L_800626FC
    if (ctx->r18 != ctx->r3) {
        // 0x800626AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800626FC;
    }
    // 0x800626AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800626B0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800626B4: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x800626B8: addiu       $v0, $v0, -0x4EB8
    ctx->r2 = ADD32(ctx->r2, -0X4EB8);
    // 0x800626BC: bne         $s2, $t6, L_800626FC
    if (ctx->r18 != ctx->r14) {
        // 0x800626C0: sll         $t7, $v0, 4
        ctx->r15 = S32(ctx->r2 << 4);
            goto L_800626FC;
    }
    // 0x800626C0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800626C4: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800626C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800626CC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800626D0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800626D4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800626D8: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x800626DC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800626E0: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x800626E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800626E8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800626EC: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800626F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800626F4: b           L_80062848
    // 0x800626F8: sw          $t3, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r11;
        goto L_80062848;
    // 0x800626F8: sw          $t3, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r11;
L_800626FC:
    // 0x800626FC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80062700: bne         $v1, $at, L_80062754
    if (ctx->r3 != ctx->r1) {
        // 0x80062704: addiu       $v0, $v0, -0x7D84
        ctx->r2 = ADD32(ctx->r2, -0X7D84);
            goto L_80062754;
    }
    // 0x80062704: addiu       $v0, $v0, -0x7D84
    ctx->r2 = ADD32(ctx->r2, -0X7D84);
    // 0x80062708: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8006270C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80062710: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80062714: bne         $s2, $t4, L_80062754
    if (ctx->r18 != ctx->r12) {
        // 0x80062718: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80062754;
    }
    // 0x80062718: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8006271C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x80062720: addiu       $v0, $v0, -0xE74
    ctx->r2 = ADD32(ctx->r2, -0XE74);
    // 0x80062724: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80062728: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8006272C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80062730: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80062734: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x80062738: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8006273C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80062740: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80062744: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x80062748: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8006274C: b           L_80062848
    // 0x80062750: sw          $t1, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r9;
        goto L_80062848;
    // 0x80062750: sw          $t1, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r9;
L_80062754:
    // 0x80062754: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80062758: bnel        $v1, $at, L_800627B0
    if (ctx->r3 != ctx->r1) {
        // 0x8006275C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800627B0;
    }
    goto skip_0;
    // 0x8006275C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_0:
    // 0x80062760: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80062764: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80062768: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8006276C: bne         $s2, $t2, L_800627AC
    if (ctx->r18 != ctx->r10) {
        // 0x80062770: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800627AC;
    }
    // 0x80062770: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80062774: lui         $v0, 0xC03
    ctx->r2 = S32(0XC03 << 16);
    // 0x80062778: addiu       $v0, $v0, 0x56A4
    ctx->r2 = ADD32(ctx->r2, 0X56A4);
    // 0x8006277C: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x80062780: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x80062784: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80062788: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8006278C: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x80062790: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80062794: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80062798: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006279C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800627A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800627A4: b           L_80062848
    // 0x800627A8: sw          $t9, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r25;
        goto L_80062848;
    // 0x800627A8: sw          $t9, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r25;
L_800627AC:
    // 0x800627AC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_800627B0:
    // 0x800627B0: bne         $v1, $at, L_80062804
    if (ctx->r3 != ctx->r1) {
        // 0x800627B4: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80062804;
    }
    // 0x800627B4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800627B8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800627BC: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x800627C0: addiu       $v0, $v0, 0x88
    ctx->r2 = ADD32(ctx->r2, 0X88);
    // 0x800627C4: bne         $s2, $t0, L_80062804
    if (ctx->r18 != ctx->r8) {
        // 0x800627C8: sll         $t1, $v0, 4
        ctx->r9 = S32(ctx->r2 << 4);
            goto L_80062804;
    }
    // 0x800627C8: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800627CC: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x800627D0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800627D4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800627D8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800627DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800627E0: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x800627E4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800627E8: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x800627EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800627F0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800627F4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800627F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800627FC: b           L_80062848
    // 0x80062800: sw          $t7, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r15;
        goto L_80062848;
    // 0x80062800: sw          $t7, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r15;
L_80062804:
    // 0x80062804: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80062808: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8006280C: lw          $v0, -0x260($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260);
    // 0x80062810: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80062814: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80062818: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x8006281C: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x80062820: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80062824: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80062828: lw          $t3, 0x1FD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1FD0);
    // 0x8006282C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80062830: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x80062834: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80062838: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8006283C: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80062840: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80062844: sw          $t5, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r13;
L_80062848:
    // 0x80062848: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006284C: lw          $t6, -0x7ED4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7ED4);
    // 0x80062850: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80062854: addiu       $s1, $s1, -0x7D48
    ctx->r17 = ADD32(ctx->r17, -0X7D48);
    // 0x80062858: bne         $t6, $zero, L_800628B0
    if (ctx->r14 != 0) {
        // 0x8006285C: nop
    
            goto L_800628B0;
    }
    // 0x8006285C: nop

    // 0x80062860: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80062864: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80062868: blez        $t7, L_800628B0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006286C: nop
    
            goto L_800628B0;
    }
    // 0x8006286C: nop

    // 0x80062870: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_80062874:
    // 0x80062874: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80062878: bne         $t8, $at, L_80062890
    if (ctx->r24 != ctx->r1) {
        // 0x8006287C: nop
    
            goto L_80062890;
    }
    // 0x8006287C: nop

    // 0x80062880: jal         0x80061B68
    // 0x80062884: nop

    func_enmy_80061B68(rdram, ctx);
        goto after_0;
    // 0x80062884: nop

    after_0:
    // 0x80062888: b           L_8006289C
    // 0x8006288C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
        goto L_8006289C;
    // 0x8006288C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
L_80062890:
    // 0x80062890: jal         0x80061A4C
    // 0x80062894: nop

    func_enmy_80061A4C(rdram, ctx);
        goto after_1;
    // 0x80062894: nop

    after_1:
    // 0x80062898: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
L_8006289C:
    // 0x8006289C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800628A0: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800628A4: bnel        $at, $zero, L_80062874
    if (ctx->r1 != 0) {
        // 0x800628A8: lw          $t8, 0x0($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X0);
            goto L_80062874;
    }
    goto skip_1;
    // 0x800628A8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x800628AC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
L_800628B0:
    // 0x800628B0: bne         $s2, $v1, L_800628DC
    if (ctx->r18 != ctx->r3) {
        // 0x800628B4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800628DC;
    }
    // 0x800628B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800628B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800628BC: lwc1        $f0, 0x6474($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6474);
    // 0x800628C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800628C4: lwc1        $f2, 0x6478($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6478);
    // 0x800628C8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800628CC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x800628D0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    // 0x800628D4: b           L_8006296C
    // 0x800628D8: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
        goto L_8006296C;
    // 0x800628D8: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
L_800628DC:
    // 0x800628DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800628E0: bne         $v1, $at, L_80062910
    if (ctx->r3 != ctx->r1) {
        // 0x800628E4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80062910;
    }
    // 0x800628E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800628E8: lwc1        $f26, 0x647C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X647C);
    // 0x800628EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800628F0: lwc1        $f28, 0x6480($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X6480);
    // 0x800628F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800628F8: lwc1        $f2, 0x6484($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6484);
    // 0x800628FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062900: lwc1        $f0, 0x6488($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6488);
    // 0x80062904: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    // 0x80062908: b           L_8006296C
    // 0x8006290C: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
        goto L_8006296C;
    // 0x8006290C: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
L_80062910:
    // 0x80062910: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80062914: bne         $v1, $at, L_80062944
    if (ctx->r3 != ctx->r1) {
        // 0x80062918: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80062944;
    }
    // 0x80062918: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006291C: lwc1        $f26, 0x648C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X648C);
    // 0x80062920: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062924: lwc1        $f28, 0x6490($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X6490);
    // 0x80062928: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006292C: lwc1        $f2, 0x6494($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6494);
    // 0x80062930: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062934: lwc1        $f0, 0x6498($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6498);
    // 0x80062938: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    // 0x8006293C: b           L_8006296C
    // 0x80062940: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
        goto L_8006296C;
    // 0x80062940: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
L_80062944:
    // 0x80062944: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80062948: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8006294C: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x80062950: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80062954: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062958: lwc1        $f2, 0x649C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X649C);
    // 0x8006295C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062960: lwc1        $f0, 0x64A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X64A0);
    // 0x80062964: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    // 0x80062968: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
L_8006296C:
    // 0x8006296C: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80062970: addiu       $s2, $s2, -0x7D80
    ctx->r18 = ADD32(ctx->r18, -0X7D80);
    // 0x80062974: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80062978: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006297C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80062980: lw          $v1, 0x210($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X210);
    // 0x80062984: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80062988: beq         $v1, $zero, L_800629B0
    if (ctx->r3 == 0) {
        // 0x8006298C: nop
    
            goto L_800629B0;
    }
    // 0x8006298C: nop

    // 0x80062990: lwc1        $f4, 0x118($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X118);
    // 0x80062994: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80062998: nop

    // 0x8006299C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800629A0: nop

    // 0x800629A4: bc1f        L_800629B0
    if (!c1cs) {
        // 0x800629A8: nop
    
            goto L_800629B0;
    }
    // 0x800629A8: nop

    // 0x800629AC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800629B0:
    // 0x800629B0: beq         $v1, $zero, L_800629D4
    if (ctx->r3 == 0) {
        // 0x800629B4: nop
    
            goto L_800629D4;
    }
    // 0x800629B4: nop

    // 0x800629B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800629BC: lwc1        $f10, 0x118($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X118);
    // 0x800629C0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800629C4: nop

    // 0x800629C8: bc1f        L_800629D4
    if (!c1cs) {
        // 0x800629CC: nop
    
            goto L_800629D4;
    }
    // 0x800629CC: nop

    // 0x800629D0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_800629D4:
    // 0x800629D4: lw          $t1, 0x7DC8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DC8);
    // 0x800629D8: lw          $t9, -0x7CF0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CF0);
    // 0x800629DC: sw          $zero, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = 0;
    // 0x800629E0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800629E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800629E8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800629EC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800629F0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800629F4: addu        $s0, $t2, $t9
    ctx->r16 = ADD32(ctx->r10, ctx->r25);
L_800629F8:
    // 0x800629F8: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x800629FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80062A00: bltzl       $v0, L_80062B34
    if (SIGNED(ctx->r2) < 0) {
        // 0x80062A04: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80062B34;
    }
    goto skip_2;
    // 0x80062A04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x80062A08: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80062A0C: lwc1        $f2, 0x7D20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80062A10: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80062A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80062A18: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80062A1C: nop

    // 0x80062A20: bc1fl       L_80062B34
    if (!c1cs) {
        // 0x80062A24: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80062B34;
    }
    goto skip_3;
    // 0x80062A24: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x80062A28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80062A2C: nop

    // 0x80062A30: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80062A34: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80062A38: nop

    // 0x80062A3C: bc1fl       L_80062B34
    if (!c1cs) {
        // 0x80062A40: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80062B34;
    }
    goto skip_4;
    // 0x80062A40: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_4:
    // 0x80062A44: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80062A48: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80062A4C: bne         $t3, $at, L_80062AF8
    if (ctx->r11 != ctx->r1) {
        // 0x80062A50: slti        $at, $v0, 0x3E8
        ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
            goto L_80062AF8;
    }
    // 0x80062A50: slti        $at, $v0, 0x3E8
    ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // 0x80062A54: bnel        $at, $zero, L_80062AFC
    if (ctx->r1 != 0) {
        // 0x80062A58: mfc1        $a1, $f22
        ctx->r5 = (int32_t)ctx->f22.u32l;
            goto L_80062AFC;
    }
    goto skip_5;
    // 0x80062A58: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    skip_5:
    // 0x80062A5C: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x80062A60: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80062A64: nop

    // 0x80062A68: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80062A6C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80062A70: nop

    // 0x80062A74: bc1fl       L_80062AA4
    if (!c1cs) {
        // 0x80062A78: c.lt.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
            goto L_80062AA4;
    }
    goto skip_6;
    // 0x80062A78: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    skip_6:
    // 0x80062A7C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80062A80: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80062A84: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80062A88: lwc1        $f10, 0xAC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XAC);
    // 0x80062A8C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80062A90: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80062A94: nop

    // 0x80062A98: bc1tl       L_80062AD8
    if (c1cs) {
        // 0x80062A9C: mfc1        $a1, $f22
        ctx->r5 = (int32_t)ctx->f22.u32l;
            goto L_80062AD8;
    }
    goto skip_7;
    // 0x80062A9C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    skip_7:
    // 0x80062AA0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
L_80062AA4:
    // 0x80062AA4: nop

    // 0x80062AA8: bc1f        L_80062AEC
    if (!c1cs) {
        // 0x80062AAC: nop
    
            goto L_80062AEC;
    }
    // 0x80062AAC: nop

    // 0x80062AB0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x80062AB4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80062AB8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80062ABC: lwc1        $f16, 0xAC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XAC);
    // 0x80062AC0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80062AC4: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80062AC8: nop

    // 0x80062ACC: bc1f        L_80062AEC
    if (!c1cs) {
        // 0x80062AD0: nop
    
            goto L_80062AEC;
    }
    // 0x80062AD0: nop

    // 0x80062AD4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
L_80062AD8:
    // 0x80062AD8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80062ADC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80062AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80062AE4: jal         0x80062180
    // 0x80062AE8: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    Object_Load(rdram, ctx);
        goto after_2;
    // 0x80062AE8: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    after_2:
L_80062AEC:
    // 0x80062AEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80062AF0: b           L_80062B14
    // 0x80062AF4: lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DC8);
        goto L_80062B14;
    // 0x80062AF4: lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DC8);
L_80062AF8:
    // 0x80062AF8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
L_80062AFC:
    // 0x80062AFC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80062B00: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80062B04: jal         0x80062180
    // 0x80062B08: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    Object_Load(rdram, ctx);
        goto after_3;
    // 0x80062B08: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    after_3:
    // 0x80062B0C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80062B10: lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DC8);
L_80062B14:
    // 0x80062B14: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80062B18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80062B1C: sw          $t0, 0x7DC8($at)
    MEM_W(0X7DC8, ctx->r1) = ctx->r8;
    // 0x80062B20: addiu       $at, $zero, 0x2710
    ctx->r1 = ADD32(0, 0X2710);
    // 0x80062B24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80062B28: bne         $s1, $at, L_800629F8
    if (ctx->r17 != ctx->r1) {
        // 0x80062B2C: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800629F8;
    }
    // 0x80062B2C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80062B30: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80062B34:
    // 0x80062B34: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80062B38: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80062B3C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80062B40: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80062B44: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80062B48: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80062B4C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80062B50: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80062B54: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80062B58: jr          $ra
    // 0x80062B5C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80062B5C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Effect_Effect386_Spawn1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BFFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C000: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C004: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8007C008: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8007C00C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007C010: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007C014: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007C018: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007C01C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007C020:
    // 0x8007C020: bnel        $t6, $zero, L_8007C06C
    if (ctx->r14 != 0) {
        // 0x8007C024: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007C06C;
    }
    goto skip_0;
    // 0x8007C024: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007C028: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007C02C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007C030: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007C034: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007C038: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007C03C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007C040: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007C044: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8007C048: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007C04C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007C050: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8007C054: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8007C058: jal         0x8007BF64
    // 0x8007C05C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    Effect_Effect_Effect386_Setup(rdram, ctx);
        goto after_0;
    // 0x8007C05C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007C060: b           L_8007C07C
    // 0x8007C064: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8007C07C;
    // 0x8007C064: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C068: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007C06C:
    // 0x8007C06C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007C070: beql        $at, $zero, L_8007C020
    if (ctx->r1 == 0) {
        // 0x8007C074: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007C020;
    }
    goto skip_1;
    // 0x8007C074: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007C078: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8007C07C:
    // 0x8007C07C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007C080: jr          $ra
    // 0x8007C084: nop

    return;
    // 0x8007C084: nop

;}
RECOMP_FUNC void Audio_ClearVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE58: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AE5C: sw          $zero, 0x7388($at)
    MEM_W(0X7388, ctx->r1) = 0;
    // 0x8001AE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AE64: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AE68: sw          $v0, 0x7384($at)
    MEM_W(0X7384, ctx->r1) = ctx->r2;
    // 0x8001AE6C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AE70: jr          $ra
    // 0x8001AE74: sb          $v0, 0x738C($at)
    MEM_B(0X738C, ctx->r1) = ctx->r2;
    return;
    // 0x8001AE74: sb          $v0, 0x738C($at)
    MEM_B(0X738C, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void AudioThread_ScheduleProcessCmds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E920: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001E924: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001E928: lbu         $v1, 0x7C54($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7C54);
    // 0x8001E92C: lbu         $v0, 0x7C50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7C50);
    // 0x8001E930: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001E934: lw          $t7, 0x7C70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7C70);
    // 0x8001E938: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // 0x8001E93C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x8001E940: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001E944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E948: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001E94C: beq         $at, $zero, L_8001E95C
    if (ctx->r1 == 0) {
        // 0x8001E950: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001E95C;
    }
    // 0x8001E950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E954: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E958: sw          $t6, 0x7C70($at)
    MEM_W(0X7C70, ctx->r1) = ctx->r14;
L_8001E95C:
    // 0x8001E95C: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x8001E960: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8001E964: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8001E968: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001E96C: or          $a1, $t9, $t0
    ctx->r5 = ctx->r25 | ctx->r8;
    // 0x8001E970: lw          $a0, 0x7C5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C5C);
    // 0x8001E974: jal         0x80020720
    // 0x8001E978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001E978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001E97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E980: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001E984: lbu         $t1, 0x7C50($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C50);
    // 0x8001E988: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E98C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E990: jr          $ra
    // 0x8001E994: sb          $t1, 0x7C54($at)
    MEM_B(0X7C54, ctx->r1) = ctx->r9;
    return;
    // 0x8001E994: sb          $t1, 0x7C54($at)
    MEM_B(0X7C54, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void Effect_Effect365_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E5CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007E5D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007E5D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007E5D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007E5DC: jal         0x8005980C
    // 0x8007E5E0: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007E5E0: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_0:
    // 0x8007E5E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8007E5E8: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8007E5EC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007E5F0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007E5F4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007E5F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007E5FC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E600: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E604: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007E608: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8007E60C: lh          $t0, 0x44($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X44);
    // 0x8007E610: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8007E614: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8007E618: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007E61C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007E620: lui         $t5, 0x201
    ctx->r13 = S32(0X201 << 16);
    // 0x8007E624: addiu       $t5, $t5, 0xA30
    ctx->r13 = ADD32(ctx->r13, 0XA30);
    // 0x8007E628: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007E62C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8007E630: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007E634: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007E638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007E63C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007E640: jr          $ra
    // 0x8007E644: nop

    return;
    // 0x8007E644: nop

;}
RECOMP_FUNC void Effect_Effect383_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A3C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A3C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A3C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007A3CC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8007A3D0: lh          $t6, 0x1410($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1410);
    // 0x8007A3D4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007A3D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007A3DC: blezl       $t6, L_8007A4AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8007A3E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A4AC;
    }
    goto skip_0;
    // 0x8007A3E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8007A3E4: lwc1        $f0, 0x70($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X70);
    // 0x8007A3E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007A3EC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007A3F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007A3F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007A3F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007A3FC: jal         0x80005C34
    // 0x8007A400: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x8007A400: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8007A404: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007A408: jal         0x80006EB8
    // 0x8007A40C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8007A40C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x8007A410: jal         0x800BA170
    // 0x8007A414: nop

    RCP_SetupDL_64_2(rdram, ctx);
        goto after_2;
    // 0x8007A414: nop

    after_2:
    // 0x8007A418: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007A41C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8007A420: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
    // 0x8007A424: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007A428: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8007A42C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007A430: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007A434: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007A438: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8007A43C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007A440: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8007A444: lh          $t3, 0x44($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X44);
    // 0x8007A448: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8007A44C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8007A450: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007A454: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007A458: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8007A45C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007A460: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007A464: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8007A468: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007A46C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007A470: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8007A474: addiu       $t1, $t1, -0x7D40
    ctx->r9 = ADD32(ctx->r9, -0X7D40);
    // 0x8007A478: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007A47C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007A480: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007A484: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007A488: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007A48C: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8007A490: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007A494: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8007A498: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8007A49C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007A4A0: jal         0x800BA170
    // 0x8007A4A4: nop

    RCP_SetupDL_64_2(rdram, ctx);
        goto after_3;
    // 0x8007A4A4: nop

    after_3:
    // 0x8007A4A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A4AC:
    // 0x8007A4AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007A4B0: jr          $ra
    // 0x8007A4B4: nop

    return;
    // 0x8007A4B4: nop

;}
RECOMP_FUNC void HUD_VS_X_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DCB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008DCB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008DCB8: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8008DCBC: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8008DCC0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008DCC4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8008DCC8: jal         0x800BA4F0
    // 0x8008DCCC: nop

    RCP_SetupDL_78(rdram, ctx);
        goto after_0;
    // 0x8008DCCC: nop

    after_0:
    // 0x8008DCD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008DCD4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008DCD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008DCDC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008DCE0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008DCE4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008DCE8: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x8008DCEC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008DCF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8008DCF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008DCF8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008DCFC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DD00: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008DD04: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x8008DD08: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8008DD0C: lw          $t9, 0x1708($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1708);
    // 0x8008DD10: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8008DD14: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8008DD18: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8008DD1C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8008DD20: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8008DD24: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8008DD28: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8008DD2C: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8008DD30: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008DD34: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008DD38: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8008DD3C: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x8008DD40: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8008DD44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008DD48: addiu       $a2, $a2, 0x1F08
    ctx->r6 = ADD32(ctx->r6, 0X1F08);
    // 0x8008DD4C: addiu       $a1, $a1, 0x1ED0
    ctx->r5 = ADD32(ctx->r5, 0X1ED0);
    // 0x8008DD50: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008DD54: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008DD58: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8008DD5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8008DD60: jal         0x8009C320
    // 0x8008DD64: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x8008DD64: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8008DD68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DD6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008DD70: jr          $ra
    // 0x8008DD74: nop

    return;
    // 0x8008DD74: nop

;}
RECOMP_FUNC void Audio_GetSfxReverb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BC0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80016BC4: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80016BC8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80016BCC: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80016BD0: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80016BD4: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x80016BD8: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80016BDC: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80016BE0: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80016BE4: addiu       $t2, $t2, -0x79A0
    ctx->r10 = ADD32(ctx->r10, -0X79A0);
    // 0x80016BE8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80016BEC: addu        $a3, $t1, $t2
    ctx->r7 = ADD32(ctx->r9, ctx->r10);
    // 0x80016BF0: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x80016BF4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80016BF8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80016BFC: sll         $t4, $t3, 10
    ctx->r12 = S32(ctx->r11 << 10);
    // 0x80016C00: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80016C04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80016C08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80016C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016C10: bltz        $t4, L_80016C64
    if (SIGNED(ctx->r12) < 0) {
        // 0x80016C14: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80016C64;
    }
    // 0x80016C14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80016C18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016C1C: lwc1        $f2, -0x6FFC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6FFC);
    // 0x80016C20: lwc1        $f0, 0x1C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80016C24: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x80016C28: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80016C2C: nop

    // 0x80016C30: bc1f        L_80016C64
    if (!c1cs) {
        // 0x80016C34: nop
    
            goto L_80016C64;
    }
    // 0x80016C34: nop

    // 0x80016C38: div.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80016C3C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80016C40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016C44: nop

    // 0x80016C48: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80016C4C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80016C50: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80016C54: nop

    // 0x80016C58: sll         $t6, $v0, 24
    ctx->r14 = S32(ctx->r2 << 24);
    // 0x80016C5C: b           L_80016C64
    // 0x80016C60: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
        goto L_80016C64;
    // 0x80016C60: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
L_80016C64:
    // 0x80016C64: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80016C68: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80016C6C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80016C70: lw          $a0, -0x17FC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17FC);
    // 0x80016C74: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80016C78: addiu       $t9, $t9, 0x2FE8
    ctx->r25 = ADD32(ctx->r25, 0X2FE8);
    // 0x80016C7C: beq         $t9, $a0, L_80016C88
    if (ctx->r25 == ctx->r4) {
        // 0x80016C80: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80016C88;
    }
    // 0x80016C80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016C84: lb          $v1, 0xC2($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XC2);
L_80016C88:
    // 0x80016C88: bnel        $v1, $at, L_80016C98
    if (ctx->r3 != ctx->r1) {
        // 0x80016C8C: lw          $t0, 0x18($a3)
        ctx->r8 = MEM_W(ctx->r7, 0X18);
            goto L_80016C98;
    }
    goto skip_0;
    // 0x80016C8C: lw          $t0, 0x18($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X18);
    skip_0:
    // 0x80016C90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80016C94: lw          $t0, 0x18($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X18);
L_80016C98:
    // 0x80016C98: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80016C9C: lb          $t4, 0x5D60($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X5D60);
    // 0x80016CA0: lb          $t1, 0x0($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X0);
    // 0x80016CA4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80016CA8: lb          $t6, 0x5D64($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X5D64);
    // 0x80016CAC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80016CB0: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80016CB4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80016CB8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80016CBC: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x80016CC0: bnel        $at, $zero, L_80016CD0
    if (ctx->r1 != 0) {
        // 0x80016CC4: sll         $v0, $a0, 24
        ctx->r2 = S32(ctx->r4 << 24);
            goto L_80016CD0;
    }
    goto skip_1;
    // 0x80016CC4: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    skip_1:
    // 0x80016CC8: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x80016CCC: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
L_80016CD0:
    // 0x80016CD0: sra         $t7, $v0, 24
    ctx->r15 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80016CD4: jr          $ra
    // 0x80016CD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80016CD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void Boss300_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042FE0: jr          $ra
    // 0x80042FE4: nop

    return;
    // 0x80042FE4: nop

;}
RECOMP_FUNC void Effect_Effect344_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007868C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80078690: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80078694: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80078698: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007869C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800786A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800786A4: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x800786A8: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x800786AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800786B0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800786B4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800786B8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800786BC: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x800786C0: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x800786C4: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x800786C8: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x800786CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800786D0: jal         0x800B9B38
    // 0x800786D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_60(rdram, ctx);
        goto after_0;
    // 0x800786D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800786D8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800786DC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800786E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800786E4: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x800786E8: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
    // 0x800786EC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800786F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800786F4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800786F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800786FC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078700: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80078704: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80078708: lwc1        $f0, 0x70($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X70);
    // 0x8007870C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80078710: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80078714: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80078718: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007871C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80078720: jal         0x80005C34
    // 0x80078724: nop

    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80078724: nop

    after_1:
    // 0x80078728: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007872C: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x80078730: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80078734: lh          $t4, 0x44($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X44);
    // 0x80078738: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007873C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80078740: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80078744: bne         $at, $zero, L_80078754
    if (ctx->r1 != 0) {
        // 0x80078748: nop
    
            goto L_80078754;
    }
    // 0x80078748: nop

    // 0x8007874C: jal         0x80005D44
    // 0x80078750: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x80078750: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
L_80078754:
    // 0x80078754: jal         0x80006EB8
    // 0x80078758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x80078758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8007875C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078760: lui         $t7, 0x103
    ctx->r15 = S32(0X103 << 16);
    // 0x80078764: addiu       $t7, $t7, -0x6880
    ctx->r15 = ADD32(ctx->r15, -0X6880);
    // 0x80078768: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8007876C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80078770: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80078774: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078778: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007877C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078780: jal         0x800B8DD0
    // 0x80078784: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80078784: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x80078788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007878C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80078790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80078794: jr          $ra
    // 0x80078798: nop

    return;
    // 0x80078798: nop

;}
RECOMP_FUNC void Background_DrawGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040CE4: addiu       $sp, $sp, -0x1D8
    ctx->r29 = ADD32(ctx->r29, -0X1D8);
    // 0x80040CE8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80040CEC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80040CF0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80040CF4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80040CF8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80040CFC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80040D00: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80040D04: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80040D08: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80040D0C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80040D10: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80040D14: beq         $v0, $at, L_80040D48
    if (ctx->r2 == ctx->r1) {
        // 0x80040D18: addiu       $v1, $v1, -0x7D80
        ctx->r3 = ADD32(ctx->r3, -0X7D80);
            goto L_80040D48;
    }
    // 0x80040D18: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80040D1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80040D20: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80040D24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040D28: lwc1        $f6, 0x44($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X44);
    // 0x80040D2C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80040D30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80040D34: nop

    // 0x80040D38: bc1tl       L_80042D18
    if (c1cs) {
        // 0x80040D3C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80042D18;
    }
    goto skip_0;
    // 0x80040D3C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80040D40: lbu         $t7, 0x7A98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7A98);
    // 0x80040D44: beq         $t7, $zero, L_80042D14
    if (ctx->r15 == 0) {
        // 0x80040D48: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_80042D14;
    }
L_80040D48:
    // 0x80040D48: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80040D4C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80040D50: bne         $v0, $at, L_80040D78
    if (ctx->r2 != ctx->r1) {
        // 0x80040D54: addiu       $v1, $v1, -0x7D80
        ctx->r3 = ADD32(ctx->r3, -0X7D80);
            goto L_80040D78;
    }
    // 0x80040D54: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80040D58: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80040D5C: lhu         $t8, -0x63CC($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X63CC);
    // 0x80040D60: beq         $t8, $zero, L_80040D78
    if (ctx->r24 == 0) {
        // 0x80040D64: nop
    
            goto L_80040D78;
    }
    // 0x80040D64: nop

    // 0x80040D68: jal         0x80192264
    // 0x80040D6C: nop

    Bolse_DrawDynamicGround(rdram, ctx);
        goto after_0;
    // 0x80040D6C: nop

    after_0:
    // 0x80040D70: b           L_80042D18
    // 0x80040D74: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80042D18;
    // 0x80040D74: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80040D78:
    // 0x80040D78: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80040D7C: lw          $v0, -0x7B54($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7B54);
    // 0x80040D80: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80040D84: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80040D88: beq         $v0, $at, L_80040DA4
    if (ctx->r2 == ctx->r1) {
        // 0x80040D8C: mov.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
            goto L_80040DA4;
    }
    // 0x80040D8C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x80040D90: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80040D94: beq         $v0, $at, L_80040DA4
    if (ctx->r2 == ctx->r1) {
        // 0x80040D98: lui         $at, 0xC57A
        ctx->r1 = S32(0XC57A << 16);
            goto L_80040DA4;
    }
    // 0x80040D98: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x80040D9C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80040DA0: nop

L_80040DA4:
    // 0x80040DA4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80040DA8: bne         $v0, $at, L_80040DDC
    if (ctx->r2 != ctx->r1) {
        // 0x80040DAC: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_80040DDC;
    }
    // 0x80040DAC: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80040DB0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80040DB4: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x80040DB8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80040DBC: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x80040DC0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80040DC4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80040DC8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80040DCC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80040DD0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80040DD4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80040DD8: swc1        $f20, 0xAC($t7)
    MEM_W(0XAC, ctx->r15) = ctx->f20.u32l;
L_80040DDC:
    // 0x80040DDC: addiu       $s1, $s1, 0x7880
    ctx->r17 = ADD32(ctx->r17, 0X7880);
    // 0x80040DE0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80040DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80040DE8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80040DEC: bne         $t8, $at, L_80040FF8
    if (ctx->r24 != ctx->r1) {
        // 0x80040DF0: nop
    
            goto L_80040FF8;
    }
    // 0x80040DF0: nop

    // 0x80040DF4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80040DF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80040DFC: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80040E00: lw          $t9, 0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A0);
    // 0x80040E04: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80040E08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040E0C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80040E10: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80040E14: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80040E18: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80040E1C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80040E20: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80040E24: swc1        $f20, 0xAC($t7)
    MEM_W(0XAC, ctx->r15) = ctx->f20.u32l;
    // 0x80040E28: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80040E2C: lw          $t9, 0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A0);
    // 0x80040E30: lwc1        $f8, 0x5508($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5508);
    // 0x80040E34: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80040E38: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80040E3C: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x80040E40: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80040E44: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x80040E48: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80040E4C: swc1        $f0, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->f0.u32l;
    // 0x80040E50: swc1        $f0, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->f0.u32l;
    // 0x80040E54: swc1        $f8, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->f8.u32l;
    // 0x80040E58: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x80040E5C: lwc1        $f10, 0x58($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X58);
    // 0x80040E60: swc1        $f20, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->f20.u32l;
    // 0x80040E64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80040E68: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80040E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80040E70: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80040E74: jal         0x80005E90
    // 0x80040E78: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80040E78: nop

    after_1:
    // 0x80040E7C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80040E80: addiu       $a1, $sp, 0x1B4
    ctx->r5 = ADD32(ctx->r29, 0X1B4);
    // 0x80040E84: jal         0x80006A20
    // 0x80040E88: addiu       $a2, $sp, 0x1A8
    ctx->r6 = ADD32(ctx->r29, 0X1A8);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80040E88: addiu       $a2, $sp, 0x1A8
    ctx->r6 = ADD32(ctx->r29, 0X1A8);
    after_2:
    // 0x80040E8C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040E90: addiu       $a0, $a0, 0x78A0
    ctx->r4 = ADD32(ctx->r4, 0X78A0);
    // 0x80040E94: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80040E98: addiu       $a1, $zero, 0x4E0
    ctx->r5 = ADD32(0, 0X4E0);
    // 0x80040E9C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80040EA0: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040EA4: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80040EA8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80040EAC: lwc1        $f8, 0x1A8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x80040EB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040EB4: lwc1        $f14, 0x550C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X550C);
    // 0x80040EB8: lwc1        $f4, 0x1B0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x80040EBC: lwc1        $f2, 0x1D4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x80040EC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040EC4: mflo        $t8
    ctx->r24 = lo;
    // 0x80040EC8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80040ECC: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80040ED0: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80040ED4: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80040ED8: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80040EDC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80040EE0: nop

    // 0x80040EE4: bc1f        L_80040EF4
    if (!c1cs) {
        // 0x80040EE8: nop
    
            goto L_80040EF4;
    }
    // 0x80040EE8: nop

    // 0x80040EEC: lwc1        $f6, 0x5510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5510);
    // 0x80040EF0: swc1        $f6, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f6.u32l;
L_80040EF4:
    // 0x80040EF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040EF8: lwc1        $f16, 0x5514($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5514);
    // 0x80040EFC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80040F00: nop

    // 0x80040F04: bc1f        L_80040F2C
    if (!c1cs) {
        // 0x80040F08: nop
    
            goto L_80040F2C;
    }
    // 0x80040F08: nop

    // 0x80040F0C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80040F10: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80040F14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040F18: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040F1C: lwc1        $f8, 0x5518($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5518);
    // 0x80040F20: mflo        $t9
    ctx->r25 = lo;
    // 0x80040F24: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x80040F28: swc1        $f8, 0xAC($t7)
    MEM_W(0XAC, ctx->r15) = ctx->f8.u32l;
L_80040F2C:
    // 0x80040F2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040F30: lwc1        $f18, 0x551C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X551C);
    // 0x80040F34: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80040F38: nop

    // 0x80040F3C: bc1f        L_80040F64
    if (!c1cs) {
        // 0x80040F40: nop
    
            goto L_80040F64;
    }
    // 0x80040F40: nop

    // 0x80040F44: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80040F48: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80040F4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040F50: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040F54: lwc1        $f10, 0x5520($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5520);
    // 0x80040F58: mflo        $t5
    ctx->r13 = lo;
    // 0x80040F5C: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80040F60: swc1        $f10, 0xAC($t9)
    MEM_W(0XAC, ctx->r25) = ctx->f10.u32l;
L_80040F64:
    // 0x80040F64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040F68: lwc1        $f4, 0x5524($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5524);
    // 0x80040F6C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80040F70: nop

    // 0x80040F74: bc1fl       L_80040FA0
    if (!c1cs) {
        // 0x80040F78: c.lt.s      $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
            goto L_80040FA0;
    }
    goto skip_1;
    // 0x80040F78: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    skip_1:
    // 0x80040F7C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80040F80: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80040F84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040F88: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040F8C: lwc1        $f6, 0x5528($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5528);
    // 0x80040F90: mflo        $t8
    ctx->r24 = lo;
    // 0x80040F94: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x80040F98: swc1        $f6, 0xAC($t5)
    MEM_W(0XAC, ctx->r13) = ctx->f6.u32l;
    // 0x80040F9C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_80040FA0:
    // 0x80040FA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040FA4: bc1fl       L_80040FB4
    if (!c1cs) {
        // 0x80040FA8: c.lt.s      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
            goto L_80040FB4;
    }
    goto skip_2;
    // 0x80040FA8: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    skip_2:
    // 0x80040FAC: lwc1        $f2, 0x552C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X552C);
    // 0x80040FB0: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
L_80040FB4:
    // 0x80040FB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040FB8: bc1fl       L_80040FC8
    if (!c1cs) {
        // 0x80040FBC: c.lt.s      $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
            goto L_80040FC8;
    }
    goto skip_3;
    // 0x80040FBC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    skip_3:
    // 0x80040FC0: lwc1        $f2, 0x5530($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5530);
    // 0x80040FC4: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
L_80040FC8:
    // 0x80040FC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040FCC: bc1f        L_80040FD8
    if (!c1cs) {
        // 0x80040FD0: nop
    
            goto L_80040FD8;
    }
    // 0x80040FD0: nop

    // 0x80040FD4: lwc1        $f2, 0x5534($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5534);
L_80040FD8:
    // 0x80040FD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040FDC: lwc1        $f8, 0x5538($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5538);
    // 0x80040FE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040FE4: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80040FE8: nop

    // 0x80040FEC: bc1f        L_80040FF8
    if (!c1cs) {
        // 0x80040FF0: nop
    
            goto L_80040FF8;
    }
    // 0x80040FF0: nop

    // 0x80040FF4: lwc1        $f2, 0x553C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X553C);
L_80040FF8:
    // 0x80040FF8: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80040FFC: addiu       $s4, $s4, -0x4C40
    ctx->r20 = ADD32(ctx->r20, -0X4C40);
    // 0x80041000: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80041004: jal         0x80005708
    // 0x80041008: swc1        $f2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->f2.u32l;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x80041008: swc1        $f2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8004100C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80041010: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80041014: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041018: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x8004101C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041020: lwc1        $f4, -0x7B84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x80041024: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80041028: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004102C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80041030: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80041034: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80041038: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8004103C: lwc1        $f2, 0x1D4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x80041040: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80041044: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80041048: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8004104C: lw          $a1, 0xAC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XAC);
    // 0x80041050: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80041054: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041058: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004105C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80041060: jal         0x80005B00
    // 0x80041064: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x80041064: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_4:
    // 0x80041068: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8004106C: lw          $t6, 0x7C70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7C70);
    // 0x80041070: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80041074: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80041078: bne         $t6, $at, L_8004109C
    if (ctx->r14 != ctx->r1) {
        // 0x8004107C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004109C;
    }
    // 0x8004107C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80041080: lwc1        $f0, 0x5540($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5540);
    // 0x80041084: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80041088: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004108C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041090: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80041094: jal         0x80005C34
    // 0x80041098: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80041098: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_5:
L_8004109C:
    // 0x8004109C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800410A0: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800410A4: jal         0x80006EB8
    // 0x800410A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x800410A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800410AC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800410B0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800410B4: sltiu       $at, $v0, 0x15
    ctx->r1 = ctx->r2 < 0X15 ? 1 : 0;
    // 0x800410B8: beq         $at, $zero, L_80042D0C
    if (ctx->r1 == 0) {
        // 0x800410BC: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80042D0C;
    }
    // 0x800410BC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800410C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800410C4: addu        $at, $at, $t7
    gpr jr_addend_800410CC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800410C8: lw          $t7, 0x5544($at)
    ctx->r15 = ADD32(ctx->r1, 0X5544);
    // 0x800410CC: jr          $t7
    // 0x800410D0: nop

    switch (jr_addend_800410CC >> 2) {
        case 0: goto L_800410D4; break;
        case 1: goto L_80042D0C; break;
        case 2: goto L_80042D0C; break;
        case 3: goto L_80042D0C; break;
        case 4: goto L_80042D0C; break;
        case 5: goto L_80042D0C; break;
        case 6: goto L_80041760; break;
        case 7: goto L_80042B38; break;
        case 8: goto L_80042C24; break;
        case 9: goto L_80042D0C; break;
        case 10: goto L_80041C74; break;
        case 11: goto L_80041760; break;
        case 12: goto L_80042D0C; break;
        case 13: goto L_80041EB8; break;
        case 14: goto L_80042830; break;
        case 15: goto L_80042D0C; break;
        case 16: goto L_80042830; break;
        case 17: goto L_80042830; break;
        case 18: goto L_80042D0C; break;
        case 19: goto L_80042830; break;
        case 20: goto L_800429F0; break;
        default: switch_error(__func__, 0x800410CC, 0x800D5544);
    }
    // 0x800410D0: nop

L_800410D4:
    // 0x800410D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800410D8: lw          $t8, -0x7ED4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7ED4);
    // 0x800410DC: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800410E0: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x800410E4: beq         $t8, $zero, L_80041134
    if (ctx->r24 == 0) {
        // 0x800410E8: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_80041134;
    }
    // 0x800410E8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800410EC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800410F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800410F4: lw          $t6, -0x7C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C24);
    // 0x800410F8: lw          $t5, -0x7C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C28);
    // 0x800410FC: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80041100: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80041104: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80041108: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8004110C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80041110: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80041114: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80041118: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8004111C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80041120: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80041124: jal         0x800BA1D0
    // 0x80041128: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    RCP_SetupDL_29(rdram, ctx);
        goto after_7;
    // 0x80041128: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x8004112C: b           L_8004116C
    // 0x80041130: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
        goto L_8004116C;
    // 0x80041130: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_80041134:
    // 0x80041134: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80041138: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004113C: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x80041140: lw          $t9, -0x7C28($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C28);
    // 0x80041144: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80041148: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8004114C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80041150: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80041154: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80041158: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8004115C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80041160: jal         0x800B9618
    // 0x80041164: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    RCP_SetupDL_20(rdram, ctx);
        goto after_8;
    // 0x80041164: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x80041168: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_8004116C:
    // 0x8004116C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80041170: addiu       $t7, $zero, 0x845
    ctx->r15 = ADD32(0, 0X845);
    // 0x80041174: bne         $t8, $zero, L_800416D0
    if (ctx->r24 != 0) {
        // 0x80041178: lui         $s1, 0x800D
        ctx->r17 = S32(0X800D << 16);
            goto L_800416D0;
    }
    // 0x80041178: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8004117C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041180: lui         $s1, 0x602
    ctx->r17 = S32(0X602 << 16);
    // 0x80041184: addiu       $s1, $s1, -0x4940
    ctx->r17 = ADD32(ctx->r17, -0X4940);
    // 0x80041188: sll         $t9, $s1, 4
    ctx->r25 = S32(ctx->r17 << 4);
    // 0x8004118C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041190: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80041194: srl         $t7, $t9, 28
    ctx->r15 = S32(U32(ctx->r25) >> 28);
    // 0x80041198: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004119C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800411A0: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x800411A4: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x800411A8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800411AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800411B0: lw          $t5, 0x1FD0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1FD0);
    // 0x800411B4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800411B8: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800411BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800411C0: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x800411C4: addu        $t7, $t9, $at
    ctx->r15 = ADD32(ctx->r25, ctx->r1);
    // 0x800411C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800411CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800411D0: lwc1        $f8, 0x7CE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x800411D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800411D8: lwc1        $f10, 0x5598($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5598);
    // 0x800411DC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800411E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800411E4: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800411E8: jal         0x80004E20
    // 0x800411EC: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    Math_ModF(rdram, ctx);
        goto after_9;
    // 0x800411EC: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_9:
    // 0x800411F0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800411F4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800411F8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800411FC: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x80041200: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80041204: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80041208: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8004120C: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80041210: nop

    // 0x80041214: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x80041218: beq         $s0, $zero, L_80041264
    if (ctx->r16 == 0) {
        // 0x8004121C: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80041264;
    }
    // 0x8004121C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80041220: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041224: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80041228: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8004122C: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x80041230: nop

    // 0x80041234: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80041238: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x8004123C: nop

    // 0x80041240: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x80041244: bne         $s0, $zero, L_8004125C
    if (ctx->r16 != 0) {
        // 0x80041248: nop
    
            goto L_8004125C;
    }
    // 0x80041248: nop

    // 0x8004124C: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x80041250: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80041254: b           L_80041274
    // 0x80041258: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_80041274;
    // 0x80041258: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_8004125C:
    // 0x8004125C: b           L_80041274
    // 0x80041260: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_80041274;
    // 0x80041260: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80041264:
    // 0x80041264: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x80041268: nop

    // 0x8004126C: bltz        $s0, L_8004125C
    if (SIGNED(ctx->r16) < 0) {
        // 0x80041270: nop
    
            goto L_8004125C;
    }
    // 0x80041270: nop

L_80041274:
    // 0x80041274: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x80041278: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8004127C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80041280: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80041284: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80041288: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004128C: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80041290: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80041294: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x80041298: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8004129C: lwc1        $f6, 0xAC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XAC);
    // 0x800412A0: lwc1        $f8, 0x559C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X559C);
    // 0x800412A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800412A8: lwc1        $f4, 0x55A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55A0);
    // 0x800412AC: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800412B0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800412B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800412B8: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800412BC: jal         0x80004E20
    // 0x800412C0: nop

    Math_ModF(rdram, ctx);
        goto after_10;
    // 0x800412C0: nop

    after_10:
    // 0x800412C4: lui         $t0, 0xE800
    ctx->r8 = S32(0XE800 << 16);
    // 0x800412C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800412CC: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x800412D0: ori         $t5, $t5, 0x1000
    ctx->r13 = ctx->r13 | 0X1000;
    // 0x800412D4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800412D8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800412DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800412E0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800412E4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800412E8: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800412EC: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x800412F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800412F4: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800412F8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800412FC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80041300: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80041304: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041308: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004130C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80041310: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80041314: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80041318: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x8004131C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80041320: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80041324: nop

    // 0x80041328: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8004132C: beq         $t6, $zero, L_80041378
    if (ctx->r14 == 0) {
        // 0x80041330: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80041378;
    }
    // 0x80041330: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80041334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80041338: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004133C: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80041340: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80041344: nop

    // 0x80041348: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004134C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80041350: nop

    // 0x80041354: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80041358: bne         $t6, $zero, L_80041370
    if (ctx->r14 != 0) {
        // 0x8004135C: nop
    
            goto L_80041370;
    }
    // 0x8004135C: nop

    // 0x80041360: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80041364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80041368: b           L_80041388
    // 0x8004136C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80041388;
    // 0x8004136C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80041370:
    // 0x80041370: b           L_80041388
    // 0x80041374: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80041388;
    // 0x80041374: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80041378:
    // 0x80041378: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8004137C: nop

    // 0x80041380: bltz        $t6, L_80041370
    if (SIGNED(ctx->r14) < 0) {
        // 0x80041384: nop
    
            goto L_80041370;
    }
    // 0x80041384: nop

L_80041388:
    // 0x80041388: andi        $t5, $t6, 0xFFF
    ctx->r13 = ctx->r14 & 0XFFF;
    // 0x8004138C: sll         $t9, $t5, 12
    ctx->r25 = S32(ctx->r13 << 12);
    // 0x80041390: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80041394: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80041398: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8004139C: andi        $t8, $s0, 0xFFF
    ctx->r24 = ctx->r16 & 0XFFF;
    // 0x800413A0: lui         $t5, 0x7
    ctx->r13 = S32(0X7 << 16);
    // 0x800413A4: ori         $t5, $t5, 0xC07C
    ctx->r13 = ctx->r13 | 0XC07C;
    // 0x800413A8: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800413AC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800413B0: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x800413B4: lw          $v1, 0x1A88($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1A88);
    // 0x800413B8: beq         $v1, $zero, L_800413DC
    if (ctx->r3 == 0) {
        // 0x800413BC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800413DC;
    }
    // 0x800413BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800413C0: beq         $v1, $at, L_8004146C
    if (ctx->r3 == ctx->r1) {
        // 0x800413C4: lui         $t6, 0xFD10
        ctx->r14 = S32(0XFD10 << 16);
            goto L_8004146C;
    }
    // 0x800413C4: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x800413C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800413CC: beq         $v1, $at, L_80041504
    if (ctx->r3 == ctx->r1) {
        // 0x800413D0: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_80041504;
    }
    // 0x800413D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800413D4: b           L_800415EC
    // 0x800413D8: nop

        goto L_800415EC;
    // 0x800413D8: nop

L_800413DC:
    // 0x800413DC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800413E0: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x800413E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800413E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800413EC: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800413F0: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x800413F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800413F8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800413FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80041400: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80041404: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80041408: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8004140C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041410: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x80041414: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80041418: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8004141C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80041420: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80041424: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80041428: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004142C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80041430: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x80041434: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80041438: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8004143C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80041440: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80041444: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041448: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8004144C: ori         $t9, $t9, 0xF100
    ctx->r25 = ctx->r25 | 0XF100;
    // 0x80041450: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80041454: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80041458: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8004145C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80041460: addiu       $t7, $zero, 0x845
    ctx->r15 = ADD32(0, 0X845);
    // 0x80041464: b           L_800415EC
    // 0x80041468: sh          $t7, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r15;
        goto L_800415EC;
    // 0x80041468: sh          $t7, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r15;
L_8004146C:
    // 0x8004146C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041470: lui         $t5, 0x603
    ctx->r13 = S32(0X603 << 16);
    // 0x80041474: addiu       $t5, $t5, -0x7DA0
    ctx->r13 = ADD32(ctx->r13, -0X7DA0);
    // 0x80041478: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8004147C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80041480: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80041484: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80041488: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004148C: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80041490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80041494: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80041498: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8004149C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800414A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800414A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800414A8: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x800414AC: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x800414B0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800414B4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800414B8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800414BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800414C0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800414C4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800414C8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800414CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800414D0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800414D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800414D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800414DC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800414E0: lui         $t5, 0x73F
    ctx->r13 = S32(0X73F << 16);
    // 0x800414E4: ori         $t5, $t5, 0xF100
    ctx->r13 = ctx->r13 | 0XF100;
    // 0x800414E8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800414EC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800414F0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800414F4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800414F8: addiu       $t9, $zero, 0x845
    ctx->r25 = ADD32(0, 0X845);
    // 0x800414FC: b           L_800415EC
    // 0x80041500: sh          $t9, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r25;
        goto L_800415EC;
    // 0x80041500: sh          $t9, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r25;
L_80041504:
    // 0x80041504: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80041508: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004150C: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x80041510: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x80041514: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80041518: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8004151C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80041520: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80041524: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80041528: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8004152C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80041530: jal         0x800B9FC8
    // 0x80041534: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_45(rdram, ctx);
        goto after_11;
    // 0x80041534: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_11:
    // 0x80041538: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004153C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80041540: addiu       $t9, $zero, -0x80
    ctx->r25 = ADD32(0, -0X80);
    // 0x80041544: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80041548: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8004154C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80041550: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80041554: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041558: lui         $t6, 0x603
    ctx->r14 = S32(0X603 << 16);
    // 0x8004155C: addiu       $t6, $t6, -0x75A0
    ctx->r14 = ADD32(ctx->r14, -0X75A0);
    // 0x80041560: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80041564: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80041568: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8004156C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80041570: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80041574: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041578: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8004157C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80041580: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041584: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80041588: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004158C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80041590: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041594: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x80041598: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8004159C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800415A0: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800415A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800415A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800415AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800415B0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800415B4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800415B8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800415BC: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800415C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800415C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800415C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800415CC: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x800415D0: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x800415D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800415D8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800415DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800415E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800415E4: addiu       $t5, $zero, 0x190F
    ctx->r13 = ADD32(0, 0X190F);
    // 0x800415E8: sh          $t5, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r13;
L_800415EC:
    // 0x800415EC: jal         0x80005708
    // 0x800415F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_12;
    // 0x800415F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x800415F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800415F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800415FC: lui         $a3, 0xC53B
    ctx->r7 = S32(0XC53B << 16);
    // 0x80041600: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80041604: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80041608: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8004160C: jal         0x80005B00
    // 0x80041610: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_13;
    // 0x80041610: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_13:
    // 0x80041614: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041618: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004161C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80041620: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80041624: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041628: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004162C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041630: jal         0x80005C34
    // 0x80041634: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_14;
    // 0x80041634: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_14:
    // 0x80041638: jal         0x80006EB8
    // 0x8004163C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x8004163C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_15:
    // 0x80041640: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80041644: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041648: lui         $s0, 0x602
    ctx->r16 = S32(0X602 << 16);
    // 0x8004164C: addiu       $s0, $s0, -0x49C0
    ctx->r16 = ADD32(ctx->r16, -0X49C0);
    // 0x80041650: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80041654: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80041658: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8004165C: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80041660: jal         0x80005740
    // 0x80041664: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x80041664: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_16:
    // 0x80041668: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004166C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041670: lui         $a3, 0x453B
    ctx->r7 = S32(0X453B << 16);
    // 0x80041674: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041678: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004167C: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80041680: jal         0x80005B00
    // 0x80041684: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x80041684: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_17:
    // 0x80041688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004168C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041690: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041694: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80041698: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004169C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800416A0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800416A4: jal         0x80005C34
    // 0x800416A8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_18;
    // 0x800416A8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_18:
    // 0x800416AC: jal         0x80006EB8
    // 0x800416B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x800416B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_19:
    // 0x800416B4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800416B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800416BC: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800416C0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x800416C4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x800416C8: b           L_80042D0C
    // 0x800416CC: nop

        goto L_80042D0C;
    // 0x800416CC: nop

L_800416D0:
    // 0x800416D0: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
    // 0x800416D4: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x800416D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800416DC: addiu       $t8, $t8, -0x1560
    ctx->r24 = ADD32(ctx->r24, -0X1560);
    // 0x800416E0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800416E4: sh          $t7, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r15;
    // 0x800416E8: addiu       $s0, $s0, -0x618C
    ctx->r16 = ADD32(ctx->r16, -0X618C);
    // 0x800416EC: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800416F0: addiu       $s1, $s1, -0x619C
    ctx->r17 = ADD32(ctx->r17, -0X619C);
    // 0x800416F4: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
L_800416F8:
    // 0x800416F8: jal         0x80005708
    // 0x800416FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_20;
    // 0x800416FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_20:
    // 0x80041700: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041704: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041708: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004170C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041710: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80041714: jal         0x80005B00
    // 0x80041718: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_21;
    // 0x80041718: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_21:
    // 0x8004171C: jal         0x80006EB8
    // 0x80041720: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_22;
    // 0x80041720: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_22:
    // 0x80041724: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041728: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8004172C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80041730: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80041734: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80041738: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8004173C: jal         0x80005740
    // 0x80041740: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_23;
    // 0x80041740: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_23:
    // 0x80041744: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80041748: addiu       $t7, $t7, -0x617C
    ctx->r15 = ADD32(ctx->r15, -0X617C);
    // 0x8004174C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80041750: bne         $s0, $t7, L_800416F8
    if (ctx->r16 != ctx->r15) {
        // 0x80041754: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800416F8;
    }
    // 0x80041754: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80041758: b           L_80042D0C
    // 0x8004175C: nop

        goto L_80042D0C;
    // 0x8004175C: nop

L_80041760:
    // 0x80041760: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80041764: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80041768: lw          $t6, -0x7C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C24);
    // 0x8004176C: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x80041770: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80041774: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80041778: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004177C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80041780: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80041784: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80041788: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8004178C: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80041790: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80041794: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80041798: jal         0x800BA1D0
    // 0x8004179C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_29(rdram, ctx);
        goto after_24;
    // 0x8004179C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_24:
    // 0x800417A0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800417A4: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x800417A8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800417AC: beq         $v1, $at, L_800417C4
    if (ctx->r3 == ctx->r1) {
        // 0x800417B0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800417C4;
    }
    // 0x800417B0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800417B4: beq         $v1, $at, L_800418AC
    if (ctx->r3 == ctx->r1) {
        // 0x800417B8: lui         $t2, 0x603
        ctx->r10 = S32(0X603 << 16);
            goto L_800418AC;
    }
    // 0x800417B8: lui         $t2, 0x603
    ctx->r10 = S32(0X603 << 16);
    // 0x800417BC: b           L_80041988
    // 0x800417C0: lw          $s1, 0x1C0($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C0);
        goto L_80041988;
    // 0x800417C0: lw          $s1, 0x1C0($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C0);
L_800417C4:
    // 0x800417C4: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800417C8: addiu       $t2, $t2, 0x6750
    ctx->r10 = ADD32(ctx->r10, 0X6750);
    // 0x800417CC: lui         $s1, 0x600
    ctx->r17 = S32(0X600 << 16);
    // 0x800417D0: sw          $t2, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r10;
    // 0x800417D4: addiu       $s1, $s1, 0x66D0
    ctx->r17 = ADD32(ctx->r17, 0X66D0);
    // 0x800417D8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800417DC: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x800417E0: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x800417E4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800417E8: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800417EC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800417F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800417F4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800417F8: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x800417FC: ori         $t6, $t6, 0x4050
    ctx->r14 = ctx->r14 | 0X4050;
    // 0x80041800: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80041804: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80041808: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8004180C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80041810: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041814: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80041818: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8004181C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041820: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80041824: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80041828: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004182C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041830: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x80041834: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x80041838: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8004183C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80041840: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80041844: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80041848: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004184C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80041850: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x80041854: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041858: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8004185C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80041860: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80041864: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041868: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8004186C: ori         $t6, $t6, 0x4050
    ctx->r14 = ctx->r14 | 0X4050;
    // 0x80041870: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80041874: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80041878: ori         $t8, $t8, 0x1000
    ctx->r24 = ctx->r24 | 0X1000;
    // 0x8004187C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80041880: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80041884: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041888: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x8004188C: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x80041890: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041894: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80041898: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8004189C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800418A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800418A4: b           L_8004198C
    // 0x800418A8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_8004198C;
    // 0x800418A8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_800418AC:
    // 0x800418AC: addiu       $t2, $t2, -0x2348
    ctx->r10 = ADD32(ctx->r10, -0X2348);
    // 0x800418B0: lui         $s1, 0x603
    ctx->r17 = S32(0X603 << 16);
    // 0x800418B4: sw          $t2, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r10;
    // 0x800418B8: addiu       $s1, $s1, 0x6D0
    ctx->r17 = ADD32(ctx->r17, 0X6D0);
    // 0x800418BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800418C0: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x800418C4: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x800418C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800418CC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800418D0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800418D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800418D8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800418DC: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x800418E0: ori         $t7, $t7, 0x4050
    ctx->r15 = ctx->r15 | 0X4050;
    // 0x800418E4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800418E8: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800418EC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800418F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800418F4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800418F8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800418FC: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80041900: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80041904: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80041908: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004190C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80041910: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041914: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x80041918: ori         $t7, $t7, 0xF100
    ctx->r15 = ctx->r15 | 0XF100;
    // 0x8004191C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041920: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80041924: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80041928: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004192C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041930: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80041934: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x80041938: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8004193C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80041940: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80041944: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80041948: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004194C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80041950: ori         $t7, $t7, 0x4050
    ctx->r15 = ctx->r15 | 0X4050;
    // 0x80041954: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041958: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8004195C: ori         $t9, $t9, 0x1000
    ctx->r25 = ctx->r25 | 0X1000;
    // 0x80041960: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80041964: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80041968: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004196C: lui         $t5, 0x7
    ctx->r13 = S32(0X7 << 16);
    // 0x80041970: ori         $t5, $t5, 0xC07C
    ctx->r13 = ctx->r13 | 0XC07C;
    // 0x80041974: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80041978: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8004197C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80041980: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80041984: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80041988:
    // 0x80041988: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8004198C:
    // 0x8004198C: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80041990: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80041994: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80041998: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8004199C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800419A0: lw          $t8, 0x1C4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C4);
    // 0x800419A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800419A8: lwc1        $f6, 0x7CE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x800419AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800419B0: lwc1        $f10, 0x55A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X55A4);
    // 0x800419B4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800419B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800419BC: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800419C0: jal         0x80004E20
    // 0x800419C4: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    Math_ModF(rdram, ctx);
        goto after_25;
    // 0x800419C4: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_25:
    // 0x800419C8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800419CC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800419D0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800419D4: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800419D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800419DC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800419E0: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800419E4: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800419E8: nop

    // 0x800419EC: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800419F0: beq         $s0, $zero, L_80041A3C
    if (ctx->r16 == 0) {
        // 0x800419F4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80041A3C;
    }
    // 0x800419F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800419F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800419FC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80041A00: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80041A04: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x80041A08: nop

    // 0x80041A0C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80041A10: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80041A14: nop

    // 0x80041A18: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x80041A1C: bne         $s0, $zero, L_80041A34
    if (ctx->r16 != 0) {
        // 0x80041A20: nop
    
            goto L_80041A34;
    }
    // 0x80041A20: nop

    // 0x80041A24: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x80041A28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80041A2C: b           L_80041A4C
    // 0x80041A30: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_80041A4C;
    // 0x80041A30: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_80041A34:
    // 0x80041A34: b           L_80041A4C
    // 0x80041A38: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_80041A4C;
    // 0x80041A38: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80041A3C:
    // 0x80041A3C: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x80041A40: nop

    // 0x80041A44: bltz        $s0, L_80041A34
    if (SIGNED(ctx->r16) < 0) {
        // 0x80041A48: nop
    
            goto L_80041A34;
    }
    // 0x80041A48: nop

L_80041A4C:
    // 0x80041A4C: lw          $t9, 0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A0);
    // 0x80041A50: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x80041A54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80041A58: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80041A5C: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80041A60: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80041A64: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x80041A68: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80041A6C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80041A70: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80041A74: lwc1        $f8, 0xAC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XAC);
    // 0x80041A78: lwc1        $f6, 0x55A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55A8);
    // 0x80041A7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80041A80: lwc1        $f4, 0x55AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55AC);
    // 0x80041A84: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80041A88: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80041A8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80041A90: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80041A94: jal         0x80004E20
    // 0x80041A98: nop

    Math_ModF(rdram, ctx);
        goto after_26;
    // 0x80041A98: nop

    after_26:
    // 0x80041A9C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041AA0: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x80041AA4: lui         $t7, 0xF510
    ctx->r15 = S32(0XF510 << 16);
    // 0x80041AA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80041AAC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80041AB0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80041AB4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80041AB8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041ABC: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80041AC0: ori         $t8, $t8, 0x4050
    ctx->r24 = ctx->r24 | 0X4050;
    // 0x80041AC4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80041AC8: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80041ACC: ori         $t7, $t7, 0x1000
    ctx->r15 = ctx->r15 | 0X1000;
    // 0x80041AD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80041AD4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80041AD8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80041ADC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041AE0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80041AE4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80041AE8: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80041AEC: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x80041AF0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80041AF4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80041AF8: nop

    // 0x80041AFC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80041B00: beq         $t5, $zero, L_80041B4C
    if (ctx->r13 == 0) {
        // 0x80041B04: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80041B4C;
    }
    // 0x80041B04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80041B08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041B0C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041B10: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80041B14: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80041B18: nop

    // 0x80041B1C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80041B20: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80041B24: nop

    // 0x80041B28: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80041B2C: bne         $t5, $zero, L_80041B44
    if (ctx->r13 != 0) {
        // 0x80041B30: nop
    
            goto L_80041B44;
    }
    // 0x80041B30: nop

    // 0x80041B34: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80041B38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80041B3C: b           L_80041B5C
    // 0x80041B40: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80041B5C;
    // 0x80041B40: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80041B44:
    // 0x80041B44: b           L_80041B5C
    // 0x80041B48: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80041B5C;
    // 0x80041B48: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80041B4C:
    // 0x80041B4C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80041B50: nop

    // 0x80041B54: bltz        $t5, L_80041B44
    if (SIGNED(ctx->r13) < 0) {
        // 0x80041B58: nop
    
            goto L_80041B44;
    }
    // 0x80041B58: nop

L_80041B5C:
    // 0x80041B5C: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80041B60: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80041B64: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80041B68: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80041B6C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80041B70: andi        $t9, $s0, 0xFFF
    ctx->r25 = ctx->r16 & 0XFFF;
    // 0x80041B74: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x80041B78: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x80041B7C: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80041B80: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80041B84: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80041B88: jal         0x80005708
    // 0x80041B8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_27;
    // 0x80041B8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_27:
    // 0x80041B90: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80041B94: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041B98: lui         $a3, 0xC53B
    ctx->r7 = S32(0XC53B << 16);
    // 0x80041B9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80041BA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80041BA4: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80041BA8: jal         0x80005B00
    // 0x80041BAC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_28;
    // 0x80041BAC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_28:
    // 0x80041BB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041BB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041BB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041BBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80041BC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041BC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80041BC8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041BCC: jal         0x80005C34
    // 0x80041BD0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_29;
    // 0x80041BD0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_29:
    // 0x80041BD4: jal         0x80006EB8
    // 0x80041BD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_30;
    // 0x80041BD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x80041BDC: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80041BE0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041BE4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80041BE8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80041BEC: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80041BF0: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80041BF4: jal         0x80005740
    // 0x80041BF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_31;
    // 0x80041BF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
    // 0x80041BFC: jal         0x80005708
    // 0x80041C00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_32;
    // 0x80041C00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_32:
    // 0x80041C04: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80041C08: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041C0C: lui         $a3, 0x453B
    ctx->r7 = S32(0X453B << 16);
    // 0x80041C10: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041C14: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80041C18: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80041C1C: jal         0x80005B00
    // 0x80041C20: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_33;
    // 0x80041C20: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_33:
    // 0x80041C24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041C28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041C2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80041C30: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80041C34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041C38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80041C3C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041C40: jal         0x80005C34
    // 0x80041C44: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_34;
    // 0x80041C44: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_34:
    // 0x80041C48: jal         0x80006EB8
    // 0x80041C4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_35;
    // 0x80041C4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_35:
    // 0x80041C50: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041C54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80041C58: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80041C5C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80041C60: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80041C64: jal         0x80005740
    // 0x80041C68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_36;
    // 0x80041C68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_36:
    // 0x80041C6C: b           L_80042D0C
    // 0x80041C70: nop

        goto L_80042D0C;
    // 0x80041C70: nop

L_80041C74:
    // 0x80041C74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80041C78: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80041C7C: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x80041C80: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x80041C84: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80041C88: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80041C8C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80041C90: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80041C94: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80041C98: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80041C9C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80041CA0: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80041CA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80041CA8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80041CAC: jal         0x800BA1D0
    // 0x80041CB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_29(rdram, ctx);
        goto after_37;
    // 0x80041CB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_37:
    // 0x80041CB4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80041CB8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80041CBC: addiu       $s1, $s1, -0x619C
    ctx->r17 = ADD32(ctx->r17, -0X619C);
    // 0x80041CC0: bne         $t5, $zero, L_80041E18
    if (ctx->r13 != 0) {
        // 0x80041CC4: lui         $s0, 0x800D
        ctx->r16 = S32(0X800D << 16);
            goto L_80041E18;
    }
    // 0x80041CC4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80041CC8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041CCC: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x80041CD0: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x80041CD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80041CD8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80041CDC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80041CE0: nop

    // 0x80041CE4: bc1f        L_80041CF4
    if (!c1cs) {
        // 0x80041CE8: nop
    
            goto L_80041CF4;
    }
    // 0x80041CE8: nop

    // 0x80041CEC: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80041CF0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80041CF4:
    // 0x80041CF4: jal         0x80005708
    // 0x80041CF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_38;
    // 0x80041CF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_38:
    // 0x80041CFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80041D00: lwc1        $f10, 0x55B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X55B0);
    // 0x80041D04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80041D08: lwc1        $f4, 0x7CE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x80041D0C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80041D10: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041D14: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80041D18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80041D1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80041D20: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041D24: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80041D28: jal         0x80005B00
    // 0x80041D2C: nop

    Matrix_Translate(rdram, ctx);
        goto after_39;
    // 0x80041D2C: nop

    after_39:
    // 0x80041D30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041D34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041D38: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80041D3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80041D40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041D44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80041D48: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041D4C: jal         0x80005C34
    // 0x80041D50: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_40;
    // 0x80041D50: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_40:
    // 0x80041D54: jal         0x80006EB8
    // 0x80041D58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_41;
    // 0x80041D58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_41:
    // 0x80041D5C: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80041D60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041D64: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80041D68: addiu       $a1, $a1, 0x5880
    ctx->r5 = ADD32(ctx->r5, 0X5880);
    // 0x80041D6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80041D70: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80041D74: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80041D78: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80041D7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80041D80: jal         0x80005740
    // 0x80041D84: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_42;
    // 0x80041D84: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_42:
    // 0x80041D88: jal         0x80005708
    // 0x80041D8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_43;
    // 0x80041D8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_43:
    // 0x80041D90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80041D94: lwc1        $f8, 0x55B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X55B4);
    // 0x80041D98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80041D9C: lwc1        $f10, 0x7CE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x80041DA0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80041DA4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041DA8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80041DAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80041DB0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80041DB4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041DB8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80041DBC: jal         0x80005B00
    // 0x80041DC0: nop

    Matrix_Translate(rdram, ctx);
        goto after_44;
    // 0x80041DC0: nop

    after_44:
    // 0x80041DC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041DC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041DCC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041DD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80041DD4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041DD8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80041DDC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041DE0: jal         0x80005C34
    // 0x80041DE4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_45;
    // 0x80041DE4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_45:
    // 0x80041DE8: jal         0x80006EB8
    // 0x80041DEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_46;
    // 0x80041DEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_46:
    // 0x80041DF0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041DF4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80041DF8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80041DFC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80041E00: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80041E04: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80041E08: jal         0x80005740
    // 0x80041E0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_47;
    // 0x80041E0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_47:
    // 0x80041E10: b           L_80042D0C
    // 0x80041E14: nop

        goto L_80042D0C;
    // 0x80041E14: nop

L_80041E18:
    // 0x80041E18: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80041E1C: addiu       $t6, $t6, 0x5880
    ctx->r14 = ADD32(ctx->r14, 0X5880);
    // 0x80041E20: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80041E24: addiu       $s0, $s0, -0x618C
    ctx->r16 = ADD32(ctx->r16, -0X618C);
    // 0x80041E28: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
L_80041E2C:
    // 0x80041E2C: jal         0x80005708
    // 0x80041E30: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_48;
    // 0x80041E30: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_48:
    // 0x80041E34: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041E38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80041E3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80041E40: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041E44: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80041E48: jal         0x80005B00
    // 0x80041E4C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_49;
    // 0x80041E4C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_49:
    // 0x80041E50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041E54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041E58: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041E5C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80041E60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80041E64: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80041E68: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80041E6C: jal         0x80005C34
    // 0x80041E70: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_50;
    // 0x80041E70: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_50:
    // 0x80041E74: jal         0x80006EB8
    // 0x80041E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_51;
    // 0x80041E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_51:
    // 0x80041E7C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041E80: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80041E84: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80041E88: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80041E8C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80041E90: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80041E94: jal         0x80005740
    // 0x80041E98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_52;
    // 0x80041E98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_52:
    // 0x80041E9C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80041EA0: addiu       $t6, $t6, -0x617C
    ctx->r14 = ADD32(ctx->r14, -0X617C);
    // 0x80041EA4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80041EA8: bne         $s0, $t6, L_80041E2C
    if (ctx->r16 != ctx->r14) {
        // 0x80041EAC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80041E2C;
    }
    // 0x80041EAC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80041EB0: b           L_80042D0C
    // 0x80041EB4: nop

        goto L_80042D0C;
    // 0x80041EB4: nop

L_80041EB8:
    // 0x80041EB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80041EBC: jal         0x800B8DD0
    // 0x80041EC0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    RCP_SetupDL(rdram, ctx);
        goto after_53;
    // 0x80041EC0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_53:
    // 0x80041EC4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041EC8: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80041ECC: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x80041ED0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80041ED4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80041ED8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80041EDC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80041EE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80041EE4: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x80041EE8: lw          $v1, -0x7C28($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7C28);
    // 0x80041EEC: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80041EF0: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x80041EF4: subu        $a1, $t7, $v1
    ctx->r5 = SUB32(ctx->r15, ctx->r3);
    // 0x80041EF8: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80041EFC: negu        $t7, $v1
    ctx->r15 = SUB32(0, ctx->r3);
    // 0x80041F00: mflo        $t9
    ctx->r25 = lo;
    // 0x80041F04: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x80041F08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80041F0C: bne         $a1, $zero, L_80041F18
    if (ctx->r5 != 0) {
        // 0x80041F10: nop
    
            goto L_80041F18;
    }
    // 0x80041F10: nop

    // 0x80041F14: break       7
    do_break(2147753748);
L_80041F18:
    // 0x80041F18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80041F1C: bne         $a1, $at, L_80041F30
    if (ctx->r5 != ctx->r1) {
        // 0x80041F20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80041F30;
    }
    // 0x80041F20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80041F24: bne         $t8, $at, L_80041F30
    if (ctx->r24 != ctx->r1) {
        // 0x80041F28: nop
    
            goto L_80041F30;
    }
    // 0x80041F28: nop

    // 0x80041F2C: break       6
    do_break(2147753772);
L_80041F30:
    // 0x80041F30: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80041F34: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x80041F38: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80041F3C: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x80041F40: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x80041F44: mflo        $t9
    ctx->r25 = lo;
    // 0x80041F48: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80041F4C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80041F50: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80041F54: bne         $a1, $zero, L_80041F60
    if (ctx->r5 != 0) {
        // 0x80041F58: nop
    
            goto L_80041F60;
    }
    // 0x80041F58: nop

    // 0x80041F5C: break       7
    do_break(2147753820);
L_80041F60:
    // 0x80041F60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80041F64: bne         $a1, $at, L_80041F78
    if (ctx->r5 != ctx->r1) {
        // 0x80041F68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80041F78;
    }
    // 0x80041F68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80041F6C: bne         $t6, $at, L_80041F78
    if (ctx->r14 != ctx->r1) {
        // 0x80041F70: nop
    
            goto L_80041F78;
    }
    // 0x80041F70: nop

    // 0x80041F74: break       6
    do_break(2147753844);
L_80041F78:
    // 0x80041F78: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80041F7C: lbu         $a2, -0x69C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X69C);
    // 0x80041F80: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041F84: bnel        $a2, $zero, L_8004235C
    if (ctx->r6 != 0) {
        // 0x80041F88: lui         $s1, 0x8000
        ctx->r17 = S32(0X8000 << 16);
            goto L_8004235C;
    }
    goto skip_4;
    // 0x80041F88: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    skip_4:
    // 0x80041F8C: lbu         $v0, 0x7AC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7AC8);
    // 0x80041F90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80041F94: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x80041F98: beq         $v0, $zero, L_80041FA8
    if (ctx->r2 == 0) {
        // 0x80041F9C: lui         $s1, 0x8000
        ctx->r17 = S32(0X8000 << 16);
            goto L_80041FA8;
    }
    // 0x80041F9C: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x80041FA0: bnel        $v0, $at, L_8004235C
    if (ctx->r2 != ctx->r1) {
        // 0x80041FA4: lui         $s1, 0x8000
        ctx->r17 = S32(0X8000 << 16);
            goto L_8004235C;
    }
    goto skip_5;
    // 0x80041FA4: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    skip_5:
L_80041FA8:
    // 0x80041FA8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041FAC: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80041FB0: addiu       $a0, $a0, -0x5498
    ctx->r4 = ADD32(ctx->r4, -0X5498);
    // 0x80041FB4: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x80041FB8: srl         $t5, $t9, 28
    ctx->r13 = S32(U32(ctx->r25) >> 28);
    // 0x80041FBC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80041FC0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80041FC4: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80041FC8: addiu       $t8, $t8, 0x1FD0
    ctx->r24 = ADD32(ctx->r24, 0X1FD0);
    // 0x80041FCC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80041FD0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80041FD4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80041FD8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80041FDC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80041FE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80041FE4: and         $a2, $a0, $at
    ctx->r6 = ctx->r4 & ctx->r1;
    // 0x80041FE8: addu        $t9, $t6, $a2
    ctx->r25 = ADD32(ctx->r14, ctx->r6);
    // 0x80041FEC: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x80041FF0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80041FF4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80041FF8: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80041FFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80042000: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80042004: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80042008: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004200C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80042010: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042014: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x80042018: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x8004201C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80042020: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80042024: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80042028: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004202C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042030: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80042034: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80042038: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8004203C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80042040: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80042044: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80042048: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004204C: lui         $t5, 0x73F
    ctx->r13 = S32(0X73F << 16);
    // 0x80042050: ori         $t5, $t5, 0xF100
    ctx->r13 = ctx->r13 | 0XF100;
    // 0x80042054: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80042058: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8004205C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80042060: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80042064: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042068: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8004206C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80042070: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80042074: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80042078: addu        $t6, $t8, $a2
    ctx->r14 = ADD32(ctx->r24, ctx->r6);
    // 0x8004207C: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x80042080: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80042084: lwc1        $f6, 0x7CE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x80042088: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004208C: lwc1        $f8, 0x55B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X55B8);
    // 0x80042090: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80042094: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80042098: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004209C: jal         0x80004E20
    // 0x800420A0: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    Math_ModF(rdram, ctx);
        goto after_54;
    // 0x800420A0: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_54:
    // 0x800420A4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800420A8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800420AC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800420B0: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800420B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800420B8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800420BC: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800420C0: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800420C4: nop

    // 0x800420C8: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800420CC: beq         $s0, $zero, L_80042118
    if (ctx->r16 == 0) {
        // 0x800420D0: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80042118;
    }
    // 0x800420D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800420D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800420D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800420DC: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800420E0: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800420E4: nop

    // 0x800420E8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800420EC: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800420F0: nop

    // 0x800420F4: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800420F8: bne         $s0, $zero, L_80042110
    if (ctx->r16 != 0) {
        // 0x800420FC: nop
    
            goto L_80042110;
    }
    // 0x800420FC: nop

    // 0x80042100: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x80042104: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80042108: b           L_80042128
    // 0x8004210C: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_80042128;
    // 0x8004210C: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_80042110:
    // 0x80042110: b           L_80042128
    // 0x80042114: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_80042128;
    // 0x80042114: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80042118:
    // 0x80042118: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x8004211C: nop

    // 0x80042120: bltz        $s0, L_80042110
    if (SIGNED(ctx->r16) < 0) {
        // 0x80042124: nop
    
            goto L_80042110;
    }
    // 0x80042124: nop

L_80042128:
    // 0x80042128: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x8004212C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80042130: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80042134: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80042138: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8004213C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80042140: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80042144: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80042148: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8004214C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80042150: lwc1        $f4, 0xAC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XAC);
    // 0x80042154: lwc1        $f6, 0x55BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55BC);
    // 0x80042158: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004215C: lwc1        $f10, 0x55C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X55C0);
    // 0x80042160: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80042164: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80042168: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004216C: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80042170: jal         0x80004E20
    // 0x80042174: nop

    Math_ModF(rdram, ctx);
        goto after_55;
    // 0x80042174: nop

    after_55:
    // 0x80042178: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004217C: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80042180: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x80042184: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80042188: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8004218C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80042190: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80042194: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042198: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8004219C: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x800421A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800421A4: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800421A8: ori         $t6, $t6, 0x1000
    ctx->r14 = ctx->r14 | 0X1000;
    // 0x800421AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800421B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800421B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800421B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800421BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800421C0: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800421C4: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800421C8: addiu       $t5, $a2, 0x8
    ctx->r13 = ADD32(ctx->r6, 0X8);
    // 0x800421CC: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800421D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800421D4: nop

    // 0x800421D8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800421DC: beq         $t7, $zero, L_80042228
    if (ctx->r15 == 0) {
        // 0x800421E0: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80042228;
    }
    // 0x800421E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800421E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800421E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800421EC: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800421F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800421F4: nop

    // 0x800421F8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800421FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80042200: nop

    // 0x80042204: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80042208: bne         $t7, $zero, L_80042220
    if (ctx->r15 != 0) {
        // 0x8004220C: nop
    
            goto L_80042220;
    }
    // 0x8004220C: nop

    // 0x80042210: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80042214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80042218: b           L_80042238
    // 0x8004221C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80042238;
    // 0x8004221C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80042220:
    // 0x80042220: b           L_80042238
    // 0x80042224: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80042238;
    // 0x80042224: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80042228:
    // 0x80042228: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8004222C: nop

    // 0x80042230: bltz        $t7, L_80042220
    if (SIGNED(ctx->r15) < 0) {
        // 0x80042234: nop
    
            goto L_80042220;
    }
    // 0x80042234: nop

L_80042238:
    // 0x80042238: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8004223C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80042240: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80042244: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80042248: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x8004224C: andi        $t8, $s0, 0xFFF
    ctx->r24 = ctx->r16 & 0XFFF;
    // 0x80042250: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x80042254: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x80042258: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x8004225C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80042260: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80042264: jal         0x80005708
    // 0x80042268: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_56;
    // 0x80042268: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_56:
    // 0x8004226C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80042270: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80042274: lui         $a3, 0xC53B
    ctx->r7 = S32(0XC53B << 16);
    // 0x80042278: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004227C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80042280: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80042284: jal         0x80005B00
    // 0x80042288: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_57;
    // 0x80042288: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_57:
    // 0x8004228C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042290: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042294: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80042298: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004229C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800422A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800422A4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800422A8: jal         0x80005C34
    // 0x800422AC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_58;
    // 0x800422AC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_58:
    // 0x800422B0: jal         0x80006EB8
    // 0x800422B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_59;
    // 0x800422B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_59:
    // 0x800422B8: lui         $s0, 0x601
    ctx->r16 = S32(0X601 << 16);
    // 0x800422BC: addiu       $s0, $s0, -0x54F0
    ctx->r16 = ADD32(ctx->r16, -0X54F0);
    // 0x800422C0: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x800422C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800422C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800422CC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800422D0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x800422D4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x800422D8: jal         0x80005740
    // 0x800422DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_60;
    // 0x800422DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_60:
    // 0x800422E0: jal         0x80005708
    // 0x800422E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_61;
    // 0x800422E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_61:
    // 0x800422E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800422EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800422F0: lui         $a3, 0x453B
    ctx->r7 = S32(0X453B << 16);
    // 0x800422F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800422F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800422FC: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80042300: jal         0x80005B00
    // 0x80042304: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_62;
    // 0x80042304: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_62:
    // 0x80042308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004230C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80042314: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80042318: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004231C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80042320: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80042324: jal         0x80005C34
    // 0x80042328: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_63;
    // 0x80042328: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_63:
    // 0x8004232C: jal         0x80006EB8
    // 0x80042330: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_64;
    // 0x80042330: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_64:
    // 0x80042334: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042338: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8004233C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80042340: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80042344: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80042348: jal         0x80005740
    // 0x8004234C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_65;
    // 0x8004234C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_65:
    // 0x80042350: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80042354: lbu         $a2, -0x69C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X69C);
    // 0x80042358: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
L_8004235C:
    // 0x8004235C: bne         $a2, $zero, L_80042374
    if (ctx->r6 != 0) {
        // 0x80042360: lui         $s3, 0x600
        ctx->r19 = S32(0X600 << 16);
            goto L_80042374;
    }
    // 0x80042360: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80042364: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80042368: lbu         $t5, 0x7AC8($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7AC8);
    // 0x8004236C: bne         $t5, $zero, L_80042D0C
    if (ctx->r13 != 0) {
        // 0x80042370: nop
    
            goto L_80042D0C;
    }
    // 0x80042370: nop

L_80042374:
    // 0x80042374: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042378: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8004237C: addiu       $a0, $a0, -0x5340
    ctx->r4 = ADD32(ctx->r4, -0X5340);
    // 0x80042380: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80042384: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80042388: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8004238C: srl         $t9, $t6, 28
    ctx->r25 = S32(U32(ctx->r14) >> 28);
    // 0x80042390: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80042394: addiu       $t8, $t8, 0x1FD0
    ctx->r24 = ADD32(ctx->r24, 0X1FD0);
    // 0x80042398: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8004239C: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x800423A0: addu        $a1, $t5, $t8
    ctx->r5 = ADD32(ctx->r13, ctx->r24);
    // 0x800423A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800423A8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800423AC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800423B0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800423B4: and         $a2, $a0, $at
    ctx->r6 = ctx->r4 & ctx->r1;
    // 0x800423B8: addu        $t6, $t7, $a2
    ctx->r14 = ADD32(ctx->r15, ctx->r6);
    // 0x800423BC: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x800423C0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800423C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800423C8: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x800423CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800423D0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800423D4: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800423D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800423DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800423E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800423E4: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x800423E8: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x800423EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800423F0: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800423F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800423F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800423FC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042400: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80042404: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80042408: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8004240C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80042410: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80042414: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80042418: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004241C: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x80042420: ori         $t9, $t9, 0xF100
    ctx->r25 = ctx->r25 | 0XF100;
    // 0x80042424: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80042428: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8004242C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80042430: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80042434: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042438: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8004243C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80042440: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80042444: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80042448: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004244C: addu        $t6, $t7, $a2
    ctx->r14 = ADD32(ctx->r15, ctx->r6);
    // 0x80042450: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x80042454: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80042458: lwc1        $f4, 0x7CE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x8004245C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80042460: lwc1        $f8, 0x55C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X55C4);
    // 0x80042464: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80042468: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004246C: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80042470: jal         0x80004E20
    // 0x80042474: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    Math_ModF(rdram, ctx);
        goto after_66;
    // 0x80042474: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_66:
    // 0x80042478: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8004247C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80042480: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80042484: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x80042488: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004248C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80042490: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80042494: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80042498: nop

    // 0x8004249C: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800424A0: beq         $s0, $zero, L_800424EC
    if (ctx->r16 == 0) {
        // 0x800424A4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_800424EC;
    }
    // 0x800424A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800424A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800424AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800424B0: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800424B4: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800424B8: nop

    // 0x800424BC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800424C0: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800424C4: nop

    // 0x800424C8: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800424CC: bne         $s0, $zero, L_800424E4
    if (ctx->r16 != 0) {
        // 0x800424D0: nop
    
            goto L_800424E4;
    }
    // 0x800424D0: nop

    // 0x800424D4: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800424D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800424DC: b           L_800424FC
    // 0x800424E0: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_800424FC;
    // 0x800424E0: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_800424E4:
    // 0x800424E4: b           L_800424FC
    // 0x800424E8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_800424FC;
    // 0x800424E8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_800424EC:
    // 0x800424EC: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800424F0: nop

    // 0x800424F4: bltz        $s0, L_800424E4
    if (SIGNED(ctx->r16) < 0) {
        // 0x800424F8: nop
    
            goto L_800424E4;
    }
    // 0x800424F8: nop

L_800424FC:
    // 0x800424FC: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x80042500: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80042504: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80042508: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8004250C: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80042510: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80042514: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80042518: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8004251C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80042520: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80042524: lwc1        $f6, 0xAC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XAC);
    // 0x80042528: lwc1        $f4, 0x55C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55C8);
    // 0x8004252C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80042530: lwc1        $f10, 0x55CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X55CC);
    // 0x80042534: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80042538: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8004253C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80042540: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80042544: jal         0x80004E20
    // 0x80042548: nop

    Math_ModF(rdram, ctx);
        goto after_67;
    // 0x80042548: nop

    after_67:
    // 0x8004254C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042550: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80042554: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x80042558: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8004255C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80042560: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80042564: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80042568: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004256C: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80042570: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x80042574: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80042578: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8004257C: ori         $t6, $t6, 0x1000
    ctx->r14 = ctx->r14 | 0X1000;
    // 0x80042580: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80042584: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80042588: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004258C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80042590: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80042594: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80042598: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8004259C: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
    // 0x800425A0: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800425A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800425A8: nop

    // 0x800425AC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800425B0: beq         $t8, $zero, L_800425FC
    if (ctx->r24 == 0) {
        // 0x800425B4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_800425FC;
    }
    // 0x800425B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800425B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800425BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800425C0: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800425C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800425C8: nop

    // 0x800425CC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800425D0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800425D4: nop

    // 0x800425D8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800425DC: bne         $t8, $zero, L_800425F4
    if (ctx->r24 != 0) {
        // 0x800425E0: nop
    
            goto L_800425F4;
    }
    // 0x800425E0: nop

    // 0x800425E4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800425E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800425EC: b           L_8004260C
    // 0x800425F0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8004260C;
    // 0x800425F0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800425F4:
    // 0x800425F4: b           L_8004260C
    // 0x800425F8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8004260C;
    // 0x800425F8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800425FC:
    // 0x800425FC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80042600: nop

    // 0x80042604: bltz        $t8, L_800425F4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80042608: nop
    
            goto L_800425F4;
    }
    // 0x80042608: nop

L_8004260C:
    // 0x8004260C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80042610: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80042614: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80042618: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8004261C: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x80042620: andi        $t7, $s0, 0xFFF
    ctx->r15 = ctx->r16 & 0XFFF;
    // 0x80042624: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x80042628: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x8004262C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80042630: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80042634: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80042638: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8004263C: lbu         $t9, 0x7AC8($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7AC8);
    // 0x80042640: beq         $t9, $zero, L_80042658
    if (ctx->r25 == 0) {
        // 0x80042644: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80042658;
    }
    // 0x80042644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80042648: jal         0x800B8DD0
    // 0x8004264C: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    RCP_SetupDL(rdram, ctx);
        goto after_68;
    // 0x8004264C: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_68:
    // 0x80042650: b           L_80042664
    // 0x80042654: nop

        goto L_80042664;
    // 0x80042654: nop

L_80042658:
    // 0x80042658: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004265C: jal         0x800B8DD0
    // 0x80042660: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    RCP_SetupDL(rdram, ctx);
        goto after_69;
    // 0x80042660: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_69:
L_80042664:
    // 0x80042664: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80042668: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8004266C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80042670: lw          $v1, 0x1C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C8);
    // 0x80042674: bnel        $v1, $at, L_800426B4
    if (ctx->r3 != ctx->r1) {
        // 0x80042678: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800426B4;
    }
    goto skip_6;
    // 0x80042678: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_6:
    // 0x8004267C: lw          $t5, 0x1D0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1D0);
    // 0x80042680: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80042684: beql        $at, $zero, L_800426B4
    if (ctx->r1 == 0) {
        // 0x80042688: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800426B4;
    }
    goto skip_7;
    // 0x80042688: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_7:
    // 0x8004268C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042690: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80042694: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80042698: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8004269C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800426A0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800426A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800426A8: b           L_80042758
    // 0x800426AC: nop

        goto L_80042758;
    // 0x800426AC: nop

    // 0x800426B0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_800426B4:
    // 0x800426B4: bnel        $v1, $at, L_80042724
    if (ctx->r3 != ctx->r1) {
        // 0x800426B8: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80042724;
    }
    goto skip_8;
    // 0x800426B8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_8:
    // 0x800426BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800426C0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800426C4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800426C8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800426CC: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800426D0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800426D4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800426D8: lw          $t9, -0x688($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X688);
    // 0x800426DC: lw          $t8, -0x68C($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X68C);
    // 0x800426E0: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800426E4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800426E8: lw          $t9, -0x684($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X684);
    // 0x800426EC: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800426F0: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800426F4: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800426F8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800426FC: lw          $t9, -0x680($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X680);
    // 0x80042700: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80042704: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80042708: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8004270C: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x80042710: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x80042714: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80042718: b           L_80042758
    // 0x8004271C: nop

        goto L_80042758;
    // 0x8004271C: nop

    // 0x80042720: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80042724:
    // 0x80042724: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80042728: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8004272C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80042730: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80042734: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80042738: lwc1        $f6, 0x4188($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4188);
    // 0x8004273C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80042740: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80042744: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80042748: nop

    // 0x8004274C: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x80042750: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80042754: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80042758:
    // 0x80042758: jal         0x80005708
    // 0x8004275C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_70;
    // 0x8004275C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_70:
    // 0x80042760: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x80042764: addiu       $s1, $s1, -0x690
    ctx->r17 = ADD32(ctx->r17, -0X690);
    // 0x80042768: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004276C: lui         $a3, 0xC53B
    ctx->r7 = S32(0XC53B << 16);
    // 0x80042770: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80042774: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80042778: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8004277C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80042780: jal         0x80005B00
    // 0x80042784: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_71;
    // 0x80042784: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_71:
    // 0x80042788: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004278C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042790: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80042794: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80042798: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004279C: jal         0x80005C34
    // 0x800427A0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_72;
    // 0x800427A0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_72:
    // 0x800427A4: jal         0x80006EB8
    // 0x800427A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_73;
    // 0x800427A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_73:
    // 0x800427AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800427B0: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x800427B4: addiu       $s0, $s0, -0x53C0
    ctx->r16 = ADD32(ctx->r16, -0X53C0);
    // 0x800427B8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800427BC: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800427C0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x800427C4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x800427C8: jal         0x80005740
    // 0x800427CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_74;
    // 0x800427CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_74:
    // 0x800427D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800427D4: lui         $a3, 0x453B
    ctx->r7 = S32(0X453B << 16);
    // 0x800427D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800427DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800427E0: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x800427E4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800427E8: jal         0x80005B00
    // 0x800427EC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_75;
    // 0x800427EC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_75:
    // 0x800427F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800427F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800427F8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800427FC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80042800: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80042804: jal         0x80005C34
    // 0x80042808: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_76;
    // 0x80042808: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_76:
    // 0x8004280C: jal         0x80006EB8
    // 0x80042810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_77;
    // 0x80042810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_77:
    // 0x80042814: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042818: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8004281C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80042820: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80042824: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80042828: b           L_80042D0C
    // 0x8004282C: nop

        goto L_80042D0C;
    // 0x8004282C: nop

L_80042830:
    // 0x80042830: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80042834: lw          $t7, -0x7ED4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7ED4);
    // 0x80042838: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x8004283C: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80042840: bne         $t7, $zero, L_80042850
    if (ctx->r15 != 0) {
        // 0x80042844: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80042850;
    }
    // 0x80042844: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80042848: bne         $v0, $at, L_80042890
    if (ctx->r2 != ctx->r1) {
        // 0x8004284C: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_80042890;
    }
    // 0x8004284C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
L_80042850:
    // 0x80042850: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80042854: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80042858: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x8004285C: lw          $t5, -0x7C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C28);
    // 0x80042860: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80042864: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80042868: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8004286C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80042870: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80042874: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80042878: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8004287C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80042880: jal         0x800BA1D0
    // 0x80042884: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    RCP_SetupDL_29(rdram, ctx);
        goto after_78;
    // 0x80042884: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_78:
    // 0x80042888: b           L_800428CC
    // 0x8004288C: nop

        goto L_800428CC;
    // 0x8004288C: nop

L_80042890:
    // 0x80042890: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80042894: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80042898: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x8004289C: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x800428A0: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800428A4: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x800428A8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800428AC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800428B0: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x800428B4: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x800428B8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800428BC: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x800428C0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800428C4: jal         0x800B9618
    // 0x800428C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_20(rdram, ctx);
        goto after_79;
    // 0x800428C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_79:
L_800428CC:
    // 0x800428CC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800428D0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800428D4: addiu       $s0, $s0, -0x618C
    ctx->r16 = ADD32(ctx->r16, -0X618C);
    // 0x800428D8: addiu       $s1, $s1, -0x619C
    ctx->r17 = ADD32(ctx->r17, -0X619C);
    // 0x800428DC: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
L_800428E0:
    // 0x800428E0: jal         0x80005708
    // 0x800428E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_80;
    // 0x800428E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_80:
    // 0x800428E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800428EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800428F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800428F4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800428F8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800428FC: jal         0x80005B00
    // 0x80042900: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_81;
    // 0x80042900: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_81:
    // 0x80042904: jal         0x80006EB8
    // 0x80042908: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_82;
    // 0x80042908: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_82:
    // 0x8004290C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80042910: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80042914: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80042918: bnel        $v0, $at, L_80042948
    if (ctx->r2 != ctx->r1) {
        // 0x8004291C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80042948;
    }
    goto skip_9;
    // 0x8004291C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_9:
    // 0x80042920: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042924: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80042928: addiu       $t8, $t8, 0x1360
    ctx->r24 = ADD32(ctx->r24, 0X1360);
    // 0x8004292C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80042930: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80042934: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80042938: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8004293C: b           L_800429CC
    // 0x80042940: nop

        goto L_800429CC;
    // 0x80042940: nop

    // 0x80042944: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_80042948:
    // 0x80042948: bnel        $v0, $at, L_80042978
    if (ctx->r2 != ctx->r1) {
        // 0x8004294C: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80042978;
    }
    goto skip_10;
    // 0x8004294C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_10:
    // 0x80042950: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042954: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x80042958: addiu       $t9, $t9, -0x6DB0
    ctx->r25 = ADD32(ctx->r25, -0X6DB0);
    // 0x8004295C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80042960: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80042964: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80042968: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8004296C: b           L_800429CC
    // 0x80042970: nop

        goto L_800429CC;
    // 0x80042970: nop

    // 0x80042974: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
L_80042978:
    // 0x80042978: bnel        $v0, $at, L_800429A8
    if (ctx->r2 != ctx->r1) {
        // 0x8004297C: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_800429A8;
    }
    goto skip_11;
    // 0x8004297C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_11:
    // 0x80042980: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042984: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x80042988: addiu       $t5, $t5, -0x57F0
    ctx->r13 = ADD32(ctx->r13, -0X57F0);
    // 0x8004298C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80042990: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80042994: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80042998: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8004299C: b           L_800429CC
    // 0x800429A0: nop

        goto L_800429CC;
    // 0x800429A0: nop

    // 0x800429A4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_800429A8:
    // 0x800429A8: bne         $v0, $at, L_800429CC
    if (ctx->r2 != ctx->r1) {
        // 0x800429AC: nop
    
            goto L_800429CC;
    }
    // 0x800429AC: nop

    // 0x800429B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800429B4: lui         $t6, 0x601
    ctx->r14 = S32(0X601 << 16);
    // 0x800429B8: addiu       $t6, $t6, 0x700
    ctx->r14 = ADD32(ctx->r14, 0X700);
    // 0x800429BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800429C0: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800429C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800429C8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_800429CC:
    // 0x800429CC: jal         0x80005740
    // 0x800429D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_83;
    // 0x800429D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_83:
    // 0x800429D4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800429D8: addiu       $t9, $t9, -0x617C
    ctx->r25 = ADD32(ctx->r25, -0X617C);
    // 0x800429DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800429E0: bne         $s0, $t9, L_800428E0
    if (ctx->r16 != ctx->r25) {
        // 0x800429E4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800428E0;
    }
    // 0x800429E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800429E8: b           L_80042D0C
    // 0x800429EC: nop

        goto L_80042D0C;
    // 0x800429EC: nop

L_800429F0:
    // 0x800429F0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800429F4: lw          $t7, -0x7ED4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7ED4);
    // 0x800429F8: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800429FC: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80042A00: beq         $t7, $zero, L_80042A50
    if (ctx->r15 == 0) {
        // 0x80042A04: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_80042A50;
    }
    // 0x80042A04: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80042A08: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80042A0C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80042A10: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x80042A14: lw          $t5, -0x7C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C28);
    // 0x80042A18: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80042A1C: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80042A20: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80042A24: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80042A28: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80042A2C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80042A30: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80042A34: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80042A38: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80042A3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80042A40: jal         0x800BA1D0
    // 0x80042A44: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    RCP_SetupDL_29(rdram, ctx);
        goto after_84;
    // 0x80042A44: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_84:
    // 0x80042A48: b           L_80042A84
    // 0x80042A4C: nop

        goto L_80042A84;
    // 0x80042A4C: nop

L_80042A50:
    // 0x80042A50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80042A54: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80042A58: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x80042A5C: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x80042A60: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80042A64: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80042A68: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80042A6C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80042A70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80042A74: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80042A78: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80042A7C: jal         0x800B9618
    // 0x80042A80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_20(rdram, ctx);
        goto after_85;
    // 0x80042A80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_85:
L_80042A84:
    // 0x80042A84: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80042A88: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80042A8C: addiu       $s0, $s0, -0x618C
    ctx->r16 = ADD32(ctx->r16, -0X618C);
    // 0x80042A90: addiu       $s1, $s1, -0x619C
    ctx->r17 = ADD32(ctx->r17, -0X619C);
    // 0x80042A94: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
L_80042A98:
    // 0x80042A98: jal         0x80005708
    // 0x80042A9C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_86;
    // 0x80042A9C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_86:
    // 0x80042AA0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80042AA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80042AA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042AAC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80042AB0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80042AB4: jal         0x80005B00
    // 0x80042AB8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_87;
    // 0x80042AB8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_87:
    // 0x80042ABC: jal         0x80006EB8
    // 0x80042AC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_88;
    // 0x80042AC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_88:
    // 0x80042AC4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80042AC8: lw          $t5, 0x789C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X789C);
    // 0x80042ACC: bnel        $t5, $zero, L_80042AFC
    if (ctx->r13 != 0) {
        // 0x80042AD0: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80042AFC;
    }
    goto skip_12;
    // 0x80042AD0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_12:
    // 0x80042AD4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042AD8: lui         $t6, 0x302
    ctx->r14 = S32(0X302 << 16);
    // 0x80042ADC: addiu       $t6, $t6, -0x7800
    ctx->r14 = ADD32(ctx->r14, -0X7800);
    // 0x80042AE0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80042AE4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80042AE8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80042AEC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80042AF0: b           L_80042B14
    // 0x80042AF4: nop

        goto L_80042B14;
    // 0x80042AF4: nop

    // 0x80042AF8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80042AFC:
    // 0x80042AFC: lui         $t7, 0x301
    ctx->r15 = S32(0X301 << 16);
    // 0x80042B00: addiu       $t7, $t7, 0x60A0
    ctx->r15 = ADD32(ctx->r15, 0X60A0);
    // 0x80042B04: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80042B08: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80042B0C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80042B10: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_80042B14:
    // 0x80042B14: jal         0x80005740
    // 0x80042B18: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_89;
    // 0x80042B18: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_89:
    // 0x80042B1C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80042B20: addiu       $t5, $t5, -0x617C
    ctx->r13 = ADD32(ctx->r13, -0X617C);
    // 0x80042B24: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80042B28: bne         $s0, $t5, L_80042A98
    if (ctx->r16 != ctx->r13) {
        // 0x80042B2C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80042A98;
    }
    // 0x80042B2C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80042B30: b           L_80042D0C
    // 0x80042B34: nop

        goto L_80042D0C;
    // 0x80042B34: nop

L_80042B38:
    // 0x80042B38: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80042B3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80042B40: lw          $t6, -0x7C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C24);
    // 0x80042B44: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x80042B48: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80042B4C: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80042B50: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80042B54: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80042B58: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80042B5C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80042B60: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80042B64: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80042B68: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80042B6C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80042B70: jal         0x800BA1D0
    // 0x80042B74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_29(rdram, ctx);
        goto after_90;
    // 0x80042B74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_90:
    // 0x80042B78: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80042B7C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80042B80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80042B84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80042B88: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80042B8C: jal         0x80005B00
    // 0x80042B90: lui         $a3, 0xC4FA
    ctx->r7 = S32(0XC4FA << 16);
    Matrix_Translate(rdram, ctx);
        goto after_91;
    // 0x80042B90: lui         $a3, 0xC4FA
    ctx->r7 = S32(0XC4FA << 16);
    after_91:
    // 0x80042B94: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80042B98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042B9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80042BA0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042BA4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042BA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80042BAC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80042BB0: jal         0x80005C34
    // 0x80042BB4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_92;
    // 0x80042BB4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_92:
    // 0x80042BB8: jal         0x80006EB8
    // 0x80042BBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_93;
    // 0x80042BBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_93:
    // 0x80042BC0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80042BC4: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x80042BC8: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80042BCC: andi        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 & 0X1;
    // 0x80042BD0: beq         $t8, $zero, L_80042C00
    if (ctx->r24 == 0) {
        // 0x80042BD4: nop
    
            goto L_80042C00;
    }
    // 0x80042BD4: nop

    // 0x80042BD8: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80042BDC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042BE0: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80042BE4: addiu       $t9, $t9, 0x5B0
    ctx->r25 = ADD32(ctx->r25, 0X5B0);
    // 0x80042BE8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80042BEC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80042BF0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80042BF4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80042BF8: b           L_80042D0C
    // 0x80042BFC: nop

        goto L_80042D0C;
    // 0x80042BFC: nop

L_80042C00:
    // 0x80042C00: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042C04: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80042C08: addiu       $t5, $t5, 0x2E60
    ctx->r13 = ADD32(ctx->r13, 0X2E60);
    // 0x80042C0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80042C10: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80042C14: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80042C18: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80042C1C: b           L_80042D0C
    // 0x80042C20: nop

        goto L_80042D0C;
    // 0x80042C20: nop

L_80042C24:
    // 0x80042C24: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80042C28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80042C2C: lw          $t6, -0x7C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C24);
    // 0x80042C30: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x80042C34: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80042C38: addiu       $s3, $s3, -0x7CE0
    ctx->r19 = ADD32(ctx->r19, -0X7CE0);
    // 0x80042C3C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80042C40: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80042C44: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80042C48: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80042C4C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80042C50: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80042C54: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80042C58: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80042C5C: jal         0x800BA1D0
    // 0x80042C60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_29(rdram, ctx);
        goto after_94;
    // 0x80042C60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_94:
    // 0x80042C64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80042C68: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80042C6C: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x80042C70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80042C74: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80042C78: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80042C7C: jal         0x80005B00
    // 0x80042C80: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_95;
    // 0x80042C80: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_95:
    // 0x80042C84: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80042C88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042C8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80042C90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042C94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042C98: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80042C9C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80042CA0: jal         0x80005C34
    // 0x80042CA4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_96;
    // 0x80042CA4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_96:
    // 0x80042CA8: jal         0x80006EB8
    // 0x80042CAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_97;
    // 0x80042CAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_97:
    // 0x80042CB0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80042CB4: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x80042CB8: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80042CBC: andi        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 & 0X1;
    // 0x80042CC0: beq         $t8, $zero, L_80042CF0
    if (ctx->r24 == 0) {
        // 0x80042CC4: nop
    
            goto L_80042CF0;
    }
    // 0x80042CC4: nop

    // 0x80042CC8: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80042CCC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042CD0: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x80042CD4: addiu       $t9, $t9, -0x77D0
    ctx->r25 = ADD32(ctx->r25, -0X77D0);
    // 0x80042CD8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80042CDC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80042CE0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80042CE4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80042CE8: b           L_80042D0C
    // 0x80042CEC: nop

        goto L_80042D0C;
    // 0x80042CEC: nop

L_80042CF0:
    // 0x80042CF0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80042CF4: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x80042CF8: addiu       $t5, $t5, -0x4F20
    ctx->r13 = ADD32(ctx->r13, -0X4F20);
    // 0x80042CFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80042D00: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80042D04: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80042D08: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_80042D0C:
    // 0x80042D0C: jal         0x80005740
    // 0x80042D10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_98;
    // 0x80042D10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_98:
L_80042D14:
    // 0x80042D14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80042D18:
    // 0x80042D18: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80042D1C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80042D20: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80042D24: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80042D28: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80042D2C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80042D30: jr          $ra
    // 0x80042D34: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
    return;
    // 0x80042D34: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
;}
RECOMP_FUNC void Fault_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007D58: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80007D5C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80007D60: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80007D64: addiu       $s3, $s3, 0x5D10
    ctx->r19 = ADD32(ctx->r19, 0X5D10);
    // 0x80007D68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80007D6C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80007D70: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80007D74: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80007D78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80007D7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80007D80: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80007D84: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80007D88: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80007D8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80007D90: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80007D94: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80007D98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80007D9C: jal         0x80021D20
    // 0x80007DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80007DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80007DA4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80007DA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80007DAC: jal         0x80021D20
    // 0x80007DB0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80007DB0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80007DB4: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x80007DB8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80007DBC:
    // 0x80007DBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80007DC0: jal         0x800205E0
    // 0x80007DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80007DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80007DC8: jal         0x80007CEC
    // 0x80007DCC: nop

    func_80007CEC(rdram, ctx);
        goto after_3;
    // 0x80007DCC: nop

    after_3:
    // 0x80007DD0: beql        $v0, $zero, L_80007DBC
    if (ctx->r2 == 0) {
        // 0x80007DD4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80007DBC;
    }
    goto skip_0;
    // 0x80007DD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80007DD8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007DDC: addiu       $a2, $a2, -0x7A28
    ctx->r6 = ADD32(ctx->r6, -0X7A28);
    // 0x80007DE0: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x80007DE4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80007DE8: jal         0x8000762C
    // 0x80007DEC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    Fault_Printf(rdram, ctx);
        goto after_4;
    // 0x80007DEC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_4:
    // 0x80007DF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80007DF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007DF8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80007DFC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80007E00: sb          $t6, -0x2750($at)
    MEM_B(-0X2750, ctx->r1) = ctx->r14;
    // 0x80007E04: addiu       $s3, $s3, -0x2780
    ctx->r19 = ADD32(ctx->r19, -0X2780);
    // 0x80007E08: addiu       $s4, $s4, -0x2768
    ctx->r20 = ADD32(ctx->r20, -0X2768);
L_80007E0C:
    // 0x80007E0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80007E10: addiu       $a0, $a0, 0x22C0
    ctx->r4 = ADD32(ctx->r4, 0X22C0);
    // 0x80007E14: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80007E18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80007E1C: jal         0x80020720
    // 0x80007E20: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80007E20: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    after_5:
    // 0x80007E24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80007E28: addiu       $a0, $a0, 0x22F8
    ctx->r4 = ADD32(ctx->r4, 0X22F8);
    // 0x80007E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007E30: jal         0x800205E0
    // 0x80007E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80007E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80007E38: jal         0x800029A8
    // 0x80007E3C: nop

    Controller_UpdateInput(rdram, ctx);
        goto after_7;
    // 0x80007E3C: nop

    after_7:
    // 0x80007E40: sltiu       $at, $s1, 0x10
    ctx->r1 = ctx->r17 < 0X10 ? 1 : 0;
    // 0x80007E44: beq         $at, $zero, L_80007F70
    if (ctx->r1 == 0) {
        // 0x80007E48: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_80007F70;
    }
    // 0x80007E48: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80007E4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80007E50: addu        $at, $at, $t7
    gpr jr_addend_80007E58 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80007E54: lw          $t7, -0x7A24($at)
    ctx->r15 = ADD32(ctx->r1, -0X7A24);
    // 0x80007E58: jr          $t7
    // 0x80007E5C: nop

    switch (jr_addend_80007E58 >> 2) {
        case 0: goto L_80007E60; break;
        case 1: goto L_80007E7C; break;
        case 2: goto L_80007E7C; break;
        case 3: goto L_80007EB8; break;
        case 4: goto L_80007EB8; break;
        case 5: goto L_80007EF4; break;
        case 6: goto L_80007EF4; break;
        case 7: goto L_80007E7C; break;
        case 8: goto L_80007EB8; break;
        case 9: goto L_80007EF4; break;
        case 10: goto L_80007EF4; break;
        case 11: goto L_80007EF4; break;
        case 12: goto L_80007EF4; break;
        case 13: goto L_80007EF4; break;
        case 14: goto L_80007F30; break;
        case 15: goto L_80007F6C; break;
        default: switch_error(__func__, 0x80007E58, 0x800C85DC);
    }
    // 0x80007E5C: nop

L_80007E60:
    // 0x80007E60: lhu         $t8, 0x0($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X0);
    // 0x80007E64: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80007E68: bne         $t8, $at, L_80007F70
    if (ctx->r24 != ctx->r1) {
        // 0x80007E6C: nop
    
            goto L_80007F70;
    }
    // 0x80007E6C: nop

    // 0x80007E70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007E74: b           L_80007F70
    // 0x80007E78: addiu       $s2, $zero, 0xFA0
    ctx->r18 = ADD32(0, 0XFA0);
        goto L_80007F70;
    // 0x80007E78: addiu       $s2, $zero, 0xFA0
    ctx->r18 = ADD32(0, 0XFA0);
L_80007E7C:
    // 0x80007E7C: lhu         $t9, 0x0($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X0);
    // 0x80007E80: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x80007E84: beq         $t0, $zero, L_80007F70
    if (ctx->r8 == 0) {
        // 0x80007E88: nop
    
            goto L_80007F70;
    }
    // 0x80007E88: nop

    // 0x80007E8C: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x80007E90: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80007E94: bne         $v0, $at, L_80007EA8
    if (ctx->r2 != ctx->r1) {
        // 0x80007E98: nop
    
            goto L_80007EA8;
    }
    // 0x80007E98: nop

    // 0x80007E9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007EA0: b           L_80007F70
    // 0x80007EA4: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
        goto L_80007F70;
    // 0x80007EA4: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
L_80007EA8:
    // 0x80007EA8: beq         $v0, $zero, L_80007F70
    if (ctx->r2 == 0) {
        // 0x80007EAC: nop
    
            goto L_80007F70;
    }
    // 0x80007EAC: nop

    // 0x80007EB0: b           L_80007F70
    // 0x80007EB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80007F70;
    // 0x80007EB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80007EB8:
    // 0x80007EB8: lhu         $t1, 0x0($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X0);
    // 0x80007EBC: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x80007EC0: beq         $t2, $zero, L_80007F70
    if (ctx->r10 == 0) {
        // 0x80007EC4: nop
    
            goto L_80007F70;
    }
    // 0x80007EC4: nop

    // 0x80007EC8: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x80007ECC: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80007ED0: bne         $v0, $at, L_80007EE4
    if (ctx->r2 != ctx->r1) {
        // 0x80007ED4: nop
    
            goto L_80007EE4;
    }
    // 0x80007ED4: nop

    // 0x80007ED8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007EDC: b           L_80007F70
    // 0x80007EE0: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
        goto L_80007F70;
    // 0x80007EE0: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
L_80007EE4:
    // 0x80007EE4: beq         $v0, $zero, L_80007F70
    if (ctx->r2 == 0) {
        // 0x80007EE8: nop
    
            goto L_80007F70;
    }
    // 0x80007EE8: nop

    // 0x80007EEC: b           L_80007F70
    // 0x80007EF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80007F70;
    // 0x80007EF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80007EF4:
    // 0x80007EF4: lhu         $t3, 0x0($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X0);
    // 0x80007EF8: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80007EFC: beq         $t4, $zero, L_80007F70
    if (ctx->r12 == 0) {
        // 0x80007F00: nop
    
            goto L_80007F70;
    }
    // 0x80007F00: nop

    // 0x80007F04: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x80007F08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80007F0C: bne         $v0, $at, L_80007F20
    if (ctx->r2 != ctx->r1) {
        // 0x80007F10: nop
    
            goto L_80007F20;
    }
    // 0x80007F10: nop

    // 0x80007F14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007F18: b           L_80007F70
    // 0x80007F1C: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
        goto L_80007F70;
    // 0x80007F1C: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
L_80007F20:
    // 0x80007F20: beq         $v0, $zero, L_80007F70
    if (ctx->r2 == 0) {
        // 0x80007F24: nop
    
            goto L_80007F70;
    }
    // 0x80007F24: nop

    // 0x80007F28: b           L_80007F70
    // 0x80007F2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80007F70;
    // 0x80007F2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80007F30:
    // 0x80007F30: lhu         $t5, 0x0($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X0);
    // 0x80007F34: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80007F38: beq         $t6, $zero, L_80007F70
    if (ctx->r14 == 0) {
        // 0x80007F3C: nop
    
            goto L_80007F70;
    }
    // 0x80007F3C: nop

    // 0x80007F40: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x80007F44: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80007F48: bne         $v0, $at, L_80007F5C
    if (ctx->r2 != ctx->r1) {
        // 0x80007F4C: nop
    
            goto L_80007F5C;
    }
    // 0x80007F4C: nop

    // 0x80007F50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007F54: b           L_80007F70
    // 0x80007F58: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
        goto L_80007F70;
    // 0x80007F58: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
L_80007F5C:
    // 0x80007F5C: beq         $v0, $zero, L_80007F70
    if (ctx->r2 == 0) {
        // 0x80007F60: nop
    
            goto L_80007F70;
    }
    // 0x80007F60: nop

    // 0x80007F64: b           L_80007F70
    // 0x80007F68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80007F70;
    // 0x80007F68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80007F6C:
    // 0x80007F6C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80007F70:
    // 0x80007F70: beql        $s2, $zero, L_80007F84
    if (ctx->r18 == 0) {
        // 0x80007F74: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80007F84;
    }
    goto skip_1;
    // 0x80007F74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_1:
    // 0x80007F78: b           L_80007F84
    // 0x80007F7C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80007F84;
    // 0x80007F7C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80007F80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80007F84:
    // 0x80007F84: beq         $s5, $zero, L_80007E0C
    if (ctx->r21 == 0) {
        // 0x80007F88: nop
    
            goto L_80007E0C;
    }
    // 0x80007F88: nop

    // 0x80007F8C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80007F90: addiu       $s2, $zero, 0xBB8
    ctx->r18 = ADD32(0, 0XBB8);
    // 0x80007F94: jal         0x80007910
    // 0x80007F98: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    Fault_DisplayDebugInfo(rdram, ctx);
        goto after_8;
    // 0x80007F98: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_8:
L_80007F9C:
    // 0x80007F9C: b           L_80007F9C
    pause_self(rdram);
    // 0x80007FA0: nop

    // 0x80007FA4: nop

    // 0x80007FA8: nop

    // 0x80007FAC: nop

    // 0x80007FB0: nop

    // 0x80007FB4: nop

    // 0x80007FB8: nop

    // 0x80007FBC: nop

    // 0x80007FC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80007FC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80007FC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80007FCC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80007FD0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80007FD4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80007FD8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80007FDC: jr          $ra
    // 0x80007FE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80007FE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Audio_SequencePlayerProcessSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800135A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800135AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800135B0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800135B4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800135B8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800135BC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800135C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800135C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800135C8: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    // 0x800135CC: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x800135D0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800135D4: beq         $t6, $zero, L_8001366C
    if (ctx->r14 == 0) {
        // 0x800135D8: addiu       $s5, $s5, 0x2FE8
        ctx->r21 = ADD32(ctx->r21, 0X2FE8);
            goto L_8001366C;
    }
    // 0x800135D8: addiu       $s5, $s5, 0x2FE8
    ctx->r21 = ADD32(ctx->r21, 0X2FE8);
    // 0x800135DC: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800135E0: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800135E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800135E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800135EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800135F0: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800135F4: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x800135F8: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800135FC: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80013600: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x80013604: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80013608: nop

    // 0x8001360C: bc1fl       L_80013620
    if (!c1cs) {
        // 0x80013610: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80013620;
    }
    goto skip_0;
    // 0x80013610: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80013614: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80013618: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001361C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80013620:
    // 0x80013620: nop

    // 0x80013624: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80013628: nop

    // 0x8001362C: bc1fl       L_8001363C
    if (!c1cs) {
        // 0x80013630: lhu         $t0, 0x12($s3)
        ctx->r8 = MEM_HU(ctx->r19, 0X12);
            goto L_8001363C;
    }
    goto skip_1;
    // 0x80013630: lhu         $t0, 0x12($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X12);
    skip_1:
    // 0x80013634: swc1        $f2, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f2.u32l;
    // 0x80013638: lhu         $t0, 0x12($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X12);
L_8001363C:
    // 0x8001363C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80013640: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80013644: bne         $t2, $zero, L_8001366C
    if (ctx->r10 != 0) {
        // 0x80013648: sh          $t1, 0x12($s3)
        MEM_H(0X12, ctx->r19) = ctx->r9;
            goto L_8001366C;
    }
    // 0x80013648: sh          $t1, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r9;
    // 0x8001364C: lbu         $t3, 0x1($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X1);
    // 0x80013650: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80013654: bnel        $t3, $at, L_80013670
    if (ctx->r11 != ctx->r1) {
        // 0x80013658: lw          $t4, 0x0($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X0);
            goto L_80013670;
    }
    goto skip_2;
    // 0x80013658: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x8001365C: jal         0x800144E4
    // 0x80013660: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_0;
    // 0x80013660: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80013664: b           L_800136E8
    // 0x80013668: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800136E8;
    // 0x80013668: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001366C:
    // 0x8001366C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80013670:
    // 0x80013670: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80013674: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x80013678: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x8001367C: bgez        $t6, L_80013694
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80013680: addiu       $s4, $zero, 0x40
        ctx->r20 = ADD32(0, 0X40);
            goto L_80013694;
    }
    // 0x80013680: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x80013684: lwc1        $f10, 0x1C($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80013688: lwc1        $f16, 0x2C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x8001368C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80013690: swc1        $f18, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->f18.u32l;
L_80013694:
    // 0x80013694: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80013698:
    // 0x80013698: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8001369C: xor         $t7, $s5, $a0
    ctx->r15 = ctx->r21 ^ ctx->r4;
    // 0x800136A0: sltu        $t7, $zero, $t7
    ctx->r15 = 0 < ctx->r15 ? 1 : 0;
    // 0x800136A4: bnel        $s2, $t7, L_800136D0
    if (ctx->r18 != ctx->r15) {
        // 0x800136A8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800136D0;
    }
    goto skip_3;
    // 0x800136A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_3:
    // 0x800136AC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800136B0: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x800136B4: bnel        $s2, $t9, L_800136D0
    if (ctx->r18 != ctx->r25) {
        // 0x800136B8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800136D0;
    }
    goto skip_4;
    // 0x800136B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_4:
    // 0x800136BC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x800136C0: sll         $t0, $a1, 5
    ctx->r8 = S32(ctx->r5 << 5);
    // 0x800136C4: jal         0x80013400
    // 0x800136C8: srl         $a1, $t0, 31
    ctx->r5 = S32(U32(ctx->r8) >> 31);
    Audio_SequenceChannelProcessSound(rdram, ctx);
        goto after_1;
    // 0x800136C8: srl         $a1, $t0, 31
    ctx->r5 = S32(U32(ctx->r8) >> 31);
    after_1:
    // 0x800136CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800136D0:
    // 0x800136D0: bne         $s0, $s4, L_80013698
    if (ctx->r16 != ctx->r20) {
        // 0x800136D4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80013698;
    }
    // 0x800136D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800136D8: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
    // 0x800136DC: andi        $t3, $t2, 0xFFFB
    ctx->r11 = ctx->r10 & 0XFFFB;
    // 0x800136E0: sb          $t3, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r11;
    // 0x800136E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800136E8:
    // 0x800136E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800136EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800136F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800136F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800136F8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800136FC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80013700: jr          $ra
    // 0x80013704: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80013704: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void BoShieldReactor_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E69C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E6A0: jal         0x80187520
    // 0x8002E6A4: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E6A4: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_0:
    // 0x8002E6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E6AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E6B0: jr          $ra
    // 0x8002E6B4: nop

    return;
    // 0x8002E6B4: nop

;}
RECOMP_FUNC void ActorAllRange_ApplyDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003088C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80030890: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80030894: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030898: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003089C: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
    // 0x800308A0: beql        $v0, $zero, L_80031848
    if (ctx->r2 == 0) {
        // 0x800308A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80031848;
    }
    goto skip_0;
    // 0x800308A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800308A8: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    // 0x800308AC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800308B0: bnel        $v1, $at, L_800308C8
    if (ctx->r3 != ctx->r1) {
        // 0x800308B4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800308C8;
    }
    goto skip_1;
    // 0x800308B4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_1:
    // 0x800308B8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x800308BC: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
    // 0x800308C0: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    // 0x800308C4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_800308C8:
    // 0x800308C8: bne         $at, $zero, L_800308F4
    if (ctx->r1 != 0) {
        // 0x800308CC: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800308F4;
    }
    // 0x800308CC: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800308D0: bne         $at, $zero, L_800308F4
    if (ctx->r1 != 0) {
        // 0x800308D4: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_800308F4;
    }
    // 0x800308D4: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x800308D8: beq         $at, $zero, L_800308F4
    if (ctx->r1 == 0) {
        // 0x800308DC: addiu       $t6, $zero, 0xA
        ctx->r14 = ADD32(0, 0XA);
            goto L_800308F4;
    }
    // 0x800308DC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800308E0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800308E4: sh          $t6, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r14;
    // 0x800308E8: sh          $t7, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r15;
    // 0x800308EC: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
    // 0x800308F0: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_800308F4:
    // 0x800308F4: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800308F8: bne         $at, $zero, L_8003090C
    if (ctx->r1 != 0) {
        // 0x800308FC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8003090C;
    }
    // 0x800308FC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80030900: beq         $v1, $at, L_8003090C
    if (ctx->r3 == ctx->r1) {
        // 0x80030904: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8003090C;
    }
    // 0x80030904: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80030908: bne         $v1, $at, L_80030920
    if (ctx->r3 != ctx->r1) {
        // 0x8003090C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80030920;
    }
L_8003090C:
    // 0x8003090C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80030910: bnel        $v0, $at, L_80030924
    if (ctx->r2 != ctx->r1) {
        // 0x80030914: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80030924;
    }
    goto skip_2;
    // 0x80030914: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_2:
    // 0x80030918: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8003091C: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
L_80030920:
    // 0x80030920: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80030924:
    // 0x80030924: bnel        $v0, $at, L_8003094C
    if (ctx->r2 != ctx->r1) {
        // 0x80030928: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003094C;
    }
    goto skip_3;
    // 0x80030928: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x8003092C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80030930: lwc1        $f6, 0x16C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80030934: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80030938: nop

    // 0x8003093C: bc1fl       L_8003094C
    if (!c1cs) {
        // 0x80030940: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003094C;
    }
    goto skip_4;
    // 0x80030940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_4:
    // 0x80030944: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80030948: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8003094C:
    // 0x8003094C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80030950: lwc1        $f10, 0x170($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80030954: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80030958: nop

    // 0x8003095C: bc1fl       L_8003096C
    if (!c1cs) {
        // 0x80030960: lb          $v0, 0xD0($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XD0);
            goto L_8003096C;
    }
    goto skip_5;
    // 0x80030960: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
    skip_5:
    // 0x80030964: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80030968: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
L_8003096C:
    // 0x8003096C: beql        $v0, $zero, L_80031848
    if (ctx->r2 == 0) {
        // 0x80030970: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80031848;
    }
    goto skip_6;
    // 0x80030970: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80030974: lh          $t8, 0xB6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB6);
    // 0x80030978: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003097C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80030980: beq         $t8, $at, L_800309E0
    if (ctx->r24 == ctx->r1) {
        // 0x80030984: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800309E0;
    }
    // 0x80030984: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030988: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x8003098C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80030990: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80030994: bnel        $a0, $at, L_800309B8
    if (ctx->r4 != ctx->r1) {
        // 0x80030998: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_800309B8;
    }
    goto skip_7;
    // 0x80030998: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_7:
    // 0x8003099C: lbu         $t9, -0xAE8($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0XAE8);
    // 0x800309A0: beql        $t9, $zero, L_800309B8
    if (ctx->r25 == 0) {
        // 0x800309A4: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_800309B8;
    }
    goto skip_8;
    // 0x800309A4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_8:
    // 0x800309A8: lh          $t0, 0xE4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE4);
    // 0x800309AC: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800309B0: beq         $at, $zero, L_800309E0
    if (ctx->r1 == 0) {
        // 0x800309B4: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_800309E0;
    }
    // 0x800309B4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_800309B8:
    // 0x800309B8: bnel        $a0, $at, L_80030A04
    if (ctx->r4 != ctx->r1) {
        // 0x800309BC: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030A04;
    }
    goto skip_9;
    // 0x800309BC: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_9:
    // 0x800309C0: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    // 0x800309C4: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800309C8: bne         $at, $zero, L_80030A00
    if (ctx->r1 != 0) {
        // 0x800309CC: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_80030A00;
    }
    // 0x800309CC: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800309D0: beq         $at, $zero, L_80030A00
    if (ctx->r1 == 0) {
        // 0x800309D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80030A00;
    }
    // 0x800309D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800309D8: bnel        $v0, $at, L_80030A04
    if (ctx->r2 != ctx->r1) {
        // 0x800309DC: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030A04;
    }
    goto skip_10;
    // 0x800309DC: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_10:
L_800309E0:
    // 0x800309E0: sh          $zero, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = 0;
    // 0x800309E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800309E8: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x800309EC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800309F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800309F4: bnel        $t1, $at, L_80030A04
    if (ctx->r9 != ctx->r1) {
        // 0x800309F8: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030A04;
    }
    goto skip_11;
    // 0x800309F8: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_11:
    // 0x800309FC: sh          $zero, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = 0;
L_80030A00:
    // 0x80030A00: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030A04:
    // 0x80030A04: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80030A08: bnel        $at, $zero, L_80030A50
    if (ctx->r1 != 0) {
        // 0x80030A0C: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80030A50;
    }
    goto skip_12;
    // 0x80030A0C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    skip_12:
    // 0x80030A10: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
    // 0x80030A14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80030A18: bne         $v0, $at, L_80030A24
    if (ctx->r2 != ctx->r1) {
        // 0x80030A1C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80030A24;
    }
    // 0x80030A1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80030A20: beq         $v1, $at, L_80030A9C
    if (ctx->r3 == ctx->r1) {
        // 0x80030A24: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_80030A9C;
    }
L_80030A24:
    // 0x80030A24: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80030A28: bne         $v1, $at, L_80030A38
    if (ctx->r3 != ctx->r1) {
        // 0x80030A2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80030A38;
    }
    // 0x80030A2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80030A30: beql        $v0, $at, L_80030AA0
    if (ctx->r2 == ctx->r1) {
        // 0x80030A34: lh          $t1, 0xCE($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XCE);
            goto L_80030AA0;
    }
    goto skip_13;
    // 0x80030A34: lh          $t1, 0xCE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCE);
    skip_13:
L_80030A38:
    // 0x80030A38: lh          $t2, 0xCE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XCE);
    // 0x80030A3C: lhu         $t3, 0xD6($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XD6);
    // 0x80030A40: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80030A44: b           L_80030A9C
    // 0x80030A48: sh          $t4, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r12;
        goto L_80030A9C;
    // 0x80030A48: sh          $t4, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r12;
    // 0x80030A4C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80030A50:
    // 0x80030A50: beql        $at, $zero, L_80030AA0
    if (ctx->r1 == 0) {
        // 0x80030A54: lh          $t1, 0xCE($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XCE);
            goto L_80030AA0;
    }
    goto skip_14;
    // 0x80030A54: lh          $t1, 0xCE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCE);
    skip_14:
    // 0x80030A58: lh          $t5, 0xB8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB8);
    // 0x80030A5C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80030A60: beq         $t5, $at, L_80030A9C
    if (ctx->r13 == ctx->r1) {
        // 0x80030A64: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80030A9C;
    }
    // 0x80030A64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030A68: bne         $v1, $at, L_80030A88
    if (ctx->r3 != ctx->r1) {
        // 0x80030A6C: sll         $t0, $v1, 2
        ctx->r8 = S32(ctx->r3 << 2);
            goto L_80030A88;
    }
    // 0x80030A6C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80030A70: lhu         $t6, 0xD6($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XD6);
    // 0x80030A74: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80030A78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030A7C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80030A80: b           L_80030A9C
    // 0x80030A84: sw          $t6, 0x7910($at)
    MEM_W(0X7910, ctx->r1) = ctx->r14;
        goto L_80030A9C;
    // 0x80030A84: sw          $t6, 0x7910($at)
    MEM_W(0X7910, ctx->r1) = ctx->r14;
L_80030A88:
    // 0x80030A88: lhu         $t8, 0xD6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XD6);
    // 0x80030A8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030A90: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80030A94: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80030A98: sw          $t9, 0x7910($at)
    MEM_W(0X7910, ctx->r1) = ctx->r25;
L_80030A9C:
    // 0x80030A9C: lh          $t1, 0xCE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCE);
L_80030AA0:
    // 0x80030AA0: bgtz        $t1, L_800311B4
    if (SIGNED(ctx->r9) > 0) {
        // 0x80030AA4: nop
    
            goto L_800311B4;
    }
    // 0x80030AA4: nop

    // 0x80030AA8: lh          $t2, 0xE4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE4);
    // 0x80030AAC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80030AB0: sh          $zero, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = 0;
    // 0x80030AB4: bne         $t2, $at, L_80030BB8
    if (ctx->r10 != ctx->r1) {
        // 0x80030AB8: addiu       $t7, $zero, 0x32
        ctx->r15 = ADD32(0, 0X32);
            goto L_80030BB8;
    }
    // 0x80030AB8: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80030ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80030AC0: jal         0x80199900
    // 0x80030AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    SectorZ_MissileExplode(rdram, ctx);
        goto after_0;
    // 0x80030AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80030AC8: lh          $a0, 0xD4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XD4);
    // 0x80030ACC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030AD0: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80030AD4: bnel        $a0, $at, L_80030B34
    if (ctx->r4 != ctx->r1) {
        // 0x80030AD8: addiu       $a1, $zero, 0x66
        ctx->r5 = ADD32(0, 0X66);
            goto L_80030B34;
    }
    goto skip_15;
    // 0x80030AD8: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    skip_15:
    // 0x80030ADC: lbu         $t3, 0x5780($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X5780);
    // 0x80030AE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80030AE4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030AE8: bne         $t3, $at, L_80030AF8
    if (ctx->r11 != ctx->r1) {
        // 0x80030AEC: addiu       $a0, $a0, 0x1530
        ctx->r4 = ADD32(ctx->r4, 0X1530);
            goto L_80030AF8;
    }
    // 0x80030AEC: addiu       $a0, $a0, 0x1530
    ctx->r4 = ADD32(ctx->r4, 0X1530);
    // 0x80030AF0: jal         0x800BA808
    // 0x80030AF4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x80030AF4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_1:
L_80030AF8:
    // 0x80030AF8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80030AFC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80030B00: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80030B04: jal         0x80077240
    // 0x80030B08: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    BonusText_Display(rdram, ctx);
        goto after_2;
    // 0x80030B08: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_2:
    // 0x80030B0C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80030B10: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x80030B14: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80030B18: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80030B1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030B20: addiu       $t5, $t4, 0xB
    ctx->r13 = ADD32(ctx->r12, 0XB);
    // 0x80030B24: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80030B28: b           L_80031844
    // 0x80030B2C: sw          $t6, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r14;
        goto L_80031844;
    // 0x80030B2C: sw          $t6, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r14;
    // 0x80030B30: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
L_80030B34:
    // 0x80030B34: beq         $a0, $a1, L_80030B64
    if (ctx->r4 == ctx->r5) {
        // 0x80030B38: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_80030B64;
    }
    // 0x80030B38: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80030B3C: beq         $a0, $at, L_80030B7C
    if (ctx->r4 == ctx->r1) {
        // 0x80030B40: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80030B7C;
    }
    // 0x80030B40: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80030B44: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80030B48: beq         $a0, $at, L_80030B90
    if (ctx->r4 == ctx->r1) {
        // 0x80030B4C: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_80030B90;
    }
    // 0x80030B4C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80030B50: addiu       $at, $zero, 0x6D
    ctx->r1 = ADD32(0, 0X6D);
    // 0x80030B54: beq         $a0, $at, L_80030BA4
    if (ctx->r4 == ctx->r1) {
        // 0x80030B58: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_80030BA4;
    }
    // 0x80030B58: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80030B5C: b           L_80031848
    // 0x80030B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80031848;
    // 0x80030B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80030B64:
    // 0x80030B64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030B68: addiu       $a0, $a0, 0x163C
    ctx->r4 = ADD32(ctx->r4, 0X163C);
    // 0x80030B6C: jal         0x800BA808
    // 0x80030B70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x80030B70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80030B74: b           L_80031848
    // 0x80030B78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80031848;
    // 0x80030B78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80030B7C:
    // 0x80030B7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030B80: jal         0x800BA808
    // 0x80030B84: addiu       $a0, $a0, 0x1698
    ctx->r4 = ADD32(ctx->r4, 0X1698);
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x80030B84: addiu       $a0, $a0, 0x1698
    ctx->r4 = ADD32(ctx->r4, 0X1698);
    after_4:
    // 0x80030B88: b           L_80031848
    // 0x80030B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80031848;
    // 0x80030B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80030B90:
    // 0x80030B90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030B94: jal         0x800BA808
    // 0x80030B98: addiu       $a0, $a0, 0x1664
    ctx->r4 = ADD32(ctx->r4, 0X1664);
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x80030B98: addiu       $a0, $a0, 0x1664
    ctx->r4 = ADD32(ctx->r4, 0X1664);
    after_5:
    // 0x80030B9C: b           L_80031848
    // 0x80030BA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80031848;
    // 0x80030BA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80030BA4:
    // 0x80030BA4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030BA8: jal         0x800BA808
    // 0x80030BAC: addiu       $a0, $a0, 0x16C8
    ctx->r4 = ADD32(ctx->r4, 0X16C8);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x80030BAC: addiu       $a0, $a0, 0x16C8
    ctx->r4 = ADD32(ctx->r4, 0X16C8);
    after_6:
    // 0x80030BB0: b           L_80031848
    // 0x80030BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80031848;
    // 0x80030BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80030BB8:
    // 0x80030BB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80030BBC: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80030BC0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80030BC4: sh          $t7, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r15;
    // 0x80030BC8: sw          $t8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r24;
    // 0x80030BCC: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x80030BD0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80030BD4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80030BD8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80030BDC: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80030BE0: jal         0x8007D2C8
    // 0x80030BE4: swc1        $f16, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f16.u32l;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_7;
    // 0x80030BE4: swc1        $f16, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f16.u32l;
    after_7:
    // 0x80030BE8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80030BEC: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80030BF0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80030BF4: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80030BF8: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80030BFC: ori         $a0, $a0, 0x700B
    ctx->r4 = ctx->r4 | 0X700B;
    // 0x80030C00: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80030C04: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80030C08: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80030C0C: jal         0x80019218
    // 0x80030C10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x80030C10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x80030C14: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80030C18: sh          $t1, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r9;
    // 0x80030C1C: jal         0x80004EB0
    // 0x80030C20: sh          $zero, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = 0;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80030C20: sh          $zero, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = 0;
    after_9:
    // 0x80030C24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030C28: lwc1        $f18, 0x4EE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4EE8);
    // 0x80030C2C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80030C30: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80030C34: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80030C38: jal         0x80004EB0
    // 0x80030C3C: sh          $t3, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r11;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80030C3C: sh          $t3, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r11;
    after_10:
    // 0x80030C40: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80030C44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80030C48: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80030C4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030C50: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80030C54: addiu       $a2, $a2, -0x7DCC
    ctx->r6 = ADD32(ctx->r6, -0X7DCC);
    // 0x80030C58: addiu       $t9, $zero, 0x46
    ctx->r25 = ADD32(0, 0X46);
    // 0x80030C5C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80030C60: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80030C64: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80030C68: nop

    // 0x80030C6C: beq         $v0, $zero, L_80030C9C
    if (ctx->r2 == 0) {
        // 0x80030C70: nop
    
            goto L_80030C9C;
    }
    // 0x80030C70: nop

    // 0x80030C74: beq         $v0, $at, L_80030CA4
    if (ctx->r2 == ctx->r1) {
        // 0x80030C78: addiu       $t5, $zero, 0x32
        ctx->r13 = ADD32(0, 0X32);
            goto L_80030CA4;
    }
    // 0x80030C78: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x80030C7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80030C80: beq         $v0, $at, L_80030CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80030C84: addiu       $t6, $zero, 0xC8
        ctx->r14 = ADD32(0, 0XC8);
            goto L_80030CAC;
    }
    // 0x80030C84: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80030C88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80030C8C: beq         $v0, $at, L_80030CB4
    if (ctx->r2 == ctx->r1) {
        // 0x80030C90: addiu       $t7, $zero, 0x12C
        ctx->r15 = ADD32(0, 0X12C);
            goto L_80030CB4;
    }
    // 0x80030C90: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x80030C94: b           L_80030CBC
    // 0x80030C98: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
        goto L_80030CBC;
    // 0x80030C98: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
L_80030C9C:
    // 0x80030C9C: b           L_80030CB8
    // 0x80030CA0: sh          $zero, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = 0;
        goto L_80030CB8;
    // 0x80030CA0: sh          $zero, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = 0;
L_80030CA4:
    // 0x80030CA4: b           L_80030CB8
    // 0x80030CA8: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
        goto L_80030CB8;
    // 0x80030CA8: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
L_80030CAC:
    // 0x80030CAC: b           L_80030CB8
    // 0x80030CB0: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
        goto L_80030CB8;
    // 0x80030CB0: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
L_80030CB4:
    // 0x80030CB4: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
L_80030CB8:
    // 0x80030CB8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
L_80030CBC:
    // 0x80030CBC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80030CC0: bne         $t8, $at, L_80030CCC
    if (ctx->r24 != ctx->r1) {
        // 0x80030CC4: nop
    
            goto L_80030CCC;
    }
    // 0x80030CC4: nop

    // 0x80030CC8: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
L_80030CCC:
    // 0x80030CCC: lbu         $t0, 0x7C98($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7C98);
    // 0x80030CD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030CD4: bnel        $t0, $at, L_80030D4C
    if (ctx->r8 != ctx->r1) {
        // 0x80030CD8: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030D4C;
    }
    goto skip_16;
    // 0x80030CD8: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_16:
    // 0x80030CDC: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80030CE0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80030CE4: beql        $t1, $at, L_80030D4C
    if (ctx->r9 == ctx->r1) {
        // 0x80030CE8: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030D4C;
    }
    goto skip_17;
    // 0x80030CE8: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_17:
    // 0x80030CEC: jal         0x80004EB0
    // 0x80030CF0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x80030CF0: nop

    after_11:
    // 0x80030CF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80030CF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80030CFC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80030D00: addiu       $a2, $a2, -0x7DCC
    ctx->r6 = ADD32(ctx->r6, -0X7DCC);
    // 0x80030D04: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80030D08: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80030D0C: bc1f        L_80030D1C
    if (!c1cs) {
        // 0x80030D10: nop
    
            goto L_80030D1C;
    }
    // 0x80030D10: nop

    // 0x80030D14: b           L_80030D48
    // 0x80030D18: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
        goto L_80030D48;
    // 0x80030D18: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
L_80030D1C:
    // 0x80030D1C: jal         0x80004EB0
    // 0x80030D20: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x80030D20: nop

    after_12:
    // 0x80030D24: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80030D28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80030D2C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80030D30: addiu       $a2, $a2, -0x7DCC
    ctx->r6 = ADD32(ctx->r6, -0X7DCC);
    // 0x80030D34: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80030D38: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80030D3C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80030D40: nop

    // 0x80030D44: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
L_80030D48:
    // 0x80030D48: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030D4C:
    // 0x80030D4C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80030D50: bne         $at, $zero, L_80030E28
    if (ctx->r1 != 0) {
        // 0x80030D54: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_80030E28;
    }
    // 0x80030D54: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80030D58: beql        $at, $zero, L_80030E2C
    if (ctx->r1 == 0) {
        // 0x80030D5C: lhu         $t9, 0xD6($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0XD6);
            goto L_80030E2C;
    }
    goto skip_18;
    // 0x80030D5C: lhu         $t9, 0xD6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XD6);
    skip_18:
    // 0x80030D60: jal         0x80004EB0
    // 0x80030D64: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x80030D64: nop

    after_13:
    // 0x80030D68: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80030D6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80030D70: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80030D74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80030D78: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80030D7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80030D80: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80030D84: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80030D88: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80030D8C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80030D90: nop

    // 0x80030D94: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80030D98: nop

    // 0x80030D9C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80030DA0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80030DA4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80030DA8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80030DAC: nop

    // 0x80030DB0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80030DB4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80030DB8: nop

    // 0x80030DBC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80030DC0: beql        $t8, $zero, L_80030E10
    if (ctx->r24 == 0) {
        // 0x80030DC4: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_80030E10;
    }
    goto skip_19;
    // 0x80030DC4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_19:
    // 0x80030DC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80030DCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80030DD0: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80030DD4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80030DD8: nop

    // 0x80030DDC: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80030DE0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80030DE4: nop

    // 0x80030DE8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80030DEC: bne         $t8, $zero, L_80030E04
    if (ctx->r24 != 0) {
        // 0x80030DF0: nop
    
            goto L_80030E04;
    }
    // 0x80030DF0: nop

    // 0x80030DF4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80030DF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030DFC: b           L_80030E1C
    // 0x80030E00: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80030E1C;
    // 0x80030E00: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80030E04:
    // 0x80030E04: b           L_80030E1C
    // 0x80030E08: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80030E1C;
    // 0x80030E08: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80030E0C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_80030E10:
    // 0x80030E10: nop

    // 0x80030E14: bltz        $t8, L_80030E04
    if (SIGNED(ctx->r24) < 0) {
        // 0x80030E18: nop
    
            goto L_80030E04;
    }
    // 0x80030E18: nop

L_80030E1C:
    // 0x80030E1C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80030E20: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
    // 0x80030E24: addiu       $a2, $a2, -0x7DCC
    ctx->r6 = ADD32(ctx->r6, -0X7DCC);
L_80030E28:
    // 0x80030E28: lhu         $t9, 0xD6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XD6);
L_80030E2C:
    // 0x80030E2C: slti        $at, $t9, 0x14
    ctx->r1 = SIGNED(ctx->r25) < 0X14 ? 1 : 0;
    // 0x80030E30: bnel        $at, $zero, L_80030E40
    if (ctx->r1 != 0) {
        // 0x80030E34: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_80030E40;
    }
    goto skip_20;
    // 0x80030E34: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    skip_20:
    // 0x80030E38: sh          $zero, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = 0;
    // 0x80030E3C: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
L_80030E40:
    // 0x80030E40: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80030E44: bnel        $t0, $at, L_80030EB0
    if (ctx->r8 != ctx->r1) {
        // 0x80030E48: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030EB0;
    }
    goto skip_21;
    // 0x80030E48: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_21:
    // 0x80030E4C: lh          $t1, 0xB6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XB6);
    // 0x80030E50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030E54: bnel        $t1, $at, L_80030EB0
    if (ctx->r9 != ctx->r1) {
        // 0x80030E58: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030EB0;
    }
    goto skip_22;
    // 0x80030E58: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_22:
    // 0x80030E5C: lh          $t2, 0xD4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XD4);
    // 0x80030E60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030E64: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80030E68: bnel        $t2, $at, L_80030EB0
    if (ctx->r10 != ctx->r1) {
        // 0x80030E6C: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_80030EB0;
    }
    goto skip_23;
    // 0x80030E6C: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_23:
    // 0x80030E70: lbu         $v0, -0x6DF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6DF);
    // 0x80030E74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030E78: addiu       $a0, $a0, 0x23B0
    ctx->r4 = ADD32(ctx->r4, 0X23B0);
    // 0x80030E7C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80030E80: beql        $at, $zero, L_80030EA4
    if (ctx->r1 == 0) {
        // 0x80030E84: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_80030EA4;
    }
    goto skip_24;
    // 0x80030E84: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    skip_24:
    // 0x80030E88: jal         0x8002F5F4
    // 0x80030E8C: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_14;
    // 0x80030E8C: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_14:
    // 0x80030E90: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80030E94: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80030E98: addiu       $a2, $a2, -0x7DCC
    ctx->r6 = ADD32(ctx->r6, -0X7DCC);
    // 0x80030E9C: lbu         $v0, -0x6DF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6DF);
    // 0x80030EA0: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
L_80030EA4:
    // 0x80030EA4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80030EA8: sb          $t3, -0x6DF($at)
    MEM_B(-0X6DF, ctx->r1) = ctx->r11;
    // 0x80030EAC: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030EB0:
    // 0x80030EB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80030EB4: beq         $v1, $at, L_80030EDC
    if (ctx->r3 == ctx->r1) {
        // 0x80030EB8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80030EDC;
    }
    // 0x80030EB8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80030EBC: beq         $v1, $at, L_80030F20
    if (ctx->r3 == ctx->r1) {
        // 0x80030EC0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80030F20;
    }
    // 0x80030EC0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80030EC4: beq         $v1, $at, L_80030F64
    if (ctx->r3 == ctx->r1) {
        // 0x80030EC8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80030F64;
    }
    // 0x80030EC8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80030ECC: beq         $v1, $at, L_80030FA8
    if (ctx->r3 == ctx->r1) {
        // 0x80030ED0: nop
    
            goto L_80030FA8;
    }
    // 0x80030ED0: nop

    // 0x80030ED4: b           L_80030FEC
    // 0x80030ED8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
        goto L_80030FEC;
    // 0x80030ED8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80030EDC:
    // 0x80030EDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030EE0: sw          $zero, 0x7CD0($at)
    MEM_W(0X7CD0, ctx->r1) = 0;
    // 0x80030EE4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80030EE8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80030EEC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030EF0: bne         $t4, $at, L_80030F10
    if (ctx->r12 != ctx->r1) {
        // 0x80030EF4: addiu       $a0, $a0, -0xCE4
        ctx->r4 = ADD32(ctx->r4, -0XCE4);
            goto L_80030F10;
    }
    // 0x80030EF4: addiu       $a0, $a0, -0xCE4
    ctx->r4 = ADD32(ctx->r4, -0XCE4);
    // 0x80030EF8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030EFC: addiu       $a0, $a0, 0x314C
    ctx->r4 = ADD32(ctx->r4, 0X314C);
    // 0x80030F00: jal         0x8002F64C
    // 0x80030F04: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_15;
    // 0x80030F04: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_15:
    // 0x80030F08: b           L_80030F18
    // 0x80030F0C: nop

        goto L_80030F18;
    // 0x80030F0C: nop

L_80030F10:
    // 0x80030F10: jal         0x8002F64C
    // 0x80030F14: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_16;
    // 0x80030F14: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_16:
L_80030F18:
    // 0x80030F18: b           L_80030FE8
    // 0x80030F1C: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
        goto L_80030FE8;
    // 0x80030F1C: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030F20:
    // 0x80030F20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030F24: sw          $zero, 0x7CD4($at)
    MEM_W(0X7CD4, ctx->r1) = 0;
    // 0x80030F28: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80030F2C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80030F30: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030F34: bne         $t5, $at, L_80030F54
    if (ctx->r13 != ctx->r1) {
        // 0x80030F38: addiu       $a0, $a0, -0xCBC
        ctx->r4 = ADD32(ctx->r4, -0XCBC);
            goto L_80030F54;
    }
    // 0x80030F38: addiu       $a0, $a0, -0xCBC
    ctx->r4 = ADD32(ctx->r4, -0XCBC);
    // 0x80030F3C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030F40: addiu       $a0, $a0, 0x318C
    ctx->r4 = ADD32(ctx->r4, 0X318C);
    // 0x80030F44: jal         0x8002F64C
    // 0x80030F48: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_17;
    // 0x80030F48: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_17:
    // 0x80030F4C: b           L_80030F5C
    // 0x80030F50: nop

        goto L_80030F5C;
    // 0x80030F50: nop

L_80030F54:
    // 0x80030F54: jal         0x8002F64C
    // 0x80030F58: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_18;
    // 0x80030F58: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_18:
L_80030F5C:
    // 0x80030F5C: b           L_80030FE8
    // 0x80030F60: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
        goto L_80030FE8;
    // 0x80030F60: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030F64:
    // 0x80030F64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030F68: sw          $zero, 0x7CD8($at)
    MEM_W(0X7CD8, ctx->r1) = 0;
    // 0x80030F6C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80030F70: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80030F74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030F78: bne         $t6, $at, L_80030F98
    if (ctx->r14 != ctx->r1) {
        // 0x80030F7C: addiu       $a0, $a0, -0xC84
        ctx->r4 = ADD32(ctx->r4, -0XC84);
            goto L_80030F98;
    }
    // 0x80030F7C: addiu       $a0, $a0, -0xC84
    ctx->r4 = ADD32(ctx->r4, -0XC84);
    // 0x80030F80: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030F84: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    // 0x80030F88: jal         0x8002F64C
    // 0x80030F8C: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_19;
    // 0x80030F8C: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    after_19:
    // 0x80030F90: b           L_80030FA0
    // 0x80030F94: nop

        goto L_80030FA0;
    // 0x80030F94: nop

L_80030F98:
    // 0x80030F98: jal         0x8002F64C
    // 0x80030F9C: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_20;
    // 0x80030F9C: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    after_20:
L_80030FA0:
    // 0x80030FA0: b           L_80030FE8
    // 0x80030FA4: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
        goto L_80030FE8;
    // 0x80030FA4: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030FA8:
    // 0x80030FA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030FAC: sw          $zero, 0x7CDC($at)
    MEM_W(0X7CDC, ctx->r1) = 0;
    // 0x80030FB0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80030FB4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80030FB8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030FBC: bne         $t7, $at, L_80030FDC
    if (ctx->r15 != ctx->r1) {
        // 0x80030FC0: addiu       $a0, $a0, -0xC38
        ctx->r4 = ADD32(ctx->r4, -0XC38);
            goto L_80030FDC;
    }
    // 0x80030FC0: addiu       $a0, $a0, -0xC38
    ctx->r4 = ADD32(ctx->r4, -0XC38);
    // 0x80030FC4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030FC8: addiu       $a0, $a0, 0x31EC
    ctx->r4 = ADD32(ctx->r4, 0X31EC);
    // 0x80030FCC: jal         0x8002F64C
    // 0x80030FD0: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_21;
    // 0x80030FD0: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    after_21:
    // 0x80030FD4: b           L_80030FE8
    // 0x80030FD8: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
        goto L_80030FE8;
    // 0x80030FD8: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030FDC:
    // 0x80030FDC: jal         0x8002F64C
    // 0x80030FE0: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    ActorAllRange_StarWolfDefeatMesg(rdram, ctx);
        goto after_22;
    // 0x80030FE0: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    after_22:
    // 0x80030FE4: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_80030FE8:
    // 0x80030FE8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80030FEC:
    // 0x80030FEC: bne         $at, $zero, L_80031008
    if (ctx->r1 != 0) {
        // 0x80030FF0: addiu       $a1, $zero, 0x66
        ctx->r5 = ADD32(0, 0X66);
            goto L_80031008;
    }
    // 0x80030FF0: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // 0x80030FF4: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80030FF8: beq         $at, $zero, L_80031008
    if (ctx->r1 == 0) {
        // 0x80030FFC: addiu       $t8, $zero, 0x96
        ctx->r24 = ADD32(0, 0X96);
            goto L_80031008;
    }
    // 0x80030FFC: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x80031000: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80031004: sw          $t8, -0x6FC($at)
    MEM_W(-0X6FC, ctx->r1) = ctx->r24;
L_80031008:
    // 0x80031008: lh          $a0, 0xD4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XD4);
    // 0x8003100C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031010: beq         $a0, $at, L_80031038
    if (ctx->r4 == ctx->r1) {
        // 0x80031014: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80031038;
    }
    // 0x80031014: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80031018: beq         $a0, $a1, L_800310B4
    if (ctx->r4 == ctx->r5) {
        // 0x8003101C: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_800310B4;
    }
    // 0x8003101C: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80031020: beq         $v0, $at, L_800310B4
    if (ctx->r2 == ctx->r1) {
        // 0x80031024: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_800310B4;
    }
    // 0x80031024: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80031028: beql        $v0, $at, L_800310B8
    if (ctx->r2 == ctx->r1) {
        // 0x8003102C: lh          $v1, 0xE4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE4);
            goto L_800310B8;
    }
    goto skip_25;
    // 0x8003102C: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    skip_25:
    // 0x80031030: b           L_80031844
    // 0x80031034: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031034: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031038:
    // 0x80031038: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    // 0x8003103C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80031040: bnel        $at, $zero, L_80031844
    if (ctx->r1 != 0) {
        // 0x80031044: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_26;
    // 0x80031044: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_26:
    // 0x80031048: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x8003104C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031050: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031054: beq         $v0, $at, L_8003107C
    if (ctx->r2 == ctx->r1) {
        // 0x80031058: addiu       $a0, $a0, 0x3898
        ctx->r4 = ADD32(ctx->r4, 0X3898);
            goto L_8003107C;
    }
    // 0x80031058: addiu       $a0, $a0, 0x3898
    ctx->r4 = ADD32(ctx->r4, 0X3898);
    // 0x8003105C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031060: beq         $v0, $at, L_8003108C
    if (ctx->r2 == ctx->r1) {
        // 0x80031064: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8003108C;
    }
    // 0x80031064: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031068: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003106C: beq         $v0, $at, L_800310A0
    if (ctx->r2 == ctx->r1) {
        // 0x80031070: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800310A0;
    }
    // 0x80031070: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031074: b           L_80031844
    // 0x80031078: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031078: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_8003107C:
    // 0x8003107C: jal         0x8002F5F4
    // 0x80031080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_23;
    // 0x80031080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_23:
    // 0x80031084: b           L_80031844
    // 0x80031088: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031088: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_8003108C:
    // 0x8003108C: addiu       $a0, $a0, 0x3834
    ctx->r4 = ADD32(ctx->r4, 0X3834);
    // 0x80031090: jal         0x8002F5F4
    // 0x80031094: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_24;
    // 0x80031094: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_24:
    // 0x80031098: b           L_80031844
    // 0x8003109C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003109C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800310A0:
    // 0x800310A0: addiu       $a0, $a0, 0x385C
    ctx->r4 = ADD32(ctx->r4, 0X385C);
    // 0x800310A4: jal         0x8002F5F4
    // 0x800310A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_25;
    // 0x800310A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_25:
    // 0x800310AC: b           L_80031844
    // 0x800310B0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800310B0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800310B4:
    // 0x800310B4: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
L_800310B8:
    // 0x800310B8: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x800310BC: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800310C0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800310C4: bne         $at, $zero, L_80031190
    if (ctx->r1 != 0) {
        // 0x800310C8: addiu       $t9, $zero, 0x50
        ctx->r25 = ADD32(0, 0X50);
            goto L_80031190;
    }
    // 0x800310C8: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x800310CC: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x800310D0: beq         $at, $zero, L_80031190
    if (ctx->r1 == 0) {
        // 0x800310D4: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_80031190;
    }
    // 0x800310D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800310D8: addiu       $v1, $v1, 0x7CD0
    ctx->r3 = ADD32(ctx->r3, 0X7CD0);
    // 0x800310DC: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x800310E0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800310E4: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x800310E8: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800310EC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800310F0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800310F4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800310F8: bne         $t6, $zero, L_80031164
    if (ctx->r14 != 0) {
        // 0x800310FC: addiu       $t7, $zero, 0x50
        ctx->r15 = ADD32(0, 0X50);
            goto L_80031164;
    }
    // 0x800310FC: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80031100: beq         $v0, $a1, L_80031128
    if (ctx->r2 == ctx->r5) {
        // 0x80031104: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80031128;
    }
    // 0x80031104: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031108: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8003110C: beq         $v0, $at, L_8003113C
    if (ctx->r2 == ctx->r1) {
        // 0x80031110: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8003113C;
    }
    // 0x80031110: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031114: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80031118: beq         $v0, $at, L_80031150
    if (ctx->r2 == ctx->r1) {
        // 0x8003111C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80031150;
    }
    // 0x8003111C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031120: b           L_80031844
    // 0x80031124: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031124: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031128:
    // 0x80031128: addiu       $a0, $a0, -0x6E0
    ctx->r4 = ADD32(ctx->r4, -0X6E0);
    // 0x8003112C: jal         0x800BA808
    // 0x80031130: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_26;
    // 0x80031130: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_26:
    // 0x80031134: b           L_80031844
    // 0x80031138: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031138: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_8003113C:
    // 0x8003113C: addiu       $a0, $a0, -0x738
    ctx->r4 = ADD32(ctx->r4, -0X738);
    // 0x80031140: jal         0x800BA808
    // 0x80031144: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_27;
    // 0x80031144: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_27:
    // 0x80031148: b           L_80031844
    // 0x8003114C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003114C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031150:
    // 0x80031150: addiu       $a0, $a0, -0x70C
    ctx->r4 = ADD32(ctx->r4, -0X70C);
    // 0x80031154: jal         0x800BA808
    // 0x80031158: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_28;
    // 0x80031158: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_28:
    // 0x8003115C: b           L_80031844
    // 0x80031160: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031160: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031164:
    // 0x80031164: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80031168: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8003116C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80031170: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80031174: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80031178: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8003117C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80031180: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80031184: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80031188: b           L_80031840
    // 0x8003118C: sw          $t7, 0x15F0($at)
    MEM_W(0X15F0, ctx->r1) = ctx->r15;
        goto L_80031840;
    // 0x8003118C: sw          $t7, 0x15F0($at)
    MEM_W(0X15F0, ctx->r1) = ctx->r15;
L_80031190:
    // 0x80031190: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80031194: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80031198: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003119C: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x800311A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800311A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800311A8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800311AC: b           L_80031840
    // 0x800311B0: sw          $t9, 0x15F0($at)
    MEM_W(0X15F0, ctx->r1) = ctx->r25;
        goto L_80031840;
    // 0x800311B0: sw          $t9, 0x15F0($at)
    MEM_W(0X15F0, ctx->r1) = ctx->r25;
L_800311B4:
    // 0x800311B4: beq         $a1, $zero, L_80031254
    if (ctx->r5 == 0) {
        // 0x800311B8: addiu       $t5, $zero, 0x14
        ctx->r13 = ADD32(0, 0X14);
            goto L_80031254;
    }
    // 0x800311B8: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x800311BC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800311C0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800311C4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800311C8: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x800311CC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x800311D0: ori         $a0, $a0, 0x1062
    ctx->r4 = ctx->r4 | 0X1062;
    // 0x800311D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800311D8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800311DC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800311E0: jal         0x80019218
    // 0x800311E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_29;
    // 0x800311E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_29:
    // 0x800311E8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800311EC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800311F0: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x800311F4: sw          $t2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r10;
    // 0x800311F8: sw          $t3, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r11;
    // 0x800311FC: jal         0x80004EB0
    // 0x80031200: sw          $t4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r12;
    Rand_ZeroOne(rdram, ctx);
        goto after_30;
    // 0x80031200: sw          $t4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r12;
    after_30:
    // 0x80031204: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80031208: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003120C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80031210: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80031214: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80031218: nop

    // 0x8003121C: bc1fl       L_80031240
    if (!c1cs) {
        // 0x80031220: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80031240;
    }
    goto skip_27;
    // 0x80031220: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_27:
    // 0x80031224: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80031228: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003122C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80031230: swc1        $f18, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f18.u32l;
    // 0x80031234: b           L_80031268
    // 0x80031238: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
        goto L_80031268;
    // 0x80031238: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    // 0x8003123C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80031240:
    // 0x80031240: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80031244: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x80031248: lwc1        $f10, 0x4EEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4EEC);
    // 0x8003124C: b           L_80031268
    // 0x80031250: swc1        $f10, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
        goto L_80031268;
    // 0x80031250: swc1        $f10, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
L_80031254:
    // 0x80031254: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80031258: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8003125C: sh          $t5, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r13;
    // 0x80031260: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80031264: sw          $t6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r14;
L_80031268:
    // 0x80031268: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
    // 0x8003126C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80031270: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80031274: bne         $t7, $at, L_800312A0
    if (ctx->r15 != ctx->r1) {
        // 0x80031278: ori         $a0, $a0, 0x4003
        ctx->r4 = ctx->r4 | 0X4003;
            goto L_800312A0;
    }
    // 0x80031278: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8003127C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80031280: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80031284: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80031288: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8003128C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80031290: jal         0x80019218
    // 0x80031294: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_31;
    // 0x80031294: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_31:
    // 0x80031298: b           L_800312D0
    // 0x8003129C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
        goto L_800312D0;
    // 0x8003129C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
L_800312A0:
    // 0x800312A0: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x800312A4: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x800312A8: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x800312AC: bne         $t9, $zero, L_800312CC
    if (ctx->r25 != 0) {
        // 0x800312B0: addiu       $a1, $s0, 0x100
        ctx->r5 = ADD32(ctx->r16, 0X100);
            goto L_800312CC;
    }
    // 0x800312B0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800312B4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800312B8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x800312BC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800312C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800312C4: jal         0x80019218
    // 0x800312C8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_32;
    // 0x800312C8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_32:
L_800312CC:
    // 0x800312CC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
L_800312D0:
    // 0x800312D0: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800312D4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800312D8: jal         0x8007D10C
    // 0x800312DC: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_33;
    // 0x800312DC: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_33:
    // 0x800312E0: lh          $t1, 0xE4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE4);
    // 0x800312E4: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x800312E8: beq         $at, $zero, L_80031414
    if (ctx->r1 == 0) {
        // 0x800312EC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80031414;
    }
    // 0x800312EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800312F0: lwc1        $f18, 0x4EF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4EF0);
    // 0x800312F4: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800312F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800312FC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80031300: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80031304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031308: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003130C: jal         0x80005E90
    // 0x80031310: nop

    Matrix_RotateY(rdram, ctx);
        goto after_34;
    // 0x80031310: nop

    after_34:
    // 0x80031314: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80031318: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003131C: jal         0x80004EB0
    // 0x80031320: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_35;
    // 0x80031320: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_35:
    // 0x80031324: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80031328: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003132C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80031330: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80031334: nop

    // 0x80031338: bc1f        L_8003134C
    if (!c1cs) {
        // 0x8003133C: nop
    
            goto L_8003134C;
    }
    // 0x8003133C: nop

    // 0x80031340: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031344: nop

    // 0x80031348: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
L_8003134C:
    // 0x8003134C: jal         0x80004EB0
    // 0x80031350: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_36;
    // 0x80031350: nop

    after_36:
    // 0x80031354: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80031358: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003135C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80031360: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80031364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80031368: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003136C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80031370: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80031374: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80031378: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003137C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80031380: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    // 0x80031384: beq         $t2, $zero, L_800313E8
    if (ctx->r10 == 0) {
        // 0x80031388: nop
    
            goto L_800313E8;
    }
    // 0x80031388: nop

    // 0x8003138C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031390: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80031394: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80031398: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003139C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800313A0: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800313A4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800313A8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800313AC: nop

    // 0x800313B0: bc1f        L_800313E8
    if (!c1cs) {
        // 0x800313B4: nop
    
            goto L_800313E8;
    }
    // 0x800313B4: nop

    // 0x800313B8: jal         0x80004EB0
    // 0x800313BC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_37;
    // 0x800313BC: nop

    after_37:
    // 0x800313C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800313C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800313C8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x800313CC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800313D0: nop

    // 0x800313D4: bc1f        L_800313E8
    if (!c1cs) {
        // 0x800313D8: nop
    
            goto L_800313E8;
    }
    // 0x800313D8: nop

    // 0x800313DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800313E0: nop

    // 0x800313E4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_800313E8:
    // 0x800313E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800313EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800313F0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800313F4: jal         0x80006A20
    // 0x800313F8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_38;
    // 0x800313F8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_38:
    // 0x800313FC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80031400: swc1        $f10, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f10.u32l;
    // 0x80031404: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80031408: swc1        $f16, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f16.u32l;
    // 0x8003140C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80031410: swc1        $f18, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f18.u32l;
L_80031414:
    // 0x80031414: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80031418: lw          $t3, -0x7D64($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D64);
    // 0x8003141C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80031420: bnel        $t3, $zero, L_80031844
    if (ctx->r11 != 0) {
        // 0x80031424: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_28;
    // 0x80031424: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_28:
    // 0x80031428: lbu         $t4, 0x3FE0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X3FE0);
    // 0x8003142C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031430: bnel        $t4, $at, L_80031844
    if (ctx->r12 != ctx->r1) {
        // 0x80031434: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_29;
    // 0x80031434: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_29:
    // 0x80031438: lb          $t5, 0xD0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0XD0);
    // 0x8003143C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80031440: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    // 0x80031444: bne         $t5, $at, L_800314D0
    if (ctx->r13 != ctx->r1) {
        // 0x80031448: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800314D0;
    }
    // 0x80031448: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003144C: beq         $v1, $at, L_80031480
    if (ctx->r3 == ctx->r1) {
        // 0x80031450: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80031480;
    }
    // 0x80031450: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031454: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031458: beq         $v1, $at, L_800314A8
    if (ctx->r3 == ctx->r1) {
        // 0x8003145C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800314A8;
    }
    // 0x8003145C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031460: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80031464: beq         $v1, $at, L_80031494
    if (ctx->r3 == ctx->r1) {
        // 0x80031468: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80031494;
    }
    // 0x80031468: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003146C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80031470: beq         $v1, $at, L_800314BC
    if (ctx->r3 == ctx->r1) {
        // 0x80031474: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800314BC;
    }
    // 0x80031474: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031478: b           L_80031844
    // 0x8003147C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003147C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031480:
    // 0x80031480: addiu       $a0, $a0, 0x398C
    ctx->r4 = ADD32(ctx->r4, 0X398C);
    // 0x80031484: jal         0x8002F5F4
    // 0x80031488: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_39;
    // 0x80031488: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_39:
    // 0x8003148C: b           L_80031844
    // 0x80031490: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031490: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031494:
    // 0x80031494: addiu       $a0, $a0, 0x3950
    ctx->r4 = ADD32(ctx->r4, 0X3950);
    // 0x80031498: jal         0x8002F5F4
    // 0x8003149C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_40;
    // 0x8003149C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_40:
    // 0x800314A0: b           L_80031844
    // 0x800314A4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800314A4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800314A8:
    // 0x800314A8: addiu       $a0, $a0, 0x3900
    ctx->r4 = ADD32(ctx->r4, 0X3900);
    // 0x800314AC: jal         0x8002F5F4
    // 0x800314B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_41;
    // 0x800314B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_41:
    // 0x800314B4: b           L_80031844
    // 0x800314B8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800314B8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800314BC:
    // 0x800314BC: addiu       $a0, $a0, 0x3760
    ctx->r4 = ADD32(ctx->r4, 0X3760);
    // 0x800314C0: jal         0x8002F5F4
    // 0x800314C4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_42;
    // 0x800314C4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_42:
    // 0x800314C8: b           L_80031844
    // 0x800314CC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800314CC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800314D0:
    // 0x800314D0: lh          $a0, 0xD4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XD4);
    // 0x800314D4: slti        $at, $a0, 0x69
    ctx->r1 = SIGNED(ctx->r4) < 0X69 ? 1 : 0;
    // 0x800314D8: beq         $at, $zero, L_80031680
    if (ctx->r1 == 0) {
        // 0x800314DC: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80031680;
    }
    // 0x800314DC: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800314E0: bne         $at, $zero, L_80031610
    if (ctx->r1 != 0) {
        // 0x800314E4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80031610;
    }
    // 0x800314E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800314E8: bne         $a0, $at, L_80031840
    if (ctx->r4 != ctx->r1) {
        // 0x800314EC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80031840;
    }
    // 0x800314EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800314F0: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x800314F4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800314F8: bnel        $a0, $at, L_80031544
    if (ctx->r4 != ctx->r1) {
        // 0x800314FC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80031544;
    }
    goto skip_30;
    // 0x800314FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_30:
    // 0x80031500: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    // 0x80031504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031508: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003150C: bne         $t6, $at, L_80031540
    if (ctx->r14 != ctx->r1) {
        // 0x80031510: addiu       $v0, $v0, -0x6E0
        ctx->r2 = ADD32(ctx->r2, -0X6E0);
            goto L_80031540;
    }
    // 0x80031510: addiu       $v0, $v0, -0x6E0
    ctx->r2 = ADD32(ctx->r2, -0X6E0);
    // 0x80031514: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80031518: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003151C: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80031520: bnel        $t7, $zero, L_80031544
    if (ctx->r15 != 0) {
        // 0x80031524: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80031544;
    }
    goto skip_31;
    // 0x80031524: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_31:
    // 0x80031528: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003152C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80031530: jal         0x800BA808
    // 0x80031534: addiu       $a0, $a0, 0x236C
    ctx->r4 = ADD32(ctx->r4, 0X236C);
    Radio_PlayMessage(rdram, ctx);
        goto after_43;
    // 0x80031534: addiu       $a0, $a0, 0x236C
    ctx->r4 = ADD32(ctx->r4, 0X236C);
    after_43:
    // 0x80031538: b           L_80031844
    // 0x8003153C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003153C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031540:
    // 0x80031540: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_80031544:
    // 0x80031544: bne         $v1, $at, L_80031560
    if (ctx->r3 != ctx->r1) {
        // 0x80031548: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_80031560;
    }
    // 0x80031548: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8003154C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031550: jal         0x8002F5F4
    // 0x80031554: addiu       $a0, $a0, 0x3760
    ctx->r4 = ADD32(ctx->r4, 0X3760);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_44;
    // 0x80031554: addiu       $a0, $a0, 0x3760
    ctx->r4 = ADD32(ctx->r4, 0X3760);
    after_44:
    // 0x80031558: b           L_80031844
    // 0x8003155C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003155C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031560:
    // 0x80031560: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80031564: bne         $v1, $at, L_80031580
    if (ctx->r3 != ctx->r1) {
        // 0x80031568: addiu       $a1, $zero, 0xAA
        ctx->r5 = ADD32(0, 0XAA);
            goto L_80031580;
    }
    // 0x80031568: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x8003156C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031570: jal         0x8002F5F4
    // 0x80031574: addiu       $a0, $a0, 0x37B4
    ctx->r4 = ADD32(ctx->r4, 0X37B4);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_45;
    // 0x80031574: addiu       $a0, $a0, 0x37B4
    ctx->r4 = ADD32(ctx->r4, 0X37B4);
    after_45:
    // 0x80031578: b           L_80031844
    // 0x8003157C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003157C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031580:
    // 0x80031580: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80031584: bne         $a0, $at, L_80031840
    if (ctx->r4 != ctx->r1) {
        // 0x80031588: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80031840;
    }
    // 0x80031588: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003158C: beq         $v1, $at, L_800315C0
    if (ctx->r3 == ctx->r1) {
        // 0x80031590: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800315C0;
    }
    // 0x80031590: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031594: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80031598: beq         $v1, $at, L_800315D4
    if (ctx->r3 == ctx->r1) {
        // 0x8003159C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800315D4;
    }
    // 0x8003159C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800315A0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800315A4: beq         $v1, $at, L_800315E8
    if (ctx->r3 == ctx->r1) {
        // 0x800315A8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800315E8;
    }
    // 0x800315A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800315AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800315B0: beq         $v1, $at, L_800315FC
    if (ctx->r3 == ctx->r1) {
        // 0x800315B4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800315FC;
    }
    // 0x800315B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800315B8: b           L_80031844
    // 0x800315BC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800315BC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800315C0:
    // 0x800315C0: addiu       $a0, $a0, 0x3028
    ctx->r4 = ADD32(ctx->r4, 0X3028);
    // 0x800315C4: jal         0x8002F5F4
    // 0x800315C8: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_46;
    // 0x800315C8: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_46:
    // 0x800315CC: b           L_80031844
    // 0x800315D0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800315D0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800315D4:
    // 0x800315D4: addiu       $a0, $a0, 0x3068
    ctx->r4 = ADD32(ctx->r4, 0X3068);
    // 0x800315D8: jal         0x8002F5F4
    // 0x800315DC: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_47;
    // 0x800315DC: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_47:
    // 0x800315E0: b           L_80031844
    // 0x800315E4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800315E4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800315E8:
    // 0x800315E8: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, 0X30B0);
    // 0x800315EC: jal         0x8002F5F4
    // 0x800315F0: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_48;
    // 0x800315F0: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    after_48:
    // 0x800315F4: b           L_80031844
    // 0x800315F8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800315F8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800315FC:
    // 0x800315FC: addiu       $a0, $a0, 0x3110
    ctx->r4 = ADD32(ctx->r4, 0X3110);
    // 0x80031600: jal         0x8002F5F4
    // 0x80031604: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_49;
    // 0x80031604: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    after_49:
    // 0x80031608: b           L_80031844
    // 0x8003160C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003160C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031610:
    // 0x80031610: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031614: bne         $a0, $at, L_80031840
    if (ctx->r4 != ctx->r1) {
        // 0x80031618: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80031840;
    }
    // 0x80031618: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003161C: beq         $v1, $at, L_80031644
    if (ctx->r3 == ctx->r1) {
        // 0x80031620: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80031644;
    }
    // 0x80031620: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031624: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031628: beq         $v1, $at, L_8003166C
    if (ctx->r3 == ctx->r1) {
        // 0x8003162C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8003166C;
    }
    // 0x8003162C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031630: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80031634: beq         $v1, $at, L_80031658
    if (ctx->r3 == ctx->r1) {
        // 0x80031638: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80031658;
    }
    // 0x80031638: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003163C: b           L_80031844
    // 0x80031640: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031640: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031644:
    // 0x80031644: addiu       $a0, $a0, 0x36B0
    ctx->r4 = ADD32(ctx->r4, 0X36B0);
    // 0x80031648: jal         0x8002F5F4
    // 0x8003164C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_50;
    // 0x8003164C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_50:
    // 0x80031650: b           L_80031844
    // 0x80031654: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031654: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031658:
    // 0x80031658: addiu       $a0, $a0, 0x36F8
    ctx->r4 = ADD32(ctx->r4, 0X36F8);
    // 0x8003165C: jal         0x8002F5F4
    // 0x80031660: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_51;
    // 0x80031660: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_51:
    // 0x80031664: b           L_80031844
    // 0x80031668: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x80031668: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_8003166C:
    // 0x8003166C: addiu       $a0, $a0, 0x3724
    ctx->r4 = ADD32(ctx->r4, 0X3724);
    // 0x80031670: jal         0x8002F5F4
    // 0x80031674: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_52;
    // 0x80031674: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_52:
    // 0x80031678: b           L_80031844
    // 0x8003167C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x8003167C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031680:
    // 0x80031680: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80031684: beql        $at, $zero, L_80031844
    if (ctx->r1 == 0) {
        // 0x80031688: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_32;
    // 0x80031688: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_32:
    // 0x8003168C: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80031690: beql        $t9, $zero, L_80031844
    if (ctx->r25 == 0) {
        // 0x80031694: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_33;
    // 0x80031694: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_33:
    // 0x80031698: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
    // 0x8003169C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800316A0: beql        $t0, $zero, L_80031844
    if (ctx->r8 == 0) {
        // 0x800316A4: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_34;
    // 0x800316A4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_34:
    // 0x800316A8: beq         $v1, $at, L_800316D0
    if (ctx->r3 == ctx->r1) {
        // 0x800316AC: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_800316D0;
    }
    // 0x800316AC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800316B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800316B4: beq         $v1, $at, L_8003174C
    if (ctx->r3 == ctx->r1) {
        // 0x800316B8: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8003174C;
    }
    // 0x800316B8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800316BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800316C0: beq         $v1, $at, L_800317C8
    if (ctx->r3 == ctx->r1) {
        // 0x800316C4: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_800317C8;
    }
    // 0x800316C4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800316C8: b           L_80031844
    // 0x800316CC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80031844;
    // 0x800316CC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800316D0:
    // 0x800316D0: lw          $t1, 0x78B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B4);
    // 0x800316D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800316D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800316DC: slti        $at, $t1, 0x5A
    ctx->r1 = SIGNED(ctx->r9) < 0X5A ? 1 : 0;
    // 0x800316E0: bne         $at, $zero, L_800316FC
    if (ctx->r1 != 0) {
        // 0x800316E4: addiu       $a0, $a0, -0x1534
        ctx->r4 = ADD32(ctx->r4, -0X1534);
            goto L_800316FC;
    }
    // 0x800316E4: addiu       $a0, $a0, -0x1534
    ctx->r4 = ADD32(ctx->r4, -0X1534);
    // 0x800316E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800316EC: jal         0x8002F5F4
    // 0x800316F0: addiu       $a0, $a0, -0x1604
    ctx->r4 = ADD32(ctx->r4, -0X1604);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_53;
    // 0x800316F0: addiu       $a0, $a0, -0x1604
    ctx->r4 = ADD32(ctx->r4, -0X1604);
    after_53:
    // 0x800316F4: b           L_80031704
    // 0x800316F8: nop

        goto L_80031704;
    // 0x800316F8: nop

L_800316FC:
    // 0x800316FC: jal         0x800BA808
    // 0x80031700: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_54;
    // 0x80031700: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_54:
L_80031704:
    // 0x80031704: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80031708: addiu       $v0, $v0, -0x5DCC
    ctx->r2 = ADD32(ctx->r2, -0X5DCC);
    // 0x8003170C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80031710: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x80031714: beql        $t2, $zero, L_80031740
    if (ctx->r10 == 0) {
        // 0x80031718: sw          $s0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r16;
            goto L_80031740;
    }
    goto skip_35;
    // 0x80031718: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    skip_35:
    // 0x8003171C: lh          $t3, 0xE4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE4);
    // 0x80031720: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80031724: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80031728: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8003172C: lw          $t5, 0x78B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78B0);
    // 0x80031730: slti        $at, $t5, 0x33
    ctx->r1 = SIGNED(ctx->r13) < 0X33 ? 1 : 0;
    // 0x80031734: beql        $at, $zero, L_80031844
    if (ctx->r1 == 0) {
        // 0x80031738: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_36;
    // 0x80031738: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_36:
    // 0x8003173C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_80031740:
    // 0x80031740: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80031744: b           L_80031840
    // 0x80031748: sw          $t6, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = ctx->r14;
        goto L_80031840;
    // 0x80031748: sw          $t6, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = ctx->r14;
L_8003174C:
    // 0x8003174C: lw          $t7, 0x78B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B8);
    // 0x80031750: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031754: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80031758: slti        $at, $t7, 0x5A
    ctx->r1 = SIGNED(ctx->r15) < 0X5A ? 1 : 0;
    // 0x8003175C: bne         $at, $zero, L_80031778
    if (ctx->r1 != 0) {
        // 0x80031760: addiu       $a0, $a0, -0x1510
        ctx->r4 = ADD32(ctx->r4, -0X1510);
            goto L_80031778;
    }
    // 0x80031760: addiu       $a0, $a0, -0x1510
    ctx->r4 = ADD32(ctx->r4, -0X1510);
    // 0x80031764: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80031768: jal         0x8002F5F4
    // 0x8003176C: addiu       $a0, $a0, -0x15CC
    ctx->r4 = ADD32(ctx->r4, -0X15CC);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_55;
    // 0x8003176C: addiu       $a0, $a0, -0x15CC
    ctx->r4 = ADD32(ctx->r4, -0X15CC);
    after_55:
    // 0x80031770: b           L_80031780
    // 0x80031774: nop

        goto L_80031780;
    // 0x80031774: nop

L_80031778:
    // 0x80031778: jal         0x800BA808
    // 0x8003177C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_56;
    // 0x8003177C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_56:
L_80031780:
    // 0x80031780: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80031784: addiu       $v0, $v0, -0x5DCC
    ctx->r2 = ADD32(ctx->r2, -0X5DCC);
    // 0x80031788: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003178C: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x80031790: beql        $t8, $zero, L_800317BC
    if (ctx->r24 == 0) {
        // 0x80031794: sw          $s0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r16;
            goto L_800317BC;
    }
    goto skip_37;
    // 0x80031794: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    skip_37:
    // 0x80031798: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    // 0x8003179C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800317A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800317A4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800317A8: lw          $t1, 0x78B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B0);
    // 0x800317AC: slti        $at, $t1, 0x33
    ctx->r1 = SIGNED(ctx->r9) < 0X33 ? 1 : 0;
    // 0x800317B0: beql        $at, $zero, L_80031844
    if (ctx->r1 == 0) {
        // 0x800317B4: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_38;
    // 0x800317B4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_38:
    // 0x800317B8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_800317BC:
    // 0x800317BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800317C0: b           L_80031840
    // 0x800317C4: sw          $t2, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = ctx->r10;
        goto L_80031840;
    // 0x800317C4: sw          $t2, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = ctx->r10;
L_800317C8:
    // 0x800317C8: lw          $t3, 0x78BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78BC);
    // 0x800317CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800317D0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800317D4: slti        $at, $t3, 0x5A
    ctx->r1 = SIGNED(ctx->r11) < 0X5A ? 1 : 0;
    // 0x800317D8: bne         $at, $zero, L_800317F4
    if (ctx->r1 != 0) {
        // 0x800317DC: addiu       $a0, $a0, -0x14EC
        ctx->r4 = ADD32(ctx->r4, -0X14EC);
            goto L_800317F4;
    }
    // 0x800317DC: addiu       $a0, $a0, -0x14EC
    ctx->r4 = ADD32(ctx->r4, -0X14EC);
    // 0x800317E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800317E4: jal         0x8002F5F4
    // 0x800317E8: addiu       $a0, $a0, -0x1578
    ctx->r4 = ADD32(ctx->r4, -0X1578);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_57;
    // 0x800317E8: addiu       $a0, $a0, -0x1578
    ctx->r4 = ADD32(ctx->r4, -0X1578);
    after_57:
    // 0x800317EC: b           L_800317FC
    // 0x800317F0: nop

        goto L_800317FC;
    // 0x800317F0: nop

L_800317F4:
    // 0x800317F4: jal         0x800BA808
    // 0x800317F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_58;
    // 0x800317F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_58:
L_800317FC:
    // 0x800317FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80031800: addiu       $v0, $v0, -0x5DCC
    ctx->r2 = ADD32(ctx->r2, -0X5DCC);
    // 0x80031804: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80031808: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8003180C: beql        $t4, $zero, L_80031838
    if (ctx->r12 == 0) {
        // 0x80031810: sw          $s0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r16;
            goto L_80031838;
    }
    goto skip_39;
    // 0x80031810: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    skip_39:
    // 0x80031814: lh          $t5, 0xE4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE4);
    // 0x80031818: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003181C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80031820: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80031824: lw          $t7, 0x78B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B0);
    // 0x80031828: slti        $at, $t7, 0x33
    ctx->r1 = SIGNED(ctx->r15) < 0X33 ? 1 : 0;
    // 0x8003182C: beql        $at, $zero, L_80031844
    if (ctx->r1 == 0) {
        // 0x80031830: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80031844;
    }
    goto skip_40;
    // 0x80031830: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_40:
    // 0x80031834: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_80031838:
    // 0x80031838: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003183C: sw          $t8, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = ctx->r24;
L_80031840:
    // 0x80031840: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80031844:
    // 0x80031844: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80031848:
    // 0x80031848: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003184C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80031850: jr          $ra
    // 0x80031854: nop

    return;
    // 0x80031854: nop

;}
RECOMP_FUNC void PlayerShot_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D854: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003D858: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003D85C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003D860: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003D864: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003D868: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003D86C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003D870: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003D874: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003D878: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D87C: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8003D880: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8003D884: beq         $v1, $zero, L_8003D990
    if (ctx->r3 == 0) {
        // 0x8003D888: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003D990;
    }
    // 0x8003D888: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8003D88C: beq         $v1, $s6, L_8003D8A4
    if (ctx->r3 == ctx->r22) {
        // 0x8003D890: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003D8A4;
    }
    // 0x8003D890: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D894: beq         $v0, $at, L_8003D988
    if (ctx->r2 == ctx->r1) {
        // 0x8003D898: nop
    
            goto L_8003D988;
    }
    // 0x8003D898: nop

    // 0x8003D89C: b           L_8003D994
    // 0x8003D8A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8003D994;
    // 0x8003D8A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003D8A4:
    // 0x8003D8A4: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x8003D8A8: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
    // 0x8003D8AC: beql        $v0, $zero, L_8003D8D8
    if (ctx->r2 == 0) {
        // 0x8003D8B0: lw          $t6, 0x58($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X58);
            goto L_8003D8D8;
    }
    goto skip_0;
    // 0x8003D8B0: lw          $t6, 0x58($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X58);
    skip_0:
    // 0x8003D8B4: beq         $v0, $s6, L_8003D8D4
    if (ctx->r2 == ctx->r22) {
        // 0x8003D8B8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8003D8D4;
    }
    // 0x8003D8B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003D8BC: beq         $v0, $at, L_8003D908
    if (ctx->r2 == ctx->r1) {
        // 0x8003D8C0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8003D908;
    }
    // 0x8003D8C0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8003D8C4: bne         $v0, $at, L_8003D90C
    if (ctx->r2 != ctx->r1) {
        // 0x8003D8C8: nop
    
            goto L_8003D90C;
    }
    // 0x8003D8C8: nop

    // 0x8003D8CC: b           L_8003D90C
    // 0x8003D8D0: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
        goto L_8003D90C;
    // 0x8003D8D0: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_8003D8D4:
    // 0x8003D8D4: lw          $t6, 0x58($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X58);
L_8003D8D8:
    // 0x8003D8D8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003D8DC: beq         $t6, $zero, L_8003D8F8
    if (ctx->r14 == 0) {
        // 0x8003D8E0: nop
    
            goto L_8003D8F8;
    }
    // 0x8003D8E0: nop

    // 0x8003D8E4: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8003D8E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D8EC: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x8003D8F0: bne         $t8, $at, L_8003D900
    if (ctx->r24 != ctx->r1) {
        // 0x8003D8F4: nop
    
            goto L_8003D900;
    }
    // 0x8003D8F4: nop

L_8003D8F8:
    // 0x8003D8F8: b           L_8003D90C
    // 0x8003D8FC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
        goto L_8003D90C;
    // 0x8003D8FC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_8003D900:
    // 0x8003D900: b           L_8003D90C
    // 0x8003D904: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
        goto L_8003D90C;
    // 0x8003D904: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_8003D908:
    // 0x8003D908: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_8003D90C:
    // 0x8003D90C: blez        $s5, L_8003D990
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8003D910: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8003D990;
    }
    // 0x8003D910: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003D914: bne         $s6, $v1, L_8003D990
    if (ctx->r22 != ctx->r3) {
        // 0x8003D918: lui         $s4, 0x8018
        ctx->r20 = S32(0X8018 << 16);
            goto L_8003D990;
    }
    // 0x8003D918: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x8003D91C: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x8003D920: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8003D924: addiu       $s2, $s2, -0x7B68
    ctx->r18 = ADD32(ctx->r18, -0X7B68);
    // 0x8003D928: addiu       $s3, $s3, -0x7B60
    ctx->r19 = ADD32(ctx->r19, -0X7B60);
    // 0x8003D92C: addiu       $s4, $s4, -0x7B64
    ctx->r20 = ADD32(ctx->r20, -0X7B64);
    // 0x8003D930: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
L_8003D934:
    // 0x8003D934: blez        $v0, L_8003D940
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D938: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8003D940;
    }
    // 0x8003D938: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8003D93C: sw          $t9, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r25;
L_8003D940:
    // 0x8003D940: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003D944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003D948: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003D94C: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8003D950: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003D954: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    // 0x8003D958: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003D95C: jal         0x8003D54C
    // 0x8003D960: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    PlayerShot_UpdateShot(rdram, ctx);
        goto after_0;
    // 0x8003D960: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    after_0:
    // 0x8003D964: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003D968: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8003D96C: beql        $at, $zero, L_8003D994
    if (ctx->r1 == 0) {
        // 0x8003D970: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8003D994;
    }
    goto skip_1;
    // 0x8003D970: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8003D974: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x8003D978: beql        $s6, $t0, L_8003D934
    if (ctx->r22 == ctx->r8) {
        // 0x8003D97C: lw          $v0, 0x64($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X64);
            goto L_8003D934;
    }
    goto skip_2;
    // 0x8003D97C: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    skip_2:
    // 0x8003D980: b           L_8003D994
    // 0x8003D984: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8003D994;
    // 0x8003D984: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003D988:
    // 0x8003D988: jal         0x8003AFD8
    // 0x8003D98C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_UpdateHitmark(rdram, ctx);
        goto after_1;
    // 0x8003D98C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_8003D990:
    // 0x8003D990: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003D994:
    // 0x8003D994: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D998: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D99C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003D9A0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003D9A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003D9A8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D9AC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8003D9B0: jr          $ra
    // 0x8003D9B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003D9B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void AudioHeap_InitTemporaryPoolsAndCaches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C1F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C1FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C204: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C208: addiu       $a0, $a0, -0x3DD0
    ctx->r4 = ADD32(ctx->r4, -0X3DD0);
    // 0x8000C20C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000C210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C214: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8000C218: jal         0x8000BF14
    // 0x8000C21C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000C21C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8000C220: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C224: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
    // 0x8000C228: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C22C: jal         0x8000BF6C
    // 0x8000C230: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    AudioHeap_InitPool(rdram, ctx);
        goto after_1;
    // 0x8000C230: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x8000C234: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C238: addiu       $a0, $a0, -0x3DD0
    ctx->r4 = ADD32(ctx->r4, -0X3DD0);
    // 0x8000C23C: jal         0x8000BF14
    // 0x8000C240: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    AudioHeap_Alloc(rdram, ctx);
        goto after_2;
    // 0x8000C240: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x8000C244: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C248: addiu       $a0, $a0, -0x3A58
    ctx->r4 = ADD32(ctx->r4, -0X3A58);
    // 0x8000C24C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C250: jal         0x8000BF6C
    // 0x8000C254: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    AudioHeap_InitPool(rdram, ctx);
        goto after_3;
    // 0x8000C254: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x8000C258: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C25C: addiu       $a0, $a0, -0x3DD0
    ctx->r4 = ADD32(ctx->r4, -0X3DD0);
    // 0x8000C260: jal         0x8000BF14
    // 0x8000C264: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    AudioHeap_Alloc(rdram, ctx);
        goto after_4;
    // 0x8000C264: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_4:
    // 0x8000C268: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C26C: addiu       $a0, $a0, -0x3888
    ctx->r4 = ADD32(ctx->r4, -0X3888);
    // 0x8000C270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C274: jal         0x8000BF6C
    // 0x8000C278: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    AudioHeap_InitPool(rdram, ctx);
        goto after_5;
    // 0x8000C278: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_5:
    // 0x8000C27C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C280: jal         0x8000BFA8
    // 0x8000C284: addiu       $a0, $a0, -0x3C2C
    ctx->r4 = ADD32(ctx->r4, -0X3C2C);
    AudioHeap_InitTemporaryCache(rdram, ctx);
        goto after_6;
    // 0x8000C284: addiu       $a0, $a0, -0x3C2C
    ctx->r4 = ADD32(ctx->r4, -0X3C2C);
    after_6:
    // 0x8000C288: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C28C: jal         0x8000BFA8
    // 0x8000C290: addiu       $a0, $a0, -0x3A5C
    ctx->r4 = ADD32(ctx->r4, -0X3A5C);
    AudioHeap_InitTemporaryCache(rdram, ctx);
        goto after_7;
    // 0x8000C290: addiu       $a0, $a0, -0x3A5C
    ctx->r4 = ADD32(ctx->r4, -0X3A5C);
    after_7:
    // 0x8000C294: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C298: jal         0x8000BFA8
    // 0x8000C29C: addiu       $a0, $a0, -0x388C
    ctx->r4 = ADD32(ctx->r4, -0X388C);
    AudioHeap_InitTemporaryCache(rdram, ctx);
        goto after_8;
    // 0x8000C29C: addiu       $a0, $a0, -0x388C
    ctx->r4 = ADD32(ctx->r4, -0X388C);
    after_8:
    // 0x8000C2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C2A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C2A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C2AC: jr          $ra
    // 0x8000C2B0: nop

    return;
    // 0x8000C2B0: nop

;}
RECOMP_FUNC void Versus_ReturnToMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1708: jal         0x800BC760
    // 0x800C170C: nop

    Versus_Exit(rdram, ctx);
        goto after_0;
    // 0x800C170C: nop

    after_0:
    // 0x800C1710: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800C1714: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C1718: sw          $t6, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r14;
    // 0x800C171C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C1720: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800C1724: sw          $t7, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r15;
    // 0x800C1728: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C172C: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x800C1730: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C1734: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C1738: sw          $t8, 0x2870($at)
    MEM_W(0X2870, ctx->r1) = ctx->r24;
    // 0x800C173C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1740: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x800C1744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C174C: jr          $ra
    // 0x800C1750: nop

    return;
    // 0x800C1750: nop

;}
RECOMP_FUNC void Effect_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007783C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077844: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80077848: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8007784C: addiu       $a2, $a2, 0x130
    ctx->r6 = ADD32(ctx->r6, 0X130);
    // 0x80077850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80077854: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
L_80077858:
    // 0x80077858: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8007785C: bne         $t6, $zero, L_800778A0
    if (ctx->r14 != 0) {
        // 0x80077860: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800778A0;
    }
    // 0x80077860: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80077864: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80077868: jal         0x80061474
    // 0x8007786C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007786C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80077870: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80077874: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80077878: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x8007787C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80077880: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80077884: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80077888: jal         0x800612B8
    // 0x8007788C: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007788C: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    after_1:
    // 0x80077890: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80077894: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x80077898: b           L_800778AC
    // 0x8007789C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_800778AC;
    // 0x8007789C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800778A0:
    // 0x800778A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800778A4: bne         $v0, $v1, L_80077858
    if (ctx->r2 != ctx->r3) {
        // 0x800778A8: addiu       $a2, $a2, 0x8C
        ctx->r6 = ADD32(ctx->r6, 0X8C);
            goto L_80077858;
    }
    // 0x800778A8: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
L_800778AC:
    // 0x800778AC: bne         $v0, $v1, L_800778B8
    if (ctx->r2 != ctx->r3) {
        // 0x800778B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800778B8;
    }
    // 0x800778B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800778B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800778B8:
    // 0x800778B8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800778BC: jr          $ra
    // 0x800778C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800778C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Effect_SetupByIdSimple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EBB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007EBBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007EBC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007EBC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007EBC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007EBCC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007EBD0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007EBD4: jal         0x80061474
    // 0x8007EBD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007EBD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007EBDC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EBE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007EBE4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007EBE8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8007EBEC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007EBF0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8007EBF4: addiu       $at, $zero, 0x163
    ctx->r1 = ADD32(0, 0X163);
    // 0x8007EBF8: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007EBFC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007EC00: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007EC04: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8007EC08: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007EC0C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007EC10: sh          $t7, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r15;
    // 0x8007EC14: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8007EC18: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007EC1C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007EC20: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8007EC24: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8007EC28: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x8007EC2C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007EC30: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007EC34: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8007EC38: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8007EC3C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007EC40: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8007EC44: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007EC48: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x8007EC4C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007EC50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007EC54: bne         $v0, $at, L_8007EC88
    if (ctx->r2 != ctx->r1) {
        // 0x8007EC58: swc1        $f4, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
            goto L_8007EC88;
    }
    // 0x8007EC58: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x8007EC5C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007EC60: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007EC64: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8007EC68: ori         $a0, $a0, 0x25
    ctx->r4 = ctx->r4 | 0X25;
    // 0x8007EC6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007EC70: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007EC74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007EC78: jal         0x80019218
    // 0x8007EC7C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8007EC7C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x8007EC80: b           L_8007EC98
    // 0x8007EC84: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
        goto L_8007EC98;
    // 0x8007EC84: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
L_8007EC88:
    // 0x8007EC88: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007EC8C: jal         0x80019218
    // 0x8007EC90: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8007EC90: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_2:
    // 0x8007EC94: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
L_8007EC98:
    // 0x8007EC98: jal         0x800612B8
    // 0x8007EC9C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8007EC9C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_3:
    // 0x8007ECA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007ECA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007ECA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007ECAC: jr          $ra
    // 0x8007ECB0: nop

    return;
    // 0x8007ECB0: nop

;}
