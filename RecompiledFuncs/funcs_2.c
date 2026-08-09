#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Audio_InitBombSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CB80: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8001CB84: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001CB88: lw          $t7, 0x5D40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D40);
    // 0x8001CB8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001CB90: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x8001CB94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001CB98: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8001CB9C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001CBA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CBA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001CBA8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001CBAC: beq         $t6, $zero, L_8001CC24
    if (ctx->r14 == 0) {
        // 0x8001CBB0: sw          $t7, -0x45D8($at)
        MEM_W(-0X45D8, ctx->r1) = ctx->r15;
            goto L_8001CC24;
    }
    // 0x8001CBB0: sw          $t7, -0x45D8($at)
    MEM_W(-0X45D8, ctx->r1) = ctx->r15;
    // 0x8001CBB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CBB8: beq         $t6, $at, L_8001CBD4
    if (ctx->r14 == ctx->r1) {
        // 0x8001CBBC: lui         $t8, 0x8015
        ctx->r24 = S32(0X8015 << 16);
            goto L_8001CBD4;
    }
    // 0x8001CBBC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001CBC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001CBC4: beq         $t6, $at, L_8001CBFC
    if (ctx->r14 == ctx->r1) {
        // 0x8001CBC8: lui         $t0, 0x8015
        ctx->r8 = S32(0X8015 << 16);
            goto L_8001CBFC;
    }
    // 0x8001CBC8: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001CBCC: b           L_8001CC28
    // 0x8001CBD0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
        goto L_8001CC28;
    // 0x8001CBD0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
L_8001CBD4:
    // 0x8001CBD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001CBD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001CBDC: addiu       $t8, $t8, -0x45F0
    ctx->r24 = ADD32(ctx->r24, -0X45F0);
    // 0x8001CBE0: addu        $a3, $v1, $t8
    ctx->r7 = ADD32(ctx->r3, ctx->r24);
    // 0x8001CBE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001CBE8: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8001CBEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001CBF0: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8001CBF4: b           L_8001CC48
    // 0x8001CBF8: sb          $t9, -0x45E0($at)
    MEM_B(-0X45E0, ctx->r1) = ctx->r25;
        goto L_8001CC48;
    // 0x8001CBF8: sb          $t9, -0x45E0($at)
    MEM_B(-0X45E0, ctx->r1) = ctx->r25;
L_8001CBFC:
    // 0x8001CBFC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001CC00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001CC04: addiu       $t0, $t0, -0x45F0
    ctx->r8 = ADD32(ctx->r8, -0X45F0);
    // 0x8001CC08: addu        $a3, $v1, $t0
    ctx->r7 = ADD32(ctx->r3, ctx->r8);
    // 0x8001CC0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001CC10: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8001CC14: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8001CC18: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8001CC1C: b           L_8001CC48
    // 0x8001CC20: sb          $t1, -0x45E0($at)
    MEM_B(-0X45E0, ctx->r1) = ctx->r9;
        goto L_8001CC48;
    // 0x8001CC20: sb          $t1, -0x45E0($at)
    MEM_B(-0X45E0, ctx->r1) = ctx->r9;
L_8001CC24:
    // 0x8001CC24: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
L_8001CC28:
    // 0x8001CC28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001CC2C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001CC30: addiu       $t2, $t2, -0x45F0
    ctx->r10 = ADD32(ctx->r10, -0X45F0);
    // 0x8001CC34: addu        $a3, $v1, $t2
    ctx->r7 = ADD32(ctx->r3, ctx->r10);
    // 0x8001CC38: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001CC3C: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8001CC40: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8001CC44: sb          $zero, -0x45E0($at)
    MEM_B(-0X45E0, ctx->r1) = 0;
L_8001CC48:
    // 0x8001CC48: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001CC4C: addiu       $t3, $t3, -0x45DC
    ctx->r11 = ADD32(ctx->r11, -0X45DC);
    // 0x8001CC50: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x8001CC54: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8001CC58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CC5C: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8001CC60: beq         $t4, $at, L_8001CCCC
    if (ctx->r12 == ctx->r1) {
        // 0x8001CC64: ori         $a0, $a0, 0x8008
        ctx->r4 = ctx->r4 | 0X8008;
            goto L_8001CCCC;
    }
    // 0x8001CC64: ori         $a0, $a0, 0x8008
    ctx->r4 = ctx->r4 | 0X8008;
    // 0x8001CC68: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8001CC6C: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x8001CC70: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001CC74: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8001CC78: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001CC7C: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8001CC80: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x8001CC84: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8001CC88: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8001CC8C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8001CC90: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001CC94: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001CC98: lw          $a1, 0x47C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X47C);
    // 0x8001CC9C: addiu       $t1, $t1, -0x47B0
    ctx->r9 = ADD32(ctx->r9, -0X47B0);
    // 0x8001CCA0: addiu       $t0, $t9, 0x6D
    ctx->r8 = ADD32(ctx->r25, 0X6D);
    // 0x8001CCA4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001CCA8: addiu       $t8, $t8, 0x5D34
    ctx->r24 = ADD32(ctx->r24, 0X5D34);
    // 0x8001CCAC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001CCB0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8001CCB4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001CCB8: jal         0x80019218
    // 0x8001CCBC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001CCBC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001CCC0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8001CCC4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001CCC8: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_8001CCCC:
    // 0x8001CCCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CCD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001CCD4: jr          $ra
    // 0x8001CCD8: nop

    return;
    // 0x8001CCD8: nop

;}
RECOMP_FUNC void Animation_GetFrameCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ACDC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8009ACE0: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8009ACE4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009ACE8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009ACEC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8009ACF0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8009ACF4: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x8009ACF8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8009ACFC: and         $t0, $a0, $at
    ctx->r8 = ctx->r4 & ctx->r1;
    // 0x8009AD00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009AD04: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8009AD08: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8009AD0C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8009AD10: jr          $ra
    // 0x8009AD14: nop

    return;
    // 0x8009AD14: nop

;}
RECOMP_FUNC void ActorEvent_SetupEffect365(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800722EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800722F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800722F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800722F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800722FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80072300: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80072304: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80072308: jal         0x80061474
    // 0x8007230C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007230C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80072310: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072314: lwc1        $f4, 0x6D9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D9C);
    // 0x80072318: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007231C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072320: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072324: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80072328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007232C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80072330: jal         0x80005E90
    // 0x80072334: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80072334: nop

    after_1:
    // 0x80072338: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007233C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80072340: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80072344: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072348: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007234C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80072350: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80072354: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80072358: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8007235C: jal         0x80006970
    // 0x80072360: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80072360: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80072364: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80072368: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007236C: addiu       $t7, $zero, 0x16D
    ctx->r15 = ADD32(0, 0X16D);
    // 0x80072370: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80072374: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80072378: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x8007237C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80072380: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80072384: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80072388: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8007238C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80072390: addiu       $t8, $zero, 0xFA
    ctx->r24 = ADD32(0, 0XFA);
    // 0x80072394: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80072398: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007239C: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x800723A0: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x800723A4: jal         0x80004EB0
    // 0x800723A8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x800723A8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x800723AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800723B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800723B4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800723B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800723BC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800723C0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800723C4: jal         0x80004EB0
    // 0x800723C8: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x800723C8: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x800723CC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800723D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800723D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800723D8: sh          $t9, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r25;
    // 0x800723DC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800723E0: lh          $t0, 0x4E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4E);
    // 0x800723E4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800723E8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800723EC: sb          $t0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r8;
    // 0x800723F0: jal         0x800612B8
    // 0x800723F4: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x800723F4: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x800723F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800723FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072400: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80072404: jr          $ra
    // 0x80072408: nop

    return;
    // 0x80072408: nop

;}
RECOMP_FUNC void Sprite_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800615A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800615A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800615A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800615AC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800615B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800615B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800615B8: jal         0x80061394
    // 0x800615BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    Sprite_Initialize(rdram, ctx);
        goto after_0;
    // 0x800615BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800615C0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800615C4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800615C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800615CC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x800615D0: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800615D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800615D8: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800615DC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800615E0: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800615E4: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800615E8: lwc1        $f8, 0x6420($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6420);
    // 0x800615EC: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800615F0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800615F4: nop

    // 0x800615F8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800615FC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80061600: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80061604: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x80061608: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x8006160C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80061610: nop

    // 0x80061614: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061618: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x8006161C: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x80061620: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80061624: nop

    // 0x80061628: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006162C: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x80061630: lh          $t0, 0xC($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XC);
    // 0x80061634: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80061638: nop

    // 0x8006163C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061640: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x80061644: lh          $t1, 0xA($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XA);
    // 0x80061648: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8006164C: nop

    // 0x80061650: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061654: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x80061658: lh          $t2, 0xE($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XE);
    // 0x8006165C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80061660: nop

    // 0x80061664: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061668: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x8006166C: lh          $t3, 0x10($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X10);
    // 0x80061670: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x80061674: jal         0x800612B8
    // 0x80061678: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80061678: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    after_1:
    // 0x8006167C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061684: jr          $ra
    // 0x80061688: nop

    return;
    // 0x80061688: nop

;}
RECOMP_FUNC void func_versus_800BF750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF750: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800BF754: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800BF758: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800BF75C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800BF760: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800BF764: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800BF768: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800BF76C: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x800BF770: addiu       $s6, $sp, 0x90
    ctx->r22 = ADD32(ctx->r29, 0X90);
    // 0x800BF774: addiu       $s7, $sp, 0x80
    ctx->r23 = ADD32(ctx->r29, 0X80);
    // 0x800BF778: addiu       $fp, $sp, 0x70
    ctx->r30 = ADD32(ctx->r29, 0X70);
    // 0x800BF77C: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x800BF780: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800BF784: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800BF788: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800BF78C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800BF790: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BF794: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800BF798: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800BF79C: addiu       $t6, $t6, 0x4C1C
    ctx->r14 = ADD32(ctx->r14, 0X4C1C);
    // 0x800BF7A0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BF7A4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800BF7A8: addiu       $t0, $t0, 0x4C2C
    ctx->r8 = ADD32(ctx->r8, 0X4C2C);
    // 0x800BF7AC: sw          $at, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r1;
    // 0x800BF7B0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800BF7B4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800BF7B8: addiu       $t4, $t4, 0x4C3C
    ctx->r12 = ADD32(ctx->r12, 0X4C3C);
    // 0x800BF7BC: sw          $t9, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r25;
    // 0x800BF7C0: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800BF7C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800BF7C8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x800BF7CC: sw          $at, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r1;
    // 0x800BF7D0: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800BF7D4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800BF7D8: addiu       $t6, $t6, 0x4C4C
    ctx->r14 = ADD32(ctx->r14, 0X4C4C);
    // 0x800BF7DC: sw          $t9, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r25;
    // 0x800BF7E0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800BF7E4: sw          $at, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r1;
    // 0x800BF7E8: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800BF7EC: sw          $t3, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r11;
    // 0x800BF7F0: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800BF7F4: sw          $at, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r1;
    // 0x800BF7F8: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800BF7FC: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x800BF800: sw          $t3, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r11;
    // 0x800BF804: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x800BF808: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800BF80C: addiu       $t3, $t3, 0x4C5C
    ctx->r11 = ADD32(ctx->r11, 0X4C5C);
    // 0x800BF810: sw          $at, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r1;
    // 0x800BF814: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800BF818: sw          $t7, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r15;
    // 0x800BF81C: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x800BF820: sw          $at, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r1;
    // 0x800BF824: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x800BF828: sw          $t7, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r15;
    // 0x800BF82C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BF830: sw          $at, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r1;
    // 0x800BF834: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x800BF838: sw          $t1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r9;
    // 0x800BF83C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800BF840: sw          $at, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r1;
    // 0x800BF844: lw          $t1, 0xC($t6)
    ctx->r9 = MEM_W(ctx->r14, 0XC);
    // 0x800BF848: sw          $t1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r9;
    // 0x800BF84C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800BF850: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800BF854: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x800BF858: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800BF85C: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x800BF860: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x800BF864: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x800BF868: jal         0x800B8DD0
    // 0x800BF86C: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BF86C: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    after_0:
    // 0x800BF870: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800BF874: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BF878: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800BF87C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_800BF880:
    // 0x800BF880: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BF884: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800BF888: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800BF88C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BF890: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BF894: addu        $t9, $t7, $t2
    ctx->r25 = ADD32(ctx->r15, ctx->r10);
    // 0x800BF898: lw          $t6, 0x1C8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X1C8);
    // 0x800BF89C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BF8A0: sll         $t1, $s4, 4
    ctx->r9 = S32(ctx->r20 << 4);
    // 0x800BF8A4: bne         $t6, $at, L_800BF960
    if (ctx->r14 != ctx->r1) {
        // 0x800BF8A8: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_800BF960;
    }
    // 0x800BF8A8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800BF8AC: addiu       $t5, $t5, 0x7B00
    ctx->r13 = ADD32(ctx->r13, 0X7B00);
    // 0x800BF8B0: addu        $s2, $t1, $t5
    ctx->r18 = ADD32(ctx->r9, ctx->r13);
L_800BF8B4:
    // 0x800BF8B4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800BF8B8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800BF8BC: beql        $t8, $zero, L_800BF954
    if (ctx->r24 == 0) {
        // 0x800BF8C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800BF954;
    }
    goto skip_0;
    // 0x800BF8C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800BF8C4: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x800BF8C8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BF8CC: andi        $t3, $t0, 0x4
    ctx->r11 = ctx->r8 & 0X4;
    // 0x800BF8D0: beql        $t3, $zero, L_800BF954
    if (ctx->r11 == 0) {
        // 0x800BF8D4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800BF954;
    }
    goto skip_1;
    // 0x800BF8D4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x800BF8D8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800BF8DC: addu        $t2, $sp, $s0
    ctx->r10 = ADD32(ctx->r29, ctx->r16);
    // 0x800BF8E0: addu        $t1, $s7, $s0
    ctx->r9 = ADD32(ctx->r23, ctx->r16);
    // 0x800BF8E4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800BF8E8: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x800BF8EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BF8F0: lw          $t2, 0x60($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X60);
    // 0x800BF8F4: addu        $t4, $fp, $s0
    ctx->r12 = ADD32(ctx->r30, ctx->r16);
    // 0x800BF8F8: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800BF8FC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BF900: andi        $t9, $t2, 0xFF
    ctx->r25 = ctx->r10 & 0XFF;
    // 0x800BF904: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x800BF908: andi        $t2, $t7, 0xFF
    ctx->r10 = ctx->r15 & 0XFF;
    // 0x800BF90C: sll         $t0, $t8, 24
    ctx->r8 = S32(ctx->r24 << 24);
    // 0x800BF910: or          $t3, $t6, $t0
    ctx->r11 = ctx->r14 | ctx->r8;
    // 0x800BF914: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x800BF918: or          $t1, $t3, $t9
    ctx->r9 = ctx->r11 | ctx->r25;
    // 0x800BF91C: ori         $t5, $t1, 0xFF
    ctx->r13 = ctx->r9 | 0XFF;
    // 0x800BF920: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800BF924: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x800BF928: sll         $a0, $s4, 2
    ctx->r4 = S32(ctx->r20 << 2);
    // 0x800BF92C: addu        $t8, $s5, $a0
    ctx->r24 = ADD32(ctx->r21, ctx->r4);
    // 0x800BF930: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BF934: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BF938: addu        $t6, $s6, $a0
    ctx->r14 = ADD32(ctx->r22, ctx->r4);
    // 0x800BF93C: lwc1        $f14, 0x0($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BF940: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BF944: jal         0x800BDA54
    // 0x800BF948: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    func_versus_800BDA54(rdram, ctx);
        goto after_1;
    // 0x800BF948: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_1:
    // 0x800BF94C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BF950: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800BF954:
    // 0x800BF954: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800BF958: bne         $s0, $at, L_800BF8B4
    if (ctx->r16 != ctx->r1) {
        // 0x800BF95C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800BF8B4;
    }
    // 0x800BF95C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800BF960:
    // 0x800BF960: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800BF964: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800BF968: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BF96C: addiu       $t4, $t0, 0x4E0
    ctx->r12 = ADD32(ctx->r8, 0X4E0);
    // 0x800BF970: bne         $s4, $at, L_800BF880
    if (ctx->r20 != ctx->r1) {
        // 0x800BF974: sw          $t4, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r12;
            goto L_800BF880;
    }
    // 0x800BF974: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x800BF978: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800BF97C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800BF980: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800BF984: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800BF988: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800BF98C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF990: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800BF994: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800BF998: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800BF99C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF9A0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800BF9A4: jr          $ra
    // 0x800BF9A8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800BF9A8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Player_UpdateTankJets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3314: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B3318: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B331C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B3320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3324: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B3328: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B332C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B3330: swc1        $f4, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f4.u32l;
    // 0x800B3334: lw          $t6, 0x7974($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7974);
    // 0x800B3338: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B333C: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x800B3340: beql        $t8, $zero, L_800B3434
    if (ctx->r24 == 0) {
        // 0x800B3344: lwc1        $f2, 0x12C($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
            goto L_800B3434;
    }
    goto skip_0;
    // 0x800B3344: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    skip_0:
    // 0x800B3348: lw          $t9, 0x2B4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2B4);
    // 0x800B334C: bnel        $t9, $zero, L_800B3434
    if (ctx->r25 != 0) {
        // 0x800B3350: lwc1        $f2, 0x12C($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
            goto L_800B3434;
    }
    goto skip_1;
    // 0x800B3350: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    skip_1:
    // 0x800B3354: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3358: lwc1        $f6, 0x2BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B335C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B3360: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x800B3364: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x800B3368: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B336C: bc1fl       L_800B3388
    if (!c1cs) {
        // 0x800B3370: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_800B3388;
    }
    goto skip_2;
    // 0x800B3370: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    skip_2:
    // 0x800B3374: jal         0x800A5FA0
    // 0x800B3378: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800B3378: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_0:
    // 0x800B337C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3380: nop

    // 0x800B3384: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_800B3388:
    // 0x800B3388: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B338C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B3390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B3394: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B3398: swc1        $f2, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f2.u32l;
    // 0x800B339C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B33A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B33A4: addiu       $a0, $s0, 0x170
    ctx->r4 = ADD32(ctx->r16, 0X170);
    // 0x800B33A8: swc1        $f16, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f16.u32l;
    // 0x800B33AC: lwc1        $f18, 0x12C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B33B0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B33B4: nop

    // 0x800B33B8: bc1fl       L_800B33C8
    if (!c1cs) {
        // 0x800B33BC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800B33C8;
    }
    goto skip_3;
    // 0x800B33BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x800B33C0: swc1        $f0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f0.u32l;
    // 0x800B33C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800B33C8:
    // 0x800B33C8: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x800B33CC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B33D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B33D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B33D8: jal         0x8009BC2C
    // 0x800B33DC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B33DC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800B33E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B33E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B33E8: sw          $t0, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = ctx->r8;
    // 0x800B33EC: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x800B33F0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x800B33F4: addiu       $a0, $s0, 0x2BC
    ctx->r4 = ADD32(ctx->r16, 0X2BC);
    // 0x800B33F8: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800B33FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B3400: jal         0x8009BC2C
    // 0x800B3404: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800B3404: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800B3408: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B340C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B3410: lwc1        $f6, 0x2BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B3414: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800B3418: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800B341C: nop

    // 0x800B3420: bc1f        L_800B34BC
    if (!c1cs) {
        // 0x800B3424: nop
    
            goto L_800B34BC;
    }
    // 0x800B3424: nop

    // 0x800B3428: b           L_800B34BC
    // 0x800B342C: sw          $t1, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r9;
        goto L_800B34BC;
    // 0x800B342C: sw          $t1, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r9;
    // 0x800B3430: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
L_800B3434:
    // 0x800B3434: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B3438: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B343C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800B3440: nop

    // 0x800B3444: bc1f        L_800B34BC
    if (!c1cs) {
        // 0x800B3448: nop
    
            goto L_800B34BC;
    }
    // 0x800B3448: nop

    // 0x800B344C: lwc1        $f16, 0x188($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X188);
    // 0x800B3450: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B3454: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B3458: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B345C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3460: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
    // 0x800B3464: lwc1        $f0, 0x188($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X188);
    // 0x800B3468: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B346C: swc1        $f6, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f6.u32l;
    // 0x800B3470: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B3474: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800B3478: nop

    // 0x800B347C: bc1f        L_800B34BC
    if (!c1cs) {
        // 0x800B3480: nop
    
            goto L_800B34BC;
    }
    // 0x800B3480: nop

    // 0x800B3484: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B3488: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B348C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3490: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800B3494: swc1        $f16, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f16.u32l;
    // 0x800B3498: bc1f        L_800B34BC
    if (!c1cs) {
        // 0x800B349C: nop
    
            goto L_800B34BC;
    }
    // 0x800B349C: nop

    // 0x800B34A0: lwc1        $f4, -0x7660($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7660);
    // 0x800B34A4: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B34A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800B34AC: swc1        $f6, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f6.u32l;
    // 0x800B34B0: lwc1        $f10, 0x188($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X188);
    // 0x800B34B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B34B8: swc1        $f16, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f16.u32l;
L_800B34BC:
    // 0x800B34BC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B34C0: lw          $t2, 0x7974($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7974);
    // 0x800B34C4: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800B34C8: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x800B34CC: beql        $t4, $zero, L_800B35C8
    if (ctx->r12 == 0) {
        // 0x800B34D0: lwc1        $f2, 0x12C($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
            goto L_800B35C8;
    }
    goto skip_4;
    // 0x800B34D0: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    skip_4:
    // 0x800B34D4: lw          $t5, 0x2B4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2B4);
    // 0x800B34D8: addiu       $t6, $s0, 0x2BC
    ctx->r14 = ADD32(ctx->r16, 0X2BC);
    // 0x800B34DC: bnel        $t5, $zero, L_800B35C8
    if (ctx->r13 != 0) {
        // 0x800B34E0: lwc1        $f2, 0x12C($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
            goto L_800B35C8;
    }
    goto skip_5;
    // 0x800B34E0: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    skip_5:
    // 0x800B34E4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800B34E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B34EC: lwc1        $f18, 0x2BC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B34F0: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B34F4: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x800B34F8: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x800B34FC: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B3500: bc1fl       L_800B351C
    if (!c1cs) {
        // 0x800B3504: lui         $at, 0xC248
        ctx->r1 = S32(0XC248 << 16);
            goto L_800B351C;
    }
    goto skip_6;
    // 0x800B3504: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    skip_6:
    // 0x800B3508: jal         0x800A5FA0
    // 0x800B350C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800B350C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_3:
    // 0x800B3510: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3514: nop

    // 0x800B3518: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
L_800B351C:
    // 0x800B351C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B3520: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B3524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B3528: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B352C: swc1        $f2, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f2.u32l;
    // 0x800B3530: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B3534: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B3538: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x800B353C: swc1        $f8, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f8.u32l;
    // 0x800B3540: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B3544: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800B3548: nop

    // 0x800B354C: bc1fl       L_800B355C
    if (!c1cs) {
        // 0x800B3550: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800B355C;
    }
    goto skip_7;
    // 0x800B3550: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_7:
    // 0x800B3554: swc1        $f0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f0.u32l;
    // 0x800B3558: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800B355C:
    // 0x800B355C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x800B3560: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B3564: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B3568: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B356C: jal         0x8009BC2C
    // 0x800B3570: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B3570: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x800B3574: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B3578: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B357C: sw          $t7, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = ctx->r15;
    // 0x800B3580: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x800B3584: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x800B3588: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B358C: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800B3590: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B3594: jal         0x8009BC2C
    // 0x800B3598: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B3598: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800B359C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B35A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B35A4: lwc1        $f18, 0x2BC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B35A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B35AC: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x800B35B0: nop

    // 0x800B35B4: bc1f        L_800B3650
    if (!c1cs) {
        // 0x800B35B8: nop
    
            goto L_800B3650;
    }
    // 0x800B35B8: nop

    // 0x800B35BC: b           L_800B3650
    // 0x800B35C0: sw          $t8, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r24;
        goto L_800B3650;
    // 0x800B35C0: sw          $t8, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r24;
    // 0x800B35C4: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
L_800B35C8:
    // 0x800B35C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B35CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B35D0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800B35D4: nop

    // 0x800B35D8: bc1f        L_800B3650
    if (!c1cs) {
        // 0x800B35DC: nop
    
            goto L_800B3650;
    }
    // 0x800B35DC: nop

    // 0x800B35E0: lwc1        $f8, 0x188($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X188);
    // 0x800B35E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B35E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B35EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B35F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B35F4: swc1        $f16, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f16.u32l;
    // 0x800B35F8: lwc1        $f0, 0x188($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X188);
    // 0x800B35FC: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B3600: swc1        $f18, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f18.u32l;
    // 0x800B3604: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B3608: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800B360C: nop

    // 0x800B3610: bc1f        L_800B3650
    if (!c1cs) {
        // 0x800B3614: nop
    
            goto L_800B3650;
    }
    // 0x800B3614: nop

    // 0x800B3618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B361C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B3620: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3624: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800B3628: swc1        $f8, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f8.u32l;
    // 0x800B362C: bc1f        L_800B3650
    if (!c1cs) {
        // 0x800B3630: nop
    
            goto L_800B3650;
    }
    // 0x800B3630: nop

    // 0x800B3634: lwc1        $f16, -0x765C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X765C);
    // 0x800B3638: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B363C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B3640: swc1        $f18, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f18.u32l;
    // 0x800B3644: lwc1        $f6, 0x188($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X188);
    // 0x800B3648: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B364C: swc1        $f8, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f8.u32l;
L_800B3650:
    // 0x800B3650: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3654: lwc1        $f2, -0x7658($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7658);
    // 0x800B3658: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x800B365C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B3660: nop

    // 0x800B3664: bc1f        L_800B3868
    if (!c1cs) {
        // 0x800B3668: nop
    
            goto L_800B3868;
    }
    // 0x800B3668: nop

    // 0x800B366C: lwc1        $f10, 0x170($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X170);
    // 0x800B3670: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800B3674: nop

    // 0x800B3678: bc1f        L_800B3868
    if (!c1cs) {
        // 0x800B367C: nop
    
            goto L_800B3868;
    }
    // 0x800B367C: nop

    // 0x800B3680: lw          $t9, 0x220($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X220);
    // 0x800B3684: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B3688: bne         $t9, $zero, L_800B3868
    if (ctx->r25 != 0) {
        // 0x800B368C: nop
    
            goto L_800B3868;
    }
    // 0x800B368C: nop

    // 0x800B3690: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x800B3694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3698: lwc1        $f4, -0x7654($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7654);
    // 0x800B369C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800B36A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800B36A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B36A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B36AC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B36B0: nop

    // 0x800B36B4: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B36B8: jal         0x80023250
    // 0x800B36BC: nop

    __cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x800B36BC: nop

    after_6:
    // 0x800B36C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B36C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B36C8: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B36CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B36D0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B36D4: lwc1        $f4, -0x7650($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7650);
    // 0x800B36D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B36DC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B36E0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B36E4: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x800B36E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B36EC: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800B36F0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B36F4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B36F8: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800B36FC: swc1        $f8, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f8.u32l;
    // 0x800B3700: lwc1        $f10, -0x764C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X764C);
    // 0x800B3704: jal         0x8009BD38
    // 0x800B3708: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_7;
    // 0x800B3708: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800B370C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3710: lwc1        $f16, -0x7648($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7648);
    // 0x800B3714: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B3718: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B371C: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x800B3720: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B3724: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B3728: jal         0x8009BD38
    // 0x800B372C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_8;
    // 0x800B372C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x800B3730: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B3734: lw          $t1, 0x797C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X797C);
    // 0x800B3738: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B373C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B3740: lb          $t2, 0x3($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X3);
    // 0x800B3744: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3748: lwc1        $f8, -0x7644($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7644);
    // 0x800B374C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800B3750: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B3754: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B3758: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B375C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3760: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B3764: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800B3768: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800B376C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B3770: jal         0x8009BC2C
    // 0x800B3774: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B3774: nop

    after_9:
    // 0x800B3778: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B377C: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x800B3780: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x800B3784: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B3788: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B378C: jal         0x8009BC2C
    // 0x800B3790: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800B3790: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x800B3794: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3798: lwc1        $f16, -0x7640($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7640);
    // 0x800B379C: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B37A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B37A4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B37A8: addiu       $t5, $t5, 0x79A8
    ctx->r13 = ADD32(ctx->r13, 0X79A8);
    // 0x800B37AC: swc1        $f16, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f16.u32l;
    // 0x800B37B0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B37B4: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800B37B8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x800B37BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B37C0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B37C4: jal         0x8009BC2C
    // 0x800B37C8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800B37C8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x800B37CC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B37D0: lw          $t6, 0x78A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A8);
    // 0x800B37D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B37D8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B37DC: bnel        $t6, $at, L_800B39D0
    if (ctx->r14 != ctx->r1) {
        // 0x800B37E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B39D0;
    }
    goto skip_8;
    // 0x800B37E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x800B37E4: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800B37E8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800B37EC: bnel        $t8, $zero, L_800B39D0
    if (ctx->r24 != 0) {
        // 0x800B37F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B39D0;
    }
    goto skip_9;
    // 0x800B37F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x800B37F4: jal         0x80004EB0
    // 0x800B37F8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x800B37F8: nop

    after_12:
    // 0x800B37FC: jal         0x80004EB0
    // 0x800B3800: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x800B3800: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x800B3804: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B3808: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B380C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B3810: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B3814: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B3818: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B381C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B3820: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B3824: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B3828: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B382C: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B3830: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B3834: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B3838: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B383C: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800B3840: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3844: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B3848: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800B384C: add.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800B3850: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B3854: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800B3858: jal         0x8007BC7C
    // 0x800B385C: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_14;
    // 0x800B385C: nop

    after_14:
    // 0x800B3860: b           L_800B39D0
    // 0x800B3864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800B39D0;
    // 0x800B3864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B3868:
    // 0x800B3868: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B386C: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x800B3870: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B3874: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B3878: bnel        $t9, $at, L_800B39D0
    if (ctx->r25 != ctx->r1) {
        // 0x800B387C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B39D0;
    }
    goto skip_10;
    // 0x800B387C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x800B3880: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x800B3884: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x800B3888: bnel        $t1, $zero, L_800B39D0
    if (ctx->r9 != 0) {
        // 0x800B388C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B39D0;
    }
    goto skip_11;
    // 0x800B388C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x800B3890: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
    // 0x800B3894: bnel        $t2, $zero, L_800B39D0
    if (ctx->r10 != 0) {
        // 0x800B3898: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B39D0;
    }
    goto skip_12;
    // 0x800B3898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x800B389C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B38A0: nop

    // 0x800B38A4: bc1fl       L_800B3934
    if (!c1cs) {
        // 0x800B38A8: lwc1        $f6, 0x170($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
            goto L_800B3934;
    }
    goto skip_13;
    // 0x800B38A8: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
    skip_13:
    // 0x800B38AC: lw          $t3, 0x220($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X220);
    // 0x800B38B0: bnel        $t3, $zero, L_800B3934
    if (ctx->r11 != 0) {
        // 0x800B38B4: lwc1        $f6, 0x170($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
            goto L_800B3934;
    }
    goto skip_14;
    // 0x800B38B4: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
    skip_14:
    // 0x800B38B8: jal         0x80004EB0
    // 0x800B38BC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x800B38BC: nop

    after_15:
    // 0x800B38C0: jal         0x80004EB0
    // 0x800B38C4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x800B38C4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x800B38C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B38CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B38D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B38D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B38D8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B38DC: lui         $at, 0x4264
    ctx->r1 = S32(0X4264 << 16);
    // 0x800B38E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B38E4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B38E8: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B38EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B38F0: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B38F4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800B38F8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B38FC: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B3900: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B3904: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B3908: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B390C: sub.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800B3910: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800B3914: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B3918: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800B391C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800B3920: jal         0x8007BC7C
    // 0x800B3924: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_17;
    // 0x800B3924: nop

    after_17:
    // 0x800B3928: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B392C: lwc1        $f2, -0x763C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X763C);
    // 0x800B3930: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
L_800B3934:
    // 0x800B3934: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800B3938: nop

    // 0x800B393C: bc1fl       L_800B39D0
    if (!c1cs) {
        // 0x800B3940: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B39D0;
    }
    goto skip_15;
    // 0x800B3940: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x800B3944: lw          $t4, 0x220($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X220);
    // 0x800B3948: bnel        $t4, $zero, L_800B39D0
    if (ctx->r12 != 0) {
        // 0x800B394C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B39D0;
    }
    goto skip_16;
    // 0x800B394C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_16:
    // 0x800B3950: jal         0x80004EB0
    // 0x800B3954: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x800B3954: nop

    after_18:
    // 0x800B3958: jal         0x80004EB0
    // 0x800B395C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x800B395C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x800B3960: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B3964: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B3968: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B396C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B3970: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B3974: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800B3978: lui         $at, 0x4264
    ctx->r1 = S32(0X4264 << 16);
    // 0x800B397C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B3980: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B3984: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800B3988: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B398C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3990: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B3994: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B3998: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B399C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B39A0: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800B39A4: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B39A8: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B39AC: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800B39B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B39B4: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B39B8: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B39BC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B39C0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800B39C4: jal         0x8007BC7C
    // 0x800B39C8: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_20;
    // 0x800B39C8: nop

    after_20:
    // 0x800B39CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B39D0:
    // 0x800B39D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B39D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B39D8: jr          $ra
    // 0x800B39DC: nop

    return;
    // 0x800B39DC: nop

;}
RECOMP_FUNC void HUD_BoostGaugeCool_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085890: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085894: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80085898: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008589C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800858A0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800858A4: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800858A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800858AC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800858B0: beq         $t6, $zero, L_80085900
    if (ctx->r14 == 0) {
        // 0x800858B4: lui         $a1, 0x101
        ctx->r5 = S32(0X101 << 16);
            goto L_80085900;
    }
    // 0x800858B4: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800858B8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800858BC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800858C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800858C4: lui         $a1, 0x301
    ctx->r5 = S32(0X301 << 16);
    // 0x800858C8: lui         $a2, 0x301
    ctx->r6 = S32(0X301 << 16);
    // 0x800858CC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800858D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800858D4: addiu       $a2, $a2, -0x2C68
    ctx->r6 = ADD32(ctx->r6, -0X2C68);
    // 0x800858D8: addiu       $a1, $a1, -0x2CB0
    ctx->r5 = ADD32(ctx->r5, -0X2CB0);
    // 0x800858DC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800858E0: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x800858E4: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800858E8: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800858EC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800858F0: jal         0x8009D0BC
    // 0x800858F4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800858F4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800858F8: b           L_80085938
    // 0x800858FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80085938;
    // 0x800858FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80085900:
    // 0x80085900: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80085904: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80085908: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x8008590C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80085910: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80085914: addiu       $a2, $a2, 0x2898
    ctx->r6 = ADD32(ctx->r6, 0X2898);
    // 0x80085918: addiu       $a1, $a1, 0x27D0
    ctx->r5 = ADD32(ctx->r5, 0X27D0);
    // 0x8008591C: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x80085920: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80085924: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80085928: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8008592C: jal         0x8009D0BC
    // 0x80085930: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x80085930: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80085934: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80085938:
    // 0x80085938: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008593C: jr          $ra
    // 0x80085940: nop

    return;
    // 0x80085940: nop

;}
RECOMP_FUNC void Versus_WaitFrames(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C16A0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C16A4: addiu       $v1, $v1, -0x7868
    ctx->r3 = ADD32(ctx->r3, -0X7868);
    // 0x800C16A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C16AC: beq         $a0, $v0, L_800C16BC
    if (ctx->r4 == ctx->r2) {
        // 0x800C16B0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_800C16BC;
    }
    // 0x800C16B0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800C16B4: b           L_800C16C4
    // 0x800C16B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_800C16C4;
    // 0x800C16B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800C16BC:
    // 0x800C16BC: jr          $ra
    // 0x800C16C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C16C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C16C4:
    // 0x800C16C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C16C8: jr          $ra
    // 0x800C16CC: nop

    return;
    // 0x800C16CC: nop

;}
RECOMP_FUNC void PlayerShot_CheckSpriteHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037698: lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X28);
    // 0x8003769C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800376A0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800376A4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800376A8: nop

    // 0x800376AC: beql        $t7, $zero, L_80037744
    if (ctx->r15 == 0) {
        // 0x800376B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037744;
    }
    goto skip_0;
    // 0x800376B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800376B4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800376B8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800376BC: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800376C0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800376C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800376C8: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800376CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800376D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800376D4: nop

    // 0x800376D8: bc1fl       L_80037744
    if (!c1cs) {
        // 0x800376DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037744;
    }
    goto skip_1;
    // 0x800376DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800376E0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800376E4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800376E8: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800376EC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800376F0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800376F4: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800376F8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800376FC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80037700: nop

    // 0x80037704: bc1fl       L_80037744
    if (!c1cs) {
        // 0x80037708: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037744;
    }
    goto skip_2;
    // 0x80037708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8003770C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80037710: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80037714: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80037718: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8003771C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037720: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80037724: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80037728: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003772C: nop

    // 0x80037730: bc1fl       L_80037744
    if (!c1cs) {
        // 0x80037734: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037744;
    }
    goto skip_3;
    // 0x80037734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80037738: jr          $ra
    // 0x8003773C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003773C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80037740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037744:
    // 0x80037744: jr          $ra
    // 0x80037748: nop

    return;
    // 0x80037748: nop

;}
RECOMP_FUNC void HUD_RadarMark_StarWolf_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089AF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089AFC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80089B00: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089B04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089B0C: jal         0x800B8DD0
    // 0x80089B10: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80089B10: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80089B14: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80089B18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089B1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80089B20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089B24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80089B28: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80089B2C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80089B30: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80089B34: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80089B38: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80089B3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80089B40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80089B44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089B48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089B4C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80089B50: jal         0x80005C34
    // 0x80089B54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80089B54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80089B58: jal         0x80006EB8
    // 0x80089B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80089B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80089B60: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089B64: lui         $t2, 0xF01
    ctx->r10 = S32(0XF01 << 16);
    // 0x80089B68: addiu       $t2, $t2, 0x4180
    ctx->r10 = ADD32(ctx->r10, 0X4180);
    // 0x80089B6C: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80089B70: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80089B74: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80089B78: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80089B7C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80089B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089B84: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089B8C: jr          $ra
    // 0x80089B90: nop

    return;
    // 0x80089B90: nop

;}
RECOMP_FUNC void Audio_AdsrInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013B6C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80013B70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80013B74: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80013B78: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80013B7C: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x80013B80: sw          $a1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r5;
    // 0x80013B84: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80013B88: jr          $ra
    // 0x80013B8C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80013B8C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void Player_CanLockOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD118: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800AD11C: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x800AD120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800AD128:
    // 0x800AD128: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800AD12C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AD130: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x800AD134: bne         $a1, $t6, L_800AD150
    if (ctx->r5 != ctx->r14) {
        // 0x800AD138: addu        $t7, $v1, $a0
        ctx->r15 = ADD32(ctx->r3, ctx->r4);
            goto L_800AD150;
    }
    // 0x800AD138: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x800AD13C: lbu         $t8, 0xCA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XCA);
    // 0x800AD140: beq         $t8, $zero, L_800AD150
    if (ctx->r24 == 0) {
        // 0x800AD144: nop
    
            goto L_800AD150;
    }
    // 0x800AD144: nop

    // 0x800AD148: jr          $ra
    // 0x800AD14C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AD14C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AD150:
    // 0x800AD150: bne         $at, $zero, L_800AD128
    if (ctx->r1 != 0) {
        // 0x800AD154: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_800AD128;
    }
    // 0x800AD154: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x800AD158: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800AD15C: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x800AD160: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800AD164: beql        $t9, $zero, L_800AD1EC
    if (ctx->r25 == 0) {
        // 0x800AD168: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AD1EC;
    }
    goto skip_0;
    // 0x800AD168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800AD16C: lw          $v1, 0x78A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78A8);
    // 0x800AD170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD174: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AD178: blez        $v1, L_800AD1E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AD17C: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_800AD1E8;
    }
    // 0x800AD17C: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800AD180: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x800AD184: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x800AD188: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800AD18C: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x800AD190: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800AD194: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800AD198: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800AD19C: lw          $a1, 0x1C8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X1C8);
    // 0x800AD1A0: addiu       $t0, $t0, 0x7B00
    ctx->r8 = ADD32(ctx->r8, 0X7B00);
    // 0x800AD1A4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800AD1A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_800AD1AC:
    // 0x800AD1AC: beq         $a2, $a1, L_800AD1B8
    if (ctx->r6 == ctx->r5) {
        // 0x800AD1B0: sll         $t4, $v0, 4
        ctx->r12 = S32(ctx->r2 << 4);
            goto L_800AD1B8;
    }
    // 0x800AD1B0: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x800AD1B4: bne         $a3, $a1, L_800AD1D8
    if (ctx->r7 != ctx->r5) {
        // 0x800AD1B8: addu        $t5, $t0, $t4
        ctx->r13 = ADD32(ctx->r8, ctx->r12);
            goto L_800AD1D8;
    }
L_800AD1B8:
    // 0x800AD1B8: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800AD1BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800AD1C0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AD1C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800AD1C8: beql        $t8, $zero, L_800AD1DC
    if (ctx->r24 == 0) {
        // 0x800AD1CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD1DC;
    }
    goto skip_1;
    // 0x800AD1CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x800AD1D0: jr          $ra
    // 0x800AD1D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AD1D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AD1D8:
    // 0x800AD1D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800AD1DC:
    // 0x800AD1DC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AD1E0: bne         $at, $zero, L_800AD1AC
    if (ctx->r1 != 0) {
        // 0x800AD1E4: nop
    
            goto L_800AD1AC;
    }
    // 0x800AD1E4: nop

L_800AD1E8:
    // 0x800AD1E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD1EC:
    // 0x800AD1EC: jr          $ra
    // 0x800AD1F0: nop

    return;
    // 0x800AD1F0: nop

;}
RECOMP_FUNC void MeMora_Dying(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B0A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006B0A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006B0A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006B0AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006B0B0: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B0B4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8006B0B8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8006B0BC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006B0C0: sh          $t7, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r15;
    // 0x8006B0C4: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B0C8: addiu       $t1, $t1, 0x6878
    ctx->r9 = ADD32(ctx->r9, 0X6878);
    // 0x8006B0CC: addiu       $t0, $t0, 0x6558
    ctx->r8 = ADD32(ctx->r8, 0X6558);
    // 0x8006B0D0: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006B0D4: bne         $at, $zero, L_8006B0E4
    if (ctx->r1 != 0) {
        // 0x8006B0D8: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8006B0E4;
    }
    // 0x8006B0D8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8006B0DC: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
    // 0x8006B0E0: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
L_8006B0E4:
    // 0x8006B0E4: lh          $t8, 0x46($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X46);
    // 0x8006B0E8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006B0EC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8006B0F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006B0F4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8006B0F8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8006B0FC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006B100: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8006B104: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x8006B108: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8006B10C: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x8006B110: lh          $t6, 0x46($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X46);
    // 0x8006B114: lh          $t9, 0x4E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B118: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006B11C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006B120: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006B124: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8006B128: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006B12C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8006B130: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8006B134: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8006B138: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x8006B13C: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
    // 0x8006B140: lh          $t5, 0x46($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X46);
    // 0x8006B144: lh          $t9, 0x4E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B148: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006B14C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006B150: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8006B154: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8006B158: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8006B15C: addiu       $t2, $t2, 0x6B98
    ctx->r10 = ADD32(ctx->r10, 0X6B98);
    // 0x8006B160: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8006B164: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8006B168: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8006B16C: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B170: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8006B174: lh          $t4, 0x46($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X46);
    // 0x8006B178: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B17C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006B180: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8006B184: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8006B188: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8006B18C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8006B190: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8006B194: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8006B198: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x8006B19C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B1A0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8006B1A4: swc1        $f10, 0x6EB8($at)
    MEM_W(0X6EB8, ctx->r1) = ctx->f10.u32l;
    // 0x8006B1A8: lh          $t8, 0x46($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X46);
    // 0x8006B1AC: lh          $t4, 0x4E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B1B0: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006B1B4: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8006B1B8: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x8006B1BC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8006B1C0: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x8006B1C4: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8006B1C8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8006B1CC: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8006B1D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B1D4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8006B1D8: swc1        $f16, 0x71D8($at)
    MEM_W(0X71D8, ctx->r1) = ctx->f16.u32l;
    // 0x8006B1DC: lh          $t9, 0x46($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X46);
    // 0x8006B1E0: lh          $t8, 0x4E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B1E4: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006B1E8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8006B1EC: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x8006B1F0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8006B1F4: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x8006B1F8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8006B1FC: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8006B200: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x8006B204: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B208: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8006B20C: swc1        $f18, 0x7500($at)
    MEM_W(0X7500, ctx->r1) = ctx->f18.u32l;
    // 0x8006B210: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006B214: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006B218: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006B21C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006B220: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006B224: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006B228: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006B22C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8006B230: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006B234: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006B238: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006B23C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8006B240: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x8006B244: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006B248: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8006B24C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8006B250: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8006B254: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8006B258: jal         0x8009F6CC
    // 0x8006B25C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    Math_Vec3fFromAngles(rdram, ctx);
        goto after_0;
    // 0x8006B25C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_0:
    // 0x8006B260: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006B264: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006B268: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8006B26C: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    // 0x8006B270: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006B274: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8006B278: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8006B27C: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x8006B280: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006B284: addiu       $t2, $t2, 0x6B98
    ctx->r10 = ADD32(ctx->r10, 0X6B98);
    // 0x8006B288: addiu       $t1, $t1, 0x6878
    ctx->r9 = ADD32(ctx->r9, 0X6878);
    // 0x8006B28C: addiu       $t0, $t0, 0x6558
    ctx->r8 = ADD32(ctx->r8, 0X6558);
    // 0x8006B290: bne         $t6, $zero, L_8006B458
    if (ctx->r14 != 0) {
        // 0x8006B294: swc1        $f18, 0xF0($s0)
        MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
            goto L_8006B458;
    }
    // 0x8006B294: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x8006B298: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8006B29C: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x8006B2A0: andi        $t9, $t5, 0x3
    ctx->r25 = ctx->r13 & 0X3;
    // 0x8006B2A4: bnel        $t9, $zero, L_8006B45C
    if (ctx->r25 != 0) {
        // 0x8006B2A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006B45C;
    }
    goto skip_0;
    // 0x8006B2A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8006B2AC: lh          $v0, 0x4A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4A);
    // 0x8006B2B0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006B2B4: lh          $t4, 0x4E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4E);
    // 0x8006B2B8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8006B2BC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B2C0: lh          $t7, -0x6C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6C);
    // 0x8006B2C4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8006B2C8: addu        $a0, $t7, $t4
    ctx->r4 = ADD32(ctx->r15, ctx->r12);
    // 0x8006B2CC: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x8006B2D0: mfhi        $t3
    ctx->r11 = hi;
    // 0x8006B2D4: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8006B2D8: bnel        $v0, $zero, L_8006B35C
    if (ctx->r2 != 0) {
        // 0x8006B2DC: lh          $v0, 0x46($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X46);
            goto L_8006B35C;
    }
    goto skip_1;
    // 0x8006B2DC: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    skip_1:
    // 0x8006B2E0: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    // 0x8006B2E4: sll         $v1, $t3, 2
    ctx->r3 = S32(ctx->r11 << 2);
    // 0x8006B2E8: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x8006B2EC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8006B2F0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8006B2F4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8006B2F8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8006B2FC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8006B300: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8006B304: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8006B308: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8006B30C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8006B310: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8006B314: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8006B318: addu        $t5, $t0, $t6
    ctx->r13 = ADD32(ctx->r8, ctx->r14);
    // 0x8006B31C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8006B320: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x8006B324: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8006B328: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8006B32C: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x8006B330: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8006B334: addu        $t9, $t5, $v1
    ctx->r25 = ADD32(ctx->r13, ctx->r3);
    // 0x8006B338: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x8006B33C: addu        $t4, $t7, $v1
    ctx->r12 = ADD32(ctx->r15, ctx->r3);
    // 0x8006B340: lwc1        $f14, 0x0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8006B344: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x8006B348: jal         0x8007D2C8
    // 0x8006B34C: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_1;
    // 0x8006B34C: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8006B350: b           L_8006B3C8
    // 0x8006B354: nop

        goto L_8006B3C8;
    // 0x8006B354: nop

    // 0x8006B358: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
L_8006B35C:
    // 0x8006B35C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8006B360: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8006B364: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8006B368: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8006B36C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8006B370: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8006B374: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8006B378: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8006B37C: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8006B380: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8006B384: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8006B388: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8006B38C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8006B390: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x8006B394: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8006B398: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x8006B39C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8006B3A0: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8006B3A4: addu        $t9, $t2, $t5
    ctx->r25 = ADD32(ctx->r10, ctx->r13);
    // 0x8006B3A8: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x8006B3AC: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8006B3B0: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x8006B3B4: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x8006B3B8: lwc1        $f14, 0x0($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8006B3BC: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8006B3C0: jal         0x8007D2C8
    // 0x8006B3C4: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_2;
    // 0x8006B3C4: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_2:
L_8006B3C8:
    // 0x8006B3C8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006B3CC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8006B3D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006B3D4: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8006B3D8: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8006B3DC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8006B3E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006B3E4: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x8006B3E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8006B3EC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006B3F0: jal         0x80019218
    // 0x8006B3F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8006B3F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8006B3F8: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
    // 0x8006B3FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006B400: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8006B404: sh          $t3, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r11;
    // 0x8006B408: lh          $t6, 0x4A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4A);
    // 0x8006B40C: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8006B410: bnel        $at, $zero, L_8006B45C
    if (ctx->r1 != 0) {
        // 0x8006B414: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006B45C;
    }
    goto skip_2;
    // 0x8006B414: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8006B418: jal         0x80060FBC
    // 0x8006B41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x8006B41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006B420: lh          $t5, 0x46($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X46);
    // 0x8006B424: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B428: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006B42C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8006B430: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8006B434: sw          $zero, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = 0;
    // 0x8006B438: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x8006B43C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006B440: lbu         $t7, 0x3C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3C);
    // 0x8006B444: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B448: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8006B44C: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x8006B450: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8006B454: sw          $t3, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r11;
L_8006B458:
    // 0x8006B458: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006B45C:
    // 0x8006B45C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006B460: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8006B464: jr          $ra
    // 0x8006B468: nop

    return;
    // 0x8006B468: nop

;}
RECOMP_FUNC void Audio_UpdateActiveSequences(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800185F8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800185FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80018600: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80018604: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80018608: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8001860C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80018610: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80018614: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x80018618: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8001861C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80018620: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80018624: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80018628: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001862C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80018630: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80018634: addiu       $s6, $s6, -0x5258
    ctx->r22 = ADD32(ctx->r22, -0X5258);
    // 0x80018638: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001863C: addiu       $s7, $zero, 0x258
    ctx->r23 = ADD32(0, 0X258);
    // 0x80018640: lui         $fp, 0xF0
    ctx->r30 = S32(0XF0 << 16);
L_80018644:
    // 0x80018644: multu       $s5, $s7
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018648: mflo        $t6
    ctx->r14 = lo;
    // 0x8001864C: addu        $s3, $s6, $t6
    ctx->r19 = ADD32(ctx->r22, ctx->r14);
    // 0x80018650: lbu         $t7, 0x254($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X254);
    // 0x80018654: beql        $t7, $zero, L_80018698
    if (ctx->r15 == 0) {
        // 0x80018658: lbu         $t8, 0x12($s3)
        ctx->r24 = MEM_BU(ctx->r19, 0X12);
            goto L_80018698;
    }
    goto skip_0;
    // 0x80018658: lbu         $t8, 0x12($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X12);
    skip_0:
    // 0x8001865C: jal         0x8001ECAC
    // 0x80018660: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    AudioThread_GetAsyncLoadStatus(rdram, ctx);
        goto after_0;
    // 0x80018660: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_0:
    // 0x80018664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018668: beq         $v0, $at, L_80018688
    if (ctx->r2 == ctx->r1) {
        // 0x8001866C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80018688;
    }
    // 0x8001866C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80018670: beq         $v0, $at, L_80018688
    if (ctx->r2 == ctx->r1) {
        // 0x80018674: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80018688;
    }
    // 0x80018674: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018678: beq         $v0, $at, L_80018688
    if (ctx->r2 == ctx->r1) {
        // 0x8001867C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80018688;
    }
    // 0x8001867C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80018680: bnel        $v0, $at, L_80018698
    if (ctx->r2 != ctx->r1) {
        // 0x80018684: lbu         $t8, 0x12($s3)
        ctx->r24 = MEM_BU(ctx->r19, 0X12);
            goto L_80018698;
    }
    goto skip_1;
    // 0x80018684: lbu         $t8, 0x12($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X12);
    skip_1:
L_80018688:
    // 0x80018688: sb          $zero, 0x254($s3)
    MEM_B(0X254, ctx->r19) = 0;
    // 0x8001868C: jal         0x800177C8
    // 0x80018690: lw          $a0, 0x250($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X250);
    Audio_ProcessSeqCmd(rdram, ctx);
        goto after_1;
    // 0x80018690: lw          $a0, 0x250($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X250);
    after_1:
    // 0x80018694: lbu         $t8, 0x12($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X12);
L_80018698:
    // 0x80018698: beq         $t8, $zero, L_800187BC
    if (ctx->r24 == 0) {
        // 0x8001869C: sll         $t9, $s5, 2
        ctx->r25 = S32(ctx->r21 << 2);
            goto L_800187BC;
    }
    // 0x8001869C: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x800186A0: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x800186A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800186A8: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x800186AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800186B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800186B4: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x800186B8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800186BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800186C0: addu        $s4, $s6, $t9
    ctx->r20 = ADD32(ctx->r22, ctx->r25);
    // 0x800186C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800186C8: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800186CC: addu        $t2, $s4, $s2
    ctx->r10 = ADD32(ctx->r20, ctx->r18);
L_800186D0:
    // 0x800186D0: lbu         $t3, 0xE($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XE);
    // 0x800186D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800186D8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800186DC: bgez        $t3, L_800186F0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800186E0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800186F0;
    }
    // 0x800186E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800186E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800186E8: nop

    // 0x800186EC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800186F0:
    // 0x800186F0: div.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800186F4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800186F8: andi        $t4, $s2, 0xFF
    ctx->r12 = ctx->r18 & 0XFF;
    // 0x800186FC: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80018700: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x80018704: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80018708: bnel        $at, $zero, L_800186D0
    if (ctx->r1 != 0) {
        // 0x8001870C: addu        $t2, $s4, $s2
        ctx->r10 = ADD32(ctx->r20, ctx->r18);
            goto L_800186D0;
    }
    goto skip_2;
    // 0x8001870C: addu        $t2, $s4, $s2
    ctx->r10 = ADD32(ctx->r20, ctx->r18);
    skip_2:
    // 0x80018710: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80018714: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80018718: lbu         $t5, 0x11($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X11);
    // 0x8001871C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80018720: sll         $t8, $v0, 24
    ctx->r24 = S32(ctx->r2 << 24);
    // 0x80018724: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80018728: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8001872C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80018730: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80018734: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80018738: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001873C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80018740: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80018744: nop

    // 0x80018748: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8001874C: beql        $t3, $zero, L_8001879C
    if (ctx->r11 == 0) {
        // 0x80018750: mfc1        $t3, $f18
        ctx->r11 = (int32_t)ctx->f18.u32l;
            goto L_8001879C;
    }
    goto skip_3;
    // 0x80018750: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x80018754: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018758: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001875C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80018760: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80018764: nop

    // 0x80018768: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8001876C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80018770: nop

    // 0x80018774: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80018778: bne         $t3, $zero, L_80018790
    if (ctx->r11 != 0) {
        // 0x8001877C: nop
    
            goto L_80018790;
    }
    // 0x8001877C: nop

    // 0x80018780: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80018784: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80018788: b           L_800187A8
    // 0x8001878C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800187A8;
    // 0x8001878C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80018790:
    // 0x80018790: b           L_800187A8
    // 0x80018794: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800187A8;
    // 0x80018794: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80018798: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
L_8001879C:
    // 0x8001879C: nop

    // 0x800187A0: bltz        $t3, L_80018790
    if (SIGNED(ctx->r11) < 0) {
        // 0x800187A4: nop
    
            goto L_80018790;
    }
    // 0x800187A4: nop

L_800187A8:
    // 0x800187A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800187AC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800187B0: jal         0x800182F4
    // 0x800187B4: or          $a0, $t9, $t4
    ctx->r4 = ctx->r25 | ctx->r12;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x800187B4: or          $a0, $t9, $t4
    ctx->r4 = ctx->r25 | ctx->r12;
    after_2:
    // 0x800187B8: sb          $zero, 0x12($s3)
    MEM_B(0X12, ctx->r19) = 0;
L_800187BC:
    // 0x800187BC: lhu         $v0, 0xC($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0XC);
    // 0x800187C0: beq         $v0, $zero, L_80018808
    if (ctx->r2 == 0) {
        // 0x800187C4: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80018808;
    }
    // 0x800187C4: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800187C8: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800187CC: beq         $t6, $zero, L_800187E8
    if (ctx->r14 == 0) {
        // 0x800187D0: sh          $t5, 0xC($s3)
        MEM_H(0XC, ctx->r19) = ctx->r13;
            goto L_800187E8;
    }
    // 0x800187D0: sh          $t5, 0xC($s3)
    MEM_H(0XC, ctx->r19) = ctx->r13;
    // 0x800187D4: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800187D8: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800187DC: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800187E0: b           L_800187F0
    // 0x800187E4: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
        goto L_800187F0;
    // 0x800187E4: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
L_800187E8:
    // 0x800187E8: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800187EC: swc1        $f10, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f10.u32l;
L_800187F0:
    // 0x800187F0: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x800187F4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800187F8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800187FC: or          $a0, $t7, $at
    ctx->r4 = ctx->r15 | ctx->r1;
    // 0x80018800: jal         0x8001E8A8
    // 0x80018804: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_3;
    // 0x80018804: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_3:
L_80018808:
    // 0x80018808: lw          $a1, 0x14($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X14);
    // 0x8001880C: beq         $a1, $zero, L_80018A64
    if (ctx->r5 == 0) {
        // 0x80018810: lui         $at, 0xFF
        ctx->r1 = S32(0XFF << 16);
            goto L_80018A64;
    }
    // 0x80018810: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80018814: and         $v0, $a1, $at
    ctx->r2 = ctx->r5 & ctx->r1;
    // 0x80018818: srl         $t2, $v0, 15
    ctx->r10 = S32(U32(ctx->r2) >> 15);
    // 0x8001881C: andi        $a0, $a1, 0xFFF
    ctx->r4 = ctx->r5 & 0XFFF;
    // 0x80018820: andi        $a3, $t2, 0xFF
    ctx->r7 = ctx->r10 & 0XFF;
    // 0x80018824: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80018828: andi        $t0, $t2, 0xFF
    ctx->r8 = ctx->r10 & 0XFF;
    // 0x8001882C: bne         $a3, $zero, L_80018840
    if (ctx->r7 != 0) {
        // 0x80018830: andi        $a2, $a0, 0xFFFF
        ctx->r6 = ctx->r4 & 0XFFFF;
            goto L_80018840;
    }
    // 0x80018830: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x80018834: addiu       $t0, $a3, 0x1
    ctx->r8 = ADD32(ctx->r7, 0X1);
    // 0x80018838: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x8001883C: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
L_80018840:
    // 0x80018840: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80018844: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x80018848: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001884C: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x80018850: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80018854: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80018858: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001885C: addiu       $t4, $t4, -0x1AC8
    ctx->r12 = ADD32(ctx->r12, -0X1AC8);
    // 0x80018860: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80018864: addu        $a1, $t9, $t4
    ctx->r5 = ADD32(ctx->r25, ctx->r12);
    // 0x80018868: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8001886C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80018870: andi        $v0, $v1, 0xF000
    ctx->r2 = ctx->r3 & 0XF000;
    // 0x80018874: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80018878: beql        $t6, $zero, L_80018A68
    if (ctx->r14 == 0) {
        // 0x8001887C: lhu         $v0, 0x28($s3)
        ctx->r2 = MEM_HU(ctx->r19, 0X28);
            goto L_80018A68;
    }
    goto skip_4;
    // 0x8001887C: lhu         $v0, 0x28($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X28);
    skip_4:
    // 0x80018880: lhu         $t1, 0x8($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X8);
    // 0x80018884: srl         $t8, $v0, 12
    ctx->r24 = S32(U32(ctx->r2) >> 12);
    // 0x80018888: andi        $t2, $t8, 0xFF
    ctx->r10 = ctx->r24 & 0XFF;
    // 0x8001888C: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80018890: mflo        $t1
    ctx->r9 = lo;
    // 0x80018894: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018898: beq         $t2, $at, L_800188CC
    if (ctx->r10 == ctx->r1) {
        // 0x8001889C: andi        $a3, $t1, 0xFFFF
        ctx->r7 = ctx->r9 & 0XFFFF;
            goto L_800188CC;
    }
    // 0x8001889C: andi        $a3, $t1, 0xFFFF
    ctx->r7 = ctx->r9 & 0XFFFF;
    // 0x800188A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800188A4: beq         $t2, $at, L_800188E0
    if (ctx->r10 == ctx->r1) {
        // 0x800188A8: andi        $v1, $a0, 0xFFFF
        ctx->r3 = ctx->r4 & 0XFFFF;
            goto L_800188E0;
    }
    // 0x800188A8: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800188AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800188B0: beq         $t2, $at, L_80018900
    if (ctx->r10 == ctx->r1) {
        // 0x800188B4: andi        $t5, $a0, 0xFFFF
        ctx->r13 = ctx->r4 & 0XFFFF;
            goto L_80018900;
    }
    // 0x800188B4: andi        $t5, $a0, 0xFFFF
    ctx->r13 = ctx->r4 & 0XFFFF;
    // 0x800188B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800188BC: beql        $t2, $at, L_800189E0
    if (ctx->r10 == ctx->r1) {
        // 0x800188C0: lhu         $v0, 0x18($s3)
        ctx->r2 = MEM_HU(ctx->r19, 0X18);
            goto L_800189E0;
    }
    goto skip_5;
    // 0x800188C0: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
    skip_5:
    // 0x800188C4: b           L_800189F4
    // 0x800188C8: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
        goto L_800189F4;
    // 0x800188C8: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
L_800188CC:
    // 0x800188CC: addu        $a2, $a0, $a3
    ctx->r6 = ADD32(ctx->r4, ctx->r7);
    // 0x800188D0: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x800188D4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800188D8: b           L_800189F4
    // 0x800188DC: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
        goto L_800189F4;
    // 0x800188DC: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
L_800188E0:
    // 0x800188E0: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800188E4: beq         $at, $zero, L_800188F8
    if (ctx->r1 == 0) {
        // 0x800188E8: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_800188F8;
    }
    // 0x800188E8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800188EC: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    // 0x800188F0: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x800188F4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
L_800188F8:
    // 0x800188F8: b           L_800189F4
    // 0x800188FC: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
        goto L_800189F4;
    // 0x800188FC: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
L_80018900:
    // 0x80018900: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80018904: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x80018908: bgez        $t5, L_80018920
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001890C: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80018920;
    }
    // 0x8001890C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80018910: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018914: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018918: nop

    // 0x8001891C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80018920:
    // 0x80018920: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80018924: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018928: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001892C: bgez        $a3, L_80018944
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80018930: div.s       $f6, $f18, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
            goto L_80018944;
    }
    // 0x80018930: div.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80018934: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018938: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001893C: nop

    // 0x80018940: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80018944:
    // 0x80018944: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80018948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001894C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80018950: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80018954: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x80018958: nop

    // 0x8001895C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80018960: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x80018964: nop

    // 0x80018968: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8001896C: beql        $a2, $zero, L_800189BC
    if (ctx->r6 == 0) {
        // 0x80018970: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_800189BC;
    }
    goto skip_6;
    // 0x80018970: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x80018974: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018978: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001897C: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80018980: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x80018984: nop

    // 0x80018988: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001898C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x80018990: nop

    // 0x80018994: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x80018998: bne         $a2, $zero, L_800189B0
    if (ctx->r6 != 0) {
        // 0x8001899C: nop
    
            goto L_800189B0;
    }
    // 0x8001899C: nop

    // 0x800189A0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800189A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800189A8: b           L_800189C8
    // 0x800189AC: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_800189C8;
    // 0x800189AC: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_800189B0:
    // 0x800189B0: b           L_800189C8
    // 0x800189B4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_800189C8;
    // 0x800189B4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800189B8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_800189BC:
    // 0x800189BC: nop

    // 0x800189C0: bltz        $a2, L_800189B0
    if (SIGNED(ctx->r6) < 0) {
        // 0x800189C4: nop
    
            goto L_800189B0;
    }
    // 0x800189C4: nop

L_800189C8:
    // 0x800189C8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800189CC: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800189D0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800189D4: b           L_800189F4
    // 0x800189D8: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
        goto L_800189F4;
    // 0x800189D8: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
    // 0x800189DC: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
L_800189E0:
    // 0x800189E0: andi        $a2, $a3, 0xFFFF
    ctx->r6 = ctx->r7 & 0XFFFF;
    // 0x800189E4: beq         $v0, $zero, L_800189F4
    if (ctx->r2 == 0) {
        // 0x800189E8: nop
    
            goto L_800189F4;
    }
    // 0x800189E8: nop

    // 0x800189EC: b           L_800189F4
    // 0x800189F0: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
        goto L_800189F4;
    // 0x800189F0: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
L_800189F4:
    // 0x800189F4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800189F8: slti        $at, $a2, 0x12D
    ctx->r1 = SIGNED(ctx->r6) < 0X12D ? 1 : 0;
    // 0x800189FC: bne         $at, $zero, L_80018A08
    if (ctx->r1 != 0) {
        // 0x80018A00: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80018A08;
    }
    // 0x80018A00: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80018A04: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
L_80018A08:
    // 0x80018A08: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x80018A0C: bne         $v0, $zero, L_80018A18
    if (ctx->r2 != 0) {
        // 0x80018A10: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_80018A18;
    }
    // 0x80018A10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018A14: sh          $a3, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r7;
L_80018A18:
    // 0x80018A18: bgez        $a2, L_80018A2C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80018A1C: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80018A2C;
    }
    // 0x80018A1C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018A20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018A24: nop

    // 0x80018A28: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80018A2C:
    // 0x80018A2C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80018A30: swc1        $f0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f0.u32l;
    // 0x80018A34: swc1        $f2, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f2.u32l;
    // 0x80018A38: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80018A3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018A40: bgez        $t0, L_80018A54
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80018A44: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80018A54;
    }
    // 0x80018A44: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80018A48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018A4C: nop

    // 0x80018A50: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80018A54:
    // 0x80018A54: div.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80018A58: sh          $t0, 0x28($s3)
    MEM_H(0X28, ctx->r19) = ctx->r8;
    // 0x80018A5C: sw          $zero, 0x14($s3)
    MEM_W(0X14, ctx->r19) = 0;
    // 0x80018A60: swc1        $f4, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f4.u32l;
L_80018A64:
    // 0x80018A64: lhu         $v0, 0x28($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X28);
L_80018A68:
    // 0x80018A68: beq         $v0, $zero, L_80018AC0
    if (ctx->r2 == 0) {
        // 0x80018A6C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80018AC0;
    }
    // 0x80018A6C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80018A70: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x80018A74: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80018A78: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x80018A7C: sh          $t8, 0x28($s3)
    MEM_H(0X28, ctx->r19) = ctx->r24;
    // 0x80018A80: beq         $t3, $zero, L_80018A9C
    if (ctx->r11 == 0) {
        // 0x80018A84: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80018A9C;
    }
    // 0x80018A84: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80018A88: lwc1        $f16, 0x1C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80018A8C: lwc1        $f18, 0x24($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80018A90: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80018A94: b           L_80018AA4
    // 0x80018A98: swc1        $f10, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f10.u32l;
        goto L_80018AA4;
    // 0x80018A98: swc1        $f10, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f10.u32l;
L_80018A9C:
    // 0x80018A9C: lwc1        $f6, 0x20($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80018AA0: swc1        $f6, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f6.u32l;
L_80018AA4:
    // 0x80018AA4: lwc1        $f8, 0x1C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80018AA8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80018AAC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80018AB0: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80018AB4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80018AB8: jal         0x8001E8CC
    // 0x80018ABC: nop

    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_4;
    // 0x80018ABC: nop

    after_4:
L_80018AC0:
    // 0x80018AC0: lhu         $t4, 0x246($s3)
    ctx->r12 = MEM_HU(ctx->r19, 0X246);
    // 0x80018AC4: beq         $t4, $zero, L_80018B78
    if (ctx->r12 == 0) {
        // 0x80018AC8: sll         $t5, $s5, 2
        ctx->r13 = S32(ctx->r21 << 2);
            goto L_80018B78;
    }
    // 0x80018AC8: sll         $t5, $s5, 2
    ctx->r13 = S32(ctx->r21 << 2);
    // 0x80018ACC: addu        $t5, $t5, $s5
    ctx->r13 = ADD32(ctx->r13, ctx->r21);
    // 0x80018AD0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80018AD4: subu        $t5, $t5, $s5
    ctx->r13 = SUB32(ctx->r13, ctx->r21);
    // 0x80018AD8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80018ADC: subu        $t5, $t5, $s5
    ctx->r13 = SUB32(ctx->r13, ctx->r21);
    // 0x80018AE0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80018AE4: addu        $s4, $s6, $t5
    ctx->r20 = ADD32(ctx->r22, ctx->r13);
    // 0x80018AE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80018AEC:
    // 0x80018AEC: sll         $a0, $s0, 5
    ctx->r4 = S32(ctx->r16 << 5);
    // 0x80018AF0: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
    // 0x80018AF4: lhu         $v1, 0x50($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X50);
    // 0x80018AF8: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // 0x80018AFC: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80018B00: beq         $v1, $zero, L_80018B64
    if (ctx->r3 == 0) {
        // 0x80018B04: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80018B64;
    }
    // 0x80018B04: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80018B08: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80018B0C: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x80018B10: sh          $t6, 0x50($v0)
    MEM_H(0X50, ctx->r2) = ctx->r14;
    // 0x80018B14: beq         $t2, $zero, L_80018B30
    if (ctx->r10 == 0) {
        // 0x80018B18: or          $a2, $t7, $at
        ctx->r6 = ctx->r15 | ctx->r1;
            goto L_80018B30;
    }
    // 0x80018B18: or          $a2, $t7, $at
    ctx->r6 = ctx->r15 | ctx->r1;
    // 0x80018B1C: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80018B20: lwc1        $f18, 0x4C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80018B24: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80018B28: b           L_80018B50
    // 0x80018B2C: swc1        $f10, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f10.u32l;
        goto L_80018B50;
    // 0x80018B2C: swc1        $f10, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f10.u32l;
L_80018B30:
    // 0x80018B30: addu        $v1, $s3, $a0
    ctx->r3 = ADD32(ctx->r19, ctx->r4);
    // 0x80018B34: lwc1        $f6, 0x48($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80018B38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80018B3C: sllv        $t4, $t9, $s0
    ctx->r12 = S32(ctx->r25 << (ctx->r16 & 31));
    // 0x80018B40: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80018B44: lhu         $t3, 0x246($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X246);
    // 0x80018B48: xor         $t5, $t3, $t4
    ctx->r13 = ctx->r11 ^ ctx->r12;
    // 0x80018B4C: sh          $t5, 0x246($s3)
    MEM_H(0X246, ctx->r19) = ctx->r13;
L_80018B50:
    // 0x80018B50: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x80018B54: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80018B58: or          $a0, $a2, $t7
    ctx->r4 = ctx->r6 | ctx->r15;
    // 0x80018B5C: jal         0x8001E8A8
    // 0x80018B60: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_5;
    // 0x80018B60: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    after_5:
L_80018B64:
    // 0x80018B64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80018B68: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x80018B6C: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80018B70: bne         $at, $zero, L_80018AEC
    if (ctx->r1 != 0) {
        // 0x80018B74: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80018AEC;
    }
    // 0x80018B74: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_80018B78:
    // 0x80018B78: lhu         $t2, 0x244($s3)
    ctx->r10 = MEM_HU(ctx->r19, 0X244);
    // 0x80018B7C: beq         $t2, $zero, L_80018C30
    if (ctx->r10 == 0) {
        // 0x80018B80: sll         $t9, $s5, 2
        ctx->r25 = S32(ctx->r21 << 2);
            goto L_80018C30;
    }
    // 0x80018B80: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80018B84: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x80018B88: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80018B8C: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80018B90: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80018B94: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80018B98: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80018B9C: addu        $s4, $s6, $t9
    ctx->r20 = ADD32(ctx->r22, ctx->r25);
    // 0x80018BA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80018BA4:
    // 0x80018BA4: sll         $a0, $s0, 5
    ctx->r4 = S32(ctx->r16 << 5);
    // 0x80018BA8: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
    // 0x80018BAC: lhu         $v1, 0x60($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X60);
    // 0x80018BB0: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // 0x80018BB4: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80018BB8: beq         $v1, $zero, L_80018C1C
    if (ctx->r3 == 0) {
        // 0x80018BBC: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80018C1C;
    }
    // 0x80018BBC: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80018BC0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80018BC4: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x80018BC8: sh          $t3, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r11;
    // 0x80018BCC: beq         $t6, $zero, L_80018BE8
    if (ctx->r14 == 0) {
        // 0x80018BD0: or          $a2, $t4, $at
        ctx->r6 = ctx->r12 | ctx->r1;
            goto L_80018BE8;
    }
    // 0x80018BD0: or          $a2, $t4, $at
    ctx->r6 = ctx->r12 | ctx->r1;
    // 0x80018BD4: lwc1        $f8, 0x54($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80018BD8: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80018BDC: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80018BE0: b           L_80018C08
    // 0x80018BE4: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
        goto L_80018C08;
    // 0x80018BE4: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
L_80018BE8:
    // 0x80018BE8: addu        $v1, $s3, $a0
    ctx->r3 = ADD32(ctx->r19, ctx->r4);
    // 0x80018BEC: lwc1        $f18, 0x58($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80018BF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80018BF4: sllv        $t2, $t8, $s0
    ctx->r10 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x80018BF8: swc1        $f18, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f18.u32l;
    // 0x80018BFC: lhu         $t7, 0x244($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X244);
    // 0x80018C00: xor         $t9, $t7, $t2
    ctx->r25 = ctx->r15 ^ ctx->r10;
    // 0x80018C04: sh          $t9, 0x244($s3)
    MEM_H(0X244, ctx->r19) = ctx->r25;
L_80018C08:
    // 0x80018C08: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x80018C0C: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80018C10: or          $a0, $a2, $t4
    ctx->r4 = ctx->r6 | ctx->r12;
    // 0x80018C14: jal         0x8001E8A8
    // 0x80018C18: lw          $a1, 0x54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X54);
    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_6;
    // 0x80018C18: lw          $a1, 0x54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X54);
    after_6:
L_80018C1C:
    // 0x80018C1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80018C20: andi        $t5, $s0, 0xFF
    ctx->r13 = ctx->r16 & 0XFF;
    // 0x80018C24: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x80018C28: bne         $at, $zero, L_80018BA4
    if (ctx->r1 != 0) {
        // 0x80018C2C: or          $s0, $t5, $zero
        ctx->r16 = ctx->r13 | 0;
            goto L_80018BA4;
    }
    // 0x80018C2C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_80018C30:
    // 0x80018C30: lbu         $t6, 0x41($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X41);
    // 0x80018C34: beq         $t6, $zero, L_80018E54
    if (ctx->r14 == 0) {
        // 0x80018C38: lui         $a0, 0xF000
        ctx->r4 = S32(0XF000 << 16);
            goto L_80018E54;
    }
    // 0x80018C38: lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // 0x80018C3C: jal         0x80018470
    // 0x80018C40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    Audio_SeqCmdValueNotQueued(rdram, ctx);
        goto after_7;
    // 0x80018C40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_7:
    // 0x80018C44: bnel        $v0, $zero, L_80018C58
    if (ctx->r2 != 0) {
        // 0x80018C48: lbu         $v0, 0x40($s3)
        ctx->r2 = MEM_BU(ctx->r19, 0X40);
            goto L_80018C58;
    }
    goto skip_7;
    // 0x80018C48: lbu         $v0, 0x40($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X40);
    skip_7:
    // 0x80018C4C: b           L_80018E68
    // 0x80018C50: sb          $zero, 0x41($s3)
    MEM_B(0X41, ctx->r19) = 0;
        goto L_80018E68;
    // 0x80018C50: sb          $zero, 0x41($s3)
    MEM_B(0X41, ctx->r19) = 0;
    // 0x80018C54: lbu         $v0, 0x40($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X40);
L_80018C58:
    // 0x80018C58: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x80018C5C: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x80018C60: beq         $v0, $zero, L_80018C74
    if (ctx->r2 == 0) {
        // 0x80018C64: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80018C74;
    }
    // 0x80018C64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018C68: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80018C6C: b           L_80018E54
    // 0x80018C70: sb          $t8, 0x40($s3)
    MEM_B(0X40, ctx->r19) = ctx->r24;
        goto L_80018E54;
    // 0x80018C70: sb          $t8, 0x40($s3)
    MEM_B(0X40, ctx->r19) = ctx->r24;
L_80018C74:
    // 0x80018C74: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x80018C78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018C7C: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80018C80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018C84: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80018C88: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x80018C8C: lw          $t2, -0x1AC8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1AC8);
    // 0x80018C90: srl         $t9, $t2, 31
    ctx->r25 = S32(U32(ctx->r10) >> 31);
    // 0x80018C94: bnel        $t9, $zero, L_80018E58
    if (ctx->r25 != 0) {
        // 0x80018C98: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80018E58;
    }
    goto skip_8;
    // 0x80018C98: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_8:
    // 0x80018C9C: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
    // 0x80018CA0: sll         $t3, $s5, 2
    ctx->r11 = S32(ctx->r21 << 2);
    // 0x80018CA4: addu        $t3, $t3, $s5
    ctx->r11 = ADD32(ctx->r11, ctx->r21);
    // 0x80018CA8: blez        $v1, L_80018E50
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80018CAC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80018E50;
    }
    // 0x80018CAC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80018CB0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80018CB4: subu        $t3, $t3, $s5
    ctx->r11 = SUB32(ctx->r11, ctx->r21);
    // 0x80018CB8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80018CBC: subu        $t3, $t3, $s5
    ctx->r11 = SUB32(ctx->r11, ctx->r21);
    // 0x80018CC0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80018CC4: addu        $s4, $s6, $t3
    ctx->r20 = ADD32(ctx->r22, ctx->r11);
L_80018CC8:
    // 0x80018CC8: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x80018CCC: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x80018CD0: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x80018CD4: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80018CD8: and         $a0, $v0, $fp
    ctx->r4 = ctx->r2 & ctx->r30;
    // 0x80018CDC: srl         $t6, $a0, 20
    ctx->r14 = S32(U32(ctx->r4) >> 20);
    // 0x80018CE0: and         $s1, $v0, $at
    ctx->r17 = ctx->r2 & ctx->r1;
    // 0x80018CE4: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80018CE8: andi        $a3, $v0, 0xFF00
    ctx->r7 = ctx->r2 & 0XFF00;
    // 0x80018CEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80018CF0: srl         $t7, $s1, 16
    ctx->r15 = S32(U32(ctx->r17) >> 16);
    // 0x80018CF4: srl         $t9, $a3, 8
    ctx->r25 = S32(U32(ctx->r7) >> 8);
    // 0x80018CF8: andi        $t4, $a1, 0xFF
    ctx->r12 = ctx->r5 & 0XFF;
    // 0x80018CFC: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80018D00: andi        $s1, $t7, 0xFF
    ctx->r17 = ctx->r15 & 0XFF;
    // 0x80018D04: andi        $a3, $t9, 0xFF
    ctx->r7 = ctx->r25 & 0XFF;
    // 0x80018D08: beq         $at, $zero, L_80018E3C
    if (ctx->r1 == 0) {
        // 0x80018D0C: or          $a1, $t4, $zero
        ctx->r5 = ctx->r12 | 0;
            goto L_80018E3C;
    }
    // 0x80018D0C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80018D10: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80018D14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018D18: addu        $at, $at, $t5
    gpr jr_addend_80018D20 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80018D1C: lw          $t5, -0x6F88($at)
    ctx->r13 = ADD32(ctx->r1, -0X6F88);
    // 0x80018D20: jr          $t5
    // 0x80018D24: nop

    switch (jr_addend_80018D20 >> 2) {
        case 0: goto L_80018D28; break;
        case 1: goto L_80018D40; break;
        case 2: goto L_80018D60; break;
        case 3: goto L_80018DA0; break;
        case 4: goto L_80018DC8; break;
        case 5: goto L_80018DEC; break;
        case 6: goto L_80018E34; break;
        default: switch_error(__func__, 0x80018D20, 0x800C9078);
    }
    // 0x80018D24: nop

L_80018D28:
    // 0x80018D28: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80018D2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80018D30: jal         0x800185A0
    // 0x80018D34: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_8;
    // 0x80018D34: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    after_8:
    // 0x80018D38: b           L_80018E3C
    // 0x80018D3C: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
        goto L_80018E3C;
    // 0x80018D3C: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
L_80018D40:
    // 0x80018D40: lhu         $t6, 0x248($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X248);
    // 0x80018D44: lui         $at, 0x3000
    ctx->r1 = S32(0X3000 << 16);
    // 0x80018D48: sll         $t7, $s5, 24
    ctx->r15 = S32(ctx->r21 << 24);
    // 0x80018D4C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80018D50: jal         0x800182F4
    // 0x80018D54: or          $a0, $t8, $t7
    ctx->r4 = ctx->r24 | ctx->r15;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_9;
    // 0x80018D54: or          $a0, $t8, $t7
    ctx->r4 = ctx->r24 | ctx->r15;
    after_9:
    // 0x80018D58: b           L_80018E3C
    // 0x80018D5C: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
        goto L_80018E3C;
    // 0x80018D5C: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
L_80018D60:
    // 0x80018D60: multu       $s1, $s7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018D64: sll         $t3, $s1, 24
    ctx->r11 = S32(ctx->r17 << 24);
    // 0x80018D68: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80018D6C: mflo        $t2
    ctx->r10 = lo;
    // 0x80018D70: addu        $s0, $s6, $t2
    ctx->r16 = ADD32(ctx->r22, ctx->r10);
    // 0x80018D74: lhu         $t9, 0x248($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X248);
    // 0x80018D78: or          $a0, $t9, $t3
    ctx->r4 = ctx->r25 | ctx->r11;
    // 0x80018D7C: or          $t4, $a0, $at
    ctx->r12 = ctx->r4 | ctx->r1;
    // 0x80018D80: jal         0x800182F4
    // 0x80018D84: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_10;
    // 0x80018D84: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_10:
    // 0x80018D88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80018D8C: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x80018D90: sb          $t5, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r13;
    // 0x80018D94: sb          $t6, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r14;
    // 0x80018D98: b           L_80018E3C
    // 0x80018D9C: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
        goto L_80018E3C;
    // 0x80018D9C: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
L_80018DA0:
    // 0x80018DA0: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80018DA4: ori         $at, $at, 0x3000
    ctx->r1 = ctx->r1 | 0X3000;
    // 0x80018DA8: sll         $t8, $s1, 24
    ctx->r24 = S32(ctx->r17 << 24);
    // 0x80018DAC: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80018DB0: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x80018DB4: or          $t9, $t7, $t2
    ctx->r25 = ctx->r15 | ctx->r10;
    // 0x80018DB8: jal         0x800182F4
    // 0x80018DBC: or          $a0, $t9, $a1
    ctx->r4 = ctx->r25 | ctx->r5;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_11;
    // 0x80018DBC: or          $a0, $t9, $a1
    ctx->r4 = ctx->r25 | ctx->r5;
    after_11:
    // 0x80018DC0: b           L_80018E3C
    // 0x80018DC4: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
        goto L_80018E3C;
    // 0x80018DC4: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
L_80018DC8:
    // 0x80018DC8: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80018DCC: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80018DD0: sll         $t3, $s1, 24
    ctx->r11 = S32(ctx->r17 << 24);
    // 0x80018DD4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80018DD8: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80018DDC: jal         0x800182F4
    // 0x80018DE0: or          $a0, $t4, $t5
    ctx->r4 = ctx->r12 | ctx->r13;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_12;
    // 0x80018DE0: or          $a0, $t4, $t5
    ctx->r4 = ctx->r12 | ctx->r13;
    after_12:
    // 0x80018DE4: b           L_80018E3C
    // 0x80018DE8: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
        goto L_80018E3C;
    // 0x80018DE8: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
L_80018DEC:
    // 0x80018DEC: multu       $s1, $s7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018DF0: sll         $t9, $s1, 24
    ctx->r25 = S32(ctx->r17 << 24);
    // 0x80018DF4: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x80018DF8: mflo        $t8
    ctx->r24 = lo;
    // 0x80018DFC: addu        $s0, $s6, $t8
    ctx->r16 = ADD32(ctx->r22, ctx->r24);
    // 0x80018E00: lbu         $t7, 0x42($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X42);
    // 0x80018E04: sll         $t2, $t7, 16
    ctx->r10 = S32(ctx->r15 << 16);
    // 0x80018E08: or          $t3, $t2, $t9
    ctx->r11 = ctx->r10 | ctx->r25;
    // 0x80018E0C: jal         0x800182F4
    // 0x80018E10: or          $a0, $t3, $t6
    ctx->r4 = ctx->r11 | ctx->r14;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_13;
    // 0x80018E10: or          $a0, $t3, $t6
    ctx->r4 = ctx->r11 | ctx->r14;
    after_13:
    // 0x80018E14: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80018E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80018E1C: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80018E20: jal         0x800185A0
    // 0x80018E24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Audio_SetSequenceFade(rdram, ctx);
        goto after_14;
    // 0x80018E24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80018E28: sb          $zero, 0x42($s0)
    MEM_B(0X42, ctx->r16) = 0;
    // 0x80018E2C: b           L_80018E3C
    // 0x80018E30: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
        goto L_80018E3C;
    // 0x80018E30: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
L_80018E34:
    // 0x80018E34: sb          $a3, 0x42($s3)
    MEM_B(0X42, ctx->r19) = ctx->r7;
    // 0x80018E38: lbu         $v1, 0x41($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X41);
L_80018E3C:
    // 0x80018E3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80018E40: andi        $t4, $s2, 0xFF
    ctx->r12 = ctx->r18 & 0XFF;
    // 0x80018E44: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018E48: bne         $at, $zero, L_80018CC8
    if (ctx->r1 != 0) {
        // 0x80018E4C: or          $s2, $t4, $zero
        ctx->r18 = ctx->r12 | 0;
            goto L_80018CC8;
    }
    // 0x80018E4C: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
L_80018E50:
    // 0x80018E50: sb          $zero, 0x41($s3)
    MEM_B(0X41, ctx->r19) = 0;
L_80018E54:
    // 0x80018E54: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80018E58:
    // 0x80018E58: andi        $t5, $s5, 0xFF
    ctx->r13 = ctx->r21 & 0XFF;
    // 0x80018E5C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80018E60: bne         $at, $zero, L_80018644
    if (ctx->r1 != 0) {
        // 0x80018E64: or          $s5, $t5, $zero
        ctx->r21 = ctx->r13 | 0;
            goto L_80018644;
    }
    // 0x80018E64: or          $s5, $t5, $zero
    ctx->r21 = ctx->r13 | 0;
L_80018E68:
    // 0x80018E68: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80018E6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80018E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80018E74: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80018E78: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80018E7C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80018E80: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80018E84: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80018E88: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80018E8C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80018E90: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80018E94: jr          $ra
    // 0x80018E98: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80018E98: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void PlayerShot_LaserMark1_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800366CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800366D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800366D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800366D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800366DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800366E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800366E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800366E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800366EC: jal         0x80061474
    // 0x800366F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x800366F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800366F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800366F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800366FC: addiu       $t7, $zero, 0x159
    ctx->r15 = ADD32(0, 0X159);
    // 0x80036700: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80036704: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80036708: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003670C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80036710: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80036714: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80036718: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003671C: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x80036720: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80036724: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80036728: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003672C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80036730: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80036734: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80036738: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x8003673C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80036740: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    // 0x80036744: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80036748: jal         0x800612B8
    // 0x8003674C: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8003674C: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
    after_1:
    // 0x80036750: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80036754: lui         $a1, 0x2900
    ctx->r5 = S32(0X2900 << 16);
    // 0x80036758: jal         0x800A6070
    // 0x8003675C: addiu       $a0, $a2, 0x80
    ctx->r4 = ADD32(ctx->r6, 0X80);
    Play_PlaySfxNoPlayer(rdram, ctx);
        goto after_2;
    // 0x8003675C: addiu       $a0, $a2, 0x80
    ctx->r4 = ADD32(ctx->r6, 0X80);
    after_2:
    // 0x80036760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036768: jr          $ra
    // 0x8003676C: nop

    return;
    // 0x8003676C: nop

;}
RECOMP_FUNC void Play_Setup360_AND(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A57E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A57E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A57E8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A57EC: jal         0x80061404
    // 0x800A57F0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A57F0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_0:
    // 0x800A57F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A57F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A57FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5800: sb          $t6, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r14;
    // 0x800A5804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5808: swc1        $f0, -0xEEC($at)
    MEM_W(-0XEEC, ctx->r1) = ctx->f0.u32l;
    // 0x800A580C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5810: swc1        $f0, -0xEE8($at)
    MEM_W(-0XEE8, ctx->r1) = ctx->f0.u32l;
    // 0x800A5814: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5818: swc1        $f0, -0xEE4($at)
    MEM_W(-0XEE4, ctx->r1) = ctx->f0.u32l;
    // 0x800A581C: addiu       $a1, $zero, 0x141
    ctx->r5 = ADD32(0, 0X141);
    // 0x800A5820: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5824: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5828: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x800A582C: jal         0x800612B8
    // 0x800A5830: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800A5830: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_1:
    // 0x800A5834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A583C: jr          $ra
    // 0x800A5840: nop

    return;
    // 0x800A5840: nop

;}
RECOMP_FUNC void Venom1_LevelStart2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096A74: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80096A78: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80096A7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80096A80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80096A84: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80096A88: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80096A8C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x80096A90: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80096A94: addiu       $v1, $v1, -0x7CA8
    ctx->r3 = ADD32(ctx->r3, -0X7CA8);
    // 0x80096A98: beq         $v0, $zero, L_80096ACC
    if (ctx->r2 == 0) {
        // 0x80096A9C: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_80096ACC;
    }
    // 0x80096A9C: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80096AA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80096AA4: beq         $v0, $at, L_80096BBC
    if (ctx->r2 == ctx->r1) {
        // 0x80096AA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80096BBC;
    }
    // 0x80096AA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80096AAC: beq         $v0, $at, L_80096E14
    if (ctx->r2 == ctx->r1) {
        // 0x80096AB0: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_80096E14;
    }
    // 0x80096AB0: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80096AB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096AB8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80096ABC: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80096AC0: addiu       $s1, $s1, 0x7A48
    ctx->r17 = ADD32(ctx->r17, 0X7A48);
    // 0x80096AC4: b           L_80097018
    // 0x80096AC8: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_80097018;
    // 0x80096AC8: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80096ACC:
    // 0x80096ACC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096AD0: lwc1        $f6, -0x7E5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7E5C);
    // 0x80096AD4: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80096AD8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80096ADC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80096AE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80096AE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80096AE8: swc1        $f10, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f10.u32l;
    // 0x80096AEC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80096AF0: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x80096AF4: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80096AF8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80096AFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80096B00: addiu       $s1, $s1, 0x7A48
    ctx->r17 = ADD32(ctx->r17, 0X7A48);
    // 0x80096B04: swc1        $f20, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f20.u32l;
    // 0x80096B08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096B0C: swc1        $f20, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
    // 0x80096B10: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x80096B14: lwc1        $f18, -0x7E58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7E58);
    // 0x80096B18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096B1C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80096B20: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x80096B24: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80096B28: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
    // 0x80096B2C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80096B30: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80096B34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80096B38: sw          $t8, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r24;
    // 0x80096B3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096B40: swc1        $f20, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f20.u32l;
    // 0x80096B44: lwc1        $f4, 0x7978($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x80096B48: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80096B4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096B50: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x80096B54: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80096B58: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80096B5C: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x80096B60: lwc1        $f16, 0x7980($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x80096B64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096B68: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x80096B6C: swc1        $f20, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f20.u32l;
    // 0x80096B70: lwc1        $f18, 0x7988($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x80096B74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096B78: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80096B7C: swc1        $f20, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f20.u32l;
    // 0x80096B80: lwc1        $f4, 0x79A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x80096B84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096B88: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x80096B8C: swc1        $f20, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f20.u32l;
    // 0x80096B90: lwc1        $f6, 0x79B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80096B94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096B98: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80096B9C: swc1        $f20, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f20.u32l;
    // 0x80096BA0: lwc1        $f8, 0x79C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x80096BA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80096BA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80096BAC: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80096BB0: swc1        $f20, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
    // 0x80096BB4: swc1        $f20, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f20.u32l;
    // 0x80096BB8: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_80096BBC:
    // 0x80096BBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096BC0: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80096BC4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80096BC8: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80096BCC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80096BD0: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80096BD4: addiu       $s1, $s1, 0x7A48
    ctx->r17 = ADD32(ctx->r17, 0X7A48);
    // 0x80096BD8: bne         $at, $zero, L_80097018
    if (ctx->r1 != 0) {
        // 0x80096BDC: addiu       $v1, $v1, -0x7CA8
        ctx->r3 = ADD32(ctx->r3, -0X7CA8);
            goto L_80097018;
    }
    // 0x80096BDC: addiu       $v1, $v1, -0x7CA8
    ctx->r3 = ADD32(ctx->r3, -0X7CA8);
    // 0x80096BE0: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80096BE4: bne         $at, $zero, L_80096C08
    if (ctx->r1 != 0) {
        // 0x80096BE8: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_80096C08;
    }
    // 0x80096BE8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80096BEC: lw          $t0, -0x7CC0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7CC0);
    // 0x80096BF0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80096BF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80096BF8: beql        $t0, $zero, L_80096C0C
    if (ctx->r8 == 0) {
        // 0x80096BFC: slti        $at, $v0, 0x8C
        ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
            goto L_80096C0C;
    }
    goto skip_0;
    // 0x80096BFC: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    skip_0:
    // 0x80096C00: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80096C04: sw          $t1, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r9;
L_80096C08:
    // 0x80096C08: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
L_80096C0C:
    // 0x80096C0C: beq         $at, $zero, L_80096CCC
    if (ctx->r1 == 0) {
        // 0x80096C10: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80096CCC;
    }
    // 0x80096C10: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80096C14: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80096C18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096C1C: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x80096C20: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    // 0x80096C24: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80096C28: jal         0x8009BC2C
    // 0x80096C2C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80096C2C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80096C30: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80096C34: lw          $t2, 0x7A80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7A80);
    // 0x80096C38: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80096C3C: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x80096C40: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x80096C44: bne         $at, $zero, L_80096C68
    if (ctx->r1 != 0) {
        // 0x80096C48: lui         $a1, 0x4040
        ctx->r5 = S32(0X4040 << 16);
            goto L_80096C68;
    }
    // 0x80096C48: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80096C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096C50: lwc1        $f16, -0x7E54($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7E54);
    // 0x80096C54: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80096C58: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096C5C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80096C60: jal         0x8009BC2C
    // 0x80096C64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80096C64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
L_80096C68:
    // 0x80096C68: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80096C6C: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80096C70: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80096C74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80096C78: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80096C7C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80096C80: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x80096C84: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80096C88: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80096C8C: nop

    // 0x80096C90: bc1fl       L_80096CB0
    if (!c1cs) {
        // 0x80096C94: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_80096CB0;
    }
    goto skip_1;
    // 0x80096C94: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_1:
    // 0x80096C98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80096C9C: nop

    // 0x80096CA0: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80096CA4: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x80096CA8: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80096CAC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_80096CB0:
    // 0x80096CB0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80096CB4: bc1f        L_80096CCC
    if (!c1cs) {
        // 0x80096CB8: nop
    
            goto L_80096CCC;
    }
    // 0x80096CB8: nop

    // 0x80096CBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80096CC0: nop

    // 0x80096CC4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80096CC8: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
L_80096CCC:
    // 0x80096CCC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096CD0: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80096CD4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80096CD8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096CDC: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80096CE0: bne         $at, $zero, L_80096D54
    if (ctx->r1 != 0) {
        // 0x80096CE4: addiu       $a0, $s0, 0x34
        ctx->r4 = ADD32(ctx->r16, 0X34);
            goto L_80096D54;
    }
    // 0x80096CE4: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80096CE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096CEC: lwc1        $f6, -0x7E50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7E50);
    // 0x80096CF0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80096CF4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80096CF8: jal         0x8009BD38
    // 0x80096CFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x80096CFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80096D00: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80096D04: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80096D08: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096D0C: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x80096D10: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80096D14: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80096D18: jal         0x8009BC2C
    // 0x80096D1C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80096D1C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80096D20: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80096D24: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80096D28: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096D2C: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x80096D30: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80096D34: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80096D38: jal         0x8009BC2C
    // 0x80096D3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80096D3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x80096D40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096D44: lwc1        $f8, -0x7E4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7E4C);
    // 0x80096D48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096D4C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x80096D50: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80096D54:
    // 0x80096D54: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80096D58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096D5C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80096D60: swc1        $f10, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f10.u32l;
    // 0x80096D64: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80096D68: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80096D6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096D70: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80096D74: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80096D78: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80096D7C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80096D80: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80096D84: swc1        $f4, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f4.u32l;
    // 0x80096D88: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80096D8C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80096D90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096D94: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80096D98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80096D9C: ori         $a0, $a0, 0x4002
    ctx->r4 = ctx->r4 | 0X4002;
    // 0x80096DA0: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80096DA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80096DA8: swc1        $f10, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f10.u32l;
    // 0x80096DAC: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80096DB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096DB4: swc1        $f16, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f16.u32l;
    // 0x80096DB8: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80096DBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096DC0: swc1        $f18, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f18.u32l;
    // 0x80096DC4: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80096DC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096DCC: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x80096DD0: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
    // 0x80096DD4: bne         $v0, $at, L_80097018
    if (ctx->r2 != ctx->r1) {
        // 0x80096DD8: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80097018;
    }
    // 0x80096DD8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80096DDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80096DE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80096DE4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80096DE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80096DEC: sw          $t3, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r11;
    // 0x80096DF0: swc1        $f6, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f6.u32l;
    // 0x80096DF4: swc1        $f8, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f8.u32l;
    // 0x80096DF8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80096DFC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80096E00: jal         0x80019218
    // 0x80096E04: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80096E04: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    after_5:
    // 0x80096E08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096E0C: b           L_80097018
    // 0x80096E10: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_80097018;
    // 0x80096E10: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80096E14:
    // 0x80096E14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096E18: lwc1        $f16, -0x7E48($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7E48);
    // 0x80096E1C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80096E20: addiu       $s1, $s1, 0x7A48
    ctx->r17 = ADD32(ctx->r17, 0X7A48);
    // 0x80096E24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096E28: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x80096E2C: lwc1        $f18, -0x7E44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7E44);
    // 0x80096E30: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80096E34: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80096E38: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096E3C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80096E40: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80096E44: jal         0x8009BD38
    // 0x80096E48: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x80096E48: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x80096E4C: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80096E50: lwc1        $f6, 0x148($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X148);
    // 0x80096E54: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80096E58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80096E5C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80096E60: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80096E64: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80096E68: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096E6C: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x80096E70: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80096E74: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80096E78: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80096E7C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80096E80: jal         0x8009BC2C
    // 0x80096E84: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80096E84: nop

    after_7:
    // 0x80096E88: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80096E8C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80096E90: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096E94: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x80096E98: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80096E9C: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80096EA0: jal         0x8009BC2C
    // 0x80096EA4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80096EA4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80096EA8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80096EAC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096EB0: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80096EB4: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x80096EB8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x80096EBC: jal         0x8009BC2C
    // 0x80096EC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80096EC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x80096EC4: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x80096EC8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80096ECC: addiu       $t6, $t6, -0x2780
    ctx->r14 = ADD32(ctx->r14, -0X2780);
    // 0x80096ED0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80096ED4: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80096ED8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80096EDC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80096EE0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80096EE4: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80096EE8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80096EEC: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x80096EF0: lhu         $t9, 0x7908($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7908);
    // 0x80096EF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80096EF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80096EFC: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80096F00: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80096F04: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80096F08: sw          $t0, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r8;
    // 0x80096F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80096F10: jal         0x800B2574
    // 0x80096F14: swc1        $f18, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f18.u32l;
    Player_ArwingBoost(rdram, ctx);
        goto after_10;
    // 0x80096F14: swc1        $f18, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f18.u32l;
    after_10:
    // 0x80096F18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80096F1C: sb          $zero, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = 0;
    // 0x80096F20: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    // 0x80096F24: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80096F28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096F2C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80096F30: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80096F34: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80096F38: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80096F3C: sh          $t1, -0x2780($at)
    MEM_H(-0X2780, ctx->r1) = ctx->r9;
    // 0x80096F40: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80096F44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096F48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096F4C: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x80096F50: lwc1        $f8, 0x148($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X148);
    // 0x80096F54: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80096F58: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80096F5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80096F60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80096F64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096F68: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80096F6C: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80096F70: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80096F74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80096F78: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80096F7C: swc1        $f18, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f18.u32l;
    // 0x80096F80: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80096F84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096F88: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x80096F8C: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80096F90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096F94: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x80096F98: lwc1        $f10, 0x148($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X148);
    // 0x80096F9C: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80096FA0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80096FA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80096FA8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80096FAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096FB0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80096FB4: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x80096FB8: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80096FBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096FC0: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x80096FC4: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x80096FC8: bnel        $v0, $at, L_8009701C
    if (ctx->r2 != ctx->r1) {
        // 0x80096FCC: slti        $at, $v0, 0x1E
        ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
            goto L_8009701C;
    }
    goto skip_2;
    // 0x80096FCC: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    skip_2:
    // 0x80096FD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80096FD4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096FD8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096FDC: swc1        $f8, 0x7CE8($at)
    MEM_W(0X7CE8, ctx->r1) = ctx->f8.u32l;
    // 0x80096FE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096FE4: sw          $t4, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r12;
    // 0x80096FE8: sw          $t5, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r13;
    // 0x80096FEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096FF0: lwc1        $f10, 0x1A54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x80096FF4: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x80096FF8: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x80096FFC: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x80097000: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x80097004: swc1        $f20, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f20.u32l;
    // 0x80097008: swc1        $f10, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f10.u32l;
    // 0x8009700C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80097010: sw          $t6, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r14;
    // 0x80097014: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80097018:
    // 0x80097018: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
L_8009701C:
    // 0x8009701C: bne         $at, $zero, L_8009729C
    if (ctx->r1 != 0) {
        // 0x80097020: addiu       $a0, $s0, 0xD0
        ctx->r4 = ADD32(ctx->r16, 0XD0);
            goto L_8009729C;
    }
    // 0x80097020: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x80097024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097028: lwc1        $f16, -0x7E40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7E40);
    // 0x8009702C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80097030: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80097034: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80097038: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8009703C: jal         0x8009BC2C
    // 0x80097040: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80097040: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x80097044: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80097048: lw          $t7, 0x7A80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A80);
    // 0x8009704C: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80097050: slti        $at, $t7, 0x6E
    ctx->r1 = SIGNED(ctx->r15) < 0X6E ? 1 : 0;
    // 0x80097054: beql        $at, $zero, L_800970B8
    if (ctx->r1 == 0) {
        // 0x80097058: lwc1        $f0, 0x10($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
            goto L_800970B8;
    }
    goto skip_3;
    // 0x80097058: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    skip_3:
    // 0x8009705C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80097060: lwc1        $f18, 0xEC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80097064: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80097068: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8009706C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80097070: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80097074: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x80097078: lwc1        $f2, 0xEC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8009707C: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80097080: nop

    // 0x80097084: bc1fl       L_8009709C
    if (!c1cs) {
        // 0x80097088: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_8009709C;
    }
    goto skip_4;
    // 0x80097088: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_4:
    // 0x8009708C: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80097090: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80097094: lwc1        $f2, 0xEC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80097098: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_8009709C:
    // 0x8009709C: nop

    // 0x800970A0: bc1fl       L_800971B0
    if (!c1cs) {
        // 0x800970A4: lwc1        $f4, 0xE8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_800971B0;
    }
    goto skip_5;
    // 0x800970A4: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    skip_5:
    // 0x800970A8: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800970AC: b           L_800971AC
    // 0x800970B0: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
        goto L_800971AC;
    // 0x800970B0: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x800970B4: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
L_800970B8:
    // 0x800970B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800970BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800970C0: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800970C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800970C8: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x800970CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800970D0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800970D4: jal         0x8009BD38
    // 0x800970D8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_12;
    // 0x800970D8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x800970DC: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800970E0: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x800970E4: nop

    // 0x800970E8: bc1fl       L_800971B0
    if (!c1cs) {
        // 0x800970EC: lwc1        $f4, 0xE8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_800971B0;
    }
    goto skip_6;
    // 0x800970EC: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    skip_6:
    // 0x800970F0: lwc1        $f6, 0xE4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800970F4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800970F8: lui         $a3, 0x4019
    ctx->r7 = S32(0X4019 << 16);
    // 0x800970FC: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x80097100: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80097104: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80097108: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x8009710C: bc1t        L_80097130
    if (c1cs) {
        // 0x80097110: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80097130;
    }
    // 0x80097110: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80097114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097118: lwc1        $f8, -0x7E3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7E3C);
    // 0x8009711C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80097120: jal         0x8009BD38
    // 0x80097124: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_13;
    // 0x80097124: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x80097128: b           L_800971B0
    // 0x8009712C: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_800971B0;
    // 0x8009712C: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_80097130:
    // 0x80097130: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80097134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80097138: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009713C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80097140: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
    // 0x80097144: lwc1        $f6, -0x7E38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7E38);
    // 0x80097148: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8009714C: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80097150: jal         0x80023090
    // 0x80097154: nop

    __sinf_recomp(rdram, ctx);
        goto after_14;
    // 0x80097154: nop

    after_14:
    // 0x80097158: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009715C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80097160: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80097164: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80097168: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009716C: lwc1        $f18, 0xF4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80097170: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80097174: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097178: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009717C: swc1        $f6, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f6.u32l;
    // 0x80097180: swc1        $f16, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f16.u32l;
    // 0x80097184: lwc1        $f10, -0x7E34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7E34);
    // 0x80097188: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8009718C: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80097190: jal         0x80023090
    // 0x80097194: nop

    __sinf_recomp(rdram, ctx);
        goto after_15;
    // 0x80097194: nop

    after_15:
    // 0x80097198: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8009719C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800971A0: nop

    // 0x800971A4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800971A8: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
L_800971AC:
    // 0x800971AC: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_800971B0:
    // 0x800971B0: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800971B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800971B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800971BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800971C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800971C4: lwc1        $f18, -0x7E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7E30);
    // 0x800971C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800971CC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800971D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800971D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800971D8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800971DC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800971E0: jal         0x80005E90
    // 0x800971E4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_16;
    // 0x800971E4: nop

    after_16:
    // 0x800971E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800971EC: lwc1        $f8, -0x7E2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7E2C);
    // 0x800971F0: lwc1        $f6, 0xE4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800971F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800971F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800971FC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80097200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80097204: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80097208: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8009720C: jal         0x80005D44
    // 0x80097210: nop

    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x80097210: nop

    after_17:
    // 0x80097214: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x80097218: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x8009721C: lwc1        $f18, 0xD0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80097220: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80097224: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80097228: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8009722C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80097230: jal         0x80006A20
    // 0x80097234: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_18;
    // 0x80097234: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x80097238: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009723C: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80097240: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80097244: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x80097248: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8009724C: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80097250: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80097254: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80097258: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8009725C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80097260: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80097264: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80097268: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8009726C: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x80097270: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80097274: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x80097278: lwc1        $f10, 0x7CE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x8009727C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80097280: swc1        $f18, 0x7CE8($at)
    MEM_W(0X7CE8, ctx->r1) = ctx->f18.u32l;
    // 0x80097284: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80097288: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8009728C: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x80097290: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80097294: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80097298: swc1        $f16, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f16.u32l;
L_8009729C:
    // 0x8009729C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800972A0: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x800972A4: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x800972A8: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x800972AC: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x800972B0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800972B4: jal         0x8009BC2C
    // 0x800972B8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x800972B8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_19:
    // 0x800972BC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800972C0: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x800972C4: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x800972C8: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x800972CC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800972D0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800972D4: jal         0x8009BC2C
    // 0x800972D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x800972D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x800972DC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800972E0: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x800972E4: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x800972E8: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x800972EC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800972F0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800972F4: jal         0x8009BC2C
    // 0x800972F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x800972F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_21:
    // 0x800972FC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80097300: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80097304: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80097308: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x8009730C: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80097310: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80097314: jal         0x8009BC2C
    // 0x80097318: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x80097318: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_22:
    // 0x8009731C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80097320: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80097324: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80097328: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x8009732C: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80097330: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80097334: jal         0x8009BC2C
    // 0x80097338: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x80097338: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_23:
    // 0x8009733C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80097340: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80097344: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80097348: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x8009734C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80097350: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80097354: jal         0x8009BC2C
    // 0x80097358: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x80097358: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_24:
    // 0x8009735C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80097360: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80097364: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80097368: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8009736C: jr          $ra
    // 0x80097370: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80097370: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_tank_800460E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800460E0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800460E4: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x800460E8: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800460EC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800460F0: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x800460F4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800460F8: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800460FC: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80046100: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80046104: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80046108: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8004610C: addiu       $s6, $s6, -0x4438
    ctx->r22 = ADD32(ctx->r22, -0X4438);
    // 0x80046110: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80046114: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80046118: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8004611C: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80046120: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80046124: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80046128: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8004612C: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80046130: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80046134: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80046138: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004613C: lwc1        $f8, 0x56E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X56E0);
    // 0x80046140: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80046144: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80046148: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004614C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80046150: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80046154: jal         0x80005E90
    // 0x80046158: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80046158: nop

    after_0:
    // 0x8004615C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80046160: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80046164: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80046168: mfc1        $s5, $f18
    ctx->r21 = (int32_t)ctx->f18.u32l;
    // 0x8004616C: nop

    // 0x80046170: beql        $s5, $zero, L_80046224
    if (ctx->r21 == 0) {
        // 0x80046174: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80046224;
    }
    goto skip_0;
    // 0x80046174: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x80046178: blez        $s5, L_80046220
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8004617C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80046220;
    }
    // 0x8004617C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80046180: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80046184: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80046188: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004618C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80046190: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80046194: lwc1        $f20, 0xB8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80046198: addiu       $s4, $sp, 0x7C
    ctx->r20 = ADD32(ctx->r29, 0X7C);
    // 0x8004619C: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
L_800461A0:
    // 0x800461A0: lwc1        $f0, 0x74($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X74);
    // 0x800461A4: lwc1        $f2, 0x138($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X138);
    // 0x800461A8: swc1        $f26, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f26.u32l;
    // 0x800461AC: sub.s       $f4, $f0, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800461B0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x800461B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800461B8: sub.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800461BC: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x800461C0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800461C4: jal         0x80006A20
    // 0x800461C8: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x800461C8: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800461CC: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800461D0: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800461D4: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800461D8: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800461DC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x800461E0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800461E4: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800461E8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800461EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800461F0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800461F4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800461F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800461FC: jal         0x800A78C4
    // 0x80046200: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_2;
    // 0x80046200: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80046204: beq         $v0, $zero, L_80046218
    if (ctx->r2 == 0) {
        // 0x80046208: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80046218;
    }
    // 0x80046208: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004620C: add.s       $f8, $f22, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x80046210: add.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x80046214: swc1        $f10, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f10.u32l;
L_80046218:
    // 0x80046218: bne         $s1, $s5, L_800461A0
    if (ctx->r17 != ctx->r21) {
        // 0x8004621C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800461A0;
    }
    // 0x8004621C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_80046220:
    // 0x80046220: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80046224:
    // 0x80046224: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80046228: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8004622C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80046230: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x80046234: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x80046238: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8004623C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80046240: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80046244: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80046248: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8004624C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80046250: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80046254: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80046258: jr          $ra
    // 0x8004625C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8004625C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void Sprite167_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80059C38: jr          $ra
    // 0x80059C3C: nop

    return;
    // 0x80059C3C: nop

;}
RECOMP_FUNC void Audio_StartPlayerNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C8B8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001C8BC: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8001C8C0: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8001C8C4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C8C8: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8001C8CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001C8D0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8001C8D4: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8001C8D8: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8001C8DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001C8E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001C8E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001C8E8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8001C8EC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001C8F0: lbu         $t2, 0x479($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X479);
    // 0x8001C8F4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001C8F8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001C8FC: addiu       $t8, $t8, -0x47B0
    ctx->r24 = ADD32(ctx->r24, -0X47B0);
    // 0x8001C900: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8001C904: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8001C908: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001C90C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8001C910: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001C914: sb          $t6, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r14;
    // 0x8001C918: jal         0x8001AF9C
    // 0x8001C91C: sb          $t2, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = ctx->r10;
    Audio_ResetPlayerFreqMods(rdram, ctx);
        goto after_0;
    // 0x8001C91C: sb          $t2, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = ctx->r10;
    after_0:
    // 0x8001C920: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C924: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001C928: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001C92C: lbu         $v0, 0x6C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6C);
    // 0x8001C930: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001C934: beq         $v0, $zero, L_8001C954
    if (ctx->r2 == 0) {
        // 0x8001C938: nop
    
            goto L_8001C954;
    }
    // 0x8001C938: nop

    // 0x8001C93C: beq         $v0, $at, L_8001C984
    if (ctx->r2 == ctx->r1) {
        // 0x8001C940: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001C984;
    }
    // 0x8001C940: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C944: beq         $v0, $at, L_8001C990
    if (ctx->r2 == ctx->r1) {
        // 0x8001C948: lui         $a0, 0x1100
        ctx->r4 = S32(0X1100 << 16);
            goto L_8001C990;
    }
    // 0x8001C948: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x8001C94C: b           L_8001C9D8
    // 0x8001C950: nop

        goto L_8001C9D8;
    // 0x8001C950: nop

L_8001C954:
    // 0x8001C954: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8001C958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001C95C: lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // 0x8001C960: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8001C964: lbu         $t5, 0x478($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X478);
    // 0x8001C968: bne         $t5, $at, L_8001C97C
    if (ctx->r13 != ctx->r1) {
        // 0x8001C96C: nop
    
            goto L_8001C97C;
    }
    // 0x8001C96C: nop

    // 0x8001C970: lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // 0x8001C974: b           L_8001C9D8
    // 0x8001C978: ori         $s0, $s0, 0xF020
    ctx->r16 = ctx->r16 | 0XF020;
        goto L_8001C9D8;
    // 0x8001C978: ori         $s0, $s0, 0xF020
    ctx->r16 = ctx->r16 | 0XF020;
L_8001C97C:
    // 0x8001C97C: b           L_8001C9D8
    // 0x8001C980: ori         $s0, $s0, 0xF005
    ctx->r16 = ctx->r16 | 0XF005;
        goto L_8001C9D8;
    // 0x8001C980: ori         $s0, $s0, 0xF005
    ctx->r16 = ctx->r16 | 0XF005;
L_8001C984:
    // 0x8001C984: lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // 0x8001C988: b           L_8001C9D8
    // 0x8001C98C: ori         $s0, $s0, 0xF006
    ctx->r16 = ctx->r16 | 0XF006;
        goto L_8001C9D8;
    // 0x8001C98C: ori         $s0, $s0, 0xF006
    ctx->r16 = ctx->r16 | 0XF006;
L_8001C990:
    // 0x8001C990: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001C994: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8001C998: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001C99C: lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // 0x8001C9A0: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001C9A4: lw          $a1, 0x47C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X47C);
    // 0x8001C9A8: addiu       $a3, $t8, 0x5D34
    ctx->r7 = ADD32(ctx->r24, 0X5D34);
    // 0x8001C9AC: addiu       $t9, $v1, 0x6D
    ctx->r25 = ADD32(ctx->r3, 0X6D);
    // 0x8001C9B0: ori         $s0, $s0, 0xF022
    ctx->r16 = ctx->r16 | 0XF022;
    // 0x8001C9B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8001C9B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001C9BC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001C9C0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8001C9C4: ori         $a0, $a0, 0x802C
    ctx->r4 = ctx->r4 | 0X802C;
    // 0x8001C9C8: jal         0x80019218
    // 0x8001C9CC: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8001C9CC: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    after_1:
    // 0x8001C9D0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C9D4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_8001C9D8:
    // 0x8001C9D8: beq         $s0, $zero, L_8001CA10
    if (ctx->r16 == 0) {
        // 0x8001C9DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001CA10;
    }
    // 0x8001C9DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C9E0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C9E4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8001C9E8: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8001C9EC: addiu       $t3, $t3, 0x5D34
    ctx->r11 = ADD32(ctx->r11, 0X5D34);
    // 0x8001C9F0: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8001C9F4: lw          $a1, 0x47C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X47C);
    // 0x8001C9F8: addiu       $t4, $v1, 0x6D
    ctx->r12 = ADD32(ctx->r3, 0X6D);
    // 0x8001C9FC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8001CA00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8001CA04: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x8001CA08: jal         0x80019218
    // 0x8001CA0C: addiu       $a3, $v1, 0x68
    ctx->r7 = ADD32(ctx->r3, 0X68);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8001CA0C: addiu       $a3, $v1, 0x68
    ctx->r7 = ADD32(ctx->r3, 0X68);
    after_2:
L_8001CA10:
    // 0x8001CA10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001CA14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001CA18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001CA1C: jr          $ra
    // 0x8001CA20: nop

    return;
    // 0x8001CA20: nop

;}
RECOMP_FUNC void func_tank_80043B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043B0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80043B10: jr          $ra
    // 0x80043B14: nop

    return;
    // 0x80043B14: nop

;}
RECOMP_FUNC void Play_SetupZPos360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B86A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B86A8: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800B86AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B86B0: lwc1        $f6, -0x741C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X741C);
    // 0x800B86B4: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B86B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B86BC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B86C0: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800B86C4: jr          $ra
    // 0x800B86C8: nop

    return;
    // 0x800B86C8: nop

;}
RECOMP_FUNC void Audio_GetCurrentVoiceStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AED4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001AED8: lw          $v0, -0x1674($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1674);
    // 0x8001AEDC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001AEE0: addiu       $t6, $t6, 0x2FE8
    ctx->r14 = ADD32(ctx->r14, 0X2FE8);
    // 0x8001AEE4: beq         $v0, $t6, L_8001AF04
    if (ctx->r2 == ctx->r14) {
        // 0x8001AEE8: lw          $v1, 0x48($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X48);
            goto L_8001AF04;
    }
    // 0x8001AEE8: lw          $v1, 0x48($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X48);
    // 0x8001AEEC: beq         $v1, $zero, L_8001AF04
    if (ctx->r3 == 0) {
        // 0x8001AEF0: nop
    
            goto L_8001AF04;
    }
    // 0x8001AEF0: nop

    // 0x8001AEF4: lb          $t7, 0xBD($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XBD);
    // 0x8001AEF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AEFC: beql        $t7, $at, L_8001AF10
    if (ctx->r15 == ctx->r1) {
        // 0x8001AF00: lw          $v0, 0x40($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X40);
            goto L_8001AF10;
    }
    goto skip_0;
    // 0x8001AF00: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    skip_0:
L_8001AF04:
    // 0x8001AF04: jr          $ra
    // 0x8001AF08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001AF08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AF0C: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
L_8001AF10:
    // 0x8001AF10: beql        $v0, $zero, L_8001AF38
    if (ctx->r2 == 0) {
        // 0x8001AF14: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001AF38;
    }
    goto skip_1;
    // 0x8001AF14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8001AF18: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x8001AF1C: beq         $v1, $t8, L_8001AF2C
    if (ctx->r3 == ctx->r24) {
        // 0x8001AF20: nop
    
            goto L_8001AF2C;
    }
    // 0x8001AF20: nop

    // 0x8001AF24: jr          $ra
    // 0x8001AF28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8001AF28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001AF2C:
    // 0x8001AF2C: jr          $ra
    // 0x8001AF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001AF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AF34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001AF38:
    // 0x8001AF38: jr          $ra
    // 0x8001AF3C: nop

    return;
    // 0x8001AF3C: nop

;}
RECOMP_FUNC void Radio_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB5D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800BB5D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BB5D8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800BB5DC: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x800BB5E0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800BB5E4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800BB5E8: bne         $t6, $at, L_800BB5FC
    if (ctx->r14 != ctx->r1) {
        // 0x800BB5EC: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800BB5FC;
    }
    // 0x800BB5EC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BB5F0: lw          $t7, 0x7834($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7834);
    // 0x800BB5F4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BB5F8: bne         $t7, $at, L_800BC030
    if (ctx->r15 != ctx->r1) {
        // 0x800BB5FC: addiu       $v1, $v1, -0x7D54
        ctx->r3 = ADD32(ctx->r3, -0X7D54);
            goto L_800BC030;
    }
L_800BB5FC:
    // 0x800BB5FC: addiu       $v1, $v1, -0x7D54
    ctx->r3 = ADD32(ctx->r3, -0X7D54);
    // 0x800BB600: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BB604: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BB608: addiu       $t0, $t0, -0x7D4C
    ctx->r8 = ADD32(ctx->r8, -0X7D4C);
    // 0x800BB60C: blez        $v0, L_800BB61C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BB610: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_800BB61C;
    }
    // 0x800BB610: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BB614: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800BB618: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800BB61C:
    // 0x800BB61C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800BB620: addiu       $a2, $a2, -0x7D64
    ctx->r6 = ADD32(ctx->r6, -0X7D64);
    // 0x800BB624: blez        $v0, L_800BB630
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BB628: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800BB630;
    }
    // 0x800BB628: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800BB62C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_800BB630:
    // 0x800BB630: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BB634: slti        $at, $a1, 0x21
    ctx->r1 = SIGNED(ctx->r5) < 0X21 ? 1 : 0;
    // 0x800BB638: bne         $at, $zero, L_800BB654
    if (ctx->r1 != 0) {
        // 0x800BB63C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800BB654;
    }
    // 0x800BB63C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800BB640: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800BB644: beq         $v0, $at, L_800BB674
    if (ctx->r2 == ctx->r1) {
        // 0x800BB648: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800BB674;
    }
    // 0x800BB648: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BB64C: b           L_800BBC84
    // 0x800BB650: nop

        goto L_800BBC84;
    // 0x800BB650: nop

L_800BB654:
    // 0x800BB654: sltiu       $at, $v0, 0x21
    ctx->r1 = ctx->r2 < 0X21 ? 1 : 0;
    // 0x800BB658: beq         $at, $zero, L_800BBC84
    if (ctx->r1 == 0) {
        // 0x800BB65C: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_800BBC84;
    }
    // 0x800BB65C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800BB660: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB664: addu        $at, $at, $t1
    gpr jr_addend_800BB66C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800BB668: lw          $t1, -0x6FAC($at)
    ctx->r9 = ADD32(ctx->r1, -0X6FAC);
    // 0x800BB66C: jr          $t1
    // 0x800BB670: nop

    switch (jr_addend_800BB66C >> 2) {
        case 0: goto L_800BBC84; break;
        case 1: goto L_800BB6D8; break;
        case 2: goto L_800BB750; break;
        case 3: goto L_800BB798; break;
        case 4: goto L_800BB938; break;
        case 5: goto L_800BBAD8; break;
        case 6: goto L_800BBB10; break;
        case 7: goto L_800BBBC4; break;
        case 8: goto L_800BBC40; break;
        case 9: goto L_800BBC84; break;
        case 10: goto L_800BBC84; break;
        case 11: goto L_800BBC84; break;
        case 12: goto L_800BBC84; break;
        case 13: goto L_800BBC84; break;
        case 14: goto L_800BBC84; break;
        case 15: goto L_800BBC84; break;
        case 16: goto L_800BBC84; break;
        case 17: goto L_800BBC84; break;
        case 18: goto L_800BBC84; break;
        case 19: goto L_800BBC84; break;
        case 20: goto L_800BBC84; break;
        case 21: goto L_800BBC84; break;
        case 22: goto L_800BBC84; break;
        case 23: goto L_800BBC84; break;
        case 24: goto L_800BBC84; break;
        case 25: goto L_800BBC84; break;
        case 26: goto L_800BBC84; break;
        case 27: goto L_800BBC84; break;
        case 28: goto L_800BBC84; break;
        case 29: goto L_800BBC84; break;
        case 30: goto L_800BBC84; break;
        case 31: goto L_800BB870; break;
        case 32: goto L_800BB890; break;
        default: switch_error(__func__, 0x800BB66C, 0x800D9054);
    }
    // 0x800BB670: nop

L_800BB674:
    // 0x800BB674: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800BB678: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB67C: sw          $a0, -0x78B8($at)
    MEM_W(-0X78B8, ctx->r1) = ctx->r4;
    // 0x800BB680: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB684: addiu       $t2, $zero, 0x3E8
    ctx->r10 = ADD32(0, 0X3E8);
    // 0x800BB688: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BB68C: sw          $t2, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r10;
    // 0x800BB690: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BB694: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB698: addiu       $a1, $a1, -0x7D28
    ctx->r5 = ADD32(ctx->r5, -0X7D28);
    // 0x800BB69C: addiu       $v0, $v0, 0x7D38
    ctx->r2 = ADD32(ctx->r2, 0X7D38);
    // 0x800BB6A0: addiu       $v1, $v1, 0x7D50
    ctx->r3 = ADD32(ctx->r3, 0X7D50);
    // 0x800BB6A4: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x800BB6A8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800BB6AC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800BB6B0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800BB6B4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800BB6B8: lw          $t3, 0x78A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A8);
    // 0x800BB6BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB6C0: sw          $zero, -0x78B4($at)
    MEM_W(-0X78B4, ctx->r1) = 0;
    // 0x800BB6C4: beq         $a0, $t3, L_800BB6D0
    if (ctx->r4 == ctx->r11) {
        // 0x800BB6C8: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_800BB6D0;
    }
    // 0x800BB6C8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB6CC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800BB6D0:
    // 0x800BB6D0: b           L_800BBC84
    // 0x800BB6D4: lw          $a1, -0x7D64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D64);
        goto L_800BBC84;
    // 0x800BB6D4: lw          $a1, -0x7D64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D64);
L_800BB6D8:
    // 0x800BB6D8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BB6DC: addiu       $v0, $v0, 0x7D38
    ctx->r2 = ADD32(ctx->r2, 0X7D38);
    // 0x800BB6E0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800BB6E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB6E8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BB6EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB6F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB6F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BB6F8: addiu       $t4, $a1, 0x1
    ctx->r12 = ADD32(ctx->r5, 0X1);
    // 0x800BB6FC: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x800BB700: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800BB704: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800BB708: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BB70C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800BB710: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800BB714: nop

    // 0x800BB718: bc1f        L_800BB72C
    if (!c1cs) {
        // 0x800BB71C: nop
    
            goto L_800BB72C;
    }
    // 0x800BB71C: nop

    // 0x800BB720: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800BB724: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800BB728: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_800BB72C:
    // 0x800BB72C: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800BB730: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800BB734: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB738: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800BB73C: beq         $t8, $zero, L_800BBC84
    if (ctx->r24 == 0) {
        // 0x800BB740: sw          $t6, -0x7D5C($at)
        MEM_W(-0X7D5C, ctx->r1) = ctx->r14;
            goto L_800BBC84;
    }
    // 0x800BB740: sw          $t6, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r14;
    // 0x800BB744: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB748: b           L_800BBC84
    // 0x800BB74C: sw          $t9, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r25;
        goto L_800BBC84;
    // 0x800BB74C: sw          $t9, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r25;
L_800BB750:
    // 0x800BB750: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800BB754: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x800BB758: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800BB75C: bne         $t1, $zero, L_800BB770
    if (ctx->r9 != 0) {
        // 0x800BB760: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_800BB770;
    }
    // 0x800BB760: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800BB764: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x800BB768: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800BB76C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_800BB770:
    // 0x800BB770: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x800BB774: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800BB778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB77C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800BB780: beq         $t6, $zero, L_800BBC84
    if (ctx->r14 == 0) {
        // 0x800BB784: sw          $t4, -0x7D5C($at)
        MEM_W(-0X7D5C, ctx->r1) = ctx->r12;
            goto L_800BBC84;
    }
    // 0x800BB784: sw          $t4, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r12;
    // 0x800BB788: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800BB78C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB790: b           L_800BBC84
    // 0x800BB794: sw          $t7, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r15;
        goto L_800BBC84;
    // 0x800BB794: sw          $t7, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r15;
L_800BB798:
    // 0x800BB798: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BB79C: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x800BB7A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BB7A4: bne         $t8, $zero, L_800BB80C
    if (ctx->r24 != 0) {
        // 0x800BB7A8: nop
    
            goto L_800BB80C;
    }
    // 0x800BB7A8: nop

    // 0x800BB7AC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800BB7B0: jal         0x800C28DC
    // 0x800BB7B4: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    Message_GetWidth(rdram, ctx);
        goto after_0;
    // 0x800BB7B4: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    after_0:
    // 0x800BB7B8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BB7BC: lbu         $t1, 0x7E78($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7E78);
    // 0x800BB7C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BB7C4: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x800BB7C8: bne         $t1, $at, L_800BB7E0
    if (ctx->r9 != ctx->r1) {
        // 0x800BB7CC: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800BB7E0;
    }
    // 0x800BB7CC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BB7D0: addiu       $t2, $v0, 0x10
    ctx->r10 = ADD32(ctx->r2, 0X10);
    // 0x800BB7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB7D8: b           L_800BB7EC
    // 0x800BB7DC: sw          $t2, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r10;
        goto L_800BB7EC;
    // 0x800BB7DC: sw          $t2, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r10;
L_800BB7E0:
    // 0x800BB7E0: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x800BB7E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB7E8: sw          $t4, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r12;
L_800BB7EC:
    // 0x800BB7EC: lw          $v1, 0x7834($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7834);
    // 0x800BB7F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BB7F4: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800BB7F8: beq         $v1, $at, L_800BB804
    if (ctx->r3 == ctx->r1) {
        // 0x800BB7FC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800BB804;
    }
    // 0x800BB7FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BB800: bne         $v1, $at, L_800BB80C
    if (ctx->r3 != ctx->r1) {
        // 0x800BB804: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800BB80C;
    }
L_800BB804:
    // 0x800BB804: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB808: sw          $t5, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r13;
L_800BB80C:
    // 0x800BB80C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB810: lwc1        $f0, -0x6F28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F28);
    // 0x800BB814: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB818: lwc1        $f18, 0x7D68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BB81C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB820: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BB824: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB828: addiu       $v1, $v1, 0x7D50
    ctx->r3 = ADD32(ctx->r3, 0X7D50);
    // 0x800BB82C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB830: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800BB834: nop

    // 0x800BB838: sw          $t7, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r15;
    // 0x800BB83C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB840: lwc1        $f8, -0x6F24($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6F24);
    // 0x800BB844: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BB848: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800BB84C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x800BB850: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BB854: lw          $a1, -0x7D64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D64);
    // 0x800BB858: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800BB85C: nop

    // 0x800BB860: bc1f        L_800BBC84
    if (!c1cs) {
        // 0x800BB864: nop
    
            goto L_800BBC84;
    }
    // 0x800BB864: nop

    // 0x800BB868: b           L_800BBC84
    // 0x800BB86C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800BBC84;
    // 0x800BB86C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_800BB870:
    // 0x800BB870: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800BB874: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x800BB878: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x800BB87C: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x800BB880: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800BB884: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800BB888: b           L_800BBC84
    // 0x800BB88C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_800BBC84;
    // 0x800BB88C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_800BB890:
    // 0x800BB890: jal         0x8001AE78
    // 0x800BB894: nop

    Audio_GetCurrentVoice(rdram, ctx);
        goto after_1;
    // 0x800BB894: nop

    after_1:
    // 0x800BB898: bne         $v0, $zero, L_800BB92C
    if (ctx->r2 != 0) {
        // 0x800BB89C: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800BB92C;
    }
    // 0x800BB89C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BB8A0: addiu       $v0, $v0, -0x78DC
    ctx->r2 = ADD32(ctx->r2, -0X78DC);
    // 0x800BB8A4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800BB8A8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BB8AC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB8B0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800BB8B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800BB8B8: lw          $t5, -0x78E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X78E0);
    // 0x800BB8BC: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x800BB8C0: addiu       $a1, $a1, -0x7CF8
    ctx->r5 = ADD32(ctx->r5, -0X7CF8);
    // 0x800BB8C4: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800BB8C8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800BB8CC: jal         0x800C2890
    // 0x800BB8D0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    Message_IdFromPtr(rdram, ctx);
        goto after_2;
    // 0x800BB8D0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    after_2:
    // 0x800BB8D4: jal         0x8001ACDC
    // 0x800BB8D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_3;
    // 0x800BB8D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800BB8DC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB8E0: addiu       $a1, $a1, -0x7D28
    ctx->r5 = ADD32(ctx->r5, -0X7D28);
    // 0x800BB8E4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BB8E8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800BB8EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB8F0: addiu       $v1, $v1, -0x7D54
    ctx->r3 = ADD32(ctx->r3, -0X7D54);
    // 0x800BB8F4: sw          $zero, -0x78B4($at)
    MEM_W(-0X78B4, ctx->r1) = 0;
    // 0x800BB8F8: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x800BB8FC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BB900: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BB904: jal         0x800C28DC
    // 0x800BB908: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    Message_GetWidth(rdram, ctx);
        goto after_4;
    // 0x800BB908: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    after_4:
    // 0x800BB90C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BB910: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BB914: addiu       $a2, $a2, -0x7D64
    ctx->r6 = ADD32(ctx->r6, -0X7D64);
    // 0x800BB918: addiu       $v1, $v1, -0x7D54
    ctx->r3 = ADD32(ctx->r3, -0X7D54);
    // 0x800BB91C: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x800BB920: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800BB924: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800BB928: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_800BB92C:
    // 0x800BB92C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB930: b           L_800BBC84
    // 0x800BB934: lw          $a1, -0x7D64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D64);
        goto L_800BBC84;
    // 0x800BB934: lw          $a1, -0x7D64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D64);
L_800BB938:
    // 0x800BB938: jal         0x8001AE78
    // 0x800BB93C: nop

    Audio_GetCurrentVoice(rdram, ctx);
        goto after_5;
    // 0x800BB93C: nop

    after_5:
    // 0x800BB940: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BB944: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BB948: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BB94C: addiu       $t0, $t0, -0x7D4C
    ctx->r8 = ADD32(ctx->r8, -0X7D4C);
    // 0x800BB950: addiu       $a2, $a2, -0x7D64
    ctx->r6 = ADD32(ctx->r6, -0X7D64);
    // 0x800BB954: bne         $v0, $zero, L_800BB994
    if (ctx->r2 != 0) {
        // 0x800BB958: addiu       $v1, $v1, -0x7D54
        ctx->r3 = ADD32(ctx->r3, -0X7D54);
            goto L_800BB994;
    }
    // 0x800BB958: addiu       $v1, $v1, -0x7D54
    ctx->r3 = ADD32(ctx->r3, -0X7D54);
    // 0x800BB95C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800BB960: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800BB964: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB968: bne         $t4, $zero, L_800BB994
    if (ctx->r12 != 0) {
        // 0x800BB96C: nop
    
            goto L_800BB994;
    }
    // 0x800BB96C: nop

    // 0x800BB970: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BB974: lwc1        $f18, 0x7D68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BB978: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB97C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800BB980: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB984: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800BB988: nop

    // 0x800BB98C: sw          $t7, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r15;
    // 0x800BB990: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800BB994:
    // 0x800BB994: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB998: lwc1        $f6, 0x7D68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BB99C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB9A0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BB9A4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800BB9A8: nop

    // 0x800BB9AC: sw          $v0, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r2;
    // 0x800BB9B0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BB9B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB9B8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800BB9BC: blez        $t9, L_800BB9C8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BB9C0: nop
    
            goto L_800BB9C8;
    }
    // 0x800BB9C0: nop

    // 0x800BB9C4: sw          $t2, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r10;
L_800BB9C8:
    // 0x800BB9C8: jal         0x8001AED4
    // 0x800BB9CC: nop

    Audio_GetCurrentVoiceStatus(rdram, ctx);
        goto after_6;
    // 0x800BB9CC: nop

    after_6:
    // 0x800BB9D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB9D4: addiu       $a1, $a1, -0x7D28
    ctx->r5 = ADD32(ctx->r5, -0X7D28);
    // 0x800BB9D8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800BB9DC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BB9E0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BB9E4: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x800BB9E8: addiu       $t0, $t0, -0x7D4C
    ctx->r8 = ADD32(ctx->r8, -0X7D4C);
    // 0x800BB9EC: beq         $at, $zero, L_800BBA2C
    if (ctx->r1 == 0) {
        // 0x800BB9F0: addiu       $a2, $a2, -0x7D64
        ctx->r6 = ADD32(ctx->r6, -0X7D64);
            goto L_800BBA2C;
    }
    // 0x800BB9F0: addiu       $a2, $a2, -0x7D64
    ctx->r6 = ADD32(ctx->r6, -0X7D64);
    // 0x800BB9F4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BB9F8: lw          $t3, -0x7CF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7CF8);
    // 0x800BB9FC: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x800BBA00: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800BBA04: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800BBA08: lhu         $t5, 0x2($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X2);
    // 0x800BBA0C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800BBA10: bnel        $t5, $at, L_800BBA2C
    if (ctx->r13 != ctx->r1) {
        // 0x800BBA14: sw          $t8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r24;
            goto L_800BBA2C;
    }
    goto skip_0;
    // 0x800BBA14: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    skip_0:
    // 0x800BBA18: bne         $v0, $zero, L_800BBA2C
    if (ctx->r2 != 0) {
        // 0x800BBA1C: addiu       $t7, $zero, 0x1F
        ctx->r15 = ADD32(0, 0X1F);
            goto L_800BBA2C;
    }
    // 0x800BBA1C: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x800BBA20: b           L_800BBA2C
    // 0x800BBA24: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_800BBA2C;
    // 0x800BBA24: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800BBA28: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_800BBA2C:
    // 0x800BBA2C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BBA30: lw          $t1, -0x78B4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X78B4);
    // 0x800BBA34: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BBA38: beq         $t1, $zero, L_800BBAB8
    if (ctx->r9 == 0) {
        // 0x800BBA3C: nop
    
            goto L_800BBAB8;
    }
    // 0x800BBA3C: nop

    // 0x800BBA40: lw          $v1, -0x7D18($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D18);
    // 0x800BBA44: slti        $at, $v1, 0x59D8
    ctx->r1 = SIGNED(ctx->r3) < 0X59D8 ? 1 : 0;
    // 0x800BBA48: bne         $at, $zero, L_800BBAA0
    if (ctx->r1 != 0) {
        // 0x800BBA4C: slti        $at, $v1, 0x59F9
        ctx->r1 = SIGNED(ctx->r3) < 0X59F9 ? 1 : 0;
            goto L_800BBAA0;
    }
    // 0x800BBA4C: slti        $at, $v1, 0x59F9
    ctx->r1 = SIGNED(ctx->r3) < 0X59F9 ? 1 : 0;
    // 0x800BBA50: beq         $at, $zero, L_800BBAA0
    if (ctx->r1 == 0) {
        // 0x800BBA54: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_800BBAA0;
    }
    // 0x800BBA54: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BBA58: lw          $t9, -0x7D08($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D08);
    // 0x800BBA5C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800BBA60: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800BBA64: beq         $t9, $zero, L_800BBAB8
    if (ctx->r25 == 0) {
        // 0x800BBA68: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800BBAB8;
    }
    // 0x800BBA68: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800BBA6C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800BBA70: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x800BBA74: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BBA78: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BBA7C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800BBA80: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BBA84: ori         $a0, $a0, 0x17
    ctx->r4 = ctx->r4 | 0X17;
    // 0x800BBA88: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800BBA8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800BBA90: jal         0x80019218
    // 0x800BBA94: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x800BBA94: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_7:
    // 0x800BBA98: b           L_800BBAB8
    // 0x800BBA9C: nop

        goto L_800BBAB8;
    // 0x800BBA9C: nop

L_800BBAA0:
    // 0x800BBAA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BBAA4: bne         $v0, $at, L_800BBAB4
    if (ctx->r2 != ctx->r1) {
        // 0x800BBAA8: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_800BBAB4;
    }
    // 0x800BBAA8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800BBAAC: b           L_800BBAB8
    // 0x800BBAB0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
        goto L_800BBAB8;
    // 0x800BBAB0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_800BBAB4:
    // 0x800BBAB4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_800BBAB8:
    // 0x800BBAB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BBABC: lw          $t6, -0x78B4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78B4);
    // 0x800BBAC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BBAC4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BBAC8: xori        $t5, $t6, 0x1
    ctx->r13 = ctx->r14 ^ 0X1;
    // 0x800BBACC: sw          $t5, -0x78B4($at)
    MEM_W(-0X78B4, ctx->r1) = ctx->r13;
    // 0x800BBAD0: b           L_800BBC84
    // 0x800BBAD4: lw          $a1, -0x7D64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D64);
        goto L_800BBC84;
    // 0x800BBAD4: lw          $a1, -0x7D64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D64);
L_800BBAD8:
    // 0x800BBAD8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BBADC: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x800BBAE0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800BBAE4: bne         $t7, $zero, L_800BBAF8
    if (ctx->r15 != 0) {
        // 0x800BBAE8: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800BBAF8;
    }
    // 0x800BBAE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BBAEC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800BBAF0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800BBAF4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_800BBAF8:
    // 0x800BBAF8: lwc1        $f10, 0x7D68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BBAFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BBB00: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BBB04: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800BBB08: b           L_800BBC84
    // 0x800BBB0C: sw          $t2, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r10;
        goto L_800BBC84;
    // 0x800BBB0C: sw          $t2, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r10;
L_800BBB10:
    // 0x800BBB10: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800BBB14: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800BBB18: bne         $t3, $zero, L_800BBB60
    if (ctx->r11 != 0) {
        // 0x800BBB1C: nop
    
            goto L_800BBB60;
    }
    // 0x800BBB1C: nop

    // 0x800BBB20: lw          $t4, 0x7834($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7834);
    // 0x800BBB24: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BBB28: bne         $t4, $at, L_800BBB44
    if (ctx->r12 != ctx->r1) {
        // 0x800BBB2C: nop
    
            goto L_800BBB44;
    }
    // 0x800BBB2C: nop

    // 0x800BBB30: jal         0x8001AE58
    // 0x800BBB34: nop

    Audio_ClearVoice(rdram, ctx);
        goto after_8;
    // 0x800BBB34: nop

    after_8:
    // 0x800BBB38: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BBB3C: b           L_800BBB54
    // 0x800BBB40: addiu       $a2, $a2, -0x7D64
    ctx->r6 = ADD32(ctx->r6, -0X7D64);
        goto L_800BBB54;
    // 0x800BBB40: addiu       $a2, $a2, -0x7D64
    ctx->r6 = ADD32(ctx->r6, -0X7D64);
L_800BBB44:
    // 0x800BBB44: jal         0x8001ACDC
    // 0x800BBB48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_9;
    // 0x800BBB48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x800BBB4C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BBB50: addiu       $a2, $a2, -0x7D64
    ctx->r6 = ADD32(ctx->r6, -0X7D64);
L_800BBB54:
    // 0x800BBB54: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800BBB58: addiu       $a1, $t6, 0x1
    ctx->r5 = ADD32(ctx->r14, 0X1);
    // 0x800BBB5C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
L_800BBB60:
    // 0x800BBB60: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BBB64: addiu       $v0, $v0, -0x7D5C
    ctx->r2 = ADD32(ctx->r2, -0X7D5C);
    // 0x800BBB68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800BBB6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800BBB70: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800BBB74: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x800BBB78: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BBB7C: addiu       $v1, $v1, 0x7D50
    ctx->r3 = ADD32(ctx->r3, 0X7D50);
    // 0x800BBB80: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x800BBB84: beq         $t1, $zero, L_800BBB94
    if (ctx->r9 == 0) {
        // 0x800BBB88: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800BBB94;
    }
    // 0x800BBB88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BBB8C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800BBB90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_800BBB94:
    // 0x800BBB94: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BBB98: lwc1        $f4, -0x6F20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6F20);
    // 0x800BBB9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BBBA0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800BBBA4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800BBBA8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BBBAC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800BBBB0: nop

    // 0x800BBBB4: bc1f        L_800BBC84
    if (!c1cs) {
        // 0x800BBBB8: nop
    
            goto L_800BBC84;
    }
    // 0x800BBBB8: nop

    // 0x800BBBBC: b           L_800BBC84
    // 0x800BBBC0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800BBC84;
    // 0x800BBBC0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_800BBBC4:
    // 0x800BBBC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BBBC8: addiu       $v0, $v0, 0x7D38
    ctx->r2 = ADD32(ctx->r2, 0X7D38);
    // 0x800BBBCC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800BBBD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BBBD4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BBBD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BBBDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BBBE0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800BBBE4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800BBBE8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800BBBEC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800BBBF0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800BBBF4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BBBF8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BBBFC: addiu       $v0, $v0, -0x7D5C
    ctx->r2 = ADD32(ctx->r2, -0X7D5C);
    // 0x800BBC00: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800BBC04: nop

    // 0x800BBC08: bc1fl       L_800BBC28
    if (!c1cs) {
        // 0x800BBC0C: sw          $t2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r10;
            goto L_800BBC28;
    }
    goto skip_1;
    // 0x800BBC0C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    skip_1:
    // 0x800BBC10: sw          $zero, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = 0;
    // 0x800BBC14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BBC18: sw          $zero, 0x4A70($at)
    MEM_W(0X4A70, ctx->r1) = 0;
    // 0x800BBC1C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800BBC20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BBC24: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_800BBC28:
    // 0x800BBC28: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x800BBC2C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800BBC30: beq         $t4, $zero, L_800BBC84
    if (ctx->r12 == 0) {
        // 0x800BBC34: nop
    
            goto L_800BBC84;
    }
    // 0x800BBC34: nop

    // 0x800BBC38: b           L_800BBC84
    // 0x800BBC3C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_800BBC84;
    // 0x800BBC3C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800BBC40:
    // 0x800BBC40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BBC44: lwc1        $f0, -0x6F1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F1C);
    // 0x800BBC48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BBC4C: lwc1        $f8, 0x7D68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BBC50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BBC54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BBC58: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BBC5C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BBC60: addiu       $v1, $v1, 0x7D50
    ctx->r3 = ADD32(ctx->r3, 0X7D50);
    // 0x800BBC64: addiu       $v0, $v0, 0x7D38
    ctx->r2 = ADD32(ctx->r2, 0X7D38);
    // 0x800BBC68: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800BBC6C: nop

    // 0x800BBC70: sw          $t7, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r15;
    // 0x800BBC74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BBC78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BBC7C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800BBC80: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800BBC84:
    // 0x800BBC84: blez        $a1, L_800BC014
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800BBC88: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_800BC014;
    }
    // 0x800BBC88: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800BBC8C: beq         $a1, $at, L_800BC014
    if (ctx->r5 == ctx->r1) {
        // 0x800BBC90: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_800BC014;
    }
    // 0x800BBC90: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BBC94: lw          $t8, -0x7D00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D00);
    // 0x800BBC98: bne         $t8, $zero, L_800BC014
    if (ctx->r24 != 0) {
        // 0x800BBC9C: nop
    
            goto L_800BC014;
    }
    // 0x800BBC9C: nop

    // 0x800BBCA0: jal         0x800BAAE8
    // 0x800BBCA4: nop

    func_radio_800BAAE8(rdram, ctx);
        goto after_10;
    // 0x800BBCA4: nop

    after_10:
    // 0x800BBCA8: jal         0x800BB388
    // 0x800BBCAC: nop

    func_radio_800BB388(rdram, ctx);
        goto after_11;
    // 0x800BBCAC: nop

    after_11:
    // 0x800BBCB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BBCB4: lwc1        $f18, 0x7D68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BBCB8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800BBCBC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800BBCC0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BBCC4: addiu       $t2, $t2, 0x78B0
    ctx->r10 = ADD32(ctx->r10, 0X78B0);
    // 0x800BBCC8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800BBCCC: nop

    // 0x800BBCD0: beq         $v0, $at, L_800BBCE4
    if (ctx->r2 == ctx->r1) {
        // 0x800BBCD4: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_800BBCE4;
    }
    // 0x800BBCD4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800BBCD8: beq         $v0, $at, L_800BBCE4
    if (ctx->r2 == ctx->r1) {
        // 0x800BBCDC: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_800BBCE4;
    }
    // 0x800BBCDC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800BBCE0: bne         $v0, $at, L_800BBE10
    if (ctx->r2 != ctx->r1) {
        // 0x800BBCE4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800BBE10;
    }
L_800BBCE4:
    // 0x800BBCE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800BBCE8: bne         $v0, $at, L_800BBCF4
    if (ctx->r2 != ctx->r1) {
        // 0x800BBCEC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800BBCF4;
    }
    // 0x800BBCEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BBCF0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
L_800BBCF4:
    // 0x800BBCF4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800BBCF8: bne         $v0, $at, L_800BBD04
    if (ctx->r2 != ctx->r1) {
        // 0x800BBCFC: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_800BBD04;
    }
    // 0x800BBCFC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800BBD00: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800BBD04:
    // 0x800BBD04: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800BBD08: bne         $v0, $at, L_800BBD14
    if (ctx->r2 != ctx->r1) {
        // 0x800BBD0C: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_800BBD14;
    }
    // 0x800BBD0C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800BBD10: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800BBD14:
    // 0x800BBD14: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800BBD18: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800BBD1C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BBD20: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800BBD24: bgtz        $v0, L_800BBDD0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800BBD28: nop
    
            goto L_800BBDD0;
    }
    // 0x800BBD28: nop

    // 0x800BBD2C: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x800BBD30: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800BBD34: andi        $t6, $t4, 0x4
    ctx->r14 = ctx->r12 & 0X4;
    // 0x800BBD38: beq         $t6, $zero, L_800BBDD0
    if (ctx->r14 == 0) {
        // 0x800BBD3C: nop
    
            goto L_800BBDD0;
    }
    // 0x800BBD3C: nop

    // 0x800BBD40: beq         $v0, $at, L_800BBDD0
    if (ctx->r2 == ctx->r1) {
        // 0x800BBD44: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800BBDD0;
    }
    // 0x800BBD44: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BBD48: lw          $a0, -0x7D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D5C);
    // 0x800BBD4C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BBD50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBD54: beq         $a3, $a0, L_800BBDD0
    if (ctx->r7 == ctx->r4) {
        // 0x800BBD58: nop
    
            goto L_800BBDD0;
    }
    // 0x800BBD58: nop

    // 0x800BBD5C: beq         $a0, $at, L_800BBDD0
    if (ctx->r4 == ctx->r1) {
        // 0x800BBD60: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_800BBDD0;
    }
    // 0x800BBD60: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800BBD64: beq         $a0, $at, L_800BBDD0
    if (ctx->r4 == ctx->r1) {
        // 0x800BBD68: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BBDD0;
    }
    // 0x800BBD68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BBD6C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BBD70: jal         0x800B8DD0
    // 0x800BBD74: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_12;
    // 0x800BBD74: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_12:
    // 0x800BBD78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BBD7C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800BBD80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BBD84: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x800BBD88: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800BBD8C: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x800BBD90: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x800BBD94: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800BBD98: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800BBD9C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BBDA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BBDA4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BBDA8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BBDAC: addiu       $t1, $t1, -0x7410
    ctx->r9 = ADD32(ctx->r9, -0X7410);
    // 0x800BBDB0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800BBDB4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800BBDB8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BBDBC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800BBDC0: jal         0x800A1200
    // 0x800BBDC4: addiu       $a1, $zero, 0xA7
    ctx->r5 = ADD32(0, 0XA7);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_13;
    // 0x800BBDC4: addiu       $a1, $zero, 0xA7
    ctx->r5 = ADD32(0, 0XA7);
    after_13:
    // 0x800BBDC8: jal         0x80084B94
    // 0x800BBDCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    HUD_TeamDownWrench_Draw(rdram, ctx);
        goto after_14;
    // 0x800BBDCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_14:
L_800BBDD0:
    // 0x800BBDD0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BBDD4: lw          $a0, -0x7D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D5C);
    // 0x800BBDD8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BBDDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBDE0: beq         $a3, $a0, L_800BBE10
    if (ctx->r7 == ctx->r4) {
        // 0x800BBDE4: nop
    
            goto L_800BBE10;
    }
    // 0x800BBDE4: nop

    // 0x800BBDE8: beq         $a0, $at, L_800BBE10
    if (ctx->r4 == ctx->r1) {
        // 0x800BBDEC: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_800BBE10;
    }
    // 0x800BBDEC: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800BBDF0: beq         $a0, $at, L_800BBE10
    if (ctx->r4 == ctx->r1) {
        // 0x800BBDF4: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800BBE10;
    }
    // 0x800BBDF4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BBDF8: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800BBDFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BBE00: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800BBE04: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800BBE08: jal         0x80086110
    // 0x800BBE0C: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    HUD_TeamShields_Draw(rdram, ctx);
        goto after_15;
    // 0x800BBE0C: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    after_15:
L_800BBE10:
    // 0x800BBE10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BBE14: lwc1        $f6, 0x7D68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BBE18: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800BBE1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BBE20: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BBE24: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BBE28: lw          $a0, -0x7D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D5C);
    // 0x800BBE2C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800BBE30: nop

    // 0x800BBE34: beq         $v0, $at, L_800BBE74
    if (ctx->r2 == ctx->r1) {
        // 0x800BBE38: addiu       $t3, $v0, -0xC8
        ctx->r11 = ADD32(ctx->r2, -0XC8);
            goto L_800BBE74;
    }
    // 0x800BBE38: addiu       $t3, $v0, -0xC8
    ctx->r11 = ADD32(ctx->r2, -0XC8);
    // 0x800BBE3C: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x800BBE40: beq         $v0, $at, L_800BBE74
    if (ctx->r2 == ctx->r1) {
        // 0x800BBE44: addiu       $at, $zero, 0xDC
        ctx->r1 = ADD32(0, 0XDC);
            goto L_800BBE74;
    }
    // 0x800BBE44: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
    // 0x800BBE48: beq         $v0, $at, L_800BBE74
    if (ctx->r2 == ctx->r1) {
        // 0x800BBE4C: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_800BBE74;
    }
    // 0x800BBE4C: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x800BBE50: beq         $v0, $at, L_800BBE74
    if (ctx->r2 == ctx->r1) {
        // 0x800BBE54: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_800BBE74;
    }
    // 0x800BBE54: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800BBE58: beq         $v0, $at, L_800BBE74
    if (ctx->r2 == ctx->r1) {
        // 0x800BBE5C: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_800BBE74;
    }
    // 0x800BBE5C: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x800BBE60: beq         $v0, $at, L_800BBE74
    if (ctx->r2 == ctx->r1) {
        // 0x800BBE64: addiu       $at, $zero, 0x104
        ctx->r1 = ADD32(0, 0X104);
            goto L_800BBE74;
    }
    // 0x800BBE64: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    // 0x800BBE68: beq         $v0, $at, L_800BBE74
    if (ctx->r2 == ctx->r1) {
        // 0x800BBE6C: addiu       $at, $zero, 0x10E
        ctx->r1 = ADD32(0, 0X10E);
            goto L_800BBE74;
    }
    // 0x800BBE6C: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
    // 0x800BBE70: bne         $v0, $at, L_800BBFF4
    if (ctx->r2 != ctx->r1) {
        // 0x800BBE74: sltiu       $at, $t3, 0x47
        ctx->r1 = ctx->r11 < 0X47 ? 1 : 0;
            goto L_800BBFF4;
    }
L_800BBE74:
    // 0x800BBE74: sltiu       $at, $t3, 0x47
    ctx->r1 = ctx->r11 < 0X47 ? 1 : 0;
    // 0x800BBE78: beq         $at, $zero, L_800BBEB4
    if (ctx->r1 == 0) {
        // 0x800BBE7C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800BBEB4;
    }
    // 0x800BBE7C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BBE80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BBE84: addu        $at, $at, $t3
    gpr jr_addend_800BBE8C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800BBE88: lw          $t3, -0x6F18($at)
    ctx->r11 = ADD32(ctx->r1, -0X6F18);
    // 0x800BBE8C: jr          $t3
    // 0x800BBE90: nop

    switch (jr_addend_800BBE8C >> 2) {
        case 0: goto L_800BBE94; break;
        case 1: goto L_800BBEB4; break;
        case 2: goto L_800BBEB4; break;
        case 3: goto L_800BBEB4; break;
        case 4: goto L_800BBEB4; break;
        case 5: goto L_800BBEB4; break;
        case 6: goto L_800BBEB4; break;
        case 7: goto L_800BBEB4; break;
        case 8: goto L_800BBEB4; break;
        case 9: goto L_800BBEB4; break;
        case 10: goto L_800BBEA4; break;
        case 11: goto L_800BBEB4; break;
        case 12: goto L_800BBEB4; break;
        case 13: goto L_800BBEB4; break;
        case 14: goto L_800BBEB4; break;
        case 15: goto L_800BBEB4; break;
        case 16: goto L_800BBEB4; break;
        case 17: goto L_800BBEB4; break;
        case 18: goto L_800BBEB4; break;
        case 19: goto L_800BBEB4; break;
        case 20: goto L_800BBE9C; break;
        case 21: goto L_800BBEB4; break;
        case 22: goto L_800BBEB4; break;
        case 23: goto L_800BBEB4; break;
        case 24: goto L_800BBEB4; break;
        case 25: goto L_800BBEB4; break;
        case 26: goto L_800BBEB4; break;
        case 27: goto L_800BBEB4; break;
        case 28: goto L_800BBEB4; break;
        case 29: goto L_800BBEB4; break;
        case 30: goto L_800BBEAC; break;
        case 31: goto L_800BBEB4; break;
        case 32: goto L_800BBEB4; break;
        case 33: goto L_800BBEB4; break;
        case 34: goto L_800BBEB4; break;
        case 35: goto L_800BBEB4; break;
        case 36: goto L_800BBEB4; break;
        case 37: goto L_800BBEB4; break;
        case 38: goto L_800BBEB4; break;
        case 39: goto L_800BBEB4; break;
        case 40: goto L_800BBE94; break;
        case 41: goto L_800BBEB4; break;
        case 42: goto L_800BBEB4; break;
        case 43: goto L_800BBEB4; break;
        case 44: goto L_800BBEB4; break;
        case 45: goto L_800BBEB4; break;
        case 46: goto L_800BBEB4; break;
        case 47: goto L_800BBEB4; break;
        case 48: goto L_800BBEB4; break;
        case 49: goto L_800BBEB4; break;
        case 50: goto L_800BBEA4; break;
        case 51: goto L_800BBEB4; break;
        case 52: goto L_800BBEB4; break;
        case 53: goto L_800BBEB4; break;
        case 54: goto L_800BBEB4; break;
        case 55: goto L_800BBEB4; break;
        case 56: goto L_800BBEB4; break;
        case 57: goto L_800BBEB4; break;
        case 58: goto L_800BBEB4; break;
        case 59: goto L_800BBEB4; break;
        case 60: goto L_800BBE9C; break;
        case 61: goto L_800BBEB4; break;
        case 62: goto L_800BBEB4; break;
        case 63: goto L_800BBEB4; break;
        case 64: goto L_800BBEB4; break;
        case 65: goto L_800BBEB4; break;
        case 66: goto L_800BBEB4; break;
        case 67: goto L_800BBEB4; break;
        case 68: goto L_800BBEB4; break;
        case 69: goto L_800BBEB4; break;
        case 70: goto L_800BBEAC; break;
        default: switch_error(__func__, 0x800BBE8C, 0x800D90E8);
    }
    // 0x800BBE90: nop

L_800BBE94:
    // 0x800BBE94: b           L_800BBEB8
    // 0x800BBE98: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_800BBEB8;
    // 0x800BBE98: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_800BBE9C:
    // 0x800BBE9C: b           L_800BBEB8
    // 0x800BBEA0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_800BBEB8;
    // 0x800BBEA0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_800BBEA4:
    // 0x800BBEA4: b           L_800BBEB8
    // 0x800BBEA8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_800BBEB8;
    // 0x800BBEA8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_800BBEAC:
    // 0x800BBEAC: b           L_800BBEB8
    // 0x800BBEB0: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
        goto L_800BBEB8;
    // 0x800BBEB0: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_800BBEB4:
    // 0x800BBEB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800BBEB8:
    // 0x800BBEB8: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800BBEBC: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800BBEC0: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800BBEC4: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800BBEC8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BBECC: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x800BBED0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BBED4: addiu       $t6, $t6, 0x3FE0
    ctx->r14 = ADD32(ctx->r14, 0X3FE0);
    // 0x800BBED8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BBEDC: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x800BBEE0: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800BBEE4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800BBEE8: beq         $a3, $t5, L_800BBF98
    if (ctx->r7 == ctx->r13) {
        // 0x800BBEEC: nop
    
            goto L_800BBF98;
    }
    // 0x800BBEEC: nop

    // 0x800BBEF0: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800BBEF4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BBEF8: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800BBEFC: beq         $t8, $zero, L_800BBF98
    if (ctx->r24 == 0) {
        // 0x800BBF00: nop
    
            goto L_800BBF98;
    }
    // 0x800BBF00: nop

    // 0x800BBF04: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x800BBF08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBF0C: lw          $t9, 0x1C8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X1C8);
    // 0x800BBF10: bne         $t9, $at, L_800BBF98
    if (ctx->r25 != ctx->r1) {
        // 0x800BBF14: nop
    
            goto L_800BBF98;
    }
    // 0x800BBF14: nop

    // 0x800BBF18: beq         $a3, $a0, L_800BBF98
    if (ctx->r7 == ctx->r4) {
        // 0x800BBF1C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800BBF98;
    }
    // 0x800BBF1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBF20: beq         $a0, $at, L_800BBF98
    if (ctx->r4 == ctx->r1) {
        // 0x800BBF24: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_800BBF98;
    }
    // 0x800BBF24: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800BBF28: beq         $a0, $at, L_800BBF98
    if (ctx->r4 == ctx->r1) {
        // 0x800BBF2C: addiu       $a1, $zero, 0x4C
        ctx->r5 = ADD32(0, 0X4C);
            goto L_800BBF98;
    }
    // 0x800BBF2C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x800BBF30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BBF34: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BBF38: jal         0x800B8DD0
    // 0x800BBF3C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    RCP_SetupDL(rdram, ctx);
        goto after_16;
    // 0x800BBF3C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_16:
    // 0x800BBF40: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBF44: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x800BBF48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBF4C: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x800BBF50: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800BBF54: sw          $t2, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r10;
    // 0x800BBF58: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x800BBF5C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800BBF60: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800BBF64: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800BBF68: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BBF6C: addiu       $t6, $t6, -0x7408
    ctx->r14 = ADD32(ctx->r14, -0X7408);
    // 0x800BBF70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BBF74: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800BBF78: addiu       $a1, $zero, 0xA7
    ctx->r5 = ADD32(0, 0XA7);
    // 0x800BBF7C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800BBF80: jal         0x800A1200
    // 0x800BBF84: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_17;
    // 0x800BBF84: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_17:
    // 0x800BBF88: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BBF8C: lw          $a0, -0x7D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D5C);
    // 0x800BBF90: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BBF94: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_800BBF98:
    // 0x800BBF98: beq         $a3, $a0, L_800BBFF4
    if (ctx->r7 == ctx->r4) {
        // 0x800BBF9C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800BBFF4;
    }
    // 0x800BBF9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBFA0: beq         $a0, $at, L_800BBFF4
    if (ctx->r4 == ctx->r1) {
        // 0x800BBFA4: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_800BBFF4;
    }
    // 0x800BBFA4: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800BBFA8: beq         $a0, $at, L_800BBFF4
    if (ctx->r4 == ctx->r1) {
        // 0x800BBFAC: nop
    
            goto L_800BBFF4;
    }
    // 0x800BBFAC: nop

    // 0x800BBFB0: lh          $t5, 0xCE($t0)
    ctx->r13 = MEM_H(ctx->r8, 0XCE);
    // 0x800BBFB4: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800BBFB8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BBFBC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800BBFC0: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800BBFC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800BBFC8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBFCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BBFD0: lwc1        $f18, -0x6DFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6DFC);
    // 0x800BBFD4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800BBFD8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BBFDC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BBFE0: jal         0x80086110
    // 0x800BBFE4: nop

    HUD_TeamShields_Draw(rdram, ctx);
        goto after_18;
    // 0x800BBFE4: nop

    after_18:
    // 0x800BBFE8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BBFEC: lw          $a0, -0x7D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D5C);
    // 0x800BBFF0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_800BBFF4:
    // 0x800BBFF4: beq         $a3, $a0, L_800BC014
    if (ctx->r7 == ctx->r4) {
        // 0x800BBFF8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800BC014;
    }
    // 0x800BBFF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBFFC: beq         $a0, $at, L_800BC014
    if (ctx->r4 == ctx->r1) {
        // 0x800BC000: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_800BC014;
    }
    // 0x800BC000: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800BC004: beq         $a0, $at, L_800BC014
    if (ctx->r4 == ctx->r1) {
        // 0x800BC008: nop
    
            goto L_800BC014;
    }
    // 0x800BC008: nop

    // 0x800BC00C: jal         0x8008AD94
    // 0x800BC010: nop

    HUD_RadioCharacterName_Draw(rdram, ctx);
        goto after_19;
    // 0x800BC010: nop

    after_19:
L_800BC014:
    // 0x800BC014: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BC018: lw          $t8, -0x7D00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D00);
    // 0x800BC01C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BC020: bnel        $t8, $at, L_800BC034
    if (ctx->r24 != ctx->r1) {
        // 0x800BC024: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800BC034;
    }
    goto skip_2;
    // 0x800BC024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800BC028: jal         0x800BA760
    // 0x800BC02C: nop

    func_radio_800BA760(rdram, ctx);
        goto after_20;
    // 0x800BC02C: nop

    after_20:
L_800BC030:
    // 0x800BC030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800BC034:
    // 0x800BC034: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800BC038: jr          $ra
    // 0x800BC03C: nop

    return;
    // 0x800BC03C: nop

;}
RECOMP_FUNC void func_8000CAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CAF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000CAF8: lwc1        $f0, -0x79A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X79A0);
    // 0x8000CAFC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000CB00: addiu       $a0, $sp, 0x14
    ctx->r4 = ADD32(ctx->r29, 0X14);
    // 0x8000CB04: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000CB08: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x8000CB0C: addiu       $v1, $a2, 0x4
    ctx->r3 = ADD32(ctx->r6, 0X4);
    // 0x8000CB10: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000CB14: nop

    // 0x8000CB18: mul.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000CB1C: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x8000CB20: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8000CB24: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000CB28: nop

    // 0x8000CB2C: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8000CB30: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8000CB34: add.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8000CB38: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8000CB3C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
L_8000CB40:
    // 0x8000CB40: lwc1        $f6, -0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, -0X4);
    // 0x8000CB44: lwc1        $f10, -0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8000CB48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000CB4C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000CB50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000CB54: mul.s       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8000CB58: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8000CB5C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000CB60: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CB64: nop

    // 0x8000CB68: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000CB6C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000CB70: nop

    // 0x8000CB74: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8000CB78: beql        $t7, $zero, L_8000CBC8
    if (ctx->r15 == 0) {
        // 0x8000CB7C: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_8000CBC8;
    }
    goto skip_0;
    // 0x8000CB7C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x8000CB80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CB84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000CB88: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000CB8C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CB90: nop

    // 0x8000CB94: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000CB98: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000CB9C: nop

    // 0x8000CBA0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8000CBA4: bne         $t7, $zero, L_8000CBBC
    if (ctx->r15 != 0) {
        // 0x8000CBA8: nop
    
            goto L_8000CBBC;
    }
    // 0x8000CBA8: nop

    // 0x8000CBAC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8000CBB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CBB4: b           L_8000CBD4
    // 0x8000CBB8: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8000CBD4;
    // 0x8000CBB8: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8000CBBC:
    // 0x8000CBBC: b           L_8000CBD4
    // 0x8000CBC0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8000CBD4;
    // 0x8000CBC0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000CBC4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_8000CBC8:
    // 0x8000CBC8: nop

    // 0x8000CBCC: bltz        $t7, L_8000CBBC
    if (SIGNED(ctx->r15) < 0) {
        // 0x8000CBD0: nop
    
            goto L_8000CBBC;
    }
    // 0x8000CBD0: nop

L_8000CBD4:
    // 0x8000CBD4: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8000CBD8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000CBDC: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000CBE0: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000CBE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000CBE8: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000CBEC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CBF0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000CBF4: mul.s       $f16, $f14, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8000CBF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000CBFC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000CC00: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000CC04: nop

    // 0x8000CC08: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000CC0C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000CC10: nop

    // 0x8000CC14: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8000CC18: beql        $t9, $zero, L_8000CC68
    if (ctx->r25 == 0) {
        // 0x8000CC1C: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_8000CC68;
    }
    goto skip_1;
    // 0x8000CC1C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x8000CC20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CC24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000CC28: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000CC2C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000CC30: nop

    // 0x8000CC34: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000CC38: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000CC3C: nop

    // 0x8000CC40: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8000CC44: bne         $t9, $zero, L_8000CC5C
    if (ctx->r25 != 0) {
        // 0x8000CC48: nop
    
            goto L_8000CC5C;
    }
    // 0x8000CC48: nop

    // 0x8000CC4C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8000CC50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CC54: b           L_8000CC74
    // 0x8000CC58: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8000CC74;
    // 0x8000CC58: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8000CC5C:
    // 0x8000CC5C: b           L_8000CC74
    // 0x8000CC60: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8000CC74;
    // 0x8000CC60: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000CC64: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_8000CC68:
    // 0x8000CC68: nop

    // 0x8000CC6C: bltz        $t9, L_8000CC5C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8000CC70: nop
    
            goto L_8000CC5C;
    }
    // 0x8000CC70: nop

L_8000CC74:
    // 0x8000CC74: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8000CC78: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000CC7C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8000CC80: bne         $at, $zero, L_8000CB40
    if (ctx->r1 != 0) {
        // 0x8000CC84: sh          $t9, 0xE($v1)
        MEM_H(0XE, ctx->r3) = ctx->r25;
            goto L_8000CB40;
    }
    // 0x8000CC84: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
    // 0x8000CC88: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8000CC8C: addiu       $a0, $sp, 0xC
    ctx->r4 = ADD32(ctx->r29, 0XC);
    // 0x8000CC90: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
L_8000CC94:
    // 0x8000CC94: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8000CC98: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000CC9C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000CCA0: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000CCA4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000CCA8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000CCAC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000CCB0: nop

    // 0x8000CCB4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000CCB8: beql        $t1, $zero, L_8000CD08
    if (ctx->r9 == 0) {
        // 0x8000CCBC: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_8000CD08;
    }
    goto skip_2;
    // 0x8000CCBC: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x8000CCC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000CCC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000CCC8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000CCCC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000CCD0: nop

    // 0x8000CCD4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000CCD8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000CCDC: nop

    // 0x8000CCE0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000CCE4: bne         $t1, $zero, L_8000CCFC
    if (ctx->r9 != 0) {
        // 0x8000CCE8: nop
    
            goto L_8000CCFC;
    }
    // 0x8000CCE8: nop

    // 0x8000CCEC: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8000CCF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CCF4: b           L_8000CD14
    // 0x8000CCF8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8000CD14;
    // 0x8000CCF8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8000CCFC:
    // 0x8000CCFC: b           L_8000CD14
    // 0x8000CD00: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8000CD14;
    // 0x8000CD00: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000CD04: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_8000CD08:
    // 0x8000CD08: nop

    // 0x8000CD0C: bltz        $t1, L_8000CCFC
    if (SIGNED(ctx->r9) < 0) {
        // 0x8000CD10: nop
    
            goto L_8000CCFC;
    }
    // 0x8000CD10: nop

L_8000CD14:
    // 0x8000CD14: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000CD18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000CD1C: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8000CD20: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000CD24: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000CD28: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8000CD2C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000CD30: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000CD34: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8000CD38: nop

    // 0x8000CD3C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8000CD40: beql        $t3, $zero, L_8000CD90
    if (ctx->r11 == 0) {
        // 0x8000CD44: mfc1        $t3, $f16
        ctx->r11 = (int32_t)ctx->f16.u32l;
            goto L_8000CD90;
    }
    goto skip_3;
    // 0x8000CD44: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x8000CD48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000CD4C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000CD50: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000CD54: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8000CD58: nop

    // 0x8000CD5C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000CD60: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8000CD64: nop

    // 0x8000CD68: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8000CD6C: bne         $t3, $zero, L_8000CD84
    if (ctx->r11 != 0) {
        // 0x8000CD70: nop
    
            goto L_8000CD84;
    }
    // 0x8000CD70: nop

    // 0x8000CD74: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8000CD78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CD7C: b           L_8000CD9C
    // 0x8000CD80: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8000CD9C;
    // 0x8000CD80: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8000CD84:
    // 0x8000CD84: b           L_8000CD9C
    // 0x8000CD88: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8000CD9C;
    // 0x8000CD88: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8000CD8C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
L_8000CD90:
    // 0x8000CD90: nop

    // 0x8000CD94: bltz        $t3, L_8000CD84
    if (SIGNED(ctx->r11) < 0) {
        // 0x8000CD98: nop
    
            goto L_8000CD84;
    }
    // 0x8000CD98: nop

L_8000CD9C:
    // 0x8000CD9C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000CDA0: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x8000CDA4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000CDA8: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000CDAC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000CDB0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8000CDB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000CDB8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000CDBC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8000CDC0: nop

    // 0x8000CDC4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8000CDC8: beql        $t5, $zero, L_8000CE18
    if (ctx->r13 == 0) {
        // 0x8000CDCC: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_8000CE18;
    }
    goto skip_4;
    // 0x8000CDCC: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x8000CDD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CDD4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000CDD8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000CDDC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8000CDE0: nop

    // 0x8000CDE4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000CDE8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8000CDEC: nop

    // 0x8000CDF0: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8000CDF4: bne         $t5, $zero, L_8000CE0C
    if (ctx->r13 != 0) {
        // 0x8000CDF8: nop
    
            goto L_8000CE0C;
    }
    // 0x8000CDF8: nop

    // 0x8000CDFC: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8000CE00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CE04: b           L_8000CE24
    // 0x8000CE08: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8000CE24;
    // 0x8000CE08: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8000CE0C:
    // 0x8000CE0C: b           L_8000CE24
    // 0x8000CE10: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8000CE24;
    // 0x8000CE10: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8000CE14: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_8000CE18:
    // 0x8000CE18: nop

    // 0x8000CE1C: bltz        $t5, L_8000CE0C
    if (SIGNED(ctx->r13) < 0) {
        // 0x8000CE20: nop
    
            goto L_8000CE0C;
    }
    // 0x8000CE20: nop

L_8000CE24:
    // 0x8000CE24: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000CE28: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
    // 0x8000CE2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000CE30: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CE34: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000CE38: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CE3C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8000CE40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000CE44: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000CE48: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000CE4C: nop

    // 0x8000CE50: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8000CE54: beql        $t7, $zero, L_8000CEA4
    if (ctx->r15 == 0) {
        // 0x8000CE58: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_8000CEA4;
    }
    goto skip_5;
    // 0x8000CE58: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x8000CE5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000CE60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000CE64: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000CE68: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CE6C: nop

    // 0x8000CE70: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000CE74: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000CE78: nop

    // 0x8000CE7C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8000CE80: bne         $t7, $zero, L_8000CE98
    if (ctx->r15 != 0) {
        // 0x8000CE84: nop
    
            goto L_8000CE98;
    }
    // 0x8000CE84: nop

    // 0x8000CE88: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8000CE8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CE90: b           L_8000CEB0
    // 0x8000CE94: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8000CEB0;
    // 0x8000CE94: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8000CE98:
    // 0x8000CE98: b           L_8000CEB0
    // 0x8000CE9C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8000CEB0;
    // 0x8000CE9C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000CEA0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_8000CEA4:
    // 0x8000CEA4: nop

    // 0x8000CEA8: bltz        $t7, L_8000CE98
    if (SIGNED(ctx->r15) < 0) {
        // 0x8000CEAC: nop
    
            goto L_8000CE98;
    }
    // 0x8000CEAC: nop

L_8000CEB0:
    // 0x8000CEB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000CEB4: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x8000CEB8: bne         $a0, $v0, L_8000CC94
    if (ctx->r4 != ctx->r2) {
        // 0x8000CEBC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8000CC94;
    }
    // 0x8000CEBC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000CEC0: jr          $ra
    // 0x8000CEC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000CEC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void AudioHeap_Alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF14: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x8000BF18: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000BF1C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8000BF20: addiu       $v0, $a1, 0xF
    ctx->r2 = ADD32(ctx->r5, 0XF);
    // 0x8000BF24: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000BF28: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8000BF2C: addu        $t0, $a2, $t6
    ctx->r8 = ADD32(ctx->r6, ctx->r14);
    // 0x8000BF30: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000BF34: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x8000BF38: bne         $at, $zero, L_8000BF4C
    if (ctx->r1 != 0) {
        // 0x8000BF3C: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8000BF4C;
    }
    // 0x8000BF3C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8000BF40: addu        $t1, $a2, $t6
    ctx->r9 = ADD32(ctx->r6, ctx->r14);
    // 0x8000BF44: b           L_8000BF54
    // 0x8000BF48: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
        goto L_8000BF54;
    // 0x8000BF48: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
L_8000BF4C:
    // 0x8000BF4C: jr          $ra
    // 0x8000BF50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000BF50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BF54:
    // 0x8000BF54: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x8000BF58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000BF5C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000BF60: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x8000BF64: jr          $ra
    // 0x8000BF68: nop

    return;
    // 0x8000BF68: nop

;}
RECOMP_FUNC void ActorEvent_UpdateTexLines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA50: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8006EA54: beq         $t6, $zero, L_8006EABC
    if (ctx->r14 == 0) {
        // 0x8006EA58: nop
    
            goto L_8006EABC;
    }
    // 0x8006EA58: nop

    // 0x8006EA5C: lw          $t7, 0x70($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X70);
    // 0x8006EA60: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8006EA64: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006EA68: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EA6C: addiu       $v1, $v1, 0x4750
    ctx->r3 = ADD32(ctx->r3, 0X4750);
    // 0x8006EA70: mflo        $t8
    ctx->r24 = lo;
    // 0x8006EA74: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8006EA78: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8006EA7C: beq         $t9, $zero, L_8006EABC
    if (ctx->r25 == 0) {
        // 0x8006EA80: nop
    
            goto L_8006EABC;
    }
    // 0x8006EA80: nop

    // 0x8006EA84: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006EA88: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8006EA8C: lw          $t0, 0x70($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X70);
    // 0x8006EA90: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006EA94: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EA98: mflo        $t1
    ctx->r9 = lo;
    // 0x8006EA9C: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8006EAA0: swc1        $f6, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f6.u32l;
    // 0x8006EAA4: lw          $t3, 0x70($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X70);
    // 0x8006EAA8: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006EAAC: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EAB0: mflo        $t4
    ctx->r12 = lo;
    // 0x8006EAB4: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8006EAB8: swc1        $f8, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f8.u32l;
L_8006EABC:
    // 0x8006EABC: jr          $ra
    // 0x8006EAC0: nop

    return;
    // 0x8006EAC0: nop

;}
RECOMP_FUNC void Play_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5844: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A5848: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800A584C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A5850: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800A5854: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800A5858: addiu       $a3, $a3, 0x7A80
    ctx->r7 = ADD32(ctx->r7, 0X7A80);
    // 0x800A585C: addiu       $a2, $a2, 0x7838
    ctx->r6 = ADD32(ctx->r6, 0X7838);
    // 0x800A5860: addiu       $a1, $a1, 0x7840
    ctx->r5 = ADD32(ctx->r5, 0X7840);
    // 0x800A5864: addiu       $a0, $a0, -0x7D64
    ctx->r4 = ADD32(ctx->r4, -0X7D64);
    // 0x800A5868: addiu       $v1, $v1, 0x7CA0
    ctx->r3 = ADD32(ctx->r3, 0X7CA0);
    // 0x800A586C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5870: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x800A5874: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5878: sw          $zero, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = 0;
    // 0x800A587C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5880: sb          $zero, 0x1684($at)
    MEM_B(0X1684, ctx->r1) = 0;
    // 0x800A5884: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5888: sb          $zero, 0x1A50($at)
    MEM_B(0X1A50, ctx->r1) = 0;
    // 0x800A588C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5890: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    // 0x800A5894: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A5898: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A589C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A58A0: sw          $zero, -0x6DC($at)
    MEM_W(-0X6DC, ctx->r1) = 0;
    // 0x800A58A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A58A8: swc1        $f4, 0x7CB0($at)
    MEM_W(0X7CB0, ctx->r1) = ctx->f4.u32l;
    // 0x800A58AC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800A58B0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800A58B4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800A58B8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800A58BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A58C0: sw          $zero, 0x1A9C($at)
    MEM_W(0X1A9C, ctx->r1) = 0;
    // 0x800A58C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800A58C8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800A58CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A58D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A58D4: sw          $t1, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = ctx->r9;
    // 0x800A58D8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800A58DC: bne         $v0, $at, L_800A58F0
    if (ctx->r2 != ctx->r1) {
        // 0x800A58E0: lui         $t2, 0x8016
        ctx->r10 = S32(0X8016 << 16);
            goto L_800A58F0;
    }
    // 0x800A58E0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800A58E4: lhu         $t2, 0x1A2E($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1A2E);
    // 0x800A58E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A58EC: beq         $t2, $at, L_800A5944
    if (ctx->r10 == ctx->r1) {
        // 0x800A58F0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800A5944;
    }
L_800A58F0:
    // 0x800A58F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A58F4: beq         $v0, $at, L_800A5944
    if (ctx->r2 == ctx->r1) {
        // 0x800A58F8: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800A5944;
    }
    // 0x800A58F8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A58FC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A5900: addiu       $a1, $a1, 0x78E0
    ctx->r5 = ADD32(ctx->r5, 0X78E0);
    // 0x800A5904: addiu       $v1, $v1, 0x78D4
    ctx->r3 = ADD32(ctx->r3, 0X78D4);
    // 0x800A5908: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800A590C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800A5910: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_800A5914:
    // 0x800A5914: bgez        $v0, L_800A592C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A5918: nop
    
            goto L_800A592C;
    }
    // 0x800A5918: nop

    // 0x800A591C: bnel        $a0, $v0, L_800A593C
    if (ctx->r4 != ctx->r2) {
        // 0x800A5920: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A593C;
    }
    goto skip_0;
    // 0x800A5920: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x800A5924: b           L_800A5938
    // 0x800A5928: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800A5938;
    // 0x800A5928: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800A592C:
    // 0x800A592C: bnel        $v0, $zero, L_800A593C
    if (ctx->r2 != 0) {
        // 0x800A5930: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A593C;
    }
    goto skip_1;
    // 0x800A5930: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_1:
    // 0x800A5934: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_800A5938:
    // 0x800A5938: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800A593C:
    // 0x800A593C: bnel        $v1, $a1, L_800A5914
    if (ctx->r3 != ctx->r5) {
        // 0x800A5940: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_800A5914;
    }
    goto skip_2;
    // 0x800A5940: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_2:
L_800A5944:
    // 0x800A5944: jr          $ra
    // 0x800A5948: nop

    return;
    // 0x800A5948: nop

;}
RECOMP_FUNC void ActorEvent_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074FF0: addiu       $sp, $sp, -0x288
    ctx->r29 = ADD32(ctx->r29, -0X288);
    // 0x80074FF4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80074FF8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80074FFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80075000: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80075004: lhu         $a1, 0xC6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XC6);
    // 0x80075008: beql        $a1, $zero, L_80075200
    if (ctx->r5 == 0) {
        // 0x8007500C: lbu         $t5, 0x0($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X0);
            goto L_80075200;
    }
    goto skip_0;
    // 0x8007500C: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    skip_0:
    // 0x80075010: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
    // 0x80075014: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80075018: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x8007501C: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_800751FC;
    }
    // 0x8007501C: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80075020: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x80075024: addiu       $s0, $zero, 0x48
        ctx->r16 = ADD32(0, 0X48);
            goto L_800751FC;
    }
    // 0x80075024: addiu       $s0, $zero, 0x48
    ctx->r16 = ADD32(0, 0X48);
    // 0x80075028: beq         $s0, $v1, L_800751FC
    if (ctx->r16 == ctx->r3) {
        // 0x8007502C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800751FC;
    }
    // 0x8007502C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80075030: beq         $v1, $at, L_800750D8
    if (ctx->r3 == ctx->r1) {
        // 0x80075034: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_800750D8;
    }
    // 0x80075034: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80075038: beq         $v1, $at, L_800750D8
    if (ctx->r3 == ctx->r1) {
        // 0x8007503C: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_800750D8;
    }
    // 0x8007503C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80075040: beq         $v1, $at, L_800750D8
    if (ctx->r3 == ctx->r1) {
        // 0x80075044: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_800750D8;
    }
    // 0x80075044: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80075048: beq         $v1, $at, L_800750D8
    if (ctx->r3 == ctx->r1) {
        // 0x8007504C: addiu       $at, $zero, 0x53
        ctx->r1 = ADD32(0, 0X53);
            goto L_800750D8;
    }
    // 0x8007504C: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x80075050: beq         $v1, $at, L_800750D8
    if (ctx->r3 == ctx->r1) {
        // 0x80075054: addiu       $at, $zero, 0x62
        ctx->r1 = ADD32(0, 0X62);
            goto L_800750D8;
    }
    // 0x80075054: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x80075058: beq         $v1, $at, L_800750D8
    if (ctx->r3 == ctx->r1) {
        // 0x8007505C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800750D8;
    }
    // 0x8007505C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80075060: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80075064: lwc1        $f0, 0x110($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80075068: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x8007506C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80075070: nop

    // 0x80075074: bc1fl       L_800750DC
    if (!c1cs) {
        // 0x80075078: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_800750DC;
    }
    goto skip_1;
    // 0x80075078: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    skip_1:
    // 0x8007507C: bne         $at, $zero, L_800750D8
    if (ctx->r1 != 0) {
        // 0x80075080: andi        $t6, $a1, 0x3
        ctx->r14 = ctx->r5 & 0X3;
            goto L_800750D8;
    }
    // 0x80075080: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x80075084: bne         $t6, $zero, L_800750D8
    if (ctx->r14 != 0) {
        // 0x80075088: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_800750D8;
    }
    // 0x80075088: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8007508C: lw          $t7, 0x7854($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7854);
    // 0x80075090: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80075094: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80075098: beq         $t7, $at, L_800750D8
    if (ctx->r15 == ctx->r1) {
        // 0x8007509C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800750D8;
    }
    // 0x8007509C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800750A0: lwc1        $f10, 0x6FCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FCC);
    // 0x800750A4: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x800750A8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800750AC: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800750B0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800750B4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800750B8: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x800750BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800750C0: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800750C4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800750C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800750CC: jal         0x8007C120
    // 0x800750D0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_0;
    // 0x800750D0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800750D4: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_800750D8:
    // 0x800750D8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
L_800750DC:
    // 0x800750DC: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x800750E0: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_800751FC;
    }
    // 0x800750E0: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x800750E4: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x800750E8: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_800751FC;
    }
    // 0x800750E8: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x800750EC: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x800750F0: addiu       $at, $zero, 0x53
        ctx->r1 = ADD32(0, 0X53);
            goto L_800751FC;
    }
    // 0x800750F0: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800750F4: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x800750F8: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_800751FC;
    }
    // 0x800750F8: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800750FC: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x80075100: addiu       $at, $zero, 0x33
        ctx->r1 = ADD32(0, 0X33);
            goto L_800751FC;
    }
    // 0x80075100: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80075104: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x80075108: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800751FC;
    }
    // 0x80075108: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007510C: beql        $v1, $at, L_80075200
    if (ctx->r3 == ctx->r1) {
        // 0x80075110: lbu         $t5, 0x0($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X0);
            goto L_80075200;
    }
    goto skip_2;
    // 0x80075110: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    skip_2:
    // 0x80075114: beq         $s0, $v1, L_800751FC
    if (ctx->r16 == ctx->r3) {
        // 0x80075118: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_800751FC;
    }
    // 0x80075118: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8007511C: beq         $v1, $at, L_800751FC
    if (ctx->r3 == ctx->r1) {
        // 0x80075120: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800751FC;
    }
    // 0x80075120: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80075124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80075128: lwc1        $f8, 0x110($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X110);
    // 0x8007512C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80075130: nop

    // 0x80075134: bc1fl       L_80075200
    if (!c1cs) {
        // 0x80075138: lbu         $t5, 0x0($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X0);
            goto L_80075200;
    }
    goto skip_3;
    // 0x80075138: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    skip_3:
    // 0x8007513C: lhu         $t9, 0xC6($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XC6);
    // 0x80075140: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80075144: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80075148: bgez        $t9, L_8007515C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007514C: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8007515C;
    }
    // 0x8007514C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80075150: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80075154: nop

    // 0x80075158: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8007515C:
    // 0x8007515C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80075160: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80075164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075168: lwc1        $f6, 0x6FD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FD0);
    // 0x8007516C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80075170: nop

    // 0x80075174: mul.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80075178: jal         0x80023090
    // 0x8007517C: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007517C: nop

    after_1:
    // 0x80075180: lhu         $t4, 0xC6($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XC6);
    // 0x80075184: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80075188: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8007518C: bgez        $t4, L_800751A0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80075190: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800751A0;
    }
    // 0x80075190: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80075194: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80075198: nop

    // 0x8007519C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800751A0:
    // 0x800751A0: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800751A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800751A8: lwc1        $f6, 0x6FD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FD4);
    // 0x800751AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800751B0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800751B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800751B8: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800751BC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800751C0: jal         0x80005E90
    // 0x800751C4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x800751C4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x800751C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800751CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800751D0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800751D4: jal         0x80005D44
    // 0x800751D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x800751D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800751DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800751E0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800751E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800751E8: jal         0x80005FE0
    // 0x800751EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x800751EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800751F0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800751F4: jal         0x80006EB8
    // 0x800751F8: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x800751F8: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    after_5:
L_800751FC:
    // 0x800751FC: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
L_80075200:
    // 0x80075200: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80075204: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80075208: bne         $t5, $at, L_80075244
    if (ctx->r13 != ctx->r1) {
        // 0x8007520C: addiu       $s0, $s0, 0x7E64
        ctx->r16 = ADD32(ctx->r16, 0X7E64);
            goto L_80075244;
    }
    // 0x8007520C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80075210: lhu         $t6, 0xBE($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XBE);
    // 0x80075214: beql        $t6, $zero, L_80075248
    if (ctx->r14 == 0) {
        // 0x80075218: lh          $v1, 0xB4($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XB4);
            goto L_80075248;
    }
    goto skip_4;
    // 0x80075218: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
    skip_4:
    // 0x8007521C: jal         0x800BA400
    // 0x80075220: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_6;
    // 0x80075220: nop

    after_6:
    // 0x80075224: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075228: lui         $t9, 0xFF00
    ctx->r25 = S32(0XFF00 << 16);
    // 0x8007522C: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x80075230: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80075234: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80075238: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007523C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80075240: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80075244:
    // 0x80075244: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80075248:
    // 0x80075248: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8007524C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80075250: beq         $v1, $at, L_80075268
    if (ctx->r3 == ctx->r1) {
        // 0x80075254: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_80075268;
    }
    // 0x80075254: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80075258: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x8007525C: beq         $v1, $at, L_80075268
    if (ctx->r3 == ctx->r1) {
        // 0x80075260: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80075268;
    }
    // 0x80075260: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80075264: bne         $v1, $at, L_800752A4
    if (ctx->r3 != ctx->r1) {
        // 0x80075268: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_800752A4;
    }
L_80075268:
    // 0x80075268: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8007526C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80075270: lw          $t5, -0x7C24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C24);
    // 0x80075274: lw          $t4, -0x7C28($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C28);
    // 0x80075278: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8007527C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80075280: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80075284: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80075288: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8007528C: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80075290: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80075294: jal         0x800B9B38
    // 0x80075298: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    RCP_SetupDL_60(rdram, ctx);
        goto after_7;
    // 0x80075298: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_7:
    // 0x8007529C: b           L_80075304
    // 0x800752A0: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
        goto L_80075304;
    // 0x800752A0: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_800752A4:
    // 0x800752A4: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x800752A8: beq         $v1, $at, L_800752D0
    if (ctx->r3 == ctx->r1) {
        // 0x800752AC: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_800752D0;
    }
    // 0x800752AC: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x800752B0: beq         $v1, $at, L_800752D0
    if (ctx->r3 == ctx->r1) {
        // 0x800752B4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800752D0;
    }
    // 0x800752B4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800752B8: bne         $v1, $at, L_80075304
    if (ctx->r3 != ctx->r1) {
        // 0x800752BC: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_80075304;
    }
    // 0x800752BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800752C0: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800752C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800752C8: bnel        $t6, $at, L_80075308
    if (ctx->r14 != ctx->r1) {
        // 0x800752CC: addiu       $t9, $v1, -0x5C
        ctx->r25 = ADD32(ctx->r3, -0X5C);
            goto L_80075308;
    }
    goto skip_5;
    // 0x800752CC: addiu       $t9, $v1, -0x5C
    ctx->r25 = ADD32(ctx->r3, -0X5C);
    skip_5:
L_800752D0:
    // 0x800752D0: lhu         $t7, 0xC6($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XC6);
    // 0x800752D4: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x800752D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800752DC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800752E0: bne         $t8, $zero, L_800752F8
    if (ctx->r24 != 0) {
        // 0x800752E4: nop
    
            goto L_800752F8;
    }
    // 0x800752E4: nop

    // 0x800752E8: jal         0x800B8DD0
    // 0x800752EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x800752EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800752F0: b           L_80075304
    // 0x800752F4: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
        goto L_80075304;
    // 0x800752F4: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_800752F8:
    // 0x800752F8: jal         0x800B8DD0
    // 0x800752FC: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x800752FC: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_9:
    // 0x80075300: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80075304:
    // 0x80075304: addiu       $t9, $v1, -0x5C
    ctx->r25 = ADD32(ctx->r3, -0X5C);
L_80075308:
    // 0x80075308: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x8007530C: beq         $at, $zero, L_800753FC
    if (ctx->r1 == 0) {
        // 0x80075310: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800753FC;
    }
    // 0x80075310: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80075314: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075318: addu        $at, $at, $t9
    gpr jr_addend_80075320 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8007531C: lw          $t9, 0x6FD8($at)
    ctx->r25 = ADD32(ctx->r1, 0X6FD8);
    // 0x80075320: jr          $t9
    // 0x80075324: nop

    switch (jr_addend_80075320 >> 2) {
        case 0: goto L_80075328; break;
        case 1: goto L_80075328; break;
        case 2: goto L_80075328; break;
        case 3: goto L_80075328; break;
        case 4: goto L_80075328; break;
        default: switch_error(__func__, 0x80075320, 0x800D6FD8);
    }
    // 0x80075324: nop

L_80075328:
    // 0x80075328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007532C: jal         0x800B8DD0
    // 0x80075330: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x80075330: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_10:
    // 0x80075334: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x80075338: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007533C: addiu       $t0, $t0, 0x3C
    ctx->r8 = ADD32(ctx->r8, 0X3C);
    // 0x80075340: ori         $a3, $a3, 0xC02
    ctx->r7 = ctx->r7 | 0XC02;
    // 0x80075344: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075348: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8007534C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80075350: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075354: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80075358: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007535C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80075360: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80075364: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80075368: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007536C: lwc1        $f4, 0x158($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X158);
    // 0x80075370: lwc1        $f8, 0x150($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80075374: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80075378: lwc1        $f4, 0x154($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X154);
    // 0x8007537C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80075380: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80075384: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80075388: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8007538C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80075390: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x80075394: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80075398: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8007539C: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800753A0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800753A4: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800753A8: or          $t8, $t9, $t4
    ctx->r24 = ctx->r25 | ctx->r12;
    // 0x800753AC: ori         $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 | 0XFF;
    // 0x800753B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800753B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800753B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800753BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800753C0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800753C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800753C8: lh          $t9, 0xB4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XB4);
    // 0x800753CC: sll         $t4, $t9, 5
    ctx->r12 = S32(ctx->r25 << 5);
    // 0x800753D0: addu        $t8, $t0, $t4
    ctx->r24 = ADD32(ctx->r8, ctx->r12);
    // 0x800753D4: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x800753D8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800753DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800753E0: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x800753E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800753E8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800753EC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800753F0: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x800753F4: b           L_80076394
    // 0x800753F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80076394;
    // 0x800753F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800753FC:
    // 0x800753FC: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    // 0x80075400: beq         $at, $zero, L_8007544C
    if (ctx->r1 == 0) {
        // 0x80075404: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_8007544C;
    }
    // 0x80075404: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80075408: addiu       $t0, $t0, 0x3C
    ctx->r8 = ADD32(ctx->r8, 0X3C);
    // 0x8007540C: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x80075410: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x80075414: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80075418: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8007541C: beql        $t8, $zero, L_80075450
    if (ctx->r24 == 0) {
        // 0x80075420: slti        $at, $v1, 0x6B
        ctx->r1 = SIGNED(ctx->r3) < 0X6B ? 1 : 0;
            goto L_80075450;
    }
    goto skip_6;
    // 0x80075420: slti        $at, $v1, 0x6B
    ctx->r1 = SIGNED(ctx->r3) < 0X6B ? 1 : 0;
    skip_6:
    // 0x80075424: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075428: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8007542C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80075430: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80075434: lh          $t6, 0xB4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XB4);
    // 0x80075438: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8007543C: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x80075440: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80075444: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80075448: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_8007544C:
    // 0x8007544C: slti        $at, $v1, 0x6B
    ctx->r1 = SIGNED(ctx->r3) < 0X6B ? 1 : 0;
L_80075450:
    // 0x80075450: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80075454: bne         $at, $zero, L_80075470
    if (ctx->r1 != 0) {
        // 0x80075458: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80075470;
    }
    // 0x80075458: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007545C: addiu       $at, $zero, 0xFFF
    ctx->r1 = ADD32(0, 0XFFF);
    // 0x80075460: beq         $v1, $at, L_800762E0
    if (ctx->r3 == ctx->r1) {
        // 0x80075464: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_800762E0;
    }
    // 0x80075464: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80075468: b           L_800762E4
    // 0x8007546C: nop

        goto L_800762E4;
    // 0x8007546C: nop

L_80075470:
    // 0x80075470: sltiu       $at, $v0, 0x6B
    ctx->r1 = ctx->r2 < 0X6B ? 1 : 0;
    // 0x80075474: beq         $at, $zero, L_800762E4
    if (ctx->r1 == 0) {
        // 0x80075478: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_800762E4;
    }
    // 0x80075478: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8007547C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075480: addu        $at, $at, $t8
    gpr jr_addend_80075488 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80075484: lw          $t8, 0x6FEC($at)
    ctx->r24 = ADD32(ctx->r1, 0X6FEC);
    // 0x80075488: jr          $t8
    // 0x8007548C: nop

    switch (jr_addend_80075488 >> 2) {
        case 0: goto L_800754A0; break;
        case 1: goto L_800762E4; break;
        case 2: goto L_800754B8; break;
        case 3: goto L_800762E4; break;
        case 4: goto L_800762E4; break;
        case 5: goto L_80075650; break;
        case 6: goto L_80075668; break;
        case 7: goto L_80075740; break;
        case 8: goto L_800762E4; break;
        case 9: goto L_80075758; break;
        case 10: goto L_800762E4; break;
        case 11: goto L_800762E4; break;
        case 12: goto L_800762E4; break;
        case 13: goto L_800762E4; break;
        case 14: goto L_800762E4; break;
        case 15: goto L_800762E4; break;
        case 16: goto L_800762E4; break;
        case 17: goto L_800762E4; break;
        case 18: goto L_800757C4; break;
        case 19: goto L_80075844; break;
        case 20: goto L_800758C4; break;
        case 21: goto L_80075928; break;
        case 22: goto L_800759B8; break;
        case 23: goto L_800762E4; break;
        case 24: goto L_800762E4; break;
        case 25: goto L_800762E4; break;
        case 26: goto L_800762E4; break;
        case 27: goto L_80075A48; break;
        case 28: goto L_800762E4; break;
        case 29: goto L_800762E4; break;
        case 30: goto L_800762E4; break;
        case 31: goto L_80075B84; break;
        case 32: goto L_800762E4; break;
        case 33: goto L_80075BCC; break;
        case 34: goto L_800762E4; break;
        case 35: goto L_800762E4; break;
        case 36: goto L_80075C80; break;
        case 37: goto L_800762E4; break;
        case 38: goto L_80075CD8; break;
        case 39: goto L_800762E4; break;
        case 40: goto L_800762E4; break;
        case 41: goto L_800762E4; break;
        case 42: goto L_800762E4; break;
        case 43: goto L_800755EC; break;
        case 44: goto L_800762E4; break;
        case 45: goto L_800762E4; break;
        case 46: goto L_800762E4; break;
        case 47: goto L_800762E4; break;
        case 48: goto L_80075CE8; break;
        case 49: goto L_80075CE8; break;
        case 50: goto L_80075CE8; break;
        case 51: goto L_800762E4; break;
        case 52: goto L_80075CF8; break;
        case 53: goto L_800762E4; break;
        case 54: goto L_800762E4; break;
        case 55: goto L_800762E4; break;
        case 56: goto L_80075490; break;
        case 57: goto L_800762E4; break;
        case 58: goto L_800762E4; break;
        case 59: goto L_800762E4; break;
        case 60: goto L_800762E4; break;
        case 61: goto L_800762E4; break;
        case 62: goto L_800762E4; break;
        case 63: goto L_800762E4; break;
        case 64: goto L_80075DB0; break;
        case 65: goto L_800762E4; break;
        case 66: goto L_800762E4; break;
        case 67: goto L_80075EF8; break;
        case 68: goto L_800762E4; break;
        case 69: goto L_800762E4; break;
        case 70: goto L_800762E4; break;
        case 71: goto L_800762E4; break;
        case 72: goto L_800762E4; break;
        case 73: goto L_800762E4; break;
        case 74: goto L_800762E4; break;
        case 75: goto L_800762E4; break;
        case 76: goto L_800762E4; break;
        case 77: goto L_800762E4; break;
        case 78: goto L_80075F48; break;
        case 79: goto L_80075F58; break;
        case 80: goto L_80075F74; break;
        case 81: goto L_80075FCC; break;
        case 82: goto L_80076060; break;
        case 83: goto L_800760B8; break;
        case 84: goto L_800762E4; break;
        case 85: goto L_80076128; break;
        case 86: goto L_80076154; break;
        case 87: goto L_800762E4; break;
        case 88: goto L_80076180; break;
        case 89: goto L_800761EC; break;
        case 90: goto L_800762E4; break;
        case 91: goto L_800762E4; break;
        case 92: goto L_800762E4; break;
        case 93: goto L_800762E4; break;
        case 94: goto L_800762E4; break;
        case 95: goto L_800762E4; break;
        case 96: goto L_800762E4; break;
        case 97: goto L_800762E4; break;
        case 98: goto L_800762E4; break;
        case 99: goto L_800762E4; break;
        case 100: goto L_800762E4; break;
        case 101: goto L_800762E4; break;
        case 102: goto L_800762E4; break;
        case 103: goto L_80076220; break;
        case 104: goto L_80076220; break;
        case 105: goto L_80076230; break;
        case 106: goto L_80076298; break;
        default: switch_error(__func__, 0x80075488, 0x800D6FEC);
    }
    // 0x8007548C: nop

L_80075490:
    // 0x80075490: jal         0x800515C4
    // 0x80075494: nop

    Cutscene_DrawGreatFox(rdram, ctx);
        goto after_11;
    // 0x80075494: nop

    after_11:
    // 0x80075498: b           L_800762E4
    // 0x8007549C: nop

        goto L_800762E4;
    // 0x8007549C: nop

L_800754A0:
    // 0x800754A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800754A4: sw          $t5, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r13;
    // 0x800754A8: jal         0x8005ADAC
    // 0x800754AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_12;
    // 0x800754AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800754B0: b           L_800762E4
    // 0x800754B4: nop

        goto L_800762E4;
    // 0x800754B4: nop

L_800754B8:
    // 0x800754B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800754BC: lwc1        $f8, 0x7198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7198);
    // 0x800754C0: lwc1        $f0, 0x150($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X150);
    // 0x800754C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800754C8: lwc1        $f14, 0x17C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X17C);
    // 0x800754CC: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800754D0: lwc1        $f12, 0x154($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X154);
    // 0x800754D4: lwc1        $f16, 0x180($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X180);
    // 0x800754D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800754DC: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800754E0: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800754E4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800754E8: swc1        $f4, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f4.u32l;
    // 0x800754EC: lwc1        $f10, 0x719C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X719C);
    // 0x800754F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800754F4: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800754F8: sub.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x800754FC: swc1        $f6, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = ctx->f6.u32l;
    // 0x80075500: lwc1        $f4, 0x71A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71A0);
    // 0x80075504: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075508: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8007550C: sub.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80075510: swc1        $f8, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f8.u32l;
    // 0x80075514: lwc1        $f6, 0x71A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X71A4);
    // 0x80075518: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007551C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80075520: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80075524: bc1f        L_8007557C
    if (!c1cs) {
        // 0x80075528: swc1        $f10, 0x180($s1)
        MEM_W(0X180, ctx->r17) = ctx->f10.u32l;
            goto L_8007557C;
    }
    // 0x80075528: swc1        $f10, 0x180($s1)
    MEM_W(0X180, ctx->r17) = ctx->f10.u32l;
    // 0x8007552C: lwc1        $f8, 0x71A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X71A8);
    // 0x80075530: lwc1        $f0, 0x150($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80075534: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075538: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8007553C: lwc1        $f10, 0x71AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71AC);
    // 0x80075540: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075544: lwc1        $f14, 0x17C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X17C);
    // 0x80075548: sub.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8007554C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80075550: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x80075554: add.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80075558: swc1        $f6, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f6.u32l;
    // 0x8007555C: lwc1        $f10, 0x71B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71B0);
    // 0x80075560: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075564: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80075568: lwc1        $f4, 0x71B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B4);
    // 0x8007556C: sub.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80075570: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80075574: add.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80075578: swc1        $f8, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = ctx->f8.u32l;
L_8007557C:
    // 0x8007557C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80075580: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075584: bc1f        L_800755DC
    if (!c1cs) {
        // 0x80075588: nop
    
            goto L_800755DC;
    }
    // 0x80075588: nop

    // 0x8007558C: lwc1        $f4, 0x71B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B8);
    // 0x80075590: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80075594: lwc1        $f12, 0x154($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X154);
    // 0x80075598: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8007559C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800755A0: lwc1        $f6, 0x71BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X71BC);
    // 0x800755A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800755A8: lwc1        $f16, 0x180($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X180);
    // 0x800755AC: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800755B0: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800755B4: add.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800755B8: swc1        $f10, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f10.u32l;
    // 0x800755BC: lwc1        $f8, 0x71C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X71C0);
    // 0x800755C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800755C4: lwc1        $f10, 0x71C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71C4);
    // 0x800755C8: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800755CC: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800755D0: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800755D4: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800755D8: swc1        $f6, 0x180($s1)
    MEM_W(0X180, ctx->r17) = ctx->f6.u32l;
L_800755DC:
    // 0x800755DC: jal         0x8005B388
    // 0x800755E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorTeamArwing_Draw(rdram, ctx);
        goto after_13;
    // 0x800755E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800755E4: b           L_800762E4
    // 0x800755E8: nop

        goto L_800762E4;
    // 0x800755E8: nop

L_800755EC:
    // 0x800755EC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800755F0: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x800755F4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800755F8: bnel        $t6, $zero, L_80075628
    if (ctx->r14 != 0) {
        // 0x800755FC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80075628;
    }
    goto skip_7;
    // 0x800755FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_7:
    // 0x80075600: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075604: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80075608: addiu       $t9, $t9, 0x18A0
    ctx->r25 = ADD32(ctx->r25, 0X18A0);
    // 0x8007560C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80075610: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80075614: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80075618: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007561C: b           L_80075640
    // 0x80075620: nop

        goto L_80075640;
    // 0x80075620: nop

    // 0x80075624: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80075628:
    // 0x80075628: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8007562C: addiu       $t5, $t5, 0x7870
    ctx->r13 = ADD32(ctx->r13, 0X7870);
    // 0x80075630: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80075634: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80075638: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007563C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80075640:
    // 0x80075640: jal         0x8005ADAC
    // 0x80075644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_14;
    // 0x80075644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80075648: b           L_800762E4
    // 0x8007564C: nop

        goto L_800762E4;
    // 0x8007564C: nop

L_80075650:
    // 0x80075650: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075654: sw          $t6, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r14;
    // 0x80075658: jal         0x8005ADAC
    // 0x8007565C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_15;
    // 0x8007565C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80075660: b           L_800762E4
    // 0x80075664: nop

        goto L_800762E4;
    // 0x80075664: nop

L_80075668:
    // 0x80075668: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007566C: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80075670: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80075674: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x80075678: bne         $t7, $at, L_800756F8
    if (ctx->r15 != ctx->r1) {
        // 0x8007567C: addiu       $a0, $a0, 0x636C
        ctx->r4 = ADD32(ctx->r4, 0X636C);
            goto L_800756F8;
    }
    // 0x8007567C: addiu       $a0, $a0, 0x636C
    ctx->r4 = ADD32(ctx->r4, 0X636C);
    // 0x80075680: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075684: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x80075688: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x8007568C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80075690: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80075694: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80075698: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007569C: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x800756A0: jal         0x8009AA20
    // 0x800756A4: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_16;
    // 0x800756A4: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_16:
    // 0x800756A8: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x800756AC: addiu       $t5, $t5, 0x4660
    ctx->r13 = ADD32(ctx->r13, 0X4660);
    // 0x800756B0: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x800756B4: addiu       $a1, $a1, 0x6558
    ctx->r5 = ADD32(ctx->r5, 0X6558);
    // 0x800756B8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800756BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800756C0: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x800756C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800756C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800756CC: jal         0x8009A72C
    // 0x800756D0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_17;
    // 0x800756D0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_17:
    // 0x800756D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800756D8: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x800756DC: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800756E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800756E4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800756E8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800756EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800756F0: b           L_800762E4
    // 0x800756F4: nop

        goto L_800762E4;
    // 0x800756F4: nop

L_800756F8:
    // 0x800756F8: lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // 0x800756FC: addiu       $a0, $a0, 0x57AC
    ctx->r4 = ADD32(ctx->r4, 0X57AC);
    // 0x80075700: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x80075704: jal         0x8009AA20
    // 0x80075708: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_18;
    // 0x80075708: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_18:
    // 0x8007570C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80075710: addiu       $t4, $t4, 0x4660
    ctx->r12 = ADD32(ctx->r12, 0X4660);
    // 0x80075714: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x80075718: addiu       $a1, $a1, 0x58B8
    ctx->r5 = ADD32(ctx->r5, 0X58B8);
    // 0x8007571C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80075720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075724: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x80075728: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007572C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80075730: jal         0x8009A72C
    // 0x80075734: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_19;
    // 0x80075734: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_19:
    // 0x80075738: b           L_800762E4
    // 0x8007573C: nop

        goto L_800762E4;
    // 0x8007573C: nop

L_80075740:
    // 0x80075740: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075744: sw          $t8, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r24;
    // 0x80075748: jal         0x8005ADAC
    // 0x8007574C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_20;
    // 0x8007574C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80075750: b           L_800762E4
    // 0x80075754: nop

        goto L_800762E4;
    // 0x80075754: nop

L_80075758:
    // 0x80075758: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007575C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075760: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80075764: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80075768: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8007576C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80075770: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80075774: jal         0x80005B00
    // 0x80075778: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_21;
    // 0x80075778: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    after_21:
    // 0x8007577C: lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // 0x80075780: addiu       $a0, $a0, 0x1A4
    ctx->r4 = ADD32(ctx->r4, 0X1A4);
    // 0x80075784: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x80075788: jal         0x8009AA20
    // 0x8007578C: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_22;
    // 0x8007578C: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_22:
    // 0x80075790: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80075794: addiu       $t6, $t6, 0x4660
    ctx->r14 = ADD32(ctx->r14, 0X4660);
    // 0x80075798: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x8007579C: addiu       $a1, $a1, 0x270
    ctx->r5 = ADD32(ctx->r5, 0X270);
    // 0x800757A0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800757A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800757A8: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x800757AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800757B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800757B4: jal         0x8009A72C
    // 0x800757B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_23;
    // 0x800757B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_23:
    // 0x800757BC: b           L_800762E4
    // 0x800757C0: nop

        goto L_800762E4;
    // 0x800757C0: nop

L_800757C4:
    // 0x800757C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800757C8: lwc1        $f4, 0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71C8);
    // 0x800757CC: lwc1        $f10, 0x114($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X114);
    // 0x800757D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800757D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800757D8: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800757DC: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    // 0x800757E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800757E4: bc1f        L_800762E4
    if (!c1cs) {
        // 0x800757E8: nop
    
            goto L_800762E4;
    }
    // 0x800757E8: nop

    // 0x800757EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800757F0: sw          $t7, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r15;
    // 0x800757F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800757F8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800757FC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80075800: jal         0x80005B00
    // 0x80075804: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_24;
    // 0x80075804: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_24:
    // 0x80075808: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8007580C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80075810: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075814: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80075818: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8007581C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80075820: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80075824: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80075828: jal         0x80005C34
    // 0x8007582C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_25;
    // 0x8007582C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_25:
    // 0x80075830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80075834: jal         0x8005B1E8
    // 0x80075838: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_26;
    // 0x80075838: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x8007583C: b           L_800762E4
    // 0x80075840: nop

        goto L_800762E4;
    // 0x80075840: nop

L_80075844:
    // 0x80075844: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075848: lwc1        $f8, 0x71CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X71CC);
    // 0x8007584C: lwc1        $f6, 0x114($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X114);
    // 0x80075850: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075854: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075858: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8007585C: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    // 0x80075860: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80075864: bc1f        L_800762E4
    if (!c1cs) {
        // 0x80075868: nop
    
            goto L_800762E4;
    }
    // 0x80075868: nop

    // 0x8007586C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80075870: sw          $t8, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r24;
    // 0x80075874: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80075878: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8007587C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80075880: jal         0x80005B00
    // 0x80075884: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_27;
    // 0x80075884: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_27:
    // 0x80075888: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8007588C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80075890: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075894: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075898: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8007589C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800758A0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800758A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800758A8: jal         0x80005C34
    // 0x800758AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_28;
    // 0x800758AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_28:
    // 0x800758B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800758B4: jal         0x8005B1E8
    // 0x800758B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_29;
    // 0x800758B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_29:
    // 0x800758BC: b           L_800762E4
    // 0x800758C0: nop

        goto L_800762E4;
    // 0x800758C0: nop

L_800758C4:
    // 0x800758C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800758C8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800758CC: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x800758D0: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x800758D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800758D8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800758DC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800758E0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800758E4: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x800758E8: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x800758EC: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x800758F0: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x800758F4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800758F8: jal         0x800B9B38
    // 0x800758FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_60(rdram, ctx);
        goto after_30;
    // 0x800758FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_30:
    // 0x80075900: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075904: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x80075908: addiu       $t5, $t5, -0x5EE0
    ctx->r13 = ADD32(ctx->r13, -0X5EE0);
    // 0x8007590C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80075910: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80075914: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80075918: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007591C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80075920: b           L_800762E4
    // 0x80075924: nop

        goto L_800762E4;
    // 0x80075924: nop

L_80075928:
    // 0x80075928: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007592C: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x80075930: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075934: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80075938: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007593C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80075940: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80075944: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80075948: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007594C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075950: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x80075954: addiu       $t4, $t4, -0x7410
    ctx->r12 = ADD32(ctx->r12, -0X7410);
    // 0x80075958: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007595C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80075960: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80075964: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80075968: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007596C: lui         $t5, 0xB700
    ctx->r13 = S32(0XB700 << 16);
    // 0x80075970: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80075974: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80075978: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8007597C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80075980: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80075984: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80075988: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007598C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80075990: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80075994: jal         0x80005B00
    // 0x80075998: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_31;
    // 0x80075998: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    after_31:
    // 0x8007599C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800759A0: sw          $t7, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r15;
    // 0x800759A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800759A8: jal         0x8005B1E8
    // 0x800759AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_32;
    // 0x800759AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x800759B0: b           L_800762E4
    // 0x800759B4: nop

        goto L_800762E4;
    // 0x800759B4: nop

L_800759B8:
    // 0x800759B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800759BC: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x800759C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800759C4: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x800759C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800759CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800759D0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800759D4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800759D8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800759DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800759E0: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x800759E4: addiu       $t5, $t5, -0x68D0
    ctx->r13 = ADD32(ctx->r13, -0X68D0);
    // 0x800759E8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800759EC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800759F0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800759F4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800759F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800759FC: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x80075A00: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80075A04: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80075A08: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80075A0C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80075A10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80075A14: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80075A18: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80075A1C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80075A20: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80075A24: jal         0x80005B00
    // 0x80075A28: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_33;
    // 0x80075A28: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    after_33:
    // 0x80075A2C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80075A30: sw          $t4, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r12;
    // 0x80075A34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80075A38: jal         0x8005B1E8
    // 0x80075A3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_34;
    // 0x80075A3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x80075A40: b           L_800762E4
    // 0x80075A44: nop

        goto L_800762E4;
    // 0x80075A44: nop

L_80075A48:
    // 0x80075A48: lhu         $v0, 0xC2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC2);
    // 0x80075A4C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80075A50: beq         $v0, $zero, L_80075B60
    if (ctx->r2 == 0) {
        // 0x80075A54: andi        $t8, $v0, 0x3
        ctx->r24 = ctx->r2 & 0X3;
            goto L_80075B60;
    }
    // 0x80075A54: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x80075A58: bne         $t8, $zero, L_80075B10
    if (ctx->r24 != 0) {
        // 0x80075A5C: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_80075B10;
    }
    // 0x80075A5C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80075A60: lw          $t5, 0x7854($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7854);
    // 0x80075A64: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80075A68: beql        $t5, $at, L_80075B14
    if (ctx->r13 == ctx->r1) {
        // 0x80075A6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80075B14;
    }
    goto skip_8;
    // 0x80075A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_8:
    // 0x80075A70: jal         0x80004EB0
    // 0x80075A74: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_35;
    // 0x80075A74: nop

    after_35:
    // 0x80075A78: jal         0x80004EB0
    // 0x80075A7C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_36;
    // 0x80075A7C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x80075A80: jal         0x80004EB0
    // 0x80075A84: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_37;
    // 0x80075A84: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x80075A88: jal         0x80004EB0
    // 0x80075A8C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_38;
    // 0x80075A8C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x80075A90: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80075A94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80075A98: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80075A9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80075AA0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80075AA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80075AA8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80075AAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80075AB0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80075AB4: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80075AB8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80075ABC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80075AC0: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80075AC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80075AC8: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80075ACC: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80075AD0: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80075AD4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80075AD8: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80075ADC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80075AE0: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80075AE4: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80075AE8: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80075AEC: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80075AF0: nop

    // 0x80075AF4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80075AF8: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80075AFC: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80075B00: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80075B04: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80075B08: jal         0x8007D0E0
    // 0x80075B0C: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_39;
    // 0x80075B0C: nop

    after_39:
L_80075B10:
    // 0x80075B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80075B14:
    // 0x80075B14: jal         0x800B8DD0
    // 0x80075B18: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_40;
    // 0x80075B18: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_40:
    // 0x80075B1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075B20: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x80075B24: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x80075B28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80075B2C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80075B30: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80075B34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80075B38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075B3C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80075B40: addiu       $t5, $t5, 0x1950
    ctx->r13 = ADD32(ctx->r13, 0X1950);
    // 0x80075B44: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80075B48: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80075B4C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80075B50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80075B54: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80075B58: b           L_800762E4
    // 0x80075B5C: nop

        goto L_800762E4;
    // 0x80075B5C: nop

L_80075B60:
    // 0x80075B60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075B64: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80075B68: addiu       $t9, $t9, 0x66F0
    ctx->r25 = ADD32(ctx->r25, 0X66F0);
    // 0x80075B6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80075B70: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80075B74: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80075B78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80075B7C: b           L_800762E4
    // 0x80075B80: nop

        goto L_800762E4;
    // 0x80075B80: nop

L_80075B84:
    // 0x80075B84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075B88: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x80075B8C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80075B90: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80075B94: jal         0x80005D44
    // 0x80075B98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_41;
    // 0x80075B98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_41:
    // 0x80075B9C: jal         0x80006EB8
    // 0x80075BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_42;
    // 0x80075BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80075BA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075BA8: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x80075BAC: addiu       $t5, $t5, -0x1F40
    ctx->r13 = ADD32(ctx->r13, -0X1F40);
    // 0x80075BB0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80075BB4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80075BB8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80075BBC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80075BC0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80075BC4: b           L_800762E4
    // 0x80075BC8: nop

        goto L_800762E4;
    // 0x80075BC8: nop

L_80075BCC:
    // 0x80075BCC: lui         $a0, 0x401
    ctx->r4 = S32(0X401 << 16);
    // 0x80075BD0: addiu       $a0, $a0, -0x5CF4
    ctx->r4 = ADD32(ctx->r4, -0X5CF4);
    // 0x80075BD4: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x80075BD8: jal         0x8009AA20
    // 0x80075BDC: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_43;
    // 0x80075BDC: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_43:
    // 0x80075BE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075BE4: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80075BE8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80075BEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80075BF0: jal         0x80005E90
    // 0x80075BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_44;
    // 0x80075BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_44:
    // 0x80075BF8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80075BFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80075C00: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075C04: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075C08: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80075C0C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80075C10: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80075C14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80075C18: jal         0x80005C34
    // 0x80075C1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_45;
    // 0x80075C1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_45:
    // 0x80075C20: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80075C24: addiu       $t7, $t7, 0x4660
    ctx->r15 = ADD32(ctx->r15, 0X4660);
    // 0x80075C28: lui         $a1, 0x401
    ctx->r5 = S32(0X401 << 16);
    // 0x80075C2C: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x80075C30: addiu       $a3, $a3, 0x4BFC
    ctx->r7 = ADD32(ctx->r7, 0X4BFC);
    // 0x80075C34: addiu       $a1, $a1, -0x5C68
    ctx->r5 = ADD32(ctx->r5, -0X5C68);
    // 0x80075C38: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80075C3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075C40: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x80075C44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80075C48: jal         0x8009A72C
    // 0x80075C4C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_46;
    // 0x80075C4C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_46:
    // 0x80075C50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80075C54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075C58: lwc1        $f8, 0x71D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X71D0);
    // 0x80075C5C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80075C60: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80075C64: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80075C68: addiu       $a0, $s1, 0x154
    ctx->r4 = ADD32(ctx->r17, 0X154);
    // 0x80075C6C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80075C70: jal         0x8009BC2C
    // 0x80075C74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x80075C74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_47:
    // 0x80075C78: b           L_800762E4
    // 0x80075C7C: nop

        goto L_800762E4;
    // 0x80075C7C: nop

L_80075C80:
    // 0x80075C80: lui         $a0, 0x701
    ctx->r4 = S32(0X701 << 16);
    // 0x80075C84: addiu       $a0, $a0, -0x350C
    ctx->r4 = ADD32(ctx->r4, -0X350C);
    // 0x80075C88: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x80075C8C: jal         0x8009AA20
    // 0x80075C90: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_48;
    // 0x80075C90: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_48:
    // 0x80075C94: lwc1        $f6, 0x134($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X134);
    // 0x80075C98: lwc1        $f4, 0x150($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80075C9C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80075CA0: addiu       $t9, $t9, 0x4660
    ctx->r25 = ADD32(ctx->r25, 0X4660);
    // 0x80075CA4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80075CA8: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x80075CAC: addiu       $a1, $a1, -0x34A0
    ctx->r5 = ADD32(ctx->r5, -0X34A0);
    // 0x80075CB0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80075CB4: swc1        $f10, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f10.u32l;
    // 0x80075CB8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80075CBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80075CC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075CC4: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x80075CC8: jal         0x8009A72C
    // 0x80075CCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_49;
    // 0x80075CCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_49:
    // 0x80075CD0: b           L_800762E4
    // 0x80075CD4: nop

        goto L_800762E4;
    // 0x80075CD4: nop

L_80075CD8:
    // 0x80075CD8: jal         0x80074E3C
    // 0x80075CDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_SxWarpGate_Draw(rdram, ctx);
        goto after_50;
    // 0x80075CDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_50:
    // 0x80075CE0: b           L_800762E4
    // 0x80075CE4: nop

        goto L_800762E4;
    // 0x80075CE4: nop

L_80075CE8:
    // 0x80075CE8: jal         0x801A4CB0
    // 0x80075CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    SectorY_SyRobot_Draw(rdram, ctx);
        goto after_51;
    // 0x80075CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_51:
    // 0x80075CF0: b           L_800762E4
    // 0x80075CF4: nop

        goto L_800762E4;
    // 0x80075CF4: nop

L_80075CF8:
    // 0x80075CF8: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x80075CFC: addiu       $a0, $a0, -0x78C
    ctx->r4 = ADD32(ctx->r4, -0X78C);
    // 0x80075D00: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x80075D04: jal         0x8009AA20
    // 0x80075D08: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_52;
    // 0x80075D08: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_52:
    // 0x80075D0C: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x80075D10: lwc1        $f6, 0x150($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80075D14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075D18: lwc1        $f0, 0x71D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X71D4);
    // 0x80075D1C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80075D20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075D24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80075D28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80075D2C: swc1        $f4, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f4.u32l;
    // 0x80075D30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075D34: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80075D38: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x80075D3C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80075D40: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80075D44: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80075D48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80075D4C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80075D50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075D54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80075D58: jal         0x80005C34
    // 0x80075D5C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_53;
    // 0x80075D5C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_53:
    // 0x80075D60: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80075D64: addiu       $t7, $t7, 0x4660
    ctx->r15 = ADD32(ctx->r15, 0X4660);
    // 0x80075D68: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80075D6C: addiu       $a1, $a1, -0x6E0
    ctx->r5 = ADD32(ctx->r5, -0X6E0);
    // 0x80075D70: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80075D74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075D78: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x80075D7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80075D80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80075D84: jal         0x8009A72C
    // 0x80075D88: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_54;
    // 0x80075D88: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_54:
    // 0x80075D8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075D90: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x80075D94: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x80075D98: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80075D9C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80075DA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80075DA4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80075DA8: b           L_800762E4
    // 0x80075DAC: nop

        goto L_800762E4;
    // 0x80075DAC: nop

L_80075DB0:
    // 0x80075DB0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075DB4: jal         0x80005708
    // 0x80075DB8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_55;
    // 0x80075DB8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_55:
    // 0x80075DBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075DC0: lwc1        $f8, 0x71D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X71D8);
    // 0x80075DC4: lwc1        $f10, 0xF4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80075DC8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075DCC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80075DD0: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80075DD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80075DD8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80075DDC: jal         0x80005D44
    // 0x80075DE0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_56;
    // 0x80075DE0: nop

    after_56:
    // 0x80075DE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075DE8: lwc1        $f10, 0x71DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71DC);
    // 0x80075DEC: lwc1        $f4, 0xF8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x80075DF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075DF4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80075DF8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80075DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80075E00: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80075E04: jal         0x80005E90
    // 0x80075E08: nop

    Matrix_RotateY(rdram, ctx);
        goto after_57;
    // 0x80075E08: nop

    after_57:
    // 0x80075E0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075E10: jal         0x80005708
    // 0x80075E14: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_58;
    // 0x80075E14: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_58:
    // 0x80075E18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80075E1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075E20: lw          $a2, 0x150($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X150);
    // 0x80075E24: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80075E28: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80075E2C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80075E30: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80075E34: jal         0x80005B00
    // 0x80075E38: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_59;
    // 0x80075E38: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_59:
    // 0x80075E3C: jal         0x80006EB8
    // 0x80075E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_60;
    // 0x80075E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80075E44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075E48: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x80075E4C: addiu       $t9, $t9, -0x3560
    ctx->r25 = ADD32(ctx->r25, -0X3560);
    // 0x80075E50: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80075E54: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80075E58: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80075E5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80075E60: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80075E64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075E68: jal         0x80005740
    // 0x80075E6C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_61;
    // 0x80075E6C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_61:
    // 0x80075E70: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80075E74: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80075E78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075E7C: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x80075E80: addiu       $t5, $t5, -0x3ED0
    ctx->r13 = ADD32(ctx->r13, -0X3ED0);
    // 0x80075E84: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80075E88: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80075E8C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80075E90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80075E94: lwc1        $f6, 0x150($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80075E98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075E9C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80075EA0: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80075EA4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80075EA8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80075EAC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075EB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80075EB4: jal         0x80005B00
    // 0x80075EB8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_62;
    // 0x80075EB8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_62:
    // 0x80075EBC: jal         0x80006EB8
    // 0x80075EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_63;
    // 0x80075EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80075EC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075EC8: lui         $t4, 0x601
    ctx->r12 = S32(0X601 << 16);
    // 0x80075ECC: addiu       $t4, $t4, -0x38C0
    ctx->r12 = ADD32(ctx->r12, -0X38C0);
    // 0x80075ED0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80075ED4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80075ED8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80075EDC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80075EE0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80075EE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075EE8: jal         0x80005740
    // 0x80075EEC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_64;
    // 0x80075EEC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_64:
    // 0x80075EF0: b           L_800762E4
    // 0x80075EF4: nop

        goto L_800762E4;
    // 0x80075EF4: nop

L_80075EF8:
    // 0x80075EF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075EFC: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x80075F00: addiu       $t5, $t5, -0x7560
    ctx->r13 = ADD32(ctx->r13, -0X7560);
    // 0x80075F04: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80075F08: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80075F0C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80075F10: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80075F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80075F18: jal         0x800B8DD0
    // 0x80075F1C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_65;
    // 0x80075F1C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_65:
    // 0x80075F20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075F24: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x80075F28: addiu       $t9, $t9, -0x61D0
    ctx->r25 = ADD32(ctx->r25, -0X61D0);
    // 0x80075F2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80075F30: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80075F34: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80075F38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80075F3C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80075F40: b           L_800762E4
    // 0x80075F44: nop

        goto L_800762E4;
    // 0x80075F44: nop

L_80075F48:
    // 0x80075F48: jal         0x80067874
    // 0x80075F4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorSupplies_Draw(rdram, ctx);
        goto after_66;
    // 0x80075F4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_66:
    // 0x80075F50: b           L_800762E4
    // 0x80075F54: nop

        goto L_800762E4;
    // 0x80075F54: nop

L_80075F58:
    // 0x80075F58: lh          $s0, 0xB8($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XB8);
    // 0x80075F5C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80075F60: sh          $t4, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r12;
    // 0x80075F64: jal         0x80190430
    // 0x80075F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Zoness_ZoBird_Draw(rdram, ctx);
        goto after_67;
    // 0x80075F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_67:
    // 0x80075F6C: b           L_800762E4
    // 0x80075F70: sh          $s0, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r16;
        goto L_800762E4;
    // 0x80075F70: sh          $s0, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r16;
L_80075F74:
    // 0x80075F74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075F78: lwc1        $f0, 0x71E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X71E0);
    // 0x80075F7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075F80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075F84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80075F88: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80075F8C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80075F90: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80075F94: jal         0x80005C34
    // 0x80075F98: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_68;
    // 0x80075F98: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_68:
    // 0x80075F9C: jal         0x80006EB8
    // 0x80075FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_69;
    // 0x80075FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x80075FA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075FA8: lui         $t7, 0x901
    ctx->r15 = S32(0X901 << 16);
    // 0x80075FAC: addiu       $t7, $t7, 0x1200
    ctx->r15 = ADD32(ctx->r15, 0X1200);
    // 0x80075FB0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80075FB4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80075FB8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80075FBC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80075FC0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80075FC4: b           L_800762E4
    // 0x80075FC8: nop

        goto L_800762E4;
    // 0x80075FC8: nop

L_80075FCC:
    // 0x80075FCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80075FD0: lwc1        $f10, 0x71E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71E4);
    // 0x80075FD4: lwc1        $f0, 0x150($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80075FD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80075FDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80075FE0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80075FE4: nop

    // 0x80075FE8: bc1f        L_800762E4
    if (!c1cs) {
        // 0x80075FEC: nop
    
            goto L_800762E4;
    }
    // 0x80075FEC: nop

    // 0x80075FF0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80075FF4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80075FF8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80075FFC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80076000: jal         0x80005C34
    // 0x80076004: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Matrix_Scale(rdram, ctx);
        goto after_70;
    // 0x80076004: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_70:
    // 0x80076008: jal         0x80006EB8
    // 0x8007600C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_71;
    // 0x8007600C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x80076010: lui         $t4, 0x900
    ctx->r12 = S32(0X900 << 16);
    // 0x80076014: addiu       $t4, $t4, 0x3330
    ctx->r12 = ADD32(ctx->r12, 0X3330);
    // 0x80076018: lwc1        $f12, 0x154($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X154);
    // 0x8007601C: lui         $a2, 0x900
    ctx->r6 = S32(0X900 << 16);
    // 0x80076020: lui         $a3, 0x900
    ctx->r7 = S32(0X900 << 16);
    // 0x80076024: addiu       $a3, $a3, 0x3DF0
    ctx->r7 = ADD32(ctx->r7, 0X3DF0);
    // 0x80076028: addiu       $a2, $a2, 0x3890
    ctx->r6 = ADD32(ctx->r6, 0X3890);
    // 0x8007602C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80076030: jal         0x800A1558
    // 0x80076034: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    Texture_BlendRGBA16(rdram, ctx);
        goto after_72;
    // 0x80076034: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_72:
    // 0x80076038: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007603C: lui         $t6, 0x900
    ctx->r14 = S32(0X900 << 16);
    // 0x80076040: addiu       $t6, $t6, 0x2CF0
    ctx->r14 = ADD32(ctx->r14, 0X2CF0);
    // 0x80076044: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80076048: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8007604C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80076050: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80076054: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80076058: b           L_800762E4
    // 0x8007605C: nop

        goto L_800762E4;
    // 0x8007605C: nop

L_80076060:
    // 0x80076060: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x80076064: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80076068: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8007606C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80076070: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80076074: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80076078: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007607C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80076080: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x80076084: addiu       $t8, $t8, -0x25F0
    ctx->r24 = ADD32(ctx->r24, -0X25F0);
    // 0x80076088: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8007608C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80076090: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80076094: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80076098: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007609C: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x800760A0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800760A4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800760A8: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x800760AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800760B0: b           L_800762E4
    // 0x800760B4: nop

        goto L_800762E4;
    // 0x800760B4: nop

L_800760B8:
    // 0x800760B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800760BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800760C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800760C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800760C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800760CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800760D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800760D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800760D8: jal         0x80005C34
    // 0x800760DC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_73;
    // 0x800760DC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_73:
    // 0x800760E0: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x800760E4: addiu       $a0, $a0, 0x201C
    ctx->r4 = ADD32(ctx->r4, 0X201C);
    // 0x800760E8: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x800760EC: jal         0x8009AA20
    // 0x800760F0: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_74;
    // 0x800760F0: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_74:
    // 0x800760F4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800760F8: addiu       $t9, $t9, 0x4660
    ctx->r25 = ADD32(ctx->r25, 0X4660);
    // 0x800760FC: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80076100: addiu       $a1, $a1, 0x20E8
    ctx->r5 = ADD32(ctx->r5, 0X20E8);
    // 0x80076104: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80076108: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007610C: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x80076110: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80076114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80076118: jal         0x8009A72C
    // 0x8007611C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_75;
    // 0x8007611C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_75:
    // 0x80076120: b           L_800762E4
    // 0x80076124: nop

        goto L_800762E4;
    // 0x80076124: nop

L_80076128:
    // 0x80076128: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007612C: lui         $t8, 0xD01
    ctx->r24 = S32(0XD01 << 16);
    // 0x80076130: addiu       $t8, $t8, -0x4780
    ctx->r24 = ADD32(ctx->r24, -0X4780);
    // 0x80076134: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80076138: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8007613C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80076140: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80076144: jal         0x8005ADAC
    // 0x80076148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_76;
    // 0x80076148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_76:
    // 0x8007614C: b           L_800762E4
    // 0x80076150: nop

        goto L_800762E4;
    // 0x80076150: nop

L_80076154:
    // 0x80076154: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80076158: lui         $t6, 0xD01
    ctx->r14 = S32(0XD01 << 16);
    // 0x8007615C: addiu       $t6, $t6, -0x65C0
    ctx->r14 = ADD32(ctx->r14, -0X65C0);
    // 0x80076160: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80076164: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80076168: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007616C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80076170: jal         0x8005ADAC
    // 0x80076174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_77;
    // 0x80076174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_77:
    // 0x80076178: b           L_800762E4
    // 0x8007617C: nop

        goto L_800762E4;
    // 0x8007617C: nop

L_80076180:
    // 0x80076180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076184: jal         0x800B8DD0
    // 0x80076188: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    RCP_SetupDL(rdram, ctx);
        goto after_78;
    // 0x80076188: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_78:
    // 0x8007618C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80076190: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80076194: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80076198: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007619C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800761A0: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
    // 0x800761A4: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x800761A8: sll         $t8, $t4, 24
    ctx->r24 = S32(ctx->r12 << 24);
    // 0x800761AC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800761B0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800761B4: sll         $t7, $t4, 8
    ctx->r15 = S32(ctx->r12 << 8);
    // 0x800761B8: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800761BC: ori         $t4, $t9, 0xFF
    ctx->r12 = ctx->r25 | 0XFF;
    // 0x800761C0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800761C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800761C8: lui         $t6, 0x601
    ctx->r14 = S32(0X601 << 16);
    // 0x800761CC: addiu       $t6, $t6, -0x7690
    ctx->r14 = ADD32(ctx->r14, -0X7690);
    // 0x800761D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800761D4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800761D8: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800761DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800761E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800761E4: b           L_800762E4
    // 0x800761E8: nop

        goto L_800762E4;
    // 0x800761E8: nop

L_800761EC:
    // 0x800761EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800761F0: jal         0x800B8DD0
    // 0x800761F4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    RCP_SetupDL(rdram, ctx);
        goto after_79;
    // 0x800761F4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_79:
    // 0x800761F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800761FC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80076200: addiu       $t4, $t4, 0xE10
    ctx->r12 = ADD32(ctx->r12, 0XE10);
    // 0x80076204: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80076208: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007620C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80076210: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80076214: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80076218: b           L_800762E4
    // 0x8007621C: nop

        goto L_800762E4;
    // 0x8007621C: nop

L_80076220:
    // 0x80076220: jal         0x8018769C
    // 0x80076224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8018769C)(rdram, ctx);
        goto after_80;
    // 0x80076224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_80:
    // 0x80076228: b           L_800762E4
    // 0x8007622C: nop

        goto L_800762E4;
    // 0x8007622C: nop

L_80076230:
    // 0x80076230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076234: jal         0x800B8DD0
    // 0x80076238: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    RCP_SetupDL(rdram, ctx);
        goto after_81;
    // 0x80076238: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_81:
    // 0x8007623C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80076240: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80076244: addiu       $t6, $zero, 0x8F
    ctx->r14 = ADD32(0, 0X8F);
    // 0x80076248: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007624C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80076250: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80076254: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80076258: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007625C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80076260: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80076264: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80076268: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007626C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80076270: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80076274: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80076278: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x8007627C: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x80076280: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80076284: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80076288: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007628C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80076290: b           L_800762E4
    // 0x80076294: nop

        goto L_800762E4;
    // 0x80076294: nop

L_80076298:
    // 0x80076298: lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // 0x8007629C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800762A0: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x800762A4: jal         0x8009AA20
    // 0x800762A8: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    Animation_GetFrameData(rdram, ctx);
        goto after_82;
    // 0x800762A8: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    after_82:
    // 0x800762AC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800762B0: addiu       $t6, $t6, 0x4660
    ctx->r14 = ADD32(ctx->r14, 0X4660);
    // 0x800762B4: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x800762B8: addiu       $a1, $a1, 0x14C
    ctx->r5 = ADD32(ctx->r5, 0X14C);
    // 0x800762BC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800762C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800762C4: addiu       $a2, $sp, 0x114
    ctx->r6 = ADD32(ctx->r29, 0X114);
    // 0x800762C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800762CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800762D0: jal         0x8009A72C
    // 0x800762D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_83;
    // 0x800762D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_83:
    // 0x800762D8: b           L_800762E4
    // 0x800762DC: nop

        goto L_800762E4;
    // 0x800762DC: nop

L_800762E0:
    // 0x800762E0: sh          $t7, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r15;
L_800762E4:
    // 0x800762E4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800762E8: lh          $t9, 0x1410($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X1410);
    // 0x800762EC: blezl       $t9, L_80076394
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800762F0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80076394;
    }
    goto skip_9;
    // 0x800762F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_9:
    // 0x800762F4: lw          $v0, 0x80($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X80);
    // 0x800762F8: blez        $v0, L_80076390
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800762FC: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_80076390;
    }
    // 0x800762FC: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80076300: beq         $at, $zero, L_80076390
    if (ctx->r1 == 0) {
        // 0x80076304: addiu       $a1, $sp, 0x58
        ctx->r5 = ADD32(ctx->r29, 0X58);
            goto L_80076390;
    }
    // 0x80076304: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80076308: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8007630C: addiu       $t4, $t4, 0x14CC
    ctx->r12 = ADD32(ctx->r12, 0X14CC);
    // 0x80076310: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80076314: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80076318: addiu       $t9, $t9, 0x7E98
    ctx->r25 = ADD32(ctx->r25, 0X7E98);
    // 0x8007631C: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80076320: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80076324: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80076328: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8007632C: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80076330: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80076334: lw          $v0, 0x80($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X80);
    // 0x80076338: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007633C: beq         $v0, $at, L_80076350
    if (ctx->r2 == ctx->r1) {
        // 0x80076340: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80076350;
    }
    // 0x80076340: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80076344: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80076348: bne         $v0, $at, L_80076370
    if (ctx->r2 != ctx->r1) {
        // 0x8007634C: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80076370;
    }
    // 0x8007634C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
L_80076350:
    // 0x80076350: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80076354: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80076358: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x8007635C: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    // 0x80076360: jal         0x80006970
    // 0x80076364: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_MultVec3f(rdram, ctx);
        goto after_84;
    // 0x80076364: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_84:
    // 0x80076368: b           L_80076394
    // 0x8007636C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80076394;
    // 0x8007636C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80076370:
    // 0x80076370: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80076374: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80076378: addiu       $t4, $t4, 0x7E98
    ctx->r12 = ADD32(ctx->r12, 0X7E98);
    // 0x8007637C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80076380: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80076384: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80076388: jal         0x80006970
    // 0x8007638C: addu        $a2, $t8, $t4
    ctx->r6 = ADD32(ctx->r24, ctx->r12);
    Matrix_MultVec3f(rdram, ctx);
        goto after_85;
    // 0x8007638C: addu        $a2, $t8, $t4
    ctx->r6 = ADD32(ctx->r24, ctx->r12);
    after_85:
L_80076390:
    // 0x80076390: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80076394:
    // 0x80076394: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80076398: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8007639C: jr          $ra
    // 0x800763A0: addiu       $sp, $sp, 0x288
    ctx->r29 = ADD32(ctx->r29, 0X288);
    return;
    // 0x800763A0: addiu       $sp, $sp, 0x288
    ctx->r29 = ADD32(ctx->r29, 0X288);
;}
RECOMP_FUNC void Effect_Effect349_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F958: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8007F95C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8007F960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F964: lwc1        $f2, 0x74B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74B4);
    // 0x8007F968: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007F96C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8007F970: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8007F974: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8007F978: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8007F97C: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8007F980: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8007F984: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8007F988: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8007F98C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8007F990: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x8007F994: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8007F998: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8007F99C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8007F9A0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8007F9A4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8007F9A8: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007F9AC: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007F9B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007F9B8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007F9BC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8007F9C0: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x8007F9C4: lwc1        $f8, 0x74B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X74B8);
    // 0x8007F9C8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8007F9CC: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    // 0x8007F9D0: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007F9D4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8007F9D8: nop

    // 0x8007F9DC: bc1fl       L_8007F9EC
    if (!c1cs) {
        // 0x8007F9E0: lh          $t6, 0x44($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X44);
            goto L_8007F9EC;
    }
    goto skip_0;
    // 0x8007F9E0: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    skip_0:
    // 0x8007F9E4: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    // 0x8007F9E8: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
L_8007F9EC:
    // 0x8007F9EC: addiu       $t7, $t6, -0x9
    ctx->r15 = ADD32(ctx->r14, -0X9);
    // 0x8007F9F0: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x8007F9F4: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x8007F9F8: bgez        $t8, L_8007FA10
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007F9FC: nop
    
            goto L_8007FA10;
    }
    // 0x8007F9FC: nop

    // 0x8007FA00: jal         0x80060FBC
    // 0x8007FA04: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007FA04: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_0:
    // 0x8007FA08: b           L_8007FB9C
    // 0x8007FA0C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_8007FB9C;
    // 0x8007FA0C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8007FA10:
    // 0x8007FA10: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8007FA14: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8007FA18: bnel        $t0, $zero, L_8007FB9C
    if (ctx->r8 != 0) {
        // 0x8007FA1C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8007FB9C;
    }
    goto skip_1;
    // 0x8007FA1C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_1:
    // 0x8007FA20: jal         0x80004EB0
    // 0x8007FA24: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007FA24: nop

    after_1:
    // 0x8007FA28: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x8007FA2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007FA30: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8007FA34: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8007FA38: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007FA3C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8007FA40: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007FA44: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x8007FA48: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x8007FA4C: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x8007FA50: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8007FA54: mul.s       $f30, $f0, $f18
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8007FA58: addiu       $s2, $s2, 0x7940
    ctx->r18 = ADD32(ctx->r18, 0X7940);
    // 0x8007FA5C: addiu       $s4, $s4, -0x7B54
    ctx->r20 = ADD32(ctx->r20, -0X7B54);
    // 0x8007FA60: addiu       $s5, $s5, 0x7D20
    ctx->r21 = ADD32(ctx->r21, 0X7D20);
    // 0x8007FA64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007FA68: addiu       $fp, $sp, 0x9C
    ctx->r30 = ADD32(ctx->r29, 0X9C);
    // 0x8007FA6C: addiu       $s7, $sp, 0x98
    ctx->r23 = ADD32(ctx->r29, 0X98);
    // 0x8007FA70: addiu       $s6, $sp, 0xA0
    ctx->r22 = ADD32(ctx->r29, 0XA0);
    // 0x8007FA74: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8007FA78: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
L_8007FA7C:
    // 0x8007FA7C: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x8007FA80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007FA84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007FA88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FA8C: lwc1        $f16, 0x74BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74BC);
    // 0x8007FA90: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007FA94: nop

    // 0x8007FA98: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007FA9C: add.s       $f20, $f18, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f30.fl;
    // 0x8007FAA0: jal         0x80023090
    // 0x8007FAA4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007FAA4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x8007FAA8: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007FAAC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8007FAB0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007FAB4: nop

    // 0x8007FAB8: mul.s       $f22, $f6, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8007FABC: jal         0x80023250
    // 0x8007FAC0: nop

    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007FAC0: nop

    after_3:
    // 0x8007FAC4: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007FAC8: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8007FACC: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8007FAD0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8007FAD4: add.s       $f14, $f16, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x8007FAD8: mul.s       $f20, $f10, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8007FADC: bne         $s3, $t1, L_8007FB14
    if (ctx->r19 != ctx->r9) {
        // 0x8007FAE0: nop
    
            goto L_8007FB14;
    }
    // 0x8007FAE0: nop

    // 0x8007FAE4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007FAE8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007FAEC: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8007FAF0: add.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8007FAF4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8007FAF8: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8007FAFC: add.s       $f12, $f16, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8007FB00: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8007FB04: jal         0x801B6E20
    // 0x8007FB08: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_4;
    // 0x8007FB08: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
    after_4:
    // 0x8007FB0C: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8007FB10: add.s       $f14, $f10, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f26.fl;
L_8007FB14:
    // 0x8007FB14: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007FB18: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8007FB1C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8007FB20: bnel        $v0, $at, L_8007FB54
    if (ctx->r2 != ctx->r1) {
        // 0x8007FB24: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8007FB54;
    }
    goto skip_2;
    // 0x8007FB24: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_2:
    // 0x8007FB28: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007FB2C: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007FB30: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8007FB34: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8007FB38: add.s       $f12, $f16, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8007FB3C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8007FB40: jal         0x8007BC7C
    // 0x8007FB44: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_5;
    // 0x8007FB44: nop

    after_5:
    // 0x8007FB48: b           L_8007FB8C
    // 0x8007FB4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8007FB8C;
    // 0x8007FB4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007FB50: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8007FB54:
    // 0x8007FB54: bne         $v0, $at, L_8007FB88
    if (ctx->r2 != ctx->r1) {
        // 0x8007FB58: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_8007FB88;
    }
    // 0x8007FB58: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8007FB5C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007FB60: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007FB64: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8007FB68: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8007FB6C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8007FB70: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8007FB74: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007FB78: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8007FB7C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8007FB80: jal         0x8007A900
    // 0x8007FB84: add.s       $f12, $f6, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f22.fl;
    Effect_Effect359_Spawn(rdram, ctx);
        goto after_6;
    // 0x8007FB84: add.s       $f12, $f6, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f22.fl;
    after_6:
L_8007FB88:
    // 0x8007FB88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007FB8C:
    // 0x8007FB8C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007FB90: bnel        $s1, $at, L_8007FA7C
    if (ctx->r17 != ctx->r1) {
        // 0x8007FB94: mtc1        $s1, $f4
        ctx->f4.u32l = ctx->r17;
            goto L_8007FA7C;
    }
    goto skip_3;
    // 0x8007FB94: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    skip_3:
    // 0x8007FB98: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8007FB9C:
    // 0x8007FB9C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8007FBA0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8007FBA4: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8007FBA8: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8007FBAC: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8007FBB0: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8007FBB4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8007FBB8: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8007FBBC: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8007FBC0: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8007FBC4: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8007FBC8: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8007FBCC: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8007FBD0: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8007FBD4: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8007FBD8: jr          $ra
    // 0x8007FBDC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8007FBDC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80009124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009124: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80009128: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8000912C: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80009130: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80009134: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80009138: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x8000913C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80009140: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009144: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80009148: addiu       $v0, $v0, 0x5D48
    ctx->r2 = ADD32(ctx->r2, 0X5D48);
    // 0x8000914C: addiu       $t5, $t5, 0x6144
    ctx->r13 = ADD32(ctx->r13, 0X6144);
L_80009150:
    // 0x80009150: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x80009154: sltu        $at, $t5, $v0
    ctx->r1 = ctx->r13 < ctx->r2 ? 1 : 0;
    // 0x80009158: beq         $at, $zero, L_80009150
    if (ctx->r1 == 0) {
        // 0x8000915C: swc1        $f0, 0x4($t5)
        MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
            goto L_80009150;
    }
    // 0x8000915C: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x80009160: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x80009164: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80009168: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000916C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80009170: lh          $v0, -0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, -0X2);
    // 0x80009174: addiu       $a3, $a3, 0x5D48
    ctx->r7 = ADD32(ctx->r7, 0X5D48);
    // 0x80009178: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8000917C: addiu       $t4, $zero, 0x100
    ctx->r12 = ADD32(0, 0X100);
    // 0x80009180: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80009184: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80009188: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8000918C: or          $t3, $t3, $v0
    ctx->r11 = ctx->r11 | ctx->r2;
    // 0x80009190: srl         $t7, $t3, 24
    ctx->r15 = S32(U32(ctx->r11) >> 24);
L_80009194:
    // 0x80009194: andi        $s0, $t7, 0xFF
    ctx->r16 = ctx->r15 & 0XFF;
    // 0x80009198: sra         $a0, $s0, 4
    ctx->r4 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8000919C: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x800091A0: andi        $t6, $a0, 0xF
    ctx->r14 = ctx->r4 & 0XF;
    // 0x800091A4: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800091A8: beq         $t6, $zero, L_800094DC
    if (ctx->r14 == 0) {
        // 0x800091AC: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_800094DC;
    }
    // 0x800091AC: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800091B0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800091B4: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x800091B8: beq         $at, $zero, L_800094DC
    if (ctx->r1 == 0) {
        // 0x800091BC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800094DC;
    }
    // 0x800091BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800091C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800091C4: addu        $at, $at, $t7
    gpr jr_addend_800091CC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800091C8: lw          $t7, -0x79C4($at)
    ctx->r15 = ADD32(ctx->r1, -0X79C4);
    // 0x800091CC: jr          $t7
    // 0x800091D0: nop

    switch (jr_addend_800091CC >> 2) {
        case 0: goto L_800091D4; break;
        case 1: goto L_80009238; break;
        case 2: goto L_800093F0; break;
        case 3: goto L_80009460; break;
        case 4: goto L_8000949C; break;
        case 5: goto L_80009378; break;
        default: switch_error(__func__, 0x800091CC, 0x800C863C);
    }
    // 0x800091D0: nop

L_800091D4:
    // 0x800091D4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800091D8: addu        $t5, $a3, $t8
    ctx->r13 = ADD32(ctx->r7, ctx->r24);
    // 0x800091DC: andi        $a0, $s0, 0xF
    ctx->r4 = ctx->r16 & 0XF;
    // 0x800091E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800091E4:
    // 0x800091E4: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
    // 0x800091E8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800091EC: sra         $t9, $s0, 12
    ctx->r25 = S32(SIGNED(ctx->r16) >> 12);
L_800091F0:
    // 0x800091F0: andi        $v1, $t9, 0xF
    ctx->r3 = ctx->r25 & 0XF;
    // 0x800091F4: andi        $t8, $v1, 0x7
    ctx->r24 = ctx->r3 & 0X7;
    // 0x800091F8: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x800091FC: sllv        $t6, $t9, $a0
    ctx->r14 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x80009200: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80009204: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x80009208: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x8000920C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80009210: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80009214: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80009218: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8000921C: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80009220: beq         $at, $zero, L_800094DC
    if (ctx->r1 == 0) {
        // 0x80009224: swc1        $f6, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->f6.u32l;
            goto L_800094DC;
    }
    // 0x80009224: swc1        $f6, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->f6.u32l;
    // 0x80009228: bnel        $s1, $a2, L_800091F0
    if (ctx->r17 != ctx->r6) {
        // 0x8000922C: sra         $t9, $s0, 12
        ctx->r25 = S32(SIGNED(ctx->r16) >> 12);
            goto L_800091F0;
    }
    goto skip_0;
    // 0x8000922C: sra         $t9, $s0, 12
    ctx->r25 = S32(SIGNED(ctx->r16) >> 12);
    skip_0:
    // 0x80009230: b           L_800091E4
    // 0x80009234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800091E4;
    // 0x80009234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80009238:
    // 0x80009238: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8000923C: addu        $t5, $a3, $t7
    ctx->r13 = ADD32(ctx->r7, ctx->r15);
    // 0x80009240: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80009244: andi        $a0, $s0, 0xF
    ctx->r4 = ctx->r16 & 0XF;
    // 0x80009248: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000924C: beq         $s1, $t1, L_800092E8
    if (ctx->r17 == ctx->r9) {
        // 0x80009250: lhu         $s0, 0x0($a1)
        ctx->r16 = MEM_HU(ctx->r5, 0X0);
            goto L_800092E8;
    }
    // 0x80009250: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
L_80009254:
    // 0x80009254: sra         $t8, $s0, 12
    ctx->r24 = S32(SIGNED(ctx->r16) >> 12);
    // 0x80009258: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8000925C: addiu       $t7, $t9, -0x8
    ctx->r15 = ADD32(ctx->r25, -0X8);
    // 0x80009260: sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16 << 4);
    // 0x80009264: sllv        $t8, $t7, $a0
    ctx->r24 = S32(ctx->r15 << (ctx->r4 & 31));
    // 0x80009268: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8000926C: sra         $t9, $v0, 12
    ctx->r25 = S32(SIGNED(ctx->r2) >> 12);
    // 0x80009270: andi        $t6, $t9, 0xF
    ctx->r14 = ctx->r25 & 0XF;
    // 0x80009274: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80009278: addiu       $t8, $t6, -0x8
    ctx->r24 = ADD32(ctx->r14, -0X8);
    // 0x8000927C: sll         $s0, $v0, 4
    ctx->r16 = S32(ctx->r2 << 4);
    // 0x80009280: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x80009284: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80009288: sra         $t6, $s0, 12
    ctx->r14 = S32(SIGNED(ctx->r16) >> 12);
    // 0x8000928C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80009290: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009294: addiu       $t9, $t7, -0x8
    ctx->r25 = ADD32(ctx->r15, -0X8);
    // 0x80009298: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x8000929C: sllv        $t6, $t9, $a0
    ctx->r14 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x800092A0: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x800092A4: sra         $t7, $t8, 12
    ctx->r15 = S32(SIGNED(ctx->r24) >> 12);
    // 0x800092A8: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800092AC: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800092B0: addiu       $t9, $t8, -0x8
    ctx->r25 = ADD32(ctx->r24, -0X8);
    // 0x800092B4: sllv        $t6, $t9, $a0
    ctx->r14 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x800092B8: mtc1        $t6, $f12
    ctx->f12.u32l = ctx->r14;
    // 0x800092BC: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x800092C0: swc1        $f16, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f16.u32l;
    // 0x800092C4: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x800092C8: swc1        $f14, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f14.u32l;
    // 0x800092CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800092D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800092D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800092D8: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x800092DC: swc1        $f12, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->f12.u32l;
    // 0x800092E0: bne         $s1, $t1, L_80009254
    if (ctx->r17 != ctx->r9) {
        // 0x800092E4: lhu         $s0, 0x0($a1)
        ctx->r16 = MEM_HU(ctx->r5, 0X0);
            goto L_80009254;
    }
    // 0x800092E4: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
L_800092E8:
    // 0x800092E8: sra         $t8, $s0, 12
    ctx->r24 = S32(SIGNED(ctx->r16) >> 12);
    // 0x800092EC: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800092F0: addiu       $t7, $t9, -0x8
    ctx->r15 = ADD32(ctx->r25, -0X8);
    // 0x800092F4: sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16 << 4);
    // 0x800092F8: sra         $t9, $v0, 12
    ctx->r25 = S32(SIGNED(ctx->r2) >> 12);
    // 0x800092FC: sllv        $t8, $t7, $a0
    ctx->r24 = S32(ctx->r15 << (ctx->r4 & 31));
    // 0x80009300: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80009304: andi        $t6, $t9, 0xF
    ctx->r14 = ctx->r25 & 0XF;
    // 0x80009308: addiu       $t8, $t6, -0x8
    ctx->r24 = ADD32(ctx->r14, -0X8);
    // 0x8000930C: sll         $s0, $v0, 4
    ctx->r16 = S32(ctx->r2 << 4);
    // 0x80009310: sra         $t6, $s0, 12
    ctx->r14 = S32(SIGNED(ctx->r16) >> 12);
    // 0x80009314: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x80009318: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8000931C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80009320: addiu       $t9, $t7, -0x8
    ctx->r25 = ADD32(ctx->r15, -0X8);
    // 0x80009324: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x80009328: sra         $t7, $t8, 12
    ctx->r15 = S32(SIGNED(ctx->r24) >> 12);
    // 0x8000932C: sllv        $t6, $t9, $a0
    ctx->r14 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x80009330: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80009334: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x80009338: addiu       $t9, $t8, -0x8
    ctx->r25 = ADD32(ctx->r24, -0X8);
    // 0x8000933C: sllv        $t6, $t9, $a0
    ctx->r14 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x80009340: mtc1        $t6, $f12
    ctx->f12.u32l = ctx->r14;
    // 0x80009344: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80009348: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8000934C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80009350: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x80009354: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009358: swc1        $f18, -0x10($t5)
    MEM_W(-0X10, ctx->r13) = ctx->f18.u32l;
    // 0x8000935C: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80009360: swc1        $f16, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->f16.u32l;
    // 0x80009364: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x80009368: swc1        $f14, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->f14.u32l;
    // 0x8000936C: swc1        $f12, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->f12.u32l;
    // 0x80009370: b           L_800094E0
    // 0x80009374: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
        goto L_800094E0;
    // 0x80009374: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
L_80009378:
    // 0x80009378: andi        $a0, $s0, 0xF
    ctx->r4 = ctx->r16 & 0XF;
L_8000937C:
    // 0x8000937C: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
    // 0x80009380: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80009384: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80009388: sra         $t7, $s0, 8
    ctx->r15 = S32(SIGNED(ctx->r16) >> 8);
    // 0x8000938C: andi        $s1, $t7, 0xFF
    ctx->r17 = ctx->r15 & 0XFF;
    // 0x80009390: andi        $t9, $s1, 0x3F
    ctx->r25 = ctx->r17 & 0X3F;
    // 0x80009394: addiu       $t6, $t9, -0x20
    ctx->r14 = ADD32(ctx->r25, -0X20);
    // 0x80009398: sllv        $t7, $t6, $a0
    ctx->r15 = S32(ctx->r14 << (ctx->r4 & 31));
    // 0x8000939C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800093A0: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x800093A4: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800093A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800093AC: sra         $t5, $s1, 6
    ctx->r13 = S32(SIGNED(ctx->r17) >> 6);
    // 0x800093B0: andi        $t7, $t6, 0x3F
    ctx->r15 = ctx->r14 & 0X3F;
    // 0x800093B4: addiu       $t8, $t7, -0x20
    ctx->r24 = ADD32(ctx->r15, -0X20);
    // 0x800093B8: beq         $t5, $zero, L_800094DC
    if (ctx->r13 == 0) {
        // 0x800093BC: swc1        $f18, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
            goto L_800094DC;
    }
    // 0x800093BC: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x800093C0: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x800093C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800093C8: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x800093CC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800093D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800093D4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800093D8: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800093DC: sra         $s1, $s0, 6
    ctx->r17 = S32(SIGNED(ctx->r16) >> 6);
    // 0x800093E0: beq         $s1, $zero, L_800094DC
    if (ctx->r17 == 0) {
        // 0x800093E4: swc1        $f6, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
            goto L_800094DC;
    }
    // 0x800093E4: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800093E8: b           L_8000937C
    // 0x800093EC: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
        goto L_8000937C;
    // 0x800093EC: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
L_800093F0:
    // 0x800093F0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800093F4: addu        $t5, $a3, $t8
    ctx->r13 = ADD32(ctx->r7, ctx->r24);
    // 0x800093F8: andi        $a0, $s0, 0xF
    ctx->r4 = ctx->r16 & 0XF;
L_800093FC:
    // 0x800093FC: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
    // 0x80009400: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80009404: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80009408: sra         $t9, $s0, 8
    ctx->r25 = S32(SIGNED(ctx->r16) >> 8);
    // 0x8000940C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80009410: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80009414: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x80009418: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x8000941C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80009420: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x80009424: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x80009428: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000942C: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80009430: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x80009434: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x80009438: beq         $at, $zero, L_800094DC
    if (ctx->r1 == 0) {
        // 0x8000943C: swc1        $f10, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->f10.u32l;
            goto L_800094DC;
    }
    // 0x8000943C: swc1        $f10, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->f10.u32l;
    // 0x80009440: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80009444: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x80009448: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8000944C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009450: bne         $at, $zero, L_800093FC
    if (ctx->r1 != 0) {
        // 0x80009454: swc1        $f18, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->f18.u32l;
            goto L_800093FC;
    }
    // 0x80009454: swc1        $f18, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->f18.u32l;
    // 0x80009458: b           L_800094E0
    // 0x8000945C: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
        goto L_800094E0;
    // 0x8000945C: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
L_80009460:
    // 0x80009460: andi        $a0, $s0, 0xF
    ctx->r4 = ctx->r16 & 0XF;
L_80009464:
    // 0x80009464: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
    // 0x80009468: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8000946C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80009470: andi        $t6, $s0, 0xFFF
    ctx->r14 = ctx->r16 & 0XFFF;
    // 0x80009474: addiu       $t7, $t6, -0x800
    ctx->r15 = ADD32(ctx->r14, -0X800);
    // 0x80009478: sllv        $t8, $t7, $a0
    ctx->r24 = S32(ctx->r15 << (ctx->r4 & 31));
    // 0x8000947C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80009480: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80009484: sra         $t5, $s0, 12
    ctx->r13 = S32(SIGNED(ctx->r16) >> 12);
    // 0x80009488: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000948C: beq         $t5, $zero, L_800094DC
    if (ctx->r13 == 0) {
        // 0x80009490: swc1        $f6, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
            goto L_800094DC;
    }
    // 0x80009490: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80009494: b           L_80009464
    // 0x80009498: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
        goto L_80009464;
    // 0x80009498: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
L_8000949C:
    // 0x8000949C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800094A0: addu        $t5, $a3, $t7
    ctx->r13 = ADD32(ctx->r7, ctx->r15);
    // 0x800094A4: andi        $a0, $s0, 0xF
    ctx->r4 = ctx->r16 & 0XF;
L_800094A8:
    // 0x800094A8: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
    // 0x800094AC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800094B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800094B4: andi        $t8, $s0, 0x7FFF
    ctx->r24 = ctx->r16 & 0X7FFF;
    // 0x800094B8: addiu       $t9, $t8, -0x4000
    ctx->r25 = ADD32(ctx->r24, -0X4000);
    // 0x800094BC: sllv        $t6, $t9, $a0
    ctx->r14 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x800094C0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800094C4: sra         $t7, $s0, 15
    ctx->r15 = S32(SIGNED(ctx->r16) >> 15);
    // 0x800094C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800094CC: beq         $t0, $t7, L_800094DC
    if (ctx->r8 == ctx->r15) {
        // 0x800094D0: swc1        $f10, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
            goto L_800094DC;
    }
    // 0x800094D0: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800094D4: b           L_800094A8
    // 0x800094D8: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
        goto L_800094A8;
    // 0x800094D8: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
L_800094DC:
    // 0x800094DC: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
L_800094E0:
    // 0x800094E0: bnel        $t2, $t4, L_80009194
    if (ctx->r10 != ctx->r12) {
        // 0x800094E4: srl         $t7, $t3, 24
        ctx->r15 = S32(U32(ctx->r11) >> 24);
            goto L_80009194;
    }
    goto skip_1;
    // 0x800094E4: srl         $t7, $t3, 24
    ctx->r15 = S32(U32(ctx->r11) >> 24);
    skip_1:
    // 0x800094E8: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800094EC: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x800094F0: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800094F4: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800094F8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800094FC: jr          $ra
    // 0x80009500: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80009500: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_enmy_80061B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80061B6C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80061B70: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80061B74: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80061B78: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80061B7C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80061B80: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80061B84: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80061B88: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80061B8C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80061B90: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80061B94: addiu       $s0, $s0, 0x130
    ctx->r16 = ADD32(ctx->r16, 0X130);
    // 0x80061B98: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_80061B9C:
    // 0x80061B9C: bnel        $t6, $zero, L_80061CA4
    if (ctx->r14 != 0) {
        // 0x80061BA0: addiu       $s0, $s0, 0x8C
        ctx->r16 = ADD32(ctx->r16, 0X8C);
            goto L_80061CA4;
    }
    goto skip_0;
    // 0x80061BA0: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
    skip_0:
    // 0x80061BA4: jal         0x80004EB0
    // 0x80061BA8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80061BA8: nop

    after_0:
    // 0x80061BAC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80061BB0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80061BB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80061BB8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80061BBC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80061BC0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80061BC4: sub.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80061BC8: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80061BCC: addiu       $s1, $s1, -0x7D80
    ctx->r17 = ADD32(ctx->r17, -0X7D80);
    // 0x80061BD0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80061BD4: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80061BD8: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x80061BDC: lwc1        $f16, 0xC0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80061BE0: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80061BE4: addiu       $s2, $s2, 0x7940
    ctx->r18 = ADD32(ctx->r18, 0X7940);
    // 0x80061BE8: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80061BEC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80061BF0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80061BF4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80061BF8: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x80061BFC: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80061C00: bc1f        L_80061C44
    if (!c1cs) {
        // 0x80061C04: swc1        $f6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
            goto L_80061C44;
    }
    // 0x80061C04: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
L_80061C08:
    // 0x80061C08: jal         0x80004EB0
    // 0x80061C0C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80061C0C: nop

    after_1:
    // 0x80061C10: sub.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80061C14: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80061C18: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80061C1C: lwc1        $f6, 0xC4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80061C20: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80061C24: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80061C28: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80061C2C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80061C30: add.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80061C34: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x80061C38: nop

    // 0x80061C3C: bc1t        L_80061C08
    if (c1cs) {
        // 0x80061C40: nop
    
            goto L_80061C08;
    }
    // 0x80061C40: nop

L_80061C44:
    // 0x80061C44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80061C48: lwc1        $f12, 0x7D20($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80061C4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061C50: lwc1        $f8, 0x6438($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6438);
    // 0x80061C54: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80061C58: lwc1        $f18, 0x7D08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80061C5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80061C60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80061C64: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80061C68: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80061C6C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80061C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061C74: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80061C78: bc1fl       L_80061C90
    if (!c1cs) {
        // 0x80061C7C: mfc1        $a3, $f0
        ctx->r7 = (int32_t)ctx->f0.u32l;
            goto L_80061C90;
    }
    goto skip_1;
    // 0x80061C7C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x80061C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80061C84: nop

    // 0x80061C88: add.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80061C8C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_80061C90:
    // 0x80061C90: jal         0x80061958
    // 0x80061C94: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    Effect_SmallRock_Setup(rdram, ctx);
        goto after_2;
    // 0x80061C94: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x80061C98: b           L_80061CB0
    // 0x80061C9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80061CB0;
    // 0x80061C9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80061CA0: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
L_80061CA4:
    // 0x80061CA4: bnel        $s0, $v0, L_80061B9C
    if (ctx->r16 != ctx->r2) {
        // 0x80061CA8: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_80061B9C;
    }
    goto skip_2;
    // 0x80061CA8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_2:
    // 0x80061CAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80061CB0:
    // 0x80061CB0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80061CB4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80061CB8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80061CBC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80061CC0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80061CC4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80061CC8: jr          $ra
    // 0x80061CCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80061CCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Audio_StopSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017764: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017768: lbu         $t7, 0x1B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1B);
    // 0x8001776C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017770: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80017774: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80017778: lui         $at, 0x8300
    ctx->r1 = S32(0X8300 << 16);
    // 0x8001777C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80017780: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80017784: jal         0x8001E8CC
    // 0x80017788: or          $a0, $t8, $at
    ctx->r4 = ctx->r24 | ctx->r1;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_0;
    // 0x80017788: or          $a0, $t8, $at
    ctx->r4 = ctx->r24 | ctx->r1;
    after_0:
    // 0x8001778C: lbu         $t1, 0x1B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1B);
    // 0x80017790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017794: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017798: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001779C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800177A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800177A4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800177A8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800177AC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800177B0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800177B4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800177B8: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x800177BC: sh          $t0, -0x5010($at)
    MEM_H(-0X5010, ctx->r1) = ctx->r8;
    // 0x800177C0: jr          $ra
    // 0x800177C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800177C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Sprite_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061394: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80061398: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x8006139C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800613A0:
    // 0x800613A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800613A4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800613A8: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800613AC: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800613B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800613B4: bne         $v1, $a0, L_800613A0
    if (ctx->r3 != ctx->r4) {
        // 0x800613B8: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800613A0;
    }
    // 0x800613B8: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800613BC: jr          $ra
    // 0x800613C0: nop

    return;
    // 0x800613C0: nop

;}
RECOMP_FUNC void Lib_Texture_Mottle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099E28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80099E2C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80099E30: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80099E34: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80099E38: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80099E3C: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80099E40: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80099E44: addiu       $v0, $v0, 0x1FD0
    ctx->r2 = ADD32(ctx->r2, 0X1FD0);
    // 0x80099E48: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80099E4C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80099E50: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80099E54: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80099E58: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80099E5C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80099E60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80099E64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80099E68: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80099E6C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80099E70: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80099E74: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x80099E78: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80099E7C: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x80099E80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80099E84: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x80099E88: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x80099E8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80099E90: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80099E94: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80099E98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80099E9C: and         $t3, $s2, $v1
    ctx->r11 = ctx->r18 & ctx->r3;
    // 0x80099EA0: and         $t1, $a3, $v1
    ctx->r9 = ctx->r7 & ctx->r3;
    // 0x80099EA4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80099EA8: sltiu       $at, $a2, 0x6
    ctx->r1 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x80099EAC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80099EB0: addu        $s2, $t4, $t0
    ctx->r18 = ADD32(ctx->r12, ctx->r8);
    // 0x80099EB4: beq         $at, $zero, L_8009A3D8
    if (ctx->r1 == 0) {
        // 0x80099EB8: addu        $a3, $t2, $t0
        ctx->r7 = ADD32(ctx->r10, ctx->r8);
            goto L_8009A3D8;
    }
    // 0x80099EB8: addu        $a3, $t2, $t0
    ctx->r7 = ADD32(ctx->r10, ctx->r8);
    // 0x80099EBC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80099EC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099EC4: addu        $at, $at, $t3
    gpr jr_addend_80099ECC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80099EC8: lw          $t3, -0x7E10($at)
    ctx->r11 = ADD32(ctx->r1, -0X7E10);
    // 0x80099ECC: jr          $t3
    // 0x80099ED0: nop

    switch (jr_addend_80099ECC >> 2) {
        case 0: goto L_8009A1E0; break;
        case 1: goto L_8009A0DC; break;
        case 2: goto L_80099ED4; break;
        case 3: goto L_80099FE0; break;
        case 4: goto L_8009A3D8; break;
        case 5: goto L_8009A2E4; break;
        default: switch_error(__func__, 0x80099ECC, 0x800D81F0);
    }
    // 0x80099ED0: nop

L_80099ED4:
    // 0x80099ED4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80099ED8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099EDC: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x80099EE0: addiu       $s5, $s5, 0x7DB0
    ctx->r21 = ADD32(ctx->r21, 0X7DB0);
    // 0x80099EE4: lwc1        $f20, -0x7DF8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7DF8);
    // 0x80099EE8: addiu       $s2, $zero, 0x400
    ctx->r18 = ADD32(0, 0X400);
    // 0x80099EEC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80099EF0: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80099EF4: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
L_80099EF8:
    // 0x80099EF8: bgez        $s3, L_80099F08
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80099EFC: sra         $t4, $s3, 5
        ctx->r12 = S32(SIGNED(ctx->r19) >> 5);
            goto L_80099F08;
    }
    // 0x80099EFC: sra         $t4, $s3, 5
    ctx->r12 = S32(SIGNED(ctx->r19) >> 5);
    // 0x80099F00: addiu       $at, $s3, 0x1F
    ctx->r1 = ADD32(ctx->r19, 0X1F);
    // 0x80099F04: sra         $t4, $at, 5
    ctx->r12 = S32(SIGNED(ctx->r1) >> 5);
L_80099F08:
    // 0x80099F08: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80099F0C: bgez        $t5, L_80099F1C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80099F10: sra         $t6, $t5, 2
        ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
            goto L_80099F1C;
    }
    // 0x80099F10: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x80099F14: addiu       $at, $t5, 0x3
    ctx->r1 = ADD32(ctx->r13, 0X3);
    // 0x80099F18: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_80099F1C:
    // 0x80099F1C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80099F20: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x80099F24: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80099F28: nop

    // 0x80099F2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80099F30: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80099F34: jal         0x80023090
    // 0x80099F38: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80099F38: nop

    after_0:
    // 0x80099F3C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80099F40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80099F44: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80099F48: addiu       $s4, $s4, 0x40
    ctx->r20 = ADD32(ctx->r20, 0X40);
    // 0x80099F4C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80099F50: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x80099F54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80099F58: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80099F5C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80099F60: nop

L_80099F64:
    // 0x80099F64: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    // 0x80099F68: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80099F6C: andi        $t2, $a0, 0x1F
    ctx->r10 = ctx->r4 & 0X1F;
    // 0x80099F70: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80099F74: addu        $t5, $s0, $t3
    ctx->r13 = ADD32(ctx->r16, ctx->r11);
    // 0x80099F78: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80099F7C: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
    // 0x80099F80: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
    // 0x80099F84: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x80099F88: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80099F8C: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80099F90: addiu       $t3, $a0, 0x2
    ctx->r11 = ADD32(ctx->r4, 0X2);
    // 0x80099F94: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x80099F98: lhu         $t2, 0x4($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X4);
    // 0x80099F9C: andi        $t1, $t3, 0x1F
    ctx->r9 = ctx->r11 & 0X1F;
    // 0x80099FA0: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x80099FA4: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80099FA8: addiu       $t8, $a0, 0x3
    ctx->r24 = ADD32(ctx->r4, 0X3);
    // 0x80099FAC: andi        $t4, $t8, 0x1F
    ctx->r12 = ctx->r24 & 0X1F;
    // 0x80099FB0: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x80099FB4: lhu         $t7, 0x6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X6);
    // 0x80099FB8: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x80099FBC: addu        $t3, $s0, $t9
    ctx->r11 = ADD32(ctx->r16, ctx->r25);
    // 0x80099FC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80099FC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80099FC8: bne         $v1, $s1, L_80099F64
    if (ctx->r3 != ctx->r17) {
        // 0x80099FCC: sh          $t7, 0x0($t3)
        MEM_H(0X0, ctx->r11) = ctx->r15;
            goto L_80099F64;
    }
    // 0x80099FCC: sh          $t7, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r15;
    // 0x80099FD0: bne         $s3, $s2, L_80099EF8
    if (ctx->r19 != ctx->r18) {
        // 0x80099FD4: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_80099EF8;
    }
    // 0x80099FD4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80099FD8: b           L_8009A3DC
    // 0x80099FDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8009A3DC;
    // 0x80099FDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80099FE0:
    // 0x80099FE0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80099FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099FE8: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x80099FEC: addiu       $s5, $s5, 0x7DB0
    ctx->r21 = ADD32(ctx->r21, 0X7DB0);
    // 0x80099FF0: lwc1        $f20, -0x7DF4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7DF4);
    // 0x80099FF4: addiu       $s2, $zero, 0x580
    ctx->r18 = ADD32(0, 0X580);
    // 0x80099FF8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80099FFC: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8009A000: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
L_8009A004:
    // 0x8009A004: bgez        $s3, L_8009A014
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8009A008: sra         $t1, $s3, 6
        ctx->r9 = S32(SIGNED(ctx->r19) >> 6);
            goto L_8009A014;
    }
    // 0x8009A008: sra         $t1, $s3, 6
    ctx->r9 = S32(SIGNED(ctx->r19) >> 6);
    // 0x8009A00C: addiu       $at, $s3, 0x3F
    ctx->r1 = ADD32(ctx->r19, 0X3F);
    // 0x8009A010: sra         $t1, $at, 6
    ctx->r9 = S32(SIGNED(ctx->r1) >> 6);
L_8009A014:
    // 0x8009A014: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8009A018: bgez        $t5, L_8009A028
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009A01C: sra         $t2, $t5, 2
        ctx->r10 = S32(SIGNED(ctx->r13) >> 2);
            goto L_8009A028;
    }
    // 0x8009A01C: sra         $t2, $t5, 2
    ctx->r10 = S32(SIGNED(ctx->r13) >> 2);
    // 0x8009A020: addiu       $at, $t5, 0x3
    ctx->r1 = ADD32(ctx->r13, 0X3);
    // 0x8009A024: sra         $t2, $at, 2
    ctx->r10 = S32(SIGNED(ctx->r1) >> 2);
L_8009A028:
    // 0x8009A028: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x8009A02C: andi        $t8, $t6, 0x1F
    ctx->r24 = ctx->r14 & 0X1F;
    // 0x8009A030: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8009A034: nop

    // 0x8009A038: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009A03C: mul.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8009A040: jal         0x80023090
    // 0x8009A044: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8009A044: nop

    after_1:
    // 0x8009A048: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8009A04C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8009A050: addiu       $s4, $s4, 0x80
    ctx->r20 = ADD32(ctx->r20, 0X80);
    // 0x8009A054: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x8009A058: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8009A05C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009A060:
    // 0x8009A060: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    // 0x8009A064: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8009A068: andi        $t7, $a0, 0x3F
    ctx->r15 = ctx->r4 & 0X3F;
    // 0x8009A06C: sll         $t3, $t7, 1
    ctx->r11 = S32(ctx->r15 << 1);
    // 0x8009A070: addu        $t5, $s0, $t3
    ctx->r13 = ADD32(ctx->r16, ctx->r11);
    // 0x8009A074: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x8009A078: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x8009A07C: lhu         $t1, 0x2($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X2);
    // 0x8009A080: andi        $t6, $t2, 0x3F
    ctx->r14 = ctx->r10 & 0X3F;
    // 0x8009A084: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8009A088: addu        $t4, $s0, $t8
    ctx->r12 = ADD32(ctx->r16, ctx->r24);
    // 0x8009A08C: addiu       $t3, $a0, 0x2
    ctx->r11 = ADD32(ctx->r4, 0X2);
    // 0x8009A090: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
    // 0x8009A094: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x8009A098: andi        $t9, $t3, 0x3F
    ctx->r25 = ctx->r11 & 0X3F;
    // 0x8009A09C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8009A0A0: addu        $t2, $s0, $t5
    ctx->r10 = ADD32(ctx->r16, ctx->r13);
    // 0x8009A0A4: addiu       $t8, $a0, 0x3
    ctx->r24 = ADD32(ctx->r4, 0X3);
    // 0x8009A0A8: andi        $t1, $t8, 0x3F
    ctx->r9 = ctx->r24 & 0X3F;
    // 0x8009A0AC: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
    // 0x8009A0B0: lhu         $t6, 0x6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6);
    // 0x8009A0B4: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8009A0B8: addu        $t3, $s0, $t4
    ctx->r11 = ADD32(ctx->r16, ctx->r12);
    // 0x8009A0BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009A0C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8009A0C4: bne         $v1, $s1, L_8009A060
    if (ctx->r3 != ctx->r17) {
        // 0x8009A0C8: sh          $t6, 0x0($t3)
        MEM_H(0X0, ctx->r11) = ctx->r14;
            goto L_8009A060;
    }
    // 0x8009A0C8: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
    // 0x8009A0CC: bne         $s3, $s2, L_8009A004
    if (ctx->r19 != ctx->r18) {
        // 0x8009A0D0: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_8009A004;
    }
    // 0x8009A0D0: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8009A0D4: b           L_8009A3DC
    // 0x8009A0D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8009A3DC;
    // 0x8009A0D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8009A0DC:
    // 0x8009A0DC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8009A0E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A0E4: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x8009A0E8: addiu       $s5, $s5, 0x7DB0
    ctx->r21 = ADD32(ctx->r21, 0X7DB0);
    // 0x8009A0EC: lwc1        $f20, -0x7DF0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7DF0);
    // 0x8009A0F0: addiu       $s2, $zero, 0x100
    ctx->r18 = ADD32(0, 0X100);
    // 0x8009A0F4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009A0F8: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8009A0FC: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_8009A100:
    // 0x8009A100: bgez        $s3, L_8009A110
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8009A104: sra         $t9, $s3, 4
        ctx->r25 = S32(SIGNED(ctx->r19) >> 4);
            goto L_8009A110;
    }
    // 0x8009A104: sra         $t9, $s3, 4
    ctx->r25 = S32(SIGNED(ctx->r19) >> 4);
    // 0x8009A108: addiu       $at, $s3, 0xF
    ctx->r1 = ADD32(ctx->r19, 0XF);
    // 0x8009A10C: sra         $t9, $at, 4
    ctx->r25 = S32(SIGNED(ctx->r1) >> 4);
L_8009A110:
    // 0x8009A110: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8009A114: bgez        $t5, L_8009A124
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009A118: sra         $t7, $t5, 1
        ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8009A124;
    }
    // 0x8009A118: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8009A11C: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8009A120: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8009A124:
    // 0x8009A124: addu        $t2, $t9, $t7
    ctx->r10 = ADD32(ctx->r25, ctx->r15);
    // 0x8009A128: andi        $t8, $t2, 0xF
    ctx->r24 = ctx->r10 & 0XF;
    // 0x8009A12C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009A130: nop

    // 0x8009A134: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009A138: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8009A13C: jal         0x80023090
    // 0x8009A140: nop

    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8009A140: nop

    after_2:
    // 0x8009A144: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8009A148: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8009A14C: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x8009A150: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8009A154: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8009A158: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009A15C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009A160: nop

L_8009A164:
    // 0x8009A164: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    // 0x8009A168: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x8009A16C: andi        $t6, $a0, 0xF
    ctx->r14 = ctx->r4 & 0XF;
    // 0x8009A170: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x8009A174: addu        $t5, $s0, $t3
    ctx->r13 = ADD32(ctx->r16, ctx->r11);
    // 0x8009A178: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8009A17C: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x8009A180: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x8009A184: andi        $t2, $t7, 0xF
    ctx->r10 = ctx->r15 & 0XF;
    // 0x8009A188: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x8009A18C: addu        $t1, $s0, $t8
    ctx->r9 = ADD32(ctx->r16, ctx->r24);
    // 0x8009A190: addiu       $t3, $a0, 0x2
    ctx->r11 = ADD32(ctx->r4, 0X2);
    // 0x8009A194: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x8009A198: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x8009A19C: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8009A1A0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8009A1A4: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
    // 0x8009A1A8: addiu       $t8, $a0, 0x3
    ctx->r24 = ADD32(ctx->r4, 0X3);
    // 0x8009A1AC: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8009A1B0: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8009A1B4: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x8009A1B8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8009A1BC: addu        $t3, $s0, $t1
    ctx->r11 = ADD32(ctx->r16, ctx->r9);
    // 0x8009A1C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009A1C4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8009A1C8: bne         $v1, $s1, L_8009A164
    if (ctx->r3 != ctx->r17) {
        // 0x8009A1CC: sh          $t2, 0x0($t3)
        MEM_H(0X0, ctx->r11) = ctx->r10;
            goto L_8009A164;
    }
    // 0x8009A1CC: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x8009A1D0: bne         $s3, $s2, L_8009A100
    if (ctx->r19 != ctx->r18) {
        // 0x8009A1D4: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_8009A100;
    }
    // 0x8009A1D4: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8009A1D8: b           L_8009A3DC
    // 0x8009A1DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8009A3DC;
    // 0x8009A1DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8009A1E0:
    // 0x8009A1E0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8009A1E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A1E8: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x8009A1EC: addiu       $s5, $s5, 0x7DB0
    ctx->r21 = ADD32(ctx->r21, 0X7DB0);
    // 0x8009A1F0: lwc1        $f20, -0x7DEC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7DEC);
    // 0x8009A1F4: addiu       $s2, $zero, 0x400
    ctx->r18 = ADD32(0, 0X400);
    // 0x8009A1F8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009A1FC: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8009A200: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
L_8009A204:
    // 0x8009A204: bgez        $s3, L_8009A214
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8009A208: sra         $t4, $s3, 5
        ctx->r12 = S32(SIGNED(ctx->r19) >> 5);
            goto L_8009A214;
    }
    // 0x8009A208: sra         $t4, $s3, 5
    ctx->r12 = S32(SIGNED(ctx->r19) >> 5);
    // 0x8009A20C: addiu       $at, $s3, 0x1F
    ctx->r1 = ADD32(ctx->r19, 0X1F);
    // 0x8009A210: sra         $t4, $at, 5
    ctx->r12 = S32(SIGNED(ctx->r1) >> 5);
L_8009A214:
    // 0x8009A214: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8009A218: bgez        $t5, L_8009A228
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009A21C: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8009A228;
    }
    // 0x8009A21C: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8009A220: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8009A224: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8009A228:
    // 0x8009A228: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8009A22C: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x8009A230: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8009A234: nop

    // 0x8009A238: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A23C: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8009A240: jal         0x80023090
    // 0x8009A244: nop

    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8009A244: nop

    after_3:
    // 0x8009A248: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8009A24C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8009A250: addiu       $s4, $s4, 0x40
    ctx->r20 = ADD32(ctx->r20, 0X40);
    // 0x8009A254: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x8009A258: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009A25C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009A260: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8009A264: nop

L_8009A268:
    // 0x8009A268: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    // 0x8009A26C: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x8009A270: andi        $t2, $a0, 0x1F
    ctx->r10 = ctx->r4 & 0X1F;
    // 0x8009A274: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8009A278: addu        $t5, $s0, $t3
    ctx->r13 = ADD32(ctx->r16, ctx->r11);
    // 0x8009A27C: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x8009A280: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
    // 0x8009A284: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
    // 0x8009A288: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x8009A28C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009A290: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x8009A294: addiu       $t3, $a0, 0x2
    ctx->r11 = ADD32(ctx->r4, 0X2);
    // 0x8009A298: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x8009A29C: lhu         $t2, 0x4($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X4);
    // 0x8009A2A0: andi        $t1, $t3, 0x1F
    ctx->r9 = ctx->r11 & 0X1F;
    // 0x8009A2A4: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x8009A2A8: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x8009A2AC: addiu       $t8, $a0, 0x3
    ctx->r24 = ADD32(ctx->r4, 0X3);
    // 0x8009A2B0: andi        $t4, $t8, 0x1F
    ctx->r12 = ctx->r24 & 0X1F;
    // 0x8009A2B4: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x8009A2B8: lhu         $t7, 0x6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X6);
    // 0x8009A2BC: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x8009A2C0: addu        $t3, $s0, $t9
    ctx->r11 = ADD32(ctx->r16, ctx->r25);
    // 0x8009A2C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009A2C8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8009A2CC: bne         $v1, $s1, L_8009A268
    if (ctx->r3 != ctx->r17) {
        // 0x8009A2D0: sh          $t7, 0x0($t3)
        MEM_H(0X0, ctx->r11) = ctx->r15;
            goto L_8009A268;
    }
    // 0x8009A2D0: sh          $t7, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r15;
    // 0x8009A2D4: bne         $s3, $s2, L_8009A204
    if (ctx->r19 != ctx->r18) {
        // 0x8009A2D8: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8009A204;
    }
    // 0x8009A2D8: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8009A2DC: b           L_8009A3DC
    // 0x8009A2E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8009A3DC;
    // 0x8009A2E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8009A2E4:
    // 0x8009A2E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A2E8: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x8009A2EC: addiu       $s5, $s5, 0x7DB0
    ctx->r21 = ADD32(ctx->r21, 0X7DB0);
    // 0x8009A2F0: lwc1        $f20, -0x7DE8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7DE8);
    // 0x8009A2F4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009A2F8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8009A2FC: addiu       $s4, $zero, 0x1000
    ctx->r20 = ADD32(0, 0X1000);
    // 0x8009A300: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
L_8009A304:
    // 0x8009A304: bgez        $s3, L_8009A314
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8009A308: sra         $t1, $s3, 6
        ctx->r9 = S32(SIGNED(ctx->r19) >> 6);
            goto L_8009A314;
    }
    // 0x8009A308: sra         $t1, $s3, 6
    ctx->r9 = S32(SIGNED(ctx->r19) >> 6);
    // 0x8009A30C: addiu       $at, $s3, 0x3F
    ctx->r1 = ADD32(ctx->r19, 0X3F);
    // 0x8009A310: sra         $t1, $at, 6
    ctx->r9 = S32(SIGNED(ctx->r1) >> 6);
L_8009A314:
    // 0x8009A314: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8009A318: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8009A31C: bgez        $t5, L_8009A32C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009A320: sra         $t2, $t5, 2
        ctx->r10 = S32(SIGNED(ctx->r13) >> 2);
            goto L_8009A32C;
    }
    // 0x8009A320: sra         $t2, $t5, 2
    ctx->r10 = S32(SIGNED(ctx->r13) >> 2);
    // 0x8009A324: addiu       $at, $t5, 0x3
    ctx->r1 = ADD32(ctx->r13, 0X3);
    // 0x8009A328: sra         $t2, $at, 2
    ctx->r10 = S32(SIGNED(ctx->r1) >> 2);
L_8009A32C:
    // 0x8009A32C: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x8009A330: andi        $t8, $t6, 0x1F
    ctx->r24 = ctx->r14 & 0X1F;
    // 0x8009A334: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8009A338: nop

    // 0x8009A33C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009A340: mul.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8009A344: jal         0x80023090
    // 0x8009A348: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8009A348: nop

    after_4:
    // 0x8009A34C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009A350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009A354: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8009A358: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009A35C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8009A360: addu        $a0, $s3, $a3
    ctx->r4 = ADD32(ctx->r19, ctx->r7);
    // 0x8009A364: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x8009A368: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009A36C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009A370: nop

L_8009A374:
    // 0x8009A374: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8009A378: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x8009A37C: andi        $t7, $v0, 0x3F
    ctx->r15 = ctx->r2 & 0X3F;
    // 0x8009A380: addu        $t3, $s0, $t7
    ctx->r11 = ADD32(ctx->r16, ctx->r15);
    // 0x8009A384: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
    // 0x8009A388: lbu         $t5, 0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X1);
    // 0x8009A38C: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x8009A390: andi        $t2, $t1, 0x3F
    ctx->r10 = ctx->r9 & 0X3F;
    // 0x8009A394: addu        $t6, $s0, $t2
    ctx->r14 = ADD32(ctx->r16, ctx->r10);
    // 0x8009A398: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8009A39C: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8009A3A0: addiu       $t4, $v0, 0x2
    ctx->r12 = ADD32(ctx->r2, 0X2);
    // 0x8009A3A4: andi        $t7, $t4, 0x3F
    ctx->r15 = ctx->r12 & 0X3F;
    // 0x8009A3A8: addu        $t9, $s0, $t7
    ctx->r25 = ADD32(ctx->r16, ctx->r15);
    // 0x8009A3AC: addiu       $t1, $v0, 0x3
    ctx->r9 = ADD32(ctx->r2, 0X3);
    // 0x8009A3B0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8009A3B4: lbu         $t3, 0x3($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X3);
    // 0x8009A3B8: andi        $t2, $t1, 0x3F
    ctx->r10 = ctx->r9 & 0X3F;
    // 0x8009A3BC: addu        $t5, $s0, $t2
    ctx->r13 = ADD32(ctx->r16, ctx->r10);
    // 0x8009A3C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009A3C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8009A3C8: bne         $v1, $s1, L_8009A374
    if (ctx->r3 != ctx->r17) {
        // 0x8009A3CC: sb          $t3, 0x0($t5)
        MEM_B(0X0, ctx->r13) = ctx->r11;
            goto L_8009A374;
    }
    // 0x8009A3CC: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x8009A3D0: bne         $s3, $s4, L_8009A304
    if (ctx->r19 != ctx->r20) {
        // 0x8009A3D4: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8009A304;
    }
    // 0x8009A3D4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
L_8009A3D8:
    // 0x8009A3D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8009A3DC:
    // 0x8009A3DC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8009A3E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8009A3E4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8009A3E8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8009A3EC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8009A3F0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8009A3F4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8009A3F8: jr          $ra
    // 0x8009A3FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8009A3FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void AudioLoad_AsyncLoadSampleBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EEE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000EEE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000EEEC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000EEF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000EEF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000EEF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000EEFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8000EF00: jal         0x8000F790
    // 0x8000EF04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000EF04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8000EF08: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000EF0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000EF10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000EF14: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000EF18: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8000EF1C: jal         0x8000FCC0
    // 0x8000EF20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    AudioLoad_AsyncLoadInner(rdram, ctx);
        goto after_1;
    // 0x8000EF20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8000EF24: bne         $v0, $zero, L_8000EF38
    if (ctx->r2 != 0) {
        // 0x8000EF28: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_8000EF38;
    }
    // 0x8000EF28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000EF2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000EF30: jal         0x80020720
    // 0x8000EF34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8000EF34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8000EF38:
    // 0x8000EF38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000EF3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000EF40: jr          $ra
    // 0x8000EF44: nop

    return;
    // 0x8000EF44: nop

;}
RECOMP_FUNC void Effect_Effect390_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C50C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007C510: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007C514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007C518: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C51C: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
    // 0x8007C520: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007C524: bnel        $t7, $zero, L_8007C5F8
    if (ctx->r15 != 0) {
        // 0x8007C528: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8007C5F8;
    }
    goto skip_0;
    // 0x8007C528: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8007C52C: jal         0x80004EB0
    // 0x8007C530: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8007C530: nop

    after_0:
    // 0x8007C534: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C538: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C53C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8007C540: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C544: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8007C548: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007C54C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007C550: nop

    // 0x8007C554: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007C558: jal         0x80004EB0
    // 0x8007C55C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007C55C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8007C560: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C568: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8007C56C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C570: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8007C574: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007C578: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007C57C: nop

    // 0x8007C580: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007C584: jal         0x80004EB0
    // 0x8007C588: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007C588: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8007C58C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007C590: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007C594: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007C598: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007C59C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8007C5A0: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x8007C5A4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007C5A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007C5AC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007C5B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8007C5B4: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8007C5B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007C5BC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007C5C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8007C5C4: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007C5C8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8007C5CC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8007C5D0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8007C5D4: jal         0x8007C484
    // 0x8007C5D8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_3;
    // 0x8007C5D8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8007C5DC: lhu         $t8, 0x50($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X50);
    // 0x8007C5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007C5E4: bnel        $t8, $zero, L_8007C5F8
    if (ctx->r24 != 0) {
        // 0x8007C5E8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8007C5F8;
    }
    goto skip_1;
    // 0x8007C5E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8007C5EC: jal         0x80060FBC
    // 0x8007C5F0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x8007C5F0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_4:
    // 0x8007C5F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8007C5F8:
    // 0x8007C5F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007C5FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007C600: jr          $ra
    // 0x8007C604: nop

    return;
    // 0x8007C604: nop

;}
RECOMP_FUNC void AudioLoad_AsyncDmaUnkMedium(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010F8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010F90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80010F94: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80010F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010F9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80010FA0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80010FA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80010FA8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80010FAC: jal         0x80021740
    // 0x80010FB0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80010FB0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80010FB4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80010FB8: jal         0x8000FC7C
    // 0x80010FBC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000FC7C(rdram, ctx);
        goto after_1;
    // 0x80010FBC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80010FC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80010FC4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80010FC8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80010FCC: jal         0x8000FC8C
    // 0x80010FD0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8000FC8C(rdram, ctx);
        goto after_2;
    // 0x80010FD0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80010FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010FD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010FDC: jr          $ra
    // 0x80010FE0: nop

    return;
    // 0x80010FE0: nop

;}
RECOMP_FUNC void Timer_CompleteTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000708C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007090: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80007094: lw          $v0, 0x28($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X28);
    // 0x80007098: beql        $v0, $zero, L_800070B8
    if (ctx->r2 == 0) {
        // 0x8000709C: sb          $zero, 0x0($a2)
        MEM_B(0X0, ctx->r6) = 0;
            goto L_800070B8;
    }
    goto skip_0;
    // 0x8000709C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    skip_0:
    // 0x800070A0: lw          $a0, 0x2C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X2C);
    // 0x800070A4: lw          $a1, 0x30($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X30);
    // 0x800070A8: jalr        $v0
    // 0x800070AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800070AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800070B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800070B4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_800070B8:
    // 0x800070B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800070BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800070C0: jr          $ra
    // 0x800070C4: nop

    return;
    // 0x800070C4: nop

;}
RECOMP_FUNC void Sprite167_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066E90: lwc1        $f6, 0x6948($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6948);
    // 0x80066E94: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80066E98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80066E9C: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80066EA0: jr          $ra
    // 0x80066EA4: nop

    return;
    // 0x80066EA4: nop

;}
RECOMP_FUNC void ActorAllRange_SpawnTeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F180: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002F184: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002F188: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002F18C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002F190: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002F194: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002F198: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002F19C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002F1A0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002F1A4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002F1A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002F1AC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8002F1B0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8002F1B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8002F1B8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8002F1BC: lui         $fp, 0x8017
    ctx->r30 = S32(0X8017 << 16);
    // 0x8002F1C0: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8002F1C4: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x8002F1C8: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x8002F1CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8002F1D0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002F1D4: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8002F1D8: addiu       $s4, $s4, 0x5D34
    ctx->r20 = ADD32(ctx->r20, 0X5D34);
    // 0x8002F1DC: addiu       $s5, $s5, -0x7DCC
    ctx->r21 = ADD32(ctx->r21, -0X7DCC);
    // 0x8002F1E0: addiu       $s6, $s6, 0x5D3C
    ctx->r22 = ADD32(ctx->r22, 0X5D3C);
    // 0x8002F1E4: addiu       $fp, $fp, 0x78B0
    ctx->r30 = ADD32(ctx->r30, 0X78B0);
    // 0x8002F1E8: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8002F1EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8002F1F0:
    // 0x8002F1F0: blez        $s1, L_8002F208
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8002F1F4: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_8002F208;
    }
    // 0x8002F1F4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8002F1F8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8002F1FC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002F200: blezl       $t8, L_8002F39C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8002F204: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8002F39C;
    }
    goto skip_0;
    // 0x8002F204: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
L_8002F208:
    // 0x8002F208: jal         0x800613C4
    // 0x8002F20C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8002F20C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8002F210: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8002F214: addiu       $t0, $zero, 0xC5
    ctx->r8 = ADD32(0, 0XC5);
    // 0x8002F218: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8002F21C: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x8002F220: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x8002F224: jal         0x800612B8
    // 0x8002F228: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8002F228: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_1:
    // 0x8002F22C: bne         $s1, $zero, L_8002F240
    if (ctx->r17 != 0) {
        // 0x8002F230: sll         $t2, $s1, 2
        ctx->r10 = S32(ctx->r17 << 2);
            goto L_8002F240;
    }
    // 0x8002F230: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8002F234: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x8002F238: b           L_8002F398
    // 0x8002F23C: sh          $t1, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r9;
        goto L_8002F398;
    // 0x8002F23C: sh          $t1, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r9;
L_8002F240:
    // 0x8002F240: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8002F244: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8002F248: addiu       $t3, $t3, -0x6564
    ctx->r11 = ADD32(ctx->r11, -0X6564);
    // 0x8002F24C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002F250: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8002F254: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F258: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x8002F25C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8002F260: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8002F264: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F268: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x8002F26C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8002F270: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8002F274: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F278: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8002F27C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8002F280: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8002F284: lw          $t4, -0x6534($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6534);
    // 0x8002F288: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8002F28C: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8002F290: sh          $t4, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r12;
    // 0x8002F294: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8002F298: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8002F29C: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x8002F2A0: bne         $t5, $at, L_8002F2B4
    if (ctx->r13 != ctx->r1) {
        // 0x8002F2A4: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8002F2B4;
    }
    // 0x8002F2A4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8002F2A8: lw          $t6, -0x6514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6514);
    // 0x8002F2AC: b           L_8002F2BC
    // 0x8002F2B0: sh          $t6, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r14;
        goto L_8002F2BC;
    // 0x8002F2B0: sh          $t6, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r14;
L_8002F2B4:
    // 0x8002F2B4: lw          $t7, -0x6524($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6524);
    // 0x8002F2B8: sh          $t7, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r15;
L_8002F2BC:
    // 0x8002F2BC: lh          $t9, 0xE6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE6);
    // 0x8002F2C0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8002F2C4: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x8002F2C8: bgez        $t9, L_8002F2D4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002F2CC: swc1        $f20, 0xF8($s0)
        MEM_W(0XF8, ctx->r16) = ctx->f20.u32l;
            goto L_8002F2D4;
    }
    // 0x8002F2CC: swc1        $f20, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f20.u32l;
    // 0x8002F2D0: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
L_8002F2D4:
    // 0x8002F2D4: sh          $t1, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r9;
    // 0x8002F2D8: lbu         $t2, 0x7C98($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7C98);
    // 0x8002F2DC: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8002F2E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002F2E4: beq         $t2, $zero, L_8002F2FC
    if (ctx->r10 == 0) {
        // 0x8002F2E8: ori         $a0, $a0, 0xC
        ctx->r4 = ctx->r4 | 0XC;
            goto L_8002F2FC;
    }
    // 0x8002F2E8: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8002F2EC: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8002F2F0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8002F2F4: bnel        $t3, $at, L_8002F304
    if (ctx->r11 != ctx->r1) {
        // 0x8002F2F8: lh          $t6, 0xE4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XE4);
            goto L_8002F304;
    }
    goto skip_1;
    // 0x8002F2F8: lh          $t6, 0xE4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE4);
    skip_1:
L_8002F2FC:
    // 0x8002F2FC: sb          $t4, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r12;
    // 0x8002F300: lh          $t6, 0xE4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE4);
L_8002F304:
    // 0x8002F304: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002F308: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    // 0x8002F30C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8002F310: beq         $at, $zero, L_8002F378
    if (ctx->r1 == 0) {
        // 0x8002F314: addiu       $a1, $s0, 0x100
        ctx->r5 = ADD32(ctx->r16, 0X100);
            goto L_8002F378;
    }
    // 0x8002F314: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8002F318: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002F31C: addiu       $v0, $v0, -0x3FE4
    ctx->r2 = ADD32(ctx->r2, -0X3FE4);
    // 0x8002F320: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8002F324: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x8002F328: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002F32C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002F330: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F334: addiu       $t0, $t0, 0x1FD0
    ctx->r8 = ADD32(ctx->r8, 0X1FD0);
    // 0x8002F338: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002F33C: addu        $s2, $t9, $t0
    ctx->r18 = ADD32(ctx->r25, ctx->r8);
    // 0x8002F340: and         $s3, $v0, $at
    ctx->r19 = ctx->r2 & ctx->r1;
    // 0x8002F344: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002F348: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8002F34C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8002F350: jal         0x80019218
    // 0x8002F354: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8002F354: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_2:
    // 0x8002F358: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8002F35C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002F360: swc1        $f22, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f22.u32l;
    // 0x8002F364: addu        $t2, $t1, $s3
    ctx->r10 = ADD32(ctx->r9, ctx->r19);
    // 0x8002F368: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8002F36C: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x8002F370: b           L_8002F398
    // 0x8002F374: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
        goto L_8002F398;
    // 0x8002F374: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
L_8002F378:
    // 0x8002F378: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8002F37C: ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // 0x8002F380: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8002F384: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002F388: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8002F38C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8002F390: jal         0x80019218
    // 0x8002F394: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8002F394: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_3:
L_8002F398:
    // 0x8002F398: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8002F39C:
    // 0x8002F39C: slt         $at, $s1, $s7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8002F3A0: bne         $at, $zero, L_8002F1F0
    if (ctx->r1 != 0) {
        // 0x8002F3A4: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8002F1F0;
    }
    // 0x8002F3A4: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8002F3A8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002F3AC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002F3B0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8002F3B4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002F3B8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002F3BC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002F3C0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002F3C4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002F3C8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002F3CC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002F3D0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F3D4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002F3D8: jr          $ra
    // 0x8002F3DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002F3DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Wipe_Vertical(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80084400: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80084404: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80084408: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008440C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80084410: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80084414: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80084418: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008441C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084424: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // 0x80084428: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008442C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80084430: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80084434: jal         0x8009F574
    // 0x80084438: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Graphics_FillRectangle(rdram, ctx);
        goto after_0;
    // 0x80084438: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8008443C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80084440: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80084444: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x80084448: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x8008444C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084450: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80084454: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80084458: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008445C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084460: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // 0x80084464: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80084468: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008446C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80084470: jal         0x8009F574
    // 0x80084474: subu        $a2, $t9, $t8
    ctx->r6 = SUB32(ctx->r25, ctx->r24);
    Graphics_FillRectangle(rdram, ctx);
        goto after_1;
    // 0x80084474: subu        $a2, $t9, $t8
    ctx->r6 = SUB32(ctx->r25, ctx->r24);
    after_1:
    // 0x80084478: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008447C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80084480: jr          $ra
    // 0x80084484: nop

    return;
    // 0x80084484: nop

;}
RECOMP_FUNC void SerialInterface_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003FEC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80003FF0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80003FF4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80003FF8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80003FFC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80004000: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80004004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80004008: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000400C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80004010: jal         0x8000291C
    // 0x80004014: nop

    Controller_Init(rdram, ctx);
        goto after_0;
    // 0x80004014: nop

    after_0:
    // 0x80004018: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000401C: addiu       $s0, $s0, 0x22C0
    ctx->r16 = ADD32(ctx->r16, 0X22C0);
    // 0x80004020: addiu       $s5, $zero, 0xD
    ctx->r21 = ADD32(0, 0XD);
    // 0x80004024: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80004028: addiu       $s3, $zero, 0xB
    ctx->r19 = ADD32(0, 0XB);
    // 0x8000402C: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80004030: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80004034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80004038:
    // 0x80004038: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000403C: jal         0x800205E0
    // 0x80004040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80004040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80004044: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80004048: beq         $v0, $s2, L_80004070
    if (ctx->r2 == ctx->r18) {
        // 0x8000404C: nop
    
            goto L_80004070;
    }
    // 0x8000404C: nop

    // 0x80004050: beq         $v0, $s3, L_80004080
    if (ctx->r2 == ctx->r19) {
        // 0x80004054: nop
    
            goto L_80004080;
    }
    // 0x80004054: nop

    // 0x80004058: beq         $v0, $s4, L_80004090
    if (ctx->r2 == ctx->r20) {
        // 0x8000405C: nop
    
            goto L_80004090;
    }
    // 0x8000405C: nop

    // 0x80004060: beq         $v0, $s5, L_800040A0
    if (ctx->r2 == ctx->r21) {
        // 0x80004064: nop
    
            goto L_800040A0;
    }
    // 0x80004064: nop

    // 0x80004068: b           L_80004038
    // 0x8000406C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80004038;
    // 0x8000406C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80004070:
    // 0x80004070: jal         0x80002AF4
    // 0x80004074: nop

    Controller_ReadData(rdram, ctx);
        goto after_2;
    // 0x80004074: nop

    after_2:
    // 0x80004078: b           L_80004038
    // 0x8000407C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80004038;
    // 0x8000407C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80004080:
    // 0x80004080: jal         0x80002BE8
    // 0x80004084: nop

    Save_ReadData(rdram, ctx);
        goto after_3;
    // 0x80004084: nop

    after_3:
    // 0x80004088: b           L_80004038
    // 0x8000408C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80004038;
    // 0x8000408C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80004090:
    // 0x80004090: jal         0x80002C50
    // 0x80004094: nop

    Save_WriteData(rdram, ctx);
        goto after_4;
    // 0x80004094: nop

    after_4:
    // 0x80004098: b           L_80004038
    // 0x8000409C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80004038;
    // 0x8000409C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800040A0:
    // 0x800040A0: jal         0x80002CB8
    // 0x800040A4: nop

    Controller_Rumble(rdram, ctx);
        goto after_5;
    // 0x800040A4: nop

    after_5:
    // 0x800040A8: b           L_80004038
    // 0x800040AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80004038;
    // 0x800040AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800040B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800040B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800040B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800040BC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800040C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800040C4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800040C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800040CC: jr          $ra
    // 0x800040D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800040D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Audio_BuildSyntheticWave(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800126AC: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x800126B0: beq         $at, $zero, L_800126BC
    if (ctx->r1 == 0) {
        // 0x800126B4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800126BC;
    }
    // 0x800126B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800126B8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
L_800126BC:
    // 0x800126BC: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800126C0: lwc1        $f2, 0x24($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800126C4: beq         $t6, $zero, L_800126FC
    if (ctx->r14 == 0) {
        // 0x800126C8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800126FC;
    }
    // 0x800126C8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800126CC: lwc1        $f12, 0x14($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800126D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800126D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800126D8: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800126DC: nop

    // 0x800126E0: bc1fl       L_80012700
    if (!c1cs) {
        // 0x800126E4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80012700;
    }
    goto skip_0;
    // 0x800126E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x800126E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800126EC: nop

    // 0x800126F0: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800126F4: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800126F8: nop

L_800126FC:
    // 0x800126FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80012700:
    // 0x80012700: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80012704: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80012708: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8001270C: nop

    // 0x80012710: bc1fl       L_80012728
    if (!c1cs) {
        // 0x80012714: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80012728;
    }
    goto skip_1;
    // 0x80012714: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_1:
    // 0x80012718: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001271C: b           L_8001277C
    // 0x80012720: lwc1        $f0, -0x792C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X792C);
        goto L_8001277C;
    // 0x80012720: lwc1        $f0, -0x792C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X792C);
    // 0x80012724: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80012728:
    // 0x80012728: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001272C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80012730: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80012734: nop

    // 0x80012738: bc1fl       L_80012750
    if (!c1cs) {
        // 0x8001273C: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80012750;
    }
    goto skip_2;
    // 0x8001273C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_2:
    // 0x80012740: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012744: b           L_8001277C
    // 0x80012748: lwc1        $f0, -0x7928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7928);
        goto L_8001277C;
    // 0x80012748: lwc1        $f0, -0x7928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7928);
    // 0x8001274C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80012750:
    // 0x80012750: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80012754: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012758: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8001275C: nop

    // 0x80012760: bc1f        L_80012778
    if (!c1cs) {
        // 0x80012764: nop
    
            goto L_80012778;
    }
    // 0x80012764: nop

    // 0x80012768: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001276C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80012770: b           L_8001277C
    // 0x80012774: lwc1        $f0, -0x7924($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7924);
        goto L_8001277C;
    // 0x80012774: lwc1        $f0, -0x7924($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7924);
L_80012778:
    // 0x80012778: lwc1        $f0, -0x7920($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7920);
L_8001277C:
    // 0x8001277C: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80012780: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80012784: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80012788: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001278C: sll         $t0, $v1, 7
    ctx->r8 = S32(ctx->r3 << 7);
    // 0x80012790: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80012794: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    // 0x80012798: sb          $a2, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r6;
    // 0x8001279C: sb          $v1, 0x32($a0)
    MEM_B(0X32, ctx->r4) = ctx->r3;
    // 0x800127A0: lw          $t8, -0x3AF0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3AF0);
    // 0x800127A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800127A8: jr          $ra
    // 0x800127AC: sw          $t1, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->r9;
    return;
    // 0x800127AC: sw          $t1, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void Audio_KillSfxByBankAndSource(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A4B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001A4BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A4C0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001A4C4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8001A4C8: jal         0x8001A38C
    // 0x8001A4CC: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    Audio_StopSfxByBankAndSource(rdram, ctx);
        goto after_0;
    // 0x8001A4CC: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_0:
    // 0x8001A4D0: lbu         $t6, 0x4B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4B);
    // 0x8001A4D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8001A4D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001A4DC: sll         $t7, $t6, 28
    ctx->r15 = S32(ctx->r14 << 28);
    // 0x8001A4E0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8001A4E4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8001A4E8: jal         0x80019290
    // 0x8001A4EC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Audio_RemoveMatchingSfxRequests(rdram, ctx);
        goto after_1;
    // 0x8001A4EC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x8001A4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A4F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8001A4F8: jr          $ra
    // 0x8001A4FC: nop

    return;
    // 0x8001A4FC: nop

;}
RECOMP_FUNC void Player_WingEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A4464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A446C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4470: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800A4474: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800A4478: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A447C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A4480: bne         $t6, $at, L_800A4560
    if (ctx->r14 != ctx->r1) {
        // 0x800A4484: addiu       $v0, $v0, -0xEF0
        ctx->r2 = ADD32(ctx->r2, -0XEF0);
            goto L_800A4560;
    }
    // 0x800A4484: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x800A4488: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800A448C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A4490: bne         $t7, $at, L_800A4560
    if (ctx->r15 != ctx->r1) {
        // 0x800A4494: nop
    
            goto L_800A4560;
    }
    // 0x800A4494: nop

    // 0x800A4498: lh          $t8, 0x4E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4E);
    // 0x800A449C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800A44A0: bne         $t8, $at, L_800A4560
    if (ctx->r24 != ctx->r1) {
        // 0x800A44A4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A4560;
    }
    // 0x800A44A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A44A8: lwc1        $f6, -0x7CF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7CF0);
    // 0x800A44AC: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800A44B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A44B4: lwc1        $f10, -0x7CEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7CEC);
    // 0x800A44B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A44BC: nop

    // 0x800A44C0: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A44C4: jal         0x80023090
    // 0x800A44C8: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A44C8: nop

    after_0:
    // 0x800A44CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A44D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A44D4: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x800A44D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A44DC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800A44E0: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800A44E4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800A44E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A44EC: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800A44F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A44F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A44F8: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
    // 0x800A44FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A4500: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
    // 0x800A4504: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800A4508: swc1        $f18, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f18.u32l;
    // 0x800A450C: lwc1        $f6, -0x7CE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7CE8);
    // 0x800A4510: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A4514: jal         0x80023090
    // 0x800A4518: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A4518: nop

    after_1:
    // 0x800A451C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A4520: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4524: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800A4528: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A452C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A4530: lwc1        $f18, 0xF4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800A4534: swc1        $f16, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f16.u32l;
    // 0x800A4538: lwc1        $f4, -0x7CE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7CE4);
    // 0x800A453C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A4540: jal         0x80023090
    // 0x800A4544: nop

    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A4544: nop

    after_2:
    // 0x800A4548: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A454C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4550: nop

    // 0x800A4554: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A4558: b           L_800A468C
    // 0x800A455C: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
        goto L_800A468C;
    // 0x800A455C: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
L_800A4560:
    // 0x800A4560: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4564: lwc1        $f16, -0x7CE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7CE0);
    // 0x800A4568: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800A456C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4570: lwc1        $f4, -0x7CDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7CDC);
    // 0x800A4574: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A4578: nop

    // 0x800A457C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A4580: jal         0x80023090
    // 0x800A4584: nop

    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A4584: nop

    after_3:
    // 0x800A4588: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A458C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4590: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A4594: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A4598: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A459C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A45A0: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800A45A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A45A8: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800A45AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A45B0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A45B4: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    // 0x800A45B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A45BC: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
    // 0x800A45C0: swc1        $f8, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f8.u32l;
    // 0x800A45C4: lbu         $t9, 0x7C98($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7C98);
    // 0x800A45C8: beq         $t9, $zero, L_800A45EC
    if (ctx->r25 == 0) {
        // 0x800A45CC: nop
    
            goto L_800A45EC;
    }
    // 0x800A45CC: nop

    // 0x800A45D0: lw          $t0, 0x238($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X238);
    // 0x800A45D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A45D8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800A45DC: bnel        $t0, $at, L_800A4690
    if (ctx->r8 != ctx->r1) {
        // 0x800A45E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4690;
    }
    goto skip_0;
    // 0x800A45E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A45E4: lw          $t1, 0x7880($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7880);
    // 0x800A45E8: bne         $t1, $zero, L_800A468C
    if (ctx->r9 != 0) {
        // 0x800A45EC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A468C;
    }
L_800A45EC:
    // 0x800A45EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A45F0: lwc1        $f16, -0x7CD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7CD8);
    // 0x800A45F4: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800A45F8: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A45FC: jal         0x80023090
    // 0x800A4600: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800A4600: nop

    after_4:
    // 0x800A4604: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4608: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A460C: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x800A4610: lbu         $t2, 0x49C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X49C);
    // 0x800A4614: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A4618: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800A461C: bne         $at, $zero, L_800A4630
    if (ctx->r1 != 0) {
        // 0x800A4620: swc1        $f6, 0x80($s0)
        MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
            goto L_800A4630;
    }
    // 0x800A4620: swc1        $f6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
    // 0x800A4624: lbu         $t3, 0x49D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X49D);
    // 0x800A4628: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800A462C: beq         $at, $zero, L_800A4660
    if (ctx->r1 == 0) {
        // 0x800A4630: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A4660;
    }
L_800A4630:
    // 0x800A4630: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4634: lwc1        $f10, -0x7CD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7CD4);
    // 0x800A4638: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800A463C: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A4640: jal         0x80023090
    // 0x800A4644: nop

    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A4644: nop

    after_5:
    // 0x800A4648: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A464C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A4650: nop

    // 0x800A4654: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800A4658: b           L_800A468C
    // 0x800A465C: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
        goto L_800A468C;
    // 0x800A465C: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
L_800A4660:
    // 0x800A4660: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4664: lwc1        $f6, -0x7CD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7CD0);
    // 0x800A4668: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800A466C: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A4670: jal         0x80023090
    // 0x800A4674: nop

    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x800A4674: nop

    after_6:
    // 0x800A4678: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800A467C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4680: nop

    // 0x800A4684: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A4688: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
L_800A468C:
    // 0x800A468C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4690:
    // 0x800A4690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A4698: jr          $ra
    // 0x800A469C: nop

    return;
    // 0x800A469C: nop

;}
RECOMP_FUNC void AudioHeap_DiscardFont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000BD3C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000BD40: lw          $v0, 0x5CA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5CA0);
    // 0x8000BD44: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000BD48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000BD4C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8000BD50: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000BD54: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000BD58: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000BD5C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000BD60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000BD64: blez        $v0, L_8000BE00
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000BD68: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000BE00;
    }
    // 0x8000BD68: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000BD6C: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x8000BD70: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000BD74: addiu       $s3, $s3, -0x1AD0
    ctx->r19 = ADD32(ctx->r19, -0X1AD0);
    // 0x8000BD78: addiu       $s4, $s4, 0x30C0
    ctx->r20 = ADD32(ctx->r20, 0X30C0);
    // 0x8000BD7C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000BD80:
    // 0x8000BD80: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8000BD84: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x8000BD88: lbu         $t7, 0x33($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X33);
    // 0x8000BD8C: bnel        $s5, $t7, L_8000BDF4
    if (ctx->r21 != ctx->r15) {
        // 0x8000BD90: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000BDF4;
    }
    goto skip_0;
    // 0x8000BD90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8000BD94: lbu         $t8, 0x34($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X34);
    // 0x8000BD98: bne         $t8, $zero, L_8000BDCC
    if (ctx->r24 != 0) {
        // 0x8000BD9C: nop
    
            goto L_8000BDCC;
    }
    // 0x8000BD9C: nop

    // 0x8000BDA0: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x8000BDA4: beq         $t9, $zero, L_8000BDCC
    if (ctx->r25 == 0) {
        // 0x8000BDA8: nop
    
            goto L_8000BDCC;
    }
    // 0x8000BDA8: nop

    // 0x8000BDAC: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8000BDB0: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8000BDB4: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x8000BDB8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8000BDBC: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8000BDC0: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8000BDC4: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x8000BDC8: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_8000BDCC:
    // 0x8000BDCC: jal         0x80011F4C
    // 0x8000BDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_NoteDisable(rdram, ctx);
        goto after_0;
    // 0x8000BDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BDD4: jal         0x80012C40
    // 0x8000BDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_1;
    // 0x8000BDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000BDDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000BDE0: jal         0x800145BC
    // 0x8000BDE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_2;
    // 0x8000BDE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000BDE8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000BDEC: lw          $v0, 0x5CA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5CA0);
    // 0x8000BDF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8000BDF4:
    // 0x8000BDF4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000BDF8: bne         $at, $zero, L_8000BD80
    if (ctx->r1 != 0) {
        // 0x8000BDFC: addiu       $s2, $s2, 0xC0
        ctx->r18 = ADD32(ctx->r18, 0XC0);
            goto L_8000BD80;
    }
    // 0x8000BDFC: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
L_8000BE00:
    // 0x8000BE00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000BE08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000BE0C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BE10: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000BE14: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000BE18: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000BE1C: jr          $ra
    // 0x8000BE20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000BE20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_enmy_80061CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061CD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061CD8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80061CDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80061CE0: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80061CE4: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80061CE8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80061CEC:
    // 0x80061CEC: bnel        $t6, $zero, L_80061E30
    if (ctx->r14 != 0) {
        // 0x80061CF0: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80061E30;
    }
    goto skip_0;
    // 0x80061CF0: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80061CF4: jal         0x80004EB0
    // 0x80061CF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80061CF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80061CFC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80061D00: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x80061D04: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80061D08: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80061D0C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80061D10: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80061D14: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80061D18: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80061D1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061D20: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80061D24: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80061D28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80061D2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061D30: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x80061D34: lwc1        $f4, 0xC0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80061D38: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80061D3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061D40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80061D44: lwc1        $f18, 0x643C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X643C);
    // 0x80061D48: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80061D4C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80061D50: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80061D54: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80061D58: jal         0x80004EB0
    // 0x80061D5C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80061D5C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80061D60: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80061D64: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x80061D68: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80061D6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061D70: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80061D74: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80061D78: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80061D7C: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80061D80: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80061D84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80061D88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80061D8C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80061D90: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80061D94: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80061D98: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80061D9C: lwc1        $f18, 0x78($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80061DA0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80061DA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80061DA8: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80061DAC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80061DB0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80061DB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061DB8: lwc1        $f8, 0xC4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80061DBC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80061DC0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80061DC4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80061DC8: jal         0x80004EB0
    // 0x80061DCC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80061DCC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80061DD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80061DD4: lwc1        $f12, 0x7D20($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80061DD8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80061DDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80061DE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80061DE4: lwc1        $f10, 0x7D08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80061DE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80061DEC: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80061DF0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80061DF4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80061DF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80061DFC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80061E00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80061E04: bc1f        L_80061E18
    if (!c1cs) {
        // 0x80061E08: sub.s       $f2, $f12, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f8.fl;
            goto L_80061E18;
    }
    // 0x80061E08: sub.s       $f2, $f12, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80061E0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061E10: nop

    // 0x80061E14: add.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f6.fl;
L_80061E18:
    // 0x80061E18: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80061E1C: jal         0x80061958
    // 0x80061E20: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    Effect_SmallRock_Setup(rdram, ctx);
        goto after_3;
    // 0x80061E20: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80061E24: b           L_80061E3C
    // 0x80061E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80061E3C;
    // 0x80061E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061E2C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80061E30:
    // 0x80061E30: bnel        $a0, $v0, L_80061CEC
    if (ctx->r4 != ctx->r2) {
        // 0x80061E34: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80061CEC;
    }
    goto skip_1;
    // 0x80061E34: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80061E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80061E3C:
    // 0x80061E3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80061E40: jr          $ra
    // 0x80061E44: nop

    return;
    // 0x80061E44: nop

;}
RECOMP_FUNC void Game_SpawnActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3608: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A360C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3610: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A3614: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800A3618: addiu       $a2, $a2, 0x3FE0
    ctx->r6 = ADD32(ctx->r6, 0X3FE0);
    // 0x800A361C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A3620: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_800A3624:
    // 0x800A3624: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800A3628: bne         $t6, $zero, L_800A366C
    if (ctx->r14 != 0) {
        // 0x800A362C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800A366C;
    }
    // 0x800A362C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A3630: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A3634: jal         0x800613C4
    // 0x800A3638: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A3638: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A363C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3640: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A3644: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x800A3648: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A364C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800A3650: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x800A3654: jal         0x800612B8
    // 0x800A3658: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800A3658: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    after_1:
    // 0x800A365C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800A3660: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800A3664: b           L_800A3678
    // 0x800A3668: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_800A3678;
    // 0x800A3668: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800A366C:
    // 0x800A366C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A3670: bne         $v0, $v1, L_800A3624
    if (ctx->r2 != ctx->r3) {
        // 0x800A3674: addiu       $a2, $a2, 0x2F4
        ctx->r6 = ADD32(ctx->r6, 0X2F4);
            goto L_800A3624;
    }
    // 0x800A3674: addiu       $a2, $a2, 0x2F4
    ctx->r6 = ADD32(ctx->r6, 0X2F4);
L_800A3678:
    // 0x800A3678: bne         $v0, $v1, L_800A3684
    if (ctx->r2 != ctx->r3) {
        // 0x800A367C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3684;
    }
    // 0x800A367C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A3684:
    // 0x800A3684: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800A3688: jr          $ra
    // 0x800A368C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A368C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Versus_dummy_800C1764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1764: jr          $ra
    // 0x800C1768: nop

    return;
    // 0x800C1768: nop

;}
