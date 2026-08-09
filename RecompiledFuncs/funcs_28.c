#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Effect_Effect361_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007BDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BDE8: lh          $t6, 0x4A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4A);
    // 0x8007BDEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BDF0: lwc1        $f6, 0x73FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X73FC);
    // 0x8007BDF4: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007BDF8: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x8007BDFC: sh          $t7, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r15;
    // 0x8007BE00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007BE04: lh          $t8, 0x4A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4A);
    // 0x8007BE08: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007BE0C: bgez        $t8, L_8007BE20
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007BE10: swc1        $f8, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
            goto L_8007BE20;
    }
    // 0x8007BE10: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8007BE14: jal         0x80060FBC
    // 0x8007BE18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007BE18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007BE1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007BE20:
    // 0x8007BE20: lh          $t9, 0x48($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X48);
    // 0x8007BE24: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007BE28: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007BE2C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8007BE30: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8007BE34: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007BE38: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007BE3C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007BE40: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
    // 0x8007BE44: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8007BE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BE4C: jr          $ra
    // 0x8007BE50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007BE50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Effect_DrawAllRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E538: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005E53C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005E540: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E544: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E548: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005E54C: addiu       $t7, $t7, -0x2F0
    ctx->r15 = ADD32(ctx->r15, -0X2F0);
    // 0x8005E550: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005E554: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x8005E558: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8005E55C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005E560: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005E564: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8005E568: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8005E56C: sb          $zero, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = 0;
    // 0x8005E570: lh          $t1, 0x30($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X30);
    // 0x8005E574: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E578: bne         $t1, $at, L_8005E5C4
    if (ctx->r9 != ctx->r1) {
        // 0x8005E57C: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8005E5C4;
    }
    // 0x8005E57C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E580: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005E584: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005E588: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E58C: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005E590: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E594: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005E598: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E59C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005E5A0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8005E5A4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8005E5A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005E5AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005E5B0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8005E5B4: jal         0x80005B00
    // 0x8005E5B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005E5B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x8005E5BC: b           L_8005E5F4
    // 0x8005E5C0: nop

        goto L_8005E5F4;
    // 0x8005E5C0: nop

L_8005E5C4:
    // 0x8005E5C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E5C8: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005E5CC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E5D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E5D4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005E5D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005E5DC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005E5E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005E5E4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005E5E8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8005E5EC: jal         0x80005B00
    // 0x8005E5F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8005E5F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
L_8005E5F4:
    // 0x8005E5F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E5F8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E5FC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8005E600: jal         0x80006970
    // 0x8005E604: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8005E604: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x8005E608: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8005E60C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8005E610: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8005E614: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005E618: beq         $v0, $at, L_8005E628
    if (ctx->r2 == ctx->r1) {
        // 0x8005E61C: lwc1        $f14, 0x48($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
            goto L_8005E628;
    }
    // 0x8005E61C: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005E620: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8005E624: bne         $v0, $at, L_8005E634
    if (ctx->r2 != ctx->r1) {
        // 0x8005E628: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005E634;
    }
L_8005E628:
    // 0x8005E628: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E62C: b           L_8005E63C
    // 0x8005E630: lwc1        $f0, 0x6338($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6338);
        goto L_8005E63C;
    // 0x8005E630: lwc1        $f0, 0x6338($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6338);
L_8005E634:
    // 0x8005E634: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E638: lwc1        $f0, 0x633C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X633C);
L_8005E63C:
    // 0x8005E63C: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x8005E640: nop

    // 0x8005E644: bc1fl       L_8005E754
    if (!c1cs) {
        // 0x8005E648: addiu       $a2, $s0, 0x80
        ctx->r6 = ADD32(ctx->r16, 0X80);
            goto L_8005E754;
    }
    goto skip_0;
    // 0x8005E648: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    skip_0:
    // 0x8005E64C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8005E650: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8005E654: bc1fl       L_8005E754
    if (!c1cs) {
        // 0x8005E658: addiu       $a2, $s0, 0x80
        ctx->r6 = ADD32(ctx->r16, 0X80);
            goto L_8005E754;
    }
    goto skip_1;
    // 0x8005E658: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    skip_1:
    // 0x8005E65C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005E660: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005E664: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005E668: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005E66C: mul.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8005E670: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005E674: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005E678: abs.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = fabsf(ctx->f12.fl);
    // 0x8005E67C: add.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005E680: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8005E684: nop

    // 0x8005E688: bc1fl       L_8005E754
    if (!c1cs) {
        // 0x8005E68C: addiu       $a2, $s0, 0x80
        ctx->r6 = ADD32(ctx->r16, 0X80);
            goto L_8005E754;
    }
    goto skip_2;
    // 0x8005E68C: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    skip_2:
    // 0x8005E690: add.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005E694: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005E698: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8005E69C: nop

    // 0x8005E6A0: bc1fl       L_8005E754
    if (!c1cs) {
        // 0x8005E6A4: addiu       $a2, $s0, 0x80
        ctx->r6 = ADD32(ctx->r16, 0X80);
            goto L_8005E754;
    }
    goto skip_3;
    // 0x8005E6A4: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    skip_3:
    // 0x8005E6A8: lw          $t4, 0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C);
    // 0x8005E6AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E6B0: beql        $t4, $zero, L_8005E74C
    if (ctx->r12 == 0) {
        // 0x8005E6B4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005E74C;
    }
    goto skip_4;
    // 0x8005E6B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_4:
    // 0x8005E6B8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005E6BC: lwc1        $f18, 0x6340($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6340);
    // 0x8005E6C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E6C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E6C8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8005E6CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E6D0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005E6D4: jal         0x80005E90
    // 0x8005E6D8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8005E6D8: nop

    after_3:
    // 0x8005E6DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E6E0: lwc1        $f8, 0x6344($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6344);
    // 0x8005E6E4: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005E6E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E6EC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E6F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005E6F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E6F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005E6FC: jal         0x80005D44
    // 0x8005E700: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8005E700: nop

    after_4:
    // 0x8005E704: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E708: lwc1        $f4, 0x6348($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6348);
    // 0x8005E70C: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005E710: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005E714: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005E718: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005E71C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E720: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005E724: jal         0x80005FE0
    // 0x8005E728: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8005E728: nop

    after_5:
    // 0x8005E72C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005E730: jal         0x80006EB8
    // 0x8005E734: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8005E734: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_6:
    // 0x8005E738: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8005E73C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E740: jalr        $t9
    // 0x8005E744: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8005E744: nop

    after_7:
    // 0x8005E748: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005E74C:
    // 0x8005E74C: sb          $t5, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r13;
    // 0x8005E750: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
L_8005E754:
    // 0x8005E754: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005E758: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005E75C: jal         0x8005F290
    // 0x8005E760: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    Object_SetSfxSourceToView(rdram, ctx);
        goto after_8;
    // 0x8005E760: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x8005E764: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x8005E768: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8005E76C: bnel        $t8, $zero, L_8005E7A8
    if (ctx->r24 != 0) {
        // 0x8005E770: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005E7A8;
    }
    goto skip_5;
    // 0x8005E770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8005E774: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005E778: addiu       $at, $zero, 0x160
    ctx->r1 = ADD32(0, 0X160);
    // 0x8005E77C: beq         $v0, $at, L_8005E7A4
    if (ctx->r2 == ctx->r1) {
        // 0x8005E780: addiu       $at, $zero, 0x175
        ctx->r1 = ADD32(0, 0X175);
            goto L_8005E7A4;
    }
    // 0x8005E780: addiu       $at, $zero, 0x175
    ctx->r1 = ADD32(0, 0X175);
    // 0x8005E784: beq         $v0, $at, L_8005E7A4
    if (ctx->r2 == ctx->r1) {
        // 0x8005E788: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_8005E7A4;
    }
    // 0x8005E788: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005E78C: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x8005E790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E794: bnel        $t6, $zero, L_8005E7A8
    if (ctx->r14 != 0) {
        // 0x8005E798: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005E7A8;
    }
    goto skip_6;
    // 0x8005E798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8005E79C: jal         0x80060FBC
    // 0x8005E7A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    Object_Kill(rdram, ctx);
        goto after_9;
    // 0x8005E7A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_9:
L_8005E7A4:
    // 0x8005E7A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005E7A8:
    // 0x8005E7A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005E7AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8005E7B0: jr          $ra
    // 0x8005E7B4: nop

    return;
    // 0x8005E7B4: nop

;}
RECOMP_FUNC void Audio_ProcessPlaylist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD0C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001BD10: addiu       $t1, $t1, 0x5E7C
    ctx->r9 = ADD32(ctx->r9, 0X5E7C);
    // 0x8001BD14: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x8001BD18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001BD1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8001BD20: beq         $a1, $a0, L_8001BFB0
    if (ctx->r5 == ctx->r4) {
        // 0x8001BD24: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8001BFB0;
    }
    // 0x8001BD24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001BD28: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8001BD2C: addiu       $t2, $t2, 0x5E80
    ctx->r10 = ADD32(ctx->r10, 0X5E80);
    // 0x8001BD30: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD34: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8001BD38: addiu       $t0, $t0, 0x5E84
    ctx->r8 = ADD32(ctx->r8, 0X5E84);
    // 0x8001BD3C: bne         $v0, $zero, L_8001BFAC
    if (ctx->r2 != 0) {
        // 0x8001BD40: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8001BFAC;
    }
    // 0x8001BD40: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8001BD44: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x8001BD48: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x8001BD4C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001BD50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001BD54: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001BD58: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001BD5C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001BD60: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001BD64: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001BD68: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8001BD6C: addiu       $t3, $t3, 0x5FF4
    ctx->r11 = ADD32(ctx->r11, 0X5FF4);
    // 0x8001BD70: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001BD74: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x8001BD78: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8001BD7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BD80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001BD84: beql        $v1, $zero, L_8001BDBC
    if (ctx->r3 == 0) {
        // 0x8001BD88: lhu         $t4, 0x2($v0)
        ctx->r12 = MEM_HU(ctx->r2, 0X2);
            goto L_8001BDBC;
    }
    goto skip_0;
    // 0x8001BD88: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
    skip_0:
    // 0x8001BD8C: beq         $v1, $at, L_8001BE2C
    if (ctx->r3 == ctx->r1) {
        // 0x8001BD90: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001BE2C;
    }
    // 0x8001BD90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001BD94: beq         $v1, $at, L_8001BEB0
    if (ctx->r3 == ctx->r1) {
        // 0x8001BD98: addiu       $a2, $zero, 0x461
        ctx->r6 = ADD32(0, 0X461);
            goto L_8001BEB0;
    }
    // 0x8001BD98: addiu       $a2, $zero, 0x461
    ctx->r6 = ADD32(0, 0X461);
    // 0x8001BD9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001BDA0: beq         $v1, $at, L_8001BF2C
    if (ctx->r3 == ctx->r1) {
        // 0x8001BDA4: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8001BF2C;
    }
    // 0x8001BDA4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8001BDA8: beql        $v1, $a1, L_8001BFA4
    if (ctx->r3 == ctx->r5) {
        // 0x8001BDAC: addiu       $t5, $zero, 0xFF
        ctx->r13 = ADD32(0, 0XFF);
            goto L_8001BFA4;
    }
    goto skip_1;
    // 0x8001BDAC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    skip_1:
    // 0x8001BDB0: b           L_8001BFB4
    // 0x8001BDB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001BFB4;
    // 0x8001BDB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BDB8: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
L_8001BDBC:
    // 0x8001BDBC: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x8001BDC0: lbu         $a3, 0x6($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X6);
    // 0x8001BDC4: jal         0x8001D444
    // 0x8001BDC8: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    Audio_PlaySequence(rdram, ctx);
        goto after_0;
    // 0x8001BDC8: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    after_0:
    // 0x8001BDCC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001BDD0: addiu       $t1, $t1, 0x5E7C
    ctx->r9 = ADD32(ctx->r9, 0X5E7C);
    // 0x8001BDD4: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8001BDD8: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8001BDDC: addiu       $t0, $t0, 0x5E84
    ctx->r8 = ADD32(ctx->r8, 0X5E84);
    // 0x8001BDE0: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001BDE4: sll         $t6, $t7, 5
    ctx->r14 = S32(ctx->r15 << 5);
    // 0x8001BDE8: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8001BDEC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001BDF0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001BDF4: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BDF8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001BDFC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001BE00: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001BE04: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001BE08: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8001BE0C: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8001BE10: lhu         $t3, 0x5FFC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X5FFC);
    // 0x8001BE14: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8001BE18: addiu       $t2, $t2, 0x5E80
    ctx->r10 = ADD32(ctx->r10, 0X5E80);
    // 0x8001BE1C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8001BE20: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
    // 0x8001BE24: b           L_8001BFB0
    // 0x8001BE28: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
        goto L_8001BFB0;
    // 0x8001BE28: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
L_8001BE2C:
    // 0x8001BE2C: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x8001BE30: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8001BE34: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8001BE38: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x8001BE3C: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x8001BE40: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8001BE44: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8001BE48: jal         0x800182F4
    // 0x8001BE4C: or          $a0, $t6, $t9
    ctx->r4 = ctx->r14 | ctx->r25;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x8001BE4C: or          $a0, $t6, $t9
    ctx->r4 = ctx->r14 | ctx->r25;
    after_1:
    // 0x8001BE50: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001BE54: addiu       $t1, $t1, 0x5E7C
    ctx->r9 = ADD32(ctx->r9, 0X5E7C);
    // 0x8001BE58: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8001BE5C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8001BE60: addiu       $t0, $t0, 0x5E84
    ctx->r8 = ADD32(ctx->r8, 0X5E84);
    // 0x8001BE64: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001BE68: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8001BE6C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8001BE70: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001BE74: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8001BE78: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001BE7C: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8001BE80: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8001BE84: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8001BE88: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8001BE8C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001BE90: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001BE94: lhu         $t8, 0x5FFC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X5FFC);
    // 0x8001BE98: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8001BE9C: addiu       $t2, $t2, 0x5E80
    ctx->r10 = ADD32(ctx->r10, 0X5E80);
    // 0x8001BEA0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8001BEA4: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
    // 0x8001BEA8: b           L_8001BFB0
    // 0x8001BEAC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
        goto L_8001BFB0;
    // 0x8001BEAC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8001BEB0:
    // 0x8001BEB0: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x8001BEB4: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x8001BEB8: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x8001BEBC: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x8001BEC0: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x8001BEC4: jal         0x8001D9E0
    // 0x8001BEC8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Audio_PlaySequenceDistorted(rdram, ctx);
        goto after_2;
    // 0x8001BEC8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_2:
    // 0x8001BECC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001BED0: addiu       $t1, $t1, 0x5E7C
    ctx->r9 = ADD32(ctx->r9, 0X5E7C);
    // 0x8001BED4: lbu         $t5, 0x0($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X0);
    // 0x8001BED8: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8001BEDC: addiu       $t0, $t0, 0x5E84
    ctx->r8 = ADD32(ctx->r8, 0X5E84);
    // 0x8001BEE0: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001BEE4: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x8001BEE8: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8001BEEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001BEF0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001BEF4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8001BEF8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001BEFC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001BF00: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001BF04: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8001BF08: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8001BF0C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8001BF10: lhu         $t9, 0x5FFC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X5FFC);
    // 0x8001BF14: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8001BF18: addiu       $t2, $t2, 0x5E80
    ctx->r10 = ADD32(ctx->r10, 0X5E80);
    // 0x8001BF1C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x8001BF20: sb          $t3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r11;
    // 0x8001BF24: b           L_8001BFB0
    // 0x8001BF28: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
        goto L_8001BFB0;
    // 0x8001BF28: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_8001BF2C:
    // 0x8001BF2C: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
    // 0x8001BF30: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8001BF34: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8001BF38: jal         0x8001D4AC
    // 0x8001BF3C: andi        $a0, $t4, 0xFF
    ctx->r4 = ctx->r12 & 0XFF;
    Audio_PlayFanfare(rdram, ctx);
        goto after_3;
    // 0x8001BF3C: andi        $a0, $t4, 0xFF
    ctx->r4 = ctx->r12 & 0XFF;
    after_3:
    // 0x8001BF40: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001BF44: addiu       $t1, $t1, 0x5E7C
    ctx->r9 = ADD32(ctx->r9, 0X5E7C);
    // 0x8001BF48: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8001BF4C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8001BF50: addiu       $t0, $t0, 0x5E84
    ctx->r8 = ADD32(ctx->r8, 0X5E84);
    // 0x8001BF54: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001BF58: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8001BF5C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8001BF60: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001BF64: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001BF68: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001BF6C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8001BF70: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001BF74: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001BF78: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8001BF7C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8001BF80: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8001BF84: lhu         $t3, 0x5FFC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X5FFC);
    // 0x8001BF88: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8001BF8C: addiu       $t2, $t2, 0x5E80
    ctx->r10 = ADD32(ctx->r10, 0X5E80);
    // 0x8001BF90: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8001BF94: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
    // 0x8001BF98: b           L_8001BFB0
    // 0x8001BF9C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
        goto L_8001BFB0;
    // 0x8001BF9C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8001BFA0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
L_8001BFA4:
    // 0x8001BFA4: b           L_8001BFB0
    // 0x8001BFA8: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
        goto L_8001BFB0;
    // 0x8001BFA8: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
L_8001BFAC:
    // 0x8001BFAC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8001BFB0:
    // 0x8001BFB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001BFB4:
    // 0x8001BFB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001BFB8: jr          $ra
    // 0x8001BFBC: nop

    return;
    // 0x8001BFBC: nop

;}
RECOMP_FUNC void ActorCutscene_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F8AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004F8B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004F8B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004F8B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004F8BC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004F8C0: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8004F8C4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8004F8C8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004F8CC: bne         $a1, $at, L_8004F8E4
    if (ctx->r5 != ctx->r1) {
        // 0x8004F8D0: nop
    
            goto L_8004F8E4;
    }
    // 0x8004F8D0: nop

    // 0x8004F8D4: jal         0x80093164
    // 0x8004F8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_CsIntroActors_Update(rdram, ctx);
        goto after_0;
    // 0x8004F8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8004F8DC: b           L_8004FCA8
    // 0x8004F8E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F8E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F8E4:
    // 0x8004F8E4: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8004F8E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004F8EC: lw          $v0, 0x1C8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C8);
    // 0x8004F8F0: beq         $v0, $zero, L_8004FC94
    if (ctx->r2 == 0) {
        // 0x8004F8F4: nop
    
            goto L_8004FC94;
    }
    // 0x8004F8F4: nop

    // 0x8004F8F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004F8FC: beq         $v0, $at, L_8004FC74
    if (ctx->r2 == ctx->r1) {
        // 0x8004F900: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8004FC74;
    }
    // 0x8004F900: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004F904: beq         $v0, $at, L_8004F91C
    if (ctx->r2 == ctx->r1) {
        // 0x8004F908: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8004F91C;
    }
    // 0x8004F908: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004F90C: beq         $v0, $at, L_8004FC84
    if (ctx->r2 == ctx->r1) {
        // 0x8004F910: nop
    
            goto L_8004FC84;
    }
    // 0x8004F910: nop

    // 0x8004F914: b           L_8004FCA8
    // 0x8004F918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F91C:
    // 0x8004F91C: sltiu       $at, $a1, 0x14
    ctx->r1 = ctx->r5 < 0X14 ? 1 : 0;
    // 0x8004F920: beq         $at, $zero, L_8004FC64
    if (ctx->r1 == 0) {
        // 0x8004F924: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_8004FC64;
    }
    // 0x8004F924: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8004F928: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F92C: addu        $at, $at, $t6
    gpr jr_addend_8004F934 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004F930: lw          $t6, 0x5C4C($at)
    ctx->r14 = ADD32(ctx->r1, 0X5C4C);
    // 0x8004F934: jr          $t6
    // 0x8004F938: nop

    switch (jr_addend_8004F934 >> 2) {
        case 0: goto L_8004FBD0; break;
        case 1: goto L_8004F9DC; break;
        case 2: goto L_8004FC04; break;
        case 3: goto L_8004F9CC; break;
        case 4: goto L_8004FC64; break;
        case 5: goto L_8004F93C; break;
        case 6: goto L_8004FC64; break;
        case 7: goto L_8004F95C; break;
        case 8: goto L_8004F97C; break;
        case 9: goto L_8004F99C; break;
        case 10: goto L_8004FC64; break;
        case 11: goto L_8004FC44; break;
        case 12: goto L_8004FC34; break;
        case 13: goto L_8004FC64; break;
        case 14: goto L_8004FA0C; break;
        case 15: goto L_8004FC64; break;
        case 16: goto L_8004F9AC; break;
        case 17: goto L_8004FC54; break;
        case 18: goto L_8004F9BC; break;
        case 19: goto L_8004F99C; break;
        default: switch_error(__func__, 0x8004F934, 0x800D5C4C);
    }
    // 0x8004F938: nop

L_8004F93C:
    // 0x8004F93C: lw          $t7, 0x1D0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1D0);
    // 0x8004F940: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8004F944: bnel        $at, $zero, L_8004FCA8
    if (ctx->r1 != 0) {
        // 0x8004F948: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8004FCA8;
    }
    goto skip_0;
    // 0x8004F948: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8004F94C: jal         0x8019FF00
    // 0x8004F950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019FF00(rdram, ctx);
        goto after_1;
    // 0x8004F950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004F954: b           L_8004FCA8
    // 0x8004F958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F95C:
    // 0x8004F95C: lw          $t8, 0x1D0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1D0);
    // 0x8004F960: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8004F964: bnel        $at, $zero, L_8004FCA8
    if (ctx->r1 != 0) {
        // 0x8004F968: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8004FCA8;
    }
    goto skip_1;
    // 0x8004F968: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8004F96C: jal         0x801A8BE8
    // 0x8004F970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Solar_801A8BE8(rdram, ctx);
        goto after_2;
    // 0x8004F970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8004F974: b           L_8004FCA8
    // 0x8004F978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F97C:
    // 0x8004F97C: lw          $t9, 0x1D0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1D0);
    // 0x8004F980: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8004F984: bnel        $at, $zero, L_8004FCA8
    if (ctx->r1 != 0) {
        // 0x8004F988: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8004FCA8;
    }
    goto skip_2;
    // 0x8004F988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8004F98C: jal         0x8019E5F0
    // 0x8004F990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Zoness_8019E5F0(rdram, ctx);
        goto after_3;
    // 0x8004F990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8004F994: b           L_8004FCA8
    // 0x8004F998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F99C:
    // 0x8004F99C: jal         0x80195E44
    // 0x8004F9A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Andross_ArwingEscape_Update(rdram, ctx);
        goto after_4;
    // 0x8004F9A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004F9A4: b           L_8004FCA8
    // 0x8004F9A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F9A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F9AC:
    // 0x8004F9AC: jal         0x80197F10
    // 0x8004F9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Katina_SFTeamFlyTowardsCamera(rdram, ctx);
        goto after_5;
    // 0x8004F9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004F9B4: b           L_8004FCA8
    // 0x8004F9B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F9B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F9BC:
    // 0x8004F9BC: jal         0x8019DD20
    // 0x8004F9C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorZ_LevelCompleteCsUpdate(rdram, ctx);
        goto after_6;
    // 0x8004F9C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8004F9C4: b           L_8004FCA8
    // 0x8004F9C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F9C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F9CC:
    // 0x8004F9CC: jal         0x8018DA58
    // 0x8004F9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Area6_8018DA58(rdram, ctx);
        goto after_7;
    // 0x8004F9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004F9D4: b           L_8004FCA8
    // 0x8004F9D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F9D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F9DC:
    // 0x8004F9DC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F9E0: lw          $t1, -0x7D84($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D84);
    // 0x8004F9E4: bne         $t1, $zero, L_8004F9FC
    if (ctx->r9 != 0) {
        // 0x8004F9E8: nop
    
            goto L_8004F9FC;
    }
    // 0x8004F9E8: nop

    // 0x8004F9EC: jal         0x8018ED9C
    // 0x8004F9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Meteo_8018ED9C(rdram, ctx);
        goto after_8;
    // 0x8004F9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8004F9F4: b           L_8004FCA8
    // 0x8004F9F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004F9F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F9FC:
    // 0x8004F9FC: jal         0x80049630
    // 0x8004FA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_TeamFormAlongPlayer(rdram, ctx);
        goto after_9;
    // 0x8004FA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8004FA04: b           L_8004FCA8
    // 0x8004FA08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FA08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FA0C:
    // 0x8004FA0C: lh          $t2, 0xB6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB6);
    // 0x8004FA10: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004FA14: bnel        $t2, $at, L_8004FCA8
    if (ctx->r10 != ctx->r1) {
        // 0x8004FA18: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8004FCA8;
    }
    goto skip_3;
    // 0x8004FA18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8004FA1C: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8004FA20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004FA24: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8004FA28: beq         $v0, $zero, L_8004FA40
    if (ctx->r2 == 0) {
        // 0x8004FA2C: nop
    
            goto L_8004FA40;
    }
    // 0x8004FA2C: nop

    // 0x8004FA30: beq         $v0, $at, L_8004FA98
    if (ctx->r2 == ctx->r1) {
        // 0x8004FA34: addiu       $a0, $s0, 0x110
        ctx->r4 = ADD32(ctx->r16, 0X110);
            goto L_8004FA98;
    }
    // 0x8004FA34: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x8004FA38: b           L_8004FCA8
    // 0x8004FA3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FA3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FA40:
    // 0x8004FA40: lw          $t3, 0x7A80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A80);
    // 0x8004FA44: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8004FA48: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004FA4C: bne         $t3, $at, L_8004FCA4
    if (ctx->r11 != ctx->r1) {
        // 0x8004FA50: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8004FCA4;
    }
    // 0x8004FA50: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004FA54: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004FA58: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004FA5C: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x8004FA60: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8004FA64: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
    // 0x8004FA68: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
    // 0x8004FA6C: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
    // 0x8004FA70: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8004FA74: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x8004FA78: ori         $a0, $a0, 0xF026
    ctx->r4 = ctx->r4 | 0XF026;
    // 0x8004FA7C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8004FA80: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004FA84: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8004FA88: jal         0x80019218
    // 0x8004FA8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8004FA8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8004FA90: b           L_8004FCA8
    // 0x8004FA94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FA94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FA98:
    // 0x8004FA98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004FA9C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8004FAA0: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x8004FAA4: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8004FAA8: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8004FAAC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8004FAB0: jal         0x8009BC2C
    // 0x8004FAB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8004FAB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x8004FAB8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004FABC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004FAC0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004FAC4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8004FAC8: addiu       $a2, $a2, -0x7CB8
    ctx->r6 = ADD32(ctx->r6, -0X7CB8);
    // 0x8004FACC: addiu       $a1, $a1, -0x7CC0
    ctx->r5 = ADD32(ctx->r5, -0X7CC0);
    // 0x8004FAD0: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x8004FAD4: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x8004FAD8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8004FADC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8004FAE0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8004FAE4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8004FAE8: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
    // 0x8004FAEC: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8004FAF0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004FAF4: beq         $v0, $at, L_8004FB10
    if (ctx->r2 == ctx->r1) {
        // 0x8004FAF8: addiu       $t1, $zero, 0xC0
        ctx->r9 = ADD32(0, 0XC0);
            goto L_8004FB10;
    }
    // 0x8004FAF8: addiu       $t1, $zero, 0xC0
    ctx->r9 = ADD32(0, 0XC0);
    // 0x8004FAFC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8004FB00: beq         $v0, $at, L_8004FB10
    if (ctx->r2 == ctx->r1) {
        // 0x8004FB04: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_8004FB10;
    }
    // 0x8004FB04: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8004FB08: bnel        $v0, $at, L_8004FB24
    if (ctx->r2 != ctx->r1) {
        // 0x8004FB0C: lw          $t4, 0x50($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X50);
            goto L_8004FB24;
    }
    goto skip_4;
    // 0x8004FB0C: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    skip_4:
