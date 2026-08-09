#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Effect_FireSmoke1_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D2F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D2F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007D2FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007D300: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D304: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007D308: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x8007D30C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007D310: bnel        $t6, $zero, L_8007D484
    if (ctx->r14 != 0) {
        // 0x8007D314: lhu         $t0, 0x50($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X50);
            goto L_8007D484;
    }
    goto skip_0;
    // 0x8007D314: lhu         $t0, 0x50($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X50);
    skip_0:
    // 0x8007D318: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8007D31C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007D320: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007D324: bnel        $v0, $at, L_8007D3A4
    if (ctx->r2 != ctx->r1) {
        // 0x8007D328: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8007D3A4;
    }
    goto skip_1;
    // 0x8007D328: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_1:
    // 0x8007D32C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8007D330: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007D334: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x8007D338: bne         $t8, $at, L_8007D3A0
    if (ctx->r24 != ctx->r1) {
        // 0x8007D33C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007D3A0;
    }
    // 0x8007D33C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D340: lwc1        $f6, 0x7434($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7434);
    // 0x8007D344: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007D348: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
    // 0x8007D34C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007D350: bne         $t9, $zero, L_8007D4C4
    if (ctx->r25 != 0) {
        // 0x8007D354: swc1        $f8, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
            goto L_8007D4C4;
    }
    // 0x8007D354: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007D358: lbu         $t0, 0x4C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4C);
    // 0x8007D35C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8007D360: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    // 0x8007D364: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007D368: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x8007D36C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8007D370: bne         $at, $zero, L_8007D384
    if (ctx->r1 != 0) {
        // 0x8007D374: sb          $t1, 0x4C($s0)
        MEM_B(0X4C, ctx->r16) = ctx->r9;
            goto L_8007D384;
    }
    // 0x8007D374: sb          $t1, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r9;
    // 0x8007D378: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8007D37C: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    // 0x8007D380: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
L_8007D384:
    // 0x8007D384: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8007D388: bne         $at, $zero, L_8007D4C4
    if (ctx->r1 != 0) {
        // 0x8007D38C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8007D4C4;
    }
    // 0x8007D38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D390: jal         0x80060FBC
    // 0x8007D394: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007D394: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_0:
    // 0x8007D398: b           L_8007D4C4
    // 0x8007D39C: nop

        goto L_8007D4C4;
    // 0x8007D39C: nop

L_8007D3A0:
    // 0x8007D3A0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_8007D3A4:
    // 0x8007D3A4: bne         $v0, $at, L_8007D420
    if (ctx->r2 != ctx->r1) {
        // 0x8007D3A8: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_8007D420;
    }
    // 0x8007D3A8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8007D3AC: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8007D3B0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007D3B4: lw          $t5, 0x1C8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C8);
    // 0x8007D3B8: bne         $t5, $at, L_8007D420
    if (ctx->r13 != ctx->r1) {
        // 0x8007D3BC: nop
    
            goto L_8007D420;
    }
    // 0x8007D3BC: nop

    // 0x8007D3C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007D3C4: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8007D3C8: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8007D3CC: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x8007D3D0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8007D3D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007D3D8: bc1t        L_8007D420
    if (c1cs) {
        // 0x8007D3DC: nop
    
            goto L_8007D420;
    }
    // 0x8007D3DC: nop

    // 0x8007D3E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D3E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8007D3E8: jal         0x8009BC2C
    // 0x8007D3EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8007D3EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8007D3F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D3F4: addiu       $a0, $s0, 0x5C
    ctx->r4 = ADD32(ctx->r16, 0X5C);
    // 0x8007D3F8: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x8007D3FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007D400: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8007D404: jal         0x8009BC2C
    // 0x8007D408: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8007D408: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8007D40C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D410: lwc1        $f8, 0x7438($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7438);
    // 0x8007D414: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007D418: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007D41C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_8007D420:
    // 0x8007D420: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D424: lwc1        $f18, 0x743C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X743C);
    // 0x8007D428: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007D42C: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
    // 0x8007D430: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007D434: bne         $t6, $zero, L_8007D4C4
    if (ctx->r14 != 0) {
        // 0x8007D438: swc1        $f4, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
            goto L_8007D4C4;
    }
    // 0x8007D438: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x8007D43C: lbu         $t7, 0x4C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4C);
    // 0x8007D440: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8007D444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D448: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007D44C: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
    // 0x8007D450: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8007D454: bne         $at, $zero, L_8007D464
    if (ctx->r1 != 0) {
        // 0x8007D458: sb          $t8, 0x4C($s0)
        MEM_B(0X4C, ctx->r16) = ctx->r24;
            goto L_8007D464;
    }
    // 0x8007D458: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    // 0x8007D45C: sh          $t9, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r25;
    // 0x8007D460: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
L_8007D464:
    // 0x8007D464: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8007D468: bne         $at, $zero, L_8007D4C4
    if (ctx->r1 != 0) {
        // 0x8007D46C: nop
    
            goto L_8007D4C4;
    }
    // 0x8007D46C: nop

    // 0x8007D470: jal         0x80060FBC
    // 0x8007D474: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8007D474: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_3:
    // 0x8007D478: b           L_8007D4C4
    // 0x8007D47C: nop

        goto L_8007D4C4;
    // 0x8007D47C: nop

    // 0x8007D480: lhu         $t0, 0x50($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X50);
L_8007D484:
    // 0x8007D484: bnel        $t0, $zero, L_8007D4BC
    if (ctx->r8 != 0) {
        // 0x8007D488: lh          $t5, 0x44($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X44);
            goto L_8007D4BC;
    }
    goto skip_2;
    // 0x8007D488: lh          $t5, 0x44($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X44);
    skip_2:
    // 0x8007D48C: lbu         $t1, 0x4C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X4C);
    // 0x8007D490: lh          $t3, 0x46($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X46);
    // 0x8007D494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D498: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8007D49C: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x8007D4A0: slti        $at, $t4, 0xE
    ctx->r1 = SIGNED(ctx->r12) < 0XE ? 1 : 0;
    // 0x8007D4A4: sb          $t2, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r10;
    // 0x8007D4A8: bne         $at, $zero, L_8007D4B8
    if (ctx->r1 != 0) {
        // 0x8007D4AC: sh          $t3, 0x50($s0)
        MEM_H(0X50, ctx->r16) = ctx->r11;
            goto L_8007D4B8;
    }
    // 0x8007D4AC: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    // 0x8007D4B0: jal         0x80060FBC
    // 0x8007D4B4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x8007D4B4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_4:
L_8007D4B8:
    // 0x8007D4B8: lh          $t5, 0x44($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X44);
L_8007D4BC:
    // 0x8007D4BC: addiu       $t6, $t5, -0xF
    ctx->r14 = ADD32(ctx->r13, -0XF);
    // 0x8007D4C0: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
L_8007D4C4:
    // 0x8007D4C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007D4C8: addiu       $v0, $v0, -0x7C94
    ctx->r2 = ADD32(ctx->r2, -0X7C94);
    // 0x8007D4CC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8007D4D0: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007D4D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D4D8: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8007D4DC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8007D4E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007D4E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007D4E8: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x8007D4EC: bc1fl       L_8007D540
    if (!c1cs) {
        // 0x8007D4F0: ori         $a3, $a3, 0xCCCD
        ctx->r7 = ctx->r7 | 0XCCCD;
            goto L_8007D540;
    }
    goto skip_3;
    // 0x8007D4F0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    skip_3:
    // 0x8007D4F4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8007D4F8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007D4FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D500: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8007D504: swc1        $f8, -0x7C90($at)
    MEM_W(-0X7C90, ctx->r1) = ctx->f8.u32l;
    // 0x8007D508: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007D50C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D510: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x8007D514: swc1        $f10, -0x7C8C($at)
    MEM_W(-0X7C8C, ctx->r1) = ctx->f10.u32l;
    // 0x8007D518: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007D51C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D520: swc1        $f16, -0x7C88($at)
    MEM_W(-0X7C88, ctx->r1) = ctx->f16.u32l;
    // 0x8007D524: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D528: sw          $t7, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = ctx->r15;
    // 0x8007D52C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D530: sw          $t8, -0x7C9C($at)
    MEM_W(-0X7C9C, ctx->r1) = ctx->r24;
    // 0x8007D534: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D538: sw          $zero, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = 0;
    // 0x8007D53C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
L_8007D540:
    // 0x8007D540: jal         0x8009BC2C
    // 0x8007D544: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8007D544: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8007D548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D54C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007D550: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007D554: jr          $ra
    // 0x8007D558: nop

    return;
    // 0x8007D558: nop

;}
RECOMP_FUNC void AudioSynth_LoadReverbSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D78: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80009D7C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80009D80: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x80009D84: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80009D88: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x80009D8C: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80009D90: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80009D94: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80009D98: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80009D9C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80009DA0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80009DA4: addiu       $t5, $t5, -0x45B0
    ctx->r13 = ADD32(ctx->r13, -0X45B0);
    // 0x80009DA8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80009DAC: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80009DB0: addu        $v1, $t9, $t5
    ctx->r3 = ADD32(ctx->r25, ctx->r13);
    // 0x80009DB4: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x80009DB8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80009DBC: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80009DC0: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80009DC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80009DC8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80009DCC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80009DD0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80009DD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009DD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80009DDC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80009DE0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80009DE4: lui         $t5, 0x200
    ctx->r13 = S32(0X200 << 16);
    // 0x80009DE8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80009DEC: ori         $t5, $t5, 0xC90
    ctx->r13 = ctx->r13 | 0XC90;
    // 0x80009DF0: addiu       $t6, $zero, 0x300
    ctx->r14 = ADD32(0, 0X300);
    // 0x80009DF4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80009DF8: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80009DFC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80009E00: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80009E04: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80009E08: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x80009E0C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80009E10: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80009E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009E18: addiu       $t0, $t0, 0x34
    ctx->r8 = ADD32(ctx->r8, 0X34);
    // 0x80009E1C: bne         $t7, $at, L_80009ED4
    if (ctx->r15 != ctx->r1) {
        // 0x80009E20: addiu       $s0, $a0, 0x8
        ctx->r16 = ADD32(ctx->r4, 0X8);
            goto L_80009ED4;
    }
    // 0x80009E20: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x80009E24: lhu         $a2, 0xE($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0XE);
    // 0x80009E28: lh          $a3, 0x10($t0)
    ctx->r7 = MEM_H(ctx->r8, 0X10);
    // 0x80009E2C: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x80009E30: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80009E34: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80009E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009E3C: jal         0x800098DC
    // 0x80009E40: addiu       $a1, $zero, 0xC90
    ctx->r5 = ADD32(0, 0XC90);
    AudioSynth_LoadRingBufferPart(rdram, ctx);
        goto after_0;
    // 0x80009E40: addiu       $a1, $zero, 0xC90
    ctx->r5 = ADD32(0, 0XC90);
    after_0:
    // 0x80009E44: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80009E48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80009E4C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80009E50: lh          $a3, 0x12($t0)
    ctx->r7 = MEM_H(ctx->r8, 0X12);
    // 0x80009E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009E58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009E5C: beql        $a3, $zero, L_80009E88
    if (ctx->r7 == 0) {
        // 0x80009E60: lui         $t9, 0x430
        ctx->r25 = S32(0X430 << 16);
            goto L_80009E88;
    }
    goto skip_0;
    // 0x80009E60: lui         $t9, 0x430
    ctx->r25 = S32(0X430 << 16);
    skip_0:
    // 0x80009E64: lh          $a1, 0x10($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X10);
    // 0x80009E68: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80009E6C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80009E70: addiu       $a1, $a1, 0xC90
    ctx->r5 = ADD32(ctx->r5, 0XC90);
    // 0x80009E74: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x80009E78: jal         0x800098DC
    // 0x80009E7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    AudioSynth_LoadRingBufferPart(rdram, ctx);
        goto after_1;
    // 0x80009E7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x80009E80: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80009E84: lui         $t9, 0x430
    ctx->r25 = S32(0X430 << 16);
L_80009E88:
    // 0x80009E88: lui         $t5, 0xC90
    ctx->r13 = S32(0XC90 << 16);
    // 0x80009E8C: ori         $t5, $t5, 0x990
    ctx->r13 = ctx->r13 | 0X990;
    // 0x80009E90: ori         $t9, $t9, 0x7FFF
    ctx->r25 = ctx->r25 | 0X7FFF;
    // 0x80009E94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009E98: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80009E9C: lhu         $t6, 0x8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8);
    // 0x80009EA0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80009EA4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80009EA8: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80009EAC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80009EB0: lui         $at, 0xC30
    ctx->r1 = S32(0XC30 << 16);
    // 0x80009EB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80009EB8: lui         $t5, 0xC90
    ctx->r13 = S32(0XC90 << 16);
    // 0x80009EBC: ori         $t5, $t5, 0xC90
    ctx->r13 = ctx->r13 | 0XC90;
    // 0x80009EC0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80009EC4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80009EC8: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80009ECC: b           L_8000A09C
    // 0x80009ED0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8000A09C;
    // 0x80009ED0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80009ED4:
    // 0x80009ED4: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x80009ED8: lh          $t9, 0x10($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X10);
    // 0x80009EDC: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80009EE0: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x80009EE4: sll         $t7, $t6, 17
    ctx->r15 = S32(ctx->r14 << 17);
    // 0x80009EE8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80009EEC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80009EF0: addiu       $t2, $t2, 0xF
    ctx->r10 = ADD32(ctx->r10, 0XF);
    // 0x80009EF4: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80009EF8: andi        $t5, $t2, 0xFFF0
    ctx->r13 = ctx->r10 & 0XFFF0;
    // 0x80009EFC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80009F00: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80009F04: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x80009F08: sh          $t2, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r10;
    // 0x80009F0C: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
    // 0x80009F10: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x80009F14: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80009F18: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80009F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009F20: addiu       $a1, $zero, 0x470
    ctx->r5 = ADD32(0, 0X470);
    // 0x80009F24: bgez        $t1, L_80009F34
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80009F28: sra         $t8, $t1, 1
        ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
            goto L_80009F34;
    }
    // 0x80009F28: sra         $t8, $t1, 1
    ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80009F2C: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x80009F30: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80009F34:
    // 0x80009F34: subu        $a2, $v0, $t8
    ctx->r6 = SUB32(ctx->r2, ctx->r24);
    // 0x80009F38: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x80009F3C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80009F40: jal         0x800098DC
    // 0x80009F44: addiu       $a3, $zero, 0x180
    ctx->r7 = ADD32(0, 0X180);
    AudioSynth_LoadRingBufferPart(rdram, ctx);
        goto after_2;
    // 0x80009F44: addiu       $a3, $zero, 0x180
    ctx->r7 = ADD32(0, 0X180);
    after_2:
    // 0x80009F48: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80009F4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80009F50: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80009F54: lh          $t5, 0x12($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X12);
    // 0x80009F58: lh          $t1, 0x62($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X62);
    // 0x80009F5C: lh          $t2, 0x60($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X60);
    // 0x80009F60: beq         $t5, $zero, L_80009F98
    if (ctx->r13 == 0) {
        // 0x80009F64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80009F98;
    }
    // 0x80009F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009F68: addiu       $a1, $t2, 0x470
    ctx->r5 = ADD32(ctx->r10, 0X470);
    // 0x80009F6C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80009F70: addiu       $t7, $zero, 0x180
    ctx->r15 = ADD32(0, 0X180);
    // 0x80009F74: subu        $a3, $t7, $t2
    ctx->r7 = SUB32(ctx->r15, ctx->r10);
    // 0x80009F78: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80009F7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009F80: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80009F84: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80009F88: jal         0x800098DC
    // 0x80009F8C: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
    AudioSynth_LoadRingBufferPart(rdram, ctx);
        goto after_3;
    // 0x80009F8C: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
    after_3:
    // 0x80009F90: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80009F94: lh          $t1, 0x62($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X62);
L_80009F98:
    // 0x80009F98: addiu       $t8, $t1, 0x470
    ctx->r24 = ADD32(ctx->r9, 0X470);
    // 0x80009F9C: lui         $t2, 0x800
    ctx->r10 = S32(0X800 << 16);
    // 0x80009FA0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80009FA4: or          $t5, $t9, $t2
    ctx->r13 = ctx->r25 | ctx->r10;
    // 0x80009FA8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80009FAC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80009FB0: lui         $at, 0xC90
    ctx->r1 = S32(0XC90 << 16);
    // 0x80009FB4: lui         $t3, 0x500
    ctx->r11 = S32(0X500 << 16);
    // 0x80009FB8: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80009FBC: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    // 0x80009FC0: or          $t8, $a1, $at
    ctx->r24 = ctx->r5 | ctx->r1;
    // 0x80009FC4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80009FC8: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80009FCC: lhu         $t5, 0xA($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XA);
    // 0x80009FD0: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80009FD4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80009FD8: or          $t6, $t5, $t3
    ctx->r14 = ctx->r13 | ctx->r11;
    // 0x80009FDC: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80009FE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80009FE4: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80009FE8: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80009FEC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80009FF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80009FF4: addiu       $t6, $t1, 0x5F0
    ctx->r14 = ADD32(ctx->r9, 0X5F0);
    // 0x80009FF8: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80009FFC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8000A000: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8000A004: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8000A008: lui         $at, 0xE10
    ctx->r1 = S32(0XE10 << 16);
    // 0x8000A00C: or          $t7, $a1, $at
    ctx->r15 = ctx->r5 | ctx->r1;
    // 0x8000A010: or          $t5, $t9, $t2
    ctx->r13 = ctx->r25 | ctx->r10;
    // 0x8000A014: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8000A018: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x8000A01C: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8000A020: lhu         $t6, 0xA($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XA);
    // 0x8000A024: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000A028: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000A02C: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x8000A030: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000A034: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8000A038: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8000A03C: lw          $t5, 0x28($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X28);
    // 0x8000A040: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000A044: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000A048: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x8000A04C: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8000A050: lui         $t8, 0xC90
    ctx->r24 = S32(0XC90 << 16);
    // 0x8000A054: lui         $t9, 0x430
    ctx->r25 = S32(0X430 << 16);
    // 0x8000A058: ori         $t9, $t9, 0x7FFF
    ctx->r25 = ctx->r25 | 0X7FFF;
    // 0x8000A05C: ori         $t8, $t8, 0x990
    ctx->r24 = ctx->r24 | 0X990;
    // 0x8000A060: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000A064: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000A068: lhu         $t6, 0x8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8);
    // 0x8000A06C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000A070: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000A074: addu        $t5, $t6, $at
    ctx->r13 = ADD32(ctx->r14, ctx->r1);
    // 0x8000A078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000A07C: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x8000A080: lui         $at, 0xC30
    ctx->r1 = S32(0XC30 << 16);
    // 0x8000A084: lui         $t8, 0xC90
    ctx->r24 = S32(0XC90 << 16);
    // 0x8000A088: ori         $t8, $t8, 0xC90
    ctx->r24 = ctx->r24 | 0XC90;
    // 0x8000A08C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8000A090: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000A094: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8000A098: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8000A09C:
    // 0x8000A09C: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x8000A0A0: lui         $a2, 0xC18
    ctx->r6 = S32(0XC18 << 16);
    // 0x8000A0A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000A0A8: bne         $t6, $zero, L_8000A0B8
    if (ctx->r14 != 0) {
        // 0x8000A0AC: lui         $t7, 0xA00
        ctx->r15 = S32(0XA00 << 16);
            goto L_8000A0B8;
    }
    // 0x8000A0AC: lui         $t7, 0xA00
    ctx->r15 = S32(0XA00 << 16);
    // 0x8000A0B0: lhu         $t5, 0xE($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XE);
    // 0x8000A0B4: beq         $t5, $zero, L_8000A110
    if (ctx->r13 == 0) {
        // 0x8000A0B8: lui         $t9, 0x470
        ctx->r25 = S32(0X470 << 16);
            goto L_8000A110;
    }
L_8000A0B8:
    // 0x8000A0B8: lui         $t9, 0x470
    ctx->r25 = S32(0X470 << 16);
    // 0x8000A0BC: ori         $t9, $t9, 0x180
    ctx->r25 = ctx->r25 | 0X180;
    // 0x8000A0C0: ori         $t7, $t7, 0xC90
    ctx->r15 = ctx->r15 | 0XC90;
    // 0x8000A0C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000A0C8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000A0CC: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x8000A0D0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000A0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000A0D8: lui         $t7, 0xE10
    ctx->r15 = S32(0XE10 << 16);
    // 0x8000A0DC: ori         $t7, $t7, 0xC90
    ctx->r15 = ctx->r15 | 0XC90;
    // 0x8000A0E0: or          $t5, $t6, $a2
    ctx->r13 = ctx->r14 | ctx->r6;
    // 0x8000A0E4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8000A0E8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8000A0EC: lhu         $t8, 0xE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XE);
    // 0x8000A0F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000A0F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000A0F8: lui         $t5, 0x470
    ctx->r13 = S32(0X470 << 16);
    // 0x8000A0FC: ori         $t5, $t5, 0xE10
    ctx->r13 = ctx->r13 | 0XE10;
    // 0x8000A100: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8000A104: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000A108: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8000A10C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8000A110:
    // 0x8000A110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A114: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000A118: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A11C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000A120: jr          $ra
    // 0x8000A124: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000A124: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E58: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80026E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026E60: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80026E64: jal         0x80026DD0
    // 0x80026E68: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80026E68: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80026E6C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80026E70: jal         0x80026CD0
    // 0x80026E74: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80026E74: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80026E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026E7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80026E80: jr          $ra
    // 0x80026E84: nop

    return;
    // 0x80026E84: nop

;}
RECOMP_FUNC void Display_ArwingLaserCharge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054E80: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80054E84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054E88: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80054E8C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80054E90: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80054E94: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80054E98: addiu       $t7, $t7, -0x5D54
    ctx->r15 = ADD32(ctx->r15, -0X5D54);
    // 0x80054E9C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80054EA0: addiu       $t6, $sp, 0xC4
    ctx->r14 = ADD32(ctx->r29, 0XC4);
    // 0x80054EA4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80054EA8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80054EAC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80054EB0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80054EB4: addiu       $t2, $t2, -0x5D48
    ctx->r10 = ADD32(ctx->r10, -0X5D48);
    // 0x80054EB8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80054EBC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80054EC0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80054EC4: addiu       $t1, $sp, 0xB8
    ctx->r9 = ADD32(ctx->r29, 0XB8);
    // 0x80054EC8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80054ECC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80054ED0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80054ED4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80054ED8: addiu       $t8, $t8, -0x5D3C
    ctx->r24 = ADD32(ctx->r24, -0X5D3C);
    // 0x80054EDC: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80054EE0: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80054EE4: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80054EE8: addiu       $t9, $sp, 0xAC
    ctx->r25 = ADD32(ctx->r29, 0XAC);
    // 0x80054EEC: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80054EF0: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80054EF4: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80054EF8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80054EFC: addiu       $t3, $t3, -0x5D30
    ctx->r11 = ADD32(ctx->r11, -0X5D30);
    // 0x80054F00: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80054F04: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80054F08: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80054F0C: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x80054F10: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80054F14: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80054F18: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80054F1C: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80054F20: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80054F24: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80054F28: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80054F2C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80054F30: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80054F34: lw          $v0, 0x1C4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1C4);
    // 0x80054F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054F3C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80054F40: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80054F44: lw          $t9, 0x79C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79C8);
    // 0x80054F48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80054F4C: slti        $at, $t9, 0xB
    ctx->r1 = SIGNED(ctx->r25) < 0XB ? 1 : 0;
    // 0x80054F50: bne         $at, $zero, L_800553C0
    if (ctx->r1 != 0) {
        // 0x80054F54: nop
    
            goto L_800553C0;
    }
    // 0x80054F54: nop

    // 0x80054F58: jal         0x800B8DD0
    // 0x80054F5C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80054F5C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x80054F60: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80054F64: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80054F68: addiu       $t1, $t1, 0x1418
    ctx->r9 = ADD32(ctx->r9, 0X1418);
    // 0x80054F6C: lw          $t0, 0x1C4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C4);
    // 0x80054F70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054F74: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80054F78: sll         $t2, $t0, 6
    ctx->r10 = S32(ctx->r8 << 6);
    // 0x80054F7C: jal         0x80005680
    // 0x80054F80: addu        $a1, $t2, $t1
    ctx->r5 = ADD32(ctx->r10, ctx->r9);
    Matrix_Copy(rdram, ctx);
        goto after_1;
    // 0x80054F80: addu        $a1, $t2, $t1
    ctx->r5 = ADD32(ctx->r10, ctx->r9);
    after_1:
    // 0x80054F84: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x80054F88: lw          $t3, 0x238($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X238);
    // 0x80054F8C: beq         $t3, $zero, L_80054FB8
    if (ctx->r11 == 0) {
        // 0x80054F90: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_80054FB8;
    }
    // 0x80054F90: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80054F94: lw          $t5, 0x7880($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7880);
    // 0x80054F98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054F9C: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x80054FA0: bne         $t5, $zero, L_80054FB8
    if (ctx->r13 != 0) {
        // 0x80054FA4: addiu       $a2, $sp, 0x94
        ctx->r6 = ADD32(ctx->r29, 0X94);
            goto L_80054FB8;
    }
    // 0x80054FA4: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80054FA8: jal         0x80006970
    // 0x80054FAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80054FAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_2:
    // 0x80054FB0: b           L_80054FCC
    // 0x80054FB4: nop

        goto L_80054FCC;
    // 0x80054FB4: nop

L_80054FB8:
    // 0x80054FB8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054FBC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80054FC0: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x80054FC4: jal         0x80006970
    // 0x80054FC8: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x80054FC8: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    after_3:
L_80054FCC:
    // 0x80054FCC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80054FD0: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80054FD4: jal         0x80005708
    // 0x80054FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x80054FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80054FDC: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80054FE0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80054FE4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80054FE8: lw          $t6, 0x1C4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X1C4);
    // 0x80054FEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80054FF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80054FF4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80054FF8: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80054FFC: lw          $t8, 0x79C8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X79C8);
    // 0x80055000: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055004: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80055008: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8005500C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80055010: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x80055014: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80055018: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005501C: jal         0x80005B00
    // 0x80055020: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80055020: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80055024: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80055028: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005502C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80055030: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055034: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055038: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005503C: jal         0x80005C34
    // 0x80055040: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x80055040: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x80055044: jal         0x80005708
    // 0x80055048: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x80055048: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8005504C: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
    // 0x80055050: lw          $t1, 0x238($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X238);
    // 0x80055054: beq         $t1, $zero, L_80055094
    if (ctx->r9 == 0) {
        // 0x80055058: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_80055094;
    }
    // 0x80055058: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8005505C: lw          $t4, 0x7880($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7880);
    // 0x80055060: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80055064: bnel        $t4, $zero, L_80055098
    if (ctx->r12 != 0) {
        // 0x80055068: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80055098;
    }
    goto skip_0;
    // 0x80055068: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_0:
    // 0x8005506C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055070: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80055074: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80055078: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005507C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055080: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80055084: jal         0x80005C34
    // 0x80055088: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x80055088: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_8:
    // 0x8005508C: b           L_800550BC
    // 0x80055090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800550BC;
    // 0x80055090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80055094:
    // 0x80055094: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80055098:
    // 0x80055098: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005509C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800550A0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800550A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800550A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800550AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800550B0: jal         0x80005C34
    // 0x800550B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x800550B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_9:
    // 0x800550B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800550BC:
    // 0x800550BC: jal         0x800B8DD0
    // 0x800550C0: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x800550C0: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_10:
    // 0x800550C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800550C8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800550CC: addiu       $t9, $zero, -0x80
    ctx->r25 = ADD32(0, -0X80);
    // 0x800550D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800550D4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800550D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800550DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800550E0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800550E4: lw          $t8, 0x78E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78E8);
    // 0x800550E8: beql        $t8, $zero, L_800551C4
    if (ctx->r24 == 0) {
        // 0x800550EC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_800551C4;
    }
    goto skip_1;
    // 0x800550EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800550F0: lw          $t0, 0xD0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD0);
    // 0x800550F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800550F8: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x800550FC: lw          $v0, 0x1C4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1C4);
    // 0x80055100: beql        $v0, $zero, L_80055134
    if (ctx->r2 == 0) {
        // 0x80055104: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80055134;
    }
    goto skip_2;
    // 0x80055104: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80055108: beq         $v0, $at, L_80055154
    if (ctx->r2 == ctx->r1) {
        // 0x8005510C: lui         $t5, 0xFB00
        ctx->r13 = S32(0XFB00 << 16);
            goto L_80055154;
    }
    // 0x8005510C: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80055110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055114: beq         $v0, $at, L_80055178
    if (ctx->r2 == ctx->r1) {
        // 0x80055118: lui         $t9, 0xFB00
        ctx->r25 = S32(0XFB00 << 16);
            goto L_80055178;
    }
    // 0x80055118: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8005511C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80055120: beq         $v0, $at, L_8005519C
    if (ctx->r2 == ctx->r1) {
        // 0x80055124: lui         $t2, 0xFB00
        ctx->r10 = S32(0XFB00 << 16);
            goto L_8005519C;
    }
    // 0x80055124: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80055128: b           L_800551E0
    // 0x8005512C: nop

        goto L_800551E0;
    // 0x8005512C: nop

    // 0x80055130: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80055134:
    // 0x80055134: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x80055138: ori         $t4, $t4, 0x2080
    ctx->r12 = ctx->r12 | 0X2080;
    // 0x8005513C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80055140: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80055144: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80055148: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005514C: b           L_800551E0
    // 0x80055150: nop

        goto L_800551E0;
    // 0x80055150: nop

