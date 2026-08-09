#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Venom1_Ve1TempleEntrance_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801924A8: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x801924AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801924B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801924B4: beq         $v0, $zero, L_801924CC
    if (ctx->r2 == 0) {
        // 0x801924B8: nop
    
            goto L_801924CC;
    }
    // 0x801924B8: nop

    // 0x801924BC: beq         $v0, $at, L_80192504
    if (ctx->r2 == ctx->r1) {
        // 0x801924C0: nop
    
            goto L_80192504;
    }
    // 0x801924C0: nop

    // 0x801924C4: jr          $ra
    // 0x801924C8: nop

    return;
    // 0x801924C8: nop

L_801924CC:
    // 0x801924CC: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801924D0: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801924D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801924D8: lwc1        $f4, 0x7C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X7C);
    // 0x801924DC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801924E0: nop

    // 0x801924E4: bc1f        L_80192504
    if (!c1cs) {
        // 0x801924E8: nop
    
            goto L_80192504;
    }
    // 0x801924E8: nop

    // 0x801924EC: sb          $zero, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = 0;
    // 0x801924F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801924F4: sb          $zero, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = 0;
    // 0x801924F8: lw          $t7, 0x48($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X48);
    // 0x801924FC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80192500: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
L_80192504:
    // 0x80192504: jr          $ra
    // 0x80192508: nop

    return;
    // 0x80192508: nop

;}
RECOMP_FUNC void Venom1_Ve1Golemech_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801935CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801935D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801935D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801935D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801935DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801935E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801935E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801935E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801935EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801935F0: sw          $t1, -0x7ED4($at)
    MEM_W(-0X7ED4, ctx->r1) = ctx->r9;
    // 0x801935F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801935F8: sw          $zero, -0x3F48($at)
    MEM_W(-0X3F48, ctx->r1) = 0;
    // 0x801935FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193600: sw          $zero, -0x3F44($at)
    MEM_W(-0X3F44, ctx->r1) = 0;
    // 0x80193604: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193608: sw          $zero, -0x3F40($at)
    MEM_W(-0X3F40, ctx->r1) = 0;
    // 0x8019360C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80193610: sw          $t1, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = ctx->r9;
    // 0x80193614: lh          $t7, 0xA2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA2);
    // 0x80193618: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8019361C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80193620: addiu       $t9, $t9, -0x5FB4
    ctx->r25 = ADD32(ctx->r25, -0X5FB4);
    // 0x80193624: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80193628: sb          $t6, 0x5E($s0)
    MEM_B(0X5E, ctx->r16) = ctx->r14;
    // 0x8019362C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80193630: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80193634: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80193638: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019363C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80193640: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80193644: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80193648: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019364C: addiu       $t0, $t6, -0x47C8
    ctx->r8 = ADD32(ctx->r14, -0X47C8);
    // 0x80193650: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80193654: addiu       $a1, $a1, -0x57E0
    ctx->r5 = ADD32(ctx->r5, -0X57E0);
    // 0x80193658: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8019365C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80193660: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x80193664: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80193668: sh          $zero, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = 0;
    // 0x8019366C: lh          $v1, 0xB2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB2);
    // 0x80193670: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80193674: sh          $t4, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r12;
    // 0x80193678: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x8019367C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80193680: swc1        $f12, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f12.u32l;
    // 0x80193684: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80193688: sh          $v1, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r3;
    // 0x8019368C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80193690: swc1        $f10, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
    // 0x80193694: lwc1        $f2, -0x5200($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5200);
    // 0x80193698: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8019369C: swc1        $f16, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f16.u32l;
    // 0x801936A0: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
    // 0x801936A4: swc1        $f2, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f2.u32l;
    // 0x801936A8: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
L_801936AC:
    // 0x801936AC: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x801936B0: sh          $zero, 0x2($a2)
    MEM_H(0X2, ctx->r6) = 0;
    // 0x801936B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801936B8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x801936BC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_801936C0:
    // 0x801936C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801936C4: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x801936C8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x801936CC: bne         $at, $zero, L_801936C0
    if (ctx->r1 != 0) {
        // 0x801936D0: sh          $zero, 0x0($v0)
        MEM_H(0X0, ctx->r2) = 0;
            goto L_801936C0;
    }
    // 0x801936D0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x801936D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801936D8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_801936DC:
    // 0x801936DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801936E0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x801936E4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x801936E8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x801936EC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x801936F0: bne         $at, $zero, L_801936DC
    if (ctx->r1 != 0) {
        // 0x801936F4: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_801936DC;
    }
    // 0x801936F4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801936F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801936FC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80193700:
    // 0x80193700: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80193704: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80193708: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8019370C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80193710: bne         $v1, $a0, L_80193700
    if (ctx->r3 != ctx->r4) {
        // 0x80193714: swc1        $f0, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
            goto L_80193700;
    }
    // 0x80193714: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80193718: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8019371C: sltiu       $at, $a3, 0x11
    ctx->r1 = ctx->r7 < 0X11 ? 1 : 0;
    // 0x80193720: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    // 0x80193724: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80193728: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
    // 0x8019372C: swc1        $f0, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f0.u32l;
    // 0x80193730: swc1        $f0, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f0.u32l;
    // 0x80193734: bne         $at, $zero, L_801936AC
    if (ctx->r1 != 0) {
        // 0x80193738: sh          $zero, -0x4($a2)
        MEM_H(-0X4, ctx->r6) = 0;
            goto L_801936AC;
    }
    // 0x80193738: sh          $zero, -0x4($a2)
    MEM_H(-0X4, ctx->r6) = 0;
    // 0x8019373C: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80193740: swc1        $f12, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f12.u32l;
    // 0x80193744: addiu       $v0, $v0, -0x4810
    ctx->r2 = ADD32(ctx->r2, -0X4810);
    // 0x80193748: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8019374C:
    // 0x8019374C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80193750: sltiu       $at, $a3, 0x21
    ctx->r1 = ctx->r7 < 0X21 ? 1 : 0;
    // 0x80193754: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80193758: bne         $at, $zero, L_8019374C
    if (ctx->r1 != 0) {
        // 0x8019375C: sh          $zero, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = 0;
            goto L_8019374C;
    }
    // 0x8019375C: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
    // 0x80193760: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80193764: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80193768: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8019376C: addiu       $v1, $v1, -0x5648
    ctx->r3 = ADD32(ctx->r3, -0X5648);
    // 0x80193770: addiu       $a1, $a1, -0x57C8
    ctx->r5 = ADD32(ctx->r5, -0X57C8);
    // 0x80193774: lh          $v0, -0x57DE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X57DE);
L_80193778:
    // 0x80193778: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x8019377C: lh          $t9, 0x1A($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X1A);
    // 0x80193780: lh          $t2, 0x32($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X32);
    // 0x80193784: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80193788: lh          $t3, 0x4A($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X4A);
    // 0x8019378C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80193790: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // 0x80193794: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80193798: bne         $a1, $v1, L_80193778
    if (ctx->r5 != ctx->r3) {
        // 0x8019379C: addu        $v0, $v0, $t3
        ctx->r2 = ADD32(ctx->r2, ctx->r11);
            goto L_80193778;
    }
    // 0x8019379C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x801937A0: lh          $t4, 0x92($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X92);
    // 0x801937A4: addiu       $v1, $v0, 0x64
    ctx->r3 = ADD32(ctx->r2, 0X64);
    // 0x801937A8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801937AC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801937B0: sh          $v1, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r3;
    // 0x801937B4: sh          $v1, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r3;
    // 0x801937B8: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x801937BC: lw          $a0, -0x532C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X532C);
    // 0x801937C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801937C4: jal         0x8009AA20
    // 0x801937C8: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x801937C8: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    after_0:
    // 0x801937CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801937D0: ori         $a1, $zero, 0x8018
    ctx->r5 = 0 | 0X8018;
    // 0x801937D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801937D8: jal         0x8001D444
    // 0x801937DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_1;
    // 0x801937DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
    // 0x801937E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801937E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801937E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801937EC: jr          $ra
    // 0x801937F0: nop

    return;
    // 0x801937F0: nop

;}
RECOMP_FUNC void Corneria_CoGaruda1_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BAAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018BAB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018BAB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018BAB8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8018BABC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8018BAC0: lw          $t7, -0x4438($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4438);
    // 0x8018BAC4: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8018BAC8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018BACC: addiu       $a3, $a3, -0x54F8
    ctx->r7 = ADD32(ctx->r7, -0X54F8);
    // 0x8018BAD0: addiu       $a1, $a1, -0x65B8
    ctx->r5 = ADD32(ctx->r5, -0X65B8);
    // 0x8018BAD4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018BAD8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018BADC: addiu       $a2, $t6, 0x18C
    ctx->r6 = ADD32(ctx->r14, 0X18C);
    // 0x8018BAE0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018BAE4: jal         0x8009A72C
    // 0x8018BAE8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_0;
    // 0x8018BAE8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8018BAEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018BAF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018BAF4: jr          $ra
    // 0x8018BAF8: nop

    return;
    // 0x8018BAF8: nop

;}
RECOMP_FUNC void Corneria_CoGranga_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A434: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018A438: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018A43C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018A440: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8018A444: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8018A448: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018A44C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8018A450: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8018A454: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8018A458: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8018A45C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A460: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8018A464: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x8018A468: lh          $t8, 0x88($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X88);
    // 0x8018A46C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8018A470: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8018A474: bne         $t8, $at, L_8018A480
    if (ctx->r24 != ctx->r1) {
        // 0x8018A478: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8018A480;
    }
    // 0x8018A478: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018A47C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8018A480:
    // 0x8018A480: lw          $t9, -0x7C28($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C28);
    // 0x8018A484: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018A488: addiu       $t0, $zero, 0x3E9
    ctx->r8 = ADD32(0, 0X3E9);
    // 0x8018A48C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018A490: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8018A494: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8018A498: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8018A49C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8018A4A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8018A4A4: jal         0x800BA1D0
    // 0x8018A4A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    RCP_SetupDL_29(rdram, ctx);
        goto after_0;
    // 0x8018A4A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8018A4AC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8018A4B0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018A4B4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8018A4B8: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x8018A4BC: beq         $at, $zero, L_8018A6C8
    if (ctx->r1 == 0) {
        // 0x8018A4C0: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8018A6C8;
    }
    // 0x8018A4C0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018A4C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A4C8: addu        $at, $at, $t2
    gpr jr_addend_8018A4D0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8018A4CC: lw          $t2, -0x5004($at)
    ctx->r10 = ADD32(ctx->r1, -0X5004);
    // 0x8018A4D0: jr          $t2
    // 0x8018A4D4: nop

    switch (jr_addend_8018A4D0 >> 2) {
        case 0: goto L_8018A654; break;
        case 1: goto L_8018A684; break;
        case 2: goto L_8018A61C; break;
        case 3: goto L_8018A54C; break;
        case 4: goto L_8018A518; break;
        case 5: goto L_8018A4D8; break;
        case 6: goto L_8018A5E8; break;
        case 7: goto L_8018A5B4; break;
        case 8: goto L_8018A580; break;
        case 9: goto L_8018A6C8; break;
        case 10: goto L_8018A6C8; break;
        case 11: goto L_8018A6C8; break;
        case 12: goto L_8018A6C8; break;
        case 13: goto L_8018A6C8; break;
        case 14: goto L_8018A6C8; break;
        case 15: goto L_8018A6B4; break;
        default: switch_error(__func__, 0x8018A4D0, 0x8019AFFC);
    }
    // 0x8018A4D4: nop

L_8018A4D8:
    // 0x8018A4D8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A4DC: lwc1        $f6, 0xDC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A4E0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A4E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A4E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018A4EC: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8018A4F0: lwc1        $f16, 0xDC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A4F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018A4F8: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018A4FC: lwc1        $f6, -0x4FC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4FC4);
    // 0x8018A500: lwc1        $f4, 0x10C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10C);
    // 0x8018A504: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A508: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018A50C: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018A510: b           L_8018A6C8
    // 0x8018A514: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
        goto L_8018A6C8;
    // 0x8018A514: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
L_8018A518:
    // 0x8018A518: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A51C: lwc1        $f4, 0xDC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A520: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A524: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018A528: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018A52C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8018A530: lwc1        $f8, 0xDC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A534: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018A538: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018A53C: lwc1        $f4, 0xDC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A540: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018A544: b           L_8018A6C8
    // 0x8018A548: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_8018A6C8;
    // 0x8018A548: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8018A54C:
    // 0x8018A54C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A550: lwc1        $f8, 0xDC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A554: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A558: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018A55C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018A560: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x8018A564: lwc1        $f4, 0xDC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A568: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018A56C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8018A570: lwc1        $f8, 0xDC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8018A574: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018A578: b           L_8018A6C8
    // 0x8018A57C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_8018A6C8;
    // 0x8018A57C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_8018A580:
    // 0x8018A580: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A584: lwc1        $f4, 0xD8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A588: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A58C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018A590: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8018A594: lwc1        $f8, 0xD8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A598: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018A59C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018A5A0: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A5A4: lwc1        $f4, 0x10C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10C);
    // 0x8018A5A8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018A5AC: b           L_8018A6C8
    // 0x8018A5B0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
        goto L_8018A6C8;
    // 0x8018A5B0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_8018A5B4:
    // 0x8018A5B4: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A5B8: lwc1        $f8, 0xD8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A5BC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A5C0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018A5C4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018A5C8: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x8018A5CC: lwc1        $f4, 0xD8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A5D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018A5D4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8018A5D8: lwc1        $f8, 0xD8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A5DC: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018A5E0: b           L_8018A6C8
    // 0x8018A5E4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_8018A6C8;
    // 0x8018A5E4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_8018A5E8:
    // 0x8018A5E8: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A5EC: lwc1        $f4, 0xD8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A5F0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A5F4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018A5F8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018A5FC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8018A600: lwc1        $f8, 0xD8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A604: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018A608: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018A60C: lwc1        $f4, 0xD8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A610: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018A614: b           L_8018A6C8
    // 0x8018A618: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_8018A6C8;
    // 0x8018A618: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8018A61C:
    // 0x8018A61C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A620: lwc1        $f8, 0xE0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE0);
    // 0x8018A624: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A628: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A62C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018A630: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018A634: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x8018A638: lwc1        $f4, 0xE0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE0);
    // 0x8018A63C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018A640: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8018A644: lwc1        $f8, -0x48EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X48EC);
    // 0x8018A648: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018A64C: b           L_8018A6C8
    // 0x8018A650: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_8018A6C8;
    // 0x8018A650: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_8018A654:
    // 0x8018A654: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A658: lwc1        $f4, -0x48EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X48EC);
    // 0x8018A65C: lwc1        $f18, 0xE8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x8018A660: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A664: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A668: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018A66C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018A670: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8018A674: lwc1        $f18, 0xE8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x8018A678: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018A67C: b           L_8018A6C8
    // 0x8018A680: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
        goto L_8018A6C8;
    // 0x8018A680: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_8018A684:
    // 0x8018A684: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A688: lwc1        $f6, -0x48EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X48EC);
    // 0x8018A68C: lwc1        $f10, 0xE4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8018A690: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A694: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018A698: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018A69C: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8018A6A0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8018A6A4: lwc1        $f10, 0xE4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8018A6A8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018A6AC: b           L_8018A6C8
    // 0x8018A6B0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
        goto L_8018A6C8;
    // 0x8018A6B0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_8018A6B4:
    // 0x8018A6B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A6B8: lwc1        $f8, -0x48E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X48E8);
    // 0x8018A6BC: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018A6C0: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8018A6C4: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_8018A6C8:
    // 0x8018A6C8: lh          $t3, 0x88($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X88);
    // 0x8018A6CC: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8018A6D0: bne         $t4, $zero, L_8018A6E8
    if (ctx->r12 != 0) {
        // 0x8018A6D4: nop
    
            goto L_8018A6E8;
    }
    // 0x8018A6D4: nop

    // 0x8018A6D8: lh          $t5, 0x5C($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X5C);
    // 0x8018A6DC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8018A6E0: beql        $t6, $zero, L_8018A71C
    if (ctx->r14 == 0) {
        // 0x8018A6E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018A71C;
    }
    goto skip_0;
    // 0x8018A6E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8018A6E8:
    // 0x8018A6E8: jal         0x800BA140
    // 0x8018A6EC: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_1;
    // 0x8018A6EC: nop

    after_1:
    // 0x8018A6F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018A6F4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018A6F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018A6FC: lui         $t9, 0x4040
    ctx->r25 = S32(0X4040 << 16);
    // 0x8018A700: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018A704: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018A708: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8018A70C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8018A710: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018A714: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018A718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018A71C:
    // 0x8018A71C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018A720: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018A724: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8018A728: jr          $ra
    // 0x8018A72C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018A72C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Corneria_CoGaruda1_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018AED0: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8018AED4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018AED8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018AEDC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018AEE0: jal         0x8018ACE0
    // 0x8018AEE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Corneria_Garuda_HandleDamage(rdram, ctx);
        goto after_0;
    // 0x8018AEE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018AEE8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018AEEC: addiu       $a0, $a0, -0x66E4
    ctx->r4 = ADD32(ctx->r4, -0X66E4);
    // 0x8018AEF0: lh          $a1, 0xB6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XB6);
    // 0x8018AEF4: jal         0x8009AA20
    // 0x8018AEF8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x8018AEF8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x8018AEFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018AF00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AF04: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8018AF08: addiu       $a1, $s0, 0x18C
    ctx->r5 = ADD32(ctx->r16, 0X18C);
    // 0x8018AF0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018AF10: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8018AF14: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8018AF18: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8018AF1C: jal         0x8009BEEC
    // 0x8018AF20: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_2;
    // 0x8018AF20: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8018AF24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AF28: lwc1        $f6, -0x4F74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F74);
    // 0x8018AF2C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018AF30: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018AF34: jal         0x80023090
    // 0x8018AF38: nop

    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8018AF38: nop

    after_3:
    // 0x8018AF3C: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018AF40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AF44: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018AF48: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018AF4C: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    // 0x8018AF50: lwc1        $f18, -0x4F70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4F70);
    // 0x8018AF54: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018AF58: jal         0x80023250
    // 0x8018AF5C: nop

    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x8018AF5C: nop

    after_4:
    // 0x8018AF60: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018AF64: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8018AF68: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018AF6C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8018AF70: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018AF74: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018AF78: beq         $v0, $zero, L_8018AF9C
    if (ctx->r2 == 0) {
        // 0x8018AF7C: swc1        $f6, 0xF0($s0)
        MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
            goto L_8018AF9C;
    }
    // 0x8018AF7C: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x8018AF80: beq         $v0, $v1, L_8018B018
    if (ctx->r2 == ctx->r3) {
        // 0x8018AF84: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8018B018;
    }
    // 0x8018AF84: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018AF88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018AF8C: beql        $v0, $at, L_8018B08C
    if (ctx->r2 == ctx->r1) {
        // 0x8018AF90: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8018B08C;
    }
    goto skip_0;
    // 0x8018AF90: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_0:
    // 0x8018AF94: b           L_8018B0A4
    // 0x8018AF98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8018B0A4;
    // 0x8018AF98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018AF9C:
    // 0x8018AF9C: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018AFA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018AFA4: addiu       $a0, $a0, 0x29C0
    ctx->r4 = ADD32(ctx->r4, 0X29C0);
    // 0x8018AFA8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8018AFAC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018AFB0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018AFB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018AFB8: jal         0x80099A2C
    // 0x8018AFBC: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_5;
    // 0x8018AFBC: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x8018AFC0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018AFC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AFC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018AFCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AFD0: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018AFD4: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
    // 0x8018AFD8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018AFDC: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x8018AFE0: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018AFE4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8018AFE8: nop

    // 0x8018AFEC: bc1f        L_8018AFF8
    if (!c1cs) {
        // 0x8018AFF0: nop
    
            goto L_8018AFF8;
    }
    // 0x8018AFF0: nop

    // 0x8018AFF4: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
L_8018AFF8:
    // 0x8018AFF8: jal         0x8018AB64
    // 0x8018AFFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Corneria_CoGaruda1_CheckCollision(rdram, ctx);
        goto after_6;
    // 0x8018AFFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8018B000: beq         $v0, $zero, L_8018B0A0
    if (ctx->r2 == 0) {
        // 0x8018B004: sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
            goto L_8018B0A0;
    }
    // 0x8018B004: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8018B008: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x8018B00C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018B010: b           L_8018B0A0
    // 0x8018B014: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
        goto L_8018B0A0;
    // 0x8018B014: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
L_8018B018:
    // 0x8018B018: lh          $t8, 0xB6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B01C: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018B020: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B024: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018B028: sh          $t9, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r25;
    // 0x8018B02C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018B030: lh          $t0, 0xB6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B034: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018B038: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8018B03C: swc1        $f18, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f18.u32l;
    // 0x8018B040: bne         $t0, $at, L_8018B05C
    if (ctx->r8 != ctx->r1) {
        // 0x8018B044: swc1        $f4, 0x114($s0)
        MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
            goto L_8018B05C;
    }
    // 0x8018B044: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x8018B048: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x8018B04C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018B050: sll         $t2, $t1, 7
    ctx->r10 = S32(ctx->r9 << 7);
    // 0x8018B054: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8018B058: sw          $v1, 0x1AC8($at)
    MEM_W(0X1AC8, ctx->r1) = ctx->r3;
L_8018B05C:
    // 0x8018B05C: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018B060: jal         0x8009ACDC
    // 0x8018B064: addiu       $a0, $a0, -0x66E4
    ctx->r4 = ADD32(ctx->r4, -0X66E4);
    Animation_GetFrameCount(rdram, ctx);
        goto after_7;
    // 0x8018B064: addiu       $a0, $a0, -0x66E4
    ctx->r4 = ADD32(ctx->r4, -0X66E4);
    after_7:
    // 0x8018B068: lh          $t3, 0xB6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B06C: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8018B070: bnel        $at, $zero, L_8018B0A4
    if (ctx->r1 != 0) {
        // 0x8018B074: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8018B0A4;
    }
    goto skip_1;
    // 0x8018B074: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8018B078: lh          $t4, 0xB8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB8);
    // 0x8018B07C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018B080: b           L_8018B0A0
    // 0x8018B084: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
        goto L_8018B0A0;
    // 0x8018B084: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
    // 0x8018B088: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8018B08C:
    // 0x8018B08C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B090: lwc1        $f6, 0x118($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018B094: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
    // 0x8018B098: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018B09C: swc1        $f10, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f10.u32l;
L_8018B0A0:
    // 0x8018B0A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018B0A4:
    // 0x8018B0A4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018B0A8: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    // 0x8018B0AC: jr          $ra
    // 0x8018B0B0: nop

    return;
    // 0x8018B0B0: nop

;}
RECOMP_FUNC void Training_ItemRing_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198968: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019896C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80198970: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80198974: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80198978: lbu         $v0, 0x46($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X46);
    // 0x8019897C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80198980: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x80198984: beql        $v0, $zero, L_801989A4
    if (ctx->r2 == 0) {
        // 0x80198988: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_801989A4;
    }
    goto skip_0;
    // 0x80198988: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8019898C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80198990: beq         $v0, $at, L_80198B18
    if (ctx->r2 == ctx->r1) {
        // 0x80198994: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80198B18;
    }
    // 0x80198994: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80198998: b           L_80198C3C
    // 0x8019899C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80198C3C;
    // 0x8019899C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801989A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_801989A4:
    // 0x801989A4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801989A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801989AC: lwc1        $f12, -0x4998($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4998);
    // 0x801989B0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801989B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801989B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801989BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801989C0: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x801989C4: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801989C8: jal         0x8009BC2C
    // 0x801989CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801989CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801989D0: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x801989D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801989D8: addiu       $a0, $a0, -0x7D80
    ctx->r4 = ADD32(ctx->r4, -0X7D80);
    // 0x801989DC: bnel        $t6, $zero, L_80198A7C
    if (ctx->r14 != 0) {
        // 0x801989E0: lb          $t0, 0x4C($s0)
        ctx->r8 = MEM_B(ctx->r16, 0X4C);
            goto L_80198A7C;
    }
    goto skip_1;
    // 0x801989E0: lb          $t0, 0x4C($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X4C);
    skip_1:
    // 0x801989E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801989E8: lw          $t7, 0x4DC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4DC);
    // 0x801989EC: bnel        $t7, $zero, L_80198A7C
    if (ctx->r15 != 0) {
        // 0x801989F0: lb          $t0, 0x4C($s0)
        ctx->r8 = MEM_B(ctx->r16, 0X4C);
            goto L_80198A7C;
    }
    goto skip_2;
    // 0x801989F0: lb          $t0, 0x4C($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X4C);
    skip_2:
    // 0x801989F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801989F8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801989FC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80198A00: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80198A04: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80198A08: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80198A0C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80198A10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80198A14: bc1f        L_80198A28
    if (!c1cs) {
        // 0x80198A18: ori         $a0, $a0, 0x402F
        ctx->r4 = ctx->r4 | 0X402F;
            goto L_80198A28;
    }
    // 0x80198A18: ori         $a0, $a0, 0x402F
    ctx->r4 = ctx->r4 | 0X402F;
    // 0x80198A1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198A20: b           L_80198A30
    // 0x80198A24: lwc1        $f0, -0x4994($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4994);
        goto L_80198A30;
    // 0x80198A24: lwc1        $f0, -0x4994($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4994);
L_80198A28:
    // 0x80198A28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80198A2C: nop

L_80198A30:
    // 0x80198A30: lwc1        $f18, 0x138($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X138);
    // 0x80198A34: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80198A38: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80198A3C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80198A40: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80198A44: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80198A48: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80198A4C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80198A50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80198A54: bc1fl       L_80198A7C
    if (!c1cs) {
        // 0x80198A58: lb          $t0, 0x4C($s0)
        ctx->r8 = MEM_B(ctx->r16, 0X4C);
            goto L_80198A7C;
    }
    goto skip_3;
    // 0x80198A58: lb          $t0, 0x4C($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X4C);
    skip_3:
    // 0x80198A5C: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x80198A60: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80198A64: jal         0x80019218
    // 0x80198A68: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80198A68: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x80198A6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80198A70: addiu       $v0, $v0, 0x7E80
    ctx->r2 = ADD32(ctx->r2, 0X7E80);
    // 0x80198A74: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80198A78: lb          $t0, 0x4C($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X4C);
