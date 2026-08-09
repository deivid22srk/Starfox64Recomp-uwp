#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AudioLoad_AsyncDma(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010EFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80010F00: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80010F04: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80010F08: addiu       $s1, $a1, 0xF
    ctx->r17 = ADD32(ctx->r5, 0XF);
    // 0x80010F0C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80010F10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80010F14: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80010F18: and         $a1, $s1, $at
    ctx->r5 = ctx->r17 & ctx->r1;
    // 0x80010F1C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80010F20: jal         0x80021740
    // 0x80010F24: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80010F24: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    after_0:
    // 0x80010F28: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80010F2C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80010F30: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x80010F34: jal         0x80021CF0
    // 0x80010F38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80010F38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80010F3C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80010F40: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80010F44: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80010F48: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80010F4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80010F50: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80010F54: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x80010F58: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80010F5C: addiu       $t0, $t0, 0x53AC
    ctx->r8 = ADD32(ctx->r8, 0X53AC);
    // 0x80010F60: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80010F64: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80010F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80010F70: jal         0x8000FBA8
    // 0x80010F74: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    AudioLoad_Dma(rdram, ctx);
        goto after_2;
    // 0x80010F74: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_2:
    // 0x80010F78: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010F7C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80010F80: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80010F84: jr          $ra
    // 0x80010F88: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80010F88: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Display_CockpitGlass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053B18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80053B1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053B20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053B24: jal         0x80005708
    // 0x80053B28: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80053B28: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80053B2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053B30: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80053B34: addiu       $a1, $a1, 0x1418
    ctx->r5 = ADD32(ctx->r5, 0X1418);
    // 0x80053B38: jal         0x80005680
    // 0x80053B3C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_1;
    // 0x80053B3C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x80053B40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053B44: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80053B48: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80053B4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80053B50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80053B54: lw          $a3, -0x5D6C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5D6C);
    // 0x80053B58: lw          $a2, -0x5D70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5D70);
    // 0x80053B5C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053B60: jal         0x80005B00
    // 0x80053B64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80053B64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80053B68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053B6C: lwc1        $f0, -0x5D74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5D74);
    // 0x80053B70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053B74: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80053B78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80053B7C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80053B80: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80053B84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80053B88: jal         0x80005C34
    // 0x80053B8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80053B8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x80053B90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053B94: jal         0x80006EB8
    // 0x80053B98: addiu       $a0, $a1, 0x7E64
    ctx->r4 = ADD32(ctx->r5, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80053B98: addiu       $a0, $a1, 0x7E64
    ctx->r4 = ADD32(ctx->r5, 0X7E64);
    after_4:
    // 0x80053B9C: jal         0x800BA170
    // 0x80053BA0: nop

    RCP_SetupDL_64_2(rdram, ctx);
        goto after_5;
    // 0x80053BA0: nop

    after_5:
    // 0x80053BA4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053BA8: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80053BAC: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x80053BB0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053BB4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80053BB8: addiu       $t2, $zero, -0x88
    ctx->r10 = ADD32(0, -0X88);
    // 0x80053BBC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80053BC0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80053BC4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80053BC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80053BCC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053BD0: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x80053BD4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80053BD8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80053BDC: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80053BE0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80053BE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80053BE8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053BEC: lui         $t7, 0x302
    ctx->r15 = S32(0X302 << 16);
    // 0x80053BF0: addiu       $t7, $t7, -0x6B20
    ctx->r15 = ADD32(ctx->r15, -0X6B20);
    // 0x80053BF4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80053BF8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80053BFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80053C00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80053C04: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053C08: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x80053C0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053C10: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80053C14: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80053C18: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80053C1C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80053C20: jal         0x80005740
    // 0x80053C24: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x80053C24: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x80053C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80053C30: jr          $ra
    // 0x80053C34: nop

    return;
    // 0x80053C34: nop

;}
RECOMP_FUNC void Versus_UpdateMenuOptions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0A04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C0A08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0A0C: jal         0x800C07C4
    // 0x800C0A10: nop

    Versus_GetMenuInput(rdram, ctx);
        goto after_0;
    // 0x800C0A10: nop

    after_0:
    // 0x800C0A14: beq         $v0, $zero, L_800C0A80
    if (ctx->r2 == 0) {
        // 0x800C0A18: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C0A80;
    }
    // 0x800C0A18: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C0A1C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0A20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C0A24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0A28: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800C0A2C: swc1        $f4, -0x7854($at)
    MEM_W(-0X7854, ctx->r1) = ctx->f4.u32l;
    // 0x800C0A30: addiu       $t1, $t1, -0x785C
    ctx->r9 = ADD32(ctx->r9, -0X785C);
    // 0x800C0A34: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0A38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C0A3C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800C0A40: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C0A44: addiu       $t0, $t0, -0x7850
    ctx->r8 = ADD32(ctx->r8, -0X7850);
    // 0x800C0A48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0A4C: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x800C0A50: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0A54: sw          $t7, -0x785C($at)
    MEM_W(-0X785C, ctx->r1) = ctx->r15;
    // 0x800C0A58: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800C0A5C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800C0A60: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800C0A64: bne         $at, $zero, L_800C0A74
    if (ctx->r1 != 0) {
        // 0x800C0A68: nop
    
            goto L_800C0A74;
    }
    // 0x800C0A68: nop

    // 0x800C0A6C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800C0A70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C0A74:
    // 0x800C0A74: bgezl       $v1, L_800C0A84
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800C0A78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800C0A84;
    }
    goto skip_0;
    // 0x800C0A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x800C0A7C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_800C0A80:
    // 0x800C0A80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800C0A84:
    // 0x800C0A84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C0A88: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C0A8C: addiu       $t0, $t0, -0x7850
    ctx->r8 = ADD32(ctx->r8, -0X7850);
    // 0x800C0A90: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C0A94: addiu       $a0, $a0, -0x7854
    ctx->r4 = ADD32(ctx->r4, -0X7854);
    // 0x800C0A98: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800C0A9C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800C0AA0: jal         0x8009BC2C
    // 0x800C0AA4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800C0AA4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800C0AA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C0AAC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C0AB0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800C0AB4: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x800C0AB8: addiu       $t1, $t1, -0x785C
    ctx->r9 = ADD32(ctx->r9, -0X785C);
    // 0x800C0ABC: addiu       $t0, $t0, -0x7850
    ctx->r8 = ADD32(ctx->r8, -0X7850);
    // 0x800C0AC0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800C0AC4: bc1fl       L_800C0AFC
    if (!c1cs) {
        // 0x800C0AC8: lw          $v0, 0x0($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X0);
            goto L_800C0AFC;
    }
    goto skip_1;
    // 0x800C0AC8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    skip_1:
    // 0x800C0ACC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C0AD0: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C0AD4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0AD8: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C0ADC: nop

    // 0x800C0AE0: bc1fl       L_800C0AF8
    if (!c1cs) {
        // 0x800C0AE4: swc1        $f0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
            goto L_800C0AF8;
    }
    goto skip_2;
    // 0x800C0AE4: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    skip_2:
    // 0x800C0AE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0AEC: b           L_800C0AF8
    // 0x800C0AF0: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
        goto L_800C0AF8;
    // 0x800C0AF0: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x800C0AF4: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
L_800C0AF8:
    // 0x800C0AF8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
L_800C0AFC:
    // 0x800C0AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0B00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C0B04: jr          $ra
    // 0x800C0B08: nop

    return;
    // 0x800C0B08: nop

;}
RECOMP_FUNC void Item_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E7B8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005E7BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005E7C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E7C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E7C8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8005E7CC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005E7D0: addiu       $t7, $t7, -0x2E4
    ctx->r15 = ADD32(ctx->r15, -0X2E4);
    // 0x8005E7D4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005E7D8: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x8005E7DC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8005E7E0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005E7E4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005E7E8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8005E7EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E7F0: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8005E7F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E7F8: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005E7FC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E800: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005E804: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005E808: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005E80C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005E810: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005E814: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E818: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8005E81C: jal         0x80005B00
    // 0x8005E820: nop

    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005E820: nop

    after_0:
    // 0x8005E824: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E828: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E82C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8005E830: jal         0x80006970
    // 0x8005E834: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x8005E834: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x8005E838: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005E83C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005E840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E844: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E848: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8005E84C: nop

    // 0x8005E850: bc1fl       L_8005E99C
    if (!c1cs) {
        // 0x8005E854: addiu       $a2, $s0, 0x5C
        ctx->r6 = ADD32(ctx->r16, 0X5C);
            goto L_8005E99C;
    }
    goto skip_0;
    // 0x8005E854: addiu       $a2, $s0, 0x5C
    ctx->r6 = ADD32(ctx->r16, 0X5C);
    skip_0:
    // 0x8005E858: lwc1        $f18, 0x634C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X634C);
    // 0x8005E85C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8005E860: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8005E864: nop

    // 0x8005E868: bc1fl       L_8005E99C
    if (!c1cs) {
        // 0x8005E86C: addiu       $a2, $s0, 0x5C
        ctx->r6 = ADD32(ctx->r16, 0X5C);
            goto L_8005E99C;
    }
    goto skip_1;
    // 0x8005E86C: addiu       $a2, $s0, 0x5C
    ctx->r6 = ADD32(ctx->r16, 0X5C);
    skip_1:
    // 0x8005E870: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005E874: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005E878: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005E87C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005E880: mul.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8005E884: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005E888: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005E88C: abs.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = fabsf(ctx->f12.fl);
    // 0x8005E890: add.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005E894: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8005E898: nop

    // 0x8005E89C: bc1fl       L_8005E99C
    if (!c1cs) {
        // 0x8005E8A0: addiu       $a2, $s0, 0x5C
        ctx->r6 = ADD32(ctx->r16, 0X5C);
            goto L_8005E99C;
    }
    goto skip_2;
    // 0x8005E8A0: addiu       $a2, $s0, 0x5C
    ctx->r6 = ADD32(ctx->r16, 0X5C);
    skip_2:
    // 0x8005E8A4: add.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005E8A8: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005E8AC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8005E8B0: nop

    // 0x8005E8B4: bc1fl       L_8005E99C
    if (!c1cs) {
        // 0x8005E8B8: addiu       $a2, $s0, 0x5C
        ctx->r6 = ADD32(ctx->r16, 0X5C);
            goto L_8005E99C;
    }
    goto skip_3;
    // 0x8005E8B8: addiu       $a2, $s0, 0x5C
    ctx->r6 = ADD32(ctx->r16, 0X5C);
    skip_3:
    // 0x8005E8BC: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
    // 0x8005E8C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E8C4: beql        $t2, $zero, L_8005E998
    if (ctx->r10 == 0) {
        // 0x8005E8C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005E998;
    }
    goto skip_4;
    // 0x8005E8C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8005E8CC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005E8D0: lwc1        $f18, 0x6350($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6350);
    // 0x8005E8D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E8D8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E8DC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8005E8E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E8E4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005E8E8: jal         0x80005E90
    // 0x8005E8EC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8005E8EC: nop

    after_2:
    // 0x8005E8F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E8F4: lwc1        $f8, 0x6354($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6354);
    // 0x8005E8F8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005E8FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E900: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E904: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005E908: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E90C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005E910: jal         0x80005D44
    // 0x8005E914: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x8005E914: nop

    after_3:
    // 0x8005E918: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E91C: lwc1        $f4, 0x6358($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6358);
    // 0x8005E920: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005E924: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E928: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E92C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005E930: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E934: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005E938: jal         0x80005FE0
    // 0x8005E93C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x8005E93C: nop

    after_4:
    // 0x8005E940: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005E944: jal         0x80006EB8
    // 0x8005E948: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x8005E948: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_5:
    // 0x8005E94C: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8005E950: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005E954: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005E958: bnel        $t3, $zero, L_8005E988
    if (ctx->r11 != 0) {
        // 0x8005E95C: lw          $t9, 0x1C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1C);
            goto L_8005E988;
    }
    goto skip_5;
    // 0x8005E95C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    skip_5:
    // 0x8005E960: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005E964: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005E968: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8005E96C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005E970: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8005E974: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8005E978: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005E97C: b           L_8005E998
    // 0x8005E980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E998;
    // 0x8005E980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E984: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
L_8005E988:
    // 0x8005E988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E98C: jalr        $t9
    // 0x8005E990: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8005E990: nop

    after_6:
    // 0x8005E994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E998:
    // 0x8005E998: addiu       $a2, $s0, 0x5C
    ctx->r6 = ADD32(ctx->r16, 0X5C);
L_8005E99C:
    // 0x8005E99C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005E9A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005E9A4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8005E9A8: jal         0x8005F290
    // 0x8005E9AC: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    Object_SetSfxSourceToView(rdram, ctx);
        goto after_7;
    // 0x8005E9AC: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    after_7:
    // 0x8005E9B0: lbu         $v0, 0x37($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X37);
    // 0x8005E9B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8005E9B8: bne         $v0, $zero, L_8005EA10
    if (ctx->r2 != 0) {
        // 0x8005E9BC: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8005EA10;
    }
    // 0x8005E9BC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8005E9C0: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x8005E9C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E9C8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005E9CC: bnel        $v0, $t8, L_8005EA14
    if (ctx->r2 != ctx->r24) {
        // 0x8005E9D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005EA14;
    }
    goto skip_6;
    // 0x8005E9D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8005E9D4: lw          $t6, 0x78A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A8);
    // 0x8005E9D8: bnel        $v0, $t6, L_8005EA14
    if (ctx->r2 != ctx->r14) {
        // 0x8005E9DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005EA14;
    }
    goto skip_7;
    // 0x8005E9DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x8005E9E0: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8005E9E4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E9E8: slti        $at, $t7, 0x150
    ctx->r1 = SIGNED(ctx->r15) < 0X150 ? 1 : 0;
    // 0x8005E9EC: beql        $at, $zero, L_8005EA14
    if (ctx->r1 == 0) {
        // 0x8005E9F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005EA14;
    }
    goto skip_8;
    // 0x8005E9F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x8005E9F4: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8005E9F8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005E9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005EA00: beql        $t0, $at, L_8005EA14
    if (ctx->r8 == ctx->r1) {
        // 0x8005EA04: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005EA14;
    }
    goto skip_9;
    // 0x8005EA04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x8005EA08: jal         0x80060FBC
    // 0x8005EA0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    Object_Kill(rdram, ctx);
        goto after_8;
    // 0x8005EA0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_8:
L_8005EA10:
    // 0x8005EA10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005EA14:
    // 0x8005EA14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005EA18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8005EA1C: jr          $ra
    // 0x8005EA20: nop

    return;
    // 0x8005EA20: nop

;}
RECOMP_FUNC void Audio_ResetSfxChannelState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017588: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001758C: lbu         $t6, 0x5D54($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5D54);
    // 0x80017590: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80017594: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80017598: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001759C: lb          $t7, 0x5E38($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X5E38);
    // 0x800175A0: sb          $zero, 0x5D60($at)
    MEM_B(0X5D60, ctx->r1) = 0;
    // 0x800175A4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800175A8: sb          $t7, 0x5D64($at)
    MEM_B(0X5D64, ctx->r1) = ctx->r15;
    // 0x800175AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800175B0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800175B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800175B8: addiu       $a0, $a0, -0x4870
    ctx->r4 = ADD32(ctx->r4, -0X4870);
    // 0x800175BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800175C0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800175C4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_800175C8:
    // 0x800175C8: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800175CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800175D0: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x800175D4: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800175D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800175DC: mflo        $t8
    ctx->r24 = lo;
    // 0x800175E0: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x800175E4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800175E8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800175EC: sb          $zero, 0x8($v1)
    MEM_B(0X8, ctx->r3) = 0;
    // 0x800175F0: bne         $at, $zero, L_800175C8
    if (ctx->r1 != 0) {
        // 0x800175F4: sb          $a2, 0x9($v1)
        MEM_B(0X9, ctx->r3) = ctx->r6;
            goto L_800175C8;
    }
    // 0x800175F4: sb          $a2, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r6;
    // 0x800175F8: jr          $ra
    // 0x800175FC: nop

    return;
    // 0x800175FC: nop

;}
RECOMP_FUNC void Message_DisplayChar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C295C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C2960: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800C2964: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C2968: sra         $t9, $a1, 2
    ctx->r25 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800C296C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2970: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800C2974: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x800C2978: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C297C: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x800C2980: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800C2984: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800C2988: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C298C: addiu       $t5, $t5, -0x6FF0
    ctx->r13 = ADD32(ctx->r13, -0X6FF0);
    // 0x800C2990: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800C2994: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C2998: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x800C299C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C29A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C29A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C29A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C29AC: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x800C29B0: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x800C29B4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800C29B8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C29BC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C29C0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C29C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C29C8: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800C29CC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800C29D0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C29D4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800C29D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C29DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C29E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C29E4: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x800C29E8: ori         $t8, $t8, 0x3800
    ctx->r24 = ctx->r24 | 0X3800;
    // 0x800C29EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C29F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C29F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C29F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C29FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2A00: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800C2A04: lui         $t6, 0xF540
    ctx->r14 = S32(0XF540 << 16);
    // 0x800C2A08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C2A0C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2A10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C2A14: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C2A18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2A1C: andi        $t8, $v1, 0x3
    ctx->r24 = ctx->r3 & 0X3;
    // 0x800C2A20: sll         $t9, $t8, 20
    ctx->r25 = S32(ctx->r24 << 20);
    // 0x800C2A24: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800C2A28: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800C2A2C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800C2A30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C2A34: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C2A38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2A3C: lui         $t6, 0x3
    ctx->r14 = S32(0X3 << 16);
    // 0x800C2A40: ori         $t6, $t6, 0xC030
    ctx->r14 = ctx->r14 | 0XC030;
    // 0x800C2A44: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C2A48: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800C2A4C: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x800C2A50: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C2A54: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C2A58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2A5C: addiu       $t8, $a2, 0xD
    ctx->r24 = ADD32(ctx->r6, 0XD);
    // 0x800C2A60: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C2A64: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800C2A68: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C2A6C: addiu       $t7, $a3, 0xD
    ctx->r15 = ADD32(ctx->r7, 0XD);
    // 0x800C2A70: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x800C2A74: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x800C2A78: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C2A7C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800C2A80: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800C2A84: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800C2A88: or          $t4, $t6, $t9
    ctx->r12 = ctx->r14 | ctx->r25;
    // 0x800C2A8C: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x800C2A90: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x800C2A94: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800C2A98: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800C2A9C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C2AA0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C2AA4: or          $t4, $t8, $t9
    ctx->r12 = ctx->r24 | ctx->r25;
    // 0x800C2AA8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C2AAC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2AB0: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x800C2AB4: lui         $t6, 0x40
    ctx->r14 = S32(0X40 << 16);
    // 0x800C2AB8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800C2ABC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800C2AC0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C2AC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C2AC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2ACC: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x800C2AD0: ori         $t4, $t4, 0x400
    ctx->r12 = ctx->r12 | 0X400;
    // 0x800C2AD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800C2AD8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C2ADC: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x800C2AE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800C2AE4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C2AE8: jr          $ra
    // 0x800C2AEC: nop

    return;
    // 0x800C2AEC: nop

;}
RECOMP_FUNC void BoBaseShield_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E64C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E654: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E658: jal         0x80187520
    // 0x8002E65C: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E65C: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_0:
    // 0x8002E660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E668: jr          $ra
    // 0x8002E66C: nop

    return;
    // 0x8002E66C: nop

;}
RECOMP_FUNC void Audio_AllocNoteFromDisabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012E90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80012E94: jal         0x800145FC
    // 0x80012E98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    AudioSeq_AudioListPopBack(rdram, ctx);
        goto after_0;
    // 0x80012E98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80012E9C: beq         $v0, $zero, L_80012EC0
    if (ctx->r2 == 0) {
        // 0x80012EA0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80012EC0;
    }
    // 0x80012EA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80012EA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80012EA8: jal         0x80012CEC
    // 0x80012EAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    Audio_NoteInitForLayer(rdram, ctx);
        goto after_1;
    // 0x80012EAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80012EB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80012EB4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80012EB8: jal         0x80012C00
    // 0x80012EBC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    Audio_AudioListPushFront(rdram, ctx);
        goto after_2;
    // 0x80012EBC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_2:
L_80012EC0:
    // 0x80012EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012EC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80012EC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012ECC: jr          $ra
    // 0x80012ED0: nop

    return;
    // 0x80012ED0: nop

;}
RECOMP_FUNC void guOrthoF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021508: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002150C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80021510: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80021514: jal         0x80026DD0
    // 0x80021518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80021518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002151C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80021520: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80021524: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80021528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002152C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80021530: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80021534: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80021538: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002153C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80021540: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80021544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021548: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8002154C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80021550: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80021554: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80021558: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002155C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80021560: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021564: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80021568: sub.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8002156C: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80021570: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80021574: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x80021578: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x8002157C: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80021580: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80021584: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80021588: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002158C: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80021590: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x80021594: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80021598: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8002159C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800215A0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800215A4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800215A8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800215AC: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800215B0: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x800215B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800215B8: nop

    // 0x800215BC: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800215C0: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800215C4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800215C8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800215CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800215D0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800215D4: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800215D8: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800215DC: beq         $v1, $a0, L_80021620
    if (ctx->r3 == ctx->r4) {
        // 0x800215E0: lwc1        $f16, 0xC($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80021620;
    }
    // 0x800215E0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
L_800215E4:
    // 0x800215E4: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800215E8: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800215EC: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800215F0: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800215F4: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800215F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800215FC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80021600: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80021604: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80021608: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8002160C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80021610: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80021614: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80021618: bne         $v1, $a0, L_800215E4
    if (ctx->r3 != ctx->r4) {
        // 0x8002161C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_800215E4;
    }
    // 0x8002161C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
L_80021620:
    // 0x80021620: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80021624: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80021628: swc1        $f12, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
    // 0x8002162C: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80021630: nop

    // 0x80021634: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80021638: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8002163C: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80021640: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80021644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002164C: jr          $ra
    // 0x80021650: nop

    return;
    // 0x80021650: nop

;}
RECOMP_FUNC void Audio_UpdateArwingNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B014: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8001B018: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x8001B01C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8001B020: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001B024: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8001B028: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001B02C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001B030: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x8001B034: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8001B038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B03C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001B040: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8001B044: lbu         $t7, 0x484($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X484);
    // 0x8001B048: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x8001B04C: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x8001B050: beq         $t7, $zero, L_8001B0A8
    if (ctx->r15 == 0) {
        // 0x8001B054: sll         $t4, $t4, 4
        ctx->r12 = S32(ctx->r12 << 4);
            goto L_8001B0A8;
    }
    // 0x8001B054: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8001B058: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x8001B05C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8001B060: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001B064: addiu       $t9, $t9, -0x47B0
    ctx->r25 = ADD32(ctx->r25, -0X47B0);
    // 0x8001B068: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8001B06C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001B070: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B074: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B078: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001B07C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8001B080: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B084: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8001B088: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B08C: addiu       $t3, $zero, 0x12
    ctx->r11 = ADD32(0, 0X12);
    // 0x8001B090: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8001B094: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001B098: sb          $t2, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r10;
    // 0x8001B09C: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x8001B0A0: b           L_8001B0CC
    // 0x8001B0A4: swc1        $f10, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f10.u32l;
        goto L_8001B0CC;
    // 0x8001B0A4: swc1        $f10, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f10.u32l;
L_8001B0A8:
    // 0x8001B0A8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001B0AC: addiu       $t5, $t5, -0x47B0
    ctx->r13 = ADD32(ctx->r13, -0X47B0);
    // 0x8001B0B0: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x8001B0B4: lbu         $t6, 0x10($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X10);
    // 0x8001B0B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B0BC: beql        $t6, $zero, L_8001B0D0
    if (ctx->r14 == 0) {
        // 0x8001B0C0: lbu         $t7, 0x485($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X485);
            goto L_8001B0D0;
    }
    goto skip_0;
    // 0x8001B0C0: lbu         $t7, 0x485($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X485);
    skip_0:
    // 0x8001B0C4: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    // 0x8001B0C8: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
L_8001B0CC:
    // 0x8001B0CC: lbu         $t7, 0x485($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X485);
L_8001B0D0:
    // 0x8001B0D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B0D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B0D8: beql        $t7, $zero, L_8001B114
    if (ctx->r15 == 0) {
        // 0x8001B0DC: lbu         $t8, 0x11($t0)
        ctx->r24 = MEM_BU(ctx->r8, 0X11);
            goto L_8001B114;
    }
    goto skip_1;
    // 0x8001B0DC: lbu         $t8, 0x11($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X11);
    skip_1:
    // 0x8001B0E0: lwc1        $f0, -0x6F4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F4C);
    // 0x8001B0E4: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001B0E8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8001B0EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B0F0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8001B0F4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8001B0F8: sw          $t1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r9;
    // 0x8001B0FC: sb          $t2, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r10;
    // 0x8001B100: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001B104: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x8001B108: b           L_8001B124
    // 0x8001B10C: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
        goto L_8001B124;
    // 0x8001B10C: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
    // 0x8001B110: lbu         $t8, 0x11($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X11);
L_8001B114:
    // 0x8001B114: beql        $t8, $zero, L_8001B128
    if (ctx->r24 == 0) {
        // 0x8001B118: lbu         $t9, 0x48C($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X48C);
            goto L_8001B128;
    }
    goto skip_2;
    // 0x8001B118: lbu         $t9, 0x48C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X48C);
    skip_2:
    // 0x8001B11C: sb          $zero, 0x11($t0)
    MEM_B(0X11, ctx->r8) = 0;
    // 0x8001B120: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
L_8001B124:
    // 0x8001B124: lbu         $t9, 0x48C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X48C);
L_8001B128:
    // 0x8001B128: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8001B12C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8001B130: beq         $t9, $zero, L_8001B17C
    if (ctx->r25 == 0) {
        // 0x8001B134: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8001B17C;
    }
    // 0x8001B134: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001B138: lwc1        $f8, 0x490($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X490);
    // 0x8001B13C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001B140: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8001B144: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8001B148: nop

    // 0x8001B14C: bc1fl       L_8001B180
    if (!c1cs) {
        // 0x8001B150: lbu         $t4, 0x494($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X494);
            goto L_8001B180;
    }
    goto skip_3;
    // 0x8001B150: lbu         $t4, 0x494($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X494);
    skip_3:
    // 0x8001B154: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B158: lwc1        $f16, 0x28($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8001B15C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8001B160: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B164: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8001B168: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8001B16C: sw          $t3, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r11;
    // 0x8001B170: swc1        $f12, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f12.u32l;
    // 0x8001B174: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001B178: swc1        $f6, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f6.u32l;
L_8001B17C:
    // 0x8001B17C: lbu         $t4, 0x494($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X494);
L_8001B180:
    // 0x8001B180: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8001B184: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B188: beq         $t4, $zero, L_8001B210
    if (ctx->r12 == 0) {
        // 0x8001B18C: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8001B210;
    }
    // 0x8001B18C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001B190: lw          $a1, 0x47C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X47C);
    // 0x8001B194: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8001B198: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8001B19C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8001B1A0: ori         $a0, $a0, 0x12
    ctx->r4 = ctx->r4 | 0X12;
    // 0x8001B1A4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001B1A8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8001B1AC: sb          $a2, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r6;
    // 0x8001B1B0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8001B1B4: jal         0x80019218
    // 0x8001B1B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001B1B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001B1BC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001B1C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B1C4: lwc1        $f0, -0x6F48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F48);
    // 0x8001B1C8: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8001B1CC: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8001B1D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B1D4: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001B1D8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001B1DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001B1E0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8001B1E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001B1E8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001B1EC: sw          $t6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r14;
    // 0x8001B1F0: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x8001B1F4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8001B1F8: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x8001B1FC: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8001B200: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B204: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x8001B208: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8001B20C: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
L_8001B210:
    // 0x8001B210: lwc1        $f0, 0x488($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X488);
    // 0x8001B214: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001B218: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001B21C: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x8001B220: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8001B224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B228: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x8001B22C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8001B230: bc1f        L_8001B240
    if (!c1cs) {
        // 0x8001B234: lui         $t6, 0x8015
        ctx->r14 = S32(0X8015 << 16);
            goto L_8001B240;
    }
    // 0x8001B234: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001B238: b           L_8001B244
    // 0x8001B23C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8001B244;
    // 0x8001B23C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8001B240:
    // 0x8001B240: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8001B244:
    // 0x8001B244: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8001B248: addiu       $t6, $t6, -0x47B0
    ctx->r14 = ADD32(ctx->r14, -0X47B0);
    // 0x8001B24C: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8001B250: addiu       $a2, $a2, 0x5E58
    ctx->r6 = ADD32(ctx->r6, 0X5E58);
    // 0x8001B254: bc1f        L_8001B288
    if (!c1cs) {
        // 0x8001B258: addu        $a1, $t5, $t6
        ctx->r5 = ADD32(ctx->r13, ctx->r14);
            goto L_8001B288;
    }
    // 0x8001B258: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8001B25C: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x8001B260: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8001B264: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001B268: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8001B26C: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8001B270: swc1        $f12, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f12.u32l;
    // 0x8001B274: sw          $t8, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r24;
    // 0x8001B278: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001B27C: sb          $t2, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r10;
    // 0x8001B280: b           L_8001B29C
    // 0x8001B284: swc1        $f18, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f18.u32l;
        goto L_8001B29C;
    // 0x8001B284: swc1        $f18, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f18.u32l;
L_8001B288:
    // 0x8001B288: lbu         $t9, 0x4C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X4C);
    // 0x8001B28C: beql        $t9, $zero, L_8001B2A0
    if (ctx->r25 == 0) {
        // 0x8001B290: lw          $t3, 0x58($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X58);
            goto L_8001B2A0;
    }
    goto skip_4;
    // 0x8001B290: lw          $t3, 0x58($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X58);
    skip_4:
    // 0x8001B294: sb          $zero, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = 0;
    // 0x8001B298: sw          $t2, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r10;
L_8001B29C:
    // 0x8001B29C: lw          $t3, 0x58($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X58);
L_8001B2A0:
    // 0x8001B2A0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001B2A4: bnel        $t3, $zero, L_8001B348
    if (ctx->r11 != 0) {
        // 0x8001B2A8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001B348;
    }
    goto skip_5;
    // 0x8001B2A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_5:
    // 0x8001B2AC: lw          $v0, 0x5D84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5D84);
    // 0x8001B2B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B2B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001B2B8: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x8001B2BC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8001B2C0: ldc1        $f2, -0x6F40($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X6F40);
    // 0x8001B2C4: bgez        $t4, L_8001B2DC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8001B2C8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001B2DC;
    }
    // 0x8001B2C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001B2CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001B2D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B2D4: nop

    // 0x8001B2D8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001B2DC:
    // 0x8001B2DC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8001B2E0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8001B2E4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8001B2E8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001B2EC: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8001B2F0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001B2F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001B2F8: srl         $v1, $v0, 27
    ctx->r3 = S32(U32(ctx->r2) >> 27);
    // 0x8001B2FC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001B300: lwc1        $f16, 0x3C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x8001B304: sw          $v1, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r3;
    // 0x8001B308: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001B30C: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8001B310: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x8001B314: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8001B318: sub.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d - ctx->f2.d;
    // 0x8001B31C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001B320: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8001B324: swc1        $f0, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->f0.u32l;
    // 0x8001B328: bgez        $v1, L_8001B33C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001B32C: sub.s       $f18, $f0, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_8001B33C;
    }
    // 0x8001B32C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8001B330: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B334: nop

    // 0x8001B338: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8001B33C:
    // 0x8001B33C: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8001B340: swc1        $f10, 0x5C($t0)
    MEM_W(0X5C, ctx->r8) = ctx->f10.u32l;
    // 0x8001B344: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8001B348:
    // 0x8001B348: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B34C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001B350:
    // 0x8001B350: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B354: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B358: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x8001B35C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8001B360: beql        $a0, $zero, L_8001B3DC
    if (ctx->r4 == 0) {
        // 0x8001B364: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B3DC;
    }
    goto skip_6;
    // 0x8001B364: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_6:
    // 0x8001B368: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001B36C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001B370: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x8001B374: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8001B378: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8001B37C: bne         $t8, $zero, L_8001B3D8
    if (ctx->r24 != 0) {
        // 0x8001B380: swc1        $f6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
            goto L_8001B3D8;
    }
    // 0x8001B380: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8001B384: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001B388: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8001B38C: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8001B390: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8001B394: nop

    // 0x8001B398: bc1tl       L_8001B3DC
    if (c1cs) {
        // 0x8001B39C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B3DC;
    }
    goto skip_7;
    // 0x8001B39C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_7:
    // 0x8001B3A0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8001B3A4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001B3A8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8001B3AC: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x8001B3B0: sub.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8001B3B4: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8001B3B8: bgez        $a0, L_8001B3D0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001B3BC: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8001B3D0;
    }
    // 0x8001B3BC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001B3C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001B3C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B3C8: nop

    // 0x8001B3CC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8001B3D0:
    // 0x8001B3D0: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001B3D4: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
L_8001B3D8:
    // 0x8001B3D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001B3DC:
    // 0x8001B3DC: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8001B3E0: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8001B3E4: bne         $at, $zero, L_8001B350
    if (ctx->r1 != 0) {
        // 0x8001B3E8: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_8001B350;
    }
    // 0x8001B3E8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8001B3EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001B3F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001B3F4:
    // 0x8001B3F4: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B3F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B3FC: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x8001B400: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8001B404: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8001B408: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B40C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8001B410: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8001B414: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8001B418: bne         $at, $zero, L_8001B3F4
    if (ctx->r1 != 0) {
        // 0x8001B41C: nop
    
            goto L_8001B3F4;
    }
    // 0x8001B41C: nop

    // 0x8001B420: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001B424: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B428: nop

    // 0x8001B42C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001B430: nop

    // 0x8001B434: bc1fl       L_8001B444
    if (!c1cs) {
        // 0x8001B438: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B444;
    }
    goto skip_8;
    // 0x8001B438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8001B43C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001B440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B444:
    // 0x8001B444: swc1        $f2, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->f2.u32l;
    // 0x8001B448: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001B44C: jr          $ra
    // 0x8001B450: nop

    return;
    // 0x8001B450: nop

;}
RECOMP_FUNC void Effect_Effect386_Spawn2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C1AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007C1B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8007C1B4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8007C1B8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8007C1BC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8007C1C0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007C1C4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007C1C8: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007C1CC: addiu       $s0, $s0, 0x3754
    ctx->r16 = ADD32(ctx->r16, 0X3754);
    // 0x8007C1D0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8007C1D4:
    // 0x8007C1D4: bnel        $t6, $zero, L_8007C230
    if (ctx->r14 != 0) {
        // 0x8007C1D8: addiu       $s0, $s0, -0x8C
        ctx->r16 = ADD32(ctx->r16, -0X8C);
            goto L_8007C230;
    }
    goto skip_0;
    // 0x8007C1D8: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
    skip_0:
    // 0x8007C1DC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007C1E0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007C1E4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007C1E8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007C1EC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8007C1F0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007C1F4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007C1F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007C1FC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8007C200: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007C204: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007C208: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8007C20C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8007C210: jal         0x8007BF64
    // 0x8007C214: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    Effect_Effect_Effect386_Setup(rdram, ctx);
        goto after_0;
    // 0x8007C214: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007C218: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x8007C21C: jal         0x800A6070
    // 0x8007C220: lui         $a1, 0x2900
    ctx->r5 = S32(0X2900 << 16);
    Play_PlaySfxNoPlayer(rdram, ctx);
        goto after_1;
    // 0x8007C220: lui         $a1, 0x2900
    ctx->r5 = S32(0X2900 << 16);
    after_1:
    // 0x8007C224: b           L_8007C240
    // 0x8007C228: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8007C240;
    // 0x8007C228: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007C22C: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
L_8007C230:
    // 0x8007C230: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8007C234: beql        $at, $zero, L_8007C1D4
    if (ctx->r1 == 0) {
        // 0x8007C238: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8007C1D4;
    }
    goto skip_1;
    // 0x8007C238: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x8007C23C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8007C240:
    // 0x8007C240: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8007C244: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007C248: jr          $ra
    // 0x8007C24C: nop

    return;
    // 0x8007C24C: nop

;}
RECOMP_FUNC void Play_UpdateLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B79B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B79B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B79B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B79BC: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800B79C0: sltiu       $at, $t6, 0x15
    ctx->r1 = ctx->r14 < 0X15 ? 1 : 0;
    // 0x800B79C4: beq         $at, $zero, L_800B831C
    if (ctx->r1 == 0) {
        // 0x800B79C8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B831C;
    }
    // 0x800B79C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B79CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B79D0: addu        $at, $at, $t6
    gpr jr_addend_800B79D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B79D4: lw          $t6, -0x7484($at)
    ctx->r14 = ADD32(ctx->r1, -0X7484);
    // 0x800B79D8: jr          $t6
    // 0x800B79DC: nop

    switch (jr_addend_800B79D8 >> 2) {
        case 0: goto L_800B7D60; break;
        case 1: goto L_800B7C00; break;
        case 2: goto L_800B7C18; break;
        case 3: goto L_800B831C; break;
        case 4: goto L_800B831C; break;
        case 5: goto L_800B831C; break;
        case 6: goto L_800B831C; break;
        case 7: goto L_800B7DC0; break;
        case 8: goto L_800B815C; break;
        case 9: goto L_800B7B90; break;
        case 10: goto L_800B79E0; break;
        case 11: goto L_800B831C; break;
        case 12: goto L_800B831C; break;
        case 13: goto L_800B7DA4; break;
        case 14: goto L_800B831C; break;
        case 15: goto L_800B831C; break;
        case 16: goto L_800B831C; break;
        case 17: goto L_800B831C; break;
        case 18: goto L_800B831C; break;
        case 19: goto L_800B7AEC; break;
        case 20: goto L_800B7A04; break;
        default: switch_error(__func__, 0x800B79D8, 0x800D8B7C);
    }
    // 0x800B79DC: nop

L_800B79E0:
    // 0x800B79E0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B79E4: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x800B79E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B79EC: bnel        $t7, $at, L_800B8320
    if (ctx->r15 != ctx->r1) {
        // 0x800B79F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B8320;
    }
    goto skip_0;
    // 0x800B79F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800B79F4: jal         0x8019949C
    // 0x800B79F8: nop

    LOOKUP_FUNC(0x8019949C)(rdram, ctx);
        goto after_0;
    // 0x800B79F8: nop

    after_0:
    // 0x800B79FC: b           L_800B8320
    // 0x800B7A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B8320;
    // 0x800B7A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B7A04:
    // 0x800B7A04: jal         0x800C26C8
    // 0x800B7A08: nop

    func_versus_800C26C8(rdram, ctx);
        goto after_1;
    // 0x800B7A08: nop

    after_1:
    // 0x800B7A0C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B7A10: addiu       $a2, $a2, 0x7844
    ctx->r6 = ADD32(ctx->r6, 0X7844);
    // 0x800B7A14: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800B7A18: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800B7A1C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800B7A20: addiu       $v0, $t8, 0x1
    ctx->r2 = ADD32(ctx->r24, 0X1);
    // 0x800B7A24: bne         $v0, $at, L_800B7A7C
    if (ctx->r2 != ctx->r1) {
        // 0x800B7A28: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_800B7A7C;
    }
    // 0x800B7A28: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800B7A2C: addiu       $v1, $v1, 0x1AA8
    ctx->r3 = ADD32(ctx->r3, 0X1AA8);
    // 0x800B7A30: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800B7A34: bnel        $t0, $zero, L_800B7A80
    if (ctx->r8 != 0) {
        // 0x800B7A38: addiu       $at, $zero, 0x190
        ctx->r1 = ADD32(0, 0X190);
            goto L_800B7A80;
    }
    goto skip_1;
    // 0x800B7A38: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    skip_1:
    // 0x800B7A3C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800B7A40: bnel        $t1, $zero, L_800B7A80
    if (ctx->r9 != 0) {
        // 0x800B7A44: addiu       $at, $zero, 0x190
        ctx->r1 = ADD32(0, 0X190);
            goto L_800B7A80;
    }
    goto skip_2;
    // 0x800B7A44: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    skip_2:
    // 0x800B7A48: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B7A4C: bnel        $t2, $zero, L_800B7A80
    if (ctx->r10 != 0) {
        // 0x800B7A50: addiu       $at, $zero, 0x190
        ctx->r1 = ADD32(0, 0X190);
            goto L_800B7A80;
    }
    goto skip_3;
    // 0x800B7A50: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    skip_3:
    // 0x800B7A54: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x800B7A58: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x800B7A5C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B7A60: bnel        $t3, $zero, L_800B7A80
    if (ctx->r11 != 0) {
        // 0x800B7A64: addiu       $at, $zero, 0x190
        ctx->r1 = ADD32(0, 0X190);
            goto L_800B7A80;
    }
    goto skip_4;
    // 0x800B7A64: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    skip_4:
    // 0x800B7A68: jal         0x800B852C
    // 0x800B7A6C: addiu       $a1, $a1, 0x37E0
    ctx->r5 = ADD32(ctx->r5, 0X37E0);
    Play_SpawnVsItem(rdram, ctx);
        goto after_2;
    // 0x800B7A6C: addiu       $a1, $a1, 0x37E0
    ctx->r5 = ADD32(ctx->r5, 0X37E0);
    after_2:
    // 0x800B7A70: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B7A74: addiu       $a2, $a2, 0x7844
    ctx->r6 = ADD32(ctx->r6, 0X7844);
    // 0x800B7A78: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800B7A7C:
    // 0x800B7A7C: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
L_800B7A80:
    // 0x800B7A80: bne         $v0, $at, L_800B7AD8
    if (ctx->r2 != ctx->r1) {
        // 0x800B7A84: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800B7AD8;
    }
    // 0x800B7A84: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B7A88: addiu       $v1, $v1, 0x7DA0
    ctx->r3 = ADD32(ctx->r3, 0X7DA0);
    // 0x800B7A8C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B7A90: bnel        $t4, $zero, L_800B7ADC
    if (ctx->r12 != 0) {
        // 0x800B7A94: addiu       $at, $zero, 0x1F4
        ctx->r1 = ADD32(0, 0X1F4);
            goto L_800B7ADC;
    }
    goto skip_5;
    // 0x800B7A94: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    skip_5:
    // 0x800B7A98: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x800B7A9C: bnel        $t5, $zero, L_800B7ADC
    if (ctx->r13 != 0) {
        // 0x800B7AA0: addiu       $at, $zero, 0x1F4
        ctx->r1 = ADD32(0, 0X1F4);
            goto L_800B7ADC;
    }
    goto skip_6;
    // 0x800B7AA0: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    skip_6:
    // 0x800B7AA4: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800B7AA8: bnel        $t6, $zero, L_800B7ADC
    if (ctx->r14 != 0) {
        // 0x800B7AAC: addiu       $at, $zero, 0x1F4
        ctx->r1 = ADD32(0, 0X1F4);
            goto L_800B7ADC;
    }
    goto skip_7;
    // 0x800B7AAC: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    skip_7:
    // 0x800B7AB0: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800B7AB4: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    // 0x800B7AB8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B7ABC: bnel        $t7, $zero, L_800B7ADC
    if (ctx->r15 != 0) {
        // 0x800B7AC0: addiu       $at, $zero, 0x1F4
        ctx->r1 = ADD32(0, 0X1F4);
            goto L_800B7ADC;
    }
    goto skip_8;
    // 0x800B7AC0: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    skip_8:
    // 0x800B7AC4: jal         0x800B852C
    // 0x800B7AC8: addiu       $a1, $a1, 0x384C
    ctx->r5 = ADD32(ctx->r5, 0X384C);
    Play_SpawnVsItem(rdram, ctx);
        goto after_3;
    // 0x800B7AC8: addiu       $a1, $a1, 0x384C
    ctx->r5 = ADD32(ctx->r5, 0X384C);
    after_3:
    // 0x800B7ACC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B7AD0: addiu       $a2, $a2, 0x7844
    ctx->r6 = ADD32(ctx->r6, 0X7844);
    // 0x800B7AD4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800B7AD8:
    // 0x800B7AD8: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
L_800B7ADC:
    // 0x800B7ADC: bnel        $v0, $at, L_800B8320
    if (ctx->r2 != ctx->r1) {
        // 0x800B7AE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B8320;
    }
    goto skip_9;
    // 0x800B7AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x800B7AE4: b           L_800B831C
    // 0x800B7AE8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_800B831C;
    // 0x800B7AE8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800B7AEC:
    // 0x800B7AEC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B7AF0: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x800B7AF4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800B7AF8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x800B7AFC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B7B00: lw          $t8, 0x1C8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C8);
    // 0x800B7B04: beql        $a2, $t8, L_800B8320
    if (ctx->r6 == ctx->r24) {
        // 0x800B7B08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B8320;
    }
    goto skip_10;
    // 0x800B7B08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x800B7B0C: lw          $t9, -0x7D84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D84);
    // 0x800B7B10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B7B14: bnel        $t9, $at, L_800B8320
    if (ctx->r25 != ctx->r1) {
        // 0x800B7B18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B8320;
    }
    goto skip_11;
    // 0x800B7B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x800B7B1C: sw          $a2, 0x1C8($v1)
    MEM_W(0X1C8, ctx->r3) = ctx->r6;
    // 0x800B7B20: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800B7B24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800B7B28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7B2C: sw          $zero, 0x1D0($t0)
    MEM_W(0X1D0, ctx->r8) = 0;
    // 0x800B7B30: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B7B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B7B38: sw          $t1, 0x234($t2)
    MEM_W(0X234, ctx->r10) = ctx->r9;
    // 0x800B7B3C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800B7B40: lwc1        $f4, -0x7430($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7430);
    // 0x800B7B44: swc1        $f4, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->f4.u32l;
    // 0x800B7B48: jal         0x800B7184
    // 0x800B7B4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    Camera_Update360(rdram, ctx);
        goto after_4;
    // 0x800B7B4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_4:
    // 0x800B7B50: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B7B54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7B58: sw          $v0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r2;
    // 0x800B7B5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7B60: sw          $v0, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r2;
    // 0x800B7B64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7B68: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x800B7B6C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7B70: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B7B74: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x800B7B78: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800B7B7C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B7B80: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800B7B84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7B88: b           L_800B831C
    // 0x800B7B8C: sw          $v0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r2;
        goto L_800B831C;
    // 0x800B7B8C: sw          $v0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r2;
L_800B7B90:
    // 0x800B7B90: jal         0x8018BDD8
    // 0x800B7B94: nop

    Andross_8018BDD8(rdram, ctx);
        goto after_5;
    // 0x800B7B94: nop

    after_5:
    // 0x800B7B98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7B9C: lwc1        $f6, -0x742C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X742C);
    // 0x800B7BA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B7BA4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B7BA8: swc1        $f6, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->f6.u32l;
    // 0x800B7BAC: addiu       $a0, $a0, -0x7D80
    ctx->r4 = ADD32(ctx->r4, -0X7D80);
    // 0x800B7BB0: lui         $at, 0x4419
    ctx->r1 = S32(0X4419 << 16);
    // 0x800B7BB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B7BB8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B7BBC: lui         $at, 0xC408
    ctx->r1 = S32(0XC408 << 16);
    // 0x800B7BC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B7BC4: swc1        $f8, 0xA0($t6)
    MEM_W(0XA0, ctx->r14) = ctx->f8.u32l;
    // 0x800B7BC8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800B7BCC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B7BD0: addiu       $v1, $v1, 0x7B44
    ctx->r3 = ADD32(ctx->r3, 0X7B44);
    // 0x800B7BD4: swc1        $f10, 0xA4($t7)
    MEM_W(0XA4, ctx->r15) = ctx->f10.u32l;
    // 0x800B7BD8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B7BDC: beq         $v0, $zero, L_800B831C
    if (ctx->r2 == 0) {
        // 0x800B7BE0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800B831C;
    }
    // 0x800B7BE0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800B7BE4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800B7BE8: bne         $t9, $zero, L_800B831C
    if (ctx->r25 != 0) {
        // 0x800B7BEC: sb          $t8, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r24;
            goto L_800B831C;
    }
    // 0x800B7BEC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800B7BF0: jal         0x80189214
    // 0x800B7BF4: nop

    Andross_80189214(rdram, ctx);
        goto after_6;
    // 0x800B7BF4: nop

    after_6:
    // 0x800B7BF8: b           L_800B8320
    // 0x800B7BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B8320;
    // 0x800B7BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B7C00:
    // 0x800B7C00: lui         $a0, 0x103
    ctx->r4 = S32(0X103 << 16);
    // 0x800B7C04: addiu       $a0, $a0, -0xF8
    ctx->r4 = ADD32(ctx->r4, -0XF8);
    // 0x800B7C08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800B7C0C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800B7C10: jal         0x80099A2C
    // 0x800B7C14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_7;
    // 0x800B7C14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
L_800B7C18:
    // 0x800B7C18: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B7C1C: lw          $t0, -0x7D84($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D84);
    // 0x800B7C20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7C24: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x800B7C28: bne         $t0, $at, L_800B7CA0
    if (ctx->r8 != ctx->r1) {
        // 0x800B7C2C: lui         $t2, 0x8018
        ctx->r10 = S32(0X8018 << 16);
            goto L_800B7CA0;
    }
    // 0x800B7C2C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800B7C30: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x800B7C34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B7C38: sb          $t1, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r9;
    // 0x800B7C3C: lw          $t3, 0x1C8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C8);
    // 0x800B7C40: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x800B7C44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B7C48: bne         $a2, $t3, L_800B7C80
    if (ctx->r6 != ctx->r11) {
        // 0x800B7C4C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_800B7C80;
    }
    // 0x800B7C4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B7C50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B7C54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B7C58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B7C5C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B7C60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B7C64: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B7C68: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B7C6C: addiu       $a0, $a0, -0x6A0
    ctx->r4 = ADD32(ctx->r4, -0X6A0);
    // 0x800B7C70: jal         0x8009BC2C
    // 0x800B7C74: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800B7C74: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x800B7C78: b           L_800B7CA0
    // 0x800B7C7C: nop

        goto L_800B7CA0;
    // 0x800B7C7C: nop

L_800B7C80:
    // 0x800B7C80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B7C84: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B7C88: addiu       $a0, $a0, -0x6A0
    ctx->r4 = ADD32(ctx->r4, -0X6A0);
    // 0x800B7C8C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B7C90: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B7C94: lui         $a1, 0x4300
    ctx->r5 = S32(0X4300 << 16);
    // 0x800B7C98: jal         0x8009BC2C
    // 0x800B7C9C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B7C9C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_9:
L_800B7CA0:
    // 0x800B7CA0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800B7CA4: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x800B7CA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B7CAC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800B7CB0: bnel        $t4, $at, L_800B8320
    if (ctx->r12 != ctx->r1) {
        // 0x800B7CB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B8320;
    }
    goto skip_12;
    // 0x800B7CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x800B7CB8: lw          $t5, -0x7D84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D84);
    // 0x800B7CBC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B7CC0: addiu       $v1, $v1, 0x7E80
    ctx->r3 = ADD32(ctx->r3, 0X7E80);
    // 0x800B7CC4: bnel        $t5, $zero, L_800B8320
    if (ctx->r13 != 0) {
        // 0x800B7CC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B8320;
    }
    goto skip_13;
    // 0x800B7CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x800B7CCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B7CD0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B7CD4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800B7CD8: bne         $v0, $at, L_800B831C
    if (ctx->r2 != ctx->r1) {
        // 0x800B7CDC: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_800B831C;
    }
    // 0x800B7CDC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800B7CE0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800B7CE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B7CE8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B7CEC: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x800B7CF0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800B7CF4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B7CF8: sw          $t7, 0x1C8($t8)
    MEM_W(0X1C8, ctx->r24) = ctx->r15;
    // 0x800B7CFC: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x800B7D00: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800B7D04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B7D08: sw          $zero, 0x1D0($t9)
    MEM_W(0X1D0, ctx->r25) = 0;
    // 0x800B7D0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B7D10: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x800B7D14: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x800B7D18: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800B7D1C: sw          $t0, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r8;
    // 0x800B7D20: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800B7D24: ori         $a0, $a0, 0x602A
    ctx->r4 = ctx->r4 | 0X602A;
    // 0x800B7D28: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B7D2C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800B7D30: jal         0x80019218
    // 0x800B7D34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x800B7D34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x800B7D38: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800B7D3C: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x800B7D40: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B7D44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B7D48: sb          $t2, 0x7930($at)
    MEM_B(0X7930, ctx->r1) = ctx->r10;
    // 0x800B7D4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B7D50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B7D54: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B7D58: b           L_800B831C
    // 0x800B7D5C: sb          $t3, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = ctx->r11;
        goto L_800B831C;
    // 0x800B7D5C: sb          $t3, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = ctx->r11;
L_800B7D60:
    // 0x800B7D60: lui         $a0, 0x604
    ctx->r4 = S32(0X604 << 16);
    // 0x800B7D64: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x800B7D68: addiu       $a1, $a1, -0x75A0
    ctx->r5 = ADD32(ctx->r5, -0X75A0);
    // 0x800B7D6C: jal         0x8008C104
    // 0x800B7D70: addiu       $a0, $a0, -0x14C8
    ctx->r4 = ADD32(ctx->r4, -0X14C8);
    HUD_Texture_Wave(rdram, ctx);
        goto after_11;
    // 0x800B7D70: addiu       $a0, $a0, -0x14C8
    ctx->r4 = ADD32(ctx->r4, -0X14C8);
    after_11:
    // 0x800B7D74: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B7D78: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x800B7D7C: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x800B7D80: addiu       $a0, $a0, -0x3428
    ctx->r4 = ADD32(ctx->r4, -0X3428);
    // 0x800B7D84: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800B7D88: beq         $t6, $zero, L_800B831C
    if (ctx->r14 == 0) {
        // 0x800B7D8C: addiu       $a1, $zero, 0x40
        ctx->r5 = ADD32(0, 0X40);
            goto L_800B831C;
    }
    // 0x800B7D8C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800B7D90: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B7D94: jal         0x80099A2C
    // 0x800B7D98: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_12;
    // 0x800B7D98: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
    // 0x800B7D9C: b           L_800B8320
    // 0x800B7DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B8320;
    // 0x800B7DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B7DA4:
    // 0x800B7DA4: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x800B7DA8: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x800B7DAC: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x800B7DB0: jal         0x8008C104
    // 0x800B7DB4: addiu       $a0, $a0, 0x158C
    ctx->r4 = ADD32(ctx->r4, 0X158C);
    HUD_Texture_Wave(rdram, ctx);
        goto after_13;
    // 0x800B7DB4: addiu       $a0, $a0, 0x158C
    ctx->r4 = ADD32(ctx->r4, 0X158C);
    after_13:
    // 0x800B7DB8: b           L_800B8320
    // 0x800B7DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B8320;
    // 0x800B7DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B7DC0:
    // 0x800B7DC0: jal         0x800A3FEC
    // 0x800B7DC4: nop

    Play_UpdateDynaFloor(rdram, ctx);
        goto after_14;
    // 0x800B7DC4: nop

    after_14:
    // 0x800B7DC8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B7DCC: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x800B7DD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B7DD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B7DD8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B7DDC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x800B7DE0: nop

    // 0x800B7DE4: bc1f        L_800B7E34
    if (!c1cs) {
        // 0x800B7DE8: lui         $a0, 0x600
        ctx->r4 = S32(0X600 << 16);
            goto L_800B7E34;
    }
L_800B7DE8:
    // 0x800B7DE8: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x800B7DEC: addiu       $a0, $a0, 0x5710
    ctx->r4 = ADD32(ctx->r4, 0X5710);
    // 0x800B7DF0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800B7DF4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B7DF8: jal         0x80099A2C
    // 0x800B7DFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_15;
    // 0x800B7DFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x800B7E00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B7E04: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x800B7E08: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B7E0C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B7E10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B7E14: nop

    // 0x800B7E18: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800B7E1C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800B7E20: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B7E24: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x800B7E28: nop

    // 0x800B7E2C: bc1t        L_800B7DE8
    if (c1cs) {
        // 0x800B7E30: nop
    
            goto L_800B7DE8;
    }
    // 0x800B7E30: nop

L_800B7E34:
    // 0x800B7E34: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B7E38: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800B7E3C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800B7E40: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x800B7E44: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x800B7E48: addiu       $a0, $a0, 0x5710
    ctx->r4 = ADD32(ctx->r4, 0X5710);
    // 0x800B7E4C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800B7E50: bne         $t8, $at, L_800B7E60
    if (ctx->r24 != ctx->r1) {
        // 0x800B7E54: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_800B7E60;
    }
    // 0x800B7E54: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B7E58: jal         0x80099A2C
    // 0x800B7E5C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_16;
    // 0x800B7E5C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_16:
L_800B7E60:
    // 0x800B7E60: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x800B7E64: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x800B7E68: addiu       $a1, $a1, 0xF60
    ctx->r5 = ADD32(ctx->r5, 0XF60);
    // 0x800B7E6C: addiu       $a0, $a0, -0x1E18
    ctx->r4 = ADD32(ctx->r4, -0X1E18);
    // 0x800B7E70: jal         0x80099E28
    // 0x800B7E74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    Lib_Texture_Mottle(rdram, ctx);
        goto after_17;
    // 0x800B7E74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x800B7E78: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7E7C: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x800B7E80: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x800B7E84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B7E88: lwc1        $f0, 0x78($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X78);
    // 0x800B7E8C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800B7E90: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800B7E94: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800B7E98: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800B7E9C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B7EA0: bc1fl       L_800B7EB4
    if (!c1cs) {
        // 0x800B7EA4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_800B7EB4;
    }
    goto skip_14;
    // 0x800B7EA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_14:
    // 0x800B7EA8: b           L_800B7F64
    // 0x800B7EAC: sb          $t9, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r25;
        goto L_800B7F64;
    // 0x800B7EAC: sb          $t9, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r25;
    // 0x800B7EB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_800B7EB4:
    // 0x800B7EB4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800B7EB8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800B7EBC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800B7EC0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800B7EC4: bc1fl       L_800B7ED8
    if (!c1cs) {
        // 0x800B7EC8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800B7ED8;
    }
    goto skip_15;
    // 0x800B7EC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_15:
    // 0x800B7ECC: b           L_800B7F64
    // 0x800B7ED0: sb          $t0, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r8;
        goto L_800B7F64;
    // 0x800B7ED0: sb          $t0, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r8;
    // 0x800B7ED4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800B7ED8:
    // 0x800B7ED8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7EDC: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800B7EE0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B7EE4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800B7EE8: bc1fl       L_800B7EFC
    if (!c1cs) {
        // 0x800B7EEC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800B7EFC;
    }
    goto skip_16;
    // 0x800B7EEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_16:
    // 0x800B7EF0: b           L_800B7F64
    // 0x800B7EF4: sb          $t1, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r9;
        goto L_800B7F64;
    // 0x800B7EF4: sb          $t1, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r9;
    // 0x800B7EF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800B7EFC:
    // 0x800B7EFC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7F00: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B7F04: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B7F08: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800B7F0C: bc1fl       L_800B7F20
    if (!c1cs) {
        // 0x800B7F10: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_800B7F20;
    }
    goto skip_17;
    // 0x800B7F10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_17:
    // 0x800B7F14: b           L_800B7F64
    // 0x800B7F18: sb          $t2, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r10;
        goto L_800B7F64;
    // 0x800B7F18: sb          $t2, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r10;
    // 0x800B7F1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_800B7F20:
    // 0x800B7F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B7F24: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B7F28: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800B7F2C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800B7F30: bc1fl       L_800B7F44
    if (!c1cs) {
        // 0x800B7F34: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800B7F44;
    }
    goto skip_18;
    // 0x800B7F34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_18:
    // 0x800B7F38: b           L_800B7F64
    // 0x800B7F3C: sb          $t3, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r11;
        goto L_800B7F64;
    // 0x800B7F3C: sb          $t3, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r11;
    // 0x800B7F40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800B7F44:
    // 0x800B7F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B7F48: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800B7F4C: nop

    // 0x800B7F50: bc1f        L_800B7F64
    if (!c1cs) {
        // 0x800B7F54: nop
    
            goto L_800B7F64;
    }
    // 0x800B7F54: nop

    // 0x800B7F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B7F5C: b           L_800B7F64
    // 0x800B7F60: sb          $zero, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = 0;
        goto L_800B7F64;
    // 0x800B7F60: sb          $zero, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = 0;
L_800B7F64:
    // 0x800B7F64: lw          $t4, 0x1C8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1C8);
    // 0x800B7F68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B7F6C: bnel        $t4, $at, L_800B8048
    if (ctx->r12 != ctx->r1) {
        // 0x800B7F70: lw          $v0, 0x264($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X264);
            goto L_800B8048;
    }
    goto skip_19;
    // 0x800B7F70: lw          $v0, 0x264($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X264);
    skip_19:
    // 0x800B7F74: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x800B7F78: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x800B7F7C: bnel        $t6, $zero, L_800B8048
    if (ctx->r14 != 0) {
        // 0x800B7F80: lw          $v0, 0x264($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X264);
            goto L_800B8048;
    }
    goto skip_20;
    // 0x800B7F80: lw          $v0, 0x264($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X264);
    skip_20:
    // 0x800B7F84: lw          $t7, 0x264($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X264);
    // 0x800B7F88: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B7F8C: sw          $t8, 0x264($v1)
    MEM_W(0X264, ctx->r3) = ctx->r24;
    // 0x800B7F90: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7F94: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x800B7F98: lw          $t9, 0x264($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X264);
    // 0x800B7F9C: bgtzl       $t9, L_800B7FB4
    if (SIGNED(ctx->r25) > 0) {
        // 0x800B7FA0: lw          $t0, 0x26C($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X26C);
            goto L_800B7FB4;
    }
    goto skip_21;
    // 0x800B7FA0: lw          $t0, 0x26C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X26C);
    skip_21:
    // 0x800B7FA4: sw          $zero, 0x264($v1)
    MEM_W(0X264, ctx->r3) = 0;
    // 0x800B7FA8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7FAC: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x800B7FB0: lw          $t0, 0x26C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X26C);
L_800B7FB4:
    // 0x800B7FB4: bnel        $t0, $zero, L_800B8048
    if (ctx->r8 != 0) {
        // 0x800B7FB8: lw          $v0, 0x264($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X264);
            goto L_800B8048;
    }
    goto skip_22;
    // 0x800B7FB8: lw          $v0, 0x264($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X264);
    skip_22:
    // 0x800B7FBC: lw          $v0, 0x264($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X264);
    // 0x800B7FC0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x800B7FC4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800B7FC8: bne         $v0, $at, L_800B8004
    if (ctx->r2 != ctx->r1) {
        // 0x800B7FCC: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_800B8004;
    }
    // 0x800B7FCC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800B7FD0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800B7FD4: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x800B7FD8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800B7FDC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800B7FE0: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800B7FE4: ori         $a0, $a0, 0x8011
    ctx->r4 = ctx->r4 | 0X8011;
    // 0x800B7FE8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B7FEC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800B7FF0: jal         0x80019218
    // 0x800B7FF4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x800B7FF4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_18:
    // 0x800B7FF8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7FFC: b           L_800B8044
    // 0x800B8000: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
        goto L_800B8044;
    // 0x800B8000: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
L_800B8004:
    // 0x800B8004: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800B8008: bne         $v0, $at, L_800B8044
    if (ctx->r2 != ctx->r1) {
        // 0x800B800C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_800B8044;
    }
    // 0x800B800C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800B8010: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x800B8014: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800B8018: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x800B801C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800B8020: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800B8024: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800B8028: ori         $a0, $a0, 0x8010
    ctx->r4 = ctx->r4 | 0X8010;
    // 0x800B802C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800B8030: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800B8034: jal         0x80019218
    // 0x800B8038: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x800B8038: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_19:
    // 0x800B803C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B8040: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
L_800B8044:
    // 0x800B8044: lw          $v0, 0x264($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X264);
L_800B8048:
    // 0x800B8048: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800B804C: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x800B8050: beq         $at, $zero, L_800B8060
    if (ctx->r1 == 0) {
        // 0x800B8054: nop
    
            goto L_800B8060;
    }
    // 0x800B8054: nop

    // 0x800B8058: b           L_800B8060
    // 0x800B805C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
        goto L_800B8060;
    // 0x800B805C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_800B8060:
    // 0x800B8060: jal         0x8001D1C8
    // 0x800B8064: lbu         $a1, 0x3A($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3A);
    Audio_SetHeatAlarmParams(rdram, ctx);
        goto after_20;
    // 0x800B8064: lbu         $a1, 0x3A($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3A);
    after_20:
    // 0x800B8068: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B806C: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x800B8070: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800B8074: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x800B8078: bne         $t4, $zero, L_800B8124
    if (ctx->r12 != 0) {
        // 0x800B807C: nop
    
            goto L_800B8124;
    }
    // 0x800B807C: nop

    // 0x800B8080: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x800B8084: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x800B8088: lw          $t6, 0x1C8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C8);
    // 0x800B808C: beq         $a2, $t6, L_800B8124
    if (ctx->r6 == ctx->r14) {
        // 0x800B8090: nop
    
            goto L_800B8124;
    }
    // 0x800B8090: nop

    // 0x800B8094: jal         0x80004EB0
    // 0x800B8098: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x800B8098: nop

    after_21:
    // 0x800B809C: jal         0x80004EB0
    // 0x800B80A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x800B80A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x800B80A4: jal         0x80004EB0
    // 0x800B80A8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x800B80A8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x800B80AC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B80B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B80B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B80B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B80BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B80C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B80C4: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B80C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B80CC: lwc1        $f8, -0x7428($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7428);
    // 0x800B80D0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B80D4: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x800B80D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B80DC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800B80E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B80E4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B80E8: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B80EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B80F0: lwc1        $f6, -0x7424($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7424);
    // 0x800B80F4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B80F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B80FC: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800B8100: lwc1        $f10, 0x138($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X138);
    // 0x800B8104: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B8108: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B810C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B8110: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800B8114: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B8118: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800B811C: jal         0x8019E8B8
    // 0x800B8120: nop

    Solar_SoFlare_Spawn3(rdram, ctx);
        goto after_24;
    // 0x800B8120: nop

    after_24:
L_800B8124:
    // 0x800B8124: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x800B8128: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x800B812C: addiu       $a1, $a1, 0x198
    ctx->r5 = ADD32(ctx->r5, 0X198);
    // 0x800B8130: jal         0x8008C104
    // 0x800B8134: addiu       $a0, $a0, 0x29A4
    ctx->r4 = ADD32(ctx->r4, 0X29A4);
    HUD_Texture_Wave(rdram, ctx);
        goto after_25;
    // 0x800B8134: addiu       $a0, $a0, 0x29A4
    ctx->r4 = ADD32(ctx->r4, 0X29A4);
    after_25:
    // 0x800B8138: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B813C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x800B8140: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B8144: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B8148: lw          $t9, 0x264($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X264);
    // 0x800B814C: bnel        $t9, $zero, L_800B8320
    if (ctx->r25 != 0) {
        // 0x800B8150: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B8320;
    }
    goto skip_23;
    // 0x800B8150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_23:
    // 0x800B8154: b           L_800B831C
    // 0x800B8158: sb          $t0, 0x7B4C($at)
    MEM_B(0X7B4C, ctx->r1) = ctx->r8;
        goto L_800B831C;
    // 0x800B8158: sb          $t0, 0x7B4C($at)
    MEM_B(0X7B4C, ctx->r1) = ctx->r8;
L_800B815C:
    // 0x800B815C: jal         0x800A3FEC
    // 0x800B8160: nop

    Play_UpdateDynaFloor(rdram, ctx);
        goto after_26;
    // 0x800B8160: nop

    after_26:
    // 0x800B8164: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B8168: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x800B816C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B8170: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B8174: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8178: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x800B817C: nop

    // 0x800B8180: bc1f        L_800B81D0
    if (!c1cs) {
        // 0x800B8184: lui         $a0, 0x603
        ctx->r4 = S32(0X603 << 16);
            goto L_800B81D0;
    }
L_800B8184:
    // 0x800B8184: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x800B8188: addiu       $a0, $a0, -0x3D34
    ctx->r4 = ADD32(ctx->r4, -0X3D34);
    // 0x800B818C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800B8190: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B8194: jal         0x80099A2C
    // 0x800B8198: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_27;
    // 0x800B8198: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_27:
    // 0x800B819C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B81A0: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x800B81A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B81A8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B81AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B81B0: nop

    // 0x800B81B4: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800B81B8: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800B81BC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B81C0: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x800B81C4: nop

    // 0x800B81C8: bc1t        L_800B8184
    if (c1cs) {
        // 0x800B81CC: nop
    
            goto L_800B8184;
    }
    // 0x800B81CC: nop

L_800B81D0:
    // 0x800B81D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B81D4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x800B81D8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800B81DC: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x800B81E0: lw          $t2, 0x1C8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C8);
    // 0x800B81E4: addiu       $a0, $a0, -0x3D34
    ctx->r4 = ADD32(ctx->r4, -0X3D34);
    // 0x800B81E8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800B81EC: bne         $t2, $at, L_800B81FC
    if (ctx->r10 != ctx->r1) {
        // 0x800B81F0: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_800B81FC;
    }
    // 0x800B81F0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B81F4: jal         0x80099A2C
    // 0x800B81F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_28;
    // 0x800B81F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_28:
L_800B81FC:
    // 0x800B81FC: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x800B8200: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x800B8204: addiu       $a1, $a1, -0x2670
    ctx->r5 = ADD32(ctx->r5, -0X2670);
    // 0x800B8208: jal         0x8008C104
    // 0x800B820C: addiu       $a0, $a0, -0x3D34
    ctx->r4 = ADD32(ctx->r4, -0X3D34);
    HUD_Texture_Wave(rdram, ctx);
        goto after_29;
    // 0x800B820C: addiu       $a0, $a0, -0x3D34
    ctx->r4 = ADD32(ctx->r4, -0X3D34);
    after_29:
    // 0x800B8210: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B8214: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x800B8218: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B821C: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800B8220: lwc1        $f6, 0x48($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X48);
    // 0x800B8224: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x800B8228: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x800B822C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B8230: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800B8234: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800B8238: jal         0x800A73E4
    // 0x800B823C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_30;
    // 0x800B823C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_30:
    // 0x800B8240: beq         $v0, $zero, L_800B82B0
    if (ctx->r2 == 0) {
        // 0x800B8244: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800B82B0;
    }
    // 0x800B8244: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B8248: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B824C: sw          $zero, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = 0;
    // 0x800B8250: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x800B8254: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B8258: sw          $a2, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r6;
    // 0x800B825C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B8260: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800B8264: sw          $t3, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r11;
    // 0x800B8268: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B826C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B8270: addiu       $v1, $v1, -0x7AA8
    ctx->r3 = ADD32(ctx->r3, -0X7AA8);
    // 0x800B8274: addiu       $v0, $v0, -0x7AA4
    ctx->r2 = ADD32(ctx->r2, -0X7AA4);
    // 0x800B8278: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B827C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B8280: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B8284: sw          $zero, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = 0;
    // 0x800B8288: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B828C: addiu       $t6, $zero, 0x3DE
    ctx->r14 = ADD32(0, 0X3DE);
    // 0x800B8290: sw          $t6, -0x7C28($at)
    MEM_W(-0X7C28, ctx->r1) = ctx->r14;
    // 0x800B8294: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B8298: addiu       $t7, $zero, 0x3E2
    ctx->r15 = ADD32(0, 0X3E2);
    // 0x800B829C: sw          $t7, -0x7C24($at)
    MEM_W(-0X7C24, ctx->r1) = ctx->r15;
    // 0x800B82A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B82A4: addiu       $t8, $zero, 0x43
    ctx->r24 = ADD32(0, 0X43);
    // 0x800B82A8: b           L_800B831C
    // 0x800B82AC: sh          $t8, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r24;
        goto L_800B831C;
    // 0x800B82AC: sh          $t8, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r24;
L_800B82B0:
    // 0x800B82B0: addiu       $t9, $zero, 0x4107
    ctx->r25 = ADD32(0, 0X4107);
    // 0x800B82B4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B82B8: sh          $t9, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r25;
    // 0x800B82BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B82C0: addiu       $t0, $zero, 0x5A
    ctx->r8 = ADD32(0, 0X5A);
    // 0x800B82C4: sw          $t0, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r8;
    // 0x800B82C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B82CC: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x800B82D0: sw          $t1, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r9;
    // 0x800B82D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B82D8: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x800B82DC: sw          $t2, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r10;
    // 0x800B82E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B82E4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800B82E8: sw          $t3, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r11;
    // 0x800B82EC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B82F0: addiu       $v0, $v0, -0x7AA4
    ctx->r2 = ADD32(ctx->r2, -0X7AA4);
    // 0x800B82F4: addiu       $v1, $v1, -0x7AA8
    ctx->r3 = ADD32(ctx->r3, -0X7AA8);
    // 0x800B82F8: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x800B82FC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800B8300: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B8304: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B8308: addiu       $t5, $zero, 0x3E4
    ctx->r13 = ADD32(0, 0X3E4);
    // 0x800B830C: sw          $t5, -0x7C28($at)
    MEM_W(-0X7C28, ctx->r1) = ctx->r13;
    // 0x800B8310: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B8314: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x800B8318: sw          $t6, -0x7C24($at)
    MEM_W(-0X7C24, ctx->r1) = ctx->r14;
L_800B831C:
    // 0x800B831C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B8320:
    // 0x800B8320: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800B8324: jr          $ra
    // 0x800B8328: nop

    return;
    // 0x800B8328: nop

;}
RECOMP_FUNC void Controller_Rumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002CB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80002CBC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80002CC0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80002CC4: addiu       $fp, $fp, 0x2128
    ctx->r30 = ADD32(ctx->r30, 0X2128);
    // 0x80002CC8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80002CCC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002CD0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002CD4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002CD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80002CDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002CE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002CE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002CE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002CEC: jal         0x80020870
    // 0x80002CF0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    osContStartQuery_recomp(rdram, ctx);
        goto after_0;
    // 0x80002CF0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_0:
    // 0x80002CF4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80002CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002CFC: jal         0x800205E0
    // 0x80002D00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002D00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80002D04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002D08: jal         0x800208F4
    // 0x80002D0C: addiu       $a0, $a0, -0x2710
    ctx->r4 = ADD32(ctx->r4, -0X2710);
    osContGetQuery_recomp(rdram, ctx);
        goto after_2;
    // 0x80002D0C: addiu       $a0, $a0, -0x2710
    ctx->r4 = ADD32(ctx->r4, -0X2710);
    after_2:
    // 0x80002D10: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80002D14: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80002D18: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80002D1C: addiu       $s3, $s3, -0x2700
    ctx->r19 = ADD32(ctx->r19, -0X2700);
    // 0x80002D20: addiu       $s6, $s6, 0x7E84
    ctx->r22 = ADD32(ctx->r22, 0X7E84);
    // 0x80002D24: addiu       $s2, $s2, -0x2750
    ctx->r18 = ADD32(ctx->r18, -0X2750);
    // 0x80002D28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80002D2C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80002D30: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80002D34: addiu       $s4, $zero, 0x68
    ctx->r20 = ADD32(0, 0X68);
L_80002D38:
    // 0x80002D38: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80002D3C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80002D40: addiu       $t8, $t8, -0x2710
    ctx->r24 = ADD32(ctx->r24, -0X2710);
    // 0x80002D44: beq         $t6, $zero, L_80002E14
    if (ctx->r14 == 0) {
        // 0x80002D48: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_80002E14;
    }
    // 0x80002D48: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80002D4C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80002D50: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x80002D54: bnel        $t9, $zero, L_80002E18
    if (ctx->r25 != 0) {
        // 0x80002D58: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80002E18;
    }
    goto skip_0;
    // 0x80002D58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80002D5C: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x80002D60: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002D64: addiu       $t0, $t0, -0x2748
    ctx->r8 = ADD32(ctx->r8, -0X2748);
    // 0x80002D68: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80002D6C: beq         $t2, $zero, L_80002E10
    if (ctx->r10 == 0) {
        // 0x80002D70: addu        $s0, $s1, $t0
        ctx->r16 = ADD32(ctx->r17, ctx->r8);
            goto L_80002E10;
    }
    // 0x80002D70: addu        $s0, $s1, $t0
    ctx->r16 = ADD32(ctx->r17, ctx->r8);
    // 0x80002D74: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80002D78: bne         $v0, $zero, L_80002DB8
    if (ctx->r2 != 0) {
        // 0x80002D7C: nop
    
            goto L_80002DB8;
    }
    // 0x80002D7C: nop

    // 0x80002D80: multu       $s1, $s4
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002D84: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80002D88: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80002D8C: mflo        $t3
    ctx->r11 = lo;
    // 0x80002D90: addu        $a1, $s3, $t3
    ctx->r5 = ADD32(ctx->r19, ctx->r11);
    // 0x80002D94: jal         0x80020D70
    // 0x80002D98: nop

    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80002D98: nop

    after_3:
    // 0x80002D9C: beql        $v0, $zero, L_80002DB4
    if (ctx->r2 == 0) {
        // 0x80002DA0: sb          $s7, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r23;
            goto L_80002DB4;
    }
    goto skip_1;
    // 0x80002DA0: sb          $s7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r23;
    skip_1:
    // 0x80002DA4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80002DA8: b           L_80002DB8
    // 0x80002DAC: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
        goto L_80002DB8;
    // 0x80002DAC: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80002DB0: sb          $s7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r23;
L_80002DB4:
    // 0x80002DB4: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
L_80002DB8:
    // 0x80002DB8: bne         $s5, $v0, L_80002E14
    if (ctx->r21 != ctx->r2) {
        // 0x80002DBC: sll         $t4, $s1, 2
        ctx->r12 = S32(ctx->r17 << 2);
            goto L_80002E14;
    }
    // 0x80002DBC: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80002DC0: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80002DC4: addu        $t5, $s6, $s1
    ctx->r13 = ADD32(ctx->r22, ctx->r17);
    // 0x80002DC8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80002DCC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80002DD0: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80002DD4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80002DD8: beq         $t6, $zero, L_80002DF8
    if (ctx->r14 == 0) {
        // 0x80002DDC: addu        $a0, $s3, $t4
        ctx->r4 = ADD32(ctx->r19, ctx->r12);
            goto L_80002DF8;
    }
    // 0x80002DDC: addu        $a0, $s3, $t4
    ctx->r4 = ADD32(ctx->r19, ctx->r12);
    // 0x80002DE0: jal         0x80020A88
    // 0x80002DE4: nop

    osMotorStart_recomp(rdram, ctx);
        goto after_4;
    // 0x80002DE4: nop

    after_4:
    // 0x80002DE8: beql        $v0, $zero, L_80002E18
    if (ctx->r2 == 0) {
        // 0x80002DEC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80002E18;
    }
    goto skip_2;
    // 0x80002DEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80002DF0: b           L_80002E14
    // 0x80002DF4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80002E14;
    // 0x80002DF4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80002DF8:
    // 0x80002DF8: jal         0x80020920
    // 0x80002DFC: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_5;
    // 0x80002DFC: nop

    after_5:
    // 0x80002E00: beql        $v0, $zero, L_80002E18
    if (ctx->r2 == 0) {
        // 0x80002E04: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80002E18;
    }
    goto skip_3;
    // 0x80002E04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x80002E08: b           L_80002E14
    // 0x80002E0C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80002E14;
    // 0x80002E0C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80002E10:
    // 0x80002E10: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80002E14:
    // 0x80002E14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80002E18:
    // 0x80002E18: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80002E1C: bne         $at, $zero, L_80002D38
    if (ctx->r1 != 0) {
        // 0x80002E20: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80002D38;
    }
    // 0x80002E20: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80002E24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80002E28: sb          $zero, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = 0;
    // 0x80002E2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80002E30: sb          $zero, 0x7E85($at)
    MEM_B(0X7E85, ctx->r1) = 0;
    // 0x80002E34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80002E38: sb          $zero, 0x7E86($at)
    MEM_B(0X7E86, ctx->r1) = 0;
    // 0x80002E3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80002E40: sb          $zero, 0x7E87($at)
    MEM_B(0X7E87, ctx->r1) = 0;
    // 0x80002E44: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80002E48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002E4C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002E50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80002E54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002E58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002E5C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002E60: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80002E64: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80002E68: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80002E6C: jr          $ra
    // 0x80002E70: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80002E70: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Effect_Clouds_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800784B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800784B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800784BC: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x800784C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800784C4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800784C8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800784CC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800784D0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800784D4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800784D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800784DC: lh          $t8, 0x46($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X46);
    // 0x800784E0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800784E4: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800784E8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800784EC: jal         0x8005980C
    // 0x800784F0: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x800784F0: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x800784F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800784F8: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x800784FC: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80078500: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80078504: jal         0x80005D44
    // 0x80078508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80078508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007850C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80078510: jal         0x80006EB8
    // 0x80078514: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80078514: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_2:
    // 0x80078518: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8007851C: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x80078520: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80078524: lui         $t3, 0x201
    ctx->r11 = S32(0X201 << 16);
    // 0x80078528: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8007852C: sw          $t1, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r9;
    // 0x80078530: addiu       $t3, $t3, -0x28B0
    ctx->r11 = ADD32(ctx->r11, -0X28B0);
    // 0x80078534: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80078538: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8007853C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80078540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078548: jr          $ra
    // 0x8007854C: nop

    return;
    // 0x8007854C: nop

;}
RECOMP_FUNC void bootproc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004DA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004DAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004DB0: jal         0x8001EF10
    // 0x80004DB4: nop

    RdRam_CheckIPL3(rdram, ctx);
        goto after_0;
    // 0x80004DB4: nop

    after_0:
    // 0x80004DB8: jal         0x80022B60
    // 0x80004DBC: nop

    osInitialize_recomp(rdram, ctx);
        goto after_1;
    // 0x80004DBC: nop

    after_1:
    // 0x80004DC0: jal         0x80003A50
    // 0x80004DC4: nop

    Main_Initialize(rdram, ctx);
        goto after_2;
    // 0x80004DC4: nop

    after_2:
    // 0x80004DC8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80004DCC: addiu       $t6, $t6, -0x5FC0
    ctx->r14 = ADD32(ctx->r14, -0X5FC0);
    // 0x80004DD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80004DD4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80004DD8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80004DDC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80004DE0: addiu       $a2, $a2, 0x4D00
    ctx->r6 = ADD32(ctx->r6, 0X4D00);
    // 0x80004DE4: addiu       $a0, $a0, -0x7170
    ctx->r4 = ADD32(ctx->r4, -0X7170);
    // 0x80004DE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80004DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80004DF0: jal         0x800221A0
    // 0x80004DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x80004DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80004DF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80004DFC: jal         0x800222F0
    // 0x80004E00: addiu       $a0, $a0, -0x7170
    ctx->r4 = ADD32(ctx->r4, -0X7170);
    osStartThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80004E00: addiu       $a0, $a0, -0x7170
    ctx->r4 = ADD32(ctx->r4, -0X7170);
    after_4:
    // 0x80004E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004E08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004E0C: jr          $ra
    // 0x80004E10: nop

    return;
    // 0x80004E10: nop

;}
RECOMP_FUNC void Effect_WaterSpray_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80077A0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80077A10: jal         0x8005980C
    // 0x80077A14: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80077A14: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_0:
    // 0x80077A18: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80077A1C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80077A20: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80077A24: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80077A28: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80077A2C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80077A30: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80077A34: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80077A38: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80077A3C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80077A40: lh          $t0, 0x44($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X44);
    // 0x80077A44: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80077A48: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80077A4C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80077A50: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80077A54: lui         $t5, 0x301
    ctx->r13 = S32(0X301 << 16);
    // 0x80077A58: addiu       $t5, $t5, 0x6B30
    ctx->r13 = ADD32(ctx->r13, 0X6B30);
    // 0x80077A5C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80077A60: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80077A64: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80077A68: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80077A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077A74: jr          $ra
    // 0x80077A78: nop

    return;
    // 0x80077A78: nop

;}
RECOMP_FUNC void AudioSeq_InitSequencePlayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800168BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800168C0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800168C4: addiu       $a2, $t6, -0x1598
    ctx->r6 = ADD32(ctx->r14, -0X1598);
    // 0x800168C8: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x800168CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800168D0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800168D4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800168D8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800168DC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800168E0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800168E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800168E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800168EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800168F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800168F4: addiu       $a3, $a3, 0xFE8
    ctx->r7 = ADD32(ctx->r7, 0XFE8);
    // 0x800168F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800168FC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
L_80016900:
    // 0x80016900: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80016904: sw          $zero, 0x44($a1)
    MEM_W(0X44, ctx->r5) = 0;
    // 0x80016908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001690C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80016910: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x80016914: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80016918:
    // 0x80016918: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001691C: sw          $zero, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = 0;
    // 0x80016920: sw          $zero, 0x50($v1)
    MEM_W(0X50, ctx->r3) = 0;
    // 0x80016924: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x80016928: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001692C: bne         $v0, $a0, L_80016918
    if (ctx->r2 != ctx->r4) {
        // 0x80016930: sw          $zero, 0x38($v1)
        MEM_W(0X38, ctx->r3) = 0;
            goto L_80016918;
    }
    // 0x80016930: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x80016934: addiu       $a2, $a2, 0xC8
    ctx->r6 = ADD32(ctx->r6, 0XC8);
    // 0x80016938: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x8001693C: bne         $at, $zero, L_80016900
    if (ctx->r1 != 0) {
        // 0x80016940: addiu       $a1, $a1, 0xC8
        ctx->r5 = ADD32(ctx->r5, 0XC8);
            goto L_80016900;
    }
    // 0x80016940: addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    // 0x80016944: jal         0x8001463C
    // 0x80016948: nop

    AudioSeq_InitLayerFreelist(rdram, ctx);
        goto after_0;
    // 0x80016948: nop

    after_0:
    // 0x8001694C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80016950: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80016954: addiu       $v1, $v1, 0x2FE8
    ctx->r3 = ADD32(ctx->r3, 0X2FE8);
    // 0x80016958: addiu       $v0, $v0, 0xFE8
    ctx->r2 = ADD32(ctx->r2, 0XFE8);
L_8001695C:
    // 0x8001695C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80016960: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x80016964: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80016968: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x8001696C: sw          $zero, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = 0;
    // 0x80016970: bne         $at, $zero, L_8001695C
    if (ctx->r1 != 0) {
        // 0x80016974: sb          $t0, -0x80($v0)
        MEM_B(-0X80, ctx->r2) = ctx->r8;
            goto L_8001695C;
    }
    // 0x80016974: sb          $t0, -0x80($v0)
    MEM_B(-0X80, ctx->r2) = ctx->r8;
    // 0x80016978: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001697C: addiu       $s1, $t1, -0x1AC8
    ctx->r17 = ADD32(ctx->r9, -0X1AC8);
    // 0x80016980: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x80016984: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80016988: addiu       $s0, $s0, 0x2FE8
    ctx->r16 = ADD32(ctx->r16, 0X2FE8);
    // 0x8001698C: addiu       $s5, $s5, -0x1A30
    ctx->r21 = ADD32(ctx->r21, -0X1A30);
    // 0x80016990: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x80016994: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80016998: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8001699C: addiu       $s7, $zero, 0xE0
    ctx->r23 = ADD32(0, 0XE0);
    // 0x800169A0: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x800169A4: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_800169A8:
    // 0x800169A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800169AC: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
L_800169B0:
    // 0x800169B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800169B4: sw          $s0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r16;
    // 0x800169B8: sw          $s0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r16;
    // 0x800169BC: sw          $s0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r16;
    // 0x800169C0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800169C4: bne         $v0, $s2, L_800169B0
    if (ctx->r2 != ctx->r18) {
        // 0x800169C8: sw          $s0, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r16;
            goto L_800169B0;
    }
    // 0x800169C8: sw          $s0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r16;
    // 0x800169CC: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x800169D0: sb          $s6, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r22;
    // 0x800169D4: sb          $s7, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r23;
    // 0x800169D8: andi        $t4, $t2, 0xFF7F
    ctx->r12 = ctx->r10 & 0XFF7F;
    // 0x800169DC: andi        $t6, $t4, 0xDF
    ctx->r14 = ctx->r12 & 0XDF;
    // 0x800169E0: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
    // 0x800169E4: andi        $t8, $t6, 0xF7
    ctx->r24 = ctx->r14 & 0XF7;
    // 0x800169E8: sb          $t6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r14;
    // 0x800169EC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800169F0: andi        $t9, $t8, 0xEF
    ctx->r25 = ctx->r24 & 0XEF;
    // 0x800169F4: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800169F8: jal         0x80012864
    // 0x800169FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Audio_InitNoteLists(rdram, ctx);
        goto after_1;
    // 0x800169FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80016A00: jal         0x80016804
    // 0x80016A04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    AudioSeq_ResetSequencePlayer(rdram, ctx);
        goto after_2;
    // 0x80016A04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80016A08: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80016A0C: addiu       $s4, $s4, 0x14C
    ctx->r20 = ADD32(ctx->r20, 0X14C);
    // 0x80016A10: addiu       $s1, $s1, 0x14C
    ctx->r17 = ADD32(ctx->r17, 0X14C);
    // 0x80016A14: bne         $s3, $fp, L_800169A8
    if (ctx->r19 != ctx->r30) {
        // 0x80016A18: addiu       $s5, $s5, 0x14C
        ctx->r21 = ADD32(ctx->r21, 0X14C);
            goto L_800169A8;
    }
    // 0x80016A18: addiu       $s5, $s5, 0x14C
    ctx->r21 = ADD32(ctx->r21, 0X14C);
    // 0x80016A1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80016A20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016A24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016A28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80016A2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80016A30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80016A34: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80016A38: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80016A3C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80016A40: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80016A44: jr          $ra
    // 0x80016A48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80016A48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_enmy_80066A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A8C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80066A90: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80066A94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066A98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066A9C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80066AA0: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80066AA4: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80066AA8: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80066AAC: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80066AB0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80066AB4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80066AB8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80066ABC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80066AC0: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80066AC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066AC8: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80066ACC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80066AD0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x80066AD4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80066AD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80066ADC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80066AE0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80066AE4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80066AE8: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80066AEC: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x80066AF0: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
    // 0x80066AF4: bc1fl       L_80066B0C
    if (!c1cs) {
        // 0x80066AF8: lui         $at, 0x442A
        ctx->r1 = S32(0X442A << 16);
            goto L_80066B0C;
    }
    goto skip_0;
    // 0x80066AF8: lui         $at, 0x442A
    ctx->r1 = S32(0X442A << 16);
    skip_0:
    // 0x80066AFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066B00: nop

    // 0x80066B04: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80066B08: lui         $at, 0x442A
    ctx->r1 = S32(0X442A << 16);
L_80066B0C:
    // 0x80066B0C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80066B10: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80066B14: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80066B18: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x80066B1C: nop

    // 0x80066B20: bc1fl       L_80066BD4
    if (!c1cs) {
        // 0x80066B24: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80066BD4;
    }
    goto skip_1;
    // 0x80066B24: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80066B28: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80066B2C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80066B30: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80066B34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066B38: lwc1        $f22, 0x693C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X693C);
    // 0x80066B3C: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
L_80066B40:
    // 0x80066B40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80066B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80066B48: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80066B4C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80066B50: jal         0x80005E90
    // 0x80066B54: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80066B54: nop

    after_0:
    // 0x80066B58: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80066B5C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80066B60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80066B64: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80066B68: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80066B6C: jal         0x80005D44
    // 0x80066B70: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80066B70: nop

    after_1:
    // 0x80066B74: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80066B78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80066B7C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80066B80: jal         0x80006A20
    // 0x80066B84: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80066B84: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80066B88: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066B8C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80066B90: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80066B94: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80066B98: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80066B9C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80066BA0: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80066BA4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80066BA8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80066BAC: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80066BB0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80066BB4: jal         0x8007D0E0
    // 0x80066BB8: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_3;
    // 0x80066BB8: nop

    after_3:
    // 0x80066BBC: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x80066BC0: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x80066BC4: nop

    // 0x80066BC8: bc1tl       L_80066B40
    if (c1cs) {
        // 0x80066BCC: lwc1        $f16, 0x14($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
            goto L_80066B40;
    }
    goto skip_2;
    // 0x80066BCC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    skip_2:
    // 0x80066BD0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80066BD4:
    // 0x80066BD4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80066BD8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80066BDC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80066BE0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80066BE4: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80066BE8: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80066BEC: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80066BF0: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80066BF4: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80066BF8: jr          $ra
    // 0x80066BFC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80066BFC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_enmy2_8006D0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0F4: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8006D0F8: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8006D0FC: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8006D100: lui         $s7, 0x8016
    ctx->r23 = S32(0X8016 << 16);
    // 0x8006D104: lui         $fp, 0x8016
    ctx->r30 = S32(0X8016 << 16);
    // 0x8006D108: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8006D10C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8006D110: addiu       $fp, $fp, 0x1A80
    ctx->r30 = ADD32(ctx->r30, 0X1A80);
    // 0x8006D114: addiu       $s7, $s7, 0x1A7C
    ctx->r23 = ADD32(ctx->r23, 0X1A7C);
    // 0x8006D118: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8006D11C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8006D120: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8006D124: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8006D128: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8006D12C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8006D130: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8006D134: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8006D138: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8006D13C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8006D140: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8006D144: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8006D148: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
    // 0x8006D14C: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // 0x8006D150: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8006D154: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006D158: sw          $v0, 0x1A84($at)
    MEM_W(0X1A84, ctx->r1) = ctx->r2;
    // 0x8006D15C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8006D160: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8006D164: sw          $t6, -0x7ABC($at)
    MEM_W(-0X7ABC, ctx->r1) = ctx->r14;
    // 0x8006D168: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D16C: lwc1        $f28, 0x6B2C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X6B2C);
    // 0x8006D170: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D174: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8006D178: addiu       $s2, $s2, 0x1B00
    ctx->r18 = ADD32(ctx->r18, 0X1B00);
    // 0x8006D17C: lwc1        $f26, 0x6B30($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X6B30);
    // 0x8006D180: addiu       $s6, $zero, 0x5
    ctx->r22 = ADD32(0, 0X5);
    // 0x8006D184: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8006D188: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
L_8006D18C:
    // 0x8006D18C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D190: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8006D194: bne         $t7, $at, L_8006D2F8
    if (ctx->r15 != ctx->r1) {
        // 0x8006D198: nop
    
            goto L_8006D2F8;
    }
    // 0x8006D198: nop

    // 0x8006D19C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8006D1A0: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006D1A4: lwc1        $f4, 0x138($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X138);
    // 0x8006D1A8: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x8006D1AC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8006D1B0: nop

    // 0x8006D1B4: bc1f        L_8006D2F8
    if (!c1cs) {
        // 0x8006D1B8: nop
    
            goto L_8006D2F8;
    }
    // 0x8006D1B8: nop

    // 0x8006D1BC: lhu         $t9, 0x2($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X2);
    // 0x8006D1C0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006D1C4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006D1C8: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8006D1CC: lw          $s0, -0x69C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X69C);
    // 0x8006D1D0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006D1D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006D1D8: mfc1        $s4, $f16
    ctx->r20 = (int32_t)ctx->f16.u32l;
    // 0x8006D1DC: nop

    // 0x8006D1E0: beq         $s4, $zero, L_8006D2F8
    if (ctx->r20 == 0) {
        // 0x8006D1E4: nop
    
            goto L_8006D2F8;
    }
    // 0x8006D1E4: nop

    // 0x8006D1E8: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8006D1EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006D1F0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006D1F4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8006D1F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006D1FC: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8006D200: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006D204: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8006D208: jal         0x80005E90
    // 0x8006D20C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8006D20C: nop

    after_0:
    // 0x8006D210: lwc1        $f8, 0x4($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006D214: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006D218: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006D21C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006D220: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006D224: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006D228: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006D22C: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8006D230: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    // 0x8006D234: lwc1        $f18, 0x8($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006D238: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    // 0x8006D23C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006D240: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x8006D244: lwc1        $f8, 0xC($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8006D248: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006D24C: jal         0x80006A20
    // 0x8006D250: swc1        $f16, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x8006D250: swc1        $f16, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8006D254: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006D258: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8006D25C: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006D260: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8006D264: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006D268: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006D26C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006D270: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006D274: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006D278: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8006D27C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8006D280: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8006D284: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8006D288: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006D28C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006D290: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8006D294: blez        $s4, L_8006D2F8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8006D298: nop
    
            goto L_8006D2F8;
    }
    // 0x8006D298: nop

    // 0x8006D29C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8006D2A0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8006D2A4: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8006D2A8: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006D2AC: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006D2B0: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
L_8006D2B4:
    // 0x8006D2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006D2B8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8006D2BC: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x8006D2C0: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x8006D2C4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8006D2C8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8006D2CC: jal         0x800A78C4
    // 0x8006D2D0: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_2;
    // 0x8006D2D0: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    after_2:
    // 0x8006D2D4: beq         $v0, $zero, L_8006D2F0
    if (ctx->r2 == 0) {
        // 0x8006D2D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8006D2F0;
    }
    // 0x8006D2D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006D2DC: sw          $s3, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r19;
    // 0x8006D2E0: sw          $s3, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r19;
    // 0x8006D2E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006D2E8: sw          $s3, 0x1A84($at)
    MEM_W(0X1A84, ctx->r1) = ctx->r19;
    // 0x8006D2EC: sb          $s6, 0xC8($s5)
    MEM_B(0XC8, ctx->r21) = ctx->r22;
L_8006D2F0:
    // 0x8006D2F0: bne         $s1, $s4, L_8006D2B4
    if (ctx->r17 != ctx->r20) {
        // 0x8006D2F4: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_8006D2B4;
    }
    // 0x8006D2F4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_8006D2F8:
    // 0x8006D2F8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8006D2FC: addiu       $t5, $t5, 0x3400
    ctx->r13 = ADD32(ctx->r13, 0X3400);
    // 0x8006D300: addiu       $s2, $s2, 0x80
    ctx->r18 = ADD32(ctx->r18, 0X80);
    // 0x8006D304: bnel        $s2, $t5, L_8006D18C
    if (ctx->r18 != ctx->r13) {
        // 0x8006D308: lbu         $t7, 0x0($s2)
        ctx->r15 = MEM_BU(ctx->r18, 0X0);
            goto L_8006D18C;
    }
    goto skip_0;
    // 0x8006D308: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    skip_0:
    // 0x8006D30C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8006D310: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8006D314: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8006D318: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8006D31C: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8006D320: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8006D324: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8006D328: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8006D32C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8006D330: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8006D334: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8006D338: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8006D33C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8006D340: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8006D344: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8006D348: jr          $ra
    // 0x8006D34C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8006D34C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void Display_PlayerShadow_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80054304: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054308: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005430C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80054310: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80054314: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80054318: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005431C: lw          $t7, 0x23C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X23C);
    // 0x80054320: addiu       $a0, $a0, -0x5D58
    ctx->r4 = ADD32(ctx->r4, -0X5D58);
    // 0x80054324: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80054328: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8005432C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80054330: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80054334: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80054338: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005433C: jal         0x8009BC2C
    // 0x80054340: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80054340: nop

    after_0:
    // 0x80054344: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80054348: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005434C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054350: jal         0x800B8DD0
    // 0x80054354: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80054354: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_1:
    // 0x80054358: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8005435C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054360: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80054364: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054368: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005436C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80054370: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054374: lwc1        $f8, -0x5D58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5D58);
    // 0x80054378: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8005437C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80054380: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80054384: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80054388: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8005438C: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80054390: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80054394: nop

    // 0x80054398: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8005439C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800543A0: lwc1        $f18, 0x68($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X68);
    // 0x800543A4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800543A8: nop

    // 0x800543AC: bc1f        L_800543D0
    if (!c1cs) {
        // 0x800543B0: nop
    
            goto L_800543D0;
    }
    // 0x800543B0: nop

    // 0x800543B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800543B8: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x800543BC: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x800543C0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800543C4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800543C8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800543CC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_800543D0:
    // 0x800543D0: lw          $t6, 0x1A88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A88);
    // 0x800543D4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800543D8: bnel        $v1, $t6, L_80054408
    if (ctx->r3 != ctx->r14) {
        // 0x800543DC: sw          $t8, 0x23C($a2)
        MEM_W(0X23C, ctx->r6) = ctx->r24;
            goto L_80054408;
    }
    goto skip_0;
    // 0x800543DC: sw          $t8, 0x23C($a2)
    MEM_W(0X23C, ctx->r6) = ctx->r24;
    skip_0:
    // 0x800543E0: lwc1        $f4, 0x68($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X68);
    // 0x800543E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800543E8: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x800543EC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800543F0: nop

    // 0x800543F4: bc1fl       L_80054408
    if (!c1cs) {
        // 0x800543F8: sw          $t8, 0x23C($a2)
        MEM_W(0X23C, ctx->r6) = ctx->r24;
            goto L_80054408;
    }
    goto skip_1;
    // 0x800543F8: sw          $t8, 0x23C($a2)
    MEM_W(0X23C, ctx->r6) = ctx->r24;
    skip_1:
    // 0x800543FC: b           L_80054408
    // 0x80054400: sw          $t7, 0x23C($a2)
    MEM_W(0X23C, ctx->r6) = ctx->r15;
        goto L_80054408;
    // 0x80054400: sw          $t7, 0x23C($a2)
    MEM_W(0X23C, ctx->r6) = ctx->r15;
    // 0x80054404: sw          $t8, 0x23C($a2)
    MEM_W(0X23C, ctx->r6) = ctx->r24;
L_80054408:
    // 0x80054408: lw          $v0, 0x1CC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1CC);
    // 0x8005440C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80054410: beq         $v0, $zero, L_80054438
    if (ctx->r2 == 0) {
        // 0x80054414: nop
    
            goto L_80054438;
    }
    // 0x80054414: nop

    // 0x80054418: beq         $v0, $at, L_800544B4
    if (ctx->r2 == ctx->r1) {
        // 0x8005441C: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800544B4;
    }
    // 0x8005441C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054420: beq         $v0, $v1, L_80054648
    if (ctx->r2 == ctx->r3) {
        // 0x80054424: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80054648;
    }
    // 0x80054424: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80054428: beq         $v0, $at, L_80054598
    if (ctx->r2 == ctx->r1) {
        // 0x8005442C: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80054598;
    }
    // 0x8005442C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054430: b           L_8005464C
    // 0x80054434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005464C;
    // 0x80054434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80054438:
    // 0x80054438: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005443C: lwc1        $f0, 0x5E94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E94);
    // 0x80054440: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054444: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80054448: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005444C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80054450: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80054454: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80054458: jal         0x80005C34
    // 0x8005445C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8005445C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_2:
    // 0x80054460: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80054464: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054468: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005446C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80054470: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054474: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80054478: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005447C: jal         0x80005B00
    // 0x80054480: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80054480: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_3:
    // 0x80054484: jal         0x80006EB8
    // 0x80054488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80054488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8005448C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054490: lui         $t3, 0x103
    ctx->r11 = S32(0X103 << 16);
    // 0x80054494: addiu       $t3, $t3, 0x2780
    ctx->r11 = ADD32(ctx->r11, 0X2780);
    // 0x80054498: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005449C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800544A0: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800544A4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800544A8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800544AC: b           L_8005464C
    // 0x800544B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005464C;
    // 0x800544B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800544B4:
    // 0x800544B4: jal         0x80005708
    // 0x800544B8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x800544B8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x800544BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800544C0: lwc1        $f0, 0x5E98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E98);
    // 0x800544C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800544C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800544CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800544D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800544D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800544D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800544DC: jal         0x80005C34
    // 0x800544E0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x800544E0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_6:
    // 0x800544E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800544E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800544EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800544F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800544F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800544F8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800544FC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80054500: jal         0x80005B00
    // 0x80054504: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x80054504: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_7:
    // 0x80054508: jal         0x80006EB8
    // 0x8005450C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x8005450C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80054510: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054514: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80054518: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8005451C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054520: bne         $t6, $at, L_80054530
    if (ctx->r14 != ctx->r1) {
        // 0x80054524: nop
    
            goto L_80054530;
    }
    // 0x80054524: nop

    // 0x80054528: jal         0x800B8DD0
    // 0x8005452C: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x8005452C: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_9:
L_80054530:
    // 0x80054530: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80054534: lw          $t7, 0x78E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78E8);
    // 0x80054538: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8005453C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80054540: bne         $t7, $zero, L_8005456C
    if (ctx->r15 != 0) {
        // 0x80054544: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8005456C;
    }
    // 0x80054544: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054548: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005454C: lui         $t0, 0x301
    ctx->r8 = S32(0X301 << 16);
    // 0x80054550: addiu       $t0, $t0, -0x7F00
    ctx->r8 = ADD32(ctx->r8, -0X7F00);
    // 0x80054554: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054558: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005455C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80054560: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054564: b           L_80054588
    // 0x80054568: nop

        goto L_80054588;
    // 0x80054568: nop

L_8005456C:
    // 0x8005456C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054570: lui         $t3, 0x302
    ctx->r11 = S32(0X302 << 16);
    // 0x80054574: addiu       $t3, $t3, -0x1A90
    ctx->r11 = ADD32(ctx->r11, -0X1A90);
    // 0x80054578: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005457C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80054580: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80054584: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80054588:
    // 0x80054588: jal         0x80005740
    // 0x8005458C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8005458C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_10:
    // 0x80054590: b           L_8005464C
    // 0x80054594: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005464C;
    // 0x80054594: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80054598:
    // 0x80054598: jal         0x80005708
    // 0x8005459C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x8005459C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_11:
    // 0x800545A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800545A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800545A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800545AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800545B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800545B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800545B8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800545BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800545C0: jal         0x80005C34
    // 0x800545C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_12;
    // 0x800545C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_12:
    // 0x800545C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800545CC: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x800545D0: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x800545D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800545D8: jal         0x80005D44
    // 0x800545DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x800545DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x800545E0: jal         0x80006EB8
    // 0x800545E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x800545E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800545E8: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x800545EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800545F0: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x800545F4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800545F8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800545FC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80054600: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80054604: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80054608: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005460C: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x80054610: addiu       $t9, $t9, -0x5760
    ctx->r25 = ADD32(ctx->r25, -0X5760);
    // 0x80054614: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80054618: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005461C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80054620: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80054624: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054628: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x8005462C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054630: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80054634: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80054638: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8005463C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80054640: jal         0x80005740
    // 0x80054644: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x80054644: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_15:
L_80054648:
    // 0x80054648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005464C:
    // 0x8005464C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80054650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80054654: jr          $ra
    // 0x80054658: nop

    return;
    // 0x80054658: nop

;}
RECOMP_FUNC void Save_ReadData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002BF0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80002BF4: lbu         $t6, 0x7E80($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7E80);
    // 0x80002BF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80002BFC: bne         $t6, $zero, L_80002C2C
    if (ctx->r14 != 0) {
        // 0x80002C00: nop
    
            goto L_80002C2C;
    }
    // 0x80002C00: nop

    // 0x80002C04: jal         0x800072E0
    // 0x80002C08: addiu       $a0, $a0, 0x4F60
    ctx->r4 = ADD32(ctx->r4, 0X4F60);
    Save_ReadEeprom(rdram, ctx);
        goto after_0;
    // 0x80002C08: addiu       $a0, $a0, 0x4F60
    ctx->r4 = ADD32(ctx->r4, 0X4F60);
    after_0:
    // 0x80002C0C: bne         $v0, $zero, L_80002C2C
    if (ctx->r2 != 0) {
        // 0x80002C10: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80002C2C;
    }
    // 0x80002C10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002C14: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x80002C18: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80002C1C: jal         0x80020720
    // 0x80002C20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002C20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80002C24: b           L_80002C44
    // 0x80002C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80002C44;
    // 0x80002C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002C2C:
    // 0x80002C2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002C30: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x80002C34: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80002C38: jal         0x80020720
    // 0x80002C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80002C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80002C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002C44:
    // 0x80002C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002C48: jr          $ra
    // 0x80002C4C: nop

    return;
    // 0x80002C4C: nop

;}
RECOMP_FUNC void Effect_Effect345_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007879C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800787A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800787A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800787A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800787AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800787B0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800787B4: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x800787B8: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x800787BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800787C0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800787C4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800787C8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800787CC: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x800787D0: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x800787D4: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x800787D8: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x800787DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800787E0: jal         0x800B9B38
    // 0x800787E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_60(rdram, ctx);
        goto after_0;
    // 0x800787E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800787E8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800787EC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800787F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800787F4: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x800787F8: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
    // 0x800787FC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078800: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078804: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80078808: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007880C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078810: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80078814: lwc1        $f4, 0x7314($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7314);
    // 0x80078818: lwc1        $f0, 0x70($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X70);
    // 0x8007881C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80078820: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80078824: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80078828: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007882C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80078830: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80078834: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80078838: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007883C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80078840: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80078844: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80078848: jal         0x80005C34
    // 0x8007884C: nop

    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8007884C: nop

    after_1:
    // 0x80078850: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80078854: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x80078858: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8007885C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80078860: jal         0x80005D44
    // 0x80078864: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x80078864: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80078868: jal         0x80006EB8
    // 0x8007886C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8007886C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80078870: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078874: lui         $t5, 0x103
    ctx->r13 = S32(0X103 << 16);
    // 0x80078878: addiu       $t5, $t5, -0x6880
    ctx->r13 = ADD32(ctx->r13, -0X6880);
    // 0x8007887C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80078880: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80078884: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80078888: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8007888C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80078890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078894: jal         0x800B8DD0
    // 0x80078898: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80078898: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x8007889C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800788A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800788A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800788A8: jr          $ra
    // 0x800788AC: nop

    return;
    // 0x800788AC: nop

;}
RECOMP_FUNC void ActorEvent_ProcessScript(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D36C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006D370: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8006D374: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8006D378: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8006D37C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006D380: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8006D384: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8006D388: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D38C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8006D390: lwc1        $f20, 0x6B34($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6B34);
    // 0x8006D394: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006D398: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8006D39C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8006D3A0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8006D3A4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8006D3A8: lui         $s3, 0xFF
    ctx->r19 = S32(0XFF << 16);
    // 0x8006D3AC: lui         $fp, 0x8017
    ctx->r30 = S32(0X8017 << 16);
    // 0x8006D3B0: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8006D3B4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8006D3B8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8006D3BC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8006D3C0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006D3C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006D3C8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8006D3CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006D3D0: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x8006D3D4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8006D3D8: addiu       $s7, $zero, 0x64
    ctx->r23 = ADD32(0, 0X64);
    // 0x8006D3DC: addiu       $fp, $fp, 0x7F10
    ctx->r30 = ADD32(ctx->r30, 0X7F10);
    // 0x8006D3E0: ori         $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 | 0XFFFF;
    // 0x8006D3E4: addiu       $s2, $s2, 0x1FD0
    ctx->r18 = ADD32(ctx->r18, 0X1FD0);
    // 0x8006D3E8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8006D3EC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8006D3F0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
L_8006D3F4:
    // 0x8006D3F4: sltiu       $at, $v0, 0xE
    ctx->r1 = ctx->r2 < 0XE ? 1 : 0;
    // 0x8006D3F8: beq         $at, $zero, L_8006D67C
    if (ctx->r1 == 0) {
        // 0x8006D3FC: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8006D67C;
    }
    // 0x8006D3FC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8006D400: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D404: addu        $at, $at, $t6
    gpr jr_addend_8006D40C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006D408: lw          $t6, 0x6B38($at)
    ctx->r14 = ADD32(ctx->r1, 0X6B38);
    // 0x8006D40C: jr          $t6
    // 0x8006D410: nop

    switch (jr_addend_8006D40C >> 2) {
        case 0: goto L_8006D440; break;
        case 1: goto L_8006D46C; break;
        case 2: goto L_8006D4F0; break;
        case 3: goto L_8006D548; break;
        case 4: goto L_8006D51C; break;
        case 5: goto L_8006D574; break;
        case 6: goto L_8006D5F8; break;
        case 7: goto L_8006D5A0; break;
        case 8: goto L_8006D5CC; break;
        case 9: goto L_8006D414; break;
        case 10: goto L_8006D650; break;
        case 11: goto L_8006D624; break;
        case 12: goto L_8006D4C4; break;
        case 13: goto L_8006D498; break;
        default: switch_error(__func__, 0x8006D40C, 0x800D6B38);
    }
    // 0x8006D410: nop

L_8006D414:
    // 0x8006D414: lui         $v0, 0xC03
    ctx->r2 = S32(0XC03 << 16);
    // 0x8006D418: addiu       $v0, $v0, 0x7E3C
    ctx->r2 = ADD32(ctx->r2, 0X7E3C);
    // 0x8006D41C: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8006D420: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x8006D424: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006D428: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8006D42C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8006D430: and         $t2, $v0, $s3
    ctx->r10 = ctx->r2 & ctx->r19;
    // 0x8006D434: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006D438: b           L_8006D6A4
    // 0x8006D43C: addu        $v1, $t3, $s4
    ctx->r3 = ADD32(ctx->r11, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D43C: addu        $v1, $t3, $s4
    ctx->r3 = ADD32(ctx->r11, ctx->r20);
L_8006D440:
    // 0x8006D440: lui         $v0, 0x604
    ctx->r2 = S32(0X604 << 16);
    // 0x8006D444: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x8006D448: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x8006D44C: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x8006D450: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006D454: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8006D458: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006D45C: and         $t9, $v0, $s3
    ctx->r25 = ctx->r2 & ctx->r19;
    // 0x8006D460: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8006D464: b           L_8006D6A4
    // 0x8006D468: addu        $v1, $t0, $s4
    ctx->r3 = ADD32(ctx->r8, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D468: addu        $v1, $t0, $s4
    ctx->r3 = ADD32(ctx->r8, ctx->r20);
L_8006D46C:
    // 0x8006D46C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8006D470: addiu       $v0, $v0, -0xC54
    ctx->r2 = ADD32(ctx->r2, -0XC54);
    // 0x8006D474: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x8006D478: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8006D47C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8006D480: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8006D484: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8006D488: and         $t6, $v0, $s3
    ctx->r14 = ctx->r2 & ctx->r19;
    // 0x8006D48C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8006D490: b           L_8006D6A4
    // 0x8006D494: addu        $v1, $t7, $s4
    ctx->r3 = ADD32(ctx->r15, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D494: addu        $v1, $t7, $s4
    ctx->r3 = ADD32(ctx->r15, ctx->r20);
L_8006D498:
    // 0x8006D498: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8006D49C: addiu       $v0, $v0, 0x8B8
    ctx->r2 = ADD32(ctx->r2, 0X8B8);
    // 0x8006D4A0: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8006D4A4: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8006D4A8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006D4AC: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x8006D4B0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8006D4B4: and         $t3, $v0, $s3
    ctx->r11 = ctx->r2 & ctx->r19;
    // 0x8006D4B8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006D4BC: b           L_8006D6A4
    // 0x8006D4C0: addu        $v1, $t4, $s4
    ctx->r3 = ADD32(ctx->r12, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D4C0: addu        $v1, $t4, $s4
    ctx->r3 = ADD32(ctx->r12, ctx->r20);
L_8006D4C4:
    // 0x8006D4C4: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8006D4C8: addiu       $v0, $v0, 0x631C
    ctx->r2 = ADD32(ctx->r2, 0X631C);
    // 0x8006D4CC: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8006D4D0: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8006D4D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006D4D8: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8006D4DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006D4E0: and         $t0, $v0, $s3
    ctx->r8 = ctx->r2 & ctx->r19;
    // 0x8006D4E4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006D4E8: b           L_8006D6A4
    // 0x8006D4EC: addu        $v1, $t1, $s4
    ctx->r3 = ADD32(ctx->r9, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D4EC: addu        $v1, $t1, $s4
    ctx->r3 = ADD32(ctx->r9, ctx->r20);
L_8006D4F0:
    // 0x8006D4F0: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8006D4F4: addiu       $v0, $v0, 0x20D0
    ctx->r2 = ADD32(ctx->r2, 0X20D0);
    // 0x8006D4F8: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8006D4FC: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x8006D500: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006D504: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8006D508: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8006D50C: and         $t7, $v0, $s3
    ctx->r15 = ctx->r2 & ctx->r19;
    // 0x8006D510: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006D514: b           L_8006D6A4
    // 0x8006D518: addu        $v1, $t8, $s4
    ctx->r3 = ADD32(ctx->r24, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D518: addu        $v1, $t8, $s4
    ctx->r3 = ADD32(ctx->r24, ctx->r20);
L_8006D51C:
    // 0x8006D51C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8006D520: addiu       $v0, $v0, -0x7604
    ctx->r2 = ADD32(ctx->r2, -0X7604);
    // 0x8006D524: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8006D528: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x8006D52C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8006D530: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x8006D534: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8006D538: and         $t4, $v0, $s3
    ctx->r12 = ctx->r2 & ctx->r19;
    // 0x8006D53C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8006D540: b           L_8006D6A4
    // 0x8006D544: addu        $v1, $t5, $s4
    ctx->r3 = ADD32(ctx->r13, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D544: addu        $v1, $t5, $s4
    ctx->r3 = ADD32(ctx->r13, ctx->r20);
L_8006D548:
    // 0x8006D548: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x8006D54C: addiu       $v0, $v0, 0x7F50
    ctx->r2 = ADD32(ctx->r2, 0X7F50);
    // 0x8006D550: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8006D554: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8006D558: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006D55C: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8006D560: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006D564: and         $t1, $v0, $s3
    ctx->r9 = ctx->r2 & ctx->r19;
    // 0x8006D568: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006D56C: b           L_8006D6A4
    // 0x8006D570: addu        $v1, $t2, $s4
    ctx->r3 = ADD32(ctx->r10, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D570: addu        $v1, $t2, $s4
    ctx->r3 = ADD32(ctx->r10, ctx->r20);
L_8006D574:
    // 0x8006D574: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8006D578: addiu       $v0, $v0, 0x2E18
    ctx->r2 = ADD32(ctx->r2, 0X2E18);
    // 0x8006D57C: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x8006D580: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x8006D584: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8006D588: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x8006D58C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8006D590: and         $t8, $v0, $s3
    ctx->r24 = ctx->r2 & ctx->r19;
    // 0x8006D594: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006D598: b           L_8006D6A4
    // 0x8006D59C: addu        $v1, $t9, $s4
    ctx->r3 = ADD32(ctx->r25, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D59C: addu        $v1, $t9, $s4
    ctx->r3 = ADD32(ctx->r25, ctx->r20);
L_8006D5A0:
    // 0x8006D5A0: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x8006D5A4: addiu       $v0, $v0, 0xDD0
    ctx->r2 = ADD32(ctx->r2, 0XDD0);
    // 0x8006D5A8: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x8006D5AC: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x8006D5B0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8006D5B4: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x8006D5B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006D5BC: and         $t5, $v0, $s3
    ctx->r13 = ctx->r2 & ctx->r19;
    // 0x8006D5C0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8006D5C4: b           L_8006D6A4
    // 0x8006D5C8: addu        $v1, $t6, $s4
    ctx->r3 = ADD32(ctx->r14, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D5C8: addu        $v1, $t6, $s4
    ctx->r3 = ADD32(ctx->r14, ctx->r20);
L_8006D5CC:
    // 0x8006D5CC: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8006D5D0: addiu       $v0, $v0, -0x5540
    ctx->r2 = ADD32(ctx->r2, -0X5540);
    // 0x8006D5D4: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8006D5D8: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x8006D5DC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006D5E0: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8006D5E4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8006D5E8: and         $t2, $v0, $s3
    ctx->r10 = ctx->r2 & ctx->r19;
    // 0x8006D5EC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006D5F0: b           L_8006D6A4
    // 0x8006D5F4: addu        $v1, $t3, $s4
    ctx->r3 = ADD32(ctx->r11, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D5F4: addu        $v1, $t3, $s4
    ctx->r3 = ADD32(ctx->r11, ctx->r20);
L_8006D5F8:
    // 0x8006D5F8: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x8006D5FC: addiu       $v0, $v0, -0x4E1C
    ctx->r2 = ADD32(ctx->r2, -0X4E1C);
    // 0x8006D600: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x8006D604: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x8006D608: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006D60C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8006D610: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006D614: and         $t9, $v0, $s3
    ctx->r25 = ctx->r2 & ctx->r19;
    // 0x8006D618: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8006D61C: b           L_8006D6A4
    // 0x8006D620: addu        $v1, $t0, $s4
    ctx->r3 = ADD32(ctx->r8, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D620: addu        $v1, $t0, $s4
    ctx->r3 = ADD32(ctx->r8, ctx->r20);
L_8006D624:
    // 0x8006D624: lui         $v0, 0x604
    ctx->r2 = S32(0X604 << 16);
    // 0x8006D628: addiu       $v0, $v0, -0x7E28
    ctx->r2 = ADD32(ctx->r2, -0X7E28);
    // 0x8006D62C: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x8006D630: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8006D634: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8006D638: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8006D63C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8006D640: and         $t6, $v0, $s3
    ctx->r14 = ctx->r2 & ctx->r19;
    // 0x8006D644: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8006D648: b           L_8006D6A4
    // 0x8006D64C: addu        $v1, $t7, $s4
    ctx->r3 = ADD32(ctx->r15, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D64C: addu        $v1, $t7, $s4
    ctx->r3 = ADD32(ctx->r15, ctx->r20);
L_8006D650:
    // 0x8006D650: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x8006D654: addiu       $v0, $v0, -0x64CC
    ctx->r2 = ADD32(ctx->r2, -0X64CC);
    // 0x8006D658: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8006D65C: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8006D660: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006D664: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x8006D668: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8006D66C: and         $t3, $v0, $s3
    ctx->r11 = ctx->r2 & ctx->r19;
    // 0x8006D670: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006D674: b           L_8006D6A4
    // 0x8006D678: addu        $v1, $t4, $s4
    ctx->r3 = ADD32(ctx->r12, ctx->r20);
        goto L_8006D6A4;
    // 0x8006D678: addu        $v1, $t4, $s4
    ctx->r3 = ADD32(ctx->r12, ctx->r20);
L_8006D67C:
    // 0x8006D67C: lui         $v0, 0x604
    ctx->r2 = S32(0X604 << 16);
    // 0x8006D680: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x8006D684: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8006D688: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8006D68C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006D690: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8006D694: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006D698: and         $t0, $v0, $s3
    ctx->r8 = ctx->r2 & ctx->r19;
    // 0x8006D69C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006D6A0: addu        $v1, $t1, $s4
    ctx->r3 = ADD32(ctx->r9, ctx->r20);
L_8006D6A4:
    // 0x8006D6A4: lh          $t2, 0xE4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE4);
    // 0x8006D6A8: lh          $a1, 0xE6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XE6);
    // 0x8006D6AC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8006D6B0: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8006D6B4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8006D6B8: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x8006D6BC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8006D6C0: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8006D6C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006D6C8: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8006D6CC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006D6D0: and         $t5, $a0, $s3
    ctx->r13 = ctx->r4 & ctx->r19;
    // 0x8006D6D4: addu        $t1, $t5, $t0
    ctx->r9 = ADD32(ctx->r13, ctx->r8);
    // 0x8006D6D8: addu        $s1, $t1, $s4
    ctx->r17 = ADD32(ctx->r9, ctx->r20);
    // 0x8006D6DC: addu        $a2, $s1, $t2
    ctx->r6 = ADD32(ctx->r17, ctx->r10);
    // 0x8006D6E0: lhu         $a3, 0x0($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X0);
    // 0x8006D6E4: andi        $v0, $a3, 0xFE00
    ctx->r2 = ctx->r7 & 0XFE00;
    // 0x8006D6E8: slti        $at, $v0, 0x5801
    ctx->r1 = SIGNED(ctx->r2) < 0X5801 ? 1 : 0;
    // 0x8006D6EC: bne         $at, $zero, L_8006D818
    if (ctx->r1 != 0) {
        // 0x8006D6F0: ori         $at, $zero, 0xE001
        ctx->r1 = 0 | 0XE001;
            goto L_8006D818;
    }
    // 0x8006D6F0: ori         $at, $zero, 0xE001
    ctx->r1 = 0 | 0XE001;
    // 0x8006D6F4: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8006D6F8: bne         $at, $zero, L_8006D78C
    if (ctx->r1 != 0) {
        // 0x8006D6FC: ori         $at, $zero, 0xF201
        ctx->r1 = 0 | 0XF201;
            goto L_8006D78C;
    }
    // 0x8006D6FC: ori         $at, $zero, 0xF201
    ctx->r1 = 0 | 0XF201;
    // 0x8006D700: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8006D704: bne         $at, $zero, L_8006D74C
    if (ctx->r1 != 0) {
        // 0x8006D708: ori         $at, $zero, 0xF400
        ctx->r1 = 0 | 0XF400;
            goto L_8006D74C;
    }
    // 0x8006D708: ori         $at, $zero, 0xF400
    ctx->r1 = 0 | 0XF400;
    // 0x8006D70C: beq         $v0, $at, L_8006E228
    if (ctx->r2 == ctx->r1) {
        // 0x8006D710: lui         $a0, 0x1032
        ctx->r4 = S32(0X1032 << 16);
            goto L_8006E228;
    }
    // 0x8006D710: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x8006D714: ori         $at, $zero, 0xF800
    ctx->r1 = 0 | 0XF800;
    // 0x8006D718: beq         $v0, $at, L_8006E2A8
    if (ctx->r2 == ctx->r1) {
        // 0x8006D71C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8006E2A8;
    }
    // 0x8006D71C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006D720: ori         $at, $zero, 0xFA00
    ctx->r1 = 0 | 0XFA00;
    // 0x8006D724: beq         $v0, $at, L_8006E3B0
    if (ctx->r2 == ctx->r1) {
        // 0x8006D728: addiu       $t1, $a1, 0x2
        ctx->r9 = ADD32(ctx->r5, 0X2);
            goto L_8006E3B0;
    }
    // 0x8006D728: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
    // 0x8006D72C: ori         $at, $zero, 0xFC00
    ctx->r1 = 0 | 0XFC00;
    // 0x8006D730: beq         $v0, $at, L_8006E598
    if (ctx->r2 == ctx->r1) {
        // 0x8006D734: addiu       $t9, $a1, 0x2
        ctx->r25 = ADD32(ctx->r5, 0X2);
            goto L_8006E598;
    }
    // 0x8006D734: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x8006D738: ori         $at, $zero, 0xFE00
    ctx->r1 = 0 | 0XFE00;
    // 0x8006D73C: beq         $v0, $at, L_8006D944
    if (ctx->r2 == ctx->r1) {
        // 0x8006D740: addiu       $t3, $zero, 0xC8
        ctx->r11 = ADD32(0, 0XC8);
            goto L_8006D944;
    }
    // 0x8006D740: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8006D744: b           L_8006EA18
    // 0x8006D748: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D748: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D74C:
    // 0x8006D74C: ori         $at, $zero, 0xE200
    ctx->r1 = 0 | 0XE200;
    // 0x8006D750: beq         $v0, $at, L_8006DF20
    if (ctx->r2 == ctx->r1) {
        // 0x8006D754: ori         $at, $zero, 0xE800
        ctx->r1 = 0 | 0XE800;
            goto L_8006DF20;
    }
    // 0x8006D754: ori         $at, $zero, 0xE800
    ctx->r1 = 0 | 0XE800;
    // 0x8006D758: beq         $v0, $at, L_8006E060
    if (ctx->r2 == ctx->r1) {
        // 0x8006D75C: addiu       $t9, $a1, 0x2
        ctx->r25 = ADD32(ctx->r5, 0X2);
            goto L_8006E060;
    }
    // 0x8006D75C: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x8006D760: ori         $at, $zero, 0xEC00
    ctx->r1 = 0 | 0XEC00;
    // 0x8006D764: beq         $v0, $at, L_8006E078
    if (ctx->r2 == ctx->r1) {
        // 0x8006D768: ori         $at, $zero, 0xEE00
        ctx->r1 = 0 | 0XEE00;
            goto L_8006E078;
    }
    // 0x8006D768: ori         $at, $zero, 0xEE00
    ctx->r1 = 0 | 0XEE00;
    // 0x8006D76C: beq         $v0, $at, L_8006E104
    if (ctx->r2 == ctx->r1) {
        // 0x8006D770: ori         $at, $zero, 0xF000
        ctx->r1 = 0 | 0XF000;
            goto L_8006E104;
    }
    // 0x8006D770: ori         $at, $zero, 0xF000
    ctx->r1 = 0 | 0XF000;
    // 0x8006D774: beq         $v0, $at, L_8006E0A0
    if (ctx->r2 == ctx->r1) {
        // 0x8006D778: ori         $at, $zero, 0xF200
        ctx->r1 = 0 | 0XF200;
            goto L_8006E0A0;
    }
    // 0x8006D778: ori         $at, $zero, 0xF200
    ctx->r1 = 0 | 0XF200;
    // 0x8006D77C: beq         $v0, $at, L_8006E25C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D780: andi        $t8, $a3, 0x1FF
        ctx->r24 = ctx->r7 & 0X1FF;
            goto L_8006E25C;
    }
    // 0x8006D780: andi        $t8, $a3, 0x1FF
    ctx->r24 = ctx->r7 & 0X1FF;
    // 0x8006D784: b           L_8006EA18
    // 0x8006D788: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D788: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D78C:
    // 0x8006D78C: slti        $at, $v0, 0x7201
    ctx->r1 = SIGNED(ctx->r2) < 0X7201 ? 1 : 0;
    // 0x8006D790: bne         $at, $zero, L_8006D7D8
    if (ctx->r1 != 0) {
        // 0x8006D794: addiu       $at, $zero, 0x7400
        ctx->r1 = ADD32(0, 0X7400);
            goto L_8006D7D8;
    }
    // 0x8006D794: addiu       $at, $zero, 0x7400
    ctx->r1 = ADD32(0, 0X7400);
    // 0x8006D798: beq         $v0, $at, L_8006E1D8
    if (ctx->r2 == ctx->r1) {
        // 0x8006D79C: addiu       $a0, $s0, 0x100
        ctx->r4 = ADD32(ctx->r16, 0X100);
            goto L_8006E1D8;
    }
    // 0x8006D79C: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    // 0x8006D7A0: addiu       $at, $zero, 0x7600
    ctx->r1 = ADD32(0, 0X7600);
    // 0x8006D7A4: beq         $v0, $at, L_8006E200
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7A8: addiu       $a0, $s0, 0x100
        ctx->r4 = ADD32(ctx->r16, 0X100);
            goto L_8006E200;
    }
    // 0x8006D7A8: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    // 0x8006D7AC: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8006D7B0: beq         $v0, $at, L_8006E570
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7B4: ori         $at, $zero, 0xD000
        ctx->r1 = 0 | 0XD000;
            goto L_8006E570;
    }
    // 0x8006D7B4: ori         $at, $zero, 0xD000
    ctx->r1 = 0 | 0XD000;
    // 0x8006D7B8: beq         $v0, $at, L_8006D974
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7BC: ori         $at, $zero, 0xD200
        ctx->r1 = 0 | 0XD200;
            goto L_8006D974;
    }
    // 0x8006D7BC: ori         $at, $zero, 0xD200
    ctx->r1 = 0 | 0XD200;
    // 0x8006D7C0: beq         $v0, $at, L_8006DEE4
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7C4: ori         $at, $zero, 0xE000
        ctx->r1 = 0 | 0XE000;
            goto L_8006DEE4;
    }
    // 0x8006D7C4: ori         $at, $zero, 0xE000
    ctx->r1 = 0 | 0XE000;
    // 0x8006D7C8: beql        $v0, $at, L_8006DFA8
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7CC: lhu         $v0, 0x2($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X2);
            goto L_8006DFA8;
    }
    goto skip_0;
    // 0x8006D7CC: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x8006D7D0: b           L_8006EA18
    // 0x8006D7D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D7D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D7D8:
    // 0x8006D7D8: addiu       $at, $zero, 0x5A00
    ctx->r1 = ADD32(0, 0X5A00);
    // 0x8006D7DC: beq         $v0, $at, L_8006E484
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7E0: addiu       $at, $zero, 0x5C00
        ctx->r1 = ADD32(0, 0X5C00);
            goto L_8006E484;
    }
    // 0x8006D7E0: addiu       $at, $zero, 0x5C00
    ctx->r1 = ADD32(0, 0X5C00);
    // 0x8006D7E4: beq         $v0, $at, L_8006E508
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7E8: addiu       $at, $zero, 0x5E00
        ctx->r1 = ADD32(0, 0X5E00);
            goto L_8006E508;
    }
    // 0x8006D7E8: addiu       $at, $zero, 0x5E00
    ctx->r1 = ADD32(0, 0X5E00);
    // 0x8006D7EC: beq         $v0, $at, L_8006E53C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7F0: andi        $t2, $a3, 0x1FF
        ctx->r10 = ctx->r7 & 0X1FF;
            goto L_8006E53C;
    }
    // 0x8006D7F0: andi        $t2, $a3, 0x1FF
    ctx->r10 = ctx->r7 & 0X1FF;
    // 0x8006D7F4: addiu       $at, $zero, 0x6000
    ctx->r1 = ADD32(0, 0X6000);
    // 0x8006D7F8: beq         $v0, $at, L_8006E5F4
    if (ctx->r2 == ctx->r1) {
        // 0x8006D7FC: addiu       $at, $zero, 0x7000
        ctx->r1 = ADD32(0, 0X7000);
            goto L_8006E5F4;
    }
    // 0x8006D7FC: addiu       $at, $zero, 0x7000
    ctx->r1 = ADD32(0, 0X7000);
    // 0x8006D800: beq         $v0, $at, L_8006E170
    if (ctx->r2 == ctx->r1) {
        // 0x8006D804: addiu       $at, $zero, 0x7200
        ctx->r1 = ADD32(0, 0X7200);
            goto L_8006E170;
    }
    // 0x8006D804: addiu       $at, $zero, 0x7200
    ctx->r1 = ADD32(0, 0X7200);
    // 0x8006D808: beql        $v0, $at, L_8006E1AC
    if (ctx->r2 == ctx->r1) {
        // 0x8006D80C: lhu         $t6, 0x2($a2)
        ctx->r14 = MEM_HU(ctx->r6, 0X2);
            goto L_8006E1AC;
    }
    goto skip_1;
    // 0x8006D80C: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    skip_1:
    // 0x8006D810: b           L_8006EA18
    // 0x8006D814: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D814: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D818:
    // 0x8006D818: slti        $at, $v0, 0x2201
    ctx->r1 = SIGNED(ctx->r2) < 0X2201 ? 1 : 0;
    // 0x8006D81C: bne         $at, $zero, L_8006D8BC
    if (ctx->r1 != 0) {
        // 0x8006D820: slti        $at, $v0, 0x3201
        ctx->r1 = SIGNED(ctx->r2) < 0X3201 ? 1 : 0;
            goto L_8006D8BC;
    }
    // 0x8006D820: slti        $at, $v0, 0x3201
    ctx->r1 = SIGNED(ctx->r2) < 0X3201 ? 1 : 0;
    // 0x8006D824: bne         $at, $zero, L_8006D870
    if (ctx->r1 != 0) {
        // 0x8006D828: andi        $t2, $a3, 0x1FF
        ctx->r10 = ctx->r7 & 0X1FF;
            goto L_8006D870;
    }
    // 0x8006D828: andi        $t2, $a3, 0x1FF
    ctx->r10 = ctx->r7 & 0X1FF;
    // 0x8006D82C: addiu       $at, $zero, 0x5000
    ctx->r1 = ADD32(0, 0X5000);
    // 0x8006D830: beq         $v0, $at, L_8006E3C4
    if (ctx->r2 == ctx->r1) {
        // 0x8006D834: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_8006E3C4;
    }
    // 0x8006D834: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8006D838: addiu       $at, $zero, 0x5200
    ctx->r1 = ADD32(0, 0X5200);
    // 0x8006D83C: beq         $v0, $at, L_8006E3F4
    if (ctx->r2 == ctx->r1) {
        // 0x8006D840: addiu       $t8, $zero, 0x7
        ctx->r24 = ADD32(0, 0X7);
            goto L_8006E3F4;
    }
    // 0x8006D840: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8006D844: addiu       $at, $zero, 0x5400
    ctx->r1 = ADD32(0, 0X5400);
    // 0x8006D848: beq         $v0, $at, L_8006E424
    if (ctx->r2 == ctx->r1) {
        // 0x8006D84C: addiu       $t3, $zero, 0x8
        ctx->r11 = ADD32(0, 0X8);
            goto L_8006E424;
    }
    // 0x8006D84C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8006D850: addiu       $at, $zero, 0x5600
    ctx->r1 = ADD32(0, 0X5600);
    // 0x8006D854: beq         $v0, $at, L_8006E454
    if (ctx->r2 == ctx->r1) {
        // 0x8006D858: addiu       $t8, $zero, 0x9
        ctx->r24 = ADD32(0, 0X9);
            goto L_8006E454;
    }
    // 0x8006D858: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8006D85C: addiu       $at, $zero, 0x5800
    ctx->r1 = ADD32(0, 0X5800);
    // 0x8006D860: beq         $v0, $at, L_8006E4D8
    if (ctx->r2 == ctx->r1) {
        // 0x8006D864: addiu       $t9, $zero, 0xD
        ctx->r25 = ADD32(0, 0XD);
            goto L_8006E4D8;
    }
    // 0x8006D864: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x8006D868: b           L_8006EA18
    // 0x8006D86C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D86C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D870:
    // 0x8006D870: addiu       $at, $zero, 0x2400
    ctx->r1 = ADD32(0, 0X2400);
    // 0x8006D874: beq         $v0, $at, L_8006E8BC
    if (ctx->r2 == ctx->r1) {
        // 0x8006D878: addiu       $at, $zero, 0x2600
        ctx->r1 = ADD32(0, 0X2600);
            goto L_8006E8BC;
    }
    // 0x8006D878: addiu       $at, $zero, 0x2600
    ctx->r1 = ADD32(0, 0X2600);
    // 0x8006D87C: beq         $v0, $at, L_8006E908
    if (ctx->r2 == ctx->r1) {
        // 0x8006D880: andi        $t5, $a3, 0x1FF
        ctx->r13 = ctx->r7 & 0X1FF;
            goto L_8006E908;
    }
    // 0x8006D880: andi        $t5, $a3, 0x1FF
    ctx->r13 = ctx->r7 & 0X1FF;
    // 0x8006D884: addiu       $at, $zero, 0x2800
    ctx->r1 = ADD32(0, 0X2800);
    // 0x8006D888: beq         $v0, $at, L_8006E954
    if (ctx->r2 == ctx->r1) {
        // 0x8006D88C: andi        $t3, $a3, 0x1FF
        ctx->r11 = ctx->r7 & 0X1FF;
            goto L_8006E954;
    }
    // 0x8006D88C: andi        $t3, $a3, 0x1FF
    ctx->r11 = ctx->r7 & 0X1FF;
    // 0x8006D890: addiu       $at, $zero, 0x2A00
    ctx->r1 = ADD32(0, 0X2A00);
    // 0x8006D894: beq         $v0, $at, L_8006E9A0
    if (ctx->r2 == ctx->r1) {
        // 0x8006D898: andi        $t7, $a3, 0x1FF
        ctx->r15 = ctx->r7 & 0X1FF;
            goto L_8006E9A0;
    }
    // 0x8006D898: andi        $t7, $a3, 0x1FF
    ctx->r15 = ctx->r7 & 0X1FF;
    // 0x8006D89C: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8006D8A0: beq         $v0, $at, L_8006E9EC
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8A4: addiu       $t9, $a1, 0x2
        ctx->r25 = ADD32(ctx->r5, 0X2);
            goto L_8006E9EC;
    }
    // 0x8006D8A4: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x8006D8A8: addiu       $at, $zero, 0x3200
    ctx->r1 = ADD32(0, 0X3200);
    // 0x8006D8AC: beq         $v0, $at, L_8006EA00
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8B0: addiu       $t5, $a1, 0x2
        ctx->r13 = ADD32(ctx->r5, 0X2);
            goto L_8006EA00;
    }
    // 0x8006D8B0: addiu       $t5, $a1, 0x2
    ctx->r13 = ADD32(ctx->r5, 0X2);
    // 0x8006D8B4: b           L_8006EA18
    // 0x8006D8B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D8B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D8BC:
    // 0x8006D8BC: slti        $at, $v0, 0x1001
    ctx->r1 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
    // 0x8006D8C0: bne         $at, $zero, L_8006D908
    if (ctx->r1 != 0) {
        // 0x8006D8C4: addiu       $at, $zero, 0x1200
        ctx->r1 = ADD32(0, 0X1200);
            goto L_8006D908;
    }
    // 0x8006D8C4: addiu       $at, $zero, 0x1200
    ctx->r1 = ADD32(0, 0X1200);
    // 0x8006D8C8: beq         $v0, $at, L_8006E6D4
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8CC: addiu       $at, $zero, 0x1400
        ctx->r1 = ADD32(0, 0X1400);
            goto L_8006E6D4;
    }
    // 0x8006D8CC: addiu       $at, $zero, 0x1400
    ctx->r1 = ADD32(0, 0X1400);
    // 0x8006D8D0: beq         $v0, $at, L_8006E728
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8D4: addiu       $at, $zero, 0x1600
        ctx->r1 = ADD32(0, 0X1600);
            goto L_8006E728;
    }
    // 0x8006D8D4: addiu       $at, $zero, 0x1600
    ctx->r1 = ADD32(0, 0X1600);
    // 0x8006D8D8: beq         $v0, $at, L_8006E77C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8DC: andi        $t0, $a3, 0x1FF
        ctx->r8 = ctx->r7 & 0X1FF;
            goto L_8006E77C;
    }
    // 0x8006D8DC: andi        $t0, $a3, 0x1FF
    ctx->r8 = ctx->r7 & 0X1FF;
    // 0x8006D8E0: addiu       $at, $zero, 0x1800
    ctx->r1 = ADD32(0, 0X1800);
    // 0x8006D8E4: beq         $v0, $at, L_8006E7D0
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8E8: andi        $t6, $a3, 0x1FF
        ctx->r14 = ctx->r7 & 0X1FF;
            goto L_8006E7D0;
    }
    // 0x8006D8E8: andi        $t6, $a3, 0x1FF
    ctx->r14 = ctx->r7 & 0X1FF;
    // 0x8006D8EC: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8006D8F0: beq         $v0, $at, L_8006E824
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8F4: addiu       $at, $zero, 0x2200
        ctx->r1 = ADD32(0, 0X2200);
            goto L_8006E824;
    }
    // 0x8006D8F4: addiu       $at, $zero, 0x2200
    ctx->r1 = ADD32(0, 0X2200);
    // 0x8006D8F8: beql        $v0, $at, L_8006E874
    if (ctx->r2 == ctx->r1) {
        // 0x8006D8FC: mtc1        $t6, $f8
        ctx->f8.u32l = ctx->r14;
            goto L_8006E874;
    }
    goto skip_2;
    // 0x8006D8FC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    skip_2:
    // 0x8006D900: b           L_8006EA18
    // 0x8006D904: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D904: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D908:
    // 0x8006D908: beq         $v0, $zero, L_8006E60C
    if (ctx->r2 == 0) {
        // 0x8006D90C: addiu       $at, $zero, 0x200
        ctx->r1 = ADD32(0, 0X200);
            goto L_8006E60C;
    }
    // 0x8006D90C: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8006D910: beq         $v0, $at, L_8006E670
    if (ctx->r2 == ctx->r1) {
        // 0x8006D914: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_8006E670;
    }
    // 0x8006D914: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8006D918: beq         $v0, $at, L_8006E648
    if (ctx->r2 == ctx->r1) {
        // 0x8006D91C: addiu       $at, $zero, 0x600
        ctx->r1 = ADD32(0, 0X600);
            goto L_8006E648;
    }
    // 0x8006D91C: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x8006D920: beq         $v0, $at, L_8006DF48
    if (ctx->r2 == ctx->r1) {
        // 0x8006D924: addiu       $at, $zero, 0x800
        ctx->r1 = ADD32(0, 0X800);
            goto L_8006DF48;
    }
    // 0x8006D924: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x8006D928: beq         $v0, $at, L_8006E6A4
    if (ctx->r2 == ctx->r1) {
        // 0x8006D92C: addiu       $t9, $a1, 0x2
        ctx->r25 = ADD32(ctx->r5, 0X2);
            goto L_8006E6A4;
    }
    // 0x8006D92C: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x8006D930: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8006D934: beq         $v0, $at, L_8006E6C0
    if (ctx->r2 == ctx->r1) {
        // 0x8006D938: addiu       $t5, $a1, 0x2
        ctx->r13 = ADD32(ctx->r5, 0X2);
            goto L_8006E6C0;
    }
    // 0x8006D938: addiu       $t5, $a1, 0x2
    ctx->r13 = ADD32(ctx->r5, 0X2);
    // 0x8006D93C: b           L_8006EA18
    // 0x8006D940: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8006EA18;
    // 0x8006D940: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006D944:
    // 0x8006D944: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    // 0x8006D948: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D94C: lwc1        $f4, 0x6B70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B70);
    // 0x8006D950: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8006D954: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006D958: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8006D95C: nop

    // 0x8006D960: bc1fl       L_8006EA18
    if (!c1cs) {
        // 0x8006D964: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_8006EA18;
    }
    goto skip_3;
    // 0x8006D964: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_3:
    // 0x8006D968: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006D96C: b           L_8006EA14
    // 0x8006D970: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
        goto L_8006EA14;
    // 0x8006D970: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8006D974:
    // 0x8006D974: addiu       $s5, $s0, 0x100
    ctx->r21 = ADD32(ctx->r16, 0X100);
    // 0x8006D978: jal         0x8001A500
    // 0x8006D97C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Audio_KillSfxBySource(rdram, ctx);
        goto after_0;
    // 0x8006D97C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8006D980: lh          $t4, 0xE6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XE6);
    // 0x8006D984: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8006D988: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006D98C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8006D990: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8006D994: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x8006D998: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8006D99C: addiu       $t5, $zero, 0x2710
    ctx->r13 = ADD32(0, 0X2710);
    // 0x8006D9A0: sh          $t8, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r24;
    // 0x8006D9A4: lh          $t9, 0xB4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB4);
    // 0x8006D9A8: bnel        $t9, $at, L_8006D9BC
    if (ctx->r25 != ctx->r1) {
        // 0x8006D9AC: sh          $zero, 0xC2($s0)
        MEM_H(0XC2, ctx->r16) = 0;
            goto L_8006D9BC;
    }
    goto skip_4;
    // 0x8006D9AC: sh          $zero, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = 0;
    skip_4:
    // 0x8006D9B0: b           L_8006D9BC
    // 0x8006D9B4: sh          $t5, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r13;
        goto L_8006D9BC;
    // 0x8006D9B4: sh          $t5, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r13;
    // 0x8006D9B8: sh          $zero, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = 0;
L_8006D9BC:
    // 0x8006D9BC: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
    // 0x8006D9C0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8006D9C4: swc1        $f10, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f10.u32l;
    // 0x8006D9C8: beq         $v1, $at, L_8006D9DC
    if (ctx->r3 == ctx->r1) {
        // 0x8006D9CC: swc1        $f16, 0x144($s0)
        MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
            goto L_8006D9DC;
    }
    // 0x8006D9CC: swc1        $f16, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
    // 0x8006D9D0: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x8006D9D4: bnel        $v1, $at, L_8006D9F0
    if (ctx->r3 != ctx->r1) {
        // 0x8006D9D8: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_8006D9F0;
    }
    goto skip_5;
    // 0x8006D9D8: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    skip_5:
L_8006D9DC:
    // 0x8006D9DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8006D9E0: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
    // 0x8006D9E4: b           L_8006DA00
    // 0x8006D9E8: swc1        $f18, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f18.u32l;
        goto L_8006DA00;
    // 0x8006D9E8: swc1        $f18, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f18.u32l;
    // 0x8006D9EC: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
L_8006D9F0:
    // 0x8006D9F0: bne         $v1, $at, L_8006DA00
    if (ctx->r3 != ctx->r1) {
        // 0x8006D9F4: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8006DA00;
    }
    // 0x8006D9F4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8006D9F8: sb          $t0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r8;
    // 0x8006D9FC: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
L_8006DA00:
    // 0x8006DA00: lh          $a1, 0xE6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XE6);
    // 0x8006DA04: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    // 0x8006DA08: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x8006DA0C: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x8006DA10: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8006DA14: addiu       $t6, $a1, 0x2
    ctx->r14 = ADD32(ctx->r5, 0X2);
    // 0x8006DA18: sh          $t6, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r14;
    // 0x8006DA1C: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x8006DA20: bne         $at, $zero, L_8006DB5C
    if (ctx->r1 != 0) {
        // 0x8006DA24: sh          $t4, 0xCE($s0)
        MEM_H(0XCE, ctx->r16) = ctx->r12;
            goto L_8006DB5C;
    }
    // 0x8006DA24: sh          $t4, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r12;
    // 0x8006DA28: slti        $at, $v1, 0x12C
    ctx->r1 = SIGNED(ctx->r3) < 0X12C ? 1 : 0;
    // 0x8006DA2C: beq         $at, $zero, L_8006DB5C
    if (ctx->r1 == 0) {
        // 0x8006DA30: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8006DB5C;
    }
    // 0x8006DA30: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006DA34: addiu       $t7, $t7, -0x413C
    ctx->r15 = ADD32(ctx->r15, -0X413C);
    // 0x8006DA38: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8006DA3C: sh          $s7, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r23;
    // 0x8006DA40: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x8006DA44: swc1        $f22, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f22.u32l;
    // 0x8006DA48: addiu       $a1, $a1, 0x6550
    ctx->r5 = ADD32(ctx->r5, 0X6550);
    // 0x8006DA4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006DA50:
    // 0x8006DA50: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8006DA54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006DA58: bne         $t8, $zero, L_8006DB38
    if (ctx->r24 != 0) {
        // 0x8006DA5C: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_8006DB38;
    }
    // 0x8006DA5C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8006DA60: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8006DA64: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8006DA68: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8006DA6C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8006DA70: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8006DA74: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8006DA78: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8006DA7C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8006DA80: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8006DA84: sw          $s6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r22;
    // 0x8006DA88: addiu       $t1, $t1, 0x6B98
    ctx->r9 = ADD32(ctx->r9, 0X6B98);
    // 0x8006DA8C: addiu       $t5, $t5, 0x6878
    ctx->r13 = ADD32(ctx->r13, 0X6878);
    // 0x8006DA90: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8006DA94: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8006DA98: sh          $a0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r4;
    // 0x8006DA9C: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8006DAA0: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
    // 0x8006DAA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8006DAA8:
    // 0x8006DAA8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006DAAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8006DAB0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006DAB4: swc1        $f4, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8006DAB8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006DABC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006DAC0: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8006DAC4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006DAC8: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8006DACC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006DAD0: swc1        $f10, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8006DAD4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006DAD8: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8006DADC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006DAE0: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8006DAE4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006DAE8: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8006DAEC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006DAF0: bne         $a2, $s7, L_8006DAA8
    if (ctx->r6 != ctx->r23) {
        // 0x8006DAF4: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_8006DAA8;
    }
    // 0x8006DAF4: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8006DAF8: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
    // 0x8006DAFC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8006DB00: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006DB04: bne         $t2, $at, L_8006DB44
    if (ctx->r10 != ctx->r1) {
        // 0x8006DB08: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8006DB44;
    }
    // 0x8006DB08: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006DB0C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8006DB10: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8006DB14: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x8006DB18: ori         $a0, $a0, 0x2049
    ctx->r4 = ctx->r4 | 0X2049;
    // 0x8006DB1C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8006DB20: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DB24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8006DB28: jal         0x80019218
    // 0x8006DB2C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8006DB2C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x8006DB30: b           L_8006DB48
    // 0x8006DB34: lh          $t4, 0x46($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X46);
        goto L_8006DB48;
    // 0x8006DB34: lh          $t4, 0x46($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X46);
L_8006DB38:
    // 0x8006DB38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006DB3C: bne         $a0, $at, L_8006DA50
    if (ctx->r4 != ctx->r1) {
        // 0x8006DB40: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006DA50;
    }
    // 0x8006DB40: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8006DB44:
    // 0x8006DB44: lh          $t4, 0x46($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X46);
L_8006DB48:
    // 0x8006DB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006DB4C: bnel        $s7, $t4, L_8006DB60
    if (ctx->r23 != ctx->r12) {
        // 0x8006DB50: lh          $v1, 0xB4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XB4);
            goto L_8006DB60;
    }
    goto skip_6;
    // 0x8006DB50: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
    skip_6:
    // 0x8006DB54: jal         0x80060FBC
    // 0x8006DB58: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8006DB58: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
L_8006DB5C:
    // 0x8006DB5C: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
L_8006DB60:
    // 0x8006DB60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006DB64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006DB68: beq         $v1, $at, L_8006DB7C
    if (ctx->r3 == ctx->r1) {
        // 0x8006DB6C: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_8006DB7C;
    }
    // 0x8006DB6C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8006DB70: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8006DB74: bnel        $v1, $at, L_8006DB8C
    if (ctx->r3 != ctx->r1) {
        // 0x8006DB78: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8006DB8C;
    }
    goto skip_7;
    // 0x8006DB78: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    skip_7:
L_8006DB7C:
    // 0x8006DB7C: sb          $t6, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r14;
    // 0x8006DB80: sw          $s6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r22;
    // 0x8006DB84: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
    // 0x8006DB88: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
L_8006DB8C:
    // 0x8006DB8C: bne         $v1, $at, L_8006DB9C
    if (ctx->r3 != ctx->r1) {
        // 0x8006DB90: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006DB9C;
    }
    // 0x8006DB90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006DB94: sb          $t7, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r15;
    // 0x8006DB98: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
L_8006DB9C:
    // 0x8006DB9C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8006DBA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006DBA4: lw          $t9, 0x1C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C8);
    // 0x8006DBA8: bne         $t9, $at, L_8006DBEC
    if (ctx->r25 != ctx->r1) {
        // 0x8006DBAC: addiu       $at, $zero, 0x56
        ctx->r1 = ADD32(0, 0X56);
            goto L_8006DBEC;
    }
    // 0x8006DBAC: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x8006DBB0: bne         $v1, $at, L_8006DBCC
    if (ctx->r3 != ctx->r1) {
        // 0x8006DBB4: addiu       $a0, $zero, 0x36
        ctx->r4 = ADD32(0, 0X36);
            goto L_8006DBCC;
    }
    // 0x8006DBB4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8006DBB8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8006DBBC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8006DBC0: jal         0x8001D4AC
    // 0x8006DBC4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    Audio_PlayFanfare(rdram, ctx);
        goto after_3;
    // 0x8006DBC4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_3:
    // 0x8006DBC8: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
L_8006DBCC:
    // 0x8006DBCC: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x8006DBD0: bne         $v1, $at, L_8006DBEC
    if (ctx->r3 != ctx->r1) {
        // 0x8006DBD4: addiu       $a0, $zero, 0x37
        ctx->r4 = ADD32(0, 0X37);
            goto L_8006DBEC;
    }
    // 0x8006DBD4: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8006DBD8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8006DBDC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8006DBE0: jal         0x8001D4AC
    // 0x8006DBE4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    Audio_PlayFanfare(rdram, ctx);
        goto after_4;
    // 0x8006DBE4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_4:
    // 0x8006DBE8: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
L_8006DBEC:
    // 0x8006DBEC: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8006DBF0: bne         $v1, $at, L_8006DC00
    if (ctx->r3 != ctx->r1) {
        // 0x8006DBF4: lui         $a0, 0x601
        ctx->r4 = S32(0X601 << 16);
            goto L_8006DC00;
    }
    // 0x8006DBF4: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x8006DBF8: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
    // 0x8006DBFC: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
L_8006DC00:
    // 0x8006DC00: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8006DC04: bnel        $v1, $at, L_8006DC24
    if (ctx->r3 != ctx->r1) {
        // 0x8006DC08: slti        $at, $v1, 0xC8
        ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
            goto L_8006DC24;
    }
    goto skip_8;
    // 0x8006DC08: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    skip_8:
    // 0x8006DC0C: jal         0x8009ACDC
    // 0x8006DC10: addiu       $a0, $a0, 0x4658
    ctx->r4 = ADD32(ctx->r4, 0X4658);
    Animation_GetFrameCount(rdram, ctx);
        goto after_5;
    // 0x8006DC10: addiu       $a0, $a0, 0x4658
    ctx->r4 = ADD32(ctx->r4, 0X4658);
    after_5:
    // 0x8006DC14: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8006DC18: sh          $t5, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r13;
    // 0x8006DC1C: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
    // 0x8006DC20: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
L_8006DC24:
    // 0x8006DC24: beq         $at, $zero, L_8006DED0
    if (ctx->r1 == 0) {
        // 0x8006DC28: sll         $t0, $v1, 5
        ctx->r8 = S32(ctx->r3 << 5);
            goto L_8006DED0;
    }
    // 0x8006DC28: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x8006DC2C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006DC30: addiu       $t1, $t1, 0x3C
    ctx->r9 = ADD32(ctx->r9, 0X3C);
    // 0x8006DC34: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8006DC38: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8006DC3C: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x8006DC40: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x8006DC44: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x8006DC48: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8006DC4C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8006DC50: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006DC54: and         $t2, $a0, $s3
    ctx->r10 = ctx->r4 & ctx->r19;
    // 0x8006DC58: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006DC5C: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x8006DC60: addu        $t5, $t9, $s4
    ctx->r13 = ADD32(ctx->r25, ctx->r20);
    // 0x8006DC64: sw          $t5, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r13;
    // 0x8006DC68: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006DC6C: swc1        $f8, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f8.u32l;
    // 0x8006DC70: lbu         $t0, 0x14($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X14);
    // 0x8006DC74: sh          $t0, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r8;
    // 0x8006DC78: lbu         $t1, 0x15($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X15);
    // 0x8006DC7C: sh          $t1, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r9;
    // 0x8006DC80: lbu         $t3, 0x17($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X17);
    // 0x8006DC84: sb          $t3, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r11;
    // 0x8006DC88: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8006DC8C: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x8006DC90: lbu         $t4, 0x1C($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1C);
    // 0x8006DC94: bne         $v1, $at, L_8006DCB0
    if (ctx->r3 != ctx->r1) {
        // 0x8006DC98: sb          $t4, 0x3C($s0)
        MEM_B(0X3C, ctx->r16) = ctx->r12;
            goto L_8006DCB0;
    }
    // 0x8006DC98: sb          $t4, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r12;
    // 0x8006DC9C: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
    // 0x8006DCA0: addiu       $t7, $t7, 0x3C
    ctx->r15 = ADD32(ctx->r15, 0X3C);
    // 0x8006DCA4: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x8006DCA8: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x8006DCAC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8006DCB0:
    // 0x8006DCB0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006DCB4: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8006DCB8: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8006DCBC: swc1        $f18, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f18.u32l;
    // 0x8006DCC0: lbu         $t2, 0x16($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X16);
    // 0x8006DCC4: addiu       $t8, $t2, -0x1
    ctx->r24 = ADD32(ctx->r10, -0X1);
    // 0x8006DCC8: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x8006DCCC: beq         $at, $zero, L_8006DE74
    if (ctx->r1 == 0) {
        // 0x8006DCD0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8006DE74;
    }
    // 0x8006DCD0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006DCD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006DCD8: addu        $at, $at, $t8
    gpr jr_addend_8006DCE0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8006DCDC: lw          $t8, 0x6B74($at)
    ctx->r24 = ADD32(ctx->r1, 0X6B74);
    // 0x8006DCE0: jr          $t8
    // 0x8006DCE4: nop

    switch (jr_addend_8006DCE0 >> 2) {
        case 0: goto L_8006DCE8; break;
        case 1: goto L_8006DD44; break;
        case 2: goto L_8006DD78; break;
        case 3: goto L_8006DDAC; break;
        case 4: goto L_8006DDE0; break;
        case 5: goto L_8006DE14; break;
        case 6: goto L_8006DE48; break;
        default: switch_error(__func__, 0x8006DCE0, 0x800D6B74);
    }
    // 0x8006DCE4: nop

L_8006DCE8:
    // 0x8006DCE8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006DCEC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8006DCF0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006DCF4: beq         $v0, $at, L_8006DE74
    if (ctx->r2 == ctx->r1) {
        // 0x8006DCF8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8006DE74;
    }
    // 0x8006DCF8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8006DCFC: beq         $v1, $at, L_8006DE74
    if (ctx->r3 == ctx->r1) {
        // 0x8006DD00: nop
    
            goto L_8006DE74;
    }
    // 0x8006DD00: nop

    // 0x8006DD04: bne         $v0, $zero, L_8006DD10
    if (ctx->r2 != 0) {
        // 0x8006DD08: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8006DD10;
    }
    // 0x8006DD08: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006DD0C: beq         $v1, $at, L_8006DE74
    if (ctx->r3 == ctx->r1) {
        // 0x8006DD10: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8006DE74;
    }
L_8006DD10:
    // 0x8006DD10: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006DD14: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8006DD18: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006DD1C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8006DD20: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8006DD24: ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // 0x8006DD28: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8006DD2C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006DD30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DD34: jal         0x80019218
    // 0x8006DD38: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x8006DD38: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x8006DD3C: b           L_8006DE74
    // 0x8006DD40: nop

        goto L_8006DE74;
    // 0x8006DD40: nop

L_8006DD44:
    // 0x8006DD44: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8006DD48: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8006DD4C: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8006DD50: addiu       $a3, $t5, 0x5D34
    ctx->r7 = ADD32(ctx->r13, 0X5D34);
    // 0x8006DD54: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8006DD58: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8006DD5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006DD60: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8006DD64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DD68: jal         0x80019218
    // 0x8006DD6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8006DD6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x8006DD70: b           L_8006DE74
    // 0x8006DD74: nop

        goto L_8006DE74;
    // 0x8006DD74: nop

L_8006DD78:
    // 0x8006DD78: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8006DD7C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8006DD80: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8006DD84: addiu       $a3, $t1, 0x5D34
    ctx->r7 = ADD32(ctx->r9, 0X5D34);
    // 0x8006DD88: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x8006DD8C: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x8006DD90: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006DD94: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8006DD98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DD9C: jal         0x80019218
    // 0x8006DDA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x8006DDA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8006DDA4: b           L_8006DE74
    // 0x8006DDA8: nop

        goto L_8006DE74;
    // 0x8006DDA8: nop

L_8006DDAC:
    // 0x8006DDAC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006DDB0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8006DDB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006DDB8: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8006DDBC: lui         $a0, 0x3101
    ctx->r4 = S32(0X3101 << 16);
    // 0x8006DDC0: ori         $a0, $a0, 0x2039
    ctx->r4 = ctx->r4 | 0X2039;
    // 0x8006DDC4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8006DDC8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006DDCC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DDD0: jal         0x80019218
    // 0x8006DDD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x8006DDD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x8006DDD8: b           L_8006DE74
    // 0x8006DDDC: nop

        goto L_8006DE74;
    // 0x8006DDDC: nop

L_8006DDE0:
    // 0x8006DDE0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006DDE4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8006DDE8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006DDEC: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8006DDF0: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x8006DDF4: ori         $a0, $a0, 0x302B
    ctx->r4 = ctx->r4 | 0X302B;
    // 0x8006DDF8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006DDFC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006DE00: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DE04: jal         0x80019218
    // 0x8006DE08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8006DE08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8006DE0C: b           L_8006DE74
    // 0x8006DE10: nop

        goto L_8006DE74;
    // 0x8006DE10: nop

L_8006DE14:
    // 0x8006DE14: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006DE18: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8006DE1C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006DE20: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8006DE24: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8006DE28: ori         $a0, $a0, 0x14
    ctx->r4 = ctx->r4 | 0X14;
    // 0x8006DE2C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8006DE30: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006DE34: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DE38: jal         0x80019218
    // 0x8006DE3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_11;
    // 0x8006DE3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x8006DE40: b           L_8006DE74
    // 0x8006DE44: nop

        goto L_8006DE74;
    // 0x8006DE44: nop

L_8006DE48:
    // 0x8006DE48: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006DE4C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8006DE50: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006DE54: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8006DE58: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8006DE5C: ori         $a0, $a0, 0x15
    ctx->r4 = ctx->r4 | 0X15;
    // 0x8006DE60: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8006DE64: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006DE68: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006DE6C: jal         0x80019218
    // 0x8006DE70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_12;
    // 0x8006DE70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
L_8006DE74:
    // 0x8006DE74: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8006DE78: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8006DE7C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006DE80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006DE84: lwc1        $f4, 0x138($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X138);
    // 0x8006DE88: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8006DE8C: nop

    // 0x8006DE90: bc1fl       L_8006DEA4
    if (!c1cs) {
        // 0x8006DE94: lh          $t9, 0x32($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X32);
            goto L_8006DEA4;
    }
    goto skip_9;
    // 0x8006DE94: lh          $t9, 0x32($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X32);
    skip_9:
    // 0x8006DE98: lwc1        $f8, 0x6B90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6B90);
    // 0x8006DE9C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8006DEA0: lh          $t9, 0x32($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X32);
L_8006DEA4:
    // 0x8006DEA4: bnel        $t9, $zero, L_8006DED4
    if (ctx->r25 != 0) {
        // 0x8006DEA8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8006DED4;
    }
    goto skip_10;
    // 0x8006DEA8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_10:
    // 0x8006DEAC: lwc1        $f0, 0xFC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8006DEB0: lh          $t5, 0xB4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB4);
    // 0x8006DEB4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8006DEB8: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x8006DEBC: beq         $t5, $at, L_8006DED0
    if (ctx->r13 == ctx->r1) {
        // 0x8006DEC0: swc1        $f0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
            goto L_8006DED0;
    }
    // 0x8006DEC0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8006DEC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006DEC8: nop

    // 0x8006DECC: swc1        $f10, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f10.u32l;
L_8006DED0:
    // 0x8006DED0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8006DED4:
    // 0x8006DED4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006DED8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006DEDC: b           L_8006D3F4
    // 0x8006DEE0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006DEE0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006DEE4:
    // 0x8006DEE4: lhu         $t0, 0x2($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X2);
    // 0x8006DEE8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006DEEC: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8006DEF0: beq         $at, $zero, L_8006DF10
    if (ctx->r1 == 0) {
        // 0x8006DEF4: sw          $t0, 0x80($s0)
        MEM_W(0X80, ctx->r16) = ctx->r8;
            goto L_8006DF10;
    }
    // 0x8006DEF4: sw          $t0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r8;
    // 0x8006DEF8: lw          $t1, 0x40($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X40);
    // 0x8006DEFC: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8006DF00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006DF04: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8006DF08: sw          $t1, -0x80($at)
    MEM_W(-0X80, ctx->r1) = ctx->r9;
    // 0x8006DF0C: lh          $a1, 0xE6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XE6);
L_8006DF10:
    // 0x8006DF10: addiu       $t4, $a1, 0x2
    ctx->r12 = ADD32(ctx->r5, 0X2);
    // 0x8006DF14: sh          $t4, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r12;
    // 0x8006DF18: b           L_8006D3F4
    // 0x8006DF1C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006DF1C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006DF20:
    // 0x8006DF20: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x8006DF24: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    // 0x8006DF28: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006DF2C: sw          $t6, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r14;
    // 0x8006DF30: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x8006DF34: sh          $t8, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r24;
    // 0x8006DF38: andi        $t2, $t7, 0x1FF
    ctx->r10 = ctx->r15 & 0X1FF;
    // 0x8006DF3C: sw          $t2, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r10;
    // 0x8006DF40: b           L_8006D3F4
    // 0x8006DF44: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006DF44: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006DF48:
    // 0x8006DF48: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x8006DF4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006DF50: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006DF54: sw          $t9, 0x7E78($at)
    MEM_W(0X7E78, ctx->r1) = ctx->r25;
    // 0x8006DF58: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006DF5C: addiu       $v1, $v1, 0x7E88
    ctx->r3 = ADD32(ctx->r3, 0X7E88);
    // 0x8006DF60: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006DF64: swc1        $f16, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f16.u32l;
    // 0x8006DF68: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006DF6C: swc1        $f18, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->f18.u32l;
    // 0x8006DF70: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006DF74: swc1        $f4, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->f4.u32l;
    // 0x8006DF78: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006DF7C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8006DF80: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006DF84: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8006DF88: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006DF8C: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x8006DF90: lh          $t5, 0xE6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE6);
    // 0x8006DF94: addiu       $t0, $t5, 0x2
    ctx->r8 = ADD32(ctx->r13, 0X2);
    // 0x8006DF98: sh          $t0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r8;
    // 0x8006DF9C: b           L_8006D3F4
    // 0x8006DFA0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006DFA0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8006DFA4: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
L_8006DFA8:
    // 0x8006DFA8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8006DFAC: bnel        $v0, $at, L_8006DFD4
    if (ctx->r2 != ctx->r1) {
        // 0x8006DFB0: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8006DFD4;
    }
    goto skip_11;
    // 0x8006DFB0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    skip_11:
    // 0x8006DFB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8006DFB8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8006DFBC: addiu       $t3, $a1, 0x2
    ctx->r11 = ADD32(ctx->r5, 0X2);
    // 0x8006DFC0: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
    // 0x8006DFC4: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x8006DFC8: b           L_8006EA14
    // 0x8006DFCC: swc1        $f16, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f16.u32l;
        goto L_8006EA14;
    // 0x8006DFCC: swc1        $f16, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f16.u32l;
    // 0x8006DFD0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
L_8006DFD4:
    // 0x8006DFD4: bne         $v0, $at, L_8006E018
    if (ctx->r2 != ctx->r1) {
        // 0x8006DFD8: addiu       $t1, $zero, 0xB
        ctx->r9 = ADD32(0, 0XB);
            goto L_8006E018;
    }
    // 0x8006DFD8: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8006DFDC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006DFE0: addiu       $v0, $v0, -0x413C
    ctx->r2 = ADD32(ctx->r2, -0X413C);
    // 0x8006DFE4: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x8006DFE8: srl         $t6, $t4, 28
    ctx->r14 = S32(U32(ctx->r12) >> 28);
    // 0x8006DFEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006DFF0: addu        $t2, $s2, $t7
    ctx->r10 = ADD32(ctx->r18, ctx->r15);
    // 0x8006DFF4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8006DFF8: and         $t9, $v0, $s3
    ctx->r25 = ctx->r2 & ctx->r19;
    // 0x8006DFFC: addiu       $t3, $a1, 0x2
    ctx->r11 = ADD32(ctx->r5, 0X2);
    // 0x8006E000: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x8006E004: addu        $t0, $t5, $s4
    ctx->r8 = ADD32(ctx->r13, ctx->r20);
    // 0x8006E008: sw          $t0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r8;
    // 0x8006E00C: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
    // 0x8006E010: b           L_8006EA14
    // 0x8006E014: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
        goto L_8006EA14;
    // 0x8006E014: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
L_8006E018:
    // 0x8006E018: sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // 0x8006E01C: lh          $v1, 0x48($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X48);
    // 0x8006E020: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006E024: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8006E028: bne         $v1, $at, L_8006E038
    if (ctx->r3 != ctx->r1) {
        // 0x8006E02C: addiu       $t6, $zero, 0x32
        ctx->r14 = ADD32(0, 0X32);
            goto L_8006E038;
    }
    // 0x8006E02C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8006E030: sh          $t4, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r12;
    // 0x8006E034: lh          $v1, 0x48($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X48);
L_8006E038:
    // 0x8006E038: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006E03C: bnel        $v1, $at, L_8006E04C
    if (ctx->r3 != ctx->r1) {
        // 0x8006E040: lh          $t7, 0xE6($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XE6);
            goto L_8006E04C;
    }
    goto skip_12;
    // 0x8006E040: lh          $t7, 0xE6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE6);
    skip_12:
    // 0x8006E044: sh          $t6, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r14;
    // 0x8006E048: lh          $t7, 0xE6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE6);
L_8006E04C:
    // 0x8006E04C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E050: addiu       $t2, $t7, 0x2
    ctx->r10 = ADD32(ctx->r15, 0X2);
    // 0x8006E054: sh          $t2, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r10;
    // 0x8006E058: b           L_8006D3F4
    // 0x8006E05C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E05C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E060:
    // 0x8006E060: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E064: sh          $t9, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r25;
    // 0x8006E068: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E06C: sb          $t8, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r24;
    // 0x8006E070: b           L_8006D3F4
    // 0x8006E074: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E074: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E078:
    // 0x8006E078: jal         0x8001D400
    // 0x8006E07C: lb          $a0, 0x3($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X3);
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_13;
    // 0x8006E07C: lb          $a0, 0x3($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X3);
    after_13:
    // 0x8006E080: lh          $t5, 0xE6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E084: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006E088: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E08C: addiu       $t0, $t5, 0x2
    ctx->r8 = ADD32(ctx->r13, 0X2);
    // 0x8006E090: sh          $t0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r8;
    // 0x8006E094: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E098: b           L_8006D3F4
    // 0x8006E09C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E09C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E0A0:
    // 0x8006E0A0: jal         0x800C2830
    // 0x8006E0A4: lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2);
    Message_PtrFromId(rdram, ctx);
        goto after_14;
    // 0x8006E0A4: lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2);
    after_14:
    // 0x8006E0A8: beq         $v0, $zero, L_8006E0E4
    if (ctx->r2 == 0) {
        // 0x8006E0AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8006E0E4;
    }
    // 0x8006E0AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006E0B0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006E0B4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8006E0B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006E0BC: lw          $t3, 0x1C8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X1C8);
    // 0x8006E0C0: bnel        $t3, $at, L_8006E0E8
    if (ctx->r11 != ctx->r1) {
        // 0x8006E0C4: lh          $t8, 0xE6($s0)
        ctx->r24 = MEM_H(ctx->r16, 0XE6);
            goto L_8006E0E8;
    }
    goto skip_13;
    // 0x8006E0C4: lh          $t8, 0xE6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE6);
    skip_13:
    // 0x8006E0C8: lh          $t4, 0xE6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E0CC: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8006E0D0: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8006E0D4: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x8006E0D8: andi        $t2, $a1, 0x1FF
    ctx->r10 = ctx->r5 & 0X1FF;
    // 0x8006E0DC: jal         0x800BA808
    // 0x8006E0E0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_15;
    // 0x8006E0E0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_15:
L_8006E0E4:
    // 0x8006E0E4: lh          $t8, 0xE6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE6);
L_8006E0E8:
    // 0x8006E0E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006E0EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E0F0: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8006E0F4: sh          $t9, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r25;
    // 0x8006E0F8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E0FC: b           L_8006D3F4
    // 0x8006E100: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E100: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E104:
    // 0x8006E104: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8006E108: addiu       $s2, $s2, 0x1A88
    ctx->r18 = ADD32(ctx->r18, 0X1A88);
    // 0x8006E10C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8006E110: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006E114: bnel        $v0, $t5, L_8006E150
    if (ctx->r2 != ctx->r13) {
        // 0x8006E118: lhu         $t4, 0x2($a2)
        ctx->r12 = MEM_HU(ctx->r6, 0X2);
            goto L_8006E150;
    }
    goto skip_14;
    // 0x8006E118: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    skip_14:
    // 0x8006E11C: lhu         $t0, 0x2($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E120: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8006E124: lui         $a1, 0x1100
    ctx->r5 = S32(0X1100 << 16);
    // 0x8006E128: beql        $v0, $t0, L_8006E150
    if (ctx->r2 == ctx->r8) {
        // 0x8006E12C: lhu         $t4, 0x2($a2)
        ctx->r12 = MEM_HU(ctx->r6, 0X2);
            goto L_8006E150;
    }
    goto skip_15;
    // 0x8006E12C: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    skip_15:
    // 0x8006E130: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8006E134: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x8006E138: jal         0x8001A55C
    // 0x8006E13C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_16;
    // 0x8006E13C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_16:
    // 0x8006E140: lh          $t1, 0xE6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E144: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x8006E148: addu        $a2, $s1, $t3
    ctx->r6 = ADD32(ctx->r17, ctx->r11);
    // 0x8006E14C: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
L_8006E150:
    // 0x8006E150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E154: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8006E158: lh          $t6, 0xE6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E15C: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8006E160: jal         0x8006D36C
    // 0x8006E164: sh          $t7, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r15;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_17;
    // 0x8006E164: sh          $t7, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r15;
    after_17:
    // 0x8006E168: b           L_8006EA14
    // 0x8006E16C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8006EA14;
    // 0x8006E16C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8006E170:
    // 0x8006E170: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006E174: sw          $t2, -0x70($at)
    MEM_W(-0X70, ctx->r1) = ctx->r10;
    // 0x8006E178: lh          $t8, 0xE6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E17C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006E180: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E184: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006E188: addu        $t5, $s1, $t9
    ctx->r13 = ADD32(ctx->r17, ctx->r25);
    // 0x8006E18C: lhu         $t0, 0x2($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X2);
    // 0x8006E190: sw          $t0, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r8;
    // 0x8006E194: lh          $t1, 0xE6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E198: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8006E19C: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x8006E1A0: b           L_8006D3F4
    // 0x8006E1A4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E1A4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8006E1A8: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
L_8006E1AC:
    // 0x8006E1AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006E1B0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8006E1B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006E1B8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8006E1BC: sw          $t4, 0x78B0($at)
    MEM_W(0X78B0, ctx->r1) = ctx->r12;
    // 0x8006E1C0: lh          $t2, 0xE6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E1C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E1C8: addiu       $t8, $t2, 0x2
    ctx->r24 = ADD32(ctx->r10, 0X2);
    // 0x8006E1CC: sh          $t8, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r24;
    // 0x8006E1D0: b           L_8006D3F4
    // 0x8006E1D4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E1D4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E1D8:
    // 0x8006E1D8: jal         0x8001D2FC
    // 0x8006E1DC: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Audio_PlayEventSfx(rdram, ctx);
        goto after_18;
    // 0x8006E1DC: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_18:
    // 0x8006E1E0: lh          $t9, 0xE6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E1E4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006E1E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E1EC: addiu       $t5, $t9, 0x2
    ctx->r13 = ADD32(ctx->r25, 0X2);
    // 0x8006E1F0: sh          $t5, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r13;
    // 0x8006E1F4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E1F8: b           L_8006D3F4
    // 0x8006E1FC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E1FC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E200:
    // 0x8006E200: jal         0x8001D3A0
    // 0x8006E204: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Audio_StopEventSfx(rdram, ctx);
        goto after_19;
    // 0x8006E204: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_19:
    // 0x8006E208: lh          $t0, 0xE6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E20C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006E210: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E214: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x8006E218: sh          $t1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r9;
    // 0x8006E21C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E220: b           L_8006D3F4
    // 0x8006E224: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E224: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E228:
    // 0x8006E228: jal         0x800182F4
    // 0x8006E22C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_20;
    // 0x8006E22C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_20:
    // 0x8006E230: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x8006E234: jal         0x800182F4
    // 0x8006E238: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_21;
    // 0x8006E238: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_21:
    // 0x8006E23C: lh          $t3, 0xE6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E240: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006E244: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E248: addiu       $t6, $t3, 0x2
    ctx->r14 = ADD32(ctx->r11, 0X2);
    // 0x8006E24C: sh          $t6, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r14;
    // 0x8006E250: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E254: b           L_8006D3F4
    // 0x8006E258: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E258: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E25C:
    // 0x8006E25C: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E260: lw          $t4, 0x80($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X80);
    // 0x8006E264: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006E268: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8006E26C: bne         $t4, $v0, L_8006E28C
    if (ctx->r12 != ctx->r2) {
        // 0x8006E270: addu        $at, $at, $t9
        ctx->r1 = ADD32(ctx->r1, ctx->r25);
            goto L_8006E28C;
    }
    // 0x8006E270: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8006E274: sb          $s6, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r22;
    // 0x8006E278: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E27C: sh          $s7, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r23;
    // 0x8006E280: andi        $t2, $t7, 0x1FF
    ctx->r10 = ctx->r15 & 0X1FF;
    // 0x8006E284: b           L_8006E294
    // 0x8006E288: sh          $t2, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r10;
        goto L_8006E294;
    // 0x8006E288: sh          $t2, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r10;
L_8006E28C:
    // 0x8006E28C: sw          $t8, 0x7910($at)
    MEM_W(0X7910, ctx->r1) = ctx->r24;
    // 0x8006E290: lh          $a1, 0xE6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XE6);
L_8006E294:
    // 0x8006E294: addiu       $t5, $a1, 0x2
    ctx->r13 = ADD32(ctx->r5, 0X2);
    // 0x8006E298: sh          $t5, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r13;
    // 0x8006E29C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E2A0: b           L_8006D3F4
    // 0x8006E2A4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E2A4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E2A8:
    // 0x8006E2A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006E2AC: sw          $s6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r22;
    // 0x8006E2B0: addiu       $v0, $v0, 0x4750
    ctx->r2 = ADD32(ctx->r2, 0X4750);
L_8006E2B4:
    // 0x8006E2B4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8006E2B8: bne         $t0, $zero, L_8006E38C
    if (ctx->r8 != 0) {
        // 0x8006E2BC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8006E38C;
    }
    // 0x8006E2BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006E2C0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8006E2C4: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8006E2C8: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8006E2CC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006E2D0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006E2D4: addiu       $v1, $v1, 0xDBC
    ctx->r3 = ADD32(ctx->r3, 0XDBC);
    // 0x8006E2D8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006E2DC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8006E2E0: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006E2E4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006E2E8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006E2EC: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8006E2F0: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8006E2F4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006E2F8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006E2FC: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8006E300: lh          $t3, 0xE6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E304: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x8006E308: addu        $t4, $s1, $t6
    ctx->r12 = ADD32(ctx->r17, ctx->r14);
    // 0x8006E30C: lhu         $t7, 0x2($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X2);
    // 0x8006E310: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8006E314: addu        $t8, $v1, $t2
    ctx->r24 = ADD32(ctx->r3, ctx->r10);
    // 0x8006E318: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8006E31C: sb          $t9, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r25;
    // 0x8006E320: lh          $t5, 0xE6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E324: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x8006E328: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x8006E32C: lhu         $t3, 0x2($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X2);
    // 0x8006E330: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8006E334: addu        $t4, $v1, $t6
    ctx->r12 = ADD32(ctx->r3, ctx->r14);
    // 0x8006E338: lbu         $t7, 0x1($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X1);
    // 0x8006E33C: sb          $t7, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r15;
    // 0x8006E340: lh          $t2, 0xE6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E344: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x8006E348: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8006E34C: lhu         $t5, 0x2($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X2);
    // 0x8006E350: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8006E354: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x8006E358: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8006E35C: lbu         $t3, 0x2($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X2);
    // 0x8006E360: sb          $t3, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r11;
    // 0x8006E364: lh          $t6, 0xE6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E368: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x8006E36C: addu        $t7, $s1, $t4
    ctx->r15 = ADD32(ctx->r17, ctx->r12);
    // 0x8006E370: lhu         $t2, 0x2($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X2);
    // 0x8006E374: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8006E378: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006E37C: lbu         $t9, 0xDBF($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0XDBF);
    // 0x8006E380: sb          $t9, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r25;
    // 0x8006E384: b           L_8006E398
    // 0x8006E388: sw          $a0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r4;
        goto L_8006E398;
    // 0x8006E388: sw          $a0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r4;
L_8006E38C:
    // 0x8006E38C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006E390: bne         $a0, $s7, L_8006E2B4
    if (ctx->r4 != ctx->r23) {
        // 0x8006E394: addiu       $v0, $v0, 0x30
        ctx->r2 = ADD32(ctx->r2, 0X30);
            goto L_8006E2B4;
    }
    // 0x8006E394: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
L_8006E398:
    // 0x8006E398: lh          $t5, 0xE6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE6);
    // 0x8006E39C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E3A0: addiu       $t0, $t5, 0x2
    ctx->r8 = ADD32(ctx->r13, 0X2);
    // 0x8006E3A4: sh          $t0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r8;
    // 0x8006E3A8: b           L_8006D3F4
    // 0x8006E3AC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E3AC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E3B0:
    // 0x8006E3B0: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x8006E3B4: sh          $t1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r9;
    // 0x8006E3B8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E3BC: b           L_8006D3F4
    // 0x8006E3C0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E3C0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E3C4:
    // 0x8006E3C4: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    // 0x8006E3C8: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E3CC: addiu       $t2, $a1, 0x2
    ctx->r10 = ADD32(ctx->r5, 0X2);
    // 0x8006E3D0: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
    // 0x8006E3D4: lhu         $t4, 0x0($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E3D8: sh          $t2, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r10;
    // 0x8006E3DC: andi        $t7, $t4, 0x1FF
    ctx->r15 = ctx->r12 & 0X1FF;
    // 0x8006E3E0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8006E3E4: nop

    // 0x8006E3E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E3EC: b           L_8006EA14
    // 0x8006E3F0: swc1        $f10, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f10.u32l;
        goto L_8006EA14;
    // 0x8006E3F0: swc1        $f10, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f10.u32l;
L_8006E3F4:
    // 0x8006E3F4: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x8006E3F8: lhu         $t9, 0x2($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E3FC: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
    // 0x8006E400: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x8006E404: lhu         $t5, 0x0($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E408: sh          $t1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r9;
    // 0x8006E40C: andi        $t0, $t5, 0x1FF
    ctx->r8 = ctx->r13 & 0X1FF;
    // 0x8006E410: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8006E414: nop

    // 0x8006E418: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E41C: b           L_8006EA14
    // 0x8006E420: swc1        $f18, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f18.u32l;
        goto L_8006EA14;
    // 0x8006E420: swc1        $f18, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f18.u32l;
L_8006E424:
    // 0x8006E424: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    // 0x8006E428: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E42C: addiu       $t2, $a1, 0x2
    ctx->r10 = ADD32(ctx->r5, 0X2);
    // 0x8006E430: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
    // 0x8006E434: lhu         $t4, 0x0($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E438: sh          $t2, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r10;
    // 0x8006E43C: andi        $t7, $t4, 0x1FF
    ctx->r15 = ctx->r12 & 0X1FF;
    // 0x8006E440: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006E444: nop

    // 0x8006E448: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006E44C: b           L_8006EA14
    // 0x8006E450: swc1        $f6, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f6.u32l;
        goto L_8006EA14;
    // 0x8006E450: swc1        $f6, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f6.u32l;
L_8006E454:
    // 0x8006E454: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x8006E458: lhu         $t9, 0x2($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E45C: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
    // 0x8006E460: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x8006E464: lhu         $t5, 0x0($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E468: sh          $t1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r9;
    // 0x8006E46C: andi        $t0, $t5, 0x1FF
    ctx->r8 = ctx->r13 & 0X1FF;
    // 0x8006E470: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8006E474: nop

    // 0x8006E478: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E47C: b           L_8006EA14
    // 0x8006E480: swc1        $f10, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f10.u32l;
        goto L_8006EA14;
    // 0x8006E480: swc1        $f10, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f10.u32l;
L_8006E484:
    // 0x8006E484: sh          $s6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r22;
    // 0x8006E488: lhu         $t3, 0x0($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E48C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006E490: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E494: andi        $t6, $t3, 0x1FF
    ctx->r14 = ctx->r11 & 0X1FF;
    // 0x8006E498: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8006E49C: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8006E4A0: lw          $t7, -0x80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X80);
    // 0x8006E4A4: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    // 0x8006E4A8: sw          $t7, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r15;
    // 0x8006E4AC: lhu         $t2, 0x2($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E4B0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8006E4B4: bgez        $t2, L_8006E4C8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006E4B8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E4C8;
    }
    // 0x8006E4B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E4BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E4C0: nop

    // 0x8006E4C4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006E4C8:
    // 0x8006E4C8: swc1        $f18, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f18.u32l;
    // 0x8006E4CC: sh          $zero, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = 0;
    // 0x8006E4D0: b           L_8006EA14
    // 0x8006E4D4: sh          $t8, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r24;
        goto L_8006EA14;
    // 0x8006E4D4: sh          $t8, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r24;
L_8006E4D8:
    // 0x8006E4D8: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
    // 0x8006E4DC: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E4E0: addiu       $t3, $a1, 0x2
    ctx->r11 = ADD32(ctx->r5, 0X2);
    // 0x8006E4E4: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
    // 0x8006E4E8: lhu         $t0, 0x0($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E4EC: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x8006E4F0: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x8006E4F4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8006E4F8: nop

    // 0x8006E4FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006E500: b           L_8006EA14
    // 0x8006E504: swc1        $f8, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f8.u32l;
        goto L_8006EA14;
    // 0x8006E504: swc1        $f8, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f8.u32l;
L_8006E508:
    // 0x8006E508: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8006E50C: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    // 0x8006E510: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E514: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    // 0x8006E518: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
    // 0x8006E51C: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E520: sh          $t8, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r24;
    // 0x8006E524: andi        $t2, $t7, 0x1FF
    ctx->r10 = ctx->r15 & 0X1FF;
    // 0x8006E528: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8006E52C: nop

    // 0x8006E530: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006E534: b           L_8006EA14
    // 0x8006E538: swc1        $f16, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f16.u32l;
        goto L_8006EA14;
    // 0x8006E538: swc1        $f16, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f16.u32l;
L_8006E53C:
    // 0x8006E53C: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8006E540: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
    // 0x8006E544: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E548: addiu       $t3, $a1, 0x2
    ctx->r11 = ADD32(ctx->r5, 0X2);
    // 0x8006E54C: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
    // 0x8006E550: lhu         $t0, 0x0($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E554: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x8006E558: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x8006E55C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8006E560: nop

    // 0x8006E564: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006E568: b           L_8006EA14
    // 0x8006E56C: swc1        $f18, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f18.u32l;
        goto L_8006EA14;
    // 0x8006E56C: swc1        $f18, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f18.u32l;
L_8006E570:
    // 0x8006E570: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E574: addiu       $t2, $a1, 0x2
    ctx->r10 = ADD32(ctx->r5, 0X2);
    // 0x8006E578: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E57C: sw          $t6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r14;
    // 0x8006E580: lhu         $t4, 0x0($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E584: sh          $t2, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r10;
    // 0x8006E588: andi        $t7, $t4, 0x1FF
    ctx->r15 = ctx->r12 & 0X1FF;
    // 0x8006E58C: sw          $t7, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r15;
    // 0x8006E590: b           L_8006D3F4
    // 0x8006E594: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E594: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E598:
    // 0x8006E598: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x8006E59C: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E5A0: andi        $v0, $a3, 0x1FF
    ctx->r2 = ctx->r7 & 0X1FF;
    // 0x8006E5A4: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006E5A8: beql        $at, $zero, L_8006E5C0
    if (ctx->r1 == 0) {
        // 0x8006E5AC: slti        $at, $v0, 0xC8
        ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
            goto L_8006E5C0;
    }
    goto skip_16;
    // 0x8006E5AC: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    skip_16:
    // 0x8006E5B0: sh          $t9, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r25;
    // 0x8006E5B4: b           L_8006E5E8
    // 0x8006E5B8: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
        goto L_8006E5E8;
    // 0x8006E5B8: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8006E5BC: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
L_8006E5C0:
    // 0x8006E5C0: beq         $at, $zero, L_8006E5DC
    if (ctx->r1 == 0) {
        // 0x8006E5C4: addiu       $t1, $v0, -0xC8
        ctx->r9 = ADD32(ctx->r2, -0XC8);
            goto L_8006E5DC;
    }
    // 0x8006E5C4: addiu       $t1, $v0, -0xC8
    ctx->r9 = ADD32(ctx->r2, -0XC8);
    // 0x8006E5C8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8006E5CC: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x8006E5D0: sh          $t5, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r13;
    // 0x8006E5D4: b           L_8006E5E8
    // 0x8006E5D8: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
        goto L_8006E5E8;
    // 0x8006E5D8: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
L_8006E5DC:
    // 0x8006E5DC: sh          $t1, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r9;
    // 0x8006E5E0: sh          $zero, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = 0;
    // 0x8006E5E4: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_8006E5E8:
    // 0x8006E5E8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E5EC: b           L_8006D3F4
    // 0x8006E5F0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E5F0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E5F4:
    // 0x8006E5F4: sh          $s6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r22;
    // 0x8006E5F8: lhu         $t3, 0x2($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E5FC: addiu       $t6, $a1, 0x2
    ctx->r14 = ADD32(ctx->r5, 0X2);
    // 0x8006E600: sh          $t6, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r14;
    // 0x8006E604: b           L_8006EA14
    // 0x8006E608: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
        goto L_8006EA14;
    // 0x8006E608: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
L_8006E60C:
    // 0x8006E60C: andi        $t4, $a3, 0x7F
    ctx->r12 = ctx->r7 & 0X7F;
    // 0x8006E610: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8006E614: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x8006E618: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006E61C: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x8006E620: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006E624: swc1        $f10, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f10.u32l;
    // 0x8006E628: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E62C: andi        $t2, $t7, 0x180
    ctx->r10 = ctx->r15 & 0X180;
    // 0x8006E630: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
    // 0x8006E634: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E638: sh          $s6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r22;
    // 0x8006E63C: sh          $t9, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r25;
    // 0x8006E640: b           L_8006EA14
    // 0x8006E644: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
        goto L_8006EA14;
    // 0x8006E644: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
L_8006E648:
    // 0x8006E648: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E64C: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
    // 0x8006E650: sh          $t1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r9;
    // 0x8006E654: andi        $t0, $t5, 0xFF
    ctx->r8 = ctx->r13 & 0XFF;
    // 0x8006E658: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8006E65C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E660: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E664: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x8006E668: b           L_8006D3F4
    // 0x8006E66C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E66C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E670:
    // 0x8006E670: andi        $t3, $a3, 0x7F
    ctx->r11 = ctx->r7 & 0X7F;
    // 0x8006E674: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8006E678: addiu       $t2, $a1, 0x2
    ctx->r10 = ADD32(ctx->r5, 0X2);
    // 0x8006E67C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006E680: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    // 0x8006E684: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E688: andi        $t4, $t6, 0x180
    ctx->r12 = ctx->r14 & 0X180;
    // 0x8006E68C: sw          $t4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r12;
    // 0x8006E690: lhu         $t7, 0x2($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E694: sh          $s6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r22;
    // 0x8006E698: sh          $t2, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r10;
    // 0x8006E69C: b           L_8006EA14
    // 0x8006E6A0: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
        goto L_8006EA14;
    // 0x8006E6A0: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
L_8006E6A4:
    // 0x8006E6A4: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E6A8: sw          $s6, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r22;
    // 0x8006E6AC: sh          $t9, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r25;
    // 0x8006E6B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E6B4: sh          $t8, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r24;
    // 0x8006E6B8: b           L_8006D3F4
    // 0x8006E6BC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E6BC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E6C0:
    // 0x8006E6C0: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x8006E6C4: sh          $t5, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r13;
    // 0x8006E6C8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E6CC: b           L_8006D3F4
    // 0x8006E6D0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E6D0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E6D4:
    // 0x8006E6D4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8006E6D8: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
    // 0x8006E6DC: lhu         $t1, 0x0($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E6E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E6E4: andi        $t3, $t1, 0x1FF
    ctx->r11 = ctx->r9 & 0X1FF;
    // 0x8006E6E8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8006E6EC: nop

    // 0x8006E6F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E6F4: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x8006E6F8: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E6FC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8006E700: bgez        $t6, L_8006E714
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006E704: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E714;
    }
    // 0x8006E704: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E708: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006E70C: nop

    // 0x8006E710: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_8006E714:
    // 0x8006E714: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8006E718: addiu       $t4, $a1, 0x2
    ctx->r12 = ADD32(ctx->r5, 0X2);
    // 0x8006E71C: sh          $t4, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r12;
    // 0x8006E720: b           L_8006EA14
    // 0x8006E724: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
        goto L_8006EA14;
    // 0x8006E724: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
L_8006E728:
    // 0x8006E728: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006E72C: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    // 0x8006E730: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E734: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E738: andi        $t8, $t2, 0x1FF
    ctx->r24 = ctx->r10 & 0X1FF;
    // 0x8006E73C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8006E740: nop

    // 0x8006E744: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E748: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x8006E74C: lhu         $t9, 0x2($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E750: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8006E754: bgez        $t9, L_8006E768
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006E758: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E768;
    }
    // 0x8006E758: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E75C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E760: nop

    // 0x8006E764: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006E768:
    // 0x8006E768: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8006E76C: addiu       $t5, $a1, 0x2
    ctx->r13 = ADD32(ctx->r5, 0X2);
    // 0x8006E770: sh          $t5, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r13;
    // 0x8006E774: b           L_8006EA14
    // 0x8006E778: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
        goto L_8006EA14;
    // 0x8006E778: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
L_8006E77C:
    // 0x8006E77C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8006E780: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
    // 0x8006E784: lhu         $t1, 0x0($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E788: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E78C: andi        $t3, $t1, 0x1FF
    ctx->r11 = ctx->r9 & 0X1FF;
    // 0x8006E790: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8006E794: nop

    // 0x8006E798: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E79C: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x8006E7A0: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E7A4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8006E7A8: bgez        $t6, L_8006E7BC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006E7AC: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E7BC;
    }
    // 0x8006E7AC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E7B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006E7B4: nop

    // 0x8006E7B8: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_8006E7BC:
    // 0x8006E7BC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8006E7C0: addiu       $t4, $a1, 0x2
    ctx->r12 = ADD32(ctx->r5, 0X2);
    // 0x8006E7C4: sh          $t4, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r12;
    // 0x8006E7C8: b           L_8006EA14
    // 0x8006E7CC: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
        goto L_8006EA14;
    // 0x8006E7CC: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
L_8006E7D0:
    // 0x8006E7D0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8006E7D4: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    // 0x8006E7D8: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E7DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E7E0: andi        $t8, $t2, 0x1FF
    ctx->r24 = ctx->r10 & 0X1FF;
    // 0x8006E7E4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8006E7E8: nop

    // 0x8006E7EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E7F0: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x8006E7F4: lhu         $t9, 0x2($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E7F8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8006E7FC: bgez        $t9, L_8006E810
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006E800: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E810;
    }
    // 0x8006E800: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E804: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E808: nop

    // 0x8006E80C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006E810:
    // 0x8006E810: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8006E814: addiu       $t5, $a1, 0x2
    ctx->r13 = ADD32(ctx->r5, 0X2);
    // 0x8006E818: sh          $t5, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r13;
    // 0x8006E81C: b           L_8006EA14
    // 0x8006E820: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
        goto L_8006EA14;
    // 0x8006E820: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
L_8006E824:
    // 0x8006E824: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8006E828: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E82C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E830: swc1        $f10, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f10.u32l;
    // 0x8006E834: lhu         $t1, 0x2($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E838: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8006E83C: bgez        $t1, L_8006E850
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8006E840: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E850;
    }
    // 0x8006E840: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E844: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006E848: nop

    // 0x8006E84C: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_8006E850:
    // 0x8006E850: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8006E854: addiu       $t3, $a1, 0x2
    ctx->r11 = ADD32(ctx->r5, 0X2);
    // 0x8006E858: swc1        $f22, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f22.u32l;
    // 0x8006E85C: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x8006E860: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E864: swc1        $f6, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f6.u32l;
    // 0x8006E868: b           L_8006D3F4
    // 0x8006E86C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E86C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8006E870: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
L_8006E874:
    // 0x8006E874: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E878: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E87C: swc1        $f10, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f10.u32l;
    // 0x8006E880: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E884: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8006E888: bgez        $t4, L_8006E89C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8006E88C: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E89C;
    }
    // 0x8006E88C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E890: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E894: nop

    // 0x8006E898: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006E89C:
    // 0x8006E89C: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8006E8A0: addiu       $t7, $a1, 0x2
    ctx->r15 = ADD32(ctx->r5, 0X2);
    // 0x8006E8A4: swc1        $f24, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f24.u32l;
    // 0x8006E8A8: sh          $t7, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r15;
    // 0x8006E8AC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E8B0: swc1        $f6, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f6.u32l;
    // 0x8006E8B4: b           L_8006D3F4
    // 0x8006E8B8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E8B8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E8BC:
    // 0x8006E8BC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8006E8C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E8C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E8C8: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x8006E8CC: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E8D0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8006E8D4: bgez        $t8, L_8006E8E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006E8D8: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E8E8;
    }
    // 0x8006E8D8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E8DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006E8E0: nop

    // 0x8006E8E4: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_8006E8E8:
    // 0x8006E8E8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8006E8EC: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x8006E8F0: swc1        $f22, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f22.u32l;
    // 0x8006E8F4: sh          $t9, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r25;
    // 0x8006E8F8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E8FC: swc1        $f6, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f6.u32l;
    // 0x8006E900: b           L_8006D3F4
    // 0x8006E904: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E904: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E908:
    // 0x8006E908: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8006E90C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E910: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E914: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x8006E918: lhu         $t0, 0x2($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E91C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8006E920: bgez        $t0, L_8006E934
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8006E924: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E934;
    }
    // 0x8006E924: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E92C: nop

    // 0x8006E930: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006E934:
    // 0x8006E934: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8006E938: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
    // 0x8006E93C: swc1        $f24, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f24.u32l;
    // 0x8006E940: sh          $t1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r9;
    // 0x8006E944: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E948: swc1        $f6, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f6.u32l;
    // 0x8006E94C: b           L_8006D3F4
    // 0x8006E950: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E950: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E954:
    // 0x8006E954: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8006E958: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E95C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E960: swc1        $f10, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f10.u32l;
    // 0x8006E964: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E968: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8006E96C: bgez        $t6, L_8006E980
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006E970: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E980;
    }
    // 0x8006E970: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E974: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006E978: nop

    // 0x8006E97C: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_8006E980:
    // 0x8006E980: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8006E984: addiu       $t4, $a1, 0x2
    ctx->r12 = ADD32(ctx->r5, 0X2);
    // 0x8006E988: swc1        $f22, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f22.u32l;
    // 0x8006E98C: sh          $t4, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r12;
    // 0x8006E990: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E994: swc1        $f6, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f6.u32l;
    // 0x8006E998: b           L_8006D3F4
    // 0x8006E99C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E99C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E9A0:
    // 0x8006E9A0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8006E9A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006E9A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006E9AC: swc1        $f10, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f10.u32l;
    // 0x8006E9B0: lhu         $t2, 0x2($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E9B4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8006E9B8: bgez        $t2, L_8006E9CC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006E9BC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8006E9CC;
    }
    // 0x8006E9BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006E9C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E9C4: nop

    // 0x8006E9C8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006E9CC:
    // 0x8006E9CC: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8006E9D0: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    // 0x8006E9D4: swc1        $f24, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f24.u32l;
    // 0x8006E9D8: sh          $t8, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r24;
    // 0x8006E9DC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E9E0: swc1        $f6, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f6.u32l;
    // 0x8006E9E4: b           L_8006D3F4
    // 0x8006E9E8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E9E8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006E9EC:
    // 0x8006E9EC: sw          $s6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r22;
    // 0x8006E9F0: sh          $t9, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r25;
    // 0x8006E9F4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006E9F8: b           L_8006D3F4
    // 0x8006E9FC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006E9FC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006EA00:
    // 0x8006EA00: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x8006EA04: sh          $t5, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r13;
    // 0x8006EA08: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006EA0C: b           L_8006D3F4
    // 0x8006EA10: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8006D3F4;
    // 0x8006EA10: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8006EA14:
    // 0x8006EA14: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8006EA18:
    // 0x8006EA18: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8006EA1C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8006EA20: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8006EA24: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8006EA28: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8006EA2C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8006EA30: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8006EA34: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8006EA38: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8006EA3C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8006EA40: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8006EA44: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8006EA48: jr          $ra
    // 0x8006EA4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006EA4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Message_IsPrintingChar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2F30: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C2F34: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800C2F38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C2F3C: beql        $t6, $zero, L_800C2FA8
    if (ctx->r14 == 0) {
        // 0x800C2F40: lw          $v0, 0x0($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X0);
            goto L_800C2FA8;
    }
    goto skip_0;
    // 0x800C2F40: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    skip_0:
    // 0x800C2F44: blez        $a1, L_800C2FA4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C2F48: sll         $t7, $zero, 1
        ctx->r15 = S32(0 << 1);
            goto L_800C2FA4;
    }
    // 0x800C2F48: sll         $t7, $zero, 1
    ctx->r15 = S32(0 << 1);
    // 0x800C2F4C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C2F50: lhu         $a3, 0x0($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X0);
    // 0x800C2F54: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
L_800C2F58:
    // 0x800C2F58: sltiu       $at, $t8, 0xF
    ctx->r1 = ctx->r24 < 0XF ? 1 : 0;
    // 0x800C2F5C: beq         $at, $zero, L_800C2F7C
    if (ctx->r1 == 0) {
        // 0x800C2F60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C2F7C;
    }
    // 0x800C2F60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C2F64: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C2F68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2F6C: addu        $at, $at, $t8
    gpr jr_addend_800C2F74 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C2F70: lw          $t8, -0x6C18($at)
    ctx->r24 = ADD32(ctx->r1, -0X6C18);
    // 0x800C2F74: jr          $t8
    // 0x800C2F78: nop

    switch (jr_addend_800C2F74 >> 2) {
        case 0: goto L_800C2F80; break;
        case 1: goto L_800C2F80; break;
        case 2: goto L_800C2F80; break;
        case 3: goto L_800C2F80; break;
        case 4: goto L_800C2F80; break;
        case 5: goto L_800C2F80; break;
        case 6: goto L_800C2F80; break;
        case 7: goto L_800C2F80; break;
        case 8: goto L_800C2F80; break;
        case 9: goto L_800C2F80; break;
        case 10: goto L_800C2F80; break;
        case 11: goto L_800C2F80; break;
        case 12: goto L_800C2F80; break;
        case 13: goto L_800C2F80; break;
        case 14: goto L_800C2F80; break;
        default: switch_error(__func__, 0x800C2F74, 0x800D93E8);
    }
    // 0x800C2F78: nop

L_800C2F7C:
    // 0x800C2F7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800C2F80:
    // 0x800C2F80: lhu         $a3, 0x2($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X2);
    // 0x800C2F84: sw          $v1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r3;
    // 0x800C2F88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C2F8C: beq         $a3, $zero, L_800C2FA4
    if (ctx->r7 == 0) {
        // 0x800C2F90: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800C2FA4;
    }
    // 0x800C2F90: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800C2F94: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C2F98: bnel        $at, $zero, L_800C2F58
    if (ctx->r1 != 0) {
        // 0x800C2F9C: addiu       $t8, $a3, -0x1
        ctx->r24 = ADD32(ctx->r7, -0X1);
            goto L_800C2F58;
    }
    goto skip_1;
    // 0x800C2F9C: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    skip_1:
    // 0x800C2FA0: sw          $v1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r3;
L_800C2FA4:
    // 0x800C2FA4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
L_800C2FA8:
    // 0x800C2FA8: jr          $ra
    // 0x800C2FAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C2FAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ActorTeamBoss_FlyAroundOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800910C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800910C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800910C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800910CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800910D0: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x800910D4: bne         $t6, $zero, L_80091168
    if (ctx->r14 != 0) {
        // 0x800910D8: nop
    
            goto L_80091168;
    }
    // 0x800910D8: nop

    // 0x800910DC: jal         0x80004EB0
    // 0x800910E0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800910E0: nop

    after_0:
    // 0x800910E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800910E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800910EC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800910F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800910F4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800910F8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800910FC: jal         0x80004EB0
    // 0x80091100: swc1        $f10, 0x2DC($s0)
    MEM_W(0X2DC, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80091100: swc1        $f10, 0x2DC($s0)
    MEM_W(0X2DC, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80091104: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80091108: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009110C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80091110: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80091114: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80091118: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009111C: jal         0x80004EB0
    // 0x80091120: swc1        $f6, 0x2E0($s0)
    MEM_W(0X2E0, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80091120: swc1        $f6, 0x2E0($s0)
    MEM_W(0X2E0, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x80091124: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80091128: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009112C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80091130: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80091134: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80091138: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009113C: jal         0x80004EB0
    // 0x80091140: swc1        $f18, 0x2E4($s0)
    MEM_W(0X2E4, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80091140: swc1        $f18, 0x2E4($s0)
    MEM_W(0X2E4, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x80091144: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80091148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009114C: nop

    // 0x80091150: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80091154: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80091158: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8009115C: nop

    // 0x80091160: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x80091164: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
L_80091168:
    // 0x80091168: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8009116C: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80091170: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80091174: lwc1        $f10, 0x2DC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2DC);
    // 0x80091178: lwc1        $f4, 0x2E0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
    // 0x8009117C: lwc1        $f6, 0x2E4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2E4);
    // 0x80091180: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80091184: swc1        $f4, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f4.u32l;
    // 0x80091188: lh          $t0, 0xE4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE4);
    // 0x8009118C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091190: swc1        $f18, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f18.u32l;
    // 0x80091194: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80091198: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8009119C: bne         $t0, $at, L_800911B0
    if (ctx->r8 != ctx->r1) {
        // 0x800911A0: swc1        $f10, 0x12C($s0)
        MEM_W(0X12C, ctx->r16) = ctx->f10.u32l;
            goto L_800911B0;
    }
    // 0x800911A0: swc1        $f10, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f10.u32l;
    // 0x800911A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800911A8: b           L_800911B8
    // 0x800911AC: lwc1        $f2, 0x7F44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7F44);
        goto L_800911B8;
    // 0x800911AC: lwc1        $f2, 0x7F44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7F44);
L_800911B0:
    // 0x800911B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800911B4: lwc1        $f2, 0x7F48($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7F48);
L_800911B8:
    // 0x800911B8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800911BC: lwc1        $f18, 0x124($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X124);
    // 0x800911C0: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800911C4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800911C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800911CC: nop

    // 0x800911D0: bc1fl       L_80091200
    if (!c1cs) {
        // 0x800911D4: lhu         $t1, 0xBE($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XBE);
            goto L_80091200;
    }
    goto skip_0;
    // 0x800911D4: lhu         $t1, 0xBE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBE);
    skip_0:
    // 0x800911D8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800911DC: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800911E0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800911E4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800911E8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800911EC: nop

    // 0x800911F0: bc1fl       L_80091200
    if (!c1cs) {
        // 0x800911F4: lhu         $t1, 0xBE($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XBE);
            goto L_80091200;
    }
    goto skip_1;
    // 0x800911F4: lhu         $t1, 0xBE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBE);
    skip_1:
    // 0x800911F8: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
    // 0x800911FC: lhu         $t1, 0xBE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBE);
L_80091200:
    // 0x80091200: bnel        $t1, $zero, L_80091240
    if (ctx->r9 != 0) {
        // 0x80091204: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80091240;
    }
    goto skip_2;
    // 0x80091204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80091208: jal         0x80004EB0
    // 0x8009120C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8009120C: nop

    after_4:
    // 0x80091210: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80091214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80091218: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8009121C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80091220: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80091224: swc1        $f18, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f18.u32l;
    // 0x80091228: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009122C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80091230: nop

    // 0x80091234: addiu       $t4, $t3, 0xC8
    ctx->r12 = ADD32(ctx->r11, 0XC8);
    // 0x80091238: sh          $t4, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r12;
    // 0x8009123C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091240:
    // 0x80091240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80091244: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80091248: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009124C: jr          $ra
    // 0x80091250: nop

    return;
    // 0x80091250: nop

;}
RECOMP_FUNC void Math_SmoothStepToVec3fArray(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BEEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009BEF0: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8009BEF4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8009BEF8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8009BEFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009BF00: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8009BF04: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8009BF08: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8009BF0C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8009BF10: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8009BF14: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8009BF18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8009BF1C: beq         $a2, $zero, L_8009BF34
    if (ctx->r6 == 0) {
        // 0x8009BF20: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009BF34;
    }
    // 0x8009BF20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009BF24: beq         $a2, $at, L_8009C020
    if (ctx->r6 == ctx->r1) {
        // 0x8009BF28: lwc1        $f20, 0x58($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0X58);
            goto L_8009C020;
    }
    // 0x8009BF28: lwc1        $f20, 0x58($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009BF2C: b           L_8009C100
    // 0x8009BF30: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009C100;
    // 0x8009BF30: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009BF34:
    // 0x8009BF34: blez        $s3, L_8009C0FC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8009BF38: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8009C0FC;
    }
    // 0x8009BF38: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8009BF3C: andi        $a2, $s3, 0x3
    ctx->r6 = ctx->r19 & 0X3;
    // 0x8009BF40: beq         $a2, $zero, L_8009BF88
    if (ctx->r6 == 0) {
        // 0x8009BF44: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8009BF88;
    }
    // 0x8009BF44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8009BF48: sll         $a1, $zero, 2
    ctx->r5 = S32(0 << 2);
    // 0x8009BF4C: subu        $a1, $a1, $zero
    ctx->r5 = SUB32(ctx->r5, 0);
    // 0x8009BF50: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8009BF54: addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // 0x8009BF58: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
L_8009BF5C:
    // 0x8009BF5C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009BF60: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8009BF64: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8009BF68: swc1        $f4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8009BF6C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009BF70: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8009BF74: swc1        $f6, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8009BF78: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8009BF7C: bne         $a0, $s2, L_8009BF5C
    if (ctx->r4 != ctx->r18) {
        // 0x8009BF80: swc1        $f8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
            goto L_8009BF5C;
    }
    // 0x8009BF80: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8009BF84: beq         $s2, $s3, L_8009C0FC
    if (ctx->r18 == ctx->r19) {
        // 0x8009BF88: sll         $a1, $s2, 2
        ctx->r5 = S32(ctx->r18 << 2);
            goto L_8009C0FC;
    }
L_8009BF88:
    // 0x8009BF88: sll         $a1, $s2, 2
    ctx->r5 = S32(ctx->r18 << 2);
    // 0x8009BF8C: subu        $a1, $a1, $s2
    ctx->r5 = SUB32(ctx->r5, ctx->r18);
    // 0x8009BF90: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x8009BF94: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x8009BF98: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8009BF9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009BFA0: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    // 0x8009BFA4: addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // 0x8009BFA8: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
L_8009BFAC:
    // 0x8009BFAC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009BFB0: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8009BFB4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x8009BFB8: swc1        $f10, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->f10.u32l;
    // 0x8009BFBC: lwc1        $f16, -0x2C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X2C);
    // 0x8009BFC0: swc1        $f16, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->f16.u32l;
    // 0x8009BFC4: lwc1        $f18, -0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X28);
    // 0x8009BFC8: swc1        $f18, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->f18.u32l;
    // 0x8009BFCC: lwc1        $f4, -0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X24);
    // 0x8009BFD0: swc1        $f4, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->f4.u32l;
    // 0x8009BFD4: lwc1        $f6, -0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X20);
    // 0x8009BFD8: swc1        $f6, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->f6.u32l;
    // 0x8009BFDC: lwc1        $f8, -0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X1C);
    // 0x8009BFE0: swc1        $f8, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->f8.u32l;
    // 0x8009BFE4: lwc1        $f10, -0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X18);
    // 0x8009BFE8: swc1        $f10, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f10.u32l;
    // 0x8009BFEC: lwc1        $f16, -0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X14);
    // 0x8009BFF0: swc1        $f16, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->f16.u32l;
    // 0x8009BFF4: lwc1        $f18, -0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X10);
    // 0x8009BFF8: swc1        $f18, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f18.u32l;
    // 0x8009BFFC: lwc1        $f4, -0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8009C000: swc1        $f4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8009C004: lwc1        $f6, -0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8009C008: swc1        $f6, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8009C00C: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8009C010: bne         $v0, $a0, L_8009BFAC
    if (ctx->r2 != ctx->r4) {
        // 0x8009C014: swc1        $f8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
            goto L_8009BFAC;
    }
    // 0x8009C014: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8009C018: b           L_8009C100
    // 0x8009C01C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009C100;
    // 0x8009C01C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009C020:
    // 0x8009C020: lwc1        $f22, 0x5C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009C024: lwc1        $f24, 0x60($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8009C028: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8009C02C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8009C030: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8009C034: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8009C038: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8009C03C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009C040: jal         0x8009BC2C
    // 0x8009C044: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8009C044: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_0:
    // 0x8009C048: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009C04C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8009C050: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8009C054: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8009C058: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x8009C05C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8009C060: jal         0x8009BC2C
    // 0x8009C064: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8009C064: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8009C068: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009C06C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8009C070: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8009C074: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8009C078: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x8009C07C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8009C080: jal         0x8009BC2C
    // 0x8009C084: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8009C084: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x8009C088: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8009C08C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8009C090: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x8009C094: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8009C098: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8009C09C: bne         $at, $zero, L_8009C0FC
    if (ctx->r1 != 0) {
        // 0x8009C0A0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8009C0FC;
    }
    // 0x8009C0A0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8009C0A4:
    // 0x8009C0A4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8009C0A8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8009C0AC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8009C0B0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8009C0B4: jal         0x8009BD38
    // 0x8009C0B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x8009C0B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8009C0BC: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8009C0C0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8009C0C4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8009C0C8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8009C0CC: jal         0x8009BD38
    // 0x8009C0D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x8009C0D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x8009C0D4: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8009C0D8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8009C0DC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8009C0E0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8009C0E4: jal         0x8009BD38
    // 0x8009C0E8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x8009C0E8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_5:
    // 0x8009C0EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8009C0F0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8009C0F4: bne         $s2, $s3, L_8009C0A4
    if (ctx->r18 != ctx->r19) {
        // 0x8009C0F8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8009C0A4;
    }
    // 0x8009C0F8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8009C0FC:
    // 0x8009C0FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009C100:
    // 0x8009C100: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8009C104: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8009C108: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8009C10C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8009C110: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8009C114: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C118: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8009C11C: jr          $ra
    // 0x8009C120: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009C120: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Fault_SetFrameBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007FE4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80007FE8: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80007FEC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80007FF0: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x80007FF4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80007FF8: addiu       $v0, $v0, 0x5360
    ctx->r2 = ADD32(ctx->r2, 0X5360);
    // 0x80007FFC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80008000: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80008004: sw          $a0, 0x9CC($v0)
    MEM_W(0X9CC, ctx->r2) = ctx->r4;
    // 0x80008008: sh          $a1, 0x9D0($v0)
    MEM_H(0X9D0, ctx->r2) = ctx->r5;
    // 0x8000800C: sh          $a2, 0x9D2($v0)
    MEM_H(0X9D2, ctx->r2) = ctx->r6;
    // 0x80008010: jr          $ra
    // 0x80008014: nop

    return;
    // 0x80008014: nop

;}
RECOMP_FUNC void Versus_UpdateStartCountdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEF00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BEF04: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BEF08: addiu       $a0, $a0, -0x7870
    ctx->r4 = ADD32(ctx->r4, -0X7870);
    // 0x800BEF0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BEF10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800BEF14: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BEF18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BEF1C: bne         $v0, $zero, L_800BEF2C
    if (ctx->r2 != 0) {
        // 0x800BEF20: addiu       $t0, $t0, -0x786C
        ctx->r8 = ADD32(ctx->r8, -0X786C);
            goto L_800BEF2C;
    }
    // 0x800BEF20: addiu       $t0, $t0, -0x786C
    ctx->r8 = ADD32(ctx->r8, -0X786C);
    // 0x800BEF24: b           L_800BEFD4
    // 0x800BEF28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800BEFD4;
    // 0x800BEF28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800BEF2C:
    // 0x800BEF2C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800BEF30: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800BEF34: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800BEF38: bne         $t7, $zero, L_800BEFD0
    if (ctx->r15 != 0) {
        // 0x800BEF3C: sw          $t7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r15;
            goto L_800BEFD0;
    }
    // 0x800BEF3C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800BEF40: beq         $t9, $zero, L_800BEF8C
    if (ctx->r25 == 0) {
        // 0x800BEF44: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_800BEF8C;
    }
    // 0x800BEF44: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BEF48: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800BEF4C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x800BEF50: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800BEF54: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x800BEF58: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BEF5C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BEF60: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BEF64: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x800BEF68: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800BEF6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800BEF70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800BEF74: jal         0x80019218
    // 0x800BEF78: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800BEF78: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800BEF7C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BEF80: addiu       $t0, $t0, -0x786C
    ctx->r8 = ADD32(ctx->r8, -0X786C);
    // 0x800BEF84: b           L_800BEFC8
    // 0x800BEF88: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_800BEFC8;
    // 0x800BEF88: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_800BEF8C:
    // 0x800BEF8C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800BEF90: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800BEF94: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800BEF98: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x800BEF9C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BEFA0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BEFA4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BEFA8: ori         $a0, $a0, 0x9
    ctx->r4 = ctx->r4 | 0X9;
    // 0x800BEFAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800BEFB0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800BEFB4: jal         0x80019218
    // 0x800BEFB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800BEFB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800BEFBC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BEFC0: addiu       $t0, $t0, -0x786C
    ctx->r8 = ADD32(ctx->r8, -0X786C);
    // 0x800BEFC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BEFC8:
    // 0x800BEFC8: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x800BEFCC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_800BEFD0:
    // 0x800BEFD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800BEFD4:
    // 0x800BEFD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEFD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BEFDC: jr          $ra
    // 0x800BEFE0: nop

    return;
    // 0x800BEFE0: nop

;}
RECOMP_FUNC void Lib_TextureRect_CI4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C320: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009C324: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009C328: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009C32C: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x8009C330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C334: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8009C338: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C33C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C340: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8009C344: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C348: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C34C: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8009C350: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C354: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C358: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C35C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009C360: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C364: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8009C368: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009C36C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C370: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C374: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009C378: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C37C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C380: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
    // 0x8009C384: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8009C388: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C38C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C390: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C394: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009C398: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C39C: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x8009C3A0: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8009C3A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009C3A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009C3AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009C3B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009C3B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C3B8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8009C3BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C3C0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C3C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C3C8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8009C3CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C3D0: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8009C3D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009C3D8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009C3DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009C3E0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C3E4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009C3E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C3EC: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8009C3F0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C3F4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C3F8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8009C3FC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009C400: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009C404: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C408: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C40C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C410: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C414: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009C418: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009C41C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8009C420: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009C424: srl         $v0, $a3, 4
    ctx->r2 = S32(U32(ctx->r7) >> 4);
    // 0x8009C428: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x8009C42C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009C430: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8009C434: mflo        $t4
    ctx->r12 = lo;
    // 0x8009C438: addiu       $t4, $t4, 0x3
    ctx->r12 = ADD32(ctx->r12, 0X3);
    // 0x8009C43C: srl         $t9, $t4, 2
    ctx->r25 = S32(U32(ctx->r12) >> 2);
    // 0x8009C440: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x8009C444: sltiu       $at, $t4, 0x7FF
    ctx->r1 = ctx->r12 < 0X7FF ? 1 : 0;
    // 0x8009C448: beql        $at, $zero, L_8009C45C
    if (ctx->r1 == 0) {
        // 0x8009C44C: addiu       $a2, $zero, 0x7FF
        ctx->r6 = ADD32(0, 0X7FF);
            goto L_8009C45C;
    }
    goto skip_0;
    // 0x8009C44C: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009C450: b           L_8009C45C
    // 0x8009C454: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
        goto L_8009C45C;
    // 0x8009C454: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8009C458: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
L_8009C45C:
    // 0x8009C45C: bne         $v0, $zero, L_8009C46C
    if (ctx->r2 != 0) {
        // 0x8009C460: lui         $at, 0xF540
        ctx->r1 = S32(0XF540 << 16);
            goto L_8009C46C;
    }
    // 0x8009C460: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8009C464: b           L_8009C470
    // 0x8009C468: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8009C470;
    // 0x8009C468: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8009C46C:
    // 0x8009C46C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8009C470:
    // 0x8009C470: bne         $v0, $zero, L_8009C480
    if (ctx->r2 != 0) {
        // 0x8009C474: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8009C480;
    }
    // 0x8009C474: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8009C478: b           L_8009C484
    // 0x8009C47C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009C484;
    // 0x8009C47C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009C480:
    // 0x8009C480: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009C484:
    // 0x8009C484: divu        $zero, $t6, $t3
    lo = S32(U32(ctx->r14) / U32(ctx->r11)); hi = S32(U32(ctx->r14) % U32(ctx->r11));
    // 0x8009C488: mflo        $t7
    ctx->r15 = lo;
    // 0x8009C48C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009C490: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x8009C494: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009C498: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x8009C49C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009C4A0: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8009C4A4: bne         $t3, $zero, L_8009C4B0
    if (ctx->r11 != 0) {
        // 0x8009C4A8: nop
    
            goto L_8009C4B0;
    }
    // 0x8009C4A8: nop

    // 0x8009C4AC: break       7
    do_break(2148123820);
L_8009C4B0:
    // 0x8009C4B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C4B4: srl         $t7, $a3, 1
    ctx->r15 = S32(U32(ctx->r7) >> 1);
    // 0x8009C4B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C4BC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C4C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C4C4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8009C4C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C4CC: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x8009C4D0: srl         $t6, $t8, 3
    ctx->r14 = S32(U32(ctx->r24) >> 3);
    // 0x8009C4D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009C4D8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009C4DC: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8009C4E0: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8009C4E4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8009C4E8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009C4EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C4F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C4F4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8009C4F8: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8009C4FC: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009C500: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C504: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C508: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009C50C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8009C510: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009C514: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8009C518: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8009C51C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8009C520: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8009C524: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009C528: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009C52C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8009C530: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8009C534: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009C538: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009C53C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009C540: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009C544: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009C548: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8009C54C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009C550: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009C554: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8009C558: bgez        $a3, L_8009C56C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009C55C: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_8009C56C;
    }
    // 0x8009C55C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C560: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009C564: nop

    // 0x8009C568: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009C56C:
    // 0x8009C56C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009C570: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8009C574: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009C578: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009C57C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009C580: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009C584: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009C588: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009C58C: nop

    // 0x8009C590: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8009C594: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009C598: bgez        $v1, L_8009C5B0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009C59C: or          $t6, $t8, $at
        ctx->r14 = ctx->r24 | ctx->r1;
            goto L_8009C5B0;
    }
    // 0x8009C59C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8009C5A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009C5A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009C5A8: nop

    // 0x8009C5AC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009C5B0:
    // 0x8009C5B0: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009C5B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009C5B8: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009C5BC: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009C5C0: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009C5C4: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009C5C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009C5CC: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009C5D0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009C5D4: nop

    // 0x8009C5D8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009C5DC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009C5E0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009C5E4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8009C5E8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009C5EC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009C5F0: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009C5F4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009C5F8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009C5FC: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8009C600: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009C604: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8009C608: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8009C60C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C610: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009C614: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009C618: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C61C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C620: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C624: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009C628: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009C62C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009C630: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C634: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009C638: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009C63C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C640: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C644: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009C648: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C64C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009C650: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009C654: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009C658: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009C65C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8009C660: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8009C664: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8009C668: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009C66C: jr          $ra
    // 0x8009C670: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8009C670: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Audio_StartSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017600: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80017604: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80017608: lbu         $t7, 0x5D4C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5D4C);
    // 0x8001760C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80017610: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x80017614: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80017618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001761C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80017620: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80017624: beq         $t7, $zero, L_8001763C
    if (ctx->r15 == 0) {
        // 0x80017628: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8001763C;
    }
    // 0x80017628: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001762C: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x80017630: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80017634: bnel        $t8, $at, L_80017754
    if (ctx->r24 != ctx->r1) {
        // 0x80017638: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80017754;
    }
    goto skip_0;
    // 0x80017638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8001763C:
    // 0x8001763C: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80017640: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x80017644: lui         $at, 0x8200
    ctx->r1 = S32(0X8200 << 16);
    // 0x80017648: sll         $v1, $t9, 16
    ctx->r3 = S32(ctx->r25 << 16);
    // 0x8001764C: or          $t1, $v1, $at
    ctx->r9 = ctx->r3 | ctx->r1;
    // 0x80017650: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80017654: or          $a0, $t1, $t4
    ctx->r4 = ctx->r9 | ctx->r12;
    // 0x80017658: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001765C: jal         0x8001E8CC
    // 0x80017660: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_0;
    // 0x80017660: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80017664: lbu         $t5, 0x33($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X33);
    // 0x80017668: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001766C: addiu       $t7, $t7, -0x5258
    ctx->r15 = ADD32(ctx->r15, -0X5258);
    // 0x80017670: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80017674: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80017678: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001767C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80017680: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80017684: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80017688: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001768C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017690: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80017694: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80017698: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001769C: lbu         $t9, 0x3B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3B);
    // 0x800176A0: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x800176A4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800176A8: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800176AC: or          $v0, $t8, $t0
    ctx->r2 = ctx->r24 | ctx->r8;
    // 0x800176B0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800176B4: sh          $v0, 0x248($a2)
    MEM_H(0X248, ctx->r6) = ctx->r2;
    // 0x800176B8: bc1t        L_800176E0
    if (c1cs) {
        // 0x800176BC: sh          $v0, 0x24A($a2)
        MEM_H(0X24A, ctx->r6) = ctx->r2;
            goto L_800176E0;
    }
    // 0x800176BC: sh          $v0, 0x24A($a2)
    MEM_H(0X24A, ctx->r6) = ctx->r2;
    // 0x800176C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800176C4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800176C8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x800176CC: jal         0x8001E8A8
    // 0x800176D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_1;
    // 0x800176D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800176D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800176D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800176DC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800176E0:
    // 0x800176E0: lbu         $t2, 0x33($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X33);
    // 0x800176E4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800176E8: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x800176EC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800176F0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800176F4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800176F8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800176FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80017700: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80017704: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80017708: sh          $zero, 0x28($a2)
    MEM_H(0X28, ctx->r6) = 0;
    // 0x8001770C: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x80017710: sw          $zero, 0x14($a2)
    MEM_W(0X14, ctx->r6) = 0;
    // 0x80017714: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    // 0x80017718: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001771C:
    // 0x8001771C: sll         $t4, $v1, 5
    ctx->r12 = S32(ctx->r3 << 5);
    // 0x80017720: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80017724: addu        $v0, $a0, $t4
    ctx->r2 = ADD32(ctx->r4, ctx->r12);
    // 0x80017728: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8001772C: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x80017730: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80017734: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x80017738: sh          $zero, 0x50($v0)
    MEM_H(0X50, ctx->r2) = 0;
    // 0x8001773C: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x80017740: bne         $at, $zero, L_8001771C
    if (ctx->r1 != 0) {
        // 0x80017744: sh          $zero, 0x60($v0)
        MEM_H(0X60, ctx->r2) = 0;
            goto L_8001771C;
    }
    // 0x80017744: sh          $zero, 0x60($v0)
    MEM_H(0X60, ctx->r2) = 0;
    // 0x80017748: sh          $zero, 0x244($a2)
    MEM_H(0X244, ctx->r6) = 0;
    // 0x8001774C: sh          $zero, 0x246($a2)
    MEM_H(0X246, ctx->r6) = 0;
    // 0x80017750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80017754:
    // 0x80017754: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80017758: jr          $ra
    // 0x8001775C: nop

    return;
    // 0x8001775C: nop

;}
RECOMP_FUNC void Display_Player_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800564C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800564C4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800564C8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800564CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800564D0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800564D4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800564D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800564DC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800564E0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800564E4: addiu       $t7, $t7, -0x5CD8
    ctx->r15 = ADD32(ctx->r15, -0X5CD8);
    // 0x800564E8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800564EC: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x800564F0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800564F4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800564F8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800564FC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80056500: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80056504: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80056508: lw          $t1, 0x234($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X234);
    // 0x8005650C: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x80056510: beql        $t1, $zero, L_80056E14
    if (ctx->r9 == 0) {
        // 0x80056514: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80056E14;
    }
    goto skip_0;
    // 0x80056514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80056518: jal         0x80005708
    // 0x8005651C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8005651C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80056520: lw          $v0, 0x1CC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1CC);
    // 0x80056524: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056528: bnel        $v0, $at, L_8005684C
    if (ctx->r2 != ctx->r1) {
        // 0x8005652C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005684C;
    }
    goto skip_1;
    // 0x8005652C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x80056530: lw          $t2, 0x1D4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X1D4);
    // 0x80056534: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80056538: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005653C: beql        $t2, $zero, L_80056564
    if (ctx->r10 == 0) {
        // 0x80056540: lwc1        $f4, 0x78($s2)
        ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
            goto L_80056564;
    }
    goto skip_2;
    // 0x80056540: lwc1        $f4, 0x78($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
    skip_2:
    // 0x80056544: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80056548: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8005654C: lw          $a2, -0x7B84($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B84);
    // 0x80056550: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80056554: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80056558: jal         0x80005B00
    // 0x8005655C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8005655C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    // 0x80056560: lwc1        $f4, 0x78($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
L_80056564:
    // 0x80056564: lwc1        $f6, 0x18C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18C);
    // 0x80056568: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8005656C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80056570: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056574: lwc1        $f6, 0x144($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X144);
    // 0x80056578: lwc1        $f4, 0x138($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X138);
    // 0x8005657C: lw          $a1, 0x74($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X74);
    // 0x80056580: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056584: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80056588: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005658C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056590: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80056594: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056598: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8005659C: jal         0x80005B00
    // 0x800565A0: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x800565A0: nop

    after_2:
    // 0x800565A4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800565A8: lw          $t5, 0x78E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78E8);
    // 0x800565AC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800565B0: beql        $t5, $zero, L_800566E4
    if (ctx->r13 == 0) {
        // 0x800565B4: lw          $a0, 0x1C4($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X1C4);
            goto L_800566E4;
    }
    goto skip_3;
    // 0x800565B4: lw          $a0, 0x1C4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C4);
    skip_3:
    // 0x800565B8: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x800565BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800565C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800565C4: blez        $t9, L_800566E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800565C8: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800566E0;
    }
    // 0x800565C8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800565CC: addiu       $v1, $v1, 0x7B00
    ctx->r3 = ADD32(ctx->r3, 0X7B00);
    // 0x800565D0: lw          $t8, 0x1C4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C4);
L_800565D4:
    // 0x800565D4: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x800565D8: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x800565DC: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800565E0: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800565E4: addu        $t0, $t7, $v0
    ctx->r8 = ADD32(ctx->r15, ctx->r2);
    // 0x800565E8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800565EC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800565F0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800565F4: beq         $t1, $zero, L_800566C4
    if (ctx->r9 == 0) {
        // 0x800565F8: lui         $t3, 0x8016
        ctx->r11 = S32(0X8016 << 16);
            goto L_800566C4;
    }
    // 0x800565F8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800565FC: addiu       $t3, $t3, 0x1578
    ctx->r11 = ADD32(ctx->r11, 0X1578);
    // 0x80056600: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x80056604: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80056608: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8005660C: jal         0x80006970
    // 0x80056610: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x80056610: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80056614: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80056618: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x8005661C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80056620: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80056624: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80056628: addiu       $v1, $v1, 0x7B00
    ctx->r3 = ADD32(ctx->r3, 0X7B00);
    // 0x8005662C: bne         $s1, $t4, L_800566C4
    if (ctx->r17 != ctx->r12) {
        // 0x80056630: lw          $v0, 0x3C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X3C);
            goto L_800566C4;
    }
    // 0x80056630: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80056634: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80056638: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005663C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80056640: lui         $at, 0xC5FA
    ctx->r1 = S32(0XC5FA << 16);
    // 0x80056644: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80056648: nop

    // 0x8005664C: bc1tl       L_800566B4
    if (c1cs) {
        // 0x80056650: lw          $t5, 0x1C4($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X1C4);
            goto L_800566B4;
    }
    goto skip_4;
    // 0x80056650: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
    skip_4:
    // 0x80056654: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80056658: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005665C: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80056660: nop

    // 0x80056664: bc1tl       L_800566B4
    if (c1cs) {
        // 0x80056668: lw          $t5, 0x1C4($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X1C4);
            goto L_800566B4;
    }
    goto skip_5;
    // 0x80056668: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
    skip_5:
    // 0x8005666C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80056670: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80056674: mul.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80056678: abs.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = fabsf(ctx->f0.fl);
    // 0x8005667C: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x80056680: add.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80056684: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80056688: nop

    // 0x8005668C: bc1tl       L_800566B4
    if (c1cs) {
        // 0x80056690: lw          $t5, 0x1C4($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X1C4);
            goto L_800566B4;
    }
    goto skip_6;
    // 0x80056690: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
    skip_6:
    // 0x80056694: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80056698: add.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8005669C: abs.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = fabsf(ctx->f0.fl);
    // 0x800566A0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x800566A4: nop

    // 0x800566A8: bc1f        L_800566C4
    if (!c1cs) {
        // 0x800566AC: nop
    
            goto L_800566C4;
    }
    // 0x800566AC: nop

    // 0x800566B0: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
L_800566B4:
    // 0x800566B4: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x800566B8: addu        $t8, $v1, $t9
    ctx->r24 = ADD32(ctx->r3, ctx->r25);
    // 0x800566BC: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800566C0: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_800566C4:
    // 0x800566C4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800566C8: lw          $t7, 0x78A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A8);
    // 0x800566CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800566D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800566D4: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800566D8: bnel        $at, $zero, L_800565D4
    if (ctx->r1 != 0) {
        // 0x800566DC: lw          $t8, 0x1C4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X1C4);
            goto L_800565D4;
    }
    goto skip_7;
    // 0x800566DC: lw          $t8, 0x1C4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C4);
    skip_7:
L_800566E0:
    // 0x800566E0: lw          $a0, 0x1C4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C4);
L_800566E4:
    // 0x800566E4: jal         0x800563B4
    // 0x800566E8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    Display_CheckPlayerVisible(rdram, ctx);
        goto after_4;
    // 0x800566E8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_4:
    // 0x800566EC: bnel        $v0, $zero, L_80056708
    if (ctx->r2 != 0) {
        // 0x800566F0: lwc1        $f10, 0xE4($s2)
        ctx->f10.u32l = MEM_W(ctx->r18, 0XE4);
            goto L_80056708;
    }
    goto skip_8;
    // 0x800566F0: lwc1        $f10, 0xE4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE4);
    skip_8:
    // 0x800566F4: jal         0x80005740
    // 0x800566F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x800566F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x800566FC: b           L_80056E14
    // 0x80056700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80056E14;
    // 0x80056700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80056704: lwc1        $f10, 0xE4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE4);
L_80056708:
    // 0x80056708: lwc1        $f18, 0x134($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X134);
    // 0x8005670C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056710: lwc1        $f6, 0x5F10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F10);
    // 0x80056714: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80056718: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8005671C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056720: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80056724: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80056728: jal         0x80005D44
    // 0x8005672C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x8005672C: nop

    after_6:
    // 0x80056730: lwc1        $f10, 0xEC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XEC);
    // 0x80056734: lwc1        $f18, 0xF0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XF0);
    // 0x80056738: lwc1        $f6, 0x134($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X134);
    // 0x8005673C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056740: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80056744: lwc1        $f10, 0x5F14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F14);
    // 0x80056748: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8005674C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056750: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056754: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80056758: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005675C: jal         0x80005FE0
    // 0x80056760: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80056760: nop

    after_7:
    // 0x80056764: lwc1        $f4, 0x114($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X114);
    // 0x80056768: lwc1        $f6, 0xE8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XE8);
    // 0x8005676C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80056770: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80056774: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056778: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005677C: lwc1        $f4, 0x5F18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F18);
    // 0x80056780: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056784: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005678C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80056790: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80056794: jal         0x80005E90
    // 0x80056798: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80056798: nop

    after_8:
    // 0x8005679C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800567A0: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x800567A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800567A8: beql        $t0, $zero, L_800567D4
    if (ctx->r8 == 0) {
        // 0x800567AC: lwc1        $f4, 0x12C($s2)
        ctx->f4.u32l = MEM_W(ctx->r18, 0X12C);
            goto L_800567D4;
    }
    goto skip_9;
    // 0x800567AC: lwc1        $f4, 0x12C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X12C);
    skip_9:
    // 0x800567B0: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800567B4: lwc1        $f10, 0x5F1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F1C);
    // 0x800567B8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800567BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800567C0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800567C4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800567C8: jal         0x80005D44
    // 0x800567CC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x800567CC: nop

    after_9:
    // 0x800567D0: lwc1        $f4, 0x12C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X12C);
L_800567D4:
    // 0x800567D4: lwc1        $f8, 0x130($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X130);
    // 0x800567D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800567DC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800567E0: lwc1        $f18, 0x5F20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F20);
    // 0x800567E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800567E8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800567EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800567F0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800567F4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800567F8: jal         0x80005FE0
    // 0x800567FC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_10;
    // 0x800567FC: nop

    after_10:
    // 0x80056800: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80056804: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80056808: lwc1        $f6, 0x80($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X80);
    // 0x8005680C: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    // 0x80056810: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80056814: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80056818: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005681C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056820: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80056824: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80056828: jal         0x80005B00
    // 0x8005682C: nop

    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x8005682C: nop

    after_11:
    // 0x80056830: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80056834: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80056838: jal         0x80006EB8
    // 0x8005683C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_12;
    // 0x8005683C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80056840: b           L_80056C44
    // 0x80056844: lw          $v0, 0x200($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X200);
        goto L_80056C44;
    // 0x80056844: lw          $v0, 0x200($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X200);
    // 0x80056848: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8005684C:
    // 0x8005684C: bnel        $v0, $at, L_800569D4
    if (ctx->r2 != ctx->r1) {
        // 0x80056850: lwc1        $f10, 0x138($s2)
        ctx->f10.u32l = MEM_W(ctx->r18, 0X138);
            goto L_800569D4;
    }
    goto skip_10;
    // 0x80056850: lwc1        $f10, 0x138($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X138);
    skip_10:
    // 0x80056854: jal         0x80005708
    // 0x80056858: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_13;
    // 0x80056858: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x8005685C: lwc1        $f18, 0x138($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X138);
    // 0x80056860: lwc1        $f4, 0x144($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X144);
    // 0x80056864: lw          $a1, 0x74($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X74);
    // 0x80056868: lw          $a2, 0x78($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X78);
    // 0x8005686C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80056870: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80056874: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80056878: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8005687C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80056880: jal         0x80005B00
    // 0x80056884: nop

    Matrix_Translate(rdram, ctx);
        goto after_14;
    // 0x80056884: nop

    after_14:
    // 0x80056888: lw          $a0, 0x1C4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C4);
    // 0x8005688C: jal         0x800563B4
    // 0x80056890: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    Display_CheckPlayerVisible(rdram, ctx);
        goto after_15;
    // 0x80056890: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_15:
    // 0x80056894: bne         $v0, $zero, L_800568B4
    if (ctx->r2 != 0) {
        // 0x80056898: nop
    
            goto L_800568B4;
    }
    // 0x80056898: nop

    // 0x8005689C: jal         0x80005740
    // 0x800568A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x800568A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x800568A4: jal         0x80005740
    // 0x800568A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x800568A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x800568AC: b           L_80056E14
    // 0x800568B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80056E14;
    // 0x800568B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800568B4:
    // 0x800568B4: jal         0x80005740
    // 0x800568B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_18;
    // 0x800568B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_18:
    // 0x800568BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800568C0: lwc1        $f10, -0x7B84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x800568C4: lwc1        $f8, 0x78($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X78);
    // 0x800568C8: lwc1        $f4, 0x138($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X138);
    // 0x800568CC: lwc1        $f6, 0x144($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X144);
    // 0x800568D0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800568D4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800568D8: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x800568DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800568E0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800568E4: lw          $a1, 0x74($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X74);
    // 0x800568E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800568EC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800568F0: jal         0x80005B00
    // 0x800568F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_19;
    // 0x800568F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_19:
    // 0x800568F8: lwc1        $f10, 0x114($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X114);
    // 0x800568FC: lwc1        $f18, 0xE8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XE8);
    // 0x80056900: lwc1        $f6, 0x134($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X134);
    // 0x80056904: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80056908: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8005690C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80056910: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056914: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056918: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005691C: lwc1        $f4, 0x5F24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F24);
    // 0x80056920: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056924: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056928: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005692C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80056930: jal         0x80005E90
    // 0x80056934: nop

    Matrix_RotateY(rdram, ctx);
        goto after_20;
    // 0x80056934: nop

    after_20:
    // 0x80056938: lwc1        $f8, 0x120($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X120);
    // 0x8005693C: lwc1        $f10, 0xE4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE4);
    // 0x80056940: lwc1        $f4, 0x134($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X134);
    // 0x80056944: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056948: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8005694C: lwc1        $f8, 0x5F28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F28);
    // 0x80056950: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80056954: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056958: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005695C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80056960: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80056964: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80056968: jal         0x80005D44
    // 0x8005696C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_21;
    // 0x8005696C: nop

    after_21:
    // 0x80056970: lwc1        $f4, 0xF8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XF8);
    // 0x80056974: lwc1        $f6, 0xF0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XF0);
    // 0x80056978: lwc1        $f10, 0x134($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X134);
    // 0x8005697C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056980: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056984: lwc1        $f4, 0x5F2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F2C);
    // 0x80056988: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005698C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056990: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056994: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80056998: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8005699C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800569A0: jal         0x80005FE0
    // 0x800569A4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_22;
    // 0x800569A4: nop

    after_22:
    // 0x800569A8: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    // 0x800569AC: lw          $a2, 0x80($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X80);
    // 0x800569B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800569B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800569B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800569BC: jal         0x80005B00
    // 0x800569C0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_23;
    // 0x800569C0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_23:
    // 0x800569C4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800569C8: b           L_80056C40
    // 0x800569CC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
        goto L_80056C40;
    // 0x800569CC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800569D0: lwc1        $f10, 0x138($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X138);
L_800569D4:
    // 0x800569D4: lwc1        $f18, 0x144($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X144);
    // 0x800569D8: lw          $a1, 0x74($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X74);
    // 0x800569DC: lw          $a2, 0x78($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X78);
    // 0x800569E0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800569E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800569E8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800569EC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800569F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800569F4: jal         0x80005B00
    // 0x800569F8: nop

    Matrix_Translate(rdram, ctx);
        goto after_24;
    // 0x800569F8: nop

    after_24:
    // 0x800569FC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80056A00: lw          $t5, 0x78E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78E8);
    // 0x80056A04: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80056A08: beql        $t5, $zero, L_80056B3C
    if (ctx->r13 == 0) {
        // 0x80056A0C: lw          $a0, 0x1C4($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X1C4);
            goto L_80056B3C;
    }
    goto skip_11;
    // 0x80056A0C: lw          $a0, 0x1C4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C4);
    skip_11:
    // 0x80056A10: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x80056A14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80056A18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056A1C: blez        $t9, L_80056B38
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80056A20: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_80056B38;
    }
    // 0x80056A20: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80056A24: addiu       $v1, $v1, 0x7B00
    ctx->r3 = ADD32(ctx->r3, 0X7B00);
    // 0x80056A28: lw          $t8, 0x1C4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C4);
L_80056A2C:
    // 0x80056A2C: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80056A30: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80056A34: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80056A38: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80056A3C: addu        $t0, $t7, $v0
    ctx->r8 = ADD32(ctx->r15, ctx->r2);
    // 0x80056A40: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80056A44: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80056A48: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80056A4C: beq         $t1, $zero, L_80056B1C
    if (ctx->r9 == 0) {
        // 0x80056A50: lui         $t3, 0x8016
        ctx->r11 = S32(0X8016 << 16);
            goto L_80056B1C;
    }
    // 0x80056A50: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80056A54: addiu       $t3, $t3, 0x1578
    ctx->r11 = ADD32(ctx->r11, 0X1578);
    // 0x80056A58: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x80056A5C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80056A60: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056A64: jal         0x80006970
    // 0x80056A68: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    Matrix_MultVec3f(rdram, ctx);
        goto after_25;
    // 0x80056A68: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_25:
    // 0x80056A6C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80056A70: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x80056A74: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80056A78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80056A7C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80056A80: addiu       $v1, $v1, 0x7B00
    ctx->r3 = ADD32(ctx->r3, 0X7B00);
    // 0x80056A84: bne         $s1, $t4, L_80056B1C
    if (ctx->r17 != ctx->r12) {
        // 0x80056A88: lw          $v0, 0x3C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X3C);
            goto L_80056B1C;
    }
    // 0x80056A88: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80056A8C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80056A90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80056A94: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80056A98: lui         $at, 0xC5FA
    ctx->r1 = S32(0XC5FA << 16);
    // 0x80056A9C: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80056AA0: nop

    // 0x80056AA4: bc1tl       L_80056B0C
    if (c1cs) {
        // 0x80056AA8: lw          $t5, 0x1C4($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X1C4);
            goto L_80056B0C;
    }
    goto skip_12;
    // 0x80056AA8: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
    skip_12:
    // 0x80056AAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80056AB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80056AB4: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80056AB8: nop

    // 0x80056ABC: bc1tl       L_80056B0C
    if (c1cs) {
        // 0x80056AC0: lw          $t5, 0x1C4($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X1C4);
            goto L_80056B0C;
    }
    goto skip_13;
    // 0x80056AC0: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
    skip_13:
    // 0x80056AC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80056AC8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80056ACC: mul.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80056AD0: abs.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = fabsf(ctx->f0.fl);
    // 0x80056AD4: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x80056AD8: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80056ADC: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x80056AE0: nop

    // 0x80056AE4: bc1tl       L_80056B0C
    if (c1cs) {
        // 0x80056AE8: lw          $t5, 0x1C4($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X1C4);
            goto L_80056B0C;
    }
    goto skip_14;
    // 0x80056AE8: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
    skip_14:
    // 0x80056AEC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80056AF0: add.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80056AF4: abs.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = fabsf(ctx->f0.fl);
    // 0x80056AF8: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80056AFC: nop

    // 0x80056B00: bc1f        L_80056B1C
    if (!c1cs) {
        // 0x80056B04: nop
    
            goto L_80056B1C;
    }
    // 0x80056B04: nop

    // 0x80056B08: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
L_80056B0C:
    // 0x80056B0C: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x80056B10: addu        $t8, $v1, $t9
    ctx->r24 = ADD32(ctx->r3, ctx->r25);
    // 0x80056B14: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80056B18: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_80056B1C:
    // 0x80056B1C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80056B20: lw          $t7, 0x78A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A8);
    // 0x80056B24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80056B28: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80056B2C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80056B30: bnel        $at, $zero, L_80056A2C
    if (ctx->r1 != 0) {
        // 0x80056B34: lw          $t8, 0x1C4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X1C4);
            goto L_80056A2C;
    }
    goto skip_15;
    // 0x80056B34: lw          $t8, 0x1C4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C4);
    skip_15:
L_80056B38:
    // 0x80056B38: lw          $a0, 0x1C4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C4);
L_80056B3C:
    // 0x80056B3C: jal         0x800563B4
    // 0x80056B40: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    Display_CheckPlayerVisible(rdram, ctx);
        goto after_26;
    // 0x80056B40: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_26:
    // 0x80056B44: bnel        $v0, $zero, L_80056B60
    if (ctx->r2 != 0) {
        // 0x80056B48: lwc1        $f6, 0x114($s2)
        ctx->f6.u32l = MEM_W(ctx->r18, 0X114);
            goto L_80056B60;
    }
    goto skip_16;
    // 0x80056B48: lwc1        $f6, 0x114($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X114);
    skip_16:
    // 0x80056B4C: jal         0x80005740
    // 0x80056B50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_27;
    // 0x80056B50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_27:
    // 0x80056B54: b           L_80056E14
    // 0x80056B58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80056E14;
    // 0x80056B58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80056B5C: lwc1        $f6, 0x114($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X114);
L_80056B60:
    // 0x80056B60: lwc1        $f8, 0xE8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XE8);
    // 0x80056B64: lwc1        $f18, 0x134($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X134);
    // 0x80056B68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80056B6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80056B70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80056B74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056B78: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056B7C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80056B80: lwc1        $f10, 0x5F30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F30);
    // 0x80056B84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056B88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056B8C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80056B90: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80056B94: jal         0x80005E90
    // 0x80056B98: nop

    Matrix_RotateY(rdram, ctx);
        goto after_28;
    // 0x80056B98: nop

    after_28:
    // 0x80056B9C: lwc1        $f4, 0x120($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X120);
    // 0x80056BA0: lwc1        $f6, 0xE4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XE4);
    // 0x80056BA4: lwc1        $f10, 0x4D8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4D8);
    // 0x80056BA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056BAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056BB0: lwc1        $f4, 0x134($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X134);
    // 0x80056BB4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056BB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056BBC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056BC0: lwc1        $f8, 0x5F34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F34);
    // 0x80056BC4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80056BC8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80056BCC: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80056BD0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80056BD4: jal         0x80005D44
    // 0x80056BD8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_29;
    // 0x80056BD8: nop

    after_29:
    // 0x80056BDC: lwc1        $f4, 0xF8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XF8);
    // 0x80056BE0: lwc1        $f6, 0xF0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XF0);
    // 0x80056BE4: lwc1        $f10, 0x134($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X134);
    // 0x80056BE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056BEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056BF0: lwc1        $f4, 0x5F38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F38);
    // 0x80056BF4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056BFC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056C00: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80056C04: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80056C08: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80056C0C: jal         0x80005FE0
    // 0x80056C10: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_30;
    // 0x80056C10: nop

    after_30:
    // 0x80056C14: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    // 0x80056C18: lw          $a2, 0x80($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X80);
    // 0x80056C1C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80056C20: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80056C24: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80056C28: jal         0x80005B00
    // 0x80056C2C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_31;
    // 0x80056C2C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_31:
    // 0x80056C30: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80056C34: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80056C38: jal         0x80006EB8
    // 0x80056C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_32;
    // 0x80056C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
L_80056C40:
    // 0x80056C40: lw          $v0, 0x200($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X200);
L_80056C44:
    // 0x80056C44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056C48: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80056C4C: beq         $v0, $zero, L_80056C6C
    if (ctx->r2 == 0) {
        // 0x80056C50: nop
    
            goto L_80056C6C;
    }
    // 0x80056C50: nop

    // 0x80056C54: beq         $v0, $at, L_80056D8C
    if (ctx->r2 == ctx->r1) {
        // 0x80056C58: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80056D8C;
    }
    // 0x80056C58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80056C5C: beq         $v0, $at, L_80056DBC
    if (ctx->r2 == ctx->r1) {
        // 0x80056C60: nop
    
            goto L_80056DBC;
    }
    // 0x80056C60: nop

    // 0x80056C64: b           L_80056DC8
    // 0x80056C68: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
        goto L_80056DC8;
    // 0x80056C68: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80056C6C:
    // 0x80056C6C: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x80056C70: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80056C74: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80056C78: bne         $t1, $zero, L_80056D18
    if (ctx->r9 != 0) {
        // 0x80056C7C: nop
    
            goto L_80056D18;
    }
    // 0x80056C7C: nop

    // 0x80056C80: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80056C84: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80056C88: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80056C8C: beq         $v0, $at, L_80056CA0
    if (ctx->r2 == ctx->r1) {
        // 0x80056C90: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_80056CA0;
    }
    // 0x80056C90: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80056C94: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80056C98: bne         $v0, $at, L_80056CD8
    if (ctx->r2 != ctx->r1) {
        // 0x80056C9C: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_80056CD8;
    }
    // 0x80056C9C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
L_80056CA0:
    // 0x80056CA0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80056CA4: lw          $t2, -0x7C28($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C28);
    // 0x80056CA8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80056CAC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80056CB0: addiu       $t3, $zero, 0x3ED
    ctx->r11 = ADD32(0, 0X3ED);
    // 0x80056CB4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80056CB8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80056CBC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80056CC0: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80056CC4: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80056CC8: jal         0x800BA1D0
    // 0x80056CCC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    RCP_SetupDL_29(rdram, ctx);
        goto after_33;
    // 0x80056CCC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_33:
    // 0x80056CD0: b           L_80056DC8
    // 0x80056CD4: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
        goto L_80056DC8;
    // 0x80056CD4: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80056CD8:
    // 0x80056CD8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80056CDC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80056CE0: lw          $t5, -0x7C24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C24);
    // 0x80056CE4: lw          $t4, -0x7C28($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C28);
    // 0x80056CE8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80056CEC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80056CF0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80056CF4: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80056CF8: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80056CFC: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80056D00: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80056D04: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80056D08: jal         0x800BA1D0
    // 0x80056D0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    RCP_SetupDL_29(rdram, ctx);
        goto after_34;
    // 0x80056D0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_34:
    // 0x80056D10: b           L_80056DC8
    // 0x80056D14: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
        goto L_80056DC8;
    // 0x80056D14: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80056D18:
    // 0x80056D18: lw          $t9, 0x789C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X789C);
    // 0x80056D1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80056D20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80056D24: bne         $t9, $at, L_80056D60
    if (ctx->r25 != ctx->r1) {
        // 0x80056D28: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80056D60;
    }
    // 0x80056D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80056D2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80056D30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056D34: lw          $t6, -0x7C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C24);
    // 0x80056D38: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x80056D3C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80056D40: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80056D44: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80056D48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80056D4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80056D50: jal         0x800BA1D0
    // 0x80056D54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_29(rdram, ctx);
        goto after_35;
    // 0x80056D54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_35:
    // 0x80056D58: b           L_80056DC8
    // 0x80056D5C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
        goto L_80056DC8;
    // 0x80056D5C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80056D60:
    // 0x80056D60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056D64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80056D68: lw          $t0, -0x7C24($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7C24);
    // 0x80056D6C: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x80056D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80056D74: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80056D78: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80056D7C: jal         0x800BA1D0
    // 0x80056D80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_29(rdram, ctx);
        goto after_36;
    // 0x80056D80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_36:
    // 0x80056D84: b           L_80056DC8
    // 0x80056D88: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
        goto L_80056DC8;
    // 0x80056D88: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80056D8C:
    // 0x80056D8C: jal         0x800BA400
    // 0x80056D90: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_37;
    // 0x80056D90: nop

    after_37:
    // 0x80056D94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80056D98: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x80056D9C: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x80056DA0: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80056DA4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80056DA8: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80056DAC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80056DB0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80056DB4: b           L_80056DC8
    // 0x80056DB8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
        goto L_80056DC8;
    // 0x80056DB8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80056DBC:
    // 0x80056DBC: jal         0x800BA430
    // 0x80056DC0: nop

    RCP_SetupDL_32(rdram, ctx);
        goto after_38;
    // 0x80056DC0: nop

    after_38:
    // 0x80056DC4: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80056DC8:
    // 0x80056DC8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80056DCC: beql        $t4, $zero, L_80056DE8
    if (ctx->r12 == 0) {
        // 0x80056DD0: lw          $t5, 0x1C4($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X1C4);
            goto L_80056DE8;
    }
    goto skip_17;
    // 0x80056DD0: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
    skip_17:
    // 0x80056DD4: jal         0x800596C0
    // 0x80056DD8: nop

    Object_ApplyWaterDistortion(rdram, ctx);
        goto after_39;
    // 0x80056DD8: nop

    after_39:
    // 0x80056DDC: b           L_80056E00
    // 0x80056DE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80056E00;
    // 0x80056DE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80056DE4: lw          $t5, 0x1C4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C4);
L_80056DE8:
    // 0x80056DE8: addiu       $t8, $t8, 0x1418
    ctx->r24 = ADD32(ctx->r24, 0X1418);
    // 0x80056DEC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80056DF0: sll         $t9, $t5, 6
    ctx->r25 = S32(ctx->r13 << 6);
    // 0x80056DF4: jal         0x80005680
    // 0x80056DF8: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    Matrix_Copy(rdram, ctx);
        goto after_40;
    // 0x80056DF8: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_40:
    // 0x80056DFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80056E00:
    // 0x80056E00: jal         0x80054280
    // 0x80056E04: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    Display_DrawPlayer(rdram, ctx);
        goto after_41;
    // 0x80056E04: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_41:
    // 0x80056E08: jal         0x80005740
    // 0x80056E0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_42;
    // 0x80056E0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_42:
    // 0x80056E10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80056E14:
    // 0x80056E14: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80056E18: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80056E1C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80056E20: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80056E24: jr          $ra
    // 0x80056E28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80056E28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void osReadHost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029EB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029EB4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80029EB8: lw          $t6, 0x7FC0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7FC0);
    // 0x80029EBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029EC0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029EC4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80029EC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029ECC: bne         $t6, $zero, L_80029F0C
    if (ctx->r14 != 0) {
        // 0x80029ED0: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_80029F0C;
    }
    // 0x80029ED0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80029ED4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80029ED8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80029EDC: addiu       $a1, $a1, -0x6828
    ctx->r5 = ADD32(ctx->r5, -0X6828);
    // 0x80029EE0: addiu       $a0, $a0, -0x6840
    ctx->r4 = ADD32(ctx->r4, -0X6840);
    // 0x80029EE4: jal         0x80021CF0
    // 0x80029EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80029EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80029EEC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80029EF0: addiu       $a1, $a1, -0x6840
    ctx->r5 = ADD32(ctx->r5, -0X6840);
    // 0x80029EF4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80029EF8: jal         0x80021D20
    // 0x80029EFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80029EFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80029F00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80029F04: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80029F08: sw          $t7, 0x7FC0($at)
    MEM_W(0X7FC0, ctx->r1) = ctx->r15;
L_80029F0C:
    // 0x80029F0C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80029F10: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80029F14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80029F18: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80029F1C: sw          $t8, -0x6824($at)
    MEM_W(-0X6824, ctx->r1) = ctx->r24;
    // 0x80029F20: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80029F24: bne         $t0, $zero, L_80029F58
    if (ctx->r8 != 0) {
        // 0x80029F28: sw          $t9, -0x6820($at)
        MEM_W(-0X6820, ctx->r1) = ctx->r25;
            goto L_80029F58;
    }
    // 0x80029F28: sw          $t9, -0x6820($at)
    MEM_W(-0X6820, ctx->r1) = ctx->r25;
L_80029F2C:
    // 0x80029F2C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80029F30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80029F34: jal         0x800288F0
    // 0x80029F38: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    __osRdbSend_recomp(rdram, ctx);
        goto after_2;
    // 0x80029F38: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x80029F3C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80029F40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80029F44: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80029F48: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80029F4C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80029F50: beq         $t3, $zero, L_80029F2C
    if (ctx->r11 == 0) {
        // 0x80029F54: nop
    
            goto L_80029F2C;
    }
    // 0x80029F54: nop

L_80029F58:
    // 0x80029F58: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80029F5C: addiu       $a0, $a0, -0x6840
    ctx->r4 = ADD32(ctx->r4, -0X6840);
    // 0x80029F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029F64: jal         0x800205E0
    // 0x80029F68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80029F68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80029F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029F70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029F74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029F78: jr          $ra
    // 0x80029F7C: nop

    return;
    // 0x80029F7C: nop

;}
RECOMP_FUNC void FoBase_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800907C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800907C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800907CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800907D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800907D4: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x800907D8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800907DC: beql        $v0, $zero, L_800907FC
    if (ctx->r2 == 0) {
        // 0x800907E0: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800907FC;
    }
    goto skip_0;
    // 0x800907E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x800907E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800907E8: beql        $v0, $at, L_80090888
    if (ctx->r2 == ctx->r1) {
        // 0x800907EC: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_80090888;
    }
    goto skip_1;
    // 0x800907EC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    skip_1:
    // 0x800907F0: b           L_80090908
    // 0x800907F4: nop

        goto L_80090908;
    // 0x800907F4: nop

    // 0x800907F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800907FC:
    // 0x800907FC: lwc1        $f4, 0xDC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80090800: lui         $at, 0x4354
    ctx->r1 = S32(0X4354 << 16);
    // 0x80090804: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    // 0x80090808: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x8009080C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80090810: bc1fl       L_80090840
    if (!c1cs) {
        // 0x80090814: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80090840;
    }
    goto skip_2;
    // 0x80090814: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    skip_2:
    // 0x80090818: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009081C: lwc1        $f8, 0xE0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80090820: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80090824: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80090828: nop

    // 0x8009082C: bc1fl       L_80090840
    if (!c1cs) {
        // 0x80090830: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80090840;
    }
    goto skip_3;
    // 0x80090830: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    skip_3:
    // 0x80090834: b           L_80090908
    // 0x80090838: sh          $t6, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r14;
        goto L_80090908;
    // 0x80090838: sh          $t6, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r14;
    // 0x8009083C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
L_80090840:
    // 0x80090840: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80090844: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80090848: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8009084C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80090850: jal         0x8009BC2C
    // 0x80090854: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80090854: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80090858: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8009085C: lwc1        $f0, 0x7EFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7EFC);
    // 0x80090860: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80090864: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80090868: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009086C: addiu       $a0, $s0, 0xE0
    ctx->r4 = ADD32(ctx->r16, 0XE0);
    // 0x80090870: lui         $a1, 0x4354
    ctx->r5 = S32(0X4354 << 16);
    // 0x80090874: jal         0x8009BC2C
    // 0x80090878: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80090878: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8009087C: b           L_80090908
    // 0x80090880: nop

        goto L_80090908;
    // 0x80090880: nop

    // 0x80090884: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
L_80090888:
    // 0x80090888: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009088C: lwc1        $f10, 0xDC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80090890: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80090894: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    // 0x80090898: c.eq.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl == ctx->f10.fl;
    // 0x8009089C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800908A0: bc1fl       L_800908CC
    if (!c1cs) {
        // 0x800908A4: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_800908CC;
    }
    goto skip_4;
    // 0x800908A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    skip_4:
    // 0x800908A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800908AC: lwc1        $f18, 0xE0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x800908B0: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800908B4: nop

    // 0x800908B8: bc1fl       L_800908CC
    if (!c1cs) {
        // 0x800908BC: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_800908CC;
    }
    goto skip_5;
    // 0x800908BC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    skip_5:
    // 0x800908C0: b           L_80090908
    // 0x800908C4: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
        goto L_80090908;
    // 0x800908C4: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
    // 0x800908C8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
L_800908CC:
    // 0x800908CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800908D0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800908D4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800908D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800908DC: jal         0x8009BC2C
    // 0x800908E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800908E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800908E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800908E8: lwc1        $f0, 0x7F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7F00);
    // 0x800908EC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800908F0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800908F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800908F8: addiu       $a0, $s0, 0xE0
    ctx->r4 = ADD32(ctx->r16, 0XE0);
    // 0x800908FC: lui         $a1, 0x41B8
    ctx->r5 = S32(0X41B8 << 16);
    // 0x80090900: jal         0x8009BC2C
    // 0x80090904: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80090904: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
L_80090908:
    // 0x80090908: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8009090C: lw          $a1, -0x6D8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6D8);
    // 0x80090910: jal         0x8008FFF0
    // 0x80090914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    FoBase_BurnEffects(rdram, ctx);
        goto after_4;
    // 0x80090914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80090918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009091C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80090920: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80090924: jr          $ra
    // 0x80090928: nop

    return;
    // 0x80090928: nop

;}
RECOMP_FUNC void Display_BarrelRollShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054914: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80054918: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005491C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80054920: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054924: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80054928: lw          $t6, 0x280($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X280);
    // 0x8005492C: beql        $t6, $zero, L_80054C94
    if (ctx->r14 == 0) {
        // 0x80054930: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80054C94;
    }
    goto skip_0;
    // 0x80054930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80054934: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80054938: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8005493C: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80054940: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80054944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80054948: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005494C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054950: lwc1        $f6, 0x5EA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EA0);
    // 0x80054954: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80054958: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005495C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80054960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80054964: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80054968: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005496C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80054970: jal         0x80005E90
    // 0x80054974: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80054974: nop

    after_0:
    // 0x80054978: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8005497C: lwc1        $f16, 0xE4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80054980: lwc1        $f4, 0x134($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80054984: lwc1        $f8, 0x4D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x80054988: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005498C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054990: lwc1        $f16, 0x5EA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5EA4);
    // 0x80054994: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80054998: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005499C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800549A0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800549A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800549A8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800549AC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800549B0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800549B4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800549B8: jal         0x80005D44
    // 0x800549BC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x800549BC: nop

    after_1:
    // 0x800549C0: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800549C4: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800549C8: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800549CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800549D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800549D4: lwc1        $f4, 0x5EA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EA8);
    // 0x800549D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800549DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800549E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800549E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800549E8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800549EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800549F0: jal         0x80005FE0
    // 0x800549F4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x800549F4: nop

    after_2:
    // 0x800549F8: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x800549FC: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    // 0x80054A00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80054A04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80054A08: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80054A0C: jal         0x80005B00
    // 0x80054A10: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80054A10: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x80054A14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80054A18: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80054A1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80054A20: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80054A24: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80054A28: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80054A2C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80054A30: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80054A34: jal         0x80006970
    // 0x80054A38: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x80054A38: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80054A3C: lw          $t8, 0x1F0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F0);
    // 0x80054A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80054A44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054A48: bgez        $t8, L_80054A5C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80054A4C: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_80054A5C;
    }
    // 0x80054A4C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80054A50: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80054A54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054A58: nop

L_80054A5C:
    // 0x80054A5C: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80054A60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054A64: jal         0x80005708
    // 0x80054A68: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x80054A68: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80054A6C: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80054A70: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80054A74: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80054A78: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80054A7C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80054A80: lwc1        $f18, 0x144($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80054A84: lwc1        $f16, 0x138($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80054A88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80054A8C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054A90: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80054A94: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80054A98: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80054A9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80054AA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80054AA4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80054AA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80054AAC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80054AB0: jal         0x80005B00
    // 0x80054AB4: nop

    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x80054AB4: nop

    after_6:
    // 0x80054AB8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80054ABC: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x80054AC0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80054AC4: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80054AC8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80054ACC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80054AD0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80054AD4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80054AD8: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80054ADC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80054AE0: lwc1        $f10, 0x58($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X58);
    // 0x80054AE4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80054AE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80054AEC: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80054AF0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80054AF4: jal         0x80005E90
    // 0x80054AF8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80054AF8: nop

    after_7:
    // 0x80054AFC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80054B00: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x80054B04: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054B08: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80054B0C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80054B10: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80054B14: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80054B18: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80054B1C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80054B20: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80054B24: lw          $a1, 0x5C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X5C);
    // 0x80054B28: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80054B2C: jal         0x80005D44
    // 0x80054B30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80054B30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80054B34: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80054B38: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80054B3C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80054B40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80054B44: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80054B48: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80054B4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054B50: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80054B54: lwc1        $f18, 0x5EAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5EAC);
    // 0x80054B58: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80054B5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80054B60: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80054B64: nop

    // 0x80054B68: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80054B6C: nop

    // 0x80054B70: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80054B74: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054B78: jal         0x80005FE0
    // 0x80054B7C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x80054B7C: nop

    after_9:
    // 0x80054B80: lw          $t9, 0x1CC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1CC);
    // 0x80054B84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054B88: bne         $t9, $zero, L_80054BBC
    if (ctx->r25 != 0) {
        // 0x80054B8C: nop
    
            goto L_80054BBC;
    }
    // 0x80054B8C: nop

    // 0x80054B90: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054B94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054B98: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80054B9C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80054BA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80054BA4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054BA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80054BAC: jal         0x80005C34
    // 0x80054BB0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_10;
    // 0x80054BB0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x80054BB4: b           L_80054BE0
    // 0x80054BB8: lw          $t2, 0x1F0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F0);
        goto L_80054BE0;
    // 0x80054BB8: lw          $t2, 0x1F0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F0);
L_80054BBC:
    // 0x80054BBC: lwc1        $f0, 0x5EB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5EB0);
    // 0x80054BC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80054BC4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80054BC8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80054BCC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054BD0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80054BD4: jal         0x80005C34
    // 0x80054BD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x80054BD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_11:
    // 0x80054BDC: lw          $t2, 0x1F0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F0);
L_80054BE0:
    // 0x80054BE0: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80054BE4: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80054BE8: bgez        $t2, L_80054BF8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80054BEC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80054BF8;
    }
    // 0x80054BEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80054BF0: jal         0x80005D44
    // 0x80054BF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_RotateX(rdram, ctx);
        goto after_12;
    // 0x80054BF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_12:
L_80054BF8:
    // 0x80054BF8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80054BFC: jal         0x80006EB8
    // 0x80054C00: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_13;
    // 0x80054C00: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    after_13:
    // 0x80054C04: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80054C08: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    // 0x80054C0C: jal         0x800B8DD0
    // 0x80054C10: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x80054C10: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_14:
    // 0x80054C14: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80054C18: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80054C1C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80054C20: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80054C24: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80054C28: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80054C2C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80054C30: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80054C34: lw          $t4, 0x280($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X280);
    // 0x80054C38: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80054C3C: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80054C40: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80054C44: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80054C48: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80054C4C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80054C50: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054C54: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80054C58: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054C5C: lw          $t1, 0x280($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X280);
    // 0x80054C60: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x80054C64: ori         $t2, $t0, 0xA000
    ctx->r10 = ctx->r8 | 0XA000;
    // 0x80054C68: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80054C6C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80054C70: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x80054C74: addiu       $t4, $t4, -0x23F0
    ctx->r12 = ADD32(ctx->r12, -0X23F0);
    // 0x80054C78: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80054C7C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80054C80: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80054C84: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80054C88: jal         0x80005740
    // 0x80054C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x80054C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80054C90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80054C94:
    // 0x80054C94: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80054C98: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80054C9C: jr          $ra
    // 0x80054CA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80054CA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Lib_TextureRect_IA16_MirY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ED04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009ED08: lui         $t1, 0xF570
    ctx->r9 = S32(0XF570 << 16);
    // 0x8009ED0C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009ED10: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009ED14: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x8009ED18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8009ED1C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009ED20: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8009ED24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009ED28: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009ED2C: lui         $t9, 0x704
    ctx->r25 = S32(0X704 << 16);
    // 0x8009ED30: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8009ED34: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009ED38: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009ED3C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009ED40: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009ED44: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009ED48: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009ED4C: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x8009ED50: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009ED54: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009ED58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009ED5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009ED60: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009ED64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009ED68: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009ED6C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009ED70: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009ED74: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009ED78: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009ED7C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8009ED80: mflo        $v0
    ctx->r2 = lo;
    // 0x8009ED84: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009ED88: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009ED8C: beql        $at, $zero, L_8009EDA0
    if (ctx->r1 == 0) {
        // 0x8009ED90: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009EDA0;
    }
    goto skip_0;
    // 0x8009ED90: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009ED94: b           L_8009EDA0
    // 0x8009ED98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009EDA0;
    // 0x8009ED98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009ED9C: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009EDA0:
    // 0x8009EDA0: srl         $v0, $t2, 3
    ctx->r2 = S32(U32(ctx->r10) >> 3);
    // 0x8009EDA4: bne         $v0, $zero, L_8009EDB4
    if (ctx->r2 != 0) {
        // 0x8009EDA8: lui         $at, 0x700
        ctx->r1 = S32(0X700 << 16);
            goto L_8009EDB4;
    }
    // 0x8009EDA8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009EDAC: b           L_8009EDB8
    // 0x8009EDB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009EDB8;
    // 0x8009EDB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009EDB4:
    // 0x8009EDB4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009EDB8:
    // 0x8009EDB8: bne         $v0, $zero, L_8009EDC8
    if (ctx->r2 != 0) {
        // 0x8009EDBC: addiu       $t6, $t3, 0x7FF
        ctx->r14 = ADD32(ctx->r11, 0X7FF);
            goto L_8009EDC8;
    }
    // 0x8009EDBC: addiu       $t6, $t3, 0x7FF
    ctx->r14 = ADD32(ctx->r11, 0X7FF);
    // 0x8009EDC0: b           L_8009EDCC
    // 0x8009EDC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8009EDCC;
    // 0x8009EDC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8009EDC8:
    // 0x8009EDC8: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8009EDCC:
    // 0x8009EDCC: divu        $zero, $t6, $t4
    lo = S32(U32(ctx->r14) / U32(ctx->r12)); hi = S32(U32(ctx->r14) % U32(ctx->r12));
    // 0x8009EDD0: mflo        $t7
    ctx->r15 = lo;
    // 0x8009EDD4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009EDD8: andi        $t6, $a1, 0xFFF
    ctx->r14 = ctx->r5 & 0XFFF;
    // 0x8009EDDC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009EDE0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009EDE4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009EDE8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8009EDEC: bne         $t4, $zero, L_8009EDF8
    if (ctx->r12 != 0) {
        // 0x8009EDF0: nop
    
            goto L_8009EDF8;
    }
    // 0x8009EDF0: nop

    // 0x8009EDF4: break       7
    do_break(2148134388);
L_8009EDF8:
    // 0x8009EDF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EDFC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009EE00: addiu       $t8, $t2, 0x7
    ctx->r24 = ADD32(ctx->r10, 0X7);
    // 0x8009EE04: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009EE08: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009EE0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009EE10: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009EE14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EE18: srl         $t6, $t8, 3
    ctx->r14 = S32(U32(ctx->r24) >> 3);
    // 0x8009EE1C: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8009EE20: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8009EE24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009EE28: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009EE2C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8009EE30: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8009EE34: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x8009EE38: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8009EE3C: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x8009EE40: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8009EE44: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8009EE48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EE4C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8009EE50: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x8009EE54: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009EE58: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009EE5C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009EE60: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8009EE64: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8009EE68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009EE6C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009EE70: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009EE74: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8009EE78: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8009EE7C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009EE80: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8009EE84: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8009EE88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009EE8C: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009EE90: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009EE94: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009EE98: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009EE9C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8009EEA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009EEA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009EEA8: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8009EEAC: bgez        $a2, L_8009EEC0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009EEB0: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8009EEC0;
    }
    // 0x8009EEB0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009EEB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009EEB8: nop

    // 0x8009EEBC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009EEC0:
    // 0x8009EEC0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009EEC4: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009EEC8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009EECC: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009EED0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009EED4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009EED8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009EEDC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009EEE0: nop

    // 0x8009EEE4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009EEE8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009EEEC: bgez        $a3, L_8009EF04
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009EEF0: or          $t8, $t6, $at
        ctx->r24 = ctx->r14 | ctx->r1;
            goto L_8009EF04;
    }
    // 0x8009EEF0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8009EEF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009EEF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EEFC: nop

    // 0x8009EF00: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009EF04:
    // 0x8009EF04: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009EF08: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009EF0C: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009EF10: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009EF14: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009EF18: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009EF1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009EF20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009EF24: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009EF28: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009EF2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EF30: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009EF34: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009EF38: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8009EF3C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009EF40: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8009EF44: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009EF48: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009EF4C: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8009EF50: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009EF54: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009EF58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009EF5C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009EF60: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009EF64: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009EF68: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8009EF6C: div.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8009EF70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EF74: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x8009EF78: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8009EF7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009EF80: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009EF84: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8009EF88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009EF8C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009EF90: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009EF94: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EF98: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009EF9C: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009EFA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009EFA4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009EFA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009EFAC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009EFB0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009EFB4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8009EFB8: nop

    // 0x8009EFBC: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8009EFC0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009EFC4: nop

    // 0x8009EFC8: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8009EFCC: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009EFD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009EFD4: jr          $ra
    // 0x8009EFD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009EFD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Mio0_Decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE70: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x8001EE74: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8001EE78: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8001EE7C: add         $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8001EE80: add         $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8001EE84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EE88: addi        $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8001EE8C: add         $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
L_8001EE90:
    // 0x8001EE90: bne         $a2, $zero, L_8001EEA4
    if (ctx->r6 != 0) {
        // 0x8001EE94: nop
    
            goto L_8001EEA4;
    }
    // 0x8001EE94: nop

    // 0x8001EE98: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8001EE9C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8001EEA0: addi        $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8001EEA4:
    // 0x8001EEA4: slt         $t1, $t0, $zero
    ctx->r9 = SIGNED(ctx->r8) < SIGNED(0) ? 1 : 0;
    // 0x8001EEA8: beq         $t1, $zero, L_8001EEC4
    if (ctx->r9 == 0) {
        // 0x8001EEAC: nop
    
            goto L_8001EEC4;
    }
    // 0x8001EEAC: nop

    // 0x8001EEB0: lb          $t2, 0x0($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X0);
    // 0x8001EEB4: addi        $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8001EEB8: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001EEBC: b           L_8001EEF4
    // 0x8001EEC0: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
        goto L_8001EEF4;
    // 0x8001EEC0: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
L_8001EEC4:
    // 0x8001EEC4: lhu         $t2, 0x0($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X0);
    // 0x8001EEC8: addi        $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8001EECC: srl         $t3, $t2, 12
    ctx->r11 = S32(U32(ctx->r10) >> 12);
    // 0x8001EED0: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
    // 0x8001EED4: sub         $t1, $a1, $t2
    ctx->r9 = SUB32(ctx->r5, ctx->r10);
    // 0x8001EED8: addi        $t3, $t3, 0x3
    ctx->r11 = ADD32(ctx->r11, 0X3);
L_8001EEDC:
    // 0x8001EEDC: lb          $t2, -0x1($t1)
    ctx->r10 = MEM_B(ctx->r9, -0X1);
    // 0x8001EEE0: addi        $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8001EEE4: addi        $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001EEE8: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001EEEC: bne         $t3, $zero, L_8001EEDC
    if (ctx->r11 != 0) {
        // 0x8001EEF0: sb          $t2, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r10;
            goto L_8001EEDC;
    }
    // 0x8001EEF0: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
L_8001EEF4:
    // 0x8001EEF4: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8001EEF8: bne         $a1, $t8, L_8001EE90
    if (ctx->r5 != ctx->r24) {
        // 0x8001EEFC: addi        $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001EE90;
    }
    // 0x8001EEFC: addi        $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001EF00: jr          $ra
    // 0x8001EF04: nop

    return;
    // 0x8001EF04: nop

    // 0x8001EF08: nop

    // 0x8001EF0C: nop

;}
RECOMP_FUNC void AudioThread_QueueCmdS8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E8F4: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8001E8F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E8FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001E900: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8001E904: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001E908: jal         0x8001E850
    // 0x8001E90C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    AudioThread_QueueCmd(rdram, ctx);
        goto after_0;
    // 0x8001E90C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8001E910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E914: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001E918: jr          $ra
    // 0x8001E91C: nop

    return;
    // 0x8001E91C: nop

;}
RECOMP_FUNC void Audio_NoteInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011EC0: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x80011EC4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80011EC8: addiu       $a2, $a3, 0x36
    ctx->r6 = ADD32(ctx->r7, 0X36);
    // 0x80011ECC: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x80011ED0: bnel        $t6, $zero, L_80011EFC
    if (ctx->r14 != 0) {
        // 0x80011ED4: lw          $a1, 0x1C($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X1C);
            goto L_80011EFC;
    }
    goto skip_0;
    // 0x80011ED4: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x80011ED8: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x80011EDC: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80011EE0: addiu       $a2, $a3, 0x36
    ctx->r6 = ADD32(ctx->r7, 0X36);
    // 0x80011EE4: lw          $a1, 0x78($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X78);
    // 0x80011EE8: jal         0x80013B6C
    // 0x80011EEC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Audio_AdsrInit(rdram, ctx);
        goto after_0;
    // 0x80011EEC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80011EF0: b           L_80011F0C
    // 0x80011EF4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_80011F0C;
    // 0x80011EF4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80011EF8: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
L_80011EFC:
    // 0x80011EFC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80011F00: jal         0x80013B6C
    // 0x80011F04: addiu       $a0, $a3, 0x58
    ctx->r4 = ADD32(ctx->r7, 0X58);
    Audio_AdsrInit(rdram, ctx);
        goto after_1;
    // 0x80011F04: addiu       $a0, $a3, 0x58
    ctx->r4 = ADD32(ctx->r7, 0X58);
    after_1:
    // 0x80011F08: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80011F0C:
    // 0x80011F0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80011F10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80011F14: sb          $t8, 0x59($a3)
    MEM_B(0X59, ctx->r7) = ctx->r24;
    // 0x80011F18: addiu       $t9, $t9, -0x2E90
    ctx->r25 = ADD32(ctx->r25, -0X2E90);
    // 0x80011F1C: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80011F20: sw          $at, 0xB0($a3)
    MEM_W(0XB0, ctx->r7) = ctx->r1;
    // 0x80011F24: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80011F28: sw          $t1, 0xB4($a3)
    MEM_W(0XB4, ctx->r7) = ctx->r9;
    // 0x80011F2C: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80011F30: sw          $at, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r1;
    // 0x80011F34: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x80011F38: sw          $t1, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r9;
    // 0x80011F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011F44: jr          $ra
    // 0x80011F48: nop

    return;
    // 0x80011F48: nop

;}
RECOMP_FUNC void __lnearbyint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF9C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001FFA0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001FFA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001FFA8: nop

    // 0x8001FFAC: add.d       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f12.d + ctx->f4.d;
    // 0x8001FFB0: floor.w.d   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floor(ctx->f0.d));
    // 0x8001FFB4: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001FFB8: jr          $ra
    // 0x8001FFBC: nop

    return;
    // 0x8001FFBC: nop

;}
RECOMP_FUNC void Corneria_CoGranga_1UpCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188D50: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80188D54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80188D58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188D5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188D60: lh          $v1, 0xD0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XD0);
    // 0x80188D64: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80188D68: bnel        $v1, $zero, L_80189048
    if (ctx->r3 != 0) {
        // 0x80188D6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80189048;
    }
    goto skip_0;
    // 0x80188D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80188D70: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80188D74: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x80188D78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188D7C: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x80188D80: beq         $t6, $zero, L_80188D8C
    if (ctx->r14 == 0) {
        // 0x80188D84: nop
    
            goto L_80188D8C;
    }
    // 0x80188D84: nop

    // 0x80188D88: sw          $t0, -0x6820($at)
    MEM_W(-0X6820, ctx->r1) = ctx->r8;
L_80188D8C:
    // 0x80188D8C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80188D90: lw          $t0, -0x6820($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6820);
    // 0x80188D94: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80188D98: beq         $t0, $zero, L_80188DAC
    if (ctx->r8 == 0) {
        // 0x80188D9C: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80188DAC;
    }
    // 0x80188D9C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80188DA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188DA4: b           L_80189044
    // 0x80188DA8: sw          $t0, -0x6820($at)
    MEM_W(-0X6820, ctx->r1) = ctx->r8;
        goto L_80189044;
    // 0x80188DA8: sw          $t0, -0x6820($at)
    MEM_W(-0X6820, ctx->r1) = ctx->r8;
L_80188DAC:
    // 0x80188DAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80188DB0: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80188DB4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80188DB8: nop

    // 0x80188DBC: bc1fl       L_80189048
    if (!c1cs) {
        // 0x80188DC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80189048;
    }
    goto skip_1;
    // 0x80188DC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80188DC4: lh          $t7, 0x4E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4E);
    // 0x80188DC8: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80188DCC: beql        $at, $zero, L_80189048
    if (ctx->r1 == 0) {
        // 0x80188DD0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80189048;
    }
    goto skip_2;
    // 0x80188DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80188DD4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188DD8: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80188DDC: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80188DE0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80188DE4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80188DE8: nop

    // 0x80188DEC: bc1fl       L_80189048
    if (!c1cs) {
        // 0x80188DF0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80189048;
    }
    goto skip_3;
    // 0x80188DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80188DF4: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80188DF8: lwc1        $f16, 0x138($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80188DFC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80188E00: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80188E04: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80188E08: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80188E0C: nop

    // 0x80188E10: bc1fl       L_80189048
    if (!c1cs) {
        // 0x80188E14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80189048;
    }
    goto skip_4;
    // 0x80188E14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80188E18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188E1C: lwc1        $f4, 0x4D8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4D8);
    // 0x80188E20: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188E24: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80188E28: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80188E2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188E30: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80188E34: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80188E38: bc1f        L_80189044
    if (!c1cs) {
        // 0x80188E3C: ori         $a0, $a0, 0x8025
        ctx->r4 = ctx->r4 | 0X8025;
            goto L_80189044;
    }
    // 0x80188E3C: ori         $a0, $a0, 0x8025
    ctx->r4 = ctx->r4 | 0X8025;
    // 0x80188E40: sh          $t8, 0xD0($s0)
    MEM_H(0XD0, ctx->r16) = ctx->r24;
    // 0x80188E44: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80188E48: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80188E4C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80188E50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188E54: sw          $t0, -0x6820($at)
    MEM_W(-0X6820, ctx->r1) = ctx->r8;
    // 0x80188E58: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80188E5C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80188E60: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188E64: jal         0x80019218
    // 0x80188E68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80188E68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80188E6C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80188E70: addiu       $s0, $s0, 0x78B0
    ctx->r16 = ADD32(ctx->r16, 0X78B0);
    // 0x80188E74: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80188E78: bgtz        $t1, L_80188E98
    if (SIGNED(ctx->r9) > 0) {
        // 0x80188E7C: nop
    
            goto L_80188E98;
    }
    // 0x80188E7C: nop

    // 0x80188E80: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80188E84: bgtz        $t2, L_80188E98
    if (SIGNED(ctx->r10) > 0) {
        // 0x80188E88: nop
    
            goto L_80188E98;
    }
    // 0x80188E88: nop

    // 0x80188E8C: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x80188E90: blez        $t3, L_80188F30
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80188E94: nop
    
            goto L_80188F30;
    }
    // 0x80188E94: nop

L_80188E98:
    // 0x80188E98: jal         0x80004EB0
    // 0x80188E9C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80188E9C: nop

    after_1:
    // 0x80188EA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188EA4: lwc1        $f6, -0x5094($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5094);
    // 0x80188EA8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80188EAC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80188EB0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80188EB4: nop

    // 0x80188EB8: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80188EBC: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80188EC0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80188EC4: blez        $t7, L_80188E98
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80188EC8: nop
    
            goto L_80188E98;
    }
    // 0x80188EC8: nop

    // 0x80188ECC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80188ED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188ED4: beq         $v1, $at, L_80188EFC
    if (ctx->r3 == ctx->r1) {
        // 0x80188ED8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80188EFC;
    }
    // 0x80188ED8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188EDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80188EE0: beq         $v1, $at, L_80188F10
    if (ctx->r3 == ctx->r1) {
        // 0x80188EE4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80188F10;
    }
    // 0x80188EE4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188EE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80188EEC: beq         $v1, $at, L_80188F24
    if (ctx->r3 == ctx->r1) {
        // 0x80188EF0: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80188F24;
    }
    // 0x80188EF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188EF4: b           L_80188F30
    // 0x80188EF8: nop

        goto L_80188F30;
    // 0x80188EF8: nop

L_80188EFC:
    // 0x80188EFC: addiu       $a0, $a0, -0x1D9C
    ctx->r4 = ADD32(ctx->r4, -0X1D9C);
    // 0x80188F00: jal         0x800BA808
    // 0x80188F04: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x80188F04: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x80188F08: b           L_80188F30
    // 0x80188F0C: nop

        goto L_80188F30;
    // 0x80188F0C: nop

L_80188F10:
    // 0x80188F10: addiu       $a0, $a0, 0xFFC
    ctx->r4 = ADD32(ctx->r4, 0XFFC);
    // 0x80188F14: jal         0x800BA808
    // 0x80188F18: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x80188F18: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80188F1C: b           L_80188F30
    // 0x80188F20: nop

        goto L_80188F30;
    // 0x80188F20: nop

L_80188F24:
    // 0x80188F24: addiu       $a0, $a0, 0x1C30
    ctx->r4 = ADD32(ctx->r4, 0X1C30);
    // 0x80188F28: jal         0x800BA808
    // 0x80188F2C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x80188F2C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_4:
L_80188F30:
    // 0x80188F30: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80188F34: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80188F38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188F3C: lwc1        $f6, -0x5090($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5090);
    // 0x80188F40: lwc1        $f16, 0xE8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x80188F44: lwc1        $f18, 0x114($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X114);
    // 0x80188F48: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80188F4C: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80188F50: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80188F54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80188F58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80188F5C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80188F60: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80188F64: jal         0x80005E90
    // 0x80188F68: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80188F68: nop

    after_5:
    // 0x80188F6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80188F70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188F74: lwc1        $f10, -0x508C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X508C);
    // 0x80188F78: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80188F7C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80188F80: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80188F84: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80188F88: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80188F8C: jal         0x80006A20
    // 0x80188F90: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x80188F90: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80188F94: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80188F98: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80188F9C: addiu       $v0, $v0, 0x4050
    ctx->r2 = ADD32(ctx->r2, 0X4050);
    // 0x80188FA0: addiu       $s0, $s0, 0x37E0
    ctx->r16 = ADD32(ctx->r16, 0X37E0);
    // 0x80188FA4: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
L_80188FA8:
    // 0x80188FA8: bnel        $t8, $zero, L_8018903C
    if (ctx->r24 != 0) {
        // 0x80188FAC: addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
            goto L_8018903C;
    }
    goto skip_5;
    // 0x80188FAC: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
    skip_5:
    // 0x80188FB0: jal         0x80061444
    // 0x80188FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_Initialize(rdram, ctx);
        goto after_7;
    // 0x80188FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80188FB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80188FBC: addiu       $t1, $zero, 0x14F
    ctx->r9 = ADD32(0, 0X14F);
    // 0x80188FC0: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x80188FC4: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80188FC8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80188FCC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80188FD0: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80188FD4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80188FD8: lwc1        $f16, 0x74($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80188FDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188FE0: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80188FE4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80188FE8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80188FEC: andi        $a1, $t1, 0xFFFF
    ctx->r5 = ctx->r9 & 0XFFFF;
    // 0x80188FF0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80188FF4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80188FF8: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80188FFC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80189000: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80189004: lwc1        $f16, 0x138($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80189008: sh          $t2, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r10;
    // 0x8018900C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80189010: jal         0x800612B8
    // 0x80189014: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_8;
    // 0x80189014: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x80189018: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018901C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80189020: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80189024: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189028: jal         0x8007B344
    // 0x8018902C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_9;
    // 0x8018902C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x80189030: b           L_80189048
    // 0x80189034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80189048;
    // 0x80189034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80189038: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
L_8018903C:
    // 0x8018903C: bnel        $s0, $v0, L_80188FA8
    if (ctx->r16 != ctx->r2) {
        // 0x80189040: lbu         $t8, 0x0($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X0);
            goto L_80188FA8;
    }
    goto skip_6;
    // 0x80189040: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    skip_6:
L_80189044:
    // 0x80189044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80189048:
    // 0x80189048: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018904C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80189050: jr          $ra
    // 0x80189054: nop

    return;
    // 0x80189054: nop

;}
RECOMP_FUNC void Corneria_CarrierBottom_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E76C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018E770: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018E774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018E778: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018E77C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018E780: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x8018E784: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E788: beql        $v0, $zero, L_8018E7A4
    if (ctx->r2 == 0) {
        // 0x8018E78C: lb          $t6, 0x62($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X62);
            goto L_8018E7A4;
    }
    goto skip_0;
    // 0x8018E78C: lb          $t6, 0x62($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X62);
    skip_0:
    // 0x8018E790: beq         $v0, $at, L_8018EA9C
    if (ctx->r2 == ctx->r1) {
        // 0x8018E794: nop
    
            goto L_8018EA9C;
    }
    // 0x8018E794: nop

    // 0x8018E798: b           L_8018EC44
    // 0x8018E79C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8018EC44;
    // 0x8018E79C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E7A0: lb          $t6, 0x62($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X62);
L_8018E7A4:
    // 0x8018E7A4: beq         $t6, $zero, L_8018E9B0
    if (ctx->r14 == 0) {
        // 0x8018E7A8: nop
    
            goto L_8018E9B0;
    }
    // 0x8018E7A8: nop

    // 0x8018E7AC: lh          $t7, 0x66($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X66);
    // 0x8018E7B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018E7B4: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
    // 0x8018E7B8: bne         $t7, $at, L_8018E984
    if (ctx->r15 != ctx->r1) {
        // 0x8018E7BC: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8018E984;
    }
    // 0x8018E7BC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018E7C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E7C4: lwc1        $f6, 0xDC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x8018E7C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018E7CC: nop

    // 0x8018E7D0: bc1f        L_8018E97C
    if (!c1cs) {
        // 0x8018E7D4: nop
    
            goto L_8018E97C;
    }
    // 0x8018E7D4: nop

    // 0x8018E7D8: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x8018E7DC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018E7E0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018E7E4: beq         $v0, $zero, L_8018E97C
    if (ctx->r2 == 0) {
        // 0x8018E7E8: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_8018E97C;
    }
    // 0x8018E7E8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8018E7EC: lh          $t9, 0x64($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X64);
    // 0x8018E7F0: sh          $t8, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r24;
    // 0x8018E7F4: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018E7F8: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8018E7FC: sh          $t0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r8;
    // 0x8018E800: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018E804: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018E808: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8018E80C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8018E810: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8018E814: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018E818: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018E81C: jal         0x80019218
    // 0x8018E820: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8018E820: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8018E824: lh          $t2, 0x60($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X60);
    // 0x8018E828: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8018E82C: addiu       $s1, $s1, -0xEF0
    ctx->r17 = ADD32(ctx->r17, -0XEF0);
    // 0x8018E830: bgtz        $t2, L_8018E97C
    if (SIGNED(ctx->r10) > 0) {
        // 0x8018E834: nop
    
            goto L_8018E97C;
    }
    // 0x8018E834: nop

    // 0x8018E838: lh          $t3, 0x98($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X98);
    // 0x8018E83C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018E840: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018E844: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8018E848: sh          $t4, 0x98($s1)
    MEM_H(0X98, ctx->r17) = ctx->r12;
    // 0x8018E84C: lh          $t5, 0x98($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X98);
    // 0x8018E850: addiu       $a0, $a0, -0x201C
    ctx->r4 = ADD32(ctx->r4, -0X201C);
    // 0x8018E854: beq         $t5, $zero, L_8018E874
    if (ctx->r13 == 0) {
        // 0x8018E858: nop
    
            goto L_8018E874;
    }
    // 0x8018E858: nop

    // 0x8018E85C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018E860: jal         0x800BA808
    // 0x8018E864: addiu       $a0, $a0, 0xDEC
    ctx->r4 = ADD32(ctx->r4, 0XDEC);
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8018E864: addiu       $a0, $a0, 0xDEC
    ctx->r4 = ADD32(ctx->r4, 0XDEC);
    after_1:
    // 0x8018E868: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018E86C: b           L_8018E884
    // 0x8018E870: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
        goto L_8018E884;
    // 0x8018E870: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
L_8018E874:
    // 0x8018E874: jal         0x800BA808
    // 0x8018E878: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x8018E878: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x8018E87C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018E880: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
L_8018E884:
    // 0x8018E884: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018E888: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E88C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018E890: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E894: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8018E898: swc1        $f10, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f10.u32l;
    // 0x8018E89C: lwc1        $f16, -0x4E4C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4E4C);
    // 0x8018E8A0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018E8A4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018E8A8: swc1        $f16, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f16.u32l;
    // 0x8018E8AC: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x8018E8B0: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x8018E8B4: ori         $a0, $a0, 0xC027
    ctx->r4 = ctx->r4 | 0XC027;
    // 0x8018E8B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018E8BC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018E8C0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8018E8C4: jal         0x80019218
    // 0x8018E8C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8018E8C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8018E8CC: lh          $v0, 0x9C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X9C);
    // 0x8018E8D0: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8018E8D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018E8D8: beq         $v0, $zero, L_8018E8E8
    if (ctx->r2 == 0) {
        // 0x8018E8DC: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_8018E8E8;
    }
    // 0x8018E8DC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018E8E0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8018E8E4: sh          $t7, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r15;
L_8018E8E8:
    // 0x8018E8E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018E8EC: sh          $t8, 0x56($s1)
    MEM_H(0X56, ctx->r17) = ctx->r24;
    // 0x8018E8F0: sh          $t9, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r25;
    // 0x8018E8F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E8F8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018E8FC: swc1        $f18, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f18.u32l;
    // 0x8018E900: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E904: addiu       $a1, $a1, -0x6564
    ctx->r5 = ADD32(ctx->r5, -0X6564);
    // 0x8018E908: jal         0x80006970
    // 0x8018E90C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8018E90C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x8018E910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018E914: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
L_8018E918:
    // 0x8018E918: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018E91C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018E920: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8018E924: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E928: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018E92C: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018E930: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018E934: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8018E938: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018E93C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018E940: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018E944: jal         0x80079618
    // 0x8018E948: nop

    func_effect_80079618(rdram, ctx);
        goto after_5;
    // 0x8018E948: nop

    after_5:
    // 0x8018E94C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E950: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018E954: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018E958: bnel        $v0, $at, L_8018E918
    if (ctx->r2 != ctx->r1) {
        // 0x8018E95C: lwc1        $f4, 0x4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8018E918;
    }
    goto skip_1;
    // 0x8018E95C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x8018E960: lh          $t0, 0x456($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X456);
    // 0x8018E964: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E968: bne         $t0, $at, L_8018E97C
    if (ctx->r8 != ctx->r1) {
        // 0x8018E96C: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_8018E97C;
    }
    // 0x8018E96C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8018E970: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E974: nop

    // 0x8018E978: swc1        $f6, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f6.u32l;
L_8018E97C:
    // 0x8018E97C: b           L_8018E9B0
    // 0x8018E980: nop

        goto L_8018E9B0;
    // 0x8018E980: nop

L_8018E984:
    // 0x8018E984: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018E988: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018E98C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018E990: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018E994: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8018E998: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8018E99C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018E9A0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018E9A4: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8018E9A8: jal         0x80019218
    // 0x8018E9AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x8018E9AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
L_8018E9B0:
    // 0x8018E9B0: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8018E9B4: addiu       $s1, $s1, -0xEF0
    ctx->r17 = ADD32(ctx->r17, -0XEF0);
    // 0x8018E9B8: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018E9BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E9C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E9C4: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8018E9C8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018E9CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018E9D0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8018E9D4: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8018E9D8: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018E9DC: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x8018E9E0: lwc1        $f4, -0x4E48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4E48);
    // 0x8018E9E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E9E8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018E9EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018E9F0: jal         0x80005E90
    // 0x8018E9F4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8018E9F4: nop

    after_7:
    // 0x8018E9F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E9FC: lwc1        $f10, -0x4E44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4E44);
    // 0x8018EA00: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018EA04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EA08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018EA0C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018EA10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EA14: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018EA18: jal         0x80005D44
    // 0x8018EA1C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8018EA1C: nop

    after_8:
    // 0x8018EA20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EA24: lwc1        $f4, -0x4E40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4E40);
    // 0x8018EA28: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018EA2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EA30: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018EA34: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018EA38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EA3C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018EA40: jal         0x80005FE0
    // 0x8018EA44: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x8018EA44: nop

    after_9:
    // 0x8018EA48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EA4C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018EA50: addiu       $a1, $a1, -0x6558
    ctx->r5 = ADD32(ctx->r5, -0X6558);
    // 0x8018EA54: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018EA58: jal         0x80006970
    // 0x8018EA5C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x8018EA5C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_10:
    // 0x8018EA60: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018EA64: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018EA68: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018EA6C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018EA70: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018EA74: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018EA78: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018EA7C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018EA80: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018EA84: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018EA88: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018EA8C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8018EA90: lwc1        $f18, 0xDC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018EA94: b           L_8018EC40
    // 0x8018EA98: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
        goto L_8018EC40;
    // 0x8018EA98: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
L_8018EA9C:
    // 0x8018EA9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EAA0: lwc1        $f6, -0x4E3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4E3C);
    // 0x8018EAA4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018EAA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EAAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018EAB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018EAB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018EAB8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018EABC: jal         0x80005FE0
    // 0x8018EAC0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x8018EAC0: nop

    after_11:
    // 0x8018EAC4: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8018EAC8: addiu       $s1, $s1, -0xEF0
    ctx->r17 = ADD32(ctx->r17, -0XEF0);
    // 0x8018EACC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018EAD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018EAD4: lwc1        $f10, 0x114($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X114);
    // 0x8018EAD8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018EADC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018EAE0: swc1        $f18, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f18.u32l;
    // 0x8018EAE4: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8018EAE8: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8018EAEC: bne         $t3, $zero, L_8018EB1C
    if (ctx->r11 != 0) {
        // 0x8018EAF0: nop
    
            goto L_8018EB1C;
    }
    // 0x8018EAF0: nop

    // 0x8018EAF4: jal         0x80004EB0
    // 0x8018EAF8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x8018EAF8: nop

    after_12:
    // 0x8018EAFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018EB00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018EB04: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8018EB08: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8018EB0C: nop

    // 0x8018EB10: bc1f        L_8018EB1C
    if (!c1cs) {
        // 0x8018EB14: nop
    
            goto L_8018EB1C;
    }
    // 0x8018EB14: nop

    // 0x8018EB18: sh          $t4, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r12;
L_8018EB1C:
    // 0x8018EB1C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018EB20: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x8018EB24: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8018EB28: bne         $t6, $zero, L_8018EB98
    if (ctx->r14 != 0) {
        // 0x8018EB2C: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018EB98;
    }
    // 0x8018EB2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EB30: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018EB34: addiu       $a1, $a1, -0x6564
    ctx->r5 = ADD32(ctx->r5, -0X6564);
    // 0x8018EB38: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018EB3C: jal         0x80006970
    // 0x8018EB40: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x8018EB40: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_13:
    // 0x8018EB44: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018EB48: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018EB4C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018EB50: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8018EB54: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018EB58: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018EB5C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018EB60: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8018EB64: lw          $a3, 0x6C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X6C);
    // 0x8018EB68: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018EB6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018EB74: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018EB78: lwc1        $f16, -0x4E38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4E38);
    // 0x8018EB7C: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018EB80: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018EB84: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018EB88: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8018EB8C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018EB90: jal         0x8007C120
    // 0x8018EB94: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_14;
    // 0x8018EB94: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_14:
L_8018EB98:
    // 0x8018EB98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EB9C: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8018EBA0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018EBA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018EBA8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018EBAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018EBB0: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8018EBB4: nop

    // 0x8018EBB8: bc1fl       L_8018EC24
    if (!c1cs) {
        // 0x8018EBBC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8018EC24;
    }
    goto skip_2;
    // 0x8018EBBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_2:
    // 0x8018EBC0: lh          $t8, 0x88($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X88);
    // 0x8018EBC4: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8018EBC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018EBCC: bne         $t8, $zero, L_8018EC40
    if (ctx->r24 != 0) {
        // 0x8018EBD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018EC40;
    }
    // 0x8018EBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018EBD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018EBD8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018EBDC: sh          $t9, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r25;
    // 0x8018EBE0: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x8018EBE4: jal         0x8018C0B0
    // 0x8018EBE8: swc1        $f16, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f16.u32l;
    Corneria_CoCarrier_WaterSplash(rdram, ctx);
        goto after_15;
    // 0x8018EBE8: swc1        $f16, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f16.u32l;
    after_15:
    // 0x8018EBEC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018EBF0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8018EBF4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018EBF8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8018EBFC: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x8018EC00: ori         $a0, $a0, 0x14
    ctx->r4 = ctx->r4 | 0X14;
    // 0x8018EC04: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018EC08: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018EC0C: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8018EC10: jal         0x80019218
    // 0x8018EC14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_16;
    // 0x8018EC14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_16:
    // 0x8018EC18: b           L_8018EC44
    // 0x8018EC1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8018EC44;
    // 0x8018EC1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EC20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8018EC24:
    // 0x8018EC24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018EC28: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018EC2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018EC30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018EC34: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018EC38: swc1        $f8, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f8.u32l;
    // 0x8018EC3C: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
L_8018EC40:
    // 0x8018EC40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018EC44:
    // 0x8018EC44: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018EC48: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018EC4C: jr          $ra
    // 0x8018EC50: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8018EC50: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Corneria_CoGranga_DecideNextAction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80188A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80188A20: lh          $t6, 0x50($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X50);
    // 0x80188A24: bne         $t6, $zero, L_80188BE8
    if (ctx->r14 != 0) {
        // 0x80188A28: nop
    
            goto L_80188BE8;
    }
    // 0x80188A28: nop

    // 0x80188A2C: sh          $zero, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = 0;
    // 0x80188A30: jal         0x80004EB0
    // 0x80188A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80188A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80188A38: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80188A3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188A40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80188A44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80188A48: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80188A4C: swc1        $f10, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f10.u32l;
    // 0x80188A50: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80188A54: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80188A58: nop

    // 0x80188A5C: addiu       $t9, $t8, 0x14
    ctx->r25 = ADD32(ctx->r24, 0X14);
    // 0x80188A60: jal         0x80004EB0
    // 0x80188A64: sh          $t9, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r25;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80188A64: sh          $t9, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r25;
    after_1:
    // 0x80188A68: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80188A6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188A70: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80188A74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80188A78: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80188A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80188A80: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80188A84: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80188A88: nop

    // 0x80188A8C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80188A90: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80188A94: nop

    // 0x80188A98: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80188A9C: beql        $t1, $zero, L_80188AEC
    if (ctx->r9 == 0) {
        // 0x80188AA0: mfc1        $t1, $f4
        ctx->r9 = (int32_t)ctx->f4.u32l;
            goto L_80188AEC;
    }
    goto skip_0;
    // 0x80188AA0: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80188AA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188AA8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80188AAC: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80188AB0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80188AB4: nop

    // 0x80188AB8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80188ABC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80188AC0: nop

    // 0x80188AC4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80188AC8: bne         $t1, $zero, L_80188AE0
    if (ctx->r9 != 0) {
        // 0x80188ACC: nop
    
            goto L_80188AE0;
    }
    // 0x80188ACC: nop

    // 0x80188AD0: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80188AD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80188AD8: b           L_80188AF8
    // 0x80188ADC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80188AF8;
    // 0x80188ADC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80188AE0:
    // 0x80188AE0: b           L_80188AF8
    // 0x80188AE4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80188AF8;
    // 0x80188AE4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80188AE8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
L_80188AEC:
    // 0x80188AEC: nop

    // 0x80188AF0: bltz        $t1, L_80188AE0
    if (SIGNED(ctx->r9) < 0) {
        // 0x80188AF4: nop
    
            goto L_80188AE0;
    }
    // 0x80188AF4: nop

L_80188AF8:
    // 0x80188AF8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80188AFC: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x80188B00: beq         $at, $zero, L_80188B70
    if (ctx->r1 == 0) {
        // 0x80188B04: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80188B70;
    }
    // 0x80188B04: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80188B08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188B0C: addu        $at, $at, $t1
    gpr jr_addend_80188B14 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80188B10: lw          $t1, -0x50BC($at)
    ctx->r9 = ADD32(ctx->r1, -0X50BC);
    // 0x80188B14: jr          $t1
    // 0x80188B18: nop

    switch (jr_addend_80188B14 >> 2) {
        case 0: goto L_80188B1C; break;
        case 1: goto L_80188B1C; break;
        case 2: goto L_80188B28; break;
        case 3: goto L_80188B28; break;
        case 4: goto L_80188B34; break;
        case 5: goto L_80188B68; break;
        case 6: goto L_80188B68; break;
        case 7: goto L_80188B68; break;
        default: switch_error(__func__, 0x80188B14, 0x8019AF44);
    }
    // 0x80188B18: nop

L_80188B1C:
    // 0x80188B1C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80188B20: b           L_80188B70
    // 0x80188B24: sh          $t2, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r10;
        goto L_80188B70;
    // 0x80188B24: sh          $t2, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r10;
L_80188B28:
    // 0x80188B28: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80188B2C: b           L_80188B70
    // 0x80188B30: sh          $t3, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r11;
        goto L_80188B70;
    // 0x80188B30: sh          $t3, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r11;
L_80188B34:
    // 0x80188B34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80188B38: lwc1        $f6, 0x15D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X15D4);
    // 0x80188B3C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80188B40: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80188B44: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80188B48: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80188B4C: nop

    // 0x80188B50: bc1f        L_80188B60
    if (!c1cs) {
        // 0x80188B54: nop
    
            goto L_80188B60;
    }
    // 0x80188B54: nop

    // 0x80188B58: b           L_80188B70
    // 0x80188B5C: sh          $t4, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r12;
        goto L_80188B70;
    // 0x80188B5C: sh          $t4, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r12;
L_80188B60:
    // 0x80188B60: b           L_80188B70
    // 0x80188B64: sh          $t5, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r13;
        goto L_80188B70;
    // 0x80188B64: sh          $t5, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r13;
L_80188B68:
    // 0x80188B68: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80188B6C: sh          $t6, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r14;
L_80188B70:
    // 0x80188B70: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80188B74: lw          $t7, 0x13A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X13A0);
    // 0x80188B78: slti        $at, $t7, 0x3E9
    ctx->r1 = SIGNED(ctx->r15) < 0X3E9 ? 1 : 0;
    // 0x80188B7C: bne         $at, $zero, L_80188BE8
    if (ctx->r1 != 0) {
        // 0x80188B80: nop
    
            goto L_80188BE8;
    }
    // 0x80188B80: nop

    // 0x80188B84: jal         0x80004EB0
    // 0x80188B88: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80188B88: nop

    after_2:
    // 0x80188B8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188B90: lwc1        $f10, -0x509C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X509C);
    // 0x80188B94: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80188B98: nop

    // 0x80188B9C: bc1f        L_80188BE8
    if (!c1cs) {
        // 0x80188BA0: nop
    
            goto L_80188BE8;
    }
    // 0x80188BA0: nop

    // 0x80188BA4: jal         0x80004EB0
    // 0x80188BA8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80188BA8: nop

    after_3:
    // 0x80188BAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80188BB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188BB4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188BB8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80188BBC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80188BC0: addiu       $a0, $a0, -0x4B9C
    ctx->r4 = ADD32(ctx->r4, -0X4B9C);
    // 0x80188BC4: bc1f        L_80188BE0
    if (!c1cs) {
        // 0x80188BC8: nop
    
            goto L_80188BE0;
    }
    // 0x80188BC8: nop

    // 0x80188BCC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188BD0: jal         0x8002E4F8
    // 0x80188BD4: addiu       $a0, $a0, -0x4BE4
    ctx->r4 = ADD32(ctx->r4, -0X4BE4);
    AllRange_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x80188BD4: addiu       $a0, $a0, -0x4BE4
    ctx->r4 = ADD32(ctx->r4, -0X4BE4);
    after_4:
    // 0x80188BD8: b           L_80188BE8
    // 0x80188BDC: nop

        goto L_80188BE8;
    // 0x80188BDC: nop

L_80188BE0:
    // 0x80188BE0: jal         0x8002E4F8
    // 0x80188BE4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    AllRange_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x80188BE4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_5:
L_80188BE8:
    // 0x80188BE8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80188BEC: lw          $v0, 0x13A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13A0);
    // 0x80188BF0: slti        $at, $v0, 0x321
    ctx->r1 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80188BF4: bne         $at, $zero, L_80188C6C
    if (ctx->r1 != 0) {
        // 0x80188BF8: andi        $t8, $v0, 0x1FF
        ctx->r24 = ctx->r2 & 0X1FF;
            goto L_80188C6C;
    }
    // 0x80188BF8: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x80188BFC: bne         $t8, $zero, L_80188C6C
    if (ctx->r24 != 0) {
        // 0x80188C00: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_80188C6C;
    }
    // 0x80188C00: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80188C04: lbu         $t9, 0x7B6C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7B6C);
    // 0x80188C08: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188C0C: addiu       $a0, $a0, 0x3B84
    ctx->r4 = ADD32(ctx->r4, 0X3B84);
    // 0x80188C10: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80188C14: beq         $at, $zero, L_80188C2C
    if (ctx->r1 == 0) {
        // 0x80188C18: nop
    
            goto L_80188C2C;
    }
    // 0x80188C18: nop

    // 0x80188C1C: jal         0x800BA808
    // 0x80188C20: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x80188C20: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_6:
    // 0x80188C24: b           L_80188C70
    // 0x80188C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80188C70;
    // 0x80188C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80188C2C:
    // 0x80188C2C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80188C30: lwc1        $f4, 0x15D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X15D8);
    // 0x80188C34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80188C38: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188C3C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80188C40: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80188C44: addiu       $a0, $a0, -0x4CE4
    ctx->r4 = ADD32(ctx->r4, -0X4CE4);
    // 0x80188C48: bc1f        L_80188C64
    if (!c1cs) {
        // 0x80188C4C: nop
    
            goto L_80188C64;
    }
    // 0x80188C4C: nop

    // 0x80188C50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188C54: jal         0x800BA808
    // 0x80188C58: addiu       $a0, $a0, -0x4D34
    ctx->r4 = ADD32(ctx->r4, -0X4D34);
    Radio_PlayMessage(rdram, ctx);
        goto after_7;
    // 0x80188C58: addiu       $a0, $a0, -0x4D34
    ctx->r4 = ADD32(ctx->r4, -0X4D34);
    after_7:
    // 0x80188C5C: b           L_80188C70
    // 0x80188C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80188C70;
    // 0x80188C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80188C64:
    // 0x80188C64: jal         0x800BA808
    // 0x80188C68: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x80188C68: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_8:
L_80188C6C:
    // 0x80188C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80188C70:
    // 0x80188C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80188C74: jr          $ra
    // 0x80188C78: nop

    return;
    // 0x80188C78: nop

;}
RECOMP_FUNC void Corneria_CoCarrierBottom_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EF90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018EF94: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8018EF98: addiu       $v0, $v0, -0x6558
    ctx->r2 = ADD32(ctx->r2, -0X6558);
    // 0x8018EF9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018EFA0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018EFA4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018EFA8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018EFAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EFB0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8018EFB4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8018EFB8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018EFBC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018EFC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018EFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018EFC8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018EFCC: jal         0x80005B00
    // 0x8018EFD0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8018EFD0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x8018EFD4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018EFD8: jal         0x80006EB8
    // 0x8018EFDC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8018EFDC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x8018EFE0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8018EFE4: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018EFE8: addiu       $a0, $a0, -0x2C00
    ctx->r4 = ADD32(ctx->r4, -0X2C00);
    // 0x8018EFEC: addiu       $a2, $a2, 0x1A0
    ctx->r6 = ADD32(ctx->r6, 0X1A0);
    // 0x8018EFF0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8018EFF4: jal         0x8009AA20
    // 0x8018EFF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_2;
    // 0x8018EFF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8018EFFC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8018F000: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8018F004: addiu       $t9, $t9, 0x4660
    ctx->r25 = ADD32(ctx->r25, 0X4660);
    // 0x8018F008: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8018F00C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018F010: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x8018F014: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F018: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018F01C: addiu       $a3, $a3, -0x10C8
    ctx->r7 = ADD32(ctx->r7, -0X10C8);
    // 0x8018F020: addiu       $a1, $a1, -0x2A54
    ctx->r5 = ADD32(ctx->r5, -0X2A54);
    // 0x8018F024: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8018F028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018F02C: jal         0x8009A72C
    // 0x8018F030: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_3;
    // 0x8018F030: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8018F034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018F038: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018F03C: jr          $ra
    // 0x8018F040: nop

    return;
    // 0x8018F040: nop

;}
RECOMP_FUNC void Training_EnemyObstacleCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198DCC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80198DD0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80198DD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80198DD8: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80198DDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198DE0: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80198DE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198DE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198DEC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80198DF0: lw          $v1, -0x7D58($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D58);
    // 0x80198DF4: lwc1        $f2, -0x4980($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4980);
    // 0x80198DF8: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80198DFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80198E00:
    // 0x80198E00: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80198E04: bnel        $a1, $t6, L_80198E84
    if (ctx->r5 != ctx->r14) {
        // 0x80198E08: lbu         $t7, 0x58($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X58);
            goto L_80198E84;
    }
    goto skip_0;
    // 0x80198E08: lbu         $t7, 0x58($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X58);
    skip_0:
    // 0x80198E0C: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80198E10: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80198E14: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80198E18: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80198E1C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80198E20: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80198E24: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198E28: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198E2C: nop

    // 0x80198E30: bc1fl       L_80198E84
    if (!c1cs) {
        // 0x80198E34: lbu         $t7, 0x58($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X58);
            goto L_80198E84;
    }
    goto skip_1;
    // 0x80198E34: lbu         $t7, 0x58($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X58);
    skip_1:
    // 0x80198E38: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80198E3C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80198E40: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80198E44: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80198E48: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80198E4C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80198E50: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198E54: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198E58: nop

    // 0x80198E5C: bc1fl       L_80198E84
    if (!c1cs) {
        // 0x80198E60: lbu         $t7, 0x58($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X58);
            goto L_80198E84;
    }
    goto skip_2;
    // 0x80198E60: lbu         $t7, 0x58($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X58);
    skip_2:
    // 0x80198E64: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80198E68: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80198E6C: nop

    // 0x80198E70: bc1fl       L_80198E84
    if (!c1cs) {
        // 0x80198E74: lbu         $t7, 0x58($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X58);
            goto L_80198E84;
    }
    goto skip_3;
    // 0x80198E74: lbu         $t7, 0x58($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X58);
    skip_3:
    // 0x80198E78: jr          $ra
    // 0x80198E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80198E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80198E80: lbu         $t7, 0x58($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X58);
L_80198E84:
    // 0x80198E84: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80198E88: bnel        $a1, $t7, L_80198F08
    if (ctx->r5 != ctx->r15) {
        // 0x80198E8C: lbu         $t8, 0x58($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F08;
    }
    goto skip_4;
    // 0x80198E8C: lbu         $t8, 0x58($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X58);
    skip_4:
    // 0x80198E90: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80198E94: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80198E98: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80198E9C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80198EA0: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80198EA4: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80198EA8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198EAC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198EB0: nop

    // 0x80198EB4: bc1fl       L_80198F08
    if (!c1cs) {
        // 0x80198EB8: lbu         $t8, 0x58($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F08;
    }
    goto skip_5;
    // 0x80198EB8: lbu         $t8, 0x58($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X58);
    skip_5:
    // 0x80198EBC: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80198EC0: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80198EC4: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80198EC8: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80198ECC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80198ED0: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80198ED4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198ED8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198EDC: nop

    // 0x80198EE0: bc1fl       L_80198F08
    if (!c1cs) {
        // 0x80198EE4: lbu         $t8, 0x58($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F08;
    }
    goto skip_6;
    // 0x80198EE4: lbu         $t8, 0x58($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X58);
    skip_6:
    // 0x80198EE8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80198EEC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80198EF0: nop

    // 0x80198EF4: bc1fl       L_80198F08
    if (!c1cs) {
        // 0x80198EF8: lbu         $t8, 0x58($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F08;
    }
    goto skip_7;
    // 0x80198EF8: lbu         $t8, 0x58($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X58);
    skip_7:
    // 0x80198EFC: jr          $ra
    // 0x80198F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80198F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80198F04: lbu         $t8, 0x58($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X58);
L_80198F08:
    // 0x80198F08: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80198F0C: bnel        $a1, $t8, L_80198F8C
    if (ctx->r5 != ctx->r24) {
        // 0x80198F10: lbu         $t9, 0x58($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F8C;
    }
    goto skip_8;
    // 0x80198F10: lbu         $t9, 0x58($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X58);
    skip_8:
    // 0x80198F14: mul.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80198F18: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80198F1C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80198F20: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80198F24: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80198F28: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80198F2C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198F30: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198F34: nop

    // 0x80198F38: bc1fl       L_80198F8C
    if (!c1cs) {
        // 0x80198F3C: lbu         $t9, 0x58($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F8C;
    }
    goto skip_9;
    // 0x80198F3C: lbu         $t9, 0x58($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X58);
    skip_9:
    // 0x80198F40: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80198F44: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80198F48: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80198F4C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80198F50: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80198F54: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80198F58: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198F5C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198F60: nop

    // 0x80198F64: bc1fl       L_80198F8C
    if (!c1cs) {
        // 0x80198F68: lbu         $t9, 0x58($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F8C;
    }
    goto skip_10;
    // 0x80198F68: lbu         $t9, 0x58($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X58);
    skip_10:
    // 0x80198F6C: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80198F70: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80198F74: nop

    // 0x80198F78: bc1fl       L_80198F8C
    if (!c1cs) {
        // 0x80198F7C: lbu         $t9, 0x58($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X58);
            goto L_80198F8C;
    }
    goto skip_11;
    // 0x80198F7C: lbu         $t9, 0x58($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X58);
    skip_11:
    // 0x80198F80: jr          $ra
    // 0x80198F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80198F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80198F88: lbu         $t9, 0x58($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X58);
L_80198F8C:
    // 0x80198F8C: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80198F90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80198F94: bne         $a1, $t9, L_80199010
    if (ctx->r5 != ctx->r25) {
        // 0x80198F98: nop
    
            goto L_80199010;
    }
    // 0x80198F98: nop

    // 0x80198F9C: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80198FA0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80198FA4: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80198FA8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80198FAC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80198FB0: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80198FB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198FB8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198FBC: nop

    // 0x80198FC0: bc1f        L_80199010
    if (!c1cs) {
        // 0x80198FC4: nop
    
            goto L_80199010;
    }
    // 0x80198FC4: nop

    // 0x80198FC8: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80198FCC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80198FD0: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80198FD4: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80198FD8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80198FDC: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80198FE0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198FE4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80198FE8: nop

    // 0x80198FEC: bc1f        L_80199010
    if (!c1cs) {
        // 0x80198FF0: nop
    
            goto L_80199010;
    }
    // 0x80198FF0: nop

    // 0x80198FF4: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80198FF8: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80198FFC: nop

    // 0x80199000: bc1f        L_80199010
    if (!c1cs) {
        // 0x80199004: nop
    
            goto L_80199010;
    }
    // 0x80199004: nop

    // 0x80199008: jr          $ra
    // 0x8019900C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8019900C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80199010:
    // 0x80199010: bne         $v0, $a2, L_80198E00
    if (ctx->r2 != ctx->r6) {
        // 0x80199014: addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
            goto L_80198E00;
    }
    // 0x80199014: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80199018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019901C: jr          $ra
    // 0x80199020: nop

    return;
    // 0x80199020: nop

;}
RECOMP_FUNC void Venom1_Ve1Pillar2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192E2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80192E30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192E34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80192E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80192E3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80192E40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80192E44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80192E48: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80192E4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80192E50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80192E54: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80192E58: jal         0x80005C34
    // 0x80192E5C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x80192E5C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80192E60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80192E64: jal         0x80006EB8
    // 0x80192E68: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x80192E68: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x80192E6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80192E70: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80192E74: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80192E78: lui         $t9, 0x902
    ctx->r25 = S32(0X902 << 16);
    // 0x80192E7C: addiu       $t9, $t9, -0x25B0
    ctx->r25 = ADD32(ctx->r25, -0X25B0);
    // 0x80192E80: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80192E84: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80192E88: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80192E8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80192E90: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80192E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80192E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80192E9C: jr          $ra
    // 0x80192EA0: nop

    return;
    // 0x80192EA0: nop

;}
RECOMP_FUNC void Corneria_CoCarrier_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C19C: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x8018C1A0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018C1A4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018C1A8: addiu       $v0, $v0, 0x13A0
    ctx->r2 = ADD32(ctx->r2, 0X13A0);
    // 0x8018C1AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018C1B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018C1B4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018C1B8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018C1BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018C1C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C1C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C1C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018C1CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018C1D0: lwc1        $f6, -0x4F4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F4C);
    // 0x8018C1D4: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8018C1D8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C1DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018C1E0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018C1E4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018C1E8: jal         0x80005E90
    // 0x8018C1EC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8018C1EC: nop

    after_0:
    // 0x8018C1F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C1F4: lwc1        $f16, -0x4F48($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4F48);
    // 0x8018C1F8: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8018C1FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C200: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C204: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018C208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C20C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018C210: jal         0x80005D44
    // 0x8018C214: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8018C214: nop

    after_1:
    // 0x8018C218: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C21C: lwc1        $f6, -0x4F44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F44);
    // 0x8018C220: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8018C224: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C228: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C22C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018C230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C234: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018C238: jal         0x80005FE0
    // 0x8018C23C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8018C23C: nop

    after_2:
    // 0x8018C240: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8018C244: lbu         $t8, -0x4930($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4930);
    // 0x8018C248: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018C24C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C250: bne         $t8, $zero, L_8018C414
    if (ctx->r24 != 0) {
        // 0x8018C254: lui         $a1, 0x801A
        ctx->r5 = S32(0X801A << 16);
            goto L_8018C414;
    }
    // 0x8018C254: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C25C: lwc1        $f10, -0x4F40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4F40);
    // 0x8018C260: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018C264: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018C268: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C26C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8018C270: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8018C274: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8018C278: bc1fl       L_8018C2CC
    if (!c1cs) {
        // 0x8018C27C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8018C2CC;
    }
    goto skip_0;
    // 0x8018C27C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8018C280: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018C284: jal         0x80060FBC
    // 0x8018C288: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8018C288: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    after_3:
    // 0x8018C28C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018C290: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8018C294: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8018C298: addiu       $s1, $s1, 0x52C
    ctx->r17 = ADD32(ctx->r17, 0X52C);
    // 0x8018C29C: addiu       $s0, $s0, -0x6EC
    ctx->r16 = ADD32(ctx->r16, -0X6EC);
    // 0x8018C2A0: addiu       $a0, $a0, -0xAE8
    ctx->r4 = ADD32(ctx->r4, -0XAE8);
L_8018C2A4:
    // 0x8018C2A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018C2A8: jal         0x80060FBC
    // 0x8018C2AC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x8018C2AC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_4:
    // 0x8018C2B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018C2B4: addiu       $s0, $s0, 0x408
    ctx->r16 = ADD32(ctx->r16, 0X408);
    // 0x8018C2B8: bne         $s0, $s1, L_8018C2A4
    if (ctx->r16 != ctx->r17) {
        // 0x8018C2BC: addiu       $a0, $a0, 0x408
        ctx->r4 = ADD32(ctx->r4, 0X408);
            goto L_8018C2A4;
    }
    // 0x8018C2BC: addiu       $a0, $a0, 0x408
    ctx->r4 = ADD32(ctx->r4, 0X408);
    // 0x8018C2C0: b           L_8018DD98
    // 0x8018C2C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8018DD98;
    // 0x8018C2C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018C2C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8018C2CC:
    // 0x8018C2CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C2D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C2D4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8018C2D8: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8018C2DC: jal         0x80006970
    // 0x8018C2E0: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x8018C2E0: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8018C2E4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018C2E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C2EC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018C2F0: swc1        $f4, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f4.u32l;
    // 0x8018C2F4: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8018C2F8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C2FC: addiu       $a1, $a1, -0x66EC
    ctx->r5 = ADD32(ctx->r5, -0X66EC);
    // 0x8018C300: swc1        $f6, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f6.u32l;
    // 0x8018C304: lwc1        $f10, 0x7D08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8018C308: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018C30C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8018C310: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C314: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018C318: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C31C: swc1        $f18, 0x118($s2)
    MEM_W(0X118, ctx->r18) = ctx->f18.u32l;
    // 0x8018C320: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    // 0x8018C324: swc1        $f16, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f16.u32l;
    // 0x8018C328: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8018C32C: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x8018C330: bnel        $t1, $zero, L_8018DD98
    if (ctx->r9 != 0) {
        // 0x8018C334: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8018DD98;
    }
    goto skip_1;
    // 0x8018C334: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8018C338: jal         0x80006970
    // 0x8018C33C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8018C33C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_6:
    // 0x8018C340: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C344: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C348: addiu       $a1, $a1, -0x66E0
    ctx->r5 = ADD32(ctx->r5, -0X66E0);
    // 0x8018C34C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C350: jal         0x80006970
    // 0x8018C354: addiu       $a2, $sp, 0xD8
    ctx->r6 = ADD32(ctx->r29, 0XD8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x8018C354: addiu       $a2, $sp, 0xD8
    ctx->r6 = ADD32(ctx->r29, 0XD8);
    after_7:
    // 0x8018C358: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C35C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C360: addiu       $a1, $a1, -0x66D4
    ctx->r5 = ADD32(ctx->r5, -0X66D4);
    // 0x8018C364: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C368: jal         0x80006970
    // 0x8018C36C: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x8018C36C: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    after_8:
    // 0x8018C370: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018C374: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018C378: lwc1        $f16, 0xD4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8018C37C: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018C380: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C384: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018C388: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018C38C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C390: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8018C394: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018C398: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018C39C: jal         0x8007BC7C
    // 0x8018C3A0: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_9;
    // 0x8018C3A0: nop

    after_9:
    // 0x8018C3A4: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8018C3A8: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018C3AC: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8018C3B0: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018C3B4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018C3B8: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8018C3BC: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018C3C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018C3C4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C3C8: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018C3CC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018C3D0: jal         0x8007BC7C
    // 0x8018C3D4: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_10;
    // 0x8018C3D4: nop

    after_10:
    // 0x8018C3D8: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8018C3DC: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018C3E0: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8018C3E4: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018C3E8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018C3EC: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8018C3F0: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018C3F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C3F8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C3FC: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C400: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018C404: jal         0x8007BC7C
    // 0x8018C408: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_11;
    // 0x8018C408: nop

    after_11:
    // 0x8018C40C: b           L_8018DD98
    // 0x8018C410: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8018DD98;
    // 0x8018C410: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8018C414:
    // 0x8018C414: lw          $v0, 0x13A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13A0);
    // 0x8018C418: addiu       $a1, $a1, -0x6734
    ctx->r5 = ADD32(ctx->r5, -0X6734);
    // 0x8018C41C: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x8018C420: slti        $at, $v0, 0x17D
    ctx->r1 = SIGNED(ctx->r2) < 0X17D ? 1 : 0;
    // 0x8018C424: bne         $at, $zero, L_8018C468
    if (ctx->r1 != 0) {
        // 0x8018C428: slti        $at, $v0, 0x1AE
        ctx->r1 = SIGNED(ctx->r2) < 0X1AE ? 1 : 0;
            goto L_8018C468;
    }
    // 0x8018C428: slti        $at, $v0, 0x1AE
    ctx->r1 = SIGNED(ctx->r2) < 0X1AE ? 1 : 0;
    // 0x8018C42C: beq         $at, $zero, L_8018C468
    if (ctx->r1 == 0) {
        // 0x8018C430: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_8018C468;
    }
    // 0x8018C430: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8018C434: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8018C438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C43C: sw          $t2, -0x7AC0($at)
    MEM_W(-0X7AC0, ctx->r1) = ctx->r10;
    // 0x8018C440: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C444: sw          $v0, -0x7A90($at)
    MEM_W(-0X7A90, ctx->r1) = ctx->r2;
    // 0x8018C448: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C44C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8018C450: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8018C454: sw          $v0, -0x7A8C($at)
    MEM_W(-0X7A8C, ctx->r1) = ctx->r2;
    // 0x8018C458: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C45C: sw          $v0, -0x7A88($at)
    MEM_W(-0X7A88, ctx->r1) = ctx->r2;
    // 0x8018C460: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8018C464: sw          $t3, 0x23C($t4)
    MEM_W(0X23C, ctx->r12) = ctx->r11;
L_8018C468:
    // 0x8018C468: jal         0x80006970
    // 0x8018C46C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x8018C46C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_12:
    // 0x8018C470: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C474: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C478: addiu       $a1, $a1, -0x6728
    ctx->r5 = ADD32(ctx->r5, -0X6728);
    // 0x8018C47C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C480: jal         0x80006970
    // 0x8018C484: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x8018C484: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_13:
    // 0x8018C488: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C48C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C490: addiu       $a1, $a1, -0x671C
    ctx->r5 = ADD32(ctx->r5, -0X671C);
    // 0x8018C494: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C498: jal         0x80006970
    // 0x8018C49C: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x8018C49C: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_14:
    // 0x8018C4A0: lh          $v0, 0x60($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X60);
    // 0x8018C4A4: addiu       $at, $zero, 0x259
    ctx->r1 = ADD32(0, 0X259);
    // 0x8018C4A8: beq         $v0, $at, L_8018C5DC
    if (ctx->r2 == ctx->r1) {
        // 0x8018C4AC: addiu       $v1, $v0, -0x259
        ctx->r3 = ADD32(ctx->r2, -0X259);
            goto L_8018C5DC;
    }
    // 0x8018C4AC: addiu       $v1, $v0, -0x259
    ctx->r3 = ADD32(ctx->r2, -0X259);
    // 0x8018C4B0: bgez        $v1, L_8018C4C0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8018C4B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018C4C0;
    }
    // 0x8018C4B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018C4B8: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x8018C4BC: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_8018C4C0:
    // 0x8018C4C0: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018C4C4: bne         $at, $zero, L_8018C4DC
    if (ctx->r1 != 0) {
        // 0x8018C4C8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8018C4DC;
    }
    // 0x8018C4C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8018C4CC:
    // 0x8018C4CC: addiu       $v1, $v1, -0x3C
    ctx->r3 = ADD32(ctx->r3, -0X3C);
    // 0x8018C4D0: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018C4D4: beq         $at, $zero, L_8018C4CC
    if (ctx->r1 == 0) {
        // 0x8018C4D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018C4CC;
    }
    // 0x8018C4D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018C4DC:
    // 0x8018C4DC: blez        $s1, L_8018C5DC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8018C4E0: addiu       $v1, $zero, 0xD
        ctx->r3 = ADD32(0, 0XD);
            goto L_8018C5DC;
    }
    // 0x8018C4E0: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
L_8018C4E4:
    // 0x8018C4E4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018C4E8: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8018C4EC: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x8018C4F0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8018C4F4: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8018C4F8: bnel        $t6, $t8, L_8018C5D4
    if (ctx->r14 != ctx->r24) {
        // 0x8018C4FC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8018C5D4;
    }
    goto skip_2;
    // 0x8018C4FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8018C500: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018C504: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8018C508: addiu       $t3, $sp, 0x84
    ctx->r11 = ADD32(ctx->r29, 0X84);
    // 0x8018C50C: addiu       $t1, $t1, -0x66A4
    ctx->r9 = ADD32(ctx->r9, -0X66A4);
    // 0x8018C510: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C514: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C518: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8018C51C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x8018C520: mflo        $t9
    ctx->r25 = lo;
    // 0x8018C524: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x8018C528: nop

    // 0x8018C52C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018C530: mflo        $t2
    ctx->r10 = lo;
    // 0x8018C534: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x8018C538: jal         0x80006970
    // 0x8018C53C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_15;
    // 0x8018C53C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_15:
    // 0x8018C540: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018C544: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018C548: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018C54C: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018C550: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018C554: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018C558: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018C55C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018C560: lw          $a3, 0x11C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X11C);
    // 0x8018C564: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018C568: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018C56C: jal         0x8007D0E0
    // 0x8018C570: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_16;
    // 0x8018C570: nop

    after_16:
    // 0x8018C574: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018C578: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018C57C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018C580: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018C584: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018C588: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018C58C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C590: lwc1        $f18, 0x70($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X70);
    // 0x8018C594: lw          $a3, 0x6C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X6C);
    // 0x8018C598: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018C59C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C5A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018C5A4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C5A8: lwc1        $f6, -0x4F3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F3C);
    // 0x8018C5AC: lwc1        $f4, 0x74($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X74);
    // 0x8018C5B0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8018C5B4: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8018C5B8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8018C5BC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018C5C0: jal         0x8007C120
    // 0x8018C5C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_17;
    // 0x8018C5C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x8018C5C8: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8018C5CC: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8018C5D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8018C5D4:
    // 0x8018C5D4: bne         $v0, $s1, L_8018C4E4
    if (ctx->r2 != ctx->r17) {
        // 0x8018C5D8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8018C4E4;
    }
    // 0x8018C5D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018C5DC:
    // 0x8018C5DC: lb          $t5, 0x62($s2)
    ctx->r13 = MEM_B(ctx->r18, 0X62);
    // 0x8018C5E0: beq         $t5, $zero, L_8018C6E0
    if (ctx->r13 == 0) {
        // 0x8018C5E4: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_8018C6E0;
    }
    // 0x8018C5E4: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8018C5E8: addiu       $s1, $s1, -0xEF0
    ctx->r17 = ADD32(ctx->r17, -0XEF0);
    // 0x8018C5EC: sb          $zero, 0x62($s2)
    MEM_B(0X62, ctx->r18) = 0;
    // 0x8018C5F0: lh          $t7, 0x456($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X456);
    // 0x8018C5F4: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8018C5F8: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8018C5FC: beq         $t7, $zero, L_8018C6C0
    if (ctx->r15 == 0) {
        // 0x8018C600: addiu       $a1, $s2, 0x3FC
        ctx->r5 = ADD32(ctx->r18, 0X3FC);
            goto L_8018C6C0;
    }
    // 0x8018C600: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018C604: lh          $t6, 0x85E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X85E);
    // 0x8018C608: beq         $t6, $zero, L_8018C6C0
    if (ctx->r14 == 0) {
        // 0x8018C60C: nop
    
            goto L_8018C6C0;
    }
    // 0x8018C60C: nop

    // 0x8018C610: lh          $t8, 0xC66($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC66);
    // 0x8018C614: beq         $t8, $zero, L_8018C6C0
    if (ctx->r24 == 0) {
        // 0x8018C618: nop
    
            goto L_8018C6C0;
    }
    // 0x8018C618: nop

    // 0x8018C61C: lh          $v0, 0x60($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X60);
    // 0x8018C620: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8018C624: bnel        $at, $zero, L_8018C6E4
    if (ctx->r1 != 0) {
        // 0x8018C628: lh          $v0, 0x4E($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X4E);
            goto L_8018C6E4;
    }
    goto skip_3;
    // 0x8018C628: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
    skip_3:
    // 0x8018C62C: lh          $t1, 0x64($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X64);
    // 0x8018C630: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8018C634: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018C638: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8018C63C: sh          $t2, 0x60($s2)
    MEM_H(0X60, ctx->r18) = ctx->r10;
    // 0x8018C640: lh          $t3, 0x60($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X60);
    // 0x8018C644: sh          $t9, 0x5C($s2)
    MEM_H(0X5C, ctx->r18) = ctx->r25;
    // 0x8018C648: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8018C64C: slti        $at, $t3, 0x78
    ctx->r1 = SIGNED(ctx->r11) < 0X78 ? 1 : 0;
    // 0x8018C650: beq         $at, $zero, L_8018C698
    if (ctx->r1 == 0) {
        // 0x8018C654: addiu       $a1, $s2, 0x3FC
        ctx->r5 = ADD32(ctx->r18, 0X3FC);
            goto L_8018C698;
    }
    // 0x8018C654: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018C658: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C65C: lwc1        $f8, -0x4F38($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4F38);
    // 0x8018C660: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018C664: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8018C668: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018C66C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8018C670: lui         $a0, 0x2943
    ctx->r4 = S32(0X2943 << 16);
    // 0x8018C674: swc1        $f8, 0x11C($s2)
    MEM_W(0X11C, ctx->r18) = ctx->f8.u32l;
    // 0x8018C678: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018C67C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018C680: ori         $a0, $a0, 0x500F
    ctx->r4 = ctx->r4 | 0X500F;
    // 0x8018C684: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018C688: jal         0x80019218
    // 0x8018C68C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x8018C68C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
    // 0x8018C690: b           L_8018C6E4
    // 0x8018C694: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
        goto L_8018C6E4;
    // 0x8018C694: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
L_8018C698:
    // 0x8018C698: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8018C69C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018C6A0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018C6A4: addiu       $a3, $t5, 0x5D34
    ctx->r7 = ADD32(ctx->r13, 0X5D34);
    // 0x8018C6A8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018C6AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018C6B0: jal         0x80019218
    // 0x8018C6B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x8018C6B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_19:
    // 0x8018C6B8: b           L_8018C6E4
    // 0x8018C6BC: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
        goto L_8018C6E4;
    // 0x8018C6BC: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
L_8018C6C0:
    // 0x8018C6C0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018C6C4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018C6C8: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018C6CC: addiu       $a3, $t6, 0x5D34
    ctx->r7 = ADD32(ctx->r14, 0X5D34);
    // 0x8018C6D0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018C6D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018C6D8: jal         0x80019218
    // 0x8018C6DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x8018C6DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_20:
L_8018C6E0:
    // 0x8018C6E0: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
L_8018C6E4:
    // 0x8018C6E4: lwc1        $f10, 0x120($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X120);
    // 0x8018C6E8: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8018C6EC: addiu       $s1, $s1, -0xEF0
    ctx->r17 = ADD32(ctx->r17, -0XEF0);
    // 0x8018C6F0: blez        $v0, L_8018C724
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8018C6F4: swc1        $f10, 0x74($s2)
        MEM_W(0X74, ctx->r18) = ctx->f10.u32l;
            goto L_8018C724;
    }
    // 0x8018C6F4: swc1        $f10, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f10.u32l;
    // 0x8018C6F8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018C6FC: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8018C700: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C704: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018C708: lwc1        $f16, 0x48($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8018C70C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C710: lwc1        $f6, -0x4F34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F34);
    // 0x8018C714: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8018C718: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
    // 0x8018C71C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018C720: swc1        $f8, 0xE4($s2)
    MEM_W(0XE4, ctx->r18) = ctx->f8.u32l;
L_8018C724:
    // 0x8018C724: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x8018C728: beq         $s0, $v0, L_8018C774
    if (ctx->r16 == ctx->r2) {
        // 0x8018C72C: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018C774;
    }
    // 0x8018C72C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C730: lwc1        $f10, -0x4F30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4F30);
    // 0x8018C734: lw          $a1, 0xEC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XEC);
    // 0x8018C738: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018C73C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C740: addiu       $a0, $s2, 0xE8
    ctx->r4 = ADD32(ctx->r18, 0XE8);
    // 0x8018C744: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018C748: jal         0x8009BC2C
    // 0x8018C74C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8018C74C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x8018C750: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C754: lwc1        $f16, -0x4F2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4F2C);
    // 0x8018C758: lw          $a1, 0xE4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XE4);
    // 0x8018C75C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018C760: lw          $a3, 0xE8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XE8);
    // 0x8018C764: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C768: addiu       $a0, $s2, 0xC
    ctx->r4 = ADD32(ctx->r18, 0XC);
    // 0x8018C76C: jal         0x8009BC2C
    // 0x8018C770: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8018C770: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_22:
L_8018C774:
    // 0x8018C774: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C778: lwc1        $f18, -0x4F28($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4F28);
    // 0x8018C77C: lw          $a1, 0xF0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XF0);
    // 0x8018C780: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018C784: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018C788: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018C78C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018C790: jal         0x8009BC2C
    // 0x8018C794: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x8018C794: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_23:
    // 0x8018C798: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C79C: lwc1        $f4, -0x4F24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4F24);
    // 0x8018C7A0: lw          $a1, 0xFC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XFC);
    // 0x8018C7A4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018C7A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C7AC: addiu       $a0, $s2, 0xD8
    ctx->r4 = ADD32(ctx->r18, 0XD8);
    // 0x8018C7B0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018C7B4: jal         0x8009BD38
    // 0x8018C7B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_24;
    // 0x8018C7B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_24:
    // 0x8018C7BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C7C0: lwc1        $f6, -0x4F20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F20);
    // 0x8018C7C4: lw          $a1, 0x100($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X100);
    // 0x8018C7C8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018C7CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C7D0: addiu       $a0, $s2, 0xDC
    ctx->r4 = ADD32(ctx->r18, 0XDC);
    // 0x8018C7D4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018C7D8: jal         0x8009BD38
    // 0x8018C7DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_25;
    // 0x8018C7DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x8018C7E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C7E4: lwc1        $f8, -0x4F1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4F1C);
    // 0x8018C7E8: lw          $a1, 0x104($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X104);
    // 0x8018C7EC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018C7F0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C7F4: addiu       $a0, $s2, 0xE0
    ctx->r4 = ADD32(ctx->r18, 0XE0);
    // 0x8018C7F8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018C7FC: jal         0x8009BD38
    // 0x8018C800: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_26;
    // 0x8018C800: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_26:
    // 0x8018C804: lh          $t1, 0x4E($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X4E);
    // 0x8018C808: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018C80C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018C810: slti        $at, $t1, 0x6
    ctx->r1 = SIGNED(ctx->r9) < 0X6 ? 1 : 0;
    // 0x8018C814: beq         $at, $zero, L_8018C8A0
    if (ctx->r1 == 0) {
        // 0x8018C818: addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
            goto L_8018C8A0;
    }
    // 0x8018C818: addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // 0x8018C81C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C820: lwc1        $f10, -0x4F18($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4F18);
    // 0x8018C824: lw          $a1, 0x10C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10C);
    // 0x8018C828: lw          $a3, 0xF8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XF8);
    // 0x8018C82C: jal         0x8009BD38
    // 0x8018C830: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_27;
    // 0x8018C830: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_27:
    // 0x8018C834: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C838: lwc1        $f16, -0x4F14($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4F14);
    // 0x8018C83C: lw          $a1, 0x108($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X108);
    // 0x8018C840: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018C844: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x8018C848: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8018C84C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C850: addiu       $a0, $s2, 0xF8
    ctx->r4 = ADD32(ctx->r18, 0XF8);
    // 0x8018C854: jal         0x8009BC2C
    // 0x8018C858: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x8018C858: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_28:
    // 0x8018C85C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C860: lwc1        $f18, -0x4F10($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4F10);
    // 0x8018C864: lw          $a1, 0x110($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X110);
    // 0x8018C868: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018C86C: lw          $a3, 0x114($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X114);
    // 0x8018C870: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018C874: addiu       $a0, $s2, 0x18
    ctx->r4 = ADD32(ctx->r18, 0X18);
    // 0x8018C878: jal         0x8009BD38
    // 0x8018C87C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_29;
    // 0x8018C87C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_29:
    // 0x8018C880: lh          $t2, 0x56($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X56);
    // 0x8018C884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018C888: bne         $t2, $at, L_8018C8A0
    if (ctx->r10 != ctx->r1) {
        // 0x8018C88C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8018C8A0;
    }
    // 0x8018C88C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018C890: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018C894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C898: swc1        $f4, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f4.u32l;
    // 0x8018C89C: swc1        $f6, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->f6.u32l;
L_8018C8A0:
    // 0x8018C8A0: lh          $t3, 0x456($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X456);
    // 0x8018C8A4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018C8A8: beql        $t3, $zero, L_8018C90C
    if (ctx->r11 == 0) {
        // 0x8018C8AC: lh          $t7, 0x85E($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X85E);
            goto L_8018C90C;
    }
    goto skip_4;
    // 0x8018C8AC: lh          $t7, 0x85E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X85E);
    skip_4:
    // 0x8018C8B0: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x8018C8B4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C8B8: addiu       $a1, $a1, -0x66F8
    ctx->r5 = ADD32(ctx->r5, -0X66F8);
    // 0x8018C8BC: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8018C8C0: bne         $t5, $zero, L_8018C908
    if (ctx->r13 != 0) {
        // 0x8018C8C4: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018C908;
    }
    // 0x8018C8C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C8C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C8CC: jal         0x80006970
    // 0x8018C8D0: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_30;
    // 0x8018C8D0: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    after_30:
    // 0x8018C8D4: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8018C8D8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018C8DC: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8018C8E0: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018C8E4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018C8E8: lwc1        $f16, 0xC4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8018C8EC: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018C8F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C8F4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018C8F8: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C8FC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018C900: jal         0x8007D0E0
    // 0x8018C904: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_31;
    // 0x8018C904: nop

    after_31:
L_8018C908:
    // 0x8018C908: lh          $t7, 0x85E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X85E);
L_8018C90C:
    // 0x8018C90C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018C910: beql        $t7, $zero, L_8018C9E0
    if (ctx->r15 == 0) {
        // 0x8018C914: lh          $t2, 0xC66($s1)
        ctx->r10 = MEM_H(ctx->r17, 0XC66);
            goto L_8018C9E0;
    }
    goto skip_5;
    // 0x8018C914: lh          $t2, 0xC66($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XC66);
    skip_5:
    // 0x8018C918: lh          $t8, 0xC66($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC66);
    // 0x8018C91C: sb          $t6, 0xC76($s1)
    MEM_B(0XC76, ctx->r17) = ctx->r14;
    // 0x8018C920: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018C924: beq         $t8, $zero, L_8018C988
    if (ctx->r24 == 0) {
        // 0x8018C928: lw          $v0, 0x7DB0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
            goto L_8018C988;
    }
    // 0x8018C928: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8018C92C: andi        $t9, $v0, 0x7
    ctx->r25 = ctx->r2 & 0X7;
    // 0x8018C930: bne         $t9, $zero, L_8018C9DC
    if (ctx->r25 != 0) {
        // 0x8018C934: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018C9DC;
    }
    // 0x8018C934: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C938: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C93C: addiu       $a1, $a1, -0x66B0
    ctx->r5 = ADD32(ctx->r5, -0X66B0);
    // 0x8018C940: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C944: jal         0x80006970
    // 0x8018C948: addiu       $a2, $sp, 0x108
    ctx->r6 = ADD32(ctx->r29, 0X108);
    Matrix_MultVec3f(rdram, ctx);
        goto after_32;
    // 0x8018C948: addiu       $a2, $sp, 0x108
    ctx->r6 = ADD32(ctx->r29, 0X108);
    after_32:
    // 0x8018C94C: lwc1        $f10, 0x108($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8018C950: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018C954: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8018C958: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018C95C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018C960: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8018C964: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018C968: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018C96C: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x8018C970: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018C974: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018C978: jal         0x8007D0E0
    // 0x8018C97C: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_33;
    // 0x8018C97C: nop

    after_33:
    // 0x8018C980: b           L_8018C9E0
    // 0x8018C984: lh          $t2, 0xC66($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XC66);
        goto L_8018C9E0;
    // 0x8018C984: lh          $t2, 0xC66($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XC66);
L_8018C988:
    // 0x8018C988: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x8018C98C: bne         $t1, $zero, L_8018C9DC
    if (ctx->r9 != 0) {
        // 0x8018C990: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018C9DC;
    }
    // 0x8018C990: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C994: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C998: addiu       $a1, $a1, -0x66C8
    ctx->r5 = ADD32(ctx->r5, -0X66C8);
    // 0x8018C99C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C9A0: jal         0x80006970
    // 0x8018C9A4: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_34;
    // 0x8018C9A4: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    after_34:
    // 0x8018C9A8: lwc1        $f16, 0xF0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8018C9AC: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018C9B0: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8018C9B4: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018C9B8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C9BC: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8018C9C0: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018C9C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018C9C8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018C9CC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C9D0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8018C9D4: jal         0x8007D0E0
    // 0x8018C9D8: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_35;
    // 0x8018C9D8: nop

    after_35:
L_8018C9DC:
    // 0x8018C9DC: lh          $t2, 0xC66($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XC66);
L_8018C9E0:
    // 0x8018C9E0: beql        $t2, $zero, L_8018CA54
    if (ctx->r10 == 0) {
        // 0x8018C9E4: lh          $v0, 0x4E($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X4E);
            goto L_8018CA54;
    }
    goto skip_6;
    // 0x8018C9E4: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
    skip_6:
    // 0x8018C9E8: lh          $t3, 0x85E($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X85E);
    // 0x8018C9EC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018C9F0: bnel        $t3, $zero, L_8018CA54
    if (ctx->r11 != 0) {
        // 0x8018C9F4: lh          $v0, 0x4E($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X4E);
            goto L_8018CA54;
    }
    goto skip_7;
    // 0x8018C9F4: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
    skip_7:
    // 0x8018C9F8: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x8018C9FC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018CA00: addiu       $a1, $a1, -0x66BC
    ctx->r5 = ADD32(ctx->r5, -0X66BC);
    // 0x8018CA04: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8018CA08: bne         $t5, $zero, L_8018CA50
    if (ctx->r13 != 0) {
        // 0x8018CA0C: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018CA50;
    }
    // 0x8018CA0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CA10: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CA14: jal         0x80006970
    // 0x8018CA18: addiu       $a2, $sp, 0xFC
    ctx->r6 = ADD32(ctx->r29, 0XFC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_36;
    // 0x8018CA18: addiu       $a2, $sp, 0xFC
    ctx->r6 = ADD32(ctx->r29, 0XFC);
    after_36:
    // 0x8018CA1C: lwc1        $f18, 0xFC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8018CA20: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018CA24: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8018CA28: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018CA2C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018CA30: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8018CA34: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018CA38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018CA3C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018CA40: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018CA44: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018CA48: jal         0x8007D0E0
    // 0x8018CA4C: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_37;
    // 0x8018CA4C: nop

    after_37:
L_8018CA50:
    // 0x8018CA50: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
L_8018CA54:
    // 0x8018CA54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018CA58: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018CA5C: beq         $v0, $at, L_8018CA6C
    if (ctx->r2 == ctx->r1) {
        // 0x8018CA60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018CA6C;
    }
    // 0x8018CA60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018CA64: bnel        $v0, $at, L_8018CB60
    if (ctx->r2 != ctx->r1) {
        // 0x8018CA68: lh          $t8, 0x52($s2)
        ctx->r24 = MEM_H(ctx->r18, 0X52);
            goto L_8018CB60;
    }
    goto skip_8;
    // 0x8018CA68: lh          $t8, 0x52($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X52);
    skip_8:
L_8018CA6C:
    // 0x8018CA6C: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8018CA70: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018CA74: addiu       $a1, $a1, -0x66EC
    ctx->r5 = ADD32(ctx->r5, -0X66EC);
    // 0x8018CA78: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x8018CA7C: bne         $t6, $zero, L_8018CB5C
    if (ctx->r14 != 0) {
        // 0x8018CA80: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018CB5C;
    }
    // 0x8018CA80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CA84: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CA88: jal         0x80006970
    // 0x8018CA8C: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_38;
    // 0x8018CA8C: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    after_38:
    // 0x8018CA90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CA94: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018CA98: addiu       $a1, $a1, -0x66E0
    ctx->r5 = ADD32(ctx->r5, -0X66E0);
    // 0x8018CA9C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CAA0: jal         0x80006970
    // 0x8018CAA4: addiu       $a2, $sp, 0xD8
    ctx->r6 = ADD32(ctx->r29, 0XD8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_39;
    // 0x8018CAA4: addiu       $a2, $sp, 0xD8
    ctx->r6 = ADD32(ctx->r29, 0XD8);
    after_39:
    // 0x8018CAA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CAAC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018CAB0: addiu       $a1, $a1, -0x66D4
    ctx->r5 = ADD32(ctx->r5, -0X66D4);
    // 0x8018CAB4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CAB8: jal         0x80006970
    // 0x8018CABC: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_40;
    // 0x8018CABC: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    after_40:
    // 0x8018CAC0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018CAC4: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018CAC8: lwc1        $f16, 0xD4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8018CACC: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018CAD0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018CAD4: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018CAD8: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018CADC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018CAE0: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8018CAE4: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018CAE8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018CAEC: jal         0x8007BC7C
    // 0x8018CAF0: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_41;
    // 0x8018CAF0: nop

    after_41:
    // 0x8018CAF4: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8018CAF8: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018CAFC: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8018CB00: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018CB04: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018CB08: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8018CB0C: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018CB10: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018CB14: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018CB18: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018CB1C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018CB20: jal         0x8007BC7C
    // 0x8018CB24: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_42;
    // 0x8018CB24: nop

    after_42:
    // 0x8018CB28: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8018CB2C: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018CB30: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8018CB34: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018CB38: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018CB3C: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8018CB40: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018CB44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018CB48: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018CB4C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018CB50: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018CB54: jal         0x8007BC7C
    // 0x8018CB58: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_43;
    // 0x8018CB58: nop

    after_43:
L_8018CB5C:
    // 0x8018CB5C: lh          $t8, 0x52($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X52);
L_8018CB60:
    // 0x8018CB60: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018CB64: addiu       $a0, $a0, 0x79A8
    ctx->r4 = ADD32(ctx->r4, 0X79A8);
    // 0x8018CB68: beq         $t8, $zero, L_8018CB8C
    if (ctx->r24 == 0) {
        // 0x8018CB6C: lui         $a1, 0x4248
        ctx->r5 = S32(0X4248 << 16);
            goto L_8018CB8C;
    }
    // 0x8018CB6C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8018CB70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CB74: lwc1        $f10, -0x4F0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4F0C);
    // 0x8018CB78: lui         $a3, 0x3FCC
    ctx->r7 = S32(0X3FCC << 16);
    // 0x8018CB7C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8018CB80: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018CB84: jal         0x8009BC2C
    // 0x8018CB88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_44;
    // 0x8018CB88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_44:
L_8018CB8C:
    // 0x8018CB8C: lhu         $t9, 0x4E($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X4E);
    // 0x8018CB90: sltiu       $at, $t9, 0xB
    ctx->r1 = ctx->r25 < 0XB ? 1 : 0;
    // 0x8018CB94: beq         $at, $zero, L_8018DBB0
    if (ctx->r1 == 0) {
        // 0x8018CB98: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8018DBB0;
    }
    // 0x8018CB98: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018CB9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CBA0: addu        $at, $at, $t9
    gpr jr_addend_8018CBA8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8018CBA4: lw          $t9, -0x4F08($at)
    ctx->r25 = ADD32(ctx->r1, -0X4F08);
    // 0x8018CBA8: jr          $t9
    // 0x8018CBAC: nop

    switch (jr_addend_8018CBA8 >> 2) {
        case 0: goto L_8018CBB0; break;
        case 1: goto L_8018CCB8; break;
        case 2: goto L_8018CCEC; break;
        case 3: goto L_8018CD38; break;
        case 4: goto L_8018CDB8; break;
        case 5: goto L_8018CEE8; break;
        case 6: goto L_8018D1D8; break;
        case 7: goto L_8018D268; break;
        case 8: goto L_8018D6D8; break;
        case 9: goto L_8018D994; break;
        case 10: goto L_8018DB0C; break;
        default: switch_error(__func__, 0x8018CBA8, 0x8019B0F8);
    }
    // 0x8018CBAC: nop

L_8018CBB0:
    // 0x8018CBB0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018CBB4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8018CBB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CBBC: lwc1        $f18, -0x4EDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4EDC);
    // 0x8018CBC0: lwc1        $f16, 0x138($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X138);
    // 0x8018CBC4: lh          $v0, 0x50($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X50);
    // 0x8018CBC8: addiu       $s0, $zero, 0x15E
    ctx->r16 = ADD32(0, 0X15E);
    // 0x8018CBCC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018CBD0: bne         $s0, $v0, L_8018CC04
    if (ctx->r16 != ctx->r2) {
        // 0x8018CBD4: swc1        $f4, 0xE4($s2)
        MEM_W(0XE4, ctx->r18) = ctx->f4.u32l;
            goto L_8018CC04;
    }
    // 0x8018CBD4: swc1        $f4, 0xE4($s2)
    MEM_W(0XE4, ctx->r18) = ctx->f4.u32l;
    // 0x8018CBD8: lui         $a0, 0x1028
    ctx->r4 = S32(0X1028 << 16);
    // 0x8018CBDC: jal         0x800182F4
    // 0x8018CBE0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_45;
    // 0x8018CBE0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_45:
    // 0x8018CBE4: lui         $a0, 0x1128
    ctx->r4 = S32(0X1128 << 16);
    // 0x8018CBE8: jal         0x800182F4
    // 0x8018CBEC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_46;
    // 0x8018CBEC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_46:
    // 0x8018CBF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018CBF4: addiu       $a0, $a0, -0x4AB4
    ctx->r4 = ADD32(ctx->r4, -0X4AB4);
    // 0x8018CBF8: jal         0x800BA808
    // 0x8018CBFC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    Radio_PlayMessage(rdram, ctx);
        goto after_47;
    // 0x8018CBFC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_47:
    // 0x8018CC00: lh          $v0, 0x50($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X50);
L_8018CC04:
    // 0x8018CC04: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x8018CC08: bne         $v0, $at, L_8018CC24
    if (ctx->r2 != ctx->r1) {
        // 0x8018CC0C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018CC24;
    }
    // 0x8018CC0C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018CC10: addiu       $a0, $a0, -0x4964
    ctx->r4 = ADD32(ctx->r4, -0X4964);
    // 0x8018CC14: jal         0x800BA808
    // 0x8018CC18: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_48;
    // 0x8018CC18: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_48:
    // 0x8018CC1C: sh          $s0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r16;
    // 0x8018CC20: lh          $v0, 0x50($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X50);
L_8018CC24:
    // 0x8018CC24: bne         $v0, $zero, L_8018DBB0
    if (ctx->r2 != 0) {
        // 0x8018CC28: lui         $at, 0x4461
        ctx->r1 = S32(0X4461 << 16);
            goto L_8018DBB0;
    }
    // 0x8018CC28: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8018CC2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CC30: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018CC34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CC38: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018CC3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CC40: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8018CC44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CC48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018CC4C: sh          $t2, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r10;
    // 0x8018CC50: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8018CC54: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
    // 0x8018CC58: swc1        $f8, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f8.u32l;
    // 0x8018CC5C: swc1        $f10, 0x108($s2)
    MEM_W(0X108, ctx->r18) = ctx->f10.u32l;
    // 0x8018CC60: swc1        $f16, 0xF0($s2)
    MEM_W(0XF0, ctx->r18) = ctx->f16.u32l;
    // 0x8018CC64: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8018CC68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CC6C: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018CC70: lwc1        $f18, 0x48($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X48);
    // 0x8018CC74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CC78: lwc1        $f8, -0x4ED8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4ED8);
    // 0x8018CC7C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018CC80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018CC84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018CC88: ori         $a1, $zero, 0x8030
    ctx->r5 = 0 | 0X8030;
    // 0x8018CC8C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018CC90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018CC94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8018CC98: swc1        $f10, 0xE4($s2)
    MEM_W(0XE4, ctx->r18) = ctx->f10.u32l;
    // 0x8018CC9C: lwc1        $f16, 0x1A54($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x8018CCA0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8018CCA4: jal         0x8001D444
    // 0x8018CCA8: swc1        $f18, 0x120($s2)
    MEM_W(0X120, ctx->r18) = ctx->f18.u32l;
    Audio_PlaySequence(rdram, ctx);
        goto after_49;
    // 0x8018CCA8: swc1        $f18, 0x120($s2)
    MEM_W(0X120, ctx->r18) = ctx->f18.u32l;
    after_49:
    // 0x8018CCAC: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x8018CCB0: b           L_8018DBB0
    // 0x8018CCB4: sh          $t4, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r12;
        goto L_8018DBB0;
    // 0x8018CCB4: sh          $t4, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r12;
L_8018CCB8:
    // 0x8018CCB8: lh          $t5, 0x50($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X50);
    // 0x8018CCBC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018CCC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CCC4: bne         $t5, $zero, L_8018DBB0
    if (ctx->r13 != 0) {
        // 0x8018CCC8: nop
    
            goto L_8018DBB0;
    }
    // 0x8018CCC8: nop

    // 0x8018CCCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018CCD0: sh          $t7, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r15;
    // 0x8018CCD4: addiu       $t6, $zero, 0xFA
    ctx->r14 = ADD32(0, 0XFA);
    // 0x8018CCD8: swc1        $f4, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f4.u32l;
    // 0x8018CCDC: lwc1        $f6, -0x4ED4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4ED4);
    // 0x8018CCE0: sh          $t6, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r14;
    // 0x8018CCE4: b           L_8018DBB0
    // 0x8018CCE8: swc1        $f6, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f6.u32l;
        goto L_8018DBB0;
    // 0x8018CCE8: swc1        $f6, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f6.u32l;
L_8018CCEC:
    // 0x8018CCEC: lh          $t8, 0x50($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X50);
    // 0x8018CCF0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8018CCF4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8018CCF8: bne         $t8, $zero, L_8018DBB0
    if (ctx->r24 != 0) {
        // 0x8018CCFC: addiu       $t2, $zero, 0x4B
        ctx->r10 = ADD32(0, 0X4B);
            goto L_8018DBB0;
    }
    // 0x8018CCFC: addiu       $t2, $zero, 0x4B
    ctx->r10 = ADD32(0, 0X4B);
    // 0x8018CD00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018CD04: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018CD08: sh          $t9, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r25;
    // 0x8018CD0C: sh          $t1, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r9;
    // 0x8018CD10: sh          $t2, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r10;
    // 0x8018CD14: sh          $zero, 0x54($s2)
    MEM_H(0X54, ctx->r18) = 0;
    // 0x8018CD18: addiu       $a0, $a0, -0x4A78
    ctx->r4 = ADD32(ctx->r4, -0X4A78);
    // 0x8018CD1C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x8018CD20: jal         0x800BA808
    // 0x8018CD24: swc1        $f8, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f8.u32l;
    Radio_PlayMessage(rdram, ctx);
        goto after_50;
    // 0x8018CD24: swc1        $f8, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f8.u32l;
    after_50:
    // 0x8018CD28: lh          $t3, 0x90($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X90);
    // 0x8018CD2C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8018CD30: b           L_8018DBB0
    // 0x8018CD34: sh          $t4, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r12;
        goto L_8018DBB0;
    // 0x8018CD34: sh          $t4, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r12;
L_8018CD38:
    // 0x8018CD38: lh          $t5, 0x50($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X50);
    // 0x8018CD3C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018CD40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CD44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018CD48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018CD4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018CD50: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018CD54: swc1        $f10, 0x108($s2)
    MEM_W(0X108, ctx->r18) = ctx->f10.u32l;
    // 0x8018CD58: swc1        $f16, 0x104($s2)
    MEM_W(0X104, ctx->r18) = ctx->f16.u32l;
    // 0x8018CD5C: swc1        $f18, 0xFC($s2)
    MEM_W(0XFC, ctx->r18) = ctx->f18.u32l;
    // 0x8018CD60: swc1        $f4, 0x100($s2)
    MEM_W(0X100, ctx->r18) = ctx->f4.u32l;
    // 0x8018CD64: bne         $t5, $zero, L_8018DBB0
    if (ctx->r13 != 0) {
        // 0x8018CD68: swc1        $f6, 0x10C($s2)
        MEM_W(0X10C, ctx->r18) = ctx->f6.u32l;
            goto L_8018DBB0;
    }
    // 0x8018CD68: swc1        $f6, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f6.u32l;
    // 0x8018CD6C: lh          $t7, 0x88($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X88);
    // 0x8018CD70: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018CD74: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8018CD78: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018CD7C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8018CD80: sh          $t6, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r14;
    // 0x8018CD84: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8018CD88: addiu       $a3, $t8, 0x5D34
    ctx->r7 = ADD32(ctx->r24, 0X5D34);
    // 0x8018CD8C: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x8018CD90: sh          $t7, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r15;
    // 0x8018CD94: swc1        $f8, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f8.u32l;
    // 0x8018CD98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8018CD9C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018CDA0: ori         $a0, $a0, 0x201A
    ctx->r4 = ctx->r4 | 0X201A;
    // 0x8018CDA4: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018CDA8: jal         0x80019218
    // 0x8018CDAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_51;
    // 0x8018CDAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_51:
    // 0x8018CDB0: b           L_8018DBB0
    // 0x8018CDB4: nop

        goto L_8018DBB0;
    // 0x8018CDB4: nop

L_8018CDB8:
    // 0x8018CDB8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018CDBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018CDC0: lh          $t1, 0x50($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X50);
    // 0x8018CDC4: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x8018CDC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CDCC: swc1        $f0, 0x104($s2)
    MEM_W(0X104, ctx->r18) = ctx->f0.u32l;
    // 0x8018CDD0: beq         $t1, $zero, L_8018CDE8
    if (ctx->r9 == 0) {
        // 0x8018CDD4: swc1        $f10, 0x10C($s2)
        MEM_W(0X10C, ctx->r18) = ctx->f10.u32l;
            goto L_8018CDE8;
    }
    // 0x8018CDD4: swc1        $f10, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f10.u32l;
    // 0x8018CDD8: lh          $t2, 0x456($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X456);
    // 0x8018CDDC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018CDE0: beql        $t2, $zero, L_8018CE90
    if (ctx->r10 == 0) {
        // 0x8018CDE4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8018CE90;
    }
    goto skip_9;
    // 0x8018CDE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_9:
L_8018CDE8:
    // 0x8018CDE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018CDEC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8018CDF0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8018CDF4: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8018CDF8: sh          $t3, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r11;
    // 0x8018CDFC: sh          $t4, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r12;
    // 0x8018CE00: sh          $t5, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r13;
    // 0x8018CE04: swc1        $f16, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f16.u32l;
    // 0x8018CE08: lh          $t7, 0x456($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X456);
    // 0x8018CE0C: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x8018CE10: ori         $a0, $a0, 0x201A
    ctx->r4 = ctx->r4 | 0X201A;
    // 0x8018CE14: bne         $t7, $zero, L_8018CE3C
    if (ctx->r15 != 0) {
        // 0x8018CE18: addiu       $a1, $s2, 0x3FC
        ctx->r5 = ADD32(ctx->r18, 0X3FC);
            goto L_8018CE3C;
    }
    // 0x8018CE18: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018CE1C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018CE20: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018CE24: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018CE28: addiu       $a3, $t6, 0x5D34
    ctx->r7 = ADD32(ctx->r14, 0X5D34);
    // 0x8018CE2C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018CE30: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018CE34: jal         0x80019218
    // 0x8018CE38: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_52;
    // 0x8018CE38: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_52:
L_8018CE3C:
    // 0x8018CE3C: lh          $v0, 0x92($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X92);
    // 0x8018CE40: bnel        $v0, $zero, L_8018CE78
    if (ctx->r2 != 0) {
        // 0x8018CE44: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8018CE78;
    }
    goto skip_10;
    // 0x8018CE44: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_10:
    // 0x8018CE48: lh          $t9, 0x85E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X85E);
    // 0x8018CE4C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018CE50: addiu       $a0, $a0, -0x4A3C
    ctx->r4 = ADD32(ctx->r4, -0X4A3C);
    // 0x8018CE54: beq         $t9, $zero, L_8018CE68
    if (ctx->r25 == 0) {
        // 0x8018CE58: nop
    
            goto L_8018CE68;
    }
    // 0x8018CE58: nop

    // 0x8018CE5C: lh          $t1, 0xC66($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XC66);
    // 0x8018CE60: bnel        $t1, $zero, L_8018CE78
    if (ctx->r9 != 0) {
        // 0x8018CE64: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8018CE78;
    }
    goto skip_11;
    // 0x8018CE64: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_11:
L_8018CE68:
    // 0x8018CE68: jal         0x800BA808
    // 0x8018CE6C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    Radio_PlayMessage(rdram, ctx);
        goto after_53;
    // 0x8018CE6C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_53:
    // 0x8018CE70: lh          $v0, 0x92($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X92);
    // 0x8018CE74: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
L_8018CE78:
    // 0x8018CE78: sh          $t2, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r10;
    // 0x8018CE7C: lh          $t3, 0x92($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X92);
    // 0x8018CE80: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x8018CE84: b           L_8018DBB0
    // 0x8018CE88: sh          $t4, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r12;
        goto L_8018DBB0;
    // 0x8018CE88: sh          $t4, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r12;
    // 0x8018CE8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8018CE90:
    // 0x8018CE90: lwc1        $f4, 0xE0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XE0);
    // 0x8018CE94: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8018CE98: nop

    // 0x8018CE9C: bc1f        L_8018DBB0
    if (!c1cs) {
        // 0x8018CEA0: nop
    
            goto L_8018DBB0;
    }
    // 0x8018CEA0: nop

    // 0x8018CEA4: lh          $t5, 0x54($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X54);
    // 0x8018CEA8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018CEAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018CEB0: bne         $t5, $zero, L_8018DBB0
    if (ctx->r13 != 0) {
        // 0x8018CEB4: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_8018DBB0;
    }
    // 0x8018CEB4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018CEB8: sh          $t7, 0x54($s2)
    MEM_H(0X54, ctx->r18) = ctx->r15;
    // 0x8018CEBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CEC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018CEC4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8018CEC8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018CECC: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x8018CED0: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8018CED4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x8018CED8: jal         0x8018BDD4
    // 0x8018CEDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Corneria_CoCarrier_ChooseMissileTarget(rdram, ctx);
        goto after_54;
    // 0x8018CEDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_54:
    // 0x8018CEE0: b           L_8018DBB0
    // 0x8018CEE4: nop

        goto L_8018DBB0;
    // 0x8018CEE4: nop

L_8018CEE8:
    // 0x8018CEE8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018CEEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018CEF0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018CEF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CEF8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018CEFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CF00: lwc1        $f16, 0xD8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XD8);
    // 0x8018CF04: swc1        $f0, 0xFC($s2)
    MEM_W(0XFC, ctx->r18) = ctx->f0.u32l;
    // 0x8018CF08: swc1        $f0, 0x100($s2)
    MEM_W(0X100, ctx->r18) = ctx->f0.u32l;
    // 0x8018CF0C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8018CF10: swc1        $f8, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f8.u32l;
    // 0x8018CF14: bc1fl       L_8018CFDC
    if (!c1cs) {
        // 0x8018CF18: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8018CFDC;
    }
    goto skip_12;
    // 0x8018CF18: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_12:
    // 0x8018CF1C: lh          $t8, 0x85E($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X85E);
    // 0x8018CF20: bnel        $t8, $zero, L_8018CFDC
    if (ctx->r24 != 0) {
        // 0x8018CF24: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8018CFDC;
    }
    goto skip_13;
    // 0x8018CF24: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_13:
    // 0x8018CF28: lh          $t9, 0x8A($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X8A);
    // 0x8018CF2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018CF30: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x8018CF34: bne         $t9, $zero, L_8018CFD8
    if (ctx->r25 != 0) {
        // 0x8018CF38: lwc1        $f18, 0x94($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
            goto L_8018CFD8;
    }
    // 0x8018CF38: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018CF3C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018CF40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CF44: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018CF48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CF4C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018CF50: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x8018CF54: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018CF58: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018CF5C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018CF60: addiu       $s0, $s2, 0x3FC
    ctx->r16 = ADD32(ctx->r18, 0X3FC);
    // 0x8018CF64: jal         0x8018BDD4
    // 0x8018CF68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Corneria_CoCarrier_ChooseMissileTarget(rdram, ctx);
        goto after_55;
    // 0x8018CF68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_55:
    // 0x8018CF6C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018CF70: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018CF74: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018CF78: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018CF7C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018CF80: ori         $a0, $a0, 0x201B
    ctx->r4 = ctx->r4 | 0X201B;
    // 0x8018CF84: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018CF88: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018CF8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018CF90: jal         0x80019218
    // 0x8018CF94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_56;
    // 0x8018CF94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_56:
    // 0x8018CF98: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018CF9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CFA0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018CFA4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018CFA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CFAC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018CFB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018CFB4: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x8018CFB8: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x8018CFBC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018CFC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018CFC4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018CFC8: jal         0x8018BDD4
    // 0x8018CFCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Corneria_CoCarrier_ChooseMissileTarget(rdram, ctx);
        goto after_57;
    // 0x8018CFCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_57:
    // 0x8018CFD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018CFD4: sh          $t2, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = ctx->r10;
L_8018CFD8:
    // 0x8018CFD8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_8018CFDC:
    // 0x8018CFDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CFE0: lwc1        $f8, 0xDC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XDC);
    // 0x8018CFE4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8018CFE8: nop

    // 0x8018CFEC: bc1fl       L_8018D0B4
    if (!c1cs) {
        // 0x8018CFF0: lh          $t6, 0x50($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X50);
            goto L_8018D0B4;
    }
    goto skip_14;
    // 0x8018CFF0: lh          $t6, 0x50($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X50);
    skip_14:
    // 0x8018CFF4: lh          $t3, 0xC66($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XC66);
    // 0x8018CFF8: bnel        $t3, $zero, L_8018D0B4
    if (ctx->r11 != 0) {
        // 0x8018CFFC: lh          $t6, 0x50($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X50);
            goto L_8018D0B4;
    }
    goto skip_15;
    // 0x8018CFFC: lh          $t6, 0x50($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X50);
    skip_15:
    // 0x8018D000: lh          $t4, 0x8C($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X8C);
    // 0x8018D004: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018D008: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8018D00C: bne         $t4, $zero, L_8018D0B0
    if (ctx->r12 != 0) {
        // 0x8018D010: lwc1        $f10, 0xA0($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
            goto L_8018D0B0;
    }
    // 0x8018D010: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8018D014: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018D018: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D01C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8018D020: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D024: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D028: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8018D02C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018D030: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018D034: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018D038: addiu       $s0, $s2, 0x3FC
    ctx->r16 = ADD32(ctx->r18, 0X3FC);
    // 0x8018D03C: jal         0x8018BDD4
    // 0x8018D040: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Corneria_CoCarrier_ChooseMissileTarget(rdram, ctx);
        goto after_58;
    // 0x8018D040: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_58:
    // 0x8018D044: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018D048: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8018D04C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018D050: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8018D054: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018D058: ori         $a0, $a0, 0x201B
    ctx->r4 = ctx->r4 | 0X201B;
    // 0x8018D05C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8018D060: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018D064: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D068: jal         0x80019218
    // 0x8018D06C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_59;
    // 0x8018D06C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_59:
    // 0x8018D070: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018D074: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D078: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8018D07C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018D080: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D084: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018D088: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018D08C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8018D090: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8018D094: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018D098: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018D09C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018D0A0: jal         0x8018BDD4
    // 0x8018D0A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Corneria_CoCarrier_ChooseMissileTarget(rdram, ctx);
        goto after_60;
    // 0x8018D0A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_60:
    // 0x8018D0A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D0AC: sh          $t7, 0x8C($s2)
    MEM_H(0X8C, ctx->r18) = ctx->r15;
L_8018D0B0:
    // 0x8018D0B0: lh          $t6, 0x50($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X50);
L_8018D0B4:
    // 0x8018D0B4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8018D0B8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8018D0BC: beq         $t6, $zero, L_8018D0DC
    if (ctx->r14 == 0) {
        // 0x8018D0C0: addiu       $t3, $zero, 0x46
        ctx->r11 = ADD32(0, 0X46);
            goto L_8018D0DC;
    }
    // 0x8018D0C0: addiu       $t3, $zero, 0x46
    ctx->r11 = ADD32(0, 0X46);
    // 0x8018D0C4: lh          $t8, 0xC66($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC66);
    // 0x8018D0C8: beq         $t8, $zero, L_8018DBB0
    if (ctx->r24 == 0) {
        // 0x8018D0CC: nop
    
            goto L_8018DBB0;
    }
    // 0x8018D0CC: nop

    // 0x8018D0D0: lh          $t9, 0x85E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X85E);
    // 0x8018D0D4: beq         $t9, $zero, L_8018DBB0
    if (ctx->r25 == 0) {
        // 0x8018D0D8: nop
    
            goto L_8018DBB0;
    }
    // 0x8018D0D8: nop

L_8018D0DC:
    // 0x8018D0DC: lh          $v0, 0x90($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X90);
    // 0x8018D0E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018D0E4: sh          $t1, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r9;
    // 0x8018D0E8: sh          $t2, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r10;
    // 0x8018D0EC: sh          $t3, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r11;
    // 0x8018D0F0: sh          $zero, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = 0;
    // 0x8018D0F4: sh          $zero, 0x8C($s2)
    MEM_H(0X8C, ctx->r18) = 0;
    // 0x8018D0F8: bne         $v0, $zero, L_8018D120
    if (ctx->r2 != 0) {
        // 0x8018D0FC: swc1        $f18, 0xF8($s2)
        MEM_W(0XF8, ctx->r18) = ctx->f18.u32l;
            goto L_8018D120;
    }
    // 0x8018D0FC: swc1        $f18, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f18.u32l;
    // 0x8018D100: lh          $t4, 0x456($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X456);
    // 0x8018D104: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D108: addiu       $a0, $a0, -0x4A78
    ctx->r4 = ADD32(ctx->r4, -0X4A78);
    // 0x8018D10C: bnel        $t4, $zero, L_8018D124
    if (ctx->r12 != 0) {
        // 0x8018D110: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018D124;
    }
    goto skip_16;
    // 0x8018D110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_16:
    // 0x8018D114: jal         0x800BA808
    // 0x8018D118: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    Radio_PlayMessage(rdram, ctx);
        goto after_61;
    // 0x8018D118: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_61:
    // 0x8018D11C: lh          $v0, 0x90($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X90);
L_8018D120:
    // 0x8018D120: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8018D124:
    // 0x8018D124: bnel        $v0, $at, L_8018D180
    if (ctx->r2 != ctx->r1) {
        // 0x8018D128: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8018D180;
    }
    goto skip_17;
    // 0x8018D128: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_17:
    // 0x8018D12C: lh          $t5, 0x96($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X96);
    // 0x8018D130: bnel        $t5, $zero, L_8018D180
    if (ctx->r13 != 0) {
        // 0x8018D134: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8018D180;
    }
    goto skip_18;
    // 0x8018D134: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_18:
    // 0x8018D138: lh          $t7, 0xC66($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC66);
    // 0x8018D13C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D140: addiu       $a0, $a0, -0x4904
    ctx->r4 = ADD32(ctx->r4, -0X4904);
    // 0x8018D144: beq         $t7, $zero, L_8018D164
    if (ctx->r15 == 0) {
        // 0x8018D148: nop
    
            goto L_8018D164;
    }
    // 0x8018D148: nop

    // 0x8018D14C: lh          $t6, 0x85E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X85E);
    // 0x8018D150: beq         $t6, $zero, L_8018D164
    if (ctx->r14 == 0) {
        // 0x8018D154: nop
    
            goto L_8018D164;
    }
    // 0x8018D154: nop

    // 0x8018D158: lh          $t8, 0x456($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X456);
    // 0x8018D15C: bnel        $t8, $zero, L_8018D180
    if (ctx->r24 != 0) {
        // 0x8018D160: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8018D180;
    }
    goto skip_19;
    // 0x8018D160: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_19:
L_8018D164:
    // 0x8018D164: jal         0x800BA808
    // 0x8018D168: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_62;
    // 0x8018D168: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_62:
    // 0x8018D16C: lh          $t9, 0x96($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X96);
    // 0x8018D170: lh          $v0, 0x90($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X90);
    // 0x8018D174: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8018D178: sh          $t1, 0x96($s2)
    MEM_H(0X96, ctx->r18) = ctx->r9;
    // 0x8018D17C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
L_8018D180:
    // 0x8018D180: sh          $t2, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r10;
    // 0x8018D184: lh          $t3, 0x90($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X90);
    // 0x8018D188: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x8018D18C: sh          $t4, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r12;
    // 0x8018D190: lh          $t5, 0xC66($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XC66);
    // 0x8018D194: bne         $t5, $zero, L_8018DBB0
    if (ctx->r13 != 0) {
        // 0x8018D198: nop
    
            goto L_8018DBB0;
    }
    // 0x8018D198: nop

    // 0x8018D19C: lh          $t7, 0x85E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X85E);
    // 0x8018D1A0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018D1A4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018D1A8: bne         $t7, $zero, L_8018DBB0
    if (ctx->r15 != 0) {
        // 0x8018D1AC: lui         $a0, 0x2940
        ctx->r4 = S32(0X2940 << 16);
            goto L_8018DBB0;
    }
    // 0x8018D1AC: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x8018D1B0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018D1B4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018D1B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018D1BC: ori         $a0, $a0, 0x201A
    ctx->r4 = ctx->r4 | 0X201A;
    // 0x8018D1C0: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018D1C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018D1C8: jal         0x80019218
    // 0x8018D1CC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_63;
    // 0x8018D1CC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_63:
    // 0x8018D1D0: b           L_8018DBB0
    // 0x8018D1D4: nop

        goto L_8018DBB0;
    // 0x8018D1D4: nop

L_8018D1D8:
    // 0x8018D1D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D1DC: lwc1        $f4, -0x4ED0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4ED0);
    // 0x8018D1E0: lw          $a1, 0x10C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10C);
    // 0x8018D1E4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D1E8: addiu       $t8, $s2, 0x18
    ctx->r24 = ADD32(ctx->r18, 0X18);
    // 0x8018D1EC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8018D1F0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D1F4: addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // 0x8018D1F8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018D1FC: jal         0x8009BD38
    // 0x8018D200: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_64;
    // 0x8018D200: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_64:
    // 0x8018D204: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D208: lwc1        $f6, -0x4ECC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4ECC);
    // 0x8018D20C: lw          $a1, 0x110($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X110);
    // 0x8018D210: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D214: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D218: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D21C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018D220: jal         0x8009BD38
    // 0x8018D224: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_65;
    // 0x8018D224: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_65:
    // 0x8018D228: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018D22C: lwc1        $f10, 0x14($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8018D230: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8018D234: nop

    // 0x8018D238: bc1tl       L_8018D250
    if (c1cs) {
        // 0x8018D23C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8018D250;
    }
    goto skip_20;
    // 0x8018D23C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_20:
    // 0x8018D240: lh          $t9, 0x58($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X58);
    // 0x8018D244: bne         $t9, $zero, L_8018DBB0
    if (ctx->r25 != 0) {
        // 0x8018D248: nop
    
            goto L_8018DBB0;
    }
    // 0x8018D248: nop

    // 0x8018D24C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8018D250:
    // 0x8018D250: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018D254: sh          $zero, 0x58($s2)
    MEM_H(0X58, ctx->r18) = 0;
    // 0x8018D258: sh          $s0, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r16;
    // 0x8018D25C: swc1        $f16, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f16.u32l;
    // 0x8018D260: b           L_8018DBB0
    // 0x8018D264: swc1        $f18, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f18.u32l;
        goto L_8018DBB0;
    // 0x8018D264: swc1        $f18, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f18.u32l;
L_8018D268:
    // 0x8018D268: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018D26C: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8018D270: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D274: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018D278: lwc1        $f4, 0x48($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X48);
    // 0x8018D27C: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8018D280: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D284: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D288: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D28C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D290: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D294: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018D298: addiu       $a0, $s2, 0xC
    ctx->r4 = ADD32(ctx->r18, 0XC);
    // 0x8018D29C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8018D2A0: swc1        $f16, 0xE4($s2)
    MEM_W(0XE4, ctx->r18) = ctx->f16.u32l;
    // 0x8018D2A4: lwc1        $f18, -0x4EC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4EC8);
    // 0x8018D2A8: lw          $a1, 0xE4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XE4);
    // 0x8018D2AC: jal         0x8009BC2C
    // 0x8018D2B0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_66;
    // 0x8018D2B0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_66:
    // 0x8018D2B4: lh          $t2, 0x58($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X58);
    // 0x8018D2B8: bnel        $t2, $zero, L_8018D330
    if (ctx->r10 != 0) {
        // 0x8018D2BC: lh          $v0, 0x8E($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X8E);
            goto L_8018D330;
    }
    goto skip_21;
    // 0x8018D2BC: lh          $v0, 0x8E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8E);
    skip_21:
    // 0x8018D2C0: lh          $v0, 0x8E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8E);
    // 0x8018D2C4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8018D2C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D2CC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8018D2D0: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8018D2D4: lw          $t3, -0x65B4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X65B4);
    // 0x8018D2D8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8018D2DC: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8018D2E0: sh          $t3, 0x58($s2)
    MEM_H(0X58, ctx->r18) = ctx->r11;
    // 0x8018D2E4: lwc1        $f4, -0x65A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X65A4);
    // 0x8018D2E8: sh          $t4, 0x8E($s2)
    MEM_H(0X8E, ctx->r18) = ctx->r12;
    // 0x8018D2EC: lh          $t5, 0x8E($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X8E);
    // 0x8018D2F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018D2F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D2F8: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x8018D2FC: sh          $t7, 0x8E($s2)
    MEM_H(0X8E, ctx->r18) = ctx->r15;
    // 0x8018D300: lh          $v0, 0x8E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8E);
    // 0x8018D304: addiu       $a0, $s2, 0x3FC
    ctx->r4 = ADD32(ctx->r18, 0X3FC);
    // 0x8018D308: swc1        $f4, 0x128($s2)
    MEM_W(0X128, ctx->r18) = ctx->f4.u32l;
    // 0x8018D30C: bne         $v0, $at, L_8018D31C
    if (ctx->r2 != ctx->r1) {
        // 0x8018D310: swc1        $f6, 0xF8($s2)
        MEM_W(0XF8, ctx->r18) = ctx->f6.u32l;
            goto L_8018D31C;
    }
    // 0x8018D310: swc1        $f6, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f6.u32l;
    // 0x8018D314: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018D318: beq         $v0, $at, L_8018D32C
    if (ctx->r2 == ctx->r1) {
        // 0x8018D31C: lui         $a1, 0x3103
        ctx->r5 = S32(0X3103 << 16);
            goto L_8018D32C;
    }
L_8018D31C:
    // 0x8018D31C: lui         $a1, 0x3103
    ctx->r5 = S32(0X3103 << 16);
    // 0x8018D320: jal         0x8001A55C
    // 0x8018D324: ori         $a1, $a1, 0x4025
    ctx->r5 = ctx->r5 | 0X4025;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_67;
    // 0x8018D324: ori         $a1, $a1, 0x4025
    ctx->r5 = ctx->r5 | 0X4025;
    after_67:
    // 0x8018D328: sh          $zero, 0x9A($s2)
    MEM_H(0X9A, ctx->r18) = 0;
L_8018D32C:
    // 0x8018D32C: lh          $v0, 0x8E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8E);
L_8018D330:
    // 0x8018D330: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018D334: beql        $v0, $zero, L_8018D344
    if (ctx->r2 == 0) {
        // 0x8018D338: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8018D344;
    }
    goto skip_22;
    // 0x8018D338: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_22:
    // 0x8018D33C: bne         $v0, $at, L_8018D500
    if (ctx->r2 != ctx->r1) {
        // 0x8018D340: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8018D500;
    }
    // 0x8018D340: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8018D344:
    // 0x8018D344: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D348: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8018D34C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8018D350: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8018D354: nop

    // 0x8018D358: bc1fl       L_8018D504
    if (!c1cs) {
        // 0x8018D35C: lh          $t2, 0x60($s2)
        ctx->r10 = MEM_H(ctx->r18, 0X60);
            goto L_8018D504;
    }
    goto skip_23;
    // 0x8018D35C: lh          $t2, 0x60($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X60);
    skip_23:
    // 0x8018D360: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D364: nop

    // 0x8018D368: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8018D36C: nop

    // 0x8018D370: bc1fl       L_8018D504
    if (!c1cs) {
        // 0x8018D374: lh          $t2, 0x60($s2)
        ctx->r10 = MEM_H(ctx->r18, 0X60);
            goto L_8018D504;
    }
    goto skip_24;
    // 0x8018D374: lh          $t2, 0x60($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X60);
    skip_24:
    // 0x8018D378: lh          $v0, 0x9A($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X9A);
    // 0x8018D37C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018D380: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018D384: bne         $v0, $zero, L_8018D3E8
    if (ctx->r2 != 0) {
        // 0x8018D388: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8018D3E8;
    }
    // 0x8018D388: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8018D38C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018D390: sh          $t6, 0x9A($s2)
    MEM_H(0X9A, ctx->r18) = ctx->r14;
    // 0x8018D394: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018D398: lui         $a0, 0x3103
    ctx->r4 = S32(0X3103 << 16);
    // 0x8018D39C: ori         $a0, $a0, 0x4025
    ctx->r4 = ctx->r4 | 0X4025;
    // 0x8018D3A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018D3A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018D3A8: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018D3AC: jal         0x80019218
    // 0x8018D3B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_68;
    // 0x8018D3B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_68:
    // 0x8018D3B4: lh          $v0, 0x94($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X94);
    // 0x8018D3B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D3BC: addiu       $a0, $a0, -0x4A00
    ctx->r4 = ADD32(ctx->r4, -0X4A00);
    // 0x8018D3C0: bnel        $v0, $zero, L_8018D3D8
    if (ctx->r2 != 0) {
        // 0x8018D3C4: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_8018D3D8;
    }
    goto skip_25;
    // 0x8018D3C4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    skip_25:
    // 0x8018D3C8: jal         0x800BA808
    // 0x8018D3CC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    Radio_PlayMessage(rdram, ctx);
        goto after_69;
    // 0x8018D3CC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_69:
    // 0x8018D3D0: lh          $v0, 0x94($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X94);
    // 0x8018D3D4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
L_8018D3D8:
    // 0x8018D3D8: sh          $t9, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r25;
    // 0x8018D3DC: lh          $t1, 0x94($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X94);
    // 0x8018D3E0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8018D3E4: sh          $t2, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r10;
L_8018D3E8:
    // 0x8018D3E8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018D3EC: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x8018D3F0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8018D3F4: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x8018D3F8: bnel        $t4, $zero, L_8018D504
    if (ctx->r12 != 0) {
        // 0x8018D3FC: lh          $t2, 0x60($s2)
        ctx->r10 = MEM_H(ctx->r18, 0X60);
            goto L_8018D504;
    }
    goto skip_26;
    // 0x8018D3FC: lh          $t2, 0x60($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X60);
    skip_26:
    // 0x8018D400: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8018D404: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018D408: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8018D40C: lwc1        $f18, 0x138($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X138);
    // 0x8018D410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D414: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018D418: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8018D41C: addiu       $a1, $a1, -0x6710
    ctx->r5 = ADD32(ctx->r5, -0X6710);
    // 0x8018D420: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D424: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x8018D428: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018D42C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D430: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8018D434: nop

    // 0x8018D438: bc1fl       L_8018D504
    if (!c1cs) {
        // 0x8018D43C: lh          $t2, 0x60($s2)
        ctx->r10 = MEM_H(ctx->r18, 0X60);
            goto L_8018D504;
    }
    goto skip_27;
    // 0x8018D43C: lh          $t2, 0x60($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X60);
    skip_27:
    // 0x8018D440: jal         0x80006970
    // 0x8018D444: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_70;
    // 0x8018D444: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_70:
    // 0x8018D448: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8018D44C: addiu       $s0, $s0, 0x130
    ctx->r16 = ADD32(ctx->r16, 0X130);
    // 0x8018D450: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_8018D454:
    // 0x8018D454: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8018D458: bnel        $t7, $zero, L_8018D4E8
    if (ctx->r15 != 0) {
        // 0x8018D45C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D4E8;
    }
    goto skip_28;
    // 0x8018D45C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_28:
    // 0x8018D460: jal         0x80061474
    // 0x8018D464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_71;
    // 0x8018D464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x8018D468: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D46C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D470: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018D474: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D478: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D47C: addiu       $t8, $zero, 0x18E
    ctx->r24 = ADD32(0, 0X18E);
    // 0x8018D480: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018D484: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D488: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8018D48C: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8018D490: sh          $t9, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r25;
    // 0x8018D494: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
    // 0x8018D498: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x8018D49C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8018D4A0: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018D4A4: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8018D4A8: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x8018D4AC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018D4B0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D4B4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D4B8: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018D4BC: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8018D4C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D4C4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8018D4C8: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018D4CC: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8018D4D0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D4D4: jal         0x800612B8
    // 0x8018D4D8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_72;
    // 0x8018D4D8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_72:
    // 0x8018D4DC: b           L_8018D4F4
    // 0x8018D4E0: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
        goto L_8018D4F4;
    // 0x8018D4E0: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
    // 0x8018D4E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D4E8:
    // 0x8018D4E8: bne         $s1, $v0, L_8018D454
    if (ctx->r17 != ctx->r2) {
        // 0x8018D4EC: addiu       $s0, $s0, 0x8C
        ctx->r16 = ADD32(ctx->r16, 0X8C);
            goto L_8018D454;
    }
    // 0x8018D4EC: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
    // 0x8018D4F0: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
L_8018D4F4:
    // 0x8018D4F4: bnel        $at, $zero, L_8018D504
    if (ctx->r1 != 0) {
        // 0x8018D4F8: lh          $t2, 0x60($s2)
        ctx->r10 = MEM_H(ctx->r18, 0X60);
            goto L_8018D504;
    }
    goto skip_29;
    // 0x8018D4F8: lh          $t2, 0x60($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X60);
    skip_29:
    // 0x8018D4FC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8018D500:
    // 0x8018D500: lh          $t2, 0x60($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X60);
L_8018D504:
    // 0x8018D504: addiu       $a0, $s2, 0xF8
    ctx->r4 = ADD32(ctx->r18, 0XF8);
    // 0x8018D508: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x8018D50C: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8018D510: beq         $at, $zero, L_8018D5C8
    if (ctx->r1 == 0) {
        // 0x8018D514: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_8018D5C8;
    }
    // 0x8018D514: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D518: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8018D51C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D520: addiu       $s0, $s2, 0x3FC
    ctx->r16 = ADD32(ctx->r18, 0X3FC);
    // 0x8018D524: lui         $a1, 0x3103
    ctx->r5 = S32(0X3103 << 16);
    // 0x8018D528: sw          $t3, 0x796C($at)
    MEM_W(0X796C, ctx->r1) = ctx->r11;
    // 0x8018D52C: ori         $a1, $a1, 0x4025
    ctx->r5 = ctx->r5 | 0X4025;
    // 0x8018D530: jal         0x8001A55C
    // 0x8018D534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_73;
    // 0x8018D534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x8018D538: lui         $a0, 0x1028
    ctx->r4 = S32(0X1028 << 16);
    // 0x8018D53C: jal         0x800182F4
    // 0x8018D540: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_74;
    // 0x8018D540: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_74:
    // 0x8018D544: lui         $a0, 0x1128
    ctx->r4 = S32(0X1128 << 16);
    // 0x8018D548: jal         0x800182F4
    // 0x8018D54C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_75;
    // 0x8018D54C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_75:
    // 0x8018D550: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018D554: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8018D558: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018D55C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8018D560: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x8018D564: ori         $a0, $a0, 0xD09A
    ctx->r4 = ctx->r4 | 0XD09A;
    // 0x8018D568: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018D56C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018D570: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D574: jal         0x80019218
    // 0x8018D578: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_76;
    // 0x8018D578: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_76:
    // 0x8018D57C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8018D580: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D584: sh          $t5, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r13;
    // 0x8018D588: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D58C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D590: sw          $zero, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = 0;
    // 0x8018D594: addiu       $a0, $a0, -0x49F0
    ctx->r4 = ADD32(ctx->r4, -0X49F0);
    // 0x8018D598: jal         0x800BA808
    // 0x8018D59C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    Radio_PlayMessage(rdram, ctx);
        goto after_77;
    // 0x8018D59C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_77:
    // 0x8018D5A0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D5A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D5A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D5AC: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x8018D5B0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8018D5B4: sh          $t7, 0x60($s2)
    MEM_H(0X60, ctx->r18) = ctx->r15;
    // 0x8018D5B8: sh          $t6, 0x56($s2)
    MEM_H(0X56, ctx->r18) = ctx->r14;
    // 0x8018D5BC: sh          $t8, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r24;
    // 0x8018D5C0: b           L_8018DBB0
    // 0x8018D5C4: swc1        $f4, 0x124($s2)
    MEM_W(0X124, ctx->r18) = ctx->f4.u32l;
        goto L_8018DBB0;
    // 0x8018D5C4: swc1        $f4, 0x124($s2)
    MEM_W(0X124, ctx->r18) = ctx->f4.u32l;
L_8018D5C8:
    // 0x8018D5C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D5CC: lwc1        $f6, -0x4EC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4EC4);
    // 0x8018D5D0: addiu       $t9, $s2, 0x18
    ctx->r25 = ADD32(ctx->r18, 0X18);
    // 0x8018D5D4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8018D5D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D5DC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8018D5E0: addiu       $s0, $s2, 0x14
    ctx->r16 = ADD32(ctx->r18, 0X14);
    // 0x8018D5E4: jal         0x8009BC2C
    // 0x8018D5E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_78;
    // 0x8018D5E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_78:
    // 0x8018D5EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D5F0: lwc1        $f8, -0x4EC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4EC0);
    // 0x8018D5F4: lw          $a1, 0x110($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X110);
    // 0x8018D5F8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D5FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D600: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D604: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018D608: jal         0x8009BD38
    // 0x8018D60C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_79;
    // 0x8018D60C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_79:
    // 0x8018D610: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D614: lwc1        $f10, -0x4EBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4EBC);
    // 0x8018D618: lw          $a1, 0x128($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X128);
    // 0x8018D61C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D620: lw          $a3, 0xF8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XF8);
    // 0x8018D624: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D62C: jal         0x8009BC2C
    // 0x8018D630: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_80;
    // 0x8018D630: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_80:
    // 0x8018D634: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018D638: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D63C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018D640: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018D644: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8018D648: swc1        $f16, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f16.u32l;
    // 0x8018D64C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018D650: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D654: bc1f        L_8018D66C
    if (!c1cs) {
        // 0x8018D658: addiu       $a1, $sp, 0x78
        ctx->r5 = ADD32(ctx->r29, 0X78);
            goto L_8018D66C;
    }
    // 0x8018D658: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8018D65C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8018D660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D664: nop

    // 0x8018D668: swc1        $f4, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f4.u32l;
L_8018D66C:
    // 0x8018D66C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D674: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D678: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8018D67C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8018D680: nop

    // 0x8018D684: bc1fl       L_8018D698
    if (!c1cs) {
        // 0x8018D688: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8018D698;
    }
    goto skip_30;
    // 0x8018D688: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    skip_30:
    // 0x8018D68C: lwc1        $f8, -0x4EB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4EB8);
    // 0x8018D690: swc1        $f8, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f8.u32l;
    // 0x8018D694: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_8018D698:
    // 0x8018D698: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D69C: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x8018D6A0: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x8018D6A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D6A8: jal         0x80006970
    // 0x8018D6AC: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_81;
    // 0x8018D6AC: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    after_81:
    // 0x8018D6B0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018D6B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D6B8: swc1        $f4, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D6BC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8018D6C0: swc1        $f6, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f6.u32l;
    // 0x8018D6C4: lwc1        $f10, 0x7D08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8018D6C8: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018D6CC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018D6D0: b           L_8018DBB0
    // 0x8018D6D4: swc1        $f16, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f16.u32l;
        goto L_8018DBB0;
    // 0x8018D6D4: swc1        $f16, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f16.u32l;
L_8018D6D8:
    // 0x8018D6D8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018D6DC: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8018D6E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018D6E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D6E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D6EC: addiu       $t1, $s2, 0x18
    ctx->r9 = ADD32(ctx->r18, 0X18);
    // 0x8018D6F0: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x8018D6F4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018D6F8: bne         $t3, $zero, L_8018D74C
    if (ctx->r11 != 0) {
        // 0x8018D6FC: swc1        $f18, 0x79A8($at)
        MEM_W(0X79A8, ctx->r1) = ctx->f18.u32l;
            goto L_8018D74C;
    }
    // 0x8018D6FC: swc1        $f18, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f18.u32l;
    // 0x8018D700: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D704: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
L_8018D708:
    // 0x8018D708: jal         0x80004EB0
    // 0x8018D70C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_82;
    // 0x8018D70C: nop

    after_82:
    // 0x8018D710: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018D714: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D718: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018D71C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D720: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018D724: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018D728: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018D72C: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x8018D730: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018D734: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018D738: jal         0x80079618
    // 0x8018D73C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_effect_80079618(rdram, ctx);
        goto after_83;
    // 0x8018D73C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_83:
    // 0x8018D740: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018D744: bne         $s1, $s0, L_8018D708
    if (ctx->r17 != ctx->r16) {
        // 0x8018D748: nop
    
            goto L_8018D708;
    }
    // 0x8018D748: nop

L_8018D74C:
    // 0x8018D74C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D750: lwc1        $f18, -0x4EB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4EB4);
    // 0x8018D754: lw          $a1, 0xF4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XF4);
    // 0x8018D758: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x8018D75C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018D760: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018D764: jal         0x8009BC2C
    // 0x8018D768: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_84;
    // 0x8018D768: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_84:
    // 0x8018D76C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D770: lwc1        $f4, -0x4EB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4EB0);
    // 0x8018D774: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D778: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D77C: addiu       $a0, $s2, 0x6C
    ctx->r4 = ADD32(ctx->r18, 0X6C);
    // 0x8018D780: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018D784: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018D788: jal         0x8009BC2C
    // 0x8018D78C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_85;
    // 0x8018D78C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_85:
    // 0x8018D790: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D794: lwc1        $f6, -0x4EAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4EAC);
    // 0x8018D798: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D79C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D7A0: addiu       $a0, $s2, 0x70
    ctx->r4 = ADD32(ctx->r18, 0X70);
    // 0x8018D7A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018D7A8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018D7AC: jal         0x8009BC2C
    // 0x8018D7B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_86;
    // 0x8018D7B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_86:
    // 0x8018D7B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D7B8: lwc1        $f8, -0x4EA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4EA8);
    // 0x8018D7BC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D7C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D7C4: addiu       $a0, $s2, 0x74
    ctx->r4 = ADD32(ctx->r18, 0X74);
    // 0x8018D7C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018D7CC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018D7D0: jal         0x8009BC2C
    // 0x8018D7D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_87;
    // 0x8018D7D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_87:
    // 0x8018D7D8: lwc1        $f2, 0x110($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X110);
    // 0x8018D7DC: lwc1        $f10, 0x18($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8018D7E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018D7E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018D7E8: c.eq.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl == ctx->f2.fl;
    // 0x8018D7EC: nop

    // 0x8018D7F0: bc1f        L_8018D830
    if (!c1cs) {
        // 0x8018D7F4: nop
    
            goto L_8018D830;
    }
    // 0x8018D7F4: nop

    // 0x8018D7F8: lwc1        $f0, 0x124($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X124);
    // 0x8018D7FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018D800: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8018D804: nop

    // 0x8018D808: bc1fl       L_8018D82C
    if (!c1cs) {
        // 0x8018D80C: swc1        $f0, 0x110($s2)
        MEM_W(0X110, ctx->r18) = ctx->f0.u32l;
            goto L_8018D82C;
    }
    goto skip_31;
    // 0x8018D80C: swc1        $f0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f0.u32l;
    skip_31:
    // 0x8018D810: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D814: nop

    // 0x8018D818: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8018D81C: swc1        $f18, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f18.u32l;
    // 0x8018D820: b           L_8018D830
    // 0x8018D824: lwc1        $f2, 0x110($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X110);
        goto L_8018D830;
    // 0x8018D824: lwc1        $f2, 0x110($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X110);
    // 0x8018D828: swc1        $f0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f0.u32l;
L_8018D82C:
    // 0x8018D82C: lwc1        $f2, 0x110($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X110);
L_8018D830:
    // 0x8018D830: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D834: lwc1        $f4, -0x4EA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4EA4);
    // 0x8018D838: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018D83C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D840: jal         0x8009BD38
    // 0x8018D844: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_88;
    // 0x8018D844: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_88:
    // 0x8018D848: lh          $t4, 0x60($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X60);
    // 0x8018D84C: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8018D850: beq         $t4, $zero, L_8018D98C
    if (ctx->r12 == 0) {
        // 0x8018D854: nop
    
            goto L_8018D98C;
    }
    // 0x8018D854: nop

    // 0x8018D858: lh          $t5, 0x56($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X56);
    // 0x8018D85C: addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // 0x8018D860: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018D864: bne         $t5, $zero, L_8018D8FC
    if (ctx->r13 != 0) {
        // 0x8018D868: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_8018D8FC;
    }
    // 0x8018D868: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018D86C: jal         0x80042EC0
    // 0x8018D870: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Boss_AwardBonus(rdram, ctx);
        goto after_89;
    // 0x8018D870: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_89:
    // 0x8018D874: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018D878: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D87C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018D880: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D884: lwc1        $f8, 0x70($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X70);
    // 0x8018D888: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D88C: swc1        $f6, 0x11C($s2)
    MEM_W(0X11C, ctx->r18) = ctx->f6.u32l;
    // 0x8018D890: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018D894: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D898: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D89C: swc1        $f16, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f16.u32l;
    // 0x8018D8A0: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8018D8A4: sb          $t7, 0x7930($at)
    MEM_B(0X7930, ctx->r1) = ctx->r15;
    // 0x8018D8A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018D8AC: lw          $v0, 0x1C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C8);
    // 0x8018D8B0: beq         $v0, $at, L_8018D8C0
    if (ctx->r2 == ctx->r1) {
        // 0x8018D8B4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8018D8C0;
    }
    // 0x8018D8B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8018D8B8: bnel        $v0, $at, L_8018D8D4
    if (ctx->r2 != ctx->r1) {
        // 0x8018D8BC: lh          $t6, 0x60($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X60);
            goto L_8018D8D4;
    }
    goto skip_32;
    // 0x8018D8BC: lh          $t6, 0x60($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X60);
    skip_32:
L_8018D8C0:
    // 0x8018D8C0: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8018D8C4: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x8018D8C8: jal         0x8004319C
    // 0x8018D8CC: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    Boss_CompleteLevel(rdram, ctx);
        goto after_90;
    // 0x8018D8CC: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    after_90:
    // 0x8018D8D0: lh          $t6, 0x60($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X60);
L_8018D8D4:
    // 0x8018D8D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018D8D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D8DC: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8018D8E0: sh          $t8, 0x60($s2)
    MEM_H(0X60, ctx->r18) = ctx->r24;
    // 0x8018D8E4: addiu       $a0, $a0, -0x49A4
    ctx->r4 = ADD32(ctx->r4, -0X49A4);
    // 0x8018D8E8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x8018D8EC: jal         0x800BA808
    // 0x8018D8F0: swc1        $f18, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f18.u32l;
    Radio_PlayMessage(rdram, ctx);
        goto after_91;
    // 0x8018D8F0: swc1        $f18, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f18.u32l;
    after_91:
    // 0x8018D8F4: b           L_8018DBB0
    // 0x8018D8F8: nop

        goto L_8018DBB0;
    // 0x8018D8F8: nop

L_8018D8FC:
    // 0x8018D8FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D900: lwc1        $f4, -0x4EA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4EA0);
    // 0x8018D904: lw          $a3, 0xF8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XF8);
    // 0x8018D908: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D90C: jal         0x8009BC2C
    // 0x8018D910: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_92;
    // 0x8018D910: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_92:
    // 0x8018D914: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018D918: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018D91C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018D920: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D924: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D928: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D92C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8018D930: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8018D934: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x8018D938: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x8018D93C: jal         0x80006970
    // 0x8018D940: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_93;
    // 0x8018D940: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    after_93:
    // 0x8018D944: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018D948: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D94C: lh          $t9, 0x56($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X56);
    // 0x8018D950: swc1        $f16, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f16.u32l;
    // 0x8018D954: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8018D958: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D95C: addiu       $a0, $a0, -0x49C8
    ctx->r4 = ADD32(ctx->r4, -0X49C8);
    // 0x8018D960: swc1        $f18, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f18.u32l;
    // 0x8018D964: lwc1        $f6, 0x7D08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8018D968: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018D96C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D970: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D974: bne         $t9, $at, L_8018DBB0
    if (ctx->r25 != ctx->r1) {
        // 0x8018D978: swc1        $f8, 0x74($s2)
        MEM_W(0X74, ctx->r18) = ctx->f8.u32l;
            goto L_8018DBB0;
    }
    // 0x8018D978: swc1        $f8, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f8.u32l;
    // 0x8018D97C: jal         0x800BA808
    // 0x8018D980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_94;
    // 0x8018D980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_94:
    // 0x8018D984: b           L_8018DBB0
    // 0x8018D988: nop

        goto L_8018DBB0;
    // 0x8018D988: nop

L_8018D98C:
    // 0x8018D98C: b           L_8018DBB0
    // 0x8018D990: sh          $t1, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r9;
        goto L_8018DBB0;
    // 0x8018D990: sh          $t1, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r9;
L_8018D994:
    // 0x8018D994: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018D998: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8018D99C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D9A0: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8018D9A4: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8018D9A8: bne         $t3, $zero, L_8018D9F4
    if (ctx->r11 != 0) {
        // 0x8018D9AC: nop
    
            goto L_8018D9F4;
    }
    // 0x8018D9AC: nop

L_8018D9B0:
    // 0x8018D9B0: jal         0x80004EB0
    // 0x8018D9B4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_95;
    // 0x8018D9B4: nop

    after_95:
    // 0x8018D9B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018D9BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D9C0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018D9C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D9C8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8018D9CC: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018D9D0: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018D9D4: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x8018D9D8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018D9DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018D9E0: jal         0x80079618
    // 0x8018D9E4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_effect_80079618(rdram, ctx);
        goto after_96;
    // 0x8018D9E4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_96:
    // 0x8018D9E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018D9EC: bne         $s1, $s0, L_8018D9B0
    if (ctx->r17 != ctx->r16) {
        // 0x8018D9F0: nop
    
            goto L_8018D9B0;
    }
    // 0x8018D9F0: nop

L_8018D9F4:
    // 0x8018D9F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D9F8: lwc1        $f8, -0x4E9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4E9C);
    // 0x8018D9FC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018DA00: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8018DA04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DA08: addiu       $a0, $s2, 0x6C
    ctx->r4 = ADD32(ctx->r18, 0X6C);
    // 0x8018DA0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018DA10: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018DA14: jal         0x8009BC2C
    // 0x8018DA18: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_97;
    // 0x8018DA18: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_97:
    // 0x8018DA1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DA20: lwc1        $f10, -0x4E98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4E98);
    // 0x8018DA24: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018DA28: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DA2C: addiu       $a0, $s2, 0x70
    ctx->r4 = ADD32(ctx->r18, 0X70);
    // 0x8018DA30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018DA34: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018DA38: jal         0x8009BC2C
    // 0x8018DA3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_98;
    // 0x8018DA3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_98:
    // 0x8018DA40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DA44: lwc1        $f16, -0x4E94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4E94);
    // 0x8018DA48: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018DA4C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DA50: addiu       $a0, $s2, 0x74
    ctx->r4 = ADD32(ctx->r18, 0X74);
    // 0x8018DA54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018DA58: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018DA5C: jal         0x8009BC2C
    // 0x8018DA60: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_99;
    // 0x8018DA60: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_99:
    // 0x8018DA64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018DA68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DA6C: lwc1        $f18, 0x18($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8018DA70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DA74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018DA78: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018DA7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018DA80: swc1        $f8, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->f8.u32l;
    // 0x8018DA84: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018DA88: swc1        $f6, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f6.u32l;
    // 0x8018DA8C: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8018DA90: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018DA94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DA98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018DA9C: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8018DAA0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018DAA4: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x8018DAA8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8018DAAC: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8018DAB0: nop

    // 0x8018DAB4: bc1f        L_8018DBB0
    if (!c1cs) {
        // 0x8018DAB8: nop
    
            goto L_8018DBB0;
    }
    // 0x8018DAB8: nop

    // 0x8018DABC: sw          $t4, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r12;
    // 0x8018DAC0: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x8018DAC4: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018DAC8: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018DACC: jal         0x80081A8C
    // 0x8018DAD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_effect_80081A8C(rdram, ctx);
        goto after_100;
    // 0x8018DAD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_100:
    // 0x8018DAD4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018DAD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DADC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018DAE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018DAE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018DAE8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DAEC: sh          $t7, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r15;
    // 0x8018DAF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018DAF4: swc1        $f6, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f6.u32l;
    // 0x8018DAF8: swc1        $f8, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->f8.u32l;
    // 0x8018DAFC: jal         0x8018C0B0
    // 0x8018DB00: swc1        $f16, 0x11C($s2)
    MEM_W(0X11C, ctx->r18) = ctx->f16.u32l;
    Corneria_CoCarrier_WaterSplash(rdram, ctx);
        goto after_101;
    // 0x8018DB00: swc1        $f16, 0x11C($s2)
    MEM_W(0X11C, ctx->r18) = ctx->f16.u32l;
    after_101:
    // 0x8018DB04: b           L_8018DBB0
    // 0x8018DB08: sh          $s0, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r16;
        goto L_8018DBB0;
    // 0x8018DB08: sh          $s0, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r16;
L_8018DB0C:
    // 0x8018DB0C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018DB10: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8018DB14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018DB18: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8018DB1C: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x8018DB20: bnel        $t8, $zero, L_8018DB70
    if (ctx->r24 != 0) {
        // 0x8018DB24: lh          $t9, 0x50($s2)
        ctx->r25 = MEM_H(ctx->r18, 0X50);
            goto L_8018DB70;
    }
    goto skip_33;
    // 0x8018DB24: lh          $t9, 0x50($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X50);
    skip_33:
L_8018DB28:
    // 0x8018DB28: jal         0x80004EB0
    // 0x8018DB2C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_102;
    // 0x8018DB2C: nop

    after_102:
    // 0x8018DB30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018DB34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DB38: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018DB3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DB40: sub.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8018DB44: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018DB48: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018DB4C: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x8018DB50: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8018DB54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018DB58: jal         0x80079618
    // 0x8018DB5C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_effect_80079618(rdram, ctx);
        goto after_103;
    // 0x8018DB5C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_103:
    // 0x8018DB60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018DB64: bne         $s1, $s0, L_8018DB28
    if (ctx->r17 != ctx->r16) {
        // 0x8018DB68: nop
    
            goto L_8018DB28;
    }
    // 0x8018DB68: nop

    // 0x8018DB6C: lh          $t9, 0x50($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X50);
L_8018DB70:
    // 0x8018DB70: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018DB74: addiu       $s0, $s2, 0x3FC
    ctx->r16 = ADD32(ctx->r18, 0X3FC);
    // 0x8018DB78: bne         $t9, $zero, L_8018DBB0
    if (ctx->r25 != 0) {
        // 0x8018DB7C: nop
    
            goto L_8018DBB0;
    }
    // 0x8018DB7C: nop

    // 0x8018DB80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB84: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018DB88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DB8C: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8018DB90: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018DB94: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8018DB98: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x8018DB9C: jal         0x8007A568
    // 0x8018DBA0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    Effect_Effect383_Spawn(rdram, ctx);
        goto after_104;
    // 0x8018DBA0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_104:
    // 0x8018DBA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018DBA8: jal         0x80060FBC
    // 0x8018DBAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Object_Kill(rdram, ctx);
        goto after_105;
    // 0x8018DBAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_105:
L_8018DBB0:
    // 0x8018DBB0: lui         $v0, 0x604
    ctx->r2 = S32(0X604 << 16);
    // 0x8018DBB4: addiu       $v0, $v0, -0x18B8
    ctx->r2 = ADD32(ctx->r2, -0X18B8);
    // 0x8018DBB8: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x8018DBBC: lui         $v1, 0x604
    ctx->r3 = S32(0X604 << 16);
    // 0x8018DBC0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8018DBC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DBC8: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8018DBCC: addiu       $v1, $v1, -0x183C
    ctx->r3 = ADD32(ctx->r3, -0X183C);
    // 0x8018DBD0: lwc1        $f0, -0x4E90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E90);
    // 0x8018DBD4: addiu       $a2, $a2, 0x1FD0
    ctx->r6 = ADD32(ctx->r6, 0X1FD0);
    // 0x8018DBD8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8018DBDC: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8018DBE0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018DBE4: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8018DBE8: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8018DBEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018DBF0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8018DBF4: lui         $a3, 0xFF
    ctx->r7 = S32(0XFF << 16);
    // 0x8018DBF8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8018DBFC: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8018DC00: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x8018DC04: lui         $at, 0x432C
    ctx->r1 = S32(0X432C << 16);
    // 0x8018DC08: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8018DC0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DC10: and         $t7, $v0, $a3
    ctx->r15 = ctx->r2 & ctx->r7;
    // 0x8018DC14: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8018DC18: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8018DC1C: addu        $a0, $t6, $t0
    ctx->r4 = ADD32(ctx->r14, ctx->r8);
    // 0x8018DC20: and         $t4, $v1, $a3
    ctx->r12 = ctx->r3 & ctx->r7;
    // 0x8018DC24: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x8018DC28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC2C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8018DC30: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    // 0x8018DC34: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8018DC38: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x8018DC3C: swc1        $f0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f0.u32l;
    // 0x8018DC40: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x8018DC44: lwc1        $f6, 0xD8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XD8);
    // 0x8018DC48: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8018DC4C: nop

    // 0x8018DC50: bc1fl       L_8018DC6C
    if (!c1cs) {
        // 0x8018DC54: lwc1        $f16, 0xDC($s2)
        ctx->f16.u32l = MEM_W(ctx->r18, 0XDC);
            goto L_8018DC6C;
    }
    goto skip_34;
    // 0x8018DC54: lwc1        $f16, 0xDC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XDC);
    skip_34:
    // 0x8018DC58: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8018DC5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DC60: lwc1        $f8, -0x4E8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4E8C);
    // 0x8018DC64: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x8018DC68: lwc1        $f16, 0xDC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XDC);
L_8018DC6C:
    // 0x8018DC6C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8018DC70: nop

    // 0x8018DC74: bc1fl       L_8018DC90
    if (!c1cs) {
        // 0x8018DC78: lh          $t7, 0x9C($s2)
        ctx->r15 = MEM_H(ctx->r18, 0X9C);
            goto L_8018DC90;
    }
    goto skip_35;
    // 0x8018DC78: lh          $t7, 0x9C($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X9C);
    skip_35:
    // 0x8018DC7C: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8018DC80: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DC84: lwc1        $f18, -0x4E88($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4E88);
    // 0x8018DC88: swc1        $f18, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f18.u32l;
    // 0x8018DC8C: lh          $t7, 0x9C($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X9C);
L_8018DC90:
    // 0x8018DC90: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8018DC94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DC98: bne         $t7, $zero, L_8018DD14
    if (ctx->r15 != 0) {
        // 0x8018DC9C: swc1        $f10, 0x118($s2)
        MEM_W(0X118, ctx->r18) = ctx->f10.u32l;
            goto L_8018DD14;
    }
    // 0x8018DC9C: swc1        $f10, 0x118($s2)
    MEM_W(0X118, ctx->r18) = ctx->f10.u32l;
    // 0x8018DCA0: lh          $t6, 0x4E($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4E);
    // 0x8018DCA4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018DCA8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018DCAC: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x8018DCB0: beq         $at, $zero, L_8018DD14
    if (ctx->r1 == 0) {
        // 0x8018DCB4: lui         $a0, 0x1102
        ctx->r4 = S32(0X1102 << 16);
            goto L_8018DD14;
    }
    // 0x8018DCB4: lui         $a0, 0x1102
    ctx->r4 = S32(0X1102 << 16);
    // 0x8018DCB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DCBC: lwc1        $f4, -0x4E84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4E84);
    // 0x8018DCC0: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018DCC4: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018DCC8: swc1        $f4, 0x11C($s2)
    MEM_W(0X11C, ctx->r18) = ctx->f4.u32l;
    // 0x8018DCCC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018DCD0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018DCD4: ori         $a0, $a0, 0x84
    ctx->r4 = ctx->r4 | 0X84;
    // 0x8018DCD8: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8018DCDC: jal         0x80019218
    // 0x8018DCE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_106;
    // 0x8018DCE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_106:
    // 0x8018DCE4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018DCE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018DCEC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018DCF0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018DCF4: addiu       $t9, $zero, 0x47
    ctx->r25 = ADD32(0, 0X47);
    // 0x8018DCF8: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8018DCFC: sh          $t9, 0x58($s2)
    MEM_H(0X58, ctx->r18) = ctx->r25;
    // 0x8018DD00: sh          $t1, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r9;
    // 0x8018DD04: swc1        $f6, 0x108($s2)
    MEM_W(0X108, ctx->r18) = ctx->f6.u32l;
    // 0x8018DD08: swc1        $f8, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f8.u32l;
    // 0x8018DD0C: swc1        $f16, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f16.u32l;
    // 0x8018DD10: swc1        $f18, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f18.u32l;
L_8018DD14:
    // 0x8018DD14: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018DD18: lw          $v0, 0x13A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13A0);
    // 0x8018DD1C: addiu       $at, $zero, 0x1AE
    ctx->r1 = ADD32(0, 0X1AE);
    // 0x8018DD20: bne         $v0, $at, L_8018DD3C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DD24: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018DD3C;
    }
    // 0x8018DD24: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018DD28: addiu       $a0, $a0, -0x4D90
    ctx->r4 = ADD32(ctx->r4, -0X4D90);
    // 0x8018DD2C: jal         0x800BA808
    // 0x8018DD30: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_107;
    // 0x8018DD30: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_107:
    // 0x8018DD34: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018DD38: lw          $v0, 0x13A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13A0);
L_8018DD3C:
    // 0x8018DD3C: addiu       $at, $zero, 0x24A
    ctx->r1 = ADD32(0, 0X24A);
    // 0x8018DD40: bne         $v0, $at, L_8018DD50
    if (ctx->r2 != ctx->r1) {
        // 0x8018DD44: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8018DD50;
    }
    // 0x8018DD44: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018DD4C: sw          $t2, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = ctx->r10;
L_8018DD50:
    // 0x8018DD50: slti        $at, $v0, 0x24B
    ctx->r1 = SIGNED(ctx->r2) < 0X24B ? 1 : 0;
    // 0x8018DD54: bnel        $at, $zero, L_8018DD98
    if (ctx->r1 != 0) {
        // 0x8018DD58: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8018DD98;
    }
    goto skip_36;
    // 0x8018DD58: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_36:
    // 0x8018DD5C: lh          $t3, 0x60($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X60);
    // 0x8018DD60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DD64: lwc1        $f6, -0x4E80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4E80);
    // 0x8018DD68: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8018DD6C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018DD70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018DD74: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018DD78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018DD7C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018DD80: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018DD84: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018DD88: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8018DD8C: nop

    // 0x8018DD90: sw          $t5, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->r13;
    // 0x8018DD94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8018DD98:
    // 0x8018DD98: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018DD9C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DDA0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018DDA4: jr          $ra
    // 0x8018DDA8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x8018DDA8: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
;}
RECOMP_FUNC void Training_Setup360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198C50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80198C54: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80198C58: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80198C5C: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x80198C60: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80198C64: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80198C68: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80198C6C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80198C70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80198C74: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80198C78: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x80198C7C: addiu       $v0, $v0, -0x7108
    ctx->r2 = ADD32(ctx->r2, -0X7108);
    // 0x80198C80: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80198C84: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80198C88: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80198C8C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80198C90: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80198C94: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80198C98: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x80198C9C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80198CA0: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x80198CA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80198CA8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80198CAC: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80198CB0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x80198CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80198CB8: addiu       $a1, $zero, 0x7148
    ctx->r5 = ADD32(0, 0X7148);
    // 0x80198CBC: jal         0x80004FC8
    // 0x80198CC0: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    Rand_SetSeed(rdram, ctx);
        goto after_0;
    // 0x80198CC0: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    after_0:
    // 0x80198CC4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80198CC8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80198CCC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80198CD0: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x80198CD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80198CD8: addiu       $s4, $zero, 0x4E20
    ctx->r20 = ADD32(0, 0X4E20);
    // 0x80198CDC: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80198CE0: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
L_80198CE4:
    // 0x80198CE4: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80198CE8: lh          $v0, 0x10($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X10);
    // 0x80198CEC: bltz        $v0, L_80198DA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80198CF0: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_80198DA8;
    }
    // 0x80198CF0: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x80198CF4: beql        $at, $zero, L_80198DA0
    if (ctx->r1 == 0) {
        // 0x80198CF8: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80198DA0;
    }
    goto skip_0;
    // 0x80198CF8: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x80198CFC: jal         0x800A4F4C
    // 0x80198D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_1;
    // 0x80198D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80198D04: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80198D08: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80198D0C: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80198D10: lh          $t7, 0x10($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10);
    // 0x80198D14: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80198D18: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80198D1C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80198D20: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x80198D24: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80198D28: nop

    // 0x80198D2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80198D30: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80198D34: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80198D38: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80198D3C: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80198D40: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80198D44: jal         0x80004FE8
    // 0x80198D48: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_2;
    // 0x80198D48: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x80198D4C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80198D50: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80198D54: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80198D58: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80198D5C: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x80198D60: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80198D64: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80198D68: nop

    // 0x80198D6C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80198D70: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80198D74: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80198D78: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80198D7C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80198D80: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x80198D84: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80198D88: nop

    // 0x80198D8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80198D90: jal         0x800612B8
    // 0x80198D94: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x80198D94: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80198D98: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80198D9C: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80198DA0:
    // 0x80198DA0: bnel        $s1, $s4, L_80198CE4
    if (ctx->r17 != ctx->r20) {
        // 0x80198DA4: lw          $t3, 0x0($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X0);
            goto L_80198CE4;
    }
    goto skip_1;
    // 0x80198DA4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80198DA8:
    // 0x80198DA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80198DAC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80198DB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80198DB4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80198DB8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80198DBC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80198DC0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80198DC4: jr          $ra
    // 0x80198DC8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80198DC8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Corneria_SetupClouds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F55C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018F560: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018F564: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018F568: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F56C: jal         0x80061474
    // 0x8018F570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018F570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018F574: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018F578: jal         0x80004EB0
    // 0x8018F57C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018F57C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    after_1:
    // 0x8018F580: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018F584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F588: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018F58C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F590: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018F594: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018F598: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8018F59C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018F5A0: lwc1        $f16, 0x40($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X40);
    // 0x8018F5A4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018F5A8: jal         0x80004EB0
    // 0x8018F5AC: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018F5AC: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x8018F5B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F5B4: lwc1        $f4, -0x4E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4E30);
    // 0x8018F5B8: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8018F5BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F5C0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018F5C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8018F5C8: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8018F5CC: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x8018F5D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018F5D4: lwc1        $f16, 0x44($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8018F5D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F5DC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018F5E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F5E4: addiu       $t9, $zero, 0x160
    ctx->r25 = ADD32(0, 0X160);
    // 0x8018F5E8: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x8018F5EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018F5F0: addiu       $t1, $zero, 0x90
    ctx->r9 = ADD32(0, 0X90);
    // 0x8018F5F4: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x8018F5F8: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
    // 0x8018F5FC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8018F600: sh          $t1, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r9;
    // 0x8018F604: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8018F608: jal         0x80004EB0
    // 0x8018F60C: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018F60C: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x8018F610: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018F614: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F618: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018F61C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F620: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018F624: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018F628: jal         0x80004EB0
    // 0x8018F62C: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8018F62C: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x8018F630: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018F634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F638: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018F63C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018F640: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8018F644: nop

    // 0x8018F648: bc1f        L_8018F65C
    if (!c1cs) {
        // 0x8018F64C: nop
    
            goto L_8018F65C;
    }
    // 0x8018F64C: nop

    // 0x8018F650: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F654: nop

    // 0x8018F658: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_8018F65C:
    // 0x8018F65C: jal         0x800612B8
    // 0x8018F660: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x8018F660: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_5:
    // 0x8018F664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018F66C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018F670: jr          $ra
    // 0x8018F674: nop

    return;
    // 0x8018F674: nop

;}
RECOMP_FUNC void Corneria_CsLevelComplete1_TeamSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190F74: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80190F78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80190F7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80190F80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80190F84: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80190F88: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80190F8C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80190F90: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80190F94: lw          $s1, -0x7D80($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X7D80);
    // 0x80190F98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190F9C: lwc1        $f6, -0x4DBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4DBC);
    // 0x80190FA0: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80190FA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190FA8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190FAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190FB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80190FB4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80190FB8: jal         0x80005E90
    // 0x80190FBC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80190FBC: nop

    after_0:
    // 0x80190FC0: lw          $s2, 0x6C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X6C);
    // 0x80190FC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190FC8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190FCC: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80190FD0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80190FD4: lwc1        $f10, -0x651C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X651C);
    // 0x80190FD8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190FDC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80190FE0: lwc1        $f16, -0x6510($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6510);
    // 0x80190FE4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190FE8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80190FEC: lwc1        $f18, -0x6504($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6504);
    // 0x80190FF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190FF4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80190FF8: lwc1        $f4, -0x64F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X64F8);
    // 0x80190FFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191000: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80191004: lwc1        $f6, -0x64EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X64EC);
    // 0x80191008: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019100C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80191010: lwc1        $f8, -0x64E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X64E0);
    // 0x80191014: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80191018: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019101C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80191020: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80191024: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80191028: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8019102C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80191030: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80191034: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80191038: jal         0x80006A20
    // 0x8019103C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x8019103C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80191040: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191044: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191048: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8019104C: jal         0x80006A20
    // 0x80191050: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80191050: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80191054: jal         0x800613C4
    // 0x80191058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_3;
    // 0x80191058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8019105C: lwc1        $f10, 0x74($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80191060: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80191064: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80191068: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8019106C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80191070: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80191074: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191078: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8019107C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80191080: lwc1        $f10, 0x7C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80191084: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80191088: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8019108C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80191090: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x80191094: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80191098: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    // 0x8019109C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801910A0: jal         0x80004EB0
    // 0x801910A4: swc1        $f8, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801910A4: swc1        $f8, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x801910A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801910AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801910B0: nop

    // 0x801910B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801910B8: jal         0x80004EB0
    // 0x801910BC: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801910BC: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x801910C0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801910C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801910C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801910CC: addiu       $t8, $zero, 0xC3
    ctx->r24 = ADD32(0, 0XC3);
    // 0x801910D0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801910D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801910D8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x801910DC: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x801910E0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801910E4: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    // 0x801910E8: lwc1        $f6, 0xC0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x801910EC: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x801910F0: lwc1        $f8, 0xC4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x801910F4: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x801910F8: lwc1        $f10, 0xC8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x801910FC: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x80191100: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x80191104: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    // 0x80191108: lwc1        $f16, -0x64D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X64D4);
    // 0x8019110C: jal         0x800612B8
    // 0x80191110: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x80191110: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    after_6:
    // 0x80191114: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80191118: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019111C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80191120: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80191124: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x80191128: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019112C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80191130: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80191134: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80191138: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019113C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80191140: jal         0x80019218
    // 0x80191144: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80191144: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80191148: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019114C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80191150: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80191154: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80191158: jr          $ra
    // 0x8019115C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8019115C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Corneria_CoGranga_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018AA74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018AA78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018AA7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018AA80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018AA84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AA88: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018AA8C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018AA90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018AA94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018AA98: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AA9C: jal         0x80005B00
    // 0x8018AAA0: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8018AAA0: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    after_0:
    // 0x8018AAA4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8018AAA8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8018AAAC: lw          $t8, -0x4438($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4438);
    // 0x8018AAB0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018AAB4: addiu       $t7, $t7, -0x58D0
    ctx->r15 = ADD32(ctx->r15, -0X58D0);
    // 0x8018AAB8: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8018AABC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018AAC0: addiu       $a3, $a3, -0x5BCC
    ctx->r7 = ADD32(ctx->r7, -0X5BCC);
    // 0x8018AAC4: addiu       $a1, $a1, -0x419C
    ctx->r5 = ADD32(ctx->r5, -0X419C);
    // 0x8018AAC8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018AACC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018AAD0: addiu       $a2, $v0, 0x1A0
    ctx->r6 = ADD32(ctx->r2, 0X1A0);
    // 0x8018AAD4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8018AAD8: jal         0x8009A72C
    // 0x8018AADC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x8018AADC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x8018AAE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AAE4: jal         0x80005740
    // 0x8018AAE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_2;
    // 0x8018AAE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x8018AAEC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AAF0: jal         0x80005708
    // 0x8018AAF4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8018AAF4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x8018AAF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018AAFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018AB00: jr          $ra
    // 0x8018AB04: nop

    return;
    // 0x8018AB04: nop

;}