L_80055154:
    // 0x80055154: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055158: lui         $t7, 0xFF20
    ctx->r15 = S32(0XFF20 << 16);
    // 0x8005515C: ori         $t7, $t7, 0x2080
    ctx->r15 = ctx->r15 | 0X2080;
    // 0x80055160: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80055164: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80055168: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005516C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80055170: b           L_800551E0
    // 0x80055174: nop

        goto L_800551E0;
    // 0x80055174: nop

L_80055178:
    // 0x80055178: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005517C: lui         $t8, 0x20FF
    ctx->r24 = S32(0X20FF << 16);
    // 0x80055180: ori         $t8, $t8, 0x2080
    ctx->r24 = ctx->r24 | 0X2080;
    // 0x80055184: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80055188: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005518C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80055190: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80055194: b           L_800551E0
    // 0x80055198: nop

        goto L_800551E0;
    // 0x80055198: nop

L_8005519C:
    // 0x8005519C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800551A0: lui         $t1, 0x2020
    ctx->r9 = S32(0X2020 << 16);
    // 0x800551A4: ori         $t1, $t1, 0xFF80
    ctx->r9 = ctx->r9 | 0XFF80;
    // 0x800551A8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800551AC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800551B0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800551B4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800551B8: b           L_800551E0
    // 0x800551BC: nop

        goto L_800551E0;
    // 0x800551BC: nop

    // 0x800551C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_800551C4:
    // 0x800551C4: lui         $t5, 0xFF
    ctx->r13 = S32(0XFF << 16);
    // 0x800551C8: ori         $t5, $t5, 0x80
    ctx->r13 = ctx->r13 | 0X80;
    // 0x800551CC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800551D0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800551D4: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x800551D8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800551DC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800551E0:
    // 0x800551E0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800551E4: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800551E8: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x800551EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800551F0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800551F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800551F8: lwc1        $f6, 0x5EB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EB4);
    // 0x800551FC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80055200: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055204: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055208: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005520C: nop

    // 0x80055210: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80055214: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80055218: jal         0x80005FE0
    // 0x8005521C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x8005521C: nop

    after_11:
    // 0x80055220: jal         0x80006EB8
    // 0x80055224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_12;
    // 0x80055224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80055228: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005522C: lui         $a3, 0x102
    ctx->r7 = S32(0X102 << 16);
    // 0x80055230: addiu       $a3, $a3, -0x3D20
    ctx->r7 = ADD32(ctx->r7, -0X3D20);
    // 0x80055234: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80055238: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005523C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80055240: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80055244: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80055248: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8005524C: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80055250: lui         $at, 0xC254
    ctx->r1 = S32(0XC254 << 16);
    // 0x80055254: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80055258: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8005525C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055260: lwc1        $f6, 0x5EB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EB8);
    // 0x80055264: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80055268: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005526C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055270: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80055274: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80055278: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8005527C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80055280: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80055284: jal         0x80005FE0
    // 0x80055288: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_13;
    // 0x80055288: nop

    after_13:
    // 0x8005528C: jal         0x80006EB8
    // 0x80055290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x80055290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80055294: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055298: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005529C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800552A0: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800552A4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800552A8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800552AC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800552B0: jal         0x80005740
    // 0x800552B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x800552B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800552B8: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x800552BC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800552C0: lw          $t3, 0x238($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X238);
    // 0x800552C4: beql        $t3, $zero, L_80055300
    if (ctx->r11 == 0) {
        // 0x800552C8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80055300;
    }
    goto skip_3;
    // 0x800552C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_3:
    // 0x800552CC: lw          $t5, 0x7880($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7880);
    // 0x800552D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800552D4: bnel        $t5, $zero, L_80055300
    if (ctx->r13 != 0) {
        // 0x800552D8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80055300;
    }
    goto skip_4;
    // 0x800552D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_4:
    // 0x800552DC: lwc1        $f0, 0x5EBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5EBC);
    // 0x800552E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800552E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800552E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800552EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800552F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800552F4: jal         0x80005C34
    // 0x800552F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_16;
    // 0x800552F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_16:
    // 0x800552FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80055300:
    // 0x80055300: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055304: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055308: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005530C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055310: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055314: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055318: jal         0x80005C34
    // 0x8005531C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_17;
    // 0x8005531C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_17:
    // 0x80055320: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80055324: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80055328: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005532C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80055330: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x80055334: bne         $t8, $zero, L_80055364
    if (ctx->r24 != 0) {
        // 0x80055338: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80055364;
    }
    // 0x80055338: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8005533C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055340: lwc1        $f0, 0x5EC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5EC0);
    // 0x80055344: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055348: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8005534C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055350: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055354: jal         0x80005C34
    // 0x80055358: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    Matrix_Scale(rdram, ctx);
        goto after_18;
    // 0x80055358: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_18:
    // 0x8005535C: b           L_80055380
    // 0x80055360: nop

        goto L_80055380;
    // 0x80055360: nop

L_80055364:
    // 0x80055364: lwc1        $f0, 0x5EC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5EC4);
    // 0x80055368: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005536C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80055370: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055374: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055378: jal         0x80005C34
    // 0x8005537C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_19;
    // 0x8005537C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_19:
L_80055380:
    // 0x80055380: jal         0x80006EB8
    // 0x80055384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_20;
    // 0x80055384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80055388: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005538C: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x80055390: addiu       $t3, $t3, 0x4AC0
    ctx->r11 = ADD32(ctx->r11, 0X4AC0);
    // 0x80055394: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80055398: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8005539C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800553A0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800553A4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800553A8: jal         0x80005740
    // 0x800553AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_21;
    // 0x800553AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x800553B0: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x800553B4: lw          $v0, 0x1C4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X1C4);
    // 0x800553B8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800553BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800553C0:
    // 0x800553C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800553C4: lwc1        $f10, 0x5EC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5EC8);
    // 0x800553C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800553CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800553D0: lwc1        $f16, 0x7AA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7AA0);
    // 0x800553D4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800553D8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800553DC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800553E0: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x800553E4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800553E8: bc1fl       L_80055778
    if (!c1cs) {
        // 0x800553EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80055778;
    }
    goto skip_5;
    // 0x800553EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800553F0: jal         0x80005708
    // 0x800553F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_22;
    // 0x800553F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x800553F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800553FC: jal         0x800B8DD0
    // 0x80055400: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_23;
    // 0x80055400: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_23:
    // 0x80055404: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x80055408: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005540C: addiu       $t0, $t0, 0x1418
    ctx->r8 = ADD32(ctx->r8, 0X1418);
    // 0x80055410: lw          $t9, 0x1C4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C4);
    // 0x80055414: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055418: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005541C: sll         $t8, $t9, 6
    ctx->r24 = S32(ctx->r25 << 6);
    // 0x80055420: jal         0x80005680
    // 0x80055424: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    Matrix_Copy(rdram, ctx);
        goto after_24;
    // 0x80055424: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    after_24:
    // 0x80055428: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
    // 0x8005542C: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80055430: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80055434: lwc1        $f4, 0x4B0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4B0);
    // 0x80055438: lw          $t1, 0x1C4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X1C4);
    // 0x8005543C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80055440: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80055444: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x80055448: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8005544C: lbu         $v1, 0x1AAB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1AAB);
    // 0x80055450: bc1f        L_8005545C
    if (!c1cs) {
        // 0x80055454: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_8005545C;
    }
    // 0x80055454: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80055458: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005545C:
    // 0x8005545C: beq         $v1, $zero, L_80055484
    if (ctx->r3 == 0) {
        // 0x80055460: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80055484;
    }
    // 0x80055460: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80055464: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80055468: beq         $v1, $at, L_800555A4
    if (ctx->r3 == ctx->r1) {
        // 0x8005546C: lui         $t1, 0x102
        ctx->r9 = S32(0X102 << 16);
            goto L_800555A4;
    }
    // 0x8005546C: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x80055470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055474: beq         $v1, $at, L_800555A4
    if (ctx->r3 == ctx->r1) {
        // 0x80055478: nop
    
            goto L_800555A4;
    }
    // 0x80055478: nop

    // 0x8005547C: b           L_8005576C
    // 0x80055480: nop

        goto L_8005576C;
    // 0x80055480: nop

L_80055484:
    // 0x80055484: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055488: lui         $t7, 0xC0FF
    ctx->r15 = S32(0XC0FF << 16);
    // 0x8005548C: ori         $t7, $t7, 0xC080
    ctx->r15 = ctx->r15 | 0XC080;
    // 0x80055490: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80055494: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80055498: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005549C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800554A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800554A4: lui         $t8, 0x40FF
    ctx->r24 = S32(0X40FF << 16);
    // 0x800554A8: ori         $t8, $t8, 0x4080
    ctx->r24 = ctx->r24 | 0X4080;
    // 0x800554AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800554B0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800554B4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800554B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800554BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800554C0: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x800554C4: lui         $t0, 0x102
    ctx->r8 = S32(0X102 << 16);
    // 0x800554C8: addiu       $t0, $t0, 0x4AC0
    ctx->r8 = ADD32(ctx->r8, 0X4AC0);
    // 0x800554CC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800554D0: lw          $t4, 0x238($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X238);
    // 0x800554D4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800554D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800554DC: beq         $t4, $zero, L_8005550C
    if (ctx->r12 == 0) {
        // 0x800554E0: addiu       $a1, $sp, 0xC4
        ctx->r5 = ADD32(ctx->r29, 0XC4);
            goto L_8005550C;
    }
    // 0x800554E0: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x800554E4: lw          $t2, 0x7880($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7880);
    // 0x800554E8: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x800554EC: bne         $t2, $zero, L_8005550C
    if (ctx->r10 != 0) {
        // 0x800554F0: nop
    
            goto L_8005550C;
    }
    // 0x800554F0: nop

    // 0x800554F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800554F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800554FC: jal         0x80006970
    // 0x80055500: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_25;
    // 0x80055500: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_25:
    // 0x80055504: b           L_80055518
    // 0x80055508: nop

        goto L_80055518;
    // 0x80055508: nop

L_8005550C:
    // 0x8005550C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055510: jal         0x80006970
    // 0x80055514: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    Matrix_MultVec3f(rdram, ctx);
        goto after_26;
    // 0x80055514: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    after_26:
L_80055518:
    // 0x80055518: jal         0x80005708
    // 0x8005551C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_27;
    // 0x8005551C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x80055520: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055524: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80055528: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x8005552C: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x80055530: jal         0x80005B00
    // 0x80055534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_28;
    // 0x80055534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_28:
    // 0x80055538: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x8005553C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80055540: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055544: lw          $t5, 0x1C4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C4);
    // 0x80055548: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005554C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055550: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80055554: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80055558: lwc1        $f0, 0x7AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AA0);
    // 0x8005555C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80055560: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055564: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055568: jal         0x80005C34
    // 0x8005556C: nop

    Matrix_Scale(rdram, ctx);
        goto after_29;
    // 0x8005556C: nop

    after_29:
    // 0x80055570: jal         0x80006EB8
    // 0x80055574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_30;
    // 0x80055574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80055578: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005557C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80055580: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80055584: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80055588: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005558C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80055590: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80055594: jal         0x80005740
    // 0x80055598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_31;
    // 0x80055598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
    // 0x8005559C: b           L_8005576C
    // 0x800555A0: nop

        goto L_8005576C;
    // 0x800555A0: nop

L_800555A4:
    // 0x800555A4: addiu       $t1, $t1, 0x4AC0
    ctx->r9 = ADD32(ctx->r9, 0X4AC0);
    // 0x800555A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800555AC: bne         $v0, $at, L_800555FC
    if (ctx->r2 != ctx->r1) {
        // 0x800555B0: sw          $t1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r9;
            goto L_800555FC;
    }
    // 0x800555B0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800555B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800555B8: lui         $t3, 0xC0FF
    ctx->r11 = S32(0XC0FF << 16);
    // 0x800555BC: ori         $t3, $t3, 0xC080
    ctx->r11 = ctx->r11 | 0XC080;
    // 0x800555C0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800555C4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800555C8: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800555CC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800555D0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800555D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800555D8: lui         $t6, 0x40FF
    ctx->r14 = S32(0X40FF << 16);
    // 0x800555DC: ori         $t6, $t6, 0x4080
    ctx->r14 = ctx->r14 | 0X4080;
    // 0x800555E0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800555E4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800555E8: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800555EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800555F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800555F4: b           L_8005563C
    // 0x800555F8: nop

        goto L_8005563C;
    // 0x800555F8: nop

L_800555FC:
    // 0x800555FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055600: lui         $t0, 0x80FF
    ctx->r8 = S32(0X80FF << 16);
    // 0x80055604: ori         $t0, $t0, 0xFFA0
    ctx->r8 = ctx->r8 | 0XFFA0;
    // 0x80055608: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005560C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80055610: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80055614: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80055618: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8005561C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055620: lui         $t2, 0x8080
    ctx->r10 = S32(0X8080 << 16);
    // 0x80055624: ori         $t2, $t2, 0xFFA0
    ctx->r10 = ctx->r10 | 0XFFA0;
    // 0x80055628: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005562C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80055630: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80055634: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80055638: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_8005563C:
    // 0x8005563C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055640: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055644: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80055648: jal         0x80006970
    // 0x8005564C: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    Matrix_MultVec3f(rdram, ctx);
        goto after_32;
    // 0x8005564C: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    after_32:
    // 0x80055650: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055654: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055658: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x8005565C: jal         0x80006970
    // 0x80055660: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    Matrix_MultVec3f(rdram, ctx);
        goto after_33;
    // 0x80055660: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_33:
    // 0x80055664: jal         0x80005708
    // 0x80055668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_34;
    // 0x80055668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x8005566C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055670: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80055674: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80055678: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8005567C: jal         0x80005B00
    // 0x80055680: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_35;
    // 0x80055680: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_35:
    // 0x80055684: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x80055688: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005568C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055690: lw          $t5, 0x1C4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C4);
    // 0x80055694: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80055698: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005569C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800556A0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800556A4: lwc1        $f0, 0x7AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AA0);
    // 0x800556A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800556AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800556B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800556B4: jal         0x80005C34
    // 0x800556B8: nop

    Matrix_Scale(rdram, ctx);
        goto after_36;
    // 0x800556B8: nop

    after_36:
    // 0x800556BC: jal         0x80006EB8
    // 0x800556C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_37;
    // 0x800556C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x800556C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800556C8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800556CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800556D0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800556D4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800556D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800556DC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800556E0: jal         0x80005740
    // 0x800556E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_38;
    // 0x800556E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_38:
    // 0x800556E8: jal         0x80005708
    // 0x800556EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_39;
    // 0x800556EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_39:
    // 0x800556F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800556F4: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x800556F8: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x800556FC: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x80055700: jal         0x80005B00
    // 0x80055704: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_40;
    // 0x80055704: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_40:
    // 0x80055708: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x8005570C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80055710: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80055714: lw          $t4, 0x1C4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X1C4);
    // 0x80055718: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005571C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055720: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x80055724: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80055728: lwc1        $f0, 0x7AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AA0);
    // 0x8005572C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80055730: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055734: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055738: jal         0x80005C34
    // 0x8005573C: nop

    Matrix_Scale(rdram, ctx);
        goto after_41;
    // 0x8005573C: nop

    after_41:
    // 0x80055740: jal         0x80006EB8
    // 0x80055744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_42;
    // 0x80055744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80055748: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005574C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80055750: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80055754: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80055758: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005575C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80055760: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80055764: jal         0x80005740
    // 0x80055768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_43;
    // 0x80055768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_43:
L_8005576C:
    // 0x8005576C: jal         0x80005740
    // 0x80055770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_44;
    // 0x80055770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_44:
    // 0x80055774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055778:
    // 0x80055778: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005577C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80055780: jr          $ra
    // 0x80055784: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80055784: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void Effect_Effect390_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C08C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007C090: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007C094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007C09C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007C0A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007C0A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007C0A8: jal         0x80061474
    // 0x8007C0AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007C0AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007C0B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007C0B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C0B8: addiu       $t7, $zero, 0x186
    ctx->r15 = ADD32(0, 0X186);
    // 0x8007C0BC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007C0C0: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007C0C4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007C0C8: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007C0CC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007C0D0: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007C0D4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007C0D8: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007C0DC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007C0E0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007C0E4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007C0E8: swc1        $f10, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f10.u32l;
    // 0x8007C0EC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007C0F0: swc1        $f16, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f16.u32l;
    // 0x8007C0F4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007C0F8: swc1        $f18, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f18.u32l;
    // 0x8007C0FC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007C100: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
    // 0x8007C104: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007C108: jal         0x800612B8
    // 0x8007C10C: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007C10C: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    after_1:
    // 0x8007C110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C118: jr          $ra
    // 0x8007C11C: nop

    return;
    // 0x8007C11C: nop

;}
RECOMP_FUNC void MeteoBall_IsCloseToPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ABA4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8006ABA8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006ABAC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006ABB0: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006ABB4: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006ABB8: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8006ABBC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006ABC0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006ABC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006ABC8: nop

    // 0x8006ABCC: bc1fl       L_8006AC00
    if (!c1cs) {
        // 0x8006ABD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006AC00;
    }
    goto skip_0;
    // 0x8006ABD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8006ABD4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006ABD8: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8006ABDC: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006ABE0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006ABE4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006ABE8: nop

    // 0x8006ABEC: bc1fl       L_8006AC00
    if (!c1cs) {
        // 0x8006ABF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006AC00;
    }
    goto skip_1;
    // 0x8006ABF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8006ABF4: jr          $ra
    // 0x8006ABF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006ABF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006ABFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006AC00:
    // 0x8006AC00: jr          $ra
    // 0x8006AC04: nop

    return;
    // 0x8006AC04: nop

;}
RECOMP_FUNC void CoRadar_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BA30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BA34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BA38: lhu         $t6, 0xBC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XBC);
    // 0x8005BA3C: beq         $t6, $zero, L_8005BA74
    if (ctx->r14 == 0) {
        // 0x8005BA40: nop
    
            goto L_8005BA74;
    }
    // 0x8005BA40: nop

    // 0x8005BA44: jal         0x800BA400
    // 0x8005BA48: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_0;
    // 0x8005BA48: nop

    after_0:
    // 0x8005BA4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005BA50: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005BA54: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA58: lui         $t9, 0xFF00
    ctx->r25 = S32(0XFF00 << 16);
    // 0x8005BA5C: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x8005BA60: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005BA64: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005BA68: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8005BA6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005BA70: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8005BA74:
    // 0x8005BA74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005BA78: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005BA7C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA80: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x8005BA84: addiu       $t2, $t2, 0xB40
    ctx->r10 = ADD32(ctx->r10, 0XB40);
    // 0x8005BA88: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8005BA8C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8005BA90: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005BA94: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005BA98: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8005BA9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BAA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BAA4: jr          $ra
    // 0x8005BAA8: nop

    return;
    // 0x8005BAA8: nop

;}
RECOMP_FUNC void guLookAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021488: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002148C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80021490: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80021494: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80021498: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8002149C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800214A0: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800214A4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800214A8: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800214AC: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800214B0: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800214B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800214B8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800214BC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800214C0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800214C4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800214C8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800214CC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800214D0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800214D4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800214D8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800214DC: jal         0x800211D0
    // 0x800214E0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    guLookAtF(rdram, ctx);
        goto after_0;
    // 0x800214E0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800214E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800214E8: jal         0x80026CD0
    // 0x800214EC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800214EC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x800214F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800214F4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800214F8: jr          $ra
    // 0x800214FC: nop

    return;
    // 0x800214FC: nop

;}
RECOMP_FUNC void Camera_UpdateArwing360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B63BC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800B63C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B63C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B63C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B63CC: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800B63D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B63D4: lwc1        $f6, -0x7574($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7574);
    // 0x800B63D8: lwc1        $f4, 0x134($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B63DC: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800B63E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B63E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B63E8: lwc1        $f6, -0x7570($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7570);
    // 0x800B63EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B63F0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B63F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B63F8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B63FC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B6400: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B6404: jal         0x80005E90
    // 0x800B6408: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x800B6408: nop

    after_0:
    // 0x800B640C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6410: lwc1        $f4, -0x756C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X756C);
    // 0x800B6414: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B6418: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B641C: lwc1        $f10, -0x7568($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7568);
    // 0x800B6420: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800B6424: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B6428: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B642C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B6430: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B6434: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B6438: jal         0x80005D44
    // 0x800B643C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x800B643C: nop

    after_1:
    // 0x800B6440: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B6444: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B6448: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x800B644C: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x800B6450: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x800B6454: lw          $t6, 0x238($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X238);
    // 0x800B6458: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x800B645C: beq         $t6, $zero, L_800B6478
    if (ctx->r14 == 0) {
        // 0x800B6460: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_800B6478;
    }
    // 0x800B6460: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800B6464: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B6468: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800B646C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B6470: b           L_800B648C
    // 0x800B6474: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
        goto L_800B648C;
    // 0x800B6474: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
L_800B6478:
    // 0x800B6478: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800B647C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6480: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800B6484: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800B6488: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
L_800B648C:
    // 0x800B648C: lw          $t7, 0x4DC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B6490: beq         $t7, $zero, L_800B64A8
    if (ctx->r15 == 0) {
        // 0x800B6494: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_800B64A8;
    }
    // 0x800B6494: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800B6498: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B649C: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B64A0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B64A4: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
L_800B64A8:
    // 0x800B64A8: jal         0x80006A20
    // 0x800B64AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x800B64AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_2:
    // 0x800B64B0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B64B4: lw          $t8, 0x78E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78E8);
    // 0x800B64B8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B64BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B64C0: bne         $t8, $zero, L_800B64E4
    if (ctx->r24 != 0) {
        // 0x800B64C4: addiu       $a0, $s0, 0x2C
        ctx->r4 = ADD32(ctx->r16, 0X2C);
            goto L_800B64E4;
    }
    // 0x800B64C4: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800B64C8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B64CC: lw          $t9, 0x797C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X797C);
    // 0x800B64D0: lb          $t0, 0x3($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X3);
    // 0x800B64D4: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x800B64D8: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800B64DC: b           L_800B6510
    // 0x800B64E0: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
        goto L_800B6510;
    // 0x800B64E0: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
L_800B64E4:
    // 0x800B64E4: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B64E8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B64EC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B64F0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800B64F4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800B64F8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B64FC: lb          $t4, -0x2765($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X2765);
    // 0x800B6500: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800B6504: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800B6508: nop

    // 0x800B650C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
L_800B6510:
    // 0x800B6510: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B6514: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B6518: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B651C: jal         0x8009BC2C
    // 0x800B6520: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800B6520: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800B6524: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B6528: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B652C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B6530: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x800B6534: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800B6538: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B653C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B6540: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x800B6544: lwc1        $f10, 0x148($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X148);
    // 0x800B6548: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B654C: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B6550: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800B6554: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800B6558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B655C: nop

    // 0x800B6560: mul.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800B6564: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800B6568: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B656C: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800B6570: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800B6574: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800B6578: lwc1        $f12, 0x134($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B657C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800B6580: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800B6584: lw          $t6, 0x4DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B6588: beq         $t6, $zero, L_800B659C
    if (ctx->r14 == 0) {
        // 0x800B658C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B659C;
    }
    // 0x800B658C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B6590: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B6594: b           L_800B65A8
    // 0x800B6598: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
        goto L_800B65A8;
    // 0x800B6598: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_800B659C:
    // 0x800B659C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B65A0: lwc1        $f0, -0x7564($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7564);
    // 0x800B65A4: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_800B65A8:
    // 0x800B65A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B65AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B65B0: lwc1        $f10, 0x60($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800B65B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B65B8: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B65BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B65C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B65C4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B65C8: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800B65CC: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800B65D0: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B65D4: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B65D8: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800B65DC: lw          $t7, 0x1C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B65E0: bnel        $t7, $at, L_800B65F0
    if (ctx->r15 != ctx->r1) {
        // 0x800B65E4: swc1        $f16, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
            goto L_800B65F0;
    }
    goto skip_0;
    // 0x800B65E4: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    skip_0:
    // 0x800B65E8: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800B65EC: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
L_800B65F0:
    // 0x800B65F0: lwc1        $f0, 0xE8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B65F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B65F8: lwc1        $f4, -0x7560($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7560);
    // 0x800B65FC: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B6600: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B6604: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6608: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800B660C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B6610: jal         0x8009BC2C
    // 0x800B6614: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B6614: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x800B6618: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B661C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B6620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B6624: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x800B6628: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B662C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x800B6630: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B6634: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x800B6638: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x800B663C: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x800B6640: jal         0x80006A20
    // 0x800B6644: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x800B6644: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800B6648: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B664C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B6650: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B6654: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B6658: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B665C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B6660: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800B6664: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x800B6668: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B666C: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800B6670: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x800B6674: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800B6678: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B667C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B6680: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B6684: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800B6688: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B668C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800B6690: lw          $t8, 0x1C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B6694: bnel        $t8, $at, L_800B6750
    if (ctx->r24 != ctx->r1) {
        // 0x800B6698: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_800B6750;
    }
    goto skip_1;
    // 0x800B6698: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x800B669C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B66A0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B66A4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B66A8: jal         0x8009BC2C
    // 0x800B66AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B66AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x800B66B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B66B4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B66B8: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800B66BC: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x800B66C0: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800B66C4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800B66C8: jal         0x8009BC2C
    // 0x800B66CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B66CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x800B66D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B66D4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B66D8: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800B66DC: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x800B66E0: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800B66E4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800B66E8: jal         0x8009BC2C
    // 0x800B66EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800B66EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x800B66F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B66F4: lwc1        $f6, -0x755C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X755C);
    // 0x800B66F8: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B66FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B6700: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B6704: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800B6708: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B670C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800B6710: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B6714: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B6718: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B671C: jal         0x8009BC2C
    // 0x800B6720: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B6720: nop

    after_9:
    // 0x800B6724: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B6728: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800B672C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B6730: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x800B6734: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x800B6738: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B673C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B6740: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800B6744: jal         0x8009BC2C
    // 0x800B6748: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800B6748: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x800B674C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_800B6750:
    // 0x800B6750: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x800B6754: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800B6758: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x800B675C: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x800B6760: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B6764: jal         0x8009BC2C
    // 0x800B6768: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800B6768: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x800B676C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B6770: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x800B6774: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800B6778: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x800B677C: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x800B6780: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B6784: jal         0x8009BC2C
    // 0x800B6788: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x800B6788: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x800B678C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B6790: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x800B6794: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800B6798: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x800B679C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x800B67A0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B67A4: jal         0x8009BC2C
    // 0x800B67A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x800B67A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x800B67AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B67B0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800B67B4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B67B8: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x800B67BC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x800B67C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B67C4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B67C8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x800B67CC: jal         0x8009BC2C
    // 0x800B67D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x800B67D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x800B67D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B67D8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B67DC: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x800B67E0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x800B67E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B67E8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800B67EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800B67F0: jal         0x8009BC2C
    // 0x800B67F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x800B67F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x800B67F8: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x800B67FC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B6800: beql        $t9, $zero, L_800B6838
    if (ctx->r25 == 0) {
        // 0x800B6804: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B6838;
    }
    goto skip_2;
    // 0x800B6804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800B6808: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x800B680C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B6810: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x800B6814: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B6818: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x800B681C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B6820: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x800B6824: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B6828: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x800B682C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B6830: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x800B6834: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B6838:
    // 0x800B6838: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B683C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x800B6840: jr          $ra
    // 0x800B6844: nop

    return;
    // 0x800B6844: nop

;}
RECOMP_FUNC void Effect_Effect384_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007B348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007B34C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007B350: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007B354: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007B358: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007B35C: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007B360: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007B364: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007B368:
    // 0x8007B368: bnel        $t6, $zero, L_8007B39C
    if (ctx->r14 != 0) {
        // 0x8007B36C: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007B39C;
    }
    goto skip_0;
    // 0x8007B36C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007B370: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007B374: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007B378: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007B37C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007B380: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007B384: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007B388: jal         0x8007B2BC
    // 0x8007B38C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Effect_Effect384_Setup(rdram, ctx);
        goto after_0;
    // 0x8007B38C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007B390: b           L_8007B3AC
    // 0x8007B394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007B3AC;
    // 0x8007B394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B398: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007B39C:
    // 0x8007B39C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007B3A0: beql        $at, $zero, L_8007B368
    if (ctx->r1 == 0) {
        // 0x8007B3A4: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007B368;
    }
    goto skip_1;
    // 0x8007B3A4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007B3A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007B3AC:
    // 0x8007B3AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007B3B0: jr          $ra
    // 0x8007B3B4: nop

    return;
    // 0x8007B3B4: nop

;}
RECOMP_FUNC void Audio_GetVibratoPitchChange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800137DC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800137E0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800137E4: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x800137E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800137EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800137F0: nop

    // 0x800137F4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800137F8: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x800137FC: andi        $t1, $t0, 0x3F
    ctx->r9 = ctx->r8 & 0X3F;
    // 0x80013800: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80013804: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80013808: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001380C: lh          $v0, 0x0($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X0);
    // 0x80013810: sra         $t5, $v0, 8
    ctx->r13 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80013814: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x80013818: jr          $ra
    // 0x8001381C: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    return;
    // 0x8001381C: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
;}
RECOMP_FUNC void AudioLoad_StartAsyncLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010AD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010ADC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80010AE0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80010AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010AE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80010AEC: addiu       $v1, $v1, 0x4248
    ctx->r3 = ADD32(ctx->r3, 0X4248);
    // 0x80010AF0: addiu       $v0, $v0, 0x3D08
    ctx->r2 = ADD32(ctx->r2, 0X3D08);
    // 0x80010AF4: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