L_8004FB10:
    // 0x8004FB10: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8004FB14: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004FB18: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8004FB1C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8004FB20: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
L_8004FB24:
    // 0x8004FB24: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004FB28: addiu       $v0, $t4, -0x2
    ctx->r2 = ADD32(ctx->r12, -0X2);
    // 0x8004FB2C: bgez        $v0, L_8004FB44
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004FB30: sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
            goto L_8004FB44;
    }
    // 0x8004FB30: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8004FB34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004FB38: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8004FB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004FB40: swc1        $f6, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f6.u32l;
L_8004FB44:
    // 0x8004FB44: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004FB48: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8004FB4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004FB50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004FB54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004FB58: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8004FB5C: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x8004FB60: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8004FB64: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8004FB68: swc1        $f18, -0x7C94($at)
    MEM_W(-0X7C94, ctx->r1) = ctx->f18.u32l;
    // 0x8004FB6C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004FB70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FB74: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004FB78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004FB7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004FB80: swc1        $f8, -0x7C90($at)
    MEM_W(-0X7C90, ctx->r1) = ctx->f8.u32l;
    // 0x8004FB84: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8004FB88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004FB8C: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8004FB90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004FB94: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8004FB98: swc1        $f18, -0x7C8C($at)
    MEM_W(-0X7C8C, ctx->r1) = ctx->f18.u32l;
    // 0x8004FB9C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8004FBA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FBA4: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8004FBA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004FBAC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004FBB0: swc1        $f8, -0x7C88($at)
    MEM_W(-0X7C88, ctx->r1) = ctx->f8.u32l;
    // 0x8004FBB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004FBB8: sw          $t0, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = ctx->r8;
    // 0x8004FBBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004FBC0: sw          $t0, -0x7C9C($at)
    MEM_W(-0X7C9C, ctx->r1) = ctx->r8;
    // 0x8004FBC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004FBC8: b           L_8004FCA4
    // 0x8004FBCC: sw          $t6, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = ctx->r14;
        goto L_8004FCA4;
    // 0x8004FBCC: sw          $t6, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = ctx->r14;
L_8004FBD0:
    // 0x8004FBD0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8004FBD4: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x8004FBD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004FBDC: bne         $t7, $at, L_8004FBF4
    if (ctx->r15 != ctx->r1) {
        // 0x8004FBE0: nop
    
            goto L_8004FBF4;
    }
    // 0x8004FBE0: nop

    // 0x8004FBE4: jal         0x8004E4D4
    // 0x8004FBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_CoTeamFormAlongPlayer2(rdram, ctx);
        goto after_12;
    // 0x8004FBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8004FBEC: b           L_8004FCA8
    // 0x8004FBF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FBF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FBF4:
    // 0x8004FBF4: jal         0x8004EBD0
    // 0x8004FBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_CoTeamFormAlongPlayer(rdram, ctx);
        goto after_13;
    // 0x8004FBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8004FBFC: b           L_8004FCA8
    // 0x8004FC00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC04:
    // 0x8004FC04: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004FC08: lw          $t8, -0x7D84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D84);
    // 0x8004FC0C: beq         $t8, $zero, L_8004FC24
    if (ctx->r24 == 0) {
        // 0x8004FC10: nop
    
            goto L_8004FC24;
    }
    // 0x8004FC10: nop

    // 0x8004FC14: jal         0x80049630
    // 0x8004FC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_TeamFormAlongPlayer(rdram, ctx);
        goto after_14;
    // 0x8004FC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8004FC1C: b           L_8004FCA8
    // 0x8004FC20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC24:
    // 0x8004FC24: jal         0x8004E4D4
    // 0x8004FC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_CoTeamFormAlongPlayer2(rdram, ctx);
        goto after_15;
    // 0x8004FC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8004FC2C: b           L_8004FCA8
    // 0x8004FC30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC34:
    // 0x8004FC34: jal         0x8004E4D4
    // 0x8004FC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_CoTeamFormAlongPlayer2(rdram, ctx);
        goto after_16;
    // 0x8004FC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8004FC3C: b           L_8004FCA8
    // 0x8004FC40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC44:
    // 0x8004FC44: jal         0x801B28BC
    // 0x8004FC48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801B28BC(rdram, ctx);
        goto after_17;
    // 0x8004FC48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8004FC4C: b           L_8004FCA8
    // 0x8004FC50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC54:
    // 0x8004FC54: jal         0x8004F05C
    // 0x8004FC58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_ActorCs_LevelIntro(rdram, ctx);
        goto after_18;
    // 0x8004FC58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8004FC5C: b           L_8004FCA8
    // 0x8004FC60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC64:
    // 0x8004FC64: jal         0x8004EBD0
    // 0x8004FC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_CoTeamFormAlongPlayer(rdram, ctx);
        goto after_19;
    // 0x8004FC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8004FC6C: b           L_8004FCA8
    // 0x8004FC70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC74:
    // 0x8004FC74: jal         0x8004F05C
    // 0x8004FC78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_ActorCs_LevelIntro(rdram, ctx);
        goto after_20;
    // 0x8004FC78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8004FC7C: b           L_8004FCA8
    // 0x8004FC80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC84:
    // 0x8004FC84: jal         0x8004F798
    // 0x8004FC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_ActorCs_EnterWarpZone(rdram, ctx);
        goto after_21;
    // 0x8004FC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8004FC8C: b           L_8004FCA8
    // 0x8004FC90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004FCA8;
    // 0x8004FC90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FC94:
    // 0x8004FC94: bnel        $a1, $at, L_8004FCA8
    if (ctx->r5 != ctx->r1) {
        // 0x8004FC98: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8004FCA8;
    }
    goto skip_5;
    // 0x8004FC98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8004FC9C: jal         0x8019FF00
    // 0x8004FCA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019FF00(rdram, ctx);
        goto after_22;
    // 0x8004FCA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
L_8004FCA4:
    // 0x8004FCA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004FCA8:
    // 0x8004FCA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004FCAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004FCB0: jr          $ra
    // 0x8004FCB4: nop

    return;
    // 0x8004FCB4: nop

;}
RECOMP_FUNC void Cutscene_FortunaComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C90C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004C910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C914: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004C918: jal         0x80187520
    // 0x8004C91C: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8004C91C: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_0:
    // 0x8004C920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004C924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004C928: jr          $ra
    // 0x8004C92C: nop

    return;
    // 0x8004C92C: nop

;}
RECOMP_FUNC void Item_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006186C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80061870: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80061874: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80061878: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006187C: jal         0x80061444
    // 0x80061880: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    Item_Initialize(rdram, ctx);
        goto after_0;
    // 0x80061880: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80061884: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80061888: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8006188C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80061890: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80061894: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80061898: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006189C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800618A0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800618A4: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800618A8: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800618AC: lwc1        $f8, 0x642C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X642C);
    // 0x800618B0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800618B4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800618B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800618BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800618C0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800618C4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800618C8: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800618CC: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x800618D0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800618D4: nop

    // 0x800618D8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800618DC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x800618E0: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x800618E4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800618E8: nop

    // 0x800618EC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800618F0: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x800618F4: lh          $t0, 0xC($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XC);
    // 0x800618F8: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800618FC: nop

    // 0x80061900: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061904: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80061908: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x8006190C: lh          $t1, 0xA($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XA);
    // 0x80061910: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80061914: nop

    // 0x80061918: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006191C: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x80061920: lh          $t2, 0xE($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XE);
    // 0x80061924: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80061928: nop

    // 0x8006192C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061930: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x80061934: lh          $t3, 0x10($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X10);
    // 0x80061938: swc1        $f18, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f18.u32l;
    // 0x8006193C: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x80061940: jal         0x800612B8
    // 0x80061944: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80061944: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    after_1:
    // 0x80061948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006194C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061950: jr          $ra
    // 0x80061954: nop

    return;
    // 0x80061954: nop

;}
RECOMP_FUNC void func_versus_800BDA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDA54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BDA58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BDA5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BDA60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BDA64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDA68: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x800BDA6C: addiu       $a1, $a1, 0x7F60
    ctx->r5 = ADD32(ctx->r5, 0X7F60);
    // 0x800BDA70: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BDA74: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800BDA78: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800BDA7C: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800BDA80: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800BDA84: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800BDA88: jal         0x8009D994
    // 0x800BDA8C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BDA8C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BDA90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BDA94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BDA98: jr          $ra
    // 0x800BDA9C: nop

    return;
    // 0x800BDA9C: nop

;}
RECOMP_FUNC void HUD_VenomTitleCard_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086444: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80086448: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8008644C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80086450: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80086454: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80086458: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8008645C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80086460: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80086464: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80086468: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8008646C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80086470: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80086474: addiu       $t7, $t7, 0x1C9C
    ctx->r15 = ADD32(ctx->r15, 0X1C9C);
    // 0x80086478: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008647C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80086480: addiu       $t6, $sp, 0xA8
    ctx->r14 = ADD32(ctx->r29, 0XA8);
    // 0x80086484: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80086488: addiu       $t2, $t2, 0x1CA4
    ctx->r10 = ADD32(ctx->r10, 0X1CA4);
    // 0x8008648C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80086490: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80086494: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80086498: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8008649C: addiu       $t1, $sp, 0xA0
    ctx->r9 = ADD32(ctx->r29, 0XA0);
    // 0x800864A0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800864A4: addiu       $t8, $t8, 0x1CAC
    ctx->r24 = ADD32(ctx->r24, 0X1CAC);
    // 0x800864A8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800864AC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800864B0: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800864B4: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800864B8: addiu       $t9, $sp, 0x98
    ctx->r25 = ADD32(ctx->r29, 0X98);
    // 0x800864BC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800864C0: addiu       $t3, $t3, 0x1CB4
    ctx->r11 = ADD32(ctx->r11, 0X1CB4);
    // 0x800864C4: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800864C8: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800864CC: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800864D0: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800864D4: addiu       $t4, $sp, 0x90
    ctx->r12 = ADD32(ctx->r29, 0X90);
    // 0x800864D8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800864DC: addiu       $t6, $t6, 0x1CBC
    ctx->r14 = ADD32(ctx->r14, 0X1CBC);
    // 0x800864E0: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x800864E4: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x800864E8: lw          $t0, 0x4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4);
    // 0x800864EC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800864F0: addiu       $t7, $sp, 0x88
    ctx->r15 = ADD32(ctx->r29, 0X88);
    // 0x800864F4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800864F8: addiu       $t1, $t1, 0x1CC4
    ctx->r9 = ADD32(ctx->r9, 0X1CC4);
    // 0x800864FC: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x80086500: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80086504: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x80086508: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8008650C: addiu       $t2, $sp, 0x80
    ctx->r10 = ADD32(ctx->r29, 0X80);
    // 0x80086510: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80086514: addiu       $t9, $t9, 0x1CCC
    ctx->r25 = ADD32(ctx->r25, 0X1CCC);
    // 0x80086518: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8008651C: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80086520: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80086524: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80086528: addiu       $t8, $sp, 0x78
    ctx->r24 = ADD32(ctx->r29, 0X78);
    // 0x8008652C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80086530: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80086534: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80086538: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8008653C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80086540: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80086544: beq         $v0, $at, L_80086560
    if (ctx->r2 == ctx->r1) {
        // 0x80086548: addiu       $s6, $zero, 0x13
        ctx->r22 = ADD32(0, 0X13);
            goto L_80086560;
    }
    // 0x80086548: addiu       $s6, $zero, 0x13
    ctx->r22 = ADD32(0, 0X13);
    // 0x8008654C: addiu       $s6, $zero, 0x13
    ctx->r22 = ADD32(0, 0X13);
    // 0x80086550: bnel        $v0, $s6, L_80086568
    if (ctx->r2 != ctx->r22) {
        // 0x80086554: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80086568;
    }
    goto skip_0;
    // 0x80086554: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_0:
    // 0x80086558: b           L_80086564
    // 0x8008655C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80086564;
    // 0x8008655C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80086560:
    // 0x80086560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80086564:
    // 0x80086564: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_80086568:
    // 0x80086568: beq         $a2, $at, L_80086634
    if (ctx->r6 == ctx->r1) {
        // 0x8008656C: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_80086634;
    }
    // 0x8008656C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80086570: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80086574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80086578: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008657C: jal         0x800B8DD0
    // 0x80086580: sw          $a2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80086580: sw          $a2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r6;
    after_0:
    // 0x80086584: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x80086588: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008658C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80086590: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80086594: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80086598: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8008659C: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x800865A0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800865A4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800865A8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800865AC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800865B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800865B4: addiu       $t1, $sp, 0xA0
    ctx->r9 = ADD32(ctx->r29, 0XA0);
    // 0x800865B8: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x800865BC: addiu       $t6, $sp, 0x90
    ctx->r14 = ADD32(ctx->r29, 0X90);
    // 0x800865C0: addiu       $t7, $sp, 0x88
    ctx->r15 = ADD32(ctx->r29, 0X88);
    // 0x800865C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800865C8: addu        $s5, $v0, $t7
    ctx->r21 = ADD32(ctx->r2, ctx->r15);
    // 0x800865CC: addu        $s4, $v0, $t6
    ctx->r20 = ADD32(ctx->r2, ctx->r14);
    // 0x800865D0: addu        $s3, $v0, $t5
    ctx->r19 = ADD32(ctx->r2, ctx->r13);
    // 0x800865D4: addu        $s2, $v0, $t1
    ctx->r18 = ADD32(ctx->r2, ctx->r9);
    // 0x800865D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800865DC: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
L_800865E0:
    // 0x800865E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800865E4: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800865E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800865EC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800865F0: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800865F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800865F8: lwc1        $f6, 0x0($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800865FC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80086600: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80086604: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80086608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008660C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80086610: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80086614: sub.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x80086618: mflo        $t8
    ctx->r24 = lo;
    // 0x8008661C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80086620: jal         0x8009D994
    // 0x80086624: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x80086624: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80086628: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008662C: bnel        $s0, $s6, L_800865E0
    if (ctx->r16 != ctx->r22) {
        // 0x80086630: mtc1        $s0, $f8
        ctx->f8.u32l = ctx->r16;
            goto L_800865E0;
    }
    goto skip_1;
    // 0x80086630: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    skip_1:
L_80086634:
    // 0x80086634: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80086638: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8008663C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80086640: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80086644: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80086648: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8008664C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80086650: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80086654: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80086658: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8008665C: jr          $ra
    // 0x80086660: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80086660: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Cutscene_WarpZoneComplete_TeamSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048CC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80048CC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80048CCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80048CD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80048CD4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80048CD8: jal         0x800613C4
    // 0x80048CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80048CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80048CE0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80048CE4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80048CE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048CEC: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x80048CF0: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80048CF4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80048CF8: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80048CFC: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80048D00: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80048D04: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80048D08: subu        $t8, $t8, $a3
    ctx->r24 = SUB32(ctx->r24, ctx->r7);
    // 0x80048D0C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80048D10: addiu       $t9, $t9, -0x60A0
    ctx->r25 = ADD32(ctx->r25, -0X60A0);
    // 0x80048D14: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80048D18: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80048D1C: lwc1        $f4, 0x74($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X74);
    // 0x80048D20: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80048D24: addiu       $t4, $t4, -0x6070
    ctx->r12 = ADD32(ctx->r12, -0X6070);
    // 0x80048D28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80048D2C: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x80048D30: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80048D34: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80048D38: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80048D3C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80048D40: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80048D44: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80048D48: lwc1        $f10, 0x78($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X78);
    // 0x80048D4C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80048D50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80048D54: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80048D58: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80048D5C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80048D60: lwc1        $f4, 0x138($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X138);
    // 0x80048D64: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x80048D68: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80048D6C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80048D70: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80048D74: swc1        $f16, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f16.u32l;
    // 0x80048D78: jal         0x800612B8
    // 0x80048D7C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80048D7C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80048D80: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80048D84: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80048D88: addiu       $t5, $t5, -0x6064
    ctx->r13 = ADD32(ctx->r13, -0X6064);
    // 0x80048D8C: bne         $a2, $t5, L_80048DFC
    if (ctx->r6 != ctx->r13) {
        // 0x80048D90: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80048DFC;
    }
    // 0x80048D90: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80048D94: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80048D98: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80048D9C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80048DA0: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80048DA4: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x80048DA8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80048DAC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80048DB0: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x80048DB4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80048DB8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80048DBC: jal         0x80019218
    // 0x80048DC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80048DC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80048DC4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80048DC8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80048DCC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80048DD0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80048DD4: lui         $a0, 0x3102
    ctx->r4 = S32(0X3102 << 16);
    // 0x80048DD8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80048DDC: ori         $a0, $a0, 0x4059
    ctx->r4 = ctx->r4 | 0X4059;
    // 0x80048DE0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80048DE4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80048DE8: jal         0x80019218
    // 0x80048DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x80048DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80048DF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80048DF4: b           L_80048E2C
    // 0x80048DF8: sh          $t8, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r24;
        goto L_80048E2C;
    // 0x80048DF8: sh          $t8, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r24;
L_80048DFC:
    // 0x80048DFC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80048E00: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80048E04: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80048E08: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x80048E0C: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80048E10: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80048E14: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80048E18: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80048E1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80048E20: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80048E24: jal         0x80019218
    // 0x80048E28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x80048E28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
L_80048E2C:
    // 0x80048E2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80048E30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80048E34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80048E38: jr          $ra
    // 0x80048E3C: nop

    return;
    // 0x80048E3C: nop

;}
RECOMP_FUNC void Effect_BlueOrb_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078AF0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078AF4: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078AFC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078B00: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80078B04: addiu       $t8, $zero, -0x4C
    ctx->r24 = ADD32(0, -0X4C);
    // 0x80078B08: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078B0C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80078B10: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80078B14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078B18: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80078B1C: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80078B20: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80078B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80078B28: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80078B2C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80078B30: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80078B34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80078B38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078B3C: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80078B40: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80078B44: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80078B48: mul.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80078B4C: jal         0x8005980C
    // 0x80078B50: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80078B50: nop

    after_0:
    // 0x80078B54: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078B58: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078B5C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078B60: lui         $t3, 0x103
    ctx->r11 = S32(0X103 << 16);
    // 0x80078B64: addiu       $t3, $t3, -0x12B0
    ctx->r11 = ADD32(ctx->r11, -0X12B0);
    // 0x80078B68: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80078B6C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80078B70: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80078B74: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80078B78: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80078B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078B84: jr          $ra
    // 0x80078B88: nop

    return;
    // 0x80078B88: nop

;}
RECOMP_FUNC void HUD_VS_ShieldGauge_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D31C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008D320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008D324: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008D328: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008D32C: addiu       $t7, $t7, 0x20E8
    ctx->r15 = ADD32(ctx->r15, 0X20E8);
    // 0x8008D330: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008D334: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8008D338: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x8008D33C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8008D340: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8008D344: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8008D348: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8008D34C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008D350: addiu       $t2, $t2, 0x20F8
    ctx->r10 = ADD32(ctx->r10, 0X20F8);
    // 0x8008D354: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8008D358: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8008D35C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8008D360: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8008D364: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x8008D368: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8008D36C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8008D370: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8008D374: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8008D378: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008D37C: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8008D380: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x8008D384: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x8008D388: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008D38C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8008D390: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8008D394: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8008D398: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8008D39C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8008D3A0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8008D3A4: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8008D3A8: lw          $t4, 0x264($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X264);
    // 0x8008D3AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D3B0: lwc1        $f8, 0x7D94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D94);
    // 0x8008D3B4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8008D3B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D3BC: lwc1        $f16, 0x7D98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D98);
    // 0x8008D3C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008D3C4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008D3C8: addiu       $t8, $t8, 0x19E0
    ctx->r24 = ADD32(ctx->r24, 0X19E0);
    // 0x8008D3CC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008D3D0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8008D3D4: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x8008D3D8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008D3DC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008D3E0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8008D3E4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8008D3E8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8008D3EC: jal         0x8009BC2C
    // 0x8008D3F0: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8008D3F0: nop

    after_0:
    // 0x8008D3F4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008D3F8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008D3FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008D400: jal         0x800B8DD0
    // 0x8008D404: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8008D404: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_1:
    // 0x8008D408: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D40C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008D410: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008D414: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008D418: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8008D41C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8008D420: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x8008D424: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8008D428: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x8008D42C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8008D430: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x8008D434: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008D438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D43C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008D440: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8008D444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008D448: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D44C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8008D450: addu        $t9, $sp, $t5
    ctx->r25 = ADD32(ctx->r29, ctx->r13);
    // 0x8008D454: addu        $t8, $sp, $t5
    ctx->r24 = ADD32(ctx->r29, ctx->r13);
    // 0x8008D458: lwc1        $f6, 0x38($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8008D45C: lwc1        $f18, 0x48($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8008D460: lwc1        $f10, 0x19E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X19E0);
    // 0x8008D464: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008D468: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008D46C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8008D470: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008D474: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8008D478: jal         0x8008D0DC
    // 0x8008D47C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    HUD_VS_ShieldGaugeTex_Draw(rdram, ctx);
        goto after_2;
    // 0x8008D47C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_2:
    // 0x8008D480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008D484: jal         0x800B8DD0
    // 0x8008D488: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8008D488: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_3:
    // 0x8008D48C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D490: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008D494: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008D498: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008D49C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008D4A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008D4A4: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8008D4A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8008D4AC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x8008D4B0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8008D4B4: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x8008D4B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008D4BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008D4C0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8008D4C4: addu        $t3, $sp, $t4
    ctx->r11 = ADD32(ctx->r29, ctx->r12);
    // 0x8008D4C8: addu        $t1, $sp, $t4
    ctx->r9 = ADD32(ctx->r29, ctx->r12);
    // 0x8008D4CC: lwc1        $f14, 0x38($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X38);
    // 0x8008D4D0: lwc1        $f12, 0x48($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X48);
    // 0x8008D4D4: jal         0x8008CFB8
    // 0x8008D4D8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    HUD_VS_ShieldGaugeFrame_Draw(rdram, ctx);
        goto after_4;
    // 0x8008D4D8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    after_4:
    // 0x8008D4DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008D4E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008D4E4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8008D4E8: jr          $ra
    // 0x8008D4EC: nop

    return;
    // 0x8008D4EC: nop

;}
RECOMP_FUNC void RCP_SetupDL_45(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9FC8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9FCC: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9FD0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B9FD4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9FD8: addiu       $t8, $t8, 0x3E58
    ctx->r24 = ADD32(ctx->r24, 0X3E58);
    // 0x800B9FDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9FE0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B9FE4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9FE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B9FEC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B9FF0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B9FF4: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B9FF8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B9FFC: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800BA000: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800BA004: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800BA008: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800BA00C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800BA010: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800BA014: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800BA018: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800BA01C: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800BA020: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800BA024: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800BA028: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800BA02C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800BA030: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800BA034: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800BA038: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800BA03C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800BA040: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BA044: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800BA048: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BA04C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800BA050: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800BA054: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800BA058: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800BA05C: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800BA060: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA064: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800BA068: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800BA06C: bne         $t2, $zero, L_800BA078
    if (ctx->r10 != 0) {
        // 0x800BA070: nop
    
            goto L_800BA078;
    }
    // 0x800BA070: nop

    // 0x800BA074: break       7
    do_break(2148245620);
L_800BA078:
    // 0x800BA078: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA07C: bne         $t2, $at, L_800BA090
    if (ctx->r10 != ctx->r1) {
        // 0x800BA080: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA090;
    }
    // 0x800BA080: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA084: bne         $t6, $at, L_800BA090
    if (ctx->r14 != ctx->r1) {
        // 0x800BA088: nop
    
            goto L_800BA090;
    }
    // 0x800BA088: nop

    // 0x800BA08C: break       6
    do_break(2148245644);
L_800BA090:
    // 0x800BA090: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BA094: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800BA098: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800BA09C: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800BA0A0: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800BA0A4: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA0A8: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800BA0AC: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800BA0B0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BA0B4: bne         $t2, $zero, L_800BA0C0
    if (ctx->r10 != 0) {
        // 0x800BA0B8: nop
    
            goto L_800BA0C0;
    }
    // 0x800BA0B8: nop

    // 0x800BA0BC: break       7
    do_break(2148245692);
L_800BA0C0:
    // 0x800BA0C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA0C4: bne         $t2, $at, L_800BA0D8
    if (ctx->r10 != ctx->r1) {
        // 0x800BA0C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA0D8;
    }
    // 0x800BA0C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA0CC: bne         $t8, $at, L_800BA0D8
    if (ctx->r24 != ctx->r1) {
        // 0x800BA0D0: nop
    
            goto L_800BA0D8;
    }
    // 0x800BA0D0: nop

    // 0x800BA0D4: break       6
    do_break(2148245716);
L_800BA0D8:
    // 0x800BA0D8: jr          $ra
    // 0x800BA0DC: nop

    return;
    // 0x800BA0DC: nop

;}
RECOMP_FUNC void Player_ArwingBoost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2574: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B2578: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B257C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B2584: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B2588: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B258C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B2590: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B2594: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x800B2598: addiu       $t1, $t1, 0x7928
    ctx->r9 = ADD32(ctx->r9, 0X7928);
    // 0x800B259C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B25A0: addiu       $t0, $t0, 0x7880
    ctx->r8 = ADD32(ctx->r8, 0X7880);
    // 0x800B25A4: bc1t        L_800B25F4
    if (c1cs) {
        // 0x800B25A8: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_800B25F4;
    }
    // 0x800B25A8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B25AC: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B25B0: addiu       $t2, $t2, 0x7974
    ctx->r10 = ADD32(ctx->r10, 0X7974);
    // 0x800B25B4: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800B25B8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800B25BC: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x800B25C0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800B25C4: lhu         $v1, 0x0($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X0);
    // 0x800B25C8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800B25CC: addiu       $a3, $a3, 0x7908
    ctx->r7 = ADD32(ctx->r7, 0X7908);
    // 0x800B25D0: and         $t4, $t9, $v1
    ctx->r12 = ctx->r25 & ctx->r3;
    // 0x800B25D4: beq         $t4, $zero, L_800B25F4
    if (ctx->r12 == 0) {
        // 0x800B25D8: addu        $t5, $a3, $t6
        ctx->r13 = ADD32(ctx->r7, ctx->r14);
            goto L_800B25F4;
    }
    // 0x800B25D8: addu        $t5, $a3, $t6
    ctx->r13 = ADD32(ctx->r7, ctx->r14);
    // 0x800B25DC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800B25E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B25E4: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x800B25E8: beql        $t7, $zero, L_800B25F8
    if (ctx->r15 == 0) {
        // 0x800B25EC: lw          $t8, 0x0($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X0);
            goto L_800B25F8;
    }
    goto skip_0;
    // 0x800B25EC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x800B25F0: sw          $t3, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r11;