L_80198A7C:
    // 0x80198A7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80198A80: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80198A84: beq         $t0, $zero, L_80198C38
    if (ctx->r8 == 0) {
        // 0x80198A88: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_80198C38;
    }
    // 0x80198A88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198A8C: sb          $t1, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r9;
    // 0x80198A90: sh          $t2, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r10;
    // 0x80198A94: lwc1        $f8, -0x4990($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4990);
    // 0x80198A98: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80198A9C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80198AA0: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80198AA4: addiu       $a3, $t3, 0x5D34
    ctx->r7 = ADD32(ctx->r11, 0X5D34);
    // 0x80198AA8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80198AAC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80198AB0: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80198AB4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80198AB8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80198ABC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80198AC0: ori         $a0, $a0, 0x8025
    ctx->r4 = ctx->r4 | 0X8025;
    // 0x80198AC4: jal         0x80019218
    // 0x80198AC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80198AC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80198ACC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80198AD0: addiu       $v0, $v0, 0x7E80
    ctx->r2 = ADD32(ctx->r2, 0X7E80);
    // 0x80198AD4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80198AD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80198ADC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80198AE0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80198AE4: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80198AE8: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x80198AEC: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80198AF0: nop

    // 0x80198AF4: bc1tl       L_80198C3C
    if (c1cs) {
        // 0x80198AF8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80198C3C;
    }
    goto skip_4;
    // 0x80198AF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80198AFC: bne         $at, $zero, L_80198C38
    if (ctx->r1 != 0) {
        // 0x80198B00: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80198C38;
    }
    // 0x80198B00: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80198B04: addiu       $a0, $a0, 0x4960
    ctx->r4 = ADD32(ctx->r4, 0X4960);
    // 0x80198B08: jal         0x800BA808
    // 0x80198B0C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x80198B0C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_3:
    // 0x80198B10: b           L_80198C3C
    // 0x80198B14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80198C3C;
    // 0x80198B14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80198B18:
    // 0x80198B18: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x80198B1C: addiu       $a0, $a0, -0x7D80
    ctx->r4 = ADD32(ctx->r4, -0X7D80);
    // 0x80198B20: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80198B24: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80198B28: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80198B2C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80198B30: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80198B34: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80198B38: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80198B3C: lwc1        $f18, 0x74($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X74);
    // 0x80198B40: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80198B44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198B48: lwc1        $f12, -0x498C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X498C);
    // 0x80198B4C: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80198B50: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80198B54: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80198B58: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80198B5C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80198B60: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80198B64: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80198B68: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80198B6C: addu        $t2, $t1, $t8
    ctx->r10 = ADD32(ctx->r9, ctx->r24);
    // 0x80198B70: lwc1        $f10, 0x78($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X78);
    // 0x80198B74: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80198B78: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80198B7C: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80198B80: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80198B84: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80198B88: lw          $t3, 0x238($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X238);
    // 0x80198B8C: addu        $t4, $v1, $t8
    ctx->r12 = ADD32(ctx->r3, ctx->r24);
    // 0x80198B90: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x80198B94: beql        $t3, $zero, L_80198BC4
    if (ctx->r11 == 0) {
        // 0x80198B98: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80198BC4;
    }
    goto skip_5;
    // 0x80198B98: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x80198B9C: lwc1        $f6, 0x138($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X138);
    // 0x80198BA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80198BA4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80198BA8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80198BAC: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80198BB0: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80198BB4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80198BB8: b           L_80198BD8
    // 0x80198BBC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_80198BD8;
    // 0x80198BBC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80198BC0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
L_80198BC4:
    // 0x80198BC4: lwc1        $f6, 0x138($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X138);
    // 0x80198BC8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80198BCC: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80198BD0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80198BD4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
L_80198BD8:
    // 0x80198BD8: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80198BDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198BE0: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80198BE4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80198BE8: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80198BEC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80198BF0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80198BF4: lwc1        $f12, 0x58($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80198BF8: jal         0x8009F768
    // 0x80198BFC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_4;
    // 0x80198BFC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_4:
    // 0x80198C00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80198C04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198C08: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80198C0C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80198C10: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80198C14: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80198C18: jal         0x8009BD38
    // 0x80198C1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x80198C1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80198C20: lhu         $t8, 0x48($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X48);
    // 0x80198C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198C28: bnel        $t8, $zero, L_80198C3C
    if (ctx->r24 != 0) {
        // 0x80198C2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80198C3C;
    }
    goto skip_6;
    // 0x80198C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80198C30: jal         0x80060FBC
    // 0x80198C34: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x80198C34: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_6:
L_80198C38:
    // 0x80198C38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80198C3C:
    // 0x80198C3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80198C40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80198C44: jr          $ra
    // 0x80198C48: nop

    return;
    // 0x80198C48: nop

;}
RECOMP_FUNC void Venom1_BossTrigger3_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801923C0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801923C4: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x801923C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801923CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801923D0: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
L_801923D4:
    // 0x801923D4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801923D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801923DC: beq         $t6, $zero, L_8019242C
    if (ctx->r14 == 0) {
        // 0x801923E0: nop
    
            goto L_8019242C;
    }
    // 0x801923E0: nop

    // 0x801923E4: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x801923E8: bne         $a1, $t7, L_8019242C
    if (ctx->r5 != ctx->r15) {
        // 0x801923EC: nop
    
            goto L_8019242C;
    }
    // 0x801923EC: nop

    // 0x801923F0: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801923F4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801923F8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801923FC: nop

    // 0x80192400: bc1f        L_80192434
    if (!c1cs) {
        // 0x80192404: nop
    
            goto L_80192434;
    }
    // 0x80192404: nop

    // 0x80192408: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8019240C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192410: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80192414: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80192418: nop

    // 0x8019241C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80192420: sw          $t0, -0x3F44($at)
    MEM_W(-0X3F44, ctx->r1) = ctx->r8;
    // 0x80192424: jr          $ra
    // 0x80192428: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x80192428: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8019242C:
    // 0x8019242C: bne         $v1, $a2, L_801923D4
    if (ctx->r3 != ctx->r6) {
        // 0x80192430: addiu       $v0, $v0, 0x408
        ctx->r2 = ADD32(ctx->r2, 0X408);
            goto L_801923D4;
    }
    // 0x80192430: addiu       $v0, $v0, 0x408
    ctx->r2 = ADD32(ctx->r2, 0X408);
L_80192434:
    // 0x80192434: jr          $ra
    // 0x80192438: nop

    return;
    // 0x80192438: nop

;}
RECOMP_FUNC void Corneria_CoGarudaDestroy_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B58C: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8018B590: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x8018B594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B598: lwc1        $f20, -0x4F58($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4F58);
    // 0x8018B59C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B5A0: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8018B5A4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018B5A8: sdc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X60, ctx->r29);
    // 0x8018B5AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B5B0: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x8018B5B4: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x8018B5B8: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x8018B5BC: lwc1        $f24, -0x4F54($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X4F54);
    // 0x8018B5C0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8018B5C4: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8018B5C8: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x8018B5CC: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x8018B5D0: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x8018B5D4: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x8018B5D8: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x8018B5DC: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x8018B5E0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8018B5E4: addiu       $t7, $t7, -0x676C
    ctx->r15 = ADD32(ctx->r15, -0X676C);
    // 0x8018B5E8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018B5EC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8018B5F0: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8018B5F4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8018B5F8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8018B5FC: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8018B600: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018B604: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8018B608: addiu       $t2, $t2, -0x675C
    ctx->r10 = ADD32(ctx->r10, -0X675C);
    // 0x8018B60C: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8018B610: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8018B614: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8018B618: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018B61C: addiu       $t1, $sp, 0xA4
    ctx->r9 = ADD32(ctx->r29, 0XA4);
    // 0x8018B620: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8018B624: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8018B628: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8018B62C: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8018B630: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x8018B634: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018B638: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8018B63C: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8018B640: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x8018B644: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8018B648: jal         0x8009BC2C
    // 0x8018B64C: addiu       $a0, $s4, 0xE8
    ctx->r4 = ADD32(ctx->r20, 0XE8);
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8018B64C: addiu       $a0, $s4, 0xE8
    ctx->r4 = ADD32(ctx->r20, 0XE8);
    after_0:
    // 0x8018B650: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x8018B654: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018B658: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8018B65C: addiu       $a0, $s4, 0xEC
    ctx->r4 = ADD32(ctx->r20, 0XEC);
    // 0x8018B660: jal         0x8009BC2C
    // 0x8018B664: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8018B664: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_1:
    // 0x8018B668: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x8018B66C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018B670: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8018B674: addiu       $a0, $s4, 0xF0
    ctx->r4 = ADD32(ctx->r20, 0XF0);
    // 0x8018B678: jal         0x8009BC2C
    // 0x8018B67C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8018B67C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_2:
    // 0x8018B680: lh          $v0, 0xB8($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XB8);
    // 0x8018B684: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8018B688: beq         $v0, $at, L_8018B6A0
    if (ctx->r2 == ctx->r1) {
        // 0x8018B68C: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_8018B6A0;
    }
    // 0x8018B68C: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8018B690: beql        $v0, $at, L_8018BA1C
    if (ctx->r2 == ctx->r1) {
        // 0x8018B694: lhu         $t1, 0xBE($s4)
        ctx->r9 = MEM_HU(ctx->r20, 0XBE);
            goto L_8018BA1C;
    }
    goto skip_0;
    // 0x8018B694: lhu         $t1, 0xBE($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0XBE);
    skip_0:
    // 0x8018B698: b           L_8018BA78
    // 0x8018B69C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_8018BA78;
    // 0x8018B69C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8018B6A0:
    // 0x8018B6A0: lhu         $v0, 0xBC($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XBC);
    // 0x8018B6A4: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8018B6A8: bnel        $t9, $zero, L_8018B7A4
    if (ctx->r25 != 0) {
        // 0x8018B6AC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8018B7A4;
    }
    goto skip_1;
    // 0x8018B6AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_1:
    // 0x8018B6B0: jal         0x80004EB0
    // 0x8018B6B4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018B6B4: nop

    after_3:
    // 0x8018B6B8: jal         0x80004EB0
    // 0x8018B6BC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8018B6BC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_4:
    // 0x8018B6C0: jal         0x80004EB0
    // 0x8018B6C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8018B6C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x8018B6C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018B6CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018B6D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018B6D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B6D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018B6DC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018B6E0: lwc1        $f8, 0x4($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8018B6E4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018B6E8: sub.s       $f4, $f26, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f24.fl;
    // 0x8018B6EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B6F0: lwc1        $f10, 0x8($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8018B6F4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018B6F8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8018B6FC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018B700: lwc1        $f18, 0xC($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8018B704: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018B708: sub.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8018B70C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8018B710: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8018B714: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018B718: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8018B71C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018B720: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018B724: jal         0x8007D2C8
    // 0x8018B728: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_6;
    // 0x8018B728: nop

    after_6:
    // 0x8018B72C: lwc1        $f10, 0xEC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0XEC);
    // 0x8018B730: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018B734: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B738: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8018B73C: lwc1        $f12, 0x4($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8018B740: lw          $a2, 0xC($s4)
    ctx->r6 = MEM_W(ctx->r20, 0XC);
    // 0x8018B744: lw          $a3, 0xE8($s4)
    ctx->r7 = MEM_W(ctx->r20, 0XE8);
    // 0x8018B748: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B74C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018B750: lwc1        $f6, 0xF0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XF0);
    // 0x8018B754: lwc1        $f8, -0x4F50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4F50);
    // 0x8018B758: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8018B75C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8018B760: add.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018B764: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018B768: jal         0x8007C120
    // 0x8018B76C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_7;
    // 0x8018B76C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x8018B770: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B774: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018B778: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B77C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018B780: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018B784: ori         $a0, $a0, 0xA008
    ctx->r4 = ctx->r4 | 0XA008;
    // 0x8018B788: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018B78C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B790: addiu       $a1, $s4, 0x100
    ctx->r5 = ADD32(ctx->r20, 0X100);
    // 0x8018B794: jal         0x80019218
    // 0x8018B798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x8018B798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x8018B79C: lhu         $v0, 0xBC($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XBC);
    // 0x8018B7A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_8018B7A4:
    // 0x8018B7A4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018B7A8: bne         $v0, $zero, L_8018B98C
    if (ctx->r2 != 0) {
        // 0x8018B7AC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8018B98C;
    }
    // 0x8018B7AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018B7B0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8018B7B4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8018B7B8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8018B7BC: addiu       $s2, $sp, 0xB4
    ctx->r18 = ADD32(ctx->r29, 0XB4);
    // 0x8018B7C0: addiu       $s3, $sp, 0xA4
    ctx->r19 = ADD32(ctx->r29, 0XA4);
L_8018B7C4:
    // 0x8018B7C4: jal         0x80004EB0
    // 0x8018B7C8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8018B7C8: nop

    after_9:
    // 0x8018B7CC: jal         0x80004EB0
    // 0x8018B7D0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8018B7D0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_10:
    // 0x8018B7D4: jal         0x80004EB0
    // 0x8018B7D8: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x8018B7D8: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_11:
    // 0x8018B7DC: jal         0x80004EB0
    // 0x8018B7E0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x8018B7E0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_12:
    // 0x8018B7E4: mul.s       $f4, $f22, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x8018B7E8: lwc1        $f12, 0x11C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8018B7EC: lwc1        $f14, 0x12C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018B7F0: lw          $a2, 0x13C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X13C);
    // 0x8018B7F4: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x8018B7F8: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x8018B7FC: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8018B800: add.s       $f18, $f4, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8018B804: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018B808: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8018B80C: addiu       $t7, $s1, 0x18
    ctx->r15 = ADD32(ctx->r17, 0X18);
    // 0x8018B810: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8018B814: nop

    // 0x8018B818: mul.s       $f8, $f26, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x8018B81C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018B820: lwc1        $f18, 0x0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8018B824: sub.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8018B828: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8018B82C: add.s       $f4, $f8, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8018B830: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B834: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018B838: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8018B83C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B840: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018B844: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018B848: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8018B84C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8018B850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B854: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018B858: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8018B85C: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018B860: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B864: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018B868: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8018B86C: nop

    // 0x8018B870: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018B874: nop

    // 0x8018B878: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018B87C: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8018B880: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018B884: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8018B888: jal         0x800430DC
    // 0x8018B88C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    Boss_SpawnDebris(rdram, ctx);
        goto after_13;
    // 0x8018B88C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_13:
    // 0x8018B890: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018B894: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018B898: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018B89C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018B8A0: bne         $s1, $at, L_8018B7C4
    if (ctx->r17 != ctx->r1) {
        // 0x8018B8A4: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8018B7C4;
    }
    // 0x8018B8A4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8018B8A8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018B8AC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8018B8B0: lwc1        $f2, 0xC($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8018B8B4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018B8B8: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8018B8BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B8C0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018B8C4: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8018B8C8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018B8CC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8018B8D0: nop

    // 0x8018B8D4: bc1fl       L_8018B940
    if (!c1cs) {
        // 0x8018B8D8: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_8018B940;
    }
    goto skip_2;
    // 0x8018B8D8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    skip_2:
    // 0x8018B8DC: lwc1        $f10, 0x4($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8018B8E0: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8018B8E4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018B8E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B8EC: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8018B8F0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018B8F4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8018B8F8: nop

    // 0x8018B8FC: bc1fl       L_8018B940
    if (!c1cs) {
        // 0x8018B900: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_8018B940;
    }
    goto skip_3;
    // 0x8018B900: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    skip_3:
    // 0x8018B904: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8018B908: lwc1        $f18, 0x78($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8018B90C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018B910: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B914: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8018B918: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B91C: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    // 0x8018B920: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018B924: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8018B928: nop

    // 0x8018B92C: bc1fl       L_8018B940
    if (!c1cs) {
        // 0x8018B930: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_8018B940;
    }
    goto skip_4;
    // 0x8018B930: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    skip_4:
    // 0x8018B934: sh          $t2, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r10;
    // 0x8018B938: lwc1        $f2, 0xC($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8018B93C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
L_8018B940:
    // 0x8018B940: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B944: lwc1        $f6, 0x8($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8018B948: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8018B94C: lwc1        $f12, 0x4($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8018B950: jal         0x80077240
    // 0x8018B954: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    BonusText_Display(rdram, ctx);
        goto after_14;
    // 0x8018B954: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    after_14:
    // 0x8018B958: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8018B95C: addiu       $v1, $v1, 0x1A98
    ctx->r3 = ADD32(ctx->r3, 0X1A98);
    // 0x8018B960: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8018B964: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8018B968: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B96C: addiu       $t9, $t5, 0x6
    ctx->r25 = ADD32(ctx->r13, 0X6);
    // 0x8018B970: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018B974: sw          $t8, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r24;
    // 0x8018B978: addiu       $t6, $zero, 0x65
    ctx->r14 = ADD32(0, 0X65);
    // 0x8018B97C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8018B980: sh          $t6, 0xB8($s4)
    MEM_H(0XB8, ctx->r20) = ctx->r14;
    // 0x8018B984: sh          $t7, 0xBE($s4)
    MEM_H(0XBE, ctx->r20) = ctx->r15;
    // 0x8018B988: lhu         $v0, 0xBC($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XBC);
L_8018B98C:
    // 0x8018B98C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8018B990: bne         $v0, $at, L_8018BA74
    if (ctx->r2 != ctx->r1) {
        // 0x8018B994: addiu       $t0, $zero, 0x1E
        ctx->r8 = ADD32(0, 0X1E);
            goto L_8018BA74;
    }
    // 0x8018B994: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x8018B998: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018B99C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B9A0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018B9A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B9A8: lwc1        $f10, 0xC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8018B9AC: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8018B9B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018B9B4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018B9B8: lwc1        $f12, 0x4($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8018B9BC: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8018B9C0: add.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018B9C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B9C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018B9CC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8018B9D0: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x8018B9D4: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x8018B9D8: addiu       $s0, $s4, 0x100
    ctx->r16 = ADD32(ctx->r20, 0X100);
    // 0x8018B9DC: jal         0x8007BFFC
    // 0x8018B9E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_15;
    // 0x8018B9E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x8018B9E4: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8018B9E8: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8018B9EC: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8018B9F0: addiu       $a3, $t4, 0x5D34
    ctx->r7 = ADD32(ctx->r12, 0X5D34);
    // 0x8018B9F4: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018B9F8: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x8018B9FC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018BA00: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8018BA04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018BA08: jal         0x80019218
    // 0x8018BA0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_16;
    // 0x8018BA0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_16:
    // 0x8018BA10: b           L_8018BA78
    // 0x8018BA14: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_8018BA78;
    // 0x8018BA14: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8018BA18: lhu         $t1, 0xBE($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0XBE);
L_8018BA1C:
    // 0x8018BA1C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018BA20: beql        $t1, $zero, L_8018BA78
    if (ctx->r9 == 0) {
        // 0x8018BA24: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8018BA78;
    }
    goto skip_5;
    // 0x8018BA24: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_5:
    // 0x8018BA28: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8018BA2C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018BA30: andi        $t5, $t2, 0x1
    ctx->r13 = ctx->r10 & 0X1;
    // 0x8018BA34: bnel        $t5, $zero, L_8018BA78
    if (ctx->r13 != 0) {
        // 0x8018BA38: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8018BA78;
    }
    goto skip_6;
    // 0x8018BA38: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_6:
    // 0x8018BA3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018BA40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018BA44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018BA48: lwc1        $f18, 0x8($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8018BA4C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018BA50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018BA54: lwc1        $f12, 0x4($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8018BA58: lw          $a2, 0xC($s4)
    ctx->r6 = MEM_W(ctx->r20, 0XC);
    // 0x8018BA5C: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8018BA60: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x8018BA64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018BA68: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8018BA6C: jal         0x8007797C
    // 0x8018BA70: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_FireSmoke1_SpawnMoving(rdram, ctx);
        goto after_17;
    // 0x8018BA70: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_17:
L_8018BA74:
    // 0x8018BA74: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8018BA78:
    // 0x8018BA78: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x8018BA7C: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x8018BA80: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x8018BA84: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x8018BA88: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x8018BA8C: ldc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X60);
    // 0x8018BA90: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x8018BA94: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x8018BA98: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x8018BA9C: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x8018BAA0: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x8018BAA4: jr          $ra
    // 0x8018BAA8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8018BAA8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Venom1_BossTrigger1_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801922DC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801922E0: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x801922E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801922E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801922EC: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
L_801922F0:
    // 0x801922F0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801922F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801922F8: beq         $t6, $zero, L_80192348
    if (ctx->r14 == 0) {
        // 0x801922FC: nop
    
            goto L_80192348;
    }
    // 0x801922FC: nop

    // 0x80192300: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x80192304: bne         $a1, $t7, L_80192348
    if (ctx->r5 != ctx->r15) {
        // 0x80192308: nop
    
            goto L_80192348;
    }
    // 0x80192308: nop

    // 0x8019230C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80192310: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80192314: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80192318: nop

    // 0x8019231C: bc1f        L_80192350
    if (!c1cs) {
        // 0x80192320: nop
    
            goto L_80192350;
    }
    // 0x80192320: nop

    // 0x80192324: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80192328: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019232C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80192330: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80192334: nop

    // 0x80192338: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8019233C: sw          $t0, -0x3F48($at)
    MEM_W(-0X3F48, ctx->r1) = ctx->r8;
    // 0x80192340: jr          $ra
    // 0x80192344: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x80192344: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_80192348:
    // 0x80192348: bne         $v1, $a2, L_801922F0
    if (ctx->r3 != ctx->r6) {
        // 0x8019234C: addiu       $v0, $v0, 0x408
        ctx->r2 = ADD32(ctx->r2, 0X408);
            goto L_801922F0;
    }
    // 0x8019234C: addiu       $v0, $v0, 0x408
    ctx->r2 = ADD32(ctx->r2, 0X408);
L_80192350:
    // 0x80192350: jr          $ra
    // 0x80192354: nop

    return;
    // 0x80192354: nop

;}
RECOMP_FUNC void Corneria_CoCarrier_ChooseMissileTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BDD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018BDD8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8018BDDC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8018BDE0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018BDE4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8018BDE8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8018BDEC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8018BDF0: addiu       $v1, $zero, 0xBF
    ctx->r3 = ADD32(0, 0XBF);
    // 0x8018BDF4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8018BDF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018BDFC: jal         0x8008AC54
    // 0x8018BE00: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    ActorMissileSeek_ModeCheck(rdram, ctx);
        goto after_0;
    // 0x8018BE00: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_0:
    // 0x8018BE04: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8018BE08: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8018BE0C: beq         $at, $zero, L_8018BE18
    if (ctx->r1 == 0) {
        // 0x8018BE10: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_8018BE18;
    }
    // 0x8018BE10: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8018BE14: addiu       $v1, $zero, 0xBE
    ctx->r3 = ADD32(0, 0XBE);
L_8018BE18:
    // 0x8018BE18: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8018BE1C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018BE20: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8018BE24: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018BE28: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018BE2C: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8018BE30: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8018BE34: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018BE38: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018BE3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018BE40: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8018BE44: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018BE48: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8018BE4C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8018BE50: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018BE54: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8018BE58: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8018BE5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8018BE60: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018BE64: jal         0x80187710
    // 0x8018BE68: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    Corneria_BossMissile_Spawn(rdram, ctx);
        goto after_1;
    // 0x8018BE68: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_1:
    // 0x8018BE6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018BE70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018BE74: jr          $ra
    // 0x8018BE78: nop

    return;
    // 0x8018BE78: nop

;}
RECOMP_FUNC void Corneria_CoCarrierUpper_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EE2C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8018EE30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018EE34: bne         $a0, $v0, L_8018EE64
    if (ctx->r4 != ctx->r2) {
        // 0x8018EE38: lw          $t6, 0x10($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X10);
            goto L_8018EE64;
    }
    // 0x8018EE38: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8018EE3C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018EE40: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EE44: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8018EE48: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x8018EE4C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018EE50: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018EE54: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018EE58: lwc1        $f6, -0xE18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XE18);
    // 0x8018EE5C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018EE60: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
L_8018EE64:
    // 0x8018EE64: beq         $a0, $v0, L_8018EE78
    if (ctx->r4 == ctx->r2) {
        // 0x8018EE68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018EE78;
    }
    // 0x8018EE68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018EE6C: beql        $a0, $at, L_8018EE7C
    if (ctx->r4 == ctx->r1) {
        // 0x8018EE70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018EE7C;
    }
    goto skip_0;
    // 0x8018EE70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8018EE74: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8018EE78:
    // 0x8018EE78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018EE7C:
    // 0x8018EE7C: jr          $ra
    // 0x8018EE80: nop

    return;
    // 0x8018EE80: nop

;}
RECOMP_FUNC void Venom1_Ve1Pillar4_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192EA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80192EA8: jr          $ra
    // 0x80192EAC: nop

    return;
    // 0x80192EAC: nop

