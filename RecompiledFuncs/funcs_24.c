#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_enmy2_8006A800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A800: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A804: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A808: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006A80C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A810: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006A814: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006A818: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006A81C: jal         0x80061474
    // 0x8006A820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006A820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006A824: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006A828: addiu       $t7, $zero, 0x169
    ctx->r15 = ADD32(0, 0X169);
    // 0x8006A82C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006A830: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8006A834: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006A838: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8006A83C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8006A840: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006A844: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8006A848: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A84C: sh          $t8, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r24;
    // 0x8006A850: jal         0x80004EB0
    // 0x8006A854: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8006A854: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8006A858: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006A85C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006A860: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8006A864: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006A868: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8006A86C: nop

    // 0x8006A870: bc1fl       L_8006A888
    if (!c1cs) {
        // 0x8006A874: lwc1        $f0, 0x30($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
            goto L_8006A888;
    }
    goto skip_0;
    // 0x8006A874: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8006A878: lh          $t9, 0x48($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X48);
    // 0x8006A87C: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8006A880: sh          $t0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r8;
    // 0x8006A884: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
L_8006A888:
    // 0x8006A888: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x8006A88C: sh          $t1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r9;
    // 0x8006A890: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8006A894: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006A898: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8006A89C: lwc1        $f4, 0x6A78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A78);
    // 0x8006A8A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006A8A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006A8A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006A8AC: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x8006A8B0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8006A8B4: nop

    // 0x8006A8B8: bc1f        L_8006A8C8
    if (!c1cs) {
        // 0x8006A8BC: nop
    
            goto L_8006A8C8;
    }
    // 0x8006A8BC: nop

    // 0x8006A8C0: lwc1        $f8, 0x6A7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A7C);
    // 0x8006A8C4: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
L_8006A8C8:
    // 0x8006A8C8: jal         0x80004EB0
    // 0x8006A8CC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8006A8CC: nop

    after_2:
    // 0x8006A8D0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8006A8D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006A8D8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8006A8DC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8006A8E0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8006A8E4: jal         0x800612B8
    // 0x8006A8E8: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8006A8E8: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x8006A8EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A8F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006A8F8: jr          $ra
    // 0x8006A8FC: nop

    return;
    // 0x8006A8FC: nop

;}
RECOMP_FUNC void Effect_Effect375_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DA58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007DA5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007DA60: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8007DA64: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007DA68: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007DA6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DA70: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8007DA74: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007DA78: bc1f        L_8007DA94
    if (!c1cs) {
        // 0x8007DA7C: swc1        $f6, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
            goto L_8007DA94;
    }
    // 0x8007DA7C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8007DA80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DA84: lwc1        $f10, 0x7448($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7448);
    // 0x8007DA88: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8007DA8C: b           L_8007DAA0
    // 0x8007DA90: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
        goto L_8007DAA0;
    // 0x8007DA90: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
L_8007DA94:
    // 0x8007DA94: lwc1        $f18, 0x744C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X744C);
    // 0x8007DA98: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8007DA9C: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
L_8007DAA0:
    // 0x8007DAA0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8007DAA4: lwc1        $f8, 0x64($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X64);
    // 0x8007DAA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DAAC: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007DAB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007DAB4: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8007DAB8: lwc1        $f18, 0x7450($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7450);
    // 0x8007DABC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8007DAC0: nop

    // 0x8007DAC4: bc1fl       L_8007DAD8
    if (!c1cs) {
        // 0x8007DAC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007DAD8;
    }
    goto skip_0;
    // 0x8007DAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007DACC: jal         0x80060FBC
    // 0x8007DAD0: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007DAD0: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x8007DAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007DAD8:
    // 0x8007DAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007DADC: jr          $ra
    // 0x8007DAE0: nop

    return;
    // 0x8007DAE0: nop

;}
RECOMP_FUNC void func_tank_80046260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046260: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80046264: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80046268: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8004626C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80046270: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80046274: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80046278: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8004627C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80046280: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80046284: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80046288: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8004628C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80046290: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80046294: addiu       $s0, $s0, 0x1B00
    ctx->r16 = ADD32(ctx->r16, 0X1B00);
    // 0x80046298: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004629C: addiu       $s5, $zero, 0x32
    ctx->r21 = ADD32(0, 0X32);
    // 0x800462A0: addiu       $s4, $zero, 0x3A
    ctx->r20 = ADD32(0, 0X3A);
    // 0x800462A4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_800462A8:
    // 0x800462A8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800462AC: bnel        $s3, $t6, L_80046328
    if (ctx->r19 != ctx->r14) {
        // 0x800462B0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80046328;
    }
    goto skip_0;
    // 0x800462B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800462B4: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x800462B8: bnel        $s4, $t7, L_80046328
    if (ctx->r20 != ctx->r15) {
        // 0x800462BC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80046328;
    }
    goto skip_1;
    // 0x800462BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800462C0: lwc1        $f4, 0x138($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X138);
    // 0x800462C4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800462C8: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800462CC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800462D0: nop

    // 0x800462D4: bc1fl       L_80046328
    if (!c1cs) {
        // 0x800462D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80046328;
    }
    goto skip_2;
    // 0x800462D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800462DC: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800462E0: lwc1        $f8, 0x78($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X78);
    // 0x800462E4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800462E8: nop

    // 0x800462EC: bc1fl       L_80046328
    if (!c1cs) {
        // 0x800462F0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80046328;
    }
    goto skip_3;
    // 0x800462F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x800462F4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800462F8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x800462FC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80046300: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80046304: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80046308: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004630C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80046310: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80046314: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80046318: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8004631C: jal         0x800460E0
    // 0x80046320: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_tank_800460E0(rdram, ctx);
        goto after_0;
    // 0x80046320: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80046324: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80046328:
    // 0x80046328: bne         $s1, $s5, L_800462A8
    if (ctx->r17 != ctx->r21) {
        // 0x8004632C: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_800462A8;
    }
    // 0x8004632C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80046330: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80046334: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80046338: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8004633C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80046340: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80046344: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80046348: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8004634C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80046350: jr          $ra
    // 0x80046354: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80046354: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Lib_TextureRect_CI4_MirX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8009C9CC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8009C9D0: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x8009C9D4: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8009C9D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C9DC: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8009C9E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C9E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C9E8: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8009C9EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C9F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C9F4: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8009C9F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C9FC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CA00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CA04: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009CA08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CA0C: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8009CA10: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009CA14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CA18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CA1C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009CA20: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009CA24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CA28: lui         $a2, 0xE700
    ctx->r6 = S32(0XE700 << 16);
    // 0x8009CA2C: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8009CA30: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CA34: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CA38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CA3C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009CA40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CA44: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x8009CA48: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8009CA4C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009CA50: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009CA54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CA58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009CA5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CA60: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8009CA64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CA68: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CA6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CA70: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8009CA74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CA78: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8009CA7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009CA80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009CA84: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009CA88: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009CA8C: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8009CA90: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CA94: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CA98: lui         $t6, 0x704
    ctx->r14 = S32(0X704 << 16);
    // 0x8009CA9C: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8009CAA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CAA4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CAA8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8009CAAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009CAB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009CAB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CAB8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009CABC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009CAC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CAC4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009CAC8: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009CACC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009CAD0: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009CAD4: srl         $v0, $a3, 4
    ctx->r2 = S32(U32(ctx->r7) >> 4);
    // 0x8009CAD8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8009CADC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CAE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009CAE4: mflo        $t4
    ctx->r12 = lo;
    // 0x8009CAE8: addiu       $t4, $t4, 0x3
    ctx->r12 = ADD32(ctx->r12, 0X3);
    // 0x8009CAEC: srl         $t6, $t4, 2
    ctx->r14 = S32(U32(ctx->r12) >> 2);
    // 0x8009CAF0: addiu       $t4, $t6, -0x1
    ctx->r12 = ADD32(ctx->r14, -0X1);
    // 0x8009CAF4: sltiu       $at, $t4, 0x7FF
    ctx->r1 = ctx->r12 < 0X7FF ? 1 : 0;
    // 0x8009CAF8: beql        $at, $zero, L_8009CB0C
    if (ctx->r1 == 0) {
        // 0x8009CAFC: addiu       $t0, $zero, 0x7FF
        ctx->r8 = ADD32(0, 0X7FF);
            goto L_8009CB0C;
    }
    goto skip_0;
    // 0x8009CAFC: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009CB00: b           L_8009CB0C
    // 0x8009CB04: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
        goto L_8009CB0C;
    // 0x8009CB04: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8009CB08: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_8009CB0C:
    // 0x8009CB0C: bne         $v0, $zero, L_8009CB1C
    if (ctx->r2 != 0) {
        // 0x8009CB10: lui         $at, 0xF540
        ctx->r1 = S32(0XF540 << 16);
            goto L_8009CB1C;
    }
    // 0x8009CB10: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8009CB14: b           L_8009CB20
    // 0x8009CB18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009CB20;
    // 0x8009CB18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009CB1C:
    // 0x8009CB1C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009CB20:
    // 0x8009CB20: bne         $v0, $zero, L_8009CB30
    if (ctx->r2 != 0) {
        // 0x8009CB24: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8009CB30;
    }
    // 0x8009CB24: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8009CB28: b           L_8009CB34
    // 0x8009CB2C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009CB34;
    // 0x8009CB2C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009CB30:
    // 0x8009CB30: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009CB34:
    // 0x8009CB34: divu        $zero, $t7, $t3
    lo = S32(U32(ctx->r15) / U32(ctx->r11)); hi = S32(U32(ctx->r15) % U32(ctx->r11));
    // 0x8009CB38: mflo        $t8
    ctx->r24 = lo;
    // 0x8009CB3C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009CB40: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x8009CB44: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009CB48: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x8009CB4C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009CB50: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009CB54: bne         $t3, $zero, L_8009CB60
    if (ctx->r11 != 0) {
        // 0x8009CB58: nop
    
            goto L_8009CB60;
    }
    // 0x8009CB58: nop

    // 0x8009CB5C: break       7
    do_break(2148125532);
L_8009CB60:
    // 0x8009CB60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CB64: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x8009CB68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009CB6C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009CB70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CB74: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8009CB78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CB7C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x8009CB80: srl         $t7, $t9, 3
    ctx->r15 = S32(U32(ctx->r25) >> 3);
    // 0x8009CB84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CB88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CB8C: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8009CB90: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8009CB94: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x8009CB98: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009CB9C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009CBA0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009CBA4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CBA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CBAC: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8009CBB0: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x8009CBB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009CBB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CBBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CBC0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8009CBC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009CBC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009CBCC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009CBD0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8009CBD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009CBD8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8009CBDC: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8009CBE0: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x8009CBE4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8009CBE8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009CBEC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8009CBF0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8009CBF4: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8009CBF8: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8009CBFC: lwc1        $f2, 0x6C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8009CC00: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8009CC04: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009CC08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009CC0C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009CC10: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8009CC14: bgez        $a3, L_8009CC28
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009CC18: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8009CC28;
    }
    // 0x8009CC18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CC1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009CC20: nop

    // 0x8009CC24: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009CC28:
    // 0x8009CC28: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009CC2C: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8009CC30: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009CC34: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009CC38: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009CC3C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009CC40: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009CC44: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009CC48: nop

    // 0x8009CC4C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009CC50: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009CC54: bgez        $a1, L_8009CC6C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8009CC58: or          $t8, $t6, $at
        ctx->r24 = ctx->r14 | ctx->r1;
            goto L_8009CC6C;
    }
    // 0x8009CC58: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8009CC5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009CC60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009CC64: nop

    // 0x8009CC68: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009CC6C:
    // 0x8009CC6C: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009CC70: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009CC74: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009CC78: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009CC7C: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009CC80: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009CC84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009CC88: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009CC8C: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009CC90: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009CC94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009CC98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009CC9C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009CCA0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8009CCA4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009CCA8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009CCAC: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009CCB0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009CCB4: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8009CCB8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009CCBC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009CCC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009CCC4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009CCC8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009CCCC: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009CCD0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009CCD4: div.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8009CCD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CCDC: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009CCE0: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8009CCE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CCE8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CCEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009CCF0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8009CCF4: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009CCF8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009CCFC: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x8009CD00: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CD04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CD08: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009CD0C: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8009CD10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CD14: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CD18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009CD1C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009CD20: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009CD24: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8009CD28: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8009CD2C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8009CD30: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CD34: jr          $ra
    // 0x8009CD38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8009CD38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Effect_Effect348_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80078A70: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80078A74: jal         0x8005980C
    // 0x80078A78: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80078A78: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_0:
    // 0x80078A7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078A80: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078A84: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80078A88: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80078A8C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80078A90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078A94: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80078A98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80078A9C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80078AA0: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80078AA4: lh          $t0, 0x44($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X44);
    // 0x80078AA8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80078AAC: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80078AB0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80078AB4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80078AB8: lui         $t5, 0x201
    ctx->r13 = S32(0X201 << 16);
    // 0x80078ABC: addiu       $t5, $t5, 0x12C0
    ctx->r13 = ADD32(ctx->r13, 0X12C0);
    // 0x80078AC0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80078AC4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80078AC8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80078ACC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80078AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078AD8: jr          $ra
    // 0x80078ADC: nop

    return;
    // 0x80078ADC: nop

;}
RECOMP_FUNC void RCP_SetupDL_62(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B94A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B94A4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B94A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B94AC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B94B0: addiu       $t8, $t8, 0x4320
    ctx->r24 = ADD32(ctx->r24, 0X4320);
    // 0x800B94B4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B94B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B94BC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B94C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B94C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B94C8: jr          $ra
    // 0x800B94CC: nop

    return;
    // 0x800B94CC: nop

;}
RECOMP_FUNC void RCP_SetupDL_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA400: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA404: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA408: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA40C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA410: addiu       $t8, $t8, 0x3948
    ctx->r24 = ADD32(ctx->r24, 0X3948);
    // 0x800BA414: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA418: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA41C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA420: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA424: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA428: jr          $ra
    // 0x800BA42C: nop

    return;
    // 0x800BA42C: nop

;}
RECOMP_FUNC void ActorEvent_ProcessTriggers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80070D48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80070D4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80070D50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80070D54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80070D58: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80070D5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80070D60: addiu       $a0, $a0, 0x78C0
    ctx->r4 = ADD32(ctx->r4, 0X78C0);
    // 0x80070D64: addiu       $v0, $v0, 0x78B4
    ctx->r2 = ADD32(ctx->r2, 0X78B4);
    // 0x80070D68: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80070D6C:
    // 0x80070D6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80070D70: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80070D74: blez        $t6, L_80070D80
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80070D78: nop
    
            goto L_80070D80;
    }
    // 0x80070D78: nop

    // 0x80070D7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80070D80:
    // 0x80070D80: bnel        $at, $zero, L_80070D6C
    if (ctx->r1 != 0) {
        // 0x80070D84: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80070D6C;
    }
    goto skip_0;
    // 0x80070D84: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80070D88: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x80070D8C: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80070D90: bne         $at, $zero, L_80070DE4
    if (ctx->r1 != 0) {
        // 0x80070D94: addiu       $t8, $v0, -0x64
        ctx->r24 = ADD32(ctx->r2, -0X64);
            goto L_80070DE4;
    }
    // 0x80070D94: addiu       $t8, $v0, -0x64
    ctx->r24 = ADD32(ctx->r2, -0X64);
    // 0x80070D98: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80070D9C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80070DA0: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80070DA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80070DA8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80070DAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80070DB0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80070DB4: lwc1        $f6, 0x138($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X138);
    // 0x80070DB8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80070DBC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80070DC0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80070DC4: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80070DC8: nop

    // 0x80070DCC: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80070DD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_1;
    // 0x80070DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80070DD4: jal         0x80070CEC
    // 0x80070DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_0;
    // 0x80070DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80070DDC: b           L_80071DB0
    // 0x80070DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070DE4:
    // 0x80070DE4: sltiu       $at, $v0, 0x44
    ctx->r1 = ctx->r2 < 0X44 ? 1 : 0;
    // 0x80070DE8: beq         $at, $zero, L_80071DAC
    if (ctx->r1 == 0) {
        // 0x80070DEC: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80071DAC;
    }
    // 0x80070DEC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80070DF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070DF4: addu        $at, $at, $t9
    gpr jr_addend_80070DFC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80070DF8: lw          $t9, 0x6C50($at)
    ctx->r25 = ADD32(ctx->r1, 0X6C50);
    // 0x80070DFC: jr          $t9
    // 0x80070E00: nop

    switch (jr_addend_80070DFC >> 2) {
        case 0: goto L_80071DAC; break;
        case 1: goto L_80070E04; break;
        case 2: goto L_80070E6C; break;
        case 3: goto L_80070E88; break;
        case 4: goto L_80070EA4; break;
        case 5: goto L_80070EC0; break;
        case 6: goto L_80070ED8; break;
        case 7: goto L_80070EF8; break;
        case 8: goto L_80070F18; break;
        case 9: goto L_80070F38; break;
        case 10: goto L_80070F84; break;
        case 11: goto L_80070FD0; break;
        case 12: goto L_8007101C; break;
        case 13: goto L_80071068; break;
        case 14: goto L_800710B4; break;
        case 15: goto L_80071100; break;
        case 16: goto L_8007114C; break;
        case 17: goto L_80071198; break;
        case 18: goto L_800711E4; break;
        case 19: goto L_80071230; break;
        case 20: goto L_8007127C; break;
        case 21: goto L_800712C8; break;
        case 22: goto L_80071314; break;
        case 23: goto L_80071360; break;
        case 24: goto L_800713AC; break;
        case 25: goto L_800713F8; break;
        case 26: goto L_80071428; break;
        case 27: goto L_80071470; break;
        case 28: goto L_800714B0; break;
        case 29: goto L_800714F0; break;
        case 30: goto L_80071514; break;
        case 31: goto L_8007153C; break;
        case 32: goto L_80071560; break;
        case 33: goto L_80071584; break;
        case 34: goto L_800715B8; break;
        case 35: goto L_800715EC; break;
        case 36: goto L_80071620; break;
        case 37: goto L_80071668; break;
        case 38: goto L_800716B0; break;
        case 39: goto L_800716F8; break;
        case 40: goto L_800717A4; break;
        case 41: goto L_80071850; break;
        case 42: goto L_800718C4; break;
        case 43: goto L_80071930; break;
        case 44: goto L_800719A8; break;
        case 45: goto L_800719C4; break;
        case 46: goto L_80071A34; break;
        case 47: goto L_80071AA8; break;
        case 48: goto L_80071AFC; break;
        case 49: goto L_80071B34; break;
        case 50: goto L_80071B54; break;
        case 51: goto L_80071B74; break;
        case 52: goto L_80071B94; break;
        case 53: goto L_80071BB4; break;
        case 54: goto L_80071BD4; break;
        case 55: goto L_80071BF4; break;
        case 56: goto L_80071C14; break;
        case 57: goto L_80071C34; break;
        case 58: goto L_80071C54; break;
        case 59: goto L_80071C74; break;
        case 60: goto L_80071C94; break;
        case 61: goto L_80071CB4; break;
        case 62: goto L_80071CD4; break;
        case 63: goto L_80071D00; break;
        case 64: goto L_80071D2C; break;
        case 65: goto L_80071D4C; break;
        case 66: goto L_80071D70; break;
        case 67: goto L_80071D94; break;
        default: switch_error(__func__, 0x80070DFC, 0x800D6C50);
    }
    // 0x80070E00: nop