L_80010AF8:
    // 0x80010AF8: bnel        $t6, $zero, L_80010B0C
    if (ctx->r14 != 0) {
        // 0x80010AFC: addiu       $v0, $v0, 0x54
        ctx->r2 = ADD32(ctx->r2, 0X54);
            goto L_80010B0C;
    }
    goto skip_0;
    // 0x80010AFC: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    skip_0:
    // 0x80010B00: b           L_80010B18
    // 0x80010B04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80010B18;
    // 0x80010B04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80010B08: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
L_80010B0C:
    // 0x80010B0C: bnel        $v0, $v1, L_80010AF8
    if (ctx->r2 != ctx->r3) {
        // 0x80010B10: lb          $t6, 0x0($v0)
        ctx->r14 = MEM_B(ctx->r2, 0X0);
            goto L_80010AF8;
    }
    goto skip_1;
    // 0x80010B10: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    skip_1:
    // 0x80010B14: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80010B18:
    // 0x80010B18: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80010B1C: addiu       $t7, $t7, 0x4248
    ctx->r15 = ADD32(ctx->r15, 0X4248);
    // 0x80010B20: bne         $v0, $t7, L_80010B30
    if (ctx->r2 != ctx->r15) {
        // 0x80010B24: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80010B30;
    }
    // 0x80010B24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80010B28: b           L_80010BE0
    // 0x80010B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80010BE0;
    // 0x80010B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80010B30:
    // 0x80010B30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80010B34: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80010B38: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80010B3C: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80010B40: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x80010B44: sw          $a2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r6;
    // 0x80010B48: bne         $a0, $zero, L_80010B5C
    if (ctx->r4 != 0) {
        // 0x80010B4C: sw          $t9, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r25;
            goto L_80010B5C;
    }
    // 0x80010B4C: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x80010B50: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x80010B54: b           L_80010BAC
    // 0x80010B58: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
        goto L_80010BAC;
    // 0x80010B58: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
L_80010B5C:
    // 0x80010B5C: div         $zero, $a2, $a0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r4)));
    // 0x80010B60: bne         $a0, $zero, L_80010B6C
    if (ctx->r4 != 0) {
        // 0x80010B64: nop
    
            goto L_80010B6C;
    }
    // 0x80010B64: nop

    // 0x80010B68: break       7
    do_break(2147552104);
L_80010B6C:
    // 0x80010B6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010B70: bne         $a0, $at, L_80010B84
    if (ctx->r4 != ctx->r1) {
        // 0x80010B74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010B84;
    }
    // 0x80010B74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010B78: bne         $a2, $at, L_80010B84
    if (ctx->r6 != ctx->r1) {
        // 0x80010B7C: nop
    
            goto L_80010B84;
    }
    // 0x80010B7C: nop

    // 0x80010B80: break       6
    do_break(2147552128);
L_80010B84:
    // 0x80010B84: mflo        $v0
    ctx->r2 = lo;
    // 0x80010B88: addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // 0x80010B8C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80010B90: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80010B94: sltiu       $at, $t1, 0x100
    ctx->r1 = ctx->r9 < 0X100 ? 1 : 0;
    // 0x80010B98: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80010B9C: beq         $at, $zero, L_80010BAC
    if (ctx->r1 == 0) {
        // 0x80010BA0: sw          $t1, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r9;
            goto L_80010BAC;
    }
    // 0x80010BA0: sw          $t1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r9;
    // 0x80010BA4: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x80010BA8: sw          $t2, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r10;
L_80010BAC:
    // 0x80010BAC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80010BB0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80010BB4: sb          $t4, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r12;
    // 0x80010BB8: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
    // 0x80010BBC: sw          $t3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r11;
    // 0x80010BC0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80010BC4: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    // 0x80010BC8: addiu       $a1, $v1, 0x38
    ctx->r5 = ADD32(ctx->r3, 0X38);
    // 0x80010BCC: sw          $t5, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r13;
    // 0x80010BD0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80010BD4: jal         0x80021CF0
    // 0x80010BD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80010BD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80010BDC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80010BE0:
    // 0x80010BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010BE8: jr          $ra
    // 0x80010BEC: nop

    return;
    // 0x80010BEC: nop

;}
RECOMP_FUNC void RadarMark_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6118: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A611C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x800A6120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A6124:
    // 0x800A6124: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A6128: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800A612C: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800A6130: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A6134: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A6138: bne         $v1, $a0, L_800A6124
    if (ctx->r3 != ctx->r4) {
        // 0x800A613C: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800A6124;
    }
    // 0x800A613C: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800A6140: jr          $ra
    // 0x800A6144: nop

    return;
    // 0x800A6144: nop

;}
RECOMP_FUNC void Effect_Effect394_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080AD4: lh          $v0, 0x78($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X78);
    // 0x80080AD8: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80080ADC: bne         $at, $zero, L_80080AFC
    if (ctx->r1 != 0) {
        // 0x80080AE0: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_80080AFC;
    }
    // 0x80080AE0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80080AE4: beq         $v0, $at, L_80080CDC
    if (ctx->r2 == ctx->r1) {
        // 0x80080AE8: addiu       $at, $zero, 0x66
        ctx->r1 = ADD32(0, 0X66);
            goto L_80080CDC;
    }
    // 0x80080AE8: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80080AEC: beq         $v0, $at, L_80080CEC
    if (ctx->r2 == ctx->r1) {
        // 0x80080AF0: nop
    
            goto L_80080CEC;
    }
    // 0x80080AF0: nop

    // 0x80080AF4: b           L_80080CF8
    // 0x80080AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80080CF8;
    // 0x80080AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080AFC:
    // 0x80080AFC: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80080B00: bne         $at, $zero, L_80080B18
    if (ctx->r1 != 0) {
        // 0x80080B04: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80080B18;
    }
    // 0x80080B04: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80080B08: beq         $v0, $at, L_80080CCC
    if (ctx->r2 == ctx->r1) {
        // 0x80080B0C: nop
    
            goto L_80080CCC;
    }
    // 0x80080B0C: nop

    // 0x80080B10: b           L_80080CF8
    // 0x80080B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80080CF8;
    // 0x80080B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080B18:
    // 0x80080B18: sltiu       $at, $v0, 0x11
    ctx->r1 = ctx->r2 < 0X11 ? 1 : 0;
    // 0x80080B1C: beq         $at, $zero, L_80080CF4
    if (ctx->r1 == 0) {
        // 0x80080B20: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80080CF4;
    }
    // 0x80080B20: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80080B24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080B28: addu        $at, $at, $t6
    gpr jr_addend_80080B30 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80080B2C: lw          $t6, 0x74E0($at)
    ctx->r14 = ADD32(ctx->r1, 0X74E0);
    // 0x80080B30: jr          $t6
    // 0x80080B34: nop

    switch (jr_addend_80080B30 >> 2) {
        case 0: goto L_80080CF4; break;
        case 1: goto L_80080B38; break;
        case 2: goto L_80080CF4; break;
        case 3: goto L_80080CF4; break;
        case 4: goto L_80080CF4; break;
        case 5: goto L_80080CF4; break;
        case 6: goto L_80080CF4; break;
        case 7: goto L_80080CF4; break;
        case 8: goto L_80080CF4; break;
        case 9: goto L_80080CF4; break;
        case 10: goto L_80080B48; break;
        case 11: goto L_80080BD8; break;
        case 12: goto L_80080C3C; break;
        case 13: goto L_80080CF4; break;
        case 14: goto L_80080CF4; break;
        case 15: goto L_80080CF4; break;
        case 16: goto L_80080CF4; break;
        default: switch_error(__func__, 0x80080B30, 0x800D74E0);
    }
    // 0x80080B34: nop

L_80080B38:
    // 0x80080B38: lh          $t7, 0x46($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X46);
    // 0x80080B3C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80080B40: b           L_80080CF4
    // 0x80080B44: sh          $t8, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r24;
        goto L_80080CF4;
    // 0x80080B44: sh          $t8, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r24;
L_80080B48:
    // 0x80080B48: lh          $t9, 0x44($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X44);
    // 0x80080B4C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80080B50: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80080B54: sh          $t0, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r8;
    // 0x80080B58: lh          $v0, 0x44($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X44);
    // 0x80080B5C: bgtzl       $v0, L_80080B74
    if (SIGNED(ctx->r2) > 0) {
        // 0x80080B60: lh          $t2, 0x46($a0)
        ctx->r10 = MEM_H(ctx->r4, 0X46);
            goto L_80080B74;
    }
    goto skip_0;
    // 0x80080B60: lh          $t2, 0x46($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X46);
    skip_0:
    // 0x80080B64: lh          $t1, 0x46($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X46);
    // 0x80080B68: sh          $t1, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r9;
    // 0x80080B6C: lh          $v0, 0x44($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X44);
    // 0x80080B70: lh          $t2, 0x46($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X46);
L_80080B74:
    // 0x80080B74: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80080B78: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80080B7C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80080B80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80080B84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80080B88: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80080B8C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80080B90: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80080B94: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80080B98: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80080B9C: nop

    // 0x80080BA0: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x80080BA4: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80080BA8: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x80080BAC: bne         $at, $zero, L_80080BB8
    if (ctx->r1 != 0) {
        // 0x80080BB0: sh          $t5, 0x48($a0)
        MEM_H(0X48, ctx->r4) = ctx->r13;
            goto L_80080BB8;
    }
    // 0x80080BB0: sh          $t5, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r13;
    // 0x80080BB4: sh          $t6, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r14;
L_80080BB8:
    // 0x80080BB8: lh          $t7, 0x48($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X48);
    // 0x80080BBC: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x80080BC0: beql        $at, $zero, L_80080CF8
    if (ctx->r1 == 0) {
        // 0x80080BC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80080CF8;
    }
    goto skip_1;
    // 0x80080BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80080BC8: jal         0x80060FBC
    // 0x80080BCC: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80080BCC: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x80080BD0: b           L_80080CF8
    // 0x80080BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80080CF8;
    // 0x80080BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080BD8:
    // 0x80080BD8: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080BDC: lwc1        $f10, 0x68($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80080BE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080BE4: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80080BE8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080BEC: lh          $t8, 0x44($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X44);
    // 0x80080BF0: lh          $t9, 0x46($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X46);
    // 0x80080BF4: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80080BF8: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    // 0x80080BFC: lwc1        $f4, 0x7524($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7524);
    // 0x80080C00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080C04: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80080C08: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80080C0C: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x80080C10: lwc1        $f10, 0x7528($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7528);
    // 0x80080C14: sh          $t0, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r8;
    // 0x80080C18: lh          $t1, 0x44($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X44);
    // 0x80080C1C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080C20: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x80080C24: beq         $at, $zero, L_80080CF4
    if (ctx->r1 == 0) {
        // 0x80080C28: swc1        $f16, 0x58($a0)
        MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
            goto L_80080CF4;
    }
    // 0x80080C28: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
    // 0x80080C2C: jal         0x80060FBC
    // 0x80080C30: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x80080C30: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_1:
    // 0x80080C34: b           L_80080CF8
    // 0x80080C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80080CF8;
    // 0x80080C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080C3C:
    // 0x80080C3C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80080C40: lwc1        $f4, 0x60($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X60);
    // 0x80080C44: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80080C48: lwc1        $f10, 0x64($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X64);
    // 0x80080C4C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80080C50: lwc1        $f4, 0x68($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80080C54: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080C58: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080C5C: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80080C60: lh          $v0, 0x44($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X44);
    // 0x80080C64: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80080C68: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x80080C6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80080C70: bne         $v0, $zero, L_80080CA4
    if (ctx->r2 != 0) {
        // 0x80080C74: swc1        $f8, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
            goto L_80080CA4;
    }
    // 0x80080C74: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80080C78: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080C7C: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80080C80: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x80080C84: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80080C88: nop

    // 0x80080C8C: bc1f        L_80080CA4
    if (!c1cs) {
        // 0x80080C90: nop
    
            goto L_80080CA4;
    }
    // 0x80080C90: nop

    // 0x80080C94: jal         0x80060FBC
    // 0x80080C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x80080C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80080C9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080CA0: lh          $v0, 0x44($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X44);
L_80080CA4:
    // 0x80080CA4: beq         $v0, $zero, L_80080CB4
    if (ctx->r2 == 0) {
        // 0x80080CA8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80080CB4;
    }
    // 0x80080CA8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80080CAC: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80080CB0: sh          $t2, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r10;
L_80080CB4:
    // 0x80080CB4: lwc1        $f16, 0x58($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80080CB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80080CBC: nop

    // 0x80080CC0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80080CC4: b           L_80080CF4
    // 0x80080CC8: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
        goto L_80080CF4;
    // 0x80080CC8: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
L_80080CCC:
    // 0x80080CCC: jal         0x8007E45C
    // 0x80080CD0: nop

    Effect_Effect365_Update(rdram, ctx);
        goto after_3;
    // 0x80080CD0: nop

    after_3:
    // 0x80080CD4: b           L_80080CF8
    // 0x80080CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80080CF8;
    // 0x80080CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080CDC:
    // 0x80080CDC: jal         0x8007BCE8
    // 0x80080CE0: nop

    Effect_Effect362_Update(rdram, ctx);
        goto after_4;
    // 0x80080CE0: nop

    after_4:
    // 0x80080CE4: b           L_80080CF8
    // 0x80080CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80080CF8;
    // 0x80080CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080CEC:
    // 0x80080CEC: jal         0x8007B758
    // 0x80080CF0: nop

    Effect_PinkExplosion_Update(rdram, ctx);
        goto after_5;
    // 0x80080CF0: nop

    after_5:
L_80080CF4:
    // 0x80080CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080CF8:
    // 0x80080CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080CFC: jr          $ra
    // 0x80080D00: nop

    return;
    // 0x80080D00: nop

;}
RECOMP_FUNC void func_versus_800BE924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE924: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800BE928: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BE92C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BE930: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800BE934: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BE938: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BE93C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BE940: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800BE944: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800BE948: addiu       $t7, $t7, 0x4B90
    ctx->r15 = ADD32(ctx->r15, 0X4B90);
    // 0x800BE94C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800BE950: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800BE954: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x800BE958: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800BE95C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800BE960: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800BE964: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800BE968: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800BE96C: addiu       $t2, $t2, 0x4BA0
    ctx->r10 = ADD32(ctx->r10, 0X4BA0);
    // 0x800BE970: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800BE974: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800BE978: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800BE97C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800BE980: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x800BE984: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BE988: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800BE98C: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800BE990: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800BE994: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BE998: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x800BE99C: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800BE9A0: jal         0x800B8DD0
    // 0x800BE9A4: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BE9A4: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    after_0:
    // 0x800BE9A8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800BE9AC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800BE9B0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800BE9B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800BE9B8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800BE9BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800BE9C0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BE9C4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800BE9C8: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x800BE9CC: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x800BE9D0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BE9D4: addu        $s1, $t7, $t4
    ctx->r17 = ADD32(ctx->r15, ctx->r12);
    // 0x800BE9D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800BE9DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE9E0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BE9E4: addu        $s0, $t7, $t0
    ctx->r16 = ADD32(ctx->r15, ctx->r8);
    // 0x800BE9E8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BE9EC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800BE9F0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800BE9F4: jal         0x800BD3A8
    // 0x800BE9F8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_versus_800BD3A8(rdram, ctx);
        goto after_1;
    // 0x800BE9F8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800BE9FC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800BEA00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEA04: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEA08: lwc1        $f14, 0x0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEA0C: jal         0x800BD350
    // 0x800BEA10: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_versus_800BD350(rdram, ctx);
        goto after_2;
    // 0x800BEA10: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x800BEA14: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BEA18: lw          $v0, -0x78A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78A4);
    // 0x800BEA1C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BEA20: beq         $v0, $zero, L_800BEB48
    if (ctx->r2 == 0) {
        // 0x800BEA24: nop
    
            goto L_800BEB48;
    }
    // 0x800BEA24: nop

    // 0x800BEA28: lw          $t3, -0x78A0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X78A0);
    // 0x800BEA2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BEA30: beq         $t3, $zero, L_800BEB48
    if (ctx->r11 == 0) {
        // 0x800BEA34: nop
    
            goto L_800BEB48;
    }
    // 0x800BEA34: nop

    // 0x800BEA38: jal         0x800B8DD0
    // 0x800BEA3C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x800BEA3C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_3:
    // 0x800BEA40: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800BEA44: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800BEA48: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800BEA4C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800BEA50: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x800BEA54: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800BEA58: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800BEA5C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800BEA60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEA64: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800BEA68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BEA6C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEA70: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEA74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800BEA78: jal         0x800BD248
    // 0x800BEA7C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_versus_800BD248(rdram, ctx);
        goto after_4;
    // 0x800BEA7C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x800BEA80: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800BEA84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEA88: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800BEA8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEA90: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEA94: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEA98: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BEA9C: jal         0x800BD2A0
    // 0x800BEAA0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    func_versus_800BD2A0(rdram, ctx);
        goto after_5;
    // 0x800BEAA0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_5:
    // 0x800BEAA4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800BEAA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BEAAC: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x800BEAB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEAB4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEAB8: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEABC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BEAC0: jal         0x800BD2F8
    // 0x800BEAC4: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    func_versus_800BD2F8(rdram, ctx);
        goto after_6;
    // 0x800BEAC4: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_6:
    // 0x800BEAC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BEACC: jal         0x800B8DD0
    // 0x800BEAD0: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x800BEAD0: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_7:
    // 0x800BEAD4: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x800BEAD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEADC: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800BEAE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BEAE4: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEAE8: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEAEC: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800BEAF0: jal         0x800BD164
    // 0x800BEAF4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_versus_800BD164(rdram, ctx);
        goto after_8;
    // 0x800BEAF4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x800BEAF8: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x800BEAFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEB00: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800BEB04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEB08: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEB0C: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEB10: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BEB14: jal         0x800BD1B0
    // 0x800BEB18: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    func_versus_800BD1B0(rdram, ctx);
        goto after_9;
    // 0x800BEB18: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_9:
    // 0x800BEB1C: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x800BEB20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BEB24: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x800BEB28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEB2C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEB30: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEB34: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BEB38: jal         0x800BD1FC
    // 0x800BEB3C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    func_versus_800BD1FC(rdram, ctx);
        goto after_10;
    // 0x800BEB3C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_10:
    // 0x800BEB40: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BEB44: lw          $v0, -0x78A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78A4);
L_800BEB48:
    // 0x800BEB48: beq         $v0, $zero, L_800BEC20
    if (ctx->r2 == 0) {
        // 0x800BEB4C: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_800BEC20;
    }
    // 0x800BEB4C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BEB50: lw          $t9, -0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X78A0);
    // 0x800BEB54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BEB58: bnel        $t9, $zero, L_800BEC24
    if (ctx->r25 != 0) {
        // 0x800BEB5C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800BEC24;
    }
    goto skip_0;
    // 0x800BEB5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x800BEB60: jal         0x800B8DD0
    // 0x800BEB64: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x800BEB64: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_11:
    // 0x800BEB68: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800BEB6C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800BEB70: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800BEB74: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800BEB78: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800BEB7C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BEB80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BEB84: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800BEB88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEB8C: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x800BEB90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BEB94: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEB98: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEB9C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800BEBA0: jal         0x800BD248
    // 0x800BEBA4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_versus_800BD248(rdram, ctx);
        goto after_12;
    // 0x800BEBA4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_12:
    // 0x800BEBA8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800BEBAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEBB0: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x800BEBB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEBB8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEBBC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEBC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BEBC4: jal         0x800BD2A0
    // 0x800BEBC8: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    func_versus_800BD2A0(rdram, ctx);
        goto after_13;
    // 0x800BEBC8: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_13:
    // 0x800BEBCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BEBD0: jal         0x800B8DD0
    // 0x800BEBD4: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x800BEBD4: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_14:
    // 0x800BEBD8: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x800BEBDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BEBE0: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x800BEBE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEBE8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEBEC: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEBF0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BEBF4: jal         0x800BD164
    // 0x800BEBF8: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    func_versus_800BD164(rdram, ctx);
        goto after_15;
    // 0x800BEBF8: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_15:
    // 0x800BEBFC: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x800BEC00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEC04: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x800BEC08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BEC0C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEC10: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEC14: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800BEC18: jal         0x800BD1B0
    // 0x800BEC1C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_versus_800BD1B0(rdram, ctx);
        goto after_16;
    // 0x800BEC1C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_16:
L_800BEC20:
    // 0x800BEC20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800BEC24:
    // 0x800BEC24: jal         0x800B8DD0
    // 0x800BEC28: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_17;
    // 0x800BEC28: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_17:
    // 0x800BEC2C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800BEC30: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x800BEC34: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x800BEC38: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800BEC3C: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x800BEC40: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800BEC44: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800BEC48: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800BEC4C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BEC50: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800BEC54: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BEC58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEC5C: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x800BEC60: lw          $a2, -0x7808($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7808);
    // 0x800BEC64: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x800BEC68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BEC6C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800BEC70: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x800BEC74: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BEC78: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BEC7C: mflo        $t2
    ctx->r10 = lo;
    // 0x800BEC80: addiu       $a2, $t2, 0x1
    ctx->r6 = ADD32(ctx->r10, 0X1);
    // 0x800BEC84: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BEC88: jal         0x800BD4D4
    // 0x800BEC8C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    func_versus_800BD4D4(rdram, ctx);
        goto after_18;
    // 0x800BEC8C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_18:
    // 0x800BEC90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BEC98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEC9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BECA0: jr          $ra
    // 0x800BECA4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800BECA4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void AudioLoad_GetFontsForSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000F018: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000F01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000F024: jal         0x8000F790
    // 0x8000F028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000F028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000F02C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000F030: addiu       $a2, $a2, 0x5C68
    ctx->r6 = ADD32(ctx->r6, 0X5C68);
    // 0x8000F034: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000F038: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8000F03C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F040: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8000F044: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x8000F048: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x8000F04C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8000F050: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000F054: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000F058: bne         $t9, $zero, L_8000F068
    if (ctx->r25 != 0) {
        // 0x8000F05C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000F068;
    }
    // 0x8000F05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F060: b           L_8000F070
    // 0x8000F064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F070;
    // 0x8000F064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F068:
    // 0x8000F068: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8000F06C: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
L_8000F070:
    // 0x8000F070: jr          $ra
    // 0x8000F074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000F074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Graphics_DisplaySmallText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1200: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A1204: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800A1208: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800A120C: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x800A1210: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800A1214: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800A1218: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x800A121C: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
    // 0x800A1220: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800A1224: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800A1228: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x800A122C: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x800A1230: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x800A1234: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x800A1238: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x800A123C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x800A1240: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800A1244: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x800A1248: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x800A124C: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800A1250: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800A1254: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800A1258: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A125C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A1260: beq         $v1, $zero, L_800A13A4
    if (ctx->r3 == 0) {
        // 0x800A1264: cvt.s.w     $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800A13A4;
    }
    // 0x800A1264: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A1268: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800A126C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A1270: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800A1274: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800A1278: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800A127C: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800A1280: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800A1284: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800A1288: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A128C: addiu       $s0, $s0, 0x2660
    ctx->r16 = ADD32(ctx->r16, 0X2660);
    // 0x800A1290: addiu       $s4, $s4, 0x27B0
    ctx->r20 = ADD32(ctx->r20, 0X27B0);
    // 0x800A1294: addiu       $s5, $s5, 0x282C
    ctx->r21 = ADD32(ctx->r21, 0X282C);
    // 0x800A1298: addiu       $s6, $s6, 0x7E64
    ctx->r22 = ADD32(ctx->r22, 0X7E64);
    // 0x800A129C: addiu       $fp, $zero, 0x2D
    ctx->r30 = ADD32(0, 0X2D);
    // 0x800A12A0: addiu       $s7, $zero, 0x21
    ctx->r23 = ADD32(0, 0X21);
L_800A12A4:
    // 0x800A12A4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A12A8: lbu         $a0, 0x2660($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2660);
    // 0x800A12AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A12B0: beql        $a0, $v1, L_800A12D8
    if (ctx->r4 == ctx->r3) {
        // 0x800A12B4: addu        $t8, $s0, $v0
        ctx->r24 = ADD32(ctx->r16, ctx->r2);
            goto L_800A12D8;
    }
    goto skip_0;
    // 0x800A12B4: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    skip_0:
    // 0x800A12B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800A12BC:
    // 0x800A12BC: sltiu       $at, $v0, 0x2A
    ctx->r1 = ctx->r2 < 0X2A ? 1 : 0;
    // 0x800A12C0: beq         $at, $zero, L_800A12D4
    if (ctx->r1 == 0) {
        // 0x800A12C4: addu        $t6, $s0, $v0
        ctx->r14 = ADD32(ctx->r16, ctx->r2);
            goto L_800A12D4;
    }
    // 0x800A12C4: addu        $t6, $s0, $v0
    ctx->r14 = ADD32(ctx->r16, ctx->r2);
    // 0x800A12C8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800A12CC: bnel        $t7, $v1, L_800A12BC
    if (ctx->r15 != ctx->r3) {
        // 0x800A12D0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800A12BC;
    }
    goto skip_1;
    // 0x800A12D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
L_800A12D4:
    // 0x800A12D4: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
L_800A12D8:
    // 0x800A12D8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800A12DC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800A12E0: addu        $s1, $s4, $t0
    ctx->r17 = ADD32(ctx->r20, ctx->r8);
    // 0x800A12E4: bnel        $t9, $v1, L_800A1398
    if (ctx->r25 != ctx->r3) {
        // 0x800A12E8: lbu         $v1, 0x1($s2)
        ctx->r3 = MEM_BU(ctx->r18, 0X1);
            goto L_800A1398;
    }
    goto skip_2;
    // 0x800A12E8: lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1);
    skip_2:
    // 0x800A12EC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800A12F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800A12F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800A12F8: beq         $a1, $zero, L_800A132C
    if (ctx->r5 == 0) {
        // 0x800A12FC: addiu       $a3, $zero, 0x8
        ctx->r7 = ADD32(0, 0X8);
            goto L_800A132C;
    }
    // 0x800A12FC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800A1300: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x800A1304: sltu        $at, $s1, $s5
    ctx->r1 = ctx->r17 < ctx->r21 ? 1 : 0;
    // 0x800A1308: bne         $at, $zero, L_800A1314
    if (ctx->r1 != 0) {
        // 0x800A130C: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A1314;
    }
    // 0x800A130C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A1310: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_800A1314:
    // 0x800A1314: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800A1318: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800A131C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x800A1320: jal         0x8009D994
    // 0x800A1324: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800A1324: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    after_0:
    // 0x800A1328: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
L_800A132C:
    // 0x800A132C: beq         $v1, $s7, L_800A1350
    if (ctx->r3 == ctx->r23) {
        // 0x800A1330: nop
    
            goto L_800A1350;
    }
    // 0x800A1330: nop

    // 0x800A1334: beq         $v1, $fp, L_800A135C
    if (ctx->r3 == ctx->r30) {
        // 0x800A1338: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_800A135C;
    }
    // 0x800A1338: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800A133C: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x800A1340: beq         $v1, $at, L_800A1350
    if (ctx->r3 == ctx->r1) {
        // 0x800A1344: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_800A1350;
    }
    // 0x800A1344: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800A1348: bne         $v1, $at, L_800A1370
    if (ctx->r3 != ctx->r1) {
        // 0x800A134C: lui         $t1, 0x800D
        ctx->r9 = S32(0X800D << 16);
            goto L_800A1370;
    }
    // 0x800A134C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
L_800A1350:
    // 0x800A1350: mul.s       $f8, $f30, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x800A1354: b           L_800A1394
    // 0x800A1358: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
        goto L_800A1394;
    // 0x800A1358: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_800A135C:
    // 0x800A135C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A1360: nop

    // 0x800A1364: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800A1368: b           L_800A1394
    // 0x800A136C: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
        goto L_800A1394;
    // 0x800A136C: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_800A1370:
    // 0x800A1370: addiu       $t1, $t1, 0x2828
    ctx->r9 = ADD32(ctx->r9, 0X2828);
    // 0x800A1374: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x800A1378: bne         $at, $zero, L_800A138C
    if (ctx->r1 != 0) {
        // 0x800A137C: nop
    
            goto L_800A138C;
    }
    // 0x800A137C: nop

    // 0x800A1380: mul.s       $f18, $f26, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x800A1384: b           L_800A1394
    // 0x800A1388: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
        goto L_800A1394;
    // 0x800A1388: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
L_800A138C:
    // 0x800A138C: mul.s       $f4, $f28, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x800A1390: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_800A1394:
    // 0x800A1394: lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1);
L_800A1398:
    // 0x800A1398: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800A139C: bne         $v1, $zero, L_800A12A4
    if (ctx->r3 != 0) {
        // 0x800A13A0: nop
    
            goto L_800A12A4;
    }
    // 0x800A13A0: nop