;}
RECOMP_FUNC void Corneria_SpawnTerrainBumps(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F4A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F4AC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018F4B0: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8018F4B4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8018F4B8: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8018F4BC: bnel        $t7, $zero, L_8018F550
    if (ctx->r15 != 0) {
        // 0x8018F4C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018F550;
    }
    goto skip_0;
    // 0x8018F4C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018F4C4: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8018F4C8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018F4CC: addiu       $a0, $a0, 0x1B00
    ctx->r4 = ADD32(ctx->r4, 0X1B00);
    // 0x8018F4D0: lw          $t9, 0x1D0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1D0);
    // 0x8018F4D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018F4D8: lui         $a1, 0x457A
    ctx->r5 = S32(0X457A << 16);
    // 0x8018F4DC: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8018F4E0: bnel        $at, $zero, L_8018F550
    if (ctx->r1 != 0) {
        // 0x8018F4E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018F550;
    }
    goto skip_1;
    // 0x8018F4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8018F4E8:
    // 0x8018F4E8: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8018F4EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018F4F0: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8018F4F4: bne         $t0, $zero, L_8018F50C
    if (ctx->r8 != 0) {
        // 0x8018F4F8: nop
    
            goto L_8018F50C;
    }
    // 0x8018F4F8: nop

    // 0x8018F4FC: jal         0x8018F3BC
    // 0x8018F500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    Corneria_SetupTerrainBumps(rdram, ctx);
        goto after_0;
    // 0x8018F500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_0:
    // 0x8018F504: b           L_8018F514
    // 0x8018F508: nop

        goto L_8018F514;
    // 0x8018F508: nop

L_8018F50C:
    // 0x8018F50C: bne         $at, $zero, L_8018F4E8
    if (ctx->r1 != 0) {
        // 0x8018F510: addiu       $a0, $a0, 0x80
        ctx->r4 = ADD32(ctx->r4, 0X80);
            goto L_8018F4E8;
    }
    // 0x8018F510: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
L_8018F514:
    // 0x8018F514: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018F518: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018F51C: addiu       $v0, $v0, 0x3400
    ctx->r2 = ADD32(ctx->r2, 0X3400);
    // 0x8018F520: addiu       $a0, $a0, 0x1B00
    ctx->r4 = ADD32(ctx->r4, 0X1B00);
    // 0x8018F524: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
L_8018F528:
    // 0x8018F528: bnel        $t1, $zero, L_8018F544
    if (ctx->r9 != 0) {
        // 0x8018F52C: addiu       $a0, $a0, 0x80
        ctx->r4 = ADD32(ctx->r4, 0X80);
            goto L_8018F544;
    }
    goto skip_2;
    // 0x8018F52C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    skip_2:
    // 0x8018F530: jal         0x8018F3BC
    // 0x8018F534: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    Corneria_SetupTerrainBumps(rdram, ctx);
        goto after_1;
    // 0x8018F534: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    after_1:
    // 0x8018F538: b           L_8018F550
    // 0x8018F53C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018F550;
    // 0x8018F53C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F540: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
L_8018F544:
    // 0x8018F544: bnel        $a0, $v0, L_8018F528
    if (ctx->r4 != ctx->r2) {
        // 0x8018F548: lbu         $t1, 0x0($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X0);
            goto L_8018F528;
    }
    goto skip_3;
    // 0x8018F548: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    skip_3:
    // 0x8018F54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018F550:
    // 0x8018F550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F554: jr          $ra
    // 0x8018F558: nop

    return;
    // 0x8018F558: nop

;}
RECOMP_FUNC void Corneria_Garuda_HandleDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ACE0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018ACE4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018ACE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018ACEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018ACF0: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x8018ACF4: beql        $t6, $zero, L_8018ADD4
    if (ctx->r14 == 0) {
        // 0x8018ACF8: lh          $t8, 0xCE($s0)
        ctx->r24 = MEM_H(ctx->r16, 0XCE);
            goto L_8018ADD4;
    }
    goto skip_0;
    // 0x8018ACF8: lh          $t8, 0xCE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XCE);
    skip_0:
    // 0x8018ACFC: lh          $t7, 0xD2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XD2);
    // 0x8018AD00: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018AD04: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8018AD08: bne         $t7, $zero, L_8018ADD0
    if (ctx->r15 != 0) {
        // 0x8018AD0C: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8018ADD0;
    }
    // 0x8018AD0C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018AD10: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018AD14: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018AD18: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018AD1C: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8018AD20: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018AD24: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018AD28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018AD2C: jal         0x80019218
    // 0x8018AD30: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8018AD30: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x8018AD34: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018AD38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018AD3C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018AD40: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018AD44: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018AD48: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8018AD4C: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8018AD50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AD54: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018AD58: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018AD5C: lwc1        $f10, 0xF0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8018AD60: lwc1        $f4, -0x4F7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4F7C);
    // 0x8018AD64: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8018AD68: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018AD6C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8018AD70: jal         0x8007C120
    // 0x8018AD74: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_1;
    // 0x8018AD74: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018AD78: lh          $t1, 0xCE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCE);
    // 0x8018AD7C: lhu         $t2, 0xD6($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XD6);
    // 0x8018AD80: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x8018AD84: addiu       $t5, $zero, 0xB3
    ctx->r13 = ADD32(0, 0XB3);
    // 0x8018AD88: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8018AD8C: sh          $t3, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r11;
    // 0x8018AD90: lh          $t4, 0xCE($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XCE);
    // 0x8018AD94: sh          $t0, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r8;
    // 0x8018AD98: andi        $a1, $t5, 0xFFFF
    ctx->r5 = ctx->r13 & 0XFFFF;
    // 0x8018AD9C: bgtz        $t4, L_8018ADD0
    if (SIGNED(ctx->r12) > 0) {
        // 0x8018ADA0: addiu       $a0, $s0, 0x1C
        ctx->r4 = ADD32(ctx->r16, 0X1C);
            goto L_8018ADD0;
    }
    // 0x8018ADA0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018ADA4: jal         0x800612B8
    // 0x8018ADA8: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8018ADA8: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    after_2:
    // 0x8018ADAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018ADB0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8018ADB4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018ADB8: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    // 0x8018ADBC: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    // 0x8018ADC0: sb          $zero, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = 0;
    // 0x8018ADC4: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x8018ADC8: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8018ADCC: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
L_8018ADD0:
    // 0x8018ADD0: lh          $t8, 0xCE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XCE);
L_8018ADD4:
    // 0x8018ADD4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018ADD8: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x8018ADDC: beql        $at, $zero, L_8018AEC0
    if (ctx->r1 == 0) {
        // 0x8018ADE0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8018AEC0;
    }
    goto skip_1;
    // 0x8018ADE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8018ADE4: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8018ADE8: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x8018ADEC: bnel        $t0, $zero, L_8018AEC0
    if (ctx->r8 != 0) {
        // 0x8018ADF0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8018AEC0;
    }
    goto skip_2;
    // 0x8018ADF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x8018ADF4: jal         0x80004EB0
    // 0x8018ADF8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018ADF8: nop

    after_3:
    // 0x8018ADFC: jal         0x80004EB0
    // 0x8018AE00: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8018AE00: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8018AE04: jal         0x80004EB0
    // 0x8018AE08: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8018AE08: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8018AE0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018AE10: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018AE14: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018AE18: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018AE1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018AE20: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8018AE24: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018AE28: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018AE2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018AE30: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018AE34: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018AE38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018AE3C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018AE40: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018AE44: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018AE48: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018AE4C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018AE50: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8018AE54: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018AE58: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018AE5C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018AE60: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018AE64: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8018AE68: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018AE6C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018AE70: jal         0x8007D2C8
    // 0x8018AE74: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_6;
    // 0x8018AE74: nop

    after_6:
    // 0x8018AE78: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018AE7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AE80: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018AE84: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018AE88: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018AE8C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8018AE90: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8018AE94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AE98: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018AE9C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018AEA0: lwc1        $f10, 0xF0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8018AEA4: lwc1        $f6, -0x4F78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F78);
    // 0x8018AEA8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8018AEAC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8018AEB0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8018AEB4: jal         0x8007C120
    // 0x8018AEB8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_7;
    // 0x8018AEB8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8018AEBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018AEC0:
    // 0x8018AEC0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018AEC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018AEC8: jr          $ra
    // 0x8018AECC: nop

    return;
    // 0x8018AECC: nop

;}
RECOMP_FUNC void Corneria_BossMissile_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80187674: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80187678: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8018767C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80187680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80187684: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80187688: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8018768C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80187690: jal         0x800613C4
    // 0x80187694: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80187694: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80187698: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8018769C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801876A0: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x801876A4: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801876A8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801876AC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801876B0: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801876B4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801876B8: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801876BC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801876C0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801876C4: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801876C8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801876CC: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x801876D0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801876D4: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
    // 0x801876D8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801876DC: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x801876E0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801876E4: sh          $t9, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r25;
    // 0x801876E8: sh          $t8, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r24;
    // 0x801876EC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801876F0: sh          $t0, 0xB4($a2)
    MEM_H(0XB4, ctx->r6) = ctx->r8;
    // 0x801876F4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801876F8: jal         0x800612B8
    // 0x801876FC: swc1        $f18, 0x128($a2)
    MEM_W(0X128, ctx->r6) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801876FC: swc1        $f18, 0x128($a2)
    MEM_W(0X128, ctx->r6) = ctx->f18.u32l;
    after_1:
    // 0x80187700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80187704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80187708: jr          $ra
    // 0x8018770C: nop

    return;
    // 0x8018770C: nop

;}
RECOMP_FUNC void Corneria_CoGaruda2_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B15C: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x8018B160: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018B164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018B168: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018B16C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018B170: jal         0x8018ACE0
    // 0x8018B174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Corneria_Garuda_HandleDamage(rdram, ctx);
        goto after_0;
    // 0x8018B174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018B178: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B17C: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x8018B180: lwc1        $f6, -0x4F6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F6C);
    // 0x8018B184: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018B188: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8018B18C: addiu       $t8, $t8, 0x1B00
    ctx->r24 = ADD32(ctx->r24, 0X1B00);
    // 0x8018B190: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x8018B194: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018B198: jal         0x80023090
    // 0x8018B19C: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8018B19C: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x8018B1A0: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018B1A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B1A8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018B1AC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018B1B0: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    // 0x8018B1B4: lwc1        $f18, -0x4F68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4F68);
    // 0x8018B1B8: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018B1BC: jal         0x80023250
    // 0x8018B1C0: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8018B1C0: nop

    after_2:
    // 0x8018B1C4: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018B1C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B1CC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018B1D0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8018B1D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B1D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B1DC: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x8018B1E0: lwc1        $f10, -0x4F64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4F64);
    // 0x8018B1E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B1E8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018B1EC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018B1F0: jal         0x80005E90
    // 0x8018B1F4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8018B1F4: nop

    after_3:
    // 0x8018B1F8: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8018B1FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018B200: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8018B204: beq         $v0, $zero, L_8018B234
    if (ctx->r2 == 0) {
        // 0x8018B208: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8018B234;
    }
    // 0x8018B208: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018B20C: beq         $v0, $at, L_8018B244
    if (ctx->r2 == ctx->r1) {
        // 0x8018B210: lui         $a0, 0x603
        ctx->r4 = S32(0X603 << 16);
            goto L_8018B244;
    }
    // 0x8018B210: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018B214: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018B218: beq         $v0, $at, L_8018B2A4
    if (ctx->r2 == ctx->r1) {
        // 0x8018B21C: lui         $a0, 0x603
        ctx->r4 = S32(0X603 << 16);
            goto L_8018B2A4;
    }
    // 0x8018B21C: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018B220: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018B224: beql        $v0, $at, L_8018B394
    if (ctx->r2 == ctx->r1) {
        // 0x8018B228: lw          $t4, 0x54($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X54);
            goto L_8018B394;
    }
    goto skip_0;
    // 0x8018B228: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    skip_0:
    // 0x8018B22C: b           L_8018B394
    // 0x8018B230: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
        goto L_8018B394;
    // 0x8018B230: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
L_8018B234:
    // 0x8018B234: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x8018B238: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
    // 0x8018B23C: b           L_8018B390
    // 0x8018B240: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
        goto L_8018B390;
    // 0x8018B240: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
L_8018B244:
    // 0x8018B244: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018B248: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B24C: addiu       $a0, $a0, 0x29C0
    ctx->r4 = ADD32(ctx->r4, 0X29C0);
    // 0x8018B250: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8018B254: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018B258: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018B25C: jal         0x80099A2C
    // 0x8018B260: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_4;
    // 0x8018B260: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x8018B264: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    // 0x8018B268: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8018B26C: bnel        $t1, $zero, L_8018B394
    if (ctx->r9 != 0) {
        // 0x8018B270: lw          $t4, 0x54($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X54);
            goto L_8018B394;
    }
    goto skip_1;
    // 0x8018B270: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    skip_1:
    // 0x8018B274: jal         0x80004EB0
    // 0x8018B278: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8018B278: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
    after_5:
    // 0x8018B27C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018B280: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B284: nop

    // 0x8018B288: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018B28C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018B290: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8018B294: nop

    // 0x8018B298: addiu       $t5, $t4, 0xA
    ctx->r13 = ADD32(ctx->r12, 0XA);
    // 0x8018B29C: b           L_8018B390
    // 0x8018B2A0: sw          $t5, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r13;
        goto L_8018B390;
    // 0x8018B2A0: sw          $t5, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r13;
L_8018B2A4:
    // 0x8018B2A4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018B2A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B2AC: addiu       $a0, $a0, 0x29C0
    ctx->r4 = ADD32(ctx->r4, 0X29C0);
    // 0x8018B2B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8018B2B4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018B2B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018B2BC: jal         0x80099A2C
    // 0x8018B2C0: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_6;
    // 0x8018B2C0: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    after_6:
    // 0x8018B2C4: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B2C8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018B2CC: addiu       $a0, $a0, -0x55FC
    ctx->r4 = ADD32(ctx->r4, -0X55FC);
    // 0x8018B2D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018B2D4: jal         0x8009ACDC
    // 0x8018B2D8: sh          $t7, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r15;
    Animation_GetFrameCount(rdram, ctx);
        goto after_7;
    // 0x8018B2D8: sh          $t7, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r15;
    after_7:
    // 0x8018B2DC: lh          $t8, 0xB6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B2E0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8018B2E4: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018B2E8: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8018B2EC: bne         $at, $zero, L_8018B2F8
    if (ctx->r1 != 0) {
        // 0x8018B2F0: nop
    
            goto L_8018B2F8;
    }
    // 0x8018B2F0: nop

    // 0x8018B2F4: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
L_8018B2F8:
    // 0x8018B2F8: jal         0x8009ACDC
    // 0x8018B2FC: addiu       $a0, $a0, -0x55FC
    ctx->r4 = ADD32(ctx->r4, -0X55FC);
    Animation_GetFrameCount(rdram, ctx);
        goto after_8;
    // 0x8018B2FC: addiu       $a0, $a0, -0x55FC
    ctx->r4 = ADD32(ctx->r4, -0X55FC);
    after_8:
    // 0x8018B300: lw          $t1, 0x58($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X58);
    // 0x8018B304: lh          $t0, 0xB6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B308: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018B30C: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8018B310: bne         $t0, $t2, L_8018B390
    if (ctx->r8 != ctx->r10) {
        // 0x8018B314: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8018B390;
    }
    // 0x8018B314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018B318: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8018B31C: sw          $v0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r2;
    // 0x8018B320: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018B324: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018B328: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B32C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B330: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B334: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8018B338: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8018B33C: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x8018B340: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x8018B344: jal         0x80006A20
    // 0x8018B348: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_9;
    // 0x8018B348: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8018B34C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018B350: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B354: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8018B358: swc1        $f6, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f6.u32l;
    // 0x8018B35C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018B360: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B364: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8018B368: swc1        $f8, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f8.u32l;
    // 0x8018B36C: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018B370: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x8018B374: ori         $a0, $a0, 0x401C
    ctx->r4 = ctx->r4 | 0X401C;
    // 0x8018B378: swc1        $f10, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f10.u32l;
    // 0x8018B37C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8018B380: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B384: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018B388: jal         0x80019218
    // 0x8018B38C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8018B38C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
L_8018B390:
    // 0x8018B390: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
L_8018B394:
    // 0x8018B394: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018B398: addiu       $a0, $a0, -0x55FC
    ctx->r4 = ADD32(ctx->r4, -0X55FC);
    // 0x8018B39C: bnel        $t4, $zero, L_8018B3D0
    if (ctx->r12 != 0) {
        // 0x8018B3A0: addiu       $s1, $sp, 0x60
        ctx->r17 = ADD32(ctx->r29, 0X60);
            goto L_8018B3D0;
    }
    goto skip_2;
    // 0x8018B3A0: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    skip_2:
    // 0x8018B3A4: lwc1        $f16, 0x11C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8018B3A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018B3AC: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x8018B3B0: lwc1        $f18, 0x12C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018B3B4: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    // 0x8018B3B8: lwc1        $f4, 0x13C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x8018B3BC: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x8018B3C0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018B3C4: swc1        $f8, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f8.u32l;
    // 0x8018B3C8: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018B3CC: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
L_8018B3D0:
    // 0x8018B3D0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8018B3D4: jal         0x8009AA20
    // 0x8018B3D8: lh          $a1, 0xB6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XB6);
    Animation_GetFrameData(rdram, ctx);
        goto after_11;
    // 0x8018B3D8: lh          $a1, 0xB6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XB6);
    after_11:
    // 0x8018B3DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B3E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018B3E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018B3E8: addiu       $a1, $s0, 0x18C
    ctx->r5 = ADD32(ctx->r16, 0X18C);
    // 0x8018B3EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B3F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8018B3F4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8018B3F8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8018B3FC: jal         0x8009BEEC
    // 0x8018B400: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_12;
    // 0x8018B400: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x8018B404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B408: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018B40C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018B410: jr          $ra
    // 0x8018B414: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8018B414: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void Corneria_CoCarrier_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ECAC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018ECB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018ECB4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018ECB8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8018ECBC: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8018ECC0: addiu       $a0, $a0, -0x2C00
    ctx->r4 = ADD32(ctx->r4, -0X2C00);
    // 0x8018ECC4: addiu       $a2, $a2, 0x1A0
    ctx->r6 = ADD32(ctx->r6, 0X1A0);
    // 0x8018ECC8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8018ECCC: jal         0x8009AA20
    // 0x8018ECD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x8018ECD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018ECD4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8018ECD8: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018ECDC: addiu       $t8, $t8, 0x4660
    ctx->r24 = ADD32(ctx->r24, 0X4660);
    // 0x8018ECE0: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8018ECE4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018ECE8: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x8018ECEC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8018ECF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018ECF4: addiu       $a3, $a3, -0x13AC
    ctx->r7 = ADD32(ctx->r7, -0X13AC);
    // 0x8018ECF8: addiu       $a1, $a1, -0x2A54
    ctx->r5 = ADD32(ctx->r5, -0X2A54);
    // 0x8018ECFC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018ED00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018ED04: jal         0x8009A72C
    // 0x8018ED08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x8018ED08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8018ED0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018ED10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018ED14: jr          $ra
    // 0x8018ED18: nop

    return;
    // 0x8018ED18: nop

;}
RECOMP_FUNC void Venom1_BossTrigger4_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019243C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80192440: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80192444: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80192448: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019244C: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
L_80192450:
    // 0x80192450: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80192454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80192458: beq         $t6, $zero, L_80192498
    if (ctx->r14 == 0) {
        // 0x8019245C: nop
    
            goto L_80192498;
    }
    // 0x8019245C: nop

    // 0x80192460: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x80192464: bne         $a1, $t7, L_80192498
    if (ctx->r5 != ctx->r15) {
        // 0x80192468: nop
    
            goto L_80192498;
    }
    // 0x80192468: nop

    // 0x8019246C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80192470: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80192474: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80192478: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019247C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80192480: nop

    // 0x80192484: bc1f        L_801924A0
    if (!c1cs) {
        // 0x80192488: nop
    
            goto L_801924A0;
    }
    // 0x80192488: nop

    // 0x8019248C: sw          $t8, -0x3F40($at)
    MEM_W(-0X3F40, ctx->r1) = ctx->r24;
    // 0x80192490: jr          $ra
    // 0x80192494: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x80192494: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_80192498:
    // 0x80192498: bne         $v1, $a2, L_80192450
    if (ctx->r3 != ctx->r6) {
        // 0x8019249C: addiu       $v0, $v0, 0x408
        ctx->r2 = ADD32(ctx->r2, 0X408);
            goto L_80192450;
    }
    // 0x8019249C: addiu       $v0, $v0, 0x408
    ctx->r2 = ADD32(ctx->r2, 0X408);
L_801924A0:
    // 0x801924A0: jr          $ra
    // 0x801924A4: nop

    return;
    // 0x801924A4: nop

;}
RECOMP_FUNC void Venom1_80192AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192AA4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80192AA8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80192AAC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80192AB0: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80192AB4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80192AB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192ABC: lwc1        $f22, -0x4CE4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X4CE4);
    // 0x80192AC0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80192AC4: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80192AC8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80192ACC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80192AD0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80192AD4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80192AD8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80192ADC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80192AE0: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80192AE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192AE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80192AEC: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80192AF0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80192AF4: jal         0x80005E90
    // 0x80192AF8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80192AF8: nop

    after_0:
    // 0x80192AFC: lwc1        $f8, 0x10($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80192B00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192B04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80192B08: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80192B0C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80192B10: jal         0x80005D44
    // 0x80192B14: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80192B14: nop

    after_1:
    // 0x80192B18: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80192B1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80192B20: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80192B24: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x80192B28: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80192B2C: nop

    // 0x80192B30: bc1tl       L_80192B54
    if (c1cs) {
        // 0x80192B34: lui         $at, 0xC2A0
        ctx->r1 = S32(0XC2A0 << 16);
            goto L_80192B54;
    }
    goto skip_0;
    // 0x80192B34: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    skip_0:
    // 0x80192B38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80192B3C: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80192B40: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80192B44: nop

    // 0x80192B48: bc1fl       L_80192BC0
    if (!c1cs) {
        // 0x80192B4C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80192BC0;
    }
    goto skip_1;
    // 0x80192B4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x80192B50: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
L_80192B54:
    // 0x80192B54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80192B58: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80192B5C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80192B60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192B64: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80192B68: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80192B6C: swc1        $f0, -0x6004($at)
    MEM_W(-0X6004, ctx->r1) = ctx->f0.u32l;
    // 0x80192B70: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80192B74: addiu       $s2, $s2, -0x6004
    ctx->r18 = ADD32(ctx->r18, -0X6004);
    // 0x80192B78: bc1fl       L_80192C88
    if (!c1cs) {
        // 0x80192B7C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80192C88;
    }
    goto skip_2;
    // 0x80192B7C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80192B80: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80192B84: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80192B88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80192B8C:
    // 0x80192B8C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80192B90: jal         0x80006A20
    // 0x80192B94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80192B94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x80192B98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192B9C: lwc1        $f0, -0x6004($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6004);
    // 0x80192BA0: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80192BA4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80192BA8: swc1        $f0, -0x6004($at)
    MEM_W(-0X6004, ctx->r1) = ctx->f0.u32l;
    // 0x80192BAC: bc1tl       L_80192B8C
    if (c1cs) {
        // 0x80192BB0: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80192B8C;
    }
    goto skip_3;
    // 0x80192BB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80192BB4: b           L_80192C88
    // 0x80192BB8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80192C88;
    // 0x80192BB8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80192BBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80192BC0:
    // 0x80192BC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80192BC4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80192BC8: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80192BCC: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80192BD0: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80192BD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192BD8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80192BDC: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x80192BE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80192BE4: nop

    // 0x80192BE8: bc1fl       L_80192C00
    if (!c1cs) {
        // 0x80192BEC: lui         $at, 0x43E1
        ctx->r1 = S32(0X43E1 << 16);
            goto L_80192C00;
    }
    goto skip_4;
    // 0x80192BEC: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    skip_4:
    // 0x80192BF0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80192BF4: nop

    // 0x80192BF8: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x80192BFC: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
L_80192C00:
    // 0x80192C00: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80192C04: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80192C08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80192C0C: c.le.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl <= ctx->f26.fl;
    // 0x80192C10: nop

    // 0x80192C14: bc1fl       L_80192C88
    if (!c1cs) {
        // 0x80192C18: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80192C88;
    }
    goto skip_5;
    // 0x80192C18: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x80192C1C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80192C20: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80192C24: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
L_80192C28:
    // 0x80192C28: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192C2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80192C30: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80192C34: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80192C38: jal         0x80005E90
    // 0x80192C3C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x80192C3C: nop

    after_3:
    // 0x80192C40: lwc1        $f16, 0x10($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80192C44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192C48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80192C4C: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80192C50: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80192C54: jal         0x80005D44
    // 0x80192C58: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80192C58: nop

    after_4:
    // 0x80192C5C: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x80192C60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192C64: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80192C68: jal         0x80006A20
    // 0x80192C6C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x80192C6C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_5:
    // 0x80192C70: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x80192C74: c.le.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
    // 0x80192C78: nop

    // 0x80192C7C: bc1tl       L_80192C28
    if (c1cs) {
        // 0x80192C80: lwc1        $f8, 0x14($s2)
        ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
            goto L_80192C28;
    }
    goto skip_6;
    // 0x80192C80: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    skip_6:
    // 0x80192C84: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80192C88:
    // 0x80192C88: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80192C8C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80192C90: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80192C94: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80192C98: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80192C9C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80192CA0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80192CA4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80192CA8: jr          $ra
    // 0x80192CAC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80192CAC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Venom1_LevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801988B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801988BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801988C0: jal         0x80096A74
    // 0x801988C4: nop

    Venom1_LevelStart2(rdram, ctx);
        goto after_0;
    // 0x801988C4: nop

    after_0:
    // 0x801988C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801988CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801988D0: jr          $ra
    // 0x801988D4: nop

    return;
    // 0x801988D4: nop

;}
RECOMP_FUNC void Venom1_Ve1Golemech_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801985E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801985E8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801985EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801985F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801985F4: lh          $t6, 0xBC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XBC);
    // 0x801985F8: lui         $a1, 0x902
    ctx->r5 = S32(0X902 << 16);
    // 0x801985FC: addiu       $a1, $a1, -0x3F0C
    ctx->r5 = ADD32(ctx->r5, -0X3F0C);
    // 0x80198600: bne         $t6, $zero, L_80198634
    if (ctx->r14 != 0) {
        // 0x80198604: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80198634;
    }
    // 0x80198604: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80198608: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8019860C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80198610: addiu       $t8, $t8, 0x4660
    ctx->r24 = ADD32(ctx->r24, 0X4660);
    // 0x80198614: addiu       $t7, $t7, 0x3D64
    ctx->r15 = ADD32(ctx->r15, 0X3D64);
    // 0x80198618: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8019861C: addiu       $a3, $a3, 0x37F4
    ctx->r7 = ADD32(ctx->r7, 0X37F4);
    // 0x80198620: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80198624: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80198628: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    // 0x8019862C: jal         0x8009A72C
    // 0x80198630: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_0;
    // 0x80198630: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
L_80198634:
    // 0x80198634: lh          $t9, 0x9A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X9A);
    // 0x80198638: sh          $t9, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r25;
    // 0x8019863C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80198640: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80198644: jr          $ra
    // 0x80198648: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80198648: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Corneria_CoGaruda1_CheckCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018AB64: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8018AB68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018AB6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018AB70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018AB74: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x8018AB78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018AB7C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018AB80: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018AB84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018AB88: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018AB8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018AB90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018AB94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018AB98: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8018AB9C: addiu       $t6, $t6, -0x6798
    ctx->r14 = ADD32(ctx->r14, -0X6798);
    // 0x8018ABA0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018ABA4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8018ABA8: addiu       $t1, $t1, -0x678C
    ctx->r9 = ADD32(ctx->r9, -0X678C);
    // 0x8018ABAC: sw          $at, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r1;
    // 0x8018ABB0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8018ABB4: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x8018ABB8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8018ABBC: sw          $t9, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r25;
    // 0x8018ABC0: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018ABC4: addiu       $t8, $t8, -0x677C
    ctx->r24 = ADD32(ctx->r24, -0X677C);
    // 0x8018ABC8: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x8018ABCC: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    // 0x8018ABD0: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x8018ABD4: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8018ABD8: lui         $s6, 0x8016
    ctx->r22 = S32(0X8016 << 16);
    // 0x8018ABDC: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x8018ABE0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8018ABE4: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x8018ABE8: lw          $t4, 0xC($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC);
    // 0x8018ABEC: addiu       $s6, $s6, 0x1B00
    ctx->r22 = ADD32(ctx->r22, 0X1B00);
    // 0x8018ABF0: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x8018ABF4: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x8018ABF8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8018ABFC: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8018AC00: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x8018AC04: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8018AC08: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8018AC0C: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8018AC10: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8018AC14: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x8018AC18: addiu       $fp, $sp, 0x60
    ctx->r30 = ADD32(ctx->r29, 0X60);
    // 0x8018AC1C: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
    // 0x8018AC20: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8018AC24: addiu       $s4, $sp, 0x7C
    ctx->r20 = ADD32(ctx->r29, 0X7C);
    // 0x8018AC28: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x8018AC2C: sw          $t9, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r25;