L_80070E04:
    // 0x80070E04: lw          $t0, 0x54($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X54);
    // 0x80070E08: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80070E0C: addiu       $t2, $t2, 0x3FE0
    ctx->r10 = ADD32(ctx->r10, 0X3FE0);
    // 0x80070E10: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80070E14: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80070E18: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80070E1C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80070E20: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80070E24: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80070E28: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80070E2C: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80070E30: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80070E34: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80070E38: bne         $a3, $t3, L_80070E5C
    if (ctx->r7 != ctx->r11) {
        // 0x80070E3C: nop
    
            goto L_80070E5C;
    }
    // 0x80070E3C: nop

    // 0x80070E40: lh          $t4, 0xCE($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XCE);
    // 0x80070E44: blez        $t4, L_80070E5C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80070E48: nop
    
            goto L_80070E5C;
    }
    // 0x80070E48: nop

    // 0x80070E4C: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x80070E50: lh          $t6, 0xE4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE4);
    // 0x80070E54: beql        $t5, $t6, L_80071DB0
    if (ctx->r13 == ctx->r14) {
        // 0x80070E58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_2;
    // 0x80070E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_80070E5C:
    // 0x80070E5C: jal         0x80070CEC
    // 0x80070E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_1;
    // 0x80070E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80070E64: b           L_80071DB0
    // 0x80070E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070E6C:
    // 0x80070E6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80070E70: bnel        $v1, $at, L_80071DB0
    if (ctx->r3 != ctx->r1) {
        // 0x80070E74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_3;
    // 0x80070E74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80070E78: jal         0x80070CEC
    // 0x80070E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_2;
    // 0x80070E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80070E80: b           L_80071DB0
    // 0x80070E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070E88:
    // 0x80070E88: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80070E8C: bnel        $v1, $a3, L_80071DB0
    if (ctx->r3 != ctx->r7) {
        // 0x80070E90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_4;
    // 0x80070E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80070E94: jal         0x80070CEC
    // 0x80070E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_3;
    // 0x80070E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80070E9C: b           L_80071DB0
    // 0x80070EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070EA4:
    // 0x80070EA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80070EA8: bnel        $v1, $a0, L_80071DB0
    if (ctx->r3 != ctx->r4) {
        // 0x80070EAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_5;
    // 0x80070EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80070EB0: jal         0x80070CEC
    // 0x80070EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_4;
    // 0x80070EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80070EB8: b           L_80071DB0
    // 0x80070EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070EC0:
    // 0x80070EC0: bnel        $v1, $zero, L_80071DB0
    if (ctx->r3 != 0) {
        // 0x80070EC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_6;
    // 0x80070EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80070EC8: jal         0x80070CEC
    // 0x80070ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_5;
    // 0x80070ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80070ED0: b           L_80071DB0
    // 0x80070ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070ED8:
    // 0x80070ED8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80070EDC: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x80070EE0: blezl       $t7, L_80071DB0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80070EE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_7;
    // 0x80070EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80070EE8: jal         0x80070CEC
    // 0x80070EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_6;
    // 0x80070EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80070EF0: b           L_80071DB0
    // 0x80070EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070EF8:
    // 0x80070EF8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80070EFC: lw          $t8, 0x78BC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78BC);
    // 0x80070F00: blezl       $t8, L_80071DB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80070F04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_8;
    // 0x80070F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80070F08: jal         0x80070CEC
    // 0x80070F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_7;
    // 0x80070F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80070F10: b           L_80071DB0
    // 0x80070F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070F18:
    // 0x80070F18: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80070F1C: lw          $t9, 0x78B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B8);
    // 0x80070F20: blezl       $t9, L_80071DB0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80070F24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_9;
    // 0x80070F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80070F28: jal         0x80070CEC
    // 0x80070F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_8;
    // 0x80070F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80070F30: b           L_80071DB0
    // 0x80070F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070F38:
    // 0x80070F38: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80070F3C: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80070F40: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070F44: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80070F48: lwc1        $f2, 0x74($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X74);
    // 0x80070F4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80070F50: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070F54: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80070F58: nop

    // 0x80070F5C: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80070F60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_10;
    // 0x80070F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80070F64: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80070F68: nop

    // 0x80070F6C: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80070F70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_11;
    // 0x80070F70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80070F74: jal         0x80070CEC
    // 0x80070F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_9;
    // 0x80070F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80070F7C: b           L_80071DB0
    // 0x80070F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070F84:
    // 0x80070F84: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80070F88: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80070F8C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070F90: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80070F94: lwc1        $f2, 0x74($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X74);
    // 0x80070F98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80070F9C: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070FA0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80070FA4: nop

    // 0x80070FA8: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80070FAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_12;
    // 0x80070FAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80070FB0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80070FB4: nop

    // 0x80070FB8: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80070FBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_13;
    // 0x80070FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x80070FC0: jal         0x80070CEC
    // 0x80070FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_10;
    // 0x80070FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80070FC8: b           L_80071DB0
    // 0x80070FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80070FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80070FD0:
    // 0x80070FD0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80070FD4: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x80070FD8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070FDC: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80070FE0: lwc1        $f2, 0x74($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X74);
    // 0x80070FE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80070FE8: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070FEC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80070FF0: nop

    // 0x80070FF4: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80070FF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_14;
    // 0x80070FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80070FFC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80071000: nop

    // 0x80071004: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071008: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_15;
    // 0x80071008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x8007100C: jal         0x80070CEC
    // 0x80071010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_11;
    // 0x80071010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80071014: b           L_80071DB0
    // 0x80071018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007101C:
    // 0x8007101C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80071020: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80071024: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80071028: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8007102C: lwc1        $f2, 0x74($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X74);
    // 0x80071030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80071034: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071038: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8007103C: nop

    // 0x80071040: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071044: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_16;
    // 0x80071044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x80071048: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007104C: nop

    // 0x80071050: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071054: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_17;
    // 0x80071054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_17:
    // 0x80071058: jal         0x80070CEC
    // 0x8007105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_12;
    // 0x8007105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80071060: b           L_80071DB0
    // 0x80071064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071068:
    // 0x80071068: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8007106C: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80071070: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80071074: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80071078: lwc1        $f2, 0x74($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X74);
    // 0x8007107C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80071080: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071084: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80071088: nop

    // 0x8007108C: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071090: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_18;
    // 0x80071090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x80071094: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80071098: nop

    // 0x8007109C: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800710A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_19;
    // 0x800710A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x800710A4: jal         0x80070CEC
    // 0x800710A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_13;
    // 0x800710A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800710AC: b           L_80071DB0
    // 0x800710B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800710B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800710B4:
    // 0x800710B4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800710B8: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x800710BC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800710C0: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x800710C4: lwc1        $f2, 0x74($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X74);
    // 0x800710C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800710CC: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800710D0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800710D4: nop

    // 0x800710D8: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800710DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_20;
    // 0x800710DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_20:
    // 0x800710E0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800710E4: nop

    // 0x800710E8: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800710EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_21;
    // 0x800710EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_21:
    // 0x800710F0: jal         0x80070CEC
    // 0x800710F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_14;
    // 0x800710F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800710F8: b           L_80071DB0
    // 0x800710FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800710FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071100:
    // 0x80071100: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071104: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80071108: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007110C: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x80071110: lwc1        $f2, 0x74($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X74);
    // 0x80071114: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80071118: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007111C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80071120: nop

    // 0x80071124: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071128: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_22;
    // 0x80071128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_22:
    // 0x8007112C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80071130: nop

    // 0x80071134: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_23;
    // 0x80071138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_23:
    // 0x8007113C: jal         0x80070CEC
    // 0x80071140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_15;
    // 0x80071140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80071144: b           L_80071DB0
    // 0x80071148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007114C:
    // 0x8007114C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80071150: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80071154: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80071158: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8007115C: lwc1        $f2, 0x74($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X74);
    // 0x80071160: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80071164: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071168: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8007116C: nop

    // 0x80071170: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071174: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_24;
    // 0x80071174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_24:
    // 0x80071178: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8007117C: nop

    // 0x80071180: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071184: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_25;
    // 0x80071184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_25:
    // 0x80071188: jal         0x80070CEC
    // 0x8007118C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_16;
    // 0x8007118C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80071190: b           L_80071DB0
    // 0x80071194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071198:
    // 0x80071198: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8007119C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x800711A0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800711A4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800711A8: lwc1        $f2, 0x78($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X78);
    // 0x800711AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800711B0: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800711B4: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800711B8: nop

    // 0x800711BC: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800711C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_26;
    // 0x800711C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_26:
    // 0x800711C4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800711C8: nop

    // 0x800711CC: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800711D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_27;
    // 0x800711D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_27:
    // 0x800711D4: jal         0x80070CEC
    // 0x800711D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_17;
    // 0x800711D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800711DC: b           L_80071DB0
    // 0x800711E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800711E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800711E4:
    // 0x800711E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800711E8: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x800711EC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800711F0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800711F4: lwc1        $f2, 0x78($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X78);
    // 0x800711F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800711FC: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071200: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80071204: nop

    // 0x80071208: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x8007120C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_28;
    // 0x8007120C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_28:
    // 0x80071210: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80071214: nop

    // 0x80071218: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x8007121C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_29;
    // 0x8007121C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_29:
    // 0x80071220: jal         0x80070CEC
    // 0x80071224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_18;
    // 0x80071224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80071228: b           L_80071DB0
    // 0x8007122C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007122C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071230:
    // 0x80071230: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80071234: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80071238: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007123C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80071240: lwc1        $f2, 0x78($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X78);
    // 0x80071244: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80071248: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007124C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80071250: nop

    // 0x80071254: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071258: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_30;
    // 0x80071258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_30:
    // 0x8007125C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80071260: nop

    // 0x80071264: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071268: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_31;
    // 0x80071268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_31:
    // 0x8007126C: jal         0x80070CEC
    // 0x80071270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_19;
    // 0x80071270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80071274: b           L_80071DB0
    // 0x80071278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007127C:
    // 0x8007127C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80071280: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80071284: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80071288: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8007128C: lwc1        $f2, 0x78($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X78);
    // 0x80071290: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80071294: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071298: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8007129C: nop

    // 0x800712A0: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800712A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_32;
    // 0x800712A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_32:
    // 0x800712A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800712AC: nop

    // 0x800712B0: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800712B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_33;
    // 0x800712B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_33:
    // 0x800712B8: jal         0x80070CEC
    // 0x800712BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_20;
    // 0x800712BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800712C0: b           L_80071DB0
    // 0x800712C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800712C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800712C8:
    // 0x800712C8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800712CC: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x800712D0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800712D4: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800712D8: lwc1        $f2, 0x78($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X78);
    // 0x800712DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800712E0: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800712E4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800712E8: nop

    // 0x800712EC: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800712F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_34;
    // 0x800712F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_34:
    // 0x800712F4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800712F8: nop

    // 0x800712FC: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071300: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_35;
    // 0x80071300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_35:
    // 0x80071304: jal         0x80070CEC
    // 0x80071308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_21;
    // 0x80071308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8007130C: b           L_80071DB0
    // 0x80071310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071314:
    // 0x80071314: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80071318: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8007131C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80071320: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80071324: lwc1        $f2, 0x78($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X78);
    // 0x80071328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007132C: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071330: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80071334: nop

    // 0x80071338: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x8007133C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_36;
    // 0x8007133C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_36:
    // 0x80071340: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80071344: nop

    // 0x80071348: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x8007134C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_37;
    // 0x8007134C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_37:
    // 0x80071350: jal         0x80070CEC
    // 0x80071354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_22;
    // 0x80071354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80071358: b           L_80071DB0
    // 0x8007135C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007135C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071360:
    // 0x80071360: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80071364: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80071368: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007136C: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x80071370: lwc1        $f2, 0x78($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X78);
    // 0x80071374: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80071378: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007137C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80071380: nop

    // 0x80071384: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071388: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_38;
    // 0x80071388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_38:
    // 0x8007138C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80071390: nop

    // 0x80071394: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071398: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_39;
    // 0x80071398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_39:
    // 0x8007139C: jal         0x80070CEC
    // 0x800713A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_23;
    // 0x800713A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800713A4: b           L_80071DB0
    // 0x800713A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800713A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800713AC:
    // 0x800713AC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800713B0: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x800713B4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800713B8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800713BC: lwc1        $f2, 0x78($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X78);
    // 0x800713C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800713C4: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800713C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800713CC: nop

    // 0x800713D0: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800713D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_40;
    // 0x800713D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_40:
    // 0x800713D8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800713DC: nop

    // 0x800713E0: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800713E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_41;
    // 0x800713E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_41:
    // 0x800713E8: jal         0x80070CEC
    // 0x800713EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_24;
    // 0x800713EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800713F0: b           L_80071DB0
    // 0x800713F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800713F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800713F8:
    // 0x800713F8: jal         0x800A3FC4
    // 0x800713FC: nop

    Play_GetMaxShields(rdram, ctx);
        goto after_25;
    // 0x800713FC: nop

    after_25:
    // 0x80071400: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071404: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80071408: lw          $t7, 0x264($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X264);
    // 0x8007140C: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80071410: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x80071414: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_42;
    // 0x80071414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_42:
    // 0x80071418: jal         0x80070CEC
    // 0x8007141C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_26;
    // 0x8007141C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80071420: b           L_80071DB0
    // 0x80071424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071428:
    // 0x80071428: jal         0x800A3FC4
    // 0x8007142C: nop

    Play_GetMaxShields(rdram, ctx);
        goto after_27;
    // 0x8007142C: nop

    after_27:
    // 0x80071430: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80071434: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80071438: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8007143C: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80071440: lw          $t9, 0x264($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X264);
    // 0x80071444: bgez        $t0, L_80071454
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80071448: sra         $t1, $t0, 2
        ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
            goto L_80071454;
    }
    // 0x80071448: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007144C: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
    // 0x80071450: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
L_80071454:
    // 0x80071454: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80071458: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x8007145C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_43;
    // 0x8007145C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_43:
    // 0x80071460: jal         0x80070CEC
    // 0x80071464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_28;
    // 0x80071464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80071468: b           L_80071DB0
    // 0x8007146C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007146C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071470:
    // 0x80071470: jal         0x800A3FC4
    // 0x80071474: nop

    Play_GetMaxShields(rdram, ctx);
        goto after_29;
    // 0x80071474: nop

    after_29:
    // 0x80071478: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8007147C: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x80071480: lw          $t3, 0x264($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X264);
    // 0x80071484: bgez        $v0, L_80071494
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80071488: sra         $t4, $v0, 1
        ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80071494;
    }
    // 0x80071488: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8007148C: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80071490: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80071494:
    // 0x80071494: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80071498: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x8007149C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_44;
    // 0x8007149C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_44:
    // 0x800714A0: jal         0x80070CEC
    // 0x800714A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_30;
    // 0x800714A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x800714A8: b           L_80071DB0
    // 0x800714AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800714AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800714B0:
    // 0x800714B0: jal         0x800A3FC4
    // 0x800714B4: nop

    Play_GetMaxShields(rdram, ctx);
        goto after_31;
    // 0x800714B4: nop

    after_31:
    // 0x800714B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800714BC: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x800714C0: lw          $t6, 0x264($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X264);
    // 0x800714C4: bgez        $v0, L_800714D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800714C8: sra         $t7, $v0, 2
        ctx->r15 = S32(SIGNED(ctx->r2) >> 2);
            goto L_800714D4;
    }
    // 0x800714C8: sra         $t7, $v0, 2
    ctx->r15 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800714CC: addiu       $at, $v0, 0x3
    ctx->r1 = ADD32(ctx->r2, 0X3);
    // 0x800714D0: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_800714D4:
    // 0x800714D4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800714D8: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x800714DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_45;
    // 0x800714DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_45:
    // 0x800714E0: jal         0x80070CEC
    // 0x800714E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_32;
    // 0x800714E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x800714E8: b           L_80071DB0
    // 0x800714EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800714EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800714F0:
    // 0x800714F0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800714F4: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x800714F8: lw          $t0, 0x264($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X264);
    // 0x800714FC: bnel        $t0, $zero, L_80071DB0
    if (ctx->r8 != 0) {
        // 0x80071500: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_46;
    // 0x80071500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_46:
    // 0x80071504: jal         0x80070CEC
    // 0x80071508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_33;
    // 0x80071508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x8007150C: b           L_80071DB0
    // 0x80071510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071514:
    // 0x80071514: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80071518: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8007151C: lw          $t1, 0x270($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X270);
    // 0x80071520: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80071524: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x80071528: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_47;
    // 0x80071528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_47:
    // 0x8007152C: jal         0x80070CEC
    // 0x80071530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_34;
    // 0x80071530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80071534: b           L_80071DB0
    // 0x80071538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007153C:
    // 0x8007153C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80071540: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x80071544: lw          $t3, 0x270($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X270);
    // 0x80071548: beql        $t3, $zero, L_80071DB0
    if (ctx->r11 == 0) {
        // 0x8007154C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_48;
    // 0x8007154C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_48:
    // 0x80071550: jal         0x80070CEC
    // 0x80071554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_35;
    // 0x80071554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80071558: b           L_80071DB0
    // 0x8007155C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007155C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071560:
    // 0x80071560: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80071564: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80071568: lw          $t5, 0x270($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X270);
    // 0x8007156C: bnel        $t5, $zero, L_80071DB0
    if (ctx->r13 != 0) {
        // 0x80071570: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_49;
    // 0x80071570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_49:
    // 0x80071574: jal         0x80070CEC
    // 0x80071578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_36;
    // 0x80071578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8007157C: b           L_80071DB0
    // 0x80071580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071584:
    // 0x80071584: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071588: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8007158C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071590: lwc1        $f10, 0x6D60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D60);
    // 0x80071594: lwc1        $f8, 0x250($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X250);
    // 0x80071598: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8007159C: nop

    // 0x800715A0: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800715A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_50;
    // 0x800715A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_50:
    // 0x800715A8: jal         0x80070CEC
    // 0x800715AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_37;
    // 0x800715AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x800715B0: b           L_80071DB0
    // 0x800715B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800715B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800715B8:
    // 0x800715B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800715BC: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800715C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800715C4: lwc1        $f16, 0x6D64($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6D64);
    // 0x800715C8: lwc1        $f18, 0x250($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X250);
    // 0x800715CC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800715D0: nop

    // 0x800715D4: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800715D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_51;
    // 0x800715D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_51:
    // 0x800715DC: jal         0x80070CEC
    // 0x800715E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_38;
    // 0x800715E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x800715E4: b           L_80071DB0
    // 0x800715E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800715E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800715EC:
    // 0x800715EC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800715F0: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x800715F4: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x800715F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800715FC: lwc1        $f6, 0x4B0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4B0);
    // 0x80071600: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80071604: nop

    // 0x80071608: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x8007160C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_52;
    // 0x8007160C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_52:
    // 0x80071610: jal         0x80070CEC
    // 0x80071614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_39;
    // 0x80071614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80071618: b           L_80071DB0
    // 0x8007161C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007161C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071620:
    // 0x80071620: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80071624: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80071628: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8007162C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80071630: lwc1        $f8, 0x4B0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4B0);
    // 0x80071634: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80071638: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8007163C: nop

    // 0x80071640: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x80071644: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_53;
    // 0x80071644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_53:
    // 0x80071648: lw          $t9, 0x1AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1AA8);
    // 0x8007164C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80071650: bnel        $a0, $t9, L_80071DB0
    if (ctx->r4 != ctx->r25) {
        // 0x80071654: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_54;
    // 0x80071654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_54:
    // 0x80071658: jal         0x80070CEC
    // 0x8007165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_40;
    // 0x8007165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80071660: b           L_80071DB0
    // 0x80071664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071668:
    // 0x80071668: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8007166C: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80071670: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80071674: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80071678: lwc1        $f16, 0x4B0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4B0);
    // 0x8007167C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80071680: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80071684: nop

    // 0x80071688: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x8007168C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_55;
    // 0x8007168C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_55:
    // 0x80071690: lw          $t2, 0x1AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1AA8);
    // 0x80071694: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80071698: bnel        $a3, $t2, L_80071DB0
    if (ctx->r7 != ctx->r10) {
        // 0x8007169C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_56;
    // 0x8007169C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_56:
    // 0x800716A0: jal         0x80070CEC
    // 0x800716A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_41;
    // 0x800716A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x800716A8: b           L_80071DB0
    // 0x800716AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800716AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800716B0:
    // 0x800716B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800716B4: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x800716B8: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x800716BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800716C0: lwc1        $f4, 0x4B0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4B0);
    // 0x800716C4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800716C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800716CC: nop

    // 0x800716D0: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800716D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_57;
    // 0x800716D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_57:
    // 0x800716D8: lw          $t4, 0x1AA8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1AA8);
    // 0x800716DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800716E0: bnel        $t4, $at, L_80071DB0
    if (ctx->r12 != ctx->r1) {
        // 0x800716E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_58;
    // 0x800716E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_58:
    // 0x800716E8: jal         0x80070CEC
    // 0x800716EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_42;
    // 0x800716EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x800716F0: b           L_80071DB0
    // 0x800716F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800716F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800716F8:
    // 0x800716F8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800716FC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80071700: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80071704: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80071708: addiu       $v1, $v1, 0x4750
    ctx->r3 = ADD32(ctx->r3, 0X4750);
    // 0x8007170C: addiu       $v0, $v0, 0x4050
    ctx->r2 = ADD32(ctx->r2, 0X4050);
    // 0x80071710: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80071714: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
L_80071718:
    // 0x80071718: bnel        $a0, $t5, L_80071794
    if (ctx->r4 != ctx->r13) {
        // 0x8007171C: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071794;
    }
    goto skip_59;
    // 0x8007171C: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_59:
    // 0x80071720: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80071724: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80071728: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007172C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80071730: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80071734: nop

    // 0x80071738: bc1fl       L_80071794
    if (!c1cs) {
        // 0x8007173C: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071794;
    }
    goto skip_60;
    // 0x8007173C: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_60:
    // 0x80071740: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80071744: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80071748: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007174C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80071750: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80071754: nop

    // 0x80071758: bc1fl       L_80071794
    if (!c1cs) {
        // 0x8007175C: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071794;
    }
    goto skip_61;
    // 0x8007175C: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_61:
    // 0x80071760: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80071764: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80071768: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007176C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80071770: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80071774: nop

    // 0x80071778: bc1fl       L_80071794
    if (!c1cs) {
        // 0x8007177C: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071794;
    }
    goto skip_62;
    // 0x8007177C: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_62:
    // 0x80071780: jal         0x80070CEC
    // 0x80071784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_43;
    // 0x80071784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80071788: b           L_80071DB0
    // 0x8007178C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007178C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80071790: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
L_80071794:
    // 0x80071794: bnel        $v0, $v1, L_80071718
    if (ctx->r2 != ctx->r3) {
        // 0x80071798: lbu         $t5, 0x0($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X0);
            goto L_80071718;
    }
    goto skip_63;
    // 0x80071798: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    skip_63:
    // 0x8007179C: b           L_80071DB0
    // 0x800717A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800717A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800717A4:
    // 0x800717A4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800717A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800717AC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800717B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800717B4: addiu       $v1, $v1, 0x4750
    ctx->r3 = ADD32(ctx->r3, 0X4750);
    // 0x800717B8: addiu       $v0, $v0, 0x4050
    ctx->r2 = ADD32(ctx->r2, 0X4050);
    // 0x800717BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800717C0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
L_800717C4:
    // 0x800717C4: bnel        $a0, $t6, L_80071840
    if (ctx->r4 != ctx->r14) {
        // 0x800717C8: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071840;
    }
    goto skip_64;
    // 0x800717C8: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_64:
    // 0x800717CC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800717D0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800717D4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800717D8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800717DC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800717E0: nop

    // 0x800717E4: bc1fl       L_80071840
    if (!c1cs) {
        // 0x800717E8: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071840;
    }
    goto skip_65;
    // 0x800717E8: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_65:
    // 0x800717EC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800717F0: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800717F4: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800717F8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800717FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80071800: nop

    // 0x80071804: bc1fl       L_80071840
    if (!c1cs) {
        // 0x80071808: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071840;
    }
    goto skip_66;
    // 0x80071808: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_66:
    // 0x8007180C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80071810: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80071814: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80071818: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007181C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80071820: nop

    // 0x80071824: bc1fl       L_80071840
    if (!c1cs) {
        // 0x80071828: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80071840;
    }
    goto skip_67;
    // 0x80071828: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_67:
    // 0x8007182C: jal         0x80070CEC
    // 0x80071830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_44;
    // 0x80071830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80071834: b           L_80071DB0
    // 0x80071838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007183C: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
L_80071840:
    // 0x80071840: bnel        $v0, $v1, L_800717C4
    if (ctx->r2 != ctx->r3) {
        // 0x80071844: lbu         $t6, 0x0($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X0);
            goto L_800717C4;
    }
    goto skip_68;
    // 0x80071844: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    skip_68:
    // 0x80071848: b           L_80071DB0
    // 0x8007184C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007184C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071850:
    // 0x80071850: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80071854: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80071858: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x8007185C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80071860: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80071864: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80071868: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007186C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80071870: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80071874: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80071878: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8007187C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80071880: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80071884: bne         $a3, $t9, L_800718B4
    if (ctx->r7 != ctx->r25) {
        // 0x80071888: nop
    
            goto L_800718B4;
    }
    // 0x80071888: nop

    // 0x8007188C: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x80071890: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80071894: nop

    // 0x80071898: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8007189C: nop

    // 0x800718A0: bc1fl       L_80071DB0
    if (!c1cs) {
        // 0x800718A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_69;
    // 0x800718A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_69:
    // 0x800718A8: lh          $t1, 0xCE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCE);
    // 0x800718AC: bgtzl       $t1, L_80071DB0
    if (SIGNED(ctx->r9) > 0) {
        // 0x800718B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_70;
    // 0x800718B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_70:
L_800718B4:
    // 0x800718B4: jal         0x80070CEC
    // 0x800718B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_45;
    // 0x800718B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x800718BC: b           L_80071DB0
    // 0x800718C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800718C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800718C4:
    // 0x800718C4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800718C8: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x800718CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800718D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800718D4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x800718D8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
L_800718DC:
    // 0x800718DC: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x800718E0: bnel        $a3, $t2, L_80071918
    if (ctx->r7 != ctx->r10) {
        // 0x800718E4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071918;
    }
    goto skip_71;
    // 0x800718E4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_71:
    // 0x800718E8: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    // 0x800718EC: bnel        $a0, $t3, L_80071918
    if (ctx->r4 != ctx->r11) {
        // 0x800718F0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071918;
    }
    goto skip_72;
    // 0x800718F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_72:
    // 0x800718F4: lw          $t4, 0x84($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X84);
    // 0x800718F8: beql        $t4, $zero, L_80071918
    if (ctx->r12 == 0) {
        // 0x800718FC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071918;
    }
    goto skip_73;
    // 0x800718FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_73:
    // 0x80071900: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80071904: beql        $a1, $v0, L_80071918
    if (ctx->r5 == ctx->r2) {
        // 0x80071908: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071918;
    }
    goto skip_74;
    // 0x80071908: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_74:
    // 0x8007190C: lw          $t5, 0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X74);
    // 0x80071910: beq         $v0, $t5, L_80071DAC
    if (ctx->r2 == ctx->r13) {
        // 0x80071914: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071DAC;
    }
    // 0x80071914: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80071918:
    // 0x80071918: bne         $a1, $a2, L_800718DC
    if (ctx->r5 != ctx->r6) {
        // 0x8007191C: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_800718DC;
    }
    // 0x8007191C: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x80071920: jal         0x80070CEC
    // 0x80071924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_46;
    // 0x80071924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80071928: b           L_80071DB0
    // 0x8007192C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x8007192C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071930:
    // 0x80071930: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80071934: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x80071938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007193C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80071940: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80071944: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
L_80071948:
    // 0x80071948: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8007194C: bnel        $a3, $t6, L_80071998
    if (ctx->r7 != ctx->r14) {
        // 0x80071950: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071998;
    }
    goto skip_75;
    // 0x80071950: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_75:
    // 0x80071954: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x80071958: bnel        $a0, $t7, L_80071998
    if (ctx->r4 != ctx->r15) {
        // 0x8007195C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071998;
    }
    goto skip_76;
    // 0x8007195C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_76:
    // 0x80071960: lw          $t8, 0x84($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X84);
    // 0x80071964: beql        $t8, $zero, L_80071998
    if (ctx->r24 == 0) {
        // 0x80071968: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071998;
    }
    goto skip_77;
    // 0x80071968: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_77:
    // 0x8007196C: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80071970: beql        $a1, $v0, L_80071998
    if (ctx->r5 == ctx->r2) {
        // 0x80071974: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071998;
    }
    goto skip_78;
    // 0x80071974: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_78:
    // 0x80071978: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    // 0x8007197C: bnel        $v0, $t0, L_80071998
    if (ctx->r2 != ctx->r8) {
        // 0x80071980: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071998;
    }
    goto skip_79;
    // 0x80071980: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_79:
    // 0x80071984: jal         0x80070CEC
    // 0x80071988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_47;
    // 0x80071988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x8007198C: b           L_80071DB0
    // 0x80071990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80071994: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80071998:
    // 0x80071998: bne         $a1, $a2, L_80071948
    if (ctx->r5 != ctx->r6) {
        // 0x8007199C: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_80071948;
    }
    // 0x8007199C: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x800719A0: b           L_80071DB0
    // 0x800719A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800719A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800719A8:
    // 0x800719A8: lb          $t9, 0xD0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XD0);
    // 0x800719AC: beql        $t9, $zero, L_80071DB0
    if (ctx->r25 == 0) {
        // 0x800719B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_80;
    // 0x800719B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_80:
    // 0x800719B4: jal         0x80070CEC
    // 0x800719B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_48;
    // 0x800719B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x800719BC: b           L_80071DB0
    // 0x800719C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x800719C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800719C4:
    // 0x800719C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800719C8: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x800719CC: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x800719D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800719D4: beq         $a0, $zero, L_80071A00
    if (ctx->r4 == 0) {
        // 0x800719D8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80071A00;
    }
    // 0x800719D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800719DC: beq         $v0, $a3, L_800719F4
    if (ctx->r2 == ctx->r7) {
        // 0x800719E0: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_800719F4;
    }
    // 0x800719E0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800719E4: beql        $v0, $at, L_80071A00
    if (ctx->r2 == ctx->r1) {
        // 0x800719E8: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80071A00;
    }
    goto skip_81;
    // 0x800719E8: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    skip_81:
    // 0x800719EC: b           L_80071A00
    // 0x800719F0: nop

        goto L_80071A00;
    // 0x800719F0: nop

L_800719F4:
    // 0x800719F4: b           L_80071A00
    // 0x800719F8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80071A00;
    // 0x800719F8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800719FC: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80071A00:
    // 0x80071A00: bne         $a0, $zero, L_80071A10
    if (ctx->r4 != 0) {
        // 0x80071A04: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_80071A10;
    }
    // 0x80071A04: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80071A08: lw          $t1, 0x78B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B4);
    // 0x80071A0C: blez        $t1, L_80071DAC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80071A10: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_80071DAC;
    }
L_80071A10:
    // 0x80071A10: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80071A14: lw          $t2, 0x7E80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7E80);
    // 0x80071A18: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80071A1C: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x80071A20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_82;
    // 0x80071A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_82:
    // 0x80071A24: jal         0x80070CEC
    // 0x80071A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_49;
    // 0x80071A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80071A2C: b           L_80071DB0
    // 0x80071A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071A34:
    // 0x80071A34: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80071A38: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80071A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071A40: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
L_80071A44:
    // 0x80071A44: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80071A48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80071A4C: beql        $v1, $at, L_80071A60
    if (ctx->r3 == ctx->r1) {
        // 0x80071A50: lw          $t3, 0x8C($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X8C);
            goto L_80071A60;
    }
    goto skip_83;
    // 0x80071A50: lw          $t3, 0x8C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8C);
    skip_83:
    // 0x80071A54: bnel        $v1, $zero, L_80071A98
    if (ctx->r3 != 0) {
        // 0x80071A58: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071A98;
    }
    goto skip_84;
    // 0x80071A58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_84:
    // 0x80071A5C: lw          $t3, 0x8C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8C);
L_80071A60:
    // 0x80071A60: lw          $t4, 0x8C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8C);
    // 0x80071A64: bnel        $t3, $t4, L_80071A98
    if (ctx->r11 != ctx->r12) {
        // 0x80071A68: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071A98;
    }
    goto skip_85;
    // 0x80071A68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_85:
    // 0x80071A6C: lw          $t5, 0x90($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X90);
    // 0x80071A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80071A74: beql        $t5, $zero, L_80071A98
    if (ctx->r13 == 0) {
        // 0x80071A78: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80071A98;
    }
    goto skip_86;
    // 0x80071A78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_86:
    // 0x80071A7C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80071A80: jal         0x80070CEC
    // 0x80071A84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_50;
    // 0x80071A84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_50:
    // 0x80071A88: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80071A8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80071A90: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80071A94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80071A98:
    // 0x80071A98: bne         $a1, $a2, L_80071A44
    if (ctx->r5 != ctx->r6) {
        // 0x80071A9C: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_80071A44;
    }
    // 0x80071A9C: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x80071AA0: b           L_80071DB0
    // 0x80071AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071AA8:
    // 0x80071AA8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80071AAC: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x80071AB0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80071AB4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80071AB8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80071ABC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80071AC0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80071AC4: lhu         $t8, -0x2768($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2768);
    // 0x80071AC8: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x80071ACC: beql        $t0, $zero, L_80071DB0
    if (ctx->r8 == 0) {
        // 0x80071AD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_87;
    // 0x80071AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_87:
    // 0x80071AD4: jal         0x8001AF40
    // 0x80071AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetUnkVoiceParam(rdram, ctx);
        goto after_51;
    // 0x80071AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_51:
    // 0x80071ADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071AE0: sw          $zero, -0x70($at)
    MEM_W(-0X70, ctx->r1) = 0;
    // 0x80071AE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80071AE8: sw          $zero, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = 0;
    // 0x80071AEC: jal         0x80070CEC
    // 0x80071AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_52;
    // 0x80071AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80071AF4: b           L_80071DB0
    // 0x80071AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071AFC:
    // 0x80071AFC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80071B00: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80071B04: lbu         $t9, 0x49C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X49C);
    // 0x80071B08: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80071B0C: bne         $at, $zero, L_80071B24
    if (ctx->r1 != 0) {
        // 0x80071B10: nop
    
            goto L_80071B24;
    }
    // 0x80071B10: nop

    // 0x80071B14: lbu         $t1, 0x49D($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X49D);
    // 0x80071B18: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80071B1C: beql        $at, $zero, L_80071DB0
    if (ctx->r1 == 0) {
        // 0x80071B20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_88;
    // 0x80071B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_88:
L_80071B24:
    // 0x80071B24: jal         0x80070CEC
    // 0x80071B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_53;
    // 0x80071B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80071B2C: b           L_80071DB0
    // 0x80071B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071B34:
    // 0x80071B34: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80071B38: lbu         $t2, 0x3181($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3181);
    // 0x80071B3C: beql        $t2, $zero, L_80071DB0
    if (ctx->r10 == 0) {
        // 0x80071B40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_89;
    // 0x80071B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_89:
    // 0x80071B44: jal         0x80070CEC
    // 0x80071B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_54;
    // 0x80071B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80071B4C: b           L_80071DB0
    // 0x80071B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071B54:
    // 0x80071B54: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80071B58: lbu         $t3, 0x318E($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X318E);
    // 0x80071B5C: beql        $t3, $zero, L_80071DB0
    if (ctx->r11 == 0) {
        // 0x80071B60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_90;
    // 0x80071B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_90:
    // 0x80071B64: jal         0x80070CEC
    // 0x80071B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_55;
    // 0x80071B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80071B6C: b           L_80071DB0
    // 0x80071B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071B74:
    // 0x80071B74: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80071B78: lbu         $t4, 0x3182($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X3182);
    // 0x80071B7C: beql        $t4, $zero, L_80071DB0
    if (ctx->r12 == 0) {
        // 0x80071B80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_91;
    // 0x80071B80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_91:
    // 0x80071B84: jal         0x80070CEC
    // 0x80071B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_56;
    // 0x80071B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80071B8C: b           L_80071DB0
    // 0x80071B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071B94:
    // 0x80071B94: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80071B98: lbu         $t5, 0x318C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X318C);
    // 0x80071B9C: beql        $t5, $zero, L_80071DB0
    if (ctx->r13 == 0) {
        // 0x80071BA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_92;
    // 0x80071BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_92:
    // 0x80071BA4: jal         0x80070CEC
    // 0x80071BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_57;
    // 0x80071BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80071BAC: b           L_80071DB0
    // 0x80071BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071BB4:
    // 0x80071BB4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80071BB8: lbu         $t6, 0x3191($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3191);
    // 0x80071BBC: beql        $t6, $zero, L_80071DB0
    if (ctx->r14 == 0) {
        // 0x80071BC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_93;
    // 0x80071BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_93:
    // 0x80071BC4: jal         0x80070CEC
    // 0x80071BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_58;
    // 0x80071BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80071BCC: b           L_80071DB0
    // 0x80071BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071BD4:
    // 0x80071BD4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80071BD8: lbu         $t7, 0x3185($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3185);
    // 0x80071BDC: beql        $t7, $zero, L_80071DB0
    if (ctx->r15 == 0) {
        // 0x80071BE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_94;
    // 0x80071BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_94:
    // 0x80071BE4: jal         0x80070CEC
    // 0x80071BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_59;
    // 0x80071BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80071BEC: b           L_80071DB0
    // 0x80071BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071BF4:
    // 0x80071BF4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80071BF8: lbu         $t8, 0x3190($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3190);
    // 0x80071BFC: beql        $t8, $zero, L_80071DB0
    if (ctx->r24 == 0) {
        // 0x80071C00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_95;
    // 0x80071C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_95:
    // 0x80071C04: jal         0x80070CEC
    // 0x80071C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_60;
    // 0x80071C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80071C0C: b           L_80071DB0
    // 0x80071C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071C14:
    // 0x80071C14: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80071C18: lbu         $t0, 0x3187($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3187);
    // 0x80071C1C: beql        $t0, $zero, L_80071DB0
    if (ctx->r8 == 0) {
        // 0x80071C20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_96;
    // 0x80071C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_96:
    // 0x80071C24: jal         0x80070CEC
    // 0x80071C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_61;
    // 0x80071C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80071C2C: b           L_80071DB0
    // 0x80071C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071C34:
    // 0x80071C34: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80071C38: lbu         $t9, 0x318B($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X318B);
    // 0x80071C3C: beql        $t9, $zero, L_80071DB0
    if (ctx->r25 == 0) {
        // 0x80071C40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_97;
    // 0x80071C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_97:
    // 0x80071C44: jal         0x80070CEC
    // 0x80071C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_62;
    // 0x80071C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80071C4C: b           L_80071DB0
    // 0x80071C50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071C50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071C54:
    // 0x80071C54: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80071C58: lbu         $t1, 0x318D($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X318D);
    // 0x80071C5C: beql        $t1, $zero, L_80071DB0
    if (ctx->r9 == 0) {
        // 0x80071C60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_98;
    // 0x80071C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_98:
    // 0x80071C64: jal         0x80070CEC
    // 0x80071C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_63;
    // 0x80071C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80071C6C: b           L_80071DB0
    // 0x80071C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071C74:
    // 0x80071C74: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80071C78: lbu         $t2, 0x3188($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3188);
    // 0x80071C7C: beql        $t2, $zero, L_80071DB0
    if (ctx->r10 == 0) {
        // 0x80071C80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_99;
    // 0x80071C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_99:
    // 0x80071C84: jal         0x80070CEC
    // 0x80071C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_64;
    // 0x80071C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x80071C8C: b           L_80071DB0
    // 0x80071C90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071C90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071C94:
    // 0x80071C94: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80071C98: lbu         $t3, 0x3192($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3192);
    // 0x80071C9C: beql        $t3, $zero, L_80071DB0
    if (ctx->r11 == 0) {
        // 0x80071CA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_100;
    // 0x80071CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_100:
    // 0x80071CA4: jal         0x80070CEC
    // 0x80071CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_65;
    // 0x80071CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80071CAC: b           L_80071DB0
    // 0x80071CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071CB4:
    // 0x80071CB4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80071CB8: lbu         $t4, 0x3183($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X3183);
    // 0x80071CBC: beql        $t4, $zero, L_80071DB0
    if (ctx->r12 == 0) {
        // 0x80071CC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_101;
    // 0x80071CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_101:
    // 0x80071CC4: jal         0x80070CEC
    // 0x80071CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_66;
    // 0x80071CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80071CCC: b           L_80071DB0
    // 0x80071CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071CD4:
    // 0x80071CD4: lw          $t5, 0x80($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X80);
    // 0x80071CD8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80071CDC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80071CE0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80071CE4: lw          $t7, 0x1670($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1670);
    // 0x80071CE8: bnel        $t7, $zero, L_80071DB0
    if (ctx->r15 != 0) {
        // 0x80071CEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_102;
    // 0x80071CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_102:
    // 0x80071CF0: jal         0x80070CEC
    // 0x80071CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_67;
    // 0x80071CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x80071CF8: b           L_80071DB0
    // 0x80071CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071D00:
    // 0x80071D00: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
    // 0x80071D04: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80071D08: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80071D0C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80071D10: lw          $t9, 0x1670($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1670);
    // 0x80071D14: beql        $t9, $zero, L_80071DB0
    if (ctx->r25 == 0) {
        // 0x80071D18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_103;
    // 0x80071D18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_103:
    // 0x80071D1C: jal         0x80070CEC
    // 0x80071D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_68;
    // 0x80071D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x80071D24: b           L_80071DB0
    // 0x80071D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071D2C:
    // 0x80071D2C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80071D30: lbu         $t1, 0x1684($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1684);
    // 0x80071D34: beql        $t1, $zero, L_80071DB0
    if (ctx->r9 == 0) {
        // 0x80071D38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_104;
    // 0x80071D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_104:
    // 0x80071D3C: jal         0x80070CEC
    // 0x80071D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_69;
    // 0x80071D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x80071D44: b           L_80071DB0
    // 0x80071D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071D4C:
    // 0x80071D4C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80071D50: lw          $t2, 0x1A98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1A98);
    // 0x80071D54: slti        $at, $t2, 0x1E
    ctx->r1 = SIGNED(ctx->r10) < 0X1E ? 1 : 0;
    // 0x80071D58: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x80071D5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_105;
    // 0x80071D5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_105:
    // 0x80071D60: jal         0x80070CEC
    // 0x80071D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_70;
    // 0x80071D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x80071D68: b           L_80071DB0
    // 0x80071D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071D70:
    // 0x80071D70: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80071D74: lw          $t3, 0x1A98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A98);
    // 0x80071D78: slti        $at, $t3, 0x50
    ctx->r1 = SIGNED(ctx->r11) < 0X50 ? 1 : 0;
    // 0x80071D7C: bnel        $at, $zero, L_80071DB0
    if (ctx->r1 != 0) {
        // 0x80071D80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_106;
    // 0x80071D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_106:
    // 0x80071D84: jal         0x80070CEC
    // 0x80071D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_71;
    // 0x80071D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x80071D8C: b           L_80071DB0
    // 0x80071D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80071DB0;
    // 0x80071D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071D94:
    // 0x80071D94: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80071D98: lw          $t4, 0x79F8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X79F8);
    // 0x80071D9C: beql        $t4, $zero, L_80071DB0
    if (ctx->r12 == 0) {
        // 0x80071DA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80071DB0;
    }
    goto skip_107;
    // 0x80071DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_107:
    // 0x80071DA4: jal         0x80070CEC
    // 0x80071DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_TriggerBranch(rdram, ctx);
        goto after_72;
    // 0x80071DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
L_80071DAC:
    // 0x80071DAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80071DB0:
    // 0x80071DB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071DB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80071DB8: jr          $ra
    // 0x80071DBC: nop

    return;
    // 0x80071DBC: nop

;}
RECOMP_FUNC void Audio_AudioListRemove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80012C44: beq         $v0, $zero, L_80012C64
    if (ctx->r2 == 0) {
        // 0x80012C48: nop
    
            goto L_80012C64;
    }
    // 0x80012C48: nop

    // 0x80012C4C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80012C50: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012C54: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80012C58: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80012C5C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80012C60: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80012C64:
    // 0x80012C64: jr          $ra
    // 0x80012C68: nop

    return;
    // 0x80012C68: nop

;}
RECOMP_FUNC void Display_LockOnIndicator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057504: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80057508: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8005750C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80057510: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80057514: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80057518: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8005751C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80057520: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80057524: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80057528: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8005752C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80057530: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80057534: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80057538: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8005753C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80057540: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80057544: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80057548: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005754C: lw          $v1, 0x78A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78A8);
    // 0x80057550: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80057554: addiu       $s0, $s0, 0x1578
    ctx->r16 = ADD32(ctx->r16, 0X1578);
    // 0x80057558: blez        $v1, L_8005778C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005755C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8005778C;
    }
    // 0x8005755C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80057560: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80057564: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80057568: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005756C: lwc1        $f26, 0x5F64($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5F64);
    // 0x80057570: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80057574: lui         $s7, 0xFF00
    ctx->r23 = S32(0XFF00 << 16);
    // 0x80057578: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8005757C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80057580: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80057584: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80057588: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8005758C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80057590: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80057594: ori         $s7, $s7, 0xFF
    ctx->r23 = ctx->r23 | 0XFF;
    // 0x80057598: addiu       $fp, $zero, 0x64
    ctx->r30 = ADD32(0, 0X64);
L_8005759C:
    // 0x8005759C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800575A0: c.lt.s      $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f14.fl < ctx->f24.fl;
    // 0x800575A4: nop

    // 0x800575A8: bc1fl       L_80057780
    if (!c1cs) {
        // 0x800575AC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80057780;
    }
    goto skip_0;
    // 0x800575AC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_0:
    // 0x800575B0: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800575B4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800575B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800575BC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800575C0: lwc1        $f16, 0x5F68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5F68);
    // 0x800575C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800575C8: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800575CC: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x800575D0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800575D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800575D8: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800575DC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800575E0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800575E4: nop

    // 0x800575E8: bc1fl       L_80057780
    if (!c1cs) {
        // 0x800575EC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80057780;
    }
    goto skip_1;
    // 0x800575EC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_1:
    // 0x800575F0: lwc1        $f18, 0x5F6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F6C);
    // 0x800575F4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800575F8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800575FC: mul.s       $f20, $f0, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80057600: addiu       $t7, $t7, 0x15B8
    ctx->r15 = ADD32(ctx->r15, 0X15B8);
    // 0x80057604: addiu       $t6, $t6, 0x15A8
    ctx->r14 = ADD32(ctx->r14, 0X15A8);
    // 0x80057608: lui         $s6, 0x102
    ctx->r22 = S32(0X102 << 16);
    // 0x8005760C: addiu       $s6, $s6, 0x4F60
    ctx->r22 = ADD32(ctx->r22, 0X4F60);
    // 0x80057610: addu        $s3, $v0, $t6
    ctx->r19 = ADD32(ctx->r2, ctx->r14);
    // 0x80057614: addu        $s4, $v0, $t7
    ctx->r20 = ADD32(ctx->r2, ctx->r15);
    // 0x80057618: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8005761C: nop

    // 0x80057620: bc1fl       L_80057630
    if (!c1cs) {
        // 0x80057624: c.lt.s      $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
            goto L_80057630;
    }
    goto skip_2;
    // 0x80057624: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    skip_2:
    // 0x80057628: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8005762C: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
L_80057630:
    // 0x80057630: nop

    // 0x80057634: bc1f        L_80057640
    if (!c1cs) {
        // 0x80057638: nop
    
            goto L_80057640;
    }
    // 0x80057638: nop

    // 0x8005763C: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_80057640:
    // 0x80057640: jal         0x80005708
    // 0x80057644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80057644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80057648: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005764C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80057650: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80057654: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80057658: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8005765C: jal         0x80005B00
    // 0x80057660: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80057660: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x80057664: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80057668: lw          $t9, 0x7854($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7854);
    // 0x8005766C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80057670: beql        $fp, $t9, L_800576BC
    if (ctx->r30 == ctx->r25) {
        // 0x80057674: lwc1        $f4, 0x0($s4)
        ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
            goto L_800576BC;
    }
    goto skip_3;
    // 0x80057674: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    skip_3:
    // 0x80057678: lw          $t0, 0x78A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A0);
    // 0x8005767C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80057680: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80057684: bnel        $s5, $t0, L_800576BC
    if (ctx->r21 != ctx->r8) {
        // 0x80057688: lwc1        $f4, 0x0($s4)
        ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
            goto L_800576BC;
    }
    goto skip_4;
    // 0x80057688: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    skip_4:
    // 0x8005768C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80057690: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80057694: jal         0x8009BC2C
    // 0x80057698: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80057698: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_2:
    // 0x8005769C: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x800576A0: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x800576A4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800576A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800576AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800576B0: jal         0x8009BC2C
    // 0x800576B4: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800576B4: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_3:
    // 0x800576B8: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
L_800576BC:
    // 0x800576BC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800576C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800576C4: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800576C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800576CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800576D0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800576D4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800576D8: mul.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800576DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800576E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800576E4: jal         0x80005C34
    // 0x800576E8: nop

    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x800576E8: nop

    after_4:
    // 0x800576EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800576F0: lwc1        $f8, 0x5F70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F70);
    // 0x800576F4: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800576F8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800576FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057700: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80057704: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80057708: jal         0x80005FE0
    // 0x8005770C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8005770C: nop

    after_5:
    // 0x80057710: jal         0x80006EB8
    // 0x80057714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80057714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80057718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005771C: jal         0x800B8DD0
    // 0x80057720: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x80057720: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_7:
    // 0x80057724: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80057728: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8005772C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80057730: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80057734: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x80057738: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005773C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80057740: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80057744: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80057748: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8005774C: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x80057750: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80057754: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80057758: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005775C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80057760: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80057764: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x80057768: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005776C: jal         0x80005740
    // 0x80057770: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x80057770: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80057774: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80057778: lw          $v1, 0x78A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78A8);
    // 0x8005777C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80057780:
    // 0x80057780: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80057784: bne         $at, $zero, L_8005759C
    if (ctx->r1 != 0) {
        // 0x80057788: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8005759C;
    }
    // 0x80057788: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8005778C:
    // 0x8005778C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80057790: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80057794: blez        $v1, L_800577CC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80057798: lui         $t8, 0x8016
        ctx->r24 = S32(0X8016 << 16);
            goto L_800577CC;
    }
    // 0x80057798: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8005779C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800577A0: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x800577A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800577A8: addiu       $v0, $t8, 0x1578
    ctx->r2 = ADD32(ctx->r24, 0X1578);
    // 0x800577AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800577B0: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
L_800577B4:
    // 0x800577B4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800577B8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800577BC: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800577C0: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
    // 0x800577C4: bne         $at, $zero, L_800577B4
    if (ctx->r1 != 0) {
        // 0x800577C8: swc1        $f22, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f22.u32l;
            goto L_800577B4;
    }
    // 0x800577C8: swc1        $f22, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f22.u32l;
L_800577CC:
    // 0x800577CC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800577D0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800577D4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800577D8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800577DC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800577E0: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800577E4: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800577E8: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800577EC: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800577F0: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800577F4: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800577F8: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800577FC: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80057800: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80057804: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80057808: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8005780C: jr          $ra
    // 0x80057810: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80057810: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Matrix_RotateX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005D4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80005D50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80005D54: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005D58: jal         0x80023090
    // 0x80005D5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80005D5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80005D60: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005D64: jal         0x80023250
    // 0x80005D68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80005D68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80005D6C: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80005D70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005D74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80005D78: bne         $t6, $at, L_80005E30
    if (ctx->r14 != ctx->r1) {
        // 0x80005D7C: lwc1        $f14, 0x18($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80005E30;
    }
    // 0x80005D7C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80005D80: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80005D84: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80005D88: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005D8C: nop

    // 0x80005D90: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005D94: nop

    // 0x80005D98: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005D9C: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80005DA0: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005DA4: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80005DA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005DAC: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005DB0: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80005DB4: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005DB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80005DBC: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005DC0: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80005DC4: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005DC8: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80005DCC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005DD0: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80005DD4: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005DD8: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80005DDC: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005DE0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80005DE4: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005DE8: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80005DEC: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005DF0: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80005DF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005DF8: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80005DFC: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005E00: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80005E04: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005E08: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80005E0C: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005E10: nop

    // 0x80005E14: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005E18: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80005E1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005E20: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x80005E24: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80005E28: b           L_80005E80
    // 0x80005E2C: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
        goto L_80005E80;
    // 0x80005E2C: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
L_80005E30:
    // 0x80005E30: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80005E34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80005E38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80005E3C: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x80005E40: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80005E44: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80005E48: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
    // 0x80005E4C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x80005E50: swc1        $f2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f2.u32l;
    // 0x80005E54: swc1        $f2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f2.u32l;
    // 0x80005E58: swc1        $f2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f2.u32l;
    // 0x80005E5C: swc1        $f2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f2.u32l;
    // 0x80005E60: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x80005E64: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80005E68: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x80005E6C: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x80005E70: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80005E74: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x80005E78: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
    // 0x80005E7C: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
L_80005E80:
    // 0x80005E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005E84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005E88: jr          $ra
    // 0x80005E8C: nop

    return;
    // 0x80005E8C: nop

;}
RECOMP_FUNC void AudioHeap_InitPool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF6C: addiu       $v0, $a1, 0xF
    ctx->r2 = ADD32(ctx->r5, 0XF);
    // 0x8000BF70: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000BF74: andi        $t7, $a1, 0xF
    ctx->r15 = ctx->r5 & 0XF;
    // 0x8000BF78: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8000BF7C: subu        $t8, $a2, $t7
    ctx->r24 = SUB32(ctx->r6, ctx->r15);
    // 0x8000BF80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000BF84: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8000BF88: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8000BF8C: jr          $ra
    // 0x8000BF90: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    return;
    // 0x8000BF90: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
;}
RECOMP_FUNC void HUD_LoseLifeExplosion_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088784: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80088788: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008878C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80088790: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80088794: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80088798: addiu       $t7, $t7, 0x1D4C
    ctx->r15 = ADD32(ctx->r15, 0X1D4C);
    // 0x8008879C: addiu       $t0, $t7, 0x48
    ctx->r8 = ADD32(ctx->r15, 0X48);
    // 0x800887A0: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
L_800887A4:
    // 0x800887A4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800887A8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800887AC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800887B0: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800887B4: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800887B8: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800887BC: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800887C0: bne         $t7, $t0, L_800887A4
    if (ctx->r15 != ctx->r8) {
        // 0x800887C4: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_800887A4;
    }
    // 0x800887C4: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800887C8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800887CC: addiu       $t2, $t2, 0x1D94
    ctx->r10 = ADD32(ctx->r10, 0X1D94);
    // 0x800887D0: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x800887D4: addiu       $t1, $sp, 0x84
    ctx->r9 = ADD32(ctx->r29, 0X84);
L_800887D8:
    // 0x800887D8: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800887DC: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800887E0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800887E4: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x800887E8: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x800887EC: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x800887F0: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x800887F4: bne         $t2, $t5, L_800887D8
    if (ctx->r10 != ctx->r13) {
        // 0x800887F8: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_800887D8;
    }
    // 0x800887F8: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x800887FC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80088800: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80088804: addiu       $t8, $t8, 0x1DC8
    ctx->r24 = ADD32(ctx->r24, 0X1DC8);
    // 0x80088808: addiu       $t6, $t8, 0x48
    ctx->r14 = ADD32(ctx->r24, 0X48);
    // 0x8008880C: addiu       $t9, $sp, 0x3C
    ctx->r25 = ADD32(ctx->r29, 0X3C);
    // 0x80088810: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
L_80088814:
    // 0x80088814: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80088818: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8008881C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80088820: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x80088824: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x80088828: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x8008882C: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x80088830: bne         $t8, $t6, L_80088814
    if (ctx->r24 != ctx->r14) {
        // 0x80088834: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_80088814;
    }
    // 0x80088834: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x80088838: beq         $a2, $zero, L_8008895C
    if (ctx->r6 == 0) {
        // 0x8008883C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8008895C;
    }
    // 0x8008883C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80088840: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80088844: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80088848: sw          $a2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r6;
    // 0x8008884C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80088850: jal         0x800B8DD0
    // 0x80088854: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80088854: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x80088858: lw          $a2, 0x100($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X100);
    // 0x8008885C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80088860: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80088864: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x80088868: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8008886C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80088870: addu        $t5, $sp, $a1
    ctx->r13 = ADD32(ctx->r29, ctx->r5);
    // 0x80088874: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80088878: lw          $t5, 0x3C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3C);
    // 0x8008887C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80088880: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80088884: andi        $t2, $t5, 0xFF
    ctx->r10 = ctx->r13 & 0XFF;
    // 0x80088888: or          $t1, $t2, $at
    ctx->r9 = ctx->r10 | ctx->r1;
    // 0x8008888C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80088890: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80088894: jal         0x80005708
    // 0x80088898: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80088898: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8008889C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800888A0: lui         $a1, 0x4079
    ctx->r5 = S32(0X4079 << 16);
    // 0x800888A4: lui         $a2, 0xC053
    ctx->r6 = S32(0XC053 << 16);
    // 0x800888A8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x800888AC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800888B0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800888B4: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    // 0x800888B8: jal         0x80005B00
    // 0x800888BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x800888BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x800888C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800888C4: lwc1        $f0, 0x78A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X78A8);
    // 0x800888C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800888CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800888D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800888D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800888D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800888DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800888E0: jal         0x80005C34
    // 0x800888E4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x800888E4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x800888E8: jal         0x80006EB8
    // 0x800888EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x800888EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800888F0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800888F4: lbu         $t0, 0x7C98($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7C98);
    // 0x800888F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800888FC: bnel        $t0, $zero, L_80088934
    if (ctx->r8 != 0) {
        // 0x80088900: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80088934;
    }
    goto skip_0;
    // 0x80088900: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80088904: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80088908: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8008890C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80088910: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80088914: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80088918: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008891C: addu        $t4, $sp, $t9
    ctx->r12 = ADD32(ctx->r29, ctx->r25);
    // 0x80088920: lw          $t4, 0xB8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XB8);
    // 0x80088924: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80088928: b           L_80088954
    // 0x8008892C: nop

        goto L_80088954;
    // 0x8008892C: nop

    // 0x80088930: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80088934:
    // 0x80088934: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80088938: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8008893C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80088940: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80088944: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80088948: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x8008894C: lw          $t1, 0x84($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X84);
    // 0x80088950: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_80088954:
    // 0x80088954: jal         0x80005740
    // 0x80088958: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x80088958: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
L_8008895C:
    // 0x8008895C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80088960: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80088964: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // 0x80088968: jr          $ra
    // 0x8008896C: nop

    return;
    // 0x8008896C: nop

;}
RECOMP_FUNC void Lib_TextureRect_IA8_FlipMirY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DF14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009DF18: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009DF1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DF20: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009DF24: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8009DF28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009DF2C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009DF30: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009DF34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009DF38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DF3C: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8009DF40: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009DF44: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009DF48: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009DF4C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DF50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DF54: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009DF58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009DF5C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009DF60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009DF64: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009DF68: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DF6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DF70: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009DF74: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009DF78: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009DF7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DF80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009DF84: mflo        $v0
    ctx->r2 = lo;
    // 0x8009DF88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009DF8C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x8009DF90: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x8009DF94: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009DF98: beql        $at, $zero, L_8009DFAC
    if (ctx->r1 == 0) {
        // 0x8009DF9C: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009DFAC;
    }
    goto skip_0;
    // 0x8009DF9C: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009DFA0: b           L_8009DFAC
    // 0x8009DFA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009DFAC;
    // 0x8009DFA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009DFA8: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009DFAC:
    // 0x8009DFAC: srl         $v0, $a2, 3
    ctx->r2 = S32(U32(ctx->r6) >> 3);
    // 0x8009DFB0: bne         $v0, $zero, L_8009DFC0
    if (ctx->r2 != 0) {
        // 0x8009DFB4: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_8009DFC0;
    }
    // 0x8009DFB4: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x8009DFB8: b           L_8009DFC4
    // 0x8009DFBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009DFC4;
    // 0x8009DFBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009DFC0:
    // 0x8009DFC0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009DFC4:
    // 0x8009DFC4: bne         $v0, $zero, L_8009DFD4
    if (ctx->r2 != 0) {
        // 0x8009DFC8: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8009DFD4;
    }
    // 0x8009DFC8: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8009DFCC: b           L_8009DFD8
    // 0x8009DFD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009DFD8;
    // 0x8009DFD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009DFD4:
    // 0x8009DFD4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009DFD8:
    // 0x8009DFD8: divu        $zero, $t7, $t3
    lo = S32(U32(ctx->r15) / U32(ctx->r11)); hi = S32(U32(ctx->r15) % U32(ctx->r11));
    // 0x8009DFDC: mflo        $t8
    ctx->r24 = lo;
    // 0x8009DFE0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009DFE4: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x8009DFE8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009DFEC: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x8009DFF0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009DFF4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009DFF8: bne         $t3, $zero, L_8009E004
    if (ctx->r11 != 0) {
        // 0x8009DFFC: nop
    
            goto L_8009E004;
    }
    // 0x8009DFFC: nop

    // 0x8009E000: break       7
    do_break(2148130816);
L_8009E004:
    // 0x8009E004: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E008: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009E00C: addiu       $t9, $t1, 0x7
    ctx->r25 = ADD32(ctx->r9, 0X7);
    // 0x8009E010: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E014: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E018: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E01C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009E020: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E024: srl         $t7, $t9, 3
    ctx->r15 = S32(U32(ctx->r25) >> 3);
    // 0x8009E028: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8009E02C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E030: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E034: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8009E038: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8009E03C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009E040: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E044: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E048: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E04C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009E050: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x8009E054: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009E058: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E05C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E060: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8009E064: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8009E068: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009E06C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8009E070: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009E074: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8009E078: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8009E07C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8009E080: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8009E084: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009E088: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009E08C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009E090: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009E094: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009E098: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009E09C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009E0A0: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009E0A4: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009E0A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009E0AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E0B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E0B4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8009E0B8: bgez        $a3, L_8009E0CC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009E0BC: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8009E0CC;
    }
    // 0x8009E0BC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E0C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009E0C4: nop

    // 0x8009E0C8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009E0CC:
    // 0x8009E0CC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009E0D0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8009E0D4: lui         $at, 0xE500
    ctx->r1 = S32(0XE500 << 16);
    // 0x8009E0D8: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009E0DC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009E0E0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009E0E4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009E0E8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009E0EC: nop

    // 0x8009E0F0: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8009E0F4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8009E0F8: bgez        $a2, L_8009E110
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009E0FC: or          $t6, $t7, $at
        ctx->r14 = ctx->r15 | ctx->r1;
            goto L_8009E110;
    }
    // 0x8009E0FC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8009E100: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E104: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E108: nop

    // 0x8009E10C: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009E110:
    // 0x8009E110: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009E114: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009E118: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009E11C: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009E120: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009E124: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009E128: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009E12C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009E130: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009E134: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009E138: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E13C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009E140: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8009E144: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8009E148: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009E14C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009E150: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009E154: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009E158: div.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8009E15C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E160: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009E164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009E168: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8009E16C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E170: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009E174: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009E178: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009E17C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E180: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009E184: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009E188: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E18C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E190: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E194: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009E198: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009E19C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009E1A0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8009E1A4: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8009E1A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009E1AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E1B0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009E1B4: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009E1B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009E1BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E1C0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009E1C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009E1C8: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8009E1CC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8009E1D0: nop

    // 0x8009E1D4: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8009E1D8: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8009E1DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009E1E0: jr          $ra
    // 0x8009E1E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8009E1E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Fault_DisplayChar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800074AC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x800074B0: addiu       $t3, $t3, 0x5360
    ctx->r11 = ADD32(ctx->r11, 0X5360);
    // 0x800074B4: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800074B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800074BC: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x800074C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800074C4: lhu         $t5, 0x9D0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X9D0);
    // 0x800074C8: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800074CC: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800074D0: addiu       $t9, $t9, 0x4770
    ctx->r25 = ADD32(ctx->r25, 0X4770);
    // 0x800074D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800074D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800074DC: mflo        $t7
    ctx->r15 = lo;
    // 0x800074E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800074E4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800074E8: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800074EC: lw          $t8, 0x9CC($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X9CC);
    // 0x800074F0: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x800074F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800074F8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800074FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80007500: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x80007504: mfhi        $t6
    ctx->r14 = hi;
    // 0x80007508: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000750C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80007510: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80007514: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80007518: srlv        $t0, $t8, $t7
    ctx->r8 = S32(U32(ctx->r24) >> (ctx->r15 & 31));
    // 0x8000751C: addu        $v1, $t9, $t5
    ctx->r3 = ADD32(ctx->r25, ctx->r13);
    // 0x80007520: srl         $t1, $t0, 1
    ctx->r9 = S32(U32(ctx->r8) >> 1);
    // 0x80007524: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80007528: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
L_8000752C:
    // 0x8000752C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80007530: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80007534: and         $t9, $t0, $a1
    ctx->r25 = ctx->r8 & ctx->r5;
    // 0x80007538: beq         $t9, $zero, L_80007548
    if (ctx->r25 == 0) {
        // 0x8000753C: and         $t5, $t1, $a1
        ctx->r13 = ctx->r9 & ctx->r5;
            goto L_80007548;
    }
    // 0x8000753C: and         $t5, $t1, $a1
    ctx->r13 = ctx->r9 & ctx->r5;
    // 0x80007540: b           L_8000754C
    // 0x80007544: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
        goto L_8000754C;
    // 0x80007544: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_80007548:
    // 0x80007548: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8000754C:
    // 0x8000754C: beq         $t5, $zero, L_8000755C
    if (ctx->r13 == 0) {
        // 0x80007550: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8000755C;
    }
    // 0x80007550: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80007554: b           L_80007560
    // 0x80007558: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
        goto L_80007560;
    // 0x80007558: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_8000755C:
    // 0x8000755C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_80007560:
    // 0x80007560: srl         $t6, $a0, 1
    ctx->r14 = S32(U32(ctx->r4) >> 1);
    // 0x80007564: and         $t8, $t6, $a1
    ctx->r24 = ctx->r14 & ctx->r5;
    // 0x80007568: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000756C: beq         $t8, $zero, L_8000757C
    if (ctx->r24 == 0) {
        // 0x80007570: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8000757C;
    }
    // 0x80007570: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80007574: b           L_80007580
    // 0x80007578: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
        goto L_80007580;
    // 0x80007578: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_8000757C:
    // 0x8000757C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_80007580:
    // 0x80007580: srl         $t7, $a0, 1
    ctx->r15 = S32(U32(ctx->r4) >> 1);
    // 0x80007584: and         $t9, $t7, $a1
    ctx->r25 = ctx->r15 & ctx->r5;
    // 0x80007588: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8000758C: beq         $t9, $zero, L_8000759C
    if (ctx->r25 == 0) {
        // 0x80007590: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8000759C;
    }
    // 0x80007590: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80007594: b           L_800075A0
    // 0x80007598: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
        goto L_800075A0;
    // 0x80007598: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_8000759C:
    // 0x8000759C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_800075A0:
    // 0x800075A0: srl         $t5, $a0, 1
    ctx->r13 = S32(U32(ctx->r4) >> 1);
    // 0x800075A4: and         $t6, $t5, $a1
    ctx->r14 = ctx->r13 & ctx->r5;
    // 0x800075A8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800075AC: beq         $t6, $zero, L_800075BC
    if (ctx->r14 == 0) {
        // 0x800075B0: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800075BC;
    }
    // 0x800075B0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800075B4: b           L_800075C0
    // 0x800075B8: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
        goto L_800075C0;
    // 0x800075B8: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_800075BC:
    // 0x800075BC: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_800075C0:
    // 0x800075C0: srl         $t8, $a0, 1
    ctx->r24 = S32(U32(ctx->r4) >> 1);
    // 0x800075C4: and         $t7, $t8, $a1
    ctx->r15 = ctx->r24 & ctx->r5;
    // 0x800075C8: beq         $t7, $zero, L_800075D8
    if (ctx->r15 == 0) {
        // 0x800075CC: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800075D8;
    }
    // 0x800075CC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800075D0: b           L_800075DC
    // 0x800075D4: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
        goto L_800075DC;
    // 0x800075D4: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_800075D8:
    // 0x800075D8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_800075DC:
    // 0x800075DC: lhu         $t9, 0x9D0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X9D0);
    // 0x800075E0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800075E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800075E8: addiu       $t5, $t9, -0x6
    ctx->r13 = ADD32(ctx->r25, -0X6);
    // 0x800075EC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800075F0: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800075F4: bnel        $a3, $t2, L_8000752C
    if (ctx->r7 != ctx->r10) {
        // 0x800075F8: lw          $a1, 0x0($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X0);
            goto L_8000752C;
    }
    goto skip_0;
    // 0x800075F8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800075FC: jr          $ra
    // 0x80007600: nop

    return;
    // 0x80007600: nop

;}
RECOMP_FUNC void Game_InitFullViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1F44: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A1F48: addiu       $v1, $v1, 0x7E58
    ctx->r3 = ADD32(ctx->r3, 0X7E58);
    // 0x800A1F4C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800A1F50: addiu       $t6, $zero, 0x280
    ctx->r14 = ADD32(0, 0X280);
    // 0x800A1F54: addiu       $t9, $zero, 0x1E0
    ctx->r25 = ADD32(0, 0X1E0);
    // 0x800A1F58: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x800A1F5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A1F60: addiu       $t2, $zero, 0x1FF
    ctx->r10 = ADD32(0, 0X1FF);
    // 0x800A1F64: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800A1F68: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800A1F6C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800A1F70: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
    // 0x800A1F74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A1F78: lh          $t1, 0xA($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XA);
    // 0x800A1F7C: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x800A1F80: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800A1F84: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x800A1F88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A1F8C: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x800A1F90: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    // 0x800A1F94: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800A1F98: sh          $zero, 0xE($t5)
    MEM_H(0XE, ctx->r13) = 0;
    // 0x800A1F9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A1FA0: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x800A1FA4: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x800A1FA8: jr          $ra
    // 0x800A1FAC: nop

    return;
    // 0x800A1FAC: nop

;}
RECOMP_FUNC void RCP_SetupDL_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA1A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA1A4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA1A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA1AC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA1B0: addiu       $t8, $t8, 0x3828
    ctx->r24 = ADD32(ctx->r24, 0X3828);
    // 0x800BA1B4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA1B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA1BC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA1C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA1C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA1C8: jr          $ra
    // 0x800BA1CC: nop

    return;
    // 0x800BA1CC: nop

;}
RECOMP_FUNC void ActorEvent_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061F10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061F14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80061F18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061F1C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80061F20: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80061F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061F28: jal         0x800613C4
    // 0x80061F2C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80061F2C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80061F30: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80061F34: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80061F38: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80061F3C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80061F40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061F44: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x80061F48: sw          $t7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r15;
    // 0x80061F4C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80061F50: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80061F54: addiu       $t6, $zero, 0xFFF
    ctx->r14 = ADD32(0, 0XFFF);
    // 0x80061F58: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80061F5C: andi        $a1, $t4, 0xFFFF
    ctx->r5 = ctx->r12 & 0XFFFF;
    // 0x80061F60: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80061F64: lh          $t8, 0x4($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X4);
    // 0x80061F68: lwc1        $f8, 0x6440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6440);
    // 0x80061F6C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80061F70: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80061F74: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80061F78: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061F7C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80061F80: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80061F84: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80061F88: lh          $t9, 0x6($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X6);
    // 0x80061F8C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80061F90: nop

    // 0x80061F94: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061F98: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80061F9C: lh          $t0, 0x8($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X8);
    // 0x80061FA0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80061FA4: nop

    // 0x80061FA8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061FAC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80061FB0: lh          $t1, 0xC($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XC);
    // 0x80061FB4: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80061FB8: nop

    // 0x80061FBC: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061FC0: swc1        $f0, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f0.u32l;
    // 0x80061FC4: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80061FC8: lh          $t2, 0xA($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XA);
    // 0x80061FCC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80061FD0: nop

    // 0x80061FD4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80061FD8: swc1        $f0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f0.u32l;
    // 0x80061FDC: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80061FE0: lh          $t3, 0xE($a3)
    ctx->r11 = MEM_H(ctx->r7, 0XE);
    // 0x80061FE4: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
    // 0x80061FE8: sh          $t5, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r13;
    // 0x80061FEC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80061FF0: sh          $t6, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r14;
    // 0x80061FF4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061FF8: swc1        $f8, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f8.u32l;
    // 0x80061FFC: lh          $t7, 0x10($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X10);
    // 0x80062000: addiu       $t8, $t7, -0x3E8
    ctx->r24 = ADD32(ctx->r15, -0X3E8);
    // 0x80062004: jal         0x800612B8
    // 0x80062008: sh          $t8, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r24;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80062008: sh          $t8, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r24;
    after_1:
    // 0x8006200C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062010: lwc1        $f16, 0x6444($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6444);
    // 0x80062014: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062018: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006201C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80062020: lwc1        $f4, 0x6448($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6448);
    // 0x80062024: addiu       $v0, $v0, 0x7E70
    ctx->r2 = ADD32(ctx->r2, 0X7E70);
    // 0x80062028: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8006202C: swc1        $f4, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f4.u32l;
    // 0x80062030: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80062034: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80062038: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006203C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    // 0x80062040: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80062044: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062048: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8006204C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80062050: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80062054: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80062058: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8006205C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80062060: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80062064: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80062068: lh          $t2, 0x40C4($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X40C4);
    // 0x8006206C: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x80062070: lwc1        $f18, 0x1A54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x80062074: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80062078: swc1        $f18, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f18.u32l;
    // 0x8006207C: lwc1        $f6, 0x7E90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7E90);
    // 0x80062080: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062084: lwc1        $f8, 0x644C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X644C);
    // 0x80062088: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8006208C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80062090: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80062094: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80062098: jal         0x80005FE0
    // 0x8006209C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8006209C: nop

    after_2:
    // 0x800620A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800620A4: lwc1        $f4, 0x7E88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E88);
    // 0x800620A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800620AC: lwc1        $f6, 0x6450($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x800620B0: neg.s       $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = -ctx->f4.fl;
    // 0x800620B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800620B8: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800620BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800620C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800620C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800620C8: jal         0x80005D44
    // 0x800620CC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x800620CC: nop

    after_3:
    // 0x800620D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800620D4: lwc1        $f8, 0x7E8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7E8C);
    // 0x800620D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800620DC: lwc1        $f4, 0x6454($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6454);
    // 0x800620E0: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800620E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800620E8: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800620EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800620F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800620F4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800620F8: jal         0x80005E90
    // 0x800620FC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x800620FC: nop

    after_4:
    // 0x80062100: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80062104: addiu       $v0, $v0, 0x7F10
    ctx->r2 = ADD32(ctx->r2, 0X7F10);
    // 0x80062108: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8006210C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80062110: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80062114: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80062118: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8006211C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80062120: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80062124: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80062128: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8006212C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80062130: addiu       $a2, $s0, 0x2DC
    ctx->r6 = ADD32(ctx->r16, 0X2DC);
    // 0x80062134: sub.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80062138: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8006213C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80062140: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80062144: jal         0x80006A20
    // 0x80062148: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x80062148: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8006214C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80062150: lw          $t3, 0x7E78($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7E78);
    // 0x80062154: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80062158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006215C: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x80062160: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80062164: jal         0x80069AAC
    // 0x80062168: sw          $t4, 0x7E70($at)
    MEM_W(0X7E70, ctx->r1) = ctx->r12;
    Actor_Update(rdram, ctx);
        goto after_6;
    // 0x80062168: sw          $t4, 0x7E70($at)
    MEM_W(0X7E70, ctx->r1) = ctx->r12;
    after_6:
    // 0x8006216C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062174: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80062178: jr          $ra
    // 0x8006217C: nop

    return;
    // 0x8006217C: nop

;}
RECOMP_FUNC void HUD_PlayerShield_GoldRings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B73C: jal         0x8008B2F0
    // 0x8008B740: nop

    HUD_PlayerShieldGauge_Update(rdram, ctx);
        goto after_0;
    // 0x8008B740: nop

    after_0:
    // 0x8008B744: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8008B748: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008B74C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008B750: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008B754: jal         0x8008B5B0
    // 0x8008B758: nop

    HUD_PlayerShieldGauge_Draw(rdram, ctx);
        goto after_1;
    // 0x8008B758: nop

    after_1:
    // 0x8008B75C: jal         0x80085944
    // 0x8008B760: nop

    HUD_GoldRings_Draw(rdram, ctx);
        goto after_2;
    // 0x8008B760: nop

    after_2:
    // 0x8008B764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B76C: jr          $ra
    // 0x8008B770: nop

    return;
    // 0x8008B770: nop

;}
RECOMP_FUNC void AudioSynth_DisableSampleStates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009A2C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80009A30: addiu       $a2, $a2, 0x5C78
    ctx->r6 = ADD32(ctx->r6, 0X5C78);
    // 0x80009A34: lh          $t6, 0xC($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XC);
    // 0x80009A38: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80009A3C: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80009A40: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80009A44: beq         $at, $zero, L_80009AA4
    if (ctx->r1 == 0) {
        // 0x80009A48: lui         $a3, 0x8015
        ctx->r7 = S32(0X8015 << 16);
            goto L_80009AA4;
    }
    // 0x80009A48: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80009A4C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80009A50: addiu       $a1, $a1, -0x3E48
    ctx->r5 = ADD32(ctx->r5, -0X3E48);
    // 0x80009A54: addiu       $a3, $a3, 0x5CA0
    ctx->r7 = ADD32(ctx->r7, 0X5CA0);
    // 0x80009A58: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_80009A5C:
    // 0x80009A5C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80009A60: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009A64: mflo        $t9
    ctx->r25 = lo;
    // 0x80009A68: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80009A6C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80009A70: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x80009A74: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80009A78: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80009A7C: bltz        $t4, L_80009AA4
    if (SIGNED(ctx->r12) < 0) {
        // 0x80009A80: nop
    
            goto L_80009AA4;
    }
    // 0x80009A80: nop

    // 0x80009A84: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x80009A88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009A8C: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x80009A90: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80009A94: lh          $t8, 0xC($a2)
    ctx->r24 = MEM_H(ctx->r6, 0XC);
    // 0x80009A98: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80009A9C: bnel        $at, $zero, L_80009A5C
    if (ctx->r1 != 0) {
        // 0x80009AA0: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_80009A5C;
    }
    goto skip_0;
    // 0x80009AA0: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_0:
L_80009AA4:
    // 0x80009AA4: jr          $ra
    // 0x80009AA8: nop

    return;
    // 0x80009AA8: nop

;}
RECOMP_FUNC void __lroundf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF20: round.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = lroundf(ctx->f12.fl);
    // 0x8001FF24: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001FF28: jr          $ra
    // 0x8001FF2C: nop

    return;
    // 0x8001FF2C: nop

;}
RECOMP_FUNC void Effect_SmallRock_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F438: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007F43C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007F440: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007F444: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007F448: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007F44C: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8007F450: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007F454: bne         $t6, $at, L_8007F548
    if (ctx->r14 != ctx->r1) {
        // 0x8007F458: lui         $at, 0x4060
        ctx->r1 = S32(0X4060 << 16);
            goto L_8007F548;
    }
    // 0x8007F458: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8007F45C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007F460: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007F464: lh          $t7, 0x44($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X44);
    // 0x8007F468: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007F46C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007F470: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007F474: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8007F478: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007F47C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8007F480: beq         $t7, $zero, L_8007F4B0
    if (ctx->r15 == 0) {
        // 0x8007F484: swc1        $f10, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
            goto L_8007F4B0;
    }
    // 0x8007F484: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    // 0x8007F488: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F48C: lwc1        $f16, 0x7494($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7494);
    // 0x8007F490: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8007F494: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8007F498: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007F49C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8007F4A0: jal         0x8009BC2C
    // 0x8007F4A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007F4A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8007F4A8: b           L_8007F4CC
    // 0x8007F4AC: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
        goto L_8007F4CC;
    // 0x8007F4AC: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
L_8007F4B0:
    // 0x8007F4B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F4B4: lwc1        $f18, 0x7498($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7498);
    // 0x8007F4B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007F4BC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8007F4C0: jal         0x8009BC2C
    // 0x8007F4C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8007F4C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8007F4C8: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
L_8007F4CC:
    // 0x8007F4CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007F4D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007F4D4: bne         $v0, $zero, L_8007F500
    if (ctx->r2 != 0) {
        // 0x8007F4D8: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8007F500;
    }
    // 0x8007F4D8: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8007F4DC: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x8007F4E0: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8007F4E4: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
    // 0x8007F4E8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8007F4EC: sh          $t0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r8;
    // 0x8007F4F0: lh          $t1, 0x44($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X44);
    // 0x8007F4F4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8007F4F8: b           L_8007F504
    // 0x8007F4FC: sh          $t2, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r10;
        goto L_8007F504;
    // 0x8007F4FC: sh          $t2, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r10;
L_8007F500:
    // 0x8007F500: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
L_8007F504:
    // 0x8007F504: lwc1        $f4, 0x7D08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8007F508: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8007F50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007F510: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8007F514: nop

    // 0x8007F518: bc1fl       L_8007F530
    if (!c1cs) {
        // 0x8007F51C: lhu         $t4, 0x50($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X50);
            goto L_8007F530;
    }
    goto skip_0;
    // 0x8007F51C: lhu         $t4, 0x50($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X50);
    skip_0:
    // 0x8007F520: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007F524: nop

    // 0x8007F528: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    // 0x8007F52C: lhu         $t4, 0x50($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X50);
L_8007F530:
    // 0x8007F530: bnel        $t4, $zero, L_8007F59C
    if (ctx->r12 != 0) {
        // 0x8007F534: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007F59C;
    }
    goto skip_1;
    // 0x8007F534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8007F538: jal         0x80060FBC
    // 0x8007F53C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8007F53C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_2:
    // 0x8007F540: b           L_8007F59C
    // 0x8007F544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007F59C;
    // 0x8007F544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007F548:
    // 0x8007F548: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8007F54C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007F550: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007F554: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8007F558: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F55C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8007F560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007F564: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8007F568: lbu         $t5, 0x7C98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C98);
    // 0x8007F56C: bnel        $t5, $zero, L_8007F588
    if (ctx->r13 != 0) {
        // 0x8007F570: lhu         $t6, 0x50($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X50);
            goto L_8007F588;
    }
    goto skip_2;
    // 0x8007F570: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
    skip_2:
    // 0x8007F574: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007F578: lwc1        $f6, 0x749C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X749C);
    // 0x8007F57C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007F580: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007F584: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
L_8007F588:
    // 0x8007F588: bnel        $t6, $zero, L_8007F59C
    if (ctx->r14 != 0) {
        // 0x8007F58C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007F59C;
    }
    goto skip_3;
    // 0x8007F58C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8007F590: jal         0x80060FBC
    // 0x8007F594: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8007F594: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_3:
    // 0x8007F598: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007F59C:
    // 0x8007F59C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007F5A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007F5A4: jr          $ra
    // 0x8007F5A8: nop

    return;
    // 0x8007F5A8: nop

;}
RECOMP_FUNC void Effect_Effect388_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80077B7C: jr          $ra
    // 0x80077B80: nop

    return;
    // 0x80077B80: nop

;}
RECOMP_FUNC void Aquas_AqCoralReef2_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009546C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80095470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095474: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80095478: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8009547C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80095480: addiu       $t7, $t7, 0x2540
    ctx->r15 = ADD32(ctx->r15, 0X2540);
    // 0x80095484: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80095488: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_8009548C:
    // 0x8009548C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80095490: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80095494: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80095498: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8009549C: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800954A0: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800954A4: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800954A8: bne         $t7, $t0, L_8009548C
    if (ctx->r15 != ctx->r8) {
        // 0x800954AC: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8009548C;
    }
    // 0x800954AC: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800954B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800954B4: jal         0x800613C4
    // 0x800954B8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800954B8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_0:
    // 0x800954BC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800954C0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800954C4: addiu       $t2, $zero, 0xC3
    ctx->r10 = ADD32(0, 0XC3);
    // 0x800954C8: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x800954CC: sh          $t2, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r10;
    // 0x800954D0: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800954D4: addiu       $t5, $sp, 0x1C
    ctx->r13 = ADD32(ctx->r29, 0X1C);
    // 0x800954D8: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x800954DC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800954E0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800954E4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800954E8: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800954EC: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800954F0: andi        $a1, $t2, 0xFFFF
    ctx->r5 = ctx->r10 & 0XFFFF;
    // 0x800954F4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800954F8: sw          $at, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r1;
    // 0x800954FC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80095500: sw          $t0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r8;
    // 0x80095504: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80095508: sw          $at, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r1;
    // 0x8009550C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095510: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80095514: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80095518: sh          $t7, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r15;
    // 0x8009551C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095520: jal         0x800612B8
    // 0x80095524: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80095524: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x80095528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009552C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80095530: jr          $ra
    // 0x80095534: nop

    return;
    // 0x80095534: nop

;}
RECOMP_FUNC void Display_OnFootPeppy_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052420: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052428: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005242C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80052430: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80052434: bne         $a0, $at, L_80052488
    if (ctx->r4 != ctx->r1) {
        // 0x80052438: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_80052488;
    }
    // 0x80052438: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8005243C: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80052440: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80052444: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80052448: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005244C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80052450: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80052454: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80052458: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8005245C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80052460: lw          $t6, 0x1C4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1C4);
    // 0x80052464: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80052468: addiu       $t8, $t8, 0x13B0
    ctx->r24 = ADD32(ctx->r24, 0X13B0);
    // 0x8005246C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80052470: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80052474: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80052478: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005247C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80052480: jal         0x80006970
    // 0x80052484: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x80052484: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_0:
L_80052488:
    // 0x80052488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005248C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052490: jr          $ra
    // 0x80052494: nop

    return;
    // 0x80052494: nop

;}
RECOMP_FUNC void Effect_WaterSpray_SetupCircle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AD58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007AD5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007AD60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007AD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007AD68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007AD6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007AD70: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007AD74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007AD78: jal         0x80061474
    // 0x8007AD7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007AD7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007AD80: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007AD84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007AD88: addiu       $t7, $zero, 0x174
    ctx->r15 = ADD32(0, 0X174);
    // 0x8007AD8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007AD90: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007AD94: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007AD98: sh          $t8, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r24;
    // 0x8007AD9C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007ADA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007ADA4: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8007ADA8: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007ADAC: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8007ADB0: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007ADB4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007ADB8: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007ADBC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007ADC0: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    // 0x8007ADC4: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007ADC8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007ADCC: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    // 0x8007ADD0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007ADD4: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x8007ADD8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007ADDC: jal         0x800612B8
    // 0x8007ADE0: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007ADE0: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    after_1:
    // 0x8007ADE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007ADE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007ADEC: jr          $ra
    // 0x8007ADF0: nop

    return;
    // 0x8007ADF0: nop

;}
RECOMP_FUNC void Effect_Effect367_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D950: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007D954: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007D958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D95C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007D960: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007D964: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007D968: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007D96C: jal         0x80061474
    // 0x8007D970: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007D970: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007D974: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007D978: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007D97C: addiu       $t7, $zero, 0x16F
    ctx->r15 = ADD32(0, 0X16F);
    // 0x8007D980: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007D984: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007D988: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007D98C: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x8007D990: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007D994: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007D998: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D99C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007D9A0: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007D9A4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007D9A8: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x8007D9AC: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007D9B0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D9B4: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    // 0x8007D9B8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D9BC: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x8007D9C0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007D9C4: jal         0x800612B8
    // 0x8007D9C8: sh          $t9, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r25;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007D9C8: sh          $t9, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r25;
    after_1:
    // 0x8007D9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D9D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007D9D4: jr          $ra
    // 0x8007D9D8: nop

    return;
    // 0x8007D9D8: nop

;}
RECOMP_FUNC void TexturedLine_UpdateAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A38C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A390: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A394: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A398: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006A39C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A3A0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8006A3A4: addiu       $s0, $s0, 0x4750
    ctx->r16 = ADD32(ctx->r16, 0X4750);
    // 0x8006A3A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A3AC: addiu       $s2, $zero, 0x64
    ctx->r18 = ADD32(0, 0X64);
L_8006A3B0:
    // 0x8006A3B0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8006A3B4: beql        $t6, $zero, L_8006A3C8
    if (ctx->r14 == 0) {
        // 0x8006A3B8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8006A3C8;
    }
    goto skip_0;
    // 0x8006A3B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8006A3BC: jal         0x8006A06C
    // 0x8006A3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    TexturedLine_Update(rdram, ctx);
        goto after_0;
    // 0x8006A3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006A3C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8006A3C8:
    // 0x8006A3C8: bne         $s1, $s2, L_8006A3B0
    if (ctx->r17 != ctx->r18) {
        // 0x8006A3CC: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_8006A3B0;
    }
    // 0x8006A3CC: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x8006A3D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006A3D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A3D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A3DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A3E0: jr          $ra
    // 0x8006A3E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006A3E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ActorEvent_CruiserGun_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074BFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80074C00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80074C04: bne         $a0, $at, L_80074C20
    if (ctx->r4 != ctx->r1) {
        // 0x80074C08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80074C20;
    }
    // 0x80074C08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80074C0C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80074C10: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80074C14: lwc1        $f6, 0x154($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X154);
    // 0x80074C18: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80074C1C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_80074C20:
    // 0x80074C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80074C24: bne         $a0, $at, L_80074C3C
    if (ctx->r4 != ctx->r1) {
        // 0x80074C28: lw          $t7, 0x10($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X10);
            goto L_80074C3C;
    }
    // 0x80074C28: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x80074C2C: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80074C30: lwc1        $f16, 0x150($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X150);
    // 0x80074C34: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80074C38: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
L_80074C3C:
    // 0x80074C3C: jr          $ra
    // 0x80074C40: nop

    return;
    // 0x80074C40: nop

;}
RECOMP_FUNC void Object_DrawShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ECD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005ECDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005ECE0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005ECE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005ECE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005ECEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005ECF0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005ECF4: jal         0x800B8DD0
    // 0x8005ECF8: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8005ECF8: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_0:
    // 0x8005ECFC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8005ED00: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x8005ED04: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8005ED08: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8005ED0C: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8005ED10: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005ED14: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005ED18: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005ED1C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005ED20: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x8005ED24: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005ED28: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x8005ED2C: bne         $a0, $at, L_8005ED64
    if (ctx->r4 != ctx->r1) {
        // 0x8005ED30: sll         $t1, $t9, 2
        ctx->r9 = S32(ctx->r25 << 2);
            goto L_8005ED64;
    }
    // 0x8005ED30: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005ED34: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8005ED38: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8005ED3C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8005ED40: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8005ED44: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8005ED48: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8005ED4C: addiu       $t2, $t2, 0x3FE0
    ctx->r10 = ADD32(ctx->r10, 0X3FE0);
    // 0x8005ED50: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8005ED54: jal         0x8005EA24
    // 0x8005ED58: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    ActorAllRange_DrawShadow(rdram, ctx);
        goto after_1;
    // 0x8005ED58: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x8005ED5C: b           L_8005F020
    // 0x8005ED60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005F020;
    // 0x8005ED60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005ED64:
    // 0x8005ED64: addiu       $at, $zero, 0xE5
    ctx->r1 = ADD32(0, 0XE5);
    // 0x8005ED68: beq         $a0, $at, L_8005EE10
    if (ctx->r4 == ctx->r1) {
        // 0x8005ED6C: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_8005EE10;
    }
    // 0x8005ED6C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005ED70: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x8005ED74: beq         $a0, $at, L_8005ED98
    if (ctx->r4 == ctx->r1) {
        // 0x8005ED78: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_8005ED98;
    }
    // 0x8005ED78: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005ED7C: addiu       $at, $zero, 0xE7
    ctx->r1 = ADD32(0, 0XE7);
    // 0x8005ED80: beq         $a0, $at, L_8005EE10
    if (ctx->r4 == ctx->r1) {
        // 0x8005ED84: addiu       $at, $zero, 0x13C
        ctx->r1 = ADD32(0, 0X13C);
            goto L_8005EE10;
    }
    // 0x8005ED84: addiu       $at, $zero, 0x13C
    ctx->r1 = ADD32(0, 0X13C);
    // 0x8005ED88: beq         $a0, $at, L_8005EE88
    if (ctx->r4 == ctx->r1) {
        // 0x8005ED8C: nop
    
            goto L_8005EE88;
    }
    // 0x8005ED8C: nop

    // 0x8005ED90: b           L_8005EED4
    // 0x8005ED94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
        goto L_8005EED4;
    // 0x8005ED94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
L_8005ED98:
    // 0x8005ED98: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005ED9C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8005EDA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005EDA4: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8005EDA8: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8005EDAC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8005EDB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EDB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005EDB8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8005EDBC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8005EDC0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8005EDC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005EDC8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8005EDCC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005EDD0: lwc1        $f10, 0x40F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X40F8);
    // 0x8005EDD4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005EDD8: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005EDDC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EDE0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8005EDE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EDE8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005EDEC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005EDF0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8005EDF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005EDF8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005EDFC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8005EE00: jal         0x80005B00
    // 0x8005EE04: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8005EE04: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x8005EE08: b           L_8005EF14
    // 0x8005EE0C: nop

        goto L_8005EF14;
    // 0x8005EE0C: nop

L_8005EE10:
    // 0x8005EE10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005EE14: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005EE18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005EE1C: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8005EE20: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005EE24: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005EE28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EE2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005EE30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EE34: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005EE38: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EE3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005EE40: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005EE44: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8005EE48: lwc1        $f18, 0x40F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X40F4);
    // 0x8005EE4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005EE50: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005EE54: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EE58: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8005EE5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EE60: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005EE64: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8005EE68: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8005EE6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005EE70: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005EE74: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8005EE78: jal         0x80005B00
    // 0x8005EE7C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8005EE7C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x8005EE80: b           L_8005EF14
    // 0x8005EE84: nop

        goto L_8005EF14;
    // 0x8005EE84: nop

L_8005EE88:
    // 0x8005EE88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005EE8C: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8005EE90: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EE94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005EE98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005EE9C: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005EEA0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8005EEA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EEA8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005EEAC: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005EEB0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005EEB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005EEB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005EEBC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005EEC0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8005EEC4: jal         0x80005B00
    // 0x8005EEC8: nop

    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x8005EEC8: nop

    after_4:
    // 0x8005EECC: b           L_8005EF14
    // 0x8005EED0: nop

        goto L_8005EF14;
    // 0x8005EED0: nop

L_8005EED4:
    // 0x8005EED4: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8005EED8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EEDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005EEE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005EEE4: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005EEE8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EEEC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8005EEF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EEF4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005EEF8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005EEFC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8005EF00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005EF04: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005EF08: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8005EF0C: jal         0x80005B00
    // 0x8005EF10: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x8005EF10: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
L_8005EF14:
    // 0x8005EF14: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005EF18: lw          $t2, -0x7B54($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7B54);
    // 0x8005EF1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005EF20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005EF24: bne         $t2, $at, L_8005EF48
    if (ctx->r10 != ctx->r1) {
        // 0x8005EF28: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005EF48;
    }
    // 0x8005EF28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005EF2C: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x8005EF30: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8005EF34: beq         $a0, $at, L_8005EF48
    if (ctx->r4 == ctx->r1) {
        // 0x8005EF38: addiu       $at, $zero, 0xC3
        ctx->r1 = ADD32(0, 0XC3);
            goto L_8005EF48;
    }
    // 0x8005EF38: addiu       $at, $zero, 0xC3
    ctx->r1 = ADD32(0, 0XC3);
    // 0x8005EF3C: beq         $a0, $at, L_8005EF48
    if (ctx->r4 == ctx->r1) {
        // 0x8005EF40: addiu       $at, $zero, 0xC6
        ctx->r1 = ADD32(0, 0XC6);
            goto L_8005EF48;
    }
    // 0x8005EF40: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x8005EF44: bne         $a0, $at, L_8005EF94
    if (ctx->r4 != ctx->r1) {
        // 0x8005EF48: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005EF94;
    }
L_8005EF48:
    // 0x8005EF48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005EF4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005EF50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EF54: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005EF58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005EF5C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005EF60: jal         0x80005C34
    // 0x8005EF64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x8005EF64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_6:
    // 0x8005EF68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005EF6C: lwc1        $f18, 0x6368($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6368);
    // 0x8005EF70: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005EF74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EF78: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005EF7C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8005EF80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005EF84: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005EF88: jal         0x80005E90
    // 0x8005EF8C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8005EF8C: nop

    after_7:
    // 0x8005EF90: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
L_8005EF94:
    // 0x8005EF94: slti        $at, $a0, 0x124
    ctx->r1 = SIGNED(ctx->r4) < 0X124 ? 1 : 0;
    // 0x8005EF98: beq         $at, $zero, L_8005F004
    if (ctx->r1 == 0) {
        // 0x8005EF9C: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_8005F004;
    }
    // 0x8005EF9C: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x8005EFA0: beq         $a0, $at, L_8005F004
    if (ctx->r4 == ctx->r1) {
        // 0x8005EFA4: addiu       $at, $zero, 0xE5
        ctx->r1 = ADD32(0, 0XE5);
            goto L_8005F004;
    }
    // 0x8005EFA4: addiu       $at, $zero, 0xE5
    ctx->r1 = ADD32(0, 0XE5);
    // 0x8005EFA8: beq         $a0, $at, L_8005F004
    if (ctx->r4 == ctx->r1) {
        // 0x8005EFAC: addiu       $at, $zero, 0xE7
        ctx->r1 = ADD32(0, 0XE7);
            goto L_8005F004;
    }
    // 0x8005EFAC: addiu       $at, $zero, 0xE7
    ctx->r1 = ADD32(0, 0XE7);
    // 0x8005EFB0: beq         $a0, $at, L_8005F004
    if (ctx->r4 == ctx->r1) {
        // 0x8005EFB4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005F004;
    }
    // 0x8005EFB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005EFB8: lwc1        $f6, 0x636C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X636C);
    // 0x8005EFBC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005EFC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EFC4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005EFC8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005EFCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005EFD0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005EFD4: jal         0x80005D44
    // 0x8005EFD8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8005EFD8: nop

    after_8:
    // 0x8005EFDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005EFE0: lwc1        $f18, 0x6370($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6370);
    // 0x8005EFE4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005EFE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005EFEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005EFF0: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8005EFF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005EFF8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005EFFC: jal         0x80005FE0
    // 0x8005F000: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x8005F000: nop

    after_9:
L_8005F004:
    // 0x8005F004: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F008: jal         0x80006EB8
    // 0x8005F00C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x8005F00C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_10:
    // 0x8005F010: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x8005F014: jal         0x8005BAB4
    // 0x8005F018: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    Object_SetShadowDL(rdram, ctx);
        goto after_11;
    // 0x8005F018: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x8005F01C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F020:
    // 0x8005F020: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005F024: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F028: jr          $ra
    // 0x8005F02C: nop

    return;
    // 0x8005F02C: nop

;}
RECOMP_FUNC void MeHopBot_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059A24: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x80059A28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059A2C: sw          $a0, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r4;
    // 0x80059A30: lw          $t6, 0x198($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X198);
    // 0x80059A34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059A38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059A3C: lh          $t7, 0xB6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XB6);
    // 0x80059A40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80059A44: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80059A48: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80059A4C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80059A50: lwc1        $f4, -0x650($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X650);
    // 0x80059A54: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80059A58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80059A5C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80059A60: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80059A64: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80059A68: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80059A6C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80059A70: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80059A74: jal         0x80005B00
    // 0x80059A78: nop

    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80059A78: nop

    after_0:
    // 0x80059A7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059A80: jal         0x80006EB8
    // 0x80059A84: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x80059A84: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x80059A88: lw          $t0, 0x198($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X198);
    // 0x80059A8C: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x80059A90: addiu       $a0, $a0, -0x173C
    ctx->r4 = ADD32(ctx->r4, -0X173C);
    // 0x80059A94: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80059A98: jal         0x8009AA20
    // 0x80059A9C: lh          $a1, 0xB6($t0)
    ctx->r5 = MEM_H(ctx->r8, 0XB6);
    Animation_GetFrameData(rdram, ctx);
        goto after_2;
    // 0x80059A9C: lh          $a1, 0xB6($t0)
    ctx->r5 = MEM_H(ctx->r8, 0XB6);
    after_2:
    // 0x80059AA0: lw          $t2, 0x198($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X198);
    // 0x80059AA4: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x80059AA8: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80059AAC: addiu       $t4, $t4, 0x4660
    ctx->r12 = ADD32(ctx->r12, 0X4660);
    // 0x80059AB0: addiu       $t1, $t1, -0x665C
    ctx->r9 = ADD32(ctx->r9, -0X665C);
    // 0x80059AB4: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80059AB8: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x80059ABC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80059AC0: addiu       $a1, $a1, -0x1630
    ctx->r5 = ADD32(ctx->r5, -0X1630);
    // 0x80059AC4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80059AC8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80059ACC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80059AD0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80059AD4: jal         0x8009A72C
    // 0x80059AD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_3;
    // 0x80059AD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80059ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059AE0: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    // 0x80059AE4: jr          $ra
    // 0x80059AE8: nop

    return;
    // 0x80059AE8: nop

;}
RECOMP_FUNC void Boss_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006177C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061780: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80061784: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80061788: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8006178C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80061790: jal         0x80061404
    // 0x80061794: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    Boss_Initialize(rdram, ctx);
        goto after_0;
    // 0x80061794: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80061798: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006179C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800617A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800617A4: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x800617A8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800617AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800617B0: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800617B4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800617B8: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800617BC: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800617C0: lwc1        $f8, 0x6428($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6428);
    // 0x800617C4: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800617C8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800617CC: nop

    // 0x800617D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800617D4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800617D8: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800617DC: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800617E0: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x800617E4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800617E8: nop

    // 0x800617EC: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800617F0: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x800617F4: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x800617F8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800617FC: nop

    // 0x80061800: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061804: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x80061808: lh          $t0, 0xC($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XC);
    // 0x8006180C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80061810: nop

    // 0x80061814: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061818: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x8006181C: lh          $t1, 0xA($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XA);
    // 0x80061820: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80061824: nop

    // 0x80061828: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006182C: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x80061830: lh          $t2, 0xE($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XE);
    // 0x80061834: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80061838: nop

    // 0x8006183C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061840: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x80061844: lh          $t3, 0x10($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X10);
    // 0x80061848: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x8006184C: jal         0x800612B8
    // 0x80061850: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80061850: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    after_1:
    // 0x80061854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006185C: jr          $ra
    // 0x80061860: nop

    return;
    // 0x80061860: nop

;}
RECOMP_FUNC void AudioSeq_ProcessSequences(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001678C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016790: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80016794: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016798: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001679C: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x800167A0: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x800167A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800167A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800167AC: addiu       $s2, $s2, -0x1598
    ctx->r18 = ADD32(ctx->r18, -0X1598);
    // 0x800167B0: addiu       $s0, $s0, -0x1AC8
    ctx->r16 = ADD32(ctx->r16, -0X1AC8);
    // 0x800167B4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800167B8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800167BC:
    // 0x800167BC: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800167C0: bnel        $s1, $t7, L_800167DC
    if (ctx->r17 != ctx->r15) {
        // 0x800167C4: addiu       $s0, $s0, 0x14C
        ctx->r16 = ADD32(ctx->r16, 0X14C);
            goto L_800167DC;
    }
    goto skip_0;
    // 0x800167C4: addiu       $s0, $s0, 0x14C
    ctx->r16 = ADD32(ctx->r16, 0X14C);
    skip_0:
    // 0x800167C8: jal         0x80015FD4
    // 0x800167CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_SequencePlayerProcessSequence(rdram, ctx);
        goto after_0;
    // 0x800167CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800167D0: jal         0x800135A8
    // 0x800167D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_SequencePlayerProcessSound(rdram, ctx);
        goto after_1;
    // 0x800167D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800167D8: addiu       $s0, $s0, 0x14C
    ctx->r16 = ADD32(ctx->r16, 0X14C);
L_800167DC:
    // 0x800167DC: bnel        $s0, $s2, L_800167BC
    if (ctx->r16 != ctx->r18) {
        // 0x800167E0: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800167BC;
    }
    goto skip_1;
    // 0x800167E0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800167E4: jal         0x80011FA8
    // 0x800167E8: nop

    Audio_ProcessNotes(rdram, ctx);
        goto after_2;
    // 0x800167E8: nop

    after_2:
    // 0x800167EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800167F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800167F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800167F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800167FC: jr          $ra
    // 0x80016800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80016800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Graphics_InitializeTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003DC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80003DC4: addiu       $v1, $v1, 0x7E50
    ctx->r3 = ADD32(ctx->r3, 0X7E50);
    // 0x80003DC8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80003DCC: ori         $at, $at, 0xAD50
    ctx->r1 = ctx->r1 | 0XAD50;
    // 0x80003DD0: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80003DD4: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003DD8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80003DDC: addiu       $t8, $t8, 0x23B0
    ctx->r24 = ADD32(ctx->r24, 0X23B0);
    // 0x80003DE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003DE4: mflo        $t7
    ctx->r15 = lo;
    // 0x80003DE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80003DEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80003DF0: sw          $t9, 0x7E54($at)
    MEM_W(0X7E54, ctx->r1) = ctx->r25;
    // 0x80003DF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003DF8: addiu       $t0, $t9, 0x50
    ctx->r8 = ADD32(ctx->r25, 0X50);
    // 0x80003DFC: sw          $t0, 0x7E58($at)
    MEM_W(0X7E58, ctx->r1) = ctx->r8;
    // 0x80003E00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003E04: addiu       $t1, $t9, 0x150
    ctx->r9 = ADD32(ctx->r25, 0X150);
    // 0x80003E08: sw          $t1, 0x7E5C($at)
    MEM_W(0X7E5C, ctx->r1) = ctx->r9;
    // 0x80003E0C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80003E10: ori         $at, $at, 0x2150
    ctx->r1 = ctx->r1 | 0X2150;
    // 0x80003E14: addu        $t2, $t9, $at
    ctx->r10 = ADD32(ctx->r25, ctx->r1);
    // 0x80003E18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003E1C: sw          $t2, 0x7E60($at)
    MEM_W(0X7E60, ctx->r1) = ctx->r10;
    // 0x80003E20: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80003E24: ori         $at, $at, 0x2D50
    ctx->r1 = ctx->r1 | 0X2D50;
    // 0x80003E28: addu        $t3, $t9, $at
    ctx->r11 = ADD32(ctx->r25, ctx->r1);
    // 0x80003E2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003E30: sw          $t3, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r11;
    // 0x80003E34: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80003E38: ori         $at, $at, 0xC950
    ctx->r1 = ctx->r1 | 0XC950;
    // 0x80003E3C: addu        $t4, $t9, $at
    ctx->r12 = ADD32(ctx->r25, ctx->r1);
    // 0x80003E40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003E44: sw          $t4, 0x7E68($at)
    MEM_W(0X7E68, ctx->r1) = ctx->r12;
    // 0x80003E48: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80003E4C: ori         $at, $at, 0x3550
    ctx->r1 = ctx->r1 | 0X3550;
    // 0x80003E50: addu        $t5, $t9, $at
    ctx->r13 = ADD32(ctx->r25, ctx->r1);
    // 0x80003E54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003E58: sw          $t5, 0x7E6C($at)
    MEM_W(0X7E6C, ctx->r1) = ctx->r13;
    // 0x80003E5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80003E60: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x80003E64: mfhi        $t6
    ctx->r14 = hi;
    // 0x80003E68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80003E6C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80003E70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80003E74: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003E78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80003E7C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003E80: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80003E84: addiu       $t8, $t8, -0x800
    ctx->r24 = ADD32(ctx->r24, -0X800);
    // 0x80003E88: sll         $t7, $t7, 11
    ctx->r15 = S32(ctx->r15 << 11);
    // 0x80003E8C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80003E90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003E94: sw          $t9, 0x7E70($at)
    MEM_W(0X7E70, ctx->r1) = ctx->r25;
    // 0x80003E98: lui         $t0, 0x8038
    ctx->r8 = S32(0X8038 << 16);
    // 0x80003E9C: addiu       $t0, $t0, 0x7800
    ctx->r8 = ADD32(ctx->r8, 0X7800);
    // 0x80003EA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003EA4: sw          $t0, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r8;
    // 0x80003EA8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80003EAC: addiu       $t1, $t1, -0x4C38
    ctx->r9 = ADD32(ctx->r9, -0X4C38);
    // 0x80003EB0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80003EB4: sw          $t1, -0x4C40($at)
    MEM_W(-0X4C40, ctx->r1) = ctx->r9;
    // 0x80003EB8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80003EBC: addiu       $t2, $t2, -0x4430
    ctx->r10 = ADD32(ctx->r10, -0X4430);
    // 0x80003EC0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80003EC4: sw          $t2, -0x4438($at)
    MEM_W(-0X4438, ctx->r1) = ctx->r10;
    // 0x80003EC8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80003ECC: addiu       $t3, $t3, -0x7A80
    ctx->r11 = ADD32(ctx->r11, -0X7A80);
    // 0x80003ED0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80003ED4: sw          $t3, -0x78F0($at)
    MEM_W(-0X78F0, ctx->r1) = ctx->r11;
    // 0x80003ED8: jr          $ra
    // 0x80003EDC: nop

    return;
    // 0x80003EDC: nop

;}
RECOMP_FUNC void AudioThread_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EE40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EE44: jal         0x8001E7C8
    // 0x8001EE48: nop

    AudioThread_InitQueues(rdram, ctx);
        goto after_0;
    // 0x8001EE48: nop

    after_0:
    // 0x8001EE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EE54: jr          $ra
    // 0x8001EE58: nop

    return;
    // 0x8001EE58: nop

;}
RECOMP_FUNC void Effect_Effect357_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007968C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079694: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80079698: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8007969C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800796A0: bnel        $t6, $at, L_800796C0
    if (ctx->r14 != ctx->r1) {
        // 0x800796A4: lhu         $t8, 0x50($a0)
        ctx->r24 = MEM_HU(ctx->r4, 0X50);
            goto L_800796C0;
    }
    goto skip_0;
    // 0x800796A4: lhu         $t8, 0x50($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X50);
    skip_0:
    // 0x800796A8: lh          $t7, 0x44($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X44);
    // 0x800796AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800796B0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800796B4: beq         $t7, $at, L_800796F8
    if (ctx->r15 == ctx->r1) {
        // 0x800796B8: nop
    
            goto L_800796F8;
    }
    // 0x800796B8: nop

    // 0x800796BC: lhu         $t8, 0x50($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X50);
L_800796C0:
    // 0x800796C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800796C4: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x800796C8: beq         $t8, $zero, L_800796E8
    if (ctx->r24 == 0) {
        // 0x800796CC: nop
    
            goto L_800796E8;
    }
    // 0x800796CC: nop

    // 0x800796D0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800796D4: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800796D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800796DC: nop

    // 0x800796E0: bc1fl       L_80079778
    if (!c1cs) {
        // 0x800796E4: lwc1        $f8, 0x10($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
            goto L_80079778;
    }
    goto skip_1;
    // 0x800796E4: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    skip_1:
L_800796E8:
    // 0x800796E8: jal         0x80060FBC
    // 0x800796EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x800796EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800796F0: b           L_80079774
    // 0x800796F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80079774;
    // 0x800796F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_800796F8:
    // 0x800796F8: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x800796FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079700: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80079704: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x80079708: bnel        $t0, $zero, L_80079734
    if (ctx->r8 != 0) {
        // 0x8007970C: lhu         $t1, 0x50($a0)
        ctx->r9 = MEM_HU(ctx->r4, 0X50);
            goto L_80079734;
    }
    goto skip_2;
    // 0x8007970C: lhu         $t1, 0x50($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X50);
    skip_2:
    // 0x80079710: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80079714: lwc1        $f10, 0x7350($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7350);
    // 0x80079718: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8007971C: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x80079720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80079724: jal         0x8007D2C8
    // 0x80079728: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_1;
    // 0x80079728: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8007972C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80079730: lhu         $t1, 0x50($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X50);
L_80079734:
    // 0x80079734: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80079738: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007973C: beq         $t1, $zero, L_80079768
    if (ctx->r9 == 0) {
        // 0x80079740: nop
    
            goto L_80079768;
    }
    // 0x80079740: nop

    // 0x80079744: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80079748: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8007974C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80079750: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80079754: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80079758: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8007975C: nop

    // 0x80079760: bc1fl       L_80079778
    if (!c1cs) {
        // 0x80079764: lwc1        $f8, 0x10($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
            goto L_80079778;
    }
    goto skip_3;
    // 0x80079764: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    skip_3:
L_80079768:
    // 0x80079768: jal         0x80060FBC
    // 0x8007976C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8007976C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80079770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80079774:
    // 0x80079774: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
L_80079778:
    // 0x80079778: lwc1        $f10, 0x60($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X60);
    // 0x8007977C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80079780: lwc1        $f16, 0x64($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X64);
    // 0x80079784: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80079788: lwc1        $f10, 0x68($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X68);
    // 0x8007978C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80079790: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80079794: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80079798: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8007979C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800797A0: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x800797A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800797A8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800797AC: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800797B0: lbu         $t2, 0x7C98($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7C98);
    // 0x800797B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800797B8: bne         $t2, $zero, L_800797D4
    if (ctx->r10 != 0) {
        // 0x800797BC: nop
    
            goto L_800797D4;
    }
    // 0x800797BC: nop

    // 0x800797C0: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800797C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800797C8: nop

    // 0x800797CC: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800797D0: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
L_800797D4:
    // 0x800797D4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800797D8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800797DC: bnel        $v0, $at, L_80079844
    if (ctx->r2 != ctx->r1) {
        // 0x800797E0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80079844;
    }
    goto skip_4;
    // 0x800797E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_4:
    // 0x800797E4: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x800797E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800797EC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800797F0: lw          $t4, 0x1C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C8);
    // 0x800797F4: bnel        $t4, $at, L_80079844
    if (ctx->r12 != ctx->r1) {
        // 0x800797F8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80079844;
    }
    goto skip_5;
    // 0x800797F8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_5:
    // 0x800797FC: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x80079800: slti        $at, $t5, 0xB0
    ctx->r1 = SIGNED(ctx->r13) < 0XB0 ? 1 : 0;
    // 0x80079804: bne         $at, $zero, L_80079840
    if (ctx->r1 != 0) {
        // 0x80079808: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80079840;
    }
    // 0x80079808: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007980C: lwc1        $f0, 0x7354($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7354);
    // 0x80079810: lwc1        $f8, 0x54($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80079814: lwc1        $f18, 0x58($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80079818: lwc1        $f16, 0x5C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x8007981C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80079820: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80079824: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80079828: nop

    // 0x8007982C: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80079830: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x80079834: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80079838: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
    // 0x8007983C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_80079840:
    // 0x80079840: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80079844:
    // 0x80079844: bnel        $v0, $at, L_800798B8
    if (ctx->r2 != ctx->r1) {
        // 0x80079848: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800798B8;
    }
    goto skip_6;
    // 0x80079848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8007984C: lh          $t6, 0x44($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X44);
    // 0x80079850: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80079854: bnel        $t6, $at, L_800798B8
    if (ctx->r14 != ctx->r1) {
        // 0x80079858: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800798B8;
    }
    goto skip_7;
    // 0x80079858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8007985C: lhu         $t7, 0x50($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X50);
    // 0x80079860: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80079864: slti        $at, $t7, 0x19
    ctx->r1 = SIGNED(ctx->r15) < 0X19 ? 1 : 0;
    // 0x80079868: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8007986C: bne         $at, $zero, L_80079884
    if (ctx->r1 != 0) {
        // 0x80079870: swc1        $f0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
            goto L_80079884;
    }
    // 0x80079870: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80079874: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80079878: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007987C: b           L_800798B4
    // 0x80079880: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
        goto L_800798B4;
    // 0x80079880: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_80079884:
    // 0x80079884: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80079888: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007988C: ldc1        $f10, 0x7358($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X7358);
    // 0x80079890: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80079894: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079898: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8007989C: nop

    // 0x800798A0: bc1fl       L_800798B8
    if (!c1cs) {
        // 0x800798A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800798B8;
    }
    goto skip_8;
    // 0x800798A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800798A8: lwc1        $f4, 0x7360($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7360);
    // 0x800798AC: sub.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800798B0: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
L_800798B4:
    // 0x800798B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800798B8:
    // 0x800798B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800798BC: jr          $ra
    // 0x800798C0: nop

    return;
    // 0x800798C0: nop

;}
RECOMP_FUNC void Effect_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069FDC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80069FE0: lhu         $v0, 0x50($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X50);
    // 0x80069FE4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80069FE8: beq         $v0, $zero, L_80069FF4
    if (ctx->r2 == 0) {
        // 0x80069FEC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80069FF4;
    }
    // 0x80069FEC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80069FF0: sh          $t6, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r14;