L_800A13A4:
    // 0x800A13A4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800A13A8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800A13AC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800A13B0: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800A13B4: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800A13B8: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800A13BC: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x800A13C0: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800A13C4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800A13C8: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x800A13CC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800A13D0: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x800A13D4: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x800A13D8: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x800A13DC: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x800A13E0: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800A13E4: jr          $ra
    // 0x800A13E8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A13E8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Main_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004ABC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80004AC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80004AC4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80004AC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80004ACC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80004AD0: addiu       $s1, $s1, -0x4E10
    ctx->r17 = ADD32(ctx->r17, -0X4E10);
    // 0x80004AD4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80004AD8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80004ADC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80004AE0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80004AE4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80004AE8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80004AEC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80004AF0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80004AF4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004AF8: addiu       $t6, $t6, -0x1560
    ctx->r14 = ADD32(ctx->r14, -0X1560);
    // 0x80004AFC: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80004B00: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80004B04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80004B08: addiu       $a2, $a2, 0x3B48
    ctx->r6 = ADD32(ctx->r6, 0X3B48);
    // 0x80004B0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80004B10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004B14: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80004B18: jal         0x800221A0
    // 0x80004B1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80004B1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x80004B20: jal         0x800222F0
    // 0x80004B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80004B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80004B28: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80004B2C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80004B30: addiu       $s1, $s1, -0x1560
    ctx->r17 = ADD32(ctx->r17, -0X1560);
    // 0x80004B34: addiu       $t8, $t8, -0x3B0
    ctx->r24 = ADD32(ctx->r24, -0X3B0);
    // 0x80004B38: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80004B3C: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x80004B40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80004B44: addiu       $a2, $a2, 0x4144
    ctx->r6 = ADD32(ctx->r6, 0X4144);
    // 0x80004B48: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80004B4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004B50: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80004B54: jal         0x800221A0
    // 0x80004B58: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80004B58: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x80004B5C: jal         0x800222F0
    // 0x80004B60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x80004B60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80004B64: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80004B68: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80004B6C: addiu       $s1, $s1, -0x3B0
    ctx->r17 = ADD32(ctx->r17, -0X3B0);
    // 0x80004B70: addiu       $t0, $t0, 0xE00
    ctx->r8 = ADD32(ctx->r8, 0XE00);
    // 0x80004B74: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80004B78: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80004B7C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80004B80: addiu       $a2, $a2, 0x40D4
    ctx->r6 = ADD32(ctx->r6, 0X40D4);
    // 0x80004B84: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80004B88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004B8C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80004B90: jal         0x800221A0
    // 0x80004B94: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80004B94: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x80004B98: jal         0x800222F0
    // 0x80004B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_5;
    // 0x80004B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80004BA0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80004BA4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80004BA8: addiu       $s1, $s1, 0xE00
    ctx->r17 = ADD32(ctx->r17, 0XE00);
    // 0x80004BAC: addiu       $t2, $t2, 0x1FB0
    ctx->r10 = ADD32(ctx->r10, 0X1FB0);
    // 0x80004BB0: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80004BB4: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80004BB8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80004BBC: addiu       $a2, $a2, 0x3FEC
    ctx->r6 = ADD32(ctx->r6, 0X3FEC);
    // 0x80004BC0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80004BC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004BC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80004BCC: jal         0x800221A0
    // 0x80004BD0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_6;
    // 0x80004BD0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x80004BD4: jal         0x800222F0
    // 0x80004BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_7;
    // 0x80004BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80004BDC: jal         0x80004560
    // 0x80004BE0: nop

    Main_InitMesgQueues(rdram, ctx);
        goto after_8;
    // 0x80004BE0: nop

    after_8:
    // 0x80004BE4: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80004BE8: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80004BEC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004BF0: addiu       $s0, $s0, 0x2148
    ctx->r16 = ADD32(ctx->r16, 0X2148);
    // 0x80004BF4: addiu       $s6, $s6, 0x7E81
    ctx->r22 = ADD32(ctx->r22, 0X7E81);
    // 0x80004BF8: addiu       $s7, $s7, 0x7E80
    ctx->r23 = ADD32(ctx->r23, 0X7E80);
    // 0x80004BFC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80004C00: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80004C04: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80004C08: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80004C0C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80004C10: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x80004C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80004C18:
    // 0x80004C18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80004C1C: jal         0x800205E0
    // 0x80004C20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80004C20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_9:
    // 0x80004C24: lbu         $v0, 0x57($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X57);
    // 0x80004C28: beq         $s2, $v0, L_80004C84
    if (ctx->r18 == ctx->r2) {
        // 0x80004C2C: nop
    
            goto L_80004C84;
    }
    // 0x80004C2C: nop

    // 0x80004C30: beq         $v0, $s3, L_80004C94
    if (ctx->r2 == ctx->r19) {
        // 0x80004C34: nop
    
            goto L_80004C94;
    }
    // 0x80004C34: nop

    // 0x80004C38: beq         $v0, $s4, L_80004C50
    if (ctx->r2 == ctx->r20) {
        // 0x80004C3C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80004C50;
    }
    // 0x80004C3C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004C40: beql        $v0, $s5, L_80004CA8
    if (ctx->r2 == ctx->r21) {
        // 0x80004C44: sb          $fp, 0x0($s7)
        MEM_B(0X0, ctx->r23) = ctx->r30;
            goto L_80004CA8;
    }
    goto skip_0;
    // 0x80004C44: sb          $fp, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r30;
    skip_0:
    // 0x80004C48: b           L_80004CAC
    // 0x80004C4C: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
        goto L_80004CAC;
    // 0x80004C4C: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
L_80004C50:
    // 0x80004C50: addiu       $a0, $a0, 0x2238
    ctx->r4 = ADD32(ctx->r4, 0X2238);
    // 0x80004C54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80004C58: jal         0x80020720
    // 0x80004C5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80004C5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80004C60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004C64: addiu       $a0, $a0, 0x2278
    ctx->r4 = ADD32(ctx->r4, 0X2278);
    // 0x80004C68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80004C6C: jal         0x80020720
    // 0x80004C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80004C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80004C74: jal         0x80004824
    // 0x80004C78: nop

    Main_GetNewTasks(rdram, ctx);
        goto after_12;
    // 0x80004C78: nop

    after_12:
    // 0x80004C7C: b           L_80004CAC
    // 0x80004C80: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
        goto L_80004CAC;
    // 0x80004C80: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
L_80004C84:
    // 0x80004C84: jal         0x80004798
    // 0x80004C88: nop

    Main_HandleRSP(rdram, ctx);
        goto after_13;
    // 0x80004C88: nop

    after_13:
    // 0x80004C8C: b           L_80004CAC
    // 0x80004C90: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
        goto L_80004CAC;
    // 0x80004C90: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
L_80004C94:
    // 0x80004C94: jal         0x80004714
    // 0x80004C98: nop

    Main_HandleRDP(rdram, ctx);
        goto after_14;
    // 0x80004C98: nop

    after_14:
    // 0x80004C9C: b           L_80004CAC
    // 0x80004CA0: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
        goto L_80004CAC;
    // 0x80004CA0: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
    // 0x80004CA4: sb          $fp, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r30;
L_80004CA8:
    // 0x80004CA8: lbu         $t4, 0x0($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X0);
L_80004CAC:
    // 0x80004CAC: bnel        $t4, $zero, L_80004C18
    if (ctx->r12 != 0) {
        // 0x80004CB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80004C18;
    }
    goto skip_1;
    // 0x80004CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80004CB4: jal         0x800049D4
    // 0x80004CB8: nop

    Main_StartNextTask(rdram, ctx);
        goto after_15;
    // 0x80004CB8: nop

    after_15:
    // 0x80004CBC: b           L_80004C18
    // 0x80004CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80004C18;
    // 0x80004CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004CC4: nop

    // 0x80004CC8: nop

    // 0x80004CCC: nop

    // 0x80004CD0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80004CD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80004CD8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80004CDC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80004CE0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80004CE4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80004CE8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80004CEC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80004CF0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80004CF4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80004CF8: jr          $ra
    // 0x80004CFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80004CFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Audio_ClearBGMMute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800191BC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800191C0: addiu       $v0, $v0, 0x5D24
    ctx->r2 = ADD32(ctx->r2, 0X5D24);
    // 0x800191C4: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800191C8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800191CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800191D0: sllv        $t9, $t8, $t6
    ctx->r25 = S32(ctx->r24 << (ctx->r14 & 31));
    // 0x800191D4: xori        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 ^ 0XFFFF;
    // 0x800191D8: and         $t1, $t7, $t0
    ctx->r9 = ctx->r15 & ctx->r8;
    // 0x800191DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800191E0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800191E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800191E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800191EC: bne         $t2, $zero, L_80019208
    if (ctx->r10 != 0) {
        // 0x800191F0: sh          $t1, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r9;
            goto L_80019208;
    }
    // 0x800191F0: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x800191F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800191F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800191FC: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80019200: jal         0x800185A0
    // 0x80019204: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_0;
    // 0x80019204: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
L_80019208:
    // 0x80019208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001920C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019210: jr          $ra
    // 0x80019214: nop

    return;
    // 0x80019214: nop

;}
RECOMP_FUNC void Matrix_Translate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005B00: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80005B04: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80005B08: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80005B0C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80005B10: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80005B14: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80005B18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005B1C: bnel        $t6, $at, L_80005BE0
    if (ctx->r14 != ctx->r1) {
        // 0x80005B20: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80005BE0;
    }
    goto skip_0;
    // 0x80005B20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80005B24: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80005B28: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80005B2C: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80005B30: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005B34: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005B38: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005B3C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80005B40: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80005B44: nop

    // 0x80005B48: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005B4C: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80005B50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005B54: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80005B58: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80005B5C: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005B60: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80005B64: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80005B68: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80005B6C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80005B70: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80005B74: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x80005B78: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80005B7C: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005B80: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80005B84: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80005B88: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005B8C: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80005B90: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80005B94: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80005B98: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80005B9C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80005BA0: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x80005BA4: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80005BA8: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005BAC: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80005BB0: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005BB4: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80005BB8: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80005BBC: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80005BC0: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80005BC4: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    // 0x80005BC8: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80005BCC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80005BD0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005BD4: b           L_80005C28
    // 0x80005BD8: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
        goto L_80005C28;
    // 0x80005BD8: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80005BDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80005BE0:
    // 0x80005BE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80005BE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80005BE8: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
    // 0x80005BEC: swc1        $f14, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f14.u32l;
    // 0x80005BF0: swc1        $f20, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f20.u32l;
    // 0x80005BF4: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80005BF8: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80005BFC: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80005C00: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80005C04: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80005C08: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80005C0C: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80005C10: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80005C14: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80005C18: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    // 0x80005C1C: swc1        $f2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f2.u32l;
    // 0x80005C20: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80005C24: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
L_80005C28:
    // 0x80005C28: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80005C2C: jr          $ra
    // 0x80005C30: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80005C30: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void Scenery_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800614B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800614B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800614BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800614C0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800614C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800614C8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800614CC: jal         0x80061364
    // 0x800614D0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    Scenery_Initialize(rdram, ctx);
        goto after_0;
    // 0x800614D0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800614D4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800614D8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800614DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800614E0: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x800614E4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800614E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800614EC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800614F0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800614F4: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800614F8: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800614FC: lwc1        $f8, 0x641C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X641C);
    // 0x80061500: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80061504: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80061508: nop

    // 0x8006150C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061510: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80061514: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80061518: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x8006151C: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x80061520: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80061524: nop

    // 0x80061528: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006152C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80061530: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x80061534: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80061538: nop

    // 0x8006153C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061540: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x80061544: lh          $t0, 0xA($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XA);
    // 0x80061548: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8006154C: nop

    // 0x80061550: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061554: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
    // 0x80061558: lh          $t1, 0xC($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XC);
    // 0x8006155C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80061560: nop

    // 0x80061564: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061568: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    // 0x8006156C: lh          $t2, 0xE($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XE);
    // 0x80061570: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80061574: nop

    // 0x80061578: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006157C: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x80061580: lh          $t3, 0x10($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X10);
    // 0x80061584: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x80061588: jal         0x800612B8
    // 0x8006158C: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8006158C: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    after_1:
    // 0x80061590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061598: jr          $ra
    // 0x8006159C: nop

    return;
    // 0x8006159C: nop

;}
RECOMP_FUNC void ActorTeamBoss_Retreat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009136C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091370: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80091374: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80091378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009137C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091380: beq         $v0, $zero, L_8009139C
    if (ctx->r2 == 0) {
        // 0x80091384: nop
    
            goto L_8009139C;
    }
    // 0x80091384: nop

    // 0x80091388: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009138C: beq         $v0, $a0, L_80091458
    if (ctx->r2 == ctx->r4) {
        // 0x80091390: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80091458;
    }
    // 0x80091390: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80091394: b           L_800914EC
    // 0x80091398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800914EC;
    // 0x80091398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009139C:
    // 0x8009139C: lwc1        $f4, 0x7F54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F54);
    // 0x800913A0: lh          $t6, 0xE4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XE4);
    // 0x800913A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800913A8: sw          $a0, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r4;
    // 0x800913AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800913B0: sw          $a0, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->r4;
    // 0x800913B4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800913B8: swc1        $f4, 0x128($a2)
    MEM_W(0X128, ctx->r6) = ctx->f4.u32l;
    // 0x800913BC: sw          $a0, 0x78B0($at)
    MEM_W(0X78B0, ctx->r1) = ctx->r4;
    // 0x800913C0: lh          $v1, 0xE4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XE4);
    // 0x800913C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800913C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800913CC: beq         $v1, $a0, L_800913F0
    if (ctx->r3 == ctx->r4) {
        // 0x800913D0: nop
    
            goto L_800913F0;
    }
    // 0x800913D0: nop

    // 0x800913D4: beq         $v1, $at, L_80091428
    if (ctx->r3 == ctx->r1) {
        // 0x800913D8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80091428;
    }
    // 0x800913D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800913DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800913E0: beq         $v1, $at, L_8009140C
    if (ctx->r3 == ctx->r1) {
        // 0x800913E4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8009140C;
    }
    // 0x800913E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800913E8: b           L_80091444
    // 0x800913EC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
        goto L_80091444;
    // 0x800913EC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_800913F0:
    // 0x800913F0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800913F4: addiu       $a0, $a0, 0x39B8
    ctx->r4 = ADD32(ctx->r4, 0X39B8);
    // 0x800913F8: jal         0x800BA808
    // 0x800913FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x800913FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80091400: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80091404: b           L_80091440
    // 0x80091408: lh          $v1, 0xE4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XE4);
        goto L_80091440;
    // 0x80091408: lh          $v1, 0xE4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XE4);
L_8009140C:
    // 0x8009140C: addiu       $a0, $a0, 0x3A08
    ctx->r4 = ADD32(ctx->r4, 0X3A08);
    // 0x80091410: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80091414: jal         0x800BA808
    // 0x80091418: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x80091418: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8009141C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80091420: b           L_80091440
    // 0x80091424: lh          $v1, 0xE4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XE4);
        goto L_80091440;
    // 0x80091424: lh          $v1, 0xE4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XE4);
L_80091428:
    // 0x80091428: addiu       $a0, $a0, 0x3A64
    ctx->r4 = ADD32(ctx->r4, 0X3A64);
    // 0x8009142C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80091430: jal         0x800BA808
    // 0x80091434: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x80091434: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80091438: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8009143C: lh          $v1, 0xE4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XE4);
L_80091440:
    // 0x80091440: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80091444:
    // 0x80091444: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80091448: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009144C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80091450: b           L_800914E8
    // 0x80091454: sw          $t8, 0x78B0($at)
    MEM_W(0X78B0, ctx->r1) = ctx->r24;
        goto L_800914E8;
    // 0x80091454: sw          $t8, 0x78B0($at)
    MEM_W(0X78B0, ctx->r1) = ctx->r24;
L_80091458:
    // 0x80091458: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009145C: lwc1        $f6, 0x188($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X188);
    // 0x80091460: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80091464: nop

    // 0x80091468: bc1fl       L_80091478
    if (!c1cs) {
        // 0x8009146C: lhu         $t0, 0xBC($a2)
        ctx->r8 = MEM_HU(ctx->r6, 0XBC);
            goto L_80091478;
    }
    goto skip_0;
    // 0x8009146C: lhu         $t0, 0xBC($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0XBC);
    skip_0:
    // 0x80091470: swc1        $f0, 0x188($a2)
    MEM_W(0X188, ctx->r6) = ctx->f0.u32l;
    // 0x80091474: lhu         $t0, 0xBC($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0XBC);
L_80091478:
    // 0x80091478: bne         $t0, $zero, L_800914C0
    if (ctx->r8 != 0) {
        // 0x8009147C: nop
    
            goto L_800914C0;
    }
    // 0x8009147C: nop

    // 0x80091480: jal         0x80004EB0
    // 0x80091484: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80091484: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x80091488: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8009148C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80091490: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80091494: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80091498: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8009149C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800914A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800914A4: swc1        $f18, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->f18.u32l;
    // 0x800914A8: swc1        $f4, 0x134($a2)
    MEM_W(0X134, ctx->r6) = ctx->f4.u32l;
    // 0x800914AC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800914B0: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800914B4: nop

    // 0x800914B8: addiu       $t3, $t2, 0x1E
    ctx->r11 = ADD32(ctx->r10, 0X1E);
    // 0x800914BC: sh          $t3, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r11;
L_800914C0:
    // 0x800914C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800914C4: lwc1        $f6, 0x7F58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F58);
    // 0x800914C8: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800914CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800914D0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800914D4: nop

    // 0x800914D8: bc1fl       L_800914EC
    if (!c1cs) {
        // 0x800914DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800914EC;
    }
    goto skip_1;
    // 0x800914DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800914E0: jal         0x80060FBC
    // 0x800914E4: addiu       $a1, $a2, 0x100
    ctx->r5 = ADD32(ctx->r6, 0X100);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x800914E4: addiu       $a1, $a2, 0x100
    ctx->r5 = ADD32(ctx->r6, 0X100);
    after_4:
L_800914E8:
    // 0x800914E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800914EC:
    // 0x800914EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800914F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800914F4: jr          $ra
    // 0x800914F8: nop

    return;
    // 0x800914F8: nop

;}
RECOMP_FUNC void RCP_SetFog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8E14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B8E18: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x800B8E1C: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // 0x800B8E20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B8E24: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8E28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B8E2C: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800B8E30: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800B8E34: sll         $t9, $a1, 24
    ctx->r25 = S32(ctx->r5 << 24);
    // 0x800B8E38: andi        $t5, $a3, 0xFF
    ctx->r13 = ctx->r7 & 0XFF;
    // 0x800B8E3C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B8E40: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800B8E44: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800B8E48: andi        $t2, $t8, 0xFF
    ctx->r10 = ctx->r24 & 0XFF;
    // 0x800B8E4C: or          $t9, $t7, $t2
    ctx->r25 = ctx->r15 | ctx->r10;
    // 0x800B8E50: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B8E54: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8E58: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x800B8E5C: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x800B8E60: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800B8E64: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800B8E68: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800B8E6C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800B8E70: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B8E74: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800B8E78: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x800B8E7C: subu        $t1, $t4, $t6
    ctx->r9 = SUB32(ctx->r12, ctx->r14);
    // 0x800B8E80: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x800B8E84: negu        $t3, $t6
    ctx->r11 = SUB32(0, ctx->r14);
    // 0x800B8E88: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x800B8E8C: addu        $t4, $t5, $t8
    ctx->r12 = ADD32(ctx->r13, ctx->r24);
    // 0x800B8E90: mflo        $t7
    ctx->r15 = lo;
    // 0x800B8E94: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x800B8E98: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x800B8E9C: div         $zero, $t4, $t1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r9)));
    // 0x800B8EA0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800B8EA4: bne         $t1, $zero, L_800B8EB0
    if (ctx->r9 != 0) {
        // 0x800B8EA8: nop
    
            goto L_800B8EB0;
    }
    // 0x800B8EA8: nop

    // 0x800B8EAC: break       7
    do_break(2148241068);
L_800B8EB0:
    // 0x800B8EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B8EB4: bne         $t1, $at, L_800B8EC8
    if (ctx->r9 != ctx->r1) {
        // 0x800B8EB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B8EC8;
    }
    // 0x800B8EB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8EBC: bne         $t8, $at, L_800B8EC8
    if (ctx->r24 != ctx->r1) {
        // 0x800B8EC0: nop
    
            goto L_800B8EC8;
    }
    // 0x800B8EC0: nop

    // 0x800B8EC4: break       6
    do_break(2148241092);
L_800B8EC8:
    // 0x800B8EC8: addu        $at, $t8, $zero
    ctx->r1 = ADD32(ctx->r24, 0);
    // 0x800B8ECC: mflo        $t8
    ctx->r24 = lo;
    // 0x800B8ED0: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800B8ED4: or          $t2, $t9, $t7
    ctx->r10 = ctx->r25 | ctx->r15;
    // 0x800B8ED8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800B8EDC: bne         $t1, $zero, L_800B8EE8
    if (ctx->r9 != 0) {
        // 0x800B8EE0: nop
    
            goto L_800B8EE8;
    }
    // 0x800B8EE0: nop

    // 0x800B8EE4: break       7
    do_break(2148241124);
L_800B8EE8:
    // 0x800B8EE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B8EEC: bne         $t1, $at, L_800B8F00
    if (ctx->r9 != ctx->r1) {
        // 0x800B8EF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B8F00;
    }
    // 0x800B8EF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8EF4: bne         $t4, $at, L_800B8F00
    if (ctx->r12 != ctx->r1) {
        // 0x800B8EF8: nop
    
            goto L_800B8F00;
    }
    // 0x800B8EF8: nop

    // 0x800B8EFC: break       6
    do_break(2148241148);
L_800B8F00:
    // 0x800B8F00: jr          $ra
    // 0x800B8F04: nop

    return;
    // 0x800B8F04: nop

;}
RECOMP_FUNC void ActorAllRange_CheckObjectNearbySpace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800301F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800301F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800301FC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80030200: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x80030204: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030208: bnel        $t6, $zero, L_8003021C
    if (ctx->r14 != 0) {
        // 0x8003020C: lwc1        $f4, 0x14($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
            goto L_8003021C;
    }
    goto skip_0;
    // 0x8003020C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    skip_0:
    // 0x80030210: b           L_8003048C
    // 0x80030214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003048C;
    // 0x80030214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030218: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
L_8003021C:
    // 0x8003021C: lwc1        $f6, 0x4EC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4EC4);
    // 0x80030220: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80030224: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80030228: jal         0x80023090
    // 0x8003022C: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003022C: nop

    after_0:
    // 0x80030230: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80030234: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80030238: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003023C: lwc1        $f10, 0x4EC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4EC8);
    // 0x80030240: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80030244: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80030248: jal         0x80023250
    // 0x8003024C: nop

    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003024C: nop

    after_1:
    // 0x80030250: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80030254: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030258: lwc1        $f12, 0x4ECC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4ECC);
    // 0x8003025C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80030260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80030264: lwc1        $f4, 0x138($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X138);
    // 0x80030268: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003026C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80030270: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80030274: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80030278: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x8003027C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80030280: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80030284: addiu       $a2, $zero, 0x44C0
    ctx->r6 = ADD32(0, 0X44C0);
    // 0x80030288: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8003028C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80030290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80030294: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80030298: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
L_8003029C:
    // 0x8003029C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800302A0: bnel        $a1, $t7, L_80030334
    if (ctx->r5 != ctx->r15) {
        // 0x800302A4: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80030334;
    }
    goto skip_1;
    // 0x800302A4: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_1:
    // 0x800302A8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800302AC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800302B0: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800302B4: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800302B8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800302BC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800302C0: nop

    // 0x800302C4: bc1fl       L_80030334
    if (!c1cs) {
        // 0x800302C8: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80030334;
    }
    goto skip_2;
    // 0x800302C8: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_2:
    // 0x800302CC: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800302D0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800302D4: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800302D8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800302DC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800302E0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800302E4: nop

    // 0x800302E8: bc1fl       L_80030334
    if (!c1cs) {
        // 0x800302EC: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80030334;
    }
    goto skip_3;
    // 0x800302EC: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_3:
    // 0x800302F0: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800302F4: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800302F8: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800302FC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030300: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80030304: nop

    // 0x80030308: bc1fl       L_80030334
    if (!c1cs) {
        // 0x8003030C: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80030334;
    }
    goto skip_4;
    // 0x8003030C: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_4:
    // 0x80030310: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80030314: nop

    // 0x80030318: bc1f        L_80030328
    if (!c1cs) {
        // 0x8003031C: nop
    
            goto L_80030328;
    }
    // 0x8003031C: nop

    // 0x80030320: b           L_8003048C
    // 0x80030324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003048C;
    // 0x80030324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030328:
    // 0x80030328: b           L_8003048C
    // 0x8003032C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8003048C;
    // 0x8003032C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80030330: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
L_80030334:
    // 0x80030334: addiu       $v1, $v1, 0xB0
    ctx->r3 = ADD32(ctx->r3, 0XB0);
    // 0x80030338: bne         $a1, $t8, L_800303C8
    if (ctx->r5 != ctx->r24) {
        // 0x8003033C: nop
    
            goto L_800303C8;
    }
    // 0x8003033C: nop

    // 0x80030340: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80030344: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80030348: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003034C: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80030350: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030354: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80030358: nop

    // 0x8003035C: bc1f        L_800303C8
    if (!c1cs) {
        // 0x80030360: nop
    
            goto L_800303C8;
    }
    // 0x80030360: nop

    // 0x80030364: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80030368: lwc1        $f6, 0x64($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X64);
    // 0x8003036C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80030370: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80030374: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030378: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003037C: nop

    // 0x80030380: bc1f        L_800303C8
    if (!c1cs) {
        // 0x80030384: nop
    
            goto L_800303C8;
    }
    // 0x80030384: nop

    // 0x80030388: lwc1        $f14, 0x60($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8003038C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80030390: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80030394: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030398: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003039C: nop

    // 0x800303A0: bc1f        L_800303C8
    if (!c1cs) {
        // 0x800303A4: nop
    
            goto L_800303C8;
    }
    // 0x800303A4: nop

    // 0x800303A8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x800303AC: nop

    // 0x800303B0: bc1f        L_800303C0
    if (!c1cs) {
        // 0x800303B4: nop
    
            goto L_800303C0;
    }
    // 0x800303B4: nop

    // 0x800303B8: b           L_8003048C
    // 0x800303BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003048C;
    // 0x800303BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800303C0:
    // 0x800303C0: b           L_8003048C
    // 0x800303C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8003048C;
    // 0x800303C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800303C8:
    // 0x800303C8: bne         $v1, $a2, L_8003029C
    if (ctx->r3 != ctx->r6) {
        // 0x800303CC: addiu       $v0, $v0, 0xB0
        ctx->r2 = ADD32(ctx->r2, 0XB0);
            goto L_8003029C;
    }
    // 0x800303CC: addiu       $v0, $v0, 0xB0
    ctx->r2 = ADD32(ctx->r2, 0XB0);
    // 0x800303D0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800303D4: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800303D8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800303DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800303E0: bne         $t9, $at, L_8003048C
    if (ctx->r25 != ctx->r1) {
        // 0x800303E4: nop
    
            goto L_8003048C;
    }
    // 0x800303E4: nop

    // 0x800303E8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800303EC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800303F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800303F4: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800303F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800303FC: lwc1        $f4, -0xEEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x80030400: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80030404: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030408: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003040C: nop

    // 0x80030410: bc1f        L_8003048C
    if (!c1cs) {
        // 0x80030414: nop
    
            goto L_8003048C;
    }
    // 0x80030414: nop

    // 0x80030418: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003041C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030420: lwc1        $f10, -0xEE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x80030424: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80030428: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003042C: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80030430: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030434: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80030438: nop

    // 0x8003043C: bc1f        L_8003048C
    if (!c1cs) {
        // 0x80030440: nop
    
            goto L_8003048C;
    }
    // 0x80030440: nop

    // 0x80030444: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80030448: lwc1        $f6, -0xEE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEE8);
    // 0x8003044C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030450: lwc1        $f8, 0x4ED0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4ED0);
    // 0x80030454: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80030458: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003045C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80030460: nop

    // 0x80030464: bc1f        L_8003048C
    if (!c1cs) {
        // 0x80030468: nop
    
            goto L_8003048C;
    }
    // 0x80030468: nop

    // 0x8003046C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80030470: nop

    // 0x80030474: bc1f        L_80030484
    if (!c1cs) {
        // 0x80030478: nop
    
            goto L_80030484;
    }
    // 0x80030478: nop

    // 0x8003047C: b           L_8003048C
    // 0x80030480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003048C;
    // 0x80030480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030484:
    // 0x80030484: b           L_8003048C
    // 0x80030488: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8003048C;
    // 0x80030488: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8003048C:
    // 0x8003048C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030490: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80030494: jr          $ra
    // 0x80030498: nop

    return;
    // 0x80030498: nop

;}
RECOMP_FUNC void Item_CheckBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066EF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066EF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80066EF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066EFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066F00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066F04: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80066F08: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80066F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066F10: lw          $v0, 0x1C8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C8);
    // 0x80066F14: beq         $v0, $at, L_80066F24
    if (ctx->r2 == ctx->r1) {
        // 0x80066F18: nop
    
            goto L_80066F24;
    }
    // 0x80066F18: nop

    // 0x80066F1C: bne         $v0, $zero, L_80066F2C
    if (ctx->r2 != 0) {
        // 0x80066F20: nop
    
            goto L_80066F2C;
    }
    // 0x80066F20: nop

L_80066F24:
    // 0x80066F24: jal         0x80060FBC
    // 0x80066F28: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80066F28: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_0:
L_80066F2C:
    // 0x80066F2C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80066F30: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x80066F34: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80066F38: bne         $t7, $zero, L_80066FFC
    if (ctx->r15 != 0) {
        // 0x80066F3C: nop
    
            goto L_80066FFC;
    }
    // 0x80066F3C: nop

    // 0x80066F40: lw          $t8, 0x1680($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1680);
    // 0x80066F44: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80066F48: bne         $t8, $zero, L_80066FFC
    if (ctx->r24 != 0) {
        // 0x80066F4C: nop
    
            goto L_80066FFC;
    }
    // 0x80066F4C: nop

    // 0x80066F50: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80066F54: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80066F58: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80066F5C: lw          $t9, 0x1CC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1CC);
    // 0x80066F60: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80066F64: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80066F68: beq         $t9, $zero, L_80066F78
    if (ctx->r25 == 0) {
        // 0x80066F6C: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_80066F78;
    }
    // 0x80066F6C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80066F70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80066F74: nop