L_8018AC30:
    // 0x8018AC30: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8018AC34: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018AC38: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8018AC3C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8018AC40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018AC44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018AC48: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x8018AC4C: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018AC50: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x8018AC54: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018AC58: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018AC5C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018AC60: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x8018AC64: jal         0x8006351C
    // 0x8018AC68: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    Object_CheckCollision(rdram, ctx);
        goto after_0;
    // 0x8018AC68: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    after_0:
    // 0x8018AC6C: beq         $v0, $zero, L_8018ACA0
    if (ctx->r2 == 0) {
        // 0x8018AC70: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8018ACA0;
    }
    // 0x8018AC70: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8018AC74: bne         $at, $zero, L_8018ACA0
    if (ctx->r1 != 0) {
        // 0x8018AC78: sll         $t3, $v0, 7
        ctx->r11 = S32(ctx->r2 << 7);
            goto L_8018ACA0;
    }
    // 0x8018AC78: sll         $t3, $v0, 7
    ctx->r11 = S32(ctx->r2 << 7);
    // 0x8018AC7C: addu        $v1, $s6, $t3
    ctx->r3 = ADD32(ctx->r22, ctx->r11);
    // 0x8018AC80: lbu         $t2, -0x500($v1)
    ctx->r10 = MEM_BU(ctx->r3, -0X500);
    // 0x8018AC84: bnel        $s5, $t2, L_8018ACA4
    if (ctx->r21 != ctx->r10) {
        // 0x8018AC88: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8018ACA4;
    }
    goto skip_0;
    // 0x8018AC88: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8018AC8C: lhu         $t0, -0x4FE($v1)
    ctx->r8 = MEM_HU(ctx->r3, -0X4FE);
    // 0x8018AC90: bnel        $s7, $t0, L_8018ACA4
    if (ctx->r23 != ctx->r8) {
        // 0x8018AC94: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8018ACA4;
    }
    goto skip_1;
    // 0x8018AC94: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x8018AC98: b           L_8018ACB0
    // 0x8018AC9C: addiu       $v0, $v0, -0x9
    ctx->r2 = ADD32(ctx->r2, -0X9);
        goto L_8018ACB0;
    // 0x8018AC9C: addiu       $v0, $v0, -0x9
    ctx->r2 = ADD32(ctx->r2, -0X9);
L_8018ACA0:
    // 0x8018ACA0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8018ACA4:
    // 0x8018ACA4: bne         $s0, $fp, L_8018AC30
    if (ctx->r16 != ctx->r30) {
        // 0x8018ACA8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8018AC30;
    }
    // 0x8018ACA8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018ACAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018ACB0:
    // 0x8018ACB0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018ACB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018ACB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018ACBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018ACC0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018ACC4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018ACC8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018ACCC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018ACD0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018ACD4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018ACD8: jr          $ra
    // 0x8018ACDC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8018ACDC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Corneria_LevelComplete1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191160: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80191164: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80191168: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019116C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80191170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80191174: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80191178: swc1        $f20, 0x4AC($s0)
    MEM_W(0X4AC, ctx->r16) = ctx->f20.u32l;
    // 0x8019117C: swc1        $f20, 0x4A4($s0)
    MEM_W(0X4A4, ctx->r16) = ctx->f20.u32l;
    // 0x80191180: swc1        $f20, 0x4A8($s0)
    MEM_W(0X4A8, ctx->r16) = ctx->f20.u32l;
    // 0x80191184: swc1        $f20, 0x4A0($s0)
    MEM_W(0X4A0, ctx->r16) = ctx->f20.u32l;
    // 0x80191188: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8019118C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80191190: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191194: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80191198: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x8019119C: jal         0x8009BC2C
    // 0x801911A0: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801911A0: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    after_0:
    // 0x801911A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801911A8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801911AC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801911B0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x801911B4: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x801911B8: jal         0x8009BC2C
    // 0x801911BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801911BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x801911C0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801911C4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801911C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801911CC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x801911D0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801911D4: jal         0x8009BC2C
    // 0x801911D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801911D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x801911DC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801911E0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801911E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801911E8: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x801911EC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x801911F0: jal         0x8009BD38
    // 0x801911F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x801911F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x801911F8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801911FC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80191200: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191204: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x80191208: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019120C: jal         0x8009BC2C
    // 0x80191210: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80191210: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x80191214: lw          $t6, 0x1D0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1D0);
    // 0x80191218: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8019121C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191220: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80191224: bne         $at, $zero, L_8019127C
    if (ctx->r1 != 0) {
        // 0x80191228: addiu       $t7, $zero, 0x845
        ctx->r15 = ADD32(0, 0X845);
            goto L_8019127C;
    }
    // 0x80191228: addiu       $t7, $zero, 0x845
    ctx->r15 = ADD32(0, 0X845);
    // 0x8019122C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80191230: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80191234: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80191238: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8019123C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80191240: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x80191244: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80191248: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x8019124C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80191250: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x80191254: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x80191258: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8019125C: lwc1        $f10, 0x2FC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X2FC);
    // 0x80191260: lwc1        $f4, 0x5F0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X5F0);
    // 0x80191264: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80191268: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019126C: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80191270: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80191274: swc1        $f18, 0x2FC($t0)
    MEM_W(0X2FC, ctx->r8) = ctx->f18.u32l;
    // 0x80191278: swc1        $f6, 0x5F0($t0)
    MEM_W(0X5F0, ctx->r8) = ctx->f6.u32l;
L_8019127C:
    // 0x8019127C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191280: sh          $t7, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r15;
    // 0x80191284: lw          $t8, 0x1D0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1D0);
    // 0x80191288: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019128C: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x80191290: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80191294: beq         $at, $zero, L_80191C18
    if (ctx->r1 == 0) {
        // 0x80191298: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80191C18;
    }
    // 0x80191298: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019129C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801912A0: addu        $at, $at, $t8
    gpr jr_addend_801912A8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801912A4: lw          $t8, -0x4DB8($at)
    ctx->r24 = ADD32(ctx->r1, -0X4DB8);
    // 0x801912A8: jr          $t8
    // 0x801912AC: nop

    switch (jr_addend_801912A8 >> 2) {
        case 0: goto L_801912B0; break;
        case 1: goto L_80191334; break;
        case 2: goto L_8019163C; break;
        case 3: goto L_80191748; break;
        case 4: goto L_80191AFC; break;
        default: switch_error(__func__, 0x801912A8, 0x8019B248);
    }
    // 0x801912AC: nop

L_801912B0:
    // 0x801912B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801912B4: jal         0x8001A38C
    // 0x801912B8: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    Audio_StopSfxByBankAndSource(rdram, ctx);
        goto after_5;
    // 0x801912B8: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    after_5:
    // 0x801912BC: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x801912C0: addiu       $v0, $v0, -0x4928
    ctx->r2 = ADD32(ctx->r2, -0X4928);
    // 0x801912C4: lwc1        $f10, 0xF8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF8);
    // 0x801912C8: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801912CC: lwc1        $f4, 0x100($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X100);
    // 0x801912D0: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801912D4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801912D8: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801912DC: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    // 0x801912E0: jal         0x80005100
    // 0x801912E4: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_6;
    // 0x801912E4: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x801912E8: jal         0x8009F768
    // 0x801912EC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_7;
    // 0x801912EC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x801912F0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801912F4: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801912F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801912FC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80191300: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80191304: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80191308: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8019130C: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80191310: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80191314: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80191318: lw          $t9, 0x1D0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1D0);
    // 0x8019131C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80191320: sw          $t1, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r9;
    // 0x80191324: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x80191328: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8019132C: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x80191330: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
L_80191334:
    // 0x80191334: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80191338: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019133C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191340: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80191344: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80191348: jal         0x8009BC2C
    // 0x8019134C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8019134C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80191350: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80191354: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191358: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8019135C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191360: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80191364: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80191368: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x8019136C: jal         0x8009BC2C
    // 0x80191370: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80191370: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x80191374: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80191378: lui         $a1, 0x44A2
    ctx->r5 = S32(0X44A2 << 16);
    // 0x8019137C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80191380: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191384: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80191388: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x8019138C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80191390: jal         0x8009BC2C
    // 0x80191394: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80191394: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x80191398: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019139C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801913A0: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x801913A4: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x801913A8: nop

    // 0x801913AC: bc1f        L_801913D0
    if (!c1cs) {
        // 0x801913B0: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_801913D0;
    }
    // 0x801913B0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801913B4: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x801913B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801913BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801913C0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801913C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801913C8: b           L_801913EC
    // 0x801913CC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_801913EC;
    // 0x801913CC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_801913D0:
    // 0x801913D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801913D4: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x801913D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801913DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801913E0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801913E4: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801913E8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_801913EC:
    // 0x801913EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801913F0: lwc1        $f8, -0x4DA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4DA4);
    // 0x801913F4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801913F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801913FC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191400: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80191404: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80191408: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019140C: jal         0x80005E90
    // 0x80191410: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x80191410: nop

    after_11:
    // 0x80191414: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191418: lwc1        $f18, 0x7A4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7A4C);
    // 0x8019141C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191420: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x80191424: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80191428: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019142C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80191430: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80191434: jal         0x80006970
    // 0x80191438: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x80191438: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x8019143C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191440: lwc1        $f4, -0x4830($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4830);
    // 0x80191444: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80191448: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8019144C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191450: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191454: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80191458: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8019145C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80191460: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80191464: jal         0x8009BC2C
    // 0x80191468: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x80191468: nop

    after_13:
    // 0x8019146C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191470: lwc1        $f10, -0x482C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X482C);
    // 0x80191474: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80191478: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019147C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80191480: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191484: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80191488: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8019148C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80191490: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80191494: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80191498: jal         0x8009BC2C
    // 0x8019149C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8019149C: nop

    after_14:
    // 0x801914A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801914A4: lwc1        $f6, -0x4828($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4828);
    // 0x801914A8: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801914AC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801914B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801914B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801914B8: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x801914BC: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801914C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801914C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801914C8: jal         0x8009BC2C
    // 0x801914CC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x801914CC: nop

    after_15:
    // 0x801914D0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801914D4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801914D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801914DC: lw          $a1, -0x4830($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4830);
    // 0x801914E0: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x801914E4: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801914E8: jal         0x8009BC2C
    // 0x801914EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x801914EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x801914F0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801914F4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801914F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801914FC: lw          $a1, -0x482C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X482C);
    // 0x80191500: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80191504: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80191508: jal         0x8009BC2C
    // 0x8019150C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8019150C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_17:
    // 0x80191510: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80191514: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80191518: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019151C: lw          $a1, -0x4828($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4828);
    // 0x80191520: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80191524: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80191528: jal         0x8009BC2C
    // 0x8019152C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8019152C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_18:
    // 0x80191530: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80191534: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80191538: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019153C: lwc1        $f10, -0x4830($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4830);
    // 0x80191540: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80191544: lw          $t2, 0x7A80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7A80);
    // 0x80191548: sub.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8019154C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191550: lwc1        $f10, -0x4828($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4828);
    // 0x80191554: slti        $at, $t2, 0x1E
    ctx->r1 = SIGNED(ctx->r10) < 0X1E ? 1 : 0;
    // 0x80191558: beq         $at, $zero, L_801915A8
    if (ctx->r1 == 0) {
        // 0x8019155C: sub.s       $f14, $f16, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f10.fl;
            goto L_801915A8;
    }
    // 0x8019155C: sub.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80191560: jal         0x80005100
    // 0x80191564: nop

    Math_Atan2F(rdram, ctx);
        goto after_19;
    // 0x80191564: nop

    after_19:
    // 0x80191568: jal         0x8009F768
    // 0x8019156C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_20;
    // 0x8019156C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_20:
    // 0x80191570: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191574: lwc1        $f10, -0x4DA0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4DA0);
    // 0x80191578: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019157C: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x80191580: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80191584: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80191588: jal         0x8009BD38
    // 0x8019158C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_21;
    // 0x8019158C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x80191590: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80191594: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191598: nop

    // 0x8019159C: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801915A0: b           L_801915EC
    // 0x801915A4: nop

        goto L_801915EC;
    // 0x801915A4: nop

L_801915A8:
    // 0x801915A8: jal         0x80005100
    // 0x801915AC: nop

    Math_Atan2F(rdram, ctx);
        goto after_22;
    // 0x801915AC: nop

    after_22:
    // 0x801915B0: jal         0x8009F768
    // 0x801915B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_23;
    // 0x801915B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_23:
    // 0x801915B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801915BC: lwc1        $f4, -0x4D9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4D9C);
    // 0x801915C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801915C4: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x801915C8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x801915CC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801915D0: jal         0x8009BD38
    // 0x801915D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_24;
    // 0x801915D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_24:
    // 0x801915D8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801915DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801915E0: nop

    // 0x801915E4: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801915E8: nop

L_801915EC:
    // 0x801915EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801915F0: lwc1        $f8, -0x4D98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4D98);
    // 0x801915F4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x801915F8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801915FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191600: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80191604: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80191608: jal         0x8009BD38
    // 0x8019160C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_25;
    // 0x8019160C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_25:
    // 0x80191610: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80191614: lw          $t3, 0x7A80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A80);
    // 0x80191618: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
    // 0x8019161C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80191620: bne         $t3, $at, L_80191634
    if (ctx->r11 != ctx->r1) {
        // 0x80191624: nop
    
            goto L_80191634;
    }
    // 0x80191624: nop

    // 0x80191628: lw          $t4, 0x1D0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1D0);
    // 0x8019162C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80191630: sw          $t5, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r13;
L_80191634:
    // 0x80191634: b           L_80191C18
    // 0x80191638: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
        goto L_80191C18;
    // 0x80191638: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_8019163C:
    // 0x8019163C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191640: lwc1        $f10, -0x4D94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4D94);
    // 0x80191644: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80191648: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019164C: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80191650: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80191654: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80191658: jal         0x8009BD38
    // 0x8019165C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_26;
    // 0x8019165C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_26:
    // 0x80191660: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191664: lwc1        $f18, -0x4D90($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4D90);
    // 0x80191668: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8019166C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80191670: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191674: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80191678: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019167C: jal         0x8009BD38
    // 0x80191680: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_27;
    // 0x80191680: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_27:
    // 0x80191684: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191688: lwc1        $f4, -0x4D8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4D8C);
    // 0x8019168C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80191690: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80191694: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x80191698: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8019169C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801916A0: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x801916A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801916A8: jal         0x8009BC2C
    // 0x801916AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x801916AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_28:
    // 0x801916B0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x801916B4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801916B8: lw          $a2, 0x7A50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A50);
    // 0x801916BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801916C0: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x801916C4: jal         0x8009BC2C
    // 0x801916C8: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x801916C8: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_29:
    // 0x801916CC: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x801916D0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801916D4: lw          $a2, 0x7A50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A50);
    // 0x801916D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801916DC: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x801916E0: jal         0x8009BC2C
    // 0x801916E4: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_30;
    // 0x801916E4: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_30:
    // 0x801916E8: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    // 0x801916EC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801916F0: lw          $a2, 0x7A50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A50);
    // 0x801916F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801916F8: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x801916FC: jal         0x8009BC2C
    // 0x80191700: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x80191700: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_31:
    // 0x80191704: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80191708: lw          $t6, 0x7A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A80);
    // 0x8019170C: addiu       $at, $zero, 0x15E
    ctx->r1 = ADD32(0, 0X15E);
    // 0x80191710: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80191714: bne         $t6, $at, L_80191740
    if (ctx->r14 != ctx->r1) {
        // 0x80191718: nop
    
            goto L_80191740;
    }
    // 0x80191718: nop

    // 0x8019171C: lw          $t7, 0x1D0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1D0);
    // 0x80191720: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191724: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80191728: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8019172C: swc1        $f20, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f20.u32l;
    // 0x80191730: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191734: lwc1        $f6, -0x4D88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D88);
    // 0x80191738: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019173C: swc1        $f6, 0x7A54($at)
    MEM_W(0X7A54, ctx->r1) = ctx->f6.u32l;
L_80191740:
    // 0x80191740: b           L_80191C18
    // 0x80191744: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
        goto L_80191C18;
    // 0x80191744: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_80191748:
    // 0x80191748: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019174C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80191750: slti        $at, $v0, 0x2BD
    ctx->r1 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80191754: bne         $at, $zero, L_8019176C
    if (ctx->r1 != 0) {
        // 0x80191758: slti        $at, $v0, 0x3E8
        ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
            goto L_8019176C;
    }
    // 0x80191758: slti        $at, $v0, 0x3E8
    ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // 0x8019175C: beql        $at, $zero, L_80191770
    if (ctx->r1 == 0) {
        // 0x80191760: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80191770;
    }
    goto skip_0;
    // 0x80191760: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80191764: jal         0x8004AA84
    // 0x80191768: nop

    Cutscene_CoComplete_SpawnClouds(rdram, ctx);
        goto after_32;
    // 0x80191768: nop

    after_32:
L_8019176C:
    // 0x8019176C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80191770:
    // 0x80191770: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80191774: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191778: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x8019177C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80191780: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80191784: jal         0x8009BD38
    // 0x80191788: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_33;
    // 0x80191788: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_33:
    // 0x8019178C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80191790: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80191794: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80191798: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019179C: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x801917A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801917A4: jal         0x8009BD38
    // 0x801917A8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_34;
    // 0x801917A8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_34:
    // 0x801917AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801917B0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801917B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801917B8: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x801917BC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801917C0: jal         0x8009BC2C
    // 0x801917C4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_35;
    // 0x801917C4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_35:
    // 0x801917C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801917CC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801917D0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x801917D4: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x801917D8: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x801917DC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801917E0: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x801917E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801917E8: jal         0x8009BC2C
    // 0x801917EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_36;
    // 0x801917EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_36:
    // 0x801917F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801917F4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801917F8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x801917FC: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x80191800: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80191804: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80191808: addiu       $a0, $a0, 0x7A54
    ctx->r4 = ADD32(ctx->r4, 0X7A54);
    // 0x8019180C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80191810: jal         0x8009BC2C
    // 0x80191814: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_37;
    // 0x80191814: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_37:
    // 0x80191818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019181C: lwc1        $f8, -0x4D84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4D84);
    // 0x80191820: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80191824: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191828: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019182C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80191830: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80191834: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80191838: jal         0x80005E90
    // 0x8019183C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_38;
    // 0x8019183C: nop

    after_38:
    // 0x80191840: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191844: jal         0x80005708
    // 0x80191848: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_39;
    // 0x80191848: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_39:
    // 0x8019184C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191850: lwc1        $f18, 0x7A5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7A5C);
    // 0x80191854: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191858: lwc1        $f4, -0x4D80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4D80);
    // 0x8019185C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191860: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191864: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80191868: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019186C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80191870: jal         0x80005E90
    // 0x80191874: nop

    Matrix_RotateY(rdram, ctx);
        goto after_40;
    // 0x80191874: nop

    after_40:
    // 0x80191878: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8019187C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191880: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80191884: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191888: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019188C: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x80191890: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191894: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80191898: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8019189C: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x801918A0: jal         0x80006970
    // 0x801918A4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_41;
    // 0x801918A4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    after_41:
    // 0x801918A8: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801918AC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801918B0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801918B4: lw          $a2, 0x7A50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A50);
    // 0x801918B8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801918BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801918C0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x801918C4: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801918C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801918CC: jal         0x8009BC2C
    // 0x801918D0: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x801918D0: nop

    after_42:
    // 0x801918D4: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801918D8: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801918DC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801918E0: lw          $a2, 0x7A50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A50);
    // 0x801918E4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801918E8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801918EC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x801918F0: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801918F4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801918F8: jal         0x8009BC2C
    // 0x801918FC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_43;
    // 0x801918FC: nop

    after_43:
    // 0x80191900: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80191904: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80191908: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019190C: lw          $a2, 0x7A50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A50);
    // 0x80191910: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191914: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80191918: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8019191C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80191920: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80191924: jal         0x8009BC2C
    // 0x80191928: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_44;
    // 0x80191928: nop

    after_44:
    // 0x8019192C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191930: jal         0x80005740
    // 0x80191934: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_45;
    // 0x80191934: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_45:
    // 0x80191938: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8019193C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80191940: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191944: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191948: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x8019194C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191950: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80191954: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80191958: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8019195C: jal         0x80006970
    // 0x80191960: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_46;
    // 0x80191960: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_46:
    // 0x80191964: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80191968: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019196C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80191970: lw          $a2, 0x7A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A54);
    // 0x80191974: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191978: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8019197C: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80191980: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80191984: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80191988: jal         0x8009BC2C
    // 0x8019198C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x8019198C: nop

    after_47:
    // 0x80191990: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80191994: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80191998: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019199C: lw          $a2, 0x7A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A54);
    // 0x801919A0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801919A4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801919A8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x801919AC: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801919B0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801919B4: jal         0x8009BC2C
    // 0x801919B8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_48;
    // 0x801919B8: nop

    after_48:
    // 0x801919BC: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801919C0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801919C4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801919C8: lw          $a2, 0x7A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A54);
    // 0x801919CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801919D0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801919D4: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x801919D8: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801919DC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801919E0: jal         0x8009BC2C
    // 0x801919E4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_49;
    // 0x801919E4: nop

    after_49:
    // 0x801919E8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801919EC: addiu       $v1, $v1, 0x7A48
    ctx->r3 = ADD32(ctx->r3, 0X7A48);
    // 0x801919F0: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x801919F4: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x801919F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801919FC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191A00: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
    // 0x80191A04: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80191A08: slti        $at, $v0, 0x191
    ctx->r1 = SIGNED(ctx->r2) < 0X191 ? 1 : 0;
    // 0x80191A0C: bne         $at, $zero, L_80191A44
    if (ctx->r1 != 0) {
        // 0x80191A10: slti        $at, $v0, 0x3E8
        ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
            goto L_80191A44;
    }
    // 0x80191A10: slti        $at, $v0, 0x3E8
    ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // 0x80191A14: beq         $at, $zero, L_80191A44
    if (ctx->r1 == 0) {
        // 0x80191A18: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80191A44;
    }
    // 0x80191A18: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80191A1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191A20: lui         $a3, 0x3B44
    ctx->r7 = S32(0X3B44 << 16);
    // 0x80191A24: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x80191A28: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x80191A2C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80191A30: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80191A34: jal         0x8009BC2C
    // 0x80191A38: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_50;
    // 0x80191A38: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_50:
    // 0x80191A3C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191A40: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80191A44:
    // 0x80191A44: slti        $at, $v0, 0x44D
    ctx->r1 = SIGNED(ctx->r2) < 0X44D ? 1 : 0;
    // 0x80191A48: bne         $at, $zero, L_80191A78
    if (ctx->r1 != 0) {
        // 0x80191A4C: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80191A78;
    }
    // 0x80191A4C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80191A50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80191A54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80191A58: lui         $a3, 0x3B44
    ctx->r7 = S32(0X3B44 << 16);
    // 0x80191A5C: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x80191A60: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x80191A64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80191A68: jal         0x8009BC2C
    // 0x80191A6C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_51;
    // 0x80191A6C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_51:
    // 0x80191A70: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191A74: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80191A78:
    // 0x80191A78: addiu       $at, $zero, 0x4F6
    ctx->r1 = ADD32(0, 0X4F6);
    // 0x80191A7C: bne         $v0, $at, L_80191AF0
    if (ctx->r2 != ctx->r1) {
        // 0x80191A80: lui         $a0, 0x1032
        ctx->r4 = S32(0X1032 << 16);
            goto L_80191AF0;
    }
    // 0x80191A80: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x80191A84: jal         0x800182F4
    // 0x80191A88: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_52;
    // 0x80191A88: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_52:
    // 0x80191A8C: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x80191A90: jal         0x800182F4
    // 0x80191A94: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_53;
    // 0x80191A94: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_53:
    // 0x80191A98: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80191A9C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80191AA0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80191AA4: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80191AA8: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80191AAC: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80191AB0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80191AB4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191AB8: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80191ABC: jal         0x80019218
    // 0x80191AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_54;
    // 0x80191AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_54:
    // 0x80191AC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80191AC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191ACC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80191AD0: lw          $t1, 0x1D0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1D0);
    // 0x80191AD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191AD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191ADC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80191AE0: sw          $t2, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r10;
    // 0x80191AE4: swc1        $f18, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f18.u32l;
    // 0x80191AE8: swc1        $f4, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f4.u32l;
    // 0x80191AEC: swc1        $f6, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f6.u32l;
L_80191AF0:
    // 0x80191AF0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80191AF4: b           L_80191C18
    // 0x80191AF8: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
        goto L_80191C18;
    // 0x80191AF8: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_80191AFC:
    // 0x80191AFC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191B00: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80191B04: slti        $at, $v0, 0x4F6
    ctx->r1 = SIGNED(ctx->r2) < 0X4F6 ? 1 : 0;
    // 0x80191B08: bne         $at, $zero, L_80191B68
    if (ctx->r1 != 0) {
        // 0x80191B0C: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_80191B68;
    }
    // 0x80191B0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191B10: lwc1        $f0, -0x4D7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D7C);
    // 0x80191B14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191B18: lwc1        $f10, -0x4D78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4D78);
    // 0x80191B1C: lwc1        $f8, 0xD0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80191B20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191B24: lwc1        $f4, 0x25C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x80191B28: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80191B2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191B30: swc1        $f18, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f18.u32l;
    // 0x80191B34: lwc1        $f6, -0x4D74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D74);
    // 0x80191B38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80191B3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191B40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191B44: swc1        $f8, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f8.u32l;
    // 0x80191B48: lwc1        $f10, 0x25C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x80191B4C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80191B50: nop

    // 0x80191B54: bc1fl       L_80191B64
    if (!c1cs) {
        // 0x80191B58: swc1        $f18, 0x190($s0)
        MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
            goto L_80191B64;
    }
    goto skip_1;
    // 0x80191B58: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
    skip_1:
    // 0x80191B5C: swc1        $f0, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f0.u32l;
    // 0x80191B60: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