L_800B25F4:
    // 0x800B25F4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
L_800B25F8:
    // 0x800B25F8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800B25FC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B2600: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B2604: addiu       $t2, $t2, 0x7974
    ctx->r10 = ADD32(ctx->r10, 0X7974);
    // 0x800B2608: addiu       $t1, $t1, 0x7928
    ctx->r9 = ADD32(ctx->r9, 0X7928);
    // 0x800B260C: addiu       $a3, $a3, 0x7908
    ctx->r7 = ADD32(ctx->r7, 0X7908);
    // 0x800B2610: bne         $t8, $zero, L_800B2630
    if (ctx->r24 != 0) {
        // 0x800B2614: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800B2630;
    }
    // 0x800B2614: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B2618: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B261C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B2620: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B2624: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B2628: b           L_800B2644
    // 0x800B262C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
        goto L_800B2644;
    // 0x800B262C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
L_800B2630:
    // 0x800B2630: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B2634: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2638: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B263C: lwc1        $f12, -0x7684($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7684);
    // 0x800B2640: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_800B2644:
    // 0x800B2644: sb          $zero, 0x484($s0)
    MEM_B(0X484, ctx->r16) = 0;
    // 0x800B2648: lw          $a0, 0x78A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78A0);
    // 0x800B264C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B2650: addiu       $t5, $t5, 0x7A70
    ctx->r13 = ADD32(ctx->r13, 0X7A70);
    // 0x800B2654: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800B2658: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x800B265C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B2660: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B2664: lw          $t9, 0x797C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X797C);
    // 0x800B2668: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800B266C: beq         $v0, $zero, L_800B267C
    if (ctx->r2 == 0) {
        // 0x800B2670: lb          $a2, 0x3($t9)
        ctx->r6 = MEM_B(ctx->r25, 0X3);
            goto L_800B267C;
    }
    // 0x800B2670: lb          $a2, 0x3($t9)
    ctx->r6 = MEM_B(ctx->r25, 0X3);
    // 0x800B2674: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800B2678: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800B267C:
    // 0x800B267C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B2680: addiu       $t7, $t7, 0x7A88
    ctx->r15 = ADD32(ctx->r15, 0X7A88);
    // 0x800B2684: addu        $a1, $a0, $t7
    ctx->r5 = ADD32(ctx->r4, ctx->r15);
    // 0x800B2688: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B268C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B2690: beq         $v0, $zero, L_800B269C
    if (ctx->r2 == 0) {
        // 0x800B2694: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800B269C;
    }
    // 0x800B2694: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800B2698: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_800B269C:
    // 0x800B269C: lw          $t9, 0x4DC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B26A0: bnel        $t9, $zero, L_800B2740
    if (ctx->r25 != 0) {
        // 0x800B26A4: lw          $v0, 0x27C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X27C);
            goto L_800B2740;
    }
    goto skip_1;
    // 0x800B26A4: lw          $v0, 0x27C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X27C);
    skip_1:
    // 0x800B26A8: lbu         $t4, 0x7AB0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7AB0);
    // 0x800B26AC: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x800B26B0: beq         $at, $zero, L_800B273C
    if (ctx->r1 == 0) {
        // 0x800B26B4: slti        $at, $a2, -0x32
        ctx->r1 = SIGNED(ctx->r6) < -0X32 ? 1 : 0;
            goto L_800B273C;
    }
    // 0x800B26B4: slti        $at, $a2, -0x32
    ctx->r1 = SIGNED(ctx->r6) < -0X32 ? 1 : 0;
    // 0x800B26B8: bne         $at, $zero, L_800B26C4
    if (ctx->r1 != 0) {
        // 0x800B26BC: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_800B26C4;
    }
    // 0x800B26BC: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800B26C0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800B26C4:
    // 0x800B26C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B26C8: blez        $v0, L_800B273C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B26CC: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_800B273C;
    }
    // 0x800B26CC: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800B26D0: beql        $at, $zero, L_800B2740
    if (ctx->r1 == 0) {
        // 0x800B26D4: lw          $v0, 0x27C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X27C);
            goto L_800B2740;
    }
    goto skip_2;
    // 0x800B26D4: lw          $v0, 0x27C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X27C);
    skip_2:
    // 0x800B26D8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800B26DC: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x800B26E0: beql        $t6, $zero, L_800B2740
    if (ctx->r14 == 0) {
        // 0x800B26E4: lw          $v0, 0x27C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X27C);
            goto L_800B2740;
    }
    goto skip_3;
    // 0x800B26E4: lw          $v0, 0x27C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X27C);
    skip_3:
    // 0x800B26E8: sw          $t3, 0x4DC($s0)
    MEM_W(0X4DC, ctx->r16) = ctx->r11;
    // 0x800B26EC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B26F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B26F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800B26F8: bnel        $t7, $zero, L_800B2710
    if (ctx->r15 != 0) {
        // 0x800B26FC: lwc1        $f0, 0x4D8($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4D8);
            goto L_800B2710;
    }
    goto skip_4;
    // 0x800B26FC: lwc1        $f0, 0x4D8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4D8);
    skip_4:
    // 0x800B2700: lw          $t8, 0x238($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X238);
    // 0x800B2704: sw          $zero, 0x238($s0)
    MEM_W(0X238, ctx->r16) = 0;
    // 0x800B2708: sw          $t8, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->r24;
    // 0x800B270C: lwc1        $f0, 0x4D8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4D8);
L_800B2710:
    // 0x800B2710: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x800B2714: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x800B2718: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800B271C: nop

    // 0x800B2720: bc1fl       L_800B2BD0
    if (!c1cs) {
        // 0x800B2724: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B2BD0;
    }
    goto skip_5;
    // 0x800B2724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800B2728: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B272C: nop

    // 0x800B2730: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800B2734: b           L_800B2BCC
    // 0x800B2738: swc1        $f18, 0x4D8($s0)
    MEM_W(0X4D8, ctx->r16) = ctx->f18.u32l;
        goto L_800B2BCC;
    // 0x800B2738: swc1        $f18, 0x4D8($s0)
    MEM_W(0X4D8, ctx->r16) = ctx->f18.u32l;
L_800B273C:
    // 0x800B273C: lw          $v0, 0x27C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X27C);
L_800B2740:
    // 0x800B2740: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800B2744: addiu       $v1, $v1, 0x1A38
    ctx->r3 = ADD32(ctx->r3, 0X1A38);
    // 0x800B2748: beq         $v0, $zero, L_800B285C
    if (ctx->r2 == 0) {
        // 0x800B274C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800B285C;
    }
    // 0x800B274C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800B2750: sw          $t9, 0x27C($s0)
    MEM_W(0X27C, ctx->r16) = ctx->r25;
    // 0x800B2754: sw          $t3, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r11;
    // 0x800B2758: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B275C: lw          $v1, 0x7E80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E80);
    // 0x800B2760: blez        $v1, L_800B27B8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B2764: nop
    
            goto L_800B27B8;
    }
    // 0x800B2764: nop

    // 0x800B2768: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800B276C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B2770: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B2774: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2778: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B277C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2780: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2784: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B2788: addiu       $t6, $t6, 0x79A8
    ctx->r14 = ADD32(ctx->r14, 0X79A8);
    // 0x800B278C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B2790: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B2794: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B2798: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800B279C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800B27A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B27A4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B27A8: jal         0x8009BC2C
    // 0x800B27AC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B27AC: nop

    after_0:
    // 0x800B27B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B27B4: nop

L_800B27B8:
    // 0x800B27B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B27BC: lwc1        $f18, -0x7680($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7680);
    // 0x800B27C0: lwc1        $f16, 0x110($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800B27C4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B27C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B27CC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B27D0: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x800B27D4: lui         $a1, 0xC302
    ctx->r5 = S32(0XC302 << 16);
    // 0x800B27D8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B27DC: swc1        $f4, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f4.u32l;
    // 0x800B27E0: jal         0x8009BC2C
    // 0x800B27E4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B27E4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800B27E8: lwc1        $f0, 0x258($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X258);
    // 0x800B27EC: lwc1        $f6, 0x130($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B27F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B27F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B27F8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800B27FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2800: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800B2804: addiu       $v1, $v1, 0x1A38
    ctx->r3 = ADD32(ctx->r3, 0X1A38);
    // 0x800B2808: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x800B280C: lwc1        $f10, -0x767C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X767C);
    // 0x800B2810: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B2814: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800B2818: swc1        $f16, 0x258($s0)
    MEM_W(0X258, ctx->r16) = ctx->f16.u32l;
    // 0x800B281C: lwc1        $f18, 0x258($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X258);
    // 0x800B2820: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800B2824: nop

    // 0x800B2828: bc1f        L_800B2834
    if (!c1cs) {
        // 0x800B282C: nop
    
            goto L_800B2834;
    }
    // 0x800B282C: nop

    // 0x800B2830: swc1        $f12, 0x258($s0)
    MEM_W(0X258, ctx->r16) = ctx->f12.u32l;
L_800B2834:
    // 0x800B2834: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800B2838: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800B283C: bnel        $t8, $zero, L_800B2BD0
    if (ctx->r24 != 0) {
        // 0x800B2840: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B2BD0;
    }
    goto skip_6;
    // 0x800B2840: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x800B2844: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B2848: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x800B284C: bne         $at, $zero, L_800B2BCC
    if (ctx->r1 != 0) {
        // 0x800B2850: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800B2BCC;
    }
    // 0x800B2850: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800B2854: b           L_800B2BCC
    // 0x800B2858: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
        goto L_800B2BCC;
    // 0x800B2858: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_800B285C:
    // 0x800B285C: swc1        $f2, 0x258($s0)
    MEM_W(0X258, ctx->r16) = ctx->f2.u32l;
    // 0x800B2860: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B2864: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x800B2868: beq         $at, $zero, L_800B2888
    if (ctx->r1 == 0) {
        // 0x800B286C: addiu       $t4, $v0, 0x4
        ctx->r12 = ADD32(ctx->r2, 0X4);
            goto L_800B2888;
    }
    // 0x800B286C: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x800B2870: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800B2874: slti        $at, $t5, 0xFC
    ctx->r1 = SIGNED(ctx->r13) < 0XFC ? 1 : 0;
    // 0x800B2878: bne         $at, $zero, L_800B2888
    if (ctx->r1 != 0) {
        // 0x800B287C: sb          $t4, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r12;
            goto L_800B2888;
    }
    // 0x800B287C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x800B2880: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800B2884: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_800B2888:
    // 0x800B2888: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B288C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800B2890: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800B2894: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x800B2898: lhu         $t4, 0x0($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X0);
    // 0x800B289C: lhu         $v1, 0x0($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X0);
    // 0x800B28A0: addu        $t6, $a3, $t7
    ctx->r14 = ADD32(ctx->r7, ctx->r15);
    // 0x800B28A4: and         $t5, $t4, $v1
    ctx->r13 = ctx->r12 & ctx->r3;
    // 0x800B28A8: bnel        $t5, $zero, L_800B28E0
    if (ctx->r13 != 0) {
        // 0x800B28AC: lw          $a2, 0x1C4($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B28E0;
    }
    goto skip_7;
    // 0x800B28AC: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    skip_7:
    // 0x800B28B0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B28B4: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x800B28B8: bnel        $t8, $zero, L_800B28E0
    if (ctx->r24 != 0) {
        // 0x800B28BC: lw          $a2, 0x1C4($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B28E0;
    }
    goto skip_8;
    // 0x800B28BC: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    skip_8:
    // 0x800B28C0: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B28C4: sw          $t3, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r11;
    // 0x800B28C8: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x800B28CC: nop

    // 0x800B28D0: bc1fl       L_800B28E0
    if (!c1cs) {
        // 0x800B28D4: lw          $a2, 0x1C4($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B28E0;
    }
    goto skip_9;
    // 0x800B28D4: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    skip_9:
    // 0x800B28D8: sw          $zero, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = 0;
    // 0x800B28DC: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
L_800B28E0:
    // 0x800B28E0: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800B28E4: lwc1        $f0, 0x2BC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B28E8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800B28EC: addu        $t4, $a3, $v0
    ctx->r12 = ADD32(ctx->r7, ctx->r2);
    // 0x800B28F0: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800B28F4: lhu         $v1, 0x0($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X0);
    // 0x800B28F8: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x800B28FC: and         $t6, $t5, $v1
    ctx->r14 = ctx->r13 & ctx->r3;
    // 0x800B2900: beql        $t6, $zero, L_800B2B60
    if (ctx->r14 == 0) {
        // 0x800B2904: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800B2B60;
    }
    goto skip_10;
    // 0x800B2904: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_10:
    // 0x800B2908: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800B290C: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x800B2910: bnel        $t9, $zero, L_800B2B60
    if (ctx->r25 != 0) {
        // 0x800B2914: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800B2B60;
    }
    goto skip_11;
    // 0x800B2914: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_11:
    // 0x800B2918: lw          $t4, 0x1C8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B291C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B2920: beql        $t4, $at, L_800B2B60
    if (ctx->r12 == ctx->r1) {
        // 0x800B2924: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800B2B60;
    }
    goto skip_12;
    // 0x800B2924: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_12:
    // 0x800B2928: lw          $t5, 0x2B4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2B4);
    // 0x800B292C: bnel        $t5, $zero, L_800B2B60
    if (ctx->r13 != 0) {
        // 0x800B2930: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800B2B60;
    }
    goto skip_13;
    // 0x800B2930: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_13:
    // 0x800B2934: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800B2938: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B293C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B2940: bc1f        L_800B29B0
    if (!c1cs) {
        // 0x800B2944: nop
    
            goto L_800B29B0;
    }
    // 0x800B2944: nop

    // 0x800B2948: jal         0x800A5FA0
    // 0x800B294C: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    Player_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800B294C: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    after_2:
    // 0x800B2950: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B2954: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B2958: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B295C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B2960: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x800B2964: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    // 0x800B2968: lw          $t4, 0x797C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X797C);
    // 0x800B296C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800B2970: addiu       $a3, $a3, 0x7908
    ctx->r7 = ADD32(ctx->r7, 0X7908);
    // 0x800B2974: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B2978: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x800B297C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800B2980: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800B2984: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2988: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B298C: and         $t6, $t9, $t5
    ctx->r14 = ctx->r25 & ctx->r13;
    // 0x800B2990: beq         $t6, $zero, L_800B29B0
    if (ctx->r14 == 0) {
        // 0x800B2994: nop
    
            goto L_800B29B0;
    }
    // 0x800B2994: nop

    // 0x800B2998: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x800B299C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B29A0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800B29A4: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x800B29A8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B29AC: sw          $t7, 0x7A88($at)
    MEM_W(0X7A88, ctx->r1) = ctx->r15;
L_800B29B0:
    // 0x800B29B0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B29B4: lbu         $t9, 0x7C98($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7C98);
    // 0x800B29B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B29BC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800B29C0: bnel        $t9, $zero, L_800B2A60
    if (ctx->r25 != 0) {
        // 0x800B29C4: lwc1        $f4, 0x2BC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
            goto L_800B2A60;
    }
    goto skip_14;
    // 0x800B29C4: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    skip_14:
    // 0x800B29C8: lwc1        $f0, 0x4C4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C4);
    // 0x800B29CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B29D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B29D4: lwc1        $f10, -0x7678($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x800B29D8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800B29DC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B29E0: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x800B29E4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B29E8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B29EC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B29F0: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800B29F4: swc1        $f18, 0x4C4($s0)
    MEM_W(0X4C4, ctx->r16) = ctx->f18.u32l;
    // 0x800B29F8: jal         0x8009BC2C
    // 0x800B29FC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800B29FC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800B2A00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2A04: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x800B2A08: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B2A0C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B2A10: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B2A14: jal         0x8009BC2C
    // 0x800B2A18: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B2A18: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x800B2A1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2A20: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x800B2A24: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B2A28: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B2A2C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B2A30: jal         0x8009BC2C
    // 0x800B2A34: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B2A34: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800B2A38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2A3C: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x800B2A40: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B2A44: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B2A48: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B2A4C: jal         0x8009BC2C
    // 0x800B2A50: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B2A50: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x800B2A54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2A58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B2A5C: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
L_800B2A60:
    // 0x800B2A60: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B2A64: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B2A68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B2A6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B2A70: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B2A74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2A78: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2A7C: swc1        $f8, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f8.u32l;
    // 0x800B2A80: lwc1        $f10, 0x2BC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B2A84: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x800B2A88: lui         $a1, 0xC3C8
    ctx->r5 = S32(0XC3C8 << 16);
    // 0x800B2A8C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800B2A90: nop

    // 0x800B2A94: bc1f        L_800B2AA4
    if (!c1cs) {
        // 0x800B2A98: nop
    
            goto L_800B2AA4;
    }
    // 0x800B2A98: nop

    // 0x800B2A9C: swc1        $f0, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f0.u32l;
    // 0x800B2AA0: sw          $t3, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r11;
L_800B2AA4:
    // 0x800B2AA4: lwc1        $f0, -0x7674($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7674);
    // 0x800B2AA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2AAC: lwc1        $f18, -0x7670($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7670);
    // 0x800B2AB0: lwc1        $f16, 0x25C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x800B2AB4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B2AB8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B2ABC: swc1        $f4, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f4.u32l;
    // 0x800B2AC0: lwc1        $f6, 0x25C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x800B2AC4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800B2AC8: nop

    // 0x800B2ACC: bc1fl       L_800B2ADC
    if (!c1cs) {
        // 0x800B2AD0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800B2ADC;
    }
    goto skip_15;
    // 0x800B2AD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_15:
    // 0x800B2AD4: swc1        $f0, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f0.u32l;
    // 0x800B2AD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800B2ADC:
    // 0x800B2ADC: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800B2AE0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800B2AE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B2AE8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800B2AEC: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    // 0x800B2AF0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800B2AF4: swc1        $f10, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
    // 0x800B2AF8: lwc1        $f16, 0x110($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800B2AFC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800B2B00: nop

    // 0x800B2B04: bc1f        L_800B2B10
    if (!c1cs) {
        // 0x800B2B08: nop
    
            goto L_800B2B10;
    }
    // 0x800B2B08: nop

    // 0x800B2B0C: swc1        $f12, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f12.u32l;
L_800B2B10:
    // 0x800B2B10: jal         0x8009BC2C
    // 0x800B2B14: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B2B14: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x800B2B18: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B2B1C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B2B20: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2B24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2B28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B2B2C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B2B30: sb          $t5, 0x484($s0)
    MEM_B(0X484, ctx->r16) = ctx->r13;
    // 0x800B2B34: addiu       $t7, $t7, 0x79A8
    ctx->r15 = ADD32(ctx->r15, 0X79A8);
    // 0x800B2B38: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B2B3C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800B2B40: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x800B2B44: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B2B48: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B2B4C: jal         0x8009BC2C
    // 0x800B2B50: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800B2B50: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x800B2B54: b           L_800B2BD0
    // 0x800B2B58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800B2BD0;
    // 0x800B2B58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B2B5C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800B2B60:
    // 0x800B2B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B2B64: bc1fl       L_800B2B94
    if (!c1cs) {
        // 0x800B2B68: lwc1        $f0, 0x110($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
            goto L_800B2B94;
    }
    goto skip_16;
    // 0x800B2B68: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
    skip_16:
    // 0x800B2B6C: sub.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800B2B70: swc1        $f18, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f18.u32l;
    // 0x800B2B74: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B2B78: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x800B2B7C: nop

    // 0x800B2B80: bc1fl       L_800B2B94
    if (!c1cs) {
        // 0x800B2B84: lwc1        $f0, 0x110($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
            goto L_800B2B94;
    }
    goto skip_17;
    // 0x800B2B84: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
    skip_17:
    // 0x800B2B88: swc1        $f2, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f2.u32l;
    // 0x800B2B8C: sw          $zero, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = 0;
    // 0x800B2B90: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
L_800B2B94:
    // 0x800B2B94: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B2B98: nop

    // 0x800B2B9C: bc1fl       L_800B2BD0
    if (!c1cs) {
        // 0x800B2BA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B2BD0;
    }
    goto skip_18;
    // 0x800B2BA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_18:
    // 0x800B2BA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B2BA8: nop

    // 0x800B2BAC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800B2BB0: swc1        $f8, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f8.u32l;
    // 0x800B2BB4: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800B2BB8: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800B2BBC: nop

    // 0x800B2BC0: bc1fl       L_800B2BD0
    if (!c1cs) {
        // 0x800B2BC4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B2BD0;
    }
    goto skip_19;
    // 0x800B2BC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x800B2BC8: swc1        $f2, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f2.u32l;
L_800B2BCC:
    // 0x800B2BCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B2BD0:
    // 0x800B2BD0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B2BD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B2BD8: jr          $ra
    // 0x800B2BDC: nop

    return;
    // 0x800B2BDC: nop

;}
RECOMP_FUNC void HUD_RadioDamage_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B9E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B9EC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008B9F0: addiu       $v1, $v1, 0x178C
    ctx->r3 = ADD32(ctx->r3, 0X178C);
    // 0x8008B9F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B9F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008B9FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008BA00: addiu       $a0, $a0, 0x1788
    ctx->r4 = ADD32(ctx->r4, 0X1788);
    // 0x8008BA04: beq         $v0, $zero, L_8008BA18
    if (ctx->r2 == 0) {
        // 0x8008BA08: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008BA18;
    }
    // 0x8008BA08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BA0C: beq         $v0, $at, L_8008BA18
    if (ctx->r2 == ctx->r1) {
        // 0x8008BA10: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8008BA18;
    }
    // 0x8008BA10: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8008BA14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8008BA18:
    // 0x8008BA18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008BA1C: beq         $v0, $zero, L_8008BA2C
    if (ctx->r2 == 0) {
        // 0x8008BA20: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8008BA2C;
    }
    // 0x8008BA20: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8008BA24: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8008BA28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008BA2C:
    // 0x8008BA2C: bne         $v0, $zero, L_8008BAB0
    if (ctx->r2 != 0) {
        // 0x8008BA30: nop
    
            goto L_8008BAB0;
    }
    // 0x8008BA30: nop

    // 0x8008BA34: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008BA38: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008BA3C: bne         $t8, $zero, L_8008BAB0
    if (ctx->r24 != 0) {
        // 0x8008BA40: nop
    
            goto L_8008BAB0;
    }
    // 0x8008BA40: nop

    // 0x8008BA44: lw          $t9, -0x7D64($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D64);
    // 0x8008BA48: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008BA4C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8008BA50: bnel        $at, $zero, L_8008BAB0
    if (ctx->r1 != 0) {
        // 0x8008BA54: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_8008BAB0;
    }
    goto skip_0;
    // 0x8008BA54: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    skip_0:
    // 0x8008BA58: lw          $v0, -0x7D5C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D5C);
    // 0x8008BA5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008BA60: beq         $v0, $at, L_8008BAAC
    if (ctx->r2 == ctx->r1) {
        // 0x8008BA64: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008BAAC;
    }
    // 0x8008BA64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008BA68: beql        $v0, $at, L_8008BAB0
    if (ctx->r2 == ctx->r1) {
        // 0x8008BA6C: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_8008BAB0;
    }
    goto skip_1;
    // 0x8008BA6C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    skip_1:
    // 0x8008BA70: jal         0x8008B774
    // 0x8008BA74: nop

    HUD_RadioDamage_Type(rdram, ctx);
        goto after_0;
    // 0x8008BA74: nop

    after_0:
    // 0x8008BA78: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008BA7C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008BA80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BA84: addiu       $a0, $a0, 0x1788
    ctx->r4 = ADD32(ctx->r4, 0X1788);
    // 0x8008BA88: bne         $v0, $at, L_8008BA98
    if (ctx->r2 != ctx->r1) {
        // 0x8008BA8C: addiu       $v1, $v1, 0x178C
        ctx->r3 = ADD32(ctx->r3, 0X178C);
            goto L_8008BA98;
    }
    // 0x8008BA8C: addiu       $v1, $v1, 0x178C
    ctx->r3 = ADD32(ctx->r3, 0X178C);
    // 0x8008BA90: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8008BA94: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8008BA98:
    // 0x8008BA98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008BA9C: bne         $v0, $at, L_8008BAB0
    if (ctx->r2 != ctx->r1) {
        // 0x8008BAA0: addiu       $t1, $zero, 0x3C
        ctx->r9 = ADD32(0, 0X3C);
            goto L_8008BAB0;
    }
    // 0x8008BAA0: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x8008BAA4: b           L_8008BAB0
    // 0x8008BAA8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_8008BAB0;
    // 0x8008BAA8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8008BAAC:
    // 0x8008BAAC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008BAB0:
    // 0x8008BAB0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008BAB4: lw          $v0, -0x7D5C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D5C);
    // 0x8008BAB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008BABC: beq         $v0, $at, L_8008BACC
    if (ctx->r2 == ctx->r1) {
        // 0x8008BAC0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008BACC;
    }
    // 0x8008BAC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008BAC4: bnel        $v0, $at, L_8008BAD8
    if (ctx->r2 != ctx->r1) {
        // 0x8008BAC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008BAD8;
    }
    goto skip_2;
    // 0x8008BAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_8008BACC:
    // 0x8008BACC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8008BAD0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008BAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008BAD8:
    // 0x8008BAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BADC: jr          $ra
    // 0x8008BAE0: nop

    return;
    // 0x8008BAE0: nop