L_80069FF4:
    // 0x80069FF4: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80069FF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069FFC: beq         $v0, $at, L_8006A014
    if (ctx->r2 == ctx->r1) {
        // 0x8006A000: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006A014;
    }
    // 0x8006A000: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A004: beql        $v0, $at, L_8006A030
    if (ctx->r2 == ctx->r1) {
        // 0x8006A008: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8006A030;
    }
    goto skip_0;
    // 0x8006A008: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x8006A00C: b           L_8006A060
    // 0x8006A010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006A060;
    // 0x8006A010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006A014:
    // 0x8006A014: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x8006A018: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x8006A01C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x8006A020: jal         0x80063F90
    // 0x8006A024: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Object_Init(rdram, ctx);
        goto after_0;
    // 0x8006A024: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006A028: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006A02C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8006A030:
    // 0x8006A030: jal         0x80069924
    // 0x8006A034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Move(rdram, ctx);
        goto after_1;
    // 0x8006A034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8006A038: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006A03C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8006A040: beql        $t8, $zero, L_8006A060
    if (ctx->r24 == 0) {
        // 0x8006A044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006A060;
    }
    goto skip_1;
    // 0x8006A044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006A048: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8006A04C: beql        $v0, $zero, L_8006A060
    if (ctx->r2 == 0) {
        // 0x8006A050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006A060;
    }
    goto skip_2;
    // 0x8006A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8006A054: jalr        $v0
    // 0x8006A058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8006A058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8006A05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006A060:
    // 0x8006A060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A064: jr          $ra
    // 0x8006A068: nop

    return;
    // 0x8006A068: nop