L_80066F78:
    // 0x80066F78: lwc1        $f0, 0xAC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x80066F7C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066F80: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80066F84: add.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80066F88: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80066F8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066F90: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80066F94: nop

    // 0x80066F98: bc1fl       L_80066FCC
    if (!c1cs) {
        // 0x80066F9C: sub.s       $f12, $f0, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
            goto L_80066FCC;
    }
    goto skip_0;
    // 0x80066F9C: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    skip_0:
    // 0x80066FA0: lwc1        $f4, 0x6950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6950);
    // 0x80066FA4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80066FA8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80066FAC: jal         0x8009BC2C
    // 0x80066FB0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80066FB0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80066FB4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80066FB8: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80066FBC: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80066FC0: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066FC4: lwc1        $f0, 0xAC($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0XAC);
    // 0x80066FC8: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
L_80066FCC:
    // 0x80066FCC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80066FD0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80066FD4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80066FD8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80066FDC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80066FE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066FE4: bc1f        L_80066FFC
    if (!c1cs) {
        // 0x80066FE8: nop
    
            goto L_80066FFC;
    }
    // 0x80066FE8: nop

    // 0x80066FEC: lwc1        $f6, 0x6954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6954);
    // 0x80066FF0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80066FF4: jal         0x8009BC2C
    // 0x80066FF8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80066FF8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
L_80066FFC:
    // 0x80066FFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067000: lwc1        $f2, 0x6958($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6958);
    // 0x80067004: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80067008: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8006700C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80067010: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80067014: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067018: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8006701C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80067020: bc1f        L_8006703C
    if (!c1cs) {
        // 0x80067024: nop
    
            goto L_8006703C;
    }
    // 0x80067024: nop

    // 0x80067028: lwc1        $f8, 0x695C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X695C);
    // 0x8006702C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80067030: jal         0x8009BC2C
    // 0x80067034: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80067034: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80067038: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
L_8006703C:
    // 0x8006703C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80067040: lbu         $t1, 0x7C98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C98);
    // 0x80067044: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80067048: bnel        $t1, $zero, L_800670DC
    if (ctx->r9 != 0) {
        // 0x8006704C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800670DC;
    }
    goto skip_1;
    // 0x8006704C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x80067050: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067054: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80067058: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8006705C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80067060: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80067064: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80067068: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006706C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067070: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80067074: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80067078: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006707C: nop

    // 0x80067080: bc1f        L_80067098
    if (!c1cs) {
        // 0x80067084: nop
    
            goto L_80067098;
    }
    // 0x80067084: nop

    // 0x80067088: lwc1        $f18, 0x6960($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6960);
    // 0x8006708C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80067090: jal         0x8009BC2C
    // 0x80067094: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80067094: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
L_80067098:
    // 0x80067098: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8006709C: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x800670A0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800670A4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800670A8: bne         $t2, $at, L_8006710C
    if (ctx->r10 != ctx->r1) {
        // 0x800670AC: nop
    
            goto L_8006710C;
    }
    // 0x800670AC: nop

    // 0x800670B0: lw          $t3, -0x7D7C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D7C);
    // 0x800670B4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800670B8: beq         $t3, $zero, L_8006710C
    if (ctx->r11 == 0) {
        // 0x800670BC: nop
    
            goto L_8006710C;
    }
    // 0x800670BC: nop

    // 0x800670C0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800670C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800670C8: nop

    // 0x800670CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800670D0: b           L_8006710C
    // 0x800670D4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8006710C;
    // 0x800670D4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800670D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800670DC:
    // 0x800670DC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800670E0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800670E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800670E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800670EC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800670F0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800670F4: bc1f        L_8006710C
    if (!c1cs) {
        // 0x800670F8: nop
    
            goto L_8006710C;
    }
    // 0x800670F8: nop

    // 0x800670FC: lwc1        $f10, 0x6964($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6964);
    // 0x80067100: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80067104: jal         0x8009BC2C
    // 0x80067108: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80067108: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
L_8006710C:
    // 0x8006710C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80067110: lw          $t4, 0x78E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78E8);
    // 0x80067114: beql        $t4, $zero, L_800671C0
    if (ctx->r12 == 0) {
        // 0x80067118: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800671C0;
    }
    goto skip_2;
    // 0x80067118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8006711C: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x80067120: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80067124: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80067128: bnel        $t5, $zero, L_800671C0
    if (ctx->r13 != 0) {
        // 0x8006712C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800671C0;
    }
    goto skip_3;
    // 0x8006712C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80067130: lbu         $t6, 0x6C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6C);
    // 0x80067134: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80067138: bnel        $t6, $at, L_800671C0
    if (ctx->r14 != ctx->r1) {
        // 0x8006713C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800671C0;
    }
    goto skip_4;
    // 0x8006713C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80067140: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80067144: lwc1        $f16, 0x70($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80067148: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8006714C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80067150: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80067154: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80067158: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8006715C: nop

    // 0x80067160: bc1fl       L_800671C0
    if (!c1cs) {
        // 0x80067164: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800671C0;
    }
    goto skip_5;
    // 0x80067164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80067168: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006716C: lwc1        $f18, 0x78($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80067170: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80067174: sub.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80067178: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006717C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80067180: nop

    // 0x80067184: bc1fl       L_800671C0
    if (!c1cs) {
        // 0x80067188: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800671C0;
    }
    goto skip_6;
    // 0x80067188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8006718C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067190: nop

    // 0x80067194: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80067198: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8006719C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800671A0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800671A4: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x800671A8: lwc1        $f16, 0x78($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800671AC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800671B0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800671B4: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
    // 0x800671B8: swc1        $f18, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f18.u32l;
    // 0x800671BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800671C0:
    // 0x800671C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800671C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800671C8: jr          $ra
    // 0x800671CC: nop

    return;
    // 0x800671CC: nop

;}
RECOMP_FUNC void func_col1_800985CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800985CC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800985D0: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800985D4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800985D8: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800985DC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800985E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800985E4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800985E8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800985EC: addiu       $t3, $t3, 0x1988
    ctx->r11 = ADD32(ctx->r11, 0X1988);
    // 0x800985F0: addiu       $t2, $t2, 0x1980
    ctx->r10 = ADD32(ctx->r10, 0X1980);
    // 0x800985F4: addiu       $t1, $t1, 0x197C
    ctx->r9 = ADD32(ctx->r9, 0X197C);
    // 0x800985F8: addiu       $t0, $t0, 0x1974
    ctx->r8 = ADD32(ctx->r8, 0X1974);
    // 0x800985FC: addiu       $a3, $a3, 0x199C
    ctx->r7 = ADD32(ctx->r7, 0X199C);
    // 0x80098600: addiu       $a2, $a2, 0x1998
    ctx->r6 = ADD32(ctx->r6, 0X1998);
    // 0x80098604: addiu       $v1, $v1, 0x1970
    ctx->r3 = ADD32(ctx->r3, 0X1970);
    // 0x80098608: addiu       $v0, $v0, 0x1968
    ctx->r2 = ADD32(ctx->r2, 0X1968);
    // 0x8009860C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80098610: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80098614: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80098618: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009861C: nop

    // 0x80098620: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80098624: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80098628: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009862C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80098630: lh          $t7, -0x1C($a1)
    ctx->r15 = MEM_H(ctx->r5, -0X1C);
    // 0x80098634: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80098638: nop

    // 0x8009863C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098640: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80098644: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80098648: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    // 0x8009864C: lh          $t8, -0x10($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X10);
    // 0x80098650: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80098654: nop

    // 0x80098658: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009865C: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x80098660: lh          $t9, -0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, -0XC);
    // 0x80098664: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80098668: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8009866C: nop

    // 0x80098670: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098674: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80098678: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009867C: lwc1        $f14, 0x0($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80098680: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80098684: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80098688: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8009868C: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80098690: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x80098694: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80098698: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009869C: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x800986A0: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800986A4: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800986A8: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800986AC: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800986B0: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800986B4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800986B8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800986BC: nop

    // 0x800986C0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800986C4: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800986C8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800986CC: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x800986D0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800986D4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800986D8: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800986DC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800986E0: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x800986E4: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800986E8: sub.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800986EC: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800986F0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800986F4: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800986F8: sub.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800986FC: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80098700: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80098704: nop

    // 0x80098708: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8009870C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80098710: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80098714: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80098718: bc1f        L_80098728
    if (!c1cs) {
        // 0x8009871C: lwc1        $f10, 0x20($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80098728;
    }
    // 0x8009871C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80098720: b           L_8009874C
    // 0x80098724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009874C;
    // 0x80098724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80098728:
    // 0x80098728: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009872C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80098730: c.eq.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl == ctx->f6.fl;
    // 0x80098734: nop

    // 0x80098738: bc1f        L_80098748
    if (!c1cs) {
        // 0x8009873C: nop
    
            goto L_80098748;
    }
    // 0x8009873C: nop

    // 0x80098740: b           L_80098748
    // 0x80098744: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80098748;
    // 0x80098744: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80098748:
    // 0x80098748: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009874C:
    // 0x8009874C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80098750: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80098754: bc1fl       L_80098768
    if (!c1cs) {
        // 0x80098758: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80098768;
    }
    goto skip_0;
    // 0x80098758: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8009875C: b           L_80098788
    // 0x80098760: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80098788;
    // 0x80098760: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80098764: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80098768:
    // 0x80098768: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8009876C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80098770: nop

    // 0x80098774: bc1f        L_80098784
    if (!c1cs) {
        // 0x80098778: nop
    
            goto L_80098784;
    }
    // 0x80098778: nop

    // 0x8009877C: b           L_80098784
    // 0x80098780: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80098784;
    // 0x80098780: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80098784:
    // 0x80098784: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80098788:
    // 0x80098788: beql        $v1, $v0, L_8009879C
    if (ctx->r3 == ctx->r2) {
        // 0x8009878C: lwc1        $f14, 0x0($a3)
        ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
            goto L_8009879C;
    }
    goto skip_1;
    // 0x8009878C: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x80098790: b           L_80098858
    // 0x80098794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098858;
    // 0x80098794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098798: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
L_8009879C:
    // 0x8009879C: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800987A0: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800987A4: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800987A8: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800987AC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800987B0: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800987B4: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800987B8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800987BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800987C0: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800987C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800987C8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800987CC: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800987D0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800987D4: bc1fl       L_800987E8
    if (!c1cs) {
        // 0x800987D8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_800987E8;
    }
    goto skip_2;
    // 0x800987D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x800987DC: b           L_80098808
    // 0x800987E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80098808;
    // 0x800987E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800987E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800987E8:
    // 0x800987E8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800987EC: c.eq.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl == ctx->f10.fl;
    // 0x800987F0: nop

    // 0x800987F4: bc1f        L_80098804
    if (!c1cs) {
        // 0x800987F8: nop
    
            goto L_80098804;
    }
    // 0x800987F8: nop

    // 0x800987FC: b           L_80098804
    // 0x80098800: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80098804;
    // 0x80098800: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80098804:
    // 0x80098804: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80098808:
    // 0x80098808: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8009880C: nop

    // 0x80098810: bc1fl       L_80098824
    if (!c1cs) {
        // 0x80098814: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80098824;
    }
    goto skip_3;
    // 0x80098814: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_3:
    // 0x80098818: b           L_80098844
    // 0x8009881C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80098844;
    // 0x8009881C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80098820: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80098824:
    // 0x80098824: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80098828: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x8009882C: nop

    // 0x80098830: bc1f        L_80098840
    if (!c1cs) {
        // 0x80098834: nop
    
            goto L_80098840;
    }
    // 0x80098834: nop

    // 0x80098838: b           L_80098840
    // 0x8009883C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80098840;
    // 0x8009883C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80098840:
    // 0x80098840: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80098844:
    // 0x80098844: beql        $v1, $v0, L_80098858
    if (ctx->r3 == ctx->r2) {
        // 0x80098848: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80098858;
    }
    goto skip_4;
    // 0x80098848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8009884C: b           L_80098858
    // 0x80098850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098858;
    // 0x80098850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80098858:
    // 0x80098858: jr          $ra
    // 0x8009885C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009885C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Effect_Effect383_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A4BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007A4C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007A4C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007A4C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007A4CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007A4D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007A4D4: jal         0x80061474
    // 0x8007A4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007A4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007A4DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007A4E0: addiu       $t7, $zero, 0x17F
    ctx->r15 = ADD32(0, 0X17F);
    // 0x8007A4E4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007A4E8: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007A4EC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007A4F0: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x8007A4F4: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8007A4F8: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x8007A4FC: sh          $t9, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r25;
    // 0x8007A500: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x8007A504: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007A508: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007A50C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8007A510: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8007A514: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007A518: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007A51C: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8007A520: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8007A524: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007A528: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x8007A52C: ori         $a0, $a0, 0xF026
    ctx->r4 = ctx->r4 | 0XF026;
    // 0x8007A530: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8007A534: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8007A538: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007A53C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007A540: jal         0x80019218
    // 0x8007A544: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8007A544: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8007A548: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007A54C: jal         0x800612B8
    // 0x8007A550: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8007A550: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_2:
    // 0x8007A554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007A558: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007A55C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A560: jr          $ra
    // 0x8007A564: nop

    return;
    // 0x8007A564: nop

;}
RECOMP_FUNC void Audio_GetDrum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011DFC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80011E00: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80011E04: lbu         $t6, -0x2C18($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2C18);
    // 0x80011E08: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80011E0C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80011E10: slti        $t7, $t6, 0x2
    ctx->r15 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80011E14: beq         $t7, $zero, L_80011E30
    if (ctx->r15 == 0) {
        // 0x80011E18: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80011E30;
    }
    // 0x80011E18: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80011E1C: addu        $t8, $a0, $at
    ctx->r24 = ADD32(ctx->r4, ctx->r1);
    // 0x80011E20: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011E24: sw          $t8, 0x5D88($at)
    MEM_W(0X5D88, ctx->r1) = ctx->r24;
    // 0x80011E28: jr          $ra
    // 0x80011E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011E30:
    // 0x80011E30: lw          $t9, 0x5C70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5C70);
    // 0x80011E34: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80011E38: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80011E3C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80011E40: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x80011E44: sll         $t2, $a0, 8
    ctx->r10 = S32(ctx->r4 << 8);
    // 0x80011E48: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x80011E4C: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011E50: bne         $at, $zero, L_80011E6C
    if (ctx->r1 != 0) {
        // 0x80011E54: lui         $at, 0x400
        ctx->r1 = S32(0X400 << 16);
            goto L_80011E6C;
    }
    // 0x80011E54: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80011E58: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80011E5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011E60: sw          $t4, 0x5D88($at)
    MEM_W(0X5D88, ctx->r1) = ctx->r12;
    // 0x80011E64: jr          $ra
    // 0x80011E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011E6C:
    // 0x80011E6C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80011E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80011E74: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80011E78: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x80011E7C: beq         $at, $zero, L_80011E8C
    if (ctx->r1 == 0) {
        // 0x80011E80: addu        $t6, $v1, $t5
        ctx->r14 = ADD32(ctx->r3, ctx->r13);
            goto L_80011E8C;
    }
    // 0x80011E80: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80011E84: jr          $ra
    // 0x80011E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011E8C:
    // 0x80011E8C: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80011E90: sll         $t7, $a0, 8
    ctx->r15 = S32(ctx->r4 << 8);
    // 0x80011E94: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80011E98: bne         $a2, $zero, L_80011EB0
    if (ctx->r6 != 0) {
        // 0x80011E9C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80011EB0;
    }
    // 0x80011E9C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80011EA0: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80011EA4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80011EA8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011EAC: sw          $t9, 0x5D88($at)
    MEM_W(0X5D88, ctx->r1) = ctx->r25;
L_80011EB0:
    // 0x80011EB0: jr          $ra
    // 0x80011EB4: nop

    return;
    // 0x80011EB4: nop

;}
RECOMP_FUNC void RCP_SetupDL_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8FA8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8FAC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B8FB0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8FB4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B8FB8: addiu       $t8, $t8, 0x3510
    ctx->r24 = ADD32(ctx->r24, 0X3510);
    // 0x800B8FBC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B8FC0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8FC4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B8FC8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B8FCC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B8FD0: jr          $ra
    // 0x800B8FD4: nop

    return;
    // 0x800B8FD4: nop

;}
RECOMP_FUNC void Graphics_DisplayLargeNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A100C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800A1010: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x800A1014: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800A1018: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800A101C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800A1020: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800A1024: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x800A1028: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x800A102C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x800A1030: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x800A1034: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x800A1038: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800A103C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800A1040: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800A1044: lui         $at, 0x98
    ctx->r1 = S32(0X98 << 16);
    // 0x800A1048: ori         $at, $at, 0x9680
    ctx->r1 = ctx->r1 | 0X9680;
    // 0x800A104C: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x800A1050: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800A1054: mfhi        $t6
    ctx->r14 = hi;
    // 0x800A1058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A105C: lui         $s0, 0xF
    ctx->r16 = S32(0XF << 16);
    // 0x800A1060: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800A1064: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800A1068: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A106C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800A1070: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800A1074: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x800A1078: addiu       $s6, $s6, 0x2788
    ctx->r22 = ADD32(ctx->r22, 0X2788);
    // 0x800A107C: ori         $s0, $s0, 0x4240
    ctx->r16 = ctx->r16 | 0X4240;
    // 0x800A1080: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x800A1084: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800A1088: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
L_800A108C:
    // 0x800A108C: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800A1090: mflo        $v0
    ctx->r2 = lo;
    // 0x800A1094: bne         $s0, $zero, L_800A10A0
    if (ctx->r16 != 0) {
        // 0x800A1098: nop
    
            goto L_800A10A0;
    }
    // 0x800A1098: nop

    // 0x800A109C: break       7
    do_break(2148143260);
L_800A10A0:
    // 0x800A10A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A10A4: bne         $s0, $at, L_800A10B8
    if (ctx->r16 != ctx->r1) {
        // 0x800A10A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A10B8;
    }
    // 0x800A10A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A10AC: bne         $s1, $at, L_800A10B8
    if (ctx->r17 != ctx->r1) {
        // 0x800A10B0: nop
    
            goto L_800A10B8;
    }
    // 0x800A10B0: nop

    // 0x800A10B4: break       6
    do_break(2148143284);
L_800A10B8:
    // 0x800A10B8: bnel        $v0, $zero, L_800A10CC
    if (ctx->r2 != 0) {
        // 0x800A10BC: mtc1        $s2, $f6
        ctx->f6.u32l = ctx->r18;
            goto L_800A10CC;
    }
    goto skip_0;
    // 0x800A10BC: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    skip_0:
    // 0x800A10C0: bne         $s3, $s4, L_800A1138
    if (ctx->r19 != ctx->r20) {
        // 0x800A10C4: nop
    
            goto L_800A1138;
    }
    // 0x800A10C4: nop

    // 0x800A10C8: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
L_800A10CC:
    // 0x800A10CC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A10D0: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x800A10D4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A10D8: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800A10DC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A10E0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800A10E4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800A10E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800A10EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800A10F0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800A10F4: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800A10F8: jal         0x8009D994
    // 0x800A10FC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800A10FC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_0:
    // 0x800A1100: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800A1104: addiu       $s2, $s2, 0xD
    ctx->r18 = ADD32(ctx->r18, 0XD);
    // 0x800A1108: bne         $s0, $zero, L_800A1114
    if (ctx->r16 != 0) {
        // 0x800A110C: nop
    
            goto L_800A1114;
    }
    // 0x800A110C: nop

    // 0x800A1110: break       7
    do_break(2148143376);
L_800A1114:
    // 0x800A1114: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1118: bne         $s0, $at, L_800A112C
    if (ctx->r16 != ctx->r1) {
        // 0x800A111C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A112C;
    }
    // 0x800A111C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1120: bne         $s1, $at, L_800A112C
    if (ctx->r17 != ctx->r1) {
        // 0x800A1124: nop
    
            goto L_800A112C;
    }
    // 0x800A1124: nop

    // 0x800A1128: break       6
    do_break(2148143400);
L_800A112C:
    // 0x800A112C: mfhi        $s1
    ctx->r17 = hi;
    // 0x800A1130: nop

    // 0x800A1134: nop

L_800A1138:
    // 0x800A1138: div         $zero, $s0, $s7
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r23)));
    // 0x800A113C: bne         $s7, $zero, L_800A1148
    if (ctx->r23 != 0) {
        // 0x800A1140: nop
    
            goto L_800A1148;
    }
    // 0x800A1140: nop

    // 0x800A1144: break       7
    do_break(2148143428);
L_800A1148:
    // 0x800A1148: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A114C: bne         $s7, $at, L_800A1160
    if (ctx->r23 != ctx->r1) {
        // 0x800A1150: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A1160;
    }
    // 0x800A1150: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1154: bne         $s0, $at, L_800A1160
    if (ctx->r16 != ctx->r1) {
        // 0x800A1158: nop
    
            goto L_800A1160;
    }
    // 0x800A1158: nop

    // 0x800A115C: break       6
    do_break(2148143452);
L_800A1160:
    // 0x800A1160: mflo        $s0
    ctx->r16 = lo;
    // 0x800A1164: bne         $s0, $s4, L_800A108C
    if (ctx->r16 != ctx->r20) {
        // 0x800A1168: nop
    
            goto L_800A108C;
    }
    // 0x800A1168: nop

    // 0x800A116C: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800A1170: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x800A1174: mflo        $t9
    ctx->r25 = lo;
    // 0x800A1178: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800A117C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A1180: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x800A1184: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800A1188: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A118C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800A1190: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800A1194: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800A1198: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800A119C: bne         $s0, $zero, L_800A11A8
    if (ctx->r16 != 0) {
        // 0x800A11A0: nop
    
            goto L_800A11A8;
    }
    // 0x800A11A0: nop

    // 0x800A11A4: break       7
    do_break(2148143524);
L_800A11A8:
    // 0x800A11A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A11AC: bne         $s0, $at, L_800A11C0
    if (ctx->r16 != ctx->r1) {
        // 0x800A11B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A11C0;
    }
    // 0x800A11B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A11B4: bne         $s1, $at, L_800A11C0
    if (ctx->r17 != ctx->r1) {
        // 0x800A11B8: nop
    
            goto L_800A11C0;
    }
    // 0x800A11B8: nop

    // 0x800A11BC: break       6
    do_break(2148143548);
L_800A11C0:
    // 0x800A11C0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800A11C4: jal         0x8009D994
    // 0x800A11C8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x800A11C8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_1:
    // 0x800A11CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800A11D0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800A11D4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800A11D8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800A11DC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800A11E0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800A11E4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800A11E8: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x800A11EC: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x800A11F0: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800A11F4: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x800A11F8: jr          $ra
    // 0x800A11FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800A11FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ActorAllRange_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035448: addiu       $sp, $sp, -0x200
    ctx->r29 = ADD32(ctx->r29, -0X200);
    // 0x8003544C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80035450: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80035454: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80035458: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003545C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80035460: addiu       $t7, $t7, -0x6450
    ctx->r15 = ADD32(ctx->r15, -0X6450);
    // 0x80035464: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80035468: addiu       $t6, $sp, 0x1E4
    ctx->r14 = ADD32(ctx->r29, 0X1E4);
    // 0x8003546C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80035470: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80035474: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80035478: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8003547C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80035480: lh          $v0, 0xE4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XE4);
    // 0x80035484: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80035488: beql        $v0, $at, L_80035D1C
    if (ctx->r2 == ctx->r1) {
        // 0x8003548C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035D1C;
    }
    goto skip_0;
    // 0x8003548C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80035490: lw          $v1, 0x70($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X70);
    // 0x80035494: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80035498: beql        $v1, $zero, L_80035544
    if (ctx->r3 == 0) {
        // 0x8003549C: lhu         $t2, 0xC6($s1)
        ctx->r10 = MEM_HU(ctx->r17, 0XC6);
            goto L_80035544;
    }
    goto skip_1;
    // 0x8003549C: lhu         $t2, 0xC6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC6);
    skip_1:
    // 0x800354A0: beql        $at, $zero, L_80035544
    if (ctx->r1 == 0) {
        // 0x800354A4: lhu         $t2, 0xC6($s1)
        ctx->r10 = MEM_HU(ctx->r17, 0XC6);
            goto L_80035544;
    }
    goto skip_2;
    // 0x800354A4: lhu         $t2, 0xC6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC6);
    skip_2:
    // 0x800354A8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800354AC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800354B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800354B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800354B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800354BC: lwc1        $f16, 0x50B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50B8);
    // 0x800354C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800354C4: nop

    // 0x800354C8: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800354CC: jal         0x80023090
    // 0x800354D0: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800354D0: nop

    after_0:
    // 0x800354D4: lw          $t1, 0x70($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X70);
    // 0x800354D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800354DC: lwc1        $f6, 0x50BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50BC);
    // 0x800354E0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800354E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800354E8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800354EC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800354F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800354F4: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800354F8: nop

    // 0x800354FC: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80035500: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80035504: jal         0x80005E90
    // 0x80035508: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80035508: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8003550C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035510: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035514: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80035518: jal         0x80005D44
    // 0x8003551C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x8003551C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80035520: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035524: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035528: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8003552C: jal         0x80005FE0
    // 0x80035530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80035530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80035534: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80035538: jal         0x80006EB8
    // 0x8003553C: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8003553C: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    after_4:
    // 0x80035540: lhu         $t2, 0xC6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC6);
L_80035544:
    // 0x80035544: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80035548: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003554C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80035550: bne         $t3, $zero, L_80035610
    if (ctx->r11 != 0) {
        // 0x80035554: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80035610;
    }
    // 0x80035554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035558: jal         0x800B8DD0
    // 0x8003555C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8003555C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_5:
    // 0x80035560: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035564: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80035568: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x8003556C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80035570: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80035574: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80035578: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003557C: lw          $a0, -0x7C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7C28);
    // 0x80035580: addiu       $t9, $zero, 0x3ED
    ctx->r25 = ADD32(0, 0X3ED);
    // 0x80035584: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80035588: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    // 0x8003558C: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x80035590: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80035594: negu        $t1, $a0
    ctx->r9 = SUB32(0, ctx->r4);
    // 0x80035598: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8003559C: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x800355A0: mflo        $t6
    ctx->r14 = lo;
    // 0x800355A4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800355A8: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x800355AC: div         $zero, $t3, $a1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r5)));
    // 0x800355B0: mflo        $t4
    ctx->r12 = lo;
    // 0x800355B4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800355B8: or          $t9, $t0, $t5
    ctx->r25 = ctx->r8 | ctx->r13;
    // 0x800355BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800355C0: bne         $a1, $zero, L_800355CC
    if (ctx->r5 != 0) {
        // 0x800355C4: nop
    
            goto L_800355CC;
    }
    // 0x800355C4: nop

    // 0x800355C8: break       7
    do_break(2147702216);
L_800355CC:
    // 0x800355CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800355D0: bne         $a1, $at, L_800355E4
    if (ctx->r5 != ctx->r1) {
        // 0x800355D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800355E4;
    }
    // 0x800355D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800355D8: bne         $t8, $at, L_800355E4
    if (ctx->r24 != ctx->r1) {
        // 0x800355DC: nop
    
            goto L_800355E4;
    }
    // 0x800355DC: nop

    // 0x800355E0: break       6
    do_break(2147702240);
L_800355E4:
    // 0x800355E4: addu        $at, $t8, $zero
    ctx->r1 = ADD32(ctx->r24, 0);
    // 0x800355E8: bne         $a1, $zero, L_800355F4
    if (ctx->r5 != 0) {
        // 0x800355EC: nop
    
            goto L_800355F4;
    }
    // 0x800355EC: nop

    // 0x800355F0: break       7
    do_break(2147702256);
L_800355F4:
    // 0x800355F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800355F8: bne         $a1, $at, L_8003560C
    if (ctx->r5 != ctx->r1) {
        // 0x800355FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8003560C;
    }
    // 0x800355FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80035600: bne         $t3, $at, L_8003560C
    if (ctx->r11 != ctx->r1) {
        // 0x80035604: nop
    
            goto L_8003560C;
    }
    // 0x80035604: nop

    // 0x80035608: break       6
    do_break(2147702280);
L_8003560C:
    // 0x8003560C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80035610:
    // 0x80035610: lh          $v0, 0xE4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XE4);
    // 0x80035614: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80035618: bne         $at, $zero, L_80035630
    if (ctx->r1 != 0) {
        // 0x8003561C: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_80035630;
    }
    // 0x8003561C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80035620: beq         $v0, $at, L_80035870
    if (ctx->r2 == ctx->r1) {
        // 0x80035624: lui         $a0, 0x600
        ctx->r4 = S32(0X600 << 16);
            goto L_80035870;
    }
    // 0x80035624: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x80035628: b           L_80035910
    // 0x8003562C: nop

        goto L_80035910;
    // 0x8003562C: nop

L_80035630:
    // 0x80035630: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80035634: bne         $at, $zero, L_8003564C
    if (ctx->r1 != 0) {
        // 0x80035638: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_8003564C;
    }
    // 0x80035638: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8003563C: beq         $v0, $at, L_80035850
    if (ctx->r2 == ctx->r1) {
        // 0x80035640: nop
    
            goto L_80035850;
    }
    // 0x80035640: nop

    // 0x80035644: b           L_80035910
    // 0x80035648: nop

        goto L_80035910;
    // 0x80035648: nop