;}
RECOMP_FUNC void Object_Kill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060FC4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80060FC8: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80060FCC: jal         0x8001A500
    // 0x80060FD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Audio_KillSfxBySource(rdram, ctx);
        goto after_0;
    // 0x80060FD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80060FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060FDC: jr          $ra
    // 0x80060FE0: nop

    return;
    // 0x80060FE0: nop

;}
RECOMP_FUNC void Display_UnusedShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054CA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80054CA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80054CAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80054CB0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80054CB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80054CB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80054CBC: lw          $t7, 0x1C4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C4);
    // 0x80054CC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80054CC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054CC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80054CCC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80054CD0: lwc1        $f6, 0x7AB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7AB8);
    // 0x80054CD4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80054CD8: nop

    // 0x80054CDC: bc1fl       L_80054E74
    if (!c1cs) {
        // 0x80054CE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80054E74;
    }
    goto skip_0;
    // 0x80054CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80054CE4: jal         0x80005708
    // 0x80054CE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80054CE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80054CEC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80054CF0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80054CF4: addiu       $t4, $t4, 0x1418
    ctx->r12 = ADD32(ctx->r12, 0X1418);
    // 0x80054CF8: lw          $t2, 0x1C4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1C4);
    // 0x80054CFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054D00: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80054D04: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80054D08: jal         0x80005680
    // 0x80054D0C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    Matrix_Copy(rdram, ctx);
        goto after_1;
    // 0x80054D0C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x80054D10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054D14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80054D18: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80054D1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80054D20: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80054D24: lui         $a2, 0xC0A0
    ctx->r6 = S32(0XC0A0 << 16);
    // 0x80054D28: jal         0x80005B00
    // 0x80054D2C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80054D2C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_2:
    // 0x80054D30: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80054D34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054D38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054D3C: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x80054D40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80054D44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80054D48: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80054D4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80054D50: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80054D54: jal         0x80005C34
    // 0x80054D58: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80054D58: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x80054D5C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80054D60: jal         0x80006EB8
    // 0x80054D64: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80054D64: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    after_4:
    // 0x80054D68: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80054D6C: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    // 0x80054D70: jal         0x800B8DD0
    // 0x80054D74: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x80054D74: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_5:
    // 0x80054D78: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80054D7C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80054D80: addiu       $t1, $t1, 0x7AB8
    ctx->r9 = ADD32(ctx->r9, 0X7AB8);
    // 0x80054D84: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80054D88: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80054D8C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80054D90: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80054D94: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80054D98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80054D9C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80054DA0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80054DA4: lw          $t9, 0x1C4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X1C4);
    // 0x80054DA8: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80054DAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80054DB0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80054DB4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80054DB8: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80054DBC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80054DC0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80054DC4: nop

    // 0x80054DC8: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80054DCC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80054DD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80054DD4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80054DD8: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80054DDC: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80054DE0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054DE4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80054DE8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054DEC: lw          $t2, 0x1C4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1C4);
    // 0x80054DF0: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80054DF4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80054DF8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80054DFC: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80054E00: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80054E04: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80054E08: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80054E0C: nop

    // 0x80054E10: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80054E14: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80054E18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80054E1C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80054E20: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x80054E24: addiu       $t3, $t3, -0x3290
    ctx->r11 = ADD32(ctx->r11, -0X3290);
    // 0x80054E28: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80054E2C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80054E30: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80054E34: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80054E38: jal         0x80005740
    // 0x80054E3C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x80054E3C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x80054E40: lui         $a0, 0x102
    ctx->r4 = S32(0X102 << 16);
    // 0x80054E44: addiu       $a0, $a0, -0x2F90
    ctx->r4 = ADD32(ctx->r4, -0X2F90);
    // 0x80054E48: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80054E4C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80054E50: jal         0x80099A2C
    // 0x80054E54: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_7;
    // 0x80054E54: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x80054E58: lui         $a0, 0x102
    ctx->r4 = S32(0X102 << 16);
    // 0x80054E5C: addiu       $a0, $a0, -0x2F90
    ctx->r4 = ADD32(ctx->r4, -0X2F90);
    // 0x80054E60: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80054E64: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80054E68: jal         0x80099A2C
    // 0x80054E6C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_8;
    // 0x80054E6C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80054E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80054E74:
    // 0x80054E74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80054E78: jr          $ra
    // 0x80054E7C: nop

    return;
    // 0x80054E7C: nop

;}
RECOMP_FUNC void Player_UseTankJets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADD98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ADD9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800ADDA0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800ADDA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800ADDA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ADDAC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800ADDB0: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x800ADDB4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800ADDB8: addiu       $a0, $s0, 0x170
    ctx->r4 = ADD32(ctx->r16, 0X170);
    // 0x800ADDBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800ADDC0: jal         0x8009BC2C
    // 0x800ADDC4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800ADDC4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800ADDC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800ADDCC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x800ADDD0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800ADDD4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800ADDD8: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x800ADDDC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800ADDE0: jal         0x8009BC2C
    // 0x800ADDE4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800ADDE4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800ADDE8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800ADDEC: lw          $t6, 0x797C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X797C);
    // 0x800ADDF0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800ADDF4: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x800ADDF8: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x800ADDFC: beql        $t7, $zero, L_800ADE80
    if (ctx->r15 == 0) {
        // 0x800ADE00: andi        $t4, $v0, 0x10
        ctx->r12 = ctx->r2 & 0X10;
            goto L_800ADE80;
    }
    goto skip_0;
    // 0x800ADE00: andi        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 & 0X10;
    skip_0:
    // 0x800ADE04: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x800ADE08: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800ADE0C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800ADE10: beql        $t8, $zero, L_800ADE74
    if (ctx->r24 == 0) {
        // 0x800ADE14: sw          $t2, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r10;
            goto L_800ADE74;
    }
    goto skip_1;
    // 0x800ADE14: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
    skip_1:
    // 0x800ADE18: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800ADE1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800ADE20: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800ADE24: nop

    // 0x800ADE28: bc1fl       L_800ADE74
    if (!c1cs) {
        // 0x800ADE2C: sw          $t2, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r10;
            goto L_800ADE74;
    }
    goto skip_2;
    // 0x800ADE2C: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
    skip_2:
    // 0x800ADE30: lwc1        $f6, 0x2BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800ADE34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800ADE38: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x800ADE3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ADE40: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800ADE44: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x800ADE48: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800ADE4C: bc1fl       L_800ADE74
    if (!c1cs) {
        // 0x800ADE50: sw          $t2, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r10;
            goto L_800ADE74;
    }
    goto skip_3;
    // 0x800ADE50: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
    skip_3:
    // 0x800ADE54: sw          $t9, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r25;
    // 0x800ADE58: sw          $t0, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r8;
    // 0x800ADE5C: sw          $v1, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r3;
    // 0x800ADE60: sw          $v1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r3;
    // 0x800ADE64: lw          $t1, 0x797C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X797C);
    // 0x800ADE68: b           L_800ADE7C
    // 0x800ADE6C: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
        goto L_800ADE7C;
    // 0x800ADE6C: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    // 0x800ADE70: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
L_800ADE74:
    // 0x800ADE74: lw          $t3, 0x797C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X797C);
    // 0x800ADE78: lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X0);
L_800ADE7C:
    // 0x800ADE7C: andi        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 & 0X10;
L_800ADE80:
    // 0x800ADE80: beq         $t4, $zero, L_800ADEE8
    if (ctx->r12 == 0) {
        // 0x800ADE84: nop
    
            goto L_800ADEE8;
    }
    // 0x800ADE84: nop

    // 0x800ADE88: lw          $t5, 0x1E4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1E4);
    // 0x800ADE8C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800ADE90: beql        $t5, $zero, L_800ADEE8
    if (ctx->r13 == 0) {
        // 0x800ADE94: sw          $t8, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r24;
            goto L_800ADEE8;
    }
    goto skip_4;
    // 0x800ADE94: sw          $t8, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r24;
    skip_4:
    // 0x800ADE98: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800ADE9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800ADEA0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800ADEA4: nop

    // 0x800ADEA8: bc1fl       L_800ADEE8
    if (!c1cs) {
        // 0x800ADEAC: sw          $t8, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r24;
            goto L_800ADEE8;
    }
    goto skip_5;
    // 0x800ADEAC: sw          $t8, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r24;
    skip_5:
    // 0x800ADEB0: lwc1        $f16, 0x2BC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800ADEB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ADEB8: addiu       $v0, $zero, -0x14
    ctx->r2 = ADD32(0, -0X14);
    // 0x800ADEBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800ADEC0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800ADEC4: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800ADEC8: bc1fl       L_800ADEE8
    if (!c1cs) {
        // 0x800ADECC: sw          $t8, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r24;
            goto L_800ADEE8;
    }
    goto skip_6;
    // 0x800ADECC: sw          $t8, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r24;
    skip_6:
    // 0x800ADED0: sw          $t6, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r14;
    // 0x800ADED4: sw          $t7, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r15;
    // 0x800ADED8: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    // 0x800ADEDC: b           L_800ADEE8
    // 0x800ADEE0: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
        goto L_800ADEE8;
    // 0x800ADEE0: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
    // 0x800ADEE4: sw          $t8, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r24;
L_800ADEE8:
    // 0x800ADEE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADEEC: lwc1        $f6, -0x79B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X79B0);
    // 0x800ADEF0: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800ADEF4: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ADEF8: jal         0x80023090
    // 0x800ADEFC: nop

    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800ADEFC: nop

    after_2:
    // 0x800ADF00: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800ADF04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800ADF08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADF0C: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800ADF10: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800ADF14: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800ADF18: swc1        $f0, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f0.u32l;
    // 0x800ADF1C: lwc1        $f16, -0x79AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X79AC);
    // 0x800ADF20: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800ADF24: jal         0x80023090
    // 0x800ADF28: nop

    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800ADF28: nop

    after_3:
    // 0x800ADF2C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800ADF30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ADF34: lwc1        $f4, 0x18C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x800ADF38: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800ADF3C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800ADF40: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800ADF44: swc1        $f6, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f6.u32l;
    // 0x800ADF48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800ADF4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ADF50: jr          $ra
    // 0x800ADF54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ADF54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Lib_QuickSort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80002F8C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002F90: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002F94: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80002F98: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002F9C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80002FA0: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80002FA4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80002FA8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80002FAC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80002FB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002FB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002FB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80002FBC:
    // 0x80002FBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002FC0: bne         $s5, $at, L_80003000
    if (ctx->r21 != ctx->r1) {
        // 0x80002FC4: or          $s1, $s6, $zero
        ctx->r17 = ctx->r22 | 0;
            goto L_80003000;
    }
    // 0x80002FC4: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x80002FC8: addiu       $t6, $s5, -0x1
    ctx->r14 = ADD32(ctx->r21, -0X1);
    // 0x80002FCC: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002FD0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80002FD4: mflo        $t7
    ctx->r15 = lo;
    // 0x80002FD8: addu        $s2, $t7, $s6
    ctx->r18 = ADD32(ctx->r15, ctx->r22);
    // 0x80002FDC: jalr        $s4
    // 0x80002FE0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x80002FE0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80002FE4: blez        $v0, L_80003144
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80002FE8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80003144;
    }
    // 0x80002FE8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80002FEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80002FF0: jal         0x80002EE4
    // 0x80002FF4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    Lib_SwapBuffers(rdram, ctx);
        goto after_1;
    // 0x80002FF4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x80002FF8: b           L_80003148
    // 0x80002FFC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80003148;
    // 0x80002FFC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80003000:
    // 0x80003000: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x80003004: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003008: mflo        $t9
    ctx->r25 = lo;
    // 0x8000300C: addu        $s2, $t9, $s6
    ctx->r18 = ADD32(ctx->r25, ctx->r22);
    // 0x80003010: subu        $s0, $s2, $s3
    ctx->r16 = SUB32(ctx->r18, ctx->r19);
L_80003014:
    // 0x80003014: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80003018: jalr        $s4
    // 0x8000301C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_2;
    // 0x8000301C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80003020: bgezl       $v0, L_80003044
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80003024: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80003044;
    }
    goto skip_0;
    // 0x80003024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80003028: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
L_8000302C:
    // 0x8000302C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80003030: jalr        $s4
    // 0x80003034: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_3;
    // 0x80003034: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80003038: bltzl       $v0, L_8000302C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000303C: addu        $s1, $s1, $s3
        ctx->r17 = ADD32(ctx->r17, ctx->r19);
            goto L_8000302C;
    }
    goto skip_1;
    // 0x8000303C: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
    skip_1:
    // 0x80003040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80003044:
    // 0x80003044: jalr        $s4
    // 0x80003048: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_4;
    // 0x80003048: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x8000304C: bltz        $v0, L_8000307C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80003050: sltu        $at, $s1, $s0
        ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
            goto L_8000307C;
    }
    // 0x80003050: sltu        $at, $s1, $s0
    ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
    // 0x80003054: beql        $at, $zero, L_80003080
    if (ctx->r1 == 0) {
        // 0x80003058: sltu        $at, $s1, $s0
        ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
            goto L_80003080;
    }
    goto skip_2;
    // 0x80003058: sltu        $at, $s1, $s0
    ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
    skip_2:
    // 0x8000305C: subu        $s0, $s0, $s3
    ctx->r16 = SUB32(ctx->r16, ctx->r19);
L_80003060:
    // 0x80003060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003064: jalr        $s4
    // 0x80003068: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x80003068: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8000306C: bltz        $v0, L_8000307C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80003070: sltu        $at, $s1, $s0
        ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
            goto L_8000307C;
    }
    // 0x80003070: sltu        $at, $s1, $s0
    ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
    // 0x80003074: bnel        $at, $zero, L_80003060
    if (ctx->r1 != 0) {
        // 0x80003078: subu        $s0, $s0, $s3
        ctx->r16 = SUB32(ctx->r16, ctx->r19);
            goto L_80003060;
    }
    goto skip_3;
    // 0x80003078: subu        $s0, $s0, $s3
    ctx->r16 = SUB32(ctx->r16, ctx->r19);
    skip_3:
L_8000307C:
    // 0x8000307C: sltu        $at, $s1, $s0
    ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
L_80003080:
    // 0x80003080: beq         $at, $zero, L_800030A0
    if (ctx->r1 == 0) {
        // 0x80003084: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800030A0;
    }
    // 0x80003084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80003088: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000308C: jal         0x80002EE4
    // 0x80003090: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    Lib_SwapBuffers(rdram, ctx);
        goto after_6;
    // 0x80003090: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_6:
    // 0x80003094: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
    // 0x80003098: b           L_80003014
    // 0x8000309C: subu        $s0, $s0, $s3
    ctx->r16 = SUB32(ctx->r16, ctx->r19);
        goto L_80003014;
    // 0x8000309C: subu        $s0, $s0, $s3
    ctx->r16 = SUB32(ctx->r16, ctx->r19);
L_800030A0:
    // 0x800030A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800030A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800030A8: jal         0x80002EE4
    // 0x800030AC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    Lib_SwapBuffers(rdram, ctx);
        goto after_7;
    // 0x800030AC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_7:
    // 0x800030B0: subu        $t0, $s1, $s6
    ctx->r8 = SUB32(ctx->r17, ctx->r22);
    // 0x800030B4: divu        $zero, $t0, $s3
    lo = S32(U32(ctx->r8) / U32(ctx->r19)); hi = S32(U32(ctx->r8) % U32(ctx->r19));
    // 0x800030B8: mflo        $s0
    ctx->r16 = lo;
    // 0x800030BC: srl         $t1, $s5, 1
    ctx->r9 = S32(U32(ctx->r21) >> 1);
    // 0x800030C0: bne         $s3, $zero, L_800030CC
    if (ctx->r19 != 0) {
        // 0x800030C4: nop
    
            goto L_800030CC;
    }
    // 0x800030C4: nop

    // 0x800030C8: break       7
    do_break(2147496136);
L_800030CC:
    // 0x800030CC: sltu        $at, $t1, $s0
    ctx->r1 = ctx->r9 < ctx->r16 ? 1 : 0;
    // 0x800030D0: beq         $at, $zero, L_8000310C
    if (ctx->r1 == 0) {
        // 0x800030D4: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_8000310C;
    }
    // 0x800030D4: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x800030D8: subu        $v0, $s5, $s0
    ctx->r2 = SUB32(ctx->r21, ctx->r16);
    // 0x800030DC: sltiu       $at, $v0, 0x3
    ctx->r1 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x800030E0: bne         $at, $zero, L_800030F8
    if (ctx->r1 != 0) {
        // 0x800030E4: addu        $a0, $s1, $s3
        ctx->r4 = ADD32(ctx->r17, ctx->r19);
            goto L_800030F8;
    }
    // 0x800030E4: addu        $a0, $s1, $s3
    ctx->r4 = ADD32(ctx->r17, ctx->r19);
    // 0x800030E8: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x800030EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800030F0: jal         0x80002F88
    // 0x800030F4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    Lib_QuickSort(rdram, ctx);
        goto after_8;
    // 0x800030F4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_8:
L_800030F8:
    // 0x800030F8: sltiu       $at, $s0, 0x2
    ctx->r1 = ctx->r16 < 0X2 ? 1 : 0;
    // 0x800030FC: bnel        $at, $zero, L_80003148
    if (ctx->r1 != 0) {
        // 0x80003100: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80003148;
    }
    goto skip_4;
    // 0x80003100: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x80003104: b           L_80002FBC
    // 0x80003108: or          $s5, $s2, $zero
    ctx->r21 = ctx->r18 | 0;
        goto L_80002FBC;
    // 0x80003108: or          $s5, $s2, $zero
    ctx->r21 = ctx->r18 | 0;
L_8000310C:
    // 0x8000310C: sltiu       $at, $s0, 0x2
    ctx->r1 = ctx->r16 < 0X2 ? 1 : 0;
    // 0x80003110: bne         $at, $zero, L_80003128
    if (ctx->r1 != 0) {
        // 0x80003114: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80003128;
    }
    // 0x80003114: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80003118: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000311C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80003120: jal         0x80002F88
    // 0x80003124: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    Lib_QuickSort(rdram, ctx);
        goto after_9;
    // 0x80003124: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_9:
L_80003128:
    // 0x80003128: subu        $t2, $s5, $s0
    ctx->r10 = SUB32(ctx->r21, ctx->r16);
    // 0x8000312C: sltiu       $at, $t2, 0x3
    ctx->r1 = ctx->r10 < 0X3 ? 1 : 0;
    // 0x80003130: bne         $at, $zero, L_80003144
    if (ctx->r1 != 0) {
        // 0x80003134: addu        $s6, $s1, $s3
        ctx->r22 = ADD32(ctx->r17, ctx->r19);
            goto L_80003144;
    }
    // 0x80003134: addu        $s6, $s1, $s3
    ctx->r22 = ADD32(ctx->r17, ctx->r19);
    // 0x80003138: subu        $s5, $s5, $s2
    ctx->r21 = SUB32(ctx->r21, ctx->r18);
    // 0x8000313C: b           L_80002FBC
    // 0x80003140: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80002FBC;
    // 0x80003140: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80003144:
    // 0x80003144: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80003148:
    // 0x80003148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000314C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003150: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003154: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80003158: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000315C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80003160: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80003164: jr          $ra
    // 0x80003168: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80003168: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Aquas_Camera_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095358: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8009535C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80095360: jal         0x800613C4
    // 0x80095364: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80095364: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80095368: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8009536C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80095370: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x80095374: addiu       $t8, $zero, 0x270F
    ctx->r24 = ADD32(0, 0X270F);
    // 0x80095378: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8009537C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80095380: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80095384: sh          $t8, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r24;
    // 0x80095388: jal         0x800612B8
    // 0x8009538C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8009538C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x80095390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095398: jr          $ra
    // 0x8009539C: nop

    return;
    // 0x8009539C: nop

;}
RECOMP_FUNC void HUD_VsModePortrait_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D250: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008D254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D258: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008D25C: addiu       $t7, $t7, 0x20C8
    ctx->r15 = ADD32(ctx->r15, 0X20C8);
    // 0x8008D260: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008D264: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8008D268: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8008D26C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8008D270: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8008D274: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8008D278: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8008D27C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008D280: addiu       $t2, $t2, 0x20D8
    ctx->r10 = ADD32(ctx->r10, 0X20D8);
    // 0x8008D284: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8008D288: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8008D28C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8008D290: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8008D294: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x8008D298: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8008D29C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8008D2A0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8008D2A4: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8008D2A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008D2AC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008D2B0: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008D2B4: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8008D2B8: jal         0x800B8DD0
    // 0x8008D2BC: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008D2BC: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    after_0:
    // 0x8008D2C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8008D2C4: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8008D2C8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008D2CC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8008D2D0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8008D2D4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8008D2D8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8008D2DC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8008D2E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008D2E4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8008D2E8: lw          $a3, 0x78A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X78A0);
    // 0x8008D2EC: lui         $a2, 0x3F0A
    ctx->r6 = S32(0X3F0A << 16);
    // 0x8008D2F0: ori         $a2, $a2, 0x3D71
    ctx->r6 = ctx->r6 | 0X3D71;
    // 0x8008D2F4: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x8008D2F8: addu        $t7, $sp, $a0
    ctx->r15 = ADD32(ctx->r29, ctx->r4);
    // 0x8008D2FC: addu        $t0, $sp, $a0
    ctx->r8 = ADD32(ctx->r29, ctx->r4);
    // 0x8008D300: lwc1        $f14, 0x28($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8008D304: jal         0x8008C5C8
    // 0x8008D308: lwc1        $f12, 0x38($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X38);
    HUD_VsModePortraitTex_Draw(rdram, ctx);
        goto after_1;
    // 0x8008D308: lwc1        $f12, 0x38($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X38);
    after_1:
    // 0x8008D30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D310: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008D314: jr          $ra
    // 0x8008D318: nop

    return;
    // 0x8008D318: nop

;}
RECOMP_FUNC void ActorEvent_80070BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070BA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80070BAC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80070BB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80070BB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80070BB8: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x80070BBC: beql        $t6, $zero, L_80070CDC
    if (ctx->r14 == 0) {
        // 0x80070BC0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80070CDC;
    }
    goto skip_0;
    // 0x80070BC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80070BC4: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80070BC8: addiu       $v1, $zero, 0x11
    ctx->r3 = ADD32(0, 0X11);
    // 0x80070BCC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80070BD0: bne         $v1, $v0, L_80070BEC
    if (ctx->r3 != ctx->r2) {
        // 0x80070BD4: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_80070BEC;
    }
    // 0x80070BD4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80070BD8: bne         $v1, $v0, L_80070CB0
    if (ctx->r3 != ctx->r2) {
        // 0x80070BDC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80070CB0;
    }
    // 0x80070BDC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80070BE0: lh          $t7, 0xD2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XD2);
    // 0x80070BE4: bne         $t7, $zero, L_80070CB0
    if (ctx->r15 != 0) {
        // 0x80070BE8: nop
    
            goto L_80070CB0;
    }
    // 0x80070BE8: nop

L_80070BEC:
    // 0x80070BEC: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80070BF0: sh          $t8, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r24;
    // 0x80070BF4: lwc1        $f12, 0xD8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x80070BF8: lwc1        $f14, 0xDC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80070BFC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    // 0x80070C00: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x80070C04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070C08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80070C0C: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80070C10: lwc1        $f8, 0x6C4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C4C);
    // 0x80070C14: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80070C18: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80070C1C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80070C20: jal         0x8007C120
    // 0x80070C24: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_0;
    // 0x80070C24: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80070C28: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
    // 0x80070C2C: lhu         $t1, 0xD6($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XD6);
    // 0x80070C30: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80070C34: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80070C38: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80070C3C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80070C40: sh          $t2, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r10;
    // 0x80070C44: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80070C48: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80070C4C: ori         $a0, $a0, 0x3064
    ctx->r4 = ctx->r4 | 0X3064;
    // 0x80070C50: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80070C54: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80070C58: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80070C5C: jal         0x80019218
    // 0x80070C60: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80070C60: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80070C64: lh          $t4, 0xCE($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XCE);
    // 0x80070C68: bgtzl       $t4, L_80070CDC
    if (SIGNED(ctx->r12) > 0) {
        // 0x80070C6C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80070CDC;
    }
    goto skip_1;
    // 0x80070C6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80070C70: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070C74: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80070C78: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80070C7C: jal         0x80077240
    // 0x80070C80: lbu         $a3, 0x3C($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3C);
    BonusText_Display(rdram, ctx);
        goto after_2;
    // 0x80070C80: lbu         $a3, 0x3C($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3C);
    after_2:
    // 0x80070C84: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80070C88: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x80070C8C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80070C90: lbu         $t6, 0x3C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3C);
    // 0x80070C94: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80070C98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80070C9C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80070CA0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80070CA4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80070CA8: b           L_80070CD8
    // 0x80070CAC: sw          $t9, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r25;
        goto L_80070CD8;
    // 0x80070CAC: sw          $t9, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r25;