;}
RECOMP_FUNC void Play_CheckDynaFloorCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A73E4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800A73E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A73EC: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800A73F0: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800A73F4: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800A73F8: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800A73FC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800A7400: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800A7404: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A7408: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A740C: beq         $v0, $at, L_800A7428
    if (ctx->r2 == ctx->r1) {
        // 0x800A7410: lwc1        $f4, 0xB8($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
            goto L_800A7428;
    }
    // 0x800A7410: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800A7414: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A7418: beq         $v0, $at, L_800A748C
    if (ctx->r2 == ctx->r1) {
        // 0x800A741C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800A748C;
    }
    // 0x800A741C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A7420: b           L_800A78B4
    // 0x800A7424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A78B4;
    // 0x800A7424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A7428:
    // 0x800A7428: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800A742C: addiu       $v0, $v0, 0x1C50
    ctx->r2 = ADD32(ctx->r2, 0X1C50);
    // 0x800A7430: lui         $v1, 0x602
    ctx->r3 = S32(0X602 << 16);
    // 0x800A7434: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800A7438: addiu       $v1, $v1, 0x2760
    ctx->r3 = ADD32(ctx->r3, 0X2760);
    // 0x800A743C: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x800A7440: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x800A7444: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    // 0x800A7448: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800A744C: srl         $t1, $t9, 28
    ctx->r9 = S32(U32(ctx->r25) >> 28);
    // 0x800A7450: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800A7454: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A7458: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A745C: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x800A7460: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800A7464: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800A7468: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800A746C: and         $t7, $v0, $a2
    ctx->r15 = ctx->r2 & ctx->r6;
    // 0x800A7470: and         $t5, $v1, $a2
    ctx->r13 = ctx->r3 & ctx->r6;
    // 0x800A7474: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7478: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800A747C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A7480: addu        $a1, $t8, $a3
    ctx->r5 = ADD32(ctx->r24, ctx->r7);
    // 0x800A7484: b           L_800A74F8
    // 0x800A7488: addu        $t0, $t6, $a3
    ctx->r8 = ADD32(ctx->r14, ctx->r7);
        goto L_800A74F8;
    // 0x800A7488: addu        $t0, $t6, $a3
    ctx->r8 = ADD32(ctx->r14, ctx->r7);