L_8003564C:
    // 0x8003564C: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80035650: beq         $at, $zero, L_80035910
    if (ctx->r1 == 0) {
        // 0x80035654: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80035910;
    }
    // 0x80035654: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80035658: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003565C: addu        $at, $at, $t8
    gpr jr_addend_80035664 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80035660: lw          $t8, 0x50C0($at)
    ctx->r24 = ADD32(ctx->r1, 0X50C0);
    // 0x80035664: jr          $t8
    // 0x80035668: nop

    switch (jr_addend_80035664 >> 2) {
        case 0: goto L_8003566C; break;
        case 1: goto L_8003566C; break;
        case 2: goto L_8003566C; break;
        case 3: goto L_8003566C; break;
        case 4: goto L_8003569C; break;
        case 5: goto L_8003569C; break;
        case 6: goto L_8003569C; break;
        case 7: goto L_8003569C; break;
        case 8: goto L_800357F0; break;
        case 9: goto L_80035820; break;
        default: switch_error(__func__, 0x80035664, 0x800D50C0);
    }
    // 0x80035668: nop

L_8003566C:
    // 0x8003566C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035670: jal         0x80005708
    // 0x80035674: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_6;
    // 0x80035674: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x80035678: jal         0x8005B388
    // 0x8003567C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorTeamArwing_Draw(rdram, ctx);
        goto after_7;
    // 0x8003567C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80035680: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035684: jal         0x80005740
    // 0x80035688: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x80035688: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_8:
    // 0x8003568C: jal         0x80035098
    // 0x80035690: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorAllRange_DrawBarrelRoll(rdram, ctx);
        goto after_9;
    // 0x80035690: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80035694: b           L_80035D1C
    // 0x80035698: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035698: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003569C:
    // 0x8003569C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800356A0: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800356A4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800356A8: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800356AC: bne         $t6, $at, L_8003577C
    if (ctx->r14 != ctx->r1) {
        // 0x800356B0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8003577C;
    }
    // 0x800356B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800356B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800356B8: lui         $t2, 0xF01
    ctx->r10 = S32(0XF01 << 16);
    // 0x800356BC: addiu       $t2, $t2, 0x3D0
    ctx->r10 = ADD32(ctx->r10, 0X3D0);
    // 0x800356C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800356C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800356C8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800356CC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800356D0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800356D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800356D8: jal         0x80005708
    // 0x800356DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x800356DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_10:
    // 0x800356E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800356E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800356E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800356EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800356F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800356F4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800356F8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x800356FC: jal         0x80005B00
    // 0x80035700: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x80035700: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_11:
    // 0x80035704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035708: jal         0x8005B1E8
    // 0x8003570C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_12;
    // 0x8003570C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80035710: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035714: jal         0x80005740
    // 0x80035718: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x80035718: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_13:
    // 0x8003571C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035720: jal         0x80005708
    // 0x80035724: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_14;
    // 0x80035724: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_14:
    // 0x80035728: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003572C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035730: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035734: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035738: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003573C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035740: lui         $a1, 0xC1F0
    ctx->r5 = S32(0XC1F0 << 16);
    // 0x80035744: jal         0x80005B00
    // 0x80035748: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x80035748: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_15:
    // 0x8003574C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035750: jal         0x8005B1E8
    // 0x80035754: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_16;
    // 0x80035754: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
    // 0x80035758: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003575C: jal         0x80005740
    // 0x80035760: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x80035760: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_17:
    // 0x80035764: jal         0x80035098
    // 0x80035768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorAllRange_DrawBarrelRoll(rdram, ctx);
        goto after_18;
    // 0x80035768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x8003576C: jal         0x80034E64
    // 0x80035770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorAllRange_DrawShield(rdram, ctx);
        goto after_19;
    // 0x80035770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80035774: b           L_80035D1C
    // 0x80035778: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035778: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003577C:
    // 0x8003577C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035780: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    // 0x80035784: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035788: lui         $t9, 0xF01
    ctx->r25 = S32(0XF01 << 16);
    // 0x8003578C: addiu       $t9, $t9, -0xE00
    ctx->r25 = ADD32(ctx->r25, -0XE00);
    // 0x80035790: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80035794: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80035798: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003579C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800357A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800357A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800357A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800357AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800357B0: jal         0x80005B00
    // 0x800357B4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_20;
    // 0x800357B4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_20:
    // 0x800357B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800357BC: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800357C0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800357C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800357C8: bne         $t6, $at, L_800357E0
    if (ctx->r14 != ctx->r1) {
        // 0x800357CC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800357E0;
    }
    // 0x800357CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800357D0: jal         0x8005B1E8
    // 0x800357D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_21;
    // 0x800357D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x800357D8: b           L_80035D1C
    // 0x800357DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x800357DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800357E0:
    // 0x800357E0: jal         0x8005B1E8
    // 0x800357E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_22;
    // 0x800357E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x800357E8: b           L_80035D1C
    // 0x800357EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x800357EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800357F0:
    // 0x800357F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800357F4: lui         $t2, 0xD01
    ctx->r10 = S32(0XD01 << 16);
    // 0x800357F8: addiu       $t2, $t2, -0x65C0
    ctx->r10 = ADD32(ctx->r10, -0X65C0);
    // 0x800357FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80035800: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80035804: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80035808: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003580C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80035810: jal         0x8005ADAC
    // 0x80035814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_23;
    // 0x80035814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x80035818: b           L_80035D1C
    // 0x8003581C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x8003581C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035820:
    // 0x80035820: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035824: lui         $t0, 0xD01
    ctx->r8 = S32(0XD01 << 16);
    // 0x80035828: addiu       $t0, $t0, -0x4780
    ctx->r8 = ADD32(ctx->r8, -0X4780);
    // 0x8003582C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80035830: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80035834: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80035838: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8003583C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80035840: jal         0x8005ADAC
    // 0x80035844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_24;
    // 0x80035844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x80035848: b           L_80035D1C
    // 0x8003584C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x8003584C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035850:
    // 0x80035850: jal         0x8005F670
    // 0x80035854: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Display_SetSecondLight(rdram, ctx);
        goto after_25;
    // 0x80035854: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_25:
    // 0x80035858: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003585C: sh          $t5, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r13;
    // 0x80035860: jal         0x8004FEC0
    // 0x80035864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorCutscene_Draw(rdram, ctx);
        goto after_26;
    // 0x80035864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x80035868: b           L_80035D1C
    // 0x8003586C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x8003586C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035870:
    // 0x80035870: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x80035874: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80035878: addiu       $a0, $a0, 0x6D64
    ctx->r4 = ADD32(ctx->r4, 0X6D64);
    // 0x8003587C: jal         0x8009AA20
    // 0x80035880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_27;
    // 0x80035880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80035884: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80035888: lw          $t9, -0x4438($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4438);
    // 0x8003588C: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80035890: lui         $a3, 0x8003
    ctx->r7 = S32(0X8003 << 16);
    // 0x80035894: addiu       $a3, $a3, 0x52E0
    ctx->r7 = ADD32(ctx->r7, 0X52E0);
    // 0x80035898: addiu       $a1, $a1, 0x6E50
    ctx->r5 = ADD32(ctx->r5, 0X6E50);
    // 0x8003589C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800358A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800358A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800358A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800358AC: jal         0x8009A72C
    // 0x800358B0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_28;
    // 0x800358B0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_28:
    // 0x800358B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800358B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800358BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800358C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800358C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800358C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800358CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800358D0: jal         0x80005B00
    // 0x800358D4: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_29;
    // 0x800358D4: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    after_29:
    // 0x800358D8: lwc1        $f0, 0x188($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X188);
    // 0x800358DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800358E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800358E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800358E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800358EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800358F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800358F4: jal         0x80005C34
    // 0x800358F8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_30;
    // 0x800358F8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_30:
    // 0x800358FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035900: jal         0x8005B1E8
    // 0x80035904: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_31;
    // 0x80035904: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_31:
    // 0x80035908: b           L_80035D1C
    // 0x8003590C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x8003590C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035910:
    // 0x80035910: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80035914: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80035918: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8003591C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035920: bne         $v0, $at, L_800359CC
    if (ctx->r2 != ctx->r1) {
        // 0x80035924: lui         $a3, 0x4270
        ctx->r7 = S32(0X4270 << 16);
            goto L_800359CC;
    }
    // 0x80035924: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    // 0x80035928: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003592C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80035930: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80035934: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035938: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003593C: jal         0x80005B00
    // 0x80035940: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_32;
    // 0x80035940: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_32:
    // 0x80035944: jal         0x80006EB8
    // 0x80035948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_33;
    // 0x80035948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x8003594C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035950: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80035954: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035958: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8003595C: addiu       $t3, $t3, 0x6BE0
    ctx->r11 = ADD32(ctx->r11, 0X6BE0);
    // 0x80035960: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80035964: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80035968: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8003596C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80035970: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035974: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035978: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003597C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035980: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80035984: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035988: jal         0x80005B00
    // 0x8003598C: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_34;
    // 0x8003598C: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_34:
    // 0x80035990: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80035994: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80035998: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003599C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800359A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800359A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800359A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800359AC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800359B0: jal         0x80005C34
    // 0x800359B4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_35;
    // 0x800359B4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_35:
    // 0x800359B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800359BC: jal         0x8005B1E8
    // 0x800359C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_36;
    // 0x800359C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_36:
    // 0x800359C4: b           L_80035D1C
    // 0x800359C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x800359C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800359CC:
    // 0x800359CC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800359D0: bnel        $v0, $at, L_80035AD4
    if (ctx->r2 != ctx->r1) {
        // 0x800359D4: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80035AD4;
    }
    goto skip_3;
    // 0x800359D4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_3:
    // 0x800359D8: lh          $v0, 0xB6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB6);
    // 0x800359DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800359E0: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800359E4: beql        $v0, $zero, L_80035A0C
    if (ctx->r2 == 0) {
        // 0x800359E8: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80035A0C;
    }
    goto skip_4;
    // 0x800359E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x800359EC: beq         $v0, $at, L_80035A2C
    if (ctx->r2 == ctx->r1) {
        // 0x800359F0: lui         $t7, 0x600
        ctx->r15 = S32(0X600 << 16);
            goto L_80035A2C;
    }
    // 0x800359F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800359F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800359F8: beq         $v0, $at, L_80035A80
    if (ctx->r2 == ctx->r1) {
        // 0x800359FC: lui         $t4, 0x600
        ctx->r12 = S32(0X600 << 16);
            goto L_80035A80;
    }
    // 0x800359FC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80035A00: b           L_80035D1C
    // 0x80035A04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035A04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035A08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80035A0C:
    // 0x80035A0C: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x80035A10: addiu       $t8, $t8, -0x1010
    ctx->r24 = ADD32(ctx->r24, -0X1010);
    // 0x80035A14: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80035A18: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80035A1C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80035A20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80035A24: b           L_80035D1C
    // 0x80035A28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035A28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035A2C:
    // 0x80035A2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035A30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035A34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035A38: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x80035A3C: addiu       $t1, $t1, -0x1FB0
    ctx->r9 = ADD32(ctx->r9, -0X1FB0);
    // 0x80035A40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80035A44: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80035A48: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80035A4C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80035A50: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035A54: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035A58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80035A5C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80035A60: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035A64: jal         0x80005B00
    // 0x80035A68: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_37;
    // 0x80035A68: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_37:
    // 0x80035A6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035A70: jal         0x8005B1E8
    // 0x80035A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_38;
    // 0x80035A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80035A78: b           L_80035D1C
    // 0x80035A7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035A7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035A80:
    // 0x80035A80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035A84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035A88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035A8C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80035A90: addiu       $t0, $t0, 0x1530
    ctx->r8 = ADD32(ctx->r8, 0X1530);
    // 0x80035A94: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80035A98: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80035A9C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80035AA0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80035AA4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035AA8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035AAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80035AB0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80035AB4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035AB8: jal         0x80005B00
    // 0x80035ABC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_39;
    // 0x80035ABC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_39:
    // 0x80035AC0: jal         0x80034E64
    // 0x80035AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorAllRange_DrawShield(rdram, ctx);
        goto after_40;
    // 0x80035AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_40:
    // 0x80035AC8: b           L_80035D1C
    // 0x80035ACC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035ACC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035AD0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
L_80035AD4:
    // 0x80035AD4: bne         $v0, $at, L_80035B30
    if (ctx->r2 != ctx->r1) {
        // 0x80035AD8: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_80035B30;
    }
    // 0x80035AD8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80035ADC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035AE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035AE4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035AE8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80035AEC: addiu       $t6, $t6, 0x4FE0
    ctx->r14 = ADD32(ctx->r14, 0X4FE0);
    // 0x80035AF0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80035AF4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80035AF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80035AFC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80035B00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035B04: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035B08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80035B0C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80035B10: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035B14: jal         0x80005B00
    // 0x80035B18: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_41;
    // 0x80035B18: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_41:
    // 0x80035B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035B20: jal         0x8005B1E8
    // 0x80035B24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_42;
    // 0x80035B24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_42:
    // 0x80035B28: b           L_80035D1C
    // 0x80035B2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035B2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035B30:
    // 0x80035B30: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80035B34: bne         $v0, $at, L_80035BB0
    if (ctx->r2 != ctx->r1) {
        // 0x80035B38: lui         $t2, 0x600
        ctx->r10 = S32(0X600 << 16);
            goto L_80035BB0;
    }
    // 0x80035B38: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80035B3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035B40: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x80035B44: addiu       $t3, $t3, -0x7890
    ctx->r11 = ADD32(ctx->r11, -0X7890);
    // 0x80035B48: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80035B4C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80035B50: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80035B54: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80035B58: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035B5C: jal         0x80005708
    // 0x80035B60: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_43;
    // 0x80035B60: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_43:
    // 0x80035B64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035B68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035B6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035B70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035B74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035B78: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80035B7C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035B80: jal         0x80005B00
    // 0x80035B84: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_44;
    // 0x80035B84: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_44:
    // 0x80035B88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035B8C: jal         0x8005B1E8
    // 0x80035B90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_45;
    // 0x80035B90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_45:
    // 0x80035B94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035B98: jal         0x80005740
    // 0x80035B9C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_46;
    // 0x80035B9C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_46:
    // 0x80035BA0: jal         0x80034E64
    // 0x80035BA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorAllRange_DrawShield(rdram, ctx);
        goto after_47;
    // 0x80035BA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_47:
    // 0x80035BA8: b           L_80035D1C
    // 0x80035BAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035BAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035BB0:
    // 0x80035BB0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80035BB4: bne         $v0, $at, L_80035C2C
    if (ctx->r2 != ctx->r1) {
        // 0x80035BB8: lui         $a0, 0x601
        ctx->r4 = S32(0X601 << 16);
            goto L_80035C2C;
    }
    // 0x80035BB8: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80035BBC: addiu       $s0, $s1, 0x18C
    ctx->r16 = ADD32(ctx->r17, 0X18C);
    // 0x80035BC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80035BC4: addiu       $a0, $a0, -0x3E00
    ctx->r4 = ADD32(ctx->r4, -0X3E00);
    // 0x80035BC8: jal         0x8009AA20
    // 0x80035BCC: lh          $a1, 0x4A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4A);
    Animation_GetFrameData(rdram, ctx);
        goto after_48;
    // 0x80035BCC: lh          $a1, 0x4A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4A);
    after_48:
    // 0x80035BD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035BD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80035BD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035BDC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80035BE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035BE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035BE8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80035BEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80035BF0: jal         0x80005C34
    // 0x80035BF4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_49;
    // 0x80035BF4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_49:
    // 0x80035BF8: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80035BFC: addiu       $t5, $t5, 0x4660
    ctx->r13 = ADD32(ctx->r13, 0X4660);
    // 0x80035C00: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x80035C04: addiu       $a1, $a1, -0x3D54
    ctx->r5 = ADD32(ctx->r5, -0X3D54);
    // 0x80035C08: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80035C0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80035C10: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80035C14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80035C18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80035C1C: jal         0x8009A72C
    // 0x80035C20: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_50;
    // 0x80035C20: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_50:
    // 0x80035C24: b           L_80035D1C
    // 0x80035C28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035C28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035C2C:
    // 0x80035C2C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80035C30: bne         $v0, $at, L_80035C5C
    if (ctx->r2 != ctx->r1) {
        // 0x80035C34: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_80035C5C;
    }
    // 0x80035C34: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80035C38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035C3C: lui         $t6, 0x301
    ctx->r14 = S32(0X301 << 16);
    // 0x80035C40: addiu       $t6, $t6, 0x5740
    ctx->r14 = ADD32(ctx->r14, 0X5740);
    // 0x80035C44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80035C48: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80035C4C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80035C50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80035C54: b           L_80035D1C
    // 0x80035C58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035C58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035C5C:
    // 0x80035C5C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80035C60: bnel        $v0, $at, L_80035D1C
    if (ctx->r2 != ctx->r1) {
        // 0x80035C64: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035D1C;
    }
    goto skip_5;
    // 0x80035C64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80035C68: lh          $t7, 0xE6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XE6);
    // 0x80035C6C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80035C70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035C74: bne         $t7, $zero, L_80035CD4
    if (ctx->r15 != 0) {
        // 0x80035C78: lui         $a3, 0xC270
        ctx->r7 = S32(0XC270 << 16);
            goto L_80035CD4;
    }
    // 0x80035C78: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    // 0x80035C7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035C80: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80035C84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035C88: lui         $t3, 0xF01
    ctx->r11 = S32(0XF01 << 16);
    // 0x80035C8C: addiu       $t3, $t3, -0xE00
    ctx->r11 = ADD32(ctx->r11, -0XE00);
    // 0x80035C90: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80035C94: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80035C98: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80035C9C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80035CA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035CA4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035CA8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035CAC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035CB0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80035CB4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035CB8: jal         0x80005B00
    // 0x80035CBC: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_51;
    // 0x80035CBC: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_51:
    // 0x80035CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035CC4: jal         0x8005B1E8
    // 0x80035CC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_52;
    // 0x80035CC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_52:
    // 0x80035CCC: b           L_80035D1C
    // 0x80035CD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80035D1C;
    // 0x80035CD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035CD4:
    // 0x80035CD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035CD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80035CDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80035CE0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80035CE4: addiu       $t9, $t9, 0x68F0
    ctx->r25 = ADD32(ctx->r25, 0X68F0);
    // 0x80035CE8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80035CEC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80035CF0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80035CF4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80035CF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035CFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80035D00: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80035D04: jal         0x80005B00
    // 0x80035D08: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    Matrix_Translate(rdram, ctx);
        goto after_53;
    // 0x80035D08: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_53:
    // 0x80035D0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035D10: jal         0x8005B1E8
    // 0x80035D14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_54;
    // 0x80035D14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_54:
    // 0x80035D18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035D1C:
    // 0x80035D1C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80035D20: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80035D24: jr          $ra
    // 0x80035D28: addiu       $sp, $sp, 0x200
    ctx->r29 = ADD32(ctx->r29, 0X200);
    return;
    // 0x80035D28: addiu       $sp, $sp, 0x200
    ctx->r29 = ADD32(ctx->r29, 0X200);
;}
RECOMP_FUNC void Play_GetMaxShields(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3FC4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A3FC8: lbu         $t6, 0x1A90($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1A90);
    // 0x800A3FCC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800A3FD0: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x800A3FD4: bne         $at, $zero, L_800A3FE4
    if (ctx->r1 != 0) {
        // 0x800A3FD8: nop
    
            goto L_800A3FE4;
    }
    // 0x800A3FD8: nop

    // 0x800A3FDC: jr          $ra
    // 0x800A3FE0: addiu       $v0, $zero, 0x17F
    ctx->r2 = ADD32(0, 0X17F);
    return;
    // 0x800A3FE0: addiu       $v0, $zero, 0x17F
    ctx->r2 = ADD32(0, 0X17F);
L_800A3FE4:
    // 0x800A3FE4: jr          $ra
    // 0x800A3FE8: nop

    return;
    // 0x800A3FE8: nop

;}
RECOMP_FUNC void HUD_RadarMark_Enemy_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089710: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089714: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089718: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008971C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089720: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089728: jal         0x800B8DD0
    // 0x8008972C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008972C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80089730: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80089734: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089738: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008973C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089740: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80089744: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80089748: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008974C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80089750: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80089754: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80089758: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008975C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80089760: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089764: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089768: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8008976C: jal         0x80005C34
    // 0x80089770: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80089770: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80089774: jal         0x80006EB8
    // 0x80089778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80089778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008977C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089780: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x80089784: addiu       $t2, $t2, 0x4AC0
    ctx->r10 = ADD32(ctx->r10, 0X4AC0);
    // 0x80089788: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8008978C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80089790: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80089794: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80089798: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008979C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800897A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800897A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800897A8: jr          $ra
    // 0x800897AC: nop

    return;
    // 0x800897AC: nop

;}
RECOMP_FUNC void Audio_SetDelayedSeqCmd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018E9C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80018EA0: addiu       $a2, $a2, -0x48F8
    ctx->r6 = ADD32(ctx->r6, -0X48F8);
    // 0x80018EA4: srl         $v0, $a0, 28
    ctx->r2 = S32(U32(ctx->r4) >> 28);
    // 0x80018EA8: lhu         $t0, 0x0($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X0);
    // 0x80018EAC: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80018EB0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80018EB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80018EB8: addiu       $t9, $t9, -0x48F0
    ctx->r25 = ADD32(ctx->r25, -0X48F0);
    // 0x80018EBC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80018EC0: sllv        $t2, $t1, $t7
    ctx->r10 = S32(ctx->r9 << (ctx->r15 & 31));
    // 0x80018EC4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80018EC8: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80018ECC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80018ED0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80018ED4: sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
    // 0x80018ED8: jr          $ra
    // 0x80018EDC: sh          $t3, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r11;
    return;
    // 0x80018EDC: sh          $t3, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r11;
;}
RECOMP_FUNC void func_80007CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007CF4: jal         0x80024D50
    // 0x80007CF8: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x80007CF8: nop

    after_0:
    // 0x80007CFC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80007D00: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80007D04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80007D08: beq         $a0, $t6, L_80007D4C
    if (ctx->r4 == ctx->r14) {
        // 0x80007D0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80007D4C;
    }
    // 0x80007D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007D10: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80007D14:
    // 0x80007D14: blez        $v0, L_80007D3C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80007D18: slti        $at, $v0, 0x7F
        ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
            goto L_80007D3C;
    }
    // 0x80007D18: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80007D1C: beql        $at, $zero, L_80007D40
    if (ctx->r1 == 0) {
        // 0x80007D20: lw          $v1, 0xC($v1)
        ctx->r3 = MEM_W(ctx->r3, 0XC);
            goto L_80007D40;
    }
    goto skip_0;
    // 0x80007D20: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x80007D24: lhu         $t7, 0x12($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X12);
    // 0x80007D28: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80007D2C: beql        $t8, $zero, L_80007D40
    if (ctx->r24 == 0) {
        // 0x80007D30: lw          $v1, 0xC($v1)
        ctx->r3 = MEM_W(ctx->r3, 0XC);
            goto L_80007D40;
    }
    goto skip_1;
    // 0x80007D30: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x80007D34: b           L_80007D50
    // 0x80007D38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80007D50;
    // 0x80007D38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80007D3C:
    // 0x80007D3C: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
L_80007D40:
    // 0x80007D40: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80007D44: bne         $a0, $v0, L_80007D14
    if (ctx->r4 != ctx->r2) {
        // 0x80007D48: nop
    
            goto L_80007D14;
    }
    // 0x80007D48: nop

L_80007D4C:
    // 0x80007D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007D50:
    // 0x80007D50: jr          $ra
    // 0x80007D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ActorCutscene_SyShip_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FCB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004FCBC: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8004FCC0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8004FCC4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004FCC8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8004FCCC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8004FCD0: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x8004FCD4: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x8004FCD8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8004FCDC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8004FCE0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8004FCE4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8004FCE8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8004FCEC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004FCF0: lhu         $t6, 0xBC($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0XBC);
    // 0x8004FCF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004FCF8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8004FCFC: bne         $t6, $zero, L_8004FD10
    if (ctx->r14 != 0) {
        // 0x8004FD00: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004FD10;
    }
    // 0x8004FD00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FD04: sh          $t7, 0xBC($s4)
    MEM_H(0XBC, ctx->r20) = ctx->r15;
    // 0x8004FD08: lwc1        $f4, 0x5C9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5C9C);
    // 0x8004FD0C: swc1        $f4, 0x128($s4)
    MEM_W(0X128, ctx->r20) = ctx->f4.u32l;
L_8004FD10:
    // 0x8004FD10: lwc1        $f0, 0x128($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X128);
    // 0x8004FD14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FD18: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8004FD1C: nop

    // 0x8004FD20: bc1fl       L_8004FE90
    if (!c1cs) {
        // 0x8004FD24: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8004FE90;
    }
    goto skip_0;
    // 0x8004FD24: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x8004FD28: lwc1        $f8, 0x5CA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5CA0);
    // 0x8004FD2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8004FD30: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004FD34: jal         0x800BA5B0
    // 0x8004FD38: swc1        $f10, 0x128($s4)
    MEM_W(0X128, ctx->r20) = ctx->f10.u32l;
    RCP_SetupDL_49(rdram, ctx);
        goto after_0;
    // 0x8004FD38: swc1        $f10, 0x128($s4)
    MEM_W(0X128, ctx->r20) = ctx->f10.u32l;
    after_0:
    // 0x8004FD3C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8004FD40: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8004FD44: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8004FD48: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8004FD4C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004FD50: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8004FD54: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8004FD58: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8004FD5C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8004FD60: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8004FD64: lui         $t3, 0x1010
    ctx->r11 = S32(0X1010 << 16);
    // 0x8004FD68: ori         $t3, $t3, 0xF0FF
    ctx->r11 = ctx->r11 | 0XF0FF;
    // 0x8004FD6C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8004FD70: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x8004FD74: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x8004FD78: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8004FD7C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8004FD80: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004FD84: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8004FD88: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8004FD8C: lwc1        $f18, 0x4C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8004FD90: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8004FD94: lwc1        $f6, 0x54($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8004FD98: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004FD9C: jal         0x80005100
    // 0x8004FDA0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x8004FDA0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x8004FDA4: addiu       $s5, $s0, 0x4
    ctx->r21 = ADD32(ctx->r16, 0X4);
    // 0x8004FDA8: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8004FDAC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8004FDB0: beq         $at, $zero, L_8004FE8C
    if (ctx->r1 == 0) {
        // 0x8004FDB4: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_8004FE8C;
    }
    // 0x8004FDB4: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8004FDB8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8004FDBC: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x8004FDC0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8004FDC4: addiu       $t5, $t5, -0x5EF0
    ctx->r13 = ADD32(ctx->r13, -0X5EF0);
    // 0x8004FDC8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8004FDCC: lui         $s6, 0x102
    ctx->r22 = S32(0X102 << 16);
    // 0x8004FDD0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8004FDD4: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8004FDD8: addiu       $s6, $s6, 0x4AC0
    ctx->r22 = ADD32(ctx->r22, 0X4AC0);
    // 0x8004FDDC: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8004FDE0: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
L_8004FDE4:
    // 0x8004FDE4: jal         0x80005740
    // 0x8004FDE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_2;
    // 0x8004FDE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8004FDEC: jal         0x80005708
    // 0x8004FDF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8004FDF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8004FDF4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004FDF8: lwc1        $f10, 0x4($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8004FDFC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004FE00: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8004FE04: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004FE08: lwc1        $f10, 0xC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8004FE0C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004FE10: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004FE14: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004FE18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004FE1C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004FE20: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8004FE24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004FE28: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004FE2C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8004FE30: jal         0x80005B00
    // 0x8004FE34: nop

    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x8004FE34: nop

    after_4:
    // 0x8004FE38: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8004FE3C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004FE40: jal         0x80005E90
    // 0x8004FE44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8004FE44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8004FE48: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004FE4C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004FE50: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8004FE54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004FE58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8004FE5C: jal         0x80005C34
    // 0x8004FE60: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x8004FE60: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x8004FE64: jal         0x80006EB8
    // 0x8004FE68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8004FE68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x8004FE6C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8004FE70: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004FE74: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8004FE78: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8004FE7C: sw          $s6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r22;
    // 0x8004FE80: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8004FE84: bne         $s2, $s5, L_8004FDE4
    if (ctx->r18 != ctx->r21) {
        // 0x8004FE88: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8004FDE4;
    }
    // 0x8004FE88: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8004FE8C:
    // 0x8004FE8C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8004FE90:
    // 0x8004FE90: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004FE94: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8004FE98: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8004FE9C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8004FEA0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8004FEA4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8004FEA8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8004FEAC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8004FEB0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8004FEB4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8004FEB8: jr          $ra
    // 0x8004FEBC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8004FEBC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_pause_800A3CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3CA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A3CA4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800A3CA8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800A3CAC: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800A3CB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A3CB4: jal         0x80005708
    // 0x800A3CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x800A3CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A3CBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3CC0: lwc1        $f4, 0x79A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x800A3CC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3CC8: lwc1        $f6, 0x79B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x800A3CCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3CD0: lwc1        $f8, 0x79C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x800A3CD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A3CD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A3CDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A3CE0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A3CE4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800A3CE8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800A3CEC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A3CF0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800A3CF4: lw          $a3, 0x7988($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7988);
    // 0x800A3CF8: lw          $a2, 0x7980($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7980);
    // 0x800A3CFC: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x800A3D00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800A3D04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A3D08: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800A3D0C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800A3D10: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A3D14: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800A3D18: jal         0x80006E3C
    // 0x800A3D1C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x800A3D1C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800A3D20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A3D24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A3D28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800A3D2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A3D30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800A3D34: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800A3D38: jal         0x80005B00
    // 0x800A3D3C: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x800A3D3C: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_2:
    // 0x800A3D40: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A3D44: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x800A3D48: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800A3D4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3D50: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A3D54: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A3D58: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800A3D5C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800A3D60: lb          $t0, -0x2766($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2766);
    // 0x800A3D64: lwc1        $f4, -0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D20);
    // 0x800A3D68: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800A3D6C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A3D70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A3D74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A3D78: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3D7C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A3D80: jal         0x80005E90
    // 0x800A3D84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x800A3D84: nop

    after_3:
    // 0x800A3D88: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800A3D8C: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x800A3D90: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A3D94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3D98: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A3D9C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A3DA0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800A3DA4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A3DA8: lb          $t3, -0x2765($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2765);
    // 0x800A3DAC: lwc1        $f16, -0x7D1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D1C);
    // 0x800A3DB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800A3DB4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A3DB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A3DBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A3DC0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A3DC4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A3DC8: jal         0x80005D44
    // 0x800A3DCC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x800A3DCC: nop

    after_4:
    // 0x800A3DD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A3DD4: jal         0x80006EB8
    // 0x800A3DD8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x800A3DD8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_5:
    // 0x800A3DDC: jal         0x800BA1A0
    // 0x800A3DE0: nop

    RCP_SetupDL_23(rdram, ctx);
        goto after_6;
    // 0x800A3DE0: nop

    after_6:
    // 0x800A3DE4: jal         0x80005740
    // 0x800A3DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x800A3DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800A3DEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A3DF0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800A3DF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A3DF8: jr          $ra
    // 0x800A3DFC: nop

    return;
    // 0x800A3DFC: nop