L_80191B64:
    // 0x80191B64: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80191B68:
    // 0x80191B68: addiu       $at, $zero, 0x50A
    ctx->r1 = ADD32(0, 0X50A);
    // 0x80191B6C: bnel        $v0, $at, L_80191B90
    if (ctx->r2 != ctx->r1) {
        // 0x80191B70: slti        $at, $v0, 0x515
        ctx->r1 = SIGNED(ctx->r2) < 0X515 ? 1 : 0;
            goto L_80191B90;
    }
    goto skip_2;
    // 0x80191B70: slti        $at, $v0, 0x515
    ctx->r1 = SIGNED(ctx->r2) < 0X515 ? 1 : 0;
    skip_2:
    // 0x80191B74: jal         0x8001DBD0
    // 0x80191B78: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    Audio_FadeOutAll(rdram, ctx);
        goto after_55;
    // 0x80191B78: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_55:
    // 0x80191B7C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191B80: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80191B84: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x80191B88: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80191B8C: slti        $at, $v0, 0x515
    ctx->r1 = SIGNED(ctx->r2) < 0X515 ? 1 : 0;
L_80191B90:
    // 0x80191B90: bne         $at, $zero, L_80191C18
    if (ctx->r1 != 0) {
        // 0x80191B94: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80191C18;
    }
    // 0x80191B94: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80191B98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191B9C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80191BA0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191BA4: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x80191BA8: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80191BAC: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80191BB0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80191BB4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80191BB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80191BBC: lw          $t6, -0x7CC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CC0);
    // 0x80191BC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191BC4: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80191BC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191BCC: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80191BD0: bne         $v0, $t6, L_80191C18
    if (ctx->r2 != ctx->r14) {
        // 0x80191BD4: sw          $t5, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r13;
            goto L_80191C18;
    }
    // 0x80191BD4: sw          $t5, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r13;
    // 0x80191BD8: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80191BDC: sw          $t7, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r15;
    // 0x80191BE0: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x80191BE4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80191BE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191BEC: sw          $t8, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r24;
    // 0x80191BF0: jal         0x800A3F50
    // 0x80191BF4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_56;
    // 0x80191BF4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_56:
    // 0x80191BF8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80191BFC: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x80191C00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80191C04: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80191C08: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80191C0C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80191C10: sb          $t9, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = ctx->r25;
    // 0x80191C14: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_80191C18:
    // 0x80191C18: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191C1C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80191C20: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80191C24: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80191C28: slti        $at, $v0, 0x2AB
    ctx->r1 = SIGNED(ctx->r2) < 0X2AB ? 1 : 0;
    // 0x80191C2C: bne         $at, $zero, L_80191C78
    if (ctx->r1 != 0) {
        // 0x80191C30: addiu       $at, $zero, 0x330
        ctx->r1 = ADD32(0, 0X330);
            goto L_80191C78;
    }
    // 0x80191C30: addiu       $at, $zero, 0x330
    ctx->r1 = ADD32(0, 0X330);
    // 0x80191C34: beq         $v0, $at, L_80191E08
    if (ctx->r2 == ctx->r1) {
        // 0x80191C38: addiu       $at, $zero, 0x3D5
        ctx->r1 = ADD32(0, 0X3D5);
            goto L_80191E08;
    }
    // 0x80191C38: addiu       $at, $zero, 0x3D5
    ctx->r1 = ADD32(0, 0X3D5);
    // 0x80191C3C: beq         $v0, $at, L_80191CC0
    if (ctx->r2 == ctx->r1) {
        // 0x80191C40: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80191CC0;
    }
    // 0x80191C40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80191C44: addiu       $at, $zero, 0x47E
    ctx->r1 = ADD32(0, 0X47E);
    // 0x80191C48: beq         $v0, $at, L_80191E4C
    if (ctx->r2 == ctx->r1) {
        // 0x80191C4C: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_80191E4C;
    }
    // 0x80191C4C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80191C50: addiu       $at, $zero, 0x49D
    ctx->r1 = ADD32(0, 0X49D);
    // 0x80191C54: beq         $v0, $at, L_80191CCC
    if (ctx->r2 == ctx->r1) {
        // 0x80191C58: addiu       $at, $zero, 0x4A6
        ctx->r1 = ADD32(0, 0X4A6);
            goto L_80191CCC;
    }
    // 0x80191C58: addiu       $at, $zero, 0x4A6
    ctx->r1 = ADD32(0, 0X4A6);
    // 0x80191C5C: beq         $v0, $at, L_80191EAC
    if (ctx->r2 == ctx->r1) {
        // 0x80191C60: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_80191EAC;
    }
    // 0x80191C60: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80191C64: addiu       $at, $zero, 0x4CE
    ctx->r1 = ADD32(0, 0X4CE);
    // 0x80191C68: beq         $v0, $at, L_80191F0C
    if (ctx->r2 == ctx->r1) {
        // 0x80191C6C: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_80191F0C;
    }
    // 0x80191C6C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80191C70: b           L_80191F6C
    // 0x80191C74: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191C74: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191C78:
    // 0x80191C78: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80191C7C: beq         $v0, $at, L_80191CD8
    if (ctx->r2 == ctx->r1) {
        // 0x80191C80: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80191CD8;
    }
    // 0x80191C80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80191C84: addiu       $at, $zero, 0x14A
    ctx->r1 = ADD32(0, 0X14A);
    // 0x80191C88: beq         $v0, $at, L_80191CF0
    if (ctx->r2 == ctx->r1) {
        // 0x80191C8C: addiu       $t3, $zero, 0x64
        ctx->r11 = ADD32(0, 0X64);
            goto L_80191CF0;
    }
    // 0x80191C8C: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80191C90: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x80191C94: beq         $v0, $at, L_80191D6C
    if (ctx->r2 == ctx->r1) {
        // 0x80191C98: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80191D6C;
    }
    // 0x80191C98: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191C9C: addiu       $at, $zero, 0x1D6
    ctx->r1 = ADD32(0, 0X1D6);
    // 0x80191CA0: beq         $v0, $at, L_80191CFC
    if (ctx->r2 == ctx->r1) {
        // 0x80191CA4: addiu       $at, $zero, 0x226
        ctx->r1 = ADD32(0, 0X226);
            goto L_80191CFC;
    }
    // 0x80191CA4: addiu       $at, $zero, 0x226
    ctx->r1 = ADD32(0, 0X226);
    // 0x80191CA8: beq         $v0, $at, L_80191D80
    if (ctx->r2 == ctx->r1) {
        // 0x80191CAC: addiu       $at, $zero, 0x2AA
        ctx->r1 = ADD32(0, 0X2AA);
            goto L_80191D80;
    }
    // 0x80191CAC: addiu       $at, $zero, 0x2AA
    ctx->r1 = ADD32(0, 0X2AA);
    // 0x80191CB0: beq         $v0, $at, L_80191DC4
    if (ctx->r2 == ctx->r1) {
        // 0x80191CB4: nop
    
            goto L_80191DC4;
    }
    // 0x80191CB4: nop

    // 0x80191CB8: b           L_80191F6C
    // 0x80191CBC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191CBC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191CC0:
    // 0x80191CC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191CC4: b           L_80191F68
    // 0x80191CC8: sb          $t2, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r10;
        goto L_80191F68;
    // 0x80191CC8: sb          $t2, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r10;
L_80191CCC:
    // 0x80191CCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191CD0: b           L_80191F68
    // 0x80191CD4: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
        goto L_80191F68;
    // 0x80191CD4: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_80191CD8:
    // 0x80191CD8: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80191CDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80191CE0: jal         0x8001D444
    // 0x80191CE4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_57;
    // 0x80191CE4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_57:
    // 0x80191CE8: b           L_80191F6C
    // 0x80191CEC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191CEC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191CF0:
    // 0x80191CF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191CF4: b           L_80191F68
    // 0x80191CF8: sw          $t3, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r11;
        goto L_80191F68;
    // 0x80191CF8: sw          $t3, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r11;
L_80191CFC:
    // 0x80191CFC: jal         0x800A6148
    // 0x80191D00: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_58;
    // 0x80191D00: nop

    after_58:
    // 0x80191D04: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80191D08: lw          $t4, 0x78B4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78B4);
    // 0x80191D0C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80191D10: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x80191D14: blez        $t4, L_80191D24
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80191D18: nop
    
            goto L_80191D24;
    }
    // 0x80191D18: nop

    // 0x80191D1C: jal         0x80190F74
    // 0x80191D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Corneria_CsLevelComplete1_TeamSetup(rdram, ctx);
        goto after_59;
    // 0x80191D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_59:
L_80191D24:
    // 0x80191D24: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80191D28: lw          $t5, 0x78B8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78B8);
    // 0x80191D2C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80191D30: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x80191D34: blez        $t5, L_80191D44
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80191D38: nop
    
            goto L_80191D44;
    }
    // 0x80191D38: nop

    // 0x80191D3C: jal         0x80190F74
    // 0x80191D40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Corneria_CsLevelComplete1_TeamSetup(rdram, ctx);
        goto after_60;
    // 0x80191D40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_60:
L_80191D44:
    // 0x80191D44: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80191D48: lw          $t6, 0x78BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78BC);
    // 0x80191D4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80191D50: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x80191D54: blezl       $t6, L_80191F6C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80191D58: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80191F6C;
    }
    goto skip_3;
    // 0x80191D58: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_3:
    // 0x80191D5C: jal         0x80190F74
    // 0x80191D60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Corneria_CsLevelComplete1_TeamSetup(rdram, ctx);
        goto after_61;
    // 0x80191D60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_61:
    // 0x80191D64: b           L_80191F6C
    // 0x80191D68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191D68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191D6C:
    // 0x80191D6C: addiu       $a0, $a0, -0x47B8
    ctx->r4 = ADD32(ctx->r4, -0X47B8);
    // 0x80191D70: jal         0x800BA808
    // 0x80191D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_62;
    // 0x80191D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_62:
    // 0x80191D78: b           L_80191F6C
    // 0x80191D7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191D7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191D80:
    // 0x80191D80: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191D84: lw          $v0, 0x78B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B8);
    // 0x80191D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80191D8C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191D90: beq         $v0, $at, L_80191DA0
    if (ctx->r2 == ctx->r1) {
        // 0x80191D94: addiu       $a0, $a0, 0x4A4C
        ctx->r4 = ADD32(ctx->r4, 0X4A4C);
            goto L_80191DA0;
    }
    // 0x80191D94: addiu       $a0, $a0, 0x4A4C
    ctx->r4 = ADD32(ctx->r4, 0X4A4C);
    // 0x80191D98: bne         $v0, $zero, L_80191DB0
    if (ctx->r2 != 0) {
        // 0x80191D9C: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80191DB0;
    }
    // 0x80191D9C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80191DA0:
    // 0x80191DA0: jal         0x800BA808
    // 0x80191DA4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_63;
    // 0x80191DA4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_63:
    // 0x80191DA8: b           L_80191F6C
    // 0x80191DAC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191DAC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191DB0:
    // 0x80191DB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191DB4: jal         0x800BA808
    // 0x80191DB8: addiu       $a0, $a0, -0x48D0
    ctx->r4 = ADD32(ctx->r4, -0X48D0);
    Radio_PlayMessage(rdram, ctx);
        goto after_64;
    // 0x80191DB8: addiu       $a0, $a0, -0x48D0
    ctx->r4 = ADD32(ctx->r4, -0X48D0);
    after_64:
    // 0x80191DBC: b           L_80191F6C
    // 0x80191DC0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191DC0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191DC4:
    // 0x80191DC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191DC8: lw          $v0, 0x78BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78BC);
    // 0x80191DCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80191DD0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191DD4: beq         $v0, $at, L_80191DE4
    if (ctx->r2 == ctx->r1) {
        // 0x80191DD8: addiu       $a0, $a0, 0x4A04
        ctx->r4 = ADD32(ctx->r4, 0X4A04);
            goto L_80191DE4;
    }
    // 0x80191DD8: addiu       $a0, $a0, 0x4A04
    ctx->r4 = ADD32(ctx->r4, 0X4A04);
    // 0x80191DDC: bne         $v0, $zero, L_80191DF4
    if (ctx->r2 != 0) {
        // 0x80191DE0: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_80191DF4;
    }
    // 0x80191DE0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
L_80191DE4:
    // 0x80191DE4: jal         0x800BA808
    // 0x80191DE8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_65;
    // 0x80191DE8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_65:
    // 0x80191DEC: b           L_80191F6C
    // 0x80191DF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191DF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191DF4:
    // 0x80191DF4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191DF8: jal         0x800BA808
    // 0x80191DFC: addiu       $a0, $a0, -0x4858
    ctx->r4 = ADD32(ctx->r4, -0X4858);
    Radio_PlayMessage(rdram, ctx);
        goto after_66;
    // 0x80191DFC: addiu       $a0, $a0, -0x4858
    ctx->r4 = ADD32(ctx->r4, -0X4858);
    after_66:
    // 0x80191E00: b           L_80191F6C
    // 0x80191E04: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191E04: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191E08:
    // 0x80191E08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191E0C: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x80191E10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80191E14: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191E18: beq         $v0, $at, L_80191E28
    if (ctx->r2 == ctx->r1) {
        // 0x80191E1C: addiu       $a0, $a0, 0x49B8
        ctx->r4 = ADD32(ctx->r4, 0X49B8);
            goto L_80191E28;
    }
    // 0x80191E1C: addiu       $a0, $a0, 0x49B8
    ctx->r4 = ADD32(ctx->r4, 0X49B8);
    // 0x80191E20: bne         $v0, $zero, L_80191E38
    if (ctx->r2 != 0) {
        // 0x80191E24: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80191E38;
    }
    // 0x80191E24: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_80191E28:
    // 0x80191E28: jal         0x800BA808
    // 0x80191E2C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_67;
    // 0x80191E2C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_67:
    // 0x80191E30: b           L_80191F6C
    // 0x80191E34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191E34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191E38:
    // 0x80191E38: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191E3C: jal         0x800BA808
    // 0x80191E40: addiu       $a0, $a0, -0x4804
    ctx->r4 = ADD32(ctx->r4, -0X4804);
    Radio_PlayMessage(rdram, ctx);
        goto after_68;
    // 0x80191E40: addiu       $a0, $a0, -0x4804
    ctx->r4 = ADD32(ctx->r4, -0X4804);
    after_68:
    // 0x80191E44: b           L_80191F6C
    // 0x80191E48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80191F6C;
    // 0x80191E48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191E4C:
    // 0x80191E4C: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x80191E50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80191E54: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80191E58: blez        $t7, L_80191F68
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80191E5C: addiu       $t9, $zero, 0x32
        ctx->r25 = ADD32(0, 0X32);
            goto L_80191F68;
    }
    // 0x80191E5C: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80191E60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191E64: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80191E68: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80191E6C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80191E70: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80191E74: sh          $t8, 0xB8($t0)
    MEM_H(0XB8, ctx->r8) = ctx->r24;
    // 0x80191E78: sh          $t9, 0xBC($t0)
    MEM_H(0XBC, ctx->r8) = ctx->r25;
    // 0x80191E7C: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x80191E80: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80191E84: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80191E88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80191E8C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191E90: jal         0x80019218
    // 0x80191E94: swc1        $f4, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->f4.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_69;
    // 0x80191E94: swc1        $f4, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->f4.u32l;
    after_69:
    // 0x80191E98: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80191E9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191EA0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191EA4: b           L_80191F68
    // 0x80191EA8: swc1        $f6, 0x4168($at)
    MEM_W(0X4168, ctx->r1) = ctx->f6.u32l;
        goto L_80191F68;
    // 0x80191EA8: swc1        $f6, 0x4168($at)
    MEM_W(0X4168, ctx->r1) = ctx->f6.u32l;
L_80191EAC:
    // 0x80191EAC: lw          $t2, 0x78B8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78B8);
    // 0x80191EB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80191EB4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80191EB8: blez        $t2, L_80191F68
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80191EBC: addiu       $t4, $zero, 0x32
        ctx->r12 = ADD32(0, 0X32);
            goto L_80191F68;
    }
    // 0x80191EBC: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80191EC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191EC4: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80191EC8: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80191ECC: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80191ED0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80191ED4: sh          $t3, 0x3AC($t0)
    MEM_H(0X3AC, ctx->r8) = ctx->r11;
    // 0x80191ED8: sh          $t4, 0x3B0($t0)
    MEM_H(0X3B0, ctx->r8) = ctx->r12;
    // 0x80191EDC: addiu       $a1, $a1, 0x43D4
    ctx->r5 = ADD32(ctx->r5, 0X43D4);
    // 0x80191EE0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80191EE4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80191EE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80191EEC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191EF0: jal         0x80019218
    // 0x80191EF4: swc1        $f8, 0x42C($t0)
    MEM_W(0X42C, ctx->r8) = ctx->f8.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_70;
    // 0x80191EF4: swc1        $f8, 0x42C($t0)
    MEM_W(0X42C, ctx->r8) = ctx->f8.u32l;
    after_70:
    // 0x80191EF8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80191EFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191F00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191F04: b           L_80191F68
    // 0x80191F08: swc1        $f10, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = ctx->f10.u32l;
        goto L_80191F68;
    // 0x80191F08: swc1        $f10, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = ctx->f10.u32l;
L_80191F0C:
    // 0x80191F0C: lw          $t6, 0x78BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78BC);
    // 0x80191F10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80191F14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80191F18: blez        $t6, L_80191F68
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80191F1C: addiu       $t8, $zero, 0x32
        ctx->r24 = ADD32(0, 0X32);
            goto L_80191F68;
    }
    // 0x80191F1C: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80191F20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191F24: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80191F28: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80191F2C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80191F30: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80191F34: sh          $t7, 0x6A0($t0)
    MEM_H(0X6A0, ctx->r8) = ctx->r15;
    // 0x80191F38: sh          $t8, 0x6A4($t0)
    MEM_H(0X6A4, ctx->r8) = ctx->r24;
    // 0x80191F3C: addiu       $a1, $a1, 0x46C8
    ctx->r5 = ADD32(ctx->r5, 0X46C8);
    // 0x80191F40: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80191F44: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80191F48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80191F4C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191F50: jal         0x80019218
    // 0x80191F54: swc1        $f18, 0x720($t0)
    MEM_W(0X720, ctx->r8) = ctx->f18.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_71;
    // 0x80191F54: swc1        $f18, 0x720($t0)
    MEM_W(0X720, ctx->r8) = ctx->f18.u32l;
    after_71:
    // 0x80191F58: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80191F5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191F60: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191F64: swc1        $f4, 0x4750($at)
    MEM_W(0X4750, ctx->r1) = ctx->f4.u32l;
L_80191F68:
    // 0x80191F68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80191F6C:
    // 0x80191F6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191F70: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80191F74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191F78: lwc1        $f18, -0x4D70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4D70);
    // 0x80191F7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80191F80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191F84: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191F88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80191F8C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80191F90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80191F94: jal         0x80005E90
    // 0x80191F98: nop

    Matrix_RotateY(rdram, ctx);
        goto after_72;
    // 0x80191F98: nop

    after_72:
    // 0x80191F9C: lwc1        $f6, 0xE4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80191FA0: lwc1        $f8, 0x4D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x80191FA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191FA8: lwc1        $f18, -0x4D6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4D6C);
    // 0x80191FAC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80191FB0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191FB4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191FBC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80191FC0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80191FC4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80191FC8: jal         0x80005D44
    // 0x80191FCC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_73;
    // 0x80191FCC: nop

    after_73:
    // 0x80191FD0: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x80191FD4: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80191FD8: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80191FDC: lwc1        $f8, 0xD0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80191FE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191FE4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191FE8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80191FEC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80191FF0: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80191FF4: jal         0x80006A20
    // 0x80191FF8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_74;
    // 0x80191FF8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_74:
    // 0x80191FFC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80192000: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80192004: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80192008: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x8019200C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80192010: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80192014: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80192018: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019201C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80192020: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80192024: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80192028: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8019202C: swc1        $f4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f4.u32l;
    // 0x80192030: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80192034: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80192038: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019203C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80192040: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x80192044: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80192048: lwc1        $f18, 0x12C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8019204C: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x80192050: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80192054: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80192058: lwc1        $f6, 0x130($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8019205C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80192060: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80192064: swc1        $f8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f8.u32l;
    // 0x80192068: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019206C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192070: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80192074: swc1        $f8, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f8.u32l;
    // 0x80192078: swc1        $f4, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f4.u32l;
    // 0x8019207C: lwc1        $f8, -0x4D68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4D68);
    // 0x80192080: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80192084: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80192088: jal         0x80023090
    // 0x8019208C: nop

    __sinf_recomp(rdram, ctx);
        goto after_75;
    // 0x8019208C: nop

    after_75:
    // 0x80192090: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192094: lwc1        $f18, -0x4D64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4D64);
    // 0x80192098: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8019209C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801920A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801920A4: lwc1        $f6, 0xF4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801920A8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801920AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801920B0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801920B4: swc1        $f10, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f10.u32l;
    // 0x801920B8: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
    // 0x801920BC: lwc1        $f4, -0x4D60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4D60);
    // 0x801920C0: lwc1        $f18, 0xF4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801920C4: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801920C8: jal         0x80023090
    // 0x801920CC: nop

    __sinf_recomp(rdram, ctx);
        goto after_76;
    // 0x801920CC: nop

    after_76:
    // 0x801920D0: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x801920D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801920D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801920DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801920E0: jr          $ra
    // 0x801920E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801920E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Corneria_CoGranga_ShootLaser(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801877A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801877A4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801877A8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801877AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801877B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801877B4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801877B8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801877BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801877C0: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x801877C4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x801877C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801877CC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801877D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x801877D4: jal         0x80006A20
    // 0x801877D8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_0;
    // 0x801877D8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801877DC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x801877E0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801877E4: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801877E8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801877EC: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801877F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801877F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801877F8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801877FC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80187800: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80187804: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80187808: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018780C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80187810: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80187814: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x80187818: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8018781C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80187820: jal         0x8007F11C
    // 0x80187824: nop

    Effect_ShootAtPlayer(rdram, ctx);
        goto after_1;
    // 0x80187824: nop

    after_1:
    // 0x80187828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018782C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80187830: jr          $ra
    // 0x80187834: nop

    return;
    // 0x80187834: nop

;}
RECOMP_FUNC void Corneria_CoGaruda2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BBA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018BBA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018BBAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018BBB0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8018BBB4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8018BBB8: lw          $t8, -0x4438($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4438);
    // 0x8018BBBC: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018BBC0: addiu       $t7, $t7, -0x4504
    ctx->r15 = ADD32(ctx->r15, -0X4504);
    // 0x8018BBC4: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8018BBC8: addiu       $a1, $a1, -0x65B8
    ctx->r5 = ADD32(ctx->r5, -0X65B8);
    // 0x8018BBCC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018BBD0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018BBD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8018BBD8: addiu       $a2, $t6, 0x18C
    ctx->r6 = ADD32(ctx->r14, 0X18C);
    // 0x8018BBDC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018BBE0: jal         0x8009A72C
    // 0x8018BBE4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_0;
    // 0x8018BBE4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x8018BBE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018BBEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018BBF0: jr          $ra
    // 0x8018BBF4: nop

    return;
    // 0x8018BBF4: nop

;}
RECOMP_FUNC void Venom1_Ve1MonkeyStatue_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801933B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801933B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801933BC: lui         $at, 0x43F4
    ctx->r1 = S32(0X43F4 << 16);
    // 0x801933C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801933C4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801933C8: swc1        $f4, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f4.u32l;
    // 0x801933CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801933D0: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x801933D4: jr          $ra
    // 0x801933D8: nop

    return;
    // 0x801933D8: nop

;}
RECOMP_FUNC void Corneria_CoGarudaDestroy_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BD7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018BD80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018BD84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018BD88: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8018BD8C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8018BD90: lw          $t8, -0x4438($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4438);
    // 0x8018BD94: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018BD98: addiu       $t7, $t7, -0x437C
    ctx->r15 = ADD32(ctx->r15, -0X437C);
    // 0x8018BD9C: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8018BDA0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018BDA4: addiu       $a3, $a3, -0x43B0
    ctx->r7 = ADD32(ctx->r7, -0X43B0);
    // 0x8018BDA8: addiu       $a1, $a1, -0x65B8
    ctx->r5 = ADD32(ctx->r5, -0X65B8);
    // 0x8018BDAC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018BDB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018BDB4: addiu       $a2, $t6, 0x18C
    ctx->r6 = ADD32(ctx->r14, 0X18C);
    // 0x8018BDB8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018BDBC: jal         0x8009A72C
    // 0x8018BDC0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_0;
    // 0x8018BDC0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x8018BDC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018BDC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018BDCC: jr          $ra
    // 0x8018BDD0: nop

    return;
    // 0x8018BDD0: nop

;}
RECOMP_FUNC void Corneria_8018798C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018798C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80187990: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80187994: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80187998: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018799C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801879A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801879A4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801879A8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801879AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801879B0: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801879B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801879B8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801879BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801879C0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801879C4: jal         0x8007BFFC
    // 0x801879C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_0;
    // 0x801879C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801879CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801879D0: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x801879D4: ori         $a1, $a1, 0x4003
    ctx->r5 = ctx->r5 | 0X4003;
    // 0x801879D8: jal         0x8007A6F0
    // 0x801879DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_1;
    // 0x801879DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x801879E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801879E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801879E8: jr          $ra
    // 0x801879EC: nop

    return;
    // 0x801879EC: nop

;}
RECOMP_FUNC void Corneria_CoSmoke_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801875A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801875A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801875AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801875B0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801875B4: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x801875B8: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x801875BC: bnel        $t7, $zero, L_80187664
    if (ctx->r15 != 0) {
        // 0x801875C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80187664;
    }
    goto skip_0;
    // 0x801875C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801875C4: jal         0x80004EB0
    // 0x801875C8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801875C8: nop

    after_0:
    // 0x801875CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801875D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801875D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801875D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801875DC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801875E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801875E4: jal         0x80004EB0
    // 0x801875E8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801875E8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801875EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801875F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801875F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801875F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801875FC: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80187600: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80187604: jal         0x80004EB0
    // 0x80187608: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80187608: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8018760C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80187610: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80187614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80187618: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018761C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80187620: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80187624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187628: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018762C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80187630: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80187634: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80187638: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8018763C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80187640: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80187644: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80187648: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018764C: nop

    // 0x80187650: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80187654: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80187658: jal         0x8007C85C
    // 0x8018765C: nop

    Effect_Effect343_Spawn(rdram, ctx);
        goto after_3;
    // 0x8018765C: nop

    after_3:
    // 0x80187660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80187664:
    // 0x80187664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80187668: jr          $ra
    // 0x8018766C: nop

    return;
    // 0x8018766C: nop