L_800A748C:
    // 0x800A748C: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x800A7490: addiu       $v0, $v0, -0x6130
    ctx->r2 = ADD32(ctx->r2, -0X6130);
    // 0x800A7494: lui         $v1, 0x603
    ctx->r3 = S32(0X603 << 16);
    // 0x800A7498: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800A749C: addiu       $v1, $v1, -0x53B0
    ctx->r3 = ADD32(ctx->r3, -0X53B0);
    // 0x800A74A0: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800A74A4: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x800A74A8: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    // 0x800A74AC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A74B0: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x800A74B4: addu        $t1, $a0, $t9
    ctx->r9 = ADD32(ctx->r4, ctx->r25);
    // 0x800A74B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A74BC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A74C0: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x800A74C4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800A74C8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800A74CC: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800A74D0: and         $t3, $v0, $a2
    ctx->r11 = ctx->r2 & ctx->r6;
    // 0x800A74D4: and         $t1, $v1, $a2
    ctx->r9 = ctx->r3 & ctx->r6;
    // 0x800A74D8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800A74DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800A74E0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800A74E4: addu        $a1, $t4, $a3
    ctx->r5 = ADD32(ctx->r12, ctx->r7);
    // 0x800A74E8: b           L_800A74F8
    // 0x800A74EC: addu        $t0, $t2, $a3
    ctx->r8 = ADD32(ctx->r10, ctx->r7);
        goto L_800A74F8;
    // 0x800A74EC: addu        $t0, $t2, $a3
    ctx->r8 = ADD32(ctx->r10, ctx->r7);
    // 0x800A74F0: b           L_800A78B4
    // 0x800A74F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A78B4;
    // 0x800A74F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A74F8:
    // 0x800A74F8: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x800A74FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A7500: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800A7504: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A7508: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A750C: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800A7510: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7514: lwc1        $f6, -0x7C58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C58);
    // 0x800A7518: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800A751C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800A7520: add.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A7524: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800A7528: add.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A752C: div.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800A7530: div.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800A7534: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A7538: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800A753C: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A7540: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A7544: nop

    // 0x800A7548: bltz        $v1, L_800A7568
    if (SIGNED(ctx->r3) < 0) {
        // 0x800A754C: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_800A7568;
    }
    // 0x800A754C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800A7550: beq         $at, $zero, L_800A7568
    if (ctx->r1 == 0) {
        // 0x800A7554: nop
    
            goto L_800A7568;
    }
    // 0x800A7554: nop

    // 0x800A7558: bltz        $a3, L_800A7568
    if (SIGNED(ctx->r7) < 0) {
        // 0x800A755C: slti        $at, $a3, 0x10
        ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
            goto L_800A7568;
    }
    // 0x800A755C: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800A7560: bnel        $at, $zero, L_800A7574
    if (ctx->r1 != 0) {
        // 0x800A7564: sw          $v1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r3;
            goto L_800A7574;
    }
    goto skip_0;
    // 0x800A7564: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    skip_0:
L_800A7568:
    // 0x800A7568: b           L_800A78B4
    // 0x800A756C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A78B4;
    // 0x800A756C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A7570: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
L_800A7574:
    // 0x800A7574: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800A7578: sw          $a3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r7;
    // 0x800A757C: jal         0x80004E20
    // 0x800A7580: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    Math_ModF(rdram, ctx);
        goto after_0;
    // 0x800A7580: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    after_0:
    // 0x800A7584: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x800A7588: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A758C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800A7590: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A7594: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A7598: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800A759C: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800A75A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A75A4: lwc1        $f8, -0x7C54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7C54);
    // 0x800A75A8: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800A75AC: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x800A75B0: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800A75B4: jal         0x80004E20
    // 0x800A75B8: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    Math_ModF(rdram, ctx);
        goto after_1;
    // 0x800A75B8: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    after_1:
    // 0x800A75BC: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x800A75C0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800A75C4: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x800A75C8: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x800A75CC: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x800A75D0: addu        $a2, $t5, $v1
    ctx->r6 = ADD32(ctx->r13, ctx->r3);
    // 0x800A75D4: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800A75D8: addu        $a0, $t0, $t6
    ctx->r4 = ADD32(ctx->r8, ctx->r14);
    // 0x800A75DC: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800A75E0: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800A75E4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800A75E8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800A75EC: addu        $v0, $a1, $t8
    ctx->r2 = ADD32(ctx->r5, ctx->r24);
    // 0x800A75F0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800A75F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A75F8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A75FC: nop

    // 0x800A7600: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A7604: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A7608: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x800A760C: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x800A7610: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800A7614: nop

    // 0x800A7618: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A761C: add.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800A7620: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x800A7624: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x800A7628: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A762C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A7630: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A7634: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A7638: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A763C: bc1f        L_800A76F0
    if (!c1cs) {
        // 0x800A7640: swc1        $f6, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
            goto L_800A76F0;
    }
    // 0x800A7640: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800A7644: lhu         $t3, 0x24($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X24);
    // 0x800A7648: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800A764C: addu        $v1, $a1, $t4
    ctx->r3 = ADD32(ctx->r5, ctx->r12);
    // 0x800A7650: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A7654: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A7658: nop

    // 0x800A765C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A7660: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A7664: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800A7668: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800A766C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A7670: nop

    // 0x800A7674: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A7678: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800A767C: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x800A7680: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x800A7684: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A7688: nop

    // 0x800A768C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7690: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A7694: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800A7698: lhu         $t8, 0x22($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X22);
    // 0x800A769C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800A76A0: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x800A76A4: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800A76A8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A76AC: nop

    // 0x800A76B0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A76B4: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A76B8: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800A76BC: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x800A76C0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A76C4: nop

    // 0x800A76C8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A76CC: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800A76D0: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800A76D4: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x800A76D8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A76DC: nop

    // 0x800A76E0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A76E4: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A76E8: b           L_800A7798
    // 0x800A76EC: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
        goto L_800A7798;
    // 0x800A76EC: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