;}
RECOMP_FUNC void Audio_PlaySequenceDistorted(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D9E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D9E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D9E8: lhu         $t6, 0x2E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2E);
    // 0x8001D9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D9F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001D9F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D9F8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001D9FC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8001DA00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001DA04: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x8001DA08: jal         0x8001D444
    // 0x8001DA0C: andi        $a1, $t6, 0x7FFF
    ctx->r5 = ctx->r14 & 0X7FFF;
    Audio_PlaySequence(rdram, ctx);
        goto after_0;
    // 0x8001DA0C: andi        $a1, $t6, 0x7FFF
    ctx->r5 = ctx->r14 & 0X7FFF;
    after_0:
    // 0x8001DA10: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
    // 0x8001DA14: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x8001DA18: lhu         $v0, 0x32($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X32);
    // 0x8001DA1C: lui         $at, 0x5000
    ctx->r1 = S32(0X5000 << 16);
    // 0x8001DA20: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x8001DA24: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x8001DA28: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8001DA2C: or          $t1, $t0, $t9
    ctx->r9 = ctx->r8 | ctx->r25;
    // 0x8001DA30: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8001DA34: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001DA38: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8001DA3C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001DA40: or          $a0, $t1, $v0
    ctx->r4 = ctx->r9 | ctx->r2;
    // 0x8001DA44: jal         0x800182F4
    // 0x8001DA48: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x8001DA48: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001DA4C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DA50: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x8001DA54: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8001DA58: ori         $at, $at, 0x3000
    ctx->r1 = ctx->r1 | 0X3000;
    // 0x8001DA5C: or          $t2, $v1, $at
    ctx->r10 = ctx->r3 | ctx->r1;
    // 0x8001DA60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8001DA64: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8001DA68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8001DA6C: mflo        $t4
    ctx->r12 = lo;
    // 0x8001DA70: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8001DA74: or          $t3, $t2, $a1
    ctx->r11 = ctx->r10 | ctx->r5;
    // 0x8001DA78: jal         0x800182F4
    // 0x8001DA7C: or          $a0, $t3, $t5
    ctx->r4 = ctx->r11 | ctx->r13;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x8001DA7C: or          $a0, $t3, $t5
    ctx->r4 = ctx->r11 | ctx->r13;
    after_2:
    // 0x8001DA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DA84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DA88: jr          $ra
    // 0x8001DA8C: nop

    return;
    // 0x8001DA8C: nop

;}
RECOMP_FUNC void __nearbyint_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF5C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001FF60: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001FF64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001FF68: nop

    // 0x8001FF6C: add.d       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f12.d + ctx->f4.d;
    // 0x8001FF70: floor.w.d   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floor(ctx->f0.d));
    // 0x8001FF74: jr          $ra
    // 0x8001FF78: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    return;
    // 0x8001FF78: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
;}
RECOMP_FUNC void PlayerShot_ApplyDamageToActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037CF4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80037CF8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80037CFC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80037D00: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80037D04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80037D08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80037D0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80037D10: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80037D14: addiu       $t7, $t7, -0x6440
    ctx->r15 = ADD32(ctx->r15, -0X6440);
    // 0x80037D18: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80037D1C: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x80037D20: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80037D24: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80037D28: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80037D2C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80037D30: addiu       $t1, $a2, -0x1
    ctx->r9 = ADD32(ctx->r6, -0X1);
    // 0x80037D34: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80037D38: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80037D3C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80037D40: sb          $a3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r7;
    // 0x80037D44: sh          $t1, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r9;
    // 0x80037D48: sh          $t2, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r10;
    // 0x80037D4C: sh          $t3, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r11;
    // 0x80037D50: lw          $v0, 0x68($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X68);
    // 0x80037D54: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80037D58: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80037D5C: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80037D60: beq         $at, $zero, L_80037DC8
    if (ctx->r1 == 0) {
        // 0x80037D64: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80037DC8;
    }
    // 0x80037D64: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80037D68: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80037D6C: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80037D70: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80037D74: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80037D78: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80037D7C: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x80037D80: lw          $t8, 0x1CC($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X1CC);
    // 0x80037D84: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80037D88: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80037D8C: beq         $a3, $t8, L_80037DC8
    if (ctx->r7 == ctx->r24) {
        // 0x80037D90: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_80037DC8;
    }
    // 0x80037D90: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80037D94: lw          $v1, 0x1AA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1AA8);
    // 0x80037D98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037D9C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80037DA0: beq         $v1, $a3, L_80037DB8
    if (ctx->r3 == ctx->r7) {
        // 0x80037DA4: nop
    
            goto L_80037DB8;
    }
    // 0x80037DA4: nop

    // 0x80037DA8: beq         $v1, $at, L_80037DC0
    if (ctx->r3 == ctx->r1) {
        // 0x80037DAC: addiu       $t0, $zero, 0xF
        ctx->r8 = ADD32(0, 0XF);
            goto L_80037DC0;
    }
    // 0x80037DAC: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80037DB0: b           L_80037E40
    // 0x80037DB4: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
        goto L_80037E40;
    // 0x80037DB4: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
L_80037DB8:
    // 0x80037DB8: b           L_80037E3C
    // 0x80037DBC: sh          $t7, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r15;
        goto L_80037E3C;
    // 0x80037DBC: sh          $t7, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r15;
L_80037DC0:
    // 0x80037DC0: b           L_80037E3C
    // 0x80037DC4: sh          $t0, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r8;
        goto L_80037E3C;
    // 0x80037DC4: sh          $t0, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r8;
L_80037DC8:
    // 0x80037DC8: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80037DCC: bne         $at, $zero, L_80037E3C
    if (ctx->r1 != 0) {
        // 0x80037DD0: lui         $t1, 0x8018
        ctx->r9 = S32(0X8018 << 16);
            goto L_80037E3C;
    }
    // 0x80037DD0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80037DD4: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x80037DD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037DDC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80037DE0: bne         $t1, $at, L_80037E3C
    if (ctx->r9 != ctx->r1) {
        // 0x80037DE4: subu        $t2, $t2, $v0
        ctx->r10 = SUB32(ctx->r10, ctx->r2);
            goto L_80037E3C;
    }
    // 0x80037DE4: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80037DE8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80037DEC: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80037DF0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80037DF4: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80037DF8: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80037DFC: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x80037E00: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80037E04: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80037E08: addiu       $t4, $t4, 0x3FE0
    ctx->r12 = ADD32(ctx->r12, 0X3FE0);
    // 0x80037E0C: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80037E10: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80037E14: lhu         $t5, 0x58B2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X58B2);
    // 0x80037E18: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80037E1C: bnel        $a1, $t5, L_80037E40
    if (ctx->r5 != ctx->r13) {
        // 0x80037E20: lhu         $v0, 0x2($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X2);
            goto L_80037E40;
    }
    goto skip_0;
    // 0x80037E20: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    skip_0:
    // 0x80037E24: lw          $t9, 0x5930($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X5930);
    // 0x80037E28: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80037E2C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80037E30: bnel        $t9, $at, L_80037E40
    if (ctx->r25 != ctx->r1) {
        // 0x80037E34: lhu         $v0, 0x2($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X2);
            goto L_80037E40;
    }
    goto skip_1;
    // 0x80037E34: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    skip_1:
    // 0x80037E38: sh          $t8, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r24;
L_80037E3C:
    // 0x80037E3C: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
L_80037E40:
    // 0x80037E40: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80037E44: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80037E48: bne         $v0, $at, L_80037E5C
    if (ctx->r2 != ctx->r1) {
        // 0x80037E4C: addiu       $t6, $zero, 0x64
        ctx->r14 = ADD32(0, 0X64);
            goto L_80037E5C;
    }
    // 0x80037E4C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80037E50: sh          $t6, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r14;
    // 0x80037E54: b           L_80037E98
    // 0x80037E58: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
        goto L_80037E98;
    // 0x80037E58: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80037E5C:
    // 0x80037E5C: bne         $a0, $v0, L_80037E98
    if (ctx->r4 != ctx->r2) {
        // 0x80037E60: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_80037E98;
    }
    // 0x80037E60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80037E64: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80037E68: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80037E6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80037E70: bne         $t7, $at, L_80037E84
    if (ctx->r15 != ctx->r1) {
        // 0x80037E74: addiu       $t2, $zero, 0x1E
        ctx->r10 = ADD32(0, 0X1E);
            goto L_80037E84;
    }
    // 0x80037E74: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80037E78: addiu       $t0, $zero, 0x1F
    ctx->r8 = ADD32(0, 0X1F);
    // 0x80037E7C: b           L_80037E98
    // 0x80037E80: sh          $t0, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r8;
        goto L_80037E98;
    // 0x80037E80: sh          $t0, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r8;
L_80037E84:
    // 0x80037E84: sb          $t1, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r9;
    // 0x80037E88: sh          $t2, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r10;
    // 0x80037E8C: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x80037E90: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80037E94: sb          $zero, 0xCA($t4)
    MEM_B(0XCA, ctx->r12) = 0;
L_80037E98:
    // 0x80037E98: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x80037E9C: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x80037EA0: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80037EA4: sh          $t9, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r25;
    // 0x80037EA8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80037EAC: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x80037EB0: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80037EB4: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    // 0x80037EB8: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80037EBC: bne         $a1, $v1, L_80037EEC
    if (ctx->r5 != ctx->r3) {
        // 0x80037EC0: swc1        $f8, 0xE0($s0)
        MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
            goto L_80037EEC;
    }
    // 0x80037EC0: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    // 0x80037EC4: lh          $t8, 0xD2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XD2);
    // 0x80037EC8: bnel        $t8, $zero, L_80037EF0
    if (ctx->r24 != 0) {
        // 0x80037ECC: addiu       $at, $zero, 0xC5
        ctx->r1 = ADD32(0, 0XC5);
            goto L_80037EF0;
    }
    goto skip_2;
    // 0x80037ECC: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    skip_2:
    // 0x80037ED0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80037ED4: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80037ED8: beq         $v0, $at, L_80037F7C
    if (ctx->r2 == ctx->r1) {
        // 0x80037EDC: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_80037F7C;
    }
    // 0x80037EDC: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80037EE0: beq         $v0, $at, L_80037F7C
    if (ctx->r2 == ctx->r1) {
        // 0x80037EE4: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80037F7C;
    }
    // 0x80037EE4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80037EE8: beq         $v0, $at, L_80037F7C
    if (ctx->r2 == ctx->r1) {
        // 0x80037EEC: addiu       $at, $zero, 0xC5
        ctx->r1 = ADD32(0, 0XC5);
            goto L_80037F7C;
    }
L_80037EEC:
    // 0x80037EEC: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
L_80037EF0:
    // 0x80037EF0: bne         $v1, $at, L_80037F10
    if (ctx->r3 != ctx->r1) {
        // 0x80037EF4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80037F10;
    }
    // 0x80037EF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037EF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037EFC: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80037F00: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80037F04: nop

    // 0x80037F08: bc1tl       L_80037F80
    if (c1cs) {
        // 0x80037F0C: addiu       $at, $zero, 0x105
        ctx->r1 = ADD32(0, 0X105);
            goto L_80037F80;
    }
    goto skip_3;
    // 0x80037F0C: addiu       $at, $zero, 0x105
    ctx->r1 = ADD32(0, 0X105);
    skip_3:
L_80037F10:
    // 0x80037F10: bnel        $a1, $v1, L_80037F34
    if (ctx->r5 != ctx->r3) {
        // 0x80037F14: addiu       $at, $zero, 0x105
        ctx->r1 = ADD32(0, 0X105);
            goto L_80037F34;
    }
    goto skip_4;
    // 0x80037F14: addiu       $at, $zero, 0x105
    ctx->r1 = ADD32(0, 0X105);
    skip_4:
    // 0x80037F18: lh          $t6, 0xD2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XD2);
    // 0x80037F1C: bnel        $t6, $zero, L_80037F34
    if (ctx->r14 != 0) {
        // 0x80037F20: addiu       $at, $zero, 0x105
        ctx->r1 = ADD32(0, 0X105);
            goto L_80037F34;
    }
    goto skip_5;
    // 0x80037F20: addiu       $at, $zero, 0x105
    ctx->r1 = ADD32(0, 0X105);
    skip_5:
    // 0x80037F24: lh          $t7, 0xB4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB4);
    // 0x80037F28: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80037F2C: beq         $t7, $at, L_80037F7C
    if (ctx->r15 == ctx->r1) {
        // 0x80037F30: addiu       $at, $zero, 0x105
        ctx->r1 = ADD32(0, 0X105);
            goto L_80037F7C;
    }
    // 0x80037F30: addiu       $at, $zero, 0x105
    ctx->r1 = ADD32(0, 0X105);
L_80037F34:
    // 0x80037F34: bnel        $v1, $at, L_80037F60
    if (ctx->r3 != ctx->r1) {
        // 0x80037F38: addiu       $at, $zero, 0x104
        ctx->r1 = ADD32(0, 0X104);
            goto L_80037F60;
    }
    goto skip_6;
    // 0x80037F38: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    skip_6:
    // 0x80037F3C: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
    // 0x80037F40: beql        $a0, $t0, L_80037F60
    if (ctx->r4 == ctx->r8) {
        // 0x80037F44: addiu       $at, $zero, 0x104
        ctx->r1 = ADD32(0, 0X104);
            goto L_80037F60;
    }
    goto skip_7;
    // 0x80037F44: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    skip_7:
    // 0x80037F48: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x80037F4C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80037F50: bne         $at, $zero, L_80037F7C
    if (ctx->r1 != 0) {
        // 0x80037F54: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_80037F7C;
    }
    // 0x80037F54: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80037F58: beq         $at, $zero, L_80037F7C
    if (ctx->r1 == 0) {
        // 0x80037F5C: addiu       $at, $zero, 0x104
        ctx->r1 = ADD32(0, 0X104);
            goto L_80037F7C;
    }
    // 0x80037F5C: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
L_80037F60:
    // 0x80037F60: bne         $v1, $at, L_80038124
    if (ctx->r3 != ctx->r1) {
        // 0x80037F64: nop
    
            goto L_80038124;
    }
    // 0x80037F64: nop

    // 0x80037F68: lhu         $t1, 0x2($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X2);
    // 0x80037F6C: beq         $a0, $t1, L_80038124
    if (ctx->r4 == ctx->r9) {
        // 0x80037F70: nop
    
            goto L_80038124;
    }
    // 0x80037F70: nop

    // 0x80037F74: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x80037F78: beq         $t2, $zero, L_80038124
    if (ctx->r10 == 0) {
        // 0x80037F7C: addiu       $at, $zero, 0x105
        ctx->r1 = ADD32(0, 0X105);
            goto L_80038124;
    }
L_80037F7C:
    // 0x80037F7C: addiu       $at, $zero, 0x105
    ctx->r1 = ADD32(0, 0X105);
L_80037F80:
    // 0x80037F80: bnel        $v1, $at, L_80037FA4
    if (ctx->r3 != ctx->r1) {
        // 0x80037F84: lhu         $v0, 0x2($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X2);
            goto L_80037FA4;
    }
    goto skip_8;
    // 0x80037F84: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    skip_8:
    // 0x80037F88: lh          $t3, 0xB8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB8);
    // 0x80037F8C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80037F90: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80037F94: beql        $at, $zero, L_80037FA4
    if (ctx->r1 == 0) {
        // 0x80037F98: lhu         $v0, 0x2($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X2);
            goto L_80037FA4;
    }
    goto skip_9;
    // 0x80037F98: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    skip_9:
    // 0x80037F9C: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
    // 0x80037FA0: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
L_80037FA4:
    // 0x80037FA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80037FA8: beq         $a0, $v0, L_80037FB8
    if (ctx->r4 == ctx->r2) {
        // 0x80037FAC: nop
    
            goto L_80037FB8;
    }
    // 0x80037FAC: nop

    // 0x80037FB0: bnel        $v0, $at, L_80037FCC
    if (ctx->r2 != ctx->r1) {
        // 0x80037FB4: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80037FCC;
    }
    goto skip_10;
    // 0x80037FB4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_10:
L_80037FB8:
    // 0x80037FB8: jal         0x80036318
    // 0x80037FBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_0;
    // 0x80037FBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80037FC0: b           L_80038130
    // 0x80037FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80038130;
    // 0x80037FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80037FC8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80037FCC:
    // 0x80037FCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037FD0: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80037FD4: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    // 0x80037FD8: sw          $t5, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r13;
    // 0x80037FDC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80037FE0: jal         0x80004EB0
    // 0x80037FE4: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80037FE4: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    after_1:
    // 0x80037FE8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80037FEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037FF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80037FF4: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80037FF8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80037FFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80038000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80038004: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x80038008: lwc1        $f18, 0x5240($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5240);
    // 0x8003800C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80038010: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038014: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80038018: jal         0x80005E90
    // 0x8003801C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8003801C: nop

    after_2:
    // 0x80038020: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038024: lwc1        $f8, 0x5244($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5244);
    // 0x80038028: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003802C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80038030: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80038034: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80038038: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003803C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80038040: jal         0x80005D44
    // 0x80038044: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x80038044: nop

    after_3:
    // 0x80038048: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003804C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80038050: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80038054: jal         0x80006A20
    // 0x80038058: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x80038058: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x8003805C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80038060: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80038064: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80038068: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x8003806C: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80038070: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80038074: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038078: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003807C: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x80038080: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80038084: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038088: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8003808C: swc1        $f4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f4.u32l;
    // 0x80038090: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80038094: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80038098: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003809C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800380A0: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800380A4: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x800380A8: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800380AC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800380B0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800380B4: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x800380B8: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800380BC: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x800380C0: sh          $t9, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r25;
    // 0x800380C4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800380C8: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800380CC: jal         0x80078E50
    // 0x800380D0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_5;
    // 0x800380D0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_5:
    // 0x800380D4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800380D8: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800380DC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800380E0: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x800380E4: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x800380E8: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x800380EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800380F0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800380F4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800380F8: jal         0x80019218
    // 0x800380FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x800380FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80038100: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80038104: lwc1        $f12, -0x7B64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7B64);
    // 0x80038108: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003810C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80038110: lw          $a2, -0x7B68($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B68);
    // 0x80038114: jal         0x800A668C
    // 0x80038118: lwc1        $f14, -0x7B60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7B60);
    Play_SpawnHitmark(rdram, ctx);
        goto after_7;
    // 0x80038118: lwc1        $f14, -0x7B60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7B60);
    after_7:
    // 0x8003811C: b           L_80038130
    // 0x80038120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80038130;
    // 0x80038120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80038124:
    // 0x80038124: jal         0x80036318
    // 0x80038128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_8;
    // 0x80038128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8003812C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80038130:
    // 0x80038130: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80038134: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80038138: jr          $ra
    // 0x8003813C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003813C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __lround_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF30: round.w.d   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = lround(ctx->f12.d);
    // 0x8001FF34: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001FF38: jr          $ra
    // 0x8001FF3C: nop

    return;
    // 0x8001FF3C: nop

;}
RECOMP_FUNC void Object_PlayerSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060F30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060F38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80060F3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80060F40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80060F44: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80060F48: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x80060F4C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80060F50: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80060F54: bne         $t6, $zero, L_80060F90
    if (ctx->r14 != 0) {
        // 0x80060F58: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80060F90;
    }
    // 0x80060F58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80060F5C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80060F60: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80060F64: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80060F68: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80060F6C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80060F70: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80060F74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80060F78: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80060F7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80060F80: jal         0x80019218
    // 0x80060F84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80060F84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80060F88: b           L_80060FB0
    // 0x80060F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80060FB0;
    // 0x80060F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80060F90:
    // 0x80060F90: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80060F94: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80060F98: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80060F9C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80060FA0: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x80060FA4: jal         0x80019218
    // 0x80060FA8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80060FA8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x80060FAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80060FB0:
    // 0x80060FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060FB4: jr          $ra
    // 0x80060FB8: nop

    return;
    // 0x80060FB8: nop

;}
RECOMP_FUNC void Audio_AllocNoteFromDecaying(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012ED4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012EDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80012EE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80012EE4: jal         0x800145FC
    // 0x80012EE8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    AudioSeq_AudioListPopBack(rdram, ctx);
        goto after_0;
    // 0x80012EE8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80012EEC: beq         $v0, $zero, L_80012F10
    if (ctx->r2 == 0) {
        // 0x80012EF0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80012F10;
    }
    // 0x80012EF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80012EF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80012EF8: jal         0x80012E5C
    // 0x80012EFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    Audio_NoteReleaseAndTakeOwnership(rdram, ctx);
        goto after_1;
    // 0x80012EFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80012F00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80012F04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F08: jal         0x800145BC
    // 0x80012F0C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_2;
    // 0x80012F0C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
L_80012F10:
    // 0x80012F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012F14: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012F1C: jr          $ra
    // 0x80012F20: nop

    return;
    // 0x80012F20: nop

;}
RECOMP_FUNC void func_tank_80045E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045E84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80045E88: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80045E8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80045E90: lwc1        $f12, 0x130($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X130);
    // 0x80045E94: jal         0x80004E20
    // 0x80045E98: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Math_ModF(rdram, ctx);
        goto after_0;
    // 0x80045E98: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80045E9C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80045EA0: lw          $t6, 0x1DC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1DC);
    // 0x80045EA4: swc1        $f0, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->f0.u32l;
    // 0x80045EA8: bnel        $t6, $zero, L_80045F3C
    if (ctx->r14 != 0) {
        // 0x80045EAC: lw          $v0, 0x1E0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X1E0);
            goto L_80045F3C;
    }
    goto skip_0;
    // 0x80045EAC: lw          $v0, 0x1E0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1E0);
    skip_0:
    // 0x80045EB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80045EB4: lwc1        $f0, 0x130($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X130);
    // 0x80045EB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045EBC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80045EC0: nop

    // 0x80045EC4: bc1fl       L_80045EFC
    if (!c1cs) {
        // 0x80045EC8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80045EFC;
    }
    goto skip_1;
    // 0x80045EC8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x80045ECC: lwc1        $f12, 0x56CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X56CC);
    // 0x80045ED0: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80045ED4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80045ED8: swc1        $f6, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->f6.u32l;
    // 0x80045EDC: lwc1        $f0, 0x130($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X130);
    // 0x80045EE0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80045EE4: nop

    // 0x80045EE8: bc1fl       L_80045EFC
    if (!c1cs) {
        // 0x80045EEC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80045EFC;
    }
    goto skip_2;
    // 0x80045EEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x80045EF0: swc1        $f2, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->f2.u32l;
    // 0x80045EF4: lwc1        $f0, 0x130($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X130);
    // 0x80045EF8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80045EFC:
    // 0x80045EFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045F00: lwc1        $f12, 0x56D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X56D0);
    // 0x80045F04: bc1fl       L_80045F3C
    if (!c1cs) {
        // 0x80045F08: lw          $v0, 0x1E0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X1E0);
            goto L_80045F3C;
    }
    goto skip_3;
    // 0x80045F08: lw          $v0, 0x1E0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1E0);
    skip_3:
    // 0x80045F0C: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80045F10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045F14: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80045F18: swc1        $f10, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->f10.u32l;
    // 0x80045F1C: lwc1        $f18, 0x130($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X130);
    // 0x80045F20: lwc1        $f16, 0x56D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X56D4);
    // 0x80045F24: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80045F28: nop

    // 0x80045F2C: bc1fl       L_80045F3C
    if (!c1cs) {
        // 0x80045F30: lw          $v0, 0x1E0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X1E0);
            goto L_80045F3C;
    }
    goto skip_4;
    // 0x80045F30: lw          $v0, 0x1E0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1E0);
    skip_4:
    // 0x80045F34: swc1        $f2, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->f2.u32l;
    // 0x80045F38: lw          $v0, 0x1E0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1E0);
L_80045F3C:
    // 0x80045F3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80045F40: beq         $v0, $zero, L_80045F4C
    if (ctx->r2 == 0) {
        // 0x80045F44: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80045F4C;
    }
    // 0x80045F44: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80045F48: sw          $t7, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r15;
L_80045F4C:
    // 0x80045F4C: lw          $v0, 0x1E4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1E4);
    // 0x80045F50: beq         $v0, $zero, L_80045F5C
    if (ctx->r2 == 0) {
        // 0x80045F54: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80045F5C;
    }
    // 0x80045F54: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80045F58: sw          $t8, 0x1E4($a2)
    MEM_W(0X1E4, ctx->r6) = ctx->r24;
L_80045F5C:
    // 0x80045F5C: lw          $v0, 0x1E8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1E8);
    // 0x80045F60: beq         $v0, $zero, L_80045F6C
    if (ctx->r2 == 0) {
        // 0x80045F64: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80045F6C;
    }
    // 0x80045F64: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80045F68: sw          $t9, 0x1E8($a2)
    MEM_W(0X1E8, ctx->r6) = ctx->r25;
L_80045F6C:
    // 0x80045F6C: lw          $t0, 0x1DC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1DC);
    // 0x80045F70: beql        $t0, $zero, L_800460D4
    if (ctx->r8 == 0) {
        // 0x80045F74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800460D4;
    }
    goto skip_5;
    // 0x80045F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80045F78: lw          $t1, 0x1EC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X1EC);
    // 0x80045F7C: lwc1        $f0, 0x12C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X12C);
    // 0x80045F80: lwc1        $f4, 0x130($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X130);
    // 0x80045F84: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80045F88: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80045F8C: sw          $zero, 0x1E4($a2)
    MEM_W(0X1E4, ctx->r6) = 0;
    // 0x80045F90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80045F94: sw          $zero, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = 0;
    // 0x80045F98: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80045F9C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80045FA0: bc1f        L_80045FD4
    if (!c1cs) {
        // 0x80045FA4: swc1        $f10, 0x130($a2)
        MEM_W(0X130, ctx->r6) = ctx->f10.u32l;
            goto L_80045FD4;
    }
    // 0x80045FA4: swc1        $f10, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->f10.u32l;
    // 0x80045FA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80045FAC: nop

    // 0x80045FB0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80045FB4: swc1        $f18, 0x12C($a2)
    MEM_W(0X12C, ctx->r6) = ctx->f18.u32l;
    // 0x80045FB8: lwc1        $f0, 0x12C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X12C);
    // 0x80045FBC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80045FC0: nop

    // 0x80045FC4: bc1fl       L_80045FD8
    if (!c1cs) {
        // 0x80045FC8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80045FD8;
    }
    goto skip_6;
    // 0x80045FC8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_6:
    // 0x80045FCC: swc1        $f2, 0x12C($a2)
    MEM_W(0X12C, ctx->r6) = ctx->f2.u32l;
    // 0x80045FD0: lwc1        $f0, 0x12C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X12C);
L_80045FD4:
    // 0x80045FD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80045FD8:
    // 0x80045FD8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80045FDC: bc1fl       L_80046010
    if (!c1cs) {
        // 0x80045FE0: lw          $t2, 0x1E8($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X1E8);
            goto L_80046010;
    }
    goto skip_7;
    // 0x80045FE0: lw          $t2, 0x1E8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X1E8);
    skip_7:
    // 0x80045FE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045FE8: nop

    // 0x80045FEC: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80045FF0: swc1        $f4, 0x12C($a2)
    MEM_W(0X12C, ctx->r6) = ctx->f4.u32l;
    // 0x80045FF4: lwc1        $f8, 0x12C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X12C);
    // 0x80045FF8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80045FFC: nop

    // 0x80046000: bc1fl       L_80046010
    if (!c1cs) {
        // 0x80046004: lw          $t2, 0x1E8($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X1E8);
            goto L_80046010;
    }
    goto skip_8;
    // 0x80046004: lw          $t2, 0x1E8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X1E8);
    skip_8:
    // 0x80046008: swc1        $f2, 0x12C($a2)
    MEM_W(0X12C, ctx->r6) = ctx->f2.u32l;
    // 0x8004600C: lw          $t2, 0x1E8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X1E8);