L_80070CB0:
    // 0x80070CB0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80070CB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80070CB8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80070CBC: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x80070CC0: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x80070CC4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80070CC8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80070CCC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80070CD0: jal         0x80019218
    // 0x80070CD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x80070CD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
L_80070CD8:
    // 0x80070CD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80070CDC:
    // 0x80070CDC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80070CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80070CE4: jr          $ra
    // 0x80070CE8: nop

    return;
    // 0x80070CE8: nop

;}
RECOMP_FUNC void Audio_SetUnkVoiceParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF40: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AF44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001AF48: jr          $ra
    // 0x8001AF4C: sb          $a0, 0x7390($at)
    MEM_B(0X7390, ctx->r1) = ctx->r4;
    return;
    // 0x8001AF4C: sb          $a0, 0x7390($at)
    MEM_B(0X7390, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void Camera_Update360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B718C: lw          $v0, 0x1CC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1CC);
    // 0x800B7190: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7194: beq         $v0, $zero, L_800B71CC
    if (ctx->r2 == 0) {
        // 0x800B7198: nop
    
            goto L_800B71CC;
    }
    // 0x800B7198: nop

    // 0x800B719C: beq         $v0, $at, L_800B71BC
    if (ctx->r2 == ctx->r1) {
        // 0x800B71A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B71BC;
    }
    // 0x800B71A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B71A4: bnel        $v0, $at, L_800B71D8
    if (ctx->r2 != ctx->r1) {
        // 0x800B71A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B71D8;
    }
    goto skip_0;
    // 0x800B71A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B71AC: jal         0x800B6BFC
    // 0x800B71B0: nop

    Camera_UpdateOnFoot360(rdram, ctx);
        goto after_0;
    // 0x800B71B0: nop

    after_0:
    // 0x800B71B4: b           L_800B71D8
    // 0x800B71B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B71D8;
    // 0x800B71B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B71BC:
    // 0x800B71BC: jal         0x800B6848
    // 0x800B71C0: nop

    Camera_UpdateTank360(rdram, ctx);
        goto after_1;
    // 0x800B71C0: nop

    after_1:
    // 0x800B71C4: b           L_800B71D8
    // 0x800B71C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B71D8;
    // 0x800B71C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B71CC:
    // 0x800B71CC: jal         0x800B63BC
    // 0x800B71D0: nop

    Camera_UpdateArwing360(rdram, ctx);
        goto after_2;
    // 0x800B71D0: nop

    after_2:
    // 0x800B71D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B71D8:
    // 0x800B71D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B71DC: jr          $ra
    // 0x800B71E0: nop

    return;
    // 0x800B71E0: nop

;}
RECOMP_FUNC void HUD_GetLevelIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800863CC: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800863D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800863D4: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x800863D8: beq         $at, $zero, L_80086438
    if (ctx->r1 == 0) {
        // 0x800863DC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80086438;
    }
    // 0x800863DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800863E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800863E4: addu        $at, $at, $t6
    gpr jr_addend_800863EC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800863E8: lw          $t6, 0x77CC($at)
    ctx->r14 = ADD32(ctx->r1, 0X77CC);
    // 0x800863EC: jr          $t6
    // 0x800863F0: nop

    switch (jr_addend_800863EC >> 2) {
        case 0: goto L_80086438; break;
        case 1: goto L_80086434; break;
        case 2: goto L_80086420; break;
        case 3: goto L_80086404; break;
        case 4: goto L_80086438; break;
        case 5: goto L_80086430; break;
        case 6: goto L_80086400; break;
        case 7: goto L_8008641C; break;
        case 8: goto L_80086418; break;
        case 9: goto L_800863F8; break;
        case 10: goto L_800863F4; break;
        case 11: goto L_80086410; break;
        case 12: goto L_80086414; break;
        case 13: goto L_80086424; break;
        case 14: goto L_8008642C; break;
        case 15: goto L_80086438; break;
        case 16: goto L_80086428; break;
        case 17: goto L_80086408; break;
        case 18: goto L_8008640C; break;
        case 19: goto L_800863FC; break;
        default: switch_error(__func__, 0x800863EC, 0x800D77CC);
    }
    // 0x800863F0: nop

L_800863F4:
    // 0x800863F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800863F8:
    // 0x800863F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800863FC:
    // 0x800863FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086400:
    // 0x80086400: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086404:
    // 0x80086404: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086408:
    // 0x80086408: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008640C:
    // 0x8008640C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086410:
    // 0x80086410: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086414:
    // 0x80086414: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086418:
    // 0x80086418: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008641C:
    // 0x8008641C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086420:
    // 0x80086420: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086424:
    // 0x80086424: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086428:
    // 0x80086428: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008642C:
    // 0x8008642C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086430:
    // 0x80086430: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086434:
    // 0x80086434: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80086438:
    // 0x80086438: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008643C: jr          $ra
    // 0x80086440: nop

    return;
    // 0x80086440: nop

;}
RECOMP_FUNC void AudioSynth_SyncSampleStates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009AAC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80009AB0: addiu       $t0, $t0, 0x5CA0
    ctx->r8 = ADD32(ctx->r8, 0X5CA0);
    // 0x80009AB4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80009AB8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80009ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009AC0: blez        $v1, L_80009B5C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009AC4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80009B5C;
    }
    // 0x80009AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009AC8: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80009ACC: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80009AD0: addiu       $t1, $t1, -0x1AD0
    ctx->r9 = ADD32(ctx->r9, -0X1AD0);
    // 0x80009AD4: addiu       $t2, $t2, -0x3E48
    ctx->r10 = ADD32(ctx->r10, -0X3E48);
L_80009AD8:
    // 0x80009AD8: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009ADC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80009AE0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80009AE4: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80009AE8: lw          $t4, 0xB0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XB0);
    // 0x80009AEC: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    // 0x80009AF0: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x80009AF4: mflo        $t7
    ctx->r15 = lo;
    // 0x80009AF8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80009AFC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80009B00: beq         $t5, $zero, L_80009B38
    if (ctx->r13 == 0) {
        // 0x80009B04: addu        $a2, $t9, $t3
        ctx->r6 = ADD32(ctx->r25, ctx->r11);
            goto L_80009B38;
    }
    // 0x80009B04: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x80009B08: lw          $at, 0x0($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X0);
    // 0x80009B0C: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x80009B10: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80009B14: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80009B18: lw          $at, 0x8($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X8);
    // 0x80009B1C: sw          $at, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r1;
    // 0x80009B20: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80009B24: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x80009B28: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80009B2C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80009B30: b           L_80009B44
    // 0x80009B34: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
        goto L_80009B44;
    // 0x80009B34: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_80009B38:
    // 0x80009B38: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x80009B3C: andi        $t4, $t3, 0xFF7F
    ctx->r12 = ctx->r11 & 0XFF7F;
    // 0x80009B40: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
L_80009B44:
    // 0x80009B44: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80009B48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009B4C: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x80009B50: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009B54: bne         $at, $zero, L_80009AD8
    if (ctx->r1 != 0) {
        // 0x80009B58: nop
    
            goto L_80009AD8;
    }
    // 0x80009B58: nop

L_80009B5C:
    // 0x80009B5C: jr          $ra
    // 0x80009B60: nop

    return;
    // 0x80009B60: nop

;}
RECOMP_FUNC void AudioHeap_InitMainPools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BFE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BFEC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000BFF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BFF4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000BFF8: lui         $a1, 0x802D
    ctx->r5 = S32(0X802D << 16);
    // 0x8000BFFC: addiu       $a1, $a1, 0x7800
    ctx->r5 = ADD32(ctx->r5, 0X7800);
    // 0x8000C000: addiu       $a0, $a0, -0x3E30
    ctx->r4 = ADD32(ctx->r4, -0X3E30);
    // 0x8000C004: jal         0x8000BF6C
    // 0x8000C008: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    AudioHeap_InitPool(rdram, ctx);
        goto after_0;
    // 0x8000C008: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000C00C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000C010: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8000C014: lw          $t7, 0x7C30($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7C30);
    // 0x8000C018: lui         $t6, 0x802D
    ctx->r14 = S32(0X802D << 16);
    // 0x8000C01C: addiu       $t6, $t6, 0x7800
    ctx->r14 = ADD32(ctx->r14, 0X7800);
    // 0x8000C020: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C024: addiu       $a0, $a0, -0x3E40
    ctx->r4 = ADD32(ctx->r4, -0X3E40);
    // 0x8000C028: addu        $a1, $a3, $t6
    ctx->r5 = ADD32(ctx->r7, ctx->r14);
    // 0x8000C02C: jal         0x8000BF6C
    // 0x8000C030: subu        $a2, $t7, $a3
    ctx->r6 = SUB32(ctx->r15, ctx->r7);
    AudioHeap_InitPool(rdram, ctx);
        goto after_1;
    // 0x8000C030: subu        $a2, $t7, $a3
    ctx->r6 = SUB32(ctx->r15, ctx->r7);
    after_1:
    // 0x8000C034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C03C: jr          $ra
    // 0x8000C040: nop

    return;
    // 0x8000C040: nop

;}
RECOMP_FUNC void RCP_SetupDL_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA110: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA114: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA118: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA11C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA120: addiu       $t8, $t8, 0x3D38
    ctx->r24 = ADD32(ctx->r24, 0X3D38);
    // 0x800BA124: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA128: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA12C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA130: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA134: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA138: jr          $ra
    // 0x800BA13C: nop

    return;
    // 0x800BA13C: nop

;}
RECOMP_FUNC void Graphics_DisplayLargeText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0094: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800A0098: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A009C: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800A00A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A00A4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800A00A8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800A00AC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800A00B0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800A00B4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800A00B8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800A00BC: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800A00C0: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800A00C4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A00C8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800A00CC: beq         $v1, $zero, L_800A06D8
    if (ctx->r3 == 0) {
        // 0x800A00D0: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800A06D8;
    }
    // 0x800A00D0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A00D4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800A00D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A00DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A00E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A00E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A00E8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800A00EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A00F0: addiu       $t4, $t4, 0x268C
    ctx->r12 = ADD32(ctx->r12, 0X268C);
    // 0x800A00F4: addiu       $s4, $zero, 0x49
    ctx->r20 = ADD32(0, 0X49);
    // 0x800A00F8: addiu       $s3, $zero, 0x59
    ctx->r19 = ADD32(0, 0X59);
    // 0x800A00FC: addiu       $s2, $zero, 0x58
    ctx->r18 = ADD32(0, 0X58);
    // 0x800A0100: addiu       $s1, $zero, 0x57
    ctx->r17 = ADD32(0, 0X57);
    // 0x800A0104: addiu       $ra, $zero, 0x4B
    ctx->r31 = ADD32(0, 0X4B);
    // 0x800A0108: addiu       $t5, $zero, 0x4F
    ctx->r13 = ADD32(0, 0X4F);
    // 0x800A010C: addiu       $t3, $zero, 0x41
    ctx->r11 = ADD32(0, 0X41);
    // 0x800A0110: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800A0114:
    // 0x800A0114: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A0118: lbu         $v0, 0x268C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X268C);
    // 0x800A011C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A0120: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800A0124: beql        $v0, $v1, L_800A014C
    if (ctx->r2 == ctx->r3) {
        // 0x800A0128: addu        $t8, $t4, $t0
        ctx->r24 = ADD32(ctx->r12, ctx->r8);
            goto L_800A014C;
    }
    goto skip_0;
    // 0x800A0128: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
    skip_0:
    // 0x800A012C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800A0130:
    // 0x800A0130: sltiu       $at, $t0, 0x2A
    ctx->r1 = ctx->r8 < 0X2A ? 1 : 0;
    // 0x800A0134: beq         $at, $zero, L_800A0148
    if (ctx->r1 == 0) {
        // 0x800A0138: addu        $t6, $t4, $t0
        ctx->r14 = ADD32(ctx->r12, ctx->r8);
            goto L_800A0148;
    }
    // 0x800A0138: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x800A013C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800A0140: bnel        $t7, $v1, L_800A0130
    if (ctx->r15 != ctx->r3) {
        // 0x800A0144: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800A0130;
    }
    goto skip_1;
    // 0x800A0144: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_1:
L_800A0148:
    // 0x800A0148: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
L_800A014C:
    // 0x800A014C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800A0150: bnel        $t9, $v1, L_800A06CC
    if (ctx->r25 != ctx->r3) {
        // 0x800A0154: lbu         $v1, 0x1($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X1);
            goto L_800A06CC;
    }
    goto skip_2;
    // 0x800A0154: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    skip_2:
    // 0x800A0158: bne         $t1, $t2, L_800A0178
    if (ctx->r9 != ctx->r10) {
        // 0x800A015C: addiu       $a3, $zero, 0xF
        ctx->r7 = ADD32(0, 0XF);
            goto L_800A0178;
    }
    // 0x800A015C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800A0160: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0164: bne         $s3, $t6, L_800A0178
    if (ctx->r19 != ctx->r14) {
        // 0x800A0168: nop
    
            goto L_800A0178;
    }
    // 0x800A0168: nop

    // 0x800A016C: bne         $t3, $v1, L_800A0178
    if (ctx->r11 != ctx->r3) {
        // 0x800A0170: nop
    
            goto L_800A0178;
    }
    // 0x800A0170: nop

    // 0x800A0174: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_800A0178:
    // 0x800A0178: bne         $t1, $t2, L_800A0198
    if (ctx->r9 != ctx->r10) {
        // 0x800A017C: nop
    
            goto L_800A0198;
    }
    // 0x800A017C: nop

    // 0x800A0180: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0184: bne         $ra, $t7, L_800A0198
    if (ctx->r31 != ctx->r15) {
        // 0x800A0188: nop
    
            goto L_800A0198;
    }
    // 0x800A0188: nop

    // 0x800A018C: bne         $t3, $v1, L_800A0198
    if (ctx->r11 != ctx->r3) {
        // 0x800A0190: nop
    
            goto L_800A0198;
    }
    // 0x800A0190: nop

    // 0x800A0194: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0198:
    // 0x800A0198: bne         $t1, $t2, L_800A01B8
    if (ctx->r9 != ctx->r10) {
        // 0x800A019C: nop
    
            goto L_800A01B8;
    }
    // 0x800A019C: nop

    // 0x800A01A0: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A01A4: bne         $t3, $t8, L_800A01B8
    if (ctx->r11 != ctx->r24) {
        // 0x800A01A8: nop
    
            goto L_800A01B8;
    }
    // 0x800A01A8: nop

    // 0x800A01AC: bne         $t5, $v1, L_800A01B8
    if (ctx->r13 != ctx->r3) {
        // 0x800A01B0: nop
    
            goto L_800A01B8;
    }
    // 0x800A01B0: nop

    // 0x800A01B4: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_800A01B8:
    // 0x800A01B8: bne         $t1, $t2, L_800A01DC
    if (ctx->r9 != ctx->r10) {
        // 0x800A01BC: nop
    
            goto L_800A01DC;
    }
    // 0x800A01BC: nop

    // 0x800A01C0: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A01C4: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x800A01C8: bne         $t9, $at, L_800A01DC
    if (ctx->r25 != ctx->r1) {
        // 0x800A01CC: nop
    
            goto L_800A01DC;
    }
    // 0x800A01CC: nop

    // 0x800A01D0: bne         $t3, $v1, L_800A01DC
    if (ctx->r11 != ctx->r3) {
        // 0x800A01D4: nop
    
            goto L_800A01DC;
    }
    // 0x800A01D4: nop

    // 0x800A01D8: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_800A01DC:
    // 0x800A01DC: bne         $t1, $t2, L_800A0204
    if (ctx->r9 != ctx->r10) {
        // 0x800A01E0: nop
    
            goto L_800A0204;
    }
    // 0x800A01E0: nop

    // 0x800A01E4: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A01E8: bne         $t3, $t6, L_800A0204
    if (ctx->r11 != ctx->r14) {
        // 0x800A01EC: nop
    
            goto L_800A0204;
    }
    // 0x800A01EC: nop

    // 0x800A01F0: bne         $s3, $v1, L_800A0204
    if (ctx->r19 != ctx->r3) {
        // 0x800A01F4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800A0204;
    }
    // 0x800A01F4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A01F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A01FC: nop

    // 0x800A0200: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