L_800A76F0:
    // 0x800A76F0: lhu         $t4, 0x2($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2);
    // 0x800A76F4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800A76F8: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x800A76FC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800A7700: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A7704: nop

    // 0x800A7708: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A770C: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A7710: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800A7714: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800A7718: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800A771C: nop

    // 0x800A7720: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A7724: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800A7728: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x800A772C: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800A7730: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800A7734: nop

    // 0x800A7738: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A773C: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A7740: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800A7744: lhu         $t9, 0x24($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X24);
    // 0x800A7748: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x800A774C: addu        $v1, $a1, $t1
    ctx->r3 = ADD32(ctx->r5, ctx->r9);
    // 0x800A7750: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800A7754: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A7758: nop

    // 0x800A775C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A7760: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A7764: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800A7768: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800A776C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A7770: nop

    // 0x800A7774: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A7778: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800A777C: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800A7780: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x800A7784: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800A7788: nop

    // 0x800A778C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7790: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A7794: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
L_800A7798:
    // 0x800A7798: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800A779C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A77A0: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800A77A4: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800A77A8: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800A77AC: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800A77B0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800A77B4: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800A77B8: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800A77BC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800A77C0: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A77C4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A77C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A77CC: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x800A77D0: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800A77D4: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800A77D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A77DC: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800A77E0: sub.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800A77E4: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A77E8: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800A77EC: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A77F0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800A77F4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A77F8: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800A77FC: nop

    // 0x800A7800: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800A7804: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800A7808: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800A780C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800A7810: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800A7814: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A7818: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800A781C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800A7820: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A7824: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A7828: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A782C: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A7830: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A7834: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A7838: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A783C: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A7840: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800A7844: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800A7848: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A784C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A7850: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800A7854: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800A7858: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800A785C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7860: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A7864: lwc1        $f6, -0x7C50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C50);
    // 0x800A7868: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800A786C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A7870: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A7874: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A7878: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A787C: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800A7880: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A7884: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800A7888: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A788C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A7890: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800A7894: nop

    // 0x800A7898: bc1f        L_800A78B4
    if (!c1cs) {
        // 0x800A789C: nop
    
            goto L_800A78B4;
    }
    // 0x800A789C: nop

    // 0x800A78A0: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800A78A4: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800A78A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A78AC: b           L_800A78B4
    // 0x800A78B0: sw          $a2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r6;
        goto L_800A78B4;
    // 0x800A78B0: sw          $a2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r6;
L_800A78B4:
    // 0x800A78B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A78B8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800A78BC: jr          $ra
    // 0x800A78C0: nop

    return;
    // 0x800A78C0: nop

;}
RECOMP_FUNC void Effect_Effect381_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B228: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007B22C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007B230: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007B234: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007B238: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007B23C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8007B240: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x8007B244: sll         $t6, $zero, 5
    ctx->r14 = S32(0 << 5);
    // 0x8007B248: bne         $v1, $v0, L_8007B2AC
    if (ctx->r3 != ctx->r2) {
        // 0x8007B24C: subu        $t6, $t6, $zero
        ctx->r14 = SUB32(ctx->r14, 0);
            goto L_8007B2AC;
    }
    // 0x8007B24C: subu        $t6, $t6, $zero
    ctx->r14 = SUB32(ctx->r14, 0);
    // 0x8007B250: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8007B254: addiu       $t7, $t7, 0x130
    ctx->r15 = ADD32(ctx->r15, 0X130);
    // 0x8007B258: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8007B25C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8007B260: addiu       $a1, $a1, 0x37E0
    ctx->r5 = ADD32(ctx->r5, 0X37E0);
    // 0x8007B264: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8007B268: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
L_8007B26C:
    // 0x8007B26C: bnel        $t8, $zero, L_8007B298
    if (ctx->r24 != 0) {
        // 0x8007B270: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8007B298;
    }
    goto skip_0;
    // 0x8007B270: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8007B274: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007B278: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007B27C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007B280: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007B284: jal         0x8007B180
    // 0x8007B288: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect381_Setup(rdram, ctx);
        goto after_0;
    // 0x8007B288: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007B28C: b           L_8007B2B0
    // 0x8007B290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007B2B0;
    // 0x8007B290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B294: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8007B298:
    // 0x8007B298: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8007B29C: beql        $at, $zero, L_8007B2B0
    if (ctx->r1 == 0) {
        // 0x8007B2A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007B2B0;
    }
    goto skip_1;
    // 0x8007B2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8007B2A4: beql        $v1, $v0, L_8007B26C
    if (ctx->r3 == ctx->r2) {
        // 0x8007B2A8: lbu         $t8, 0x0($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X0);
            goto L_8007B26C;
    }
    goto skip_2;
    // 0x8007B2A8: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    skip_2:
L_8007B2AC:
    // 0x8007B2AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007B2B0:
    // 0x8007B2B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007B2B4: jr          $ra
    // 0x8007B2B8: nop

    return;
    // 0x8007B2B8: nop

;}
RECOMP_FUNC void Object_SetSfxSourceToPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F0E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005F0EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F0F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8005F0F4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005F0F8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005F0FC: lw          $t6, 0x78A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A8);
    // 0x8005F100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F104: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F108: beq         $t6, $at, L_8005F128
    if (ctx->r14 == ctx->r1) {
        // 0x8005F10C: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_8005F128;
    }
    // 0x8005F10C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005F110: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005F114: nop

    // 0x8005F118: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x8005F11C: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x8005F120: b           L_8005F1D4
    // 0x8005F124: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
        goto L_8005F1D4;
    // 0x8005F124: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8005F128:
    // 0x8005F128: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8005F12C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005F130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005F134: lw          $a1, 0x58($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X58);
    // 0x8005F138: jal         0x80005E90
    // 0x8005F13C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8005F13C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005F140: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005F144: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8005F148: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F14C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005F150: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005F154: jal         0x80005D44
    // 0x8005F158: lw          $a1, 0x5C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X5C);
    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8005F158: lw          $a1, 0x5C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X5C);
    after_1:
    // 0x8005F15C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F160: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005F164: addiu       $v0, $v0, 0x79D8
    ctx->r2 = ADD32(ctx->r2, 0X79D8);
    // 0x8005F168: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005F16C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8005F170: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005F174: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F178: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005F17C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005F180: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F184: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005F188: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8005F18C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8005F190: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8005F194: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8005F198: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005F19C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005F1A0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8005F1A4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8005F1A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005F1AC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005F1B0: jal         0x80006970
    // 0x8005F1B4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8005F1B4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8005F1B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8005F1BC: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005F1C0: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x8005F1C4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005F1C8: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x8005F1CC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005F1D0: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
L_8005F1D4:
    // 0x8005F1D4: jal         0x8005F030
    // 0x8005F1D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    Object_ClampSfxSource(rdram, ctx);
        goto after_3;
    // 0x8005F1D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8005F1DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F1E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005F1E4: jr          $ra
    // 0x8005F1E8: nop

    return;
    // 0x8005F1E8: nop

;}
RECOMP_FUNC void func_edisplay_8005A07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A07C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005A080: jr          $ra
    // 0x8005A084: nop

    return;
    // 0x8005A084: nop

;}
RECOMP_FUNC void ActorEvent_FlamePillar_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EAC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006EAC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006EACC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006EAD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006EAD4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006EAD8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006EADC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006EAE0: jal         0x80061474
    // 0x8006EAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006EAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006EAE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006EAEC: addiu       $t7, $zero, 0x176
    ctx->r15 = ADD32(0, 0X176);
    // 0x8006EAF0: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006EAF4: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8006EAF8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006EAFC: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8006EB00: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8006EB04: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8006EB08: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8006EB0C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8006EB10: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8006EB14: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006EB18: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x8006EB1C: jal         0x800612B8
    // 0x8006EB20: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8006EB20: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8006EB24: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006EB28: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8006EB2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006EB30: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8006EB34: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8006EB38: ori         $a0, $a0, 0x201D
    ctx->r4 = ctx->r4 | 0X201D;
    // 0x8006EB3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8006EB40: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006EB44: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8006EB48: jal         0x80019218
    // 0x8006EB4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8006EB4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8006EB50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006EB54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006EB58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006EB5C: jr          $ra
    // 0x8006EB60: nop

    return;
    // 0x8006EB60: nop

;}
RECOMP_FUNC void HUD_LivesCount1_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084930: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80084934: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80084938: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8008493C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80084940: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80084944: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80084948: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8008494C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80084950: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80084954: swc1        $f14, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f14.u32l;
    // 0x80084958: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008495C: addiu       $t7, $t7, 0x1A58
    ctx->r15 = ADD32(ctx->r15, 0X1A58);
    // 0x80084960: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80084964: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x80084968: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8008496C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80084970: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80084974: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80084978: addiu       $t3, $t3, 0x1A64
    ctx->r11 = ADD32(ctx->r11, 0X1A64);
    // 0x8008497C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80084980: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80084984: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80084988: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x8008498C: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80084990: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80084994: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80084998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008499C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x800849A0: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800849A4: jal         0x800B8DD0
    // 0x800849A8: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800849A8: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    after_0:
    // 0x800849AC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800849B0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800849B4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800849B8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800849BC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800849C0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800849C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800849C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800849CC: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x800849D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800849D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800849D8: lw          $a1, 0x1CC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1CC);
    // 0x800849DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800849E0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800849E4: beq         $a1, $zero, L_80084A10
    if (ctx->r5 == 0) {
        // 0x800849E8: addiu       $t1, $zero, 0x10
        ctx->r9 = ADD32(0, 0X10);
            goto L_80084A10;
    }
    // 0x800849E8: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800849EC: beq         $a1, $at, L_80084A04
    if (ctx->r5 == ctx->r1) {
        // 0x800849F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80084A04;
    }
    // 0x800849F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800849F4: beql        $a1, $at, L_80084A10
    if (ctx->r5 == ctx->r1) {
        // 0x800849F8: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_80084A10;
    }
    goto skip_0;
    // 0x800849F8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    skip_0:
    // 0x800849FC: b           L_80084A14
    // 0x80084A00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80084A14;
    // 0x80084A00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80084A04:
    // 0x80084A04: b           L_80084A10
    // 0x80084A08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80084A10;
    // 0x80084A08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80084A0C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80084A10:
    // 0x80084A10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80084A14:
    // 0x80084A14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80084A18: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80084A1C: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80084A20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80084A24: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80084A28: addu        $a1, $sp, $v0
    ctx->r5 = ADD32(ctx->r29, ctx->r2);
    // 0x80084A2C: addu        $a2, $sp, $v0
    ctx->r6 = ADD32(ctx->r29, ctx->r2);
    // 0x80084A30: lw          $a2, 0x60($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X60);
    // 0x80084A34: lw          $a1, 0x6C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6C);
    // 0x80084A38: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80084A3C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80084A40: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80084A44: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80084A48: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80084A4C: jal         0x8009C320
    // 0x80084A50: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x80084A50: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80084A54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80084A58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80084A5C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80084A60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80084A64: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80084A68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80084A6C: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80084A70: add.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x80084A74: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x80084A78: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80084A7C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80084A80: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80084A84: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80084A88: addiu       $a2, $a2, 0x1F08
    ctx->r6 = ADD32(ctx->r6, 0X1F08);
    // 0x80084A8C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80084A90: addiu       $a1, $a1, 0x1ED0
    ctx->r5 = ADD32(ctx->r5, 0X1ED0);
    // 0x80084A94: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80084A98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80084A9C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80084AA0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80084AA4: jal         0x8009C320
    // 0x80084AA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_2;
    // 0x80084AA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80084AAC: bltz        $s0, L_80084B7C
    if (SIGNED(ctx->r16) < 0) {
        // 0x80084AB0: lui         $at, 0x4130
        ctx->r1 = S32(0X4130 << 16);
            goto L_80084B7C;
    }
    // 0x80084AB0: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80084AB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80084AB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80084ABC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80084AC0: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80084AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80084AC8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x80084ACC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80084AD0: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x80084AD4: jal         0x800B8DD0
    // 0x80084AD8: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80084AD8: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80084ADC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80084AE0: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80084AE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80084AE8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80084AEC: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80084AF0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80084AF4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80084AF8: bgez        $s0, L_80084B04
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80084AFC: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80084B04;
    }
    // 0x80084AFC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80084B00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80084B04:
    // 0x80084B04: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x80084B08: bne         $at, $zero, L_80084B14
    if (ctx->r1 != 0) {
        // 0x80084B0C: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80084B14;
    }
    // 0x80084B0C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80084B10: addiu       $s0, $zero, 0x63
    ctx->r16 = ADD32(0, 0X63);
L_80084B14:
    // 0x80084B14: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80084B18: bne         $at, $zero, L_80084B38
    if (ctx->r1 != 0) {
        // 0x80084B1C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80084B38;
    }
    // 0x80084B1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80084B20:
    // 0x80084B20: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084B24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80084B28: mflo        $v0
    ctx->r2 = lo;
    // 0x80084B2C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80084B30: beq         $at, $zero, L_80084B20
    if (ctx->r1 == 0) {
        // 0x80084B34: nop
    
            goto L_80084B20;
    }
    // 0x80084B34: nop

L_80084B38:
    // 0x80084B38: negu        $t9, $v1
    ctx->r25 = SUB32(0, ctx->r3);
    // 0x80084B3C: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x80084B40: addiu       $t6, $t8, 0x10
    ctx->r14 = ADD32(ctx->r24, 0X10);
    // 0x80084B44: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80084B48: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80084B4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80084B50: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80084B54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80084B58: addiu       $t1, $zero, 0x63
    ctx->r9 = ADD32(0, 0X63);
    // 0x80084B5C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80084B60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084B64: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80084B68: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80084B6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80084B70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80084B74: jal         0x800869A0
    // 0x80084B78: add.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f10.fl;
    HUD_Number_Draw(rdram, ctx);
        goto after_4;
    // 0x80084B78: add.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f10.fl;
    after_4:
L_80084B7C:
    // 0x80084B7C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80084B80: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80084B84: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80084B88: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80084B8C: jr          $ra
    // 0x80084B90: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80084B90: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_versus_800BCE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCE24: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800BCE28: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800BCE2C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800BCE30: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800BCE34: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800BCE38: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800BCE3C: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x800BCE40: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BCE44: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BCE48: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BCE4C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800BCE50: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800BCE54: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800BCE58: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800BCE5C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800BCE60: lui         $s1, 0x300
    ctx->r17 = S32(0X300 << 16);
    // 0x800BCE64: lui         $s3, 0x300
    ctx->r19 = S32(0X300 << 16);
    // 0x800BCE68: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BCE6C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800BCE70: addiu       $s3, $s3, 0x3E20
    ctx->r19 = ADD32(ctx->r19, 0X3E20);
    // 0x800BCE74: addiu       $s1, $s1, 0x1420
    ctx->r17 = ADD32(ctx->r17, 0X1420);
    // 0x800BCE78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BCE7C: addiu       $s4, $zero, 0x2A
    ctx->r20 = ADD32(0, 0X2A);
L_800BCE80:
    // 0x800BCE80: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800BCE84: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800BCE88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BCE8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCE90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BCE94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BCE98: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800BCE9C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x800BCEA0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCEA4: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BCEA8: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x800BCEAC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCEB0: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800BCEB4: jal         0x8009D0BC
    // 0x800BCEB8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BCEB8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BCEBC: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
    // 0x800BCEC0: bne         $s0, $s4, L_800BCE80
    if (ctx->r16 != ctx->r20) {
        // 0x800BCEC4: addiu       $s1, $s1, 0x700
        ctx->r17 = ADD32(ctx->r17, 0X700);
            goto L_800BCE80;
    }
    // 0x800BCEC4: addiu       $s1, $s1, 0x700
    ctx->r17 = ADD32(ctx->r17, 0X700);
    // 0x800BCEC8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BCECC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800BCED0: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800BCED4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800BCED8: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800BCEDC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800BCEE0: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800BCEE4: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800BCEE8: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCEEC: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800BCEF0: jr          $ra
    // 0x800BCEF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800BCEF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Audio_FindNodeWithPrioLessThan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C6C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80012C70: bne         $v0, $a0, L_80012C80
    if (ctx->r2 != ctx->r4) {
        // 0x80012C74: nop
    
            goto L_80012C80;
    }
    // 0x80012C74: nop

    // 0x80012C78: jr          $ra
    // 0x80012C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80012C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012C80:
    // 0x80012C80: beq         $v0, $a0, L_80012CB4
    if (ctx->r2 == ctx->r4) {
        // 0x80012C84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80012CB4;
    }
    // 0x80012C84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80012C88: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
L_80012C8C:
    // 0x80012C8C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80012C90: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x80012C94: lbu         $t9, 0x30($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X30);
    // 0x80012C98: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80012C9C: bnel        $at, $zero, L_80012CAC
    if (ctx->r1 != 0) {
        // 0x80012CA0: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80012CAC;
    }
    goto skip_0;
    // 0x80012CA0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80012CA4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80012CA8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80012CAC:
    // 0x80012CAC: bnel        $v0, $a0, L_80012C8C
    if (ctx->r2 != ctx->r4) {
        // 0x80012CB0: lw          $t6, 0x8($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X8);
            goto L_80012C8C;
    }
    goto skip_1;
    // 0x80012CB0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    skip_1:
L_80012CB4:
    // 0x80012CB4: bnel        $v1, $zero, L_80012CC8
    if (ctx->r3 != 0) {
        // 0x80012CB8: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_80012CC8;
    }
    goto skip_2;
    // 0x80012CB8: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x80012CBC: jr          $ra
    // 0x80012CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80012CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012CC4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_80012CC8:
    // 0x80012CC8: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x80012CCC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80012CD0: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80012CD4: bne         $at, $zero, L_80012CE4
    if (ctx->r1 != 0) {
        // 0x80012CD8: nop
    
            goto L_80012CE4;
    }
    // 0x80012CD8: nop

    // 0x80012CDC: jr          $ra
    // 0x80012CE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80012CE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012CE4:
    // 0x80012CE4: jr          $ra
    // 0x80012CE8: nop

    return;
    // 0x80012CE8: nop

;}
RECOMP_FUNC void Player_PerformLoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AECAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800AECB0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AECB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AECB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AECBC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AECC0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800AECC4: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800AECC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800AECCC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AECD0: beq         $t6, $zero, L_800AED24
    if (ctx->r14 == 0) {
        // 0x800AECD4: lui         $at, 0x4370
        ctx->r1 = S32(0X4370 << 16);
            goto L_800AED24;
    }
    // 0x800AECD4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AECD8: lw          $t7, 0x1C4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AECDC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800AECE0: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    // 0x800AECE4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800AECE8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800AECEC: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x800AECF0: lw          $t0, 0x1C4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AECF4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800AECF8: addu        $v1, $a0, $t1
    ctx->r3 = ADD32(ctx->r4, ctx->r9);
    // 0x800AECFC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800AED00: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800AED04: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AED08: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800AED0C: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800AED10: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800AED14: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AED18: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x800AED1C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800AED20: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
L_800AED24:
    // 0x800AED24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AED28: lwc1        $f6, 0x4D8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800AED2C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800AED30: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800AED34: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AED38: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800AED3C: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x800AED40: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AED44: bc1f        L_800AED54
    if (!c1cs) {
        // 0x800AED48: lui         $at, 0xC248
        ctx->r1 = S32(0XC248 << 16);
            goto L_800AED54;
    }
    // 0x800AED48: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800AED4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AED50: nop

L_800AED54:
    // 0x800AED54: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AED58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AED5C: jal         0x8009BC2C
    // 0x800AED60: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800AED60: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800AED64: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800AED68: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800AED6C: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x800AED70: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800AED74: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AED78: jal         0x8009BC2C
    // 0x800AED7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800AED7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800AED80: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800AED84: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800AED88: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x800AED8C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800AED90: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AED94: jal         0x8009BC2C
    // 0x800AED98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800AED98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x800AED9C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800AEDA0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800AEDA4: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x800AEDA8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800AEDAC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800AEDB0: jal         0x8009BC2C
    // 0x800AEDB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800AEDB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x800AEDB8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AEDBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AEDC0: lwc1        $f8, 0x4D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800AEDC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AEDC8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800AEDCC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800AEDD0: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x800AEDD4: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    // 0x800AEDD8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AEDDC: bc1f        L_800AEDF4
    if (!c1cs) {
        // 0x800AEDE0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800AEDF4;
    }
    // 0x800AEDE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AEDE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AEDE8: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AEDEC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AEDF0: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
L_800AEDF4:
    // 0x800AEDF4: sw          $t8, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r24;
    // 0x800AEDF8: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x800AEDFC: bne         $t9, $zero, L_800AEE18
    if (ctx->r25 != 0) {
        // 0x800AEE00: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800AEE18;
    }
    // 0x800AEE00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AEE04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AEE08: lwc1        $f6, 0x2BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800AEE0C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AEE10: b           L_800AEE2C
    // 0x800AEE14: swc1        $f10, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f10.u32l;
        goto L_800AEE2C;
    // 0x800AEE14: swc1        $f10, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f10.u32l;
L_800AEE18:
    // 0x800AEE18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AEE1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AEE20: lwc1        $f16, 0x2BC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800AEE24: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AEE28: swc1        $f4, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f4.u32l;
L_800AEE2C:
    // 0x800AEE2C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800AEE30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AEE34: lwc1        $f6, 0x2BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800AEE38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AEE3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AEE40: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800AEE44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE48: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AEE4C: bc1fl       L_800AEE5C
    if (!c1cs) {
        // 0x800AEE50: swc1        $f8, 0x190($s0)
        MEM_W(0X190, ctx->r16) = ctx->f8.u32l;
            goto L_800AEE5C;
    }
    goto skip_0;
    // 0x800AEE50: swc1        $f8, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f8.u32l;
    skip_0:
    // 0x800AEE54: swc1        $f0, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f0.u32l;
    // 0x800AEE58: swc1        $f8, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f8.u32l;
L_800AEE5C:
    // 0x800AEE5C: lwc1        $f10, -0x7904($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7904);
    // 0x800AEE60: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800AEE64: jal         0x8009BC2C
    // 0x800AEE68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800AEE68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x800AEE6C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x800AEE70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AEE74: lwc1        $f18, 0x4D8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800AEE78: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800AEE7C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AEE80: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800AEE84: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800AEE88: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AEE8C: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x800AEE90: bc1f        L_800AEECC
    if (!c1cs) {
        // 0x800AEE94: lui         $a3, 0x40A0
        ctx->r7 = S32(0X40A0 << 16);
            goto L_800AEECC;
    }
    // 0x800AEE94: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800AEE98: sw          $zero, 0x4DC($s0)
    MEM_W(0X4DC, ctx->r16) = 0;
    // 0x800AEE9C: lw          $t0, 0x7880($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7880);
    // 0x800AEEA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEEA4: beql        $t0, $zero, L_800AEEC0
    if (ctx->r8 == 0) {
        // 0x800AEEA8: lw          $v0, 0x198($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X198);
            goto L_800AEEC0;
    }
    goto skip_1;
    // 0x800AEEA8: lw          $v0, 0x198($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X198);
    skip_1:
    // 0x800AEEAC: lwc1        $f0, -0x7900($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7900);
    // 0x800AEEB0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800AEEB4: b           L_800AEECC
    // 0x800AEEB8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
        goto L_800AEECC;
    // 0x800AEEB8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x800AEEBC: lw          $v0, 0x198($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X198);
L_800AEEC0:
    // 0x800AEEC0: beq         $v0, $zero, L_800AEECC
    if (ctx->r2 == 0) {
        // 0x800AEEC4: sw          $v0, 0x238($s0)
        MEM_W(0X238, ctx->r16) = ctx->r2;
            goto L_800AEECC;
    }
    // 0x800AEEC4: sw          $v0, 0x238($s0)
    MEM_W(0X238, ctx->r16) = ctx->r2;
    // 0x800AEEC8: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