L_80046010:
    // 0x80046010: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80046014: bnel        $t2, $zero, L_8004607C
    if (ctx->r10 != 0) {
        // 0x80046018: lw          $t7, 0x1E8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X1E8);
            goto L_8004607C;
    }
    goto skip_9;
    // 0x80046018: lw          $t7, 0x1E8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1E8);
    skip_9:
    // 0x8004601C: lw          $t3, 0x1C4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X1C4);
    // 0x80046020: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046024: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80046028: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8004602C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80046030: swc1        $f10, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f10.u32l;
    // 0x80046034: lw          $v0, 0x1EC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1EC);
    // 0x80046038: addiu       $a0, $a2, 0x460
    ctx->r4 = ADD32(ctx->r6, 0X460);
    // 0x8004603C: lui         $a1, 0x1100
    ctx->r5 = S32(0X1100 << 16);
    // 0x80046040: blez        $v0, L_80046050
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80046044: addiu       $t5, $v0, -0x2
        ctx->r13 = ADD32(ctx->r2, -0X2);
            goto L_80046050;
    }
    // 0x80046044: addiu       $t5, $v0, -0x2
    ctx->r13 = ADD32(ctx->r2, -0X2);
    // 0x80046048: sw          $t5, 0x1EC($a2)
    MEM_W(0X1EC, ctx->r6) = ctx->r13;
    // 0x8004604C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80046050:
    // 0x80046050: bgez        $v0, L_80046060
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80046054: addiu       $t6, $v0, 0x2
        ctx->r14 = ADD32(ctx->r2, 0X2);
            goto L_80046060;
    }
    // 0x80046054: addiu       $t6, $v0, 0x2
    ctx->r14 = ADD32(ctx->r2, 0X2);
    // 0x80046058: sw          $t6, 0x1EC($a2)
    MEM_W(0X1EC, ctx->r6) = ctx->r14;
    // 0x8004605C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80046060:
    // 0x80046060: bne         $v0, $zero, L_80046078
    if (ctx->r2 != 0) {
        // 0x80046064: ori         $a1, $a1, 0xA
        ctx->r5 = ctx->r5 | 0XA;
            goto L_80046078;
    }
    // 0x80046064: ori         $a1, $a1, 0xA
    ctx->r5 = ctx->r5 | 0XA;
    // 0x80046068: sw          $zero, 0x1DC($a2)
    MEM_W(0X1DC, ctx->r6) = 0;
    // 0x8004606C: jal         0x8001A55C
    // 0x80046070: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_1;
    // 0x80046070: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80046074: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80046078:
    // 0x80046078: lw          $t7, 0x1E8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1E8);
L_8004607C:
    // 0x8004607C: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80046080: bnel        $at, $zero, L_800460D4
    if (ctx->r1 != 0) {
        // 0x80046084: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800460D4;
    }
    goto skip_10;
    // 0x80046084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x80046088: lw          $t8, 0x1F4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1F4);
    // 0x8004608C: bnel        $t8, $zero, L_800460D4
    if (ctx->r24 != 0) {
        // 0x80046090: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800460D4;
    }
    goto skip_11;
    // 0x80046090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x80046094: lw          $t9, 0x1DC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1DC);
    // 0x80046098: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004609C: beql        $t9, $at, L_800460D4
    if (ctx->r25 == ctx->r1) {
        // 0x800460A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800460D4;
    }
    goto skip_12;
    // 0x800460A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_12:
    // 0x800460A4: lw          $v0, 0x1EC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1EC);
    // 0x800460A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800460AC: blez        $v0, L_800460C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800460B0: nop
    
            goto L_800460C0;
    }
    // 0x800460B0: nop

    // 0x800460B4: lwc1        $f16, 0x56D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X56D8);
    // 0x800460B8: lw          $v0, 0x1EC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1EC);
    // 0x800460BC: swc1        $f16, 0x170($a2)
    MEM_W(0X170, ctx->r6) = ctx->f16.u32l;
L_800460C0:
    // 0x800460C0: bgez        $v0, L_800460D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800460C4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800460D0;
    }
    // 0x800460C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800460C8: lwc1        $f18, 0x56DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X56DC);
    // 0x800460CC: swc1        $f18, 0x16C($a2)
    MEM_W(0X16C, ctx->r6) = ctx->f18.u32l;
L_800460D0:
    // 0x800460D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800460D4:
    // 0x800460D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800460D8: jr          $ra
    // 0x800460DC: nop

    return;
    // 0x800460DC: nop

;}
RECOMP_FUNC void func_versus_800BED78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BED7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BED80: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BED84: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BED88: jal         0x800B8DD0
    // 0x800BED8C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BED8C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x800BED90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BED94: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BED98: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BED9C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BEDA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800BEDA4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BEDA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BEDAC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BEDB0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BEDB4: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x800BEDB8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BEDBC: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x800BEDC0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800BEDC4: jal         0x800BC8D8
    // 0x800BEDC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_versus_800BC8D8(rdram, ctx);
        goto after_1;
    // 0x800BEDC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x800BEDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BEDD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BEDD4: jr          $ra
    // 0x800BEDD8: nop

    return;
    // 0x800BEDD8: nop

;}
RECOMP_FUNC void ActorAllRange_MissileOverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800352E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800352E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800352E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800352EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800352F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800352F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800352F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800352FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80035300: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80035304: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80035308: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003530C: lhu         $t7, 0xC6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC6);
    // 0x80035310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035314: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80035318: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8003531C: beq         $t8, $zero, L_80035368
    if (ctx->r24 == 0) {
        // 0x80035320: nop
    
            goto L_80035368;
    }
    // 0x80035320: nop

    // 0x80035324: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80035328: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003532C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035330: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80035334: jal         0x800B8DD0
    // 0x80035338: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80035338: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003533C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80035340: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80035344: lui         $t1, 0xFF80
    ctx->r9 = S32(0XFF80 << 16);
    // 0x80035348: ori         $t1, $t1, 0x80FF
    ctx->r9 = ctx->r9 | 0X80FF;
    // 0x8003534C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80035350: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80035354: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80035358: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8003535C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80035360: b           L_80035378
    // 0x80035364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80035378;
    // 0x80035364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80035368:
    // 0x80035368: jal         0x800B8DD0
    // 0x8003536C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8003536C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80035370: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80035374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80035378:
    // 0x80035378: beq         $a2, $v0, L_80035384
    if (ctx->r6 == ctx->r2) {
        // 0x8003537C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80035384;
    }
    // 0x8003537C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80035380: bne         $a2, $at, L_800353B0
    if (ctx->r6 != ctx->r1) {
        // 0x80035384: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_800353B0;
    }
L_80035384:
    // 0x80035384: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80035388: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8003538C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80035390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80035394: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80035398: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8003539C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800353A0: lwc1        $f16, 0x8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800353A4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800353A8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800353AC: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
L_800353B0:
    // 0x800353B0: beq         $a2, $v0, L_800353BC
    if (ctx->r6 == ctx->r2) {
        // 0x800353B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800353BC;
    }
    // 0x800353B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800353B8: bne         $a2, $at, L_80035430
    if (ctx->r6 != ctx->r1) {
        // 0x800353BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80035430;
    }
L_800353BC:
    // 0x800353BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800353C0: jal         0x800B8DD0
    // 0x800353C4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x800353C4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_2:
    // 0x800353C8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800353CC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800353D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800353D4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800353D8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800353DC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800353E0: lwc1        $f4, -0x6EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6EC);
    // 0x800353E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800353E8: lwc1        $f8, -0x6E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6E8);
    // 0x800353EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800353F0: lwc1        $f10, -0x6E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6E4);
    // 0x800353F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800353F8: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800353FC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80035400: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80035404: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80035408: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8003540C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80035410: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80035414: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80035418: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8003541C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80035420: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x80035424: or          $t0, $t4, $t8
    ctx->r8 = ctx->r12 | ctx->r24;
    // 0x80035428: ori         $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 | 0XFF;
    // 0x8003542C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_80035430:
    // 0x80035430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035438: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003543C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80035440: jr          $ra
    // 0x80035444: nop

    return;
    // 0x80035444: nop

;}
RECOMP_FUNC void AudioSynth_SaveReverbSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000A12C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000A130: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x8000A134: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000A138: addiu       $t0, $t0, -0x45B0
    ctx->r8 = ADD32(ctx->r8, -0X45B0);
    // 0x8000A13C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8000A140: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8000A144: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000A148: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000A14C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000A150: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000A154: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000A158: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8000A15C: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x8000A160: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8000A164: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8000A168: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000A16C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8000A170: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8000A174: sll         $a3, $t7, 2
    ctx->r7 = S32(ctx->r15 << 2);
    // 0x8000A178: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8000A17C: lbu         $t4, 0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4);
    // 0x8000A180: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8000A184: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8000A188: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8000A18C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8000A190: addu        $v1, $t3, $a3
    ctx->r3 = ADD32(ctx->r11, ctx->r7);
    // 0x8000A194: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000A19C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000A1A0: bne         $t4, $at, L_8000A200
    if (ctx->r12 != ctx->r1) {
        // 0x8000A1A4: addiu       $v1, $v1, 0x34
        ctx->r3 = ADD32(ctx->r3, 0X34);
            goto L_8000A200;
    }
    // 0x8000A1A4: addiu       $v1, $v1, 0x34
    ctx->r3 = ADD32(ctx->r3, 0X34);
    // 0x8000A1A8: lh          $t5, 0x2E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2E);
    // 0x8000A1AC: lhu         $a2, 0xE($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XE);
    // 0x8000A1B0: lh          $a3, 0x10($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X10);
    // 0x8000A1B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8000A1B8: addiu       $a1, $zero, 0xC90
    ctx->r5 = ADD32(0, 0XC90);
    // 0x8000A1BC: jal         0x80009984
    // 0x8000A1C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    AudioSynth_SaveRingBufferPart(rdram, ctx);
        goto after_0;
    // 0x8000A1C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_0:
    // 0x8000A1C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000A1C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000A1CC: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x8000A1D0: lh          $a3, 0x12($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X12);
    // 0x8000A1D4: beql        $a3, $zero, L_8000A24C
    if (ctx->r7 == 0) {
        // 0x8000A1D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000A24C;
    }
    goto skip_0;
    // 0x8000A1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8000A1DC: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x8000A1E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000A1E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A1E8: addiu       $a1, $a1, 0xC90
    ctx->r5 = ADD32(ctx->r5, 0XC90);
    // 0x8000A1EC: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8000A1F0: jal         0x80009984
    // 0x8000A1F4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    AudioSynth_SaveRingBufferPart(rdram, ctx);
        goto after_1;
    // 0x8000A1F4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x8000A1F8: b           L_8000A248
    // 0x8000A1FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8000A248;
    // 0x8000A1FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8000A200:
    // 0x8000A200: lui         $t8, 0x1530
    ctx->r24 = S32(0X1530 << 16);
    // 0x8000A204: ori         $t8, $t8, 0xC90
    ctx->r24 = ctx->r24 | 0XC90;
    // 0x8000A208: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000A20C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A210: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8000A214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000A218: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000A21C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8000A220: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8000A224: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8000A228: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8000A22C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8000A230: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8000A234: addu        $t2, $t1, $a3
    ctx->r10 = ADD32(ctx->r9, ctx->r7);
    // 0x8000A238: lw          $t3, 0x38($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X38);
    // 0x8000A23C: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x8000A240: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8000A244: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8000A248:
    // 0x8000A248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A24C:
    // 0x8000A24C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000A250: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000A254: jr          $ra
    // 0x8000A258: nop

    return;
    // 0x8000A258: nop

;}
RECOMP_FUNC void Actor_DrawOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D954: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005D958: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005D95C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005D960: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005D964: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005D968: addiu       $t7, $t7, -0x314
    ctx->r15 = ADD32(ctx->r15, -0X314);
    // 0x8005D96C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005D970: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x8005D974: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8005D978: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005D97C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005D980: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8005D984: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8005D988: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x8005D98C: beql        $t1, $zero, L_8005DBB0
    if (ctx->r9 == 0) {
        // 0x8005D990: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005DBB0;
    }
    goto skip_0;
    // 0x8005D990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8005D994: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005D998: addiu       $at, $zero, 0xC2
    ctx->r1 = ADD32(0, 0XC2);
    // 0x8005D99C: beq         $v0, $at, L_8005D9B4
    if (ctx->r2 == ctx->r1) {
        // 0x8005D9A0: addiu       $at, $zero, 0xEC
        ctx->r1 = ADD32(0, 0XEC);
            goto L_8005D9B4;
    }
    // 0x8005D9A0: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x8005D9A4: beq         $v0, $at, L_8005D9C4
    if (ctx->r2 == ctx->r1) {
        // 0x8005D9A8: addiu       $v1, $zero, 0xC8
        ctx->r3 = ADD32(0, 0XC8);
            goto L_8005D9C4;
    }
    // 0x8005D9A8: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x8005D9AC: b           L_8005D9D4
    // 0x8005D9B0: nop

        goto L_8005D9D4;
    // 0x8005D9B0: nop

L_8005D9B4:
    // 0x8005D9B4: jal         0x8006B74C
    // 0x8005D9B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MeMora_Draw(rdram, ctx);
        goto after_0;
    // 0x8005D9B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8005D9BC: b           L_8005DBB0
    // 0x8005D9C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005DBB0;
    // 0x8005D9C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D9C4:
    // 0x8005D9C4: jal         0x80190F08
    // 0x8005D9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Zoness_ZoDodora_Draw(rdram, ctx);
        goto after_1;
    // 0x8005D9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8005D9CC: b           L_8005DBB0
    // 0x8005D9D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005DBB0;
    // 0x8005D9D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D9D4:
    // 0x8005D9D4: bnel        $v1, $v0, L_8005D9FC
    if (ctx->r3 != ctx->r2) {
        // 0x8005D9D8: lbu         $t3, 0x35($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X35);
            goto L_8005D9FC;
    }
    goto skip_1;
    // 0x8005D9D8: lbu         $t3, 0x35($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X35);
    skip_1:
    // 0x8005D9DC: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
    // 0x8005D9E0: bnel        $v1, $t2, L_8005D9FC
    if (ctx->r3 != ctx->r10) {
        // 0x8005D9E4: lbu         $t3, 0x35($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X35);
            goto L_8005D9FC;
    }
    goto skip_2;
    // 0x8005D9E4: lbu         $t3, 0x35($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X35);
    skip_2:
    // 0x8005D9E8: jal         0x8006B74C
    // 0x8005D9EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MeMora_Draw(rdram, ctx);
        goto after_2;
    // 0x8005D9EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005D9F0: b           L_8005DBB0
    // 0x8005D9F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005DBB0;
    // 0x8005D9F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005D9F8: lbu         $t3, 0x35($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X35);
L_8005D9FC:
    // 0x8005D9FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DA00: beq         $t3, $zero, L_8005DA3C
    if (ctx->r11 == 0) {
        // 0x8005DA04: nop
    
            goto L_8005DA3C;
    }
    // 0x8005DA04: nop

    // 0x8005DA08: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005DA0C: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005DA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005DA14: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    // 0x8005DA18: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005DA1C: jal         0x8005D008
    // 0x8005DA20: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    Object_SetMatrix(rdram, ctx);
        goto after_3;
    // 0x8005DA20: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8005DA24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DA28: lwc1        $f16, -0x7B84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005DA2C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005DA30: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005DA34: b           L_8005DA90
    // 0x8005DA38: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_8005DA90;
    // 0x8005DA38: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_8005DA3C:
    // 0x8005DA3C: bne         $v1, $v0, L_8005DA88
    if (ctx->r3 != ctx->r2) {
        // 0x8005DA40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005DA88;
    }
    // 0x8005DA40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005DA44: lh          $t4, 0xB4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB4);
    // 0x8005DA48: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8005DA4C: beq         $t4, $at, L_8005DA88
    if (ctx->r12 == ctx->r1) {
        // 0x8005DA50: nop
    
            goto L_8005DA88;
    }
    // 0x8005DA50: nop

    // 0x8005DA54: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8005DA58: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8005DA5C: lbu         $t5, 0x20($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X20);
    // 0x8005DA60: lw          $a1, 0x2E8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2E8);
    // 0x8005DA64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005DA68: lw          $a2, 0x2EC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2EC);
    // 0x8005DA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005DA70: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005DA74: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8005DA78: jal         0x8005D3CC
    // 0x8005DA7C: nop

    ObjSpecial_SetMatrix(rdram, ctx);
        goto after_4;
    // 0x8005DA7C: nop

    after_4:
    // 0x8005DA80: b           L_8005DA94
    // 0x8005DA84: lbu         $t9, 0x20($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X20);
        goto L_8005DA94;
    // 0x8005DA84: lbu         $t9, 0x20($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X20);
L_8005DA88:
    // 0x8005DA88: jal         0x8005D008
    // 0x8005DA8C: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    Object_SetMatrix(rdram, ctx);
        goto after_5;
    // 0x8005DA8C: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_5:
L_8005DA90:
    // 0x8005DA90: lbu         $t9, 0x20($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X20);
L_8005DA94:
    // 0x8005DA94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005DA98: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8005DA9C: bnel        $t9, $zero, L_8005DAD4
    if (ctx->r25 != 0) {
        // 0x8005DAA0: lw          $t9, 0x1C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1C);
            goto L_8005DAD4;
    }
    goto skip_3;
    // 0x8005DAA0: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    skip_3:
    // 0x8005DAA4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005DAA8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005DAAC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DAB0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005DAB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DAB8: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x8005DABC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005DAC0: jal         0x8005F1EC
    // 0x8005DAC4: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    Object_UpdateSfxSource(rdram, ctx);
        goto after_6;
    // 0x8005DAC4: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    after_6:
    // 0x8005DAC8: b           L_8005DB48
    // 0x8005DACC: lbu         $t5, 0xCA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XCA);
        goto L_8005DB48;
    // 0x8005DACC: lbu         $t5, 0xCA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XCA);
    // 0x8005DAD0: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
L_8005DAD4:
    // 0x8005DAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005DAD8: jalr        $t9
    // 0x8005DADC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8005DADC: nop

    after_7:
    // 0x8005DAE0: jal         0x8005F1EC
    // 0x8005DAE4: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    Object_UpdateSfxSource(rdram, ctx);
        goto after_8;
    // 0x8005DAE4: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    after_8:
    // 0x8005DAE8: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005DAEC: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x8005DAF0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005DAF4: beq         $v0, $at, L_8005DB10
    if (ctx->r2 == ctx->r1) {
        // 0x8005DAF8: addiu       $at, $zero, 0xCB
        ctx->r1 = ADD32(0, 0XCB);
            goto L_8005DB10;
    }
    // 0x8005DAF8: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8005DAFC: bnel        $v0, $at, L_8005DB48
    if (ctx->r2 != ctx->r1) {
        // 0x8005DB00: lbu         $t5, 0xCA($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0XCA);
            goto L_8005DB48;
    }
    goto skip_4;
    // 0x8005DB00: lbu         $t5, 0xCA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XCA);
    skip_4:
    // 0x8005DB04: lh          $t0, 0xB6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB6);
    // 0x8005DB08: blezl       $t0, L_8005DB48
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8005DB0C: lbu         $t5, 0xCA($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0XCA);
            goto L_8005DB48;
    }
    goto skip_5;
    // 0x8005DB0C: lbu         $t5, 0xCA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XCA);
    skip_5:
L_8005DB10:
    // 0x8005DB10: lh          $t1, 0x1410($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1410);
    // 0x8005DB14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DB18: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8005DB1C: blez        $t1, L_8005DB44
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005DB20: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8005DB44;
    }
    // 0x8005DB20: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8005DB24: lh          $t2, 0xE4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE4);
    // 0x8005DB28: addiu       $t4, $t4, 0x7E98
    ctx->r12 = ADD32(ctx->r12, 0X7E98);
    // 0x8005DB2C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DB30: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005DB34: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005DB38: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005DB3C: jal         0x80006970
    // 0x8005DB40: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    Matrix_MultVec3f(rdram, ctx);
        goto after_9;
    // 0x8005DB40: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    after_9:
L_8005DB44:
    // 0x8005DB44: lbu         $t5, 0xCA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XCA);
L_8005DB48:
    // 0x8005DB48: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8005DB4C: beql        $t5, $zero, L_8005DBB0
    if (ctx->r13 == 0) {
        // 0x8005DB50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005DBB0;
    }
    goto skip_6;
    // 0x8005DB50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8005DB54: lh          $t8, 0x1410($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X1410);
    // 0x8005DB58: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005DB5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DB60: blezl       $t8, L_8005DBB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005DB64: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005DBB0;
    }
    goto skip_7;
    // 0x8005DB64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x8005DB68: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8005DB6C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8005DB70: addiu       $a2, $a2, 0x1578
    ctx->r6 = ADD32(ctx->r6, 0X1578);
    // 0x8005DB74: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005DB78: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DB7C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8005DB80: jal         0x80006970
    // 0x8005DB84: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x8005DB84: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x8005DB88: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8005DB8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005DB90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005DB94: lwc1        $f6, 0x1580($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1580);
    // 0x8005DB98: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005DB9C: nop

    // 0x8005DBA0: bc1fl       L_8005DBB0
    if (!c1cs) {
        // 0x8005DBA4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005DBB0;
    }
    goto skip_8;
    // 0x8005DBA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x8005DBA8: sb          $zero, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = 0;
    // 0x8005DBAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005DBB0:
    // 0x8005DBB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005DBB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005DBB8: jr          $ra
    // 0x8005DBBC: nop

    return;
    // 0x8005DBBC: nop

;}
RECOMP_FUNC void HUD_RadarWindowFrame_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085404: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085408: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008540C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80085410: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80085414: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80085418: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008541C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085420: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x80085424: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80085428: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x8008542C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085430: addiu       $a2, $a2, 0x16A0
    ctx->r6 = ADD32(ctx->r6, 0X16A0);
    // 0x80085434: addiu       $a1, $a1, 0x1280
    ctx->r5 = ADD32(ctx->r5, 0X1280);
    // 0x80085438: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008543C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80085440: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80085444: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80085448: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8008544C: jal         0x8009C320
    // 0x80085450: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x80085450: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80085454: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80085458: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008545C: jr          $ra
    // 0x80085460: nop

    return;
    // 0x80085460: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028DE0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80028DE4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80028DE8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80028DEC: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x80028DF0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80028DF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80028DF8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80028DFC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80028E00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80028E04: bne         $v1, $v0, L_80028E18
    if (ctx->r3 != ctx->r2) {
        // 0x80028E08: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_80028E18;
    }
    // 0x80028E08: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80028E0C: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x80028E10: b           L_80028E20
    // 0x80028E14: addiu       $s3, $s3, 0x7F94
    ctx->r19 = ADD32(ctx->r19, 0X7F94);
        goto L_80028E20;
    // 0x80028E14: addiu       $s3, $s3, 0x7F94
    ctx->r19 = ADD32(ctx->r19, 0X7F94);
L_80028E18:
    // 0x80028E18: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x80028E1C: addiu       $s3, $s3, 0x7F80
    ctx->r19 = ADD32(ctx->r19, 0X7F80);
L_80028E20:
    // 0x80028E20: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80028E24: bne         $v0, $at, L_80028E34
    if (ctx->r2 != ctx->r1) {
        // 0x80028E28: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_80028E34;
    }
    // 0x80028E28: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x80028E2C: b           L_80028E54
    // 0x80028E30: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_80028E54;
    // 0x80028E30: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_80028E34:
    // 0x80028E34: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80028E38: beq         $v0, $at, L_80028E50
    if (ctx->r2 == ctx->r1) {
        // 0x80028E3C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_80028E50;
    }
    // 0x80028E3C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80028E40: beq         $v1, $v0, L_80028E50
    if (ctx->r3 == ctx->r2) {
        // 0x80028E44: nop
    
            goto L_80028E50;
    }
    // 0x80028E44: nop

    // 0x80028E48: b           L_80028E50
    // 0x80028E4C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_80028E50;
    // 0x80028E4C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_80028E50:
    // 0x80028E50: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80028E54:
    // 0x80028E54: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80028E58: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80028E5C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80028E60: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80028E64: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80028E68: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80028E6C: beq         $v0, $at, L_80028E80
    if (ctx->r2 == ctx->r1) {
        // 0x80028E70: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_80028E80;
    }
    // 0x80028E70: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80028E74: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80028E78: bnel        $v0, $at, L_80028EBC
    if (ctx->r2 != ctx->r1) {
        // 0x80028E7C: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80028EBC;
    }
    goto skip_0;
    // 0x80028E7C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_80028E80:
    // 0x80028E80: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80028E84: bgtzl       $t4, L_80028EBC
    if (SIGNED(ctx->r12) > 0) {
        // 0x80028E88: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80028EBC;
    }
    goto skip_1;
    // 0x80028E88: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x80028E8C: bltz        $t4, L_80028E9C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80028E90: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80028E9C;
    }
    // 0x80028E90: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80028E94: b           L_80028EBC
    // 0x80028E98: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_80028EBC;
    // 0x80028E98: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80028E9C:
    // 0x80028E9C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80028EA0: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x80028EA4: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80028EA8: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x80028EAC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x80028EB0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80028EB4: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80028EB8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80028EBC:
    // 0x80028EBC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80028EC0: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80028EC4: bne         $t2, $zero, L_80028EE0
    if (ctx->r10 != 0) {
        // 0x80028EC8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80028EE0;
    }
    // 0x80028EC8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80028ECC: bnel        $t3, $zero, L_80028EE4
    if (ctx->r11 != 0) {
        // 0x80028ED0: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_80028EE4;
    }
    goto skip_2;
    // 0x80028ED0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x80028ED4: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80028ED8: beql        $t4, $zero, L_80028F1C
    if (ctx->r12 == 0) {
        // 0x80028EDC: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_80028F1C;
    }
    goto skip_3;
    // 0x80028EDC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_80028EE0:
    // 0x80028EE0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_80028EE4:
    // 0x80028EE4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80028EE8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80028EEC: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80028EF0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80028EF4: jal         0x80023CBC
    // 0x80028EF8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x80028EF8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x80028EFC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80028F00: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x80028F04: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80028F08: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x80028F0C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80028F10: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x80028F14: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80028F18: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_80028F1C:
    // 0x80028F1C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80028F20: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80028F24: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80028F28: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80028F2C: jal         0x80023CF8
    // 0x80028F30: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80028F30: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x80028F34: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80028F38: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x80028F3C: bltz        $v0, L_80028FEC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80028F40: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_80028FEC;
    }
    // 0x80028F40: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80028F44: bgtz        $v0, L_80028F54
    if (SIGNED(ctx->r2) > 0) {
        // 0x80028F48: nop
    
            goto L_80028F54;
    }
    // 0x80028F48: nop

    // 0x80028F4C: beql        $v1, $zero, L_80028FF0
    if (ctx->r3 == 0) {
        // 0x80028F50: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80028FF0;
    }
    goto skip_4;
    // 0x80028F50: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_80028F54:
    // 0x80028F54: blez        $s0, L_80028FEC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80028F58: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_80028FEC;
    }
    // 0x80028F58: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80028F5C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80028F60: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x80028F64: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80028F68: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80028F6C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80028F70: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80028F74: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80028F78:
    // 0x80028F78: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80028F7C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80028F80: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80028F84: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80028F88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028F8C: jal         0x8002AFB0
    // 0x80028F90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x80028F90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x80028F94: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80028F98: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80028F9C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x80028FA0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80028FA4: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80028FA8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80028FAC: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x80028FB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80028FB4: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x80028FB8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80028FBC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80028FC0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80028FC4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80028FC8: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80028FCC: bltz        $t8, L_80028FEC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80028FD0: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_80028FEC;
    }
    // 0x80028FD0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80028FD4: bgtz        $t8, L_80028FE4
    if (SIGNED(ctx->r24) > 0) {
        // 0x80028FD8: nop
    
            goto L_80028FE4;
    }
    // 0x80028FD8: nop

    // 0x80028FDC: beql        $t9, $zero, L_80028FF0
    if (ctx->r25 == 0) {
        // 0x80028FE0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80028FF0;
    }
    goto skip_5;
    // 0x80028FE0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_80028FE4:
    // 0x80028FE4: bgtzl       $s0, L_80028F78
    if (SIGNED(ctx->r16) > 0) {
        // 0x80028FE8: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80028F78;
    }
    goto skip_6;
    // 0x80028FE8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_80028FEC:
    // 0x80028FEC: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_80028FF0:
    // 0x80028FF0: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x80028FF4: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x80028FF8: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80028FFC: jal         0x80023FC0
    // 0x80029000: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80029000: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x80029004: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80029008: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8002900C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80029010: beq         $at, $zero, L_8002901C
    if (ctx->r1 == 0) {
        // 0x80029014: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_8002901C;
    }
    // 0x80029014: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x80029018: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_8002901C:
    // 0x8002901C: bgezl       $a0, L_80029060
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80029020: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80029060;
    }
    goto skip_7;
    // 0x80029020: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80029024: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x80029028: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8002902C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x80029030: bnel        $t7, $at, L_80029060
    if (ctx->r15 != ctx->r1) {
        // 0x80029034: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80029060;
    }
    goto skip_8;
    // 0x80029034: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80029038: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x8002903C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80029040: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80029044: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80029048: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x8002904C: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x80029050: blez        $s0, L_8002905C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80029054: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_8002905C;
    }
    // 0x80029054: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x80029058: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_8002905C:
    // 0x8002905C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80029060:
    // 0x80029060: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80029064: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80029068: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8002906C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80029070: jr          $ra
    // 0x80029074: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80029074: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
