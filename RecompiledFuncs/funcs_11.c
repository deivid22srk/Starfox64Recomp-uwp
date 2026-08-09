#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Math_CeilF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FB04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FB08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FB0C: jal         0x8001FE98
    // 0x8001FB10: nop

    __ceilf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001FB10: nop

    after_0:
    // 0x8001FB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FB18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FB1C: jr          $ra
    // 0x8001FB20: nop

    return;
    // 0x8001FB20: nop

;}
RECOMP_FUNC void Effect_Effect343_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C6FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007C700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C704: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007C708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C70C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007C710: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007C714: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007C718: jal         0x80061474
    // 0x8007C71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007C71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007C720: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C724: addiu       $t7, $zero, 0x157
    ctx->r15 = ADD32(0, 0X157);
    // 0x8007C728: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007C72C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007C730: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007C734: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007C738: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007C73C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007C740: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007C744: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007C748: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007C74C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007C750: sh          $t8, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r24;
    // 0x8007C754: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x8007C758: jal         0x80004EB0
    // 0x8007C75C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007C75C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8007C760: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C764: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007C768: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8007C76C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8007C770: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8007C774: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8007C778: bc1f        L_8007C78C
    if (!c1cs) {
        // 0x8007C77C: nop
    
            goto L_8007C78C;
    }
    // 0x8007C77C: nop

    // 0x8007C780: lh          $t9, 0x48($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X48);
    // 0x8007C784: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8007C788: sh          $t0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r8;
L_8007C78C:
    // 0x8007C78C: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x8007C790: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8007C794: bnel        $t1, $at, L_8007C7C0
    if (ctx->r9 != ctx->r1) {
        // 0x8007C798: sh          $t5, 0x4A($s0)
        MEM_H(0X4A, ctx->r16) = ctx->r13;
            goto L_8007C7C0;
    }
    goto skip_0;
    // 0x8007C798: sh          $t5, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r13;
    skip_0:
    // 0x8007C79C: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8007C7A0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007C7A4: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x8007C7A8: lw          $t3, 0x1C8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C8);
    // 0x8007C7AC: beql        $t3, $at, L_8007C7C0
    if (ctx->r11 == ctx->r1) {
        // 0x8007C7B0: sh          $t5, 0x4A($s0)
        MEM_H(0X4A, ctx->r16) = ctx->r13;
            goto L_8007C7C0;
    }
    goto skip_1;
    // 0x8007C7B0: sh          $t5, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r13;
    skip_1:
    // 0x8007C7B4: b           L_8007C7C0
    // 0x8007C7B8: sh          $t4, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r12;
        goto L_8007C7C0;
    // 0x8007C7B8: sh          $t4, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r12;
    // 0x8007C7BC: sh          $t5, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r13;
L_8007C7C0:
    // 0x8007C7C0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8007C7C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C7C8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007C7CC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007C7D0: jal         0x80004EB0
    // 0x8007C7D4: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007C7D4: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8007C7D8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007C7DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C7E0: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
    // 0x8007C7E4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8007C7E8: jal         0x80004EB0
    // 0x8007C7EC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8007C7EC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x8007C7F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C7F4: lwc1        $f2, 0x7414($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7414);
    // 0x8007C7F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C7FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8007C800: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007C804: nop

    // 0x8007C808: bc1f        L_8007C824
    if (!c1cs) {
        // 0x8007C80C: nop
    
            goto L_8007C824;
    }
    // 0x8007C80C: nop

    // 0x8007C810: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
    // 0x8007C814: sh          $t7, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r15;
    // 0x8007C818: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007C81C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8007C820: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
L_8007C824:
    // 0x8007C824: jal         0x80004EB0
    // 0x8007C828: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8007C828: nop

    after_4:
    // 0x8007C82C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C830: lwc1        $f4, 0x7418($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7418);
    // 0x8007C834: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007C838: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8007C83C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007C840: jal         0x800612B8
    // 0x8007C844: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x8007C844: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x8007C848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C84C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007C850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007C854: jr          $ra
    // 0x8007C858: nop

    return;
    // 0x8007C858: nop

;}
RECOMP_FUNC void HUD_BombCounter_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EA14: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8008EA18: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x8008EA1C: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x8008EA20: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8008EA24: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x8008EA28: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8008EA2C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8008EA30: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8008EA34: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8008EA38: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8008EA3C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8008EA40: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8008EA44: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8008EA48: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8008EA4C: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x8008EA50: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8008EA54: addiu       $t8, $t8, 0x7DA0
    ctx->r24 = ADD32(ctx->r24, 0X7DA0);
    // 0x8008EA58: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008EA5C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8008EA60: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EA64: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8008EA68: addiu       $s1, $s1, 0x19F8
    ctx->r17 = ADD32(ctx->r17, 0X19F8);
    // 0x8008EA6C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8008EA70: bne         $at, $zero, L_8008EA7C
    if (ctx->r1 != 0) {
        // 0x8008EA74: addiu       $t2, $zero, 0x9
        ctx->r10 = ADD32(0, 0X9);
            goto L_8008EA7C;
    }
    // 0x8008EA74: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8008EA78: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_8008EA7C:
    // 0x8008EA7C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8008EA80: sltiu       $at, $t3, 0x8
    ctx->r1 = ctx->r11 < 0X8 ? 1 : 0;
    // 0x8008EA84: beq         $at, $zero, L_8008F128
    if (ctx->r1 == 0) {
        // 0x8008EA88: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8008F128;
    }
    // 0x8008EA88: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008EA8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008EA90: addu        $at, $at, $t3
    gpr jr_addend_8008EA98 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8008EA94: lw          $t3, 0x7E24($at)
    ctx->r11 = ADD32(ctx->r1, 0X7E24);
    // 0x8008EA98: jr          $t3
    // 0x8008EA9C: nop

    switch (jr_addend_8008EA98 >> 2) {
        case 0: goto L_8008EAA0; break;
        case 1: goto L_8008EB2C; break;
        case 2: goto L_8008ECC4; break;
        case 3: goto L_8008EDF8; break;
        case 4: goto L_8008EE88; break;
        case 5: goto L_8008EF18; break;
        case 6: goto L_8008F004; break;
        case 7: goto L_8008F09C; break;
        default: switch_error(__func__, 0x8008EA98, 0x800D7E24);
    }
    // 0x8008EA9C: nop

L_8008EAA0:
    // 0x8008EAA0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EAA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EAA8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EAAC: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EAB0: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EAB4: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EAB8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8008EABC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8008EAC0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008EAC4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8008EAC8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EACC: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EAD0: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008EAD4: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EAD8: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8008EADC: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x8008EAE0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EAE4: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8008EAE8: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008EAEC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EAF0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EAF4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008EAF8: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008EAFC: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008EB00: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EB04: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008EB08: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008EB0C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EB10: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8008EB14: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8008EB18: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008EB1C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8008EB20: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8008EB24: b           L_8008F16C
    // 0x8008EB28: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
        goto L_8008F16C;
    // 0x8008EB28: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_8008EB2C:
    // 0x8008EB2C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008EB30: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008EB34: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008EB38: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008EB40: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x8008EB44: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8008EB48: nop

    // 0x8008EB4C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008EB50: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8008EB54: nop

    // 0x8008EB58: bc1f        L_8008EC6C
    if (!c1cs) {
        // 0x8008EB5C: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_8008EC6C;
    }
    // 0x8008EB5C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8008EB60: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8008EB64: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8008EB68: bne         $at, $zero, L_8008EBB8
    if (ctx->r1 != 0) {
        // 0x8008EB6C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8008EBB8;
    }
    // 0x8008EB6C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008EB70: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EB74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EB78: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EB7C: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EB80: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EB84: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EB88: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EB8C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EB90: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EB94: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8008EB98: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EB9C: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EBA0: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008EBA4: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EBA8: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EBAC: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008EBB0: b           L_8008F16C
    // 0x8008EBB4: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
        goto L_8008F16C;
    // 0x8008EBB4: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
L_8008EBB8:
    // 0x8008EBB8: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8008EBBC: bne         $v1, $v0, L_8008EC1C
    if (ctx->r3 != ctx->r2) {
        // 0x8008EBC0: lui         $s4, 0x800D
        ctx->r20 = S32(0X800D << 16);
            goto L_8008EC1C;
    }
    // 0x8008EBC0: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EBC4: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EBC8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EBCC: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008EBD0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8008EBD4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8008EBD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EBDC: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EBE0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EBE4: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EBE8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EBEC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EBF0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EBF4: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
    // 0x8008EBF8: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8008EBFC: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8008EC00: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EC04: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EC08: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008EC0C: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EC10: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EC14: b           L_8008F16C
    // 0x8008EC18: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
        goto L_8008F16C;
    // 0x8008EC18: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
L_8008EC1C:
    // 0x8008EC1C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EC20: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008EC24: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8008EC28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EC2C: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EC30: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EC34: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EC38: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EC3C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EC40: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EC44: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
    // 0x8008EC48: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x8008EC4C: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x8008EC50: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EC54: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EC58: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008EC5C: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EC60: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EC64: b           L_8008F16C
    // 0x8008EC68: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
        goto L_8008F16C;
    // 0x8008EC68: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
L_8008EC6C:
    // 0x8008EC6C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8008EC70: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EC74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EC78: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EC7C: bc1f        L_8008EC8C
    if (!c1cs) {
        // 0x8008EC80: addiu       $s4, $s4, 0x19F0
        ctx->r20 = ADD32(ctx->r20, 0X19F0);
            goto L_8008EC8C;
    }
    // 0x8008EC80: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008EC84: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8008EC88: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
L_8008EC8C:
    // 0x8008EC8C: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EC90: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EC94: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EC98: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EC9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008ECA0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008ECA4: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8008ECA8: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008ECAC: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008ECB0: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008ECB4: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008ECB8: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008ECBC: b           L_8008F16C
    // 0x8008ECC0: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
        goto L_8008F16C;
    // 0x8008ECC0: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
L_8008ECC4:
    // 0x8008ECC4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008ECC8: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008ECCC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8008ECD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008ECD4: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8008ECD8: addiu       $v0, $t5, -0x1
    ctx->r2 = ADD32(ctx->r13, -0X1);
    // 0x8008ECDC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008ECE0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8008ECE4: beq         $at, $zero, L_8008ED48
    if (ctx->r1 == 0) {
        // 0x8008ECE8: sw          $t7, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r15;
            goto L_8008ED48;
    }
    // 0x8008ECE8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8008ECEC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008ECF0: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008ECF4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008ECF8: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008ECFC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008ED00: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8008ED04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008ED08: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008ED0C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008ED10: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008ED14: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008ED18: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008ED1C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008ED20: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8008ED24: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8008ED28: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008ED2C: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008ED30: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008ED34: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008ED38: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008ED3C: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008ED40: b           L_8008F16C
    // 0x8008ED44: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
        goto L_8008F16C;
    // 0x8008ED44: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
L_8008ED48:
    // 0x8008ED48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008ED4C: bnel        $v0, $at, L_8008EDB4
    if (ctx->r2 != ctx->r1) {
        // 0x8008ED50: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8008EDB4;
    }
    goto skip_0;
    // 0x8008ED50: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    skip_0:
    // 0x8008ED54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008ED58: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008ED5C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008ED60: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008ED64: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008ED68: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8008ED6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008ED70: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008ED74: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008ED78: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008ED7C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008ED80: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008ED84: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008ED88: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8008ED8C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8008ED90: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008ED94: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008ED98: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008ED9C: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EDA0: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EDA4: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008EDA8: b           L_8008F16C
    // 0x8008EDAC: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
        goto L_8008F16C;
    // 0x8008EDAC: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
    // 0x8008EDB0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
L_8008EDB4:
    // 0x8008EDB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EDB8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008EDBC: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EDC0: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EDC4: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EDC8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EDCC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EDD0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EDD4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EDD8: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EDDC: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EDE0: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008EDE4: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EDE8: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EDEC: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008EDF0: b           L_8008F16C
    // 0x8008EDF4: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
        goto L_8008F16C;
    // 0x8008EDF4: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
L_8008EDF8:
    // 0x8008EDF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008EDFC: lwc1        $f18, 0x7E44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7E44);
    // 0x8008EE00: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EE04: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008EE08: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008EE0C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008EE10: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x8008EE14: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008EE18: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008EE1C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8008EE20: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8008EE24: jal         0x8009BC2C
    // 0x8008EE28: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8008EE28: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8008EE2C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008EE30: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EE34: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EE38: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8008EE3C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EE40: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EE44: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EE48: bc1f        L_8008EE64
    if (!c1cs) {
        // 0x8008EE4C: addiu       $s2, $s2, 0x1774
        ctx->r18 = ADD32(ctx->r18, 0X1774);
            goto L_8008EE64;
    }
    // 0x8008EE4C: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008EE50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008EE54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008EE58: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008EE5C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8008EE60: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
L_8008EE64:
    // 0x8008EE64: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EE68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EE6C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EE70: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EE74: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EE78: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EE7C: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EE80: b           L_8008F16C
    // 0x8008EE84: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
        goto L_8008F16C;
    // 0x8008EE84: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
L_8008EE88:
    // 0x8008EE88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008EE8C: lwc1        $f6, 0x7E48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7E48);
    // 0x8008EE90: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EE94: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008EE98: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8008EE9C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008EEA0: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8008EEA4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008EEA8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008EEAC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8008EEB0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8008EEB4: jal         0x8009BC2C
    // 0x8008EEB8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8008EEB8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8008EEBC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008EEC0: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EEC4: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EEC8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8008EECC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EED0: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EED4: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008EED8: bc1f        L_8008EEF4
    if (!c1cs) {
        // 0x8008EEDC: addiu       $s2, $s2, 0x1774
        ctx->r18 = ADD32(ctx->r18, 0X1774);
            goto L_8008EEF4;
    }
    // 0x8008EEDC: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008EEE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008EEE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008EEE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008EEEC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8008EEF0: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
L_8008EEF4:
    // 0x8008EEF4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EEF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EEFC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EF00: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EF04: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EF08: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EF0C: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EF10: b           L_8008F16C
    // 0x8008EF14: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
        goto L_8008F16C;
    // 0x8008EF14: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
L_8008EF18:
    // 0x8008EF18: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008EF1C: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008EF20: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8008EF24: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8008EF28: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8008EF2C: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EF30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008EF34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008EF38: lwc1        $f6, 0x7E4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7E4C);
    // 0x8008EF3C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008EF40: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008EF44: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8008EF48: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008EF4C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8008EF50: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008EF54: mflo        $t2
    ctx->r10 = lo;
    // 0x8008EF58: addiu       $t3, $t2, -0xA
    ctx->r11 = ADD32(ctx->r10, -0XA);
    // 0x8008EF5C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8008EF60: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008EF64: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8008EF68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008EF6C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8008EF70: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008EF74: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8008EF78: jal         0x8009BC2C
    // 0x8008EF7C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8008EF7C: nop

    after_2:
    // 0x8008EF80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008EF84: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008EF88: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008EF8C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8008EF90: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EF94: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008EF98: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008EF9C: bc1f        L_8008EFD8
    if (!c1cs) {
        // 0x8008EFA0: addiu       $s2, $s2, 0x1774
        ctx->r18 = ADD32(ctx->r18, 0X1774);
            goto L_8008EFD8;
    }
    // 0x8008EFA0: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008EFA4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8008EFA8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8008EFAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008EFB0: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EFB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008EFB8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8008EFBC: mflo        $t6
    ctx->r14 = lo;
    // 0x8008EFC0: addiu       $t7, $t6, -0xA
    ctx->r15 = ADD32(ctx->r14, -0XA);
    // 0x8008EFC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8008EFC8: nop

    // 0x8008EFCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008EFD0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008EFD4: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
L_8008EFD8:
    // 0x8008EFD8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008EFDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008EFE0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008EFE4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008EFE8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008EFEC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008EFF0: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008EFF4: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008EFF8: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008EFFC: b           L_8008F16C
    // 0x8008F000: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
        goto L_8008F16C;
    // 0x8008F000: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
L_8008F004:
    // 0x8008F004: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008F008: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008F00C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008F010: lwc1        $f4, 0x7E50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E50);
    // 0x8008F014: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008F018: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008F01C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8008F020: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008F024: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008F028: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008F02C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8008F030: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008F034: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008F038: jal         0x8009BC2C
    // 0x8008F03C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8008F03C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8008F040: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008F044: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008F048: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008F04C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8008F050: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008F054: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008F058: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008F05C: bc1f        L_8008F078
    if (!c1cs) {
        // 0x8008F060: addiu       $s2, $s2, 0x1774
        ctx->r18 = ADD32(ctx->r18, 0X1774);
            goto L_8008F078;
    }
    // 0x8008F060: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008F064: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8008F068: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8008F06C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8008F070: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
    // 0x8008F074: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
L_8008F078:
    // 0x8008F078: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F07C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008F080: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008F084: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008F088: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008F08C: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008F090: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008F094: b           L_8008F16C
    // 0x8008F098: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
        goto L_8008F16C;
    // 0x8008F098: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
L_8008F09C:
    // 0x8008F09C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8008F0A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008F0A4: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008F0A8: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
    // 0x8008F0AC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8008F0B0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008F0B4: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x8008F0B8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008F0BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008F0C0: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x8008F0C4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8008F0C8: jal         0x8009BC2C
    // 0x8008F0CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8008F0CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8008F0D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008F0D4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008F0D8: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008F0DC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8008F0E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008F0E4: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008F0E8: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008F0EC: bc1f        L_8008F104
    if (!c1cs) {
        // 0x8008F0F0: addiu       $s2, $s2, 0x1774
        ctx->r18 = ADD32(ctx->r18, 0X1774);
            goto L_8008F104;
    }
    // 0x8008F0F0: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008F0F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008F0F8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8008F0FC: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
    // 0x8008F100: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
L_8008F104:
    // 0x8008F104: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F108: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008F10C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008F110: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008F114: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008F118: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008F11C: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008F120: b           L_8008F16C
    // 0x8008F124: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
        goto L_8008F16C;
    // 0x8008F124: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
L_8008F128:
    // 0x8008F128: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008F12C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8008F130: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8008F134: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008F138: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F13C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008F140: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008F144: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008F148: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008F14C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008F150: addiu       $v0, $v0, 0x1784
    ctx->r2 = ADD32(ctx->r2, 0X1784);
    // 0x8008F154: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008F158: addiu       $a1, $a1, 0x177C
    ctx->r5 = ADD32(ctx->r5, 0X177C);
    // 0x8008F15C: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008F160: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8008F164: addiu       $s2, $s2, 0x1774
    ctx->r18 = ADD32(ctx->r18, 0X1774);
    // 0x8008F168: addiu       $s4, $s4, 0x19F0
    ctx->r20 = ADD32(ctx->r20, 0X19F0);
L_8008F16C:
    // 0x8008F16C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8008F170: lbu         $t5, 0x46E0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X46E0);
    // 0x8008F174: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8008F178: bnel        $t5, $zero, L_8008F1AC
    if (ctx->r13 != 0) {
        // 0x8008F17C: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8008F1AC;
    }
    goto skip_1;
    // 0x8008F17C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x8008F180: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8008F184: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008F188: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x8008F18C: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008F190: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x8008F194: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8008F198: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8008F19C: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8008F1A0: b           L_8008F1D4
    // 0x8008F1A4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
        goto L_8008F1D4;
    // 0x8008F1A4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8008F1A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8008F1AC:
    // 0x8008F1AC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8008F1B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008F1B4: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x8008F1B8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008F1BC: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x8008F1C0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008F1C4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8008F1C8: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8008F1CC: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8008F1D0: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8008F1D4:
    // 0x8008F1D4: jal         0x800BA4F0
    // 0x8008F1D8: nop

    RCP_SetupDL_78(rdram, ctx);
        goto after_5;
    // 0x8008F1D8: nop

    after_5:
    // 0x8008F1DC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008F1E0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F1E4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008F1E8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8008F1EC: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8008F1F0: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008F1F4: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008F1F8: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x8008F1FC: lui         $s1, 0xFA00
    ctx->r17 = S32(0XFA00 << 16);
    // 0x8008F200: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8008F204: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008F208: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8008F20C: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x8008F210: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8008F214: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008F218: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008F21C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8008F220: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8008F224: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8008F228: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8008F22C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8008F230: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8008F234: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8008F238: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x8008F23C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8008F240: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x8008F244: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8008F248: lw          $t2, 0x1708($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1708);
    // 0x8008F24C: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x8008F250: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8008F254: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x8008F258: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x8008F25C: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x8008F260: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008F264: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008F268: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8008F26C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8008F270: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8008F274: bnel        $t9, $at, L_8008F284
    if (ctx->r25 != ctx->r1) {
        // 0x8008F278: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_8008F284;
    }
    goto skip_2;
    // 0x8008F278: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    skip_2:
    // 0x8008F27C: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x8008F280: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
L_8008F284:
    // 0x8008F284: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8008F288: beq         $at, $zero, L_8008F91C
    if (ctx->r1 == 0) {
        // 0x8008F28C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8008F91C;
    }
    // 0x8008F28C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008F290: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008F294: addu        $at, $at, $t7
    gpr jr_addend_8008F29C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008F298: lw          $t7, 0x7E54($at)
    ctx->r15 = ADD32(ctx->r1, 0X7E54);
    // 0x8008F29C: jr          $t7
    // 0x8008F2A0: nop

    switch (jr_addend_8008F29C >> 2) {
        case 0: goto L_8008F2A4; break;
        case 1: goto L_8008F42C; break;
        case 2: goto L_8008F524; break;
        case 3: goto L_8008F5D0; break;
        case 4: goto L_8008F6A8; break;
        case 5: goto L_8008F7C4; break;
        case 6: goto L_8008F8B8; break;
        default: switch_error(__func__, 0x8008F29C, 0x800D7E54);
    }
    // 0x8008F2A0: nop

L_8008F2A4:
    // 0x8008F2A4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008F2A8: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F2AC: addiu       $a1, $s1, 0x16B0
    ctx->r5 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F2B0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8008F2B4: bne         $at, $zero, L_8008F3AC
    if (ctx->r1 != 0) {
        // 0x8008F2B8: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_8008F3AC;
    }
    // 0x8008F2B8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8008F2BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F2C0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F2C4: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F2C8: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8008F2CC: addiu       $a2, $s2, 0x1730
    ctx->r6 = ADD32(ctx->r18, 0X1730);
    // 0x8008F2D0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008F2D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F2D8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F2DC: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x8008F2E0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F2E4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F2E8: jal         0x8009C320
    // 0x8008F2EC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_6;
    // 0x8008F2EC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x8008F2F0: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8008F2F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008F2F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008F2FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008F300: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F304: lwc1        $f18, 0x177C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X177C);
    // 0x8008F308: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F30C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F310: add.s       $f12, $f24, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f24.fl + ctx->f10.fl;
    // 0x8008F314: lwc1        $f10, 0x1784($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1784);
    // 0x8008F318: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008F31C: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008F320: add.s       $f14, $f26, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f26.fl + ctx->f16.fl;
    // 0x8008F324: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8008F328: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8008F32C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8008F330: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8008F334: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8008F338: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008F33C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8008F340: jal         0x8008DCB0
    // 0x8008F344: nop

    HUD_VS_X_Draw(rdram, ctx);
        goto after_7;
    // 0x8008F344: nop

    after_7:
    // 0x8008F348: add.s       $f14, $f26, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x8008F34C: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x8008F350: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008F354: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F358: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008F35C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008F360: add.s       $f12, $f24, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x8008F364: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F368: lwc1        $f22, 0x177C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X177C);
    // 0x8008F36C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8008F370: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F374: lwc1        $f16, 0x1784($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1784);
    // 0x8008F378: trunc.w.s   $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x8008F37C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8008F380: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008F384: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8008F388: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8008F38C: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008F390: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8008F394: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8008F398: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008F39C: jal         0x8008DD78
    // 0x8008F3A0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    HUD_VS_LivesCount_Draw(rdram, ctx);
        goto after_8;
    // 0x8008F3A0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_8:
    // 0x8008F3A4: b           L_8008F920
    // 0x8008F3A8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8008F920;
    // 0x8008F3A8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F3AC:
    // 0x8008F3AC: bltz        $v1, L_8008F91C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8008F3B0: sll         $s0, $v1, 2
        ctx->r16 = S32(ctx->r3 << 2);
            goto L_8008F91C;
    }
    // 0x8008F3B0: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x8008F3B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008F3B8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008F3BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F3C0: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8008F3C4: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F3C8: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F3CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F3D0: addiu       $s1, $s1, 0x16B0
    ctx->r17 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F3D4: addiu       $s2, $s2, 0x1730
    ctx->r18 = ADD32(ctx->r18, 0X1730);
    // 0x8008F3D8: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x8008F3DC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_8008F3E0:
    // 0x8008F3E0: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8008F3E4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008F3E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008F3EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F3F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F3F4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F3F8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F3FC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F400: sub.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x8008F404: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F408: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8008F40C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8008F410: jal         0x8009C320
    // 0x8008F414: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_9;
    // 0x8008F414: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8008F418: addiu       $s0, $s0, -0xA
    ctx->r16 = ADD32(ctx->r16, -0XA);
    // 0x8008F41C: bgezl       $s0, L_8008F3E0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8008F420: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_8008F3E0;
    }
    goto skip_3;
    // 0x8008F420: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_3:
    // 0x8008F424: b           L_8008F920
    // 0x8008F428: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8008F920;
    // 0x8008F428: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F42C:
    // 0x8008F42C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F430: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F434: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008F438: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008F43C: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F440: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F444: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F448: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8008F44C: addiu       $s2, $s2, 0x1730
    ctx->r18 = ADD32(ctx->r18, 0X1730);
    // 0x8008F450: addiu       $s1, $s1, 0x16B0
    ctx->r17 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F454: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8008F458: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008F45C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F460: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F464: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8008F468: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F46C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F470: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F474: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8008F478: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F47C: jal         0x8009C320
    // 0x8008F480: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_10;
    // 0x8008F480: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x8008F484: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F488: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8008F48C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008F490: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8008F494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F498: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F49C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F4A0: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8008F4A4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F4A8: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F4AC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F4B0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8008F4B4: jal         0x8009C320
    // 0x8008F4B8: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_11;
    // 0x8008F4B8: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x8008F4BC: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F4C0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008F4C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008F4C8: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x8008F4CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F4D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F4D4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F4D8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8008F4DC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F4E0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F4E4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F4E8: jal         0x8009C320
    // 0x8008F4EC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_12;
    // 0x8008F4EC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x8008F4F0: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8008F4F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008F4F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F4FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F500: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F504: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F508: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x8008F50C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F510: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F514: jal         0x8009C320
    // 0x8008F518: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_13;
    // 0x8008F518: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_13:
    // 0x8008F51C: b           L_8008F920
    // 0x8008F520: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8008F920;
    // 0x8008F520: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F524:
    // 0x8008F524: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8008F528: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008F52C: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F530: bltz        $v1, L_8008F91C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8008F534: sll         $s0, $v1, 2
        ctx->r16 = S32(ctx->r3 << 2);
            goto L_8008F91C;
    }
    // 0x8008F534: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x8008F538: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008F53C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F540: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8008F544: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F548: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F54C: addiu       $s1, $s1, 0x16B0
    ctx->r17 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F550: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x8008F554: addiu       $s2, $s2, 0x1730
    ctx->r18 = ADD32(ctx->r18, 0X1730);
    // 0x8008F558: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
L_8008F55C:
    // 0x8008F55C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008F560: bne         $s0, $zero, L_8008F580
    if (ctx->r16 != 0) {
        // 0x8008F564: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8008F580;
    }
    // 0x8008F564: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008F568: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F56C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008F570: nop

    // 0x8008F574: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008F578: b           L_8008F588
    // 0x8008F57C: sub.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f10.fl;
        goto L_8008F588;
    // 0x8008F57C: sub.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f10.fl;
L_8008F580:
    // 0x8008F580: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F584: sub.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f10.fl;
L_8008F588:
    // 0x8008F588: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8008F58C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008F590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F594: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x8008F598: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F59C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F5A0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F5A4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8008F5A8: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F5AC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F5B0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8008F5B4: jal         0x8009C320
    // 0x8008F5B8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_14;
    // 0x8008F5B8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x8008F5BC: addiu       $s0, $s0, -0xA
    ctx->r16 = ADD32(ctx->r16, -0XA);
    // 0x8008F5C0: bgezl       $s0, L_8008F55C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8008F5C4: mtc1        $s0, $f8
        ctx->f8.u32l = ctx->r16;
            goto L_8008F55C;
    }
    goto skip_4;
    // 0x8008F5C4: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    skip_4:
    // 0x8008F5C8: b           L_8008F920
    // 0x8008F5CC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8008F920;
    // 0x8008F5CC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F5D0:
    // 0x8008F5D0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8008F5D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008F5D8: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F5DC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8008F5E0: bltz        $v1, L_8008F650
    if (SIGNED(ctx->r3) < 0) {
        // 0x8008F5E4: sll         $s0, $v1, 2
        ctx->r16 = S32(ctx->r3 << 2);
            goto L_8008F650;
    }
    // 0x8008F5E4: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x8008F5E8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008F5EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F5F0: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8008F5F4: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F5F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F5FC: addiu       $s1, $s1, 0x16B0
    ctx->r17 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F600: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x8008F604: addiu       $s2, $s2, 0x1730
    ctx->r18 = ADD32(ctx->r18, 0X1730);
    // 0x8008F608: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_8008F60C:
    // 0x8008F60C: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8008F610: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008F614: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008F618: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F61C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F620: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F624: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F628: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F62C: sub.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x8008F630: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F634: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8008F638: add.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8008F63C: jal         0x8009C320
    // 0x8008F640: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_15;
    // 0x8008F640: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x8008F644: addiu       $s0, $s0, -0xA
    ctx->r16 = ADD32(ctx->r16, -0XA);
    // 0x8008F648: bgezl       $s0, L_8008F60C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8008F64C: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_8008F60C;
    }
    goto skip_5;
    // 0x8008F64C: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_5:
L_8008F650:
    // 0x8008F650: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F654: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F658: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8008F65C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008F660: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F664: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F668: add.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x8008F66C: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F670: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8008F674: addiu       $a2, $s2, 0x1730
    ctx->r6 = ADD32(ctx->r18, 0X1730);
    // 0x8008F678: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008F67C: addiu       $a1, $s1, 0x16B0
    ctx->r5 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F680: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008F684: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F688: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8008F68C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F690: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F694: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F698: jal         0x8009C320
    // 0x8008F69C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_16;
    // 0x8008F69C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x8008F6A0: b           L_8008F920
    // 0x8008F6A4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8008F920;
    // 0x8008F6A4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F6A8:
    // 0x8008F6A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F6AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F6B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008F6B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008F6B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008F6BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008F6C0: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F6C4: add.s       $f4, $f24, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x8008F6C8: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F6CC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8008F6D0: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F6D4: addiu       $s2, $s2, 0x1730
    ctx->r18 = ADD32(ctx->r18, 0X1730);
    // 0x8008F6D8: addiu       $s1, $s1, 0x16B0
    ctx->r17 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F6DC: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8008F6E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008F6E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F6E8: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8008F6EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F6F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F6F4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F6F8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8008F6FC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F700: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F704: jal         0x8009C320
    // 0x8008F708: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_17;
    // 0x8008F708: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_17:
    // 0x8008F70C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8008F710: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008F714: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F718: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8008F71C: add.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x8008F720: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008F724: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F728: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8008F72C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F730: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F734: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F738: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8008F73C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F740: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F744: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8008F748: jal         0x8009C320
    // 0x8008F74C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_18;
    // 0x8008F74C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_18:
    // 0x8008F750: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008F754: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008F758: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F75C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8008F760: add.s       $f6, $f24, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x8008F764: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008F768: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F76C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F770: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8008F774: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F778: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F77C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F780: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8008F784: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F788: jal         0x8009C320
    // 0x8008F78C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_19;
    // 0x8008F78C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_19:
    // 0x8008F790: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008F794: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008F798: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F79C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F7A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F7A4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F7A8: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x8008F7AC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F7B0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F7B4: jal         0x8009C320
    // 0x8008F7B8: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_20;
    // 0x8008F7B8: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x8008F7BC: b           L_8008F920
    // 0x8008F7C0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8008F920;
    // 0x8008F7C0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F7C4:
    // 0x8008F7C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008F7C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008F7CC: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F7D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F7D4: lwc1        $f18, 0x177C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X177C);
    // 0x8008F7D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F7DC: add.s       $f12, $f24, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f24.fl + ctx->f16.fl;
    // 0x8008F7E0: lwc1        $f16, 0x1784($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1784);
    // 0x8008F7E4: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008F7E8: add.s       $f14, $f26, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f26.fl + ctx->f4.fl;
    // 0x8008F7EC: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8008F7F0: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8008F7F4: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8008F7F8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8008F7FC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8008F800: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008F804: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8008F808: jal         0x8008DCB0
    // 0x8008F80C: nop

    HUD_VS_X_Draw(rdram, ctx);
        goto after_21;
    // 0x8008F80C: nop

    after_21:
    // 0x8008F810: lwc1        $f22, 0x0($s4)
    ctx->f22.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8008F814: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F818: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F81C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8008F820: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008F824: add.s       $f14, $f26, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x8008F828: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F82C: addiu       $t0, $t0, 0x1780
    ctx->r8 = ADD32(ctx->r8, 0X1780);
    // 0x8008F830: add.s       $f18, $f24, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x8008F834: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008F838: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F83C: lwc1        $f10, 0x177C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X177C);
    // 0x8008F840: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8008F844: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008F848: lwc1        $f8, 0x1784($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1784);
    // 0x8008F84C: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8008F850: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8008F854: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008F858: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8008F85C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8008F860: addiu       $t1, $t1, 0x19F4
    ctx->r9 = ADD32(ctx->r9, 0X19F4);
    // 0x8008F864: add.s       $f12, $f18, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x8008F868: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8008F86C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8008F870: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008F874: jal         0x8008DD78
    // 0x8008F878: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    HUD_VS_LivesCount_Draw(rdram, ctx);
        goto after_22;
    // 0x8008F878: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_22:
    // 0x8008F87C: lui         $s1, 0x101
    ctx->r17 = S32(0X101 << 16);
    // 0x8008F880: lui         $s2, 0x101
    ctx->r18 = S32(0X101 << 16);
    // 0x8008F884: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8008F888: addiu       $a2, $s2, 0x1730
    ctx->r6 = ADD32(ctx->r18, 0X1730);
    // 0x8008F88C: addiu       $a1, $s1, 0x16B0
    ctx->r5 = ADD32(ctx->r17, 0X16B0);
    // 0x8008F890: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008F894: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F898: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008F89C: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x8008F8A0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F8A4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F8A8: jal         0x8009C320
    // 0x8008F8AC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_23;
    // 0x8008F8AC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_23:
    // 0x8008F8B0: b           L_8008F920
    // 0x8008F8B4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8008F920;
    // 0x8008F8B4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F8B8:
    // 0x8008F8B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F8BC: jal         0x800B8DD0
    // 0x8008F8C0: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_24;
    // 0x8008F8C0: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_24:
    // 0x8008F8C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008F8C8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008F8CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008F8D0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8008F8D4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8008F8D8: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x8008F8DC: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8008F8E0: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x8008F8E4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008F8E8: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x8008F8EC: add.s       $f10, $f24, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x8008F8F0: lui         $a2, 0x300
    ctx->r6 = S32(0X300 << 16);
    // 0x8008F8F4: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8008F8F8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008F8FC: addiu       $a2, $a2, 0x120
    ctx->r6 = ADD32(ctx->r6, 0X120);
    // 0x8008F900: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8008F904: addiu       $a1, $a1, 0x90
    ctx->r5 = ADD32(ctx->r5, 0X90);
    // 0x8008F908: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8008F90C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008F910: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008F914: jal         0x8009C320
    // 0x8008F918: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_25;
    // 0x8008F918: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_25:
L_8008F91C:
    // 0x8008F91C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008F920:
    // 0x8008F920: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8008F924: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8008F928: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8008F92C: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x8008F930: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8008F934: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8008F938: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8008F93C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8008F940: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8008F944: jr          $ra
    // 0x8008F948: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8008F948: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_tank_80045130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045130: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80045134: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80045138: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004513C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80045140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80045144: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80045148: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004514C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80045150: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80045154: addiu       $a0, $s0, 0x170
    ctx->r4 = ADD32(ctx->r16, 0X170);
    // 0x80045158: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004515C: jal         0x8009BC2C
    // 0x80045160: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80045160: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80045164: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80045168: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8004516C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80045170: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x80045174: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80045178: jal         0x8009BC2C
    // 0x8004517C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8004517C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80045180: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80045184: lw          $t6, 0x797C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X797C);
    // 0x80045188: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x8004518C: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x80045190: beql        $t7, $zero, L_80045244
    if (ctx->r15 == 0) {
        // 0x80045194: andi        $t5, $v0, 0x10
        ctx->r13 = ctx->r2 & 0X10;
            goto L_80045244;
    }
    goto skip_0;
    // 0x80045194: andi        $t5, $v0, 0x10
    ctx->r13 = ctx->r2 & 0X10;
    skip_0:
    // 0x80045198: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8004519C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800451A0: sb          $v1, 0x48C($s0)
    MEM_B(0X48C, ctx->r16) = ctx->r3;
    // 0x800451A4: beq         $t8, $zero, L_80045230
    if (ctx->r24 == 0) {
        // 0x800451A8: addiu       $t3, $zero, 0xA
        ctx->r11 = ADD32(0, 0XA);
            goto L_80045230;
    }
    // 0x800451A8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800451AC: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800451B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800451B4: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x800451B8: nop

    // 0x800451BC: bc1fl       L_80045234
    if (!c1cs) {
        // 0x800451C0: sw          $t3, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r11;
            goto L_80045234;
    }
    goto skip_1;
    // 0x800451C0: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
    skip_1:
    // 0x800451C4: lwc1        $f6, 0x2BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800451C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800451CC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800451D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800451D4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800451D8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800451DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800451E0: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x800451E4: bc1f        L_80045230
    if (!c1cs) {
        // 0x800451E8: lui         $a0, 0x1100
        ctx->r4 = S32(0X1100 << 16);
            goto L_80045230;
    }
    // 0x800451E8: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x800451EC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800451F0: sw          $t9, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r25;
    // 0x800451F4: sw          $t0, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r8;
    // 0x800451F8: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    // 0x800451FC: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
    // 0x80045200: sb          $v1, 0x494($s0)
    MEM_B(0X494, ctx->r16) = ctx->r3;
    // 0x80045204: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80045208: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8004520C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80045210: ori         $a0, $a0, 0xA
    ctx->r4 = ctx->r4 | 0XA;
    // 0x80045214: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80045218: jal         0x80019218
    // 0x8004521C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8004521C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80045220: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80045224: lw          $t2, 0x797C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X797C);
    // 0x80045228: b           L_80045240
    // 0x8004522C: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
        goto L_80045240;
    // 0x8004522C: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_80045230:
    // 0x80045230: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
L_80045234:
    // 0x80045234: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80045238: lw          $t4, 0x797C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X797C);
    // 0x8004523C: lhu         $v0, 0x0($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X0);
L_80045240:
    // 0x80045240: andi        $t5, $v0, 0x10
    ctx->r13 = ctx->r2 & 0X10;
L_80045244:
    // 0x80045244: beq         $t5, $zero, L_800452E0
    if (ctx->r13 == 0) {
        // 0x80045248: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800452E0;
    }
    // 0x80045248: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8004524C: lw          $t6, 0x1E4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E4);
    // 0x80045250: sb          $v1, 0x48C($s0)
    MEM_B(0X48C, ctx->r16) = ctx->r3;
    // 0x80045254: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80045258: beql        $t6, $zero, L_800452E0
    if (ctx->r14 == 0) {
        // 0x8004525C: sw          $t1, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r9;
            goto L_800452E0;
    }
    goto skip_2;
    // 0x8004525C: sw          $t1, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r9;
    skip_2:
    // 0x80045260: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80045264: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80045268: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x8004526C: nop

    // 0x80045270: bc1fl       L_800452E0
    if (!c1cs) {
        // 0x80045274: sw          $t1, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r9;
            goto L_800452E0;
    }
    goto skip_3;
    // 0x80045274: sw          $t1, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r9;
    skip_3:
    // 0x80045278: lwc1        $f16, 0x2BC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x8004527C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80045280: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x80045284: addiu       $v0, $zero, -0x14
    ctx->r2 = ADD32(0, -0X14);
    // 0x80045288: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8004528C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80045290: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80045294: ori         $a0, $a0, 0xA
    ctx->r4 = ctx->r4 | 0XA;
    // 0x80045298: bc1f        L_800452DC
    if (!c1cs) {
        // 0x8004529C: addiu       $a1, $s0, 0x460
        ctx->r5 = ADD32(ctx->r16, 0X460);
            goto L_800452DC;
    }
    // 0x8004529C: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x800452A0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800452A4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800452A8: sw          $t7, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r15;
    // 0x800452AC: sw          $t8, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r24;
    // 0x800452B0: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    // 0x800452B4: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
    // 0x800452B8: sb          $v1, 0x494($s0)
    MEM_B(0X494, ctx->r16) = ctx->r3;
    // 0x800452BC: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x800452C0: addiu       $a3, $t9, 0x5D34
    ctx->r7 = ADD32(ctx->r25, 0X5D34);
    // 0x800452C4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800452C8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800452CC: jal         0x80019218
    // 0x800452D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800452D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800452D4: b           L_800452E0
    // 0x800452D8: nop

        goto L_800452E0;
    // 0x800452D8: nop

L_800452DC:
    // 0x800452DC: sw          $t1, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r9;
L_800452E0:
    // 0x800452E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800452E4: lwc1        $f20, 0x5688($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5688);
    // 0x800452E8: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800452EC: mul.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800452F0: jal         0x80023090
    // 0x800452F4: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800452F4: nop

    after_4:
    // 0x800452F8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800452FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045300: lwc1        $f8, 0x130($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X130);
    // 0x80045304: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80045308: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8004530C: mul.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80045310: jal         0x80023090
    // 0x80045314: swc1        $f0, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x80045314: swc1        $f0, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x80045318: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004531C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80045320: lwc1        $f16, 0x18C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80045324: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80045328: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8004532C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80045330: swc1        $f18, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f18.u32l;
    // 0x80045334: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80045338: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8004533C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80045340: jr          $ra
    // 0x80045344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80045344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Object_Dying(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800690D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800690D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800690D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800690DC: slti        $at, $a1, 0xE9
    ctx->r1 = SIGNED(ctx->r5) < 0XE9 ? 1 : 0;
    // 0x800690E0: bne         $at, $zero, L_80069104
    if (ctx->r1 != 0) {
        // 0x800690E4: addiu       $at, $zero, 0x132
        ctx->r1 = ADD32(0, 0X132);
            goto L_80069104;
    }
    // 0x800690E4: addiu       $at, $zero, 0x132
    ctx->r1 = ADD32(0, 0X132);
    // 0x800690E8: beq         $a1, $at, L_80069370
    if (ctx->r5 == ctx->r1) {
        // 0x800690EC: sll         $t6, $a2, 7
        ctx->r14 = S32(ctx->r6 << 7);
            goto L_80069370;
    }
    // 0x800690EC: sll         $t6, $a2, 7
    ctx->r14 = S32(ctx->r6 << 7);
    // 0x800690F0: addiu       $at, $zero, 0x13F
    ctx->r1 = ADD32(0, 0X13F);
    // 0x800690F4: beq         $a1, $at, L_800693C0
    if (ctx->r5 == ctx->r1) {
        // 0x800690F8: sll         $t0, $a2, 7
        ctx->r8 = S32(ctx->r6 << 7);
            goto L_800693C0;
    }
    // 0x800690F8: sll         $t0, $a2, 7
    ctx->r8 = S32(ctx->r6 << 7);
    // 0x800690FC: b           L_800693DC
    // 0x80069100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x80069100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069104:
    // 0x80069104: slti        $at, $a1, 0xCB
    ctx->r1 = SIGNED(ctx->r5) < 0XCB ? 1 : 0;
    // 0x80069108: bne         $at, $zero, L_80069124
    if (ctx->r1 != 0) {
        // 0x8006910C: addiu       $t6, $a1, -0xB5
        ctx->r14 = ADD32(ctx->r5, -0XB5);
            goto L_80069124;
    }
    // 0x8006910C: addiu       $t6, $a1, -0xB5
    ctx->r14 = ADD32(ctx->r5, -0XB5);
    // 0x80069110: addiu       $at, $zero, 0xE8
    ctx->r1 = ADD32(0, 0XE8);
    // 0x80069114: beq         $a1, $at, L_80069390
    if (ctx->r5 == ctx->r1) {
        // 0x80069118: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80069390;
    }
    // 0x80069118: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8006911C: b           L_800693DC
    // 0x80069120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x80069120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069124:
    // 0x80069124: sltiu       $at, $t6, 0x16
    ctx->r1 = ctx->r14 < 0X16 ? 1 : 0;
    // 0x80069128: beq         $at, $zero, L_800693D8
    if (ctx->r1 == 0) {
        // 0x8006912C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800693D8;
    }
    // 0x8006912C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80069130: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80069134: addu        $at, $at, $t6
    gpr jr_addend_8006913C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80069138: lw          $t6, 0x69E0($at)
    ctx->r14 = ADD32(ctx->r1, 0X69E0);
    // 0x8006913C: jr          $t6
    // 0x80069140: nop

    switch (jr_addend_8006913C >> 2) {
        case 0: goto L_8006928C; break;
        case 1: goto L_800692E0; break;
        case 2: goto L_800693D8; break;
        case 3: goto L_800693D8; break;
        case 4: goto L_800693D8; break;
        case 5: goto L_80069258; break;
        case 6: goto L_800693D8; break;
        case 7: goto L_800693D8; break;
        case 8: goto L_800693D8; break;
        case 9: goto L_800693D8; break;
        case 10: goto L_800693D8; break;
        case 11: goto L_8006933C; break;
        case 12: goto L_800693D8; break;
        case 13: goto L_80069224; break;
        case 14: goto L_800693D8; break;
        case 15: goto L_800693D8; break;
        case 16: goto L_80069178; break;
        case 17: goto L_800693D8; break;
        case 18: goto L_800693D8; break;
        case 19: goto L_80069144; break;
        case 20: goto L_800693D8; break;
        case 21: goto L_800691F0; break;
        default: switch_error(__func__, 0x8006913C, 0x800D69E0);
    }
    // 0x80069140: nop

L_80069144:
    // 0x80069144: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80069148: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x8006914C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80069150: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80069154: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069158: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x8006915C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80069160: addiu       $t8, $t8, 0x3FE0
    ctx->r24 = ADD32(ctx->r24, 0X3FE0);
    // 0x80069164: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069168: jal         0x8007717C
    // 0x8006916C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    ActorEvent_Dying(rdram, ctx);
        goto after_0;
    // 0x8006916C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80069170: b           L_800693DC
    // 0x80069174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x80069174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069178:
    // 0x80069178: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8006917C: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80069180: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80069184: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80069188: bne         $t9, $at, L_800691C4
    if (ctx->r25 != ctx->r1) {
        // 0x8006918C: subu        $t2, $t2, $a2
        ctx->r10 = SUB32(ctx->r10, ctx->r6);
            goto L_800691C4;
    }
    // 0x8006918C: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x80069190: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80069194: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x80069198: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8006919C: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x800691A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800691A4: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800691A8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800691AC: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x800691B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800691B4: jal         0x801888F4
    // 0x800691B8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    LOOKUP_FUNC(0x801888F4)(rdram, ctx);
        goto after_1;
    // 0x800691B8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x800691BC: b           L_800693DC
    // 0x800691C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x800691C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800691C4:
    // 0x800691C4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800691C8: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x800691CC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800691D0: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x800691D4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800691D8: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x800691DC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800691E0: jal         0x800763A4
    // 0x800691E4: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Actor_DyingCrash(rdram, ctx);
        goto after_2;
    // 0x800691E4: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x800691E8: b           L_800693DC
    // 0x800691EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x800691EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800691F0:
    // 0x800691F0: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800691F4: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x800691F8: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800691FC: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x80069200: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80069204: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x80069208: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8006920C: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x80069210: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80069214: jal         0x800763A4
    // 0x80069218: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Actor_DyingCrash(rdram, ctx);
        goto after_3;
    // 0x80069218: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x8006921C: b           L_800693DC
    // 0x80069220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x80069220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069224:
    // 0x80069224: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80069228: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8006922C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80069230: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80069234: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80069238: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x8006923C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80069240: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x80069244: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80069248: jal         0x8006B0A0
    // 0x8006924C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    MeMora_Dying(rdram, ctx);
        goto after_4;
    // 0x8006924C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_4:
    // 0x80069250: b           L_800693DC
    // 0x80069254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x80069254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069258:
    // 0x80069258: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8006925C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80069260: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80069264: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80069268: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006926C: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80069270: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80069274: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x80069278: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006927C: jal         0x80187B08
    // 0x80069280: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Meteo_80187B08(rdram, ctx);
        goto after_5;
    // 0x80069280: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x80069284: b           L_800693DC
    // 0x80069288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x80069288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006928C:
    // 0x8006928C: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80069290: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x80069294: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80069298: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8006929C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800692A0: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800692A4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800692A8: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x800692AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800692B0: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x800692B4: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    // 0x800692B8: jal         0x80060FBC
    // 0x800692BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x800692BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_6:
    // 0x800692C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800692C4: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800692C8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800692CC: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800692D0: jal         0x8007D2C8
    // 0x800692D4: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_7;
    // 0x800692D4: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    after_7:
    // 0x800692D8: b           L_800693DC
    // 0x800692DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x800692DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800692E0:
    // 0x800692E0: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800692E4: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x800692E8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800692EC: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x800692F0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800692F4: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x800692F8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800692FC: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80069300: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80069304: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80069308: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    // 0x8006930C: jal         0x80060FBC
    // 0x80069310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_8;
    // 0x80069310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_8:
    // 0x80069314: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80069318: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8006931C: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80069320: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80069324: jal         0x8007D2C8
    // 0x80069328: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_9;
    // 0x80069328: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    after_9:
    // 0x8006932C: jal         0x80066254
    // 0x80069330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    Actor_Despawn(rdram, ctx);
        goto after_10;
    // 0x80069330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x80069334: b           L_800693DC
    // 0x80069338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x80069338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006933C:
    // 0x8006933C: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x80069340: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x80069344: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80069348: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x8006934C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80069350: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x80069354: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80069358: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x8006935C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80069360: jal         0x8006684C
    // 0x80069364: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    func_enmy_8006684C(rdram, ctx);
        goto after_11;
    // 0x80069364: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_11:
    // 0x80069368: b           L_800693DC
    // 0x8006936C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x8006936C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069370:
    // 0x80069370: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80069374: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80069378: addiu       $t7, $t7, -0xEF0
    ctx->r15 = ADD32(ctx->r15, -0XEF0);
    // 0x8006937C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80069380: jal         0x801990DC
    // 0x80069384: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Titania_TiGoras_Dying(rdram, ctx);
        goto after_12;
    // 0x80069384: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_12:
    // 0x80069388: b           L_800693DC
    // 0x8006938C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x8006938C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069390:
    // 0x80069390: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80069394: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80069398: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8006939C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800693A0: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x800693A4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800693A8: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x800693AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800693B0: jal         0x8018B720
    // 0x800693B4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Titania_TiRasco_Dying(rdram, ctx);
        goto after_13;
    // 0x800693B4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_13:
    // 0x800693B8: b           L_800693DC
    // 0x800693BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800693DC;
    // 0x800693BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800693C0:
    // 0x800693C0: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800693C4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800693C8: addiu       $t1, $t1, -0xEF0
    ctx->r9 = ADD32(ctx->r9, -0XEF0);
    // 0x800693CC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800693D0: jal         0x80198594
    // 0x800693D4: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    LOOKUP_FUNC(0x80198594)(rdram, ctx);
        goto after_14;
    // 0x800693D4: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_14:
L_800693D8:
    // 0x800693D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800693DC:
    // 0x800693DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800693E0: jr          $ra
    // 0x800693E4: nop

    return;
    // 0x800693E4: nop

;}
RECOMP_FUNC void AudioLoad_GetLoadTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F820: beq         $a0, $zero, L_8000F848
    if (ctx->r4 == 0) {
        // 0x8000F824: lui         $v1, 0x8015
        ctx->r3 = S32(0X8015 << 16);
            goto L_8000F848;
    }
    // 0x8000F824: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000F828: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F82C: beq         $a0, $at, L_8000F850
    if (ctx->r4 == ctx->r1) {
        // 0x8000F830: lui         $v1, 0x8015
        ctx->r3 = S32(0X8015 << 16);
            goto L_8000F850;
    }
    // 0x8000F830: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000F834: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000F838: beq         $a0, $at, L_8000F858
    if (ctx->r4 == ctx->r1) {
        // 0x8000F83C: lui         $v1, 0x8015
        ctx->r3 = S32(0X8015 << 16);
            goto L_8000F858;
    }
    // 0x8000F83C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000F840: jr          $ra
    // 0x8000F844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000F844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F848:
    // 0x8000F848: jr          $ra
    // 0x8000F84C: lw          $v0, 0x5C5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C5C);
    return;
    // 0x8000F84C: lw          $v0, 0x5C5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C5C);
L_8000F850:
    // 0x8000F850: jr          $ra
    // 0x8000F854: lw          $v0, 0x5C60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C60);
    return;
    // 0x8000F854: lw          $v0, 0x5C60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C60);
L_8000F858:
    // 0x8000F858: lw          $v1, 0x5C64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5C64);
    // 0x8000F85C: jr          $ra
    // 0x8000F860: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000F860: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void PlayerShot_HitGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036774: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80036778: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8003677C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80036780: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80036784: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80036788: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003678C: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x80036790: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036794: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80036798: beq         $t6, $at, L_80036840
    if (ctx->r14 == ctx->r1) {
        // 0x8003679C: nop
    
            goto L_80036840;
    }
    // 0x8003679C: nop

    // 0x800367A0: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x800367A4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800367A8: bne         $t7, $zero, L_80036840
    if (ctx->r15 != 0) {
        // 0x800367AC: nop
    
            goto L_80036840;
    }
    // 0x800367AC: nop

    // 0x800367B0: lw          $t8, 0x1A88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1A88);
    // 0x800367B4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800367B8: bgtz        $t8, L_80036840
    if (SIGNED(ctx->r24) > 0) {
        // 0x800367BC: nop
    
            goto L_80036840;
    }
    // 0x800367BC: nop

    // 0x800367C0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800367C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800367C8: beq         $v0, $at, L_80036840
    if (ctx->r2 == ctx->r1) {
        // 0x800367CC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80036840;
    }
    // 0x800367CC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800367D0: beq         $v0, $at, L_80036840
    if (ctx->r2 == ctx->r1) {
        // 0x800367D4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80036840;
    }
    // 0x800367D4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800367D8: beq         $v0, $at, L_80036840
    if (ctx->r2 == ctx->r1) {
        // 0x800367DC: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80036840;
    }
    // 0x800367DC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800367E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800367E4: addiu       $v0, $v0, 0x1C88
    ctx->r2 = ADD32(ctx->r2, 0X1C88);
    // 0x800367E8: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x800367EC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
L_800367F0:
    // 0x800367F0: bnel        $t9, $zero, L_80036838
    if (ctx->r25 != 0) {
        // 0x800367F4: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80036838;
    }
    goto skip_0;
    // 0x800367F4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x800367F8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800367FC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80036800: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80036804: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80036808: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8003680C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80036810: jal         0x800366CC
    // 0x80036814: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    PlayerShot_LaserMark1_Setup(rdram, ctx);
        goto after_0;
    // 0x80036814: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80036818: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003681C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80036820: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80036824: jal         0x8007D10C
    // 0x80036828: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_1;
    // 0x80036828: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_1:
    // 0x8003682C: b           L_80036840
    // 0x80036830: nop

        goto L_80036840;
    // 0x80036830: nop

    // 0x80036834: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80036838:
    // 0x80036838: bnel        $a0, $v0, L_800367F0
    if (ctx->r4 != ctx->r2) {
        // 0x8003683C: lbu         $t9, 0x0($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X0);
            goto L_800367F0;
    }
    goto skip_1;
    // 0x8003683C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_80036840:
    // 0x80036840: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80036844: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x80036848: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8003684C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80036850: bne         $t0, $at, L_80036864
    if (ctx->r8 != ctx->r1) {
        // 0x80036854: lwc1        $f14, 0x24($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80036864;
    }
    // 0x80036854: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80036858: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8003685C: jal         0x8007D10C
    // 0x80036860: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_2;
    // 0x80036860: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_2:
L_80036864:
    // 0x80036864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80036868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003686C: jr          $ra
    // 0x80036870: nop

    return;
    // 0x80036870: nop

;}
RECOMP_FUNC void func_versus_800BD10C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD10C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD110: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD114: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800BD118: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BD11C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD120: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x800BD124: lui         $a2, 0x300
    ctx->r6 = S32(0X300 << 16);
    // 0x800BD128: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800BD12C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD130: addiu       $a2, $a2, 0x810
    ctx->r6 = ADD32(ctx->r6, 0X810);
    // 0x800BD134: addiu       $a1, $a1, 0x6D0
    ctx->r5 = ADD32(ctx->r5, 0X6D0);
    // 0x800BD138: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD13C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800BD140: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD144: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD148: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800BD14C: jal         0x8009C320
    // 0x800BD150: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800BD150: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800BD154: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD15C: jr          $ra
    // 0x800BD160: nop

    return;
    // 0x800BD160: nop

;}
RECOMP_FUNC void Player_DamageWings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6AC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6AC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A6AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A6ACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6AD0: lw          $t6, 0x1CC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A6AD4: bnel        $t6, $zero, L_800A6CC0
    if (ctx->r14 != 0) {
        // 0x800A6AD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_0;
    // 0x800A6AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A6ADC: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6AE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A6AE4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A6AE8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A6AEC: lwc1        $f4, 0x7AB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7AB8);
    // 0x800A6AF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6AF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6AF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800A6AFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A6B00: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800A6B04: nop

    // 0x800A6B08: bc1fl       L_800A6CC0
    if (!c1cs) {
        // 0x800A6B0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_1;
    // 0x800A6B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800A6B10: bne         $a1, $at, L_800A6BEC
    if (ctx->r5 != ctx->r1) {
        // 0x800A6B14: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800A6BEC;
    }
    // 0x800A6B14: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800A6B18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A6B1C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A6B20: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800A6B24: sw          $t8, 0x7D40($at)
    MEM_W(0X7D40, ctx->r1) = ctx->r24;
    // 0x800A6B28: lbu         $t9, 0x49C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X49C);
    // 0x800A6B2C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800A6B30: bnel        $v1, $t9, L_800A6CC0
    if (ctx->r3 != ctx->r25) {
        // 0x800A6B34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_2;
    // 0x800A6B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800A6B38: lw          $t0, 0x1C4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6B3C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A6B40: addiu       $v1, $v1, 0x7D10
    ctx->r3 = ADD32(ctx->r3, 0X7D10);
    // 0x800A6B44: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800A6B48: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x800A6B4C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800A6B50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A6B54: subu        $t3, $t2, $a2
    ctx->r11 = SUB32(ctx->r10, ctx->r6);
    // 0x800A6B58: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800A6B5C: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6B60: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A6B64: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x800A6B68: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A6B6C: bgtzl       $t7, L_800A6CC0
    if (SIGNED(ctx->r15) > 0) {
        // 0x800A6B70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_3;
    // 0x800A6B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800A6B74: lw          $a1, 0x2D4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2D4);
    // 0x800A6B78: lw          $a2, 0x2D8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2D8);
    // 0x800A6B7C: jal         0x800A69F8
    // 0x800A6B80: lw          $a3, 0x2DC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2DC);
    Play_SpawnDebris(rdram, ctx);
        goto after_0;
    // 0x800A6B80: lw          $a3, 0x2DC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2DC);
    after_0:
    // 0x800A6B84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A6B88: sb          $t8, 0x49C($s0)
    MEM_B(0X49C, ctx->r16) = ctx->r24;
    // 0x800A6B8C: lwc1        $f12, 0x2D4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2D4);
    // 0x800A6B90: lwc1        $f14, 0x2D8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x800A6B94: lw          $a2, 0x2DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2DC);
    // 0x800A6B98: jal         0x8007D0E0
    // 0x800A6B9C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_1;
    // 0x800A6B9C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_1:
    // 0x800A6BA0: lw          $t0, 0x1C4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6BA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A6BA8: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x800A6BAC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800A6BB0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800A6BB4: sw          $t9, 0x7D70($at)
    MEM_W(0X7D70, ctx->r1) = ctx->r25;
    // 0x800A6BB8: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800A6BBC: ori         $a1, $a1, 0xA02C
    ctx->r5 = ctx->r5 | 0XA02C;
    // 0x800A6BC0: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6BC4: jal         0x800A5FA0
    // 0x800A6BC8: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    Player_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800A6BC8: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    after_2:
    // 0x800A6BCC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800A6BD0: addiu       $v0, $v0, -0x6F4
    ctx->r2 = ADD32(ctx->r2, -0X6F4);
    // 0x800A6BD4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800A6BD8: addiu       $t3, $zero, 0x3E8
    ctx->r11 = ADD32(0, 0X3E8);
    // 0x800A6BDC: bnel        $t2, $zero, L_800A6CC0
    if (ctx->r10 != 0) {
        // 0x800A6BE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_4;
    // 0x800A6BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800A6BE4: b           L_800A6CBC
    // 0x800A6BE8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_800A6CBC;
    // 0x800A6BE8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800A6BEC:
    // 0x800A6BEC: bne         $a1, $v1, L_800A6CBC
    if (ctx->r5 != ctx->r3) {
        // 0x800A6BF0: addiu       $t4, $zero, 0x1E
        ctx->r12 = ADD32(0, 0X1E);
            goto L_800A6CBC;
    }
    // 0x800A6BF0: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x800A6BF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A6BF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800A6BFC: sw          $t4, 0x7D58($at)
    MEM_W(0X7D58, ctx->r1) = ctx->r12;
    // 0x800A6C00: lbu         $t5, 0x49D($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X49D);
    // 0x800A6C04: bnel        $v1, $t5, L_800A6CC0
    if (ctx->r3 != ctx->r13) {
        // 0x800A6C08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_5;
    // 0x800A6C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800A6C0C: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6C10: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A6C14: addiu       $v1, $v1, 0x7D28
    ctx->r3 = ADD32(ctx->r3, 0X7D28);
    // 0x800A6C18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A6C1C: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x800A6C20: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A6C24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A6C28: subu        $t0, $t8, $a2
    ctx->r8 = SUB32(ctx->r24, ctx->r6);
    // 0x800A6C2C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800A6C30: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6C34: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800A6C38: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x800A6C3C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800A6C40: bgtzl       $t3, L_800A6CC0
    if (SIGNED(ctx->r11) > 0) {
        // 0x800A6C44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_6;
    // 0x800A6C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800A6C48: lw          $a1, 0x2C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C8);
    // 0x800A6C4C: lw          $a2, 0x2CC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2CC);
    // 0x800A6C50: jal         0x800A69F8
    // 0x800A6C54: lw          $a3, 0x2D0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2D0);
    Play_SpawnDebris(rdram, ctx);
        goto after_3;
    // 0x800A6C54: lw          $a3, 0x2D0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2D0);
    after_3:
    // 0x800A6C58: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A6C5C: sb          $t4, 0x49D($s0)
    MEM_B(0X49D, ctx->r16) = ctx->r12;
    // 0x800A6C60: lwc1        $f12, 0x2C8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C8);
    // 0x800A6C64: lwc1        $f14, 0x2CC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x800A6C68: lw          $a2, 0x2D0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2D0);
    // 0x800A6C6C: jal         0x8007D0E0
    // 0x800A6C70: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_4;
    // 0x800A6C70: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_4:
    // 0x800A6C74: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6C78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A6C7C: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x800A6C80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A6C84: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A6C88: sw          $t5, 0x7D88($at)
    MEM_W(0X7D88, ctx->r1) = ctx->r13;
    // 0x800A6C8C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800A6C90: ori         $a1, $a1, 0xA02C
    ctx->r5 = ctx->r5 | 0XA02C;
    // 0x800A6C94: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6C98: jal         0x800A5FA0
    // 0x800A6C9C: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    Player_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x800A6C9C: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    after_5:
    // 0x800A6CA0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800A6CA4: addiu       $v0, $v0, -0x6F4
    ctx->r2 = ADD32(ctx->r2, -0X6F4);
    // 0x800A6CA8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A6CAC: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x800A6CB0: bnel        $t8, $zero, L_800A6CC0
    if (ctx->r24 != 0) {
        // 0x800A6CB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6CC0;
    }
    goto skip_7;
    // 0x800A6CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x800A6CB8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_800A6CBC:
    // 0x800A6CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6CC0:
    // 0x800A6CC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A6CC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6CC8: jr          $ra
    // 0x800A6CCC: nop

    return;
    // 0x800A6CCC: nop

;}
RECOMP_FUNC void Audio_LoadInstruments(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017494: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80017498: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001749C: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x800174A0: addiu       $s4, $s4, 0x5D54
    ctx->r20 = ADD32(ctx->r20, 0X5D54);
    // 0x800174A4: lbu         $t6, 0x0($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X0);
    // 0x800174A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800174AC: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x800174B0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800174B4: addiu       $s3, $s3, 0x5D6C
    ctx->r19 = ADD32(ctx->r19, 0X5D6C);
    // 0x800174B8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800174BC: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
    // 0x800174C0: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800174C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800174C8: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x800174CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800174D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800174D4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800174D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800174DC: beq         $s2, $t8, L_8001752C
    if (ctx->r18 == ctx->r24) {
        // 0x800174E0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001752C;
    }
    // 0x800174E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800174E4: andi        $s1, $t8, 0xFF
    ctx->r17 = ctx->r24 & 0XFF;
    // 0x800174E8: lui         $s5, 0xF300
    ctx->r21 = S32(0XF300 << 16);
    // 0x800174EC: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
L_800174F0:
    // 0x800174F0: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800174F4: or          $a0, $t0, $s5
    ctx->r4 = ctx->r8 | ctx->r21;
    // 0x800174F8: jal         0x8001E8F0
    // 0x800174FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x800174FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80017500: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    // 0x80017504: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017508: andi        $t1, $s0, 0xFF
    ctx->r9 = ctx->r16 & 0XFF;
    // 0x8001750C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80017510: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80017514: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80017518: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x8001751C: lbu         $s1, 0x0($t5)
    ctx->r17 = MEM_BU(ctx->r13, 0X0);
    // 0x80017520: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80017524: bnel        $s2, $s1, L_800174F0
    if (ctx->r18 != ctx->r17) {
        // 0x80017528: andi        $t9, $s1, 0xFF
        ctx->r25 = ctx->r17 & 0XFF;
            goto L_800174F0;
    }
    goto skip_0;
    // 0x80017528: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    skip_0:
L_8001752C:
    // 0x8001752C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80017530: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80017534: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80017538: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001753C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80017540: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80017544: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80017548: jr          $ra
    // 0x8001754C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001754C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Cutscene_TeamFormAlongPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049630: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80049634: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80049638: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004963C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80049640: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x80049644: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80049648: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8004964C: beq         $v0, $zero, L_80049674
    if (ctx->r2 == 0) {
        // 0x80049650: lui         $t8, 0x800D
        ctx->r24 = S32(0X800D << 16);
            goto L_80049674;
    }
    // 0x80049650: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80049654: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049658: beq         $v0, $at, L_800497BC
    if (ctx->r2 == ctx->r1) {
        // 0x8004965C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_800497BC;
    }
    // 0x8004965C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80049660: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049664: beql        $v0, $at, L_80049804
    if (ctx->r2 == ctx->r1) {
        // 0x80049668: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80049804;
    }
    goto skip_0;
    // 0x80049668: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x8004966C: b           L_80049834
    // 0x80049670: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80049834;
    // 0x80049670: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80049674:
    // 0x80049674: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x80049678: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004967C: addiu       $t8, $t8, -0x6060
    ctx->r24 = ADD32(ctx->r24, -0X6060);
    // 0x80049680: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80049684: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80049688: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004968C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80049690: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80049694: lwc1        $f6, 0x74($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X74);
    // 0x80049698: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004969C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800496A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800496A4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800496A8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x800496AC: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x800496B0: swc1        $f8, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f8.u32l;
    // 0x800496B4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800496B8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800496BC: lw          $a1, 0x18C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18C);
    // 0x800496C0: lwc1        $f16, 0x78($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X78);
    // 0x800496C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800496C8: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
    // 0x800496CC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800496D0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800496D4: lwc1        $f6, 0x7C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X7C);
    // 0x800496D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800496DC: swc1        $f8, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f8.u32l;
    // 0x800496E0: lwc1        $f10, 0x5874($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5874);
    // 0x800496E4: jal         0x8009BC2C
    // 0x800496E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800496E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800496EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800496F0: lwc1        $f16, 0x5878($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5878);
    // 0x800496F4: lw          $a1, 0x190($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X190);
    // 0x800496F8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800496FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049700: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80049704: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80049708: jal         0x8009BC2C
    // 0x8004970C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8004970C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80049710: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049714: lwc1        $f18, 0x587C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X587C);
    // 0x80049718: lw          $a1, 0x194($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X194);
    // 0x8004971C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80049720: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049724: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80049728: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8004972C: jal         0x8009BC2C
    // 0x80049730: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80049730: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80049734: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80049738: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8004973C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049740: lwc1        $f4, 0x5880($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5880);
    // 0x80049744: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049748: lw          $a1, 0xE4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XE4);
    // 0x8004974C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049750: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x80049754: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80049758: jal         0x8009BC2C
    // 0x8004975C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8004975C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80049760: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80049764: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80049768: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004976C: lwc1        $f6, 0x5884($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5884);
    // 0x80049770: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049774: lw          $a1, 0xE8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XE8);
    // 0x80049778: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004977C: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x80049780: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80049784: jal         0x8009BC2C
    // 0x80049788: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80049788: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8004978C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049790: lwc1        $f8, 0x5888($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5888);
    // 0x80049794: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80049798: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8004979C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800497A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800497A4: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x800497A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800497AC: jal         0x8009BC2C
    // 0x800497B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800497B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x800497B4: b           L_80049834
    // 0x800497B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80049834;
    // 0x800497B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_800497BC:
    // 0x800497BC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800497C0: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x800497C4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800497C8: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
    // 0x800497CC: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x800497D0: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x800497D4: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x800497D8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800497DC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800497E0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800497E4: jal         0x80019218
    // 0x800497E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x800497E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x800497EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800497F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800497F4: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x800497F8: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
    // 0x800497FC: swc1        $f10, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f10.u32l;
    // 0x80049800: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80049804:
    // 0x80049804: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80049808: lwc1        $f16, 0x114($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004980C: lhu         $t8, 0xBC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XBC);
    // 0x80049810: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80049814: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80049818: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
    // 0x8004981C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80049820: bne         $t8, $zero, L_80049830
    if (ctx->r24 != 0) {
        // 0x80049824: swc1        $f4, 0x114($s0)
        MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
            goto L_80049830;
    }
    // 0x80049824: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x80049828: jal         0x80060FBC
    // 0x8004982C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x8004982C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_7:
L_80049830:
    // 0x80049830: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80049834:
    // 0x80049834: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049838: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8004983C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049840: lwc1        $f16, 0x588C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X588C);
    // 0x80049844: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80049848: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004984C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80049850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80049854: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80049858: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8004985C: jal         0x80005E90
    // 0x80049860: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80049860: nop

    after_8:
    // 0x80049864: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049868: lwc1        $f6, 0x5890($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5890);
    // 0x8004986C: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80049870: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80049874: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80049878: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004987C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80049880: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80049884: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80049888: jal         0x80005D44
    // 0x8004988C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x8004988C: nop

    after_9:
    // 0x80049890: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049894: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80049898: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004989C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800498A0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800498A4: lwc1        $f16, 0x114($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800498A8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800498AC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800498B0: jal         0x80006A20
    // 0x800498B4: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x800498B4: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x800498B8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800498BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800498C0: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800498C4: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x800498C8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800498CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800498D0: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800498D4: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x800498D8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800498DC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800498E0: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x800498E4: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x800498E8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800498EC: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800498F0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800498F4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800498F8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x800498FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80049900: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80049904: jr          $ra
    // 0x80049908: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80049908: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void AudioHeap_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D4A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000D4AC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000D4B0: lbu         $t6, -0x2AD7($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2AD7);
    // 0x8000D4B4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8000D4B8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000D4BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D4C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000D4C4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8000D4C8: addiu       $t8, $t8, 0x76B8
    ctx->r24 = ADD32(ctx->r24, 0X76B8);
    // 0x8000D4CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000D4D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000D4D4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000D4D8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000D4DC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000D4E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000D4E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000D4E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000D4EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000D4F0: addu        $s6, $t7, $t8
    ctx->r22 = ADD32(ctx->r15, ctx->r24);
    // 0x8000D4F4: sw          $zero, 0x5A48($at)
    MEM_W(0X5A48, ctx->r1) = 0;
    // 0x8000D4F8: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8000D4FC: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x8000D500: addiu       $s4, $s4, 0x5C78
    ctx->r20 = ADD32(ctx->r20, 0X5C78);
    // 0x8000D504: sh          $t9, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r25;
    // 0x8000D508: jal         0x80024D60
    // 0x8000D50C: andi        $a0, $t9, 0xFFFF
    ctx->r4 = ctx->r25 & 0XFFFF;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x8000D50C: andi        $a0, $t9, 0xFFFF
    ctx->r4 = ctx->r25 & 0XFFFF;
    after_0:
    // 0x8000D510: sh          $v0, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r2;
    // 0x8000D514: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000D518: lw          $t2, 0x5D6C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5D6C);
    // 0x8000D51C: lhu         $a2, 0x2($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X2);
    // 0x8000D520: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000D524: addiu       $t1, $t1, 0x5CA0
    ctx->r9 = ADD32(ctx->r9, 0X5CA0);
    // 0x8000D528: div         $zero, $a2, $t2
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r10)));
    // 0x8000D52C: mflo        $t3
    ctx->r11 = lo;
    // 0x8000D530: addiu       $t4, $t3, 0xF
    ctx->r12 = ADD32(ctx->r11, 0XF);
    // 0x8000D534: andi        $t5, $t4, 0xFFF0
    ctx->r13 = ctx->r12 & 0XFFF0;
    // 0x8000D538: bne         $t2, $zero, L_8000D544
    if (ctx->r10 != 0) {
        // 0x8000D53C: nop
    
            goto L_8000D544;
    }
    // 0x8000D53C: nop

    // 0x8000D540: break       7
    do_break(2147538240);
L_8000D544:
    // 0x8000D544: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D548: bne         $t2, $at, L_8000D55C
    if (ctx->r10 != ctx->r1) {
        // 0x8000D54C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000D55C;
    }
    // 0x8000D54C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D550: bne         $a2, $at, L_8000D55C
    if (ctx->r6 != ctx->r1) {
        // 0x8000D554: nop
    
            goto L_8000D55C;
    }
    // 0x8000D554: nop

    // 0x8000D558: break       6
    do_break(2147538264);
L_8000D55C:
    // 0x8000D55C: sh          $t5, 0x6($s4)
    MEM_H(0X6, ctx->r20) = ctx->r13;
    // 0x8000D560: lh          $a0, 0x6($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X6);
    // 0x8000D564: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x8000D568: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8000D56C: addiu       $a3, $a0, 0x10
    ctx->r7 = ADD32(ctx->r4, 0X10);
    // 0x8000D570: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x8000D574: mflo        $t7
    ctx->r15 = lo;
    // 0x8000D578: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000D57C: sh          $t8, 0xC($s4)
    MEM_H(0XC, ctx->r20) = ctx->r24;
    // 0x8000D580: lh          $a1, 0xC($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XC);
    // 0x8000D584: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000D588: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x8000D58C: div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // 0x8000D590: mflo        $t9
    ctx->r25 = lo;
    // 0x8000D594: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x8000D598: sh          $t6, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r14;
    // 0x8000D59C: sh          $a3, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r7;
    // 0x8000D5A0: bne         $a1, $zero, L_8000D5AC
    if (ctx->r5 != 0) {
        // 0x8000D5A4: nop
    
            goto L_8000D5AC;
    }
    // 0x8000D5A4: nop

    // 0x8000D5A8: break       7
    do_break(2147538344);
L_8000D5AC:
    // 0x8000D5AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D5B0: bne         $a1, $at, L_8000D5C4
    if (ctx->r5 != ctx->r1) {
        // 0x8000D5B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000D5C4;
    }
    // 0x8000D5B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D5B8: bne         $a0, $at, L_8000D5C4
    if (ctx->r4 != ctx->r1) {
        // 0x8000D5BC: nop
    
            goto L_8000D5C4;
    }
    // 0x8000D5BC: nop

    // 0x8000D5C0: break       6
    do_break(2147538368);
L_8000D5C4:
    // 0x8000D5C4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8000D5C8: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x8000D5CC: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x8000D5D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000D5D4: sh          $t2, 0xE($s4)
    MEM_H(0XE, ctx->r20) = ctx->r10;
    // 0x8000D5D8: lh          $t0, 0xE($s4)
    ctx->r8 = MEM_H(ctx->r20, 0XE);
    // 0x8000D5DC: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000D5E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000D5E4: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x8000D5E8: addiu       $t4, $t0, -0x8
    ctx->r12 = ADD32(ctx->r8, -0X8);
    // 0x8000D5EC: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000D5F0: sh          $t3, 0x10($s4)
    MEM_H(0X10, ctx->r20) = ctx->r11;
    // 0x8000D5F4: sh          $t4, 0x12($s4)
    MEM_H(0X12, ctx->r20) = ctx->r12;
    // 0x8000D5F8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8000D5FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D600: swc1        $f10, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f10.u32l;
    // 0x8000D604: lwc1        $f18, -0x7988($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7988);
    // 0x8000D608: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D60C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000D610: div.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8000D614: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000D618: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000D61C: swc1        $f6, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f6.u32l;
    // 0x8000D620: swc1        $f8, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f8.u32l;
    // 0x8000D624: lbu         $t5, 0x5($s6)
    ctx->r13 = MEM_BU(ctx->r22, 0X5);
    // 0x8000D628: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8000D62C: lhu         $t6, 0xC($s6)
    ctx->r14 = MEM_HU(ctx->r22, 0XC);
    // 0x8000D630: lh          $t7, 0x7C2C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7C2C);
    // 0x8000D634: sh          $t6, -0x3E50($at)
    MEM_H(-0X3E50, ctx->r1) = ctx->r14;
    // 0x8000D638: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000D63C: lwc1        $f10, -0x7984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7984);
    // 0x8000D640: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000D644: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000D648: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000D64C: lwc1        $f8, 0x5D68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5D68);
    // 0x8000D650: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D654: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000D658: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000D65C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000D660: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000D664: nop

    // 0x8000D668: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000D66C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000D670: nop

    // 0x8000D674: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8000D678: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8000D67C: beq         $t9, $zero, L_8000D6C8
    if (ctx->r25 == 0) {
        // 0x8000D680: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8000D6C8;
    }
    // 0x8000D680: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000D684: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000D688: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D68C: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8000D690: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000D694: nop

    // 0x8000D698: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000D69C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000D6A0: nop

    // 0x8000D6A4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8000D6A8: bne         $t9, $zero, L_8000D6C0
    if (ctx->r25 != 0) {
        // 0x8000D6AC: nop
    
            goto L_8000D6C0;
    }
    // 0x8000D6AC: nop

    // 0x8000D6B0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8000D6B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D6B8: b           L_8000D6D8
    // 0x8000D6BC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8000D6D8;
    // 0x8000D6BC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8000D6C0:
    // 0x8000D6C0: b           L_8000D6D8
    // 0x8000D6C4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8000D6D8;
    // 0x8000D6C4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_8000D6C8:
    // 0x8000D6C8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8000D6CC: nop

    // 0x8000D6D0: bltz        $t9, L_8000D6C0
    if (SIGNED(ctx->r25) < 0) {
        // 0x8000D6D4: nop
    
            goto L_8000D6C0;
    }
    // 0x8000D6D4: nop

L_8000D6D8:
    // 0x8000D6D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000D6DC: sh          $t9, 0x5CA4($at)
    MEM_H(0X5CA4, ctx->r1) = ctx->r25;
    // 0x8000D6E0: lbu         $t2, 0x4($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X4);
    // 0x8000D6E4: lh          $t4, 0x8($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X8);
    // 0x8000D6E8: lh          $t6, 0xA($s4)
    ctx->r14 = MEM_H(ctx->r20, 0XA);
    // 0x8000D6EC: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
    // 0x8000D6F0: lh          $v1, 0x0($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X0);
    // 0x8000D6F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000D6F8: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D6FC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000D700: mflo        $t3
    ctx->r11 = lo;
    // 0x8000D704: sh          $t3, 0x6($s4)
    MEM_H(0X6, ctx->r20) = ctx->r11;
    // 0x8000D708: nop

    // 0x8000D70C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D710: mflo        $t5
    ctx->r13 = lo;
    // 0x8000D714: sh          $t5, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r13;
    // 0x8000D718: nop

    // 0x8000D71C: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D720: mflo        $t7
    ctx->r15 = lo;
    // 0x8000D724: sh          $t7, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r15;
    // 0x8000D728: nop

    // 0x8000D72C: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D730: mflo        $t8
    ctx->r24 = lo;
    // 0x8000D734: sh          $t8, 0xC($s4)
    MEM_H(0XC, ctx->r20) = ctx->r24;
    // 0x8000D738: bnel        $at, $zero, L_8000D750
    if (ctx->r1 != 0) {
        // 0x8000D73C: lw          $t3, 0x0($t1)
        ctx->r11 = MEM_W(ctx->r9, 0X0);
            goto L_8000D750;
    }
    goto skip_0;
    // 0x8000D73C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    skip_0:
    // 0x8000D740: lh          $t9, 0x8($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X8);
    // 0x8000D744: addiu       $t2, $t9, -0x10
    ctx->r10 = ADD32(ctx->r25, -0X10);
    // 0x8000D748: sh          $t2, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r10;
    // 0x8000D74C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_8000D750:
    // 0x8000D750: lh          $t5, 0xC($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XC);
    // 0x8000D754: lbu         $t7, 0x6($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X6);
    // 0x8000D758: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8000D75C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8000D760: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8000D764: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D768: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8000D76C: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8000D770: addiu       $s2, $s2, 0x5C9C
    ctx->r18 = ADD32(ctx->r18, 0X5C9C);
    // 0x8000D774: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000D778: addiu       $a0, $a0, -0x2C90
    ctx->r4 = ADD32(ctx->r4, -0X2C90);
    // 0x8000D77C: mflo        $t6
    ctx->r14 = lo;
    // 0x8000D780: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000D784: addiu       $t2, $t9, 0x1E0
    ctx->r10 = ADD32(ctx->r25, 0X1E0);
    // 0x8000D788: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x8000D78C: lw          $t4, 0x14($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X14);
    // 0x8000D790: lw          $t3, 0x10($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X10);
    // 0x8000D794: lw          $t7, 0x18($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X18);
    // 0x8000D798: lw          $t8, 0x28($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X28);
    // 0x8000D79C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000D7A0: lw          $t2, 0x20($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X20);
    // 0x8000D7A4: lw          $t9, 0x1C($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X1C);
    // 0x8000D7A8: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8000D7AC: lw          $t4, 0x24($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X24);
    // 0x8000D7B0: lw          $t7, 0x2C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X2C);
    // 0x8000D7B4: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
    // 0x8000D7B8: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8000D7BC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000D7C0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000D7C4: lw          $t6, -0x3E38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3E38);
    // 0x8000D7C8: addu        $s1, $t5, $t7
    ctx->r17 = ADD32(ctx->r13, ctx->r15);
    // 0x8000D7CC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8000D7D0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8000D7D4: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
    // 0x8000D7D8: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x8000D7DC: addiu       $v1, $v1, -0x100
    ctx->r3 = ADD32(ctx->r3, -0X100);
    // 0x8000D7E0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000D7E4: jal         0x8000C044
    // 0x8000D7E8: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    AudioHeap_InitSessionPools(rdram, ctx);
        goto after_1;
    // 0x8000D7E8: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    after_1:
    // 0x8000D7EC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000D7F0: addiu       $a0, $a0, -0x2C80
    ctx->r4 = ADD32(ctx->r4, -0X2C80);
    // 0x8000D7F4: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
    // 0x8000D7F8: jal         0x8000C0C0
    // 0x8000D7FC: sw          $s1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r17;
    AudioHeap_InitCachePools(rdram, ctx);
        goto after_2;
    // 0x8000D7FC: sw          $s1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r17;
    after_2:
    // 0x8000D800: lw          $t8, 0x10($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X10);
    // 0x8000D804: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000D808: addiu       $a0, $a0, -0x2C78
    ctx->r4 = ADD32(ctx->r4, -0X2C78);
    // 0x8000D80C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000D810: lw          $t9, 0x14($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X14);
    // 0x8000D814: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8000D818: lw          $t2, 0x18($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X18);
    // 0x8000D81C: jal         0x8000C13C
    // 0x8000D820: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    AudioHeap_InitPersistentPoolsAndCaches(rdram, ctx);
        goto after_3;
    // 0x8000D820: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    after_3:
    // 0x8000D824: lw          $t3, 0x1C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X1C);
    // 0x8000D828: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000D82C: addiu       $a0, $a0, -0x2C68
    ctx->r4 = ADD32(ctx->r4, -0X2C68);
    // 0x8000D830: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8000D834: lw          $t4, 0x20($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X20);
    // 0x8000D838: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x8000D83C: lw          $t5, 0x24($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X24);
    // 0x8000D840: jal         0x8000C1F8
    // 0x8000D844: sw          $t5, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r13;
    AudioHeap_InitTemporaryPoolsAndCaches(rdram, ctx);
        goto after_4;
    // 0x8000D844: sw          $t5, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r13;
    after_4:
    // 0x8000D848: lw          $a0, 0x28($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X28);
    // 0x8000D84C: jal         0x8000DCD4
    // 0x8000D850: lw          $a1, 0x2C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X2C);
    AudioHeap_InitSampleCaches(rdram, ctx);
        goto after_5;
    // 0x8000D850: lw          $a1, 0x2C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X2C);
    after_5:
    // 0x8000D854: jal         0x8000BC70
    // 0x8000D858: nop

    AudioHeap_ResetLoadStatus(rdram, ctx);
        goto after_6;
    // 0x8000D858: nop

    after_6:
    // 0x8000D85C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000D860: lw          $a1, 0x5CA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5CA0);
    // 0x8000D864: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000D868: addiu       $s3, $s3, -0x3E20
    ctx->r19 = ADD32(ctx->r19, -0X3E20);
    // 0x8000D86C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8000D870: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8000D874: sll         $a1, $t7, 6
    ctx->r5 = S32(ctx->r15 << 6);
    // 0x8000D878: jal         0x8000BE94
    // 0x8000D87C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_7;
    // 0x8000D87C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x8000D880: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000D884: jal         0x800132E8
    // 0x8000D888: sw          $v0, -0x1AD0($at)
    MEM_W(-0X1AD0, ctx->r1) = ctx->r2;
    Audio_NoteInitAll(rdram, ctx);
        goto after_8;
    // 0x8000D888: sw          $v0, -0x1AD0($at)
    MEM_W(-0X1AD0, ctx->r1) = ctx->r2;
    after_8:
    // 0x8000D88C: jal         0x800128B4
    // 0x8000D890: nop

    Audio_InitNoteFreeList(rdram, ctx);
        goto after_9;
    // 0x8000D890: nop

    after_9:
    // 0x8000D894: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000D898: lw          $t8, 0x5CA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5CA0);
    // 0x8000D89C: lh          $t6, 0xC($s4)
    ctx->r14 = MEM_H(ctx->r20, 0XC);
    // 0x8000D8A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D8A4: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D8A8: mflo        $a1
    ctx->r5 = lo;
    // 0x8000D8AC: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8000D8B0: jal         0x8000BE94
    // 0x8000D8B4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_10;
    // 0x8000D8B4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_10:
    // 0x8000D8B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000D8BC: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8000D8C0: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8000D8C4: sw          $v0, -0x3E48($at)
    MEM_W(-0X3E48, ctx->r1) = ctx->r2;
    // 0x8000D8C8: addiu       $s1, $s1, 0x5CC0
    ctx->r17 = ADD32(ctx->r17, 0X5CC0);
    // 0x8000D8CC: addiu       $s0, $s0, 0x5CB8
    ctx->r16 = ADD32(ctx->r16, 0X5CB8);
L_8000D8D0:
    // 0x8000D8D0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8000D8D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D8D8: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x8000D8DC: jal         0x8000BE94
    // 0x8000D8E0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_11;
    // 0x8000D8E0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_11:
    // 0x8000D8E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000D8E8: bne         $s0, $s1, L_8000D8D0
    if (ctx->r16 != ctx->r17) {
        // 0x8000D8EC: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8000D8D0;
    }
    // 0x8000D8EC: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x8000D8F0: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8000D8F4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000D8F8: addiu       $v0, $v0, -0x3E60
    ctx->r2 = ADD32(ctx->r2, -0X3E60);
    // 0x8000D8FC: addiu       $s2, $s2, -0x45B0
    ctx->r18 = ADD32(ctx->r18, -0X45B0);
L_8000D900:
    // 0x8000D900: addiu       $s2, $s2, 0x1D4
    ctx->r18 = ADD32(ctx->r18, 0X1D4);
    // 0x8000D904: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x8000D908: bne         $at, $zero, L_8000D900
    if (ctx->r1 != 0) {
        // 0x8000D90C: sb          $zero, -0x1D3($s2)
        MEM_B(-0X1D3, ctx->r18) = 0;
            goto L_8000D900;
    }
    // 0x8000D90C: sb          $zero, -0x1D3($s2)
    MEM_B(-0X1D3, ctx->r18) = 0;
    // 0x8000D910: lbu         $t3, 0x6($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X6);
    // 0x8000D914: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x8000D918: addiu       $s7, $s7, -0x3E4D
    ctx->r23 = ADD32(ctx->r23, -0X3E4D);
    // 0x8000D91C: sb          $t3, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r11;
    // 0x8000D920: lb          $t4, 0x0($s7)
    ctx->r12 = MEM_B(ctx->r23, 0X0);
    // 0x8000D924: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8000D928: addiu       $s2, $s2, -0x45B0
    ctx->r18 = ADD32(ctx->r18, -0X45B0);
    // 0x8000D92C: blez        $t4, L_8000DABC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000D930: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8000DABC;
    }
    // 0x8000D930: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000D934: lw          $t5, 0x8($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X8);
L_8000D938:
    // 0x8000D938: sll         $t7, $s5, 3
    ctx->r15 = S32(ctx->r21 << 3);
    // 0x8000D93C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D940: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x8000D944: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8000D948: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000D94C: sb          $t6, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r14;
    // 0x8000D950: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000D954: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x8000D958: sh          $t9, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r25;
    // 0x8000D95C: lhu         $t2, 0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2);
    // 0x8000D960: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x8000D964: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x8000D968: sh          $t2, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r10;
    // 0x8000D96C: lhu         $t3, 0x4($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X4);
    // 0x8000D970: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8000D974: sh          $t3, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r11;
    // 0x8000D978: lhu         $t4, 0x6($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X6);
    // 0x8000D97C: sb          $t5, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r13;
    // 0x8000D980: jal         0x8000BE94
    // 0x8000D984: sh          $t4, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r12;
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_12;
    // 0x8000D984: sh          $t4, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r12;
    after_12:
    // 0x8000D988: lhu         $a1, 0x6($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X6);
    // 0x8000D98C: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8000D990: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D994: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8000D998: jal         0x8000BE94
    // 0x8000D99C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_13;
    // 0x8000D99C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_13:
    // 0x8000D9A0: lbu         $v1, 0x4($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X4);
    // 0x8000D9A4: lhu         $t8, 0x6($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6);
    // 0x8000D9A8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000D9AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D9B0: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // 0x8000D9B4: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    // 0x8000D9B8: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x8000D9BC: sb          $zero, 0x3($s2)
    MEM_B(0X3, ctx->r18) = 0;
    // 0x8000D9C0: sb          $t9, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r25;
    // 0x8000D9C4: beq         $v1, $at, L_8000DAA4
    if (ctx->r3 == ctx->r1) {
        // 0x8000D9C8: sw          $t8, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r24;
            goto L_8000DAA4;
    }
    // 0x8000D9C8: sw          $t8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r24;
    // 0x8000D9CC: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x8000D9D0: div         $zero, $t3, $v1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r3)));
    // 0x8000D9D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000D9D8: mflo        $t4
    ctx->r12 = lo;
    // 0x8000D9DC: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
    // 0x8000D9E0: bne         $v1, $zero, L_8000D9EC
    if (ctx->r3 != 0) {
        // 0x8000D9E4: nop
    
            goto L_8000D9EC;
    }
    // 0x8000D9E4: nop

    // 0x8000D9E8: break       7
    do_break(2147539432);
L_8000D9EC:
    // 0x8000D9EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D9F0: bne         $v1, $at, L_8000DA04
    if (ctx->r3 != ctx->r1) {
        // 0x8000D9F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000DA04;
    }
    // 0x8000D9F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D9F8: bne         $t3, $at, L_8000DA04
    if (ctx->r11 != ctx->r1) {
        // 0x8000D9FC: nop
    
            goto L_8000DA04;
    }
    // 0x8000D9FC: nop

    // 0x8000DA00: break       6
    do_break(2147539456);
L_8000DA04:
    // 0x8000DA04: sh          $t4, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r12;
    // 0x8000DA08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000DA0C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8000DA10: jal         0x8000BE94
    // 0x8000DA14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_14;
    // 0x8000DA14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_14:
    // 0x8000DA18: sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    // 0x8000DA1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000DA20: jal         0x8000BE94
    // 0x8000DA24: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_15;
    // 0x8000DA24: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_15:
    // 0x8000DA28: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x8000DA2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000DA30: jal         0x8000BE94
    // 0x8000DA34: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_16;
    // 0x8000DA34: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_16:
    // 0x8000DA38: sw          $v0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r2;
    // 0x8000DA3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000DA40: jal         0x8000BE94
    // 0x8000DA44: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_17;
    // 0x8000DA44: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_17:
    // 0x8000DA48: lh          $t5, 0xC($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XC);
    // 0x8000DA4C: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
    // 0x8000DA50: blezl       $t5, L_8000DAA8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8000DA54: lb          $t9, 0x0($s7)
        ctx->r25 = MEM_B(ctx->r23, 0X0);
            goto L_8000DAA8;
    }
    goto skip_1;
    // 0x8000DA54: lb          $t9, 0x0($s7)
    ctx->r25 = MEM_B(ctx->r23, 0X0);
    skip_1:
    // 0x8000DA58: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8000DA5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8000DA60:
    // 0x8000DA60: jal         0x8000BE94
    // 0x8000DA64: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_18;
    // 0x8000DA64: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    after_18:
    // 0x8000DA68: addiu       $t7, $v0, 0x180
    ctx->r15 = ADD32(ctx->r2, 0X180);
    // 0x8000DA6C: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8000DA70: sw          $t7, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r15;
    // 0x8000DA74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000DA78: jal         0x8000BE94
    // 0x8000DA7C: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    AudioHeap_AllocZeroed(rdram, ctx);
        goto after_19;
    // 0x8000DA7C: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    after_19:
    // 0x8000DA80: addiu       $t6, $v0, 0x180
    ctx->r14 = ADD32(ctx->r2, 0X180);
    // 0x8000DA84: sw          $v0, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r2;
    // 0x8000DA88: sw          $t6, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r14;
    // 0x8000DA8C: lh          $t8, 0xC($s4)
    ctx->r24 = MEM_H(ctx->r20, 0XC);
    // 0x8000DA90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000DA94: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8000DA98: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000DA9C: bnel        $at, $zero, L_8000DA60
    if (ctx->r1 != 0) {
        // 0x8000DAA0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8000DA60;
    }
    goto skip_2;
    // 0x8000DAA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
L_8000DAA4:
    // 0x8000DAA4: lb          $t9, 0x0($s7)
    ctx->r25 = MEM_B(ctx->r23, 0X0);
L_8000DAA8:
    // 0x8000DAA8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8000DAAC: addiu       $s2, $s2, 0x1D4
    ctx->r18 = ADD32(ctx->r18, 0X1D4);
    // 0x8000DAB0: slt         $at, $s5, $t9
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000DAB4: bnel        $at, $zero, L_8000D938
    if (ctx->r1 != 0) {
        // 0x8000DAB8: lw          $t5, 0x8($s6)
        ctx->r13 = MEM_W(ctx->r22, 0X8);
            goto L_8000D938;
    }
    goto skip_3;
    // 0x8000DAB8: lw          $t5, 0x8($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X8);
    skip_3:
L_8000DABC:
    // 0x8000DABC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DAC0: jal         0x8000E8E0
    // 0x8000DAC4: lw          $a0, 0x5CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CA0);
    AudioLoad_InitSampleDmaBuffers(rdram, ctx);
        goto after_20;
    // 0x8000DAC4: lw          $a0, 0x5CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CA0);
    after_20:
    // 0x8000DAC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DACC: sw          $zero, 0x3D04($at)
    MEM_W(0X3D04, ctx->r1) = 0;
    // 0x8000DAD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DAD4: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8000DAD8: jal         0x80021970
    // 0x8000DADC: sh          $t2, -0x3E4C($at)
    MEM_H(-0X3E4C, ctx->r1) = ctx->r10;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_21;
    // 0x8000DADC: sh          $t2, -0x3E4C($at)
    MEM_H(-0X3E4C, ctx->r1) = ctx->r10;
    after_21:
    // 0x8000DAE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000DAE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000DAE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000DAEC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DAF0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000DAF4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000DAF8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000DAFC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DB00: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000DB04: jr          $ra
    // 0x8000DB08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000DB08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Matrix_GetXYZAngles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006C7C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80006C80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006C84: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80006C88: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80006C8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006C90: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x80006C94: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80006C98: addiu       $t6, $t6, 0x46C4
    ctx->r14 = ADD32(ctx->r14, 0X46C4);
    // 0x80006C9C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80006CA0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80006CA4: addiu       $t1, $t1, 0x46D0
    ctx->r9 = ADD32(ctx->r9, 0X46D0);
    // 0x80006CA8: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80006CAC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80006CB0: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // 0x80006CB4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80006CB8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80006CBC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80006CC0: addiu       $t8, $t8, 0x46DC
    ctx->r24 = ADD32(ctx->r24, 0X46DC);
    // 0x80006CC4: addiu       $t5, $sp, 0x34
    ctx->r13 = ADD32(ctx->r29, 0X34);
    // 0x80006CC8: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80006CCC: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80006CD0: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80006CD4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80006CD8: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80006CDC: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80006CE0: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80006CE4: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80006CE8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80006CEC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80006CF0: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80006CF4: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80006CF8: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80006CFC: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80006D00: jal         0x80006A20
    // 0x80006D04: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_0;
    // 0x80006D04: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    after_0:
    // 0x80006D08: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80006D0C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80006D10: jal         0x80006A20
    // 0x80006D14: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x80006D14: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80006D18: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80006D1C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80006D20: jal         0x80006A20
    // 0x80006D24: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80006D24: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80006D28: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80006D2C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80006D30: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80006D34: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80006D38: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80006D3C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80006D40: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80006D44: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80006D48: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80006D4C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80006D50: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80006D54: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80006D58: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80006D5C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80006D60: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80006D64: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x80006D68: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80006D6C: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x80006D70: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80006D74: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80006D78: jal         0x80005100
    // 0x80006D7C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x80006D7C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80006D80: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80006D84: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80006D88: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80006D8C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80006D90: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80006D94: nop

    // 0x80006D98: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80006D9C: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80006DA0: jal         0x80005100
    // 0x80006DA4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_4;
    // 0x80006DA4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_4:
    // 0x80006DA8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80006DAC: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80006DB0: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80006DB4: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x80006DB8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006DBC: jal         0x80005E90
    // 0x80006DC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80006DC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80006DC4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80006DC8: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80006DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006DD0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80006DD4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80006DD8: jal         0x80005FE0
    // 0x80006DDC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80006DDC: nop

    after_6:
    // 0x80006DE0: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80006DE4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80006DE8: jal         0x80006A20
    // 0x80006DEC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_7;
    // 0x80006DEC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80006DF0: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80006DF4: jal         0x80005100
    // 0x80006DF8: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    Math_Atan2F(rdram, ctx);
        goto after_8;
    // 0x80006DF8: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80006DFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006E00: lwc1        $f2, -0x7EE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7EE8);
    // 0x80006E04: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80006E08: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80006E0C: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80006E10: nop

    // 0x80006E14: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80006E18: nop

    // 0x80006E1C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80006E20: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80006E24: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80006E28: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80006E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006E30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006E34: jr          $ra
    // 0x80006E38: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80006E38: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void AudioSeq_SequenceChannelSetVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800153C4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800153C8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800153CC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800153D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800153D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800153D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800153DC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800153E0: jr          $ra
    // 0x800153E4: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800153E4: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void Player_UpdatePath(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADF58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ADF5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800ADF60: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800ADF64: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x800ADF68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800ADF6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ADF70: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800ADF74: lwc1        $f4, 0x144($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X144);
    // 0x800ADF78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ADF7C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800ADF80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800ADF84: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800ADF88: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
    // 0x800ADF8C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800ADF90: swc1        $f6, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f6.u32l;
    // 0x800ADF94: swc1        $f0, 0x7D08($at)
    MEM_W(0X7D08, ctx->r1) = ctx->f0.u32l;
    // 0x800ADF98: lwc1        $f8, 0x144($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X144);
    // 0x800ADF9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ADFA0: swc1        $f8, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f8.u32l;
    // 0x800ADFA4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ADFA8: lwc1        $f16, 0x140($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X140);
    // 0x800ADFAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800ADFB0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ADFB4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800ADFB8: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x800ADFBC: bne         $t6, $at, L_800ADFD0
    if (ctx->r14 != ctx->r1) {
        // 0x800ADFC0: nop
    
            goto L_800ADFD0;
    }
    // 0x800ADFC0: nop

    // 0x800ADFC4: lwc1        $f4, 0x140($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X140);
    // 0x800ADFC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ADFCC: swc1        $f4, 0x7CC8($at)
    MEM_W(0X7CC8, ctx->r1) = ctx->f4.u32l;
L_800ADFD0:
    // 0x800ADFD0: lw          $t7, -0x7D7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D7C);
    // 0x800ADFD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADFD8: bnel        $t7, $zero, L_800AE014
    if (ctx->r15 != 0) {
        // 0x800ADFDC: lwc1        $f10, 0x7C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_800AE014;
    }
    goto skip_0;
    // 0x800ADFDC: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x800ADFE0: lwc1        $f6, -0x79A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X79A8);
    // 0x800ADFE4: lwc1        $f8, 0x144($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X144);
    // 0x800ADFE8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800ADFEC: nop

    // 0x800ADFF0: bc1fl       L_800AE014
    if (!c1cs) {
        // 0x800ADFF4: lwc1        $f10, 0x7C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_800AE014;
    }
    goto skip_1;
    // 0x800ADFF4: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    skip_1:
    // 0x800ADFF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ADFFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE000: swc1        $f0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f0.u32l;
    // 0x800AE004: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x800AE008: jal         0x800A6148
    // 0x800AE00C: sw          $zero, 0x7DC8($at)
    MEM_W(0X7DC8, ctx->r1) = 0;
    Play_ClearObjectData(rdram, ctx);
        goto after_0;
    // 0x800AE00C: sw          $zero, 0x7DC8($at)
    MEM_W(0X7DC8, ctx->r1) = 0;
    after_0:
    // 0x800AE010: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
L_800AE014:
    // 0x800AE014: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800AE018: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800AE01C: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE020: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AE024: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800AE028: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800AE02C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE030: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AE034: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x800AE038: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800AE03C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AE040: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
    // 0x800AE044: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE048: addiu       $a0, $s0, 0xB4
    ctx->r4 = ADD32(ctx->r16, 0XB4);
    // 0x800AE04C: swc1        $f16, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f16.u32l;
L_800AE050:
    // 0x800AE050: lwc1        $f0, 0xF8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800AE054: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AE058: nop

    // 0x800AE05C: bc1f        L_800AE070
    if (!c1cs) {
        // 0x800AE060: nop
    
            goto L_800AE070;
    }
    // 0x800AE060: nop

    // 0x800AE064: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AE068: b           L_800AE050
    // 0x800AE06C: swc1        $f18, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f18.u32l;
        goto L_800AE050;
    // 0x800AE06C: swc1        $f18, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f18.u32l;
L_800AE070:
    // 0x800AE070: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800AE074: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE078: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE07C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x800AE080: bc1f        L_800AE0A4
    if (!c1cs) {
        // 0x800AE084: nop
    
            goto L_800AE0A4;
    }
    // 0x800AE084: nop

    // 0x800AE088: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
L_800AE08C:
    // 0x800AE08C: swc1        $f4, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f4.u32l;
    // 0x800AE090: lwc1        $f0, 0xF8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800AE094: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800AE098: nop

    // 0x800AE09C: bc1tl       L_800AE08C
    if (c1cs) {
        // 0x800AE0A0: add.s       $f4, $f0, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_800AE08C;
    }
    goto skip_2;
    // 0x800AE0A0: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    skip_2:
L_800AE0A4:
    // 0x800AE0A4: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x800AE0A8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800AE0AC: bne         $t8, $at, L_800AE128
    if (ctx->r24 != ctx->r1) {
        // 0x800AE0B0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE128;
    }
    // 0x800AE0B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE0B4: lwc1        $f6, -0x79A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X79A4);
    // 0x800AE0B8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800AE0BC: jal         0x8009BC2C
    // 0x800AE0C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800AE0C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800AE0C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE0C8: lwc1        $f8, -0x79A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X79A0);
    // 0x800AE0CC: lw          $a1, 0xB8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB8);
    // 0x800AE0D0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE0D4: lw          $a3, 0xB4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB4);
    // 0x800AE0D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE0DC: addiu       $a0, $s0, 0xAC
    ctx->r4 = ADD32(ctx->r16, 0XAC);
    // 0x800AE0E0: jal         0x8009BC2C
    // 0x800AE0E4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800AE0E4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800AE0E8: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800AE0EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE0F0: lw          $a1, 0xBC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XBC);
    // 0x800AE0F4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800AE0F8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE0FC: lw          $a3, 0xB4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB4);
    // 0x800AE100: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE104: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
    // 0x800AE108: lwc1        $f18, -0x799C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X799C);
    // 0x800AE10C: addiu       $a0, $s0, 0xB0
    ctx->r4 = ADD32(ctx->r16, 0XB0);
    // 0x800AE110: jal         0x8009BC2C
    // 0x800AE114: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800AE114: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800AE118: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AE11C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800AE120: b           L_800AE1BC
    // 0x800AE124: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
        goto L_800AE1BC;
    // 0x800AE124: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
L_800AE128:
    // 0x800AE128: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE12C: lwc1        $f8, 0x7D08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x800AE130: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE134: lwc1        $f10, -0x7998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7998);
    // 0x800AE138: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE13C: lwc1        $f18, -0x7994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7994);
    // 0x800AE140: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AE144: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE148: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE14C: addiu       $a0, $s0, 0xB4
    ctx->r4 = ADD32(ctx->r16, 0XB4);
    // 0x800AE150: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800AE154: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800AE158: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800AE15C: jal         0x8009BC2C
    // 0x800AE160: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800AE160: nop

    after_4:
    // 0x800AE164: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE168: lwc1        $f4, -0x7990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7990);
    // 0x800AE16C: lw          $a1, 0xB8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB8);
    // 0x800AE170: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE174: lw          $a3, 0xB4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB4);
    // 0x800AE178: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE17C: addiu       $a0, $s0, 0xAC
    ctx->r4 = ADD32(ctx->r16, 0XAC);
    // 0x800AE180: jal         0x8009BC2C
    // 0x800AE184: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800AE184: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800AE188: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE18C: swc1        $f0, 0x79E4($at)
    MEM_W(0X79E4, ctx->r1) = ctx->f0.u32l;
    // 0x800AE190: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE194: lwc1        $f6, -0x798C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X798C);
    // 0x800AE198: lw          $a3, 0xB4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB4);
    // 0x800AE19C: lw          $a1, 0xBC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XBC);
    // 0x800AE1A0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE1A4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE1A8: addiu       $a0, $s0, 0xB0
    ctx->r4 = ADD32(ctx->r16, 0XB0);
    // 0x800AE1AC: jal         0x8009BC2C
    // 0x800AE1B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800AE1B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x800AE1B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE1B8: swc1        $f0, 0x79F4($at)
    MEM_W(0X79F4, ctx->r1) = ctx->f0.u32l;
L_800AE1BC:
    // 0x800AE1BC: lw          $v0, 0x210($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X210);
    // 0x800AE1C0: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x800AE1C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800AE1C8: beq         $v0, $zero, L_800AE228
    if (ctx->r2 == 0) {
        // 0x800AE1CC: lui         $a2, 0x3CF5
        ctx->r6 = S32(0X3CF5 << 16);
            goto L_800AE228;
    }
    // 0x800AE1CC: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x800AE1D0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800AE1D4: sw          $t9, 0x210($s0)
    MEM_W(0X210, ctx->r16) = ctx->r25;
    // 0x800AE1D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE1DC: lwc1        $f8, -0x7988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7988);
    // 0x800AE1E0: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
    // 0x800AE1E4: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x800AE1E8: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800AE1EC: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x800AE1F0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800AE1F4: jal         0x8009BC2C
    // 0x800AE1F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800AE1F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x800AE1FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE200: lwc1        $f10, -0x7984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7984);
    // 0x800AE204: lw          $a1, 0x124($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X124);
    // 0x800AE208: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x800AE20C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800AE210: addiu       $a0, $s0, 0x120
    ctx->r4 = ADD32(ctx->r16, 0X120);
    // 0x800AE214: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800AE218: jal         0x8009BC2C
    // 0x800AE21C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800AE21C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800AE220: b           L_800AE268
    // 0x800AE224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800AE268;
    // 0x800AE224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AE228:
    // 0x800AE228: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE22C: lwc1        $f16, -0x7980($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7980);
    // 0x800AE230: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800AE234: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800AE238: jal         0x8009BC2C
    // 0x800AE23C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800AE23C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x800AE240: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE244: lwc1        $f18, -0x797C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X797C);
    // 0x800AE248: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x800AE24C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800AE250: addiu       $a0, $s0, 0x120
    ctx->r4 = ADD32(ctx->r16, 0X120);
    // 0x800AE254: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800AE258: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800AE25C: jal         0x8009BC2C
    // 0x800AE260: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800AE260: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x800AE264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AE268:
    // 0x800AE268: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AE26C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800AE270: jr          $ra
    // 0x800AE274: nop

    return;
    // 0x800AE274: nop

;}
RECOMP_FUNC void Matrix_SetGfxMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006EBC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80006EC0: addiu       $a1, $a1, 0x7E5C
    ctx->r5 = ADD32(ctx->r5, 0X7E5C);
    // 0x80006EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006EC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80006ECC: jal         0x80006500
    // 0x80006ED0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    Matrix_ToMtx(rdram, ctx);
        goto after_0;
    // 0x80006ED0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x80006ED4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80006ED8: addiu       $a1, $a1, 0x7E5C
    ctx->r5 = ADD32(ctx->r5, 0X7E5C);
    // 0x80006EDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80006EE0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80006EE4: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x80006EE8: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x80006EEC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80006EF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80006EF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80006EF8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80006EFC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80006F00: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80006F04: addiu       $t0, $t9, 0x40
    ctx->r8 = ADD32(ctx->r25, 0X40);
    // 0x80006F08: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80006F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006F10: jr          $ra
    // 0x80006F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Audio_PlaySoundTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D8F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D8F8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D8FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D900: beq         $t6, $zero, L_8001D91C
    if (ctx->r14 == 0) {
        // 0x8001D904: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8001D91C;
    }
    // 0x8001D904: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D908: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001D90C: beq         $t6, $at, L_8001D958
    if (ctx->r14 == ctx->r1) {
        // 0x8001D910: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001D958;
    }
    // 0x8001D910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D914: b           L_8001D9D4
    // 0x8001D918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001D9D4;
    // 0x8001D918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D91C:
    // 0x8001D91C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D920: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8001D924: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001D928: jal         0x8001D444
    // 0x8001D92C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_0;
    // 0x8001D92C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
    // 0x8001D930: jal         0x8001ACDC
    // 0x8001D934: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_PlayVoice(rdram, ctx);
        goto after_1;
    // 0x8001D934: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8001D938: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8001D93C: jal         0x8001A838
    // 0x8001D940: ori         $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 | 0X1F;
    Audio_KillSfxById(rdram, ctx);
        goto after_2;
    // 0x8001D940: ori         $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 | 0X1F;
    after_2:
    // 0x8001D944: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8001D948: jal         0x8001A838
    // 0x8001D94C: ori         $a0, $a0, 0xF005
    ctx->r4 = ctx->r4 | 0XF005;
    Audio_KillSfxById(rdram, ctx);
        goto after_3;
    // 0x8001D94C: ori         $a0, $a0, 0xF005
    ctx->r4 = ctx->r4 | 0XF005;
    after_3:
    // 0x8001D950: b           L_8001D9D4
    // 0x8001D954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001D9D4;
    // 0x8001D954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D958:
    // 0x8001D958: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8001D95C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001D960: jal         0x8001D444
    // 0x8001D964: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_4;
    // 0x8001D964: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x8001D968: jal         0x8001ACDC
    // 0x8001D96C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Audio_PlayVoice(rdram, ctx);
        goto after_5;
    // 0x8001D96C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8001D970: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D974: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001D978: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D97C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8001D980: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8001D984: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D988: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D98C: ori         $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 | 0X1F;
    // 0x8001D990: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001D994: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D998: jal         0x80019218
    // 0x8001D99C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x8001D99C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8001D9A0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D9A4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001D9A8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D9AC: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8001D9B0: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8001D9B4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D9B8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D9BC: ori         $a0, $a0, 0xF005
    ctx->r4 = ctx->r4 | 0XF005;
    // 0x8001D9C0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8001D9C4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D9C8: jal         0x80019218
    // 0x8001D9CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8001D9CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8001D9D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D9D4:
    // 0x8001D9D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D9D8: jr          $ra
    // 0x8001D9DC: nop

    return;
    // 0x8001D9DC: nop

;}
RECOMP_FUNC void Fault_FillRectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800073C0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800073C4: addiu       $t1, $t1, 0x5360
    ctx->r9 = ADD32(ctx->r9, 0X5360);
    // 0x800073C8: lhu         $v1, 0x9D0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X9D0);
    // 0x800073CC: lw          $t8, 0x9CC($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X9CC);
    // 0x800073D0: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x800073D4: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800073D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800073DC: mflo        $t6
    ctx->r14 = lo;
    // 0x800073E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800073E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800073E8: blez        $a3, L_800074A4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800073EC: addu        $v0, $t9, $t2
        ctx->r2 = ADD32(ctx->r25, ctx->r10);
            goto L_800074A4;
    }
    // 0x800073EC: addu        $v0, $t9, $t2
    ctx->r2 = ADD32(ctx->r25, ctx->r10);
L_800073F0:
    // 0x800073F0: blez        $a2, L_80007490
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800073F4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80007490;
    }
    // 0x800073F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800073F8: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x800073FC: beq         $a1, $zero, L_8000742C
    if (ctx->r5 == 0) {
        // 0x80007400: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8000742C;
    }
    // 0x80007400: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80007404:
    // 0x80007404: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x80007408: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000740C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80007410: andi        $t4, $t3, 0xE738
    ctx->r12 = ctx->r11 & 0XE738;
    // 0x80007414: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80007418: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8000741C: bne         $v1, $a0, L_80007404
    if (ctx->r3 != ctx->r4) {
        // 0x80007420: sh          $t6, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r14;
            goto L_80007404;
    }
    // 0x80007420: sh          $t6, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r14;
    // 0x80007424: beq         $a0, $a2, L_80007488
    if (ctx->r4 == ctx->r6) {
        // 0x80007428: nop
    
            goto L_80007488;
    }
    // 0x80007428: nop

L_8000742C:
    // 0x8000742C: lhu         $t3, 0x2($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2);
    // 0x80007430: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80007434: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80007438: andi        $t4, $t3, 0xE738
    ctx->r12 = ctx->r11 & 0XE738;
    // 0x8000743C: andi        $t8, $t7, 0xE738
    ctx->r24 = ctx->r15 & 0XE738;
    // 0x80007440: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x80007444: lhu         $t3, 0x6($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X6);
    // 0x80007448: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8000744C: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80007450: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80007454: ori         $t2, $t9, 0x1
    ctx->r10 = ctx->r25 | 0X1;
    // 0x80007458: andi        $t8, $t7, 0xE738
    ctx->r24 = ctx->r15 & 0XE738;
    // 0x8000745C: andi        $t4, $t3, 0xE738
    ctx->r12 = ctx->r11 & 0XE738;
    // 0x80007460: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80007464: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80007468: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x8000746C: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x80007470: ori         $t2, $t9, 0x1
    ctx->r10 = ctx->r25 | 0X1;
    // 0x80007474: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80007478: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x8000747C: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x80007480: bne         $a0, $a2, L_8000742C
    if (ctx->r4 != ctx->r6) {
        // 0x80007484: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_8000742C;
    }
    // 0x80007484: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80007488:
    // 0x80007488: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8000748C: lhu         $v1, 0x5D30($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X5D30);
L_80007490:
    // 0x80007490: subu        $t7, $v1, $a2
    ctx->r15 = SUB32(ctx->r3, ctx->r6);
    // 0x80007494: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80007498: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8000749C: bne         $t0, $a3, L_800073F0
    if (ctx->r8 != ctx->r7) {
        // 0x800074A0: addu        $v0, $v0, $t8
        ctx->r2 = ADD32(ctx->r2, ctx->r24);
            goto L_800073F0;
    }
    // 0x800074A0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
L_800074A4:
    // 0x800074A4: jr          $ra
    // 0x800074A8: nop

    return;
    // 0x800074A8: nop

;}
RECOMP_FUNC void Player_UpdateArwingRoll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2134: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B2138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B213C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B2140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2144: lwc1        $f4, -0x76A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76A0);
    // 0x800B2148: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B214C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2150: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x800B2154: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800B2158: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B215C: jal         0x8009BC2C
    // 0x800B2160: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B2160: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800B2164: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800B2168: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B216C: jal         0x80004E20
    // 0x800B2170: lwc1        $f12, 0x130($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X130);
    Math_ModF(rdram, ctx);
        goto after_1;
    // 0x800B2170: lwc1        $f12, 0x130($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X130);
    after_1:
    // 0x800B2174: lw          $v0, 0x280($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X280);
    // 0x800B2178: swc1        $f0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f0.u32l;
    // 0x800B217C: blez        $v0, L_800B2190
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2180: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_800B2190;
    }
    // 0x800B2180: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x800B2184: bgtz        $t6, L_800B2190
    if (SIGNED(ctx->r14) > 0) {
        // 0x800B2188: sw          $t6, 0x280($s0)
        MEM_W(0X280, ctx->r16) = ctx->r14;
            goto L_800B2190;
    }
    // 0x800B2188: sw          $t6, 0x280($s0)
    MEM_W(0X280, ctx->r16) = ctx->r14;
    // 0x800B218C: sw          $zero, 0x280($s0)
    MEM_W(0X280, ctx->r16) = 0;
L_800B2190:
    // 0x800B2190: lw          $t8, 0x27C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X27C);
    // 0x800B2194: bnel        $t8, $zero, L_800B22B0
    if (ctx->r24 != 0) {
        // 0x800B2198: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B22B0;
    }
    goto skip_0;
    // 0x800B2198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800B219C: lw          $t9, 0x1DC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1DC);
    // 0x800B21A0: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x800B21A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B21A8: bne         $t9, $zero, L_800B21C8
    if (ctx->r25 != 0) {
        // 0x800B21AC: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_800B21C8;
    }
    // 0x800B21AC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B21B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B21B4: lwc1        $f6, -0x769C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X769C);
    // 0x800B21B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B21BC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B21C0: jal         0x8009BC2C
    // 0x800B21C4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800B21C4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
L_800B21C8:
    // 0x800B21C8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x800B21CC: beq         $v0, $zero, L_800B21D8
    if (ctx->r2 == 0) {
        // 0x800B21D0: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_800B21D8;
    }
    // 0x800B21D0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800B21D4: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
L_800B21D8:
    // 0x800B21D8: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x800B21DC: beq         $v0, $zero, L_800B21E8
    if (ctx->r2 == 0) {
        // 0x800B21E0: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800B21E8;
    }
    // 0x800B21E0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x800B21E4: sw          $t1, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r9;
L_800B21E8:
    // 0x800B21E8: lw          $v0, 0x214($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X214);
    // 0x800B21EC: beq         $v0, $zero, L_800B21F8
    if (ctx->r2 == 0) {
        // 0x800B21F0: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800B21F8;
    }
    // 0x800B21F0: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800B21F4: sw          $t2, 0x214($s0)
    MEM_W(0X214, ctx->r16) = ctx->r10;
L_800B21F8:
    // 0x800B21F8: lw          $v0, 0x218($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X218);
    // 0x800B21FC: beq         $v0, $zero, L_800B2208
    if (ctx->r2 == 0) {
        // 0x800B2200: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800B2208;
    }
    // 0x800B2200: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800B2204: sw          $t3, 0x218($s0)
    MEM_W(0X218, ctx->r16) = ctx->r11;
L_800B2208:
    // 0x800B2208: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
    // 0x800B220C: beq         $v0, $zero, L_800B2218
    if (ctx->r2 == 0) {
        // 0x800B2210: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800B2218;
    }
    // 0x800B2210: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800B2214: sw          $t4, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r12;
L_800B2218:
    // 0x800B2218: lw          $t5, 0x1DC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1DC);
    // 0x800B221C: beql        $t5, $zero, L_800B22B0
    if (ctx->r13 == 0) {
        // 0x800B2220: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B22B0;
    }
    goto skip_1;
    // 0x800B2220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800B2224: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x800B2228: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B222C: lw          $t6, 0x1E8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E8);
    // 0x800B2230: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B2234: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B2238: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B223C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2240: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x800B2244: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x800B2248: swc1        $f8, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f8.u32l;
    // 0x800B224C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800B2250: bne         $t6, $zero, L_800B2288
    if (ctx->r14 != 0) {
        // 0x800B2254: swc1        $f4, 0x130($s0)
        MEM_W(0X130, ctx->r16) = ctx->f4.u32l;
            goto L_800B2288;
    }
    // 0x800B2254: swc1        $f4, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f4.u32l;
    // 0x800B2258: blez        $v0, L_800B2268
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B225C: addiu       $t7, $v0, -0x5
        ctx->r15 = ADD32(ctx->r2, -0X5);
            goto L_800B2268;
    }
    // 0x800B225C: addiu       $t7, $v0, -0x5
    ctx->r15 = ADD32(ctx->r2, -0X5);
    // 0x800B2260: sw          $t7, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r15;
    // 0x800B2264: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800B2268:
    // 0x800B2268: bgez        $v0, L_800B2278
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B226C: addiu       $t8, $v0, 0x5
        ctx->r24 = ADD32(ctx->r2, 0X5);
            goto L_800B2278;
    }
    // 0x800B226C: addiu       $t8, $v0, 0x5
    ctx->r24 = ADD32(ctx->r2, 0X5);
    // 0x800B2270: sw          $t8, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r24;
    // 0x800B2274: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800B2278:
    // 0x800B2278: bnel        $v0, $zero, L_800B22B0
    if (ctx->r2 != 0) {
        // 0x800B227C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B22B0;
    }
    goto skip_2;
    // 0x800B227C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800B2280: b           L_800B22AC
    // 0x800B2284: sw          $zero, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = 0;
        goto L_800B22AC;
    // 0x800B2284: sw          $zero, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = 0;
L_800B2288:
    // 0x800B2288: lw          $v0, 0x280($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X280);
    // 0x800B228C: slti        $at, $v0, 0xB4
    ctx->r1 = SIGNED(ctx->r2) < 0XB4 ? 1 : 0;
    // 0x800B2290: beq         $at, $zero, L_800B22AC
    if (ctx->r1 == 0) {
        // 0x800B2294: addiu       $t9, $v0, 0x64
        ctx->r25 = ADD32(ctx->r2, 0X64);
            goto L_800B22AC;
    }
    // 0x800B2294: addiu       $t9, $v0, 0x64
    ctx->r25 = ADD32(ctx->r2, 0X64);
    // 0x800B2298: slti        $at, $t9, 0xB5
    ctx->r1 = SIGNED(ctx->r25) < 0XB5 ? 1 : 0;
    // 0x800B229C: bne         $at, $zero, L_800B22AC
    if (ctx->r1 != 0) {
        // 0x800B22A0: sw          $t9, 0x280($s0)
        MEM_W(0X280, ctx->r16) = ctx->r25;
            goto L_800B22AC;
    }
    // 0x800B22A0: sw          $t9, 0x280($s0)
    MEM_W(0X280, ctx->r16) = ctx->r25;
    // 0x800B22A4: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x800B22A8: sw          $t1, 0x280($s0)
    MEM_W(0X280, ctx->r16) = ctx->r9;
L_800B22AC:
    // 0x800B22AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B22B0:
    // 0x800B22B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B22B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B22B8: jr          $ra
    // 0x800B22BC: nop

    return;
    // 0x800B22BC: nop

;}
RECOMP_FUNC void ActorAllRange_CheckPlayerNearby(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031858: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003185C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80031860: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80031864: lw          $t6, 0x1C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C8);
    // 0x80031868: bnel        $t6, $at, L_800318F8
    if (ctx->r14 != ctx->r1) {
        // 0x8003186C: sw          $zero, 0x78($a0)
        MEM_W(0X78, ctx->r4) = 0;
            goto L_800318F8;
    }
    goto skip_0;
    // 0x8003186C: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    skip_0:
    // 0x80031870: lw          $t7, 0xB0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB0);
    // 0x80031874: beql        $t7, $zero, L_800318F8
    if (ctx->r15 == 0) {
        // 0x80031878: sw          $zero, 0x78($a0)
        MEM_W(0X78, ctx->r4) = 0;
            goto L_800318F8;
    }
    goto skip_1;
    // 0x80031878: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    skip_1:
    // 0x8003187C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031880: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80031884: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80031888: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003188C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80031890: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80031894: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80031898: nop

    // 0x8003189C: bc1fl       L_800318F8
    if (!c1cs) {
        // 0x800318A0: sw          $zero, 0x78($a0)
        MEM_W(0X78, ctx->r4) = 0;
            goto L_800318F8;
    }
    goto skip_2;
    // 0x800318A0: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    skip_2:
    // 0x800318A4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800318A8: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800318AC: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800318B0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800318B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800318B8: nop

    // 0x800318BC: bc1fl       L_800318F8
    if (!c1cs) {
        // 0x800318C0: sw          $zero, 0x78($a0)
        MEM_W(0X78, ctx->r4) = 0;
            goto L_800318F8;
    }
    goto skip_3;
    // 0x800318C0: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    skip_3:
    // 0x800318C4: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800318C8: lwc1        $f18, 0x138($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X138);
    // 0x800318CC: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800318D0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800318D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800318D8: nop

    // 0x800318DC: bc1fl       L_800318F8
    if (!c1cs) {
        // 0x800318E0: sw          $zero, 0x78($a0)
        MEM_W(0X78, ctx->r4) = 0;
            goto L_800318F8;
    }
    goto skip_4;
    // 0x800318E0: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    skip_4:
    // 0x800318E4: lw          $t8, 0x78($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X78);
    // 0x800318E8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800318EC: jr          $ra
    // 0x800318F0: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    return;
    // 0x800318F0: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    // 0x800318F4: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
L_800318F8:
    // 0x800318F8: jr          $ra
    // 0x800318FC: nop

    return;
    // 0x800318FC: nop

;}
RECOMP_FUNC void Player_WaterEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4C40: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A4C44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A4C48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A4C4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A4C50: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A4C54: addiu       $t7, $t7, 0x2F80
    ctx->r15 = ADD32(ctx->r15, 0X2F80);
    // 0x800A4C58: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800A4C5C: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x800A4C60: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800A4C64: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800A4C68: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800A4C6C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A4C70: addiu       $t2, $t2, 0x2F8C
    ctx->r10 = ADD32(ctx->r10, 0X2F8C);
    // 0x800A4C74: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800A4C78: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800A4C7C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800A4C80: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x800A4C84: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800A4C88: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800A4C8C: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800A4C90: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800A4C94: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800A4C98: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800A4C9C: lw          $t9, 0x1A88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1A88);
    // 0x800A4CA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A4CA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A4CA8: bnel        $t9, $at, L_800A4F3C
    if (ctx->r25 != ctx->r1) {
        // 0x800A4CAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A4F3C;
    }
    goto skip_0;
    // 0x800A4CAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800A4CB0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x800A4CB4: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x800A4CB8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x800A4CBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A4CC0: jal         0x80005B00
    // 0x800A4CC4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x800A4CC4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_0:
    // 0x800A4CC8: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800A4CCC: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800A4CD0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800A4CD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4CD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A4CDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4CE0: lwc1        $f18, -0x7CB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7CB8);
    // 0x800A4CE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A4CE8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A4CEC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A4CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A4CF4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A4CF8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800A4CFC: jal         0x80005E90
    // 0x800A4D00: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x800A4D00: nop

    after_1:
    // 0x800A4D04: lwc1        $f6, 0xE4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800A4D08: lwc1        $f8, 0x4D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800A4D0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4D10: lwc1        $f16, -0x7CB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7CB4);
    // 0x800A4D14: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A4D18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A4D1C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A4D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A4D24: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A4D28: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800A4D2C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800A4D30: jal         0x80005D44
    // 0x800A4D34: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x800A4D34: nop

    after_2:
    // 0x800A4D38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4D3C: lwc1        $f8, -0x7CB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7CB0);
    // 0x800A4D40: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800A4D44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A4D48: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A4D4C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A4D50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A4D54: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800A4D58: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800A4D5C: jal         0x80005FE0
    // 0x800A4D60: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x800A4D60: nop

    after_3:
    // 0x800A4D64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A4D68: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A4D6C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800A4D70: jal         0x80006970
    // 0x800A4D74: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x800A4D74: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x800A4D78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A4D7C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A4D80: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800A4D84: jal         0x80006970
    // 0x800A4D88: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x800A4D88: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x800A4D8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A4D90: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800A4D94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A4D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A4D9C: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800A4DA0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800A4DA4: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800A4DA8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A4DAC: nop

    // 0x800A4DB0: bc1fl       L_800A4EAC
    if (!c1cs) {
        // 0x800A4DB4: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_800A4EAC;
    }
    goto skip_1;
    // 0x800A4DB4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_1:
    // 0x800A4DB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4DBC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A4DC0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A4DC4: add.s       $f0, $f14, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800A4DC8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800A4DCC: nop

    // 0x800A4DD0: bc1fl       L_800A4E40
    if (!c1cs) {
        // 0x800A4DD4: lwc1        $f4, 0x34($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800A4E40;
    }
    goto skip_2;
    // 0x800A4DD4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x800A4DD8: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x800A4DDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A4DE0: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800A4DE4: bnel        $t6, $zero, L_800A4E40
    if (ctx->r14 != 0) {
        // 0x800A4DE8: lwc1        $f4, 0x34($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800A4E40;
    }
    goto skip_3;
    // 0x800A4DE8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x800A4DEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A4DF0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800A4DF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4DF8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800A4DFC: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800A4E00: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800A4E04: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x800A4E08: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800A4E0C: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800A4E10: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A4E14: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800A4E18: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A4E1C: jal         0x8007ACE0
    // 0x800A4E20: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Effect_WaterSpray_Spawn(rdram, ctx);
        goto after_6;
    // 0x800A4E20: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x800A4E24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A4E28: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800A4E2C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800A4E30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A4E34: nop

    // 0x800A4E38: add.s       $f0, $f14, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800A4E3C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
L_800A4E40:
    // 0x800A4E40: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800A4E44: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A4E48: nop

    // 0x800A4E4C: bc1fl       L_800A4EAC
    if (!c1cs) {
        // 0x800A4E50: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_800A4EAC;
    }
    goto skip_4;
    // 0x800A4E50: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_4:
    // 0x800A4E54: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800A4E58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A4E5C: andi        $t0, $t7, 0x1
    ctx->r8 = ctx->r15 & 0X1;
    // 0x800A4E60: bnel        $t0, $zero, L_800A4EAC
    if (ctx->r8 != 0) {
        // 0x800A4E64: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_800A4EAC;
    }
    goto skip_5;
    // 0x800A4E64: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_5:
    // 0x800A4E68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4E6C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800A4E70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A4E74: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800A4E78: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800A4E7C: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800A4E80: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x800A4E84: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800A4E88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A4E8C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A4E90: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800A4E94: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A4E98: jal         0x8007ACE0
    // 0x800A4E9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Effect_WaterSpray_Spawn(rdram, ctx);
        goto after_7;
    // 0x800A4E9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x800A4EA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A4EA4: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800A4EA8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
L_800A4EAC:
    // 0x800A4EAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4EB0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A4EB4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A4EB8: add.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x800A4EBC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800A4EC0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800A4EC4: nop

    // 0x800A4EC8: bc1t        L_800A4EE8
    if (c1cs) {
        // 0x800A4ECC: nop
    
            goto L_800A4EE8;
    }
    // 0x800A4ECC: nop

    // 0x800A4ED0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800A4ED4: lui         $a1, 0x1100
    ctx->r5 = S32(0X1100 << 16);
    // 0x800A4ED8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A4EDC: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x800A4EE0: bc1f        L_800A4F30
    if (!c1cs) {
        // 0x800A4EE4: addiu       $a0, $s0, 0x460
        ctx->r4 = ADD32(ctx->r16, 0X460);
            goto L_800A4F30;
    }
    // 0x800A4EE4: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
L_800A4EE8:
    // 0x800A4EE8: lw          $t4, 0x1A64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1A64);
    // 0x800A4EEC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A4EF0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A4EF4: bne         $t4, $zero, L_800A4F38
    if (ctx->r12 != 0) {
        // 0x800A4EF8: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800A4F38;
    }
    // 0x800A4EF8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A4EFC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800A4F00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A4F04: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x800A4F08: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x800A4F0C: sw          $t3, 0x1A64($at)
    MEM_W(0X1A64, ctx->r1) = ctx->r11;
    // 0x800A4F10: ori         $a0, $a0, 0xB
    ctx->r4 = ctx->r4 | 0XB;
    // 0x800A4F14: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800A4F18: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x800A4F1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A4F20: jal         0x80019218
    // 0x800A4F24: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x800A4F24: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_8:
    // 0x800A4F28: b           L_800A4F3C
    // 0x800A4F2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A4F3C;
    // 0x800A4F2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A4F30:
    // 0x800A4F30: jal         0x8001A55C
    // 0x800A4F34: sw          $zero, 0x1A64($at)
    MEM_W(0X1A64, ctx->r1) = 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_9;
    // 0x800A4F34: sw          $zero, 0x1A64($at)
    MEM_W(0X1A64, ctx->r1) = 0;
    after_9:
L_800A4F38:
    // 0x800A4F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A4F3C:
    // 0x800A4F3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A4F40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800A4F44: jr          $ra
    // 0x800A4F48: nop

    return;
    // 0x800A4F48: nop

;}
RECOMP_FUNC void Play_UpdateDynaFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3FEC: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800A3FF0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800A3FF4: addiu       $a2, $a2, -0x7D04
    ctx->r6 = ADD32(ctx->r6, -0X7D04);
    // 0x800A3FF8: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800A3FFC: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800A4000: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800A4004: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800A4008: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800A400C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800A4010: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800A4014: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800A4018: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800A401C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800A4020: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x800A4024: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800A4028: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800A402C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800A4030: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800A4034: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800A4038: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A403C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800A4040: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A4044: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A4048: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800A404C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800A4050: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A4054: beq         $v0, $at, L_800A4074
    if (ctx->r2 == ctx->r1) {
        // 0x800A4058: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A4074;
    }
    // 0x800A4058: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A405C: beq         $v0, $at, L_800A4158
    if (ctx->r2 == ctx->r1) {
        // 0x800A4060: lwc1        $f30, 0x8C($sp)
        ctx->f30.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800A4158;
    }
    // 0x800A4060: lwc1        $f30, 0x8C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A4064: lwc1        $f28, 0x90($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A4068: lw          $s7, 0xB4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XB4);
    // 0x800A406C: b           L_800A423C
    // 0x800A4070: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
        goto L_800A423C;
    // 0x800A4070: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
L_800A4074:
    // 0x800A4074: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x800A4078: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800A407C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800A4080: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800A4084: beq         $t9, $zero, L_800A40CC
    if (ctx->r25 == 0) {
        // 0x800A4088: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A40CC;
    }
    // 0x800A4088: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A408C: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800A4090: addiu       $v0, $v0, 0x1C50
    ctx->r2 = ADD32(ctx->r2, 0X1C50);
    // 0x800A4094: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x800A4098: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A409C: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x800A40A0: addiu       $v1, $v1, 0x1FD0
    ctx->r3 = ADD32(ctx->r3, 0X1FD0);
    // 0x800A40A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A40A8: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800A40AC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800A40B0: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800A40B4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800A40B8: and         $t5, $v0, $a0
    ctx->r13 = ctx->r2 & ctx->r4;
    // 0x800A40BC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800A40C0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A40C4: b           L_800A4108
    // 0x800A40C8: addu        $s7, $t6, $a1
    ctx->r23 = ADD32(ctx->r14, ctx->r5);
        goto L_800A4108;
    // 0x800A40C8: addu        $s7, $t6, $a1
    ctx->r23 = ADD32(ctx->r14, ctx->r5);
L_800A40CC:
    // 0x800A40CC: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800A40D0: addiu       $v0, $v0, 0x4500
    ctx->r2 = ADD32(ctx->r2, 0X4500);
    // 0x800A40D4: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800A40D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A40DC: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800A40E0: addiu       $v1, $v1, 0x1FD0
    ctx->r3 = ADD32(ctx->r3, 0X1FD0);
    // 0x800A40E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A40E8: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x800A40EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A40F0: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800A40F4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800A40F8: and         $t2, $v0, $a0
    ctx->r10 = ctx->r2 & ctx->r4;
    // 0x800A40FC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800A4100: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A4104: addu        $s7, $t3, $a1
    ctx->r23 = ADD32(ctx->r11, ctx->r5);
L_800A4108:
    // 0x800A4108: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x800A410C: addiu       $v0, $v0, 0x2760
    ctx->r2 = ADD32(ctx->r2, 0X2760);
    // 0x800A4110: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x800A4114: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x800A4118: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A411C: lwc1        $f30, -0x7D00($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X7D00);
    // 0x800A4120: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800A4124: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4128: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800A412C: lwc1        $f4, -0x7CFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7CFC);
    // 0x800A4130: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4134: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4138: and         $t9, $v0, $a0
    ctx->r25 = ctx->r2 & ctx->r4;
    // 0x800A413C: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x800A4140: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A4144: addu        $s2, $t0, $a1
    ctx->r18 = ADD32(ctx->r8, ctx->r5);
    // 0x800A4148: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A414C: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x800A4150: b           L_800A423C
    // 0x800A4154: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
        goto L_800A423C;
    // 0x800A4154: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
L_800A4158:
    // 0x800A4158: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800A415C: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x800A4160: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A4164: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800A4168: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800A416C: beq         $t3, $zero, L_800A41B4
    if (ctx->r11 == 0) {
        // 0x800A4170: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A41B4;
    }
    // 0x800A4170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4174: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x800A4178: addiu       $v0, $v0, -0x6130
    ctx->r2 = ADD32(ctx->r2, -0X6130);
    // 0x800A417C: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x800A4180: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A4184: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x800A4188: addiu       $v1, $v1, 0x1FD0
    ctx->r3 = ADD32(ctx->r3, 0X1FD0);
    // 0x800A418C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A4190: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800A4194: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800A4198: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800A419C: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800A41A0: and         $t9, $v0, $a0
    ctx->r25 = ctx->r2 & ctx->r4;
    // 0x800A41A4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800A41A8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A41AC: b           L_800A41F0
    // 0x800A41B0: addu        $s7, $t0, $a1
    ctx->r23 = ADD32(ctx->r8, ctx->r5);
        goto L_800A41F0;
    // 0x800A41B0: addu        $s7, $t0, $a1
    ctx->r23 = ADD32(ctx->r8, ctx->r5);
L_800A41B4:
    // 0x800A41B4: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x800A41B8: addiu       $v0, $v0, -0x3880
    ctx->r2 = ADD32(ctx->r2, -0X3880);
    // 0x800A41BC: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800A41C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A41C4: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x800A41C8: addiu       $v1, $v1, 0x1FD0
    ctx->r3 = ADD32(ctx->r3, 0X1FD0);
    // 0x800A41CC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A41D0: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800A41D4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A41D8: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800A41DC: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800A41E0: and         $t6, $v0, $a0
    ctx->r14 = ctx->r2 & ctx->r4;
    // 0x800A41E4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800A41E8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A41EC: addu        $s7, $t7, $a1
    ctx->r23 = ADD32(ctx->r15, ctx->r5);
L_800A41F0:
    // 0x800A41F0: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x800A41F4: addiu       $v0, $v0, -0x53B0
    ctx->r2 = ADD32(ctx->r2, -0X53B0);
    // 0x800A41F8: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800A41FC: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800A4200: lwc1        $f30, -0x7CF8($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X7CF8);
    // 0x800A4204: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800A4208: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A420C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4210: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x800A4214: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A4218: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A421C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4220: and         $t3, $v0, $a0
    ctx->r11 = ctx->r2 & ctx->r4;
    // 0x800A4224: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x800A4228: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800A422C: addu        $s2, $t4, $a1
    ctx->r18 = ADD32(ctx->r12, ctx->r5);
    // 0x800A4230: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x800A4234: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x800A4238: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
L_800A423C:
    // 0x800A423C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800A4240: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A4244: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4248: lwc1        $f24, -0x7CF4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X7CF4);
    // 0x800A424C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A4250: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800A4254: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x800A4258: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x800A425C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800A4260: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x800A4264: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x800A4268: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800A426C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800A4270: lw          $s3, -0x7D34($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X7D34);
    // 0x800A4274: lw          $s5, -0x7D2C($s5)
    ctx->r21 = MEM_W(ctx->r21, -0X7D2C);
    // 0x800A4278: lw          $s4, -0x7D24($s4)
    ctx->r20 = MEM_W(ctx->r20, -0X7D24);
    // 0x800A427C: lw          $s0, -0x7D1C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D1C);
    // 0x800A4280: lw          $s1, -0x7D14($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X7D14);
    // 0x800A4284: addiu       $fp, $fp, -0x4438
    ctx->r30 = ADD32(ctx->r30, -0X4438);
    // 0x800A4288: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800A428C:
    // 0x800A428C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x800A4290: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x800A4294: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    // 0x800A4298: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800A429C: jal         0x8009BC2C
    // 0x800A42A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800A42A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800A42A4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800A42A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A42AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A42B0: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x800A42B4: jal         0x8009BC2C
    // 0x800A42B8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800A42B8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800A42BC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800A42C0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A42C4: lw          $t8, -0x7D04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D04);
    // 0x800A42C8: and         $t7, $s6, $t6
    ctx->r15 = ctx->r22 & ctx->r14;
    // 0x800A42CC: and         $t9, $t8, $t6
    ctx->r25 = ctx->r24 & ctx->r14;
    // 0x800A42D0: bnel        $t7, $t9, L_800A42F0
    if (ctx->r15 != ctx->r25) {
        // 0x800A42D4: lwc1        $f18, 0x0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800A42F0;
    }
    goto skip_0;
    // 0x800A42D4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800A42D8: jal         0x80004EB0
    // 0x800A42DC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800A42DC: nop

    after_2:
    // 0x800A42E0: mul.s       $f16, $f0, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800A42E4: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
    // 0x800A42E8: swc1        $f20, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f20.u32l;
    // 0x800A42EC: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
L_800A42F0:
    // 0x800A42F0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800A42F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A42F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A42FC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A4300: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800A4304: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800A4308: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A430C: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x800A4310: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A4314: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800A4318: nop

    // 0x800A431C: bc1fl       L_800A4334
    if (!c1cs) {
        // 0x800A4320: lwc1        $f4, 0x0($s3)
        ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
            goto L_800A4334;
    }
    goto skip_1;
    // 0x800A4320: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x800A4324: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x800A4328: swc1        $f20, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
    // 0x800A432C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A4330: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
L_800A4334:
    // 0x800A4334: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A4338: lhu         $t9, 0x0($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X0);
    // 0x800A433C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A4340: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A4344: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800A4348: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800A434C: addu        $t1, $s7, $t0
    ctx->r9 = ADD32(ctx->r23, ctx->r8);
    // 0x800A4350: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800A4354: nop

    // 0x800A4358: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800A435C: sh          $t7, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r15;
    // 0x800A4360: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A4364: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800A4368: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800A436C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A4370: nop

    // 0x800A4374: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800A4378: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A437C: jal         0x80005FE0
    // 0x800A4380: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x800A4380: nop

    after_3:
    // 0x800A4384: swc1        $f26, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f26.u32l;
    // 0x800A4388: swc1        $f20, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f20.u32l;
    // 0x800A438C: swc1        $f20, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f20.u32l;
    // 0x800A4390: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800A4394: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x800A4398: jal         0x80006A20
    // 0x800A439C: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x800A439C: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    after_4:
    // 0x800A43A0: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800A43A4: lhu         $t5, 0x0($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X0);
    // 0x800A43A8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800A43AC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A43B0: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x800A43B4: addu        $t3, $s7, $t8
    ctx->r11 = ADD32(ctx->r23, ctx->r24);
    // 0x800A43B8: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x800A43BC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A43C0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800A43C4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800A43C8: sb          $t4, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r12;
    // 0x800A43CC: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800A43D0: lhu         $t0, 0x0($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X0);
    // 0x800A43D4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800A43D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A43DC: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x800A43E0: addu        $t1, $s7, $t7
    ctx->r9 = ADD32(ctx->r23, ctx->r15);
    // 0x800A43E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A43E8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800A43EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800A43F0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800A43F4: sb          $t9, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r25;
    // 0x800A43F8: lwc1        $f16, 0xC0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800A43FC: lhu         $t8, -0x2($s2)
    ctx->r24 = MEM_HU(ctx->r18, -0X2);
    // 0x800A4400: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A4404: sll         $t4, $t8, 4
    ctx->r12 = S32(ctx->r24 << 4);
    // 0x800A4408: addu        $t3, $s7, $t4
    ctx->r11 = ADD32(ctx->r23, ctx->r12);
    // 0x800A440C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800A4410: bne         $s6, $at, L_800A428C
    if (ctx->r22 != ctx->r1) {
        // 0x800A4414: sb          $t5, 0xE($t3)
        MEM_B(0XE, ctx->r11) = ctx->r13;
            goto L_800A428C;
    }
    // 0x800A4414: sb          $t5, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r13;
    // 0x800A4418: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800A441C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800A4420: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800A4424: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800A4428: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800A442C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800A4430: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800A4434: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800A4438: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800A443C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800A4440: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800A4444: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800A4448: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800A444C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800A4450: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4454: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800A4458: jr          $ra
    // 0x800A445C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800A445C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void Player_MoveArwing360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE4A4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800AE4A8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AE4AC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AE4B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800AE4B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AE4B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AE4BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE4C0: lwc1        $f4, -0x7958($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x800AE4C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE4C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AE4CC: swc1        $f4, 0x7968($at)
    MEM_W(0X7968, ctx->r1) = ctx->f4.u32l;
    // 0x800AE4D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE4D4: lwc1        $f6, -0x7954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x800AE4D8: lw          $v0, 0x797C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X797C);
    // 0x800AE4DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE4E0: swc1        $f6, 0x7970($at)
    MEM_W(0X7970, ctx->r1) = ctx->f6.u32l;
    // 0x800AE4E4: lb          $t6, 0x2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X2);
    // 0x800AE4E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE4EC: lwc1        $f4, -0x7950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7950);
    // 0x800AE4F0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800AE4F4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800AE4F8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800AE4FC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE500: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AE504: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE508: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x800AE50C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800AE510: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800AE514: lb          $t8, 0x3($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3);
    // 0x800AE518: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800AE51C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800AE520: nop

    // 0x800AE524: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AE528: jal         0x8009BD38
    // 0x800AE52C: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_0;
    // 0x800AE52C: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800AE530: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE538: lwc1        $f10, -0x794C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X794C);
    // 0x800AE53C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AE540: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AE544: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AE548: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AE54C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AE550: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800AE554: jal         0x80005FE0
    // 0x800AE558: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x800AE558: nop

    after_1:
    // 0x800AE55C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800AE560: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AE564: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE568: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AE56C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AE570: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800AE574: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x800AE578: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AE57C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AE580: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800AE584: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800AE588: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800AE58C: jal         0x80006A20
    // 0x800AE590: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x800AE590: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800AE594: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x800AE598: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AE59C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AE5A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800AE5A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AE5A8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800AE5AC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AE5B0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800AE5B4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800AE5B8: bc1f        L_800AE5C4
    if (!c1cs) {
        // 0x800AE5BC: addiu       $a0, $s0, 0x4C4
        ctx->r4 = ADD32(ctx->r16, 0X4C4);
            goto L_800AE5C4;
    }
    // 0x800AE5BC: addiu       $a0, $s0, 0x4C4
    ctx->r4 = ADD32(ctx->r16, 0X4C4);
    // 0x800AE5C0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_800AE5C4:
    // 0x800AE5C4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800AE5C8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800AE5CC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE5D0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE5D4: bc1f        L_800AE5E0
    if (!c1cs) {
        // 0x800AE5D8: lui         $a3, 0x42C8
        ctx->r7 = S32(0X42C8 << 16);
            goto L_800AE5E0;
    }
    // 0x800AE5D8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AE5DC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_800AE5E0:
    // 0x800AE5E0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AE5E4: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x800AE5E8: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x800AE5EC: jal         0x8009BC2C
    // 0x800AE5F0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800AE5F0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x800AE5F4: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800AE5F8: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800AE5FC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE600: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x800AE604: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE608: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AE60C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800AE610: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x800AE614: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AE618: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800AE61C: jal         0x8009BC2C
    // 0x800AE620: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800AE620: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x800AE624: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800AE628: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AE62C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE630: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE634: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800AE638: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x800AE63C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AE640: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AE644: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AE648: jal         0x8009BC2C
    // 0x800AE64C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800AE64C: nop

    after_5:
    // 0x800AE650: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AE654: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800AE658: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE65C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE660: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AE664: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x800AE668: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AE66C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AE670: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800AE674: jal         0x8009BC2C
    // 0x800AE678: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800AE678: nop

    after_6:
    // 0x800AE67C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AE680: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800AE684: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE688: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE68C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AE690: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x800AE694: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AE698: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AE69C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AE6A0: jal         0x8009BC2C
    // 0x800AE6A4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800AE6A4: nop

    after_7:
    // 0x800AE6A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE6AC: lwc1        $f12, -0x7948($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7948);
    // 0x800AE6B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800AE6B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AE6B8: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE6BC: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800AE6C0: nop

    // 0x800AE6C4: bc1fl       L_800AE708
    if (!c1cs) {
        // 0x800AE6C8: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_800AE708;
    }
    goto skip_0;
    // 0x800AE6C8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_0:
    // 0x800AE6CC: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE6D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE6D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AE6D8: addiu       $v0, $v0, 0x7968
    ctx->r2 = ADD32(ctx->r2, 0X7968);
    // 0x800AE6DC: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x800AE6E0: nop

    // 0x800AE6E4: bc1fl       L_800AE708
    if (!c1cs) {
        // 0x800AE6E8: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_800AE708;
    }
    goto skip_1;
    // 0x800AE6E8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_1:
    // 0x800AE6EC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800AE6F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE6F4: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800AE6F8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x800AE6FC: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE700: lwc1        $f12, -0x7944($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7944);
    // 0x800AE704: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_800AE708:
    // 0x800AE708: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AE70C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AE710: addiu       $v0, $v0, 0x7968
    ctx->r2 = ADD32(ctx->r2, 0X7968);
    // 0x800AE714: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800AE718: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE71C: bc1f        L_800AE750
    if (!c1cs) {
        // 0x800AE720: nop
    
            goto L_800AE750;
    }
    // 0x800AE720: nop

    // 0x800AE724: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AE728: nop

    // 0x800AE72C: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800AE730: nop

    // 0x800AE734: bc1f        L_800AE750
    if (!c1cs) {
        // 0x800AE738: nop
    
            goto L_800AE750;
    }
    // 0x800AE738: nop

    // 0x800AE73C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800AE740: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE744: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800AE748: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800AE74C: lwc1        $f12, -0x7940($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7940);
L_800AE750:
    // 0x800AE750: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE754: lwc1        $f8, 0x7970($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7970);
    // 0x800AE758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE75C: lwc1        $f16, -0x793C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X793C);
    // 0x800AE760: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800AE764: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800AE768: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800AE76C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800AE770: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800AE774: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AE778: jal         0x8009BC2C
    // 0x800AE77C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800AE77C: nop

    after_8:
    // 0x800AE780: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE784: lwc1        $f12, -0x7938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7938);
    // 0x800AE788: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800AE78C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AE790: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE794: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800AE798: nop

    // 0x800AE79C: bc1f        L_800AE7C4
    if (!c1cs) {
        // 0x800AE7A0: nop
    
            goto L_800AE7C4;
    }
    // 0x800AE7A0: nop

    // 0x800AE7A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AE7A8: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE7AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7B0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AE7B4: nop

    // 0x800AE7B8: bc1f        L_800AE7C4
    if (!c1cs) {
        // 0x800AE7BC: nop
    
            goto L_800AE7C4;
    }
    // 0x800AE7BC: nop

    // 0x800AE7C0: lwc1        $f12, -0x7934($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7934);
L_800AE7C4:
    // 0x800AE7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7C8: lwc1        $f0, -0x7930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7930);
    // 0x800AE7CC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800AE7D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AE7D4: nop

    // 0x800AE7D8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800AE7DC: nop

    // 0x800AE7E0: bc1fl       L_800AE80C
    if (!c1cs) {
        // 0x800AE7E4: lwc1        $f18, 0xE8($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_800AE80C;
    }
    goto skip_2;
    // 0x800AE7E4: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    skip_2:
    // 0x800AE7E8: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE7EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AE7F0: nop

    // 0x800AE7F4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800AE7F8: nop

    // 0x800AE7FC: bc1fl       L_800AE80C
    if (!c1cs) {
        // 0x800AE800: lwc1        $f18, 0xE8($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_800AE80C;
    }
    goto skip_3;
    // 0x800AE800: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    skip_3:
    // 0x800AE804: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800AE808: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
L_800AE80C:
    // 0x800AE80C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE810: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x800AE814: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800AE818: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800AE81C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE820: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AE824: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x800AE828: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800AE82C: jal         0x8009BC2C
    // 0x800AE830: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800AE830: nop

    after_9:
    // 0x800AE834: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AE838: lwc1        $f8, 0x11C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x800AE83C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800AE840: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AE844: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AE848: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AE84C: addiu       $v0, $v0, 0x7968
    ctx->r2 = ADD32(ctx->r2, 0X7968);
    // 0x800AE850: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE854: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x800AE858: lwc1        $f0, 0x114($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AE85C: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x800AE860: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AE864: nop

    // 0x800AE868: bc1fl       L_800AE880
    if (!c1cs) {
        // 0x800AE86C: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_800AE880;
    }
    goto skip_4;
    // 0x800AE86C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_4:
    // 0x800AE870: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AE874: swc1        $f16, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f16.u32l;
    // 0x800AE878: lwc1        $f0, 0x114($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AE87C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_800AE880:
    // 0x800AE880: nop

    // 0x800AE884: bc1f        L_800AE894
    if (!c1cs) {
        // 0x800AE888: nop
    
            goto L_800AE894;
    }
    // 0x800AE888: nop

    // 0x800AE88C: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800AE890: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
L_800AE894:
    // 0x800AE894: lwc1        $f4, -0x792C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X792C);
    // 0x800AE898: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE89C: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AE8A0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800AE8A4: lwc1        $f12, -0x7928($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7928);
    // 0x800AE8A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE8AC: lwc1        $f10, 0x7970($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7970);
    // 0x800AE8B0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AE8B4: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AE8B8: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x800AE8BC: nop

    // 0x800AE8C0: bc1f        L_800AE904
    if (!c1cs) {
        // 0x800AE8C4: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800AE904;
    }
    // 0x800AE8C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE8C8: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800AE8CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800AE8D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AE8D4: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AE8D8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AE8DC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800AE8E0: nop

    // 0x800AE8E4: bc1f        L_800AE904
    if (!c1cs) {
        // 0x800AE8E8: nop
    
            goto L_800AE904;
    }
    // 0x800AE8E8: nop

    // 0x800AE8EC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800AE8F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE8F4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800AE8F8: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800AE8FC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800AE900: lwc1        $f12, -0x7924($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7924);
L_800AE904:
    // 0x800AE904: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE908: lwc1        $f10, -0x7920($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7920);
    // 0x800AE90C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800AE910: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800AE914: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800AE918: jal         0x8009BC2C
    // 0x800AE91C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800AE91C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x800AE920: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800AE924: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AE928: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AE92C: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800AE930: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800AE934: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AE938: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AE93C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE940: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AE944: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800AE948: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE94C: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE950: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800AE954: nop

    // 0x800AE958: bc1f        L_800AE964
    if (!c1cs) {
        // 0x800AE95C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE964;
    }
    // 0x800AE95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE960: lwc1        $f2, -0x791C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X791C);
L_800AE964:
    // 0x800AE964: lw          $t9, 0x7974($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7974);
    // 0x800AE968: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x800AE96C: andi        $v1, $v0, 0x10
    ctx->r3 = ctx->r2 & 0X10;
    // 0x800AE970: beq         $v1, $zero, L_800AE980
    if (ctx->r3 == 0) {
        // 0x800AE974: andi        $t0, $v0, 0x2000
        ctx->r8 = ctx->r2 & 0X2000;
            goto L_800AE980;
    }
    // 0x800AE974: andi        $t0, $v0, 0x2000
    ctx->r8 = ctx->r2 & 0X2000;
    // 0x800AE978: bnel        $t0, $zero, L_800AE998
    if (ctx->r8 != 0) {
        // 0x800AE97C: c.eq.s      $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
            goto L_800AE998;
    }
    goto skip_5;
    // 0x800AE97C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    skip_5:
L_800AE980:
    // 0x800AE980: bne         $v1, $zero, L_800AE98C
    if (ctx->r3 != 0) {
        // 0x800AE984: andi        $t1, $v0, 0x2000
        ctx->r9 = ctx->r2 & 0X2000;
            goto L_800AE98C;
    }
    // 0x800AE984: andi        $t1, $v0, 0x2000
    ctx->r9 = ctx->r2 & 0X2000;
    // 0x800AE988: beq         $t1, $zero, L_800AE994
    if (ctx->r9 == 0) {
        // 0x800AE98C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE994;
    }
L_800AE98C:
    // 0x800AE98C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE990: lwc1        $f2, -0x7918($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7918);
L_800AE994:
    // 0x800AE994: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
L_800AE998:
    // 0x800AE998: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AE99C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AE9A0: bc1f        L_800AE9B0
    if (!c1cs) {
        // 0x800AE9A4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800AE9B0;
    }
    // 0x800AE9A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AE9A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AE9AC: nop

L_800AE9B0:
    // 0x800AE9B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE9B4: lwc1        $f16, -0x7914($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7914);
    // 0x800AE9B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE9BC: lwc1        $f8, -0x7910($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7910);
    // 0x800AE9C0: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AE9C4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AE9C8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800AE9CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AE9D0: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x800AE9D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800AE9D8: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800AE9DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AE9E0: jal         0x8009BC2C
    // 0x800AE9E4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800AE9E4: nop

    after_11:
    // 0x800AE9E8: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800AE9EC: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE9F0: lwc1        $f18, 0x130($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800AE9F4: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AE9F8: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AE9FC: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800AEA00: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AEA04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AEA08: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AEA0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AEA10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA14: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AEA18: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x800AEA1C: lwc1        $f6, -0x790C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X790C);
    // 0x800AEA20: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AEA24: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AEA28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AEA2C: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AEA30: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AEA34: jal         0x80005E90
    // 0x800AEA38: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x800AEA38: nop

    after_12:
    // 0x800AEA3C: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800AEA40: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800AEA44: lwc1        $f18, 0x4D8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800AEA48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA4C: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AEA50: lwc1        $f8, -0x7908($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7908);
    // 0x800AEA54: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AEA58: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AEA5C: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AEA60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEA64: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AEA68: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800AEA6C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800AEA70: jal         0x80005D44
    // 0x800AEA74: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x800AEA74: nop

    after_13:
    // 0x800AEA78: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x800AEA7C: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x800AEA80: lbu         $t2, 0x49C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X49C);
    // 0x800AEA84: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800AEA88: beq         $at, $zero, L_800AEAA8
    if (ctx->r1 == 0) {
        // 0x800AEA8C: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_800AEAA8;
    }
    // 0x800AEA8C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800AEA90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AEA94: nop

    // 0x800AEA98: sub.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800AEA9C: sub.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800AEAA0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x800AEAA4: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_800AEAA8:
    // 0x800AEAA8: lbu         $t3, 0x49D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X49D);
    // 0x800AEAAC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800AEAB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AEAB4: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800AEAB8: beq         $at, $zero, L_800AEAD4
    if (ctx->r1 == 0) {
        // 0x800AEABC: lwc1        $f6, 0x4C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_800AEAD4;
    }
    // 0x800AEABC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800AEAC0: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800AEAC4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800AEAC8: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800AEACC: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800AEAD0: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
L_800AEAD4:
    // 0x800AEAD4: lwc1        $f16, 0xD0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800AEAD8: lwc1        $f18, 0x110($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800AEADC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AEAE0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AEAE4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AEAE8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800AEAEC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800AEAF0: jal         0x80006A20
    // 0x800AEAF4: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_14;
    // 0x800AEAF4: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x800AEAF8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AEAFC: lwc1        $f2, 0xA0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800AEB00: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800AEB04: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
    // 0x800AEB08: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800AEB0C: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AEB10: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800AEB14: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x800AEB18: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AEB1C: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AEB20: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x800AEB24: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800AEB28: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    // 0x800AEB2C: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800AEB30: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x800AEB34: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AEB38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AEB3C: nop

    // 0x800AEB40: bc1fl       L_800AEB98
    if (!c1cs) {
        // 0x800AEB44: lwc1        $f2, 0xA4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0XA4);
            goto L_800AEB98;
    }
    goto skip_6;
    // 0x800AEB44: lwc1        $f2, 0xA4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA4);
    skip_6:
    // 0x800AEB48: c.le.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl <= ctx->f12.fl;
    // 0x800AEB4C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800AEB50: bc1fl       L_800AEB98
    if (!c1cs) {
        // 0x800AEB54: lwc1        $f2, 0xA4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0XA4);
            goto L_800AEB98;
    }
    goto skip_7;
    // 0x800AEB54: lwc1        $f2, 0xA4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA4);
    skip_7:
    // 0x800AEB58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AEB5C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800AEB60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AEB64: mul.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800AEB68: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800AEB6C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AEB70: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AEB74: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x800AEB78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AEB7C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AEB80: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800AEB84: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AEB88: jal         0x8009BC2C
    // 0x800AEB8C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x800AEB8C: nop

    after_15:
    // 0x800AEB90: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AEB94: lwc1        $f2, 0xA4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA4);
L_800AEB98:
    // 0x800AEB98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AEB9C: nop

    // 0x800AEBA0: bc1fl       L_800AEC18
    if (!c1cs) {
        // 0x800AEBA4: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800AEC18;
    }
    goto skip_8;
    // 0x800AEBA4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_8:
    // 0x800AEBA8: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800AEBAC: c.le.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl <= ctx->f20.fl;
    // 0x800AEBB0: nop

    // 0x800AEBB4: bc1fl       L_800AEC18
    if (!c1cs) {
        // 0x800AEBB8: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800AEC18;
    }
    goto skip_9;
    // 0x800AEBB8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_9:
    // 0x800AEBBC: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x800AEBC0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800AEBC4: bc1fl       L_800AEBDC
    if (!c1cs) {
        // 0x800AEBC8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800AEBDC;
    }
    goto skip_10;
    // 0x800AEBC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_10:
    // 0x800AEBCC: swc1        $f2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f2.u32l;
    // 0x800AEBD0: b           L_800AEC14
    // 0x800AEBD4: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
        goto L_800AEC14;
    // 0x800AEBD4: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AEBD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800AEBDC:
    // 0x800AEBDC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800AEBE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AEBE4: mul.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800AEBE8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800AEBEC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AEBF0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AEBF4: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x800AEBF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AEBFC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AEC00: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800AEC04: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800AEC08: jal         0x8009BC2C
    // 0x800AEC0C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x800AEC0C: nop

    after_16:
    // 0x800AEC10: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
L_800AEC14:
    // 0x800AEC14: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_800AEC18:
    // 0x800AEC18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AEC1C: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800AEC20: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800AEC24: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800AEC28: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AEC2C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800AEC30: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800AEC34: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AEC38: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800AEC3C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AEC40: swc1        $f18, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f18.u32l;
    // 0x800AEC44: bc1fl       L_800AEC64
    if (!c1cs) {
        // 0x800AEC48: neg.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
            goto L_800AEC64;
    }
    goto skip_11;
    // 0x800AEC48: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    skip_11:
    // 0x800AEC4C: lwc1        $f10, 0xA0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800AEC50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AEC54: sw          $t4, 0x228($s0)
    MEM_W(0X228, ctx->r16) = ctx->r12;
    // 0x800AEC58: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AEC5C: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800AEC60: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
L_800AEC64:
    // 0x800AEC64: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800AEC68: nop

    // 0x800AEC6C: bc1f        L_800AEC78
    if (!c1cs) {
        // 0x800AEC70: nop
    
            goto L_800AEC78;
    }
    // 0x800AEC70: nop

    // 0x800AEC74: sw          $t5, 0x228($s0)
    MEM_W(0X228, ctx->r16) = ctx->r13;
L_800AEC78:
    // 0x800AEC78: jal         0x800AE278
    // 0x800AEC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CheckBounds360(rdram, ctx);
        goto after_17;
    // 0x800AEC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800AEC80: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800AEC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEC88: jal         0x800A4460
    // 0x800AEC8C: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
    Player_WingEffects(rdram, ctx);
        goto after_18;
    // 0x800AEC8C: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
    after_18:
    // 0x800AEC90: jal         0x800A46A0
    // 0x800AEC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_DamageEffects(rdram, ctx);
        goto after_19;
    // 0x800AEC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800AEC98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AEC9C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AECA0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AECA4: jr          $ra
    // 0x800AECA8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800AECA8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Object_dummy_800598DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800598DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800598E0: jr          $ra
    // 0x800598E4: nop

    return;
    // 0x800598E4: nop

;}
RECOMP_FUNC void AudioLoad_AsyncLoadInner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FCC0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000FCC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000FCC8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8000FCCC: beq         $a0, $zero, L_8000FCF4
    if (ctx->r4 == 0) {
        // 0x8000FCD0: sw          $a3, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r7;
            goto L_8000FCF4;
    }
    // 0x8000FCD0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8000FCD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000FCD8: beq         $a0, $v0, L_8000FD1C
    if (ctx->r4 == ctx->r2) {
        // 0x8000FCDC: lui         $t7, 0x8015
        ctx->r15 = S32(0X8015 << 16);
            goto L_8000FD1C;
    }
    // 0x8000FCDC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000FCE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000FCE4: beq         $a0, $at, L_8000FD34
    if (ctx->r4 == ctx->r1) {
        // 0x8000FCE8: lui         $t8, 0x8015
        ctx->r24 = S32(0X8015 << 16);
            goto L_8000FD34;
    }
    // 0x8000FCE8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000FCEC: b           L_8000FD50
    // 0x8000FCF0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
        goto L_8000FD50;
    // 0x8000FCF0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
L_8000FCF4:
    // 0x8000FCF4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000FCF8: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8000FCFC: lbu         $t6, -0x2BD8($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2BD8);
    // 0x8000FD00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000FD04: bne         $t6, $at, L_8000FD14
    if (ctx->r14 != ctx->r1) {
        // 0x8000FD08: nop
    
            goto L_8000FD14;
    }
    // 0x8000FD08: nop

    // 0x8000FD0C: b           L_8000FF8C
    // 0x8000FD10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF8C;
    // 0x8000FD10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD14:
    // 0x8000FD14: b           L_8000FD50
    // 0x8000FD18: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
        goto L_8000FD50;
    // 0x8000FD18: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
L_8000FD1C:
    // 0x8000FD1C: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8000FD20: lbu         $t7, -0x2C18($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2C18);
    // 0x8000FD24: bnel        $v0, $t7, L_8000FD50
    if (ctx->r2 != ctx->r15) {
        // 0x8000FD28: sw          $a0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r4;
            goto L_8000FD50;
    }
    goto skip_0;
    // 0x8000FD28: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    skip_0:
    // 0x8000FD2C: b           L_8000FF8C
    // 0x8000FD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF8C;
    // 0x8000FD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD34:
    // 0x8000FD34: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x8000FD38: lbu         $t8, -0x2C58($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2C58);
    // 0x8000FD3C: bnel        $v0, $t8, L_8000FD50
    if (ctx->r2 != ctx->r24) {
        // 0x8000FD40: sw          $a0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r4;
            goto L_8000FD50;
    }
    goto skip_1;
    // 0x8000FD40: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    skip_1:
    // 0x8000FD44: b           L_8000FF8C
    // 0x8000FD48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF8C;
    // 0x8000FD48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000FD4C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
L_8000FD50:
    // 0x8000FD50: jal         0x8000F7CC
    // 0x8000FD54: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    AudioLoad_SearchCaches(rdram, ctx);
        goto after_0;
    // 0x8000FD54: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000FD58: beq         $v0, $zero, L_8000FD8C
    if (ctx->r2 == 0) {
        // 0x8000FD5C: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_8000FD8C;
    }
    // 0x8000FD5C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8000FD60: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8000FD64: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8000FD68: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8000FD6C: sll         $t9, $a1, 24
    ctx->r25 = S32(ctx->r5 << 24);
    // 0x8000FD70: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8000FD74: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8000FD78: jal         0x80020720
    // 0x8000FD7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8000FD7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000FD80: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FD84: b           L_8000FEF4
    // 0x8000FD88: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_8000FEF4;
    // 0x8000FD88: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8000FD8C:
    // 0x8000FD8C: jal         0x8000F820
    // 0x8000FD90: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    AudioLoad_GetLoadTable(rdram, ctx);
        goto after_2;
    // 0x8000FD90: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8000FD94: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FD98: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000FD9C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FDA0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8000FDA4: addu        $v1, $v0, $t2
    ctx->r3 = ADD32(ctx->r2, ctx->r10);
    // 0x8000FDA8: lw          $t3, 0x14($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X14);
    // 0x8000FDAC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8000FDB0: addiu       $t5, $t3, 0xF
    ctx->r13 = ADD32(ctx->r11, 0XF);
    // 0x8000FDB4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8000FDB8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8000FDBC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8000FDC0: lb          $t7, 0x18($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X18);
    // 0x8000FDC4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8000FDC8: lb          $a0, 0x19($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X19);
    // 0x8000FDCC: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8000FDD0: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x8000FDD4: beq         $at, $zero, L_8000FEA0
    if (ctx->r1 == 0) {
        // 0x8000FDD8: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_8000FEA0;
    }
    // 0x8000FDD8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8000FDDC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8000FDE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000FDE4: addu        $at, $at, $t9
    gpr jr_addend_8000FDEC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000FDE8: lw          $t9, -0x796C($at)
    ctx->r25 = ADD32(ctx->r1, -0X796C);
    // 0x8000FDEC: jr          $t9
    // 0x8000FDF0: nop

    switch (jr_addend_8000FDEC >> 2) {
        case 0: goto L_8000FDF4; break;
        case 1: goto L_8000FE1C; break;
        case 2: goto L_8000FE48; break;
        case 3: goto L_8000FE74; break;
        case 4: goto L_8000FE74; break;
        default: switch_error(__func__, 0x8000FDEC, 0x800C8694);
    }
    // 0x8000FDF0: nop

L_8000FDF4:
    // 0x8000FDF4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000FDF8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FDFC: jal         0x8000DB64
    // 0x8000FE00: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    AudioHeap_AllocPermanent(rdram, ctx);
        goto after_3;
    // 0x8000FE00: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x8000FE04: bne         $v0, $zero, L_8000FE14
    if (ctx->r2 != 0) {
        // 0x8000FE08: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000FE14;
    }
    // 0x8000FE08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000FE0C: b           L_8000FF90
    // 0x8000FE10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000FF90;
    // 0x8000FE10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000FE14:
    // 0x8000FE14: b           L_8000FEA0
    // 0x8000FE18: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
        goto L_8000FEA0;
    // 0x8000FE18: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_8000FE1C:
    // 0x8000FE1C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000FE20: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8000FE24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000FE28: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FE2C: jal         0x8000C2B4
    // 0x8000FE30: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    AudioHeap_AllocCached(rdram, ctx);
        goto after_4;
    // 0x8000FE30: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_4:
    // 0x8000FE34: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FE38: bne         $v0, $zero, L_8000FEA0
    if (ctx->r2 != 0) {
        // 0x8000FE3C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000FEA0;
    }
    // 0x8000FE3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000FE40: b           L_8000FF90
    // 0x8000FE44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000FF90;
    // 0x8000FE44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000FE48:
    // 0x8000FE48: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000FE4C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8000FE50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000FE54: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FE58: jal         0x8000C2B4
    // 0x8000FE5C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    AudioHeap_AllocCached(rdram, ctx);
        goto after_5;
    // 0x8000FE5C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_5:
    // 0x8000FE60: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FE64: bne         $v0, $zero, L_8000FEA0
    if (ctx->r2 != 0) {
        // 0x8000FE68: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000FEA0;
    }
    // 0x8000FE68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000FE6C: b           L_8000FF90
    // 0x8000FE70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000FF90;
    // 0x8000FE70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000FE74:
    // 0x8000FE74: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000FE78: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8000FE7C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000FE80: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FE84: jal         0x8000C2B4
    // 0x8000FE88: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    AudioHeap_AllocCached(rdram, ctx);
        goto after_6;
    // 0x8000FE88: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_6:
    // 0x8000FE8C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FE90: bne         $v0, $zero, L_8000FEA0
    if (ctx->r2 != 0) {
        // 0x8000FE94: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000FEA0;
    }
    // 0x8000FE94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000FE98: b           L_8000FF90
    // 0x8000FE9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000FF90;
    // 0x8000FE9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000FEA0:
    // 0x8000FEA0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8000FEA4: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000FEA8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8000FEAC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FEB0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8000FEB4: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8000FEB8: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8000FEBC: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8000FEC0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8000FEC4: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8000FEC8: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x8000FECC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8000FED0: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x8000FED4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8000FED8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8000FEDC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8000FEE0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8000FEE4: jal         0x80010AD8
    // 0x8000FEE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    AudioLoad_StartAsyncLoad(rdram, ctx);
        goto after_7;
    // 0x8000FEE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_7:
    // 0x8000FEEC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FEF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000FEF4:
    // 0x8000FEF4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8000FEF8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000FEFC: addiu       $t5, $t5, -0x2BD8
    ctx->r13 = ADD32(ctx->r13, -0X2BD8);
    // 0x8000FF00: beq         $v0, $zero, L_8000FF28
    if (ctx->r2 == 0) {
        // 0x8000FF04: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_8000FF28;
    }
    // 0x8000FF04: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FF08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000FF0C: beq         $v0, $at, L_8000FF44
    if (ctx->r2 == ctx->r1) {
        // 0x8000FF10: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_8000FF44;
    }
    // 0x8000FF10: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FF14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000FF18: beq         $v0, $at, L_8000FF68
    if (ctx->r2 == ctx->r1) {
        // 0x8000FF1C: lw          $t9, 0x4C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X4C);
            goto L_8000FF68;
    }
    // 0x8000FF1C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FF20: b           L_8000FF8C
    // 0x8000FF24: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8000FF8C;
    // 0x8000FF24: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000FF28:
    // 0x8000FF28: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8000FF2C: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8000FF30: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000FF34: beql        $t4, $at, L_8000FF8C
    if (ctx->r12 == ctx->r1) {
        // 0x8000FF38: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000FF8C;
    }
    goto skip_2;
    // 0x8000FF38: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_2:
    // 0x8000FF3C: b           L_8000FF88
    // 0x8000FF40: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
        goto L_8000FF88;
    // 0x8000FF40: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_8000FF44:
    // 0x8000FF44: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000FF48: addiu       $t8, $t8, -0x2C18
    ctx->r24 = ADD32(ctx->r24, -0X2C18);
    // 0x8000FF4C: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x8000FF50: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8000FF54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000FF58: beql        $t7, $at, L_8000FF8C
    if (ctx->r15 == ctx->r1) {
        // 0x8000FF5C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000FF8C;
    }
    goto skip_3;
    // 0x8000FF5C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_3:
    // 0x8000FF60: b           L_8000FF88
    // 0x8000FF64: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
        goto L_8000FF88;
    // 0x8000FF64: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_8000FF68:
    // 0x8000FF68: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000FF6C: addiu       $t1, $t1, -0x2C58
    ctx->r9 = ADD32(ctx->r9, -0X2C58);
    // 0x8000FF70: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8000FF74: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8000FF78: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000FF7C: beql        $t2, $at, L_8000FF8C
    if (ctx->r10 == ctx->r1) {
        // 0x8000FF80: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000FF8C;
    }
    goto skip_4;
    // 0x8000FF80: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_4:
    // 0x8000FF84: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_8000FF88:
    // 0x8000FF88: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000FF8C:
    // 0x8000FF8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000FF90:
    // 0x8000FF90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000FF94: jr          $ra
    // 0x8000FF98: nop

    return;
    // 0x8000FF98: nop

;}
RECOMP_FUNC void Play_CheckPolyCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8054: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A8058: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A805C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A8060: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A8064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A8068: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800A806C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8070: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A8074: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800A8078: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A807C: slti        $at, $a0, 0x97
    ctx->r1 = SIGNED(ctx->r4) < 0X97 ? 1 : 0;
    // 0x800A8080: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800A8084: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x800A8088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A808C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800A8090: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800A8094: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800A8098: bne         $at, $zero, L_800A80DC
    if (ctx->r1 != 0) {
        // 0x800A809C: swc1        $f10, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
            goto L_800A80DC;
    }
    // 0x800A809C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800A80A0: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x800A80A4: beq         $a0, $at, L_800A8178
    if (ctx->r4 == ctx->r1) {
        // 0x800A80A8: addiu       $at, $zero, 0x134
        ctx->r1 = ADD32(0, 0X134);
            goto L_800A8178;
    }
    // 0x800A80A8: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x800A80AC: beq         $a0, $at, L_800A819C
    if (ctx->r4 == ctx->r1) {
        // 0x800A80B0: addiu       $at, $zero, 0x135
        ctx->r1 = ADD32(0, 0X135);
            goto L_800A819C;
    }
    // 0x800A80B0: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x800A80B4: beq         $a0, $at, L_800A81AC
    if (ctx->r4 == ctx->r1) {
        // 0x800A80B8: addiu       $at, $zero, 0x138
        ctx->r1 = ADD32(0, 0X138);
            goto L_800A81AC;
    }
    // 0x800A80B8: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x800A80BC: beq         $a0, $at, L_800A81A4
    if (ctx->r4 == ctx->r1) {
        // 0x800A80C0: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_800A81A4;
    }
    // 0x800A80C0: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    // 0x800A80C4: beq         $a0, $at, L_800A81BC
    if (ctx->r4 == ctx->r1) {
        // 0x800A80C8: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_800A81BC;
    }
    // 0x800A80C8: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800A80CC: beq         $a0, $at, L_800A81B4
    if (ctx->r4 == ctx->r1) {
        // 0x800A80D0: nop
    
            goto L_800A81B4;
    }
    // 0x800A80D0: nop

    // 0x800A80D4: b           L_800A828C
    // 0x800A80D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800A828C;
    // 0x800A80D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800A80DC:
    // 0x800A80DC: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x800A80E0: bne         $at, $zero, L_800A8150
    if (ctx->r1 != 0) {
        // 0x800A80E4: slti        $at, $a0, 0x4B
        ctx->r1 = SIGNED(ctx->r4) < 0X4B ? 1 : 0;
            goto L_800A8150;
    }
    // 0x800A80E4: slti        $at, $a0, 0x4B
    ctx->r1 = SIGNED(ctx->r4) < 0X4B ? 1 : 0;
    // 0x800A80E8: bne         $at, $zero, L_800A8110
    if (ctx->r1 != 0) {
        // 0x800A80EC: addiu       $t6, $a0, -0x75
        ctx->r14 = ADD32(ctx->r4, -0X75);
            goto L_800A8110;
    }
    // 0x800A80EC: addiu       $t6, $a0, -0x75
    ctx->r14 = ADD32(ctx->r4, -0X75);
    // 0x800A80F0: sltiu       $at, $t6, 0x22
    ctx->r1 = ctx->r14 < 0X22 ? 1 : 0;
    // 0x800A80F4: beq         $at, $zero, L_800A8288
    if (ctx->r1 == 0) {
        // 0x800A80F8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A8288;
    }
    // 0x800A80F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A80FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8100: addu        $at, $at, $t6
    gpr jr_addend_800A8108 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A8104: lw          $t6, -0x7C14($at)
    ctx->r14 = ADD32(ctx->r1, -0X7C14);
    // 0x800A8108: jr          $t6
    // 0x800A810C: nop

    switch (jr_addend_800A8108 >> 2) {
        case 0: goto L_800A8234; break;
        case 1: goto L_800A8288; break;
        case 2: goto L_800A8288; break;
        case 3: goto L_800A81CC; break;
        case 4: goto L_800A8288; break;
        case 5: goto L_800A8288; break;
        case 6: goto L_800A8288; break;
        case 7: goto L_800A81D8; break;
        case 8: goto L_800A8288; break;
        case 9: goto L_800A81E4; break;
        case 10: goto L_800A8288; break;
        case 11: goto L_800A8288; break;
        case 12: goto L_800A8288; break;
        case 13: goto L_800A8288; break;
        case 14: goto L_800A8288; break;
        case 15: goto L_800A8288; break;
        case 16: goto L_800A8288; break;
        case 17: goto L_800A8288; break;
        case 18: goto L_800A8288; break;
        case 19: goto L_800A8288; break;
        case 20: goto L_800A8288; break;
        case 21: goto L_800A8288; break;
        case 22: goto L_800A8288; break;
        case 23: goto L_800A821C; break;
        case 24: goto L_800A8228; break;
        case 25: goto L_800A8288; break;
        case 26: goto L_800A8210; break;
        case 27: goto L_800A8288; break;
        case 28: goto L_800A8288; break;
        case 29: goto L_800A8288; break;
        case 30: goto L_800A8288; break;
        case 31: goto L_800A8288; break;
        case 32: goto L_800A818C; break;
        case 33: goto L_800A8194; break;
        default: switch_error(__func__, 0x800A8108, 0x800D83EC);
    }
    // 0x800A810C: nop

L_800A8110:
    // 0x800A8110: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x800A8114: bne         $at, $zero, L_800A813C
    if (ctx->r1 != 0) {
        // 0x800A8118: addiu       $t7, $a0, -0x27
        ctx->r15 = ADD32(ctx->r4, -0X27);
            goto L_800A813C;
    }
    // 0x800A8118: addiu       $t7, $a0, -0x27
    ctx->r15 = ADD32(ctx->r4, -0X27);
    // 0x800A811C: sltiu       $at, $t7, 0x24
    ctx->r1 = ctx->r15 < 0X24 ? 1 : 0;
    // 0x800A8120: beq         $at, $zero, L_800A8288
    if (ctx->r1 == 0) {
        // 0x800A8124: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800A8288;
    }
    // 0x800A8124: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A8128: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A812C: addu        $at, $at, $t7
    gpr jr_addend_800A8134 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A8130: lw          $t7, -0x7B8C($at)
    ctx->r15 = ADD32(ctx->r1, -0X7B8C);
    // 0x800A8134: jr          $t7
    // 0x800A8138: nop

    switch (jr_addend_800A8134 >> 2) {
        case 0: goto L_800A81C4; break;
        case 1: goto L_800A8288; break;
        case 2: goto L_800A8288; break;
        case 3: goto L_800A8288; break;
        case 4: goto L_800A8288; break;
        case 5: goto L_800A8288; break;
        case 6: goto L_800A8288; break;
        case 7: goto L_800A8288; break;
        case 8: goto L_800A81F0; break;
        case 9: goto L_800A8288; break;
        case 10: goto L_800A8288; break;
        case 11: goto L_800A8288; break;
        case 12: goto L_800A8288; break;
        case 13: goto L_800A8288; break;
        case 14: goto L_800A8288; break;
        case 15: goto L_800A8288; break;
        case 16: goto L_800A8288; break;
        case 17: goto L_800A8288; break;
        case 18: goto L_800A8288; break;
        case 19: goto L_800A8288; break;
        case 20: goto L_800A8288; break;
        case 21: goto L_800A8288; break;
        case 22: goto L_800A8288; break;
        case 23: goto L_800A8288; break;
        case 24: goto L_800A8288; break;
        case 25: goto L_800A8288; break;
        case 26: goto L_800A8288; break;
        case 27: goto L_800A8288; break;
        case 28: goto L_800A8270; break;
        case 29: goto L_800A8288; break;
        case 30: goto L_800A8204; break;
        case 31: goto L_800A8240; break;
        case 32: goto L_800A8258; break;
        case 33: goto L_800A824C; break;
        case 34: goto L_800A8264; break;
        case 35: goto L_800A827C; break;
        default: switch_error(__func__, 0x800A8134, 0x800D8474);
    }
    // 0x800A8138: nop

L_800A813C:
    // 0x800A813C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A8140: beql        $a0, $at, L_800A8184
    if (ctx->r4 == ctx->r1) {
        // 0x800A8144: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800A8184;
    }
    goto skip_0;
    // 0x800A8144: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_0:
    // 0x800A8148: b           L_800A828C
    // 0x800A814C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800A828C;
    // 0x800A814C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800A8150:
    // 0x800A8150: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8154: beq         $a0, $at, L_800A81FC
    if (ctx->r4 == ctx->r1) {
        // 0x800A8158: addiu       $s0, $zero, 0x2
        ctx->r16 = ADD32(0, 0X2);
            goto L_800A81FC;
    }
    // 0x800A8158: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800A815C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A8160: beq         $a0, $at, L_800A8204
    if (ctx->r4 == ctx->r1) {
        // 0x800A8164: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A8204;
    }
    // 0x800A8164: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A8168: beql        $a0, $at, L_800A8184
    if (ctx->r4 == ctx->r1) {
        // 0x800A816C: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800A8184;
    }
    goto skip_1;
    // 0x800A816C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_1:
    // 0x800A8170: b           L_800A828C
    // 0x800A8174: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800A828C;
    // 0x800A8174: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800A8178:
    // 0x800A8178: b           L_800A8290
    // 0x800A817C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800A8290;
    // 0x800A817C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A8180: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800A8184:
    // 0x800A8184: b           L_800A8290
    // 0x800A8188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A818C:
    // 0x800A818C: b           L_800A8290
    // 0x800A8190: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
        goto L_800A8290;
    // 0x800A8190: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_800A8194:
    // 0x800A8194: b           L_800A8290
    // 0x800A8198: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_800A8290;
    // 0x800A8198: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_800A819C:
    // 0x800A819C: b           L_800A8290
    // 0x800A81A0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_800A8290;
    // 0x800A81A0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_800A81A4:
    // 0x800A81A4: b           L_800A8290
    // 0x800A81A8: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_800A8290;
    // 0x800A81A8: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_800A81AC:
    // 0x800A81AC: b           L_800A8290
    // 0x800A81B0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_800A8290;
    // 0x800A81B0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_800A81B4:
    // 0x800A81B4: b           L_800A8290
    // 0x800A81B8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_800A8290;
    // 0x800A81B8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_800A81BC:
    // 0x800A81BC: b           L_800A8290
    // 0x800A81C0: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_800A8290;
    // 0x800A81C0: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_800A81C4:
    // 0x800A81C4: b           L_800A8290
    // 0x800A81C8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A81C8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800A81CC:
    // 0x800A81CC: addiu       $s0, $zero, 0x12
    ctx->r16 = ADD32(0, 0X12);
    // 0x800A81D0: b           L_800A8290
    // 0x800A81D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A81D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A81D8:
    // 0x800A81D8: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // 0x800A81DC: b           L_800A8290
    // 0x800A81E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A81E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A81E4:
    // 0x800A81E4: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x800A81E8: b           L_800A8290
    // 0x800A81EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A81EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A81F0:
    // 0x800A81F0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x800A81F4: b           L_800A8290
    // 0x800A81F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A81F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A81FC:
    // 0x800A81FC: b           L_800A8290
    // 0x800A8200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8204:
    // 0x800A8204: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x800A8208: b           L_800A8290
    // 0x800A820C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A820C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8210:
    // 0x800A8210: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
    // 0x800A8214: b           L_800A8290
    // 0x800A8218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A821C:
    // 0x800A821C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800A8220: b           L_800A8290
    // 0x800A8224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8228:
    // 0x800A8228: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x800A822C: b           L_800A8290
    // 0x800A8230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8234:
    // 0x800A8234: addiu       $s0, $zero, 0xE
    ctx->r16 = ADD32(0, 0XE);
    // 0x800A8238: b           L_800A8290
    // 0x800A823C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A823C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8240:
    // 0x800A8240: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x800A8244: b           L_800A8290
    // 0x800A8248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A824C:
    // 0x800A824C: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x800A8250: b           L_800A8290
    // 0x800A8254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8258:
    // 0x800A8258: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x800A825C: b           L_800A8290
    // 0x800A8260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8264:
    // 0x800A8264: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
    // 0x800A8268: b           L_800A8290
    // 0x800A826C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A826C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8270:
    // 0x800A8270: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x800A8274: b           L_800A8290
    // 0x800A8278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A827C:
    // 0x800A827C: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
    // 0x800A8280: b           L_800A8290
    // 0x800A8284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A8290;
    // 0x800A8284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8288:
    // 0x800A8288: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800A828C:
    // 0x800A828C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8290:
    // 0x800A8290: bne         $v0, $zero, L_800A82CC
    if (ctx->r2 != 0) {
        // 0x800A8294: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800A82CC;
    }
    // 0x800A8294: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800A8298: addiu       $t8, $sp, 0x3C
    ctx->r24 = ADD32(ctx->r29, 0X3C);
    // 0x800A829C: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800A82A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A82A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A82A8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800A82AC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800A82B0: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800A82B4: jal         0x800998FC
    // 0x800A82B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_col1_800998FC(rdram, ctx);
        goto after_0;
    // 0x800A82B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x800A82BC: blezl       $v0, L_800A82F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A82C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A82F0;
    }
    goto skip_2;
    // 0x800A82C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800A82C4: b           L_800A82F0
    // 0x800A82C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A82F0;
    // 0x800A82C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A82CC:
    // 0x800A82CC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800A82D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800A82D4: jal         0x800A3690
    // 0x800A82D8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_col2_800A3690(rdram, ctx);
        goto after_1;
    // 0x800A82D8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_1:
    // 0x800A82DC: beql        $v0, $zero, L_800A82F0
    if (ctx->r2 == 0) {
        // 0x800A82E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A82F0;
    }
    goto skip_3;
    // 0x800A82E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x800A82E4: b           L_800A82F0
    // 0x800A82E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A82F0;
    // 0x800A82E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A82EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A82F0:
    // 0x800A82F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A82F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A82F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800A82FC: jr          $ra
    // 0x800A8300: nop

    return;
    // 0x800A8300: nop

;}
RECOMP_FUNC void Graphics_GetLargeTextWidth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A06FC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800A0700: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800A0704: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800A0708: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800A070C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800A0710: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A0714: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800A0718: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A071C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A0720: beq         $a1, $zero, L_800A0FEC
    if (ctx->r5 == 0) {
        // 0x800A0724: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_800A0FEC;
    }
    // 0x800A0724: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A0728: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A072C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0730: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A0734: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A0738: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A073C: lbu         $t6, 0x268C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X268C);
    // 0x800A0740: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A0744: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800A0748: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A074C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A0750: addiu       $t2, $t2, 0x268C
    ctx->r10 = ADD32(ctx->r10, 0X268C);
    // 0x800A0754: addiu       $s4, $zero, 0x4A
    ctx->r20 = ADD32(0, 0X4A);
    // 0x800A0758: addiu       $s3, $zero, 0x54
    ctx->r19 = ADD32(0, 0X54);
    // 0x800A075C: addiu       $s2, $zero, 0x58
    ctx->r18 = ADD32(0, 0X58);
    // 0x800A0760: addiu       $s1, $zero, 0x49
    ctx->r17 = ADD32(0, 0X49);
    // 0x800A0764: addiu       $s0, $zero, 0x59
    ctx->r16 = ADD32(0, 0X59);
    // 0x800A0768: addiu       $t5, $zero, 0x57
    ctx->r13 = ADD32(0, 0X57);
    // 0x800A076C: addiu       $t4, $zero, 0x4B
    ctx->r12 = ADD32(0, 0X4B);
    // 0x800A0770: addiu       $t3, $zero, 0x4F
    ctx->r11 = ADD32(0, 0X4F);
    // 0x800A0774: addiu       $t1, $zero, 0x41
    ctx->r9 = ADD32(0, 0X41);
    // 0x800A0778: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A077C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A0780: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_800A0784:
    // 0x800A0784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A0788: xor         $v0, $a3, $t0
    ctx->r2 = ctx->r7 ^ ctx->r8;
    // 0x800A078C: beql        $t7, $a1, L_800A07B4
    if (ctx->r15 == ctx->r5) {
        // 0x800A0790: addu        $t6, $t2, $a0
        ctx->r14 = ADD32(ctx->r10, ctx->r4);
            goto L_800A07B4;
    }
    goto skip_0;
    // 0x800A0790: addu        $t6, $t2, $a0
    ctx->r14 = ADD32(ctx->r10, ctx->r4);
    skip_0:
    // 0x800A0794: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800A0798:
    // 0x800A0798: sltiu       $at, $a0, 0x2A
    ctx->r1 = ctx->r4 < 0X2A ? 1 : 0;
    // 0x800A079C: beq         $at, $zero, L_800A07B0
    if (ctx->r1 == 0) {
        // 0x800A07A0: addu        $t8, $t2, $a0
        ctx->r24 = ADD32(ctx->r10, ctx->r4);
            goto L_800A07B0;
    }
    // 0x800A07A0: addu        $t8, $t2, $a0
    ctx->r24 = ADD32(ctx->r10, ctx->r4);
    // 0x800A07A4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800A07A8: bnel        $t9, $a1, L_800A0798
    if (ctx->r25 != ctx->r5) {
        // 0x800A07AC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800A0798;
    }
    goto skip_1;
    // 0x800A07AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
L_800A07B0:
    // 0x800A07B0: addu        $t6, $t2, $a0
    ctx->r14 = ADD32(ctx->r10, ctx->r4);
L_800A07B4:
    // 0x800A07B4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800A07B8: bnel        $t7, $a1, L_800A0FE0
    if (ctx->r15 != ctx->r5) {
        // 0x800A07BC: lbu         $a1, 0x1($a2)
        ctx->r5 = MEM_BU(ctx->r6, 0X1);
            goto L_800A0FE0;
    }
    goto skip_2;
    // 0x800A07BC: lbu         $a1, 0x1($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X1);
    skip_2:
    // 0x800A07C0: bne         $a3, $t0, L_800A07F8
    if (ctx->r7 != ctx->r8) {
        // 0x800A07C4: nop
    
            goto L_800A07F8;
    }
    // 0x800A07C4: nop

    // 0x800A07C8: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A07CC: bne         $s0, $t8, L_800A07F8
    if (ctx->r16 != ctx->r24) {
        // 0x800A07D0: nop
    
            goto L_800A07F8;
    }
    // 0x800A07D0: nop

    // 0x800A07D4: bne         $t1, $a1, L_800A07F8
    if (ctx->r9 != ctx->r5) {
        // 0x800A07D8: nop
    
            goto L_800A07F8;
    }
    // 0x800A07D8: nop

    // 0x800A07DC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A07E0: nop

    // 0x800A07E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A07E8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A07EC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A07F0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A07F4: nop

L_800A07F8:
    // 0x800A07F8: bne         $a3, $t0, L_800A0830
    if (ctx->r7 != ctx->r8) {
        // 0x800A07FC: nop
    
            goto L_800A0830;
    }
    // 0x800A07FC: nop

    // 0x800A0800: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0804: bne         $t4, $t6, L_800A0830
    if (ctx->r12 != ctx->r14) {
        // 0x800A0808: nop
    
            goto L_800A0830;
    }
    // 0x800A0808: nop

    // 0x800A080C: bne         $t1, $a1, L_800A0830
    if (ctx->r9 != ctx->r5) {
        // 0x800A0810: nop
    
            goto L_800A0830;
    }
    // 0x800A0810: nop

    // 0x800A0814: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0818: nop

    // 0x800A081C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0820: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A0824: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0828: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A082C: nop

L_800A0830:
    // 0x800A0830: bne         $a3, $t0, L_800A0868
    if (ctx->r7 != ctx->r8) {
        // 0x800A0834: nop
    
            goto L_800A0868;
    }
    // 0x800A0834: nop

    // 0x800A0838: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A083C: bne         $t1, $t8, L_800A0868
    if (ctx->r9 != ctx->r24) {
        // 0x800A0840: nop
    
            goto L_800A0868;
    }
    // 0x800A0840: nop

    // 0x800A0844: bne         $t3, $a1, L_800A0868
    if (ctx->r11 != ctx->r5) {
        // 0x800A0848: nop
    
            goto L_800A0868;
    }
    // 0x800A0848: nop

    // 0x800A084C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0850: nop

    // 0x800A0854: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0858: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A085C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0860: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0864: nop

L_800A0868:
    // 0x800A0868: bne         $a3, $t0, L_800A08A0
    if (ctx->r7 != ctx->r8) {
        // 0x800A086C: nop
    
            goto L_800A08A0;
    }
    // 0x800A086C: nop

    // 0x800A0870: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0874: bne         $s3, $t6, L_800A08A0
    if (ctx->r19 != ctx->r14) {
        // 0x800A0878: nop
    
            goto L_800A08A0;
    }
    // 0x800A0878: nop

    // 0x800A087C: bne         $t1, $a1, L_800A08A0
    if (ctx->r9 != ctx->r5) {
        // 0x800A0880: nop
    
            goto L_800A08A0;
    }
    // 0x800A0880: nop

    // 0x800A0884: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0888: nop

    // 0x800A088C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0890: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A0894: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0898: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A089C: nop

L_800A08A0:
    // 0x800A08A0: bne         $a3, $t0, L_800A08D8
    if (ctx->r7 != ctx->r8) {
        // 0x800A08A4: nop
    
            goto L_800A08D8;
    }
    // 0x800A08A4: nop

    // 0x800A08A8: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A08AC: bne         $t1, $t8, L_800A08D8
    if (ctx->r9 != ctx->r24) {
        // 0x800A08B0: nop
    
            goto L_800A08D8;
    }
    // 0x800A08B0: nop

    // 0x800A08B4: bne         $s0, $a1, L_800A08D8
    if (ctx->r16 != ctx->r5) {
        // 0x800A08B8: nop
    
            goto L_800A08D8;
    }
    // 0x800A08B8: nop

    // 0x800A08BC: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A08C0: nop

    // 0x800A08C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A08C8: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800A08CC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A08D0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A08D4: nop

L_800A08D8:
    // 0x800A08D8: bne         $a3, $t0, L_800A0910
    if (ctx->r7 != ctx->r8) {
        // 0x800A08DC: nop
    
            goto L_800A0910;
    }
    // 0x800A08DC: nop

    // 0x800A08E0: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A08E4: bne         $t4, $t6, L_800A0910
    if (ctx->r12 != ctx->r14) {
        // 0x800A08E8: nop
    
            goto L_800A0910;
    }
    // 0x800A08E8: nop

    // 0x800A08EC: bne         $s1, $a1, L_800A0910
    if (ctx->r17 != ctx->r5) {
        // 0x800A08F0: nop
    
            goto L_800A0910;
    }
    // 0x800A08F0: nop

    // 0x800A08F4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A08F8: nop

    // 0x800A08FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0900: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A0904: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0908: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A090C: nop

L_800A0910:
    // 0x800A0910: bne         $a3, $t0, L_800A0948
    if (ctx->r7 != ctx->r8) {
        // 0x800A0914: nop
    
            goto L_800A0948;
    }
    // 0x800A0914: nop

    // 0x800A0918: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A091C: bne         $t4, $t8, L_800A0948
    if (ctx->r12 != ctx->r24) {
        // 0x800A0920: nop
    
            goto L_800A0948;
    }
    // 0x800A0920: nop

    // 0x800A0924: bne         $t3, $a1, L_800A0948
    if (ctx->r11 != ctx->r5) {
        // 0x800A0928: nop
    
            goto L_800A0948;
    }
    // 0x800A0928: nop

    // 0x800A092C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0930: nop

    // 0x800A0934: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0938: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A093C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0940: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0944: nop

L_800A0948:
    // 0x800A0948: bne         $a3, $t0, L_800A0980
    if (ctx->r7 != ctx->r8) {
        // 0x800A094C: nop
    
            goto L_800A0980;
    }
    // 0x800A094C: nop

    // 0x800A0950: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0954: bne         $t1, $t6, L_800A0980
    if (ctx->r9 != ctx->r14) {
        // 0x800A0958: nop
    
            goto L_800A0980;
    }
    // 0x800A0958: nop

    // 0x800A095C: bne         $s4, $a1, L_800A0980
    if (ctx->r20 != ctx->r5) {
        // 0x800A0960: nop
    
            goto L_800A0980;
    }
    // 0x800A0960: nop

    // 0x800A0964: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0968: nop

    // 0x800A096C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0970: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A0974: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0978: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A097C: nop

L_800A0980:
    // 0x800A0980: bne         $a3, $t0, L_800A09B8
    if (ctx->r7 != ctx->r8) {
        // 0x800A0984: nop
    
            goto L_800A09B8;
    }
    // 0x800A0984: nop

    // 0x800A0988: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A098C: bne         $t5, $t8, L_800A09B8
    if (ctx->r13 != ctx->r24) {
        // 0x800A0990: nop
    
            goto L_800A09B8;
    }
    // 0x800A0990: nop

    // 0x800A0994: bne         $t1, $a1, L_800A09B8
    if (ctx->r9 != ctx->r5) {
        // 0x800A0998: nop
    
            goto L_800A09B8;
    }
    // 0x800A0998: nop

    // 0x800A099C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A09A0: nop

    // 0x800A09A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A09A8: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A09AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A09B0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A09B4: nop

L_800A09B8:
    // 0x800A09B8: bne         $a3, $t0, L_800A09F0
    if (ctx->r7 != ctx->r8) {
        // 0x800A09BC: nop
    
            goto L_800A09F0;
    }
    // 0x800A09BC: nop

    // 0x800A09C0: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A09C4: bne         $s0, $t6, L_800A09F0
    if (ctx->r16 != ctx->r14) {
        // 0x800A09C8: nop
    
            goto L_800A09F0;
    }
    // 0x800A09C8: nop

    // 0x800A09CC: bne         $t3, $a1, L_800A09F0
    if (ctx->r11 != ctx->r5) {
        // 0x800A09D0: nop
    
            goto L_800A09F0;
    }
    // 0x800A09D0: nop

    // 0x800A09D4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A09D8: nop

    // 0x800A09DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A09E0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A09E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A09E8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A09EC: nop

L_800A09F0:
    // 0x800A09F0: bne         $a3, $t0, L_800A0A28
    if (ctx->r7 != ctx->r8) {
        // 0x800A09F4: nop
    
            goto L_800A0A28;
    }
    // 0x800A09F4: nop

    // 0x800A09F8: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A09FC: bne         $t1, $t8, L_800A0A28
    if (ctx->r9 != ctx->r24) {
        // 0x800A0A00: nop
    
            goto L_800A0A28;
    }
    // 0x800A0A00: nop

    // 0x800A0A04: bne         $s3, $a1, L_800A0A28
    if (ctx->r19 != ctx->r5) {
        // 0x800A0A08: nop
    
            goto L_800A0A28;
    }
    // 0x800A0A08: nop

    // 0x800A0A0C: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0A10: nop

    // 0x800A0A14: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0A18: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800A0A1C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0A20: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0A24: nop

L_800A0A28:
    // 0x800A0A28: bne         $a3, $t0, L_800A0A60
    if (ctx->r7 != ctx->r8) {
        // 0x800A0A2C: nop
    
            goto L_800A0A60;
    }
    // 0x800A0A2C: nop

    // 0x800A0A30: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0A34: bne         $t1, $t6, L_800A0A60
    if (ctx->r9 != ctx->r14) {
        // 0x800A0A38: nop
    
            goto L_800A0A60;
    }
    // 0x800A0A38: nop

    // 0x800A0A3C: bne         $t5, $a1, L_800A0A60
    if (ctx->r13 != ctx->r5) {
        // 0x800A0A40: nop
    
            goto L_800A0A60;
    }
    // 0x800A0A40: nop

    // 0x800A0A44: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0A48: nop

    // 0x800A0A4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0A50: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A0A54: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0A58: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0A5C: nop

L_800A0A60:
    // 0x800A0A60: bne         $a3, $t0, L_800A0A98
    if (ctx->r7 != ctx->r8) {
        // 0x800A0A64: nop
    
            goto L_800A0A98;
    }
    // 0x800A0A64: nop

    // 0x800A0A68: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0A6C: bne         $t3, $t8, L_800A0A98
    if (ctx->r11 != ctx->r24) {
        // 0x800A0A70: nop
    
            goto L_800A0A98;
    }
    // 0x800A0A70: nop

    // 0x800A0A74: bne         $s3, $a1, L_800A0A98
    if (ctx->r19 != ctx->r5) {
        // 0x800A0A78: nop
    
            goto L_800A0A98;
    }
    // 0x800A0A78: nop

    // 0x800A0A7C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0A80: nop

    // 0x800A0A84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0A88: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A0A8C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0A90: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0A94: nop

L_800A0A98:
    // 0x800A0A98: bne         $a3, $t0, L_800A0AD4
    if (ctx->r7 != ctx->r8) {
        // 0x800A0A9C: nop
    
            goto L_800A0AD4;
    }
    // 0x800A0A9C: nop

    // 0x800A0AA0: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0AA4: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800A0AA8: bne         $t1, $t6, L_800A0AD4
    if (ctx->r9 != ctx->r14) {
        // 0x800A0AAC: nop
    
            goto L_800A0AD4;
    }
    // 0x800A0AAC: nop

    // 0x800A0AB0: bne         $a1, $at, L_800A0AD4
    if (ctx->r5 != ctx->r1) {
        // 0x800A0AB4: nop
    
            goto L_800A0AD4;
    }
    // 0x800A0AB4: nop

    // 0x800A0AB8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0ABC: nop

    // 0x800A0AC0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0AC4: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800A0AC8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0ACC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0AD0: nop

L_800A0AD4:
    // 0x800A0AD4: bne         $a3, $t0, L_800A0B0C
    if (ctx->r7 != ctx->r8) {
        // 0x800A0AD8: nop
    
            goto L_800A0B0C;
    }
    // 0x800A0AD8: nop

    // 0x800A0ADC: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0AE0: bne         $t3, $t8, L_800A0B0C
    if (ctx->r11 != ctx->r24) {
        // 0x800A0AE4: nop
    
            goto L_800A0B0C;
    }
    // 0x800A0AE4: nop

    // 0x800A0AE8: bne         $s0, $a1, L_800A0B0C
    if (ctx->r16 != ctx->r5) {
        // 0x800A0AEC: nop
    
            goto L_800A0B0C;
    }
    // 0x800A0AEC: nop

    // 0x800A0AF0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0AF4: nop

    // 0x800A0AF8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0AFC: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A0B00: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0B04: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0B08: nop

L_800A0B0C:
    // 0x800A0B0C: bne         $a3, $t0, L_800A0B44
    if (ctx->r7 != ctx->r8) {
        // 0x800A0B10: nop
    
            goto L_800A0B44;
    }
    // 0x800A0B10: nop

    // 0x800A0B14: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0B18: bne         $t1, $t6, L_800A0B44
    if (ctx->r9 != ctx->r14) {
        // 0x800A0B1C: nop
    
            goto L_800A0B44;
    }
    // 0x800A0B1C: nop

    // 0x800A0B20: bne         $s4, $a1, L_800A0B44
    if (ctx->r20 != ctx->r5) {
        // 0x800A0B24: nop
    
            goto L_800A0B44;
    }
    // 0x800A0B24: nop

    // 0x800A0B28: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0B2C: nop

    // 0x800A0B30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0B34: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A0B38: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0B3C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0B40: nop

L_800A0B44:
    // 0x800A0B44: bne         $a3, $t0, L_800A0B7C
    if (ctx->r7 != ctx->r8) {
        // 0x800A0B48: nop
    
            goto L_800A0B7C;
    }
    // 0x800A0B48: nop

    // 0x800A0B4C: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0B50: bne         $s3, $t8, L_800A0B7C
    if (ctx->r19 != ctx->r24) {
        // 0x800A0B54: nop
    
            goto L_800A0B7C;
    }
    // 0x800A0B54: nop

    // 0x800A0B58: bne         $t3, $a1, L_800A0B7C
    if (ctx->r11 != ctx->r5) {
        // 0x800A0B5C: nop
    
            goto L_800A0B7C;
    }
    // 0x800A0B5C: nop

    // 0x800A0B60: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0B64: nop

    // 0x800A0B68: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0B6C: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800A0B70: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0B74: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0B78: nop

L_800A0B7C:
    // 0x800A0B7C: bne         $a3, $t0, L_800A0BB8
    if (ctx->r7 != ctx->r8) {
        // 0x800A0B80: nop
    
            goto L_800A0BB8;
    }
    // 0x800A0B80: nop

    // 0x800A0B84: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0B88: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x800A0B8C: bne         $t4, $t6, L_800A0BB8
    if (ctx->r12 != ctx->r14) {
        // 0x800A0B90: nop
    
            goto L_800A0BB8;
    }
    // 0x800A0B90: nop

    // 0x800A0B94: bne         $a1, $at, L_800A0BB8
    if (ctx->r5 != ctx->r1) {
        // 0x800A0B98: nop
    
            goto L_800A0BB8;
    }
    // 0x800A0B98: nop

    // 0x800A0B9C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0BA0: nop

    // 0x800A0BA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0BA8: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A0BAC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0BB0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0BB4: nop

L_800A0BB8:
    // 0x800A0BB8: bne         $a3, $t0, L_800A0BF4
    if (ctx->r7 != ctx->r8) {
        // 0x800A0BBC: nop
    
            goto L_800A0BF4;
    }
    // 0x800A0BBC: nop

    // 0x800A0BC0: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0BC4: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800A0BC8: bne         $t1, $t8, L_800A0BF4
    if (ctx->r9 != ctx->r24) {
        // 0x800A0BCC: nop
    
            goto L_800A0BF4;
    }
    // 0x800A0BCC: nop

    // 0x800A0BD0: bne         $a1, $at, L_800A0BF4
    if (ctx->r5 != ctx->r1) {
        // 0x800A0BD4: nop
    
            goto L_800A0BF4;
    }
    // 0x800A0BD4: nop

    // 0x800A0BD8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0BDC: nop

    // 0x800A0BE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0BE4: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800A0BE8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0BEC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0BF0: nop

L_800A0BF4:
    // 0x800A0BF4: bne         $a3, $t0, L_800A0C30
    if (ctx->r7 != ctx->r8) {
        // 0x800A0BF8: nop
    
            goto L_800A0C30;
    }
    // 0x800A0BF8: nop

    // 0x800A0BFC: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0C00: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x800A0C04: bne         $t6, $at, L_800A0C30
    if (ctx->r14 != ctx->r1) {
        // 0x800A0C08: nop
    
            goto L_800A0C30;
    }
    // 0x800A0C08: nop

    // 0x800A0C0C: bne         $t3, $a1, L_800A0C30
    if (ctx->r11 != ctx->r5) {
        // 0x800A0C10: nop
    
            goto L_800A0C30;
    }
    // 0x800A0C10: nop

    // 0x800A0C14: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0C18: nop

    // 0x800A0C1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0C20: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A0C24: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0C28: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0C2C: nop

L_800A0C30:
    // 0x800A0C30: bne         $a3, $t0, L_800A0C68
    if (ctx->r7 != ctx->r8) {
        // 0x800A0C34: nop
    
            goto L_800A0C68;
    }
    // 0x800A0C34: nop

    // 0x800A0C38: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0C3C: bne         $t4, $t8, L_800A0C68
    if (ctx->r12 != ctx->r24) {
        // 0x800A0C40: nop
    
            goto L_800A0C68;
    }
    // 0x800A0C40: nop

    // 0x800A0C44: bne         $s0, $a1, L_800A0C68
    if (ctx->r16 != ctx->r5) {
        // 0x800A0C48: nop
    
            goto L_800A0C68;
    }
    // 0x800A0C48: nop

    // 0x800A0C4C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0C50: nop

    // 0x800A0C54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0C58: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A0C5C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0C60: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0C64: nop

L_800A0C68:
    // 0x800A0C68: bne         $a3, $t0, L_800A0CA4
    if (ctx->r7 != ctx->r8) {
        // 0x800A0C6C: nop
    
            goto L_800A0CA4;
    }
    // 0x800A0C6C: nop

    // 0x800A0C70: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0C74: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800A0C78: bne         $t6, $at, L_800A0CA4
    if (ctx->r14 != ctx->r1) {
        // 0x800A0C7C: nop
    
            goto L_800A0CA4;
    }
    // 0x800A0C7C: nop

    // 0x800A0C80: bne         $s4, $a1, L_800A0CA4
    if (ctx->r20 != ctx->r5) {
        // 0x800A0C84: nop
    
            goto L_800A0CA4;
    }
    // 0x800A0C84: nop

    // 0x800A0C88: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0C8C: nop

    // 0x800A0C90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0C94: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A0C98: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0C9C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0CA0: nop

L_800A0CA4:
    // 0x800A0CA4: bne         $a3, $t0, L_800A0CE0
    if (ctx->r7 != ctx->r8) {
        // 0x800A0CA8: nop
    
            goto L_800A0CE0;
    }
    // 0x800A0CA8: nop

    // 0x800A0CAC: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0CB0: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800A0CB4: bne         $t4, $t8, L_800A0CE0
    if (ctx->r12 != ctx->r24) {
        // 0x800A0CB8: nop
    
            goto L_800A0CE0;
    }
    // 0x800A0CB8: nop

    // 0x800A0CBC: bne         $a1, $at, L_800A0CE0
    if (ctx->r5 != ctx->r1) {
        // 0x800A0CC0: nop
    
            goto L_800A0CE0;
    }
    // 0x800A0CC0: nop

    // 0x800A0CC4: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0CC8: nop

    // 0x800A0CCC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0CD0: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A0CD4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0CD8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0CDC: nop

L_800A0CE0:
    // 0x800A0CE0: bne         $a3, $t0, L_800A0D1C
    if (ctx->r7 != ctx->r8) {
        // 0x800A0CE4: nop
    
            goto L_800A0D1C;
    }
    // 0x800A0CE4: nop

    // 0x800A0CE8: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0CEC: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800A0CF0: bne         $t6, $at, L_800A0D1C
    if (ctx->r14 != ctx->r1) {
        // 0x800A0CF4: addiu       $at, $zero, 0x74
        ctx->r1 = ADD32(0, 0X74);
            goto L_800A0D1C;
    }
    // 0x800A0CF4: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x800A0CF8: bne         $a1, $at, L_800A0D1C
    if (ctx->r5 != ctx->r1) {
        // 0x800A0CFC: nop
    
            goto L_800A0D1C;
    }
    // 0x800A0CFC: nop

    // 0x800A0D00: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0D04: nop

    // 0x800A0D08: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0D0C: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A0D10: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0D14: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0D18: nop

L_800A0D1C:
    // 0x800A0D1C: bne         $a3, $t0, L_800A0D54
    if (ctx->r7 != ctx->r8) {
        // 0x800A0D20: nop
    
            goto L_800A0D54;
    }
    // 0x800A0D20: nop

    // 0x800A0D24: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0D28: bne         $s2, $t8, L_800A0D54
    if (ctx->r18 != ctx->r24) {
        // 0x800A0D2C: nop
    
            goto L_800A0D54;
    }
    // 0x800A0D2C: nop

    // 0x800A0D30: bne         $s2, $a1, L_800A0D54
    if (ctx->r18 != ctx->r5) {
        // 0x800A0D34: nop
    
            goto L_800A0D54;
    }
    // 0x800A0D34: nop

    // 0x800A0D38: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0D3C: nop

    // 0x800A0D40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0D44: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A0D48: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0D4C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0D50: nop

L_800A0D54:
    // 0x800A0D54: bne         $a3, $t0, L_800A0D8C
    if (ctx->r7 != ctx->r8) {
        // 0x800A0D58: nop
    
            goto L_800A0D8C;
    }
    // 0x800A0D58: nop

    // 0x800A0D5C: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0D60: bne         $t3, $t6, L_800A0D8C
    if (ctx->r11 != ctx->r14) {
        // 0x800A0D64: nop
    
            goto L_800A0D8C;
    }
    // 0x800A0D64: nop

    // 0x800A0D68: bne         $s2, $a1, L_800A0D8C
    if (ctx->r18 != ctx->r5) {
        // 0x800A0D6C: nop
    
            goto L_800A0D8C;
    }
    // 0x800A0D6C: nop

    // 0x800A0D70: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0D74: nop

    // 0x800A0D78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0D7C: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A0D80: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0D84: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0D88: nop

L_800A0D8C:
    // 0x800A0D8C: bne         $a3, $t0, L_800A0DC4
    if (ctx->r7 != ctx->r8) {
        // 0x800A0D90: nop
    
            goto L_800A0DC4;
    }
    // 0x800A0D90: nop

    // 0x800A0D94: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0D98: bne         $t5, $t8, L_800A0DC4
    if (ctx->r13 != ctx->r24) {
        // 0x800A0D9C: nop
    
            goto L_800A0DC4;
    }
    // 0x800A0D9C: nop

    // 0x800A0DA0: bne         $t5, $a1, L_800A0DC4
    if (ctx->r13 != ctx->r5) {
        // 0x800A0DA4: nop
    
            goto L_800A0DC4;
    }
    // 0x800A0DA4: nop

    // 0x800A0DA8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0DAC: nop

    // 0x800A0DB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0DB4: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A0DB8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0DBC: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0DC0: nop

L_800A0DC4:
    // 0x800A0DC4: bne         $a3, $t0, L_800A0DFC
    if (ctx->r7 != ctx->r8) {
        // 0x800A0DC8: nop
    
            goto L_800A0DFC;
    }
    // 0x800A0DC8: nop

    // 0x800A0DCC: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0DD0: bne         $s2, $t6, L_800A0DFC
    if (ctx->r18 != ctx->r14) {
        // 0x800A0DD4: nop
    
            goto L_800A0DFC;
    }
    // 0x800A0DD4: nop

    // 0x800A0DD8: bne         $t5, $a1, L_800A0DFC
    if (ctx->r13 != ctx->r5) {
        // 0x800A0DDC: nop
    
            goto L_800A0DFC;
    }
    // 0x800A0DDC: nop

    // 0x800A0DE0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0DE4: nop

    // 0x800A0DE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0DEC: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A0DF0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0DF4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0DF8: nop

L_800A0DFC:
    // 0x800A0DFC: bne         $a3, $t0, L_800A0E34
    if (ctx->r7 != ctx->r8) {
        // 0x800A0E00: nop
    
            goto L_800A0E34;
    }
    // 0x800A0E00: nop

    // 0x800A0E04: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0E08: bne         $t5, $t8, L_800A0E34
    if (ctx->r13 != ctx->r24) {
        // 0x800A0E0C: nop
    
            goto L_800A0E34;
    }
    // 0x800A0E0C: nop

    // 0x800A0E10: bne         $s2, $a1, L_800A0E34
    if (ctx->r18 != ctx->r5) {
        // 0x800A0E14: nop
    
            goto L_800A0E34;
    }
    // 0x800A0E14: nop

    // 0x800A0E18: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0E1C: nop

    // 0x800A0E20: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0E24: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800A0E28: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0E2C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0E30: nop

L_800A0E34:
    // 0x800A0E34: bne         $a3, $t0, L_800A0E70
    if (ctx->r7 != ctx->r8) {
        // 0x800A0E38: nop
    
            goto L_800A0E70;
    }
    // 0x800A0E38: nop

    // 0x800A0E3C: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0E40: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x800A0E44: bne         $t6, $at, L_800A0E70
    if (ctx->r14 != ctx->r1) {
        // 0x800A0E48: nop
    
            goto L_800A0E70;
    }
    // 0x800A0E48: nop

    // 0x800A0E4C: bne         $t3, $a1, L_800A0E70
    if (ctx->r11 != ctx->r5) {
        // 0x800A0E50: nop
    
            goto L_800A0E70;
    }
    // 0x800A0E50: nop

    // 0x800A0E54: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0E58: nop

    // 0x800A0E5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0E60: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800A0E64: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0E68: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0E6C: nop

L_800A0E70:
    // 0x800A0E70: bne         $a3, $t0, L_800A0EA8
    if (ctx->r7 != ctx->r8) {
        // 0x800A0E74: nop
    
            goto L_800A0EA8;
    }
    // 0x800A0E74: nop

    // 0x800A0E78: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0E7C: bne         $s4, $t8, L_800A0EA8
    if (ctx->r20 != ctx->r24) {
        // 0x800A0E80: nop
    
            goto L_800A0EA8;
    }
    // 0x800A0E80: nop

    // 0x800A0E84: bne         $s1, $a1, L_800A0EA8
    if (ctx->r17 != ctx->r5) {
        // 0x800A0E88: nop
    
            goto L_800A0EA8;
    }
    // 0x800A0E88: nop

    // 0x800A0E8C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0E90: nop

    // 0x800A0E94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0E98: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A0E9C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0EA0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0EA4: nop

L_800A0EA8:
    // 0x800A0EA8: bne         $a3, $t0, L_800A0EE4
    if (ctx->r7 != ctx->r8) {
        // 0x800A0EAC: nop
    
            goto L_800A0EE4;
    }
    // 0x800A0EAC: nop

    // 0x800A0EB0: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0EB4: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800A0EB8: bne         $s1, $t6, L_800A0EE4
    if (ctx->r17 != ctx->r14) {
        // 0x800A0EBC: nop
    
            goto L_800A0EE4;
    }
    // 0x800A0EBC: nop

    // 0x800A0EC0: bne         $a1, $at, L_800A0EE4
    if (ctx->r5 != ctx->r1) {
        // 0x800A0EC4: nop
    
            goto L_800A0EE4;
    }
    // 0x800A0EC4: nop

    // 0x800A0EC8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0ECC: nop

    // 0x800A0ED0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0ED4: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800A0ED8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0EDC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0EE0: nop

L_800A0EE4:
    // 0x800A0EE4: bne         $a3, $t0, L_800A0F20
    if (ctx->r7 != ctx->r8) {
        // 0x800A0EE8: nop
    
            goto L_800A0F20;
    }
    // 0x800A0EE8: nop

    // 0x800A0EEC: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0EF0: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x800A0EF4: bne         $s1, $t8, L_800A0F20
    if (ctx->r17 != ctx->r24) {
        // 0x800A0EF8: nop
    
            goto L_800A0F20;
    }
    // 0x800A0EF8: nop

    // 0x800A0EFC: bne         $a1, $at, L_800A0F20
    if (ctx->r5 != ctx->r1) {
        // 0x800A0F00: nop
    
            goto L_800A0F20;
    }
    // 0x800A0F00: nop

    // 0x800A0F04: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0F08: nop

    // 0x800A0F0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0F10: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800A0F14: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A0F18: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800A0F1C: nop

L_800A0F20:
    // 0x800A0F20: bne         $a3, $t0, L_800A0F5C
    if (ctx->r7 != ctx->r8) {
        // 0x800A0F24: nop
    
            goto L_800A0F5C;
    }
    // 0x800A0F24: nop

    // 0x800A0F28: lbu         $t6, -0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0F2C: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x800A0F30: bne         $s1, $t6, L_800A0F5C
    if (ctx->r17 != ctx->r14) {
        // 0x800A0F34: nop
    
            goto L_800A0F5C;
    }
    // 0x800A0F34: nop

    // 0x800A0F38: bne         $a1, $at, L_800A0F5C
    if (ctx->r5 != ctx->r1) {
        // 0x800A0F3C: nop
    
            goto L_800A0F5C;
    }
    // 0x800A0F3C: nop

    // 0x800A0F40: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A0F44: nop

    // 0x800A0F48: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A0F4C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A0F50: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0F54: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A0F58: nop

L_800A0F5C:
    // 0x800A0F5C: bne         $v0, $zero, L_800A0F98
    if (ctx->r2 != 0) {
        // 0x800A0F60: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800A0F98;
    }
    // 0x800A0F60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800A0F64: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x800A0F68: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x800A0F6C: bne         $t8, $at, L_800A0F98
    if (ctx->r24 != ctx->r1) {
        // 0x800A0F70: nop
    
            goto L_800A0F98;
    }
    // 0x800A0F70: nop

    // 0x800A0F74: bne         $t4, $a1, L_800A0F98
    if (ctx->r12 != ctx->r5) {
        // 0x800A0F78: nop
    
            goto L_800A0F98;
    }
    // 0x800A0F78: nop

    // 0x800A0F7C: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A0F80: nop

    // 0x800A0F84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0F88: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800A0F8C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A0F90: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A0F94: nop

L_800A0F98:
    // 0x800A0F98: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A0F9C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800A0FA0: lbu         $t6, 0x26B8($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X26B8);
    // 0x800A0FA4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A0FA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A0FAC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800A0FB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0FB4: bgez        $t6, L_800A0FC8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A0FB8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800A0FC8;
    }
    // 0x800A0FB8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A0FBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A0FC0: nop

    // 0x800A0FC4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800A0FC8:
    // 0x800A0FC8: add.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x800A0FCC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A0FD0: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A0FD4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A0FD8: nop

    // 0x800A0FDC: lbu         $a1, 0x1($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X1);
L_800A0FE0:
    // 0x800A0FE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A0FE4: bnel        $a1, $zero, L_800A0784
    if (ctx->r5 != 0) {
        // 0x800A0FE8: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_800A0784;
    }
    goto skip_3;
    // 0x800A0FE8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_800A0FEC:
    // 0x800A0FEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A0FF0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800A0FF4: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800A0FF8: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800A0FFC: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x800A1000: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x800A1004: jr          $ra
    // 0x800A1008: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A1008: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void HUD_8008CB8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CB8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008CB90: jr          $ra
    // 0x8008CB94: nop

    return;
    // 0x8008CB94: nop

;}
RECOMP_FUNC void Boss_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E1B8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005E1BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005E1C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E1C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005E1C8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8005E1CC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005E1D0: addiu       $t7, $t7, -0x2FC
    ctx->r15 = ADD32(ctx->r15, -0X2FC);
    // 0x8005E1D4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005E1D8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8005E1DC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8005E1E0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005E1E4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005E1E8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8005E1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E1F0: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8005E1F4: lbu         $t1, 0x35($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X35);
    // 0x8005E1F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E1FC: beq         $t1, $zero, L_8005E248
    if (ctx->r9 == 0) {
        // 0x8005E200: nop
    
            goto L_8005E248;
    }
    // 0x8005E200: nop

    // 0x8005E204: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8005E208: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005E20C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005E210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E214: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005E218: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    // 0x8005E21C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8005E220: jal         0x8005D1F0
    // 0x8005E224: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    Boss_SetMatrix(rdram, ctx);
        goto after_0;
    // 0x8005E224: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x8005E228: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E22C: lwc1        $f10, -0x7B84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005E230: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8005E234: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005E238: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8005E23C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E240: b           L_8005E250
    // 0x8005E244: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_8005E250;
    // 0x8005E244: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8005E248:
    // 0x8005E248: jal         0x8005D1F0
    // 0x8005E24C: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    Boss_SetMatrix(rdram, ctx);
        goto after_1;
    // 0x8005E24C: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_1:
L_8005E250:
    // 0x8005E250: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005E254: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8005E258: addiu       $a2, $a2, 0x15D0
    ctx->r6 = ADD32(ctx->r6, 0X15D0);
    // 0x8005E25C: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005E260: jal         0x80006970
    // 0x8005E264: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8005E264: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8005E268: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8005E26C: addiu       $a1, $a1, 0x15D0
    ctx->r5 = ADD32(ctx->r5, 0X15D0);
    // 0x8005E270: jal         0x8005F290
    // 0x8005E274: addiu       $a0, $s0, 0x3FC
    ctx->r4 = ADD32(ctx->r16, 0X3FC);
    Object_SetSfxSourceToView(rdram, ctx);
        goto after_3;
    // 0x8005E274: addiu       $a0, $s0, 0x3FC
    ctx->r4 = ADD32(ctx->r16, 0X3FC);
    after_3:
    // 0x8005E278: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005E27C: addiu       $v1, $zero, 0x13C
    ctx->r3 = ADD32(0, 0X13C);
    // 0x8005E280: addiu       $at, $zero, 0x13D
    ctx->r1 = ADD32(0, 0X13D);
    // 0x8005E284: beq         $v1, $v0, L_8005E290
    if (ctx->r3 == ctx->r2) {
        // 0x8005E288: nop
    
            goto L_8005E290;
    }
    // 0x8005E288: nop

    // 0x8005E28C: bne         $v0, $at, L_8005E2B0
    if (ctx->r2 != ctx->r1) {
        // 0x8005E290: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005E2B0;
    }
L_8005E290:
    // 0x8005E290: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E294: lwc1        $f0, 0x631C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X631C);
    // 0x8005E298: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E29C: lwc1        $f18, 0x6320($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6320);
    // 0x8005E2A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E2A4: lwc1        $f2, 0x6324($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6324);
    // 0x8005E2A8: b           L_8005E300
    // 0x8005E2AC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8005E300;
    // 0x8005E2AC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8005E2B0:
    // 0x8005E2B0: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    // 0x8005E2B4: bne         $v0, $at, L_8005E2E0
    if (ctx->r2 != ctx->r1) {
        // 0x8005E2B8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005E2E0;
    }
    // 0x8005E2B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E2BC: lwc1        $f2, 0x6328($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6328);
    // 0x8005E2C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E2C4: lwc1        $f18, 0x632C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X632C);
    // 0x8005E2C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E2CC: lwc1        $f14, 0x6330($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6330);
    // 0x8005E2D0: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8005E2D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E2D8: b           L_8005E304
    // 0x8005E2DC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_8005E304;
    // 0x8005E2DC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_8005E2E0:
    // 0x8005E2E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005E2E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005E2E8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8005E2EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005E2F0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005E2F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E2F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E2FC: lwc1        $f2, 0x6334($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6334);
L_8005E300:
    // 0x8005E300: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_8005E304:
    // 0x8005E304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005E308: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005E30C: lwc1        $f12, 0x15D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X15D8);
    // 0x8005E310: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8005E314: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8005E318: nop

    // 0x8005E31C: bc1fl       L_8005E3E4
    if (!c1cs) {
        // 0x8005E320: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8005E3E4;
    }
    goto skip_0;
    // 0x8005E320: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8005E324: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8005E328: nop

    // 0x8005E32C: bc1fl       L_8005E3E4
    if (!c1cs) {
        // 0x8005E330: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8005E3E4;
    }
    goto skip_1;
    // 0x8005E330: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x8005E334: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8005E338: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005E33C: lwc1        $f0, 0x15D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8005E340: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005E344: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005E348: abs.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = fabsf(ctx->f16.fl);
    // 0x8005E34C: add.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8005E350: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8005E354: nop

    // 0x8005E358: bc1fl       L_8005E3E4
    if (!c1cs) {
        // 0x8005E35C: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8005E3E4;
    }
    goto skip_2;
    // 0x8005E35C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x8005E360: lwc1        $f0, 0x15D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X15D4);
    // 0x8005E364: add.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8005E368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E36C: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005E370: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8005E374: nop

    // 0x8005E378: bc1fl       L_8005E3E4
    if (!c1cs) {
        // 0x8005E37C: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8005E3E4;
    }
    goto skip_3;
    // 0x8005E37C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x8005E380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005E384: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x8005E388: beq         $v0, $at, L_8005E3E0
    if (ctx->r2 == ctx->r1) {
        // 0x8005E38C: swc1        $f6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
            goto L_8005E3E0;
    }
    // 0x8005E38C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8005E390: beql        $v1, $v0, L_8005E3A4
    if (ctx->r3 == ctx->r2) {
        // 0x8005E394: lbu         $t2, 0x20($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X20);
            goto L_8005E3A4;
    }
    goto skip_4;
    // 0x8005E394: lbu         $t2, 0x20($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X20);
    skip_4:
    // 0x8005E398: jal         0x8005F670
    // 0x8005E39C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Display_SetSecondLight(rdram, ctx);
        goto after_4;
    // 0x8005E39C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x8005E3A0: lbu         $t2, 0x20($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X20);
L_8005E3A4:
    // 0x8005E3A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E3A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005E3AC: beql        $t2, $at, L_8005E3C0
    if (ctx->r10 == ctx->r1) {
        // 0x8005E3B0: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_8005E3C0;
    }
    goto skip_5;
    // 0x8005E3B0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x8005E3B4: jal         0x80006EB8
    // 0x8005E3B8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x8005E3B8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_5:
    // 0x8005E3BC: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
L_8005E3C0:
    // 0x8005E3C0: bgezl       $t3, L_8005E3D4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8005E3C4: lw          $t9, 0x1C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1C);
            goto L_8005E3D4;
    }
    goto skip_6;
    // 0x8005E3C4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    skip_6:
    // 0x8005E3C8: jal         0x800596C0
    // 0x8005E3CC: nop

    Object_ApplyWaterDistortion(rdram, ctx);
        goto after_6;
    // 0x8005E3CC: nop

    after_6:
    // 0x8005E3D0: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
L_8005E3D4:
    // 0x8005E3D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E3D8: jalr        $t9
    // 0x8005E3DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8005E3DC: nop

    after_7:
L_8005E3E0:
    // 0x8005E3E0: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
L_8005E3E4:
    // 0x8005E3E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005E3E8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8005E3EC: swc1        $f10, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->f10.u32l;
    // 0x8005E3F0: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x8005E3F4: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x8005E3F8: addiu       $t5, $t5, 0x15D0
    ctx->r13 = ADD32(ctx->r13, 0X15D0);
    // 0x8005E3FC: bnel        $t4, $at, L_8005E444
    if (ctx->r12 != ctx->r1) {
        // 0x8005E400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8005E444;
    }
    goto skip_7;
    // 0x8005E400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8005E404: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8005E408: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8005E40C: sw          $at, 0x308($s0)
    MEM_W(0X308, ctx->r16) = ctx->r1;
    // 0x8005E410: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8005E414: sw          $t6, 0x30C($s0)
    MEM_W(0X30C, ctx->r16) = ctx->r14;
    // 0x8005E418: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x8005E41C: jal         0x8005F670
    // 0x8005E420: sw          $at, 0x310($s0)
    MEM_W(0X310, ctx->r16) = ctx->r1;
    Display_SetSecondLight(rdram, ctx);
        goto after_8;
    // 0x8005E420: sw          $at, 0x310($s0)
    MEM_W(0X310, ctx->r16) = ctx->r1;
    after_8:
    // 0x8005E424: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005E428: jal         0x80006EB8
    // 0x8005E42C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8005E42C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_9:
    // 0x8005E430: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8005E434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E438: jalr        $t9
    // 0x8005E43C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x8005E43C: nop

    after_10:
    // 0x8005E440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005E444:
    // 0x8005E444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E448: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8005E44C: jr          $ra
    // 0x8005E450: nop

    return;
    // 0x8005E450: nop

;}
RECOMP_FUNC void func_stdlib_800A1540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1540: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A1544: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800A1548: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800A154C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800A1550: jr          $ra
    // 0x800A1554: nop

    return;
    // 0x800A1554: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026DD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80026DD4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80026DD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80026DDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80026DE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80026DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026DE8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80026DEC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80026DF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80026DF4:
    // 0x80026DF4: bnel        $v0, $zero, L_80026E08
    if (ctx->r2 != 0) {
        // 0x80026DF8: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80026E08;
    }
    goto skip_0;
    // 0x80026DF8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x80026DFC: b           L_80026E08
    // 0x80026E00: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_80026E08;
    // 0x80026E00: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80026E04: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80026E08:
    // 0x80026E08: bnel        $v0, $a0, L_80026E1C
    if (ctx->r2 != ctx->r4) {
        // 0x80026E0C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_80026E1C;
    }
    goto skip_1;
    // 0x80026E0C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x80026E10: b           L_80026E1C
    // 0x80026E14: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_80026E1C;
    // 0x80026E14: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80026E18: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_80026E1C:
    // 0x80026E1C: bnel        $v0, $a1, L_80026E30
    if (ctx->r2 != ctx->r5) {
        // 0x80026E20: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_80026E30;
    }
    goto skip_2;
    // 0x80026E20: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x80026E24: b           L_80026E30
    // 0x80026E28: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_80026E30;
    // 0x80026E28: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80026E2C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_80026E30:
    // 0x80026E30: bnel        $v0, $a2, L_80026E44
    if (ctx->r2 != ctx->r6) {
        // 0x80026E34: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_80026E44;
    }
    goto skip_3;
    // 0x80026E34: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x80026E38: b           L_80026E44
    // 0x80026E3C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_80026E44;
    // 0x80026E3C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80026E40: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_80026E44:
    // 0x80026E44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80026E48: bne         $v0, $a3, L_80026DF4
    if (ctx->r2 != ctx->r7) {
        // 0x80026E4C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80026DF4;
    }
    // 0x80026E4C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80026E50: jr          $ra
    // 0x80026E54: nop

    return;
    // 0x80026E54: nop

;}
RECOMP_FUNC void HUD_VS_ShieldGaugeFrame_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CFB8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008CFBC: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8008CFC0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8008CFC4: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8008CFC8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8008CFCC: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8008CFD0: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8008CFD4: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x8008CFD8: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8008CFDC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8008CFE0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8008CFE4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8008CFE8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8008CFEC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8008CFF0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8008CFF4: lui         $s3, 0x300
    ctx->r19 = S32(0X300 << 16);
    // 0x8008CFF8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8008CFFC: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8008D000: addiu       $s3, $s3, 0xBC0
    ctx->r19 = ADD32(ctx->r19, 0XBC0);
    // 0x8008D004: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008D008: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008D00C: addiu       $s4, $zero, 0x18
    ctx->r20 = ADD32(0, 0X18);
L_8008D010:
    // 0x8008D010: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8008D014: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008D018: bgez        $s1, L_8008D028
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8008D01C: sra         $t6, $s1, 1
        ctx->r14 = S32(SIGNED(ctx->r17) >> 1);
            goto L_8008D028;
    }
    // 0x8008D01C: sra         $t6, $s1, 1
    ctx->r14 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8008D020: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8008D024: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8008D028:
    // 0x8008D028: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008D02C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008D030: addu        $a1, $s3, $t7
    ctx->r5 = ADD32(ctx->r19, ctx->r15);
    // 0x8008D034: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8008D038: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8008D03C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8008D040: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8008D044: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008D048: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008D04C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8008D050: jal         0x8009D994
    // 0x8008D054: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x8008D054: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8008D058: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8008D05C: bne         $s0, $s4, L_8008D010
    if (ctx->r16 != ctx->r20) {
        // 0x8008D060: addiu       $s1, $s1, 0x280
        ctx->r17 = ADD32(ctx->r17, 0X280);
            goto L_8008D010;
    }
    // 0x8008D060: addiu       $s1, $s1, 0x280
    ctx->r17 = ADD32(ctx->r17, 0X280);
    // 0x8008D064: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x8008D068: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008D06C: bgez        $s1, L_8008D07C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8008D070: sra         $t8, $s1, 1
        ctx->r24 = S32(SIGNED(ctx->r17) >> 1);
            goto L_8008D07C;
    }
    // 0x8008D070: sra         $t8, $s1, 1
    ctx->r24 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8008D074: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8008D078: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8008D07C:
    // 0x8008D07C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008D080: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8008D084: addu        $a1, $s3, $t9
    ctx->r5 = ADD32(ctx->r19, ctx->r25);
    // 0x8008D088: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8008D08C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8008D090: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8008D094: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8008D098: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008D09C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008D0A0: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8008D0A4: jal         0x8009D994
    // 0x8008D0A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8008D0A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8008D0AC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8008D0B0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8008D0B4: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8008D0B8: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8008D0BC: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8008D0C0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8008D0C4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D0C8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8008D0CC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8008D0D0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8008D0D4: jr          $ra
    // 0x8008D0D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008D0D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Audio_SetTransposeAndPlaySfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D034: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001D038: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001D03C: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
    // 0x8001D040: addiu       $t6, $t6, 0x749C
    ctx->r14 = ADD32(ctx->r14, 0X749C);
    // 0x8001D044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D048: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8001D04C: andi        $a3, $a2, 0xFF
    ctx->r7 = ctx->r6 & 0XFF;
    // 0x8001D050: addiu       $t9, $t6, 0x30
    ctx->r25 = ADD32(ctx->r14, 0X30);
    // 0x8001D054: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_8001D058:
    // 0x8001D058: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8001D05C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001D060: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8001D064: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x8001D068: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x8001D06C: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8001D070: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8001D074: bne         $t6, $t9, L_8001D058
    if (ctx->r14 != ctx->r25) {
        // 0x8001D078: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8001D058;
    }
    // 0x8001D078: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x8001D07C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8001D080: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8001D084: slti        $at, $a3, 0xD
    ctx->r1 = SIGNED(ctx->r7) < 0XD ? 1 : 0;
    // 0x8001D088: bnel        $at, $zero, L_8001D098
    if (ctx->r1 != 0) {
        // 0x8001D08C: sll         $t1, $a3, 2
        ctx->r9 = S32(ctx->r7 << 2);
            goto L_8001D098;
    }
    goto skip_0;
    // 0x8001D08C: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    skip_0:
    // 0x8001D090: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8001D094: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
L_8001D098:
    // 0x8001D098: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8001D09C: jal         0x8001D0B4
    // 0x8001D0A0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    Audio_SetModulationAndPlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001D0A0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    after_0:
    // 0x8001D0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D0A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8001D0AC: jr          $ra
    // 0x8001D0B0: nop

    return;
    // 0x8001D0B0: nop

;}
RECOMP_FUNC void HUD_RadioDamage_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BAE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008BAE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008BAEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008BAF0: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008BAF4: lw          $v1, 0x178C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X178C);
    // 0x8008BAF8: addiu       $t6, $zero, 0xC0
    ctx->r14 = ADD32(0, 0XC0);
    // 0x8008BAFC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8008BB00: beq         $v1, $zero, L_8008BB4C
    if (ctx->r3 == 0) {
        // 0x8008BB04: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_8008BB4C;
    }
    // 0x8008BB04: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008BB08: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x8008BB0C: mflo        $a2
    ctx->r6 = lo;
    // 0x8008BB10: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008BB14: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008BB18: bne         $v1, $zero, L_8008BB24
    if (ctx->r3 != 0) {
        // 0x8008BB1C: nop
    
            goto L_8008BB24;
    }
    // 0x8008BB1C: nop

    // 0x8008BB20: break       7
    do_break(2148055840);
L_8008BB24:
    // 0x8008BB24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008BB28: bne         $v1, $at, L_8008BB3C
    if (ctx->r3 != ctx->r1) {
        // 0x8008BB2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008BB3C;
    }
    // 0x8008BB2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008BB30: bne         $t6, $at, L_8008BB3C
    if (ctx->r14 != ctx->r1) {
        // 0x8008BB34: nop
    
            goto L_8008BB3C;
    }
    // 0x8008BB34: nop

    // 0x8008BB38: break       6
    do_break(2148055864);
L_8008BB3C:
    // 0x8008BB3C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8008BB40: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008BB44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008BB48: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8008BB4C:
    // 0x8008BB4C: lw          $v0, 0x1788($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1788);
    // 0x8008BB50: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008BB54: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8008BB58: beq         $v0, $zero, L_8008BB78
    if (ctx->r2 == 0) {
        // 0x8008BB5C: addiu       $s0, $s0, 0x7E64
        ctx->r16 = ADD32(ctx->r16, 0X7E64);
            goto L_8008BB78;
    }
    // 0x8008BB5C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008BB60: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x8008BB64: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x8008BB68: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8008BB6C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8008BB70: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8008BB74: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8008BB78:
    // 0x8008BB78: bne         $v0, $zero, L_8008BB84
    if (ctx->r2 != 0) {
        // 0x8008BB7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008BB84;
    }
    // 0x8008BB7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008BB80: beq         $v1, $zero, L_8008BC6C
    if (ctx->r3 == 0) {
        // 0x8008BB84: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_8008BC6C;
    }
L_8008BB84:
    // 0x8008BB84: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8008BB88: jal         0x800B8DD0
    // 0x8008BB8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008BB8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8008BB90: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8008BB94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008BB98: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8008BB9C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008BBA0: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8008BBA4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8008BBA8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008BBAC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8008BBB0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BBB4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8008BBB8: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8008BBBC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8008BBC0: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8008BBC4: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8008BBC8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8008BBCC: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8008BBD0: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8008BBD4: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x8008BBD8: or          $t5, $t2, $t3
    ctx->r13 = ctx->r10 | ctx->r11;
    // 0x8008BBDC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8008BBE0: jal         0x80005708
    // 0x8008BBE4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8008BBE4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x8008BBE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008BBEC: lui         $a1, 0xC257
    ctx->r5 = S32(0XC257 << 16);
    // 0x8008BBF0: lui         $a3, 0xC30B
    ctx->r7 = S32(0XC30B << 16);
    // 0x8008BBF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008BBF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008BBFC: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x8008BC00: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8008BC04: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8008BC08: jal         0x80005B00
    // 0x8008BC0C: lui         $a2, 0xC21A
    ctx->r6 = S32(0XC21A << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8008BC0C: lui         $a2, 0xC21A
    ctx->r6 = S32(0XC21A << 16);
    after_2:
    // 0x8008BC10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008BC14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008BC18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008BC1C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008BC20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008BC24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008BC28: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008BC2C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008BC30: jal         0x80005C34
    // 0x8008BC34: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8008BC34: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x8008BC38: jal         0x80006EB8
    // 0x8008BC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8008BC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008BC40: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008BC44: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008BC48: addiu       $t0, $t0, 0x1A40
    ctx->r8 = ADD32(ctx->r8, 0X1A40);
    // 0x8008BC4C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8008BC50: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8008BC54: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8008BC58: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008BC5C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8008BC60: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008BC64: jal         0x80005740
    // 0x8008BC68: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x8008BC68: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
L_8008BC6C:
    // 0x8008BC6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008BC70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008BC74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008BC78: jr          $ra
    // 0x8008BC7C: nop

    return;
    // 0x8008BC7C: nop

;}
RECOMP_FUNC void HUD_VS_ShieldGaugeTex_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D0DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008D0E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008D0E4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8008D0E8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8008D0EC: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8008D0F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008D0F4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8008D0F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008D0FC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8008D100: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008D104: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008D108: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008D10C: lui         $a1, 0x301
    ctx->r5 = S32(0X301 << 16);
    // 0x8008D110: lui         $a2, 0x301
    ctx->r6 = S32(0X301 << 16);
    // 0x8008D114: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8008D118: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D11C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8008D120: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008D124: addiu       $a2, $a2, -0x2B00
    ctx->r6 = ADD32(ctx->r6, -0X2B00);
    // 0x8008D128: addiu       $a1, $a1, -0x2BC0
    ctx->r5 = ADD32(ctx->r5, -0X2BC0);
    // 0x8008D12C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8008D130: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008D134: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8008D138: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8008D13C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008D140: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x8008D144: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8008D148: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8008D14C: beq         $t8, $zero, L_8008D19C
    if (ctx->r24 == 0) {
        // 0x8008D150: swc1        $f6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
            goto L_8008D19C;
    }
    // 0x8008D150: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8008D154: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8008D158: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008D15C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008D160: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8008D164: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008D168: nop

    // 0x8008D16C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8008D170: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008D174: nop

    // 0x8008D178: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8008D17C: bne         $t8, $zero, L_8008D194
    if (ctx->r24 != 0) {
        // 0x8008D180: nop
    
            goto L_8008D194;
    }
    // 0x8008D180: nop

    // 0x8008D184: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8008D188: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D18C: b           L_8008D1AC
    // 0x8008D190: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8008D1AC;
    // 0x8008D190: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8008D194:
    // 0x8008D194: b           L_8008D1AC
    // 0x8008D198: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8008D1AC;
    // 0x8008D198: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8008D19C:
    // 0x8008D19C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8008D1A0: nop

    // 0x8008D1A4: bltz        $t8, L_8008D194
    if (SIGNED(ctx->r24) < 0) {
        // 0x8008D1A8: nop
    
            goto L_8008D194;
    }
    // 0x8008D1A8: nop

L_8008D1AC:
    // 0x8008D1AC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8008D1B0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008D1B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8008D1B8: bgez        $t8, L_8008D1CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008D1BC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8008D1CC;
    }
    // 0x8008D1BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008D1C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008D1C4: nop

    // 0x8008D1C8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8008D1CC:
    // 0x8008D1CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008D1D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008D1D4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8008D1D8: jal         0x80084E78
    // 0x8008D1DC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    TextureRect_CI8_2(rdram, ctx);
        goto after_0;
    // 0x8008D1DC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8008D1E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008D1E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008D1E8: jr          $ra
    // 0x8008D1EC: nop

    return;
    // 0x8008D1EC: nop

;}
RECOMP_FUNC void func_col1_8009808C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009808C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80098090: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x80098094: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80098098: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x8009809C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800980A0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800980A4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800980A8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800980AC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800980B0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800980B4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800980B8: addiu       $t5, $t5, 0x1984
    ctx->r13 = ADD32(ctx->r13, 0X1984);
    // 0x800980BC: addiu       $t4, $t4, 0x1980
    ctx->r12 = ADD32(ctx->r12, 0X1980);
    // 0x800980C0: addiu       $t3, $t3, 0x197C
    ctx->r11 = ADD32(ctx->r11, 0X197C);
    // 0x800980C4: addiu       $t2, $t2, 0x1978
    ctx->r10 = ADD32(ctx->r10, 0X1978);
    // 0x800980C8: addiu       $t1, $t1, 0x1974
    ctx->r9 = ADD32(ctx->r9, 0X1974);
    // 0x800980CC: addiu       $t0, $t0, 0x1970
    ctx->r8 = ADD32(ctx->r8, 0X1970);
    // 0x800980D0: addiu       $a3, $a3, 0x196C
    ctx->r7 = ADD32(ctx->r7, 0X196C);
    // 0x800980D4: addiu       $v0, $v0, 0x1968
    ctx->r2 = ADD32(ctx->r2, 0X1968);
    // 0x800980D8: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x800980DC: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x800980E0: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800980E4: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800980E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800980EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800980F0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800980F4: nop

    // 0x800980F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800980FC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80098100: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x80098104: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80098108: nop

    // 0x8009810C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098110: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80098114: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x80098118: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8009811C: nop

    // 0x80098120: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80098124: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x80098128: lh          $t9, 0x10($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X10);
    // 0x8009812C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80098130: nop

    // 0x80098134: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098138: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8009813C: lh          $t6, 0x12($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X12);
    // 0x80098140: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80098144: nop

    // 0x80098148: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009814C: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80098150: lh          $t7, 0x14($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X14);
    // 0x80098154: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80098158: nop

    // 0x8009815C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098160: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80098164: lh          $t8, 0x20($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X20);
    // 0x80098168: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8009816C: nop

    // 0x80098170: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80098174: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
    // 0x80098178: lh          $t9, 0x22($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X22);
    // 0x8009817C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80098180: nop

    // 0x80098184: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098188: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x8009818C: lh          $t6, 0x24($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X24);
    // 0x80098190: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80098194: nop

    // 0x80098198: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009819C: swc1        $f6, 0x1988($at)
    MEM_W(0X1988, ctx->r1) = ctx->f6.u32l;
    // 0x800981A0: lh          $t7, 0x30($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X30);
    // 0x800981A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800981A8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800981AC: nop

    // 0x800981B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800981B4: swc1        $f10, 0x198C($at)
    MEM_W(0X198C, ctx->r1) = ctx->f10.u32l;
    // 0x800981B8: lh          $t8, 0x32($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X32);
    // 0x800981BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800981C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800981C4: nop

    // 0x800981C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800981CC: swc1        $f6, 0x1990($at)
    MEM_W(0X1990, ctx->r1) = ctx->f6.u32l;
    // 0x800981D0: lh          $t9, 0x34($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X34);
    // 0x800981D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800981D8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800981DC: nop

    // 0x800981E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800981E4: swc1        $f10, 0x1994($at)
    MEM_W(0X1994, ctx->r1) = ctx->f10.u32l;
    // 0x800981E8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800981EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800981F0: swc1        $f4, 0x1998($at)
    MEM_W(0X1998, ctx->r1) = ctx->f4.u32l;
    // 0x800981F4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800981F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800981FC: swc1        $f6, 0x199C($at)
    MEM_W(0X199C, ctx->r1) = ctx->f6.u32l;
    // 0x80098200: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80098204: lwc1        $f20, 0x1998($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X1998);
    // 0x80098208: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009820C: lwc1        $f24, 0x199C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X199C);
    // 0x80098210: lwc1        $f22, 0x0($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80098214: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80098218: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8009821C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80098220: sub.s       $f8, $f12, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f22.fl;
    // 0x80098224: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80098228: sub.s       $f10, $f24, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f16.fl;
    // 0x8009822C: sub.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f12.fl;
    // 0x80098230: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80098234: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80098238: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8009823C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80098240: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80098244: c.le.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl <= ctx->f14.fl;
    // 0x80098248: nop

    // 0x8009824C: bc1f        L_80098390
    if (!c1cs) {
        // 0x80098250: nop
    
            goto L_80098390;
    }
    // 0x80098250: nop

    // 0x80098254: lwc1        $f2, 0x1988($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1988);
    // 0x80098258: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8009825C: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80098260: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80098264: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80098268: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009826C: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80098270: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80098274: sub.s       $f8, $f24, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x80098278: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8009827C: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80098280: c.le.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl <= ctx->f14.fl;
    // 0x80098284: nop

    // 0x80098288: bc1f        L_80098390
    if (!c1cs) {
        // 0x8009828C: nop
    
            goto L_80098390;
    }
    // 0x8009828C: nop

    // 0x80098290: sub.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80098294: sub.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80098298: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8009829C: sub.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x800982A0: sub.s       $f8, $f22, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x800982A4: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800982A8: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800982AC: c.le.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl <= ctx->f14.fl;
    // 0x800982B0: nop

    // 0x800982B4: bc1f        L_80098390
    if (!c1cs) {
        // 0x800982B8: nop
    
            goto L_80098390;
    }
    // 0x800982B8: nop

    // 0x800982BC: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800982C0: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800982C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800982C8: sub.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800982CC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800982D0: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800982D4: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800982D8: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800982DC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800982E0: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800982E4: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x800982E8: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800982EC: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800982F0: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800982F4: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800982F8: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800982FC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80098300: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80098304: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80098308: lwc1        $f4, 0x1988($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1988);
    // 0x8009830C: sub.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80098310: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80098314: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80098318: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8009831C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80098320: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80098324: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80098328: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8009832C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80098330: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80098334: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80098338: sub.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8009833C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80098340: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80098344: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80098348: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8009834C: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80098350: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80098354: c.eq.s      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.fl == ctx->f4.fl;
    // 0x80098358: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8009835C: bc1f        L_8009838C
    if (!c1cs) {
        // 0x80098360: swc1        $f6, 0x8($a2)
        MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
            goto L_8009838C;
    }
    // 0x80098360: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80098364: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80098368: c.eq.s      $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f26.fl == ctx->f10.fl;
    // 0x8009836C: nop

    // 0x80098370: bc1fl       L_80098390
    if (!c1cs) {
        // 0x80098374: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80098390;
    }
    goto skip_0;
    // 0x80098374: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
    // 0x80098378: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8009837C: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x80098380: nop

    // 0x80098384: bc1t        L_80098390
    if (c1cs) {
        // 0x80098388: nop
    
            goto L_80098390;
    }
    // 0x80098388: nop

L_8009838C:
    // 0x8009838C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80098390:
    // 0x80098390: bne         $v1, $zero, L_8009853C
    if (ctx->r3 != 0) {
        // 0x80098394: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_8009853C;
    }
    // 0x80098394: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80098398: lwc1        $f2, 0x1988($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1988);
    // 0x8009839C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800983A0: lwc1        $f20, 0x1998($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X1998);
    // 0x800983A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800983A8: lwc1        $f24, 0x199C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X199C);
    // 0x800983AC: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800983B0: lwc1        $f22, 0x0($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800983B4: sub.s       $f4, $f24, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x800983B8: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800983BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800983C0: sub.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800983C4: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800983C8: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800983CC: sub.s       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x800983D0: mul.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800983D4: sub.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800983D8: c.le.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl <= ctx->f14.fl;
    // 0x800983DC: nop

    // 0x800983E0: bc1f        L_8009853C
    if (!c1cs) {
        // 0x800983E4: nop
    
            goto L_8009853C;
    }
    // 0x800983E4: nop

    // 0x800983E8: lwc1        $f4, 0x1994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1994);
    // 0x800983EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800983F0: lwc1        $f8, 0x198C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X198C);
    // 0x800983F4: sub.s       $f10, $f24, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800983F8: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800983FC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80098400: sub.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80098404: sub.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80098408: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8009840C: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x80098410: mul.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80098414: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80098418: c.le.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl <= ctx->f14.fl;
    // 0x8009841C: nop

    // 0x80098420: bc1f        L_8009853C
    if (!c1cs) {
        // 0x80098424: nop
    
            goto L_8009853C;
    }
    // 0x80098424: nop

    // 0x80098428: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8009842C: sub.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80098430: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80098434: sub.s       $f6, $f24, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80098438: sub.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x8009843C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80098440: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80098444: c.le.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl <= ctx->f14.fl;
    // 0x80098448: nop

    // 0x8009844C: bc1f        L_8009853C
    if (!c1cs) {
        // 0x80098450: nop
    
            goto L_8009853C;
    }
    // 0x80098450: nop

    // 0x80098454: lwc1        $f14, 0x0($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80098458: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8009845C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80098460: lwc1        $f8, 0x1990($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1990);
    // 0x80098464: sub.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80098468: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009846C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80098470: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80098474: nop

    // 0x80098478: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8009847C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80098480: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80098484: lwc1        $f2, 0x1988($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1988);
    // 0x80098488: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009848C: lwc1        $f6, 0x198C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X198C);
    // 0x80098490: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80098494: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80098498: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009849C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800984A0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800984A4: sub.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800984A8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800984AC: lwc1        $f8, 0x1994($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1994);
    // 0x800984B0: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800984B4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800984B8: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800984BC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800984C0: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800984C4: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x800984C8: lwc1        $f8, 0x1990($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1990);
    // 0x800984CC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800984D0: lwc1        $f14, 0x0($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800984D4: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800984D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800984DC: sub.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800984E0: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800984E4: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800984E8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800984EC: lwc1        $f4, 0x198C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X198C);
    // 0x800984F0: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x800984F4: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800984F8: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800984FC: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80098500: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x80098504: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80098508: bc1f        L_80098538
    if (!c1cs) {
        // 0x8009850C: swc1        $f10, 0x8($a2)
        MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
            goto L_80098538;
    }
    // 0x8009850C: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x80098510: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80098514: c.eq.s      $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f26.fl == ctx->f6.fl;
    // 0x80098518: nop

    // 0x8009851C: bc1fl       L_8009853C
    if (!c1cs) {
        // 0x80098520: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8009853C;
    }
    goto skip_1;
    // 0x80098520: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_1:
    // 0x80098524: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80098528: c.eq.s      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.fl == ctx->f4.fl;
    // 0x8009852C: nop

    // 0x80098530: bc1t        L_8009853C
    if (c1cs) {
        // 0x80098534: nop
    
            goto L_8009853C;
    }
    // 0x80098534: nop

L_80098538:
    // 0x80098538: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8009853C:
    // 0x8009853C: beq         $v1, $zero, L_800985B4
    if (ctx->r3 == 0) {
        // 0x80098540: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800985B4;
    }
    // 0x80098540: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80098544: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80098548: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8009854C: lwc1        $f14, 0x8($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80098550: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80098554: nop

    // 0x80098558: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8009855C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80098560: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80098564: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80098568: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8009856C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80098570: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80098574: nop

    // 0x80098578: bc1f        L_80098588
    if (!c1cs) {
        // 0x8009857C: nop
    
            goto L_80098588;
    }
    // 0x8009857C: nop

    // 0x80098580: b           L_800985B4
    // 0x80098584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800985B4;
    // 0x80098584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80098588:
    // 0x80098588: div.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009858C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80098590: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80098594: div.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80098598: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009859C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800985A0: div.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800985A4: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800985A8: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x800985AC: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800985B0: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
L_800985B4:
    // 0x800985B4: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800985B8: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800985BC: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x800985C0: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x800985C4: jr          $ra
    // 0x800985C8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800985C8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Effect_ElectricArc_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B67C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B684: lh          $t6, 0x46($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X46);
    // 0x8007B688: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8007B68C: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8007B690: sh          $t7, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r15;
    // 0x8007B694: lh          $v0, 0x46($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X46);
    // 0x8007B698: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8007B69C: bnel        $at, $zero, L_8007B6B0
    if (ctx->r1 != 0) {
        // 0x8007B6A0: slti        $at, $v0, 0x9
        ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
            goto L_8007B6B0;
    }
    goto skip_0;
    // 0x8007B6A0: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    skip_0:
    // 0x8007B6A4: sh          $t8, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r24;
    // 0x8007B6A8: lh          $v0, 0x46($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X46);
    // 0x8007B6AC: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
L_8007B6B0:
    // 0x8007B6B0: bnel        $at, $zero, L_8007B6E8
    if (ctx->r1 != 0) {
        // 0x8007B6B4: lh          $v1, 0x4A($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X4A);
            goto L_8007B6E8;
    }
    goto skip_1;
    // 0x8007B6B4: lh          $v1, 0x4A($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4A);
    skip_1:
    // 0x8007B6B8: lh          $t9, 0x48($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X48);
    // 0x8007B6BC: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007B6C0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8007B6C4: sh          $t0, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r8;
    // 0x8007B6C8: lh          $t1, 0x48($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X48);
    // 0x8007B6CC: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x8007B6D0: bnel        $at, $zero, L_8007B6E8
    if (ctx->r1 != 0) {
        // 0x8007B6D4: lh          $v1, 0x4A($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X4A);
            goto L_8007B6E8;
    }
    goto skip_2;
    // 0x8007B6D4: lh          $v1, 0x4A($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4A);
    skip_2:
    // 0x8007B6D8: jal         0x80060FBC
    // 0x8007B6DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007B6DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007B6E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B6E4: lh          $v1, 0x4A($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4A);
L_8007B6E8:
    // 0x8007B6E8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007B6EC: addiu       $a1, $a1, -0x7D80
    ctx->r5 = ADD32(ctx->r5, -0X7D80);
    // 0x8007B6F0: beq         $v1, $zero, L_8007B748
    if (ctx->r3 == 0) {
        // 0x8007B6F4: slti        $at, $v1, 0xB
        ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
            goto L_8007B748;
    }
    // 0x8007B6F4: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x8007B6F8: bnel        $at, $zero, L_8007B708
    if (ctx->r1 != 0) {
        // 0x8007B6FC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8007B708;
    }
    goto skip_3;
    // 0x8007B6FC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    skip_3:
    // 0x8007B700: addiu       $v1, $v1, -0xA
    ctx->r3 = ADD32(ctx->r3, -0XA);
    // 0x8007B704: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_8007B708:
    // 0x8007B708: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007B70C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8007B710: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007B714: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B718: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8007B71C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8007B720: lwc1        $f4, -0x420($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, -0X420);
    // 0x8007B724: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x8007B728: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8007B72C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8007B730: lwc1        $f6, -0x41C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, -0X41C);
    // 0x8007B734: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x8007B738: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007B73C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8007B740: lwc1        $f8, -0x418($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, -0X418);
    // 0x8007B744: swc1        $f8, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f8.u32l;
L_8007B748:
    // 0x8007B748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B74C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B750: jr          $ra
    // 0x8007B754: nop

    return;
    // 0x8007B754: nop

;}
RECOMP_FUNC void RCP_SetupDL_73(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA460: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA464: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA468: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA46C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA470: addiu       $t8, $t8, 0x4638
    ctx->r24 = ADD32(ctx->r24, 0X4638);
    // 0x800BA474: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA478: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA47C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA480: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA484: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA488: jr          $ra
    // 0x800BA48C: nop

    return;
    // 0x800BA48C: nop

;}
RECOMP_FUNC void ActorDebris_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A094: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A098: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005A09C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005A0A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005A0A4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005A0A8: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
    // 0x8005A0AC: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8005A0B0: bne         $at, $zero, L_8005A0DC
    if (ctx->r1 != 0) {
        // 0x8005A0B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005A0DC;
    }
    // 0x8005A0B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005A0B8: addiu       $t6, $v1, -0x27
    ctx->r14 = ADD32(ctx->r3, -0X27);
    // 0x8005A0BC: sltiu       $at, $t6, 0x20
    ctx->r1 = ctx->r14 < 0X20 ? 1 : 0;
    // 0x8005A0C0: beq         $at, $zero, L_8005AD30
    if (ctx->r1 == 0) {
        // 0x8005A0C4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8005AD30;
    }
    // 0x8005A0C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005A0C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A0CC: addu        $at, $at, $t6
    gpr jr_addend_8005A0D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8005A0D0: lw          $t6, 0x6084($at)
    ctx->r14 = ADD32(ctx->r1, 0X6084);
    // 0x8005A0D4: jr          $t6
    // 0x8005A0D8: nop

    switch (jr_addend_8005A0D4 >> 2) {
        case 0: goto L_8005A2B8; break;
        case 1: goto L_8005A310; break;
        case 2: goto L_8005A658; break;
        case 3: goto L_8005A69C; break;
        case 4: goto L_8005A6E0; break;
        case 5: goto L_8005A724; break;
        case 6: goto L_8005A768; break;
        case 7: goto L_8005A798; break;
        case 8: goto L_8005A81C; break;
        case 9: goto L_8005A858; break;
        case 10: goto L_8005A89C; break;
        case 11: goto L_8005A8E0; break;
        case 12: goto L_8005AA6C; break;
        case 13: goto L_8005AAB0; break;
        case 14: goto L_8005AAF4; break;
        case 15: goto L_8005AB38; break;
        case 16: goto L_8005AB7C; break;
        case 17: goto L_8005ABC0; break;
        case 18: goto L_8005ACF4; break;
        case 19: goto L_8005AC38; break;
        case 20: goto L_8005AC78; break;
        case 21: goto L_8005AD30; break;
        case 22: goto L_8005AD30; break;
        case 23: goto L_8005AD30; break;
        case 24: goto L_8005AD30; break;
        case 25: goto L_8005AD30; break;
        case 26: goto L_8005AD30; break;
        case 27: goto L_8005AD30; break;
        case 28: goto L_8005AD30; break;
        case 29: goto L_8005AD30; break;
        case 30: goto L_8005AD30; break;
        case 31: goto L_8005ACC4; break;
        default: switch_error(__func__, 0x8005A0D4, 0x800D6084);
    }
    // 0x8005A0D8: nop

L_8005A0DC:
    // 0x8005A0DC: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8005A0E0: beq         $at, $zero, L_8005AD30
    if (ctx->r1 == 0) {
        // 0x8005A0E4: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8005AD30;
    }
    // 0x8005A0E4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8005A0E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A0EC: addu        $at, $at, $t7
    gpr jr_addend_8005A0F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005A0F0: lw          $t7, 0x6104($at)
    ctx->r15 = ADD32(ctx->r1, 0X6104);
    // 0x8005A0F4: jr          $t7
    // 0x8005A0F8: nop

    switch (jr_addend_8005A0F4 >> 2) {
        case 0: goto L_8005A0FC; break;
        case 1: goto L_8005A16C; break;
        case 2: goto L_8005A1DC; break;
        case 3: goto L_8005A214; break;
        case 4: goto L_8005A244; break;
        default: switch_error(__func__, 0x8005A0F4, 0x800D6104);
    }
    // 0x8005A0F8: nop

L_8005A0FC:
    // 0x8005A0FC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005A100: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8005A104: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005A108: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005A10C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005A110: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x8005A114: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x8005A118: jal         0x80005B00
    // 0x8005A11C: lui         $a3, 0xC170
    ctx->r7 = S32(0XC170 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005A11C: lui         $a3, 0xC170
    ctx->r7 = S32(0XC170 << 16);
    after_0:
    // 0x8005A120: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8005A124: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005A128: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005A12C: jal         0x80005E90
    // 0x8005A130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8005A130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8005A134: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A138: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A13C: jal         0x80006EB8
    // 0x8005A140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8005A140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005A144: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A148: lui         $t1, 0x301
    ctx->r9 = S32(0X301 << 16);
    // 0x8005A14C: addiu       $t1, $t1, 0x6660
    ctx->r9 = ADD32(ctx->r9, 0X6660);
    // 0x8005A150: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005A154: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005A158: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005A15C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005A160: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005A164: b           L_8005AD9C
    // 0x8005A168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A16C:
    // 0x8005A16C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005A170: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8005A174: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005A178: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005A17C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005A180: lui         $a1, 0xC190
    ctx->r5 = S32(0XC190 << 16);
    // 0x8005A184: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x8005A188: jal         0x80005B00
    // 0x8005A18C: lui         $a3, 0xC170
    ctx->r7 = S32(0XC170 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8005A18C: lui         $a3, 0xC170
    ctx->r7 = S32(0XC170 << 16);
    after_3:
    // 0x8005A190: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8005A194: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005A198: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005A19C: jal         0x80005E90
    // 0x8005A1A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8005A1A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8005A1A4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A1A8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A1AC: jal         0x80006EB8
    // 0x8005A1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x8005A1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8005A1B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A1B8: lui         $t5, 0x301
    ctx->r13 = S32(0X301 << 16);
    // 0x8005A1BC: addiu       $t5, $t5, 0x5D80
    ctx->r13 = ADD32(ctx->r13, 0X5D80);
    // 0x8005A1C0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005A1C4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005A1C8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005A1CC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005A1D0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005A1D4: b           L_8005AD9C
    // 0x8005A1D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A1D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A1DC:
    // 0x8005A1DC: jal         0x8005980C
    // 0x8005A1E0: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_6;
    // 0x8005A1E0: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_6:
    // 0x8005A1E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A1E8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A1EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A1F0: lui         $t8, 0x301
    ctx->r24 = S32(0X301 << 16);
    // 0x8005A1F4: addiu       $t8, $t8, 0x55E0
    ctx->r24 = ADD32(ctx->r24, 0X55E0);
    // 0x8005A1F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005A1FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005A200: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005A204: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005A208: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005A20C: b           L_8005AD9C
    // 0x8005A210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A214:
    // 0x8005A214: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A218: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A21C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A220: lui         $t1, 0x301
    ctx->r9 = S32(0X301 << 16);
    // 0x8005A224: addiu       $t1, $t1, 0x1720
    ctx->r9 = ADD32(ctx->r9, 0X1720);
    // 0x8005A228: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005A22C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005A230: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005A234: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005A238: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005A23C: b           L_8005AD9C
    // 0x8005A240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A244:
    // 0x8005A244: jal         0x8005980C
    // 0x8005A248: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_7;
    // 0x8005A248: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_7:
    // 0x8005A24C: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x8005A250: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8005A254: beq         $t3, $zero, L_8005A288
    if (ctx->r11 == 0) {
        // 0x8005A258: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005A288;
    }
    // 0x8005A258: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A25C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A260: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A264: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x8005A268: addiu       $t6, $t6, -0x6B40
    ctx->r14 = ADD32(ctx->r14, -0X6B40);
    // 0x8005A26C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005A270: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005A274: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005A278: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005A27C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005A280: b           L_8005AD9C
    // 0x8005A284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A288:
    // 0x8005A288: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A28C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A290: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A294: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x8005A298: addiu       $t9, $t9, 0x4290
    ctx->r25 = ADD32(ctx->r25, 0X4290);
    // 0x8005A29C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005A2A0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005A2A4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005A2A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005A2AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005A2B0: b           L_8005AD9C
    // 0x8005A2B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A2B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A2B8:
    // 0x8005A2B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A2BC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A2C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A2C4: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x8005A2C8: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x8005A2CC: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8005A2D0: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8005A2D4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005A2D8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005A2DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A2E0: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005A2E4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005A2E8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005A2EC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005A2F0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005A2F4: lh          $t5, 0x48($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X48);
    // 0x8005A2F8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8005A2FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005A300: lw          $t7, -0x53C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X53C);
    // 0x8005A304: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005A308: b           L_8005AD9C
    // 0x8005A30C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A30C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A310:
    // 0x8005A310: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A314: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A318: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A31C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8005A320: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005A324: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005A328: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005A32C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8005A330: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005A334: lh          $v1, 0x48($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X48);
    // 0x8005A338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A33C: beq         $v1, $zero, L_8005A3CC
    if (ctx->r3 == 0) {
        // 0x8005A340: nop
    
            goto L_8005A3CC;
    }
    // 0x8005A340: nop

    // 0x8005A344: beq         $v1, $at, L_8005A36C
    if (ctx->r3 == ctx->r1) {
        // 0x8005A348: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005A36C;
    }
    // 0x8005A348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A34C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A350: beq         $v1, $at, L_8005A398
    if (ctx->r3 == ctx->r1) {
        // 0x8005A354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005A398;
    }
    // 0x8005A354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A358: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005A35C: beq         $v1, $at, L_8005A3C4
    if (ctx->r3 == ctx->r1) {
        // 0x8005A360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005A3C4;
    }
    // 0x8005A360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A364: b           L_8005A3CC
    // 0x8005A368: nop

        goto L_8005A3CC;
    // 0x8005A368: nop

L_8005A36C:
    // 0x8005A36C: jal         0x800B8DD0
    // 0x8005A370: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x8005A370: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_8:
    // 0x8005A374: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A378: lui         $t2, 0xB600
    ctx->r10 = S32(0XB600 << 16);
    // 0x8005A37C: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x8005A380: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005A384: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8005A388: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005A38C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005A390: b           L_8005A3CC
    // 0x8005A394: nop

        goto L_8005A3CC;
    // 0x8005A394: nop

L_8005A398:
    // 0x8005A398: jal         0x800B8DD0
    // 0x8005A39C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x8005A39C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_9:
    // 0x8005A3A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A3A4: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8005A3A8: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8005A3AC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005A3B0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005A3B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005A3B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005A3BC: b           L_8005A3CC
    // 0x8005A3C0: nop

        goto L_8005A3CC;
    // 0x8005A3C0: nop

L_8005A3C4:
    // 0x8005A3C4: jal         0x800B8DD0
    // 0x8005A3C8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x8005A3C8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_10:
L_8005A3CC:
    // 0x8005A3CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A3D0: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8005A3D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005A3D8: beq         $t7, $at, L_8005A414
    if (ctx->r15 == ctx->r1) {
        // 0x8005A3DC: nop
    
            goto L_8005A414;
    }
    // 0x8005A3DC: nop

    // 0x8005A3E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A3E4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8005A3E8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8005A3EC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005A3F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005A3F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005A3F8: lh          $t0, 0x46($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X46);
    // 0x8005A3FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005A400: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005A404: lw          $t2, 0x769C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X769C);
    // 0x8005A408: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005A40C: b           L_8005AD9C
    // 0x8005A410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A414:
    // 0x8005A414: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A418: lwc1        $f4, -0xE0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XE0C);
    // 0x8005A41C: lui         $at, 0x4596
    ctx->r1 = S32(0X4596 << 16);
    // 0x8005A420: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A424: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8005A428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A42C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005A430: nop

    // 0x8005A434: bc1f        L_8005A530
    if (!c1cs) {
        // 0x8005A438: nop
    
            goto L_8005A530;
    }
    // 0x8005A438: nop

    // 0x8005A43C: jal         0x800B8DD0
    // 0x8005A440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x8005A440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8005A444: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8005A448: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x8005A44C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005A450: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8005A454: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005A458: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8005A45C: lw          $t5, -0x7CC8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7CC8);
    // 0x8005A460: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8005A464: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8005A468: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8005A46C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005A470: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005A474: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A478: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8005A47C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x8005A480: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005A484: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005A488: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005A48C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005A490: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005A494: lw          $t0, -0x7C24($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7C24);
    // 0x8005A498: lw          $a1, -0x7C28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7C28);
    // 0x8005A49C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8005A4A0: ori         $t1, $t1, 0xF400
    ctx->r9 = ctx->r9 | 0XF400;
    // 0x8005A4A4: subu        $a2, $t0, $a1
    ctx->r6 = SUB32(ctx->r8, ctx->r5);
    // 0x8005A4A8: div         $zero, $t1, $a2
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r6)));
    // 0x8005A4AC: negu        $t5, $a1
    ctx->r13 = SUB32(0, ctx->r5);
    // 0x8005A4B0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8005A4B4: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8005A4B8: mflo        $t2
    ctx->r10 = lo;
    // 0x8005A4BC: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8005A4C0: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8005A4C4: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x8005A4C8: mflo        $t8
    ctx->r24 = lo;
    // 0x8005A4CC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005A4D0: or          $t0, $t4, $t9
    ctx->r8 = ctx->r12 | ctx->r25;
    // 0x8005A4D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005A4D8: bne         $a2, $zero, L_8005A4E4
    if (ctx->r6 != 0) {
        // 0x8005A4DC: nop
    
            goto L_8005A4E4;
    }
    // 0x8005A4DC: nop

    // 0x8005A4E0: break       7
    do_break(2147853536);
L_8005A4E4:
    // 0x8005A4E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A4E8: bne         $a2, $at, L_8005A4FC
    if (ctx->r6 != ctx->r1) {
        // 0x8005A4EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005A4FC;
    }
    // 0x8005A4EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A4F0: bne         $t1, $at, L_8005A4FC
    if (ctx->r9 != ctx->r1) {
        // 0x8005A4F4: nop
    
            goto L_8005A4FC;
    }
    // 0x8005A4F4: nop

    // 0x8005A4F8: break       6
    do_break(2147853560);
L_8005A4FC:
    // 0x8005A4FC: addu        $at, $t1, $zero
    ctx->r1 = ADD32(ctx->r9, 0);
    // 0x8005A500: bne         $a2, $zero, L_8005A50C
    if (ctx->r6 != 0) {
        // 0x8005A504: nop
    
            goto L_8005A50C;
    }
    // 0x8005A504: nop

    // 0x8005A508: break       7
    do_break(2147853576);
L_8005A50C:
    // 0x8005A50C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A510: bne         $a2, $at, L_8005A524
    if (ctx->r6 != ctx->r1) {
        // 0x8005A514: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005A524;
    }
    // 0x8005A514: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A518: bne         $t7, $at, L_8005A524
    if (ctx->r15 != ctx->r1) {
        // 0x8005A51C: nop
    
            goto L_8005A524;
    }
    // 0x8005A51C: nop

    // 0x8005A520: break       6
    do_break(2147853600);
L_8005A524:
    // 0x8005A524: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x8005A528: b           L_8005A61C
    // 0x8005A52C: nop

        goto L_8005A61C;
    // 0x8005A52C: nop

L_8005A530:
    // 0x8005A530: jal         0x800B8DD0
    // 0x8005A534: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_12;
    // 0x8005A534: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_12:
    // 0x8005A538: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8005A53C: lui         $t2, 0xF800
    ctx->r10 = S32(0XF800 << 16);
    // 0x8005A540: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005A544: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8005A548: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8005A54C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8005A550: lw          $t3, -0x7CC8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7CC8);
    // 0x8005A554: lui         $at, 0x1010
    ctx->r1 = S32(0X1010 << 16);
    // 0x8005A558: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x8005A55C: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8005A560: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8005A564: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005A568: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A56C: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x8005A570: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x8005A574: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005A578: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005A57C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005A580: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005A584: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005A588: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x8005A58C: lw          $a1, -0x7C28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7C28);
    // 0x8005A590: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8005A594: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x8005A598: subu        $a2, $t4, $a1
    ctx->r6 = SUB32(ctx->r12, ctx->r5);
    // 0x8005A59C: div         $zero, $t9, $a2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r6)));
    // 0x8005A5A0: negu        $t3, $a1
    ctx->r11 = SUB32(0, ctx->r5);
    // 0x8005A5A4: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x8005A5A8: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x8005A5AC: mflo        $t0
    ctx->r8 = lo;
    // 0x8005A5B0: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8005A5B4: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8005A5B8: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x8005A5BC: mflo        $t7
    ctx->r15 = lo;
    // 0x8005A5C0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005A5C4: or          $t4, $t2, $t8
    ctx->r12 = ctx->r10 | ctx->r24;
    // 0x8005A5C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005A5CC: bne         $a2, $zero, L_8005A5D8
    if (ctx->r6 != 0) {
        // 0x8005A5D0: nop
    
            goto L_8005A5D8;
    }
    // 0x8005A5D0: nop

    // 0x8005A5D4: break       7
    do_break(2147853780);
L_8005A5D8:
    // 0x8005A5D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A5DC: bne         $a2, $at, L_8005A5F0
    if (ctx->r6 != ctx->r1) {
        // 0x8005A5E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005A5F0;
    }
    // 0x8005A5E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A5E4: bne         $t9, $at, L_8005A5F0
    if (ctx->r25 != ctx->r1) {
        // 0x8005A5E8: nop
    
            goto L_8005A5F0;
    }
    // 0x8005A5E8: nop

    // 0x8005A5EC: break       6
    do_break(2147853804);
L_8005A5F0:
    // 0x8005A5F0: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x8005A5F4: bne         $a2, $zero, L_8005A600
    if (ctx->r6 != 0) {
        // 0x8005A5F8: nop
    
            goto L_8005A600;
    }
    // 0x8005A5F8: nop

    // 0x8005A5FC: break       7
    do_break(2147853820);
L_8005A600:
    // 0x8005A600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A604: bne         $a2, $at, L_8005A618
    if (ctx->r6 != ctx->r1) {
        // 0x8005A608: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005A618;
    }
    // 0x8005A608: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A60C: bne         $t6, $at, L_8005A618
    if (ctx->r14 != ctx->r1) {
        // 0x8005A610: nop
    
            goto L_8005A618;
    }
    // 0x8005A610: nop

    // 0x8005A614: break       6
    do_break(2147853844);
L_8005A618:
    // 0x8005A618: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
L_8005A61C:
    // 0x8005A61C: jal         0x8005980C
    // 0x8005A620: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_13;
    // 0x8005A620: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_13:
    // 0x8005A624: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A628: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005A62C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8005A630: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005A634: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005A638: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005A63C: lh          $t1, 0x46($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X46);
    // 0x8005A640: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8005A644: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8005A648: lw          $t5, -0x4C0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4C0);
    // 0x8005A64C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005A650: b           L_8005AD9C
    // 0x8005A654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A658:
    // 0x8005A658: jal         0x8005980C
    // 0x8005A65C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_14;
    // 0x8005A65C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_14:
    // 0x8005A660: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A664: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A668: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A66C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005A670: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005A674: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005A678: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005A67C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005A680: lh          $t2, 0x48($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X48);
    // 0x8005A684: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8005A688: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x8005A68C: lw          $t4, -0x524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X524);
    // 0x8005A690: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005A694: b           L_8005AD9C
    // 0x8005A698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A69C:
    // 0x8005A69C: jal         0x8005980C
    // 0x8005A6A0: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_15;
    // 0x8005A6A0: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_15:
    // 0x8005A6A4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A6A8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A6AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A6B0: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005A6B4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8005A6B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005A6BC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005A6C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005A6C4: lh          $t1, 0x48($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X48);
    // 0x8005A6C8: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8005A6CC: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8005A6D0: lw          $t5, -0x4F8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4F8);
    // 0x8005A6D4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005A6D8: b           L_8005AD9C
    // 0x8005A6DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A6DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A6E0:
    // 0x8005A6E0: jal         0x8005980C
    // 0x8005A6E4: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_16;
    // 0x8005A6E4: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_16:
    // 0x8005A6E8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A6EC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A6F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A6F4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005A6F8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005A6FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005A700: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005A704: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005A708: lh          $t2, 0x48($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X48);
    // 0x8005A70C: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8005A710: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x8005A714: lw          $t4, -0x4EC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4EC);
    // 0x8005A718: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005A71C: b           L_8005AD9C
    // 0x8005A720: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A720: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A724:
    // 0x8005A724: jal         0x8005980C
    // 0x8005A728: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_17;
    // 0x8005A728: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_17:
    // 0x8005A72C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A730: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A734: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A738: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005A73C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8005A740: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005A744: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005A748: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005A74C: lh          $t1, 0x48($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X48);
    // 0x8005A750: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8005A754: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8005A758: lw          $t5, -0x4D8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4D8);
    // 0x8005A75C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005A760: b           L_8005AD9C
    // 0x8005A764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A768:
    // 0x8005A768: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A76C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A770: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A774: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x8005A778: addiu       $t2, $t2, 0x18A0
    ctx->r10 = ADD32(ctx->r10, 0X18A0);
    // 0x8005A77C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005A780: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005A784: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005A788: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005A78C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005A790: b           L_8005AD9C
    // 0x8005A794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A798:
    // 0x8005A798: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8005A79C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A7A0: beq         $v0, $at, L_8005A7B4
    if (ctx->r2 == ctx->r1) {
        // 0x8005A7A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005A7B4;
    }
    // 0x8005A7A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005A7A8: beq         $v0, $at, L_8005A7B4
    if (ctx->r2 == ctx->r1) {
        // 0x8005A7AC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005A7B4;
    }
    // 0x8005A7AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005A7B0: bne         $v0, $at, L_8005A7C4
    if (ctx->r2 != ctx->r1) {
        // 0x8005A7B4: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005A7C4;
    }
L_8005A7B4:
    // 0x8005A7B4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A7B8: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A7BC: jal         0x800B8DD0
    // 0x8005A7C0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    RCP_SetupDL(rdram, ctx);
        goto after_18;
    // 0x8005A7C0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_18:
L_8005A7C4:
    // 0x8005A7C4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A7C8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A7CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A7D0: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x8005A7D4: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8005A7D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005A7DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005A7E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005A7E4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005A7E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A7EC: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005A7F0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8005A7F4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8005A7F8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8005A7FC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005A800: lh          $t3, 0x48($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X48);
    // 0x8005A804: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8005A808: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005A80C: lw          $t6, 0x7584($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7584);
    // 0x8005A810: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005A814: b           L_8005AD9C
    // 0x8005A818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A81C:
    // 0x8005A81C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A820: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A824: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A828: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005A82C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8005A830: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005A834: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005A838: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005A83C: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x8005A840: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8005A844: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8005A848: lw          $t9, 0x7608($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7608);
    // 0x8005A84C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005A850: b           L_8005AD9C
    // 0x8005A854: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A854: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A858:
    // 0x8005A858: jal         0x8005980C
    // 0x8005A85C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_19;
    // 0x8005A85C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_19:
    // 0x8005A860: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A864: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A868: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A86C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005A870: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005A874: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8005A878: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8005A87C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005A880: lh          $t3, 0x48($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X48);
    // 0x8005A884: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8005A888: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005A88C: lw          $t6, -0x49C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49C);
    // 0x8005A890: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005A894: b           L_8005AD9C
    // 0x8005A898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A89C:
    // 0x8005A89C: jal         0x8005980C
    // 0x8005A8A0: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_20;
    // 0x8005A8A0: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_20:
    // 0x8005A8A4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A8A8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A8AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A8B0: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005A8B4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8005A8B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005A8BC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005A8C0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005A8C4: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x8005A8C8: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8005A8CC: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8005A8D0: lw          $t9, -0x478($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X478);
    // 0x8005A8D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005A8D8: b           L_8005AD9C
    // 0x8005A8DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005A8DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A8E0:
    // 0x8005A8E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A8E4: jal         0x8005980C
    // 0x8005A8E8: lwc1        $f12, 0x6118($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6118);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_21;
    // 0x8005A8E8: lwc1        $f12, 0x6118($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6118);
    after_21:
    // 0x8005A8EC: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
    // 0x8005A8F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A8F4: bne         $v1, $at, L_8005A934
    if (ctx->r3 != ctx->r1) {
        // 0x8005A8F8: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005A934;
    }
    // 0x8005A8F8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A8FC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A904: jal         0x800B8DD0
    // 0x8005A908: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_22;
    // 0x8005A908: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_22:
    // 0x8005A90C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A910: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x8005A914: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x8005A918: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8005A91C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8005A920: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8005A924: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005A928: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005A92C: b           L_8005A980
    // 0x8005A930: lw          $v1, 0x50($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X50);
        goto L_8005A980;
    // 0x8005A930: lw          $v1, 0x50($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X50);
L_8005A934:
    // 0x8005A934: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A938: bne         $v1, $at, L_8005A97C
    if (ctx->r3 != ctx->r1) {
        // 0x8005A93C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005A97C;
    }
    // 0x8005A93C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A940: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A948: jal         0x800B8DD0
    // 0x8005A94C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_23;
    // 0x8005A94C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_23:
    // 0x8005A950: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A954: lui         $t7, 0xFF00
    ctx->r15 = S32(0XFF00 << 16);
    // 0x8005A958: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x8005A95C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005A960: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005A964: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8005A968: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005A96C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005A970: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A974: jal         0x8005980C
    // 0x8005A978: lwc1        $f12, 0x611C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X611C);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_24;
    // 0x8005A978: lwc1        $f12, 0x611C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X611C);
    after_24:
L_8005A97C:
    // 0x8005A97C: lw          $v1, 0x50($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X50);
L_8005A980:
    // 0x8005A980: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005A984: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005A988: beq         $v1, $zero, L_8005A9B8
    if (ctx->r3 == 0) {
        // 0x8005A98C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005A9B8;
    }
    // 0x8005A98C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A990: beq         $v1, $at, L_8005A9E0
    if (ctx->r3 == ctx->r1) {
        // 0x8005A994: lui         $t0, 0x600
        ctx->r8 = S32(0X600 << 16);
            goto L_8005A9E0;
    }
    // 0x8005A994: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005A998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A99C: beq         $v1, $at, L_8005AA04
    if (ctx->r3 == ctx->r1) {
        // 0x8005A9A0: lui         $t5, 0x600
        ctx->r13 = S32(0X600 << 16);
            goto L_8005AA04;
    }
    // 0x8005A9A0: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005A9A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005A9A8: beq         $v1, $at, L_8005AA28
    if (ctx->r3 == ctx->r1) {
        // 0x8005A9AC: lui         $t2, 0x600
        ctx->r10 = S32(0X600 << 16);
            goto L_8005AA28;
    }
    // 0x8005A9AC: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005A9B0: b           L_8005AA48
    // 0x8005A9B4: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
        goto L_8005AA48;
    // 0x8005A9B4: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
L_8005A9B8:
    // 0x8005A9B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A9BC: lui         $t4, 0x902
    ctx->r12 = S32(0X902 << 16);
    // 0x8005A9C0: addiu       $t4, $t4, 0x34D0
    ctx->r12 = ADD32(ctx->r12, 0X34D0);
    // 0x8005A9C4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8005A9C8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8005A9CC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005A9D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005A9D4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005A9D8: b           L_8005AA48
    // 0x8005A9DC: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
        goto L_8005AA48;
    // 0x8005A9DC: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
L_8005A9E0:
    // 0x8005A9E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005A9E4: lui         $t1, 0x902
    ctx->r9 = S32(0X902 << 16);
    // 0x8005A9E8: addiu       $t1, $t1, 0x3290
    ctx->r9 = ADD32(ctx->r9, 0X3290);
    // 0x8005A9EC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005A9F0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005A9F4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005A9F8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005A9FC: b           L_8005AA48
    // 0x8005AA00: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
        goto L_8005AA48;
    // 0x8005AA00: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
L_8005AA04:
    // 0x8005AA04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AA08: lui         $t6, 0x901
    ctx->r14 = S32(0X901 << 16);
    // 0x8005AA0C: addiu       $t6, $t6, -0x2E80
    ctx->r14 = ADD32(ctx->r14, -0X2E80);
    // 0x8005AA10: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005AA14: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005AA18: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005AA1C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005AA20: b           L_8005AA48
    // 0x8005AA24: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
        goto L_8005AA48;
    // 0x8005AA24: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
L_8005AA28:
    // 0x8005AA28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AA2C: lui         $t8, 0x901
    ctx->r24 = S32(0X901 << 16);
    // 0x8005AA30: addiu       $t8, $t8, 0xFD0
    ctx->r24 = ADD32(ctx->r24, 0XFD0);
    // 0x8005AA34: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005AA38: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005AA3C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005AA40: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005AA44: lw          $v1, 0x54($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X54);
L_8005AA48:
    // 0x8005AA48: beq         $v1, $zero, L_8005AD98
    if (ctx->r3 == 0) {
        // 0x8005AA4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005AD98;
    }
    // 0x8005AA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AA50: jal         0x800B8DD0
    // 0x8005AA54: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_25;
    // 0x8005AA54: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_25:
    // 0x8005AA58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AA5C: jal         0x8005980C
    // 0x8005AA60: lwc1        $f12, 0x6120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6120);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_26;
    // 0x8005AA60: lwc1        $f12, 0x6120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6120);
    after_26:
    // 0x8005AA64: b           L_8005AD9C
    // 0x8005AA68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AA68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AA6C:
    // 0x8005AA6C: jal         0x8005980C
    // 0x8005AA70: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_27;
    // 0x8005AA70: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_27:
    // 0x8005AA74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AA78: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AA7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AA80: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8005AA84: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005AA88: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005AA8C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005AA90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005AA94: lh          $t0, 0x48($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X48);
    // 0x8005AA98: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005AA9C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8005AAA0: lw          $t3, -0x458($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X458);
    // 0x8005AAA4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005AAA8: b           L_8005AD9C
    // 0x8005AAAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AAAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AAB0:
    // 0x8005AAB0: jal         0x8005980C
    // 0x8005AAB4: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_28;
    // 0x8005AAB4: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_28:
    // 0x8005AAB8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AABC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AAC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AAC4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005AAC8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005AACC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005AAD0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005AAD4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005AAD8: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x8005AADC: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8005AAE0: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8005AAE4: lw          $t8, -0x41C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X41C);
    // 0x8005AAE8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005AAEC: b           L_8005AD9C
    // 0x8005AAF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AAF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AAF4:
    // 0x8005AAF4: jal         0x8005980C
    // 0x8005AAF8: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_29;
    // 0x8005AAF8: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_29:
    // 0x8005AAFC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AB00: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AB04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AB08: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8005AB0C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005AB10: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005AB14: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005AB18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005AB1C: lh          $t0, 0x48($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X48);
    // 0x8005AB20: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005AB24: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8005AB28: lw          $t3, -0x3F4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3F4);
    // 0x8005AB2C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005AB30: b           L_8005AD9C
    // 0x8005AB34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AB34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AB38:
    // 0x8005AB38: jal         0x8005980C
    // 0x8005AB3C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_30;
    // 0x8005AB3C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_30:
    // 0x8005AB40: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AB44: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AB48: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AB4C: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005AB50: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005AB54: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005AB58: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005AB5C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005AB60: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x8005AB64: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8005AB68: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8005AB6C: lw          $t8, -0x3C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3C0);
    // 0x8005AB70: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005AB74: b           L_8005AD9C
    // 0x8005AB78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AB78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AB7C:
    // 0x8005AB7C: jal         0x8005980C
    // 0x8005AB80: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_31;
    // 0x8005AB80: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_31:
    // 0x8005AB84: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AB88: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AB8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AB90: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8005AB94: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005AB98: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005AB9C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005ABA0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005ABA4: lh          $t0, 0x48($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X48);
    // 0x8005ABA8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005ABAC: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8005ABB0: lw          $t3, -0x3B0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3B0);
    // 0x8005ABB4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005ABB8: b           L_8005AD9C
    // 0x8005ABBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005ABBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005ABC0:
    // 0x8005ABC0: jal         0x8005980C
    // 0x8005ABC4: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_32;
    // 0x8005ABC4: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_32:
    // 0x8005ABC8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005ABCC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005ABD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005ABD4: jal         0x800B8DD0
    // 0x8005ABD8: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_33;
    // 0x8005ABD8: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_33:
    // 0x8005ABDC: jal         0x80006EB8
    // 0x8005ABE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_34;
    // 0x8005ABE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8005ABE4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005ABE8: lui         $t7, 0xBFFF
    ctx->r15 = S32(0XBFFF << 16);
    // 0x8005ABEC: ori         $t7, $t7, 0xDFFF
    ctx->r15 = ctx->r15 | 0XDFFF;
    // 0x8005ABF0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005ABF4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005ABF8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8005ABFC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005AC00: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005AC04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AC08: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005AC0C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8005AC10: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8005AC14: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8005AC18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005AC1C: lh          $t4, 0x48($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X48);
    // 0x8005AC20: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8005AC24: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8005AC28: lw          $t0, -0x39C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X39C);
    // 0x8005AC2C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8005AC30: b           L_8005AD9C
    // 0x8005AC34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AC34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AC38:
    // 0x8005AC38: jal         0x8005980C
    // 0x8005AC3C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_35;
    // 0x8005AC3C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_35:
    // 0x8005AC40: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AC44: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AC48: jal         0x80006EB8
    // 0x8005AC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_36;
    // 0x8005AC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8005AC50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AC54: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x8005AC58: addiu       $t5, $t5, 0x48B0
    ctx->r13 = ADD32(ctx->r13, 0X48B0);
    // 0x8005AC5C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005AC60: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8005AC64: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8005AC68: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005AC6C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005AC70: b           L_8005AD9C
    // 0x8005AC74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AC74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AC78:
    // 0x8005AC78: jal         0x8005980C
    // 0x8005AC7C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_37;
    // 0x8005AC7C: lwc1        $f12, 0x110($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X110);
    after_37:
    // 0x8005AC80: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AC84: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AC88: jal         0x80006EB8
    // 0x8005AC8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_38;
    // 0x8005AC8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8005AC90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AC94: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005AC98: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005AC9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005ACA0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005ACA4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005ACA8: lh          $t2, 0x48($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X48);
    // 0x8005ACAC: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8005ACB0: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x8005ACB4: lw          $t4, -0x384($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X384);
    // 0x8005ACB8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005ACBC: b           L_8005AD9C
    // 0x8005ACC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005ACC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005ACC4:
    // 0x8005ACC4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005ACC8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005ACCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005ACD0: lui         $t1, 0x101
    ctx->r9 = S32(0X101 << 16);
    // 0x8005ACD4: addiu       $t1, $t1, 0x77C0
    ctx->r9 = ADD32(ctx->r9, 0X77C0);
    // 0x8005ACD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005ACDC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005ACE0: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005ACE4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005ACE8: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005ACEC: b           L_8005AD9C
    // 0x8005ACF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005ACF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005ACF4:
    // 0x8005ACF4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005ACF8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005ACFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AD00: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005AD04: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005AD08: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005AD0C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005AD10: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005AD14: lh          $t6, 0x48($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X48);
    // 0x8005AD18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005AD1C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8005AD20: lw          $t2, -0x5FF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5FF8);
    // 0x8005AD24: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005AD28: b           L_8005AD9C
    // 0x8005AD2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005AD9C;
    // 0x8005AD2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AD30:
    // 0x8005AD30: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8005AD34: bne         $at, $zero, L_8005AD98
    if (ctx->r1 != 0) {
        // 0x8005AD38: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_8005AD98;
    }
    // 0x8005AD38: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x8005AD3C: bne         $v0, $at, L_8005AD64
    if (ctx->r2 != ctx->r1) {
        // 0x8005AD40: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005AD64;
    }
    // 0x8005AD40: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AD44: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AD48: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AD4C: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x8005AD50: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8005AD54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005AD58: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005AD5C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005AD60: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005AD64:
    // 0x8005AD64: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005AD68: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005AD6C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005AD70: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005AD74: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005AD78: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8005AD7C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8005AD80: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005AD84: lh          $t3, 0xB8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XB8);
    // 0x8005AD88: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8005AD8C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005AD90: lw          $t6, -0x5D4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5D4);
    // 0x8005AD94: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8005AD98:
    // 0x8005AD98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005AD9C:
    // 0x8005AD9C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ADA0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005ADA4: jr          $ra
    // 0x8005ADA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005ADA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void RCP_SetupDL_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9A20: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9A24: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9A28: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B9A2C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9A30: addiu       $t8, $t8, 0x3DC8
    ctx->r24 = ADD32(ctx->r24, 0X3DC8);
    // 0x800B9A34: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9A38: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B9A3C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9A40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B9A44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B9A48: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B9A4C: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B9A50: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B9A54: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B9A58: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B9A5C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B9A60: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B9A64: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B9A68: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B9A6C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B9A70: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B9A74: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B9A78: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B9A7C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B9A80: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B9A84: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B9A88: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B9A8C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9A90: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B9A94: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9A98: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B9A9C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9AA0: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B9AA4: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9AA8: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B9AAC: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9AB0: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B9AB4: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9AB8: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9ABC: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9AC0: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B9AC4: bne         $t2, $zero, L_800B9AD0
    if (ctx->r10 != 0) {
        // 0x800B9AC8: nop
    
            goto L_800B9AD0;
    }
    // 0x800B9AC8: nop

    // 0x800B9ACC: break       7
    do_break(2148244172);
L_800B9AD0:
    // 0x800B9AD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9AD4: bne         $t2, $at, L_800B9AE8
    if (ctx->r10 != ctx->r1) {
        // 0x800B9AD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9AE8;
    }
    // 0x800B9AD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9ADC: bne         $t6, $at, L_800B9AE8
    if (ctx->r14 != ctx->r1) {
        // 0x800B9AE0: nop
    
            goto L_800B9AE8;
    }
    // 0x800B9AE0: nop

    // 0x800B9AE4: break       6
    do_break(2148244196);
L_800B9AE8:
    // 0x800B9AE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B9AEC: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B9AF0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B9AF4: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B9AF8: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B9AFC: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9B00: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B9B04: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9B08: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B9B0C: bne         $t2, $zero, L_800B9B18
    if (ctx->r10 != 0) {
        // 0x800B9B10: nop
    
            goto L_800B9B18;
    }
    // 0x800B9B10: nop

    // 0x800B9B14: break       7
    do_break(2148244244);
L_800B9B18:
    // 0x800B9B18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9B1C: bne         $t2, $at, L_800B9B30
    if (ctx->r10 != ctx->r1) {
        // 0x800B9B20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9B30;
    }
    // 0x800B9B20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9B24: bne         $t8, $at, L_800B9B30
    if (ctx->r24 != ctx->r1) {
        // 0x800B9B28: nop
    
            goto L_800B9B30;
    }
    // 0x800B9B28: nop

    // 0x800B9B2C: break       6
    do_break(2148244268);
L_800B9B30:
    // 0x800B9B30: jr          $ra
    // 0x800B9B34: nop

    return;
    // 0x800B9B34: nop

;}
RECOMP_FUNC void Audio_KillSfxByBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A290: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001A294: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8001A298: andi        $s7, $a0, 0xFF
    ctx->r23 = ctx->r4 & 0XFF;
    // 0x8001A29C: sll         $t6, $s7, 4
    ctx->r14 = S32(ctx->r23 << 4);
    // 0x8001A2A0: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8001A2A4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001A2A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001A2AC: addiu       $t7, $t7, -0x79A0
    ctx->r15 = ADD32(ctx->r15, -0X79A0);
    // 0x8001A2B0: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x8001A2B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A2B8: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A2BC: lbu         $s1, 0x2B($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0X2B);
    // 0x8001A2C0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001A2C4: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x8001A2C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001A2CC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8001A2D0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001A2D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001A2D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A2DC: beq         $s4, $s1, L_8001A34C
    if (ctx->r20 == ctx->r17) {
        // 0x8001A2E0: sw          $a0, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r4;
            goto L_8001A34C;
    }
    // 0x8001A2E0: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8001A2E4: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x8001A2E8: subu        $t8, $t8, $s7
    ctx->r24 = SUB32(ctx->r24, ctx->r23);
    // 0x8001A2EC: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x8001A2F0: addu        $s3, $t8, $t7
    ctx->r19 = ADD32(ctx->r24, ctx->r15);
    // 0x8001A2F4: lui         $s6, 0x602
    ctx->r22 = S32(0X602 << 16);
    // 0x8001A2F8: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
L_8001A2FC:
    // 0x8001A2FC: multu       $s1, $s5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A300: mflo        $t9
    ctx->r25 = lo;
    // 0x8001A304: addu        $s0, $s3, $t9
    ctx->r16 = ADD32(ctx->r19, ctx->r25);
    // 0x8001A308: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x8001A30C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001A310: bne         $at, $zero, L_8001A330
    if (ctx->r1 != 0) {
        // 0x8001A314: nop
    
            goto L_8001A330;
    }
    // 0x8001A314: nop

    // 0x8001A318: lbu         $t1, 0x2C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001A31C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A320: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8001A324: jal         0x8001E8F0
    // 0x8001A328: or          $a0, $t2, $s6
    ctx->r4 = ctx->r10 | ctx->r22;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001A328: or          $a0, $t2, $s6
    ctx->r4 = ctx->r10 | ctx->r22;
    after_0:
    // 0x8001A32C: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_8001A330:
    // 0x8001A330: beq         $v0, $zero, L_8001A340
    if (ctx->r2 == 0) {
        // 0x8001A334: andi        $a0, $s7, 0xFF
        ctx->r4 = ctx->r23 & 0XFF;
            goto L_8001A340;
    }
    // 0x8001A334: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x8001A338: jal         0x800197AC
    // 0x8001A33C: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_1;
    // 0x8001A33C: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
L_8001A340:
    // 0x8001A340: lbu         $s1, 0x2B($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0X2B);
    // 0x8001A344: bne         $s4, $s1, L_8001A2FC
    if (ctx->r20 != ctx->r17) {
        // 0x8001A348: nop
    
            goto L_8001A2FC;
    }
    // 0x8001A348: nop

L_8001A34C:
    // 0x8001A34C: sll         $t3, $s7, 28
    ctx->r11 = S32(ctx->r23 << 28);
    // 0x8001A350: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8001A354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A358: jal         0x80019290
    // 0x8001A35C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    Audio_RemoveMatchingSfxRequests(rdram, ctx);
        goto after_2;
    // 0x8001A35C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x8001A360: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A364: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001A368: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001A36C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A370: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001A374: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001A378: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001A37C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A380: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8001A384: jr          $ra
    // 0x8001A388: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001A388: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void HUD_Texture_Wave(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C104: addiu       $sp, $sp, -0x898
    ctx->r29 = ADD32(ctx->r29, -0X898);
    // 0x8008C108: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8008C10C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008C110: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8008C114: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8008C118: addiu       $v0, $v0, 0x1FD0
    ctx->r2 = ADD32(ctx->r2, 0X1FD0);
    // 0x8008C11C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8008C120: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8008C124: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8008C128: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8008C12C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8008C130: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8008C134: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8008C138: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8008C13C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8008C140: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8008C144: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8008C148: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8008C14C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8008C150: sll         $t4, $s0, 4
    ctx->r12 = S32(ctx->r16 << 4);
    // 0x8008C154: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008C158: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x8008C15C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8008C160: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008C164: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8008C168: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8008C16C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8008C170: and         $t2, $a0, $v1
    ctx->r10 = ctx->r4 & ctx->r3;
    // 0x8008C174: and         $t9, $s0, $v1
    ctx->r25 = ctx->r16 & ctx->r3;
    // 0x8008C178: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8008C17C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8008C180: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8008C184: addu        $s2, $t3, $t0
    ctx->r18 = ADD32(ctx->r11, ctx->r8);
    // 0x8008C188: sw          $t2, 0x890($sp)
    MEM_W(0X890, ctx->r29) = ctx->r10;
    // 0x8008C18C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8008C190: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8008C194: jal         0x80099A2C
    // 0x8008C198: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_0;
    // 0x8008C198: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8008C19C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8008C1A0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8008C1A4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8008C1A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008C1AC: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008C1B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008C1B4: lwc1        $f26, 0x7D80($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X7D80);
    // 0x8008C1B8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8008C1BC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8008C1C0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8008C1C4: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    // 0x8008C1C8: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
    // 0x8008C1CC: div.s       $f28, $f6, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f28.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8008C1D0: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x8008C1D4: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x8008C1D8: nop

    // 0x8008C1DC: bc1tl       L_8008C354
    if (c1cs) {
        // 0x8008C1E0: lw          $a0, 0x890($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X890);
            goto L_8008C354;
    }
    goto skip_0;
    // 0x8008C1E0: lw          $a0, 0x890($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X890);
    skip_0:
L_8008C1E4:
    // 0x8008C1E4: mul.s       $f12, $f26, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8008C1E8: jal         0x80023250
    // 0x8008C1EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8008C1EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x8008C1F0: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8008C1F4: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x8008C1F8: sll         $t6, $s3, 6
    ctx->r14 = S32(ctx->r19 << 6);
    // 0x8008C1FC: addiu       $t7, $sp, 0x90
    ctx->r15 = ADD32(ctx->r29, 0X90);
    // 0x8008C200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008C204: sll         $a1, $s0, 1
    ctx->r5 = S32(ctx->r16 << 1);
    // 0x8008C208: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8008C20C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8008C210: nop

    // 0x8008C214: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8008C218: bne         $at, $zero, L_8008C224
    if (ctx->r1 != 0) {
        // 0x8008C21C: nop
    
            goto L_8008C224;
    }
    // 0x8008C21C: nop

    // 0x8008C220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8008C224:
    // 0x8008C224: b           L_8008C258
    // 0x8008C228: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
        goto L_8008C258;
    // 0x8008C228: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8008C22C: sll         $t9, $a2, 6
    ctx->r25 = S32(ctx->r6 << 6);
    // 0x8008C230: addu        $t1, $s2, $t9
    ctx->r9 = ADD32(ctx->r18, ctx->r25);
    // 0x8008C234: addu        $v1, $t1, $a1
    ctx->r3 = ADD32(ctx->r9, ctx->r5);
    // 0x8008C238: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_8008C23C:
    // 0x8008C23C: lhu         $t2, 0x0($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X0);
    // 0x8008C240: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008C244: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8008C248: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8008C24C: bne         $a0, $s0, L_8008C23C
    if (ctx->r4 != ctx->r16) {
        // 0x8008C250: sh          $t2, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r10;
            goto L_8008C23C;
    }
    // 0x8008C250: sh          $t2, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r10;
    // 0x8008C254: beq         $s0, $s1, L_8008C29C
    if (ctx->r16 == ctx->r17) {
        // 0x8008C258: sll         $a1, $s0, 1
        ctx->r5 = S32(ctx->r16 << 1);
            goto L_8008C29C;
    }
L_8008C258:
    // 0x8008C258: sll         $a1, $s0, 1
    ctx->r5 = S32(ctx->r16 << 1);
    // 0x8008C25C: sll         $t4, $a2, 6
    ctx->r12 = S32(ctx->r6 << 6);
    // 0x8008C260: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8008C264: addu        $v1, $t5, $a1
    ctx->r3 = ADD32(ctx->r13, ctx->r5);
    // 0x8008C268: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_8008C26C:
    // 0x8008C26C: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8008C270: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008C274: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8008C278: sh          $t6, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r14;
    // 0x8008C27C: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x8008C280: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8008C284: sh          $t7, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r15;
    // 0x8008C288: lhu         $t8, -0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, -0X4);
    // 0x8008C28C: sh          $t8, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r24;
    // 0x8008C290: lhu         $t9, -0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, -0X2);
    // 0x8008C294: bne         $s0, $s1, L_8008C26C
    if (ctx->r16 != ctx->r17) {
        // 0x8008C298: sh          $t9, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r25;
            goto L_8008C26C;
    }
    // 0x8008C298: sh          $t9, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r25;
L_8008C29C:
    // 0x8008C29C: negu        $t2, $s3
    ctx->r10 = SUB32(0, ctx->r19);
    // 0x8008C2A0: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8008C2A4: addiu       $t4, $t3, 0x7C0
    ctx->r12 = ADD32(ctx->r11, 0X7C0);
    // 0x8008C2A8: addiu       $t5, $sp, 0x90
    ctx->r13 = ADD32(ctx->r29, 0X90);
    // 0x8008C2AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008C2B0: b           L_8008C2F4
    // 0x8008C2B4: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
        goto L_8008C2F4;
    // 0x8008C2B4: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x8008C2B8: negu        $t7, $a2
    ctx->r15 = SUB32(0, ctx->r6);
    // 0x8008C2BC: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8008C2C0: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8008C2C4: sll         $a1, $zero, 1
    ctx->r5 = S32(0 << 1);
    // 0x8008C2C8: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x8008C2CC: addiu       $v1, $v1, 0x7C0
    ctx->r3 = ADD32(ctx->r3, 0X7C0);
    // 0x8008C2D0: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
    // 0x8008C2D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008C2D8:
    // 0x8008C2D8: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x8008C2DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008C2E0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8008C2E4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8008C2E8: bne         $a0, $s0, L_8008C2D8
    if (ctx->r4 != ctx->r16) {
        // 0x8008C2EC: sh          $t1, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r9;
            goto L_8008C2D8;
    }
    // 0x8008C2EC: sh          $t1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r9;
    // 0x8008C2F0: beq         $s0, $s1, L_8008C340
    if (ctx->r16 == ctx->r17) {
        // 0x8008C2F4: negu        $t3, $a2
        ctx->r11 = SUB32(0, ctx->r6);
            goto L_8008C340;
    }
L_8008C2F4:
    // 0x8008C2F4: negu        $t3, $a2
    ctx->r11 = SUB32(0, ctx->r6);
    // 0x8008C2F8: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8008C2FC: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8008C300: sll         $a1, $s0, 1
    ctx->r5 = S32(ctx->r16 << 1);
    // 0x8008C304: addu        $v1, $t5, $a1
    ctx->r3 = ADD32(ctx->r13, ctx->r5);
    // 0x8008C308: addiu       $v1, $v1, 0x7C0
    ctx->r3 = ADD32(ctx->r3, 0X7C0);
    // 0x8008C30C: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_8008C310:
    // 0x8008C310: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8008C314: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008C318: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8008C31C: sh          $t6, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r14;
    // 0x8008C320: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x8008C324: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8008C328: sh          $t7, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r15;
    // 0x8008C32C: lhu         $t8, -0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, -0X4);
    // 0x8008C330: sh          $t8, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r24;
    // 0x8008C334: lhu         $t9, -0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, -0X2);
    // 0x8008C338: bne         $s0, $s1, L_8008C310
    if (ctx->r16 != ctx->r17) {
        // 0x8008C33C: sh          $t9, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r25;
            goto L_8008C310;
    }
    // 0x8008C33C: sh          $t9, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r25;
L_8008C340:
    // 0x8008C340: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x8008C344: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8008C348: bc1f        L_8008C1E4
    if (!c1cs) {
        // 0x8008C34C: nop
    
            goto L_8008C1E4;
    }
    // 0x8008C34C: nop

    // 0x8008C350: lw          $a0, 0x890($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X890);
L_8008C354:
    // 0x8008C354: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8008C358: jal         0x80099E28
    // 0x8008C35C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Lib_Texture_Mottle(rdram, ctx);
        goto after_2;
    // 0x8008C35C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x8008C360: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8008C364: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8008C368: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8008C36C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8008C370: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8008C374: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8008C378: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8008C37C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8008C380: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x8008C384: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x8008C388: jr          $ra
    // 0x8008C38C: addiu       $sp, $sp, 0x898
    ctx->r29 = ADD32(ctx->r29, 0X898);
    return;
    // 0x8008C38C: addiu       $sp, $sp, 0x898
    ctx->r29 = ADD32(ctx->r29, 0X898);
;}
RECOMP_FUNC void AudioSeq_ResetSequencePlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016804: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80016808: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001680C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80016810: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80016814: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80016818: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001681C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80016820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016824: addiu       $t7, $t7, -0x1AC8
    ctx->r15 = ADD32(ctx->r15, -0X1AC8);
    // 0x80016828: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001682C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016830: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80016834: jal         0x800144E4
    // 0x80016838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_0;
    // 0x80016838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001683C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80016840: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016844: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016848: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001684C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80016850: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016854: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80016858: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8001685C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80016860: addiu       $t9, $zero, 0x1680
    ctx->r25 = ADD32(0, 0X1680);
    // 0x80016864: addiu       $t0, $t0, -0x2ED0
    ctx->r8 = ADD32(ctx->r8, -0X2ED0);
    // 0x80016868: addiu       $t1, $t1, -0x2EC0
    ctx->r9 = ADD32(ctx->r9, -0X2EC0);
    // 0x8001686C: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80016870: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
    // 0x80016874: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x80016878: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x8001687C: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80016880: sh          $t9, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r25;
    // 0x80016884: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80016888: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x8001688C: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80016890: sw          $t0, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r8;
    // 0x80016894: sw          $t1, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r9;
    // 0x80016898: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001689C: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x800168A0: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x800168A4: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x800168A8: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x800168AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800168B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800168B4: jr          $ra
    // 0x800168B8: nop

    return;
    // 0x800168B8: nop

;}
RECOMP_FUNC void Effect_Effect360_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007BE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BE5C: lh          $t6, 0x4A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4A);
    // 0x8007BE60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BE64: lwc1        $f6, 0x7400($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7400);
    // 0x8007BE68: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007BE6C: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x8007BE70: sh          $t7, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r15;
    // 0x8007BE74: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007BE78: lh          $t8, 0x4A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4A);
    // 0x8007BE7C: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007BE80: bgez        $t8, L_8007BE94
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007BE84: swc1        $f8, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
            goto L_8007BE94;
    }
    // 0x8007BE84: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8007BE88: jal         0x80060FBC
    // 0x8007BE8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007BE8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007BE90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007BE94:
    // 0x8007BE94: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
    // 0x8007BE98: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8007BE9C: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8007BEA0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8007BEA4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8007BEA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007BEAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007BEB0: lwc1        $f10, 0xC8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x8007BEB4: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007BEB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BEBC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8007BEC0: lwc1        $f16, 0x58($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007BEC4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8007BEC8: swc1        $f18, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f18.u32l;
    // 0x8007BECC: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x8007BED0: lwc1        $f18, 0x7404($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7404);
    // 0x8007BED4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007BED8: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x8007BEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BEE0: jr          $ra
    // 0x8007BEE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007BEE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_demo_8004D3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D3C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8004D3CC: jr          $ra
    // 0x8004D3D0: nop

    return;
    // 0x8004D3D0: nop

;}
RECOMP_FUNC void Cutscene_PathTexScroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004990C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80049910: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x80049914: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80049918: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x8004991C: bne         $t6, $zero, L_80049938
    if (ctx->r14 != 0) {
        // 0x80049920: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80049938;
    }
    // 0x80049920: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80049924: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80049928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004992C: nop

    // 0x80049930: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80049934: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80049938:
    // 0x80049938: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8004993C: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80049940: lwc1        $f4, 0xEC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x80049944: lwc1        $f6, 0x12C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x80049948: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004994C: lwc1        $f10, 0x130($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X130);
    // 0x80049950: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80049954: swc1        $f18, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f18.u32l;
    // 0x80049958: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004995C: swc1        $f16, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f16.u32l;
    // 0x80049960: jr          $ra
    // 0x80049964: nop

    return;
    // 0x80049964: nop

;}
RECOMP_FUNC void ActorAllRange_CheckActorInFrontXZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031900: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80031904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031908: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003190C: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80031910: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80031914: lwc1        $f8, 0x4EF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4EF4);
    // 0x80031918: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8003191C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80031920: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80031924: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80031928: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8003192C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031930: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80031934: jal         0x80005E90
    // 0x80031938: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80031938: nop

    after_0:
    // 0x8003193C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80031940: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80031944: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80031948: lwc1        $f16, 0x124($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X124);
    // 0x8003194C: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80031950: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80031954: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80031958: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003195C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80031960: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80031964: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80031968: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003196C: lwc1        $f8, 0x12C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X12C);
    // 0x80031970: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80031974: jal         0x80006A20
    // 0x80031978: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x80031978: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8003197C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80031980: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80031984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003198C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80031990: nop

    // 0x80031994: bc1f        L_800319A4
    if (!c1cs) {
        // 0x80031998: nop
    
            goto L_800319A4;
    }
    // 0x80031998: nop

    // 0x8003199C: b           L_800319A4
    // 0x800319A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800319A4;
    // 0x800319A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800319A4:
    // 0x800319A4: jr          $ra
    // 0x800319A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800319A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void AudioHeap_DiscardSampleCaches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E290: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8000E294: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000E298: lw          $t6, 0x5C60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C60);
    // 0x8000E29C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000E2A0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000E2A4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000E2A8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000E2AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000E2B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000E2B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000E2B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000E2BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000E2C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000E2C4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8000E2C8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000E2CC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000E2D0: blez        $t7, L_8000E464
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000E2D4: sw          $t7, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r15;
            goto L_8000E464;
    }
    // 0x8000E2D4: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x8000E2D8: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x8000E2DC: addiu       $s6, $s6, 0x5C70
    ctx->r22 = ADD32(ctx->r22, 0X5C70);
    // 0x8000E2E0: addiu       $s7, $zero, 0x7F
    ctx->r23 = ADD32(0, 0X7F);
    // 0x8000E2E4: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
L_8000E2E8:
    // 0x8000E2E8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8000E2EC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000E2F0: addu        $v0, $t8, $s5
    ctx->r2 = ADD32(ctx->r24, ctx->r21);
    // 0x8000E2F4: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x8000E2F8: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x8000E2FC: lb          $a1, 0x2($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X2);
    // 0x8000E300: beql        $v1, $at, L_8000E310
    if (ctx->r3 == ctx->r1) {
        // 0x8000E304: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8000E310;
    }
    goto skip_0;
    // 0x8000E304: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    skip_0:
    // 0x8000E308: beq         $v1, $a1, L_8000E324
    if (ctx->r3 == ctx->r5) {
        // 0x8000E30C: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8000E324;
    }
    // 0x8000E30C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
L_8000E310:
    // 0x8000E310: beq         $a0, $at, L_8000E320
    if (ctx->r4 == ctx->r1) {
        // 0x8000E314: nop
    
            goto L_8000E320;
    }
    // 0x8000E314: nop

    // 0x8000E318: beql        $a0, $a1, L_8000E328
    if (ctx->r4 == ctx->r5) {
        // 0x8000E31C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000E328;
    }
    goto skip_1;
    // 0x8000E31C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_1:
L_8000E320:
    // 0x8000E320: bne         $a1, $zero, L_8000E450
    if (ctx->r5 != 0) {
        // 0x8000E324: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000E450;
    }
L_8000E324:
    // 0x8000E324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000E328:
    // 0x8000E328: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8000E32C: jal         0x8000C990
    // 0x8000E330: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    AudioHeap_SearchCaches(rdram, ctx);
        goto after_0;
    // 0x8000E330: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x8000E334: beq         $v0, $zero, L_8000E450
    if (ctx->r2 == 0) {
        // 0x8000E338: lui         $t0, 0x8015
        ctx->r8 = S32(0X8015 << 16);
            goto L_8000E450;
    }
    // 0x8000E338: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000E33C: addu        $t0, $t0, $s4
    ctx->r8 = ADD32(ctx->r8, ctx->r20);
    // 0x8000E340: lbu         $t0, -0x2C18($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X2C18);
    // 0x8000E344: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000E348: slti        $t1, $t0, 0x2
    ctx->r9 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x8000E34C: bnel        $t1, $zero, L_8000E454
    if (ctx->r9 != 0) {
        // 0x8000E350: lw          $t3, 0x64($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X64);
            goto L_8000E454;
    }
    goto skip_2;
    // 0x8000E350: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x8000E354: lw          $t2, -0x31B0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X31B0);
    // 0x8000E358: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8000E35C: blezl       $t2, L_8000E454
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8000E360: lw          $t3, 0x64($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X64);
            goto L_8000E454;
    }
    goto skip_3;
    // 0x8000E360: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    skip_3:
    // 0x8000E364: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x8000E368: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000E36C: addiu       $s3, $s3, -0x36B0
    ctx->r19 = ADD32(ctx->r19, -0X36B0);
    // 0x8000E370: addu        $v0, $t3, $s5
    ctx->r2 = ADD32(ctx->r11, ctx->r21);
    // 0x8000E374: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
L_8000E378:
    // 0x8000E378: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E37C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000E380: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000E384: blez        $t4, L_8000E3F4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000E388: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E3F4;
    }
    // 0x8000E388: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000E38C:
    // 0x8000E38C: jal         0x80011D4C
    // 0x8000E390: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Audio_GetInstrument(rdram, ctx);
        goto after_1;
    // 0x8000E390: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8000E394: beq         $v0, $zero, L_8000E3D8
    if (ctx->r2 == 0) {
        // 0x8000E398: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000E3D8;
    }
    // 0x8000E398: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000E39C: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x8000E3A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000E3A4: beql        $t5, $zero, L_8000E3B8
    if (ctx->r13 == 0) {
        // 0x8000E3A8: lbu         $t6, 0x2($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X2);
            goto L_8000E3B8;
    }
    goto skip_4;
    // 0x8000E3A8: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    skip_4:
    // 0x8000E3AC: jal         0x8000E1C4
    // 0x8000E3B0: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_2;
    // 0x8000E3B0: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    after_2:
    // 0x8000E3B4: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
L_8000E3B8:
    // 0x8000E3B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000E3BC: beql        $s7, $t6, L_8000E3D0
    if (ctx->r23 == ctx->r14) {
        // 0x8000E3C0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8000E3D0;
    }
    goto skip_5;
    // 0x8000E3C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_5:
    // 0x8000E3C4: jal         0x8000E1C4
    // 0x8000E3C8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_3;
    // 0x8000E3C8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_3:
    // 0x8000E3CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8000E3D0:
    // 0x8000E3D0: jal         0x8000E1C4
    // 0x8000E3D4: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_4;
    // 0x8000E3D4: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_4:
L_8000E3D8:
    // 0x8000E3D8: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8000E3DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000E3E0: addu        $v0, $t7, $s5
    ctx->r2 = ADD32(ctx->r15, ctx->r21);
    // 0x8000E3E4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E3E8: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000E3EC: bnel        $at, $zero, L_8000E38C
    if (ctx->r1 != 0) {
        // 0x8000E3F0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E38C;
    }
    goto skip_6;
    // 0x8000E3F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_6:
L_8000E3F4:
    // 0x8000E3F4: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8000E3F8: blez        $t9, L_8000E434
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8000E3FC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E434;
    }
    // 0x8000E3FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000E400:
    // 0x8000E400: jal         0x80011DFC
    // 0x8000E404: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Audio_GetDrum(rdram, ctx);
        goto after_5;
    // 0x8000E404: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8000E408: beq         $v0, $zero, L_8000E418
    if (ctx->r2 == 0) {
        // 0x8000E40C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8000E418;
    }
    // 0x8000E40C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000E410: jal         0x8000E1C4
    // 0x8000E414: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_6;
    // 0x8000E414: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_6:
L_8000E418:
    // 0x8000E418: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x8000E41C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000E420: addu        $v0, $t0, $s5
    ctx->r2 = ADD32(ctx->r8, ctx->r21);
    // 0x8000E424: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x8000E428: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000E42C: bnel        $at, $zero, L_8000E400
    if (ctx->r1 != 0) {
        // 0x8000E430: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E400;
    }
    goto skip_7;
    // 0x8000E430: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_7:
L_8000E434:
    // 0x8000E434: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000E438: lw          $t2, -0x31B0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X31B0);
    // 0x8000E43C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8000E440: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
    // 0x8000E444: slt         $at, $fp, $t2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000E448: bnel        $at, $zero, L_8000E378
    if (ctx->r1 != 0) {
        // 0x8000E44C: sw          $s3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r19;
            goto L_8000E378;
    }
    goto skip_8;
    // 0x8000E44C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    skip_8:
L_8000E450:
    // 0x8000E450: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
L_8000E454:
    // 0x8000E454: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000E458: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x8000E45C: bnel        $s4, $t3, L_8000E2E8
    if (ctx->r20 != ctx->r11) {
        // 0x8000E460: lw          $t8, 0x0($s6)
        ctx->r24 = MEM_W(ctx->r22, 0X0);
            goto L_8000E2E8;
    }
    goto skip_9;
    // 0x8000E460: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    skip_9:
L_8000E464:
    // 0x8000E464: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E468: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E46C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E470: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000E474: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000E478: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000E47C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E480: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000E484: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000E488: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000E48C: jr          $ra
    // 0x8000E490: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8000E490: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void RCP_SetupDL_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8FD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8FDC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B8FE0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8FE4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B8FE8: addiu       $t8, $t8, 0x3240
    ctx->r24 = ADD32(ctx->r24, 0X3240);
    // 0x800B8FEC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B8FF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8FF4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B8FF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B8FFC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9000: jr          $ra
    // 0x800B9004: nop

    return;
    // 0x800B9004: nop

;}
RECOMP_FUNC void __lnearbyintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001FF80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001FF84: nop

    // 0x8001FF88: add.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8001FF8C: floor.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floorf(ctx->f0.fl));
    // 0x8001FF90: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001FF94: jr          $ra
    // 0x8001FF98: nop

    return;
    // 0x8001FF98: nop

;}