L_800AEECC:
    // 0x800AEECC: jal         0x8009BC2C
    // 0x800AEED0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800AEED0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x800AEED4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800AEED8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AEEDC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AEEE0: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x800AEEE4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800AEEE8: jal         0x8009BC2C
    // 0x800AEEEC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800AEEEC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x800AEEF0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800AEEF4: lw          $t1, 0x797C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X797C);
    // 0x800AEEF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEEFC: lwc1        $f8, -0x78FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X78FC);
    // 0x800AEF00: lb          $t2, 0x2($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X2);
    // 0x800AEF04: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AEF08: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AEF0C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800AEF10: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800AEF14: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800AEF18: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800AEF1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AEF20: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800AEF24: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AEF28: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AEF2C: jal         0x8009BC2C
    // 0x800AEF30: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800AEF30: nop

    after_7:
    // 0x800AEF34: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800AEF38: lwc1        $f16, 0x12C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AEF3C: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800AEF40: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AEF44: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AEF48: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800AEF4C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AEF50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AEF54: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEF58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AEF5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEF60: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AEF64: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x800AEF68: lwc1        $f6, -0x78F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X78F8);
    // 0x800AEF6C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AEF70: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AEF74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AEF78: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEF7C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AEF80: jal         0x80005E90
    // 0x800AEF84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x800AEF84: nop

    after_8:
    // 0x800AEF88: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800AEF8C: lwc1        $f16, 0xE4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800AEF90: lwc1        $f4, 0x4D8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800AEF94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEF98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AEF9C: lwc1        $f8, -0x78F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X78F4);
    // 0x800AEFA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AEFA4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AEFA8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEFAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEFB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AEFB4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800AEFB8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800AEFBC: jal         0x80005D44
    // 0x800AEFC0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x800AEFC0: nop

    after_9:
    // 0x800AEFC4: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x800AEFC8: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x800AEFCC: lwc1        $f18, 0xD0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800AEFD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AEFD4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AEFD8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800AEFDC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800AEFE0: jal         0x80006A20
    // 0x800AEFE4: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x800AEFE4: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x800AEFE8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AEFEC: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800AEFF0: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x800AEFF4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800AEFF8: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800AEFFC: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AF000: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x800AF004: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AF008: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF00C: lwc1        $f16, 0xB0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800AF010: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x800AF014: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800AF018: lwc1        $f10, 0xA4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x800AF01C: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x800AF020: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AF024: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF028: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x800AF02C: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AF030: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800AF034: nop

    // 0x800AF038: bc1fl       L_800AF04C
    if (!c1cs) {
        // 0x800AF03C: lwc1        $f4, 0x7C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_800AF04C;
    }
    goto skip_2;
    // 0x800AF03C: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    skip_2:
    // 0x800AF040: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x800AF044: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x800AF048: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
L_800AF04C:
    // 0x800AF04C: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800AF050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AF054: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AF058: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    // 0x800AF05C: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800AF060: jal         0x800A46A0
    // 0x800AF064: swc1        $f10, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f10.u32l;
    Player_DamageEffects(rdram, ctx);
        goto after_11;
    // 0x800AF064: swc1        $f10, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f10.u32l;
    after_11:
    // 0x800AF068: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF06C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AF070: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AF074: jr          $ra
    // 0x800AF078: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800AF078: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void RCP_SetupDL_64_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA170: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA174: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA178: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA17C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA180: addiu       $t8, $t8, 0x43B0
    ctx->r24 = ADD32(ctx->r24, 0X43B0);
    // 0x800BA184: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA188: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA18C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA190: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA194: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA198: jr          $ra
    // 0x800BA19C: nop

    return;
    // 0x800BA19C: nop

;}
RECOMP_FUNC void Audio_PlayActiveSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A01C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001A020: lbu         $t6, 0x5D20($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5D20);
    // 0x8001A024: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001A028: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001A02C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001A030: andi        $s3, $a0, 0xFF
    ctx->r19 = ctx->r4 & 0XFF;
    // 0x8001A034: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001A038: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8001A03C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A040: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8001A044: lbu         $v1, 0x5CE0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5CE0);
    // 0x8001A048: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001A04C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A050: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001A054: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001A058: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001A05C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001A060: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001A064: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001A068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A06C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001A070: blez        $v1, L_8001A260
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001A074: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8001A260;
    }
    // 0x8001A074: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001A078: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001A07C: addiu       $t0, $t0, -0x66C8
    ctx->r8 = ADD32(ctx->r8, -0X66C8);
    // 0x8001A080: sll         $t9, $s3, 6
    ctx->r25 = S32(ctx->r19 << 6);
    // 0x8001A084: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001A088: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8001A08C: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8001A090: addiu       $s2, $s2, -0x6588
    ctx->r18 = ADD32(ctx->r18, -0X6588);
    // 0x8001A094: addiu       $s6, $s6, 0x5D24
    ctx->r22 = ADD32(ctx->r22, 0X5D24);
    // 0x8001A098: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8001A09C: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x8001A0A0: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8001A0A4: lui         $s5, 0x602
    ctx->r21 = S32(0X602 << 16);
L_8001A0A8:
    // 0x8001A0A8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8001A0AC: sll         $t3, $s4, 3
    ctx->r11 = S32(ctx->r20 << 3);
    // 0x8001A0B0: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x8001A0B4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A0B8: lbu         $s1, 0x4($t4)
    ctx->r17 = MEM_BU(ctx->r12, 0X4);
    // 0x8001A0BC: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x8001A0C0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001A0C4: beq         $fp, $s1, L_8001A240
    if (ctx->r30 == ctx->r17) {
        // 0x8001A0C8: sll         $t6, $t6, 6
        ctx->r14 = S32(ctx->r14 << 6);
            goto L_8001A240;
    }
    // 0x8001A0C8: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x8001A0CC: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8001A0D0: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x8001A0D4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8001A0D8: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001A0DC: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    // 0x8001A0E0: addiu       $t9, $t9, -0x79A0
    ctx->r25 = ADD32(ctx->r25, -0X79A0);
    // 0x8001A0E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A0E8: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8001A0EC: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x8001A0F0: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8001A0F4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8001A0F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001A0FC: bne         $v0, $at, L_8001A1B0
    if (ctx->r2 != ctx->r1) {
        // 0x8001A100: lw          $a0, -0x17FC($a0)
        ctx->r4 = MEM_W(ctx->r4, -0X17FC);
            goto L_8001A1B0;
    }
    // 0x8001A100: lw          $a0, -0x17FC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17FC);
    // 0x8001A104: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8001A108: sb          $a2, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r6;
    // 0x8001A10C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001A110: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x8001A114: bgez        $t1, L_8001A140
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001A118: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001A140;
    }
    // 0x8001A118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A11C: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x8001A120: lhu         $t2, 0x0($s6)
    ctx->r10 = MEM_HU(ctx->r22, 0X0);
    // 0x8001A124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001A128: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8001A12C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8001A130: sh          $t6, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r14;
    // 0x8001A134: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8001A138: jal         0x800185A0
    // 0x8001A13C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_0;
    // 0x8001A13C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
L_8001A140:
    // 0x8001A140: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8001A144: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x8001A148: jal         0x80016FF0
    // 0x8001A14C: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    Audio_SetSfxProperties(rdram, ctx);
        goto after_1;
    // 0x8001A14C: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    after_1:
    // 0x8001A150: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x8001A154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001A158: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8001A15C: jal         0x8001E8F0
    // 0x8001A160: or          $a0, $t9, $s5
    ctx->r4 = ctx->r25 | ctx->r21;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_2;
    // 0x8001A160: or          $a0, $t9, $s5
    ctx->r4 = ctx->r25 | ctx->r21;
    after_2:
    // 0x8001A164: lbu         $t1, 0x0($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X0);
    // 0x8001A168: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8001A16C: sll         $t4, $t1, 8
    ctx->r12 = S32(ctx->r9 << 8);
    // 0x8001A170: or          $a0, $t4, $s5
    ctx->r4 = ctx->r12 | ctx->r21;
    // 0x8001A174: ori         $t3, $a0, 0x4
    ctx->r11 = ctx->r4 | 0X4;
    // 0x8001A178: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x8001A17C: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8001A180: jal         0x8001E8F0
    // 0x8001A184: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_3;
    // 0x8001A184: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_3:
    // 0x8001A188: sb          $s7, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r23;
    // 0x8001A18C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001A190: lbu         $t8, 0x5D20($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5D20);
    // 0x8001A194: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A198: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A19C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8001A1A0: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8001A1A4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8001A1A8: b           L_8001A240
    // 0x8001A1AC: lbu         $v1, 0x5CE0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5CE0);
        goto L_8001A240;
    // 0x8001A1AC: lbu         $v1, 0x5CE0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5CE0);
L_8001A1B0:
    // 0x8001A1B0: lbu         $t1, 0xC3($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XC3);
    // 0x8001A1B4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001A1B8: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x8001A1BC: bne         $t1, $at, L_8001A208
    if (ctx->r9 != ctx->r1) {
        // 0x8001A1C0: sll         $t3, $t4, 8
        ctx->r11 = S32(ctx->r12 << 8);
            goto L_8001A208;
    }
    // 0x8001A1C0: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x8001A1C4: or          $a0, $t3, $s5
    ctx->r4 = ctx->r11 | ctx->r21;
    // 0x8001A1C8: ori         $t2, $a0, 0x7
    ctx->r10 = ctx->r4 | 0X7;
    // 0x8001A1CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8001A1D0: jal         0x8001E8F0
    // 0x8001A1D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_4;
    // 0x8001A1D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8001A1D8: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8001A1DC: jal         0x800197AC
    // 0x8001A1E0: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_5;
    // 0x8001A1E0: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_5:
    // 0x8001A1E4: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8001A1E8: lbu         $t5, 0x5D20($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X5D20);
    // 0x8001A1EC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A1F0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001A1F4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8001A1F8: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8001A1FC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8001A200: b           L_8001A240
    // 0x8001A204: lbu         $v1, 0x5CE0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5CE0);
        goto L_8001A240;
    // 0x8001A204: lbu         $v1, 0x5CE0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5CE0);
L_8001A208:
    // 0x8001A208: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001A20C: bne         $v0, $at, L_8001A240
    if (ctx->r2 != ctx->r1) {
        // 0x8001A210: andi        $a0, $s3, 0xFF
        ctx->r4 = ctx->r19 & 0XFF;
            goto L_8001A240;
    }
    // 0x8001A210: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8001A214: jal         0x80016FF0
    // 0x8001A218: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    Audio_SetSfxProperties(rdram, ctx);
        goto after_6;
    // 0x8001A218: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_6:
    // 0x8001A21C: sb          $s7, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r23;
    // 0x8001A220: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001A224: lbu         $t8, 0x5D20($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5D20);
    // 0x8001A228: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A22C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A230: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8001A234: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8001A238: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8001A23C: lbu         $v1, 0x5CE0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5CE0);
L_8001A240:
    // 0x8001A240: lbu         $t1, 0x0($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X0);
    // 0x8001A244: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001A248: andi        $t3, $s4, 0xFF
    ctx->r11 = ctx->r20 & 0XFF;
    // 0x8001A24C: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001A250: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x8001A254: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    // 0x8001A258: bne         $at, $zero, L_8001A0A8
    if (ctx->r1 != 0) {
        // 0x8001A25C: sb          $t4, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r12;
            goto L_8001A0A8;
    }
    // 0x8001A25C: sb          $t4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r12;
L_8001A260:
    // 0x8001A260: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A268: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A26C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A270: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A274: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A278: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A27C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A280: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A284: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A288: jr          $ra
    // 0x8001A28C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001A28C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Player_UpdateTankRoll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B22C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B22C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B22C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B22CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B22D0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800B22D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B22D8: jal         0x80004E20
    // 0x800B22DC: lwc1        $f12, 0x130($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X130);
    Math_ModF(rdram, ctx);
        goto after_0;
    // 0x800B22DC: lwc1        $f12, 0x130($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X130);
    after_0:
    // 0x800B22E0: lw          $t6, 0x1DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1DC);
    // 0x800B22E4: swc1        $f0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f0.u32l;
    // 0x800B22E8: bnel        $t6, $zero, L_800B237C
    if (ctx->r14 != 0) {
        // 0x800B22EC: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_800B237C;
    }
    goto skip_0;
    // 0x800B22EC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x800B22F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B22F4: lwc1        $f0, 0x130($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B22F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B22FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B2300: nop

    // 0x800B2304: bc1fl       L_800B233C
    if (!c1cs) {
        // 0x800B2308: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800B233C;
    }
    goto skip_1;
    // 0x800B2308: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x800B230C: lwc1        $f12, -0x7698($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7698);
    // 0x800B2310: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B2314: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B2318: swc1        $f6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f6.u32l;
    // 0x800B231C: lwc1        $f0, 0x130($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B2320: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800B2324: nop

    // 0x800B2328: bc1fl       L_800B233C
    if (!c1cs) {
        // 0x800B232C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800B233C;
    }
    goto skip_2;
    // 0x800B232C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x800B2330: swc1        $f2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f2.u32l;
    // 0x800B2334: lwc1        $f0, 0x130($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B2338: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800B233C:
    // 0x800B233C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2340: lwc1        $f12, -0x7694($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7694);
    // 0x800B2344: bc1fl       L_800B237C
    if (!c1cs) {
        // 0x800B2348: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_800B237C;
    }
    goto skip_3;
    // 0x800B2348: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_3:
    // 0x800B234C: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B2350: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2354: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800B2358: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x800B235C: lwc1        $f18, 0x130($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B2360: lwc1        $f16, -0x7690($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7690);
    // 0x800B2364: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800B2368: nop

    // 0x800B236C: bc1fl       L_800B237C
    if (!c1cs) {
        // 0x800B2370: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_800B237C;
    }
    goto skip_4;
    // 0x800B2370: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_4:
    // 0x800B2374: swc1        $f2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f2.u32l;
    // 0x800B2378: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_800B237C:
    // 0x800B237C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2380: beq         $v0, $zero, L_800B238C
    if (ctx->r2 == 0) {
        // 0x800B2384: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800B238C;
    }
    // 0x800B2384: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800B2388: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_800B238C:
    // 0x800B238C: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x800B2390: beq         $v0, $zero, L_800B239C
    if (ctx->r2 == 0) {
        // 0x800B2394: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800B239C;
    }
    // 0x800B2394: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800B2398: sw          $t8, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r24;
L_800B239C:
    // 0x800B239C: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
    // 0x800B23A0: beq         $v0, $zero, L_800B23AC
    if (ctx->r2 == 0) {
        // 0x800B23A4: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800B23AC;
    }
    // 0x800B23A4: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800B23A8: sw          $t9, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r25;
L_800B23AC:
    // 0x800B23AC: lw          $t0, 0x1DC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1DC);
    // 0x800B23B0: beql        $t0, $zero, L_800B2564
    if (ctx->r8 == 0) {
        // 0x800B23B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B2564;
    }
    goto skip_5;
    // 0x800B23B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800B23B8: lw          $t1, 0x1EC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1EC);
    // 0x800B23BC: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B23C0: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B23C4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800B23C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B23CC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B23D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B23D4: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x800B23D8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x800B23DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800B23E0: addiu       $t7, $t7, 0x79A8
    ctx->r15 = ADD32(ctx->r15, 0X79A8);
    // 0x800B23E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B23E8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B23EC: bc1f        L_800B2420
    if (!c1cs) {
        // 0x800B23F0: swc1        $f10, 0x130($s0)
        MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
            goto L_800B2420;
    }
    // 0x800B23F0: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x800B23F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B23F8: nop

    // 0x800B23FC: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800B2400: swc1        $f18, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f18.u32l;
    // 0x800B2404: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B2408: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B240C: nop

    // 0x800B2410: bc1fl       L_800B2424
    if (!c1cs) {
        // 0x800B2414: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800B2424;
    }
    goto skip_6;
    // 0x800B2414: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_6:
    // 0x800B2418: swc1        $f2, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f2.u32l;
    // 0x800B241C: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
L_800B2420:
    // 0x800B2420: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800B2424:
    // 0x800B2424: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800B2428: bc1fl       L_800B245C
    if (!c1cs) {
        // 0x800B242C: lw          $t2, 0x1E8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1E8);
            goto L_800B245C;
    }
    goto skip_7;
    // 0x800B242C: lw          $t2, 0x1E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E8);
    skip_7:
    // 0x800B2430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B2434: nop

    // 0x800B2438: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800B243C: swc1        $f4, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f4.u32l;
    // 0x800B2440: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B2444: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800B2448: nop

    // 0x800B244C: bc1fl       L_800B245C
    if (!c1cs) {
        // 0x800B2450: lw          $t2, 0x1E8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1E8);
            goto L_800B245C;
    }
    goto skip_8;
    // 0x800B2450: lw          $t2, 0x1E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E8);
    skip_8:
    // 0x800B2454: swc1        $f2, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f2.u32l;
    // 0x800B2458: lw          $t2, 0x1E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E8);
L_800B245C:
    // 0x800B245C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800B2460: bnel        $t2, $zero, L_800B24A4
    if (ctx->r10 != 0) {
        // 0x800B2464: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800B24A4;
    }
    goto skip_9;
    // 0x800B2464: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_9:
    // 0x800B2468: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x800B246C: blez        $v0, L_800B247C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2470: addiu       $t3, $v0, -0x2
        ctx->r11 = ADD32(ctx->r2, -0X2);
            goto L_800B247C;
    }
    // 0x800B2470: addiu       $t3, $v0, -0x2
    ctx->r11 = ADD32(ctx->r2, -0X2);
    // 0x800B2474: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
    // 0x800B2478: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800B247C:
    // 0x800B247C: bgez        $v0, L_800B248C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B2480: addiu       $t4, $v0, 0x2
        ctx->r12 = ADD32(ctx->r2, 0X2);
            goto L_800B248C;
    }
    // 0x800B2480: addiu       $t4, $v0, 0x2
    ctx->r12 = ADD32(ctx->r2, 0X2);
    // 0x800B2484: sw          $t4, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r12;
    // 0x800B2488: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800B248C:
    // 0x800B248C: bne         $v0, $zero, L_800B2498
    if (ctx->r2 != 0) {
        // 0x800B2490: nop
    
            goto L_800B2498;
    }
    // 0x800B2490: nop

    // 0x800B2494: sw          $zero, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = 0;
L_800B2498:
    // 0x800B2498: b           L_800B24C4
    // 0x800B249C: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
        goto L_800B24C4;
    // 0x800B249C: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
    // 0x800B24A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800B24A4:
    // 0x800B24A4: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B24A8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800B24AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B24B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B24B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B24B8: jal         0x8009BC2C
    // 0x800B24BC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B24BC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x800B24C0: lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E8);
L_800B24C4:
    // 0x800B24C4: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800B24C8: bne         $at, $zero, L_800B2508
    if (ctx->r1 != 0) {
        // 0x800B24CC: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_800B2508;
    }
    // 0x800B24CC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B24D0: lw          $t8, 0x498($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X498);
    // 0x800B24D4: bne         $t8, $zero, L_800B2508
    if (ctx->r24 != 0) {
        // 0x800B24D8: nop
    
            goto L_800B2508;
    }
    // 0x800B24D8: nop

    // 0x800B24DC: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x800B24E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B24E4: blez        $v0, L_800B24F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B24E8: nop
    
            goto L_800B24F8;
    }
    // 0x800B24E8: nop

    // 0x800B24EC: lwc1        $f10, -0x768C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X768C);
    // 0x800B24F0: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x800B24F4: swc1        $f10, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f10.u32l;
L_800B24F8:
    // 0x800B24F8: bgez        $v0, L_800B2508
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B24FC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800B2508;
    }
    // 0x800B24FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2500: lwc1        $f16, -0x7688($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7688);
    // 0x800B2504: swc1        $f16, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f16.u32l;
L_800B2508:
    // 0x800B2508: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x800B250C: beql        $t9, $zero, L_800B2564
    if (ctx->r25 == 0) {
        // 0x800B2510: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B2564;
    }
    goto skip_10;
    // 0x800B2510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x800B2514: lw          $t0, 0x1C4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2518: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B251C: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    // 0x800B2520: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800B2524: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800B2528: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x800B252C: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2530: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800B2534: addu        $v1, $a0, $t4
    ctx->r3 = ADD32(ctx->r4, ctx->r12);
    // 0x800B2538: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800B253C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800B2540: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2544: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x800B2548: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800B254C: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x800B2550: lw          $t8, 0x1C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2554: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800B2558: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800B255C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800B2560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B2564:
    // 0x800B2564: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B2568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B256C: jr          $ra
    // 0x800B2570: nop

    return;
    // 0x800B2570: nop

;}
RECOMP_FUNC void ActorAllRange_DrawShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034E64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80034E68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034E6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80034E70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80034E74: lwc1        $f6, 0x16C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X16C);
    // 0x80034E78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80034E7C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80034E80: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80034E84: nop

    // 0x80034E88: bc1fl       L_8003508C
    if (!c1cs) {
        // 0x80034E8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003508C;
    }
    goto skip_0;
    // 0x80034E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80034E90: jal         0x80005708
    // 0x80034E94: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80034E94: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x80034E98: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80034E9C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80034EA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034EA4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80034EA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80034EAC: lwc1        $f8, 0x16C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X16C);
    // 0x80034EB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80034EB4: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x80034EB8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80034EBC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80034EC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80034EC4: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    // 0x80034EC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80034ECC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80034ED0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80034ED4: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80034ED8: bne         $t8, $at, L_80034EF4
    if (ctx->r24 != ctx->r1) {
        // 0x80034EDC: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80034EF4;
    }
    // 0x80034EDC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80034EE0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80034EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034EE8: nop

    // 0x80034EEC: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80034EF0: nop

L_80034EF4:
    // 0x80034EF4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80034EF8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80034EFC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80034F00: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80034F04: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80034F08: jal         0x80005B00
    // 0x80034F0C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80034F0C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80034F10: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80034F14: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80034F18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034F1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80034F20: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80034F24: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80034F28: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80034F2C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80034F30: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80034F34: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80034F38: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80034F3C: jal         0x80005C34
    // 0x80034F40: nop

    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x80034F40: nop

    after_2:
    // 0x80034F44: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80034F48: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x80034F4C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80034F50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034F54: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80034F58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80034F5C: lwc1        $f6, 0x50A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50A4);
    // 0x80034F60: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80034F64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80034F68: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80034F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80034F70: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80034F74: nop

    // 0x80034F78: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80034F7C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80034F80: jal         0x80005E90
    // 0x80034F84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x80034F84: nop

    after_3:
    // 0x80034F88: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80034F8C: jal         0x80006EB8
    // 0x80034F90: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80034F90: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    after_4:
    // 0x80034F94: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80034F98: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    // 0x80034F9C: jal         0x800B8DD0
    // 0x80034FA0: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x80034FA0: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_5:
    // 0x80034FA4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80034FA8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80034FAC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80034FB0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80034FB4: bne         $v0, $at, L_80034FF0
    if (ctx->r2 != ctx->r1) {
        // 0x80034FB8: addiu       $a2, $a2, 0x7E64
        ctx->r6 = ADD32(ctx->r6, 0X7E64);
            goto L_80034FF0;
    }
    // 0x80034FB8: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80034FBC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80034FC0: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80034FC4: lui         $at, 0x80FF
    ctx->r1 = S32(0X80FF << 16);
    // 0x80034FC8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80034FCC: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80034FD0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80034FD4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80034FD8: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80034FDC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80034FE0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80034FE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80034FE8: b           L_80035060
    // 0x80034FEC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
        goto L_80035060;
    // 0x80034FEC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80034FF0:
    // 0x80034FF0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80034FF4: bnel        $v0, $at, L_80035034
    if (ctx->r2 != ctx->r1) {
        // 0x80034FF8: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_80035034;
    }
    goto skip_1;
    // 0x80034FF8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x80034FFC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80035000: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80035004: lui         $at, 0xFF80
    ctx->r1 = S32(0XFF80 << 16);
    // 0x80035008: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003500C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80035010: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80035014: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80035018: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x8003501C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80035020: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80035024: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80035028: b           L_80035060
    // 0x8003502C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
        goto L_80035060;
    // 0x8003502C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80035030: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80035034:
    // 0x80035034: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80035038: lui         $at, 0x30FF
    ctx->r1 = S32(0X30FF << 16);
    // 0x8003503C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80035040: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80035044: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80035048: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003504C: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80035050: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80035054: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80035058: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8003505C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80035060:
    // 0x80035060: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x80035064: addiu       $t9, $t9, 0x1630
    ctx->r25 = ADD32(ctx->r25, 0X1630);
    // 0x80035068: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003506C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80035070: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80035074: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80035078: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003507C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80035080: jal         0x80005740
    // 0x80035084: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x80035084: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x80035088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003508C:
    // 0x8003508C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80035090: jr          $ra
    // 0x80035094: nop

    return;
    // 0x80035094: nop

;}