;}
RECOMP_FUNC void Venom1_80193D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193D64: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80193D68: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80193D6C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80193D70: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80193D74: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80193D78: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80193D7C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80193D80: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80193D84: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80193D88: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80193D8C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80193D90: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80193D94: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80193D98: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80193D9C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80193DA0: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x80193DA4: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x80193DA8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80193DAC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80193DB0: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x80193DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80193DB8: lw          $s0, 0x28($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X28);
    // 0x80193DBC: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80193DC0: addiu       $v0, $v0, -0x5B88
    ctx->r2 = ADD32(ctx->r2, -0X5B88);
    // 0x80193DC4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80193DC8: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x80193DCC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80193DD0:
    // 0x80193DD0: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80193DD4: lh          $s3, 0x4($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X4);
    // 0x80193DD8: bnel        $a3, $t7, L_80193EA4
    if (ctx->r7 != ctx->r15) {
        // 0x80193DDC: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_80193EA4;
    }
    goto skip_0;
    // 0x80193DDC: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_0:
    // 0x80193DE0: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80193DE4: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x80193DE8: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x80193DEC: sll         $t9, $t8, 7
    ctx->r25 = S32(ctx->r24 << 7);
    // 0x80193DF0: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80193DF4: lh          $v1, -0x47C8($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X47C8);
    // 0x80193DF8: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x80193DFC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80193E00: slt         $t0, $zero, $v1
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80193E04: beq         $t0, $zero, L_80193E20
    if (ctx->r8 == 0) {
        // 0x80193E08: sll         $t3, $a0, 4
        ctx->r11 = S32(ctx->r4 << 4);
            goto L_80193E20;
    }
    // 0x80193E08: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x80193E0C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80193E10: addiu       $t2, $t2, -0x5FA8
    ctx->r10 = ADD32(ctx->r10, -0X5FA8);
    // 0x80193E14: sll         $t1, $a0, 4
    ctx->r9 = S32(ctx->r4 << 4);
    // 0x80193E18: b           L_80193E28
    // 0x80193E1C: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
        goto L_80193E28;
    // 0x80193E1C: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
L_80193E20:
    // 0x80193E20: addiu       $t4, $t4, -0x5D98
    ctx->r12 = ADD32(ctx->r12, -0X5D98);
    // 0x80193E24: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
L_80193E28:
    // 0x80193E28: blez        $s3, L_80193E94
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80193E2C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80193E94;
    }
    // 0x80193E2C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80193E30: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80193E34: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x80193E38: sw          $a3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r7;
    // 0x80193E3C: addiu       $s5, $sp, 0xAC
    ctx->r21 = ADD32(ctx->r29, 0XAC);
L_80193E40:
    // 0x80193E40: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80193E44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80193E48: jal         0x80006970
    // 0x80193E4C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x80193E4C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x80193E50: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80193E54: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80193E58: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80193E5C: swc1        $f6, -0x18($s0)
    MEM_W(-0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80193E60: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80193E64: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80193E68: swc1        $f8, -0x14($s0)
    MEM_W(-0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80193E6C: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80193E70: swc1        $f10, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80193E74: lwc1        $f16, -0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X4);
    // 0x80193E78: swc1        $f16, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80193E7C: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80193E80: swc1        $f18, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80193E84: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x80193E88: bne         $s4, $s3, L_80193E40
    if (ctx->r20 != ctx->r19) {
        // 0x80193E8C: swc1        $f4, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f4.u32l;
            goto L_80193E40;
    }
    // 0x80193E8C: swc1        $f4, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80193E90: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
L_80193E94:
    // 0x80193E94: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80193E98: b           L_80193ED8
    // 0x80193E9C: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
        goto L_80193ED8;
    // 0x80193E9C: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x80193EA0: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_80193EA4:
    // 0x80193EA4: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
    // 0x80193EA8: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80193EAC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80193EB0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80193EB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80193EB8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80193EBC: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x80193EC0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80193EC4: bne         $t0, $at, L_80193DD0
    if (ctx->r8 != ctx->r1) {
        // 0x80193EC8: addu        $s0, $s0, $t8
        ctx->r16 = ADD32(ctx->r16, ctx->r24);
            goto L_80193DD0;
    }
    // 0x80193EC8: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80193ECC: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80193ED0: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x80193ED4: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_80193ED8:
    // 0x80193ED8: lui         $s6, 0x801A
    ctx->r22 = S32(0X801A << 16);
    // 0x80193EDC: lui         $s7, 0x801A
    ctx->r23 = S32(0X801A << 16);
    // 0x80193EE0: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x80193EE4: addiu       $s6, $s6, -0x57E0
    ctx->r22 = ADD32(ctx->r22, -0X57E0);
    // 0x80193EE8: addiu       $s7, $s7, -0x47C8
    ctx->r23 = ADD32(ctx->r23, -0X47C8);
    // 0x80193EEC: addiu       $s3, $s3, -0x60D4
    ctx->r19 = ADD32(ctx->r19, -0X60D4);
    // 0x80193EF0: sw          $a3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r7;
    // 0x80193EF4: addiu       $fp, $zero, -0x21
    ctx->r30 = ADD32(0, -0X21);
    // 0x80193EF8: addiu       $s5, $zero, -0x9
    ctx->r21 = ADD32(0, -0X9);
L_80193EFC:
    // 0x80193EFC: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x80193F00: lh          $t3, 0x0($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X0);
    // 0x80193F04: bnel        $t2, $t3, L_80194010
    if (ctx->r10 != ctx->r11) {
        // 0x80193F08: lw          $t6, 0xBC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XBC);
            goto L_80194010;
    }
    goto skip_1;
    // 0x80193F08: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    skip_1:
    // 0x80193F0C: lhu         $v0, 0x7C($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X7C);
    // 0x80193F10: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    // 0x80193F14: beql        $t4, $zero, L_80193F8C
    if (ctx->r12 == 0) {
        // 0x80193F18: andi        $t2, $v0, 0x20
        ctx->r10 = ctx->r2 & 0X20;
            goto L_80193F8C;
    }
    goto skip_2;
    // 0x80193F18: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    skip_2:
    // 0x80193F1C: lh          $t5, 0x6($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X6);
    // 0x80193F20: lh          $v1, 0x4($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X4);
    // 0x80193F24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80193F28: blez        $t5, L_80193F74
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80193F2C: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80193F74;
    }
    // 0x80193F2C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80193F30: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80193F34: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80193F38: addiu       $t7, $t7, -0x5ABC
    ctx->r15 = ADD32(ctx->r15, -0X5ABC);
    // 0x80193F3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80193F40: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80193F44: addiu       $s0, $s7, 0xC
    ctx->r16 = ADD32(ctx->r23, 0XC);
L_80193F48:
    // 0x80193F48: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80193F4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80193F50: jal         0x80006970
    // 0x80193F54: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x80193F54: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80193F58: lh          $t8, 0x6($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X6);
    // 0x80193F5C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80193F60: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80193F64: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80193F68: bne         $at, $zero, L_80193F48
    if (ctx->r1 != 0) {
        // 0x80193F6C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80193F48;
    }
    // 0x80193F6C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80193F70: lhu         $v0, 0x7C($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X7C);
L_80193F74:
    // 0x80193F74: and         $t0, $v0, $s5
    ctx->r8 = ctx->r2 & ctx->r21;
    // 0x80193F78: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80193F7C: sh          $t0, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r8;
    // 0x80193F80: sh          $t1, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r9;
    // 0x80193F84: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x80193F88: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
L_80193F8C:
    // 0x80193F8C: beq         $t2, $zero, L_80193FC4
    if (ctx->r10 == 0) {
        // 0x80193F90: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80193FC4;
    }
    // 0x80193F90: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80193F94: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80193F98: jal         0x80006970
    // 0x80193F9C: addiu       $a2, $s7, 0xC
    ctx->r6 = ADD32(ctx->r23, 0XC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80193F9C: addiu       $a2, $s7, 0xC
    ctx->r6 = ADD32(ctx->r23, 0XC);
    after_2:
    // 0x80193FA0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80193FA4: jal         0x80006AB8
    // 0x80193FA8: addiu       $a1, $s7, 0x30
    ctx->r5 = ADD32(ctx->r23, 0X30);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_3;
    // 0x80193FA8: addiu       $a1, $s7, 0x30
    ctx->r5 = ADD32(ctx->r23, 0X30);
    after_3:
    // 0x80193FAC: lhu         $t3, 0x7C($s7)
    ctx->r11 = MEM_HU(ctx->r23, 0X7C);
    // 0x80193FB0: and         $t5, $t3, $fp
    ctx->r13 = ctx->r11 & ctx->r30;
    // 0x80193FB4: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x80193FB8: sh          $t5, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r13;
    // 0x80193FBC: sh          $t6, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r14;
    // 0x80193FC0: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
L_80193FC4:
    // 0x80193FC4: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80193FC8: beq         $t7, $zero, L_80193FE0
    if (ctx->r15 == 0) {
        // 0x80193FCC: andi        $t9, $v0, 0xFEFF
        ctx->r25 = ctx->r2 & 0XFEFF;
            goto L_80193FE0;
    }
    // 0x80193FCC: andi        $t9, $v0, 0xFEFF
    ctx->r25 = ctx->r2 & 0XFEFF;
    // 0x80193FD0: ori         $t0, $t9, 0x200
    ctx->r8 = ctx->r25 | 0X200;
    // 0x80193FD4: sh          $t9, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r25;
    // 0x80193FD8: sh          $t0, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r8;
    // 0x80193FDC: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
L_80193FE0:
    // 0x80193FE0: andi        $t1, $v0, 0x800
    ctx->r9 = ctx->r2 & 0X800;
    // 0x80193FE4: beq         $t1, $zero, L_8019400C
    if (ctx->r9 == 0) {
        // 0x80193FE8: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_8019400C;
    }
    // 0x80193FE8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80193FEC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80193FF0: jal         0x80006970
    // 0x80193FF4: addiu       $a2, $s7, 0x18
    ctx->r6 = ADD32(ctx->r23, 0X18);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x80193FF4: addiu       $a2, $s7, 0x18
    ctx->r6 = ADD32(ctx->r23, 0X18);
    after_4:
    // 0x80193FF8: lhu         $t2, 0x7C($s7)
    ctx->r10 = MEM_HU(ctx->r23, 0X7C);
    // 0x80193FFC: andi        $t4, $t2, 0xF7FF
    ctx->r12 = ctx->r10 & 0XF7FF;
    // 0x80194000: sh          $t4, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r12;
    // 0x80194004: ori         $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 | 0X1000;
    // 0x80194008: sh          $t5, 0x7C($s7)
    MEM_H(0X7C, ctx->r23) = ctx->r13;
L_8019400C:
    // 0x8019400C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
L_80194010:
    // 0x80194010: addiu       $s6, $s6, 0x18
    ctx->r22 = ADD32(ctx->r22, 0X18);
    // 0x80194014: addiu       $s7, $s7, 0x80
    ctx->r23 = ADD32(ctx->r23, 0X80);
    // 0x80194018: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8019401C: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x80194020: bne         $at, $zero, L_80193EFC
    if (ctx->r1 != 0) {
        // 0x80194024: sw          $t7, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r15;
            goto L_80193EFC;
    }
    // 0x80194024: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80194028: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8019402C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80194030: beq         $t9, $at, L_80194054
    if (ctx->r25 == ctx->r1) {
        // 0x80194034: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80194054;
    }
    // 0x80194034: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80194038: beq         $t9, $at, L_80194090
    if (ctx->r25 == ctx->r1) {
        // 0x8019403C: lw          $t6, 0xC8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XC8);
            goto L_80194090;
    }
    // 0x8019403C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80194040: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80194044: beq         $t9, $at, L_801940C4
    if (ctx->r25 == ctx->r1) {
        // 0x80194048: lw          $v0, 0xC8($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XC8);
            goto L_801940C4;
    }
    // 0x80194048: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x8019404C: b           L_801940F4
    // 0x80194050: nop

        goto L_801940F4;
    // 0x80194050: nop

L_80194054:
    // 0x80194054: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x80194058: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019405C: addiu       $a1, $a1, -0x52A4
    ctx->r5 = ADD32(ctx->r5, -0X52A4);
    // 0x80194060: lh          $t1, 0x9E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X9E);
    // 0x80194064: addiu       $a2, $t0, 0xE4
    ctx->r6 = ADD32(ctx->r8, 0XE4);
    // 0x80194068: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8019406C: beq         $t2, $zero, L_801940F4
    if (ctx->r10 == 0) {
        // 0x80194070: nop
    
            goto L_801940F4;
    }
    // 0x80194070: nop

    // 0x80194074: jal         0x80006970
    // 0x80194078: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x80194078: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_5:
    // 0x8019407C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x80194080: lh          $t4, 0x9E($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X9E);
    // 0x80194084: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80194088: b           L_801940F4
    // 0x8019408C: sh          $t5, 0x9E($t3)
    MEM_H(0X9E, ctx->r11) = ctx->r13;
        goto L_801940F4;
    // 0x8019408C: sh          $t5, 0x9E($t3)
    MEM_H(0X9E, ctx->r11) = ctx->r13;
L_80194090:
    // 0x80194090: lh          $t7, 0x9E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X9E);
    // 0x80194094: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80194098: addiu       $a1, $a1, -0x52A4
    ctx->r5 = ADD32(ctx->r5, -0X52A4);
    // 0x8019409C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x801940A0: beq         $t8, $zero, L_801940F4
    if (ctx->r24 == 0) {
        // 0x801940A4: addiu       $a2, $t6, 0xE4
        ctx->r6 = ADD32(ctx->r14, 0XE4);
            goto L_801940F4;
    }
    // 0x801940A4: addiu       $a2, $t6, 0xE4
    ctx->r6 = ADD32(ctx->r14, 0XE4);
    // 0x801940A8: jal         0x80006970
    // 0x801940AC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x801940AC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_6:
    // 0x801940B0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x801940B4: lh          $t1, 0x9E($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X9E);
    // 0x801940B8: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x801940BC: b           L_801940F4
    // 0x801940C0: sh          $t2, 0x9E($t9)
    MEM_H(0X9E, ctx->r25) = ctx->r10;
        goto L_801940F4;
    // 0x801940C0: sh          $t2, 0x9E($t9)
    MEM_H(0X9E, ctx->r25) = ctx->r10;
L_801940C4:
    // 0x801940C4: lh          $t0, 0x9E($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X9E);
    // 0x801940C8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801940CC: addiu       $a1, $a1, -0x51C8
    ctx->r5 = ADD32(ctx->r5, -0X51C8);
    // 0x801940D0: andi        $t4, $t0, 0x4
    ctx->r12 = ctx->r8 & 0X4;
    // 0x801940D4: beq         $t4, $zero, L_801940F4
    if (ctx->r12 == 0) {
        // 0x801940D8: addiu       $a2, $v0, 0xE4
        ctx->r6 = ADD32(ctx->r2, 0XE4);
            goto L_801940F4;
    }
    // 0x801940D8: addiu       $a2, $v0, 0xE4
    ctx->r6 = ADD32(ctx->r2, 0XE4);
    // 0x801940DC: jal         0x80006970
    // 0x801940E0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x801940E0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_7:
    // 0x801940E4: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x801940E8: lh          $t3, 0x9E($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X9E);
    // 0x801940EC: andi        $t7, $t3, 0xFFFB
    ctx->r15 = ctx->r11 & 0XFFFB;
    // 0x801940F0: sh          $t7, 0x9E($t5)
    MEM_H(0X9E, ctx->r13) = ctx->r15;
L_801940F4:
    // 0x801940F4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801940F8: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x801940FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194100: jal         0x800B8DD0
    // 0x80194104: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x80194104: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_8:
    // 0x80194108: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019410C: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x80194110: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x80194114: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80194118: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8019411C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80194120: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80194124: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80194128: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019412C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80194130: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80194134: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80194138: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019413C: lui         $s6, 0x801A
    ctx->r22 = S32(0X801A << 16);
    // 0x80194140: lui         $s7, 0x801A
    ctx->r23 = S32(0X801A << 16);
    // 0x80194144: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80194148: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8019414C: addiu       $s6, $s6, -0x57E0
    ctx->r22 = ADD32(ctx->r22, -0X57E0);
    // 0x80194150: addiu       $s7, $s7, -0x47C8
    ctx->r23 = ADD32(ctx->r23, -0X47C8);
    // 0x80194154: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80194158: lwc1        $f20, -0x4C7C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4C7C);
    // 0x8019415C: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x80194160: lui         $s5, 0xFA00
    ctx->r21 = S32(0XFA00 << 16);
L_80194164:
    // 0x80194164: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x80194168: lh          $t9, 0x0($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X0);
    // 0x8019416C: bnel        $t2, $t9, L_80194334
    if (ctx->r10 != ctx->r25) {
        // 0x80194170: lw          $t4, 0xBC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XBC);
            goto L_80194334;
    }
    goto skip_3;
    // 0x80194170: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    skip_3:
    // 0x80194174: lhu         $t0, 0x7C($s7)
    ctx->r8 = MEM_HU(ctx->r23, 0X7C);
    // 0x80194178: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8019417C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80194180: andi        $t4, $t0, 0x200
    ctx->r12 = ctx->r8 & 0X200;
    // 0x80194184: beql        $t4, $zero, L_80194334
    if (ctx->r12 == 0) {
        // 0x80194188: lw          $t4, 0xBC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XBC);
            goto L_80194334;
    }
    goto skip_4;
    // 0x80194188: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    skip_4:
    // 0x8019418C: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x80194190: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x80194194: andi        $t8, $t5, 0x2
    ctx->r24 = ctx->r13 & 0X2;
    // 0x80194198: bnel        $t8, $zero, L_80194334
    if (ctx->r24 != 0) {
        // 0x8019419C: lw          $t4, 0xBC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XBC);
            goto L_80194334;
    }
    goto skip_5;
    // 0x8019419C: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    skip_5:
    // 0x801941A0: lh          $t6, 0x6($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X6);
    // 0x801941A4: lh          $v1, 0x4($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X4);
    // 0x801941A8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801941AC: blez        $t6, L_80194330
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801941B0: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_80194330;
    }
    // 0x801941B0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x801941B4: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x801941B8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x801941BC: addiu       $t2, $t2, -0x5ABC
    ctx->r10 = ADD32(ctx->r10, -0X5ABC);
    // 0x801941C0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801941C4: lui         $fp, 0x901
    ctx->r30 = S32(0X901 << 16);
    // 0x801941C8: addiu       $fp, $fp, -0x20E0
    ctx->r30 = ADD32(ctx->r30, -0X20E0);
    // 0x801941CC: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
    // 0x801941D0: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
L_801941D4:
    // 0x801941D4: jal         0x80005708
    // 0x801941D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x801941D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x801941DC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801941E0: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801941E4: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801941E8: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801941EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801941F0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801941F4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801941F8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801941FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80194200: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80194204: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80194208: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8019420C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80194210: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80194214: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80194218: jal         0x80005B00
    // 0x8019421C: nop

    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x8019421C: nop

    after_10:
    // 0x80194220: jal         0x8005980C
    // 0x80194224: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_11;
    // 0x80194224: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_11:
    // 0x80194228: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8019422C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80194230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80194234: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80194238: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019423C: jal         0x80005E90
    // 0x80194240: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x80194240: nop

    after_12:
    // 0x80194244: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80194248: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019424C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80194250: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80194254: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80194258: jal         0x80005D44
    // 0x8019425C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x8019425C: nop

    after_13:
    // 0x80194260: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80194264: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80194268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019426C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80194270: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80194274: jal         0x80005FE0
    // 0x80194278: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x80194278: nop

    after_14:
    // 0x8019427C: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80194280: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80194284: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80194288: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019428C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80194290: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80194294: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80194298: nop

    // 0x8019429C: andi        $t3, $t4, 0x1
    ctx->r11 = ctx->r12 & 0X1;
    // 0x801942A0: beql        $t3, $zero, L_801942CC
    if (ctx->r11 == 0) {
        // 0x801942A4: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_801942CC;
    }
    goto skip_6;
    // 0x801942A4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_6:
    // 0x801942A8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x801942AC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801942B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801942B4: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x801942B8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801942BC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x801942C0: b           L_801942E8
    // 0x801942C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
        goto L_801942E8;
    // 0x801942C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801942C8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_801942CC:
    // 0x801942CC: lui         $t6, 0x6060
    ctx->r14 = S32(0X6060 << 16);
    // 0x801942D0: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x801942D4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801942D8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x801942DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801942E0: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x801942E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_801942E8:
    // 0x801942E8: jal         0x80005C34
    // 0x801942EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Matrix_Scale(rdram, ctx);
        goto after_15;
    // 0x801942EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_15:
    // 0x801942F0: jal         0x80006EB8
    // 0x801942F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x801942F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x801942F8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x801942FC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80194300: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80194304: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80194308: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x8019430C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80194310: jal         0x80005740
    // 0x80194314: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x80194314: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80194318: lh          $t0, 0x6($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X6);
    // 0x8019431C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80194320: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80194324: slt         $at, $s4, $t0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80194328: bne         $at, $zero, L_801941D4
    if (ctx->r1 != 0) {
        // 0x8019432C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_801941D4;
    }
    // 0x8019432C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80194330:
    // 0x80194330: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
L_80194334:
    // 0x80194334: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80194338: addiu       $s6, $s6, 0x18
    ctx->r22 = ADD32(ctx->r22, 0X18);
    // 0x8019433C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80194340: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x80194344: bne         $t3, $at, L_80194164
    if (ctx->r11 != ctx->r1) {
        // 0x80194348: addiu       $s7, $s7, 0x80
        ctx->r23 = ADD32(ctx->r23, 0X80);
            goto L_80194164;
    }
    // 0x80194348: addiu       $s7, $s7, 0x80
    ctx->r23 = ADD32(ctx->r23, 0X80);
    // 0x8019434C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194350: jal         0x800B8DD0
    // 0x80194354: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_18;
    // 0x80194354: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_18:
    // 0x80194358: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8019435C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80194360: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80194364: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80194368: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8019436C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80194370: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80194374: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80194378: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8019437C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80194380: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80194384: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80194388: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8019438C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80194390: jr          $ra
    // 0x80194394: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80194394: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void Corneria_CoGranga_ChooseMissileTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80188754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80188758: lh          $t6, 0xCE($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XCE);
    // 0x8018875C: addiu       $v0, $zero, 0xBF
    ctx->r2 = ADD32(0, 0XBF);
    // 0x80188760: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80188764: sh          $t7, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r15;
    // 0x80188768: lh          $t8, 0xCE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XCE);
    // 0x8018876C: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x80188770: bne         $at, $zero, L_80188780
    if (ctx->r1 != 0) {
        // 0x80188774: nop
    
            goto L_80188780;
    }
    // 0x80188774: nop

    // 0x80188778: b           L_8018879C
    // 0x8018877C: sh          $zero, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = 0;
        goto L_8018879C;
    // 0x8018877C: sh          $zero, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = 0;
L_80188780:
    // 0x80188780: jal         0x8008AC54
    // 0x80188784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ActorMissileSeek_ModeCheck(rdram, ctx);
        goto after_0;
    // 0x80188784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80188788: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8018878C: beq         $at, $zero, L_8018879C
    if (ctx->r1 == 0) {
        // 0x80188790: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018879C;
    }
    // 0x80188790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80188794: b           L_8018879C
    // 0x80188798: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
        goto L_8018879C;
    // 0x80188798: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
L_8018879C:
    // 0x8018879C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801887A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801887A4: jr          $ra
    // 0x801887A8: nop

    return;
    // 0x801887A8: nop

;}
RECOMP_FUNC void Corneria_CoGranga_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A730: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8018A734: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8018A738: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8018A73C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018A740: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018A744: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018A748: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018A74C: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x8018A750: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8018A754: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8018A758: addiu       $t6, $t6, -0x67EC
    ctx->r14 = ADD32(ctx->r14, -0X67EC);
    // 0x8018A75C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018A760: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8018A764: addiu       $t1, $t1, -0x67E0
    ctx->r9 = ADD32(ctx->r9, -0X67E0);
    // 0x8018A768: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8018A76C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8018A770: addiu       $t0, $sp, 0x68
    ctx->r8 = ADD32(ctx->r29, 0X68);
    // 0x8018A774: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8018A778: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8018A77C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018A780: addiu       $t8, $t8, -0x67D4
    ctx->r24 = ADD32(ctx->r24, -0X67D4);
    // 0x8018A784: addiu       $t5, $sp, 0x5C
    ctx->r13 = ADD32(ctx->r29, 0X5C);
    // 0x8018A788: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8018A78C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8018A790: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x8018A794: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8018A798: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8018A79C: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x8018A7A0: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x8018A7A4: addiu       $t2, $t2, -0x67C8
    ctx->r10 = ADD32(ctx->r10, -0X67C8);
    // 0x8018A7A8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x8018A7AC: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8018A7B0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8018A7B4: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x8018A7B8: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8018A7BC: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8018A7C0: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8018A7C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8018A7C8: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x8018A7CC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018A7D0: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8018A7D4: addiu       $t7, $t7, -0x67BC
    ctx->r15 = ADD32(ctx->r15, -0X67BC);
    // 0x8018A7D8: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x8018A7DC: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8018A7E0: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x8018A7E4: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x8018A7E8: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x8018A7EC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018A7F0: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8018A7F4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8018A7F8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8018A7FC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018A800: addiu       $t0, $t0, -0x67B0
    ctx->r8 = ADD32(ctx->r8, -0X67B0);
    // 0x8018A804: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8018A808: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8018A80C: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8018A810: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x8018A814: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x8018A818: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8018A81C: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x8018A820: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8018A824: addiu       $t5, $t5, -0x67A4
    ctx->r13 = ADD32(ctx->r13, -0X67A4);
    // 0x8018A828: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8018A82C: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8018A830: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8018A834: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8018A838: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8018A83C: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8018A840: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x8018A844: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8018A848: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x8018A84C: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x8018A850: bne         $at, $zero, L_8018A8D4
    if (ctx->r1 != 0) {
        // 0x8018A854: slti        $at, $a3, 0xA
        ctx->r1 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
            goto L_8018A8D4;
    }
    // 0x8018A854: slti        $at, $a3, 0xA
    ctx->r1 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x8018A858: beq         $at, $zero, L_8018A8D4
    if (ctx->r1 == 0) {
        // 0x8018A85C: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_8018A8D4;
    }
    // 0x8018A85C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018A860: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8018A864: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x8018A868: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8018A86C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A870: jal         0x80006970
    // 0x8018A874: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8018A874: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_0:
    // 0x8018A878: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8018A87C: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8018A880: addiu       $s0, $s0, -0x4928
    ctx->r16 = ADD32(ctx->r16, -0X4928);
    // 0x8018A884: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x8018A888: addu        $v0, $s0, $t2
    ctx->r2 = ADD32(ctx->r16, ctx->r10);
    // 0x8018A88C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A890: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A894: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A898: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8018A89C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A8A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8018A8A4: swc1        $f4, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f4.u32l;
    // 0x8018A8A8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018A8AC: jal         0x80006AB8
    // 0x8018A8B0: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x8018A8B0: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    after_1:
    // 0x8018A8B4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8018A8B8: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A8BC: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A8C0: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A8C4: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8018A8C8: swc1        $f10, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f10.u32l;
    // 0x8018A8CC: swc1        $f16, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->f16.u32l;
    // 0x8018A8D0: swc1        $f18, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f18.u32l;