L_800A0204:
    // 0x800A0204: bne         $t1, $t2, L_800A0224
    if (ctx->r9 != ctx->r10) {
        // 0x800A0208: nop
    
            goto L_800A0224;
    }
    // 0x800A0208: nop

    // 0x800A020C: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0210: bne         $ra, $t7, L_800A0224
    if (ctx->r31 != ctx->r15) {
        // 0x800A0214: nop
    
            goto L_800A0224;
    }
    // 0x800A0214: nop

    // 0x800A0218: bne         $s4, $v1, L_800A0224
    if (ctx->r20 != ctx->r3) {
        // 0x800A021C: nop
    
            goto L_800A0224;
    }
    // 0x800A021C: nop

    // 0x800A0220: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0224:
    // 0x800A0224: bne         $t1, $t2, L_800A0244
    if (ctx->r9 != ctx->r10) {
        // 0x800A0228: nop
    
            goto L_800A0244;
    }
    // 0x800A0228: nop

    // 0x800A022C: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0230: bne         $ra, $t8, L_800A0244
    if (ctx->r31 != ctx->r24) {
        // 0x800A0234: nop
    
            goto L_800A0244;
    }
    // 0x800A0234: nop

    // 0x800A0238: bne         $t5, $v1, L_800A0244
    if (ctx->r13 != ctx->r3) {
        // 0x800A023C: nop
    
            goto L_800A0244;
    }
    // 0x800A023C: nop

    // 0x800A0240: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_800A0244:
    // 0x800A0244: bne         $t1, $t2, L_800A0268
    if (ctx->r9 != ctx->r10) {
        // 0x800A0248: nop
    
            goto L_800A0268;
    }
    // 0x800A0248: nop

    // 0x800A024C: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0250: addiu       $at, $zero, 0x4A
    ctx->r1 = ADD32(0, 0X4A);
    // 0x800A0254: bne         $t3, $t9, L_800A0268
    if (ctx->r11 != ctx->r25) {
        // 0x800A0258: nop
    
            goto L_800A0268;
    }
    // 0x800A0258: nop

    // 0x800A025C: bne         $v1, $at, L_800A0268
    if (ctx->r3 != ctx->r1) {
        // 0x800A0260: nop
    
            goto L_800A0268;
    }
    // 0x800A0260: nop

    // 0x800A0264: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0268:
    // 0x800A0268: bne         $t1, $t2, L_800A0288
    if (ctx->r9 != ctx->r10) {
        // 0x800A026C: nop
    
            goto L_800A0288;
    }
    // 0x800A026C: nop

    // 0x800A0270: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0274: bne         $s1, $t6, L_800A0288
    if (ctx->r17 != ctx->r14) {
        // 0x800A0278: nop
    
            goto L_800A0288;
    }
    // 0x800A0278: nop

    // 0x800A027C: bne         $t3, $v1, L_800A0288
    if (ctx->r11 != ctx->r3) {
        // 0x800A0280: nop
    
            goto L_800A0288;
    }
    // 0x800A0280: nop

    // 0x800A0284: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_800A0288:
    // 0x800A0288: bne         $t1, $t2, L_800A02A8
    if (ctx->r9 != ctx->r10) {
        // 0x800A028C: nop
    
            goto L_800A02A8;
    }
    // 0x800A028C: nop

    // 0x800A0290: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0294: bne         $s3, $t7, L_800A02A8
    if (ctx->r19 != ctx->r15) {
        // 0x800A0298: nop
    
            goto L_800A02A8;
    }
    // 0x800A0298: nop

    // 0x800A029C: bne         $t5, $v1, L_800A02A8
    if (ctx->r13 != ctx->r3) {
        // 0x800A02A0: nop
    
            goto L_800A02A8;
    }
    // 0x800A02A0: nop

    // 0x800A02A4: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_800A02A8:
    // 0x800A02A8: bne         $t1, $t2, L_800A02CC
    if (ctx->r9 != ctx->r10) {
        // 0x800A02AC: nop
    
            goto L_800A02CC;
    }
    // 0x800A02AC: nop

    // 0x800A02B0: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A02B4: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x800A02B8: bne         $t3, $t8, L_800A02CC
    if (ctx->r11 != ctx->r24) {
        // 0x800A02BC: nop
    
            goto L_800A02CC;
    }
    // 0x800A02BC: nop

    // 0x800A02C0: bne         $a0, $v1, L_800A02CC
    if (ctx->r4 != ctx->r3) {
        // 0x800A02C4: nop
    
            goto L_800A02CC;
    }
    // 0x800A02C4: nop

    // 0x800A02C8: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_800A02CC:
    // 0x800A02CC: bne         $t1, $t2, L_800A02EC
    if (ctx->r9 != ctx->r10) {
        // 0x800A02D0: addiu       $a0, $zero, 0x54
        ctx->r4 = ADD32(0, 0X54);
            goto L_800A02EC;
    }
    // 0x800A02D0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x800A02D4: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A02D8: bne         $t3, $t9, L_800A02EC
    if (ctx->r11 != ctx->r25) {
        // 0x800A02DC: nop
    
            goto L_800A02EC;
    }
    // 0x800A02DC: nop

    // 0x800A02E0: bne         $s1, $v1, L_800A02EC
    if (ctx->r17 != ctx->r3) {
        // 0x800A02E4: nop
    
            goto L_800A02EC;
    }
    // 0x800A02E4: nop

    // 0x800A02E8: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_800A02EC:
    // 0x800A02EC: bne         $t1, $t2, L_800A030C
    if (ctx->r9 != ctx->r10) {
        // 0x800A02F0: nop
    
            goto L_800A030C;
    }
    // 0x800A02F0: nop

    // 0x800A02F4: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A02F8: bne         $t5, $t6, L_800A030C
    if (ctx->r13 != ctx->r14) {
        // 0x800A02FC: nop
    
            goto L_800A030C;
    }
    // 0x800A02FC: nop

    // 0x800A0300: bne         $a0, $v1, L_800A030C
    if (ctx->r4 != ctx->r3) {
        // 0x800A0304: nop
    
            goto L_800A030C;
    }
    // 0x800A0304: nop

    // 0x800A0308: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A030C:
    // 0x800A030C: bne         $t1, $t2, L_800A0330
    if (ctx->r9 != ctx->r10) {
        // 0x800A0310: nop
    
            goto L_800A0330;
    }
    // 0x800A0310: nop

    // 0x800A0314: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0318: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800A031C: bne         $t3, $t7, L_800A0330
    if (ctx->r11 != ctx->r15) {
        // 0x800A0320: nop
    
            goto L_800A0330;
    }
    // 0x800A0320: nop

    // 0x800A0324: bne         $v1, $at, L_800A0330
    if (ctx->r3 != ctx->r1) {
        // 0x800A0328: nop
    
            goto L_800A0330;
    }
    // 0x800A0328: nop

    // 0x800A032C: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_800A0330:
    // 0x800A0330: bne         $t1, $t2, L_800A0350
    if (ctx->r9 != ctx->r10) {
        // 0x800A0334: nop
    
            goto L_800A0350;
    }
    // 0x800A0334: nop

    // 0x800A0338: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A033C: bne         $t5, $t8, L_800A0350
    if (ctx->r13 != ctx->r24) {
        // 0x800A0340: nop
    
            goto L_800A0350;
    }
    // 0x800A0340: nop

    // 0x800A0344: bne         $s3, $v1, L_800A0350
    if (ctx->r19 != ctx->r3) {
        // 0x800A0348: nop
    
            goto L_800A0350;
    }
    // 0x800A0348: nop

    // 0x800A034C: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_800A0350:
    // 0x800A0350: bne         $t1, $t2, L_800A0374
    if (ctx->r9 != ctx->r10) {
        // 0x800A0354: nop
    
            goto L_800A0374;
    }
    // 0x800A0354: nop

    // 0x800A0358: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A035C: addiu       $v0, $zero, 0x4A
    ctx->r2 = ADD32(0, 0X4A);
    // 0x800A0360: bne         $t3, $t9, L_800A0374
    if (ctx->r11 != ctx->r25) {
        // 0x800A0364: nop
    
            goto L_800A0374;
    }
    // 0x800A0364: nop

    // 0x800A0368: bne         $v0, $v1, L_800A0374
    if (ctx->r2 != ctx->r3) {
        // 0x800A036C: nop
    
            goto L_800A0374;
    }
    // 0x800A036C: nop

    // 0x800A0370: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0374:
    // 0x800A0374: bne         $t1, $t2, L_800A0394
    if (ctx->r9 != ctx->r10) {
        // 0x800A0378: addiu       $v0, $zero, 0x4A
        ctx->r2 = ADD32(0, 0X4A);
            goto L_800A0394;
    }
    // 0x800A0378: addiu       $v0, $zero, 0x4A
    ctx->r2 = ADD32(0, 0X4A);
    // 0x800A037C: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0380: bne         $a0, $t6, L_800A0394
    if (ctx->r4 != ctx->r14) {
        // 0x800A0384: nop
    
            goto L_800A0394;
    }
    // 0x800A0384: nop

    // 0x800A0388: bne         $t5, $v1, L_800A0394
    if (ctx->r13 != ctx->r3) {
        // 0x800A038C: nop
    
            goto L_800A0394;
    }
    // 0x800A038C: nop

    // 0x800A0390: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_800A0394:
    // 0x800A0394: bne         $t1, $t2, L_800A03B8
    if (ctx->r9 != ctx->r10) {
        // 0x800A0398: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800A03B8;
    }
    // 0x800A0398: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A039C: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A03A0: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x800A03A4: bne         $ra, $t7, L_800A03B8
    if (ctx->r31 != ctx->r15) {
        // 0x800A03A8: nop
    
            goto L_800A03B8;
    }
    // 0x800A03A8: nop

    // 0x800A03AC: bne         $v1, $at, L_800A03B8
    if (ctx->r3 != ctx->r1) {
        // 0x800A03B0: nop
    
            goto L_800A03B8;
    }
    // 0x800A03B0: nop

    // 0x800A03B4: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A03B8:
    // 0x800A03B8: bne         $t1, $t2, L_800A03DC
    if (ctx->r9 != ctx->r10) {
        // 0x800A03BC: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_800A03DC;
    }
    // 0x800A03BC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800A03C0: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A03C4: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800A03C8: bne         $t3, $t8, L_800A03DC
    if (ctx->r11 != ctx->r24) {
        // 0x800A03CC: nop
    
            goto L_800A03DC;
    }
    // 0x800A03CC: nop

    // 0x800A03D0: bne         $v1, $at, L_800A03DC
    if (ctx->r3 != ctx->r1) {
        // 0x800A03D4: nop
    
            goto L_800A03DC;
    }
    // 0x800A03D4: nop

    // 0x800A03D8: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_800A03DC:
    // 0x800A03DC: bne         $t1, $t2, L_800A0400
    if (ctx->r9 != ctx->r10) {
        // 0x800A03E0: nop
    
            goto L_800A0400;
    }
    // 0x800A03E0: nop

    // 0x800A03E4: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A03E8: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x800A03EC: bne         $t9, $at, L_800A0400
    if (ctx->r25 != ctx->r1) {
        // 0x800A03F0: nop
    
            goto L_800A0400;
    }
    // 0x800A03F0: nop

    // 0x800A03F4: bne         $t5, $v1, L_800A0400
    if (ctx->r13 != ctx->r3) {
        // 0x800A03F8: nop
    
            goto L_800A0400;
    }
    // 0x800A03F8: nop

    // 0x800A03FC: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0400:
    // 0x800A0400: bne         $t1, $t2, L_800A0420
    if (ctx->r9 != ctx->r10) {
        // 0x800A0404: nop
    
            goto L_800A0420;
    }
    // 0x800A0404: nop

    // 0x800A0408: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A040C: bne         $ra, $t6, L_800A0420
    if (ctx->r31 != ctx->r14) {
        // 0x800A0410: nop
    
            goto L_800A0420;
    }
    // 0x800A0410: nop

    // 0x800A0414: bne         $s3, $v1, L_800A0420
    if (ctx->r19 != ctx->r3) {
        // 0x800A0418: nop
    
            goto L_800A0420;
    }
    // 0x800A0418: nop

    // 0x800A041C: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0420:
    // 0x800A0420: bne         $t1, $t2, L_800A0444
    if (ctx->r9 != ctx->r10) {
        // 0x800A0424: nop
    
            goto L_800A0444;
    }
    // 0x800A0424: nop

    // 0x800A0428: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A042C: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800A0430: bne         $t7, $at, L_800A0444
    if (ctx->r15 != ctx->r1) {
        // 0x800A0434: nop
    
            goto L_800A0444;
    }
    // 0x800A0434: nop

    // 0x800A0438: bne         $v0, $v1, L_800A0444
    if (ctx->r2 != ctx->r3) {
        // 0x800A043C: nop
    
            goto L_800A0444;
    }
    // 0x800A043C: nop

    // 0x800A0440: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0444:
    // 0x800A0444: bne         $t1, $t2, L_800A0468
    if (ctx->r9 != ctx->r10) {
        // 0x800A0448: nop
    
            goto L_800A0468;
    }
    // 0x800A0448: nop

    // 0x800A044C: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0450: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800A0454: bne         $ra, $t8, L_800A0468
    if (ctx->r31 != ctx->r24) {
        // 0x800A0458: nop
    
            goto L_800A0468;
    }
    // 0x800A0458: nop

    // 0x800A045C: bne         $v1, $at, L_800A0468
    if (ctx->r3 != ctx->r1) {
        // 0x800A0460: nop
    
            goto L_800A0468;
    }
    // 0x800A0460: nop

    // 0x800A0464: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A0468:
    // 0x800A0468: bne         $t1, $t2, L_800A048C
    if (ctx->r9 != ctx->r10) {
        // 0x800A046C: nop
    
            goto L_800A048C;
    }
    // 0x800A046C: nop

    // 0x800A0470: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0474: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800A0478: bne         $t9, $at, L_800A048C
    if (ctx->r25 != ctx->r1) {
        // 0x800A047C: addiu       $at, $zero, 0x74
        ctx->r1 = ADD32(0, 0X74);
            goto L_800A048C;
    }
    // 0x800A047C: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x800A0480: bne         $v1, $at, L_800A048C
    if (ctx->r3 != ctx->r1) {
        // 0x800A0484: nop
    
            goto L_800A048C;
    }
    // 0x800A0484: nop

    // 0x800A0488: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_800A048C:
    // 0x800A048C: bne         $t1, $t2, L_800A04AC
    if (ctx->r9 != ctx->r10) {
        // 0x800A0490: nop
    
            goto L_800A04AC;
    }
    // 0x800A0490: nop

    // 0x800A0494: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0498: bne         $s2, $t6, L_800A04AC
    if (ctx->r18 != ctx->r14) {
        // 0x800A049C: nop
    
            goto L_800A04AC;
    }
    // 0x800A049C: nop

    // 0x800A04A0: bne         $s2, $v1, L_800A04AC
    if (ctx->r18 != ctx->r3) {
        // 0x800A04A4: nop
    
            goto L_800A04AC;
    }
    // 0x800A04A4: nop

    // 0x800A04A8: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_800A04AC:
    // 0x800A04AC: bne         $t1, $t2, L_800A04CC
    if (ctx->r9 != ctx->r10) {
        // 0x800A04B0: nop
    
            goto L_800A04CC;
    }
    // 0x800A04B0: nop

    // 0x800A04B4: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A04B8: bne         $t5, $t7, L_800A04CC
    if (ctx->r13 != ctx->r15) {
        // 0x800A04BC: nop
    
            goto L_800A04CC;
    }
    // 0x800A04BC: nop

    // 0x800A04C0: bne         $s2, $v1, L_800A04CC
    if (ctx->r18 != ctx->r3) {
        // 0x800A04C4: nop
    
            goto L_800A04CC;
    }
    // 0x800A04C4: nop

    // 0x800A04C8: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A04CC:
    // 0x800A04CC: bne         $t1, $t2, L_800A04EC
    if (ctx->r9 != ctx->r10) {
        // 0x800A04D0: nop
    
            goto L_800A04EC;
    }
    // 0x800A04D0: nop

    // 0x800A04D4: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A04D8: bne         $s1, $t8, L_800A04EC
    if (ctx->r17 != ctx->r24) {
        // 0x800A04DC: nop
    
            goto L_800A04EC;
    }
    // 0x800A04DC: nop

    // 0x800A04E0: bne         $s1, $v1, L_800A04EC
    if (ctx->r17 != ctx->r3) {
        // 0x800A04E4: nop
    
            goto L_800A04EC;
    }
    // 0x800A04E4: nop

    // 0x800A04E8: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A04EC:
    // 0x800A04EC: bne         $t1, $t2, L_800A050C
    if (ctx->r9 != ctx->r10) {
        // 0x800A04F0: nop
    
            goto L_800A050C;
    }
    // 0x800A04F0: nop

    // 0x800A04F4: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A04F8: bne         $s2, $t9, L_800A050C
    if (ctx->r18 != ctx->r25) {
        // 0x800A04FC: nop
    
            goto L_800A050C;
    }
    // 0x800A04FC: nop

    // 0x800A0500: bne         $s1, $v1, L_800A050C
    if (ctx->r17 != ctx->r3) {
        // 0x800A0504: nop
    
            goto L_800A050C;
    }
    // 0x800A0504: nop

    // 0x800A0508: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A050C:
    // 0x800A050C: bne         $t1, $t2, L_800A052C
    if (ctx->r9 != ctx->r10) {
        // 0x800A0510: nop
    
            goto L_800A052C;
    }
    // 0x800A0510: nop

    // 0x800A0514: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0518: bne         $s1, $t6, L_800A052C
    if (ctx->r17 != ctx->r14) {
        // 0x800A051C: nop
    
            goto L_800A052C;
    }
    // 0x800A051C: nop

    // 0x800A0520: bne         $s2, $v1, L_800A052C
    if (ctx->r18 != ctx->r3) {
        // 0x800A0524: nop
    
            goto L_800A052C;
    }
    // 0x800A0524: nop

    // 0x800A0528: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_800A052C:
    // 0x800A052C: bne         $t1, $t2, L_800A0550
    if (ctx->r9 != ctx->r10) {
        // 0x800A0530: nop
    
            goto L_800A0550;
    }
    // 0x800A0530: nop

    // 0x800A0534: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A0538: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x800A053C: bne         $t7, $at, L_800A0550
    if (ctx->r15 != ctx->r1) {
        // 0x800A0540: nop
    
            goto L_800A0550;
    }
    // 0x800A0540: nop

    // 0x800A0544: bne         $t5, $v1, L_800A0550
    if (ctx->r13 != ctx->r3) {
        // 0x800A0548: nop
    
            goto L_800A0550;
    }
    // 0x800A0548: nop

    // 0x800A054C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_800A0550:
    // 0x800A0550: bne         $t1, $t2, L_800A0570
    if (ctx->r9 != ctx->r10) {
        // 0x800A0554: nop
    
            goto L_800A0570;
    }
    // 0x800A0554: nop

    // 0x800A0558: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A055C: bne         $v0, $t8, L_800A0570
    if (ctx->r2 != ctx->r24) {
        // 0x800A0560: nop
    
            goto L_800A0570;
    }
    // 0x800A0560: nop

    // 0x800A0564: bne         $s4, $v1, L_800A0570
    if (ctx->r20 != ctx->r3) {
        // 0x800A0568: nop
    
            goto L_800A0570;
    }
    // 0x800A0568: nop

    // 0x800A056C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_800A0570:
    // 0x800A0570: bne         $t1, $t2, L_800A0594
    if (ctx->r9 != ctx->r10) {
        // 0x800A0574: xor         $v0, $t1, $t2
        ctx->r2 = ctx->r9 ^ ctx->r10;
            goto L_800A0594;
    }
    // 0x800A0574: xor         $v0, $t1, $t2
    ctx->r2 = ctx->r9 ^ ctx->r10;
    // 0x800A0578: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800A057C: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800A0580: bne         $s4, $t9, L_800A0594
    if (ctx->r20 != ctx->r25) {
        // 0x800A0584: nop
    
            goto L_800A0594;
    }
    // 0x800A0584: nop

    // 0x800A0588: bne         $v1, $at, L_800A0594
    if (ctx->r3 != ctx->r1) {
        // 0x800A058C: nop
    
            goto L_800A0594;
    }
    // 0x800A058C: nop

    // 0x800A0590: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_800A0594:
    // 0x800A0594: bne         $t1, $t2, L_800A05B8
    if (ctx->r9 != ctx->r10) {
        // 0x800A0598: sll         $t9, $t0, 2
        ctx->r25 = S32(ctx->r8 << 2);
            goto L_800A05B8;
    }
    // 0x800A0598: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800A059C: lbu         $t6, -0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X1);
    // 0x800A05A0: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x800A05A4: bne         $s4, $t6, L_800A05B8
    if (ctx->r20 != ctx->r14) {
        // 0x800A05A8: nop
    
            goto L_800A05B8;
    }
    // 0x800A05A8: nop

    // 0x800A05AC: bne         $v1, $at, L_800A05B8
    if (ctx->r3 != ctx->r1) {
        // 0x800A05B0: nop
    
            goto L_800A05B8;
    }
    // 0x800A05B0: nop

    // 0x800A05B4: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_800A05B8:
    // 0x800A05B8: bne         $t1, $t2, L_800A05DC
    if (ctx->r9 != ctx->r10) {
        // 0x800A05BC: addu        $a1, $a1, $t9
        ctx->r5 = ADD32(ctx->r5, ctx->r25);
            goto L_800A05DC;
    }
    // 0x800A05BC: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x800A05C0: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x800A05C4: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x800A05C8: bne         $s4, $t7, L_800A05DC
    if (ctx->r20 != ctx->r15) {
        // 0x800A05CC: nop
    
            goto L_800A05DC;
    }
    // 0x800A05CC: nop

    // 0x800A05D0: bne         $v1, $at, L_800A05DC
    if (ctx->r3 != ctx->r1) {
        // 0x800A05D4: nop
    
            goto L_800A05DC;
    }
    // 0x800A05D4: nop

    // 0x800A05D8: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_800A05DC:
    // 0x800A05DC: bne         $v0, $zero, L_800A0600
    if (ctx->r2 != 0) {
        // 0x800A05E0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800A0600;
    }
    // 0x800A05E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A05E4: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x800A05E8: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x800A05EC: bne         $t8, $at, L_800A0600
    if (ctx->r24 != ctx->r1) {
        // 0x800A05F0: nop
    
            goto L_800A0600;
    }
    // 0x800A05F0: nop

    // 0x800A05F4: bne         $ra, $v1, L_800A0600
    if (ctx->r31 != ctx->r3) {
        // 0x800A05F8: nop
    
            goto L_800A0600;
    }
    // 0x800A05F8: nop

    // 0x800A05FC: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_800A0600:
    // 0x800A0600: lw          $a1, 0x26E4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X26E4);
    // 0x800A0604: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800A0608: beq         $a1, $zero, L_800A0690
    if (ctx->r5 == 0) {
        // 0x800A060C: nop
    
            goto L_800A0690;
    }
    // 0x800A060C: nop

    // 0x800A0610: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A0614: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800A0618: beq         $s1, $v1, L_800A0628
    if (ctx->r17 == ctx->r3) {
        // 0x800A061C: cvt.s.w     $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800A0628;
    }
    // 0x800A061C: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A0620: bnel        $s2, $v1, L_800A0630
    if (ctx->r18 != ctx->r3) {
        // 0x800A0624: lwc1        $f10, 0x60($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
            goto L_800A0630;
    }
    goto skip_3;
    // 0x800A0624: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    skip_3:
L_800A0628:
    // 0x800A0628: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800A062C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
L_800A0630:
    // 0x800A0630: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800A0634: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800A0638: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800A063C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x800A0640: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800A0644: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800A0648: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800A064C: jal         0x8009D994
    // 0x800A0650: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800A0650: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800A0654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0658: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A065C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A0660: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0664: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800A0668: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800A066C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A0670: addiu       $t4, $t4, 0x268C
    ctx->r12 = ADD32(ctx->r12, 0X268C);
    // 0x800A0674: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800A0678: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A067C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800A0680: addiu       $t3, $zero, 0x41
    ctx->r11 = ADD32(0, 0X41);
    // 0x800A0684: addiu       $t5, $zero, 0x4F
    ctx->r13 = ADD32(0, 0X4F);
    // 0x800A0688: addiu       $ra, $zero, 0x4B
    ctx->r31 = ADD32(0, 0X4B);
    // 0x800A068C: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
L_800A0690:
    // 0x800A0690: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A0694: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x800A0698: lbu         $t7, 0x26B8($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X26B8);
    // 0x800A069C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800A06A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A06A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800A06A8: bgez        $t7, L_800A06BC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800A06AC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800A06BC;
    }
    // 0x800A06AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A06B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A06B4: nop

    // 0x800A06B8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800A06BC:
    // 0x800A06BC: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800A06C0: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x800A06C4: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800A06C8: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
L_800A06CC:
    // 0x800A06CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A06D0: bne         $v1, $zero, L_800A0114
    if (ctx->r3 != 0) {
        // 0x800A06D4: nop
    
            goto L_800A0114;
    }
    // 0x800A06D4: nop

L_800A06D8:
    // 0x800A06D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A06DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800A06E0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800A06E4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800A06E8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800A06EC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800A06F0: jr          $ra
    // 0x800A06F4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800A06F4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Matrix_GetYPRAngles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AB8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80006ABC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006AC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80006AC4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80006AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006ACC: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x80006AD0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80006AD4: addiu       $t6, $t6, 0x46A0
    ctx->r14 = ADD32(ctx->r14, 0X46A0);
    // 0x80006AD8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80006ADC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80006AE0: addiu       $t1, $t1, 0x46AC
    ctx->r9 = ADD32(ctx->r9, 0X46AC);
    // 0x80006AE4: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80006AE8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80006AEC: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // 0x80006AF0: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80006AF4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80006AF8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80006AFC: addiu       $t8, $t8, 0x46B8
    ctx->r24 = ADD32(ctx->r24, 0X46B8);
    // 0x80006B00: addiu       $t5, $sp, 0x34
    ctx->r13 = ADD32(ctx->r29, 0X34);
    // 0x80006B04: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80006B08: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80006B0C: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80006B10: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80006B14: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80006B18: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80006B1C: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80006B20: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80006B24: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80006B28: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80006B2C: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80006B30: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80006B34: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80006B38: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80006B3C: jal         0x80006A20
    // 0x80006B40: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_0;
    // 0x80006B40: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    after_0:
    // 0x80006B44: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80006B48: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80006B4C: jal         0x80006A20
    // 0x80006B50: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x80006B50: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80006B54: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80006B58: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80006B5C: jal         0x80006A20
    // 0x80006B60: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80006B60: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80006B64: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80006B68: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80006B6C: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80006B70: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80006B74: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80006B78: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80006B7C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80006B80: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80006B84: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80006B88: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80006B8C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80006B90: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80006B94: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80006B98: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80006B9C: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80006BA0: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x80006BA4: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80006BA8: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x80006BAC: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80006BB0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80006BB4: jal         0x80005100
    // 0x80006BB8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x80006BB8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80006BBC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80006BC0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80006BC4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80006BC8: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80006BCC: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80006BD0: nop

    // 0x80006BD4: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80006BD8: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80006BDC: jal         0x80005100
    // 0x80006BE0: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_4;
    // 0x80006BE0: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_4:
    // 0x80006BE4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80006BE8: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80006BEC: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80006BF0: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x80006BF4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006BF8: jal         0x80005D44
    // 0x80006BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80006BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80006C00: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80006C04: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80006C08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006C0C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80006C10: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80006C14: jal         0x80005E90
    // 0x80006C18: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x80006C18: nop

    after_6:
    // 0x80006C1C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80006C20: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80006C24: jal         0x80006A20
    // 0x80006C28: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_7;
    // 0x80006C28: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80006C2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006C30: lwc1        $f0, -0x7EF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7EF0);
    // 0x80006C34: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80006C38: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80006C3C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80006C40: nop

    // 0x80006C44: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80006C48: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80006C4C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80006C50: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80006C54: jal         0x80005100
    // 0x80006C58: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    Math_Atan2F(rdram, ctx);
        goto after_8;
    // 0x80006C58: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80006C5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006C60: lwc1        $f4, -0x7EEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7EEC);
    // 0x80006C64: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80006C68: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80006C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006C70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006C74: jr          $ra
    // 0x80006C78: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80006C78: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void AudioLoad_SyncLoadFont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F478: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000F47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F480: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000F484: jal         0x8000F790
    // 0x8000F488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000F488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8000F48C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000F490: lw          $t6, 0x5C70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C70);
    // 0x8000F494: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000F498: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8000F49C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000F4A0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8000F4A4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8000F4A8: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x8000F4AC: lbu         $a2, 0x3($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3);
    // 0x8000F4B0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000F4B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000F4B8: beq         $a0, $at, L_8000F4D8
    if (ctx->r4 == ctx->r1) {
        // 0x8000F4BC: sw          $a2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r6;
            goto L_8000F4D8;
    }
    // 0x8000F4BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8000F4C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8000F4C4: jal         0x8000F388
    // 0x8000F4C8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    AudioLoad_SyncLoadSampleBank(rdram, ctx);
        goto after_1;
    // 0x8000F4C8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8000F4CC: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F4D0: b           L_8000F4DC
    // 0x8000F4D4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_8000F4DC;
    // 0x8000F4D4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8000F4D8:
    // 0x8000F4D8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8000F4DC:
    // 0x8000F4DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000F4E0: beq         $a2, $at, L_8000F4F8
    if (ctx->r6 == ctx->r1) {
        // 0x8000F4E4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8000F4F8;
    }
    // 0x8000F4E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000F4E8: jal         0x8000F388
    // 0x8000F4EC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    AudioLoad_SyncLoadSampleBank(rdram, ctx);
        goto after_2;
    // 0x8000F4EC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8000F4F0: b           L_8000F4FC
    // 0x8000F4F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_8000F4FC;
    // 0x8000F4F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8000F4F8:
    // 0x8000F4F8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8000F4FC:
    // 0x8000F4FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000F500: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8000F504: jal         0x8000F554
    // 0x8000F508: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    AudioLoad_SyncLoad(rdram, ctx);
        goto after_3;
    // 0x8000F508: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x8000F50C: bne         $v0, $zero, L_8000F51C
    if (ctx->r2 != 0) {
        // 0x8000F510: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000F51C;
    }
    // 0x8000F510: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000F514: b           L_8000F544
    // 0x8000F518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F544;
    // 0x8000F518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F51C:
    // 0x8000F51C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8000F520: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F524: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000F528: bne         $t8, $at, L_8000F540
    if (ctx->r24 != ctx->r1) {
        // 0x8000F52C: addiu       $a2, $sp, 0x20
        ctx->r6 = ADD32(ctx->r29, 0X20);
            goto L_8000F540;
    }
    // 0x8000F52C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8000F530: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000F534: jal         0x80011120
    // 0x8000F538: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    AudioLoad_RelocateFontAndPreloadSamples(rdram, ctx);
        goto after_4;
    // 0x8000F538: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_4:
    // 0x8000F53C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_8000F540:
    // 0x8000F540: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000F544:
    // 0x8000F544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F548: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000F54C: jr          $ra
    // 0x8000F550: nop

    return;
    // 0x8000F550: nop

;}
RECOMP_FUNC void ptstart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022FF0: jr          $ra
    // 0x80022FF4: nop

    return;
    // 0x80022FF4: nop

;}
RECOMP_FUNC void Effect_Effect357_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800798C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800798C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800798CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800798D0: beq         $a0, $at, L_800798E8
    if (ctx->r4 == ctx->r1) {
        // 0x800798D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800798E8;
    }
    // 0x800798D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800798D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800798DC: beq         $a0, $at, L_800798E8
    if (ctx->r4 == ctx->r1) {
        // 0x800798E0: nop
    
            goto L_800798E8;
    }
    // 0x800798E0: nop

    // 0x800798E4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800798E8:
    // 0x800798E8: jr          $ra
    // 0x800798EC: nop

    return;
    // 0x800798EC: nop

;}
RECOMP_FUNC void Effect_FireSmoke1_Spawn2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007D00C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D010: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007D014: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007D018: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007D01C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007D020: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007D024: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007D028: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007D02C:
    // 0x8007D02C: bnel        $t6, $zero, L_8007D058
    if (ctx->r14 != 0) {
        // 0x8007D030: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007D058;
    }
    goto skip_0;
    // 0x8007D030: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007D034: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D038: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007D03C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007D040: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007D044: jal         0x8007CC00
    // 0x8007D048: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_FireSmoke1_Setup(rdram, ctx);
        goto after_0;
    // 0x8007D048: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007D04C: b           L_8007D068
    // 0x8007D050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007D068;
    // 0x8007D050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D054: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007D058:
    // 0x8007D058: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007D05C: beql        $at, $zero, L_8007D02C
    if (ctx->r1 == 0) {
        // 0x8007D060: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007D02C;
    }
    goto skip_1;
    // 0x8007D060: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007D064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007D068:
    // 0x8007D068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007D06C: jr          $ra
    // 0x8007D070: nop

    return;
    // 0x8007D070: nop

;}
RECOMP_FUNC void Graphics_SetTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003C54: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80003C58: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80003C5C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80003C60: addiu       $a0, $a0, 0x7E50
    ctx->r4 = ADD32(ctx->r4, 0X7E50);
    // 0x80003C64: addiu       $v1, $v1, 0x450
    ctx->r3 = ADD32(ctx->r3, 0X450);
    // 0x80003C68: addiu       $v0, $v0, 0x7E54
    ctx->r2 = ADD32(ctx->r2, 0X7E54);
    // 0x80003C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003C70: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80003C74: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80003C78: addiu       $t6, $t6, 0x22A0
    ctx->r14 = ADD32(ctx->r14, 0X22A0);
    // 0x80003C7C: sw          $t6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->r14;
    // 0x80003C80: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80003C84: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80003C88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80003C8C: sw          $t8, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r24;
    // 0x80003C90: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80003C94: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80003C98: addiu       $t4, $t4, 0x520
    ctx->r12 = ADD32(ctx->r12, 0X520);
    // 0x80003C9C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80003CA0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80003CA4: subu        $t5, $t4, $v1
    ctx->r13 = SUB32(ctx->r12, ctx->r3);
    // 0x80003CA8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80003CAC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80003CB0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80003CB4: addiu       $t7, $t7, 0x1410
    ctx->r15 = ADD32(ctx->r15, 0X1410);
    // 0x80003CB8: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x80003CBC: sw          $v1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r3;
    // 0x80003CC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80003CC4: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80003CC8: addiu       $t1, $t1, 0x3DD0
    ctx->r9 = ADD32(ctx->r9, 0X3DD0);
    // 0x80003CCC: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
    // 0x80003CD0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80003CD4: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80003CD8: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x80003CDC: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80003CE0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80003CE4: addiu       $t5, $t5, 0x1000
    ctx->r13 = ADD32(ctx->r13, 0X1000);
    // 0x80003CE8: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x80003CEC: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x80003CF0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80003CF4: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80003CF8: addiu       $t9, $t9, 0x7800
    ctx->r25 = ADD32(ctx->r25, 0X7800);
    // 0x80003CFC: sw          $t1, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r9;
    // 0x80003D00: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80003D04: lui         $t1, 0x802D
    ctx->r9 = S32(0X802D << 16);
    // 0x80003D08: addiu       $t1, $t1, 0x7800
    ctx->r9 = ADD32(ctx->r9, 0X7800);
    // 0x80003D0C: sw          $t3, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r11;
    // 0x80003D10: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80003D14: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80003D18: ori         $at, $at, 0x2D50
    ctx->r1 = ctx->r1 | 0X2D50;
    // 0x80003D1C: sw          $t5, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r13;
    // 0x80003D20: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80003D24: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80003D28: sw          $t7, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r15;
    // 0x80003D2C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80003D30: sw          $t9, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r25;
    // 0x80003D34: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80003D38: sw          $t1, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r9;
    // 0x80003D3C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80003D40: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80003D44: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80003D48: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
    // 0x80003D4C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80003D50: lw          $t6, 0x7E64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E64);
    // 0x80003D54: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80003D58: ori         $at, $at, 0xD2B0
    ctx->r1 = ctx->r1 | 0XD2B0;
    // 0x80003D5C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80003D60: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80003D64: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80003D68: sra         $t0, $t9, 3
    ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80003D6C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80003D70: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    // 0x80003D74: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80003D78: lui         $t3, 0x8028
    ctx->r11 = S32(0X8028 << 16);
    // 0x80003D7C: addiu       $t3, $t3, 0x1400
    ctx->r11 = ADD32(ctx->r11, 0X1400);
    // 0x80003D80: sw          $t3, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->r11;
    // 0x80003D84: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80003D88: addiu       $t5, $zero, 0xC00
    ctx->r13 = ADD32(0, 0XC00);
    // 0x80003D8C: jal         0x80021970
    // 0x80003D90: sw          $t5, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r13;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80003D90: sw          $t5, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r13;
    after_0:
    // 0x80003D94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80003D98: addiu       $v0, $v0, 0x7E54
    ctx->r2 = ADD32(ctx->r2, 0X7E54);
    // 0x80003D9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80003DA0: addiu       $a0, $a0, 0x21E0
    ctx->r4 = ADD32(ctx->r4, 0X21E0);
    // 0x80003DA4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80003DA8: jal         0x80020720
    // 0x80003DAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80003DAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80003DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003DB8: jr          $ra
    // 0x80003DBC: nop

    return;
    // 0x80003DBC: nop