L_8018A8D4:
    // 0x8018A8D4: addiu       $t3, $a3, -0x1
    ctx->r11 = ADD32(ctx->r7, -0X1);
    // 0x8018A8D8: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8018A8DC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018A8E0: sltiu       $at, $t3, 0x11
    ctx->r1 = ctx->r11 < 0X11 ? 1 : 0;
    // 0x8018A8E4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8018A8E8: addiu       $s0, $s0, -0x4928
    ctx->r16 = ADD32(ctx->r16, -0X4928);
    // 0x8018A8EC: beq         $at, $zero, L_8018AA5C
    if (ctx->r1 == 0) {
        // 0x8018A8F0: addiu       $s2, $sp, 0x74
        ctx->r18 = ADD32(ctx->r29, 0X74);
            goto L_8018AA5C;
    }
    // 0x8018A8F0: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x8018A8F4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018A8F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A8FC: addu        $at, $at, $t3
    gpr jr_addend_8018A904 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8018A900: lw          $t3, -0x4FC0($at)
    ctx->r11 = ADD32(ctx->r1, -0X4FC0);
    // 0x8018A904: jr          $t3
    // 0x8018A908: nop

    switch (jr_addend_8018A904 >> 2) {
        case 0: goto L_8018A90C; break;
        case 1: goto L_8018A960; break;
        case 2: goto L_8018A9B4; break;
        case 3: goto L_8018AA5C; break;
        case 4: goto L_8018AA5C; break;
        case 5: goto L_8018AA5C; break;
        case 6: goto L_8018AA5C; break;
        case 7: goto L_8018AA5C; break;
        case 8: goto L_8018AA5C; break;
        case 9: goto L_8018AA34; break;
        case 10: goto L_8018AA5C; break;
        case 11: goto L_8018AA5C; break;
        case 12: goto L_8018AA5C; break;
        case 13: goto L_8018AA5C; break;
        case 14: goto L_8018AA5C; break;
        case 15: goto L_8018AA5C; break;
        case 16: goto L_8018A9E0; break;
        default: switch_error(__func__, 0x8018A904, 0x8019B040);
    }
    // 0x8018A908: nop

L_8018A90C:
    // 0x8018A90C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A910: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8018A914: jal         0x80006970
    // 0x8018A918: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8018A918: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x8018A91C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A920: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A924: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A928: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A92C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8018A930: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8018A934: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8018A938: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8018A93C: jal         0x80006970
    // 0x8018A940: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x8018A940: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8018A944: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A948: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A94C: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A950: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018A954: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018A958: b           L_8018AA5C
    // 0x8018A95C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_8018AA5C;
    // 0x8018A95C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_8018A960:
    // 0x8018A960: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A964: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8018A968: jal         0x80006970
    // 0x8018A96C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8018A96C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x8018A970: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A974: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A978: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A97C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A980: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8018A984: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8018A988: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x8018A98C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8018A990: jal         0x80006970
    // 0x8018A994: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x8018A994: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x8018A998: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A99C: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A9A0: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A9A4: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8018A9A8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x8018A9AC: b           L_8018AA5C
    // 0x8018A9B0: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
        goto L_8018AA5C;
    // 0x8018A9B0: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
L_8018A9B4:
    // 0x8018A9B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A9B8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8018A9BC: jal         0x80006970
    // 0x8018A9C0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8018A9C0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x8018A9C4: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A9C8: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A9CC: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A9D0: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x8018A9D4: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x8018A9D8: b           L_8018AA5C
    // 0x8018A9DC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
        goto L_8018AA5C;
    // 0x8018A9DC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
L_8018A9E0:
    // 0x8018A9E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A9E4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8018A9E8: jal         0x80006970
    // 0x8018A9EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x8018A9EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
    // 0x8018A9F0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018A9F4: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018A9F8: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018A9FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018AA00: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8018AA04: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8018AA08: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
    // 0x8018AA0C: swc1        $f16, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f16.u32l;
    // 0x8018AA10: jal         0x80006970
    // 0x8018AA14: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x8018AA14: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    after_8:
    // 0x8018AA18: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018AA1C: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018AA20: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018AA24: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x8018AA28: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x8018AA2C: b           L_8018AA5C
    // 0x8018AA30: swc1        $f8, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f8.u32l;
        goto L_8018AA5C;
    // 0x8018AA30: swc1        $f8, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f8.u32l;
L_8018AA34:
    // 0x8018AA34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018AA38: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8018AA3C: jal         0x80006970
    // 0x8018AA40: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_9;
    // 0x8018AA40: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_9:
    // 0x8018AA44: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018AA48: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8018AA4C: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8018AA50: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x8018AA54: swc1        $f16, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f16.u32l;
    // 0x8018AA58: swc1        $f18, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f18.u32l;
L_8018AA5C:
    // 0x8018AA5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018AA60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018AA64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018AA68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018AA6C: jr          $ra
    // 0x8018AA70: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8018AA70: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void Venom1_Ve1Golemech_SetShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80198314: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80198318: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019831C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80198320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80198324: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80198328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019832C: jal         0x800B8DD0
    // 0x80198330: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80198330: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_0:
    // 0x80198334: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80198338: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8019833C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198340: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80198344: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80198348: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019834C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80198350: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80198354: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80198358: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019835C: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x80198360: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198364: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80198368: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019836C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80198370: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80198374: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80198378: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8019837C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198380: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198384: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80198388: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019838C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80198390: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80198394: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80198398: jal         0x80005B00
    // 0x8019839C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8019839C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x801983A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801983A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801983A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801983AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801983B0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x801983B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801983B8: jal         0x80005C34
    // 0x801983BC: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x801983BC: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_2:
    // 0x801983C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801983C4: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x801983C8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801983CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801983D0: jal         0x80005D44
    // 0x801983D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x801983D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801983D8: jal         0x80006EB8
    // 0x801983DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801983DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801983E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801983E4: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x801983E8: addiu       $t6, $t6, 0x4AC0
    ctx->r14 = ADD32(ctx->r14, 0X4AC0);
    // 0x801983EC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801983F0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801983F4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801983F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801983FC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80198400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80198404: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80198408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019840C: jr          $ra
    // 0x80198410: nop

    return;
    // 0x80198410: nop

;}
RECOMP_FUNC void Corneria_CoBuildingOnFire_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187530: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80187534: jr          $ra
    // 0x80187538: nop

    return;
    // 0x80187538: nop

;}
RECOMP_FUNC void Corneria_80187A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187A38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80187A3C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80187A40: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80187A44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80187A48: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80187A4C: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80187A50: lw          $a3, 0x6C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X6C);
    // 0x80187A54: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80187A58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80187A5C: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80187A60: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80187A64: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80187A68: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80187A6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80187A70: jal         0x8007C120
    // 0x80187A74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_0;
    // 0x80187A74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80187A78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80187A7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80187A80: jr          $ra
    // 0x80187A84: nop

    return;
    // 0x80187A84: nop

;}
RECOMP_FUNC void Corneria_CoGarudaDestroy_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BC84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018BC88: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8018BC8C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8018BC90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018BC94: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8018BC98: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8018BC9C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8018BCA0: addiu       $t6, $t6, -0x6740
    ctx->r14 = ADD32(ctx->r14, -0X6740);
    // 0x8018BCA4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018BCA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018BCAC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8018BCB0: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8018BCB4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8018BCB8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8018BCBC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018BCC0: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8018BCC4: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8018BCC8: jal         0x80006970
    // 0x8018BCCC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8018BCCC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_0:
    // 0x8018BCD0: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8018BCD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018BCD8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8018BCDC: beq         $v0, $at, L_8018BD10
    if (ctx->r2 == ctx->r1) {
        // 0x8018BCE0: lwc1        $f4, 0x1C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8018BD10;
    }
    // 0x8018BCE0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018BCE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018BCE8: beq         $v0, $at, L_8018BD28
    if (ctx->r2 == ctx->r1) {
        // 0x8018BCEC: lwc1        $f10, 0x1C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8018BD28;
    }
    // 0x8018BCEC: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018BCF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018BCF4: beq         $v0, $at, L_8018BD40
    if (ctx->r2 == ctx->r1) {
        // 0x8018BCF8: lwc1        $f4, 0x1C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8018BD40;
    }
    // 0x8018BCF8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018BCFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018BD00: beq         $v0, $at, L_8018BD58
    if (ctx->r2 == ctx->r1) {
        // 0x8018BD04: lwc1        $f10, 0x1C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8018BD58;
    }
    // 0x8018BD04: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018BD08: b           L_8018BD70
    // 0x8018BD0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018BD70;
    // 0x8018BD0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018BD10:
    // 0x8018BD10: swc1        $f4, 0x11C($a3)
    MEM_W(0X11C, ctx->r7) = ctx->f4.u32l;
    // 0x8018BD14: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018BD18: swc1        $f6, 0x12C($a3)
    MEM_W(0X12C, ctx->r7) = ctx->f6.u32l;
    // 0x8018BD1C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018BD20: b           L_8018BD6C
    // 0x8018BD24: swc1        $f8, 0x13C($a3)
    MEM_W(0X13C, ctx->r7) = ctx->f8.u32l;
        goto L_8018BD6C;
    // 0x8018BD24: swc1        $f8, 0x13C($a3)
    MEM_W(0X13C, ctx->r7) = ctx->f8.u32l;
L_8018BD28:
    // 0x8018BD28: swc1        $f10, 0x120($a3)
    MEM_W(0X120, ctx->r7) = ctx->f10.u32l;
    // 0x8018BD2C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018BD30: swc1        $f16, 0x130($a3)
    MEM_W(0X130, ctx->r7) = ctx->f16.u32l;
    // 0x8018BD34: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018BD38: b           L_8018BD6C
    // 0x8018BD3C: swc1        $f18, 0x140($a3)
    MEM_W(0X140, ctx->r7) = ctx->f18.u32l;
        goto L_8018BD6C;
    // 0x8018BD3C: swc1        $f18, 0x140($a3)
    MEM_W(0X140, ctx->r7) = ctx->f18.u32l;
L_8018BD40:
    // 0x8018BD40: swc1        $f4, 0x124($a3)
    MEM_W(0X124, ctx->r7) = ctx->f4.u32l;
    // 0x8018BD44: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018BD48: swc1        $f6, 0x134($a3)
    MEM_W(0X134, ctx->r7) = ctx->f6.u32l;
    // 0x8018BD4C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018BD50: b           L_8018BD6C
    // 0x8018BD54: swc1        $f8, 0x144($a3)
    MEM_W(0X144, ctx->r7) = ctx->f8.u32l;
        goto L_8018BD6C;
    // 0x8018BD54: swc1        $f8, 0x144($a3)
    MEM_W(0X144, ctx->r7) = ctx->f8.u32l;
L_8018BD58:
    // 0x8018BD58: swc1        $f10, 0x128($a3)
    MEM_W(0X128, ctx->r7) = ctx->f10.u32l;
    // 0x8018BD5C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018BD60: swc1        $f16, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->f16.u32l;
    // 0x8018BD64: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018BD68: swc1        $f18, 0x148($a3)
    MEM_W(0X148, ctx->r7) = ctx->f18.u32l;
L_8018BD6C:
    // 0x8018BD6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018BD70:
    // 0x8018BD70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018BD74: jr          $ra
    // 0x8018BD78: nop

    return;
    // 0x8018BD78: nop

;}
RECOMP_FUNC void Corneria_Granga_SpawnItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187838: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018783C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80187840: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80187844: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80187848: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8018784C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80187850: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80187854: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80187858: addiu       $v0, $v0, 0x4050
    ctx->r2 = ADD32(ctx->r2, 0X4050);
    // 0x8018785C: addiu       $a2, $a2, 0x37E0
    ctx->r6 = ADD32(ctx->r6, 0X37E0);
    // 0x80187860: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
L_80187864:
    // 0x80187864: bne         $t6, $zero, L_801878BC
    if (ctx->r14 != 0) {
        // 0x80187868: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801878BC;
    }
    // 0x80187868: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8018786C: jal         0x80061444
    // 0x80187870: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Item_Initialize(rdram, ctx);
        goto after_0;
    // 0x80187870: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80187874: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80187878: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8018787C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80187880: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80187884: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80187888: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018788C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80187890: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80187894: sh          $t9, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r25;
    // 0x80187898: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8018789C: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x801878A0: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x801878A4: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801878A8: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801878AC: jal         0x800612B8
    // 0x801878B0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801878B0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x801878B4: b           L_801878CC
    // 0x801878B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801878CC;
    // 0x801878B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801878BC:
    // 0x801878BC: addiu       $a2, $a2, 0x6C
    ctx->r6 = ADD32(ctx->r6, 0X6C);
    // 0x801878C0: bnel        $a2, $v0, L_80187864
    if (ctx->r6 != ctx->r2) {
        // 0x801878C4: lbu         $t6, 0x0($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X0);
            goto L_80187864;
    }
    goto skip_0;
    // 0x801878C4: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    skip_0:
    // 0x801878C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801878CC:
    // 0x801878CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801878D0: jr          $ra
    // 0x801878D4: nop

    return;
    // 0x801878D4: nop

;}
RECOMP_FUNC void Meteo_MeCrusherShield_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188344: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80188348: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018834C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188350: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80188354: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x80188358: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018835C: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80188360: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80188364: beql        $at, $zero, L_801883C4
    if (ctx->r1 == 0) {
        // 0x80188368: sltiu       $at, $v1, 0x6
        ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
            goto L_801883C4;
    }
    goto skip_0;
    // 0x80188368: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
    skip_0:
    // 0x8018836C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80188370: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80188374: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x80188378: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8018837C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80188380: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80188384: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80188388: lwc1        $f6, 0x80($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8018838C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80188390: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80188394: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80188398: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8018839C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801883A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801883A4: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x801883A8: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801883AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801883B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801883B4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801883B8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801883BC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x801883C0: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_801883C4:
    // 0x801883C4: beq         $at, $zero, L_80188778
    if (ctx->r1 == 0) {
        // 0x801883C8: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80188778;
    }
    // 0x801883C8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801883CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801883D0: addu        $at, $at, $t6
    gpr jr_addend_801883D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801883D4: lw          $t6, 0x57D0($at)
    ctx->r14 = ADD32(ctx->r1, 0X57D0);
    // 0x801883D8: jr          $t6
    // 0x801883DC: nop

    switch (jr_addend_801883D8 >> 2) {
        case 0: goto L_801883E0; break;
        case 1: goto L_80188400; break;
        case 2: goto L_8018845C; break;
        case 3: goto L_80188644; break;
        case 4: goto L_80188664; break;
        case 5: goto L_8018873C; break;
        default: switch_error(__func__, 0x801883D8, 0x801957D0);
    }
    // 0x801883DC: nop

L_801883E0:
    // 0x801883E0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801883E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801883E8: lwc1        $f8, 0x80($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X80);
    // 0x801883EC: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x801883F0: sh          $t7, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r15;
    // 0x801883F4: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801883F8: b           L_80188778
    // 0x801883FC: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
        goto L_80188778;
    // 0x801883FC: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
L_80188400:
    // 0x80188400: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80188404: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188408: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018840C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188410: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80188414: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188418: lwc1        $f4, 0x57E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X57E8);
    // 0x8018841C: sub.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80188420: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80188424: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80188428: mul.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018842C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80188430: nop

    // 0x80188434: bc1fl       L_80188444
    if (!c1cs) {
        // 0x80188438: add.s       $f6, $f2, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_80188444;
    }
    goto skip_1;
    // 0x80188438: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    skip_1:
    // 0x8018843C: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80188440: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
L_80188444:
    // 0x80188444: lh          $t8, 0x50($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X50);
    // 0x80188448: bne         $t8, $zero, L_80188778
    if (ctx->r24 != 0) {
        // 0x8018844C: swc1        $f6, 0x80($s0)
        MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
            goto L_80188778;
    }
    // 0x8018844C: swc1        $f6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
    // 0x80188450: sh          $t9, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r25;
    // 0x80188454: b           L_80188778
    // 0x80188458: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
        goto L_80188778;
    // 0x80188458: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
L_8018845C:
    // 0x8018845C: lb          $t0, 0x62($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X62);
    // 0x80188460: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188464: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80188468: bne         $t0, $at, L_80188778
    if (ctx->r8 != ctx->r1) {
        // 0x8018846C: addiu       $a0, $s0, 0x3FC
        ctx->r4 = ADD32(ctx->r16, 0X3FC);
            goto L_80188778;
    }
    // 0x8018846C: addiu       $a0, $s0, 0x3FC
    ctx->r4 = ADD32(ctx->r16, 0X3FC);
    // 0x80188470: lh          $t2, 0x88($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X88);
    // 0x80188474: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
    // 0x80188478: sh          $t1, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r9;
    // 0x8018847C: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x80188480: sh          $t3, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r11;
    // 0x80188484: lui         $a1, 0x3103
    ctx->r5 = S32(0X3103 << 16);
    // 0x80188488: lbu         $a2, 0x4B($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4B);
    // 0x8018848C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80188490: jal         0x8001D034
    // 0x80188494: ori         $a1, $a1, 0x605B
    ctx->r5 = ctx->r5 | 0X605B;
    Audio_SetTransposeAndPlaySfx(rdram, ctx);
        goto after_0;
    // 0x80188494: ori         $a1, $a1, 0x605B
    ctx->r5 = ctx->r5 | 0X605B;
    after_0:
    // 0x80188498: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
    // 0x8018849C: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x801884A0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801884A4: sh          $t5, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r13;
    // 0x801884A8: lh          $t6, 0x4A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4A);
    // 0x801884AC: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x801884B0: bnel        $at, $zero, L_801884C0
    if (ctx->r1 != 0) {
        // 0x801884B4: lh          $t8, 0x88($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X88);
            goto L_801884C0;
    }
    goto skip_2;
    // 0x801884B4: lh          $t8, 0x88($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X88);
    skip_2:
    // 0x801884B8: sh          $t7, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r15;
    // 0x801884BC: lh          $t8, 0x88($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X88);
L_801884C0:
    // 0x801884C0: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x801884C4: bnel        $at, $zero, L_8018877C
    if (ctx->r1 != 0) {
        // 0x801884C8: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8018877C;
    }
    goto skip_3;
    // 0x801884C8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_3:
    // 0x801884CC: sh          $zero, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = 0;
    // 0x801884D0: jal         0x8001A500
    // 0x801884D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_1;
    // 0x801884D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x801884D8: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
    // 0x801884DC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801884E0: addiu       $a0, $a0, -0x4354
    ctx->r4 = ADD32(ctx->r4, -0X4354);
    // 0x801884E4: bne         $v0, $zero, L_801884F8
    if (ctx->r2 != 0) {
        // 0x801884E8: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_801884F8;
    }
    // 0x801884E8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801884EC: sh          $t9, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r25;
    // 0x801884F0: jal         0x800BA808
    // 0x801884F4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x801884F4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_2:
L_801884F8:
    // 0x801884F8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801884FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188500: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80188504: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80188508: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018850C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80188510: lwc1        $f4, 0x57EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X57EC);
    // 0x80188514: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188518: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018851C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80188520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80188524: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80188528: jal         0x80005FE0
    // 0x8018852C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8018852C: nop

    after_3:
    // 0x80188530: lui         $at, 0x431C
    ctx->r1 = S32(0X431C << 16);
    // 0x80188534: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188538: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018853C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80188540: lwc1        $f18, 0x57F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X57F0);
    // 0x80188544: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188548: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018854C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80188550: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80188554: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80188558: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8018855C: jal         0x80006A20
    // 0x80188560: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x80188560: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80188564: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188568: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018856C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188570: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80188574: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80188578: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018857C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80188580: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188584: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80188588: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018858C: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80188590: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80188594: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80188598: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018859C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801885A0: jal         0x80188298
    // 0x801885A4: nop

    Meteo_Effect370_Spawn2(rdram, ctx);
        goto after_5;
    // 0x801885A4: nop

    after_5:
    // 0x801885A8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801885AC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801885B0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801885B4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801885B8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801885BC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801885C0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801885C4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801885C8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801885CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801885D0: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801885D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801885D8: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801885DC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801885E0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801885E4: jal         0x80188228
    // 0x801885E8: nop

    Meteo_Effect370_Spawn1(rdram, ctx);
        goto after_6;
    // 0x801885E8: nop

    after_6:
    // 0x801885EC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801885F0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801885F4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801885F8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801885FC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80188600: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80188604: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80188608: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018860C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80188610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188614: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80188618: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018861C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80188620: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188624: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80188628: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018862C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80188630: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80188634: jal         0x80188228
    // 0x80188638: nop

    Meteo_Effect370_Spawn1(rdram, ctx);
        goto after_7;
    // 0x80188638: nop

    after_7:
    // 0x8018863C: b           L_8018877C
    // 0x80188640: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
        goto L_8018877C;
    // 0x80188640: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80188644:
    // 0x80188644: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x80188648: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8018864C: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80188650: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
    // 0x80188654: sh          $t1, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r9;
    // 0x80188658: sh          $t2, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r10;
    // 0x8018865C: b           L_80188778
    // 0x80188660: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
        goto L_80188778;
    // 0x80188660: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
L_80188664:
    // 0x80188664: lh          $t3, 0x50($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X50);
    // 0x80188668: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018866C: bnel        $t3, $zero, L_8018877C
    if (ctx->r11 != 0) {
        // 0x80188670: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8018877C;
    }
    goto skip_4;
    // 0x80188670: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_4:
    // 0x80188674: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80188678: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018867C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188680: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188684: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188688: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8018868C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80188690: jal         0x8007D2C8
    // 0x80188694: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_8;
    // 0x80188694: nop

    after_8:
    // 0x80188698: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018869C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801886A0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801886A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801886A8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801886AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801886B0: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801886B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801886B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801886BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801886C0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801886C4: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x801886C8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801886CC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801886D0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801886D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801886D8: jal         0x8007BFFC
    // 0x801886DC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_9;
    // 0x801886DC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x801886E0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801886E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801886E8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801886EC: sh          $t5, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r13;
    // 0x801886F0: addiu       $a0, $s0, 0x3FC
    ctx->r4 = ADD32(ctx->r16, 0X3FC);
    // 0x801886F4: lui         $a1, 0x3103
    ctx->r5 = S32(0X3103 << 16);
    // 0x801886F8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x801886FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80188700: jal         0x8001A55C
    // 0x80188704: ori         $a1, $a1, 0x605B
    ctx->r5 = ctx->r5 | 0X605B;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_10;
    // 0x80188704: ori         $a1, $a1, 0x605B
    ctx->r5 = ctx->r5 | 0X605B;
    after_10:
    // 0x80188708: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018870C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80188710: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188714: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80188718: lui         $a0, 0x3102
    ctx->r4 = S32(0X3102 << 16);
    // 0x8018871C: ori         $a0, $a0, 0x405D
    ctx->r4 = ctx->r4 | 0X405D;
    // 0x80188720: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80188724: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188728: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8018872C: jal         0x80019218
    // 0x80188730: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_11;
    // 0x80188730: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x80188734: b           L_8018877C
    // 0x80188738: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
        goto L_8018877C;
    // 0x80188738: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8018873C:
    // 0x8018873C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80188740: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188744: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80188748: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018874C: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80188750: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80188754: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188758: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8018875C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80188760: bc1f        L_80188778
    if (!c1cs) {
        // 0x80188764: swc1        $f18, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
            goto L_80188778;
    }
    // 0x80188764: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x80188768: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018876C: nop

    // 0x80188770: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80188774: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
L_80188778:
    // 0x80188778: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8018877C:
    // 0x8018877C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188780: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80188784: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80188788: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8018878C: nop

    // 0x80188790: bc1fl       L_801887A8
    if (!c1cs) {
        // 0x80188794: c.lt.s      $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
            goto L_801887A8;
    }
    goto skip_5;
    // 0x80188794: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    skip_5:
    // 0x80188798: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8018879C: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
    // 0x801887A0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x801887A4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
L_801887A8:
    // 0x801887A8: nop

    // 0x801887AC: bc1fl       L_801887C0
    if (!c1cs) {
        // 0x801887B0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801887C0;
    }
    goto skip_6;
    // 0x801887B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_6:
    // 0x801887B4: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x801887B8: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
    // 0x801887BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801887C0:
    // 0x801887C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801887C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801887C8: jr          $ra
    // 0x801887CC: nop

    return;
    // 0x801887CC: nop

;}
RECOMP_FUNC void Meteo_Effect370_Setup1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801881A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801881AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801881B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801881B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801881B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801881BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801881C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801881C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801881C8: jal         0x80061474
    // 0x801881CC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x801881CC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801881D0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801881D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801881D8: addiu       $t7, $zero, 0x172
    ctx->r15 = ADD32(0, 0X172);
    // 0x801881DC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801881E0: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801881E4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801881E8: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801881EC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801881F0: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801881F4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801881F8: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801881FC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80188200: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80188204: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80188208: swc1        $f10, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f10.u32l;
    // 0x8018820C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80188210: jal         0x800612B8
    // 0x80188214: sh          $t8, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r24;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80188214: sh          $t8, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r24;
    after_1:
    // 0x80188218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018821C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80188220: jr          $ra
    // 0x80188224: nop

    return;
    // 0x80188224: nop

;}
RECOMP_FUNC void OvlI2_CallFunction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187520: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80187524: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80187528: jr          $ra
    // 0x8018752C: nop

    return;
    // 0x8018752C: nop

;}
RECOMP_FUNC void Meteo_SmallRock_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CCF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018CCFC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8018CD00: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018CD04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018CD08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8018CD0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018CD10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018CD14: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018CD18: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8018CD1C: jal         0x8007A6F0
    // 0x8018CD20: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_0;
    // 0x8018CD20: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_0:
    // 0x8018CD24: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8018CD28: addiu       $s0, $s0, 0x37E0
    ctx->r16 = ADD32(ctx->r16, 0X37E0);
    // 0x8018CD2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018CD30: addiu       $s3, $zero, 0x19
    ctx->r19 = ADD32(0, 0X19);