;}
RECOMP_FUNC void Scenery_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D654: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D658: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005D65C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005D660: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005D664: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005D668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D66C: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005D670: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005D674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D678: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    // 0x8005D67C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005D680: jal         0x8005D008
    // 0x8005D684: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    Object_SetMatrix(rdram, ctx);
        goto after_0;
    // 0x8005D684: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_0:
    // 0x8005D688: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D68C: lwc1        $f16, -0x7B84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005D690: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005D694: lbu         $t6, 0x20($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X20);
    // 0x8005D698: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005D69C: bne         $t6, $zero, L_8005D880
    if (ctx->r14 != 0) {
        // 0x8005D6A0: swc1        $f18, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
            goto L_8005D880;
    }
    // 0x8005D6A0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8005D6A4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005D6A8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8005D6AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D6B0: beq         $v0, $at, L_8005D6D0
    if (ctx->r2 == ctx->r1) {
        // 0x8005D6B4: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_8005D6D0;
    }
    // 0x8005D6B4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005D6B8: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x8005D6BC: beq         $v0, $at, L_8005D6D0
    if (ctx->r2 == ctx->r1) {
        // 0x8005D6C0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8005D6D0;
    }
    // 0x8005D6C0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005D6C4: beq         $v0, $at, L_8005D6D0
    if (ctx->r2 == ctx->r1) {
        // 0x8005D6C8: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_8005D6D0;
    }
    // 0x8005D6C8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8005D6CC: bne         $v0, $at, L_8005D7A4
    if (ctx->r2 != ctx->r1) {
        // 0x8005D6D0: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_8005D7A4;
    }
L_8005D6D0:
    // 0x8005D6D0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005D6D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D6D8: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x8005D6DC: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x8005D6E0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005D6E4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005D6E8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005D6EC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005D6F0: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8005D6F4: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8005D6F8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005D6FC: jal         0x800B9EB0
    // 0x8005D700: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_57(rdram, ctx);
        goto after_1;
    // 0x8005D700: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x8005D704: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8005D708: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x8005D70C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005D710: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x8005D714: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x8005D718: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005D71C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8005D720: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005D724: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005D728: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D72C: bgezl       $t3, L_8005D748
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8005D730: lw          $v0, 0x0($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X0);
            goto L_8005D748;
    }
    goto skip_0;
    // 0x8005D730: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x8005D734: jal         0x800596C0
    // 0x8005D738: nop

    Object_ApplyWaterDistortion(rdram, ctx);
        goto after_2;
    // 0x8005D738: nop

    after_2:
    // 0x8005D73C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8005D740: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x8005D744: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_8005D748:
    // 0x8005D748: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005D74C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D750: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005D754: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8005D758: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005D75C: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x8005D760: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005D764: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005D768: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005D76C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005D770: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D774: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x8005D778: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x8005D77C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005D780: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005D784: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8005D788: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8005D78C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005D790: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005D794: jal         0x800BA1D0
    // 0x8005D798: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_29(rdram, ctx);
        goto after_3;
    // 0x8005D798: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8005D79C: b           L_8005D8A8
    // 0x8005D7A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005D8A8;
    // 0x8005D7A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D7A4:
    // 0x8005D7A4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005D7A8: bne         $v0, $at, L_8005D7F0
    if (ctx->r2 != ctx->r1) {
        // 0x8005D7AC: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_8005D7F0;
    }
    // 0x8005D7AC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D7B0: bltz        $t9, L_8005D8A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x8005D7B4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8005D8A4;
    }
    // 0x8005D7B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D7B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005D7BC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005D7C0: lw          $t2, -0x7C24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C24);
    // 0x8005D7C4: lw          $t1, -0x7C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7C28);
    // 0x8005D7C8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005D7CC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005D7D0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005D7D4: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005D7D8: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005D7DC: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8005D7E0: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8005D7E4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005D7E8: jal         0x800B9B38
    // 0x8005D7EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    RCP_SetupDL_60(rdram, ctx);
        goto after_4;
    // 0x8005D7EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
L_8005D7F0:
    // 0x8005D7F0: jal         0x800597C0
    // 0x8005D7F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    Object_SetCullDirection(rdram, ctx);
        goto after_5;
    // 0x8005D7F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x8005D7F8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D7FC: bgez        $t3, L_8005D80C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8005D800: nop
    
            goto L_8005D80C;
    }
    // 0x8005D800: nop

    // 0x8005D804: jal         0x800596C0
    // 0x8005D808: nop

    Object_ApplyWaterDistortion(rdram, ctx);
        goto after_6;
    // 0x8005D808: nop

    after_6:
L_8005D80C:
    // 0x8005D80C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8005D810: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x8005D814: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005D818: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005D81C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D820: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005D824: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8005D828: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005D82C: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x8005D830: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005D834: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005D838: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005D83C: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8005D840: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005D844: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005D848: bne         $t7, $at, L_8005D8A4
    if (ctx->r15 != ctx->r1) {
        // 0x8005D84C: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_8005D8A4;
    }
    // 0x8005D84C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D850: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005D854: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x8005D858: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x8005D85C: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8005D860: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8005D864: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005D868: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005D86C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8005D870: jal         0x800BA1D0
    // 0x8005D874: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_29(rdram, ctx);
        goto after_7;
    // 0x8005D874: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_7:
    // 0x8005D878: b           L_8005D8A8
    // 0x8005D87C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005D8A8;
    // 0x8005D87C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D880:
    // 0x8005D880: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x8005D884: beql        $t1, $zero, L_8005D8A8
    if (ctx->r9 == 0) {
        // 0x8005D888: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005D8A8;
    }
    goto skip_1;
    // 0x8005D888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8005D88C: jal         0x800597C0
    // 0x8005D890: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    Object_SetCullDirection(rdram, ctx);
        goto after_8;
    // 0x8005D890: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x8005D894: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8005D898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D89C: jalr        $t9
    // 0x8005D8A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8005D8A0: nop

    after_9:
L_8005D8A4:
    // 0x8005D8A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D8A8:
    // 0x8005D8A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005D8AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005D8B0: jr          $ra
    // 0x8005D8B4: nop

    return;
    // 0x8005D8B4: nop

;}
RECOMP_FUNC void AudioLoad_SyncLoadSimple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FCA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000FCA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FCA8: jal         0x8000F554
    // 0x8000FCAC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    AudioLoad_SyncLoad(rdram, ctx);
        goto after_0;
    // 0x8000FCAC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8000FCB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FCB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000FCB8: jr          $ra
    // 0x8000FCBC: nop

    return;
    // 0x8000FCBC: nop

;}
RECOMP_FUNC void Fault_PrOut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000760C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80007610: jal         0x80023FC0
    // 0x80007614: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80007614: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80007618: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000761C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007620: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80007624: jr          $ra
    // 0x80007628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void AudioLoad_ProcessSlowLoads(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010870: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80010874: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80010878: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001087C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80010880: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80010884: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80010888: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001088C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80010890: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x80010894: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80010898: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x8001089C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800108A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800108A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800108A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800108AC: lw          $s6, 0x5C64($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X5C64);
    // 0x800108B0: addiu       $s7, $s7, 0x6E50
    ctx->r23 = ADD32(ctx->r23, 0X6E50);
    // 0x800108B4: addiu       $s2, $s2, 0x6D90
    ctx->r18 = ADD32(ctx->r18, 0X6D90);
    // 0x800108B8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800108BC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800108C0: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x800108C4: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
L_800108C8:
    // 0x800108C8: beql        $v0, $s3, L_800108FC
    if (ctx->r2 == ctx->r19) {
        // 0x800108CC: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_800108FC;
    }
    goto skip_0;
    // 0x800108CC: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x800108D0: bne         $v0, $s4, L_800109C0
    if (ctx->r2 != ctx->r20) {
        // 0x800108D4: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_800109C0;
    }
    // 0x800108D4: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x800108D8: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800108DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800108E0: jal         0x800205E0
    // 0x800108E4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800108E4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x800108E8: beql        $fp, $zero, L_800108FC
    if (ctx->r30 == 0) {
        // 0x800108EC: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_800108FC;
    }
    goto skip_1;
    // 0x800108EC: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    skip_1:
    // 0x800108F0: b           L_800109C0
    // 0x800108F4: sw          $s5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r21;
        goto L_800109C0;
    // 0x800108F4: sw          $s5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r21;
    // 0x800108F8: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
L_800108FC:
    // 0x800108FC: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x80010900: sw          $s4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r20;
    // 0x80010904: bne         $s1, $zero, L_80010924
    if (ctx->r17 != 0) {
        // 0x80010908: slti        $at, $s1, 0x1000
        ctx->r1 = SIGNED(ctx->r17) < 0X1000 ? 1 : 0;
            goto L_80010924;
    }
    // 0x80010908: slti        $at, $s1, 0x1000
    ctx->r1 = SIGNED(ctx->r17) < 0X1000 ? 1 : 0;
    // 0x8001090C: jal         0x80010808
    // 0x80010910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioLoad_FinishSlowLoad(rdram, ctx);
        goto after_1;
    // 0x80010910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80010914: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80010918: sw          $s5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r21;
    // 0x8001091C: b           L_800109C0
    // 0x80010920: sb          $s3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r19;
        goto L_800109C0;
    // 0x80010920: sb          $s3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r19;
L_80010924:
    // 0x80010924: beql        $at, $zero, L_8001096C
    if (ctx->r1 == 0) {
        // 0x80010928: lbu         $t8, 0x0($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X0);
            goto L_8001096C;
    }
    goto skip_2;
    // 0x80010928: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    skip_2:
    // 0x8001092C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80010930: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80010934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010938: bne         $s3, $t7, L_80010958
    if (ctx->r19 != ctx->r15) {
        // 0x8001093C: nop
    
            goto L_80010958;
    }
    // 0x8001093C: nop

    // 0x80010940: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80010944: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80010948: jal         0x80010A80
    // 0x8001094C: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    AudioLoad_DmaSlowCopyUnkMedium(rdram, ctx);
        goto after_2;
    // 0x8001094C: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    after_2:
    // 0x80010950: b           L_80010960
    // 0x80010954: nop

        goto L_80010960;
    // 0x80010954: nop

L_80010958:
    // 0x80010958: jal         0x800109FC
    // 0x8001095C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    AudioLoad_DmaSlowCopy(rdram, ctx);
        goto after_3;
    // 0x8001095C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80010960:
    // 0x80010960: b           L_800109C0
    // 0x80010964: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
        goto L_800109C0;
    // 0x80010964: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80010968: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
L_8001096C:
    // 0x8001096C: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // 0x80010970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010974: bne         $s3, $t8, L_80010994
    if (ctx->r19 != ctx->r24) {
        // 0x80010978: nop
    
            goto L_80010994;
    }
    // 0x80010978: nop

    // 0x8001097C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80010980: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80010984: jal         0x80010A80
    // 0x80010988: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    AudioLoad_DmaSlowCopyUnkMedium(rdram, ctx);
        goto after_4;
    // 0x80010988: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    after_4:
    // 0x8001098C: b           L_800109A0
    // 0x80010990: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
        goto L_800109A0;
    // 0x80010990: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
L_80010994:
    // 0x80010994: jal         0x800109FC
    // 0x80010998: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    AudioLoad_DmaSlowCopy(rdram, ctx);
        goto after_5;
    // 0x80010998: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_5:
    // 0x8001099C: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
L_800109A0:
    // 0x800109A0: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800109A4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800109A8: addiu       $t0, $t9, -0x1000
    ctx->r8 = ADD32(ctx->r25, -0X1000);
    // 0x800109AC: addiu       $t2, $t1, 0x1000
    ctx->r10 = ADD32(ctx->r9, 0X1000);
    // 0x800109B0: addiu       $t4, $t3, 0x1000
    ctx->r12 = ADD32(ctx->r11, 0X1000);
    // 0x800109B4: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    // 0x800109B8: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800109BC: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
L_800109C0:
    // 0x800109C0: addiu       $s2, $s2, 0x60
    ctx->r18 = ADD32(ctx->r18, 0X60);
    // 0x800109C4: bnel        $s2, $s7, L_800108C8
    if (ctx->r18 != ctx->r23) {
        // 0x800109C8: lw          $v0, 0x14($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X14);
            goto L_800108C8;
    }
    goto skip_3;
    // 0x800109C8: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    skip_3:
    // 0x800109CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800109D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800109D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800109D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800109DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800109E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800109E4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800109E8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800109EC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800109F0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800109F4: jr          $ra
    // 0x800109F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800109F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_tank_8004641C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004641C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80046420: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80046424: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80046428: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8004642C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80046430: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80046434: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80046438: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x8004643C: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80046440: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046444: lwc1        $f8, 0x56E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X56E4);
    // 0x80046448: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8004644C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80046450: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80046454: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80046458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004645C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80046460: jal         0x80005E90
    // 0x80046464: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80046464: nop

    after_0:
    // 0x80046468: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004646C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80046470: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80046474: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x80046478: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004647C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80046480: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80046484: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80046488: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004648C: jal         0x80006A20
    // 0x80046490: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x80046490: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80046494: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80046498: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004649C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800464A0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800464A4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800464A8: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800464AC: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800464B0: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800464B4: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x800464B8: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800464BC: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800464C0: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x800464C4: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800464C8: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800464CC: jal         0x80006A20
    // 0x800464D0: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x800464D0: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800464D4: lwc1        $f14, 0xA0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800464D8: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800464DC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800464E0: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800464E4: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800464E8: add.s       $f0, $f4, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800464EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800464F0: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x800464F4: add.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800464F8: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x800464FC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80046500: add.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80046504: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80046508: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8004650C: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
    // 0x80046510: swc1        $f12, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f12.u32l;
    // 0x80046514: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80046518: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8004651C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80046520: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80046524: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80046528: jal         0x800A8054
    // 0x8004652C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    Play_CheckPolyCollision(rdram, ctx);
        goto after_3;
    // 0x8004652C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_3:
    // 0x80046530: beq         $v0, $zero, L_8004658C
    if (ctx->r2 == 0) {
        // 0x80046534: lwc1        $f10, 0x5C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_8004658C;
    }
    // 0x80046534: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80046538: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8004653C: add.s       $f0, $f20, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x80046540: addiu       $v0, $v0, -0x1DB0
    ctx->r2 = ADD32(ctx->r2, -0X1DB0);
    // 0x80046544: lwc1        $f18, 0x6C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x80046548: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8004654C: nop

    // 0x80046550: bc1fl       L_8004657C
    if (!c1cs) {
        // 0x80046554: lwc1        $f4, 0x58($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
            goto L_8004657C;
    }
    goto skip_0;
    // 0x80046554: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x80046558: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8004655C: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80046560: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80046564: bne         $t8, $at, L_80046578
    if (ctx->r24 != ctx->r1) {
        // 0x80046568: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80046578;
    }
    // 0x80046568: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004656C: sw          $zero, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = 0;
    // 0x80046570: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046574: sb          $t9, -0x60FC($at)
    MEM_B(-0X60FC, ctx->r1) = ctx->r25;
L_80046578:
    // 0x80046578: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
L_8004657C:
    // 0x8004657C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80046580: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
    // 0x80046584: b           L_8004665C
    // 0x80046588: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
        goto L_8004665C;
    // 0x80046588: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
L_8004658C:
    // 0x8004658C: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x80046590: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80046594: bne         $t0, $at, L_8004665C
    if (ctx->r8 != ctx->r1) {
        // 0x80046598: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8004665C;
    }
    // 0x80046598: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8004659C: addiu       $v0, $v0, -0x1DB0
    ctx->r2 = ADD32(ctx->r2, -0X1DB0);
    // 0x800465A0: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x800465A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800465A8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800465AC: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800465B0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800465B4: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800465B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800465BC: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x800465C0: bc1f        L_8004665C
    if (!c1cs) {
        // 0x800465C4: addiu       $t1, $sp, 0x58
        ctx->r9 = ADD32(ctx->r29, 0X58);
            goto L_8004665C;
    }
    // 0x800465C4: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
    // 0x800465C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800465CC: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800465D0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800465D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800465D8: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800465DC: addiu       $t2, $sp, 0x4C
    ctx->r10 = ADD32(ctx->r29, 0X4C);
    // 0x800465E0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800465E4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800465E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800465EC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800465F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800465F4: jal         0x800A8054
    // 0x800465F8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Play_CheckPolyCollision(rdram, ctx);
        goto after_4;
    // 0x800465F8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800465FC: beq         $v0, $zero, L_8004665C
    if (ctx->r2 == 0) {
        // 0x80046600: lwc1        $f0, 0xA8($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0XA8);
            goto L_8004665C;
    }
    // 0x80046600: lwc1        $f0, 0xA8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80046604: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80046608: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004660C: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80046610: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80046614: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80046618: sw          $t3, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r11;
    // 0x8004661C: sw          $t4, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r12;
    // 0x80046620: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80046624: bc1f        L_80046654
    if (!c1cs) {
        // 0x80046628: addiu       $v0, $zero, -0x14
        ctx->r2 = ADD32(0, -0X14);
            goto L_80046654;
    }
    // 0x80046628: addiu       $v0, $zero, -0x14
    ctx->r2 = ADD32(0, -0X14);
    // 0x8004662C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046630: nop

    // 0x80046634: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80046638: nop

    // 0x8004663C: bc1fl       L_80046658
    if (!c1cs) {
        // 0x80046640: sw          $v0, 0x1F0($s0)
        MEM_W(0X1F0, ctx->r16) = ctx->r2;
            goto L_80046658;
    }
    goto skip_1;
    // 0x80046640: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    skip_1:
    // 0x80046644: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80046648: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    // 0x8004664C: b           L_8004665C
    // 0x80046650: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
        goto L_8004665C;
    // 0x80046650: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
L_80046654:
    // 0x80046654: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
L_80046658:
    // 0x80046658: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
L_8004665C:
    // 0x8004665C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80046660: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80046664: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80046668: addiu       $t5, $sp, 0x58
    ctx->r13 = ADD32(ctx->r29, 0X58);
    // 0x8004666C: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x80046670: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80046674: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80046678: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8004667C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80046680: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80046684: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80046688: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8004668C: jal         0x800A8054
    // 0x80046690: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Play_CheckPolyCollision(rdram, ctx);
        goto after_5;
    // 0x80046690: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80046694: beql        $v0, $zero, L_800466F4
    if (ctx->r2 == 0) {
        // 0x80046698: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800466F4;
    }
    goto skip_2;
    // 0x80046698: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x8004669C: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800466A0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800466A4: addiu       $v0, $v0, -0x60F0
    ctx->r2 = ADD32(ctx->r2, -0X60F0);
    // 0x800466A8: add.s       $f0, $f20, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x800466AC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800466B0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800466B4: nop

    // 0x800466B8: bc1fl       L_800466F4
    if (!c1cs) {
        // 0x800466BC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800466F4;
    }
    goto skip_3;
    // 0x800466BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x800466C0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800466C4: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800466C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800466CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800466D0: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x800466D4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800466D8: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800466DC: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
    // 0x800466E0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800466E4: swc1        $f4, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->f4.u32l;
    // 0x800466E8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800466EC: swc1        $f6, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->f6.u32l;
    // 0x800466F0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800466F4:
    // 0x800466F4: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800466F8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800466FC: jr          $ra
    // 0x80046700: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80046700: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void Effect_Effect342_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CD7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CD80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CD84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CD88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CD8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007CD90: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007CD94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007CD98: jal         0x80061474
    // 0x8007CD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007CD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007CDA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007CDA4: addiu       $t7, $zero, 0x156
    ctx->r15 = ADD32(0, 0X156);
    // 0x8007CDA8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007CDAC: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007CDB0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8007CDB4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8007CDB8: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x8007CDBC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007CDC0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007CDC4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CDC8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007CDCC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CDD0: sh          $t9, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r25;
    // 0x8007CDD4: jal         0x80004EB0
    // 0x8007CDD8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007CDD8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8007CDDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007CDE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007CDE4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8007CDE8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8007CDEC: nop

    // 0x8007CDF0: bc1fl       L_8007CE08
    if (!c1cs) {
        // 0x8007CDF4: sh          $t2, 0x4A($s0)
        MEM_H(0X4A, ctx->r16) = ctx->r10;
            goto L_8007CE08;
    }
    goto skip_0;
    // 0x8007CDF4: sh          $t2, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r10;
    skip_0:
    // 0x8007CDF8: lh          $t0, 0x48($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X48);
    // 0x8007CDFC: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8007CE00: sh          $t1, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r9;
    // 0x8007CE04: sh          $t2, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r10;
L_8007CE08:
    // 0x8007CE08: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CE0C: jal         0x80004EB0
    // 0x8007CE10: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007CE10: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    after_2:
    // 0x8007CE14: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007CE18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007CE1C: nop

    // 0x8007CE20: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8007CE24: jal         0x80004EB0
    // 0x8007CE28: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8007CE28: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8007CE2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007CE30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007CE34: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8007CE38: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007CE3C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8007CE40: nop

    // 0x8007CE44: bc1fl       L_8007CE6C
    if (!c1cs) {
        // 0x8007CE48: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_8007CE6C;
    }
    goto skip_1;
    // 0x8007CE48: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8007CE4C: lbu         $t3, 0x7C98($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7C98);
    // 0x8007CE50: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8007CE54: bne         $t3, $zero, L_8007CE68
    if (ctx->r11 != 0) {
        // 0x8007CE58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007CE68;
    }
    // 0x8007CE58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CE5C: beql        $t4, $v0, L_8007CE6C
    if (ctx->r12 == ctx->r2) {
        // 0x8007CE60: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_8007CE6C;
    }
    goto skip_2;
    // 0x8007CE60: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x8007CE64: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
L_8007CE68:
    // 0x8007CE68: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_8007CE6C:
    // 0x8007CE6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007CE70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CE74: bne         $t5, $at, L_8007CE80
    if (ctx->r13 != ctx->r1) {
        // 0x8007CE78: nop
    
            goto L_8007CE80;
    }
    // 0x8007CE78: nop

    // 0x8007CE7C: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
L_8007CE80:
    // 0x8007CE80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007CE84: lwc1        $f10, 0x7430($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7430);
    // 0x8007CE88: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CE8C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8007CE90: nop

    // 0x8007CE94: bc1f        L_8007CEA0
    if (!c1cs) {
        // 0x8007CE98: nop
    
            goto L_8007CEA0;
    }
    // 0x8007CE98: nop

    // 0x8007CE9C: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
L_8007CEA0:
    // 0x8007CEA0: jal         0x800612B8
    // 0x8007CEA4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x8007CEA4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_4:
    // 0x8007CEA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CEAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CEB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CEB4: jr          $ra
    // 0x8007CEB8: nop

    return;
    // 0x8007CEB8: nop

;}
RECOMP_FUNC void Effect_Effect387_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C60C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007C610: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007C614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007C61C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007C620: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007C624: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007C628: jal         0x80061474
    // 0x8007C62C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007C62C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007C630: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007C634: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C638: addiu       $t7, $zero, 0x183
    ctx->r15 = ADD32(0, 0X183);
    // 0x8007C63C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007C640: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007C644: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007C648: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007C64C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007C650: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007C654: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007C658: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007C65C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007C660: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007C664: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007C668: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    // 0x8007C66C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C670: jal         0x800612B8
    // 0x8007C674: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007C674: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    after_1:
    // 0x8007C678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C67C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C680: jr          $ra
    // 0x8007C684: nop

    return;
    // 0x8007C684: nop

;}
RECOMP_FUNC void PlayerShot_Effect344_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003652C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80036530: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80036534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036538: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003653C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80036540: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80036544: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80036548: jal         0x80061474
    // 0x8003654C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8003654C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80036550: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80036554: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80036558: addiu       $t7, $zero, 0x158
    ctx->r15 = ADD32(0, 0X158);
    // 0x8003655C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80036560: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80036564: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80036568: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003656C: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80036570: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80036574: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80036578: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003657C: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80036580: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80036584: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80036588: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8003658C: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80036590: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80036594: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x80036598: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003659C: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x800365A0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800365A4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800365A8: swc1        $f6, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f6.u32l;
    // 0x800365AC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800365B0: sh          $t9, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r25;
    // 0x800365B4: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x800365B8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800365BC: jal         0x800612B8
    // 0x800365C0: sh          $t0, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r8;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800365C0: sh          $t0, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r8;
    after_1:
    // 0x800365C4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800365C8: lui         $a1, 0x2900
    ctx->r5 = S32(0X2900 << 16);
    // 0x800365CC: jal         0x800A6070
    // 0x800365D0: addiu       $a0, $a2, 0x80
    ctx->r4 = ADD32(ctx->r6, 0X80);
    Play_PlaySfxNoPlayer(rdram, ctx);
        goto after_2;
    // 0x800365D0: addiu       $a0, $a2, 0x80
    ctx->r4 = ADD32(ctx->r6, 0X80);
    after_2:
    // 0x800365D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800365D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800365DC: jr          $ra
    // 0x800365E0: nop

    return;
    // 0x800365E0: nop

;}
RECOMP_FUNC void Player_TankCannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACA40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ACA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACA48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800ACA4C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800ACA50: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800ACA54: addiu       $v0, $v0, 0x46E0
    ctx->r2 = ADD32(ctx->r2, 0X46E0);
    // 0x800ACA58: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x800ACA5C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
L_800ACA60:
    // 0x800ACA60: bnel        $t6, $zero, L_800ACAA4
    if (ctx->r14 != 0) {
        // 0x800ACA64: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_800ACAA4;
    }
    goto skip_0;
    // 0x800ACA64: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    skip_0:
    // 0x800ACA68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800ACA6C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x800ACA70: jal         0x800AC650
    // 0x800ACA74: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    Player_SetupTankShot(rdram, ctx);
        goto after_0;
    // 0x800ACA74: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_0:
    // 0x800ACA78: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800ACA7C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800ACA80: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x800ACA84: addiu       $a0, $v0, 0x460
    ctx->r4 = ADD32(ctx->r2, 0X460);
    // 0x800ACA88: jal         0x800A5FA0
    // 0x800ACA8C: lw          $a2, 0x1C4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800ACA8C: lw          $a2, 0x1C4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C4);
    after_1:
    // 0x800ACA90: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800ACA94: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800ACA98: b           L_800ACAAC
    // 0x800ACA9C: sw          $t7, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->r15;
        goto L_800ACAAC;
    // 0x800ACA9C: sw          $t7, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->r15;
    // 0x800ACAA0: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
L_800ACAA4:
    // 0x800ACAA4: bnel        $a1, $v0, L_800ACA60
    if (ctx->r5 != ctx->r2) {
        // 0x800ACAA8: lbu         $t6, 0x0($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X0);
            goto L_800ACA60;
    }
    goto skip_1;
    // 0x800ACAA8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    skip_1:
L_800ACAAC:
    // 0x800ACAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACAB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ACAB4: jr          $ra
    // 0x800ACAB8: nop

    return;
    // 0x800ACAB8: nop

;}
RECOMP_FUNC void Player_ArwingLaser(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACABC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800ACAC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800ACAC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800ACAC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ACACC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x800ACAD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACAD4: lwc1        $f6, 0x4B0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4B0);
    // 0x800ACAD8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800ACADC: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x800ACAE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800ACAE4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800ACAE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ACAEC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800ACAF0: bc1f        L_800ACAFC
    if (!c1cs) {
        // 0x800ACAF4: lw          $v1, 0x1AA8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X1AA8);
            goto L_800ACAFC;
    }
    // 0x800ACAF4: lw          $v1, 0x1AA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1AA8);
    // 0x800ACAF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800ACAFC:
    // 0x800ACAFC: beq         $v1, $zero, L_800ACB24
    if (ctx->r3 == 0) {
        // 0x800ACB00: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_800ACB24;
    }
    // 0x800ACB00: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800ACB04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800ACB08: beq         $v1, $at, L_800ACBA4
    if (ctx->r3 == ctx->r1) {
        // 0x800ACB0C: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_800ACBA4;
    }
    // 0x800ACB0C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800ACB10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ACB14: beq         $v1, $at, L_800ACBA4
    if (ctx->r3 == ctx->r1) {
        // 0x800ACB18: nop
    
            goto L_800ACBA4;
    }
    // 0x800ACB18: nop

    // 0x800ACB1C: b           L_800ACC6C
    // 0x800ACB20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800ACC6C;
    // 0x800ACB20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ACB24:
    // 0x800ACB24: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800ACB28: addiu       $v0, $v0, 0x46E0
    ctx->r2 = ADD32(ctx->r2, 0X46E0);
    // 0x800ACB2C: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x800ACB30: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
L_800ACB34:
    // 0x800ACB34: bnel        $t8, $zero, L_800ACB94
    if (ctx->r24 != 0) {
        // 0x800ACB38: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_800ACB94;
    }
    goto skip_0;
    // 0x800ACB38: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    skip_0:
    // 0x800ACB3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ACB40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACB44: lwc1        $f8, -0x79C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X79C8);
    // 0x800ACB48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800ACB4C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800ACB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ACB54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800ACB58: jal         0x800AC290
    // 0x800ACB5C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_0;
    // 0x800ACB5C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800ACB60: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800ACB64: lui         $a1, 0x940
    ctx->r5 = S32(0X940 << 16);
    // 0x800ACB68: jal         0x800A5FA0
    // 0x800ACB6C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800ACB6C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_1:
    // 0x800ACB70: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800ACB74: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800ACB78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ACB7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ACB80: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800ACB84: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800ACB88: b           L_800ACC68
    // 0x800ACB8C: swc1        $f10, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->f10.u32l;
        goto L_800ACC68;
    // 0x800ACB8C: swc1        $f10, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->f10.u32l;
    // 0x800ACB90: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
L_800ACB94:
    // 0x800ACB94: bnel        $a1, $v0, L_800ACB34
    if (ctx->r5 != ctx->r2) {
        // 0x800ACB98: lbu         $t8, 0x0($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X0);
            goto L_800ACB34;
    }
    goto skip_1;
    // 0x800ACB98: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    skip_1:
    // 0x800ACB9C: b           L_800ACC6C
    // 0x800ACBA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800ACC6C;
    // 0x800ACBA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ACBA4:
    // 0x800ACBA4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800ACBA8: addiu       $v0, $v0, 0x46E0
    ctx->r2 = ADD32(ctx->r2, 0X46E0);
    // 0x800ACBAC: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x800ACBB0: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
L_800ACBB4:
    // 0x800ACBB4: bnel        $t1, $zero, L_800ACC60
    if (ctx->r9 != 0) {
        // 0x800ACBB8: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_800ACC60;
    }
    goto skip_2;
    // 0x800ACBB8: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    skip_2:
    // 0x800ACBBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ACBC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACBC4: lwc1        $f16, -0x79C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X79C4);
    // 0x800ACBC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ACBCC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800ACBD0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800ACBD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ACBD8: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    // 0x800ACBDC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800ACBE0: jal         0x800AC290
    // 0x800ACBE4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_2;
    // 0x800ACBE4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800ACBE8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800ACBEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800ACBF0: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800ACBF4: bne         $v1, $at, L_800ACC30
    if (ctx->r3 != ctx->r1) {
        // 0x800ACBF8: lui         $a1, 0x940
        ctx->r5 = S32(0X940 << 16);
            goto L_800ACC30;
    }
    // 0x800ACBF8: lui         $a1, 0x940
    ctx->r5 = S32(0X940 << 16);
    // 0x800ACBFC: lui         $a1, 0x940
    ctx->r5 = S32(0X940 << 16);
    // 0x800ACC00: ori         $a1, $a1, 0x800C
    ctx->r5 = ctx->r5 | 0X800C;
    // 0x800ACC04: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800ACC08: jal         0x800A5FA0
    // 0x800ACC0C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800ACC0C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_3:
    // 0x800ACC10: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x800ACC14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800ACC18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ACC1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ACC20: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800ACC24: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800ACC28: b           L_800ACC68
    // 0x800ACC2C: swc1        $f18, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->f18.u32l;
        goto L_800ACC68;
    // 0x800ACC2C: swc1        $f18, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->f18.u32l;
L_800ACC30:
    // 0x800ACC30: ori         $a1, $a1, 0x802B
    ctx->r5 = ctx->r5 | 0X802B;
    // 0x800ACC34: jal         0x800A5FA0
    // 0x800ACC38: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x800ACC38: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_4:
    // 0x800ACC3C: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800ACC40: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800ACC44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACC48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ACC4C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800ACC50: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800ACC54: b           L_800ACC68
    // 0x800ACC58: swc1        $f4, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->f4.u32l;
        goto L_800ACC68;
    // 0x800ACC58: swc1        $f4, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->f4.u32l;
    // 0x800ACC5C: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
L_800ACC60:
    // 0x800ACC60: bnel        $a1, $v0, L_800ACBB4
    if (ctx->r5 != ctx->r2) {
        // 0x800ACC64: lbu         $t1, 0x0($a1)
        ctx->r9 = MEM_BU(ctx->r5, 0X0);
            goto L_800ACBB4;
    }
    goto skip_3;
    // 0x800ACC64: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    skip_3:
L_800ACC68:
    // 0x800ACC68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ACC6C:
    // 0x800ACC6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ACC70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800ACC74: jr          $ra
    // 0x800ACC78: nop

    return;
    // 0x800ACC78: nop

;}
RECOMP_FUNC void Player_CheckAllGoldRings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6A74: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800A6A78: addiu       $v1, $v1, 0x1A90
    ctx->r3 = ADD32(ctx->r3, 0X1A90);
    // 0x800A6A7C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800A6A80: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A6A84: beq         $t6, $zero, L_800A6AB8
    if (ctx->r14 == 0) {
        // 0x800A6A88: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800A6AB8;
    }
    // 0x800A6A88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A6A8C: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800A6A90: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A6A94: beq         $t7, $zero, L_800A6AB8
    if (ctx->r15 == 0) {
        // 0x800A6A98: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800A6AB8;
    }
    // 0x800A6A98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800A6A9C: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x800A6AA0: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A6AA4: beq         $t8, $zero, L_800A6AB8
    if (ctx->r24 == 0) {
        // 0x800A6AA8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800A6AB8;
    }
    // 0x800A6AA8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800A6AAC: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800A6AB0: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A6AB4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800A6AB8:
    // 0x800A6AB8: jr          $ra
    // 0x800A6ABC: nop

    return;
    // 0x800A6ABC: nop

;}
RECOMP_FUNC void Effect_FireSmoke2_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CF9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CFA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CFA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007CFA8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007CFAC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007CFB0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007CFB4: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007CFB8: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007CFBC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007CFC0:
    // 0x8007CFC0: bnel        $t6, $zero, L_8007CFEC
    if (ctx->r14 != 0) {
        // 0x8007CFC4: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007CFEC;
    }
    goto skip_0;
    // 0x8007CFC4: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007CFC8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CFCC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007CFD0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007CFD4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007CFD8: jal         0x8007CCBC
    // 0x8007CFDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_FireSmoke2_Setup(rdram, ctx);
        goto after_0;
    // 0x8007CFDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007CFE0: b           L_8007CFFC
    // 0x8007CFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007CFFC;
    // 0x8007CFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CFE8: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007CFEC:
    // 0x8007CFEC: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007CFF0: beql        $at, $zero, L_8007CFC0
    if (ctx->r1 == 0) {
        // 0x8007CFF4: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007CFC0;
    }
    goto skip_1;
    // 0x8007CFF4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007CFF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007CFFC:
    // 0x8007CFFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007D000: jr          $ra
    // 0x8007D004: nop

    return;
    // 0x8007D004: nop

;}
RECOMP_FUNC void HUD_DrawCountdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E51C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E524: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008E528: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008E52C: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
    // 0x8008E530: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x8008E534: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8008E538: beq         $v1, $v0, L_8008E5BC
    if (ctx->r3 == ctx->r2) {
        // 0x8008E53C: nop
    
            goto L_8008E5BC;
    }
    // 0x8008E53C: nop

    // 0x8008E540: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8008E544: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008E548: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x8008E54C: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8008E550: bne         $at, $zero, L_8008E560
    if (ctx->r1 != 0) {
        // 0x8008E554: sw          $t7, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r15;
            goto L_8008E560;
    }
    // 0x8008E554: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8008E558: b           L_8008E5BC
    // 0x8008E55C: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
        goto L_8008E5BC;
    // 0x8008E55C: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
L_8008E560:
    // 0x8008E560: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8008E564: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x8008E568: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8008E56C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8008E570: bltz        $t1, L_8008E584
    if (SIGNED(ctx->r9) < 0) {
        // 0x8008E574: sw          $t1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r9;
            goto L_8008E584;
    }
    // 0x8008E574: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8008E578: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008E57C: b           L_8008E5BC
    // 0x8008E580: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
        goto L_8008E5BC;
    // 0x8008E580: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
L_8008E584:
    // 0x8008E584: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8008E588: addiu       $t3, $zero, 0x3B
    ctx->r11 = ADD32(0, 0X3B);
    // 0x8008E58C: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8008E590: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8008E594: bltz        $t5, L_8008E5A8
    if (SIGNED(ctx->r13) < 0) {
        // 0x8008E598: sw          $t5, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r13;
            goto L_8008E5A8;
    }
    // 0x8008E598: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8008E59C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008E5A0: b           L_8008E5BC
    // 0x8008E5A4: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
        goto L_8008E5BC;
    // 0x8008E5A4: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
L_8008E5A8:
    // 0x8008E5A8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8008E5AC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8008E5B0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8008E5B4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008E5B8: lw          $v0, 0x7854($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7854);
L_8008E5BC:
    // 0x8008E5BC: beq         $v1, $v0, L_8008E5D8
    if (ctx->r3 == ctx->r2) {
        // 0x8008E5C0: lui         $at, 0x4330
        ctx->r1 = S32(0X4330 << 16);
            goto L_8008E5D8;
    }
    // 0x8008E5C0: lui         $at, 0x4330
    ctx->r1 = S32(0X4330 << 16);
    // 0x8008E5C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008E5C8: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8008E5CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008E5D0: jal         0x8008E2C8
    // 0x8008E5D4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    HUD_DisplayCountdown(rdram, ctx);
        goto after_0;
    // 0x8008E5D4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    after_0:
L_8008E5D8:
    // 0x8008E5D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E5DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E5E0: jr          $ra
    // 0x8008E5E4: nop

    return;
    // 0x8008E5E4: nop

;}
RECOMP_FUNC void HUD_RadarMark_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80089E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80089EA0: slti        $at, $a0, 0x67
    ctx->r1 = SIGNED(ctx->r4) < 0X67 ? 1 : 0;
    // 0x80089EA4: bne         $at, $zero, L_80089ED8
    if (ctx->r1 != 0) {
        // 0x80089EA8: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_80089ED8;
    }
    // 0x80089EA8: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80089EAC: beq         $a0, $at, L_8008A024
    if (ctx->r4 == ctx->r1) {
        // 0x80089EB0: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8008A024;
    }
    // 0x80089EB0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80089EB4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80089EB8: beq         $a0, $at, L_8008A054
    if (ctx->r4 == ctx->r1) {
        // 0x80089EBC: addiu       $at, $zero, 0xC9
        ctx->r1 = ADD32(0, 0XC9);
            goto L_8008A054;
    }
    // 0x80089EBC: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80089EC0: beq         $a0, $at, L_8008A054
    if (ctx->r4 == ctx->r1) {
        // 0x80089EC4: addiu       $at, $zero, 0x3E7
        ctx->r1 = ADD32(0, 0X3E7);
            goto L_8008A054;
    }
    // 0x80089EC4: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80089EC8: beql        $a0, $at, L_8008A070
    if (ctx->r4 == ctx->r1) {
        // 0x80089ECC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008A070;
    }
    goto skip_0;
    // 0x80089ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80089ED0: b           L_8008A064
    // 0x80089ED4: nop

        goto L_8008A064;
    // 0x80089ED4: nop

L_80089ED8:
    // 0x80089ED8: slti        $at, $a0, 0x65
    ctx->r1 = SIGNED(ctx->r4) < 0X65 ? 1 : 0;
    // 0x80089EDC: bne         $at, $zero, L_80089EFC
    if (ctx->r1 != 0) {
        // 0x80089EE0: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_80089EFC;
    }
    // 0x80089EE0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80089EE4: beq         $a0, $at, L_8008A004
    if (ctx->r4 == ctx->r1) {
        // 0x80089EE8: addiu       $at, $zero, 0x66
        ctx->r1 = ADD32(0, 0X66);
            goto L_8008A004;
    }
    // 0x80089EE8: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80089EEC: beq         $a0, $at, L_8008A014
    if (ctx->r4 == ctx->r1) {
        // 0x80089EF0: nop
    
            goto L_8008A014;
    }
    // 0x80089EF0: nop

    // 0x80089EF4: b           L_8008A064
    // 0x80089EF8: nop

        goto L_8008A064;
    // 0x80089EF8: nop

L_80089EFC:
    // 0x80089EFC: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x80089F00: bne         $at, $zero, L_80089F18
    if (ctx->r1 != 0) {
        // 0x80089F04: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80089F18;
    }
    // 0x80089F04: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80089F08: beq         $a0, $at, L_80089FF4
    if (ctx->r4 == ctx->r1) {
        // 0x80089F0C: nop
    
            goto L_80089FF4;
    }
    // 0x80089F0C: nop

    // 0x80089F10: b           L_8008A064
    // 0x80089F14: nop

        goto L_8008A064;
    // 0x80089F14: nop

L_80089F18:
    // 0x80089F18: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    // 0x80089F1C: beq         $at, $zero, L_8008A064
    if (ctx->r1 == 0) {
        // 0x80089F20: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8008A064;
    }
    // 0x80089F20: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80089F24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80089F28: addu        $at, $at, $t6
    gpr jr_addend_80089F30 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80089F2C: lw          $t6, 0x7928($at)
    ctx->r14 = ADD32(ctx->r1, 0X7928);
    // 0x80089F30: jr          $t6
    // 0x80089F34: nop

    switch (jr_addend_80089F30 >> 2) {
        case 0: goto L_80089F38; break;
        case 1: goto L_80089F38; break;
        case 2: goto L_80089F38; break;
        case 3: goto L_80089F38; break;
        case 4: goto L_80089FD4; break;
        case 5: goto L_80089FD4; break;
        case 6: goto L_80089FD4; break;
        case 7: goto L_80089FD4; break;
        case 8: goto L_80089FE4; break;
        default: switch_error(__func__, 0x80089F30, 0x800D7928);
    }
    // 0x80089F34: nop

L_80089F38:
    // 0x80089F38: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80089F3C: lw          $t7, 0x78A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A8);
    // 0x80089F40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80089F44: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80089F48: beq         $v0, $t7, L_80089F8C
    if (ctx->r2 == ctx->r15) {
        // 0x80089F4C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80089F8C;
    }
    // 0x80089F4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80089F50: bne         $a0, $v0, L_80089F5C
    if (ctx->r4 != ctx->r2) {
        // 0x80089F54: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_80089F5C;
    }
    // 0x80089F54: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80089F58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80089F5C:
    // 0x80089F5C: bne         $a0, $at, L_80089F68
    if (ctx->r4 != ctx->r1) {
        // 0x80089F60: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80089F68;
    }
    // 0x80089F60: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80089F64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80089F68:
    // 0x80089F68: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80089F6C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80089F70: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80089F74: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80089F78: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80089F7C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80089F80: lw          $t1, 0x1C8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C8);
    // 0x80089F84: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80089F88: beq         $t1, $at, L_8008A06C
    if (ctx->r9 == ctx->r1) {
        // 0x80089F8C: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8008A06C;
    }
L_80089F8C:
    // 0x80089F8C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80089F90: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x80089F94: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80089F98: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80089F9C: bnel        $a0, $t2, L_80089FC4
    if (ctx->r4 != ctx->r10) {
        // 0x80089FA0: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80089FC4;
    }
    goto skip_1;
    // 0x80089FA0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    skip_1:
    // 0x80089FA4: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x80089FA8: sll         $t5, $a1, 1
    ctx->r13 = S32(ctx->r5 << 1);
    // 0x80089FAC: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80089FB0: beql        $t4, $zero, L_80089FC4
    if (ctx->r12 == 0) {
        // 0x80089FB4: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80089FC4;
    }
    goto skip_2;
    // 0x80089FB4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    skip_2:
    // 0x80089FB8: b           L_80089FC4
    // 0x80089FBC: addiu       $a1, $t5, 0x1
    ctx->r5 = ADD32(ctx->r13, 0X1);
        goto L_80089FC4;
    // 0x80089FBC: addiu       $a1, $t5, 0x1
    ctx->r5 = ADD32(ctx->r13, 0X1);
    // 0x80089FC0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_80089FC4:
    // 0x80089FC4: jal         0x80089994
    // 0x80089FC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    HUD_RadarMark_Arwing_Draw(rdram, ctx);
        goto after_0;
    // 0x80089FC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80089FCC: b           L_8008A070
    // 0x80089FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x80089FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089FD4:
    // 0x80089FD4: jal         0x80089AF4
    // 0x80089FD8: nop

    HUD_RadarMark_StarWolf_Draw(rdram, ctx);
        goto after_1;
    // 0x80089FD8: nop

    after_1:
    // 0x80089FDC: b           L_8008A070
    // 0x80089FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x80089FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089FE4:
    // 0x80089FE4: jal         0x80089B94
    // 0x80089FE8: nop

    HUD_RadarMark_Katt_Draw(rdram, ctx);
        goto after_2;
    // 0x80089FE8: nop

    after_2:
    // 0x80089FEC: b           L_8008A070
    // 0x80089FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x80089FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089FF4:
    // 0x80089FF4: jal         0x800898F0
    // 0x80089FF8: nop

    HUD_RadarMark_Missile_Draw(rdram, ctx);
        goto after_3;
    // 0x80089FF8: nop

    after_3:
    // 0x80089FFC: b           L_8008A070
    // 0x8008A000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x8008A000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A004:
    // 0x8008A004: jal         0x80089850
    // 0x8008A008: nop

    HUD_RadarMark_KaSaucerer_Draw(rdram, ctx);
        goto after_4;
    // 0x8008A008: nop

    after_4:
    // 0x8008A00C: b           L_8008A070
    // 0x8008A010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x8008A010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A014:
    // 0x8008A014: jal         0x800897B0
    // 0x8008A018: nop

    HUD_RadarMark_Boss_Draw(rdram, ctx);
        goto after_5;
    // 0x8008A018: nop

    after_5:
    // 0x8008A01C: b           L_8008A070
    // 0x8008A020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x8008A020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A024:
    // 0x8008A024: lw          $t7, 0x78E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78E8);
    // 0x8008A028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008A02C: bne         $v0, $t7, L_8008A044
    if (ctx->r2 != ctx->r15) {
        // 0x8008A030: nop
    
            goto L_8008A044;
    }
    // 0x8008A030: nop

    // 0x8008A034: jal         0x80089670
    // 0x8008A038: nop

    HUD_RadarMark_Item_Draw(rdram, ctx);
        goto after_6;
    // 0x8008A038: nop

    after_6:
    // 0x8008A03C: b           L_8008A070
    // 0x8008A040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x8008A040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A044:
    // 0x8008A044: jal         0x80089C38
    // 0x8008A048: nop

    HUD_RadarMark_Supplies_Draw(rdram, ctx);
        goto after_7;
    // 0x8008A048: nop

    after_7:
    // 0x8008A04C: b           L_8008A070
    // 0x8008A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x8008A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A054:
    // 0x8008A054: jal         0x80089670
    // 0x8008A058: nop

    HUD_RadarMark_Item_Draw(rdram, ctx);
        goto after_8;
    // 0x8008A058: nop

    after_8:
    // 0x8008A05C: b           L_8008A070
    // 0x8008A060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A070;
    // 0x8008A060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A064:
    // 0x8008A064: jal         0x80089710
    // 0x8008A068: nop

    HUD_RadarMark_Enemy_Draw(rdram, ctx);
        goto after_9;
    // 0x8008A068: nop

    after_9:
L_8008A06C:
    // 0x8008A06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A070:
    // 0x8008A070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A074: jr          $ra
    // 0x8008A078: nop

    return;
    // 0x8008A078: nop

;}
RECOMP_FUNC void HUD_Shield_GoldRings_Score(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E9EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E9F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E9F4: jal         0x8008E620
    // 0x8008E9F8: nop

    HUD_Score_Update(rdram, ctx);
        goto after_0;
    // 0x8008E9F8: nop

    after_0:
    // 0x8008E9FC: jal         0x8008B734
    // 0x8008EA00: nop

    HUD_PlayerShield_GoldRings(rdram, ctx);
        goto after_1;
    // 0x8008EA00: nop

    after_1:
    // 0x8008EA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008EA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008EA0C: jr          $ra
    // 0x8008EA10: nop

    return;
    // 0x8008EA10: nop

;}
RECOMP_FUNC void Versus_UpdateMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0C8C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0C90: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0C94: addiu       $a1, $a1, -0x2768
    ctx->r5 = ADD32(ctx->r5, -0X2768);
    // 0x800C0C98: addiu       $v1, $v1, -0x2750
    ctx->r3 = ADD32(ctx->r3, -0X2750);
    // 0x800C0C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0CA0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800C0CA4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800C0CA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800C0CAC:
    // 0x800C0CAC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800C0CB0: bnel        $a0, $t6, L_800C0CEC
    if (ctx->r4 != ctx->r14) {
        // 0x800C0CB4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0CEC;
    }
    goto skip_0;
    // 0x800C0CB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800C0CB8: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0CBC: mflo        $t7
    ctx->r15 = lo;
    // 0x800C0CC0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800C0CC4: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800C0CC8: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800C0CCC: beq         $t0, $zero, L_800C0CE8
    if (ctx->r8 == 0) {
        // 0x800C0CD0: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_800C0CE8;
    }
    // 0x800C0CD0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800C0CD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C0CD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C0CE0: b           L_800C0D00
    // 0x800C0CE4: swc1        $f4, -0x7854($at)
    MEM_W(-0X7854, ctx->r1) = ctx->f4.u32l;
        goto L_800C0D00;
    // 0x800C0CE4: swc1        $f4, -0x7854($at)
    MEM_W(-0X7854, ctx->r1) = ctx->f4.u32l;
L_800C0CE8:
    // 0x800C0CE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C0CEC:
    // 0x800C0CEC: bne         $v0, $a3, L_800C0CAC
    if (ctx->r2 != ctx->r7) {
        // 0x800C0CF0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800C0CAC;
    }
    // 0x800C0CF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C0CF4: jal         0x800C0A04
    // 0x800C0CF8: nop

    Versus_UpdateMenuOptions(rdram, ctx);
        goto after_0;
    // 0x800C0CF8: nop

    after_0:
    // 0x800C0CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0D00:
    // 0x800C0D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0D08: jr          $ra
    // 0x800C0D0C: nop

    return;
    // 0x800C0D0C: nop

;}