L_8018CD34:
    // 0x8018CD34: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018CD38: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8018CD3C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8018CD40:
    // 0x8018CD40: bnel        $t6, $zero, L_8018CD5C
    if (ctx->r14 != 0) {
        // 0x8018CD44: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8018CD5C;
    }
    goto skip_0;
    // 0x8018CD44: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8018CD48: jal         0x8018CB50
    // 0x8018CD4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Meteo_SmallRock_Setup(rdram, ctx);
        goto after_1;
    // 0x8018CD4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8018CD50: b           L_8018CD68
    // 0x8018CD54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8018CD68;
    // 0x8018CD54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018CD58: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8018CD5C:
    // 0x8018CD5C: bnel        $a0, $s0, L_8018CD40
    if (ctx->r4 != ctx->r16) {
        // 0x8018CD60: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8018CD40;
    }
    goto skip_1;
    // 0x8018CD60: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8018CD64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018CD68:
    // 0x8018CD68: bne         $s1, $s3, L_8018CD34
    if (ctx->r17 != ctx->r19) {
        // 0x8018CD6C: nop
    
            goto L_8018CD34;
    }
    // 0x8018CD6C: nop

    // 0x8018CD70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018CD74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018CD78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018CD7C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8018CD80: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8018CD84: jr          $ra
    // 0x8018CD88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018CD88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void SectorX_SxSpyborgLeftArm_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FF84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018FF88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018FF8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018FF90: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8018FF94: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8018FF98: lw          $t8, -0x4438($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4438);
    // 0x8018FF9C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018FFA0: addiu       $t7, $t7, 0x3208
    ctx->r15 = ADD32(ctx->r15, 0X3208);
    // 0x8018FFA4: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x8018FFA8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018FFAC: addiu       $a3, $a3, -0xC0
    ctx->r7 = ADD32(ctx->r7, -0XC0);
    // 0x8018FFB0: addiu       $a1, $a1, 0xC68
    ctx->r5 = ADD32(ctx->r5, 0XC68);
    // 0x8018FFB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018FFB8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018FFBC: addiu       $a2, $t6, 0x1A0
    ctx->r6 = ADD32(ctx->r14, 0X1A0);
    // 0x8018FFC0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018FFC4: jal         0x8009A72C
    // 0x8018FFC8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_0;
    // 0x8018FFC8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x8018FFCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018FFD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018FFD4: jr          $ra
    // 0x8018FFD8: nop

    return;
    // 0x8018FFD8: nop

;}
RECOMP_FUNC void Meteo_Effect369_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188CAC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80188CB0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80188CB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188CB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80188CBC: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x80188CC0: bnel        $t6, $zero, L_80188E50
    if (ctx->r14 != 0) {
        // 0x80188CC4: lhu         $t9, 0x50($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X50);
            goto L_80188E50;
    }
    goto skip_0;
    // 0x80188CC4: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
    skip_0:
    // 0x80188CC8: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80188CCC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80188CD0: beql        $v0, $zero, L_80188CF0
    if (ctx->r2 == 0) {
        // 0x80188CD4: lwc1        $f4, 0x10($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80188CF0;
    }
    goto skip_1;
    // 0x80188CD4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x80188CD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188CDC: beql        $v0, $at, L_80188D28
    if (ctx->r2 == ctx->r1) {
        // 0x80188CE0: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80188D28;
    }
    goto skip_2;
    // 0x80188CE0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_2:
    // 0x80188CE4: b           L_80188D5C
    // 0x80188CE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80188D5C;
    // 0x80188CE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188CEC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
L_80188CF0:
    // 0x80188CF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188CF4: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80188CF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188CFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80188D00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80188D04: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80188D08: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80188D0C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80188D10: nop

    // 0x80188D14: bc1fl       L_80188D5C
    if (!c1cs) {
        // 0x80188D18: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80188D5C;
    }
    goto skip_3;
    // 0x80188D18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x80188D1C: b           L_80188D58
    // 0x80188D20: sh          $t7, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r15;
        goto L_80188D58;
    // 0x80188D20: sh          $t7, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r15;
    // 0x80188D24: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_80188D28:
    // 0x80188D28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188D2C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80188D30: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80188D34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188D38: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80188D3C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80188D40: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80188D44: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80188D48: nop

    // 0x80188D4C: bc1fl       L_80188D5C
    if (!c1cs) {
        // 0x80188D50: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80188D5C;
    }
    goto skip_4;
    // 0x80188D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_4:
    // 0x80188D54: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_80188D58:
    // 0x80188D58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80188D5C:
    // 0x80188D5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188D60: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80188D64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188D68: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80188D6C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80188D70: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x80188D74: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80188D78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188D7C: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    // 0x80188D80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188D84: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    // 0x80188D88: lwc1        $f10, 0x5800($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5800);
    // 0x80188D8C: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80188D90: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80188D98: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80188D9C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80188DA0: jal         0x80005FE0
    // 0x80188DA4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x80188DA4: nop

    after_0:
    // 0x80188DA8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188DAC: lwc1        $f4, 0x5804($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5804);
    // 0x80188DB0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80188DB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188DB8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188DBC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80188DC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80188DC4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80188DC8: jal         0x80005D44
    // 0x80188DCC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80188DCC: nop

    after_1:
    // 0x80188DD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80188DD4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80188DD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188DDC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188DE0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188DE4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80188DE8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80188DEC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80188DF0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80188DF4: jal         0x80006970
    // 0x80188DF8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80188DF8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80188DFC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80188E00: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80188E04: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188E08: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188E0C: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80188E10: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80188E14: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80188E18: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x80188E1C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80188E20: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80188E24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188E28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188E2C: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x80188E30: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80188E34: lwc1        $f16, 0x68($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80188E38: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80188E3C: jal         0x80188C2C
    // 0x80188E40: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Meteo_Effect369_Spawn(rdram, ctx);
        goto after_3;
    // 0x80188E40: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80188E44: b           L_80188E64
    // 0x80188E48: nop

        goto L_80188E64;
    // 0x80188E48: nop

    // 0x80188E4C: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
L_80188E50:
    // 0x80188E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80188E54: bne         $t9, $zero, L_80188E64
    if (ctx->r25 != 0) {
        // 0x80188E58: nop
    
            goto L_80188E64;
    }
    // 0x80188E58: nop

    // 0x80188E5C: jal         0x80060FBC
    // 0x80188E60: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x80188E60: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_4:
L_80188E64:
    // 0x80188E64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188E68: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80188E6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80188E70: jal         0x8007A774
    // 0x80188E74: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_5;
    // 0x80188E74: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_5:
    // 0x80188E78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80188E7C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80188E80: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80188E84: jr          $ra
    // 0x80188E88: nop

    return;
    // 0x80188E88: nop

;}
RECOMP_FUNC void Meteo_Effect371_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DE1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018DE20: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8018DE24: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE28: lwc1        $f6, 0x5A08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A08);
    // 0x8018DE2C: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8018DE30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DE34: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018DE38: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018DE3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DE40: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018DE44: jal         0x80005D44
    // 0x8018DE48: nop

    Matrix_RotateX(rdram, ctx);
        goto after_0;
    // 0x8018DE48: nop

    after_0:
    // 0x8018DE4C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8018DE50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DE54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DE58: lwc1        $f0, 0x70($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X70);
    // 0x8018DE5C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018DE60: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018DE64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DE68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DE6C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018DE70: jal         0x80005C34
    // 0x8018DE74: nop

    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8018DE74: nop

    after_1:
    // 0x8018DE78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DE7C: jal         0x80006EB8
    // 0x8018DE80: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8018DE80: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_2:
    // 0x8018DE84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DE88: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018DE8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8018DE90: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018DE94: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8018DE98: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018DE9C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018DEA0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8018DEA4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8018DEA8: lh          $t1, 0x44($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X44);
    // 0x8018DEAC: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8018DEB0: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8018DEB4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8018DEB8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8018DEBC: lbu         $a1, 0x4C($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X4C);
    // 0x8018DEC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018DEC4: beql        $a1, $zero, L_8018DEE0
    if (ctx->r5 == 0) {
        // 0x8018DEC8: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_8018DEE0;
    }
    goto skip_0;
    // 0x8018DEC8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8018DECC: beql        $a1, $at, L_8018DEFC
    if (ctx->r5 == ctx->r1) {
        // 0x8018DED0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018DEFC;
    }
    goto skip_1;
    // 0x8018DED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8018DED4: b           L_8018DEFC
    // 0x8018DED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018DEFC;
    // 0x8018DED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DEDC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_8018DEE0:
    // 0x8018DEE0: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8018DEE4: addiu       $t6, $t6, 0x3810
    ctx->r14 = ADD32(ctx->r14, 0X3810);
    // 0x8018DEE8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018DEEC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8018DEF0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018DEF4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018DEF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DEFC:
    // 0x8018DEFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018DF00: jr          $ra
    // 0x8018DF04: nop

    return;
    // 0x8018DF04: nop

;}
RECOMP_FUNC void SectorX_SxSlippy_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F884: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F888: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018F88C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018F890: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8018F894: lh          $t6, 0xB6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XB6);
    // 0x8018F898: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018F89C: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x8018F8A0: beq         $at, $zero, L_8018F9F0
    if (ctx->r1 == 0) {
        // 0x8018F8A4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8018F9F0;
    }
    // 0x8018F8A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018F8A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F8AC: addu        $at, $at, $t7
    gpr jr_addend_8018F8B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018F8B0: lw          $t7, 0x5AC0($at)
    ctx->r15 = ADD32(ctx->r1, 0X5AC0);
    // 0x8018F8B4: jr          $t7
    // 0x8018F8B8: nop

    switch (jr_addend_8018F8B4 >> 2) {
        case 0: goto L_8018F8FC; break;
        case 1: goto L_8018F8BC; break;
        case 2: goto L_8018F8EC; break;
        case 3: goto L_8018F8EC; break;
        case 4: goto L_8018F9F0; break;
        case 5: goto L_8018F9F0; break;
        case 6: goto L_8018F9F0; break;
        case 7: goto L_8018F9F0; break;
        case 8: goto L_8018F9F0; break;
        case 9: goto L_8018F9F0; break;
        case 10: goto L_8018F9F0; break;
        case 11: goto L_8018F8EC; break;
        default: switch_error(__func__, 0x8018F8B4, 0x80195AC0);
    }
    // 0x8018F8B8: nop

L_8018F8BC:
    // 0x8018F8BC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018F8C0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018F8C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018F8C8: lui         $t0, 0x602
    ctx->r8 = S32(0X602 << 16);
    // 0x8018F8CC: addiu       $t0, $t0, 0xD20
    ctx->r8 = ADD32(ctx->r8, 0XD20);
    // 0x8018F8D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018F8D4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018F8D8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018F8DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018F8E0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018F8E4: b           L_8018F9F4
    // 0x8018F8E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018F9F4;
    // 0x8018F8E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018F8EC:
    // 0x8018F8EC: jal         0x8005B388
    // 0x8018F8F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ActorTeamArwing_Draw(rdram, ctx);
        goto after_0;
    // 0x8018F8F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8018F8F4: b           L_8018F9F4
    // 0x8018F8F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018F9F4;
    // 0x8018F8F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018F8FC:
    // 0x8018F8FC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018F900: addiu       $v1, $v1, 0x78A0
    ctx->r3 = ADD32(ctx->r3, 0X78A0);
    // 0x8018F904: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8018F908: addiu       $a3, $zero, 0x4E0
    ctx->r7 = ADD32(0, 0X4E0);
    // 0x8018F90C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018F910: multu       $t2, $a3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F914: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8018F918: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8018F91C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018F920: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018F924: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F928: lwc1        $f2, 0x5AF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AF0);
    // 0x8018F92C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018F930: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018F934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018F938: mflo        $t3
    ctx->r11 = lo;
    // 0x8018F93C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8018F940: lwc1        $f4, 0x58($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X58);
    // 0x8018F944: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8018F948: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8018F94C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8018F950: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8018F954: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x8018F958: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018F95C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8018F960: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F964: mflo        $t7
    ctx->r15 = lo;
    // 0x8018F968: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8018F96C: lwc1        $f16, 0x5C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x8018F970: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8018F974: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8018F978: jal         0x800B8DD0
    // 0x8018F97C: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018F97C: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
    after_1:
    // 0x8018F980: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8018F984: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018F988: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8018F98C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018F990: lui         $t2, 0xDC46
    ctx->r10 = S32(0XDC46 << 16);
    // 0x8018F994: ori         $t2, $t2, 0x1EFF
    ctx->r10 = ctx->r10 | 0X1EFF;
    // 0x8018F998: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018F99C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8018F9A0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018F9A4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8018F9A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F9AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018F9B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018F9B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018F9B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018F9BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F9C0: jal         0x80005C34
    // 0x8018F9C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8018F9C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8018F9C8: jal         0x80006EB8
    // 0x8018F9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8018F9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018F9D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018F9D4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8018F9D8: addiu       $t6, $t6, 0x10C0
    ctx->r14 = ADD32(ctx->r14, 0X10C0);
    // 0x8018F9DC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018F9E0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8018F9E4: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8018F9E8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018F9EC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8018F9F0:
    // 0x8018F9F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018F9F4:
    // 0x8018F9F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018F9F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F9FC: jr          $ra
    // 0x8018FA00: nop

    return;
    // 0x8018FA00: nop

;}
RECOMP_FUNC void SectorX_8018FFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FFDC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8018FFE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8018FFE4: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8018FFE8: bne         $at, $zero, L_8018FFF4
    if (ctx->r1 != 0) {
        // 0x8018FFEC: slti        $at, $a0, 0xC
        ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
            goto L_8018FFF4;
    }
    // 0x8018FFEC: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8018FFF0: bne         $at, $zero, L_8019000C
    if (ctx->r1 != 0) {
        // 0x8018FFF4: slti        $at, $a0, 0x20
        ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
            goto L_8019000C;
    }
L_8018FFF4:
    // 0x8018FFF4: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x8018FFF8: bne         $at, $zero, L_80190014
    if (ctx->r1 != 0) {
        // 0x8018FFFC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80190014;
    }
    // 0x8018FFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80190000: slti        $at, $a0, 0x24
    ctx->r1 = SIGNED(ctx->r4) < 0X24 ? 1 : 0;
    // 0x80190004: beql        $at, $zero, L_80190018
    if (ctx->r1 == 0) {
        // 0x80190008: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80190018;
    }
    goto skip_0;
    // 0x80190008: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_0:
L_8019000C:
    // 0x8019000C: jr          $ra
    // 0x80190010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80190010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80190014:
    // 0x80190014: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80190018:
    // 0x80190018: jr          $ra
    // 0x8019001C: nop

    return;
    // 0x8019001C: nop

;}
RECOMP_FUNC void SectorX_SxSlippy_ShootBoss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F1DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018F1E0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018F1E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018F1E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018F1EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018F1F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018F1F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F1F8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8018F1FC: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8018F200: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018F204: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8018F208: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018F20C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F210: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F214: lwc1        $f16, 0x5A9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5A9C);
    // 0x8018F218: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018F21C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F220: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018F224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018F228: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018F22C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018F230: jal         0x80005E90
    // 0x8018F234: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8018F234: nop

    after_0:
    // 0x8018F238: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F23C: lwc1        $f6, 0x5AA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5AA0);
    // 0x8018F240: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018F244: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F248: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018F24C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018F250: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F254: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018F258: jal         0x80005D44
    // 0x8018F25C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8018F25C: nop

    after_1:
    // 0x8018F260: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F264: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018F268: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8018F26C: jal         0x80006A20
    // 0x8018F270: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8018F270: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x8018F274: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018F278: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8018F27C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8018F280: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018F284: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8018F288: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F28C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8018F290: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018F294: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8018F298: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8018F29C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018F2A0: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x8018F2A4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018F2A8: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8018F2AC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8018F2B0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8018F2B4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018F2B8: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8018F2BC: add.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d + ctx->f10.d;
    // 0x8018F2C0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018F2C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018F2C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018F2CC: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8018F2D0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018F2D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018F2D8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8018F2DC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018F2E0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8018F2E4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018F2E8: mul.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8018F2EC: add.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f10.d + ctx->f16.d;
    // 0x8018F2F0: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018F2F4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8018F2F8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018F2FC: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018F300: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8018F304: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8018F308: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F30C: nop

    // 0x8018F310: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F314: jal         0x8006EEFC
    // 0x8018F318: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    Actor_SpawnPlayerLaser(rdram, ctx);
        goto after_3;
    // 0x8018F318: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8018F31C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018F320: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018F324: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8018F328: jr          $ra
    // 0x8018F32C: nop

    return;
    // 0x8018F32C: nop

;}
RECOMP_FUNC void Meteo_Effect370_Spawn3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188F2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80188F30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188F34: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80188F38: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80188F3C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80188F40: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80188F44: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80188F48: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80188F4C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80188F50:
    // 0x80188F50: bnel        $t6, $zero, L_80188F94
    if (ctx->r14 != 0) {
        // 0x80188F54: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80188F94;
    }
    goto skip_0;
    // 0x80188F54: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80188F58: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80188F5C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80188F60: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80188F64: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80188F68: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80188F6C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80188F70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80188F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80188F78: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80188F7C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80188F80: jal         0x80188E8C
    // 0x80188F84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Meteo_Effect370_Setup2(rdram, ctx);
        goto after_0;
    // 0x80188F84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80188F88: b           L_80188FA0
    // 0x80188F8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80188FA0;
    // 0x80188F8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80188F90: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80188F94:
    // 0x80188F94: bnel        $a0, $v0, L_80188F50
    if (ctx->r4 != ctx->r2) {
        // 0x80188F98: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80188F50;
    }
    goto skip_1;
    // 0x80188F98: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80188F9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80188FA0:
    // 0x80188FA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80188FA4: jr          $ra
    // 0x80188FA8: nop

    return;
    // 0x80188FA8: nop

;}
RECOMP_FUNC void Meteo_Effect371_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80189118: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018911C: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80189120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80189124: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80189128: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018912C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80189130: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80189134: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x80189138: addiu       $a1, $a3, 0x80
    ctx->r5 = ADD32(ctx->r7, 0X80);
    // 0x8018913C: bnel        $t7, $at, L_8018915C
    if (ctx->r15 != ctx->r1) {
        // 0x80189140: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8018915C;
    }
    goto skip_0;
    // 0x80189140: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_0:
    // 0x80189144: jal         0x80060FBC
    // 0x80189148: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80189148: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8018914C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189150: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80189154: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80189158: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8018915C:
    // 0x8018915C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80189160: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189168: lwc1        $f4, 0x70($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X70);
    // 0x8018916C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80189170: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189174: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189178: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018917C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80189180: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80189184: swc1        $f8, 0x70($a3)
    MEM_W(0X70, ctx->r7) = ctx->f8.u32l;
    // 0x80189188: lwc1        $f10, 0x70($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X70);
    // 0x8018918C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80189190: nop

    // 0x80189194: bc1fl       L_801891A4
    if (!c1cs) {
        // 0x80189198: lwc1        $f16, 0x18($a3)
        ctx->f16.u32l = MEM_W(ctx->r7, 0X18);
            goto L_801891A4;
    }
    goto skip_1;
    // 0x80189198: lwc1        $f16, 0x18($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X18);
    skip_1:
    // 0x8018919C: swc1        $f0, 0x70($a3)
    MEM_W(0X70, ctx->r7) = ctx->f0.u32l;
    // 0x801891A0: lwc1        $f16, 0x18($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X18);
L_801891A4:
    // 0x801891A4: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801891A8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801891AC: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
    // 0x801891B0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801891B4: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x801891B8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801891BC: nop

    // 0x801891C0: bc1fl       L_80189204
    if (!c1cs) {
        // 0x801891C4: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80189204;
    }
    goto skip_2;
    // 0x801891C4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x801891C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801891CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801891D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801891D4: lwc1        $f2, 0x54($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X54);
    // 0x801891D8: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x801891DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801891E0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x801891E4: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x801891E8: bc1fl       L_80189204
    if (!c1cs) {
        // 0x801891EC: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80189204;
    }
    goto skip_3;
    // 0x801891EC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_3:
    // 0x801891F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801891F4: nop

    // 0x801891F8: add.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x801891FC: swc1        $f16, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->f16.u32l;
    // 0x80189200: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_80189204:
    // 0x80189204: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189208: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018920C: lwc1        $f18, 0x74($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X74);
    // 0x80189210: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80189214: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80189218: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8018921C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80189220: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80189224: bc1fl       L_80189254
    if (!c1cs) {
        // 0x80189228: lw          $t0, 0x0($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X0);
            goto L_80189254;
    }
    goto skip_4;
    // 0x80189228: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    skip_4:
    // 0x8018922C: lwc1        $f2, 0x54($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X54);
    // 0x80189230: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189234: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80189238: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8018923C: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x80189240: bc1fl       L_80189254
    if (!c1cs) {
        // 0x80189244: lw          $t0, 0x0($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X0);
            goto L_80189254;
    }
    goto skip_5;
    // 0x80189244: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    skip_5:
    // 0x80189248: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8018924C: swc1        $f8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->f8.u32l;
    // 0x80189250: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
L_80189254:
    // 0x80189254: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189258: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018925C: lwc1        $f10, 0x78($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X78);
    // 0x80189260: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80189264: nop

    // 0x80189268: bc1fl       L_80189298
    if (!c1cs) {
        // 0x8018926C: lw          $t1, 0x0($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X0);
            goto L_80189298;
    }
    goto skip_6;
    // 0x8018926C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    skip_6:
    // 0x80189270: lwc1        $f2, 0x58($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X58);
    // 0x80189274: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189278: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8018927C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80189280: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x80189284: bc1fl       L_80189298
    if (!c1cs) {
        // 0x80189288: lw          $t1, 0x0($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X0);
            goto L_80189298;
    }
    goto skip_7;
    // 0x80189288: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    skip_7:
    // 0x8018928C: add.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80189290: swc1        $f4, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f4.u32l;
    // 0x80189294: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
L_80189298:
    // 0x80189298: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8018929C: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x801892A0: lwc1        $f6, 0x78($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X78);
    // 0x801892A4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801892A8: nop

    // 0x801892AC: bc1f        L_801892D8
    if (!c1cs) {
        // 0x801892B0: nop
    
            goto L_801892D8;
    }
    // 0x801892B0: nop

    // 0x801892B4: lwc1        $f2, 0x58($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X58);
    // 0x801892B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801892BC: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801892C0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x801892C4: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x801892C8: bc1f        L_801892D8
    if (!c1cs) {
        // 0x801892CC: nop
    
            goto L_801892D8;
    }
    // 0x801892CC: nop

    // 0x801892D0: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x801892D4: swc1        $f16, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f16.u32l;
L_801892D8:
    // 0x801892D8: jal         0x8007A774
    // 0x801892DC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_1;
    // 0x801892DC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x801892E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801892E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801892E8: jr          $ra
    // 0x801892EC: nop

    return;
    // 0x801892EC: nop

;}
RECOMP_FUNC void SectorX_SxSpyborgLeftArm_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FE38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018FE3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018FE40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018FE44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018FE48: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x8018FE4C: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8018FE50: addiu       $a0, $a0, 0x6DC
    ctx->r4 = ADD32(ctx->r4, 0X6DC);
    // 0x8018FE54: bne         $t6, $zero, L_8018FEA0
    if (ctx->r14 != 0) {
        // 0x8018FE58: addiu       $a2, $s0, 0x1A0
        ctx->r6 = ADD32(ctx->r16, 0X1A0);
            goto L_8018FEA0;
    }
    // 0x8018FE58: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    // 0x8018FE5C: jal         0x8009AA20
    // 0x8018FE60: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x8018FE60: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    after_0:
    // 0x8018FE64: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8018FE68: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x8018FE6C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8018FE70: jal         0x8009F6CC
    // 0x8018FE74: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    Math_Vec3fFromAngles(rdram, ctx);
        goto after_1;
    // 0x8018FE74: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_1:
    // 0x8018FE78: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018FE7C: lh          $t7, 0x4E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4E);
    // 0x8018FE80: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x8018FE84: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018FE88: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8018FE8C: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x8018FE90: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018FE94: sh          $t8, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r24;
    // 0x8018FE98: b           L_8018FEEC
    // 0x8018FE9C: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
        goto L_8018FEEC;
    // 0x8018FE9C: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
L_8018FEA0:
    // 0x8018FEA0: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x8018FEA4: addiu       $at, $zero, 0x130
    ctx->r1 = ADD32(0, 0X130);
    // 0x8018FEA8: bnel        $t9, $at, L_8018FED0
    if (ctx->r25 != ctx->r1) {
        // 0x8018FEAC: lwc1        $f4, 0xF8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_8018FED0;
    }
    goto skip_0;
    // 0x8018FEAC: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    skip_0:
    // 0x8018FEB0: lwc1        $f10, 0x104($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X104);
    // 0x8018FEB4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8018FEB8: lwc1        $f16, 0x108($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X108);
    // 0x8018FEBC: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8018FEC0: lwc1        $f18, 0x10C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8018FEC4: b           L_8018FEE4
    // 0x8018FEC8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
        goto L_8018FEE4;
    // 0x8018FEC8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8018FECC: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
L_8018FED0:
    // 0x8018FED0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8018FED4: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8018FED8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8018FEDC: lwc1        $f8, 0x100($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X100);
    // 0x8018FEE0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_8018FEE4:
    // 0x8018FEE4: jal         0x8018FBBC
    // 0x8018FEE8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    SectorX_8018FBBC(rdram, ctx);
        goto after_2;
    // 0x8018FEE8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_2:
L_8018FEEC:
    // 0x8018FEEC: lb          $t0, 0x62($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X62);
    // 0x8018FEF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018FEF4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8018FEF8: bne         $t0, $at, L_8018FF0C
    if (ctx->r8 != ctx->r1) {
        // 0x8018FEFC: lui         $a1, 0x2912
        ctx->r5 = S32(0X2912 << 16);
            goto L_8018FF0C;
    }
    // 0x8018FEFC: lui         $a1, 0x2912
    ctx->r5 = S32(0X2912 << 16);
    // 0x8018FF00: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
    // 0x8018FF04: jal         0x8007A6F0
    // 0x8018FF08: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_3;
    // 0x8018FF08: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    after_3:
L_8018FF0C:
    // 0x8018FF0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018FF10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018FF14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018FF18: jr          $ra
    // 0x8018FF1C: nop

    return;
    // 0x8018FF1C: nop

;}
